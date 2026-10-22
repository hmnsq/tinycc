/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#که_نه_تعریف_شوی _WINNT_
#تعریف_کړه _WINNT_

#که_تعریف_شوی __cplusplus
خارجي "C" {
#د_که_پای

#ضمن <ctype.h>
#تعریف_کړه ANYSIZE_ARRAY 1

//gr #include <specstrings.h>

#تعریف_کړه RESTRICTED_اشاره_ګر

#که_نه_تعریف_شوی __CRT_UNALIGNED
#تعریف_کړه __CRT_UNALIGNED
#د_که_پای

#إذا defined(__ia64__) || defined(__x86_64) || defined(__aarch64__)
#تعریف_کړه UNALIGNED __CRT_UNALIGNED
#که_تعریف_شوی _WIN64
#تعریف_کړه UNALIGNED64 __CRT_UNALIGNED
#وإلا
#تعریف_کړه UNALIGNED64
#د_که_پای
#وإلا
#تعریف_کړه UNALIGNED
#تعریف_کړه UNALIGNED64
#د_که_پای

#إذا !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && (defined(_X86_) && !defined(__x86_64))
#تعریف_کړه I_X86_
#د_که_پای

#إذا !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && defined(__x86_64)
#تعریف_کړه _AMD64_
#د_که_پای

#إذا !defined(I_X86_) && !(defined(_X86_) && !defined(__x86_64)) && !defined(_AMD64_) && defined(__ia64__)
#إذا !defined(_IA64_)
#تعریف_کړه _IA64_
#د_که_پای
#د_که_پای


#که_تعریف_شوی _WIN64
#تعریف_کړه MAX_NATURAL_ALIGNMENT حجم(ULONGLONG)
#تعریف_کړه حافظه_ویش_ALIGNMENT 16
#وإلا
#تعریف_کړه MAX_NATURAL_ALIGNMENT حجم(DWORD)
#تعریف_کړه حافظه_ویش_ALIGNMENT 8
#د_که_پای

#که_تعریف_شوی __cplusplus
#تعریف_کړه TYPE_ALIGNMENT(t) __alignof__ (t)
#وإلا
#تعریف_کړه TYPE_ALIGNMENT(t) ډګر_دننه_واټن(بنية { حرف x; t test; },test)
#د_که_پای

#که_تعریف_شوی _WIN64
#که_تعریف_شوی _AMD64_
#تعریف_کړه PROBE_ALIGNMENT(_s) TYPE_ALIGNMENT(DWORD)
#وإلاإذا defined(_IA64_) || defined(_ARM64_)
#تعریف_کړه PROBE_ALIGNMENT(_s) (TYPE_ALIGNMENT(_s) > TYPE_ALIGNMENT(DWORD) ? TYPE_ALIGNMENT(_s) : TYPE_ALIGNMENT(DWORD))
#وإلا
#تېروتنه No موخه_2 Architecture
#د_که_پای
#تعریف_کړه PROBE_ALIGNMENT32(_s) TYPE_ALIGNMENT(DWORD)
#وإلا
#تعریف_کړه PROBE_ALIGNMENT(_s) TYPE_ALIGNMENT(DWORD)
#د_که_پای

#تعریف_کړه C_ASSERT(e) تعريفنوع حرف __C_ASSERT__[(e)?1:-1]

#ضمن <basetsd.h>

#إذا defined(_X86_) || defined(__ia64__) || defined(__x86_64) || defined(__aarch64__)
#تعریف_کړه DECLSPEC_IMPORT __declspec(dllimport)
#وإلا
#تعریف_کړه DECLSPEC_IMPORT
#د_که_پای

#که_نه_تعریف_شوی DECLSPEC_NORETURN
#تعریف_کړه DECLSPEC_NORETURN __declspec(noreturn)
#د_که_پای

#که_نه_تعریف_شوی DECLSPEC_ALIGN
#تعریف_کړه DECLSPEC_ALIGN(x) __attribute__ ((aligned(x)))
#د_که_پای

#که_نه_تعریف_شوی SYSTEM_CACHE_ALIGNMENT_اندازه
#إذا defined(_AMD64_) || defined(I_X86_)
#تعریف_کړه SYSTEM_CACHE_ALIGNMENT_اندازه 64
#وإلا
#تعریف_کړه SYSTEM_CACHE_ALIGNMENT_اندازه 128
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی DECLSPEC_CACHEALIGN
#تعریف_کړه DECLSPEC_CACHEALIGN DECLSPEC_ALIGN(SYSTEM_CACHE_ALIGNMENT_اندازه)
#د_که_پای

#که_نه_تعریف_شوی DECLSPEC_UUID
#تعریف_کړه DECLSPEC_UUID(x)
#د_که_پای

#که_نه_تعریف_شوی DECLSPEC_NOVTABLE
#تعریف_کړه DECLSPEC_NOVTABLE
#د_که_پای

#که_نه_تعریف_شوی DECLSPEC_SELECTANY
#تعریف_کړه DECLSPEC_SELECTANY __declspec(selectany)
#د_که_پای

#که_نه_تعریف_شوی NOP_FUNCTION
#تعریف_کړه NOP_FUNCTION (فراغ)0
#د_که_پای

#که_نه_تعریف_شوی DECLSPEC_NOINLINE
#تعریف_کړه DECLSPEC_NOINLINE
#د_که_پای

#که_نه_تعریف_شوی FORCEINLINE
#تعریف_کړه FORCEINLINE ساكن __inline__
#د_که_پای

#که_نه_تعریف_شوی DECLSPEC_DEPRECATED
#تعریف_کړه DECLSPEC_DEPRECATED __declspec(deprecated)
#تعریف_کړه DEPRECATE_SUPPORTED
#د_که_پای

#تعریف_کړه DECLSPEC_DEPRECATED_DDK
#تعریف_کړه PRAGMA_DEPRECATED_DDK 0

  تعريفنوع فراغ *PVOID;
  تعريفنوع فراغ *PVOID64;

#تعریف_کړه NTAPI __stdcall
#تعریف_کړه NTSYSAPI DECLSPEC_IMPORT
#تعریف_کړه NTSYSCALLAPI DECLSPEC_IMPORT

#که_نه_تعریف_شوی VOID
#تعریف_کړه VOID فراغ
  تعريفنوع حرف CHAR;
  تعريفنوع لنډ SHORT;
  تعريفنوع اوږد LONG;
#د_که_پای

  تعريفنوع wchar_t WCHAR;
  تعريفنوع WCHAR *PWCHAR,*LPWCH,*PWCH;
  تعريفنوع CONST WCHAR *LPCWCH,*PCWCH;
  تعريفنوع WCHAR *NWPSTR,*LPWSTR,*PWSTR;
  تعريفنوع PWSTR *PZPWSTR;
  تعريفنوع CONST PWSTR *PCZPWSTR;
  تعريفنوع WCHAR UNALIGNED *LPUWSTR,*PUWSTR;
  تعريفنوع CONST WCHAR *LPCWSTR,*PCWSTR;
  تعريفنوع PCWSTR *PZPCWSTR;
  تعريفنوع CONST WCHAR UNALIGNED *LPCUWSTR,*PCUWSTR;
  تعريفنوع CHAR *PCHAR,*LPCH,*PCH;
  تعريفنوع CONST CHAR *LPCCH,*PCCH;
  تعريفنوع CHAR *NPSTR,*LPSTR,*PSTR;
  تعريفنوع PSTR *PZPSTR;
  تعريفنوع CONST PSTR *PCZPSTR;
  تعريفنوع CONST CHAR *LPCSTR,*PCSTR;
  تعريفنوع PCSTR *PZPCSTR;

#که_تعریف_شوی UNICODE
#که_نه_تعریف_شوی _TCHAR_DEFINED
#تعریف_کړه _TCHAR_DEFINED
  تعريفنوع WCHAR TCHAR,*PTCHAR;
  تعريفنوع WCHAR TBYTE ,*PTBYTE;
#د_که_پای

  تعريفنوع LPWSTR LPTCH,PTCH;
  تعريفنوع LPWSTR PTSTR,LPTSTR;
  تعريفنوع LPCWSTR PCTSTR,LPCTSTR;
  تعريفنوع LPUWSTR PUTSTR,LPUTSTR;
  تعريفنوع LPCUWSTR PCUTSTR,LPCUTSTR;
  تعريفنوع LPWSTR LP;
#تعریف_کړه __TEXT(quote) L##quote
#وإلا
#که_نه_تعریف_شوی _TCHAR_DEFINED
#تعریف_کړه _TCHAR_DEFINED
  تعريفنوع حرف TCHAR,*PTCHAR;
  تعريفنوع بینښه حرف TBYTE ,*PTBYTE;
#د_که_پای

  تعريفنوع LPSTR LPTCH,PTCH;
  تعريفنوع LPSTR PTSTR,LPTSTR,PUTSTR,LPUTSTR;
  تعريفنوع LPCSTR PCTSTR,LPCTSTR,PCUTSTR,LPCUTSTR;
#تعریف_کړه __TEXT(quote) quote
#د_که_پای

#تعریف_کړه متن_3(quote) __TEXT(quote)

  تعريفنوع SHORT *PSHORT;
  تعريفنوع LONG *PLONG;

  تعريفنوع فراغ *HANDLE;
#تعریف_کړه DECLARE_HANDLE(name) بنية name##__ { صحيح ناکارول_شوی; }; تعريفنوع بنية name##__ *name
  تعريفنوع HANDLE *PHANDLE;

  تعريفنوع BYTE FCHAR;
  تعريفنوع کلمه_3 FSHORT;
  تعريفنوع DWORD FLONG;

#که_نه_تعریف_شوی _HRESULT_DEFINED
#تعریف_کړه _HRESULT_DEFINED
  تعريفنوع LONG HRESULT;
#د_که_پای

#که_تعریف_شوی __cplusplus
#تعریف_کړه EXTERN_C خارجي "C"
#وإلا
#تعریف_کړه EXTERN_C خارجي
#د_که_پای

#تعریف_کړه STDMETHODCALLTYPE WINAPI
#تعریف_کړه STDMETHODVCALLTYPE __cdecl
#تعریف_کړه STDAPICALLTYPE WINAPI
#تعریف_کړه STDAPIVCALLTYPE __cdecl
#تعریف_کړه STDAPI EXTERN_C HRESULT WINAPI
#تعریف_کړه STDAPI_(type) EXTERN_C type WINAPI
#تعریف_کړه STDMETHODIMP HRESULT WINAPI
#تعریف_کړه STDMETHODIMP_(type) type WINAPI
#تعریف_کړه STDAPIV EXTERN_C HRESULT STDAPIVCALLTYPE
#تعریف_کړه STDAPIV_(type) EXTERN_C type STDAPIVCALLTYPE
#تعریف_کړه STDMETHODIMPV HRESULT STDMETHODVCALLTYPE
#تعریف_کړه STDMETHODIMPV_(type) type STDMETHODVCALLTYPE

  تعريفنوع حرف CCHAR;
#که_نه_تعریف_شوی _LCID_DEFINED
#تعریف_کړه _LCID_DEFINED
تعريفنوع DWORD LCID;
#د_که_پای
  تعريفنوع PDWORD PLCID;
#که_نه_تعریف_شوی _LANGID_DEFINED
#تعریف_کړه _LANGID_DEFINED
  تعريفنوع کلمه_3 LANGID;
#د_که_پای
#تعریف_کړه APPLICATION_ERROR_ماسک 0x20000000
#تعریف_کړه ERROR_SEVERITY_SUCCESS 0x00000000
#تعریف_کړه ERROR_SEVERITY_INFORMATIONAL 0x40000000
#تعریف_کړه ERROR_SEVERITY_WARNING 0x80000000
#تعریف_کړه ERROR_SEVERITY_ERROR 0xC0000000

#که_تعریف_شوی __ia64__
  __declspec(align(16))
#د_که_پای
    تعريفنوع بنية _FLOAT128 {
      __int64 ټیټ_Part;
      __int64 لوړ_Part;
  } FLOAT128;

  تعريفنوع FLOAT128 *PFLOAT128;

#تعریف_کړه _ULONGLONG_
#إذا((!(defined(_X86_) && !defined(__x86_64)) || (defined(INTEGRAL_MAX_بټونه) && INTEGRAL_MAX_بټونه >= 64)))
  تعريفنوع __int64 LONGLONG;
  تعريفنوع بینښه __int64 ULONGLONG;

#تعریف_کړه MAXLONGLONG (0x7fffffffffffffff)
#وإلا

  تعريفنوع مزدوج LONGLONG;
  تعريفنوع مزدوج ULONGLONG;
#د_که_پای

  تعريفنوع LONGLONG *PLONGLONG;
  تعريفنوع ULONGLONG *PULONGLONG;

  تعريفنوع LONGLONG USN;

  تعريفنوع اتحاد _LARGE_INTEGER {
    بنية {
      DWORD ټیټ_Part;
      LONG لوړ_Part;
    };
    بنية {
      DWORD ټیټ_Part;
      LONG لوړ_Part;
    } u;
    LONGLONG QuadPart;
  } LARGE_INTEGER;

  تعريفنوع LARGE_INTEGER *PLARGE_INTEGER;

  تعريفنوع اتحاد _ULARGE_INTEGER {
    بنية {
      DWORD ټیټ_Part;
      DWORD لوړ_Part;
    };
    بنية {
      DWORD ټیټ_Part;
      DWORD لوړ_Part;
    } u;
    ULONGLONG QuadPart;
  } ULARGE_INTEGER;

  تعريفنوع ULARGE_INTEGER *PULARGE_INTEGER;

  تعريفنوع بنية _LUID {
    DWORD ټیټ_Part;
    LONG لوړ_Part;
  } LUID,*PLUID;

#تعریف_کړه _DWORDLONG_
  تعريفنوع ULONGLONG DWORDLONG;
  تعريفنوع DWORDLONG *PDWORDLONG;

#که_تعریف_شوی RC_INVOKED
#تعریف_کړه Int32x32To64(a,b) ((LONGLONG)((LONG)(a)) *(LONGLONG)((LONG)(b)))
#تعریف_کړه UInt32x32To64(a,b) ((ULONGLONG)((DWORD)(a)) *(ULONGLONG)((DWORD)(b)))
#تعریف_کړه Int64ShrlMod32(a,b) ((ULONGLONG)(a) >> (b))
#وإلاإذا (defined(_X86_) && !defined(__x86_64))
#تعریف_کړه Int32x32To64(a,b) (LONGLONG)((LONGLONG)(LONG)(a) *(LONG)(b))
#تعریف_کړه UInt32x32To64(a,b) (ULONGLONG)((ULONGLONG)(DWORD)(a) *(DWORD)(b))
#تعریف_کړه Int64ShrlMod32(a,b) ((DWORDLONG)(a)>>(b))
#وإلاإذا defined(__ia64__) || defined(__x86_64) || defined(__aarch64__)
#تعریف_کړه Int32x32To64(a,b) ((LONGLONG)((LONG)(a)) *(LONGLONG)((LONG)(b)))
#تعریف_کړه UInt32x32To64(a,b) ((ULONGLONG)((DWORD)(a)) *(ULONGLONG)((DWORD)(b)))
#تعریف_کړه Int64ShrlMod32(a,b) ((ULONGLONG)(a) >> (b))
#وإلا
#تېروتنه Must define a موخه architecture.
#د_که_پای

#تعریف_کړه Int64ShraMod32(a,b) ((LONGLONG)(a) >> (b))
#تعریف_کړه Int64ShllMod32(a,b) ((ULONGLONG)(a) << (b))

#که_تعریف_شوی __cplusplus
  خارجي "C" {
#د_که_پای

#که_تعریف_شوی __x86_64

#تعریف_کړه RotateLeft8 _rotl8
#تعریف_کړه RotateLeft16 _rotl16
#تعریف_کړه RotateRight8 _rotr8
#تعریف_کړه RotateRight16 _rotr16

    بینښه حرف __cdecl _rotl8(بینښه حرف ارزښت_3,بینښه حرف ښويدنه_3);
    بینښه لنډ __cdecl _rotl16(بینښه لنډ ارزښت_3,بینښه حرف ښويدنه_3);
    بینښه حرف __cdecl _rotr8(بینښه حرف ارزښت_3,بینښه حرف ښويدنه_3);
    بینښه لنډ __cdecl _rotr16(بینښه لنډ ارزښت_3,بینښه حرف ښويدنه_3);
#د_که_پای

#تعریف_کړه RotateLeft32 _rotl
#تعریف_کړه RotateLeft64 _rotl64
#تعریف_کړه RotateRight32 _rotr
#تعریف_کړه RotateRight64 _rotr64

    بینښه صحيح __cdecl _rotl(بینښه صحيح ارزښت_3,صحيح ښويدنه_3);
    بینښه __int64 __cdecl _rotl64(بینښه __int64 ارزښت_3,صحيح ښويدنه_3);
    بینښه صحيح __cdecl _rotr(بینښه صحيح ارزښت_3,صحيح ښويدنه_3);
    بینښه __int64 __cdecl _rotr64(بینښه __int64 ارزښت_3,صحيح ښويدنه_3);
#که_تعریف_شوی __cplusplus
  }
#د_که_پای

#تعریف_کړه ANSI_NULL ((CHAR)0)
#تعریف_کړه UNICODE_NULL ((WCHAR)0)
#تعریف_کړه UNICODE_STRING_MAX_بایټونه ((کلمه_3) 65534)
#تعریف_کړه UNICODE_STRING_MAX_CHARS (32767)

#که_نه_تعریف_شوی _BOOLEAN_
#تعریف_کړه _BOOLEAN_
  تعريفنوع BYTE BOOLEAN;
#د_که_پای
  تعريفنوع BOOLEAN *PBOOLEAN;

  تعريفنوع بنية LIST_ثبت {
    بنية LIST_ثبت *Flink;
    بنية LIST_ثبت *Blink;
  } LIST_ثبت_2,*PLIST_ثبت,*RESTRICTED_اشاره_ګر PRLIST_ثبت;

  تعريفنوع بنية SINGLE_LIST_ثبت {
    بنية SINGLE_LIST_ثبت *بل_2;
  } SINGLE_LIST_ثبت_2,*PSINGLE_LIST_ثبت;

  تعريفنوع بنية LIST_ENTRY32 {
    DWORD Flink;
    DWORD Blink;
  } LIST_ENTRY32;
  تعريفنوع LIST_ENTRY32 *PLIST_ENTRY32;

  تعريفنوع بنية LIST_ENTRY64 {
    ULONGLONG Flink;
    ULONGLONG Blink;
  } LIST_ENTRY64;
  تعريفنوع LIST_ENTRY64 *PLIST_ENTRY64;

#ضمن <guiddef.h>

#که_نه_تعریف_شوی __OBJECTID_DEFINED
#تعریف_کړه __OBJECTID_DEFINED
  تعريفنوع بنية _OBJECTID {
    GUID Lineage;
    DWORD Uniquifier;
  } OBJECTID;
#د_که_پای

#تعریف_کړه MINCHAR 0x80
#تعریف_کړه MAXCHAR 0x7f
#تعریف_کړه MINSHORT 0x8000
#تعریف_کړه MAXSHORT 0x7fff
#تعریف_کړه MINLONG 0x80000000
#تعریف_کړه MAXLONG 0x7fffffff
#تعریف_کړه MAXBYTE 0xff
#تعریف_کړه MAXWORD 0xffff
#تعریف_کړه MAXDWORD 0xffffffff

#تعریف_کړه ډګر_دننه_واټن(type,ډګر) ((LONG)(LONG_PTR)&(((type *)0)->ډګر))
#تعریف_کړه RTL_ډګر_اندازه(type,ډګر) (حجم(((type *)0)->ډګر))
#تعریف_کړه RTL_SIZEOF_THROUGH_ډګر(type,ډګر) (ډګر_دننه_واټن(type,ډګر) + RTL_ډګر_اندازه(type,ډګر))
#تعریف_کړه RTL_لري_ډګر(Struct,اندازه_3,ډګر_2) ((((PCHAR)(&(Struct)->ډګر_2)) + حجم((Struct)->ډګر_2)) <= (((PCHAR)(Struct))+(اندازه_3)))
#تعریف_کړه RTL_شمېره_د_V1(A) (حجم(A)/حجم((A)[0]))
#تعریف_کړه RTL_شمېره_د_V2(A) RTL_شمېره_د_V1(A)

#که_تعریف_شوی ENABLE_RTL_شمېره_د_V2
#تعریف_کړه RTL_شمېره_د(A) RTL_شمېره_د_V2(A)
#وإلا
#تعریف_کړه RTL_شمېره_د(A) RTL_شمېره_د_V1(A)
#د_که_پای

#تعریف_کړه ARRAYSIZE(A) RTL_شمېره_د_V2(A)
#تعریف_کړه _ARRAYSIZE(A) RTL_شمېره_د_V1(A)

#تعریف_کړه RTL_ډګر_TYPE(type,ډګر) (((type*)0)->ډګر)
#تعریف_کړه RTL_شمېره_د_ډګر(type,ډګر) (RTL_شمېره_د(RTL_ډګر_TYPE(type,ډګر)))
#تعریف_کړه RTL_PADDING_BETWEEN_FIELDS(T,F1,F2) ((ډګر_دننه_واټن(T,F2) > ډګر_دننه_واټن(T,F1)) ? (ډګر_دننه_واټن(T,F2) - ډګر_دننه_واټن(T,F1) - RTL_ډګر_اندازه(T,F1)) : (ډګر_دننه_واټن(T,F1) - ډګر_دننه_واټن(T,F2) - RTL_ډګر_اندازه(T,F2)))

#که_تعریف_شوی __cplusplus
#تعریف_کړه RTL_CONST_CAST(type) const_cast<type>
#وإلا
#تعریف_کړه RTL_CONST_CAST(type) (type)
#د_که_پای

#تعریف_کړه RTL_بټونه_د(اندازه_د_Arg) (حجم(اندازه_د_Arg) *8)
#تعریف_کړه RTL_بټونه_د_ډګر(type,ډګر) (RTL_بټونه_د(RTL_ډګر_TYPE(type,ډګر)))
#تعریف_کړه CONTAINING_ریکارډ(پته,type,ډګر) ((type *)((PCHAR)(پته) - (ULONG_PTR)(&((type *)0)->ډګر)))

#تعریف_کړه VER_SERVER_NT 0x80000000
#تعریف_کړه VER_WORKSTATION_NT 0x40000000
#تعریف_کړه VER_SUITE_SMALLBUSINESS 0x00000001
#تعریف_کړه VER_SUITE_ENTERPRISE 0x00000002
#تعریف_کړه VER_SUITE_BACKOFFICE 0x00000004
#تعریف_کړه VER_SUITE_COMMUNICATIONS 0x00000008
#تعریف_کړه VER_SUITE_TERMINAL 0x00000010
#تعریف_کړه VER_SUITE_SMALLBUSINESS_RESTRICTED 0x00000020
#تعریف_کړه VER_SUITE_EMBEDDEDNT 0x00000040
#تعریف_کړه VER_SUITE_DATACENTER 0x00000080
#تعریف_کړه VER_SUITE_SINGLEUSERTS 0x00000100
#تعریف_کړه VER_SUITE_PERSONAL 0x00000200
#تعریف_کړه VER_SUITE_BLADE 0x00000400
#تعریف_کړه VER_SUITE_EMBEDDED_RESTRICTED 0x00000800
#تعریف_کړه VER_SUITE_SECURITY_APPLIANCE 0x00001000
#تعریف_کړه VER_SUITE_STORAGE_SERVER 0x00002000
#تعریف_کړه VER_SUITE_COMPUTE_SERVER 0x00004000

#تعریف_کړه حاصل_ضرب_UNDEFINED                       0x0

#تعریف_کړه حاصل_ضرب_ULTIMATE                        0x1
#تعریف_کړه حاصل_ضرب_HOME_BASIC                      0x2
#تعریف_کړه حاصل_ضرب_HOME_PREMIUM                    0x3
#تعریف_کړه حاصل_ضرب_ENTERPRISE                      0x4
#تعریف_کړه حاصل_ضرب_HOME_BASIC_N                    0x5
#تعریف_کړه حاصل_ضرب_BUSINESS                        0x6
#تعریف_کړه حاصل_ضرب_STANDARD_SERVER                 0x7
#تعریف_کړه حاصل_ضرب_DATACENTER_SERVER               0x8
#تعریف_کړه حاصل_ضرب_SMALLBUSINESS_SERVER            0x9
#تعریف_کړه حاصل_ضرب_ENTERPRISE_SERVER               0xa
#تعریف_کړه حاصل_ضرب_STARTER                         0xb
#تعریف_کړه حاصل_ضرب_DATACENTER_SERVER_CORE          0xc
#تعریف_کړه حاصل_ضرب_STANDARD_SERVER_CORE            0xd
#تعریف_کړه حاصل_ضرب_ENTERPRISE_SERVER_CORE          0xe
#تعریف_کړه حاصل_ضرب_ENTERPRISE_SERVER_IA64          0xf
#تعریف_کړه حاصل_ضرب_BUSINESS_N                      0x10
#تعریف_کړه حاصل_ضرب_WEB_SERVER                      0x11
#تعریف_کړه حاصل_ضرب_CLUSTER_SERVER                  0x12
#تعریف_کړه حاصل_ضرب_HOME_SERVER                     0x13
#تعریف_کړه حاصل_ضرب_STORAGE_EXPRESS_SERVER          0x14
#تعریف_کړه حاصل_ضرب_STORAGE_STANDARD_SERVER         0x15
#تعریف_کړه حاصل_ضرب_STORAGE_WORKGROUP_SERVER        0x16
#تعریف_کړه حاصل_ضرب_STORAGE_ENTERPRISE_SERVER       0x17
#تعریف_کړه حاصل_ضرب_SERVER_FOR_SMALLBUSINESS        0x18
#تعریف_کړه حاصل_ضرب_SMALLBUSINESS_SERVER_PREMIUM    0x19

#تعریف_کړه حاصل_ضرب_UNLICENSED                      0xabcdabcd

#تعریف_کړه LANG_NEUTRAL 0x00
#تعریف_کړه LANG_INVARIANT 0x7f

#تعریف_کړه LANG_AFRIKAANS 0x36
#تعریف_کړه LANG_ALBANIAN 0x1c
#تعریف_کړه LANG_ALSATIAN 0x84
#تعریف_کړه LANG_AMHARIC 0x5e
#تعریف_کړه LANG_ARABIC 0x01
#تعریف_کړه LANG_ARMENIAN 0x2b
#تعریف_کړه LANG_ASSAMESE 0x4d
#تعریف_کړه LANG_AZERI 0x2c
#تعریف_کړه LANG_BASHKIR 0x6d
#تعریف_کړه LANG_BASQUE 0x2d
#تعریف_کړه LANG_BELARUSIAN 0x23
#تعریف_کړه LANG_BENGALI 0x45
#تعریف_کړه LANG_BRETON 0x7e
#تعریف_کړه LANG_BOSNIAN 0x1a
#تعریف_کړه LANG_BOSNIAN_NEUTRAL 0x781a
#تعریف_کړه LANG_BULGARIAN 0x02
#تعریف_کړه LANG_کاتالان 0x03
#تعریف_کړه LANG_CHINESE 0x04
#تعریف_کړه LANG_CHINESE_SIMPLIFIED 0x04
#تعریف_کړه LANG_CHINESE_TRADITIONAL 0x7c04
#تعریف_کړه LANG_CORSICAN 0x83
#تعریف_کړه LANG_CROATIAN 0x1a
#تعریف_کړه LANG_CZECH 0x05
#تعریف_کړه LANG_DANISH 0x06
#تعریف_کړه LANG_DARI 0x8c
#تعریف_کړه LANG_DIVEHI 0x65
#تعریف_کړه LANG_DUTCH 0x13
#تعریف_کړه LANG_ENGLISH 0x09
#تعریف_کړه LANG_ESTONIAN 0x25
#تعریف_کړه LANG_FAEROESE 0x38
#تعریف_کړه LANG_FARSI 0x29
#تعریف_کړه LANG_FILIPINO 0x64
#تعریف_کړه LANG_FINNISH 0x0b
#تعریف_کړه LANG_FRENCH 0x0c
#تعریف_کړه LANG_FRISIAN 0x62
#تعریف_کړه LANG_GALICIAN 0x56
#تعریف_کړه LANG_GEORGIAN 0x37
#تعریف_کړه LANG_GERMAN 0x07
#تعریف_کړه LANG_GREEK 0x08
#تعریف_کړه LANG_GREENLANDIC 0x6f
#تعریف_کړه LANG_GUJARATI 0x47
#تعریف_کړه LANG_HAUSA 0x68
#تعریف_کړه LANG_HEBREW 0x0d
#تعریف_کړه LANG_HINDI 0x39
#تعریف_کړه LANG_HUNGARIAN 0x0e
#تعریف_کړه LANG_ICELANDIC 0x0f
#تعریف_کړه LANG_IGBO 0x70
#تعریف_کړه LANG_INDONESIAN 0x21
#تعریف_کړه LANG_INUKTITUT 0x5d
#تعریف_کړه LANG_IRISH 0x3c
#تعریف_کړه LANG_ITALIAN 0x10
#تعریف_کړه LANG_JAPANESE 0x11
#تعریف_کړه LANG_KANNADA 0x4b
#تعریف_کړه LANG_KASHMIRI 0x60
#تعریف_کړه LANG_KAZAK 0x3f
#تعریف_کړه LANG_KHMER 0x53
#تعریف_کړه LANG_KICHE 0x86
#تعریف_کړه LANG_KINYARWANDA 0x87
#تعریف_کړه LANG_KONKANI 0x57
#تعریف_کړه LANG_KOREAN 0x12
#تعریف_کړه LANG_KYRGYZ 0x40
#تعریف_کړه LANG_LAO 0x54
#تعریف_کړه LANG_LATVIAN 0x26
#تعریف_کړه LANG_LITHUANIAN 0x27
#تعریف_کړه LANG_ښکتنی_SORBIAN 0x2e
#تعریف_کړه LANG_LUXEMBOURGISH 0x6e
#تعریف_کړه LANG_MACEDONIAN 0x2f
#تعریف_کړه LANG_MALAY 0x3e
#تعریف_کړه LANG_MALAYALAM 0x4c
#تعریف_کړه LANG_MALTESE 0x3a
#تعریف_کړه LANG_MANIPURI 0x58
#تعریف_کړه LANG_MAORI 0x81
#تعریف_کړه LANG_MAPUDUNGUN 0x7a
#تعریف_کړه LANG_MARATHI 0x4e
#تعریف_کړه LANG_MOHAWK 0x7c
#تعریف_کړه LANG_MONGOLIAN 0x50
#تعریف_کړه LANG_NEPALI 0x61
#تعریف_کړه LANG_NORWEGIAN 0x14
#تعریف_کړه LANG_OCCITAN 0x82
#تعریف_کړه LANG_ORIYA 0x48
#تعریف_کړه LANG_PASHTO 0x63
#تعریف_کړه LANG_PERSIAN 0x29
#تعریف_کړه LANG_POLISH 0x15
#تعریف_کړه LANG_PORTUGUESE 0x16
#تعریف_کړه LANG_PUNJABI 0x46
#تعریف_کړه LANG_QUECHUA 0x6b
#تعریف_کړه LANG_ROMANIAN 0x18
#تعریف_کړه LANG_RUSSIAN 0x19
#تعریف_کړه LANG_SAMI 0x3b
#تعریف_کړه LANG_ROMANSH 0x17
#تعریف_کړه LANG_SANSKRIT 0x4f
#تعریف_کړه LANG_SERBIAN 0x1a
#تعریف_کړه LANG_SERBIAN_NEUTRAL 0x7c1a
#تعریف_کړه LANG_SINDHI 0x59
#تعریف_کړه LANG_SINHALESE 0x5b
#تعریف_کړه LANG_SLOVAK 0x1b
#تعریف_کړه LANG_SLOVENIAN 0x24
#تعریف_کړه LANG_SOTHO 0x6c
#تعریف_کړه LANG_SPANISH 0x0a
#تعریف_کړه LANG_SWAHILI 0x41
#تعریف_کړه LANG_SWEDISH 0x1d
#تعریف_کړه LANG_SYRIAC 0x5a
#تعریف_کړه LANG_TAJIK 0x28
#تعریف_کړه LANG_TAMAZIGHT 0x5f
#تعریف_کړه LANG_TAMIL 0x49
#تعریف_کړه LANG_TATAR 0x44
#تعریف_کړه LANG_TELUGU 0x4a
#تعریف_کړه LANG_THAI 0x1e
#تعریف_کړه LANG_TIBETAN 0x51
#تعریف_کړه LANG_TIGRIGNA 0x73
#تعریف_کړه LANG_TSWANA 0x32
#تعریف_کړه LANG_TURKISH 0x1f
#تعریف_کړه LANG_TURKMEN 0x42
#تعریف_کړه LANG_UIGHUR 0x80
#تعریف_کړه LANG_UKRAINIAN 0x22
#تعریف_کړه LANG_پاسنی_SORBIAN 0x2e
#تعریف_کړه LANG_URDU 0x20
#تعریف_کړه LANG_UZBEK 0x43
#تعریف_کړه LANG_VIETNAMESE 0x2a
#تعریف_کړه LANG_WELSH 0x52
#تعریف_کړه LANG_WOLOF 0x88
#تعریف_کړه LANG_XHOSA 0x34
#تعریف_کړه LANG_YAKUT 0x85
#تعریف_کړه LANG_YI 0x78
#تعریف_کړه LANG_YORUBA 0x6a
#تعریف_کړه LANG_ZULU 0x35

#تعریف_کړه SUBLANG_NEUTRAL 0x0
#تعریف_کړه SUBLANG_DEFAULT 0x1
#تعریف_کړه SUBLANG_SYS_DEFAULT 0x2
#تعریف_کړه SUBLANG_CUSTOM_DEFAULT 0x3
#تعریف_کړه SUBLANG_CUSTOM_UNSPECIFIED 0x4
#تعریف_کړه SUBLANG_UI_CUSTOM_DEFAULT 0x5

#تعریف_کړه SUBLANG_ARABIC_SAUDI_ARABIA 0x01
#تعریف_کړه SUBLANG_ARABIC_IRAQ 0x02
#تعریف_کړه SUBLANG_ARABIC_EGYPT 0x03
#تعریف_کړه SUBLANG_ARABIC_LIBYA 0x04
#تعریف_کړه SUBLANG_ARABIC_ALGERIA 0x05
#تعریف_کړه SUBLANG_ARABIC_MOROCCO 0x06
#تعریف_کړه SUBLANG_ARABIC_TUNISIA 0x07
#تعریف_کړه SUBLANG_ARABIC_OMAN 0x08
#تعریف_کړه SUBLANG_ARABIC_YEMEN 0x09
#تعریف_کړه SUBLANG_ARABIC_SYRIA 0x0a
#تعریف_کړه SUBLANG_ARABIC_JORDAN 0x0b
#تعریف_کړه SUBLANG_ARABIC_LEBANON 0x0c
#تعریف_کړه SUBLANG_ARABIC_KUWAIT 0x0d
#تعریف_کړه SUBLANG_ARABIC_UAE 0x0e
#تعریف_کړه SUBLANG_ARABIC_BAHRAIN 0x0f
#تعریف_کړه SUBLANG_ARABIC_QATAR 0x10
#تعریف_کړه SUBLANG_AZERI_LATIN 0x01
#تعریف_کړه SUBLANG_AZERI_CYRILLIC 0x02
#تعریف_کړه SUBLANG_CHINESE_TRADITIONAL 0x01
#تعریف_کړه SUBLANG_CHINESE_SIMPLIFIED 0x02
#تعریف_کړه SUBLANG_CHINESE_HONGKONG 0x03
#تعریف_کړه SUBLANG_CHINESE_SINGAPORE 0x04
#تعریف_کړه SUBLANG_CHINESE_MACAU 0x05
#تعریف_کړه SUBLANG_DUTCH 0x01
#تعریف_کړه SUBLANG_DUTCH_BELGIAN 0x02
#تعریف_کړه SUBLANG_ENGLISH_US 0x01
#تعریف_کړه SUBLANG_ENGLISH_UK 0x02
#تعریف_کړه SUBLANG_ENGLISH_AUS 0x03
#تعریف_کړه SUBLANG_ENGLISH_CAN 0x04
#تعریف_کړه SUBLANG_ENGLISH_NZ 0x05
#تعریف_کړه SUBLANG_ENGLISH_EIRE 0x06
#تعریف_کړه SUBLANG_ENGLISH_SOUTH_AFRICA 0x07
#تعریف_کړه SUBLANG_ENGLISH_JAMAICA 0x08
#تعریف_کړه SUBLANG_ENGLISH_CARIBBEAN 0x09
#تعریف_کړه SUBLANG_ENGLISH_BELIZE 0x0a
#تعریف_کړه SUBLANG_ENGLISH_TRINIDAD 0x0b
#تعریف_کړه SUBLANG_ENGLISH_ZIMBABWE 0x0c
#تعریف_کړه SUBLANG_ENGLISH_PHILIPPINES 0x0d
#تعریف_کړه SUBLANG_FRENCH 0x01
#تعریف_کړه SUBLANG_FRENCH_BELGIAN 0x02
#تعریف_کړه SUBLANG_FRENCH_CANADIAN 0x03
#تعریف_کړه SUBLANG_FRENCH_SWISS 0x04
#تعریف_کړه SUBLANG_FRENCH_LUXEMBOURG 0x05
#تعریف_کړه SUBLANG_FRENCH_MONACO 0x06
#تعریف_کړه SUBLANG_GERMAN 0x01
#تعریف_کړه SUBLANG_GERMAN_SWISS 0x02
#تعریف_کړه SUBLANG_GERMAN_AUSTRIAN 0x03
#تعریف_کړه SUBLANG_GERMAN_LUXEMBOURG 0x04
#تعریف_کړه SUBLANG_GERMAN_LIECHTENSTEIN 0x05
#تعریف_کړه SUBLANG_ITALIAN 0x01
#تعریف_کړه SUBLANG_ITALIAN_SWISS 0x02
#تعریف_کړه SUBLANG_KASHMIRI_SASIA 0x02
#تعریف_کړه SUBLANG_KASHMIRI_INDIA 0x02
#تعریف_کړه SUBLANG_KOREAN 0x01
#تعریف_کړه SUBLANG_LITHUANIAN 0x01
#تعریف_کړه SUBLANG_MALAY_MALAYSIA 0x01
#تعریف_کړه SUBLANG_MALAY_BRUNEI_DARUSSALAM 0x02
#تعریف_کړه SUBLANG_NEPALI_INDIA 0x02
#تعریف_کړه SUBLANG_NORWEGIAN_BOKMAL 0x01
#تعریف_کړه SUBLANG_NORWEGIAN_NYNORSK 0x02
#تعریف_کړه SUBLANG_PORTUGUESE 0x02
#تعریف_کړه SUBLANG_PORTUGUESE_BRAZILIAN 0x01
#تعریف_کړه SUBLANG_SERBIAN_LATIN 0x02
#تعریف_کړه SUBLANG_SERBIAN_CYRILLIC 0x03
#تعریف_کړه SUBLANG_SPANISH 0x01
#تعریف_کړه SUBLANG_SPANISH_MEXICAN 0x02
#تعریف_کړه SUBLANG_SPANISH_MODERN 0x03
#تعریف_کړه SUBLANG_SPANISH_GUATEMALA 0x04
#تعریف_کړه SUBLANG_SPANISH_COSTA_RICA 0x05
#تعریف_کړه SUBLANG_SPANISH_PANAMA 0x06
#تعریف_کړه SUBLANG_SPANISH_DOMINICAN_REPUBLIC 0x07
#تعریف_کړه SUBLANG_SPANISH_VENEZUELA 0x08
#تعریف_کړه SUBLANG_SPANISH_COLOMBIA 0x09
#تعریف_کړه SUBLANG_SPANISH_PERU 0x0a
#تعریف_کړه SUBLANG_SPANISH_ARGENTINA 0x0b
#تعریف_کړه SUBLANG_SPANISH_ECUADOR 0x0c
#تعریف_کړه SUBLANG_SPANISH_CHILE 0x0d
#تعریف_کړه SUBLANG_SPANISH_URUGUAY 0x0e
#تعریف_کړه SUBLANG_SPANISH_PARAGUAY 0x0f
#تعریف_کړه SUBLANG_SPANISH_BOLIVIA 0x10
#تعریف_کړه SUBLANG_SPANISH_EL_SALVADOR 0x11
#تعریف_کړه SUBLANG_SPANISH_HONDURAS 0x12
#تعریف_کړه SUBLANG_SPANISH_NICARAGUA 0x13
#تعریف_کړه SUBLANG_SPANISH_PUERTO_RICO 0x14
#تعریف_کړه SUBLANG_SWEDISH 0x01
#تعریف_کړه SUBLANG_SWEDISH_FINLAND 0x02
#تعریف_کړه SUBLANG_URDU_PAKISTAN 0x01
#تعریف_کړه SUBLANG_URDU_INDIA 0x02
#تعریف_کړه SUBLANG_UZBEK_LATIN 0x01
#تعریف_کړه SUBLANG_UZBEK_CYRILLIC 0x02

#تعریف_کړه ترتیبول_DEFAULT 0x0
#تعریف_کړه ترتیبول_INVARIANT_MATH 0x1

#تعریف_کړه ترتیبول_JAPANESE_XJIS 0x0
#تعریف_کړه ترتیبول_JAPANESE_UNICODE 0x1
#تعریف_کړه ترتیبول_JAPANESE_RADICALSTROKE 0x4

#تعریف_کړه ترتیبول_CHINESE_BIG5 0x0
#تعریف_کړه ترتیبول_CHINESE_PRCP 0x0
#تعریف_کړه ترتیبول_CHINESE_UNICODE 0x1
#تعریف_کړه ترتیبول_CHINESE_PRC 0x2
#تعریف_کړه ترتیبول_CHINESE_BOPOMOFO 0x3

#تعریف_کړه ترتیبول_KOREAN_KSC 0x0
#تعریف_کړه ترتیبول_KOREAN_UNICODE 0x1

#تعریف_کړه ترتیبول_GERMAN_PHONE_BOOK 0x1

#تعریف_کړه ترتیبول_HUNGARIAN_DEFAULT 0x0
#تعریف_کړه ترتیبول_HUNGARIAN_TECHNICAL 0x1

#تعریف_کړه ترتیبول_GEORGIAN_TRADITIONAL 0x0
#تعریف_کړه ترتیبول_GEORGIAN_MODERN 0x1

#تعریف_کړه MAKELANGID(p,s) ((((کلمه_3)(s)) << 10) | (کلمه_3)(p))
#تعریف_کړه PRIMARYLANGID(lgid) ((کلمه_3)(lgid) & 0x3ff)
#تعریف_کړه SUBLANGID(lgid) ((کلمه_3)(lgid) >> 10)

#تعریف_کړه NLS_VALID_LOCALE_ماسک 0x000fffff

#تعریف_کړه MAKELCID(lgid,srtid) ((DWORD)((((DWORD)((کلمه_3)(srtid))) << 16) | ((DWORD)((کلمه_3)(lgid)))))
#تعریف_کړه MAKESORTLCID(lgid,srtid,ver) ((DWORD)((MAKELCID(lgid,srtid)) | (((DWORD)((کلمه_3)(ver))) << 20)))
#تعریف_کړه LANGIDFROMLCID(lcid) ((کلمه_3)(lcid))
#تعریف_کړه SORTIDFROMLCID(lcid) ((کلمه_3)((((DWORD)(lcid)) >> 16) & 0xf))
#تعریف_کړه SORTVERSIONFROMLCID(lcid) ((کلمه_3)((((DWORD)(lcid)) >> 20) & 0xf))

#تعریف_کړه LOCALE_NAME_MAX_اوږدتیا 85
#تعریف_کړه LANG_SYSTEM_DEFAULT (MAKELANGID(LANG_NEUTRAL,SUBLANG_SYS_DEFAULT))
#تعریف_کړه LANG_USER_DEFAULT (MAKELANGID(LANG_NEUTRAL,SUBLANG_DEFAULT))

#تعریف_کړه LOCALE_SYSTEM_DEFAULT (MAKELCID(LANG_SYSTEM_DEFAULT,ترتیبول_DEFAULT))
#تعریف_کړه LOCALE_USER_DEFAULT (MAKELCID(LANG_USER_DEFAULT,ترتیبول_DEFAULT))

#تعریف_کړه LOCALE_NEUTRAL (MAKELCID(MAKELANGID(LANG_NEUTRAL,SUBLANG_NEUTRAL),ترتیبول_DEFAULT))

#تعریف_کړه LOCALE_CUSTOM_DEFAULT (MAKELCID(MAKELANGID(LANG_NEUTRAL, SUBLANG_CUSTOM_DEFAULT), ترتیبول_DEFAULT))
#تعریف_کړه LOCALE_CUSTOM_UNSPECIFIED (MAKELCID(MAKELANGID(LANG_NEUTRAL, SUBLANG_CUSTOM_UNSPECIFIED), ترتیبول_DEFAULT))
#تعریف_کړه LOCALE_CUSTOM_UI_DEFAULT (MAKELCID(MAKELANGID(LANG_NEUTRAL, SUBLANG_UI_CUSTOM_DEFAULT), ترتیبول_DEFAULT))

#تعریف_کړه LOCALE_INVARIANT (MAKELCID(MAKELANGID(LANG_INVARIANT,SUBLANG_NEUTRAL),ترتیبول_DEFAULT))

#تعریف_کړه UNREFERENCED_PARAMETER(P) (P)
#تعریف_کړه DBG_UNREFERENCED_PARAMETER(P) (P)
#تعریف_کړه DBG_UNREFERENCED_LOCAL_VARIABLE(V) (V)

#تعریف_کړه DEFAULT_UNREACHABLE

#که_نه_تعریف_شوی WIN32_NO_حالت
#تعریف_کړه حالت_WAIT_0 ((DWORD)0x00000000L)
#تعریف_کړه حالت_ABANDONED_WAIT_0 ((DWORD)0x00000080L)
#تعریف_کړه حالت_USER_APC ((DWORD)0x000000C0L)
#تعریف_کړه حالت_TIMEOUT ((DWORD)0x00000102L)
#تعریف_کړه حالت_PENDING ((DWORD)0x00000103L)
#تعریف_کړه DBG_EXCEPTION_HANDLED ((DWORD)0x00010001L)
#تعریف_کړه DBG_CONTINUE ((DWORD)0x00010002L)
#تعریف_کړه حالت_SEGMENT_NOTIFICATION ((DWORD)0x40000005L)
#تعریف_کړه DBG_TERMINATE_THREAD ((DWORD)0x40010003L)
#تعریف_کړه DBG_TERMINATE_PROCESS ((DWORD)0x40010004L)
#تعریف_کړه DBG_CONTROL_C ((DWORD)0x40010005L)
#تعریف_کړه DBG_CONTROL_BREAK ((DWORD)0x40010008L)
#تعریف_کړه DBG_COMMAND_EXCEPTION ((DWORD)0x40010009L)
#تعریف_کړه حالت_GUARD_پاڼه_VIOLATION ((DWORD)0x80000001L)
#تعریف_کړه حالت_DATATYPE_MISALIGNMENT ((DWORD)0x80000002L)
#تعریف_کړه حالت_BREAKPOINT ((DWORD)0x80000003L)
#تعریف_کړه حالت_SINGLE_ګام ((DWORD)0x80000004L)
#تعریف_کړه DBG_EXCEPTION_NOT_HANDLED ((DWORD)0x80010001L)
#تعریف_کړه حالت_ACCESS_VIOLATION ((DWORD)0xC0000005L)
#تعریف_کړه حالت_دننه_پاڼه_ERROR ((DWORD)0xC0000006L)
#تعریف_کړه حالت_INVALID_HANDLE ((DWORD)0xC0000008L)
#تعریف_کړه حالت_NO_حافظه ((DWORD)0xC0000017L)
#تعریف_کړه حالت_ILLEGAL_INSTRUCTION ((DWORD)0xC000001DL)
#تعریف_کړه حالت_NONCONTINUABLE_EXCEPTION ((DWORD)0xC0000025L)
#تعریف_کړه حالت_INVALID_DISPOSITION ((DWORD)0xC0000026L)
#تعریف_کړه حالت_ARRAY_BOUNDS_EXCEEDED ((DWORD)0xC000008CL)
#تعریف_کړه حالت_FLOAT_DENORMAL_عملوند ((DWORD)0xC000008DL)
#تعریف_کړه حالت_FLOAT_DIVIDE_BY_ZERO ((DWORD)0xC000008EL)
#تعریف_کړه حالت_FLOAT_INEXACT_پایله ((DWORD)0xC000008FL)
#تعریف_کړه حالت_FLOAT_INVALID_OPERATION ((DWORD)0xC0000090L)
#تعریف_کړه حالت_FLOAT_ډکېدنه ((DWORD)0xC0000091L)
#تعریف_کړه حالت_FLOAT_ډېری_CHECK ((DWORD)0xC0000092L)
#تعریف_کړه حالت_FLOAT_UNDERFLOW ((DWORD)0xC0000093L)
#تعریف_کړه حالت_INTEGER_DIVIDE_BY_ZERO ((DWORD)0xC0000094L)
#تعریف_کړه حالت_INTEGER_ډکېدنه ((DWORD)0xC0000095L)
#تعریف_کړه حالت_PRIVILEGED_INSTRUCTION ((DWORD)0xC0000096L)
#تعریف_کړه حالت_ډېری_ډکېدنه ((DWORD)0xC00000FDL)
#تعریف_کړه حالت_CONTROL_C_EXIT ((DWORD)0xC000013AL)
#تعریف_کړه حالت_FLOAT_مضرب_تېروتنې ((DWORD)0xC00002B4L)
#تعریف_کړه حالت_FLOAT_مضرب_TRAPS ((DWORD)0xC00002B5L)
#تعریف_کړه حالت_REG_NAT_CONSUMPTION ((DWORD)0xC00002C9L)
#تعریف_کړه حالت_SXS_EARLY_DEACTIVATION ((DWORD)0xC015000FL)
#تعریف_کړه حالت_SXS_INVALID_DEACTIVATION ((DWORD)0xC0150010L)
#د_که_پای

#تعریف_کړه اعظمي_WAIT_OBJECTS 64
#تعریف_کړه اعظمي_SUSPEND_شمېر MAXCHAR

  تعريفنوع ULONG_PTR KSPIN_قلف;
  تعريفنوع KSPIN_قلف *PKSPIN_قلف;

#إذا defined(__x86_64) && !defined(RC_INVOKED)

#که_تعریف_شوی __cplusplus
  خارجي "C" {
#د_که_پای

#تعریف_کړه بټ_Test _bittest
#تعریف_کړه بټ_Test_And_Complement _bittestandcomplement
#تعریف_کړه بټ_Test_And_سېټ _bittestandset
#تعریف_کړه بټ_Test_And_Reset _bittestandreset
#تعریف_کړه Interlocked_بټ_Test_And_سېټ _interlockedbittestandset
#تعریف_کړه Interlocked_بټ_Test_And_Reset _interlockedbittestandreset
#تعریف_کړه بټ_Test64 _bittest64
#تعریف_کړه بټ_Test_And_Complement64 _bittestandcomplement64
#تعریف_کړه بټ_Test_And_Set64 _bittestandset64
#تعریف_کړه بټ_Test_And_Reset64 _bittestandreset64
#تعریف_کړه Interlocked_بټ_Test_And_Set64 _interlockedbittestandset64
#تعریف_کړه Interlocked_بټ_Test_And_Reset64 _interlockedbittestandreset64

    __CRT_INLINE BOOLEAN _bittest(LONG ثابت *بنسټ_2,LONG دننه_واټن_3) {
      صحيح old = 0;
      __asm__ __volatile__("btl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متطاير اوږد *) بنسټ_2))
	:"Ir" (دننه_واټن_3));
      أرجع (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandcomplement(LONG *بنسټ_2,LONG دننه_واټن_3) {
      صحيح old = 0;
      __asm__ __volatile__("btcl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متطاير اوږد *) بنسټ_2))
	:"Ir" (دننه_واټن_3));
      أرجع (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN Interlocked_بټ_Test_And_Complement(LONG *بنسټ_2,LONG بټ_2) {
      صحيح old = 0;
      __asm__ __volatile__("lock ; btcl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متطاير اوږد *) بنسټ_2))
	:"Ir" (بټ_2));
      أرجع (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandset(LONG *بنسټ_2,LONG دننه_واټن_3) {
      صحيح old = 0;
      __asm__ __volatile__("btsl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متطاير اوږد *) بنسټ_2))
	:"Ir" (دننه_واټن_3));
      أرجع (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandreset(LONG *بنسټ_2,LONG دننه_واټن_3) {
      صحيح old = 0;
      __asm__ __volatile__("btrl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متطاير اوږد *) بنسټ_2))
	:"Ir" (دننه_واټن_3));
      أرجع (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _interlockedbittestandset(LONG *بنسټ_2,LONG دننه_واټن_3) {
      صحيح old = 0;
      __asm__ __volatile__("lock ; btsl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متطاير اوږد *) بنسټ_2))
	:"Ir" (دننه_واټن_3));
      أرجع (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _interlockedbittestandreset(LONG *بنسټ_2,LONG دننه_واټن_3) {
      صحيح old = 0;
      __asm__ __volatile__("lock ; btrl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متطاير اوږد *) بنسټ_2))
	:"Ir" (دننه_واټن_3));
      أرجع (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittest64(LONG64 ثابت *بنسټ_2,LONG64 دننه_واټن_3) {
      صحيح old = 0;
      __asm__ __volatile__("btq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متطاير اوږد اوږد *) بنسټ_2))
	:"Ir" (دننه_واټن_3));
      أرجع (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandcomplement64(LONG64 *بنسټ_2,LONG64 دننه_واټن_3) {
      صحيح old = 0;
      __asm__ __volatile__("btcq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متطاير اوږد اوږد *) بنسټ_2))
	:"Ir" (دننه_واټن_3));
      أرجع (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandset64(LONG64 *بنسټ_2,LONG64 دننه_واټن_3) {
      صحيح old = 0;
      __asm__ __volatile__("btsq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متطاير اوږد اوږد *) بنسټ_2))
	:"Ir" (دننه_واټن_3));
      أرجع (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandreset64(LONG64 *بنسټ_2,LONG64 دننه_واټن_3) {
      صحيح old = 0;
      __asm__ __volatile__("btrq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متطاير اوږد اوږد *) بنسټ_2))
	:"Ir" (دننه_واټن_3));
      أرجع (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _interlockedbittestandset64(LONG64 *بنسټ_2,LONG64 دننه_واټن_3) {
      صحيح old = 0;
      __asm__ __volatile__("lock ; btsq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متطاير اوږد اوږد *) بنسټ_2))
	:"Ir" (دننه_واټن_3));
      أرجع (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _interlockedbittestandreset64(LONG64 *بنسټ_2,LONG64 دننه_واټن_3) {
      صحيح old = 0;
      __asm__ __volatile__("lock ; btrq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متطاير اوږد اوږد *) بنسټ_2))
	:"Ir" (دننه_واټن_3));
      أرجع (BOOLEAN) (old!=0);
    }
#تعریف_کړه بټ_لټون_Forward بټ_لټون_Forward_2
#تعریف_کړه بټ_لټون_سرچپه بټ_لټون_سرچپه_2
#تعریف_کړه بټ_لټون_Forward64 بټ_لټون_Forward64_2
#تعریف_کړه بټ_لټون_Reverse64 بټ_لټون_Reverse64_2

    __CRT_INLINE BOOLEAN بټ_لټون_Forward_2(DWORD *شاخص_3,DWORD ماسک_3) {
      __asm__ __volatile__("bsfl %1,%0" : "=r" (ماسک_3),"=m" ((*(متطاير اوږد *)شاخص_3)));
      أرجع ماسک_3!=0;
    }
    __CRT_INLINE BOOLEAN بټ_لټون_سرچپه_2(DWORD *شاخص_3,DWORD ماسک_3) {
      __asm__ __volatile__("bsrl %1,%0" : "=r" (ماسک_3),"=m" ((*(متطاير اوږد *)شاخص_3)));
      أرجع ماسک_3!=0;
    }
    __CRT_INLINE BOOLEAN بټ_لټون_Forward64_2(DWORD *شاخص_3,DWORD64 ماسک_3) {
      __asm__ __volatile__("bsfq %1,%0" : "=r" (ماسک_3),"=m" ((*(متطاير اوږد اوږد *)شاخص_3)));
      أرجع ماسک_3!=0;
    }
    __CRT_INLINE BOOLEAN بټ_لټون_Reverse64_2(DWORD *شاخص_3,DWORD64 ماسک_3) {
      __asm__ __volatile__("bsrq %1,%0" : "=r" (ماسک_3),"=m" ((*(متطاير اوږد اوږد *)شاخص_3)));
      أرجع ماسک_3!=0;
    }

#تعریف_کړه InterlockedIncrement16 _InterlockedIncrement16
#تعریف_کړه InterlockedDecrement16 _InterlockedDecrement16
#تعریف_کړه InterlockedCompareExchange16 _InterlockedCompareExchange16

#تعریف_کړه InterlockedAnd _InterlockedAnd
#تعریف_کړه InterlockedOr _InterlockedOr
#تعریف_کړه InterlockedXor _InterlockedXor
#تعریف_کړه InterlockedIncrement _InterlockedIncrement
#تعریف_کړه InterlockedIncrementAcquire InterlockedIncrement
#تعریف_کړه InterlockedIncrementRelease InterlockedIncrement
#تعریف_کړه InterlockedDecrement _InterlockedDecrement
#تعریف_کړه InterlockedDecrementAcquire InterlockedDecrement
#تعریف_کړه InterlockedDecrementRelease InterlockedDecrement
#تعریف_کړه Interlocked_جمع_کړه Interlocked_جمع_کړه_2
#تعریف_کړه InterlockedExchange _InterlockedExchange
#تعریف_کړه Interlocked_Exchange_جمع_کړه Interlocked_Exchange_جمع_کړه_2
#تعریف_کړه InterlockedCompareExchange _InterlockedCompareExchange
#تعریف_کړه InterlockedCompareExchangeAcquire InterlockedCompareExchange
#تعریف_کړه InterlockedCompareExchangeRelease InterlockedCompareExchange

#تعریف_کړه InterlockedAnd64 _InterlockedAnd64
#تعریف_کړه InterlockedAndAffinity InterlockedAnd64
#تعریف_کړه InterlockedOr64 _InterlockedOr64
#تعریف_کړه InterlockedOrAffinity InterlockedOr64
#تعریف_کړه InterlockedXor64 _InterlockedXor64
#تعریف_کړه InterlockedIncrement64 _InterlockedIncrement64
#تعریف_کړه InterlockedDecrement64 _InterlockedDecrement64
#تعریف_کړه InterlockedAdd64 _InterlockedAdd64
#تعریف_کړه InterlockedExchange64 _InterlockedExchange64
#تعریف_کړه InterlockedExchangeAcquire64 InterlockedExchange64
#تعریف_کړه InterlockedExchangeAdd64 _InterlockedExchangeAdd64
#تعریف_کړه InterlockedCompareExchange64 _InterlockedCompareExchange64
#تعریف_کړه InterlockedCompareExchangeAcquire64 InterlockedCompareExchange64
#تعریف_کړه InterlockedCompareExchangeRelease64 InterlockedCompareExchange64

#تعریف_کړه Interlocked_Exchange_اشاره_ګر Interlocked_Exchange_اشاره_ګر_2
#تعریف_کړه Interlocked_Compare_Exchange_اشاره_ګر Interlocked_Compare_Exchange_اشاره_ګر_2
#تعریف_کړه Interlocked_Compare_Exchange_اشاره_ګر_Acquire Interlocked_Compare_Exchange_اشاره_ګر_2
#تعریف_کړه Interlocked_Compare_Exchange_اشاره_ګر_Release Interlocked_Compare_Exchange_اشاره_ګر_2

#تعریف_کړه Interlocked_Exchange_جمع_کړه_اندازه_T(a,b) InterlockedExchangeAdd64((LONG64 *)a,b)
#تعریف_کړه Interlocked_Increment_اندازه_T(a) InterlockedIncrement64((LONG64 *)a)
#تعریف_کړه Interlocked_Decrement_اندازه_T(a) InterlockedDecrement64((LONG64 *)a)

    __CRT_INLINE SHORT InterlockedIncrement16(SHORT متطاير *Addend) {
      بینښه حرف c;
      بینښه حرف s;
      __asm__ __volatile__(
	"lock ; addw $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      أرجع (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE SHORT InterlockedDecrement16(SHORT متطاير *Addend) {
      بینښه حرف c;
      بینښه حرف s;
      __asm__ __volatile__(
	"lock ; subw $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      أرجع (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE SHORT InterlockedCompareExchange16(SHORT متطاير *Destination,SHORT ExChange,SHORT Comperand) {
      SHORT prev;
      __asm__ __volatile__("lock ; cmpxchgw %w1,%2"
	:"=a"(prev)
	:"q"(ExChange), "m"(*Destination), "0"(Comperand)
	: "memory");
      أرجع prev;
    }
    __CRT_INLINE LONG InterlockedAnd(LONG متطاير *Destination,LONG ارزښت_3) {
      __asm__ __volatile__("lock ; andl %0,%1"
	: :"r"(ارزښت_3),"m"(*Destination)
	: "memory");
      أرجع *Destination;
    }
    __CRT_INLINE LONG InterlockedOr(LONG متطاير *Destination,LONG ارزښت_3) {
      __asm__ __volatile__("lock ; orl %0,%1"
	: : "r"(ارزښت_3),"m"(*Destination) : "memory");
      أرجع *Destination;
    }
    __CRT_INLINE LONG InterlockedXor(LONG متطاير *Destination,LONG ارزښت_3) {
      __asm__ __volatile__("lock ; xorl %0,%1"
	: : "r"(ارزښت_3),"m"(*Destination) : "memory");
      أرجع *Destination;
    }
    //		$$$$
    __CRT_INLINE LONG64 InterlockedAnd64(LONG64 متطاير *Destination,LONG64 ارزښت_3) {
      __asm__ __volatile__("lock ; andq %0,%1"
	: : "r"(ارزښت_3),"m"(*Destination) : "memory");
      أرجع *Destination;
    }
    __CRT_INLINE LONG64 InterlockedOr64(LONG64 متطاير *Destination,LONG64 ارزښت_3) {
      __asm__ __volatile__("lock ; orq %0,%1"
	: : "r"(ارزښت_3),"m"(*Destination) : "memory");
      أرجع *Destination;
    }
    __CRT_INLINE LONG64 InterlockedXor64(LONG64 متطاير *Destination,LONG64 ارزښت_3) {
      __asm__ __volatile__("lock ; xorq %0,%1"
	: : "r"(ارزښت_3),"m"(*Destination) : "memory");
      أرجع *Destination;
    }
    __CRT_INLINE LONG InterlockedIncrement(LONG متطاير *Addend) {
      بینښه حرف c;
      بینښه حرف s;
      __asm__ __volatile__(
	"lock ; addl $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      أرجع (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE LONG InterlockedDecrement(LONG متطاير *Addend) {
      بینښه حرف c;
      بینښه حرف s;
      __asm__ __volatile__(
	"lock ; subl $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      أرجع (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE LONG InterlockedExchange(LONG متطاير *موخه_2,LONG ارزښت_3) {
      __asm__ __volatile("lock ; xchgl %0,%1"
	: "=r"(ارزښت_3)
	: "m"(*موخه_2),"0"(ارزښت_3)
	: "memory");
      أرجع ارزښت_3;
    }
    LONG Interlocked_Exchange_جمع_کړه(LONG متطاير *Addend,LONG ارزښت_3);

#که_نه_تعریف_شوی _X86AMD64_
    __CRT_INLINE LONG Interlocked_جمع_کړه(LONG متطاير *Addend,LONG ارزښت_3) { أرجع Interlocked_Exchange_جمع_کړه(Addend,ارزښت_3) + ارزښت_3; }
#د_که_پای
    __CRT_INLINE LONG InterlockedCompareExchange(LONG متطاير *Destination,LONG ExChange,LONG Comperand) {
      LONG prev;
      __asm__ __volatile__("lock ; cmpxchgl %1,%2" : "=a" (prev) : "q" (ExChange),"m" (*Destination), "0" (Comperand) : "memory");
      أرجع prev;
    }
    __CRT_INLINE LONG64 InterlockedIncrement64(LONG64 متطاير *Addend) {
      بینښه حرف c;
      بینښه حرف s;
      __asm__ __volatile__(
	"lock ; addq $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      أرجع (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE LONG64 InterlockedDecrement64(LONG64 متطاير *Addend) {
      بینښه حرف c;
      بینښه حرف s;
      __asm__ __volatile__(
	"lock ; subq $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      أرجع (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE LONG64 InterlockedExchange64(LONG64 متطاير *موخه_2,LONG64 ارزښت_3) {
      __asm__ __volatile("lock ; xchgq %0,%1"
	: "=r"(ارزښت_3)
	: "m"(*موخه_2),"0"(ارزښت_3)
	: "memory");
      أرجع ارزښت_3;
    }
    LONG64 InterlockedExchangeAdd64(LONG64 متطاير *Addend,LONG64 ارزښت_3);

#که_نه_تعریف_شوی _X86AMD64_
    __CRT_INLINE LONG64 InterlockedAdd64(LONG64 متطاير *Addend,LONG64 ارزښت_3) { أرجع InterlockedExchangeAdd64(Addend,ارزښت_3) + ارزښت_3; }
#د_که_پای

    __CRT_INLINE LONG64 InterlockedCompareExchange64(LONG64 متطاير *Destination,LONG64 ExChange,LONG64 Comperand) {
      LONG64 prev;
      __asm__ __volatile__("lock ; cmpxchgq %1,%2" : "=a" (prev) : "q" (ExChange),"m" (*Destination), "0" (Comperand) : "memory");
      أرجع prev;
    }
    __CRT_INLINE PVOID Interlocked_Compare_Exchange_اشاره_ګر(PVOID متطاير *Destination,PVOID ExChange,PVOID Comperand) {
      PVOID prev;
      __asm__ __volatile__("lock ; cmpxchgq %1,%2" : "=a" (prev) : "q" (ExChange),"m" (*Destination), "0" (Comperand) : "memory");
      أرجع prev;
    }
    __CRT_INLINE PVOID Interlocked_Exchange_اشاره_ګر(PVOID متطاير *موخه_2,PVOID ارزښت_3) {
      __asm__ __volatile("lock ; xchgq %0,%1"
	: "=r"(ارزښت_3)
	: "m"(*موخه_2),"0"(ارزښت_3)
	: "memory");
      أرجع ارزښت_3;
    }

#تعریف_کړه Cache_کرښه_Flush(پته_2) _mm_clflush(پته_2)

    VOID _ReadWriteBarrier(VOID);

#تعریف_کړه FastFence __faststorefence
#تعریف_کړه بارول_Fence _mm_lfence
#تعریف_کړه حافظه_Fence _mm_mfence
#تعریف_کړه StoreFence _mm_sfence

    VOID __faststorefence(VOID);
    VOID _m_prefetchw(متطاير CONST VOID *سرچینه_2);

//!__TINYC__: #include <intrin.h>

#تعریف_کړه YieldProcessor _mm_pause
#تعریف_کړه حافظه_Barrier __faststorefence
#تعریف_کړه Pre_Fetch_Cache_کرښه(l,a) _mm_prefetch((CHAR CONST *) a,l)
#تعریف_کړه PrefetchForWrite(p) _m_prefetchw(p)
#تعریف_کړه ReadForWriteAccess(p) (_m_prefetchw(p),*(p))

#تعریف_کړه PF_TEMPORAL_LEVEL_1 _MM_HINT_T0
#تعریف_کړه PF_TEMPORAL_LEVEL_2 _MM_HINT_T1
#تعریف_کړه PF_TEMPORAL_LEVEL_3 _MM_HINT_T2
#تعریف_کړه PF_NON_TEMPORAL_LEVEL_ALL _MM_HINT_NTA

#تعریف_کړه ReadMxCsr _mm_getcsr
#تعریف_کړه WriteMxCsr _mm_setcsr

    VOID __int2c(VOID);

#تعریف_کړه DbgRaiseAssertionFailure() __int2c()
#تعریف_کړه GetCallersEflags() __getcallerseflags()

    بینښه __int32 __getcallerseflags(VOID);

#تعریف_کړه Get_Segment_حد __segmentlimit

    DWORD __segmentlimit(DWORD Selector);

#تعریف_کړه Read_وخت_Stamp_Counter() __rdtsc()

    DWORD64 __rdtsc(VOID);
    VOID __movsb(PBYTE Destination,BYTE ثابت *سرچینه_2,اندازه_T شمېر_3);
    VOID __movsw(PWORD Destination,کلمه_3 ثابت *سرچینه_2,اندازه_T شمېر_3);
    VOID __movsd(PDWORD Destination,DWORD ثابت *سرچینه_2,اندازه_T شمېر_3);
    VOID __movsq(PDWORD64 Destination,DWORD64 ثابت *سرچینه_2,اندازه_T شمېر_3);
    VOID __stosb(PBYTE Destination,BYTE ارزښت_3,اندازه_T شمېر_3);
    VOID __stosw(PWORD Destination,کلمه_3 ارزښت_3,اندازه_T شمېر_3);
    VOID __stosd(PDWORD Destination,DWORD ارزښت_3,اندازه_T شمېر_3);
    VOID __stosq(PDWORD64 Destination,DWORD64 ارزښت_3,اندازه_T شمېر_3);

#تعریف_کړه Multiply_لوړ __mulh
#تعریف_کړه Unsigned_Multiply_لوړ __umulh

    LONGLONG Multiply_لوړ(LONGLONG Multiplier,LONGLONG Multiplicand);
    ULONGLONG Unsigned_Multiply_لوړ(ULONGLONG Multiplier,ULONGLONG Multiplicand);

#تعریف_کړه ښويدنه_Left128 __shiftleft128
#تعریف_کړه ښويدنه_Right128 __shiftright128

    DWORD64 ښويدنه_Left128(DWORD64 ټیټ_Part,DWORD64 لوړ_Part,BYTE ښويدنه_3);
    DWORD64 ښويدنه_Right128(DWORD64 ټیټ_Part,DWORD64 لوړ_Part,BYTE ښويدنه_3);

#تعریف_کړه Multiply128 _mul128

    LONG64 Multiply128(LONG64 Multiplier,LONG64 Multiplicand,LONG64 *لوړ_حاصل_ضرب);

#تعریف_کړه UnsignedMultiply128 _umul128

    DWORD64 UnsignedMultiply128(DWORD64 Multiplier,DWORD64 Multiplicand,DWORD64 *لوړ_حاصل_ضرب);

    __CRT_INLINE LONG64 MultiplyExtract128(LONG64 Multiplier,LONG64 Multiplicand,BYTE ښويدنه_3) {
      LONG64 extracted_حاصل_ضرب;
      LONG64 لوړ_حاصل_ضرب_2;
      LONG64 ټیټ_حاصل_ضرب;
      ټیټ_حاصل_ضرب = Multiply128(Multiplier,Multiplicand,&لوړ_حاصل_ضرب_2);
      extracted_حاصل_ضرب = (LONG64)ښويدنه_Right128((LONG64)ټیټ_حاصل_ضرب,(LONG64)لوړ_حاصل_ضرب_2,ښويدنه_3);
      أرجع extracted_حاصل_ضرب;
    }

    __CRT_INLINE DWORD64 UnsignedMultiplyExtract128(DWORD64 Multiplier,DWORD64 Multiplicand,BYTE ښويدنه_3) {
      DWORD64 extracted_حاصل_ضرب;
      DWORD64 لوړ_حاصل_ضرب_2;
      DWORD64 ټیټ_حاصل_ضرب;
      ټیټ_حاصل_ضرب = UnsignedMultiply128(Multiplier,Multiplicand,&لوړ_حاصل_ضرب_2);
      extracted_حاصل_ضرب = ښويدنه_Right128(ټیټ_حاصل_ضرب,لوړ_حاصل_ضرب_2,ښويدنه_3);
      أرجع extracted_حاصل_ضرب;
    }

    __CRT_INLINE BYTE __readgsbyte(DWORD دننه_واټن_3) {
      BYTE ret;
      __asm__ متطاير ("movb	%%gs:%1,%0"
	: "=r" (ret) ,"=m" ((*(متطاير اوږد *) (DWORD64) دننه_واټن_3)));
      أرجع ret;
    }
    __CRT_INLINE کلمه_3 __readgsword(DWORD دننه_واټن_3) {
      کلمه_3 ret;
      __asm__ متطاير ("movw	%%gs:%1,%0"
	: "=r" (ret) ,"=m" ((*(متطاير اوږد *) (DWORD64) دننه_واټن_3)));
      أرجع ret;
    }
    __CRT_INLINE DWORD __readgsdword(DWORD دننه_واټن_3) {
      DWORD ret;
      __asm__ متطاير ("movl	%%gs:%1,%0"
	: "=r" (ret) ,"=m" ((*(متطاير اوږد *) (DWORD64) دننه_واټن_3)));
      أرجع ret;
    }
    __CRT_INLINE DWORD64 __readgsqword(DWORD دننه_واټن_3) {
      فراغ *ret;
      __asm__ متطاير ("movq	%%gs:%1,%0"
	: "=r" (ret) ,"=m" ((*(متطاير اوږد *) (DWORD64) دننه_واټن_3)));
      أرجع (DWORD64) ret;
    }
    __CRT_INLINE VOID __writegsbyte(DWORD دننه_واټن_3,BYTE معلومات_3) {
      __asm__ متطاير ("movb	%0,%%gs:%1"
	: "=r" (معلومات_3) ,"=m" ((*(متطاير اوږد *) (DWORD64) دننه_واټن_3)));
    }
    __CRT_INLINE VOID __writegsword(DWORD دننه_واټن_3,کلمه_3 معلومات_3) {
      __asm__ متطاير ("movw	%0,%%gs:%1"
	: "=r" (معلومات_3) ,"=m" ((*(متطاير اوږد *) (DWORD64) دننه_واټن_3)));
    }
    __CRT_INLINE VOID __writegsdword(DWORD دننه_واټن_3,DWORD معلومات_3) {
      __asm__ متطاير ("movl	%0,%%gs:%1"
	: "=r" (معلومات_3) ,"=m" ((*(متطاير اوږد *) (DWORD64) دننه_واټن_3)));
    }
    __CRT_INLINE VOID __writegsqword(DWORD دننه_واټن_3,DWORD64 معلومات_3) {
      __asm__ متطاير ("movq	%0,%%gs:%1"
	: "=r" (معلومات_3) ,"=m" ((*(متطاير اوږد *) (DWORD64) دننه_واټن_3)));
    }

#که_تعریف_شوی __cplusplus
  }
#د_که_پای

#تعریف_کړه EXCEPTION_READ_FAULT 0
#تعریف_کړه EXCEPTION_WRITE_FAULT 1
#تعریف_کړه EXCEPTION_EXECUTE_FAULT 8

#إذا !defined(RC_INVOKED)

#تعریف_کړه CONTEXT_AMD64 0x100000

#تعریف_کړه CONTEXT_CONTROL (CONTEXT_AMD64 | 0x1L)
#تعریف_کړه CONTEXT_INTEGER (CONTEXT_AMD64 | 0x2L)
#تعریف_کړه CONTEXT_SEGMENTS (CONTEXT_AMD64 | 0x4L)
#تعریف_کړه CONTEXT_FLOATING_ټکی (CONTEXT_AMD64 | 0x8L)
#تعریف_کړه CONTEXT_DEBUG_REGISTERS (CONTEXT_AMD64 | 0x10L)

#تعریف_کړه CONTEXT_ډک (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_FLOATING_ټکی)
#تعریف_کړه CONTEXT_ALL (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_SEGMENTS | CONTEXT_FLOATING_ټکی | CONTEXT_DEBUG_REGISTERS)

#تعریف_کړه CONTEXT_EXCEPTION_فعال 0x8000000
#تعریف_کړه CONTEXT_SERVICE_فعال 0x10000000
#تعریف_کړه CONTEXT_EXCEPTION_REQUEST 0x40000000
#تعریف_کړه CONTEXT_EXCEPTION_REPORTING 0x80000000
#د_که_پای

#تعریف_کړه INITIAL_MXCSR 0x1f80
#تعریف_کړه INITIAL_FPCSR 0x027f

  تعريفنوع بنية DECLSPEC_ALIGN(16) _M128A {
    ULONGLONG ټیټ_3;
    LONGLONG لوړ_3;
  } M128A,*PM128A;

  تعريفنوع بنية _XMM_SAVE_AREA32 {
    کلمه_3 Control_کلمه;
    کلمه_3 حالت_کلمه;
    BYTE نښان_کلمه;
    BYTE Reserved1;
    کلمه_3 ErrorOpcode;
    DWORD Error_دننه_واټن;
    کلمه_3 ErrorSelector;
    کلمه_3 Reserved2;
    DWORD معلومات_دننه_واټن_2;
    کلمه_3 معلومات_Selector;
    کلمه_3 Reserved3;
    DWORD MxCsr;
    DWORD Mx_Csr_ماسک;
    M128A FloatRegisters[8];
    M128A XmmRegisters[16];
    BYTE Reserved4[96];
  } XMM_SAVE_AREA32,*PXMM_SAVE_AREA32;

#تعریف_کړه LEGACY_SAVE_AREA_اوږدتیا حجم(XMM_SAVE_AREA32)

  تعريفنوع بنية DECLSPEC_ALIGN(16) _CONTEXT {
    DWORD64 P1Home;
    DWORD64 P2Home;
    DWORD64 P3Home;
    DWORD64 P4Home;
    DWORD64 P5Home;
    DWORD64 P6Home;
    DWORD ContextFlags;
    DWORD MxCsr;
    کلمه_3 SegCs;
    کلمه_3 SegDs;
    کلمه_3 SegEs;
    کلمه_3 SegFs;
    کلمه_3 SegGs;
    کلمه_3 SegSs;
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
    اتحاد {
      XMM_SAVE_AREA32 FltSave;
      XMM_SAVE_AREA32 FloatSave;
      بنية {
	M128A سرلیک_2[2];
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
    M128A ویکټور_ثبتوونکی[26];
    DWORD64 ویکټور_Control;
    DWORD64 DebugControl;
    DWORD64 وروستی_Branch_منزل_Rip;
    DWORD64 وروستی_Branch_From_Rip;
    DWORD64 وروستی_Exception_منزل_Rip;
    DWORD64 وروستی_Exception_From_Rip;
  } CONTEXT,*PCONTEXT;

#تعریف_کړه RUNTIME_FUNCTION_غیرمستقیم 0x1

  تعريفنوع بنية _RUNTIME_FUNCTION {
    DWORD Begin_پته;
    DWORD پای_ټکی_پته;
    DWORD Unwind_معلومات;
  } RUNTIME_FUNCTION,*PRUNTIME_FUNCTION;

  تعريفنوع PRUNTIME_FUNCTION (*PGET_RUNTIME_FUNCTION_CALLBACK)(DWORD64 ControlPc,PVOID Context);
  تعريفنوع DWORD (*POUT_د_PROCESS_FUNCTION_جدول_CALLBACK)(HANDLE Process,PVOID جدول_پته,PDWORD Entries,PRUNTIME_FUNCTION *Functions);

#تعریف_کړه بهر_د_PROCESS_FUNCTION_جدول_CALLBACK_EXPORT_NAME "OutOfProcessFunctionTableCallback"
#د_که_پای /* defined(__x86_64) && !defined(RC_INVOKED) */

#إذا defined(__TINYC__) && (defined(__aarch64__) || defined(__arm64__)) && !defined(RC_INVOKED)

#تعریف_کړه __TCC_WINNT_ATOMIC_SEQ_CST 5
/* TCC lowers __atomic_compare_exchange's fourth argument as weak, but the
   ARM64 helper reads it as success_memorder.  Strong CAS passes weak == 0,
   so keep Interlocked's barriers explicit here. */
#تعریف_کړه __TCC_WINNT_MEMORY_BARRIER() __asm__ __volatile__("dmb ish" : : : "memory")

/* This covers the LONG operations needed by TCC's semaphore code and the
   pointer helpers that winbase.h exposes through Interlocked pointer macros.
   Add local helpers before relying on increment/decrement, add/exchange-add,
   bitwise, or 64-bit Interlocked forms on Windows ARM64 with TCC. */

    __CRT_INLINE LONG InterlockedExchange(LONG متطاير *موخه_2,LONG ارزښت_3) {
      LONG Old;
      __atomic_load(موخه_2,&Old,__TCC_WINNT_ATOMIC_SEQ_CST);
      __TCC_WINNT_MEMORY_BARRIER();
      طالما (!__atomic_compare_exchange(موخه_2,&Old,&ارزښت_3,0,
	__TCC_WINNT_ATOMIC_SEQ_CST,__TCC_WINNT_ATOMIC_SEQ_CST))
	;
      __TCC_WINNT_MEMORY_BARRIER();
      أرجع Old;
    }
    __CRT_INLINE LONG InterlockedCompareExchange(LONG متطاير *Destination,LONG ExChange,LONG Comperand) {
      LONG Old = Comperand;
      __TCC_WINNT_MEMORY_BARRIER();
      __atomic_compare_exchange(Destination,&Old,&ExChange,0,
	__TCC_WINNT_ATOMIC_SEQ_CST,__TCC_WINNT_ATOMIC_SEQ_CST);
      __TCC_WINNT_MEMORY_BARRIER();
      أرجع Old;
    }
    __CRT_INLINE PVOID __TCC_WINNT_InterlockedExchangePointer(PVOID متطاير *موخه_2,PVOID ارزښت_3) {
      PVOID Old;
      __atomic_load(موخه_2,&Old,__TCC_WINNT_ATOMIC_SEQ_CST);
      __TCC_WINNT_MEMORY_BARRIER();
      طالما (!__atomic_compare_exchange(موخه_2,&Old,&ارزښت_3,0,
	__TCC_WINNT_ATOMIC_SEQ_CST,__TCC_WINNT_ATOMIC_SEQ_CST))
	;
      __TCC_WINNT_MEMORY_BARRIER();
      أرجع Old;
    }
    __CRT_INLINE PVOID __TCC_WINNT_InterlockedCompareExchangePointer(PVOID متطاير *Destination,PVOID ExChange,PVOID Comperand) {
      PVOID Old = Comperand;
      __TCC_WINNT_MEMORY_BARRIER();
      __atomic_compare_exchange(Destination,&Old,&ExChange,0,
	__TCC_WINNT_ATOMIC_SEQ_CST,__TCC_WINNT_ATOMIC_SEQ_CST);
      __TCC_WINNT_MEMORY_BARRIER();
      أرجع Old;
    }

#تعریف_کړه Interlocked_Exchange_اشاره_ګر __TCC_WINNT_InterlockedExchangePointer
#تعریف_کړه Interlocked_Compare_Exchange_اشاره_ګر __TCC_WINNT_InterlockedCompareExchangePointer
#تعریف_کړه Interlocked_Compare_Exchange_اشاره_ګر_Acquire Interlocked_Compare_Exchange_اشاره_ګر
#تعریف_کړه Interlocked_Compare_Exchange_اشاره_ګر_Release Interlocked_Compare_Exchange_اشاره_ګر

#تعریف_کړه InterlockedCompareExchangeAcquire InterlockedCompareExchange
#تعریف_کړه InterlockedCompareExchangeRelease InterlockedCompareExchange

#تعریف_لغوه __TCC_WINNT_MEMORY_BARRIER
#تعریف_لغوه __TCC_WINNT_ATOMIC_SEQ_CST

#د_که_پای /* defined(__TINYC__) && (defined(__aarch64__) || defined(__arm64__)) && !defined(RC_INVOKED) */

#إذا defined(_ARM64_)

/* ARM64 Context Definition */
#تعریف_کړه CONTEXT_ARM64 0x00400000
#تعریف_کړه CONTEXT_CONTROL (CONTEXT_ARM64 | 0x00000001L)
#تعریف_کړه CONTEXT_INTEGER (CONTEXT_ARM64 | 0x00000002L)
#تعریف_کړه CONTEXT_FLOATING_ټکی (CONTEXT_ARM64 | 0x00000004L)
#تعریف_کړه CONTEXT_DEBUG (CONTEXT_ARM64 | 0x00000008L)
#تعریف_کړه CONTEXT_ډک (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_FLOATING_ټکی)
#تعریف_کړه CONTEXT_ALL (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_FLOATING_ټکی | CONTEXT_DEBUG)
#تعریف_کړه ARM64_MAX_BREAKPOINTS 8
#تعریف_کړه ARM64_MAX_WATCHPOINTS 2

  تعريفنوع اتحاد _ARM64_NT_NEON128 {
    بنية {
      ULONGLONG ټیټ_3;
      LONGLONG لوړ_3;
    } DUMMYSTRUCTNAME;
    مزدوج D[2];
    عائم S[4];
    کلمه_3 H[8];
    BYTE B[16];
  } ARM64_NT_NEON128,*PARM64_NT_NEON128;

  تعريفنوع بنية DECLSPEC_ALIGN(16) _ARM64_NT_CONTEXT {
    ULONG ContextFlags;
    ULONG Cpsr;
    اتحاد {
      بنية {
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

  C_ASSERT(حجم(ARM64_NT_CONTEXT) == 0x390);

  تعريفنوع ARM64_NT_CONTEXT CONTEXT,*PCONTEXT;

  تعريفنوع بنية _RUNTIME_FUNCTION {
    DWORD Begin_پته;
    DWORD Unwind_معلومات;
  } RUNTIME_FUNCTION,*PRUNTIME_FUNCTION;

  تعريفنوع PRUNTIME_FUNCTION (*PGET_RUNTIME_FUNCTION_CALLBACK)(DWORD64 ControlPc,PVOID Context);
  تعريفنوع DWORD (*POUT_د_PROCESS_FUNCTION_جدول_CALLBACK)(HANDLE Process,PVOID جدول_پته,PDWORD Entries,PRUNTIME_FUNCTION *Functions);

#د_که_پای /* _ARM64_ */

#إذا (defined _ARM64_ || defined _AMD64_) && !defined RC_INVOKED
  NTSYSAPI VOID __cdecl RtlRestoreContext (PCONTEXT Context_ریکارډ,بنية EXCEPTION_ریکارډ *Exception_ریکارډ);
  NTSYSAPI BOOLEAN __cdecl Rtl_جمع_کړه_Function_جدول(PRUNTIME_FUNCTION Function_جدول,DWORD ثبت_شمېر,DWORD64 بنسټ_پته);
  NTSYSAPI BOOLEAN __cdecl Rtl_Install_Function_جدول_Callback(DWORD64 جدول_Identifier,DWORD64 بنسټ_پته,DWORD اوږدتیا_2,PGET_RUNTIME_FUNCTION_CALLBACK Callback,PVOID Context,PCWSTR بهر_د_Process_Callback_Dll);
  NTSYSAPI BOOLEAN __cdecl Rtl_Delete_Function_جدول(PRUNTIME_FUNCTION Function_جدول);
#د_که_پای

#که_تعریف_شوی I_X86_
#إذا(defined(_X86_) && !defined(__x86_64)) && !defined(RC_INVOKED)
#که_تعریف_شوی __cplusplus
  خارجي "C" {
#د_که_پای

    __CRT_INLINE BOOLEAN Interlocked_بټ_Test_And_سېټ(LONG *بنسټ_2,LONG بټ_2) {
      صحيح old = 0;
      __asm__ __volatile__("lock ; btsl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متطاير اوږد *) بنسټ_2))
	:"Ir" (بټ_2));
      أرجع (BOOLEAN) (old!=0);
    }

    __CRT_INLINE BOOLEAN Interlocked_بټ_Test_And_Reset(LONG *بنسټ_2,LONG بټ_2) {
      صحيح old = 0;
      __asm__ __volatile__("lock ; btrl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متطاير اوږد *) بنسټ_2))
	:"Ir" (بټ_2));
      أرجع (BOOLEAN) (old!=0);
    }

    __CRT_INLINE BOOLEAN Interlocked_بټ_Test_And_Complement(LONG *بنسټ_2,LONG بټ_2) {
      صحيح old = 0;
      __asm__ __volatile__("lock ; btcl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متطاير اوږد *) بنسټ_2))
	:"Ir" (بټ_2));
      أرجع (BOOLEAN) (old!=0);
    }

#که_تعریف_شوی مختاړی_2
    BYTE __readfsbyte(DWORD دننه_واټن_3);
    کلمه_3 __readfsword(DWORD دننه_واټن_3);
    DWORD __readfsdword(DWORD دننه_واټن_3);
    VOID __writefsbyte(DWORD دننه_واټن_3,BYTE معلومات_3);
    VOID __writefsword(DWORD دننه_واټن_3,کلمه_3 معلومات_3);
    VOID __writefsdword(DWORD دننه_واټن_3,DWORD معلومات_3);
#د_که_پای

#که_تعریف_شوی __cplusplus
  }
#د_که_پای
#د_که_پای

#إذا(defined(_X86_) && !defined(__x86_64))
  __CRT_INLINE VOID حافظه_Barrier(VOID) {
    LONG Barrier;
    __asm__ __volatile__("xchgl %%eax,%0 "
      :"=r" (Barrier));
  }
#تعریف_کړه YieldProcessor() __asm__ __volatile__("rep nop ");

#تعریف_کړه Pre_Fetch_Cache_کرښه(l,a)
#تعریف_کړه ReadForWriteAccess(p) (*(p))

#تعریف_کړه PF_TEMPORAL_LEVEL_1
#تعریف_کړه PF_NON_TEMPORAL_LEVEL_ALL

  __CRT_INLINE VOID DbgRaiseAssertionFailure(فراغ) {
    __asm__ __volatile__("int $0x2c ");
  }
  PVOID GetCurrentFiber(فراغ);
  __CRT_INLINE PVOID GetCurrentFiber(فراغ)
  {
    فراغ *ret;
    __asm__ متطاير ("movl	%%fs:0x10,%0"
	: "=r" (ret));
    أرجع ret;
  }
  PVOID Get_Fiber_معلومات(فراغ);
  __CRT_INLINE PVOID Get_Fiber_معلومات(فراغ)
  {
    فراغ *ret;
    __asm__ متطاير ("movl	%%fs:0x10,%0\n"
	"movl	(%0),%0"
	: "=r" (ret));
    أرجع ret;
  }
#د_که_پای

#تعریف_کړه EXCEPTION_READ_FAULT 0
#تعریف_کړه EXCEPTION_WRITE_FAULT 1
#تعریف_کړه EXCEPTION_EXECUTE_FAULT 8

#تعریف_کړه اندازه_د_80387_REGISTERS 80

#إذا !defined(RC_INVOKED)

#تعریف_کړه CONTEXT_i386 0x00010000
#تعریف_کړه CONTEXT_i486 0x00010000

#تعریف_کړه CONTEXT_CONTROL (CONTEXT_i386 | 0x00000001L)
#تعریف_کړه CONTEXT_INTEGER (CONTEXT_i386 | 0x00000002L)
#تعریف_کړه CONTEXT_SEGMENTS (CONTEXT_i386 | 0x00000004L)
#تعریف_کړه CONTEXT_FLOATING_ټکی (CONTEXT_i386 | 0x00000008L)
#تعریف_کړه CONTEXT_DEBUG_REGISTERS (CONTEXT_i386 | 0x00000010L)
#تعریف_کړه CONTEXT_EXTENDED_REGISTERS (CONTEXT_i386 | 0x00000020L)

#تعریف_کړه CONTEXT_ډک (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_SEGMENTS)

#تعریف_کړه CONTEXT_ALL (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_SEGMENTS | CONTEXT_FLOATING_ټکی | CONTEXT_DEBUG_REGISTERS | CONTEXT_EXTENDED_REGISTERS)
#د_که_پای

#تعریف_کړه اعظمي_SUPPORTED_EXTENSION 512

    تعريفنوع بنية _FLOATING_SAVE_AREA {
      DWORD Control_کلمه;
      DWORD حالت_کلمه;
      DWORD نښان_کلمه;
      DWORD Error_دننه_واټن;
      DWORD ErrorSelector;
      DWORD معلومات_دننه_واټن_2;
      DWORD معلومات_Selector;
      BYTE ثبتوونکی_Area[اندازه_د_80387_REGISTERS];
      DWORD Cr0NpxState;
    } FLOATING_SAVE_AREA;

    تعريفنوع FLOATING_SAVE_AREA *PFLOATING_SAVE_AREA;

    تعريفنوع بنية _CONTEXT {
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
      BYTE ExtendedRegisters[اعظمي_SUPPORTED_EXTENSION];
    } CONTEXT;

    تعريفنوع CONTEXT *PCONTEXT;
#د_که_پای

#که_نه_تعریف_شوی LDT_ثبت_DEFINED
#تعریف_کړه LDT_ثبت_DEFINED

    تعريفنوع بنية LDT_ثبت {
      کلمه_3 حد_ټیټ;
      کلمه_3 بنسټ_ټیټ;
      اتحاد {
	بنية {
	  BYTE بنسټ_Mid;
	  BYTE Flags1;
	  BYTE Flags2;
	  BYTE بنسټ_Hi;
	} بایټونه_2;
	بنية {
	  DWORD بنسټ_Mid : 8;
	  DWORD Type : 5;
	  DWORD Dpl : 2;
	  DWORD Pres : 1;
	  DWORD حد_Hi : 4;
	  DWORD Sys : 1;
	  DWORD Reserved_0 : 1;
	  DWORD Default_Big : 1;
	  DWORD Granularity : 1;
	  DWORD بنسټ_Hi : 8;
	} بټونه_2;
      } لوړ_کلمه;
    } LDT_ثبت_2,*PLDT_ثبت;
#د_که_پای

#إذا defined(__ia64__) && !defined(RC_INVOKED)

#که_تعریف_شوی __cplusplus
    خارجي "C" {
#د_که_پای

      BOOLEAN بټ_لټون_Forward64(DWORD *شاخص_3,DWORD64 ماسک_3);
      BOOLEAN بټ_لټون_Reverse64(DWORD *شاخص_3,DWORD64 ماسک_3);

#که_تعریف_شوی __cplusplus
    }
#د_که_پای
#د_که_پای

#إذا !defined(GENUTIL) && !defined(_GENIA64_) && defined(_IA64_)

    فراغ *_cdecl _rdteb(فراغ);
#که_تعریف_شوی __ia64__

#تعریف_کړه NtCurrentTeb() ((بنية _TEB *)_rdteb())
#تعریف_کړه GetCurrentFiber() (((PNT_TIB)NtCurrentTeb())->Fiber_معلومات)
#تعریف_کړه Get_Fiber_معلومات() (*(PVOID *)(GetCurrentFiber()))

#که_تعریف_شوی __cplusplus
    خارجي "C" {
#د_که_پای

      فراغ __break(صحيح);
      فراغ __yield(فراغ);
      فراغ __mf(فراغ);
      فراغ __lfetch(صحيح Level,VOID CONST *پته_2);
      فراغ __lfetchfault(صحيح Level,VOID CONST *پته_2);
      فراغ __lfetch_excl(صحيح Level,VOID CONST *پته_2);
      فراغ __lfetchfault_excl(صحيح Level,VOID CONST *پته_2);

#تعریف_کړه MD_LFHINT_NONE 0x00
#تعریف_کړه MD_LFHINT_NT1 0x01
#تعریف_کړه MD_LFHINT_NT2 0x02
#تعریف_کړه MD_LFHINT_NTA 0x03

#که_تعریف_شوی __cplusplus
    }
#د_که_پای

#تعریف_کړه YieldProcessor __yield
#تعریف_کړه حافظه_Barrier __mf
#تعریف_کړه Pre_Fetch_Cache_کرښه __lfetch
#تعریف_کړه ReadForWriteAccess(p) (*(p))
#تعریف_کړه DbgRaiseAssertionFailure() __break(ASSERT_BREAKPOINT)

#تعریف_کړه PF_TEMPORAL_LEVEL_1 MD_LFHINT_NONE
#تعریف_کړه PF_NON_TEMPORAL_LEVEL_ALL MD_LFHINT_NTA

#تعریف_کړه Unsigned_Multiply_لوړ __UMULH

    ULONGLONG Unsigned_Multiply_لوړ(ULONGLONG Multiplier,ULONGLONG Multiplicand);
#وإلا
    بنية _TEB *NtCurrentTeb(فراغ);
#د_که_پای
#د_که_پای

#که_تعریف_شوی _IA64_

#تعریف_کړه EXCEPTION_READ_FAULT 0
#تعریف_کړه EXCEPTION_WRITE_FAULT 1
#تعریف_کړه EXCEPTION_EXECUTE_FAULT 2

#إذا !defined(RC_INVOKED)

#تعریف_کړه CONTEXT_IA64 0x00080000

#تعریف_کړه CONTEXT_CONTROL (CONTEXT_IA64 | 0x00000001L)
#تعریف_کړه CONTEXT_ښکتنی_FLOATING_ټکی (CONTEXT_IA64 | 0x00000002L)
#تعریف_کړه CONTEXT_HIGHER_FLOATING_ټکی (CONTEXT_IA64 | 0x00000004L)
#تعریف_کړه CONTEXT_INTEGER (CONTEXT_IA64 | 0x00000008L)
#تعریف_کړه CONTEXT_DEBUG (CONTEXT_IA64 | 0x00000010L)
#تعریف_کړه CONTEXT_IA32_CONTROL (CONTEXT_IA64 | 0x00000020L)

#تعریف_کړه CONTEXT_FLOATING_ټکی (CONTEXT_ښکتنی_FLOATING_ټکی | CONTEXT_HIGHER_FLOATING_ټکی)
#تعریف_کړه CONTEXT_ډک (CONTEXT_CONTROL | CONTEXT_FLOATING_ټکی | CONTEXT_INTEGER | CONTEXT_IA32_CONTROL)
#تعریف_کړه CONTEXT_ALL (CONTEXT_CONTROL | CONTEXT_FLOATING_ټکی | CONTEXT_INTEGER | CONTEXT_DEBUG | CONTEXT_IA32_CONTROL)

#تعریف_کړه CONTEXT_EXCEPTION_فعال 0x8000000
#تعریف_کړه CONTEXT_SERVICE_فعال 0x10000000
#تعریف_کړه CONTEXT_EXCEPTION_REQUEST 0x40000000
#تعریف_کړه CONTEXT_EXCEPTION_REPORTING 0x80000000
#د_که_پای

    تعريفنوع بنية _CONTEXT {
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

    تعريفنوع بنية _PLABEL_DESCRIPTOR {
      ULONGLONG ثبت_ټکی;
      ULONGLONG Global_اشاره_ګر_2;
    } PLABEL_DESCRIPTOR,*PPLABEL_DESCRIPTOR;

    تعريفنوع بنية _RUNTIME_FUNCTION {
      DWORD Begin_پته;
      DWORD پای_ټکی_پته;
      DWORD Unwind_Info_پته;
    } RUNTIME_FUNCTION,*PRUNTIME_FUNCTION;

    تعريفنوع PRUNTIME_FUNCTION (*PGET_RUNTIME_FUNCTION_CALLBACK)(DWORD64 ControlPc,PVOID Context);
    تعريفنوع DWORD (*POUT_د_PROCESS_FUNCTION_جدول_CALLBACK)(HANDLE Process,PVOID جدول_پته,PDWORD Entries,PRUNTIME_FUNCTION *Functions);

#تعریف_کړه بهر_د_PROCESS_FUNCTION_جدول_CALLBACK_EXPORT_NAME "OutOfProcessFunctionTableCallback"

    BOOLEAN Rtl_جمع_کړه_Function_جدول(PRUNTIME_FUNCTION Function_جدول,DWORD ثبت_شمېر,ULONGLONG بنسټ_پته,ULONGLONG موخه_Gp);
    BOOLEAN Rtl_Install_Function_جدول_Callback(DWORD64 جدول_Identifier,DWORD64 بنسټ_پته,DWORD اوږدتیا_2,DWORD64 موخه_Gp,PGET_RUNTIME_FUNCTION_CALLBACK Callback,PVOID Context,PCWSTR بهر_د_Process_Callback_Dll);
    BOOLEAN Rtl_Delete_Function_جدول(PRUNTIME_FUNCTION Function_جدول);
    VOID RtlRestoreContext (PCONTEXT Context_ریکارډ,بنية EXCEPTION_ریکارډ *Exception_ریکارډ);
    VOID __jump_unwind(ULONGLONG موخه_Ms_چوکاټ,ULONGLONG موخه_Bs_چوکاټ,ULONGLONG موخه_Pc);
#د_که_پای

#تعریف_کړه EXCEPTION_NONCONTINUABLE 0x1
#تعریف_کړه EXCEPTION_اعظمي_PARAMETERS 15

    تعريفنوع بنية EXCEPTION_ریکارډ {
      DWORD Exception_کوډ;
      DWORD ExceptionFlags;
      بنية EXCEPTION_ریکارډ *Exception_ریکارډ;
      PVOID Exception_پته;
      DWORD شمېره_Parameters;
      ULONG_PTR ExceptionInformation[EXCEPTION_اعظمي_PARAMETERS];
    } EXCEPTION_ریکارډ_2;

    تعريفنوع EXCEPTION_ریکارډ_2 *PEXCEPTION_ریکارډ;

    تعريفنوع بنية _EXCEPTION_RECORD32 {
      DWORD Exception_کوډ;
      DWORD ExceptionFlags;
      DWORD Exception_ریکارډ;
      DWORD Exception_پته;
      DWORD شمېره_Parameters;
      DWORD ExceptionInformation[EXCEPTION_اعظمي_PARAMETERS];
    } EXCEPTION_RECORD32,*PEXCEPTION_RECORD32;

    تعريفنوع بنية _EXCEPTION_RECORD64 {
      DWORD Exception_کوډ;
      DWORD ExceptionFlags;
      DWORD64 Exception_ریکارډ;
      DWORD64 Exception_پته;
      DWORD شمېره_Parameters;
      DWORD __unusedAlignment;
      DWORD64 ExceptionInformation[EXCEPTION_اعظمي_PARAMETERS];
    } EXCEPTION_RECORD64,*PEXCEPTION_RECORD64;

    تعريفنوع بنية EXCEPTION_اشارې_2 {
      PEXCEPTION_ریکارډ Exception_ریکارډ;
      PCONTEXT Context_ریکارډ;
    } EXCEPTION_اشارې,*PEXCEPTION_اشارې;

#که_تعریف_شوی __x86_64

    تعريفنوع EXCEPTION_DISPOSITION NTAPI EXCEPTION_ROUTINE (بنية EXCEPTION_ریکارډ *Exception_ریکارډ, PVOID Establisher_چوکاټ_2, بنية _CONTEXT *Context_ریکارډ, PVOID DispatcherContext);
#که_نه_تعریف_شوی __PEXCEPTION_ROUTINE_DEFINED
#تعریف_کړه __PEXCEPTION_ROUTINE_DEFINED
    تعريفنوع EXCEPTION_ROUTINE *PEXCEPTION_ROUTINE;
#د_که_پای

    /* http://msdn.microsoft.com/en-us/library/ms680597(VS.85).aspx */

#تعریف_کړه UNWIND_HISTORY_جدول_اندازه 12

  تعريفنوع بنية UNWIND_HISTORY_جدول_ثبت {
    ULONG64 Image_بنسټ;
    PRUNTIME_FUNCTION Function_ثبت;
  } UNWIND_HISTORY_جدول_ثبت_2, *PUNWIND_HISTORY_جدول_ثبت;

#تعریف_کړه UNWIND_HISTORY_جدول_NONE    0
#تعریف_کړه UNWIND_HISTORY_جدول_GLOBAL  1
#تعریف_کړه UNWIND_HISTORY_جدول_LOCAL   2

  تعريفنوع بنية UNWIND_HISTORY_جدول {
    ULONG شمېر_3;
    UCHAR پلټنه;
    ULONG64 ټیټ_پته;
    ULONG64 لوړ_پته;
    UNWIND_HISTORY_جدول_ثبت_2 ثبت[UNWIND_HISTORY_جدول_اندازه];
  } UNWIND_HISTORY_جدول_2, *PUNWIND_HISTORY_جدول;

  /* http://msdn.microsoft.com/en-us/library/b6sf5kbd(VS.80).aspx */

  بنية _DISPATCHER_CONTEXT;
  تعريفنوع بنية _DISPATCHER_CONTEXT DISPATCHER_CONTEXT;
  تعريفنوع بنية _DISPATCHER_CONTEXT *PDISPATCHER_CONTEXT;

  بنية _DISPATCHER_CONTEXT {
    ULONG64 ControlPc;
    ULONG64 Image_بنسټ;
    PRUNTIME_FUNCTION Function_ثبت;
    ULONG64 Establisher_چوکاټ_2;
    ULONG64 موخه_Ip;
    PCONTEXT Context_ریکارډ;
    PEXCEPTION_ROUTINE LanguageHandler;
    PVOID Handler_معلومات;
    /* http://www.nynaeve.net/?p=99 */
    PUNWIND_HISTORY_جدول History_جدول;
    ULONG Scope_شاخص;
    ULONG Fill0;
  };

  /* http://msdn.microsoft.com/en-us/library/ms680617(VS.85).aspx */

  تعريفنوع بنية KNONVOLATILE_CONTEXT_اشارې
  {
    PM128A FloatingContext[16];
    PULONG64 IntegerContext[16];
  } KNONVOLATILE_CONTEXT_اشارې_2, *PKNONVOLATILE_CONTEXT_اشارې;
#د_که_پای /* defined(__x86_64) */

    تعريفنوع PVOID PACCESS_TOKEN;
    تعريفنوع PVOID PSECURITY_DESCRIPTOR;
    تعريفنوع PVOID PSID;

    تعريفنوع DWORD ACCESS_ماسک;
    تعريفنوع ACCESS_ماسک *PACCESS_ماسک;

#تعریف_کړه DELETE (0x00010000L)
#تعریف_کړه READ_CONTROL (0x00020000L)
#تعریف_کړه WRITE_DAC (0x00040000L)
#تعریف_کړه WRITE_OWNER (0x00080000L)
#تعریف_کړه SYNCHRONIZE (0x00100000L)

#تعریف_کړه STANDARD_RIGHTS_REQUIRED (0x000F0000L)
#تعریف_کړه STANDARD_RIGHTS_READ (READ_CONTROL)
#تعریف_کړه STANDARD_RIGHTS_WRITE (READ_CONTROL)
#تعریف_کړه STANDARD_RIGHTS_EXECUTE (READ_CONTROL)
#تعریف_کړه STANDARD_RIGHTS_ALL (0x001F0000L)

#تعریف_کړه SPECIFIC_RIGHTS_ALL (0x0000FFFFL)

#تعریف_کړه ACCESS_SYSTEM_SECURITY (0x01000000L)

#تعریف_کړه اعظمي_ALLOWED (0x02000000L)

#تعریف_کړه GENERIC_READ (0x80000000L)
#تعریف_کړه GENERIC_WRITE (0x40000000L)
#تعریف_کړه GENERIC_EXECUTE (0x20000000L)
#تعریف_کړه GENERIC_ALL (0x10000000L)

    تعريفنوع بنية _GENERIC_MAPPING {
      ACCESS_ماسک GenericRead;
      ACCESS_ماسک GenericWrite;
      ACCESS_ماسک GenericExecute;
      ACCESS_ماسک GenericAll;
    } GENERIC_MAPPING;
    تعريفنوع GENERIC_MAPPING *PGENERIC_MAPPING;

#ضمن <pshpack4.h>

    تعريفنوع بنية LUID_AND_ځانګړتیاوې {
      LUID Luid;
      DWORD ځانګړتیاوې;
    } LUID_AND_ځانګړتیاوې_2,*PLUID_AND_ځانګړتیاوې;
    تعريفنوع LUID_AND_ځانګړتیاوې_2 LUID_AND_ځانګړتیاوې_ARRAY[ANYSIZE_ARRAY];
    تعريفنوع LUID_AND_ځانګړتیاوې_ARRAY *PLUID_AND_ځانګړتیاوې_ARRAY;

#ضمن <poppack.h>

#که_نه_تعریف_شوی SID_IDENTIFIER_AUTHORITY_DEFINED
#تعریف_کړه SID_IDENTIFIER_AUTHORITY_DEFINED
    تعريفنوع بنية _SID_IDENTIFIER_AUTHORITY {
      BYTE ارزښت_3[6];
    } SID_IDENTIFIER_AUTHORITY,*PSID_IDENTIFIER_AUTHORITY;
#د_که_پای

#که_نه_تعریف_شوی SID_DEFINED
#تعریف_کړه SID_DEFINED
    تعريفنوع بنية _SID {
      BYTE Revision;
      BYTE Sub_Authority_شمېر;
      SID_IDENTIFIER_AUTHORITY IdentifierAuthority;
      DWORD SubAuthority[ANYSIZE_ARRAY];
    } SID,*PISID;
#د_که_پای

#تعریف_کړه SID_REVISION (1)
#تعریف_کړه SID_MAX_SUB_AUTHORITIES (15)
#تعریف_کړه SID_RECOMMENDED_SUB_AUTHORITIES (1)

#تعریف_کړه SECURITY_MAX_SID_اندازه (حجم(SID) - حجم(DWORD) + (SID_MAX_SUB_AUTHORITIES *حجم(DWORD)))

    تعريفنوع تعداد _SID_NAME_USE {
      SidTypeUser = 1,Sid_Type_ډله,SidTypeDomain,SidTypeAlias,Sid_Type_Well_معلوم_ډله,SidTypeDeletedAccount,SidTypeInvalid,SidTypeUnknown,SidTypeComputer
    } SID_NAME_USE,*PSID_NAME_USE;

    تعريفنوع بنية SID_AND_ځانګړتیاوې {
      PSID Sid;
      DWORD ځانګړتیاوې;
    } SID_AND_ځانګړتیاوې_2,*PSID_AND_ځانګړتیاوې;

    تعريفنوع SID_AND_ځانګړتیاوې_2 SID_AND_ځانګړتیاوې_ARRAY[ANYSIZE_ARRAY];
    تعريفنوع SID_AND_ځانګړتیاوې_ARRAY *PSID_AND_ځانګړتیاوې_ARRAY;

#تعریف_کړه SECURITY_NULL_SID_AUTHORITY {0,0,0,0,0,0}
#تعریف_کړه SECURITY_WORLD_SID_AUTHORITY {0,0,0,0,0,1}
#تعریف_کړه SECURITY_LOCAL_SID_AUTHORITY {0,0,0,0,0,2}
#تعریف_کړه SECURITY_CREATOR_SID_AUTHORITY {0,0,0,0,0,3}
#تعریف_کړه SECURITY_NON_UNIQUE_AUTHORITY {0,0,0,0,0,4}
#تعریف_کړه SECURITY_RESOURCE_MANAGER_AUTHORITY {0,0,0,0,0,9}

#تعریف_کړه SECURITY_NULL_RID (0x00000000L)
#تعریف_کړه SECURITY_WORLD_RID (0x00000000L)
#تعریف_کړه SECURITY_LOCAL_RID (0x00000000L)

#تعریف_کړه SECURITY_CREATOR_OWNER_RID (0x00000000L)
#تعریف_کړه SECURITY_CREATOR_ډله_RID (0x00000001L)

#تعریف_کړه SECURITY_CREATOR_OWNER_SERVER_RID (0x00000002L)
#تعریف_کړه SECURITY_CREATOR_ډله_SERVER_RID (0x00000003L)

#تعریف_کړه SECURITY_NT_AUTHORITY {0,0,0,0,0,5}

#تعریف_کړه SECURITY_DIALUP_RID (0x00000001L)
#تعریف_کړه SECURITY_شبکه_RID (0x00000002L)
#تعریف_کړه SECURITY_BATCH_RID (0x00000003L)
#تعریف_کړه SECURITY_INTERACTIVE_RID (0x00000004L)
#تعریف_کړه SECURITY_LOGON_IDS_RID (0x00000005L)
#تعریف_کړه SECURITY_LOGON_IDS_RID_شمېر (3L)
#تعریف_کړه SECURITY_SERVICE_RID (0x00000006L)
#تعریف_کړه SECURITY_ANONYMOUS_LOGON_RID (0x00000007L)
#تعریف_کړه SECURITY_PROXY_RID (0x00000008L)
#تعریف_کړه SECURITY_ENTERPRISE_CONTROLLERS_RID (0x00000009L)
#تعریف_کړه SECURITY_SERVER_LOGON_RID SECURITY_ENTERPRISE_CONTROLLERS_RID
#تعریف_کړه SECURITY_PRINCIPAL_SELF_RID (0x0000000AL)
#تعریف_کړه SECURITY_AUTHENTICATED_USER_RID (0x0000000BL)
#تعریف_کړه SECURITY_RESTRICTED_کوډ_RID (0x0000000CL)
#تعریف_کړه SECURITY_TERMINAL_SERVER_RID (0x0000000DL)
#تعریف_کړه SECURITY_REMOTE_LOGON_RID (0x0000000EL)
#تعریف_کړه SECURITY_THIS_ORGANIZATION_RID (0x0000000FL)
#تعریف_کړه SECURITY_IUSER_RID (0x00000011L)

#تعریف_کړه SECURITY_LOCAL_SYSTEM_RID (0x00000012L)
#تعریف_کړه SECURITY_LOCAL_SERVICE_RID (0x00000013L)
#تعریف_کړه SECURITY_شبکه_SERVICE_RID (0x00000014L)

#تعریف_کړه SECURITY_NT_NON_UNIQUE (0x00000015L)
#تعریف_کړه SECURITY_NT_NON_UNIQUE_SUB_AUTH_شمېر (3L)

#تعریف_کړه SECURITY_ENTERPRISE_READONLY_CONTROLLERS_RID (0x00000016L)

#تعریف_کړه SECURITY_BUILTIN_DOMAIN_RID (0x00000020L)
#تعریف_کړه SECURITY_WRITE_RESTRICTED_کوډ_RID (0x00000021L)

#تعریف_کړه SECURITY_PACKAGE_بنسټ_RID (0x00000040L)
#تعریف_کړه SECURITY_PACKAGE_RID_شمېر (2L)
#تعریف_کړه SECURITY_PACKAGE_NTLM_RID (0x0000000AL)
#تعریف_کړه SECURITY_PACKAGE_SCHANNEL_RID (0x0000000EL)
#تعریف_کړه SECURITY_PACKAGE_DIGEST_RID (0x00000015L)

#تعریف_کړه SECURITY_SERVICE_ID_بنسټ_RID (0x00000050L)
#تعریف_کړه SECURITY_SERVICE_ID_RID_شمېر (6L)

#تعریف_کړه SECURITY_RESERVED_ID_بنسټ_RID (0x00000051L)

#تعریف_کړه SECURITY_MAX_ALWAYS_FILTERED (0x000003E7L)
#تعریف_کړه SECURITY_MIN_NEVER_FILTERED (0x000003E8L)

#تعریف_کړه SECURITY_OTHER_ORGANIZATION_RID (0x000003E8L)

#تعریف_کړه FOREST_USER_RID_MAX (0x000001F3L)

#تعریف_کړه DOMAIN_USER_RID_ADMIN (0x000001F4L)
#تعریف_کړه DOMAIN_USER_RID_GUEST (0x000001F5L)
#تعریف_کړه DOMAIN_USER_RID_KRBTGT (0x000001F6L)

#تعریف_کړه DOMAIN_USER_RID_MAX (0x000003E7L)

#تعریف_کړه DOMAIN_ډله_RID_ADMINS (0x00000200L)
#تعریف_کړه DOMAIN_ډله_RID_USERS (0x00000201L)
#تعریف_کړه DOMAIN_ډله_RID_GUESTS (0x00000202L)
#تعریف_کړه DOMAIN_ډله_RID_COMPUTERS (0x00000203L)
#تعریف_کړه DOMAIN_ډله_RID_CONTROLLERS (0x00000204L)
#تعریف_کړه DOMAIN_ډله_RID_CERT_ADMINS (0x00000205L)
#تعریف_کړه DOMAIN_ډله_RID_SCHEMA_ADMINS (0x00000206L)
#تعریف_کړه DOMAIN_ډله_RID_ENTERPRISE_ADMINS (0x00000207L)
#تعریف_کړه DOMAIN_ډله_RID_POLICY_ADMINS (0x00000208L)
#تعریف_کړه DOMAIN_ډله_RID_READONLY_CONTROLLERS (0x00000209L)

#تعریف_کړه DOMAIN_ALIAS_RID_ADMINS (0x00000220L)
#تعریف_کړه DOMAIN_ALIAS_RID_USERS (0x00000221L)
#تعریف_کړه DOMAIN_ALIAS_RID_GUESTS (0x00000222L)
#تعریف_کړه DOMAIN_ALIAS_RID_POWER_USERS (0x00000223L)

#تعریف_کړه DOMAIN_ALIAS_RID_ACCOUNT_OPS (0x00000224L)
#تعریف_کړه DOMAIN_ALIAS_RID_SYSTEM_OPS (0x00000225L)
#تعریف_کړه DOMAIN_ALIAS_RID_PRINT_OPS (0x00000226L)
#تعریف_کړه DOMAIN_ALIAS_RID_BACKUP_OPS (0x00000227L)

#تعریف_کړه DOMAIN_ALIAS_RID_REPLICATOR (0x00000228L)
#تعریف_کړه DOMAIN_ALIAS_RID_RAS_SERVERS (0x00000229L)
#تعریف_کړه DOMAIN_ALIAS_RID_PREW2KCOMPACCESS (0x0000022AL)
#تعریف_کړه DOMAIN_ALIAS_RID_REMOTE_DESKTOP_USERS (0x0000022BL)
#تعریف_کړه DOMAIN_ALIAS_RID_شبکه_CONFIGURATION_OPS (0x0000022CL)
#تعریف_کړه DOMAIN_ALIAS_RID_INCOMING_FOREST_TRUST_BUILDERS (0x0000022DL)

#تعریف_کړه DOMAIN_ALIAS_RID_MONITORING_USERS (0x0000022EL)
#تعریف_کړه DOMAIN_ALIAS_RID_LOGGING_USERS (0x0000022FL)
#تعریف_کړه DOMAIN_ALIAS_RID_AUTHORIZATIONACCESS (0x00000230L)
#تعریف_کړه DOMAIN_ALIAS_RID_TS_LICENSE_SERVERS (0x00000231L)
#تعریف_کړه DOMAIN_ALIAS_RID_DCOM_USERS (0x00000232L)

#تعریف_کړه DOMAIN_ALIAS_RID_IUSERS (0x00000238L)
#تعریف_کړه DOMAIN_ALIAS_RID_CRYPTO_OPERATORS (0x00000239L)
#تعریف_کړه DOMAIN_ALIAS_RID_CACHEABLE_PRINCIPALS_ډله (0x0000023BL)
#تعریف_کړه DOMAIN_ALIAS_RID_NON_CACHEABLE_PRINCIPALS_ډله (0x0000023CL)
#تعریف_کړه DOMAIN_ALIAS_RID_EVENT_LOG_READERS_ډله (0x0000023DL)

#تعریف_کړه SECURITY_MANDATORY_LABEL_AUTHORITY {0,0,0,0,0,16}
#تعریف_کړه SECURITY_MANDATORY_UNTRUSTED_RID (0x00000000L)
#تعریف_کړه SECURITY_MANDATORY_ټیټ_RID (0x00001000L)
#تعریف_کړه SECURITY_MANDATORY_MEDIUM_RID (0x00002000L)
#تعریف_کړه SECURITY_MANDATORY_لوړ_RID (0x00003000L)
#تعریف_کړه SECURITY_MANDATORY_SYSTEM_RID (0x00004000L)
#تعریف_کړه SECURITY_MANDATORY_PROTECTED_PROCESS_RID (0x00005000L)

#تعریف_کړه SECURITY_MANDATORY_اعظمي_USER_RID SECURITY_MANDATORY_SYSTEM_RID

#تعریف_کړه MANDATORY_LEVEL_منزل_MANDATORY_RID(IL) (IL * 0x1000)

    تعريفنوع تعداد {
      WinNullSid = 0,WinWorldSid = 1,WinLocalSid = 2,WinCreatorOwnerSid = 3,Win_Creator_ډله_Sid = 4,WinCreatorOwnerServerSid = 5,Win_Creator_ډله_Server_Sid = 6,WinNtAuthoritySid = 7,WinDialupSid = 8,Win_شبکه_Sid = 9,WinBatchSid = 10,WinInteractiveSid = 11,WinServiceSid = 12,WinAnonymousSid = 13,WinProxySid = 14,WinEnterpriseControllersSid = 15,WinSelfSid = 16,WinAuthenticatedUserSid = 17,Win_Restricted_کوډ_Sid = 18,WinTerminalServerSid = 19,WinRemoteLogonIdSid = 20,WinLogonIdsSid = 21,WinLocalSystemSid = 22,WinLocalServiceSid = 23,Win_شبکه_Service_Sid = 24,WinBuiltinDomainSid = 25,WinBuiltinAdministratorsSid = 26,WinBuiltinUsersSid = 27,WinBuiltinGuestsSid = 28,WinBuiltinPowerUsersSid = 29,WinBuiltinAccountOperatorsSid = 30,WinBuiltinSystemOperatorsSid = 31,WinBuiltinPrintOperatorsSid = 32,WinBuiltinBackupOperatorsSid = 33,WinBuiltinReplicatorSid = 34,WinBuiltinPreWindows2000CompatibleAccessSid = 35,WinBuiltinRemoteDesktopUsersSid = 36,Win_Builtin_شبکه_Configuration_Operators_Sid = 37,WinAccountAdministratorSid = 38,WinAccountGuestSid = 39,WinAccountKrbtgtSid = 40,WinAccountDomainAdminsSid = 41,WinAccountDomainUsersSid = 42,WinAccountDomainGuestsSid = 43,WinAccountComputersSid = 44,WinAccountControllersSid = 45,WinAccountCertAdminsSid = 46,WinAccountSchemaAdminsSid = 47,WinAccountEnterpriseAdminsSid = 48,WinAccountPolicyAdminsSid = 49,WinAccountRasAndIasServersSid = 50,WinNTLMAuthenticationSid = 51,WinDigestAuthenticationSid = 52,WinSChannelAuthenticationSid = 53,WinThisOrganizationSid = 54,WinOtherOrganizationSid = 55,WinBuiltinIncomingForestTrustBuildersSid = 56,WinBuiltinPerfMonitoringUsersSid = 57,WinBuiltinPerfLoggingUsersSid = 58,WinBuiltinAuthorizationAccessSid = 59,WinBuiltinTerminalServerLicenseServersSid = 60,WinBuiltinDCOMUsersSid = 61
    } WELL_معلوم_SID_TYPE;

#تعریف_کړه SYSTEM_LUID { 0x3E7,0x0 }
#تعریف_کړه ANONYMOUS_LOGON_LUID { 0x3e6,0x0 }
#تعریف_کړه LOCALSERVICE_LUID { 0x3e5,0x0 }
#تعریف_کړه NETWORKSERVICE_LUID { 0x3e4,0x0 }
#تعریف_کړه IUSER_LUID { 0x3e3, 0x0 }

#تعریف_کړه SE_ډله_MANDATORY (0x00000001L)
#تعریف_کړه SE_ډله_ENABLED_BY_DEFAULT (0x00000002L)
#تعریف_کړه SE_ډله_ENABLED (0x00000004L)
#تعریف_کړه SE_ډله_OWNER (0x00000008L)
#تعریف_کړه SE_ډله_USE_FOR_DENY_ONLY (0x00000010L)
#تعریف_کړه SE_ډله_INTEGRITY (0x00000020L)
#تعریف_کړه SE_ډله_INTEGRITY_ENABLED (0x00000040L)
#تعریف_کړه SE_ډله_LOGON_ID (0xC0000000L)
#تعریف_کړه SE_ډله_RESOURCE (0x20000000L)

#تعریف_کړه ACL_REVISION (2)
#تعریف_کړه ACL_REVISION_DS (4)

#تعریف_کړه ACL_REVISION1 (1)
#تعریف_کړه MIN_ACL_REVISION ACL_REVISION2
#تعریف_کړه ACL_REVISION2 (2)
#تعریف_کړه ACL_REVISION3 (3)
#تعریف_کړه ACL_REVISION4 (4)
#تعریف_کړه MAX_ACL_REVISION ACL_REVISION4

    تعريفنوع بنية _ACL {
      BYTE AclRevision;
      BYTE Sbz1;
      کلمه_3 Acl_اندازه;
      کلمه_3 Ace_شمېر;
      کلمه_3 Sbz2;
    } ACL;
    تعريفنوع ACL *PACL;

    تعريفنوع بنية ACE_سرلیک {
      BYTE AceType;
      BYTE AceFlags;
      کلمه_3 Ace_اندازه;
    } ACE_سرلیک_2;
    تعريفنوع ACE_سرلیک_2 *PACE_سرلیک;

#تعریف_کړه ACCESS_MIN_MS_ACE_TYPE (0x0)
#تعریف_کړه ACCESS_ALLOWED_ACE_TYPE (0x0)
#تعریف_کړه ACCESS_DENIED_ACE_TYPE (0x1)
#تعریف_کړه SYSTEM_AUDIT_ACE_TYPE (0x2)
#تعریف_کړه SYSTEM_ALARM_ACE_TYPE (0x3)
#تعریف_کړه ACCESS_MAX_MS_V2_ACE_TYPE (0x3)

#تعریف_کړه ACCESS_ALLOWED_COMPOUND_ACE_TYPE (0x4)
#تعریف_کړه ACCESS_MAX_MS_V3_ACE_TYPE (0x4)

#تعریف_کړه ACCESS_MIN_MS_OBJECT_ACE_TYPE (0x5)
#تعریف_کړه ACCESS_ALLOWED_OBJECT_ACE_TYPE (0x5)
#تعریف_کړه ACCESS_DENIED_OBJECT_ACE_TYPE (0x6)
#تعریف_کړه SYSTEM_AUDIT_OBJECT_ACE_TYPE (0x7)
#تعریف_کړه SYSTEM_ALARM_OBJECT_ACE_TYPE (0x8)
#تعریف_کړه ACCESS_MAX_MS_OBJECT_ACE_TYPE (0x8)

#تعریف_کړه ACCESS_MAX_MS_V4_ACE_TYPE (0x8)
#تعریف_کړه ACCESS_MAX_MS_ACE_TYPE (0x8)

#تعریف_کړه ACCESS_ALLOWED_CALLBACK_ACE_TYPE (0x9)
#تعریف_کړه ACCESS_DENIED_CALLBACK_ACE_TYPE (0xA)
#تعریف_کړه ACCESS_ALLOWED_CALLBACK_OBJECT_ACE_TYPE (0xB)
#تعریف_کړه ACCESS_DENIED_CALLBACK_OBJECT_ACE_TYPE (0xC)
#تعریف_کړه SYSTEM_AUDIT_CALLBACK_ACE_TYPE (0xD)
#تعریف_کړه SYSTEM_ALARM_CALLBACK_ACE_TYPE (0xE)
#تعریف_کړه SYSTEM_AUDIT_CALLBACK_OBJECT_ACE_TYPE (0xF)
#تعریف_کړه SYSTEM_ALARM_CALLBACK_OBJECT_ACE_TYPE (0x10)

#تعریف_کړه SYSTEM_MANDATORY_LABEL_ACE_TYPE (0x11)
#تعریف_کړه ACCESS_MAX_MS_V5_ACE_TYPE (0x11)

#تعریف_کړه OBJECT_INHERIT_ACE (0x1)
#تعریف_کړه CONTAINER_INHERIT_ACE (0x2)
#تعریف_کړه NO_PROPAGATE_INHERIT_ACE (0x4)
#تعریف_کړه INHERIT_ONLY_ACE (0x8)
#تعریف_کړه INHERITED_ACE (0x10)
#تعریف_کړه VALID_INHERIT_FLAGS (0x1F)

#تعریف_کړه SUCCESSFUL_ACCESS_ACE_FLAG (0x40)
#تعریف_کړه FAILED_ACCESS_ACE_FLAG (0x80)

    تعريفنوع بنية _ACCESS_ALLOWED_ACE {
      ACE_سرلیک_2 سرلیک_2;
      ACCESS_ماسک ماسک_3;
      DWORD Sid_پیل;
    } ACCESS_ALLOWED_ACE;

    تعريفنوع ACCESS_ALLOWED_ACE *PACCESS_ALLOWED_ACE;

    تعريفنوع بنية _ACCESS_DENIED_ACE {
      ACE_سرلیک_2 سرلیک_2;
      ACCESS_ماسک ماسک_3;
      DWORD Sid_پیل;
    } ACCESS_DENIED_ACE;
    تعريفنوع ACCESS_DENIED_ACE *PACCESS_DENIED_ACE;

    تعريفنوع بنية _SYSTEM_AUDIT_ACE {
      ACE_سرلیک_2 سرلیک_2;
      ACCESS_ماسک ماسک_3;
      DWORD Sid_پیل;
    } SYSTEM_AUDIT_ACE;
    تعريفنوع SYSTEM_AUDIT_ACE *PSYSTEM_AUDIT_ACE;

    تعريفنوع بنية _SYSTEM_ALARM_ACE {
      ACE_سرلیک_2 سرلیک_2;
      ACCESS_ماسک ماسک_3;
      DWORD Sid_پیل;
    } SYSTEM_ALARM_ACE;
    تعريفنوع SYSTEM_ALARM_ACE *PSYSTEM_ALARM_ACE;

    تعريفنوع بنية _ACCESS_ALLOWED_OBJECT_ACE {
      ACE_سرلیک_2 سرلیک_2;
      ACCESS_ماسک ماسک_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_پیل;
    } ACCESS_ALLOWED_OBJECT_ACE,*PACCESS_ALLOWED_OBJECT_ACE;

    تعريفنوع بنية _ACCESS_DENIED_OBJECT_ACE {
      ACE_سرلیک_2 سرلیک_2;
      ACCESS_ماسک ماسک_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_پیل;
    } ACCESS_DENIED_OBJECT_ACE,*PACCESS_DENIED_OBJECT_ACE;

    تعريفنوع بنية _SYSTEM_AUDIT_OBJECT_ACE {
      ACE_سرلیک_2 سرلیک_2;
      ACCESS_ماسک ماسک_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_پیل;
    } SYSTEM_AUDIT_OBJECT_ACE,*PSYSTEM_AUDIT_OBJECT_ACE;

    تعريفنوع بنية _SYSTEM_ALARM_OBJECT_ACE {
      ACE_سرلیک_2 سرلیک_2;
      ACCESS_ماسک ماسک_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_پیل;
    } SYSTEM_ALARM_OBJECT_ACE,*PSYSTEM_ALARM_OBJECT_ACE;

    تعريفنوع بنية _ACCESS_ALLOWED_CALLBACK_ACE {
      ACE_سرلیک_2 سرلیک_2;
      ACCESS_ماسک ماسک_3;
      DWORD Sid_پیل;

    } ACCESS_ALLOWED_CALLBACK_ACE,*PACCESS_ALLOWED_CALLBACK_ACE;

    تعريفنوع بنية _ACCESS_DENIED_CALLBACK_ACE {
      ACE_سرلیک_2 سرلیک_2;
      ACCESS_ماسک ماسک_3;
      DWORD Sid_پیل;

    } ACCESS_DENIED_CALLBACK_ACE,*PACCESS_DENIED_CALLBACK_ACE;

    تعريفنوع بنية _SYSTEM_AUDIT_CALLBACK_ACE {
      ACE_سرلیک_2 سرلیک_2;
      ACCESS_ماسک ماسک_3;
      DWORD Sid_پیل;

    } SYSTEM_AUDIT_CALLBACK_ACE,*PSYSTEM_AUDIT_CALLBACK_ACE;

    تعريفنوع بنية _SYSTEM_ALARM_CALLBACK_ACE {
      ACE_سرلیک_2 سرلیک_2;
      ACCESS_ماسک ماسک_3;
      DWORD Sid_پیل;

    } SYSTEM_ALARM_CALLBACK_ACE,*PSYSTEM_ALARM_CALLBACK_ACE;

    تعريفنوع بنية _ACCESS_ALLOWED_CALLBACK_OBJECT_ACE {
      ACE_سرلیک_2 سرلیک_2;
      ACCESS_ماسک ماسک_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_پیل;

    } ACCESS_ALLOWED_CALLBACK_OBJECT_ACE,*PACCESS_ALLOWED_CALLBACK_OBJECT_ACE;

    تعريفنوع بنية _ACCESS_DENIED_CALLBACK_OBJECT_ACE {
      ACE_سرلیک_2 سرلیک_2;
      ACCESS_ماسک ماسک_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_پیل;

    } ACCESS_DENIED_CALLBACK_OBJECT_ACE,*PACCESS_DENIED_CALLBACK_OBJECT_ACE;

    تعريفنوع بنية _SYSTEM_AUDIT_CALLBACK_OBJECT_ACE {
      ACE_سرلیک_2 سرلیک_2;
      ACCESS_ماسک ماسک_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_پیل;

    } SYSTEM_AUDIT_CALLBACK_OBJECT_ACE,*PSYSTEM_AUDIT_CALLBACK_OBJECT_ACE;

    تعريفنوع بنية _SYSTEM_ALARM_CALLBACK_OBJECT_ACE {
      ACE_سرلیک_2 سرلیک_2;
      ACCESS_ماسک ماسک_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_پیل;

    } SYSTEM_ALARM_CALLBACK_OBJECT_ACE,*PSYSTEM_ALARM_CALLBACK_OBJECT_ACE;

#تعریف_کړه ACE_OBJECT_TYPE_PRESENT 0x1
#تعریف_کړه ACE_INHERITED_OBJECT_TYPE_PRESENT 0x2

    تعريفنوع تعداد _ACL_INFORMATION_CLASS {
      AclRevisionInformation = 1,Acl_اندازه_Information
    } ACL_INFORMATION_CLASS;

    تعريفنوع بنية _ACL_REVISION_INFORMATION {
      DWORD AclRevision;
    } ACL_REVISION_INFORMATION;
    تعريفنوع ACL_REVISION_INFORMATION *PACL_REVISION_INFORMATION;

    تعريفنوع بنية ACL_اندازه_INFORMATION {
      DWORD Ace_شمېر;
      DWORD Acl_بایټونه_دننه_Use;
      DWORD Acl_بایټونه_Free;
    } ACL_اندازه_INFORMATION_2;
    تعريفنوع ACL_اندازه_INFORMATION_2 *PACL_اندازه_INFORMATION;

#تعریف_کړه SECURITY_DESCRIPTOR_REVISION (1)
#تعریف_کړه SECURITY_DESCRIPTOR_REVISION1 (1)

#تعریف_کړه SECURITY_DESCRIPTOR_MIN_اوږدتیا (حجم(SECURITY_DESCRIPTOR))

    تعريفنوع کلمه_3 SECURITY_DESCRIPTOR_CONTROL,*PSECURITY_DESCRIPTOR_CONTROL;

#تعریف_کړه SE_OWNER_DEFAULTED (0x0001)
#تعریف_کړه SE_ډله_DEFAULTED (0x0002)
#تعریف_کړه SE_DACL_PRESENT (0x0004)
#تعریف_کړه SE_DACL_DEFAULTED (0x0008)
#تعریف_کړه SE_SACL_PRESENT (0x0010)
#تعریف_کړه SE_SACL_DEFAULTED (0x0020)
#تعریف_کړه SE_DACL_AUTO_INHERIT_REQ (0x0100)
#تعریف_کړه SE_SACL_AUTO_INHERIT_REQ (0x0200)
#تعریف_کړه SE_DACL_AUTO_INHERITED (0x0400)
#تعریف_کړه SE_SACL_AUTO_INHERITED (0x0800)
#تعریف_کړه SE_DACL_PROTECTED (0x1000)
#تعریف_کړه SE_SACL_PROTECTED (0x2000)
#تعریف_کړه SE_RM_CONTROL_VALID (0x4000)
#تعریف_کړه SE_SELF_RELATIVE (0x8000)

    تعريفنوع بنية _SECURITY_DESCRIPTOR_RELATIVE {
      BYTE Revision;
      BYTE Sbz1;
      SECURITY_DESCRIPTOR_CONTROL Control;
      DWORD Owner;
      DWORD ډله_2;
      DWORD Sacl;
      DWORD Dacl;
    } SECURITY_DESCRIPTOR_RELATIVE,*PISECURITY_DESCRIPTOR_RELATIVE;

    تعريفنوع بنية _SECURITY_DESCRIPTOR {
      BYTE Revision;
      BYTE Sbz1;
      SECURITY_DESCRIPTOR_CONTROL Control;
      PSID Owner;
      PSID ډله_2;
      PACL Sacl;
      PACL Dacl;

    } SECURITY_DESCRIPTOR,*PISECURITY_DESCRIPTOR;

    تعريفنوع بنية _OBJECT_TYPE_LIST {
      کلمه_3 Level;
      کلمه_3 Sbz;
      GUID *ObjectType;
    } OBJECT_TYPE_LIST,*POBJECT_TYPE_LIST;

#تعریف_کړه ACCESS_OBJECT_GUID 0
#تعریف_کړه ACCESS_PROPERTY_سېټ_GUID 1
#تعریف_کړه ACCESS_PROPERTY_GUID 2

#تعریف_کړه ACCESS_MAX_LEVEL 4

    تعريفنوع تعداد _AUDIT_EVENT_TYPE {
      AuditEventObjectAccess,AuditEventDirectoryServiceAccess
    } AUDIT_EVENT_TYPE,*PAUDIT_EVENT_TYPE;

#تعریف_کړه AUDIT_ALLOW_NO_PRIVILEGE 0x1

#تعریف_کړه ACCESS_DS_سرچینه_A "DS"
#تعریف_کړه ACCESS_DS_سرچینه_W L"DS"
#تعریف_کړه ACCESS_DS_OBJECT_TYPE_NAME_A "Directory Service Object"
#تعریف_کړه ACCESS_DS_OBJECT_TYPE_NAME_W L"Directory Service Object"

#تعریف_کړه SE_PRIVILEGE_ENABLED_BY_DEFAULT (0x00000001L)
#تعریف_کړه SE_PRIVILEGE_ENABLED (0x00000002L)
#تعریف_کړه SE_PRIVILEGE_REMOVED (0X00000004L)
#تعریف_کړه SE_PRIVILEGE_کارول_شوی_FOR_ACCESS (0x80000000L)

#تعریف_کړه PRIVILEGE_سېټ_ALL_NECESSARY (1)

    تعريفنوع بنية PRIVILEGE_سېټ {
      DWORD Privilege_شمېر;
      DWORD Control;
      LUID_AND_ځانګړتیاوې_2 Privilege[ANYSIZE_ARRAY];
    } PRIVILEGE_سېټ_2,*PPRIVILEGE_سېټ;

#تعریف_کړه SE_CREATE_TOKEN_NAME متن_3("SeCreateTokenPrivilege")
#تعریف_کړه SE_ASSIGNPRIMARYTOKEN_NAME متن_3("SeAssignPrimaryTokenPrivilege")
#تعریف_کړه SE_قلف_حافظه_NAME متن_3("SeLockMemoryPrivilege")
#تعریف_کړه SE_INCREASE_QUOTA_NAME متن_3("SeIncreaseQuotaPrivilege")
#تعریف_کړه SE_UNSOLICITED_ننوت_NAME متن_3("SeUnsolicitedInputPrivilege")
#تعریف_کړه SE_MACHINE_ACCOUNT_NAME متن_3("SeMachineAccountPrivilege")
#تعریف_کړه SE_TCB_NAME متن_3("SeTcbPrivilege")
#تعریف_کړه SE_SECURITY_NAME متن_3("SeSecurityPrivilege")
#تعریف_کړه SE_TAKE_OWNERSHIP_NAME متن_3("SeTakeOwnershipPrivilege")
#تعریف_کړه SE_بارول_DRIVER_NAME متن_3("SeLoadDriverPrivilege")
#تعریف_کړه SE_SYSTEM_PROFILE_NAME متن_3("SeSystemProfilePrivilege")
#تعریف_کړه SE_SYSTEMTIME_NAME متن_3("SeSystemtimePrivilege")
#تعریف_کړه SE_PROF_SINGLE_PROCESS_NAME متن_3("SeProfileSingleProcessPrivilege")
#تعریف_کړه SE_INC_بنسټ_لومړیتوب_NAME متن_3("SeIncreaseBasePriorityPrivilege")
#تعریف_کړه SE_CREATE_PAGEFILE_NAME متن_3("SeCreatePagefilePrivilege")
#تعریف_کړه SE_CREATE_PERMANENT_NAME متن_3("SeCreatePermanentPrivilege")
#تعریف_کړه SE_BACKUP_NAME متن_3("SeBackupPrivilege")
#تعریف_کړه SE_RESTORE_NAME متن_3("SeRestorePrivilege")
#تعریف_کړه SE_SHUTDOWN_NAME متن_3("SeShutdownPrivilege")
#تعریف_کړه SE_DEBUG_NAME متن_3("SeDebugPrivilege")
#تعریف_کړه SE_AUDIT_NAME متن_3("SeAuditPrivilege")
#تعریف_کړه SE_SYSTEM_ENVIRONMENT_NAME متن_3("SeSystemEnvironmentPrivilege")
#تعریف_کړه SE_CHANGE_NOTIFY_NAME متن_3("SeChangeNotifyPrivilege")
#تعریف_کړه SE_REMOTE_SHUTDOWN_NAME متن_3("SeRemoteShutdownPrivilege")
#تعریف_کړه SE_UNDOCK_NAME متن_3("SeUndockPrivilege")
#تعریف_کړه SE_SYNC_AGENT_NAME متن_3("SeSyncAgentPrivilege")
#تعریف_کړه SE_ENABLE_DELEGATION_NAME متن_3("SeEnableDelegationPrivilege")
#تعریف_کړه SE_MANAGE_VOLUME_NAME متن_3("SeManageVolumePrivilege")
#تعریف_کړه SE_IMPERSONATE_NAME متن_3("SeImpersonatePrivilege")
#تعریف_کړه SE_CREATE_GLOBAL_NAME متن_3("SeCreateGlobalPrivilege")

    تعريفنوع تعداد _SECURITY_IMPERSONATION_LEVEL {
      SecurityAnonymous,SecurityIdentification,SecurityImpersonation,SecurityDelegation
    } SECURITY_IMPERSONATION_LEVEL,*PSECURITY_IMPERSONATION_LEVEL;

#تعریف_کړه SECURITY_MAX_IMPERSONATION_LEVEL SecurityDelegation
#تعریف_کړه SECURITY_MIN_IMPERSONATION_LEVEL SecurityAnonymous
#تعریف_کړه DEFAULT_IMPERSONATION_LEVEL SecurityImpersonation
#تعریف_کړه VALID_IMPERSONATION_LEVEL(L) (((L) >= SECURITY_MIN_IMPERSONATION_LEVEL) && ((L) <= SECURITY_MAX_IMPERSONATION_LEVEL))

#تعریف_کړه TOKEN_ټاکل_PRIMARY (0x0001)
#تعریف_کړه TOKEN_DUPLICATE (0x0002)
#تعریف_کړه TOKEN_IMPERSONATE (0x0004)
#تعریف_کړه TOKEN_QUERY (0x0008)
#تعریف_کړه TOKEN_QUERY_سرچینه (0x0010)
#تعریف_کړه TOKEN_ADJUST_PRIVILEGES (0x0020)
#تعریف_کړه TOKEN_ADJUST_GROUPS (0x0040)
#تعریف_کړه TOKEN_ADJUST_DEFAULT (0x0080)
#تعریف_کړه TOKEN_ADJUST_SESSIONID (0x0100)

#تعریف_کړه TOKEN_ALL_ACCESS_P (STANDARD_RIGHTS_REQUIRED | TOKEN_ټاکل_PRIMARY | TOKEN_DUPLICATE | TOKEN_IMPERSONATE | TOKEN_QUERY | TOKEN_QUERY_سرچینه | TOKEN_ADJUST_PRIVILEGES | TOKEN_ADJUST_GROUPS | TOKEN_ADJUST_DEFAULT)
#تعریف_کړه TOKEN_ALL_ACCESS (TOKEN_ALL_ACCESS_P | TOKEN_ADJUST_SESSIONID)
#تعریف_کړه TOKEN_READ (STANDARD_RIGHTS_READ | TOKEN_QUERY)

#تعریف_کړه TOKEN_WRITE (STANDARD_RIGHTS_WRITE | TOKEN_ADJUST_PRIVILEGES | TOKEN_ADJUST_GROUPS | TOKEN_ADJUST_DEFAULT)

#تعریف_کړه TOKEN_EXECUTE (STANDARD_RIGHTS_EXECUTE)

    تعريفنوع تعداد _TOKEN_TYPE {
      TokenPrimary = 1,TokenImpersonation
    } TOKEN_TYPE;
    تعريفنوع TOKEN_TYPE *PTOKEN_TYPE;

    تعريفنوع تعداد _TOKEN_INFORMATION_CLASS {
      TokenUser = 1,TokenGroups,TokenPrivileges,TokenOwner,Token_Primary_ډله,TokenDefaultDacl,Token_سرچینه,TokenType,TokenImpersonationLevel,
      TokenStatistics,TokenRestrictedSids,TokenSessionId,TokenGroupsAndPrivileges,TokenSessionReference,TokenSandBoxInert,TokenAuditPolicy,
      TokenOrigin,MaxTokenInfoClass
    } TOKEN_INFORMATION_CLASS,*PTOKEN_INFORMATION_CLASS;

    تعريفنوع بنية _TOKEN_USER {
      SID_AND_ځانګړتیاوې_2 User;
    } TOKEN_USER,*PTOKEN_USER;

    تعريفنوع بنية _TOKEN_GROUPS {
      DWORD ډله_شمېر;
      SID_AND_ځانګړتیاوې_2 Groups[ANYSIZE_ARRAY];
    } TOKEN_GROUPS,*PTOKEN_GROUPS;

    تعريفنوع بنية _TOKEN_PRIVILEGES {
      DWORD Privilege_شمېر;
      LUID_AND_ځانګړتیاوې_2 Privileges[ANYSIZE_ARRAY];
    } TOKEN_PRIVILEGES,*PTOKEN_PRIVILEGES;

    تعريفنوع بنية _TOKEN_OWNER {
      PSID Owner;
    } TOKEN_OWNER,*PTOKEN_OWNER;

    تعريفنوع بنية TOKEN_PRIMARY_ډله {
      PSID Primary_ډله;
    } TOKEN_PRIMARY_ډله_2,*PTOKEN_PRIMARY_ډله;

    تعريفنوع بنية _TOKEN_DEFAULT_DACL {
      PACL DefaultDacl;
    } TOKEN_DEFAULT_DACL,*PTOKEN_DEFAULT_DACL;

    تعريفنوع بنية _TOKEN_GROUPS_AND_PRIVILEGES {
      DWORD Sid_شمېر;
      DWORD Sid_اوږدتیا;
      PSID_AND_ځانګړتیاوې Sids;
      DWORD Restricted_Sid_شمېر;
      DWORD Restricted_Sid_اوږدتیا;
      PSID_AND_ځانګړتیاوې RestrictedSids;
      DWORD Privilege_شمېر;
      DWORD Privilege_اوږدتیا;
      PLUID_AND_ځانګړتیاوې Privileges;
      LUID AuthenticationId;
    } TOKEN_GROUPS_AND_PRIVILEGES,*PTOKEN_GROUPS_AND_PRIVILEGES;

#تعریف_کړه TOKEN_AUDIT_SUCCESS_INCLUDE 0x1
#تعریف_کړه TOKEN_AUDIT_SUCCESS_EXCLUDE 0x2
#تعریف_کړه TOKEN_AUDIT_FAILURE_INCLUDE 0x4
#تعریف_کړه TOKEN_AUDIT_FAILURE_EXCLUDE 0x8

#تعریف_کړه VALID_AUDIT_POLICY_بټونه (TOKEN_AUDIT_SUCCESS_INCLUDE | TOKEN_AUDIT_SUCCESS_EXCLUDE | TOKEN_AUDIT_FAILURE_INCLUDE | TOKEN_AUDIT_FAILURE_EXCLUDE)
#تعریف_کړه VALID_TOKEN_AUDIT_POLICY_ELEMENT(P) ((((P).Policy_ماسک & ~VALID_AUDIT_POLICY_بټونه)==0) && ((P).Category <= AuditEventMaxType))

    تعريفنوع بنية _TOKEN_AUDIT_POLICY_ELEMENT {
      DWORD Category;
      DWORD Policy_ماسک;
    } TOKEN_AUDIT_POLICY_ELEMENT,*PTOKEN_AUDIT_POLICY_ELEMENT;

    تعريفنوع بنية _TOKEN_AUDIT_POLICY {
      DWORD Policy_شمېر;
      TOKEN_AUDIT_POLICY_ELEMENT Policy[ANYSIZE_ARRAY];
    } TOKEN_AUDIT_POLICY,*PTOKEN_AUDIT_POLICY;

#تعریف_کړه فی_USER_AUDITING_POLICY_اندازه(p) (حجم(TOKEN_AUDIT_POLICY) + (((p)->Policy_شمېر > ANYSIZE_ARRAY) ? (حجم(TOKEN_AUDIT_POLICY_ELEMENT) *((p)->Policy_شمېر - ANYSIZE_ARRAY)) : 0))
#تعریف_کړه فی_USER_AUDITING_POLICY_اندازه_BY_شمېر(C) (حجم(TOKEN_AUDIT_POLICY) + (((C) > ANYSIZE_ARRAY) ? (حجم(TOKEN_AUDIT_POLICY_ELEMENT) *((C) - ANYSIZE_ARRAY)) : 0))

#تعریف_کړه TOKEN_سرچینه_اوږدتیا 8

    تعريفنوع بنية TOKEN_سرچینه {
      CHAR سرچینه_Name[TOKEN_سرچینه_اوږدتیا];
      LUID سرچینه_Identifier;
    } TOKEN_سرچینه_2,*PTOKEN_سرچینه;

    تعريفنوع بنية _TOKEN_STATISTICS {
      LUID TokenId;
      LUID AuthenticationId;
      LARGE_INTEGER Expiration_وخت;
      TOKEN_TYPE TokenType;
      SECURITY_IMPERSONATION_LEVEL ImpersonationLevel;
      DWORD DynamicCharged;
      DWORD Dynamic_شته;
      DWORD ډله_شمېر;
      DWORD Privilege_شمېر;
      LUID ModifiedId;
    } TOKEN_STATISTICS,*PTOKEN_STATISTICS;

    تعريفنوع بنية _TOKEN_CONTROL {
      LUID TokenId;
      LUID AuthenticationId;
      LUID ModifiedId;
      TOKEN_سرچینه_2 Token_سرچینه;
    } TOKEN_CONTROL,*PTOKEN_CONTROL;

    تعريفنوع بنية _TOKEN_ORIGIN {
      LUID OriginatingLogonSession;
    } TOKEN_ORIGIN,*PTOKEN_ORIGIN;

#تعریف_کړه SECURITY_DYNAMIC_TRACKING (TRUE)
#تعریف_کړه SECURITY_STATIC_TRACKING (FALSE)

    تعريفنوع BOOLEAN SECURITY_CONTEXT_TRACKING_ډېرپېښ,*PSECURITY_CONTEXT_TRACKING_ډېرپېښ;

    تعريفنوع بنية SECURITY_QUALITY_د_SERVICE {
      DWORD اوږدتیا_2;
      SECURITY_IMPERSONATION_LEVEL ImpersonationLevel;
      SECURITY_CONTEXT_TRACKING_ډېرپېښ Context_Tracking_ډېرپېښ;
      BOOLEAN EffectiveOnly;
    } SECURITY_QUALITY_د_SERVICE_2,*PSECURITY_QUALITY_د_SERVICE;

    تعريفنوع بنية _SE_IMPERSONATION_STATE {
      PACCESS_TOKEN Token;
      BOOLEAN CopyOnOpen;
      BOOLEAN EffectiveOnly;
      SECURITY_IMPERSONATION_LEVEL Level;
    } SE_IMPERSONATION_STATE,*PSE_IMPERSONATION_STATE;

#تعریف_کړه DISABLE_MAX_PRIVILEGE 0x1
#تعریف_کړه SANDBOX_INERT 0x2

    تعريفنوع DWORD SECURITY_INFORMATION,*PSECURITY_INFORMATION;

#تعریف_کړه OWNER_SECURITY_INFORMATION (0x00000001L)
#تعریف_کړه ډله_SECURITY_INFORMATION (0x00000002L)
#تعریف_کړه DACL_SECURITY_INFORMATION (0x00000004L)
#تعریف_کړه SACL_SECURITY_INFORMATION (0x00000008L)

#تعریف_کړه PROTECTED_DACL_SECURITY_INFORMATION (0x80000000L)
#تعریف_کړه PROTECTED_SACL_SECURITY_INFORMATION (0x40000000L)
#تعریف_کړه UNPROTECTED_DACL_SECURITY_INFORMATION (0x20000000L)
#تعریف_کړه UNPROTECTED_SACL_SECURITY_INFORMATION (0x10000000L)

#تعریف_کړه PROCESS_TERMINATE (0x0001)
#تعریف_کړه PROCESS_CREATE_THREAD (0x0002)
#تعریف_کړه PROCESS_سېټ_SESSIONID (0x0004)
#تعریف_کړه PROCESS_VM_OPERATION (0x0008)
#تعریف_کړه PROCESS_VM_READ (0x0010)
#تعریف_کړه PROCESS_VM_WRITE (0x0020)
#تعریف_کړه PROCESS_DUP_HANDLE (0x0040)
#تعریف_کړه PROCESS_CREATE_PROCESS (0x0080)
#تعریف_کړه PROCESS_سېټ_QUOTA (0x0100)
#تعریف_کړه PROCESS_سېټ_INFORMATION (0x0200)
#تعریف_کړه PROCESS_QUERY_INFORMATION (0x0400)
#تعریف_کړه PROCESS_SUSPEND_RESUME (0x0800)
#تعریف_کړه PROCESS_QUERY_LIMITED_INFORMATION (0x1000)
#تعریف_کړه PROCESS_سېټ_LIMITED_INFORMATION (0x2000)
#تعریف_کړه PROCESS_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0xFFF)

#که_تعریف_شوی _WIN64
#تعریف_کړه اعظمي_PROCESSORS 64
#وإلا
#تعریف_کړه اعظمي_PROCESSORS 32
#د_که_پای

#تعریف_کړه THREAD_TERMINATE (0x0001)
#تعریف_کړه THREAD_SUSPEND_RESUME (0x0002)
#تعریف_کړه THREAD_GET_CONTEXT (0x0008)
#تعریف_کړه THREAD_سېټ_CONTEXT (0x0010)
#تعریف_کړه THREAD_سېټ_INFORMATION (0x0020)
#تعریف_کړه THREAD_QUERY_INFORMATION (0x0040)
#تعریف_کړه THREAD_سېټ_THREAD_TOKEN (0x0080)
#تعریف_کړه THREAD_IMPERSONATE (0x0100)
#تعریف_کړه THREAD_مستقیم_IMPERSONATION (0x0200)

#تعریف_کړه THREAD_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0x3FF)

#تعریف_کړه دنده_OBJECT_ټاکل_PROCESS (0x0001)
#تعریف_کړه دنده_OBJECT_سېټ_ځانګړتیاوې (0x0002)
#تعریف_کړه دنده_OBJECT_QUERY (0x0004)
#تعریف_کړه دنده_OBJECT_TERMINATE (0x0008)
#تعریف_کړه دنده_OBJECT_سېټ_SECURITY_ځانګړتیاوې (0x0010)
#تعریف_کړه دنده_OBJECT_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0x1F)

    تعريفنوع بنية دنده_سېټ_ARRAY {
      HANDLE دنده_Handle;
      DWORD MemberLevel;
      DWORD Flags;
    } دنده_سېټ_ARRAY_2,*PJOB_سېټ_ARRAY;

#تعریف_کړه FLS_اعظمي_شته 128
#تعریف_کړه TLS_MINIMUM_شته 64

#که_نه_تعریف_شوی _NT_TIB_DEFINED
#تعریف_کړه _NT_TIB_DEFINED
    تعريفنوع بنية _NT_TIB {
      بنية EXCEPTION_REGISTRATION_ریکارډ_2 *ExceptionList;
      PVOID ډېری_بنسټ;
      PVOID ډېری_حد;
      PVOID SubSystemTib;
      اتحاد {
	PVOID Fiber_معلومات;
	DWORD نسخه_2;
      };
      PVOID Arbitrary_User_اشاره_ګر;
      بنية _NT_TIB *Self;
    } NT_TIB;
    تعريفنوع NT_TIB *PNT_TIB;
#د_که_پای

    تعريفنوع بنية _NT_TIB32 {
      DWORD ExceptionList;
      DWORD ډېری_بنسټ;
      DWORD ډېری_حد;
      DWORD SubSystemTib;
      اتحاد {
	DWORD Fiber_معلومات;
	DWORD نسخه_2;
      };
      DWORD Arbitrary_User_اشاره_ګر;
      DWORD Self;
    } NT_TIB32,*PNT_TIB32;

    تعريفنوع بنية _NT_TIB64 {
      DWORD64 ExceptionList;
      DWORD64 ډېری_بنسټ;
      DWORD64 ډېری_حد;
      DWORD64 SubSystemTib;
      اتحاد {
	DWORD64 Fiber_معلومات;
	DWORD نسخه_2;
      };
      DWORD64 Arbitrary_User_اشاره_ګر;
      DWORD64 Self;
    } NT_TIB64,*PNT_TIB64;

#إذا !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_)
#تعریف_کړه WX86
#د_که_پای

#تعریف_کړه THREAD_بنسټ_لومړیتوب_LOWRT 15
#تعریف_کړه THREAD_بنسټ_لومړیتوب_MAX 2
#تعریف_کړه THREAD_بنسټ_لومړیتوب_MIN (-2)
#تعریف_کړه THREAD_بنسټ_لومړیتوب_IDLE (-15)

    تعريفنوع بنية _QUOTA_LIMITS {
      اندازه_T Paged_Pool_حد;
      اندازه_T Non_Paged_Pool_حد;
      اندازه_T Minimum_Working_سېټ_اندازه;
      اندازه_T اعظمي_Working_سېټ_اندازه;
      اندازه_T Pagefile_حد;
      LARGE_INTEGER وخت_حد;
    } QUOTA_LIMITS,*PQUOTA_LIMITS;

#تعریف_کړه QUOTA_LIMITS_HARDWS_MIN_ENABLE 0x00000001
#تعریف_کړه QUOTA_LIMITS_HARDWS_MIN_DISABLE 0x00000002
#تعریف_کړه QUOTA_LIMITS_HARDWS_MAX_ENABLE 0x00000004
#تعریف_کړه QUOTA_LIMITS_HARDWS_MAX_DISABLE 0x00000008

    تعريفنوع بنية _QUOTA_LIMITS_EX {
      اندازه_T Paged_Pool_حد;
      اندازه_T Non_Paged_Pool_حد;
      اندازه_T Minimum_Working_سېټ_اندازه;
      اندازه_T اعظمي_Working_سېټ_اندازه;
      اندازه_T Pagefile_حد;
      LARGE_INTEGER وخت_حد;
      اندازه_T Reserved1;
      اندازه_T Reserved2;
      اندازه_T Reserved3;
      اندازه_T Reserved4;
      DWORD Flags;
      DWORD Reserved5;
    } QUOTA_LIMITS_EX,*PQUOTA_LIMITS_EX;

    تعريفنوع بنية _IO_COUNTERS {
      ULONGLONG Read_Operation_شمېر;
      ULONGLONG Write_Operation_شمېر;
      ULONGLONG Other_Operation_شمېر;
      ULONGLONG Read_Transfer_شمېر;
      ULONGLONG Write_Transfer_شمېر;
      ULONGLONG Other_Transfer_شمېر;
    } IO_COUNTERS;
    تعريفنوع IO_COUNTERS *PIO_COUNTERS;

    تعريفنوع بنية _JOBOBJECT_BASIC_ACCOUNTING_INFORMATION {
      LARGE_INTEGER ټول_User_وخت;
      LARGE_INTEGER ټول_Kernel_وخت;
      LARGE_INTEGER This_Period_ټول_User_وخت;
      LARGE_INTEGER This_Period_ټول_Kernel_وخت;
      DWORD ټول_پاڼه_Fault_شمېر;
      DWORD ټول_Processes;
      DWORD فعال_Processes;
      DWORD ټول_Terminated_Processes;
    } JOBOBJECT_BASIC_ACCOUNTING_INFORMATION,*PJOBOBJECT_BASIC_ACCOUNTING_INFORMATION;

    تعريفنوع بنية JOBOBJECT_BASIC_حد_INFORMATION {
      LARGE_INTEGER فی_Process_User_وخت_حد;
      LARGE_INTEGER فی_دنده_User_وخت_حد;
      DWORD حد_Flags;
      اندازه_T Minimum_Working_سېټ_اندازه;
      اندازه_T اعظمي_Working_سېټ_اندازه;
      DWORD فعال_Process_حد;
      ULONG_PTR Affinity;
      DWORD لومړیتوب_Class;
      DWORD SchedulingClass;
    } JOBOBJECT_BASIC_حد_INFORMATION_2,*PJOBOBJECT_BASIC_حد_INFORMATION;

    تعريفنوع بنية JOBOBJECT_EXTENDED_حد_INFORMATION {
      JOBOBJECT_BASIC_حد_INFORMATION_2 Basic_حد_Information;
      IO_COUNTERS IoInfo;
      اندازه_T Process_حافظه_حد;
      اندازه_T دنده_حافظه_حد;
      اندازه_T Peak_Process_حافظه_کارول_شوی;
      اندازه_T Peak_دنده_حافظه_کارول_شوی;
    } JOBOBJECT_EXTENDED_حد_INFORMATION_2,*PJOBOBJECT_EXTENDED_حد_INFORMATION;

    تعريفنوع بنية _JOBOBJECT_BASIC_PROCESS_ID_LIST {
      DWORD شمېره_د_Assigned_Processes;
      DWORD شمېره_د_Process_Ids_دننه_List;
      ULONG_PTR ProcessIdList[1];
    } JOBOBJECT_BASIC_PROCESS_ID_LIST,*PJOBOBJECT_BASIC_PROCESS_ID_LIST;

    تعريفنوع بنية _JOBOBJECT_BASIC_UI_RESTRICTIONS {
      DWORD UIRestrictionsClass;
    } JOBOBJECT_BASIC_UI_RESTRICTIONS,*PJOBOBJECT_BASIC_UI_RESTRICTIONS;

    تعريفنوع بنية JOBOBJECT_SECURITY_حد_INFORMATION {
      DWORD Security_حد_Flags;
      HANDLE دنده_Token;
      PTOKEN_GROUPS Sids_منزل_Disable;
      PTOKEN_PRIVILEGES Privileges_منزل_Delete;
      PTOKEN_GROUPS RestrictedSids;
    } JOBOBJECT_SECURITY_حد_INFORMATION_2,*PJOBOBJECT_SECURITY_حد_INFORMATION;

    تعريفنوع بنية JOBOBJECT_پای_ټکی_د_دنده_وخت_INFORMATION {
      DWORD پای_ټکی_د_دنده_وخت_Action;
    } JOBOBJECT_پای_ټکی_د_دنده_وخت_INFORMATION_2,*PJOBOBJECT_پای_ټکی_د_دنده_وخت_INFORMATION;

    تعريفنوع بنية JOBOBJECT_ASSOCIATE_COMPLETION_پورټ {
      PVOID Completion_کلی;
      HANDLE Completion_پورټ;
    } JOBOBJECT_ASSOCIATE_COMPLETION_پورټ_2,*PJOBOBJECT_ASSOCIATE_COMPLETION_پورټ;

    تعريفنوع بنية _JOBOBJECT_BASIC_AND_IO_ACCOUNTING_INFORMATION {
      JOBOBJECT_BASIC_ACCOUNTING_INFORMATION BasicInfo;
      IO_COUNTERS IoInfo;
    } JOBOBJECT_BASIC_AND_IO_ACCOUNTING_INFORMATION,*PJOBOBJECT_BASIC_AND_IO_ACCOUNTING_INFORMATION;

    تعريفنوع بنية _JOBOBJECT_JOBSET_INFORMATION {
      DWORD MemberLevel;
    } JOBOBJECT_JOBSET_INFORMATION,*PJOBOBJECT_JOBSET_INFORMATION;

#تعریف_کړه دنده_OBJECT_TERMINATE_AT_پای_ټکی_د_دنده 0
#تعریف_کړه دنده_OBJECT_POST_AT_پای_ټکی_د_دنده 1

#تعریف_کړه دنده_OBJECT_پیغام_پای_ټکی_د_دنده_وخت 1
#تعریف_کړه دنده_OBJECT_پیغام_پای_ټکی_د_PROCESS_وخت 2
#تعریف_کړه دنده_OBJECT_پیغام_فعال_PROCESS_حد 3
#تعریف_کړه دنده_OBJECT_پیغام_فعال_PROCESS_ZERO 4
#تعریف_کړه دنده_OBJECT_پیغام_NEW_PROCESS 6
#تعریف_کړه دنده_OBJECT_پیغام_EXIT_PROCESS 7
#تعریف_کړه دنده_OBJECT_پیغام_ABNORMAL_EXIT_PROCESS 8
#تعریف_کړه دنده_OBJECT_پیغام_PROCESS_حافظه_حد 9
#تعریف_کړه دنده_OBJECT_پیغام_دنده_حافظه_حد 10

#تعریف_کړه دنده_OBJECT_حد_WORKINGSET 0x00000001
#تعریف_کړه دنده_OBJECT_حد_PROCESS_وخت 0x00000002
#تعریف_کړه دنده_OBJECT_حد_دنده_وخت 0x00000004
#تعریف_کړه دنده_OBJECT_حد_فعال_PROCESS 0x00000008
#تعریف_کړه دنده_OBJECT_حد_AFFINITY 0x00000010
#تعریف_کړه دنده_OBJECT_حد_لومړیتوب_CLASS 0x00000020
#تعریف_کړه دنده_OBJECT_حد_PRESERVE_دنده_وخت 0x00000040
#تعریف_کړه دنده_OBJECT_حد_SCHEDULING_CLASS 0x00000080

#تعریف_کړه دنده_OBJECT_حد_PROCESS_حافظه 0x00000100
#تعریف_کړه دنده_OBJECT_حد_دنده_حافظه 0x00000200
#تعریف_کړه دنده_OBJECT_حد_DIE_ON_UNHANDLED_EXCEPTION 0x00000400
#تعریف_کړه دنده_OBJECT_حد_BREAKAWAY_OK 0x00000800
#تعریف_کړه دنده_OBJECT_حد_SILENT_BREAKAWAY_OK 0x00001000
#تعریف_کړه دنده_OBJECT_حد_KILL_ON_دنده_CLOSE 0x00002000

#تعریف_کړه دنده_OBJECT_حد_RESERVED2 0x00004000
#تعریف_کړه دنده_OBJECT_حد_RESERVED3 0x00008000
#تعریف_کړه دنده_OBJECT_حد_RESERVED4 0x00010000
#تعریف_کړه دنده_OBJECT_حد_RESERVED5 0x00020000
#تعریف_کړه دنده_OBJECT_حد_RESERVED6 0x00040000

#تعریف_کړه دنده_OBJECT_حد_VALID_FLAGS 0x0007ffff

#تعریف_کړه دنده_OBJECT_BASIC_حد_VALID_FLAGS 0x000000ff
#تعریف_کړه دنده_OBJECT_EXTENDED_حد_VALID_FLAGS 0x00003fff
#تعریف_کړه دنده_OBJECT_RESERVED_حد_VALID_FLAGS 0x0007ffff

#تعریف_کړه دنده_OBJECT_UILIMIT_NONE 0x00000000

#تعریف_کړه دنده_OBJECT_UILIMIT_HANDLES 0x00000001
#تعریف_کړه دنده_OBJECT_UILIMIT_READCLIPBOARD 0x00000002
#تعریف_کړه دنده_OBJECT_UILIMIT_WRITECLIPBOARD 0x00000004
#تعریف_کړه دنده_OBJECT_UILIMIT_SYSTEMPARAMETERS 0x00000008
#تعریف_کړه دنده_OBJECT_UILIMIT_DISPLAYSETTINGS 0x00000010
#تعریف_کړه دنده_OBJECT_UILIMIT_GLOBALATOMS 0x00000020
#تعریف_کړه دنده_OBJECT_UILIMIT_DESKTOP 0x00000040
#تعریف_کړه دنده_OBJECT_UILIMIT_EXITWINDOWS 0x00000080

#تعریف_کړه دنده_OBJECT_UILIMIT_ALL 0x000000FF

#تعریف_کړه دنده_OBJECT_UI_VALID_FLAGS 0x000000FF

#تعریف_کړه دنده_OBJECT_SECURITY_NO_ADMIN 0x00000001
#تعریف_کړه دنده_OBJECT_SECURITY_RESTRICTED_TOKEN 0x00000002
#تعریف_کړه دنده_OBJECT_SECURITY_ONLY_TOKEN 0x00000004
#تعریف_کړه دنده_OBJECT_SECURITY_FILTER_نښې 0x00000008

#تعریف_کړه دنده_OBJECT_SECURITY_VALID_FLAGS 0x0000000f

    تعريفنوع تعداد _JOBOBJECTINFOCLASS {
      دنده_Object_Basic_Accounting_Information = 1,دنده_Object_Basic_حد_Information,دنده_Object_Basic_Process_Id_List,دنده_Object_Basic_UIRestrictions,
      دنده_Object_Security_حد_Information,دنده_Object_پای_ټکی_د_دنده_وخت_Information,دنده_Object_Associate_Completion_پورټ_Information,
      دنده_Object_Basic_And_Io_Accounting_Information,دنده_Object_Extended_حد_Information,دنده_Object_دنده_سېټ_Information,Max_دنده_Object_Info_Class
    } JOBOBJECTINFOCLASS;

#تعریف_کړه EVENT_MODIFY_STATE 0x0002
#تعریف_کړه EVENT_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x3)

#تعریف_کړه MUTANT_QUERY_STATE 0x0001

#تعریف_کړه MUTANT_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE| MUTANT_QUERY_STATE)
#تعریف_کړه SEMAPHORE_MODIFY_STATE 0x0002
#تعریف_کړه SEMAPHORE_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x3)

#تعریف_کړه TIMER_QUERY_STATE 0x0001
#تعریف_کړه TIMER_MODIFY_STATE 0x0002

#تعریف_کړه TIMER_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE| TIMER_QUERY_STATE|TIMER_MODIFY_STATE)

#تعریف_کړه وخت_ZONE_ID_UNKNOWN 0
#تعریف_کړه وخت_ZONE_ID_STANDARD 1
#تعریف_کړه وخت_ZONE_ID_DAYLIGHT 2

    تعريفنوع تعداد _LOGICAL_PROCESSOR_RELATIONSHIP {
      اړیکه_Processor_Core,اړیکه_Numa_غوټه,اړیکه_Cache
    } LOGICAL_PROCESSOR_RELATIONSHIP;

#تعریف_کړه LTP_PC_SMT 0x1

    تعريفنوع تعداد _PROCESSOR_CACHE_TYPE {
      CacheUnified,CacheInstruction,Cache_معلومات,CacheTrace
    } PROCESSOR_CACHE_TYPE;

#تعریف_کړه CACHE_FULLY_ASSOCIATIVE 0xFF

    تعريفنوع بنية _CACHE_DESCRIPTOR {
      BYTE Level;
      BYTE Associativity;
      کلمه_3 کرښه_اندازه_2;
      DWORD اندازه_3;
      PROCESSOR_CACHE_TYPE Type;
    } CACHE_DESCRIPTOR,*PCACHE_DESCRIPTOR;

    تعريفنوع بنية _SYSTEM_LOGICAL_PROCESSOR_INFORMATION {
      ULONG_PTR Processor_ماسک;
      LOGICAL_PROCESSOR_RELATIONSHIP Relationship;
      اتحاد {
	بنية {
	  BYTE Flags;
	} ProcessorCore;
	بنية {
	  DWORD غوټه_شمېره;
	} Numa_غوټه;
	CACHE_DESCRIPTOR Cache;
	ULONGLONG Reserved[2];
      };
    } SYSTEM_LOGICAL_PROCESSOR_INFORMATION,*PSYSTEM_LOGICAL_PROCESSOR_INFORMATION;

#تعریف_کړه PROCESSOR_INTEL_386 386
#تعریف_کړه PROCESSOR_INTEL_486 486
#تعریف_کړه PROCESSOR_INTEL_PENTIUM 586
#تعریف_کړه PROCESSOR_INTEL_IA64 2200
#تعریف_کړه PROCESSOR_AMD_X8664 8664
#تعریف_کړه PROCESSOR_MIPS_R4000 4000
#تعریف_کړه PROCESSOR_ALPHA_21064 21064
#تعریف_کړه PROCESSOR_PPC_601 601
#تعریف_کړه PROCESSOR_PPC_603 603
#تعریف_کړه PROCESSOR_PPC_604 604
#تعریف_کړه PROCESSOR_PPC_620 620
#تعریف_کړه PROCESSOR_HITACHI_SH3 10003
#تعریف_کړه PROCESSOR_HITACHI_SH3E 10004
#تعریف_کړه PROCESSOR_HITACHI_SH4 10005
#تعریف_کړه PROCESSOR_MOTOROLA_821 821
#تعریف_کړه PROCESSOR_SHx_SH3 103
#تعریف_کړه PROCESSOR_SHx_SH4 104
#تعریف_کړه PROCESSOR_STRONGARM 2577
#تعریف_کړه PROCESSOR_ARM720 1824
#تعریف_کړه PROCESSOR_ARM820 2080
#تعریف_کړه PROCESSOR_ARM920 2336
#تعریف_کړه PROCESSOR_ARM_7TDMI 70001
#تعریف_کړه PROCESSOR_OPTIL 0x494f

#تعریف_کړه PROCESSOR_ARCHITECTURE_INTEL 0
#تعریف_کړه PROCESSOR_ARCHITECTURE_MIPS 1
#تعریف_کړه PROCESSOR_ARCHITECTURE_ALPHA 2
#تعریف_کړه PROCESSOR_ARCHITECTURE_PPC 3
#تعریف_کړه PROCESSOR_ARCHITECTURE_SHX 4
#تعریف_کړه PROCESSOR_ARCHITECTURE_ARM 5
#تعریف_کړه PROCESSOR_ARCHITECTURE_IA64 6
#تعریف_کړه PROCESSOR_ARCHITECTURE_ALPHA64 7
#تعریف_کړه PROCESSOR_ARCHITECTURE_MSIL 8
#تعریف_کړه PROCESSOR_ARCHITECTURE_AMD64 9
#تعریف_کړه PROCESSOR_ARCHITECTURE_IA32_ON_WIN64 10

#تعریف_کړه PROCESSOR_ARCHITECTURE_UNKNOWN 0xFFFF

#تعریف_کړه PF_FLOATING_ټکی_PRECISION_ERRATA 0
#تعریف_کړه PF_FLOATING_ټکی_EMULATED 1
#تعریف_کړه PF_COMPARE_EXCHANGE_DOUBLE 2
#تعریف_کړه PF_MMX_INSTRUCTIONS_شته 3
#تعریف_کړه PF_PPC_MOVEMEM_64_بټ_OK 4
#تعریف_کړه PF_ALPHA_BYTE_INSTRUCTIONS 5
#تعریف_کړه PF_XMMI_INSTRUCTIONS_شته 6
#تعریف_کړه PF_3_DNOW_INSTRUCTIONS_شته 7
#تعریف_کړه PF_RDTSC_INSTRUCTION_شته 8
#تعریف_کړه PF_PAE_ENABLED 9
#تعریف_کړه PF_XMMI64_INSTRUCTIONS_شته 10
#تعریف_کړه PF_SSE_DAZ_ډېرپېښ_شته 11
#تعریف_کړه PF_NX_ENABLED 12

    تعريفنوع بنية حافظه_BASIC_INFORMATION_2 {
      PVOID بنسټ_پته;
      PVOID ویش_بنسټ;
      DWORD ویش_Protect;
      اندازه_T Region_اندازه;
      DWORD State;
      DWORD Protect;
      DWORD Type;
    } حافظه_BASIC_INFORMATION,*PMEMORY_BASIC_INFORMATION;

    تعريفنوع بنية حافظه_BASIC_INFORMATION32 {
      DWORD بنسټ_پته;
      DWORD ویش_بنسټ;
      DWORD ویش_Protect;
      DWORD Region_اندازه;
      DWORD State;
      DWORD Protect;
      DWORD Type;
    } حافظه_BASIC_INFORMATION32_2,*PMEMORY_BASIC_INFORMATION32;

    تعريفنوع بنية DECLSPEC_ALIGN(16) حافظه_BASIC_INFORMATION64 {
      ULONGLONG بنسټ_پته;
      ULONGLONG ویش_بنسټ;
      DWORD ویش_Protect;
      DWORD __alignment1;
      ULONGLONG Region_اندازه;
      DWORD State;
      DWORD Protect;
      DWORD Type;
      DWORD __alignment2;
    } حافظه_BASIC_INFORMATION64_2,*PMEMORY_BASIC_INFORMATION64;

#تعریف_کړه SECTION_QUERY 0x0001
#تعریف_کړه SECTION_MAP_WRITE 0x0002
#تعریف_کړه SECTION_MAP_READ 0x0004
#تعریف_کړه SECTION_MAP_EXECUTE 0x0008
#تعریف_کړه SECTION_EXTEND_اندازه 0x0010
#تعریف_کړه SECTION_MAP_EXECUTE_EXPLICIT 0x0020

#تعریف_کړه SECTION_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SECTION_QUERY| SECTION_MAP_WRITE | SECTION_MAP_READ | SECTION_MAP_EXECUTE | SECTION_EXTEND_اندازه)
#تعریف_کړه پاڼه_NOACCESS 0x01
#تعریف_کړه پاڼه_READONLY 0x02
#تعریف_کړه پاڼه_READWRITE 0x04
#تعریف_کړه پاڼه_WRITECOPY 0x08
#تعریف_کړه پاڼه_EXECUTE 0x10
#تعریف_کړه پاڼه_EXECUTE_READ 0x20
#تعریف_کړه پاڼه_EXECUTE_READWRITE 0x40
#تعریف_کړه پاڼه_EXECUTE_WRITECOPY 0x80
#تعریف_کړه پاڼه_GUARD 0x100
#تعریف_کړه پاڼه_NOCACHE 0x200
#تعریف_کړه پاڼه_WRITECOMBINE 0x400
#تعریف_کړه MEM_COMMIT 0x1000
#تعریف_کړه MEM_RESERVE 0x2000
#تعریف_کړه MEM_DECOMMIT 0x4000
#تعریف_کړه MEM_RELEASE 0x8000
#تعریف_کړه MEM_FREE 0x10000
#تعریف_کړه MEM_شخصي 0x20000
#تعریف_کړه MEM_MAPPED 0x40000
#تعریف_کړه MEM_RESET 0x80000
#تعریف_کړه MEM_سر_ښکته 0x100000
#تعریف_کړه MEM_WRITE_WATCH 0x200000
#تعریف_کړه MEM_PHYSICAL 0x400000
#تعریف_کړه MEM_LARGE_پاڼې 0x20000000
#تعریف_کړه MEM_4_MB_پاڼې 0x80000000
#تعریف_کړه SEC_FILE 0x800000
#تعریف_کړه SEC_IMAGE 0x1000000
#تعریف_کړه SEC_RESERVE 0x4000000
#تعریف_کړه SEC_COMMIT 0x8000000
#تعریف_کړه SEC_NOCACHE 0x10000000
#تعریف_کړه SEC_LARGE_پاڼې 0x80000000
#تعریف_کړه MEM_IMAGE SEC_IMAGE
#تعریف_کړه WRITE_WATCH_FLAG_RESET 0x01

#تعریف_کړه FILE_READ_معلومات (0x0001)
#تعریف_کړه FILE_LIST_DIRECTORY (0x0001)

#تعریف_کړه FILE_WRITE_معلومات (0x0002)
#تعریف_کړه FILE_جمع_کړه_FILE (0x0002)

#تعریف_کړه FILE_APPEND_معلومات (0x0004)
#تعریف_کړه FILE_جمع_کړه_SUBDIRECTORY (0x0004)
#تعریف_کړه FILE_CREATE_PIPE_INSTANCE (0x0004)

#تعریف_کړه FILE_READ_EA (0x0008)

#تعریف_کړه FILE_WRITE_EA (0x0010)

#تعریف_کړه FILE_EXECUTE (0x0020)
#تعریف_کړه FILE_TRAVERSE (0x0020)

#تعریف_کړه FILE_DELETE_ماشوم (0x0040)

#تعریف_کړه FILE_READ_ځانګړتیاوې (0x0080)

#تعریف_کړه FILE_WRITE_ځانګړتیاوې (0x0100)

#تعریف_کړه FILE_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0x1FF)
#تعریف_کړه FILE_GENERIC_READ (STANDARD_RIGHTS_READ | FILE_READ_معلومات | FILE_READ_ځانګړتیاوې | FILE_READ_EA | SYNCHRONIZE)
#تعریف_کړه FILE_GENERIC_WRITE (STANDARD_RIGHTS_WRITE | FILE_WRITE_معلومات | FILE_WRITE_ځانګړتیاوې | FILE_WRITE_EA | FILE_APPEND_معلومات | SYNCHRONIZE)
#تعریف_کړه FILE_GENERIC_EXECUTE (STANDARD_RIGHTS_EXECUTE | FILE_READ_ځانګړتیاوې | FILE_EXECUTE | SYNCHRONIZE)

#تعریف_کړه FILE_SHARE_READ 0x00000001
#تعریف_کړه FILE_SHARE_WRITE 0x00000002
#تعریف_کړه FILE_SHARE_DELETE 0x00000004
#تعریف_کړه FILE_ATTRIBUTE_READONLY 0x00000001
#تعریف_کړه FILE_ATTRIBUTE_HIDDEN 0x00000002
#تعریف_کړه FILE_ATTRIBUTE_SYSTEM 0x00000004
#تعریف_کړه FILE_ATTRIBUTE_DIRECTORY 0x00000010
#تعریف_کړه FILE_ATTRIBUTE_ARCHIVE 0x00000020
#تعریف_کړه FILE_ATTRIBUTE_DEVICE 0x00000040
#تعریف_کړه FILE_ATTRIBUTE_نورمال 0x00000080
#تعریف_کړه FILE_ATTRIBUTE_TEMPORARY 0x00000100
#تعریف_کړه FILE_ATTRIBUTE_SPARSE_FILE 0x00000200
#تعریف_کړه FILE_ATTRIBUTE_REPARSE_ټکی 0x00000400
#تعریف_کړه FILE_ATTRIBUTE_COMPRESSED 0x00000800
#تعریف_کړه FILE_ATTRIBUTE_OFFLINE 0x00001000
#تعریف_کړه FILE_ATTRIBUTE_NOT_CONTENT_شاخصي 0x00002000
#تعریف_کړه FILE_ATTRIBUTE_ENCRYPTED 0x00004000
#تعریف_کړه FILE_NOTIFY_CHANGE_FILE_NAME 0x00000001
#تعریف_کړه FILE_NOTIFY_CHANGE_DIR_NAME 0x00000002
#تعریف_کړه FILE_NOTIFY_CHANGE_ځانګړتیاوې 0x00000004
#تعریف_کړه FILE_NOTIFY_CHANGE_اندازه 0x00000008
#تعریف_کړه FILE_NOTIFY_CHANGE_وروستی_WRITE 0x00000010
#تعریف_کړه FILE_NOTIFY_CHANGE_وروستی_ACCESS 0x00000020
#تعریف_کړه FILE_NOTIFY_CHANGE_CREATION 0x00000040
#تعریف_کړه FILE_NOTIFY_CHANGE_SECURITY 0x00000100
#تعریف_کړه FILE_ACTION_ADDED 0x00000001
#تعریف_کړه FILE_ACTION_REMOVED 0x00000002
#تعریف_کړه FILE_ACTION_MODIFIED 0x00000003
#تعریف_کړه FILE_ACTION_RENAMED_OLD_NAME 0x00000004
#تعریف_کړه FILE_ACTION_RENAMED_NEW_NAME 0x00000005
#تعریف_کړه MAILSLOT_NO_پیغام ((DWORD)-1)
#تعریف_کړه MAILSLOT_WAIT_FOREVER ((DWORD)-1)
#تعریف_کړه FILE_CASE_SENSITIVE_پلټنه 0x00000001
#تعریف_کړه FILE_CASE_PRESERVED_نومونه 0x00000002
#تعریف_کړه FILE_UNICODE_ON_DISK 0x00000004
#تعریف_کړه FILE_PERSISTENT_ACLS 0x00000008
#تعریف_کړه FILE_FILE_COMPRESSION 0x00000010
#تعریف_کړه FILE_VOLUME_QUOTAS 0x00000020
#تعریف_کړه FILE_SUPPORTS_SPARSE_FILES 0x00000040
#تعریف_کړه FILE_SUPPORTS_REPARSE_POINTS 0x00000080
#تعریف_کړه FILE_SUPPORTS_REMOTE_STORAGE 0x00000100
#تعریف_کړه FILE_VOLUME_IS_COMPRESSED 0x00008000
#تعریف_کړه FILE_SUPPORTS_OBJECT_IDS 0x00010000
#تعریف_کړه FILE_SUPPORTS_ENCRYPTION 0x00020000
#تعریف_کړه FILE_NAMED_STREAMS 0x00040000
#تعریف_کړه FILE_READ_ONLY_VOLUME 0x00080000

    تعريفنوع بنية _FILE_NOTIFY_INFORMATION {
      DWORD بل_ثبت_دننه_واټن;
      DWORD Action;
      DWORD File_Name_اوږدتیا;
      WCHAR FileName[1];
    } FILE_NOTIFY_INFORMATION,*PFILE_NOTIFY_INFORMATION;

    تعريفنوع اتحاد _FILE_SEGMENT_ELEMENT {
      PVOID64 بفر_3;
      ULONGLONG Alignment;
    }FILE_SEGMENT_ELEMENT,*PFILE_SEGMENT_ELEMENT;

    تعريفنوع بنية REPARSE_GUID_معلومات_بفر {
      DWORD Reparse_نښان;
      کلمه_3 Reparse_معلومات_اوږدتیا;
      کلمه_3 Reserved;
      GUID ReparseGuid;
      بنية {
	BYTE معلومات_بفر[1];
      } Generic_Reparse_بفر;
    } REPARSE_GUID_معلومات_بفر_2,*PREPARSE_GUID_معلومات_بفر;

#تعریف_کړه REPARSE_GUID_معلومات_بفر_سرلیک_اندازه ډګر_دننه_واټن(REPARSE_GUID_معلومات_بفر_2,Generic_Reparse_بفر)

#تعریف_کړه اعظمي_REPARSE_معلومات_بفر_اندازه (16 *1024)

#تعریف_کړه IO_REPARSE_نښان_RESERVED_ZERO (0)
#تعریف_کړه IO_REPARSE_نښان_RESERVED_ONE (1)

#تعریف_کړه IO_REPARSE_نښان_RESERVED_RANGE IO_REPARSE_نښان_RESERVED_ONE

#تعریف_کړه Is_Reparse_نښان_Microsoft(نښان_2) (((نښان_2) & 0x80000000))
#تعریف_کړه Is_Reparse_نښان_Name_Surrogate(نښان_2) (((نښان_2) & 0x20000000))

#تعریف_کړه IO_REPARSE_نښان_MOUNT_ټکی (0xA0000003L)
#تعریف_کړه IO_REPARSE_نښان_HSM (0xC0000004L)
#تعریف_کړه IO_REPARSE_نښان_SIS (0x80000007L)
#تعریف_کړه IO_REPARSE_نښان_DFS (0x8000000AL)
#تعریف_کړه IO_REPARSE_نښان_FILTER_MANAGER (0x8000000BL)
#تعریف_کړه IO_COMPLETION_MODIFY_STATE 0x0002
#تعریف_کړه IO_COMPLETION_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x3)
#تعریف_کړه DUPLICATE_CLOSE_سرچینه 0x00000001
#تعریف_کړه DUPLICATE_SAME_ACCESS 0x00000002

    تعريفنوع تعداد _SYSTEM_POWER_STATE {
      PowerSystemUnspecified = 0,PowerSystemWorking = 1,PowerSystemSleeping1 = 2,PowerSystemSleeping2 = 3,PowerSystemSleeping3 = 4,PowerSystemHibernate = 5,PowerSystemShutdown = 6,Power_System_اعظمي = 7
    } SYSTEM_POWER_STATE,*PSYSTEM_POWER_STATE;

#تعریف_کړه POWER_SYSTEM_اعظمي 7

    تعريفنوع تعداد {
      PowerActionNone = 0,PowerActionReserved,PowerActionSleep,PowerActionHibernate,PowerActionShutdown,PowerActionShutdownReset,PowerActionShutdownOff,PowerActionWarmEject
    } POWER_ACTION,*PPOWER_ACTION;

    تعريفنوع تعداد _DEVICE_POWER_STATE {
      PowerDeviceUnspecified = 0,PowerDeviceD0,PowerDeviceD1,PowerDeviceD2,PowerDeviceD3,Power_Device_اعظمي
    } DEVICE_POWER_STATE,*PDEVICE_POWER_STATE;

#تعریف_کړه ES_SYSTEM_REQUIRED ((DWORD)0x00000001)
#تعریف_کړه ES_DISPLAY_REQUIRED ((DWORD)0x00000002)
#تعریف_کړه ES_USER_PRESENT ((DWORD)0x00000004)
#تعریف_کړه ES_CONTINUOUS ((DWORD)0x80000000)

    تعريفنوع DWORD EXECUTION_STATE;

    تعريفنوع تعداد {
      LT_DONT_CARE,LT_ټیټ_ترین_LATENCY
    } LATENCY_وخت;

#تعریف_کړه PDCAP_D0_SUPPORTED 0x00000001
#تعریف_کړه PDCAP_D1_SUPPORTED 0x00000002
#تعریف_کړه PDCAP_D2_SUPPORTED 0x00000004
#تعریف_کړه PDCAP_D3_SUPPORTED 0x00000008
#تعریف_کړه PDCAP_WAKE_FROM_D0_SUPPORTED 0x00000010
#تعریف_کړه PDCAP_WAKE_FROM_D1_SUPPORTED 0x00000020
#تعریف_کړه PDCAP_WAKE_FROM_D2_SUPPORTED 0x00000040
#تعریف_کړه PDCAP_WAKE_FROM_D3_SUPPORTED 0x00000080
#تعریف_کړه PDCAP_WARM_EJECT_SUPPORTED 0x00000100

    تعريفنوع بنية CM_Power_معلومات_s {
      DWORD PD_اندازه;
      DEVICE_POWER_STATE PD_MostRecentPowerState;
      DWORD PD_Capabilities;
      DWORD PD_D1Latency;
      DWORD PD_D2Latency;
      DWORD PD_D3Latency;
      DEVICE_POWER_STATE PD_PowerStateMapping[POWER_SYSTEM_اعظمي];
      SYSTEM_POWER_STATE PD_تر_ټولو_ژور_System_Wake;
    } CM_POWER_معلومات,*PCM_POWER_معلومات;

    تعريفنوع تعداد {
      SystemPowerPolicyAc,SystemPowerPolicyDc,VerifySystemPolicyAc,VerifySystemPolicyDc,SystemPowerCapabilities,SystemBatteryState,SystemPowerStateHandler,ProcessorStateHandler,SystemPowerPolicyCurrent,AdministratorPowerPolicy,SystemReserveHiberFile,ProcessorInformation,SystemPowerInformation,ProcessorStateHandler2,وروستی_Wake_وخت,وروستی_Sleep_وخت,SystemExecutionState,SystemPowerStateNotifyHandler,ProcessorPowerPolicyAc,ProcessorPowerPolicyDc,VerifyProcessorPowerPolicyAc,VerifyProcessorPowerPolicyDc,ProcessorPowerPolicyCurrent,SystemPowerStateLogging,System_Power_Logging_ثبت
    } POWER_INFORMATION_LEVEL;

    تعريفنوع بنية {
      DWORD Granularity;
      DWORD ظرفیت;
    } BATTERY_REPORTING_SCALE,*PBATTERY_REPORTING_SCALE;

    تعريفنوع بنية {
      POWER_ACTION Action;
      DWORD Flags;
      DWORD Event_کوډ;
    } POWER_ACTION_POLICY,*PPOWER_ACTION_POLICY;

#تعریف_کړه POWER_ACTION_QUERY_ALLOWED 0x00000001
#تعریف_کړه POWER_ACTION_UI_ALLOWED 0x00000002
#تعریف_کړه POWER_ACTION_OVERRIDE_APPS 0x00000004
#تعریف_کړه POWER_ACTION_LIGHTEST_لومړی 0x10000000
#تعریف_کړه POWER_ACTION_قلف_CONSOLE 0x20000000
#تعریف_کړه POWER_ACTION_DISABLE_WAKES 0x40000000
#تعریف_کړه POWER_ACTION_CRITICAL 0x80000000

#تعریف_کړه POWER_LEVEL_USER_NOTIFY_متن 0x00000001
#تعریف_کړه POWER_LEVEL_USER_NOTIFY_SOUND 0x00000002
#تعریف_کړه POWER_LEVEL_USER_NOTIFY_EXEC 0x00000004
#تعریف_کړه POWER_USER_NOTIFY_BUTTON 0x00000008
#تعریف_کړه POWER_USER_NOTIFY_SHUTDOWN 0x00000010
#تعریف_کړه POWER_FORCE_TRIGGER_RESET 0x80000000

    تعريفنوع بنية {
      BOOLEAN Enable;
      BYTE اضافي_2[3];
      DWORD BatteryLevel;
      POWER_ACTION_POLICY PowerPolicy;
      SYSTEM_POWER_STATE MinSystemState;
    } SYSTEM_POWER_LEVEL,*PSYSTEM_POWER_LEVEL;

#تعریف_کړه عدد_DISCHARGE_POLICIES 4
#تعریف_کړه DISCHARGE_POLICY_CRITICAL 0
#تعریف_کړه DISCHARGE_POLICY_ټیټ 1

#تعریف_کړه PO_THROTTLE_NONE 0
#تعریف_کړه PO_THROTTLE_CONSTANT 1
#تعریف_کړه PO_THROTTLE_DEGRADE 2
#تعریف_کړه PO_THROTTLE_ADAPTIVE 3
#تعریف_کړه PO_THROTTLE_اعظمي 4

    تعريفنوع بنية _SYSTEM_POWER_POLICY {
      DWORD Revision;
      POWER_ACTION_POLICY PowerButton;
      POWER_ACTION_POLICY SleepButton;
      POWER_ACTION_POLICY LidClose;
      SYSTEM_POWER_STATE LidOpenWake;
      DWORD Reserved;
      POWER_ACTION_POLICY Idle;
      DWORD IdleTimeout;
      BYTE Idle_حساسیت;
      BYTE DynamicThrottle;
      BYTE Spare2[2];
      SYSTEM_POWER_STATE MinSleep;
      SYSTEM_POWER_STATE MaxSleep;
      SYSTEM_POWER_STATE ReducedLatencySleep;
      DWORD WinLogonFlags;
      DWORD Spare3;
      DWORD DozeS4Timeout;
      DWORD خپرونه_ظرفیت_Resolution;
      SYSTEM_POWER_LEVEL DischargePolicy[عدد_DISCHARGE_POLICIES];
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

    تعريفنوع بنية _PROCESSOR_POWER_POLICY_INFO {
      DWORD وخت_Check;
      DWORD Demote_حد;
      DWORD Promote_حد;
      BYTE DemotePercent;
      BYTE PromotePercent;
      BYTE اضافي_2[2];
      DWORD AllowDemotion:1;
      DWORD AllowPromotion:1;
      DWORD Reserved:30;
    } PROCESSOR_POWER_POLICY_INFO,*PPROCESSOR_POWER_POLICY_INFO;

    تعريفنوع بنية _PROCESSOR_POWER_POLICY {
      DWORD Revision;
      BYTE DynamicThrottle;
      BYTE اضافي_2[3];
      DWORD DisableCStates:1;
      DWORD Reserved:31;
      DWORD Policy_شمېر;
      PROCESSOR_POWER_POLICY_INFO Policy[3];
    } PROCESSOR_POWER_POLICY,*PPROCESSOR_POWER_POLICY;

    تعريفنوع بنية _ADMINISTRATOR_POWER_POLICY {
      SYSTEM_POWER_STATE MinSleep;
      SYSTEM_POWER_STATE MaxSleep;
      DWORD MinVideoTimeout;
      DWORD MaxVideoTimeout;
      DWORD MinSpindownTimeout;
      DWORD MaxSpindownTimeout;
    } ADMINISTRATOR_POWER_POLICY,*PADMINISTRATOR_POWER_POLICY;

    تعريفنوع بنية {
      BOOLEAN PowerButtonPresent;
      BOOLEAN SleepButtonPresent;
      BOOLEAN LidPresent;
      BOOLEAN SystemS1;
      BOOLEAN SystemS2;
      BOOLEAN SystemS3;
      BOOLEAN SystemS4;
      BOOLEAN SystemS5;
      BOOLEAN HiberFilePresent;
      BOOLEAN ډک_Wake;
      BOOLEAN VideoDimPresent;
      BOOLEAN ApmPresent;
      BOOLEAN UpsPresent;
      BOOLEAN ThermalControl;
      BOOLEAN ProcessorThrottle;
      BYTE ProcessorMinThrottle;
      BYTE ProcessorMaxThrottle;
      BYTE spare2[4];
      BOOLEAN Disk_Spin_ښکته;
      BYTE spare3[8];
      BOOLEAN SystemBatteriesPresent;
      BOOLEAN Batteries_Are_Short_غړی;
      BATTERY_REPORTING_SCALE BatteryScale[3];
      SYSTEM_POWER_STATE Ac_On_کرښه_Wake;
      SYSTEM_POWER_STATE SoftLidWake;
      SYSTEM_POWER_STATE RtcWake;
      SYSTEM_POWER_STATE MinDeviceWakeState;
      SYSTEM_POWER_STATE Default_ټیټ_Latency_Wake;
    } SYSTEM_POWER_CAPABILITIES,*PSYSTEM_POWER_CAPABILITIES;

    تعريفنوع بنية {
      BOOLEAN Ac_On_کرښه;
      BOOLEAN BatteryPresent;
      BOOLEAN Charging;
      BOOLEAN Discharging;
      BOOLEAN Spare1[4];
      DWORD Max_ظرفیت;
      DWORD پاتې_شوی_ظرفیت;
      DWORD شرح;
      DWORD Estimated_وخت;
      DWORD DefaultAlert1;
      DWORD DefaultAlert2;
    } SYSTEM_BATTERY_STATE,*PSYSTEM_BATTERY_STATE;

#ضمن "pshpack4.h"

#تعریف_کړه IMAGE_DOS_SIGNATURE 0x5A4D
#تعریف_کړه IMAGE_OS2_SIGNATURE 0x454E
#تعریف_کړه IMAGE_OS2_SIGNATURE_LE 0x454C
#تعریف_کړه IMAGE_VXD_SIGNATURE 0x454C
#تعریف_کړه IMAGE_NT_SIGNATURE 0x00004550

#ضمن "pshpack2.h"

    تعريفنوع بنية IMAGE_DOS_سرلیک {
      کلمه_3 e_magic;
      کلمه_3 e_cblp;
      کلمه_3 e_cp;
      کلمه_3 e_crlc;
      کلمه_3 e_cparhdr;
      کلمه_3 e_minalloc;
      کلمه_3 e_maxalloc;
      کلمه_3 e_ss;
      کلمه_3 e_sp;
      کلمه_3 e_csum;
      کلمه_3 e_ip;
      کلمه_3 e_cs;
      کلمه_3 e_lfarlc;
      کلمه_3 e_ovno;
      کلمه_3 e_res[4];
      کلمه_3 e_oemid;
      کلمه_3 e_oeminfo;
      کلمه_3 e_res2[10];
      LONG e_lfanew;
    } IMAGE_DOS_سرلیک_2,*PIMAGE_DOS_سرلیک;

    تعريفنوع بنية IMAGE_OS2_سرلیک {
      کلمه_3 ne_magic;
      CHAR ne_ver;
      CHAR ne_rev;
      کلمه_3 ne_enttab;
      کلمه_3 ne_cbenttab;
      LONG ne_دوراني_ازموینه;
      کلمه_3 ne_flags;
      کلمه_3 ne_autodata;
      کلمه_3 ne_ډېرۍ;
      کلمه_3 ne_ډېری;
      LONG ne_csip;
      LONG ne_sssp;
      کلمه_3 ne_cseg;
      کلمه_3 ne_cmod;
      کلمه_3 ne_cbnrestab;
      کلمه_3 ne_segtab;
      کلمه_3 ne_rsrctab;
      کلمه_3 ne_restab;
      کلمه_3 ne_modtab;
      کلمه_3 ne_imptab;
      LONG ne_nrestab;
      کلمه_3 ne_cmovent;
      کلمه_3 ne_align;
      کلمه_3 ne_cres;
      BYTE ne_exetyp;
      BYTE ne_flagsothers;
      کلمه_3 ne_pretthunks;
      کلمه_3 ne_psegrefbytes;
      کلمه_3 ne_swaparea;
      کلمه_3 ne_expver;
    } IMAGE_OS2_سرلیک_2,*PIMAGE_OS2_سرلیک;

    تعريفنوع بنية IMAGE_VXD_سرلیک {
      کلمه_3 e32_magic;
      BYTE e32_border;
      BYTE e32_worder;
      DWORD e32_level;
      کلمه_3 e32_cpu;
      کلمه_3 e32_os;
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
      کلمه_3 e32_devid;
      کلمه_3 e32_ddkver;
    } IMAGE_VXD_سرلیک_2,*PIMAGE_VXD_سرلیک;

#ضمن "poppack.h"

    تعريفنوع بنية IMAGE_FILE_سرلیک {
      کلمه_3 Machine;
      کلمه_3 شمېره_د_Sections;
      DWORD وخت_Date_Stamp;
      DWORD اشاره_ګر_منزل_نښه_جدول;
      DWORD شمېره_د_Symbols;
      کلمه_3 اندازه_د_Optional_سرلیک;
      کلمه_3 Characteristics;
    } IMAGE_FILE_سرلیک_2,*PIMAGE_FILE_سرلیک;

#تعریف_کړه IMAGE_SIZEOF_FILE_سرلیک 20

#تعریف_کړه IMAGE_FILE_RELOCS_STRIPPED 0x0001
#تعریف_کړه IMAGE_FILE_EXECUTABLE_IMAGE 0x0002
#تعریف_کړه IMAGE_FILE_کرښه_NUMS_STRIPPED 0x0004
#تعریف_کړه IMAGE_FILE_LOCAL_SYMS_STRIPPED 0x0008
#تعریف_کړه IMAGE_FILE_AGGRESIVE_WS_TRIM 0x0010
#تعریف_کړه IMAGE_FILE_LARGE_پته_AWARE 0x0020
#تعریف_کړه IMAGE_FILE_بایټونه_REVERSED_LO 0x0080
#تعریف_کړه IMAGE_FILE_32_بټ_MACHINE 0x0100
#تعریف_کړه IMAGE_FILE_DEBUG_STRIPPED 0x0200
#تعریف_کړه IMAGE_FILE_REMOVABLE_پرلپسې_FROM_بدلون 0x0400
#تعریف_کړه IMAGE_FILE_NET_پرلپسې_FROM_بدلون 0x0800
#تعریف_کړه IMAGE_FILE_SYSTEM 0x1000
#تعریف_کړه IMAGE_FILE_DLL 0x2000
#تعریف_کړه IMAGE_FILE_پورته_SYSTEM_ONLY 0x4000
#تعریف_کړه IMAGE_FILE_بایټونه_REVERSED_HI 0x8000

#تعریف_کړه IMAGE_FILE_MACHINE_UNKNOWN 0
#تعریف_کړه IMAGE_FILE_MACHINE_I386 0x014c
#تعریف_کړه IMAGE_FILE_MACHINE_R3000 0x0162
#تعریف_کړه IMAGE_FILE_MACHINE_R4000 0x0166
#تعریف_کړه IMAGE_FILE_MACHINE_R10000 0x0168
#تعریف_کړه IMAGE_FILE_MACHINE_WCEMIPSV2 0x0169
#تعریف_کړه IMAGE_FILE_MACHINE_ALPHA 0x0184
#تعریف_کړه IMAGE_FILE_MACHINE_SH3 0x01a2
#تعریف_کړه IMAGE_FILE_MACHINE_SH3DSP 0x01a3
#تعریف_کړه IMAGE_FILE_MACHINE_SH3E 0x01a4
#تعریف_کړه IMAGE_FILE_MACHINE_SH4 0x01a6
#تعریف_کړه IMAGE_FILE_MACHINE_SH5 0x01a8
#تعریف_کړه IMAGE_FILE_MACHINE_ARM 0x01c0
#تعریف_کړه IMAGE_FILE_MACHINE_THUMB 0x01c2
#تعریف_کړه IMAGE_FILE_MACHINE_AM33 0x01d3
#تعریف_کړه IMAGE_FILE_MACHINE_POWERPC 0x01F0
#تعریف_کړه IMAGE_FILE_MACHINE_POWERPCFP 0x01f1
#تعریف_کړه IMAGE_FILE_MACHINE_IA64 0x0200
#تعریف_کړه IMAGE_FILE_MACHINE_MIPS16 0x0266
#تعریف_کړه IMAGE_FILE_MACHINE_ALPHA64 0x0284
#تعریف_کړه IMAGE_FILE_MACHINE_MIPSFPU 0x0366
#تعریف_کړه IMAGE_FILE_MACHINE_MIPSFPU16 0x0466
#تعریف_کړه IMAGE_FILE_MACHINE_AXP64 IMAGE_FILE_MACHINE_ALPHA64
#تعریف_کړه IMAGE_FILE_MACHINE_TRICORE 0x0520
#تعریف_کړه IMAGE_FILE_MACHINE_CEF 0x0CEF
#تعریف_کړه IMAGE_FILE_MACHINE_EBC 0x0EBC
#تعریف_کړه IMAGE_FILE_MACHINE_AMD64 0x8664
#تعریف_کړه IMAGE_FILE_MACHINE_ARM64 0xAA64
#تعریف_کړه IMAGE_FILE_MACHINE_M32R 0x9041
#تعریف_کړه IMAGE_FILE_MACHINE_CEE 0xC0EE

    تعريفنوع بنية IMAGE_معلومات_DIRECTORY {
      DWORD Virtual_پته;
      DWORD اندازه_3;
    } IMAGE_معلومات_DIRECTORY_2,*PIMAGE_معلومات_DIRECTORY;

#تعریف_کړه IMAGE_NUMBEROF_DIRECTORY_ENTRIES 16

    تعريفنوع بنية IMAGE_OPTIONAL_سرلیک {

      کلمه_3 Magic;
      BYTE Major_Linker_نسخه;
      BYTE Minor_Linker_نسخه;
      DWORD اندازه_د_کوډ;
      DWORD اندازه_د_Initialized_معلومات;
      DWORD اندازه_د_Uninitialized_معلومات;
      DWORD پته_د_ثبت_ټکی;
      DWORD بنسټ_د_کوډ;
      DWORD بنسټ_د_معلومات;
      DWORD Image_بنسټ;
      DWORD SectionAlignment;
      DWORD FileAlignment;
      کلمه_3 Major_Operating_System_نسخه;
      کلمه_3 Minor_Operating_System_نسخه;
      کلمه_3 Major_Image_نسخه;
      کلمه_3 Minor_Image_نسخه;
      کلمه_3 Major_Subsystem_نسخه;
      کلمه_3 Minor_Subsystem_نسخه;
      DWORD Win32_نسخه_ارزښت;
      DWORD اندازه_د_Image;
      DWORD اندازه_د_سرلیکونه;
      DWORD Check_مجموعه;
      کلمه_3 Subsystem;
      کلمه_3 DllCharacteristics;
      DWORD اندازه_د_ډېری_Reserve;
      DWORD اندازه_د_ډېری_Commit;
      DWORD اندازه_د_ډېرۍ_Reserve;
      DWORD اندازه_د_ډېرۍ_Commit;
      DWORD LoaderFlags;
      DWORD شمېره_د_Rva_And_Sizes;
      IMAGE_معلومات_DIRECTORY_2 معلومات_Directory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
    } IMAGE_OPTIONAL_HEADER32,*PIMAGE_OPTIONAL_HEADER32;

    تعريفنوع بنية IMAGE_ROM_OPTIONAL_سرلیک {
      کلمه_3 Magic;
      BYTE Major_Linker_نسخه;
      BYTE Minor_Linker_نسخه;
      DWORD اندازه_د_کوډ;
      DWORD اندازه_د_Initialized_معلومات;
      DWORD اندازه_د_Uninitialized_معلومات;
      DWORD پته_د_ثبت_ټکی;
      DWORD بنسټ_د_کوډ;
      DWORD بنسټ_د_معلومات;
      DWORD بنسټ_د_Bss;
      DWORD Gpr_ماسک;
      DWORD Cpr_ماسک[4];
      DWORD Gp_ارزښت;
    } IMAGE_ROM_OPTIONAL_سرلیک_2,*PIMAGE_ROM_OPTIONAL_سرلیک;

    تعريفنوع بنية _IMAGE_OPTIONAL_HEADER64 {
      کلمه_3 Magic;
      BYTE Major_Linker_نسخه;
      BYTE Minor_Linker_نسخه;
      DWORD اندازه_د_کوډ;
      DWORD اندازه_د_Initialized_معلومات;
      DWORD اندازه_د_Uninitialized_معلومات;
      DWORD پته_د_ثبت_ټکی;
      DWORD بنسټ_د_کوډ;
      ULONGLONG Image_بنسټ;
      DWORD SectionAlignment;
      DWORD FileAlignment;
      کلمه_3 Major_Operating_System_نسخه;
      کلمه_3 Minor_Operating_System_نسخه;
      کلمه_3 Major_Image_نسخه;
      کلمه_3 Minor_Image_نسخه;
      کلمه_3 Major_Subsystem_نسخه;
      کلمه_3 Minor_Subsystem_نسخه;
      DWORD Win32_نسخه_ارزښت;
      DWORD اندازه_د_Image;
      DWORD اندازه_د_سرلیکونه;
      DWORD Check_مجموعه;
      کلمه_3 Subsystem;
      کلمه_3 DllCharacteristics;
      ULONGLONG اندازه_د_ډېری_Reserve;
      ULONGLONG اندازه_د_ډېری_Commit;
      ULONGLONG اندازه_د_ډېرۍ_Reserve;
      ULONGLONG اندازه_د_ډېرۍ_Commit;
      DWORD LoaderFlags;
      DWORD شمېره_د_Rva_And_Sizes;
      IMAGE_معلومات_DIRECTORY_2 معلومات_Directory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
    } IMAGE_OPTIONAL_HEADER64,*PIMAGE_OPTIONAL_HEADER64;

#تعریف_کړه IMAGE_SIZEOF_ROM_OPTIONAL_سرلیک 56
#تعریف_کړه IMAGE_SIZEOF_STD_OPTIONAL_سرلیک 28
#تعریف_کړه IMAGE_SIZEOF_NT_OPTIONAL32_سرلیک 224
#تعریف_کړه IMAGE_SIZEOF_NT_OPTIONAL64_سرلیک 240

#تعریف_کړه IMAGE_NT_OPTIONAL_HDR32_MAGIC 0x10b
#تعریف_کړه IMAGE_NT_OPTIONAL_HDR64_MAGIC 0x20b
#تعریف_کړه IMAGE_ROM_OPTIONAL_HDR_MAGIC 0x107

#که_تعریف_شوی _WIN64
    تعريفنوع IMAGE_OPTIONAL_HEADER64 IMAGE_OPTIONAL_سرلیک_2;
    تعريفنوع PIMAGE_OPTIONAL_HEADER64 PIMAGE_OPTIONAL_سرلیک;
#تعریف_کړه IMAGE_SIZEOF_NT_OPTIONAL_سرلیک IMAGE_SIZEOF_NT_OPTIONAL64_سرلیک
#تعریف_کړه IMAGE_NT_OPTIONAL_HDR_MAGIC IMAGE_NT_OPTIONAL_HDR64_MAGIC
#وإلا
    تعريفنوع IMAGE_OPTIONAL_HEADER32 IMAGE_OPTIONAL_سرلیک_2;
    تعريفنوع PIMAGE_OPTIONAL_HEADER32 PIMAGE_OPTIONAL_سرلیک;
#تعریف_کړه IMAGE_SIZEOF_NT_OPTIONAL_سرلیک IMAGE_SIZEOF_NT_OPTIONAL32_سرلیک
#تعریف_کړه IMAGE_NT_OPTIONAL_HDR_MAGIC IMAGE_NT_OPTIONAL_HDR32_MAGIC
#د_که_پای

    تعريفنوع بنية _IMAGE_NT_HEADERS64 {
      DWORD Signature;
      IMAGE_FILE_سرلیک_2 File_سرلیک;
      IMAGE_OPTIONAL_HEADER64 Optional_سرلیک;
    } IMAGE_NT_HEADERS64,*PIMAGE_NT_HEADERS64;

    تعريفنوع بنية IMAGE_NT_سرلیکونه {
      DWORD Signature;
      IMAGE_FILE_سرلیک_2 File_سرلیک;
      IMAGE_OPTIONAL_HEADER32 Optional_سرلیک;
    } IMAGE_NT_HEADERS32,*PIMAGE_NT_HEADERS32;

    تعريفنوع بنية IMAGE_ROM_سرلیکونه {
      IMAGE_FILE_سرلیک_2 File_سرلیک;
      IMAGE_ROM_OPTIONAL_سرلیک_2 Optional_سرلیک;
    } IMAGE_ROM_سرلیکونه_2,*PIMAGE_ROM_سرلیکونه;

#که_تعریف_شوی _WIN64
    تعريفنوع IMAGE_NT_HEADERS64 IMAGE_NT_سرلیکونه_2;
    تعريفنوع PIMAGE_NT_HEADERS64 PIMAGE_NT_سرلیکونه;
#وإلا
    تعريفنوع IMAGE_NT_HEADERS32 IMAGE_NT_سرلیکونه_2;
    تعريفنوع PIMAGE_NT_HEADERS32 PIMAGE_NT_سرلیکونه;
#د_که_پای

#تعریف_کړه IMAGE_لومړی_SECTION(ntheader) ((PIMAGE_SECTION_سرلیک) ((ULONG_PTR)ntheader + ډګر_دننه_واټن(IMAGE_NT_سرلیکونه_2,Optional_سرلیک) + ((PIMAGE_NT_سرلیکونه)(ntheader))->File_سرلیک.اندازه_د_Optional_سرلیک))

#تعریف_کړه IMAGE_SUBSYSTEM_UNKNOWN 0
#تعریف_کړه IMAGE_SUBSYSTEM_NATIVE 1
#تعریف_کړه IMAGE_SUBSYSTEM_WINDOWS_GUI 2
#تعریف_کړه IMAGE_SUBSYSTEM_WINDOWS_CUI 3
#تعریف_کړه IMAGE_SUBSYSTEM_OS2_CUI 5
#تعریف_کړه IMAGE_SUBSYSTEM_POSIX_CUI 7
#تعریف_کړه IMAGE_SUBSYSTEM_NATIVE_WINDOWS 8
#تعریف_کړه IMAGE_SUBSYSTEM_WINDOWS_CE_GUI 9
#تعریف_کړه IMAGE_SUBSYSTEM_EFI_APPLICATION 10
#تعریف_کړه IMAGE_SUBSYSTEM_EFI_BOOT_SERVICE_DRIVER 11
#تعریف_کړه IMAGE_SUBSYSTEM_EFI_RUNTIME_DRIVER 12
#تعریف_کړه IMAGE_SUBSYSTEM_EFI_ROM 13
#تعریف_کړه IMAGE_SUBSYSTEM_XBOX 14

#تعریف_کړه IMAGE_DLLCHARACTERISTICS_لوړ_ENTROPY_VA 0x0020
#تعریف_کړه IMAGE_DLLCHARACTERISTICS_DYNAMIC_بنسټ 0x0040
#تعریف_کړه IMAGE_DLLCHARACTERISTICS_FORCE_INTEGRITY 0x0080
#تعریف_کړه IMAGE_DLLCHARACTERISTICS_NX_COMPAT 0x0100
#تعریف_کړه IMAGE_DLLCHARACTERISTICS_NO_ISOLATION 0x0200
#تعریف_کړه IMAGE_DLLCHARACTERISTICS_NO_SEH 0x0400
#تعریف_کړه IMAGE_DLLCHARACTERISTICS_NO_BIND 0x0800
#تعریف_کړه IMAGE_DLLCHARACTERISTICS_APPCONTAINER 0x1000
#تعریف_کړه IMAGE_DLLCHARACTERISTICS_WDM_DRIVER 0x2000
#تعریف_کړه IMAGE_DLLCHARACTERISTICS_GUARD_CF 0x4000
#تعریف_کړه IMAGE_DLLCHARACTERISTICS_TERMINAL_SERVER_AWARE 0x8000

#تعریف_کړه IMAGE_DIRECTORY_ثبت_EXPORT 0
#تعریف_کړه IMAGE_DIRECTORY_ثبت_IMPORT 1
#تعریف_کړه IMAGE_DIRECTORY_ثبت_RESOURCE 2
#تعریف_کړه IMAGE_DIRECTORY_ثبت_EXCEPTION 3
#تعریف_کړه IMAGE_DIRECTORY_ثبت_SECURITY 4
#تعریف_کړه IMAGE_DIRECTORY_ثبت_BASERELOC 5
#تعریف_کړه IMAGE_DIRECTORY_ثبت_DEBUG 6

#تعریف_کړه IMAGE_DIRECTORY_ثبت_ARCHITECTURE 7
#تعریف_کړه IMAGE_DIRECTORY_ثبت_GLOBALPTR 8
#تعریف_کړه IMAGE_DIRECTORY_ثبت_TLS 9
#تعریف_کړه IMAGE_DIRECTORY_ثبت_بارول_CONFIG 10
#تعریف_کړه IMAGE_DIRECTORY_ثبت_BOUND_IMPORT 11
#تعریف_کړه IMAGE_DIRECTORY_ثبت_IAT 12
#تعریف_کړه IMAGE_DIRECTORY_ثبت_DELAY_IMPORT 13
#تعریف_کړه IMAGE_DIRECTORY_ثبت_COM_DESCRIPTOR 14

    تعريفنوع بنية ANON_OBJECT_سرلیک {
      کلمه_3 Sig1;
      کلمه_3 Sig2;
      کلمه_3 نسخه_2;
      کلمه_3 Machine;
      DWORD وخت_Date_Stamp;
      CLSID ClassID;
      DWORD اندازه_د_معلومات;
    } ANON_OBJECT_سرلیک;

#تعریف_کړه IMAGE_SIZEOF_SHORT_NAME 8

    تعريفنوع بنية IMAGE_SECTION_سرلیک {
      BYTE Name[IMAGE_SIZEOF_SHORT_NAME];
      اتحاد {
	DWORD Physical_پته;
	DWORD Virtual_اندازه;
      } Misc;
      DWORD Virtual_پته;
      DWORD اندازه_د_Raw_معلومات;
      DWORD اشاره_ګر_منزل_Raw_معلومات;
      DWORD اشاره_ګر_منزل_Relocations;
      DWORD اشاره_ګر_منزل_Linenumbers;
      کلمه_3 شمېره_د_Relocations;
      کلمه_3 شمېره_د_Linenumbers;
      DWORD Characteristics;
    } IMAGE_SECTION_سرلیک_2,*PIMAGE_SECTION_سرلیک;

#تعریف_کړه IMAGE_SIZEOF_SECTION_سرلیک 40

#تعریف_کړه IMAGE_SCN_TYPE_NO_PAD 0x00000008

#تعریف_کړه IMAGE_SCN_CNT_کوډ 0x00000020
#تعریف_کړه IMAGE_SCN_CNT_INITIALIZED_معلومات 0x00000040
#تعریف_کړه IMAGE_SCN_CNT_UNINITIALIZED_معلومات 0x00000080
#تعریف_کړه IMAGE_SCN_LNK_OTHER 0x00000100
#تعریف_کړه IMAGE_SCN_LNK_INFO 0x00000200
#تعریف_کړه IMAGE_SCN_LNK_REMOVE 0x00000800
#تعریف_کړه IMAGE_SCN_LNK_COMDAT 0x00001000
#تعریف_کړه IMAGE_SCN_NO_DEFER_SPEC_EXC 0x00004000
#تعریف_کړه IMAGE_SCN_GPREL 0x00008000
#تعریف_کړه IMAGE_SCN_MEM_FARDATA 0x00008000
#تعریف_کړه IMAGE_SCN_MEM_PURGEABLE 0x00020000
#تعریف_کړه IMAGE_SCN_MEM_16_بټ 0x00020000
#تعریف_کړه IMAGE_SCN_MEM_LOCKED 0x00040000
#تعریف_کړه IMAGE_SCN_MEM_PRELOAD 0x00080000

#تعریف_کړه IMAGE_SCN_ALIGN_1_بایټونه 0x00100000
#تعریف_کړه IMAGE_SCN_ALIGN_2_بایټونه 0x00200000
#تعریف_کړه IMAGE_SCN_ALIGN_4_بایټونه 0x00300000
#تعریف_کړه IMAGE_SCN_ALIGN_8_بایټونه 0x00400000
#تعریف_کړه IMAGE_SCN_ALIGN_16_بایټونه 0x00500000
#تعریف_کړه IMAGE_SCN_ALIGN_32_بایټونه 0x00600000
#تعریف_کړه IMAGE_SCN_ALIGN_64_بایټونه 0x00700000
#تعریف_کړه IMAGE_SCN_ALIGN_128_بایټونه 0x00800000
#تعریف_کړه IMAGE_SCN_ALIGN_256_بایټونه 0x00900000
#تعریف_کړه IMAGE_SCN_ALIGN_512_بایټونه 0x00A00000
#تعریف_کړه IMAGE_SCN_ALIGN_1024_بایټونه 0x00B00000
#تعریف_کړه IMAGE_SCN_ALIGN_2048_بایټونه 0x00C00000
#تعریف_کړه IMAGE_SCN_ALIGN_4096_بایټونه 0x00D00000
#تعریف_کړه IMAGE_SCN_ALIGN_8192_بایټونه 0x00E00000

#تعریف_کړه IMAGE_SCN_ALIGN_ماسک 0x00F00000

#تعریف_کړه IMAGE_SCN_LNK_NRELOC_OVFL 0x01000000
#تعریف_کړه IMAGE_SCN_MEM_DISCARDABLE 0x02000000
#تعریف_کړه IMAGE_SCN_MEM_NOT_CACHED 0x04000000
#تعریف_کړه IMAGE_SCN_MEM_NOT_PAGED 0x08000000
#تعریف_کړه IMAGE_SCN_MEM_SHARED 0x10000000
#تعریف_کړه IMAGE_SCN_MEM_EXECUTE 0x20000000
#تعریف_کړه IMAGE_SCN_MEM_READ 0x40000000
#تعریف_کړه IMAGE_SCN_MEM_WRITE 0x80000000

#تعریف_کړه IMAGE_SCN_SCALE_شاخص 0x00000001

#ضمن "pshpack2.h"

    تعريفنوع بنية IMAGE_نښه {
      اتحاد {
	BYTE ShortName[8];
	بنية {
	  DWORD Short;
	  DWORD Long;
	} Name;
	DWORD LongName[2];
      } N;
      DWORD ارزښت_3;
      SHORT Section_شمېره;
      کلمه_3 Type;
      BYTE StorageClass;
      BYTE شمېره_د_Aux_Symbols;
    } IMAGE_نښه_2;
    تعريفنوع IMAGE_نښه_2 UNALIGNED *PIMAGE_نښه;

#تعریف_کړه IMAGE_SIZEOF_نښه 18

#تعریف_کړه IMAGE_SYM_UNDEFINED (SHORT)0
#تعریف_کړه IMAGE_SYM_ABSOLUTE (SHORT)-1
#تعریف_کړه IMAGE_SYM_DEBUG (SHORT)-2
#تعریف_کړه IMAGE_SYM_SECTION_MAX 0xFEFF

#تعریف_کړه IMAGE_SYM_TYPE_NULL 0x0000
#تعریف_کړه IMAGE_SYM_TYPE_VOID 0x0001
#تعریف_کړه IMAGE_SYM_TYPE_CHAR 0x0002
#تعریف_کړه IMAGE_SYM_TYPE_SHORT 0x0003
#تعریف_کړه IMAGE_SYM_TYPE_INT 0x0004
#تعریف_کړه IMAGE_SYM_TYPE_LONG 0x0005
#تعریف_کړه IMAGE_SYM_TYPE_FLOAT 0x0006
#تعریف_کړه IMAGE_SYM_TYPE_DOUBLE 0x0007
#تعریف_کړه IMAGE_SYM_TYPE_STRUCT 0x0008
#تعریف_کړه IMAGE_SYM_TYPE_UNION 0x0009
#تعریف_کړه IMAGE_SYM_TYPE_ENUM 0x000A
#تعریف_کړه IMAGE_SYM_TYPE_MOE 0x000B
#تعریف_کړه IMAGE_SYM_TYPE_BYTE 0x000C
#تعریف_کړه IMAGE_SYM_TYPE_کلمه 0x000D
#تعریف_کړه IMAGE_SYM_TYPE_UINT 0x000E
#تعریف_کړه IMAGE_SYM_TYPE_DWORD 0x000F
#تعریف_کړه IMAGE_SYM_TYPE_PCODE 0x8000

#تعریف_کړه IMAGE_SYM_DTYPE_NULL 0
#تعریف_کړه IMAGE_SYM_DTYPE_اشاره_ګر 1
#تعریف_کړه IMAGE_SYM_DTYPE_FUNCTION 2
#تعریف_کړه IMAGE_SYM_DTYPE_ARRAY 3

#تعریف_کړه IMAGE_SYM_CLASS_پای_ټکی_د_FUNCTION (BYTE)-1
#تعریف_کړه IMAGE_SYM_CLASS_NULL 0x0000
#تعریف_کړه IMAGE_SYM_CLASS_AUTOMATIC 0x0001
#تعریف_کړه IMAGE_SYM_CLASS_EXTERNAL 0x0002
#تعریف_کړه IMAGE_SYM_CLASS_STATIC 0x0003
#تعریف_کړه IMAGE_SYM_CLASS_ثبتوونکی 0x0004
#تعریف_کړه IMAGE_SYM_CLASS_EXTERNAL_DEF 0x0005
#تعریف_کړه IMAGE_SYM_CLASS_LABEL 0x0006
#تعریف_کړه IMAGE_SYM_CLASS_UNDEFINED_LABEL 0x0007
#تعریف_کړه IMAGE_SYM_CLASS_MEMBER_د_STRUCT 0x0008
#تعریف_کړه IMAGE_SYM_CLASS_دلیل 0x0009
#تعریف_کړه IMAGE_SYM_CLASS_STRUCT_نښان 0x000A
#تعریف_کړه IMAGE_SYM_CLASS_MEMBER_د_UNION 0x000B
#تعریف_کړه IMAGE_SYM_CLASS_UNION_نښان 0x000C
#تعریف_کړه IMAGE_SYM_CLASS_TYPE_DEFINITION 0x000D
#تعریف_کړه IMAGE_SYM_CLASS_UNDEFINED_STATIC 0x000E
#تعریف_کړه IMAGE_SYM_CLASS_ENUM_نښان 0x000F
#تعریف_کړه IMAGE_SYM_CLASS_MEMBER_د_ENUM 0x0010
#تعریف_کړه IMAGE_SYM_CLASS_ثبتوونکی_PARAM 0x0011
#تعریف_کړه IMAGE_SYM_CLASS_بټ_ډګر 0x0012
#تعریف_کړه IMAGE_SYM_CLASS_FAR_EXTERNAL 0x0044
#تعریف_کړه IMAGE_SYM_CLASS_بلاک 0x0064
#تعریف_کړه IMAGE_SYM_CLASS_FUNCTION 0x0065
#تعریف_کړه IMAGE_SYM_CLASS_پای_ټکی_د_STRUCT 0x0066
#تعریف_کړه IMAGE_SYM_CLASS_FILE 0x0067
#تعریف_کړه IMAGE_SYM_CLASS_SECTION 0x0068
#تعریف_کړه IMAGE_SYM_CLASS_WEAK_EXTERNAL 0x0069
#تعریف_کړه IMAGE_SYM_CLASS_CLR_TOKEN 0x006B

#تعریف_کړه N_BTMASK 0x000F
#تعریف_کړه N_TMASK 0x0030
#تعریف_کړه N_TMASK1 0x00C0
#تعریف_کړه N_TMASK2 0x00F0
#تعریف_کړه N_BTSHFT 4
#تعریف_کړه N_TSHIFT 2

#تعریف_کړه BTYPE(x) ((x) & N_BTMASK)

#که_نه_تعریف_شوی ISPTR
#تعریف_کړه ISPTR(x) (((x) & N_TMASK)==(IMAGE_SYM_DTYPE_اشاره_ګر << N_BTSHFT))
#د_که_پای

#که_نه_تعریف_شوی ISFCN
#تعریف_کړه ISFCN(x) (((x) & N_TMASK)==(IMAGE_SYM_DTYPE_FUNCTION << N_BTSHFT))
#د_که_پای

#که_نه_تعریف_شوی ISARY
#تعریف_کړه ISARY(x) (((x) & N_TMASK)==(IMAGE_SYM_DTYPE_ARRAY << N_BTSHFT))
#د_که_پای

#که_نه_تعریف_شوی ISTAG
#تعریف_کړه ISTAG(x) ((x)==IMAGE_SYM_CLASS_STRUCT_نښان || (x)==IMAGE_SYM_CLASS_UNION_نښان || (x)==IMAGE_SYM_CLASS_ENUM_نښان)
#د_که_پای

#که_نه_تعریف_شوی INCREF
#تعریف_کړه INCREF(x) ((((x)&~N_BTMASK)<<N_TSHIFT)|(IMAGE_SYM_DTYPE_اشاره_ګر<<N_BTSHFT)|((x)&N_BTMASK))
#د_که_پای
#که_نه_تعریف_شوی DECREF
#تعریف_کړه DECREF(x) ((((x)>>N_TSHIFT)&~N_BTMASK)|((x)&N_BTMASK))
#د_که_پای

    تعريفنوع اتحاد IMAGE_AUX_نښه {
      بنية {
	DWORD نښان_شاخص;
	اتحاد {
	  بنية {
	    کلمه_3 Linenumber;
	    کلمه_3 اندازه_3;
	  } LnSz;
	  DWORD ټول_اندازه;
	} Misc;
	اتحاد {
	  بنية {
	    DWORD اشاره_ګر_منزل_Linenumber;
	    DWORD اشاره_ګر_منزل_بل_Function;
	  } Function;
	  بنية {
	    کلمه_3 Dimension[4];
	  } Array;
	} FcnAry;
	کلمه_3 Tv_شاخص;
      } Sym;
      بنية {
	BYTE Name[IMAGE_SIZEOF_نښه];
      } File;
      بنية {
	DWORD اوږدتیا_2;
	کلمه_3 شمېره_د_Relocations;
	کلمه_3 شمېره_د_Linenumbers;
	DWORD Check_مجموعه;
	SHORT شمېره_2;
	BYTE Selection;
      } Section;
    } IMAGE_AUX_نښه_2;
    تعريفنوع IMAGE_AUX_نښه_2 UNALIGNED *PIMAGE_AUX_نښه;

#تعریف_کړه IMAGE_SIZEOF_AUX_نښه 18

    تعريفنوع تعداد IMAGE_AUX_نښه_TYPE {
      IMAGE_AUX_نښه_TYPE_TOKEN_DEF = 1
    } IMAGE_AUX_نښه_TYPE;

#ضمن <pshpack2.h>

    تعريفنوع بنية IMAGE_AUX_نښه_TOKEN_DEF {
      BYTE bAuxType;
      BYTE bReserved;
      DWORD نښه_جدول_شاخص;
      BYTE rgbReserved[12];
    } IMAGE_AUX_نښه_TOKEN_DEF;

    تعريفنوع IMAGE_AUX_نښه_TOKEN_DEF UNALIGNED *PIMAGE_AUX_نښه_TOKEN_DEF;

#ضمن <poppack.h>

#تعریف_کړه IMAGE_COMDAT_SELECT_NODUPLICATES 1
#تعریف_کړه IMAGE_COMDAT_SELECT_ANY 2
#تعریف_کړه IMAGE_COMDAT_SELECT_SAME_اندازه 3
#تعریف_کړه IMAGE_COMDAT_SELECT_EXACT_سمون 4
#تعریف_کړه IMAGE_COMDAT_SELECT_ASSOCIATIVE 5
#تعریف_کړه IMAGE_COMDAT_SELECT_تر_ټولو_لوی 6
#تعریف_کړه IMAGE_COMDAT_SELECT_NEWEST 7

#تعریف_کړه IMAGE_WEAK_EXTERN_پلټنه_NOLIBRARY 1
#تعریف_کړه IMAGE_WEAK_EXTERN_پلټنه_LIBRARY 2
#تعریف_کړه IMAGE_WEAK_EXTERN_پلټنه_ALIAS 3

    تعريفنوع بنية _IMAGE_RELOCATION {
      اتحاد {
	DWORD Virtual_پته;
	DWORD Reloc_شمېر;
      };
      DWORD نښه_جدول_شاخص;
      کلمه_3 Type;
    } IMAGE_RELOCATION;
    تعريفنوع IMAGE_RELOCATION UNALIGNED *PIMAGE_RELOCATION;

#تعریف_کړه IMAGE_SIZEOF_RELOCATION 10

#تعریف_کړه IMAGE_REL_I386_ABSOLUTE 0x0000
#تعریف_کړه IMAGE_REL_I386_DIR16 0x0001
#تعریف_کړه IMAGE_REL_I386_REL16 0x0002
#تعریف_کړه IMAGE_REL_I386_DIR32 0x0006
#تعریف_کړه IMAGE_REL_I386_DIR32NB 0x0007
#تعریف_کړه IMAGE_REL_I386_SEG12 0x0009
#تعریف_کړه IMAGE_REL_I386_SECTION 0x000A
#تعریف_کړه IMAGE_REL_I386_SECREL 0x000B
#تعریف_کړه IMAGE_REL_I386_TOKEN 0x000C
#تعریف_کړه IMAGE_REL_I386_SECREL7 0x000D
#تعریف_کړه IMAGE_REL_I386_REL32 0x0014

#تعریف_کړه IMAGE_REL_MIPS_ABSOLUTE 0x0000
#تعریف_کړه IMAGE_REL_MIPS_REFHALF 0x0001
#تعریف_کړه IMAGE_REL_MIPS_REFWORD 0x0002
#تعریف_کړه IMAGE_REL_MIPS_JMPADDR 0x0003
#تعریف_کړه IMAGE_REL_MIPS_REFHI 0x0004
#تعریف_کړه IMAGE_REL_MIPS_REFLO 0x0005
#تعریف_کړه IMAGE_REL_MIPS_GPREL 0x0006
#تعریف_کړه IMAGE_REL_MIPS_LITERAL 0x0007
#تعریف_کړه IMAGE_REL_MIPS_SECTION 0x000A
#تعریف_کړه IMAGE_REL_MIPS_SECREL 0x000B
#تعریف_کړه IMAGE_REL_MIPS_SECRELLO 0x000C
#تعریف_کړه IMAGE_REL_MIPS_SECRELHI 0x000D
#تعریف_کړه IMAGE_REL_MIPS_TOKEN 0x000E
#تعریف_کړه IMAGE_REL_MIPS_JMPADDR16 0x0010
#تعریف_کړه IMAGE_REL_MIPS_REFWORDNB 0x0022
#تعریف_کړه IMAGE_REL_MIPS_PAIR 0x0025

#تعریف_کړه IMAGE_REL_ALPHA_ABSOLUTE 0x0000
#تعریف_کړه IMAGE_REL_ALPHA_REFLONG 0x0001
#تعریف_کړه IMAGE_REL_ALPHA_REFQUAD 0x0002
#تعریف_کړه IMAGE_REL_ALPHA_GPREL32 0x0003
#تعریف_کړه IMAGE_REL_ALPHA_LITERAL 0x0004
#تعریف_کړه IMAGE_REL_ALPHA_LITUSE 0x0005
#تعریف_کړه IMAGE_REL_ALPHA_GPDISP 0x0006
#تعریف_کړه IMAGE_REL_ALPHA_BRADDR 0x0007
#تعریف_کړه IMAGE_REL_ALPHA_HINT 0x0008
#تعریف_کړه IMAGE_REL_ALPHA_INLINE_REFLONG 0x0009
#تعریف_کړه IMAGE_REL_ALPHA_REFHI 0x000A
#تعریف_کړه IMAGE_REL_ALPHA_REFLO 0x000B
#تعریف_کړه IMAGE_REL_ALPHA_PAIR 0x000C
#تعریف_کړه IMAGE_REL_ALPHA_سمون 0x000D
#تعریف_کړه IMAGE_REL_ALPHA_SECTION 0x000E
#تعریف_کړه IMAGE_REL_ALPHA_SECREL 0x000F
#تعریف_کړه IMAGE_REL_ALPHA_REFLONGNB 0x0010
#تعریف_کړه IMAGE_REL_ALPHA_SECRELLO 0x0011
#تعریف_کړه IMAGE_REL_ALPHA_SECRELHI 0x0012
#تعریف_کړه IMAGE_REL_ALPHA_REFQ3 0x0013
#تعریف_کړه IMAGE_REL_ALPHA_REFQ2 0x0014
#تعریف_کړه IMAGE_REL_ALPHA_REFQ1 0x0015
#تعریف_کړه IMAGE_REL_ALPHA_GPRELLO 0x0016
#تعریف_کړه IMAGE_REL_ALPHA_GPRELHI 0x0017

#تعریف_کړه IMAGE_REL_PPC_ABSOLUTE 0x0000
#تعریف_کړه IMAGE_REL_PPC_ADDR64 0x0001
#تعریف_کړه IMAGE_REL_PPC_ADDR32 0x0002
#تعریف_کړه IMAGE_REL_PPC_ADDR24 0x0003
#تعریف_کړه IMAGE_REL_PPC_ADDR16 0x0004
#تعریف_کړه IMAGE_REL_PPC_ADDR14 0x0005
#تعریف_کړه IMAGE_REL_PPC_REL24 0x0006
#تعریف_کړه IMAGE_REL_PPC_REL14 0x0007
#تعریف_کړه IMAGE_REL_PPC_TOCREL16 0x0008
#تعریف_کړه IMAGE_REL_PPC_TOCREL14 0x0009
#تعریف_کړه IMAGE_REL_PPC_ADDR32NB 0x000A
#تعریف_کړه IMAGE_REL_PPC_SECREL 0x000B
#تعریف_کړه IMAGE_REL_PPC_SECTION 0x000C
#تعریف_کړه IMAGE_REL_PPC_IFGLUE 0x000D
#تعریف_کړه IMAGE_REL_PPC_IMGLUE 0x000E
#تعریف_کړه IMAGE_REL_PPC_SECREL16 0x000F
#تعریف_کړه IMAGE_REL_PPC_REFHI 0x0010
#تعریف_کړه IMAGE_REL_PPC_REFLO 0x0011
#تعریف_کړه IMAGE_REL_PPC_PAIR 0x0012
#تعریف_کړه IMAGE_REL_PPC_SECRELLO 0x0013
#تعریف_کړه IMAGE_REL_PPC_SECRELHI 0x0014
#تعریف_کړه IMAGE_REL_PPC_GPREL 0x0015
#تعریف_کړه IMAGE_REL_PPC_TOKEN 0x0016
#تعریف_کړه IMAGE_REL_PPC_TYPEMASK 0x00FF
#تعریف_کړه IMAGE_REL_PPC_NEG 0x0100
#تعریف_کړه IMAGE_REL_PPC_BRTAKEN 0x0200
#تعریف_کړه IMAGE_REL_PPC_BRNTAKEN 0x0400
#تعریف_کړه IMAGE_REL_PPC_TOCDEFN 0x0800

#تعریف_کړه IMAGE_REL_SH3_ABSOLUTE 0x0000
#تعریف_کړه IMAGE_REL_SH3_DIRECT16 0x0001
#تعریف_کړه IMAGE_REL_SH3_DIRECT32 0x0002
#تعریف_کړه IMAGE_REL_SH3_DIRECT8 0x0003
#تعریف_کړه IMAGE_REL_SH3_DIRECT8_کلمه 0x0004
#تعریف_کړه IMAGE_REL_SH3_DIRECT8_LONG 0x0005
#تعریف_کړه IMAGE_REL_SH3_DIRECT4 0x0006
#تعریف_کړه IMAGE_REL_SH3_DIRECT4_کلمه 0x0007
#تعریف_کړه IMAGE_REL_SH3_DIRECT4_LONG 0x0008
#تعریف_کړه IMAGE_REL_SH3_PCREL8_کلمه 0x0009
#تعریف_کړه IMAGE_REL_SH3_PCREL8_LONG 0x000A
#تعریف_کړه IMAGE_REL_SH3_PCREL12_کلمه 0x000B
#تعریف_کړه IMAGE_REL_SH3_STARTOF_SECTION 0x000C
#تعریف_کړه IMAGE_REL_SH3_SIZEOF_SECTION 0x000D
#تعریف_کړه IMAGE_REL_SH3_SECTION 0x000E
#تعریف_کړه IMAGE_REL_SH3_SECREL 0x000F
#تعریف_کړه IMAGE_REL_SH3_DIRECT32_NB 0x0010
#تعریف_کړه IMAGE_REL_SH3_GPREL4_LONG 0x0011
#تعریف_کړه IMAGE_REL_SH3_TOKEN 0x0012

#تعریف_کړه IMAGE_REL_SHM_PCRELPT 0x0013
#تعریف_کړه IMAGE_REL_SHM_REFLO 0x0014
#تعریف_کړه IMAGE_REL_SHM_REFHALF 0x0015
#تعریف_کړه IMAGE_REL_SHM_RELLO 0x0016
#تعریف_کړه IMAGE_REL_SHM_RELHALF 0x0017
#تعریف_کړه IMAGE_REL_SHM_PAIR 0x0018

#تعریف_کړه IMAGE_REL_SH_NOMODE 0x8000

#تعریف_کړه IMAGE_REL_ARM_ABSOLUTE 0x0000
#تعریف_کړه IMAGE_REL_ARM_ADDR32 0x0001
#تعریف_کړه IMAGE_REL_ARM_ADDR32NB 0x0002
#تعریف_کړه IMAGE_REL_ARM_BRANCH24 0x0003
#تعریف_کړه IMAGE_REL_ARM_BRANCH11 0x0004
#تعریف_کړه IMAGE_REL_ARM_TOKEN 0x0005
#تعریف_کړه IMAGE_REL_ARM_GPREL12 0x0006
#تعریف_کړه IMAGE_REL_ARM_GPREL7 0x0007
#تعریف_کړه IMAGE_REL_ARM_BLX24 0x0008
#تعریف_کړه IMAGE_REL_ARM_BLX11 0x0009
#تعریف_کړه IMAGE_REL_ARM_SECTION 0x000E
#تعریف_کړه IMAGE_REL_ARM_SECREL 0x000F

#تعریف_کړه IMAGE_REL_AM_ABSOLUTE 0x0000
#تعریف_کړه IMAGE_REL_AM_ADDR32 0x0001
#تعریف_کړه IMAGE_REL_AM_ADDR32NB 0x0002
#تعریف_کړه IMAGE_REL_AM_CALL32 0x0003
#تعریف_کړه IMAGE_REL_AM_FUNCINFO 0x0004
#تعریف_کړه IMAGE_REL_AM_REL32_1 0x0005
#تعریف_کړه IMAGE_REL_AM_REL32_2 0x0006
#تعریف_کړه IMAGE_REL_AM_SECREL 0x0007
#تعریف_کړه IMAGE_REL_AM_SECTION 0x0008
#تعریف_کړه IMAGE_REL_AM_TOKEN 0x0009

#تعریف_کړه IMAGE_REL_AMD64_ABSOLUTE 0x0000
#تعریف_کړه IMAGE_REL_AMD64_ADDR64 0x0001
#تعریف_کړه IMAGE_REL_AMD64_ADDR32 0x0002
#تعریف_کړه IMAGE_REL_AMD64_ADDR32NB 0x0003
#تعریف_کړه IMAGE_REL_AMD64_REL32 0x0004
#تعریف_کړه IMAGE_REL_AMD64_REL32_1 0x0005
#تعریف_کړه IMAGE_REL_AMD64_REL32_2 0x0006
#تعریف_کړه IMAGE_REL_AMD64_REL32_3 0x0007
#تعریف_کړه IMAGE_REL_AMD64_REL32_4 0x0008
#تعریف_کړه IMAGE_REL_AMD64_REL32_5 0x0009
#تعریف_کړه IMAGE_REL_AMD64_SECTION 0x000A
#تعریف_کړه IMAGE_REL_AMD64_SECREL 0x000B
#تعریف_کړه IMAGE_REL_AMD64_SECREL7 0x000C
#تعریف_کړه IMAGE_REL_AMD64_TOKEN 0x000D
#تعریف_کړه IMAGE_REL_AMD64_SREL32 0x000E
#تعریف_کړه IMAGE_REL_AMD64_PAIR 0x000F
#تعریف_کړه IMAGE_REL_AMD64_SSPAN32 0x0010

#تعریف_کړه IMAGE_REL_IA64_ABSOLUTE 0x0000
#تعریف_کړه IMAGE_REL_IA64_IMM14 0x0001
#تعریف_کړه IMAGE_REL_IA64_IMM22 0x0002
#تعریف_کړه IMAGE_REL_IA64_IMM64 0x0003
#تعریف_کړه IMAGE_REL_IA64_DIR32 0x0004
#تعریف_کړه IMAGE_REL_IA64_DIR64 0x0005
#تعریف_کړه IMAGE_REL_IA64_PCREL21B 0x0006
#تعریف_کړه IMAGE_REL_IA64_PCREL21M 0x0007
#تعریف_کړه IMAGE_REL_IA64_PCREL21F 0x0008
#تعریف_کړه IMAGE_REL_IA64_GPREL22 0x0009
#تعریف_کړه IMAGE_REL_IA64_LTOFF22 0x000A
#تعریف_کړه IMAGE_REL_IA64_SECTION 0x000B
#تعریف_کړه IMAGE_REL_IA64_SECREL22 0x000C
#تعریف_کړه IMAGE_REL_IA64_SECREL64I 0x000D
#تعریف_کړه IMAGE_REL_IA64_SECREL32 0x000E

#تعریف_کړه IMAGE_REL_IA64_DIR32NB 0x0010
#تعریف_کړه IMAGE_REL_IA64_SREL14 0x0011
#تعریف_کړه IMAGE_REL_IA64_SREL22 0x0012
#تعریف_کړه IMAGE_REL_IA64_SREL32 0x0013
#تعریف_کړه IMAGE_REL_IA64_UREL32 0x0014
#تعریف_کړه IMAGE_REL_IA64_PCREL60X 0x0015
#تعریف_کړه IMAGE_REL_IA64_PCREL60B 0x0016
#تعریف_کړه IMAGE_REL_IA64_PCREL60F 0x0017
#تعریف_کړه IMAGE_REL_IA64_PCREL60I 0x0018
#تعریف_کړه IMAGE_REL_IA64_PCREL60M 0x0019
#تعریف_کړه IMAGE_REL_IA64_IMMGPREL64 0x001A
#تعریف_کړه IMAGE_REL_IA64_TOKEN 0x001B
#تعریف_کړه IMAGE_REL_IA64_GPREL32 0x001C
#تعریف_کړه IMAGE_REL_IA64_ADDEND 0x001F

#تعریف_کړه IMAGE_REL_CEF_ABSOLUTE 0x0000
#تعریف_کړه IMAGE_REL_CEF_ADDR32 0x0001
#تعریف_کړه IMAGE_REL_CEF_ADDR64 0x0002
#تعریف_کړه IMAGE_REL_CEF_ADDR32NB 0x0003
#تعریف_کړه IMAGE_REL_CEF_SECTION 0x0004
#تعریف_کړه IMAGE_REL_CEF_SECREL 0x0005
#تعریف_کړه IMAGE_REL_CEF_TOKEN 0x0006

#تعریف_کړه IMAGE_REL_CEE_ABSOLUTE 0x0000
#تعریف_کړه IMAGE_REL_CEE_ADDR32 0x0001
#تعریف_کړه IMAGE_REL_CEE_ADDR64 0x0002
#تعریف_کړه IMAGE_REL_CEE_ADDR32NB 0x0003
#تعریف_کړه IMAGE_REL_CEE_SECTION 0x0004
#تعریف_کړه IMAGE_REL_CEE_SECREL 0x0005
#تعریف_کړه IMAGE_REL_CEE_TOKEN 0x0006

#تعریف_کړه IMAGE_REL_M32R_ABSOLUTE 0x0000
#تعریف_کړه IMAGE_REL_M32R_ADDR32 0x0001
#تعریف_کړه IMAGE_REL_M32R_ADDR32NB 0x0002
#تعریف_کړه IMAGE_REL_M32R_ADDR24 0x0003
#تعریف_کړه IMAGE_REL_M32R_GPREL16 0x0004
#تعریف_کړه IMAGE_REL_M32R_PCREL24 0x0005
#تعریف_کړه IMAGE_REL_M32R_PCREL16 0x0006
#تعریف_کړه IMAGE_REL_M32R_PCREL8 0x0007
#تعریف_کړه IMAGE_REL_M32R_REFHALF 0x0008
#تعریف_کړه IMAGE_REL_M32R_REFHI 0x0009
#تعریف_کړه IMAGE_REL_M32R_REFLO 0x000A
#تعریف_کړه IMAGE_REL_M32R_PAIR 0x000B
#تعریف_کړه IMAGE_REL_M32R_SECTION 0x000C
#تعریف_کړه IMAGE_REL_M32R_SECREL32 0x000D
#تعریف_کړه IMAGE_REL_M32R_TOKEN 0x000E

#تعریف_کړه EXT_IMM64(ارزښت_3,پته_2,اندازه_3,InstPos,ValPos) ارزښت_3 |= (((ULONGLONG)((*(پته_2) >> InstPos) & (((ULONGLONG)1 << اندازه_3) - 1))) << ValPos)
#تعریف_کړه INS_IMM64(ارزښت_3,پته_2,اندازه_3,InstPos,ValPos) *(PDWORD)پته_2 = (*(PDWORD)پته_2 & ~(((1 << اندازه_3) - 1) << InstPos)) | ((DWORD)((((ULONGLONG)ارزښت_3 >> ValPos) & (((ULONGLONG)1 << اندازه_3) - 1))) << InstPos)

#تعریف_کړه EMARCH_ENC_I17_IMM7_B_INST_کلمه_X 3
#تعریف_کړه EMARCH_ENC_I17_IMM7_B_اندازه_X 7
#تعریف_کړه EMARCH_ENC_I17_IMM7_B_INST_کلمه_POS_X 4
#تعریف_کړه EMARCH_ENC_I17_IMM7B_VAL_POS_X 0

#تعریف_کړه EMARCH_ENC_I17_IMM9_D_INST_کلمه_X 3
#تعریف_کړه EMARCH_ENC_I17_IMM9_D_اندازه_X 9
#تعریف_کړه EMARCH_ENC_I17_IMM9_D_INST_کلمه_POS_X 18
#تعریف_کړه EMARCH_ENC_I17_IMM9D_VAL_POS_X 7

#تعریف_کړه EMARCH_ENC_I17_IMM5_C_INST_کلمه_X 3
#تعریف_کړه EMARCH_ENC_I17_IMM5_C_اندازه_X 5
#تعریف_کړه EMARCH_ENC_I17_IMM5_C_INST_کلمه_POS_X 13
#تعریف_کړه EMARCH_ENC_I17_IMM5C_VAL_POS_X 16

#تعریف_کړه EMARCH_ENC_I17_IC_INST_کلمه_X 3
#تعریف_کړه EMARCH_ENC_I17_IC_اندازه_X 1
#تعریف_کړه EMARCH_ENC_I17_IC_INST_کلمه_POS_X 12
#تعریف_کړه EMARCH_ENC_I17_IC_VAL_POS_X 21

#تعریف_کړه EMARCH_ENC_I17_IMM41a_INST_کلمه_X 1
#تعریف_کړه EMARCH_ENC_I17_IMM41a_اندازه_X 10
#تعریف_کړه EMARCH_ENC_I17_IMM41a_INST_کلمه_POS_X 14
#تعریف_کړه EMARCH_ENC_I17_IMM41a_VAL_POS_X 22

#تعریف_کړه EMARCH_ENC_I17_IMM41b_INST_کلمه_X 1
#تعریف_کړه EMARCH_ENC_I17_IMM41b_اندازه_X 8
#تعریف_کړه EMARCH_ENC_I17_IMM41b_INST_کلمه_POS_X 24
#تعریف_کړه EMARCH_ENC_I17_IMM41b_VAL_POS_X 32

#تعریف_کړه EMARCH_ENC_I17_IMM41c_INST_کلمه_X 2
#تعریف_کړه EMARCH_ENC_I17_IMM41c_اندازه_X 23
#تعریف_کړه EMARCH_ENC_I17_IMM41c_INST_کلمه_POS_X 0
#تعریف_کړه EMARCH_ENC_I17_IMM41c_VAL_POS_X 40

#تعریف_کړه EMARCH_ENC_I17_SIGN_INST_کلمه_X 3
#تعریف_کړه EMARCH_ENC_I17_SIGN_اندازه_X 1
#تعریف_کړه EMARCH_ENC_I17_SIGN_INST_کلمه_POS_X 27
#تعریف_کړه EMARCH_ENC_I17_SIGN_VAL_POS_X 63

#تعریف_کړه X3_OPCODE_INST_کلمه_X 3
#تعریف_کړه X3_OPCODE_اندازه_X 4
#تعریف_کړه X3_OPCODE_INST_کلمه_POS_X 28
#تعریف_کړه X3_OPCODE_SIGN_VAL_POS_X 0

#تعریف_کړه X3_I_INST_کلمه_X 3
#تعریف_کړه X3_I_اندازه_X 1
#تعریف_کړه X3_I_INST_کلمه_POS_X 27
#تعریف_کړه X3_I_SIGN_VAL_POS_X 59

#تعریف_کړه X3_D_WH_INST_کلمه_X 3
#تعریف_کړه X3_D_WH_اندازه_X 3
#تعریف_کړه X3_D_WH_INST_کلمه_POS_X 24
#تعریف_کړه X3_D_WH_SIGN_VAL_POS_X 0

#تعریف_کړه X3_IMM20_INST_کلمه_X 3
#تعریف_کړه X3_IMM20_اندازه_X 20
#تعریف_کړه X3_IMM20_INST_کلمه_POS_X 4
#تعریف_کړه X3_IMM20_SIGN_VAL_POS_X 0

#تعریف_کړه X3_IMM39_1_INST_کلمه_X 2
#تعریف_کړه X3_IMM39_1_اندازه_X 23
#تعریف_کړه X3_IMM39_1_INST_کلمه_POS_X 0
#تعریف_کړه X3_IMM39_1_SIGN_VAL_POS_X 36

#تعریف_کړه X3_IMM39_2_INST_کلمه_X 1
#تعریف_کړه X3_IMM39_2_اندازه_X 16
#تعریف_کړه X3_IMM39_2_INST_کلمه_POS_X 16
#تعریف_کړه X3_IMM39_2_SIGN_VAL_POS_X 20

#تعریف_کړه X3_P_INST_کلمه_X 3
#تعریف_کړه X3_P_اندازه_X 4
#تعریف_کړه X3_P_INST_کلمه_POS_X 0
#تعریف_کړه X3_P_SIGN_VAL_POS_X 0

#تعریف_کړه X3_TMPLT_INST_کلمه_X 0
#تعریف_کړه X3_TMPLT_اندازه_X 4
#تعریف_کړه X3_TMPLT_INST_کلمه_POS_X 0
#تعریف_کړه X3_TMPLT_SIGN_VAL_POS_X 0

#تعریف_کړه X3_BTYPE_QP_INST_کلمه_X 2
#تعریف_کړه X3_BTYPE_QP_اندازه_X 9
#تعریف_کړه X3_BTYPE_QP_INST_کلمه_POS_X 23
#تعریف_کړه X3_BTYPE_QP_INST_VAL_POS_X 0

#تعریف_کړه X3_تشه_INST_کلمه_X 1
#تعریف_کړه X3_تشه_اندازه_X 2
#تعریف_کړه X3_تشه_INST_کلمه_POS_X 14
#تعریف_کړه X3_تشه_INST_VAL_POS_X 0

    تعريفنوع بنية _IMAGE_LINENUMBER {
      اتحاد {
	DWORD نښه_جدول_شاخص;
	DWORD Virtual_پته;
      } Type;
      کلمه_3 Linenumber;
    } IMAGE_LINENUMBER;
    تعريفنوع IMAGE_LINENUMBER UNALIGNED *PIMAGE_LINENUMBER;

#تعریف_کړه IMAGE_SIZEOF_LINENUMBER 6

#ضمن "poppack.h"

    تعريفنوع بنية IMAGE_بنسټ_RELOCATION {
      DWORD Virtual_پته;
      DWORD اندازه_د_بلاک;

    } IMAGE_بنسټ_RELOCATION_2;
    تعريفنوع IMAGE_بنسټ_RELOCATION_2 UNALIGNED *PIMAGE_بنسټ_RELOCATION;

#تعریف_کړه IMAGE_SIZEOF_بنسټ_RELOCATION 8

#تعریف_کړه IMAGE_REL_BASED_ABSOLUTE 0
#تعریف_کړه IMAGE_REL_BASED_لوړ 1
#تعریف_کړه IMAGE_REL_BASED_ټیټ 2
#تعریف_کړه IMAGE_REL_BASED_HIGHLOW 3
#تعریف_کړه IMAGE_REL_BASED_HIGHADJ 4
#تعریف_کړه IMAGE_REL_BASED_MIPS_JMPADDR 5
#تعریف_کړه IMAGE_REL_BASED_MIPS_JMPADDR16 9
#تعریف_کړه IMAGE_REL_BASED_IA64_IMM64 9
#تعریف_کړه IMAGE_REL_BASED_DIR64 10

#تعریف_کړه IMAGE_ARCHIVE_پیل_اندازه 8
#تعریف_کړه IMAGE_ARCHIVE_پیل "!<arch>\n"
#تعریف_کړه IMAGE_ARCHIVE_پای_ټکی "`\n"
#تعریف_کړه IMAGE_ARCHIVE_PAD "\n"
#تعریف_کړه IMAGE_ARCHIVE_LINKER_MEMBER "/               "
#تعریف_کړه IMAGE_ARCHIVE_LONGNAMES_MEMBER "//              "

    تعريفنوع بنية IMAGE_ARCHIVE_MEMBER_سرلیک {
      BYTE Name[16];
      BYTE Date[12];
      BYTE UserID[6];
      BYTE ډله_ID[6];
      BYTE ډېرپېښ_4[8];
      BYTE اندازه_3[10];
      BYTE پای_ټکی_سرلیک[2];
    } IMAGE_ARCHIVE_MEMBER_سرلیک_2,*PIMAGE_ARCHIVE_MEMBER_سرلیک;

#تعریف_کړه IMAGE_SIZEOF_ARCHIVE_MEMBER_HDR 60

    تعريفنوع بنية _IMAGE_EXPORT_DIRECTORY {
      DWORD Characteristics;
      DWORD وخت_Date_Stamp;
      کلمه_3 Major_نسخه;
      کلمه_3 Minor_نسخه;
      DWORD Name;
      DWORD بنسټ_2;
      DWORD شمېره_د_Functions;
      DWORD شمېره_د_نومونه;
      DWORD پته_د_Functions;
      DWORD پته_د_نومونه;
      DWORD پته_د_Name_Ordinals;
    } IMAGE_EXPORT_DIRECTORY,*PIMAGE_EXPORT_DIRECTORY;

    تعريفنوع بنية _IMAGE_IMPORT_BY_NAME {
      کلمه_3 Hint;
      BYTE Name[1];
    } IMAGE_IMPORT_BY_NAME,*PIMAGE_IMPORT_BY_NAME;

#ضمن "pshpack8.h"

    تعريفنوع بنية _IMAGE_THUNK_DATA64 {
      اتحاد {
	ULONGLONG ForwarderString;
	ULONGLONG Function;
	ULONGLONG Ordinal;
	ULONGLONG پته_د_معلومات;
      } u1;
    } IMAGE_THUNK_DATA64;
    تعريفنوع IMAGE_THUNK_DATA64 *PIMAGE_THUNK_DATA64;

#ضمن "poppack.h"

    تعريفنوع بنية _IMAGE_THUNK_DATA32 {
      اتحاد {
	DWORD ForwarderString;
	DWORD Function;
	DWORD Ordinal;
	DWORD پته_د_معلومات;
      } u1;
    } IMAGE_THUNK_DATA32;
    تعريفنوع IMAGE_THUNK_DATA32 *PIMAGE_THUNK_DATA32;

#تعریف_کړه IMAGE_ORDINAL_FLAG64 0x8000000000000000ull
#تعریف_کړه IMAGE_ORDINAL_FLAG32 0x80000000
#تعریف_کړه IMAGE_ORDINAL64(Ordinal) (Ordinal & 0xffffull)
#تعریف_کړه IMAGE_ORDINAL32(Ordinal) (Ordinal & 0xffff)
#تعریف_کړه IMAGE_SNAP_BY_ORDINAL64(Ordinal) ((Ordinal & IMAGE_ORDINAL_FLAG64)!=0)
#تعریف_کړه IMAGE_SNAP_BY_ORDINAL32(Ordinal) ((Ordinal & IMAGE_ORDINAL_FLAG32)!=0)

    تعريفنوع VOID
      (NTAPI *PIMAGE_TLS_CALLBACK)(PVOID DllHandle,DWORD Reason,PVOID Reserved);

    تعريفنوع بنية _IMAGE_TLS_DIRECTORY64 {
      ULONGLONG پیل_پته_د_Raw_معلومات;
      ULONGLONG پای_ټکی_پته_د_Raw_معلومات;
      ULONGLONG پته_د_شاخص;
      ULONGLONG پته_د_Call_Backs;
      DWORD اندازه_د_Zero_Fill;
      DWORD Characteristics;
    } IMAGE_TLS_DIRECTORY64;
    تعريفنوع IMAGE_TLS_DIRECTORY64 *PIMAGE_TLS_DIRECTORY64;

    تعريفنوع بنية _IMAGE_TLS_DIRECTORY32 {
      DWORD پیل_پته_د_Raw_معلومات;
      DWORD پای_ټکی_پته_د_Raw_معلومات;
      DWORD پته_د_شاخص;
      DWORD پته_د_Call_Backs;
      DWORD اندازه_د_Zero_Fill;
      DWORD Characteristics;
    } IMAGE_TLS_DIRECTORY32;
    تعريفنوع IMAGE_TLS_DIRECTORY32 *PIMAGE_TLS_DIRECTORY32;

#که_تعریف_شوی _WIN64
#تعریف_کړه IMAGE_ORDINAL_FLAG IMAGE_ORDINAL_FLAG64
#تعریف_کړه IMAGE_ORDINAL(Ordinal) IMAGE_ORDINAL64(Ordinal)
    تعريفنوع IMAGE_THUNK_DATA64 IMAGE_THUNK_معلومات;
    تعريفنوع PIMAGE_THUNK_DATA64 PIMAGE_THUNK_معلومات;
#تعریف_کړه IMAGE_SNAP_BY_ORDINAL(Ordinal) IMAGE_SNAP_BY_ORDINAL64(Ordinal)
    تعريفنوع IMAGE_TLS_DIRECTORY64 IMAGE_TLS_DIRECTORY;
    تعريفنوع PIMAGE_TLS_DIRECTORY64 PIMAGE_TLS_DIRECTORY;
#وإلا
#تعریف_کړه IMAGE_ORDINAL_FLAG IMAGE_ORDINAL_FLAG32
#تعریف_کړه IMAGE_ORDINAL(Ordinal) IMAGE_ORDINAL32(Ordinal)
    تعريفنوع IMAGE_THUNK_DATA32 IMAGE_THUNK_معلومات;
    تعريفنوع PIMAGE_THUNK_DATA32 PIMAGE_THUNK_معلومات;
#تعریف_کړه IMAGE_SNAP_BY_ORDINAL(Ordinal) IMAGE_SNAP_BY_ORDINAL32(Ordinal)
    تعريفنوع IMAGE_TLS_DIRECTORY32 IMAGE_TLS_DIRECTORY;
    تعريفنوع PIMAGE_TLS_DIRECTORY32 PIMAGE_TLS_DIRECTORY;
#د_که_پای

    تعريفنوع بنية _IMAGE_IMPORT_DESCRIPTOR {
      اتحاد {
	DWORD Characteristics;
	DWORD Original_لومړی_Thunk;
      };
      DWORD وخت_Date_Stamp;

      DWORD ForwarderChain;
      DWORD Name;
      DWORD لومړی_Thunk;
    } IMAGE_IMPORT_DESCRIPTOR;
    تعريفنوع IMAGE_IMPORT_DESCRIPTOR UNALIGNED *PIMAGE_IMPORT_DESCRIPTOR;

    تعريفنوع بنية _IMAGE_BOUND_IMPORT_DESCRIPTOR {
      DWORD وخت_Date_Stamp;
      کلمه_3 دننه_واټن_Module_Name;
      کلمه_3 شمېره_د_Module_Forwarder_Refs;
    } IMAGE_BOUND_IMPORT_DESCRIPTOR,*PIMAGE_BOUND_IMPORT_DESCRIPTOR;

    تعريفنوع بنية _IMAGE_BOUND_FORWARDER_REF {
      DWORD وخت_Date_Stamp;
      کلمه_3 دننه_واټن_Module_Name;
      کلمه_3 Reserved;
    } IMAGE_BOUND_FORWARDER_REF,*PIMAGE_BOUND_FORWARDER_REF;

    تعريفنوع بنية _IMAGE_RESOURCE_DIRECTORY {
      DWORD Characteristics;
      DWORD وخت_Date_Stamp;
      کلمه_3 Major_نسخه;
      کلمه_3 Minor_نسخه;
      کلمه_3 شمېره_د_Named_Entries;
      کلمه_3 شمېره_د_Id_Entries;
    } IMAGE_RESOURCE_DIRECTORY,*PIMAGE_RESOURCE_DIRECTORY;

#تعریف_کړه IMAGE_RESOURCE_NAME_IS_STRING 0x80000000
#تعریف_کړه IMAGE_RESOURCE_معلومات_IS_DIRECTORY 0x80000000

    تعريفنوع بنية IMAGE_RESOURCE_DIRECTORY_ثبت {
      اتحاد {
	بنية {
	  DWORD Name_دننه_واټن:31;
	  DWORD NameIsString:1;
	};
	DWORD Name;
	کلمه_3 Id;
      };
      اتحاد {
	DWORD دننه_واټن_منزل_معلومات;
	بنية {
	  DWORD دننه_واټن_منزل_Directory:31;
	  DWORD معلومات_Is_Directory:1;
	};
      };
    } IMAGE_RESOURCE_DIRECTORY_ثبت_2,*PIMAGE_RESOURCE_DIRECTORY_ثبت;

    تعريفنوع بنية _IMAGE_RESOURCE_DIRECTORY_STRING {
      کلمه_3 اوږدتیا_2;
      CHAR NameString[1];
    } IMAGE_RESOURCE_DIRECTORY_STRING,*PIMAGE_RESOURCE_DIRECTORY_STRING;

    تعريفنوع بنية _IMAGE_RESOURCE_DIR_STRING_U {
      کلمه_3 اوږدتیا_2;
      WCHAR NameString[1];
    } IMAGE_RESOURCE_DIR_STRING_U,*PIMAGE_RESOURCE_DIR_STRING_U;

    تعريفنوع بنية IMAGE_RESOURCE_معلومات_ثبت {
      DWORD دننه_واټن_منزل_معلومات;
      DWORD اندازه_3;
      DWORD کوډ_پاڼه;
      DWORD Reserved;
    } IMAGE_RESOURCE_معلومات_ثبت_2,*PIMAGE_RESOURCE_معلومات_ثبت;

    تعريفنوع بنية {
      DWORD اندازه_3;
      DWORD وخت_Date_Stamp;
      کلمه_3 Major_نسخه;
      کلمه_3 Minor_نسخه;
      DWORD GlobalFlagsClear;
      DWORD Global_Flags_سېټ;
      DWORD CriticalSectionDefaultTimeout;
      DWORD De_Commit_Free_بلاک_پوله;
      DWORD De_Commit_ټول_Free_پوله;
      DWORD قلف_مختاړی_جدول;
      DWORD اعظمي_ویش_اندازه;
      DWORD Virtual_حافظه_پوله;
      DWORD Process_ډېرۍ_Flags;
      DWORD Process_Affinity_ماسک;
      کلمه_3 CSDVersion;
      کلمه_3 Reserved1;
      DWORD EditList;
      DWORD SecurityCookie;
      DWORD SEHandler_جدول;
      DWORD SEHandler_شمېر;
    } IMAGE_بارول_CONFIG_DIRECTORY32,*PIMAGE_بارول_CONFIG_DIRECTORY32;

    تعريفنوع بنية {
      DWORD اندازه_3;
      DWORD وخت_Date_Stamp;
      کلمه_3 Major_نسخه;
      کلمه_3 Minor_نسخه;
      DWORD GlobalFlagsClear;
      DWORD Global_Flags_سېټ;
      DWORD CriticalSectionDefaultTimeout;
      ULONGLONG De_Commit_Free_بلاک_پوله;
      ULONGLONG De_Commit_ټول_Free_پوله;
      ULONGLONG قلف_مختاړی_جدول;
      ULONGLONG اعظمي_ویش_اندازه;
      ULONGLONG Virtual_حافظه_پوله;
      ULONGLONG Process_Affinity_ماسک;
      DWORD Process_ډېرۍ_Flags;
      کلمه_3 CSDVersion;
      کلمه_3 Reserved1;
      ULONGLONG EditList;
      ULONGLONG SecurityCookie;
      ULONGLONG SEHandler_جدول;
      ULONGLONG SEHandler_شمېر;
    } IMAGE_بارول_CONFIG_DIRECTORY64,*PIMAGE_بارول_CONFIG_DIRECTORY64;

#که_تعریف_شوی _WIN64
    تعريفنوع IMAGE_بارول_CONFIG_DIRECTORY64 IMAGE_بارول_CONFIG_DIRECTORY;
    تعريفنوع PIMAGE_بارول_CONFIG_DIRECTORY64 PIMAGE_بارول_CONFIG_DIRECTORY;
#وإلا
    تعريفنوع IMAGE_بارول_CONFIG_DIRECTORY32 IMAGE_بارول_CONFIG_DIRECTORY;
    تعريفنوع PIMAGE_بارول_CONFIG_DIRECTORY32 PIMAGE_بارول_CONFIG_DIRECTORY;
#د_که_پای

    تعريفنوع بنية IMAGE_CE_RUNTIME_FUNCTION_ثبت {
      DWORD Func_پیل;
      DWORD PrologLen : 8;
      DWORD FuncLen : 22;
      DWORD Thirty_Two_بټ : 1;
      DWORD ExceptionFlag : 1;
    } IMAGE_CE_RUNTIME_FUNCTION_ثبت_2,*PIMAGE_CE_RUNTIME_FUNCTION_ثبت;

    تعريفنوع بنية IMAGE_ALPHA64_RUNTIME_FUNCTION_ثبت {
      ULONGLONG Begin_پته;
      ULONGLONG پای_ټکی_پته;
      ULONGLONG ExceptionHandler;
      ULONGLONG Handler_معلومات;
      ULONGLONG Prolog_پای_ټکی_پته;
    } IMAGE_ALPHA64_RUNTIME_FUNCTION_ثبت_2,*PIMAGE_ALPHA64_RUNTIME_FUNCTION_ثبت;

    تعريفنوع بنية IMAGE_ALPHA_RUNTIME_FUNCTION_ثبت {
      DWORD Begin_پته;
      DWORD پای_ټکی_پته;
      DWORD ExceptionHandler;
      DWORD Handler_معلومات;
      DWORD Prolog_پای_ټکی_پته;
    } IMAGE_ALPHA_RUNTIME_FUNCTION_ثبت_2,*PIMAGE_ALPHA_RUNTIME_FUNCTION_ثبت;

    تعريفنوع بنية IMAGE_RUNTIME_FUNCTION_ثبت {
      DWORD Begin_پته;
      DWORD پای_ټکی_پته;
      DWORD Unwind_Info_پته;
    } IMAGE_RUNTIME_FUNCTION_ثبت,*PIMAGE_RUNTIME_FUNCTION_ثبت;

    تعريفنوع IMAGE_RUNTIME_FUNCTION_ثبت IMAGE_IA64_RUNTIME_FUNCTION_ثبت;
    تعريفنوع PIMAGE_RUNTIME_FUNCTION_ثبت PIMAGE_IA64_RUNTIME_FUNCTION_ثبت;

    تعريفنوع IMAGE_RUNTIME_FUNCTION_ثبت IMAGE_RUNTIME_FUNCTION_ثبت_2;
    تعريفنوع PIMAGE_RUNTIME_FUNCTION_ثبت PIMAGE_RUNTIME_FUNCTION_ثبت_2;

    تعريفنوع بنية _IMAGE_DEBUG_DIRECTORY {
      DWORD Characteristics;
      DWORD وخت_Date_Stamp;
      کلمه_3 Major_نسخه;
      کلمه_3 Minor_نسخه;
      DWORD Type;
      DWORD اندازه_د_معلومات;
      DWORD پته_د_Raw_معلومات;
      DWORD اشاره_ګر_منزل_Raw_معلومات;
    } IMAGE_DEBUG_DIRECTORY,*PIMAGE_DEBUG_DIRECTORY;

#تعریف_کړه IMAGE_DEBUG_TYPE_UNKNOWN 0
#تعریف_کړه IMAGE_DEBUG_TYPE_COFF 1
#تعریف_کړه IMAGE_DEBUG_TYPE_CODEVIEW 2
#تعریف_کړه IMAGE_DEBUG_TYPE_FPO 3
#تعریف_کړه IMAGE_DEBUG_TYPE_MISC 4
#تعریف_کړه IMAGE_DEBUG_TYPE_EXCEPTION 5
#تعریف_کړه IMAGE_DEBUG_TYPE_FIXUP 6
#تعریف_کړه IMAGE_DEBUG_TYPE_OMAP_منزل_SRC 7
#تعریف_کړه IMAGE_DEBUG_TYPE_OMAP_FROM_SRC 8
#تعریف_کړه IMAGE_DEBUG_TYPE_BORLAND 9
#تعریف_کړه IMAGE_DEBUG_TYPE_RESERVED10 10
#تعریف_کړه IMAGE_DEBUG_TYPE_CLSID 11

    تعريفنوع بنية IMAGE_COFF_SYMBOLS_سرلیک {
      DWORD شمېره_د_Symbols;
      DWORD Lva_منزل_لومړی_نښه;
      DWORD شمېره_د_Linenumbers;
      DWORD Lva_منزل_لومړی_Linenumber;
      DWORD Rva_منزل_لومړی_Byte_د_کوډ;
      DWORD Rva_منزل_وروستی_Byte_د_کوډ;
      DWORD Rva_منزل_لومړی_Byte_د_معلومات;
      DWORD Rva_منزل_وروستی_Byte_د_معلومات;
    } IMAGE_COFF_SYMBOLS_سرلیک_2,*PIMAGE_COFF_SYMBOLS_سرلیک;

#تعریف_کړه چوکاټ_FPO 0
#تعریف_کړه چوکاټ_TRAP 1
#تعریف_کړه چوکاټ_TSS 2
#تعریف_کړه چوکاټ_NONFPO 3

    تعريفنوع بنية FPO_معلومات {
      DWORD ul_Off_پیل;
      DWORD cb_Proc_اندازه;
      DWORD cdwLocals;
      کلمه_3 cdwParams;
      کلمه_3 cbProlog : 8;
      کلمه_3 cbRegs : 3;
      کلمه_3 fHasSEH : 1;
      کلمه_3 fUseBP : 1;
      کلمه_3 reserved : 1;
      کلمه_3 cb_چوکاټ : 2;
    } FPO_معلومات_2,*PFPO_معلومات;
#تعریف_کړه SIZEOF_RFPO_معلومات 16

#تعریف_کړه IMAGE_DEBUG_MISC_EXENAME 1

    تعريفنوع بنية _IMAGE_DEBUG_MISC {
      DWORD معلومات_Type;
      DWORD اوږدتیا_2;
      BOOLEAN Unicode;
      BYTE Reserved[3];
      BYTE معلومات_3[1];
    } IMAGE_DEBUG_MISC,*PIMAGE_DEBUG_MISC;

    تعريفنوع بنية IMAGE_FUNCTION_ثبت {
      DWORD Starting_پته;
      DWORD Ending_پته;
      DWORD پای_ټکی_د_Prologue;
    } IMAGE_FUNCTION_ثبت_2,*PIMAGE_FUNCTION_ثبت;

    تعريفنوع بنية _IMAGE_FUNCTION_ENTRY64 {
      ULONGLONG Starting_پته;
      ULONGLONG Ending_پته;
      اتحاد {
	ULONGLONG پای_ټکی_د_Prologue;
	ULONGLONG Unwind_Info_پته;
      };
    } IMAGE_FUNCTION_ENTRY64,*PIMAGE_FUNCTION_ENTRY64;

    تعريفنوع بنية IMAGE_SEPARATE_DEBUG_سرلیک {
      کلمه_3 Signature;
      کلمه_3 Flags;
      کلمه_3 Machine;
      کلمه_3 Characteristics;
      DWORD وخت_Date_Stamp;
      DWORD Check_مجموعه;
      DWORD Image_بنسټ;
      DWORD اندازه_د_Image;
      DWORD شمېره_د_Sections;
      DWORD Exported_نومونه_اندازه;
      DWORD Debug_Directory_اندازه;
      DWORD SectionAlignment;
      DWORD Reserved[2];
    } IMAGE_SEPARATE_DEBUG_سرلیک_2,*PIMAGE_SEPARATE_DEBUG_سرلیک;

    تعريفنوع بنية _NON_PAGED_DEBUG_INFO {
      کلمه_3 Signature;
      کلمه_3 Flags;
      DWORD اندازه_3;
      کلمه_3 Machine;
      کلمه_3 Characteristics;
      DWORD وخت_Date_Stamp;
      DWORD Check_مجموعه;
      DWORD اندازه_د_Image;
      ULONGLONG Image_بنسټ;

    } NON_PAGED_DEBUG_INFO,*PNON_PAGED_DEBUG_INFO;

#تعریف_کړه IMAGE_SEPARATE_DEBUG_SIGNATURE 0x4944
#تعریف_کړه NON_PAGED_DEBUG_SIGNATURE 0x494E

#تعریف_کړه IMAGE_SEPARATE_DEBUG_FLAGS_ماسک 0x8000
#تعریف_کړه IMAGE_SEPARATE_DEBUG_MISMATCH 0x8000

    تعريفنوع بنية Image_Architecture_سرلیک {
      بینښه صحيح Amask_ارزښت: 1;
      صحيح Adummy1 :7;
      بینښه صحيح Amask_ښويدنه: 8;
      صحيح Adummy2 :16;
      DWORD لومړی_ثبت_RVA;
    } IMAGE_ARCHITECTURE_سرلیک,*PIMAGE_ARCHITECTURE_سرلیک;

    تعريفنوع بنية Image_Architecture_ثبت {
      DWORD FixupInstRVA;
      DWORD NewInst;
    } IMAGE_ARCHITECTURE_ثبت,*PIMAGE_ARCHITECTURE_ثبت;

#ضمن "poppack.h"

#تعریف_کړه IMPORT_OBJECT_HDR_SIG2 0xffff

    تعريفنوع بنية IMPORT_OBJECT_سرلیک {
      کلمه_3 Sig1;
      کلمه_3 Sig2;
      کلمه_3 نسخه_2;
      کلمه_3 Machine;
      DWORD وخت_Date_Stamp;
      DWORD اندازه_د_معلومات;
      اتحاد {
	کلمه_3 Ordinal;
	کلمه_3 Hint;
      };
      کلمه_3 Type : 2;
      کلمه_3 NameType : 3;
      کلمه_3 Reserved : 11;
    } IMPORT_OBJECT_سرلیک;

    تعريفنوع تعداد IMPORT_OBJECT_TYPE {
      IMPORT_OBJECT_کوډ = 0,IMPORT_OBJECT_معلومات = 1,IMPORT_OBJECT_CONST = 2
    } IMPORT_OBJECT_TYPE;

    تعريفنوع تعداد IMPORT_OBJECT_NAME_TYPE {
      IMPORT_OBJECT_ORDINAL = 0,IMPORT_OBJECT_NAME = 1,IMPORT_OBJECT_NAME_NO_مختاړی = 2,IMPORT_OBJECT_NAME_UNDECORATE = 3
    } IMPORT_OBJECT_NAME_TYPE;

#که_نه_تعریف_شوی __IMAGE_COR20_HEADER_DEFINED__
#تعریف_کړه __IMAGE_COR20_HEADER_DEFINED__
    تعريفنوع تعداد Replaces_Cor_Hdr_Numeric_تعریفوي {
      COMIMAGE_FLAGS_ILONLY =0x00000001,COMIMAGE_FLAGS_32BITREQUIRED =0x00000002,COMIMAGE_FLAGS_IL_LIBRARY =0x00000004,
      COMIMAGE_FLAGS_STRONGNAMESIGNED =0x00000008,COMIMAGE_FLAGS_TRACKDEBUGDATA =0x00010000,COR_نسخه_MAJOR_V2 =2,
      COR_نسخه_MAJOR =COR_نسخه_MAJOR_V2,COR_نسخه_MINOR =0,COR_DELETED_NAME_اوږدتیا =8,COR_VTABLEGAP_NAME_اوږدتیا =8,
      NATIVE_TYPE_MAX_CB =1,COR_ILMETHOD_SECT_SMALL_MAX_DATASIZE=0xFF,IMAGE_COR_MIH_METHODRVA =0x01,IMAGE_COR_MIH_EHRVA =0x02,
      IMAGE_COR_MIH_BASICBLOCK =0x08,COR_VTABLE_32_بټ =0x01,COR_VTABLE_64_بټ =0x02,COR_VTABLE_FROM_UNMANAGED =0x04,
      COR_VTABLE_CALL_MOST_DERIVED =0x10,IMAGE_COR_EATJ_THUNK_اندازه =32,MAX_CLASS_NAME =1024,MAX_PACKAGE_NAME =1024
    } Replaces_Cor_Hdr_Numeric_تعریفوي;

    تعريفنوع بنية IMAGE_COR20_سرلیک {
      DWORD cb;
      کلمه_3 Major_Runtime_نسخه;
      کلمه_3 Minor_Runtime_نسخه;
      IMAGE_معلومات_DIRECTORY_2 Meta_معلومات;
      DWORD Flags;
      DWORD ثبت_ټکی_Token;
      IMAGE_معلومات_DIRECTORY_2 Resources;
      IMAGE_معلومات_DIRECTORY_2 StrongNameSignature;
      IMAGE_معلومات_DIRECTORY_2 کوډ_Manager_جدول;
      IMAGE_معلومات_DIRECTORY_2 VTableFixups;
      IMAGE_معلومات_DIRECTORY_2 Export_پته_جدول_Jumps;
      IMAGE_معلومات_DIRECTORY_2 Managed_Native_سرلیک;
    } IMAGE_COR20_سرلیک,*PIMAGE_COR20_سرلیک;
#د_که_پای

#إذا defined (__x86_64)
    NTSYSAPI PRUNTIME_FUNCTION NTAPI Rtl_Lookup_Function_ثبت (DWORD64 ControlPc, PDWORD64 Image_بنسټ, PUNWIND_HISTORY_جدول History_جدول);
    NTSYSAPI VOID NTAPI RtlUnwindEx (PVOID موخه_چوکاټ, PVOID موخه_Ip, PEXCEPTION_ریکارډ Exception_ریکارډ, PVOID Return_ارزښت_2, PCONTEXT Context_ریکارډ, PUNWIND_HISTORY_جدول History_جدول);
#د_که_پای

#ضمن <string.h>

#که_نه_تعریف_شوی SLIST_سرلیک
#تعریف_کړه SLIST_سرلیک

#که_تعریف_شوی _WIN64
    تعريفنوع بنية SLIST_ثبت *PSLIST_ثبت;
    تعريفنوع بنية DECLSPEC_ALIGN(16) SLIST_ثبت {
      PSLIST_ثبت بل_2;
    } SLIST_ثبت_2;
#وإلا

#تعریف_کړه SLIST_ثبت_2 SINGLE_LIST_ثبت_2
#تعریف_کړه SLIST_ثبت SINGLE_LIST_ثبت
#تعریف_کړه PSLIST_ثبت PSINGLE_LIST_ثبت
#د_که_پای

#إذا defined(_WIN64)

    تعريفنوع بنية DECLSPEC_ALIGN(16) SLIST_سرلیک_2 {
      ULONGLONG Alignment;
      ULONGLONG Region;
    } SLIST_سرلیک_3;

    تعريفنوع بنية SLIST_سرلیک_2 *PSLIST_سرلیک;
#وإلا

    تعريفنوع اتحاد SLIST_سرلیک_2 {
      ULONGLONG Alignment;
      بنية {
	SLIST_ثبت_2 بل_2;
	کلمه_3 ژوروالی;
	کلمه_3 Sequence;
      };
    } SLIST_سرلیک_3,*PSLIST_سرلیک;
#د_که_پای
#د_که_پای

    NTSYSAPI VOID NTAPI Rtl_Initialize_SList_سر(PSLIST_سرلیک List_سر);
    NTSYSAPI PSLIST_ثبت NTAPI Rtl_لومړی_ثبت_SList(ثابت SLIST_سرلیک_3 *List_سر);
    NTSYSAPI PSLIST_ثبت NTAPI Rtl_Interlocked_راوباسه_ثبت_SList(PSLIST_سرلیک List_سر);
    NTSYSAPI PSLIST_ثبت NTAPI Rtl_Interlocked_ټېل_ثبت_SList(PSLIST_سرلیک List_سر,PSLIST_ثبت List_ثبت);
    NTSYSAPI PSLIST_ثبت NTAPI RtlInterlockedFlushSList(PSLIST_سرلیک List_سر);
    NTSYSAPI کلمه_3 NTAPI Rtl_Query_ژوروالی_SList(PSLIST_سرلیک List_سر);

#تعریف_کړه ډېرۍ_NO_SERIALIZE 0x00000001
#تعریف_کړه ډېرۍ_GROWABLE 0x00000002
#تعریف_کړه ډېرۍ_GENERATE_EXCEPTIONS 0x00000004
#تعریف_کړه ډېرۍ_ZERO_حافظه 0x00000008
#تعریف_کړه ډېرۍ_REALLOC_دننه_ځای_پرځای_کړه_ONLY 0x00000010
#تعریف_کړه ډېرۍ_لکۍ_CHECKING_ENABLED 0x00000020
#تعریف_کړه ډېرۍ_FREE_CHECKING_ENABLED 0x00000040
#تعریف_کړه ډېرۍ_DISABLE_COALESCE_ON_FREE 0x00000080
#تعریف_کړه ډېرۍ_CREATE_ALIGN_16 0x00010000
#تعریف_کړه ډېرۍ_CREATE_ENABLE_TRACING 0x00020000
#تعریف_کړه ډېرۍ_CREATE_ENABLE_EXECUTE 0x00040000
#تعریف_کړه ډېرۍ_اعظمي_نښان 0x0FFF
#تعریف_کړه ډېرۍ_PSEUDO_نښان_FLAG 0x8000
#تعریف_کړه ډېرۍ_نښان_ښويدنه 18
#تعریف_کړه ډېرۍ_MAKE_نښان_FLAGS(b,o) ((DWORD)((b) + ((o) << 18)))

    NTSYSAPI VOID NTAPI RtlCaptureContext(PCONTEXT Context_ریکارډ);

#تعریف_کړه IS_متن_UNICODE_ASCII16 0x0001
#تعریف_کړه IS_متن_UNICODE_سرچپه_ASCII16 0x0010

#تعریف_کړه IS_متن_UNICODE_STATISTICS 0x0002
#تعریف_کړه IS_متن_UNICODE_سرچپه_STATISTICS 0x0020

#تعریف_کړه IS_متن_UNICODE_CONTROLS 0x0004
#تعریف_کړه IS_متن_UNICODE_سرچپه_CONTROLS 0x0040

#تعریف_کړه IS_متن_UNICODE_SIGNATURE 0x0008
#تعریف_کړه IS_متن_UNICODE_سرچپه_SIGNATURE 0x0080

#تعریف_کړه IS_متن_UNICODE_ILLEGAL_CHARS 0x0100
#تعریف_کړه IS_متن_UNICODE_ODD_اوږدتیا 0x0200
#تعریف_کړه IS_متن_UNICODE_DBCS_LEADBYTE 0x0400
#تعریف_کړه IS_متن_UNICODE_NULL_بایټونه 0x1000

#تعریف_کړه IS_متن_UNICODE_UNICODE_ماسک 0x000F
#تعریف_کړه IS_متن_UNICODE_سرچپه_ماسک 0x00F0
#تعریف_کړه IS_متن_UNICODE_NOT_UNICODE_ماسک 0x0F00
#تعریف_کړه IS_متن_UNICODE_NOT_ASCII_ماسک 0xF000

#تعریف_کړه COMPRESSION_FORMAT_NONE (0x0000)
#تعریف_کړه COMPRESSION_FORMAT_DEFAULT (0x0001)
#تعریف_کړه COMPRESSION_FORMAT_LZNT1 (0x0002)
#تعریف_کړه COMPRESSION_ENGINE_STANDARD (0x0000)
#تعریف_کړه COMPRESSION_ENGINE_اعظمي (0x0100)
#تعریف_کړه COMPRESSION_ENGINE_HIBER (0x0200)

#إذا _DBG_MEMCPY_INLINE_ && !defined(_MEMCPY_INLINE_) && !defined(_CRTBLD)
#تعریف_کړه _MEMCPY_INLINE_
    __CRT_INLINE PVOID __cdecl memcpy_inline(فراغ *dst,ثابت فراغ *src,اندازه_t اندازه) {
      إذا(((حرف *)dst > (حرف *)src) && ((حرف *)dst < ((حرف *)src + اندازه))) {
	__debugbreak();
      }
      أرجع حافظه_نقل(dst,src,اندازه);
    }
#تعریف_کړه حافظه_نقل memcpy_inline
#د_که_پای

    NTSYSAPI اندازه_T NTAPI Rtl_Compare_حافظه(ثابت VOID *Source1,ثابت VOID *Source2,اندازه_T اوږدتیا_2);

#تعریف_کړه Rtl_Equal_حافظه(Destination,سرچینه_2,اوږدتیا_2) (!memcmp((Destination),(سرچینه_2),(اوږدتیا_2)))
#تعریف_کړه Rtl_Move_حافظه(Destination,سرچینه_2,اوږدتیا_2) memmove((Destination),(سرچینه_2),(اوږدتیا_2))
#تعریف_کړه Rtl_Copy_حافظه(Destination,سرچینه_2,اوږدتیا_2) حافظه_نقل((Destination),(سرچینه_2),(اوږدتیا_2))
#تعریف_کړه Rtl_Fill_حافظه(Destination,اوږدتیا_2,Fill) memset((Destination),(Fill),(اوږدتیا_2))
#تعریف_کړه Rtl_Zero_حافظه(Destination,اوږدتیا_2) memset((Destination),0,(اوږدتیا_2))

    __CRT_INLINE PVOID Rtl_Secure_Zero_حافظه(PVOID ptr,اندازه_T cnt) {
      متطاير حرف *vptr =(متطاير حرف *)ptr;
#که_تعریف_شوی __x86_64
      __stosb((PBYTE)((DWORD64)vptr),0,cnt);
#وإلا
      طالما(cnt) {
	*vptr = 0;
	vptr++;
	cnt--;
      }
#د_که_پای
      أرجع ptr;
    }

    تعريفنوع بنية پیغام_RESOURCE_ثبت {
      کلمه_3 اوږدتیا_2;
      کلمه_3 Flags;
      BYTE متن_4[1];
    } پیغام_RESOURCE_ثبت_2,*PMESSAGE_RESOURCE_ثبت;

#تعریف_کړه پیغام_RESOURCE_UNICODE 0x0001

    تعريفنوع بنية پیغام_RESOURCE_بلاک {
      DWORD ټیټ_Id;
      DWORD لوړ_Id;
      DWORD دننه_واټن_منزل_Entries;
    } پیغام_RESOURCE_بلاک_2,*PMESSAGE_RESOURCE_بلاک;

    تعريفنوع بنية پیغام_RESOURCE_معلومات {
      DWORD شمېره_د_بلاکونه;
      پیغام_RESOURCE_بلاک_2 بلاکونه_2[1];
    } پیغام_RESOURCE_معلومات_2,*PMESSAGE_RESOURCE_معلومات;

    تعريفنوع بنية _OSVERSIONINFOA {
      DWORD dw_OSVersion_Info_اندازه;
      DWORD dw_Major_نسخه;
      DWORD dw_Minor_نسخه;
      DWORD dw_Build_شمېره;
      DWORD dwPlatformId;
      CHAR szCSDVersion[128];
    } OSVERSIONINFOA,*POSVERSIONINFOA,*LPOSVERSIONINFOA;

    تعريفنوع بنية _OSVERSIONINFOW {
      DWORD dw_OSVersion_Info_اندازه;
      DWORD dw_Major_نسخه;
      DWORD dw_Minor_نسخه;
      DWORD dw_Build_شمېره;
      DWORD dwPlatformId;
      WCHAR szCSDVersion[128];
    } OSVERSIONINFOW,*POSVERSIONINFOW,*LPOSVERSIONINFOW,RTL_OSVERSIONINFOW,*PRTL_OSVERSIONINFOW;

#که_تعریف_شوی UNICODE
    تعريفنوع OSVERSIONINFOW OSVERSIONINFO;
    تعريفنوع POSVERSIONINFOW POSVERSIONINFO;
    تعريفنوع LPOSVERSIONINFOW LPOSVERSIONINFO;
#وإلا
    تعريفنوع OSVERSIONINFOA OSVERSIONINFO;
    تعريفنوع POSVERSIONINFOA POSVERSIONINFO;
    تعريفنوع LPOSVERSIONINFOA LPOSVERSIONINFO;
#د_که_پای

    تعريفنوع بنية _OSVERSIONINFOEXA {
      DWORD dw_OSVersion_Info_اندازه;
      DWORD dw_Major_نسخه;
      DWORD dw_Minor_نسخه;
      DWORD dw_Build_شمېره;
      DWORD dwPlatformId;
      CHAR szCSDVersion[128];
      کلمه_3 wServicePackMajor;
      کلمه_3 wServicePackMinor;
      کلمه_3 w_Suite_ماسک;
      BYTE w_حاصل_ضرب_Type;
      BYTE wReserved;
    } OSVERSIONINFOEXA,*POSVERSIONINFOEXA,*LPOSVERSIONINFOEXA;

    تعريفنوع بنية _OSVERSIONINFOEXW {
      DWORD dw_OSVersion_Info_اندازه;
      DWORD dw_Major_نسخه;
      DWORD dw_Minor_نسخه;
      DWORD dw_Build_شمېره;
      DWORD dwPlatformId;
      WCHAR szCSDVersion[128];
      کلمه_3 wServicePackMajor;
      کلمه_3 wServicePackMinor;
      کلمه_3 w_Suite_ماسک;
      BYTE w_حاصل_ضرب_Type;
      BYTE wReserved;
    } OSVERSIONINFOEXW,*POSVERSIONINFOEXW,*LPOSVERSIONINFOEXW,RTL_OSVERSIONINFOEXW,*PRTL_OSVERSIONINFOEXW;
#که_تعریف_شوی UNICODE
    تعريفنوع OSVERSIONINFOEXW OSVERSIONINFOEX;
    تعريفنوع POSVERSIONINFOEXW POSVERSIONINFOEX;
    تعريفنوع LPOSVERSIONINFOEXW LPOSVERSIONINFOEX;
#وإلا
    تعريفنوع OSVERSIONINFOEXA OSVERSIONINFOEX;
    تعريفنوع POSVERSIONINFOEXA POSVERSIONINFOEX;
    تعريفنوع LPOSVERSIONINFOEXA LPOSVERSIONINFOEX;
#د_که_پای

#تعریف_کړه VER_EQUAL 1
#تعریف_کړه VER_GREATER 2
#تعریف_کړه VER_GREATER_EQUAL 3
#تعریف_کړه VER_LESS 4
#تعریف_کړه VER_LESS_EQUAL 5
#تعریف_کړه VER_AND 6
#تعریف_کړه VER_OR 7

#تعریف_کړه VER_CONDITION_ماسک 7
#تعریف_کړه VER_عدد_بټونه_فی_CONDITION_ماسک 3

#تعریف_کړه VER_MINORVERSION 0x0000001
#تعریف_کړه VER_MAJORVERSION 0x0000002
#تعریف_کړه VER_BUILDNUMBER 0x0000004
#تعریف_کړه VER_PLATFORMID 0x0000008
#تعریف_کړه VER_SERVICEPACKMINOR 0x0000010
#تعریف_کړه VER_SERVICEPACKMAJOR 0x0000020
#تعریف_کړه VER_SUITENAME 0x0000040
#تعریف_کړه VER_حاصل_ضرب_TYPE 0x0000080

#تعریف_کړه VER_NT_WORKSTATION 0x0000001
#تعریف_کړه VER_NT_DOMAIN_CONTROLLER 0x0000002
#تعریف_کړه VER_NT_SERVER 0x0000003

#تعریف_کړه VER_PLATFORM_WIN32s 0
#تعریف_کړه VER_PLATFORM_WIN32_WINDOWS 1
#تعریف_کړه VER_PLATFORM_WIN32_NT 2

#تعریف_کړه VER_سېټ_CONDITION(_m_,_t_,_c_) ((_m_)=Ver_سېټ_Condition_ماسک((_m_),(_t_),(_c_)))

    NTSYSAPI ULONGLONG NTAPI Ver_سېټ_Condition_ماسک(ULONGLONG Condition_ماسک,DWORD Type_ماسک,BYTE Condition);

    تعريفنوع بنية _RTL_CRITICAL_SECTION_DEBUG {
      کلمه_3 Type;
      کلمه_3 Creator_شا_Trace_شاخص;
      بنية _RTL_CRITICAL_SECTION *CriticalSection;
      LIST_ثبت_2 ProcessLocksList;
      DWORD ثبت_شمېر;
      DWORD Contention_شمېر;
      DWORD اضافي_2[2];
    } RTL_CRITICAL_SECTION_DEBUG,*PRTL_CRITICAL_SECTION_DEBUG,RTL_RESOURCE_DEBUG,*PRTL_RESOURCE_DEBUG;

#تعریف_کړه RTL_CRITSECT_TYPE 0
#تعریف_کړه RTL_RESOURCE_TYPE 1

    تعريفنوع بنية _RTL_CRITICAL_SECTION {
      PRTL_CRITICAL_SECTION_DEBUG DebugInfo;
      LONG قلف_شمېر;
      LONG Recursion_شمېر;
      HANDLE OwningThread;
      HANDLE قلف_Semaphore;
      ULONG_PTR Spin_شمېر;
    } RTL_CRITICAL_SECTION,*PRTL_CRITICAL_SECTION;

    تعريفنوع VOID (NTAPI *RTL_VERIFIER_DLL_بارول_CALLBACK) (PWSTR DllName,PVOID Dll_بنسټ,اندازه_T Dll_اندازه,PVOID Reserved);
    تعريفنوع VOID (NTAPI *RTL_VERIFIER_DLL_UNLOAD_CALLBACK) (PWSTR DllName,PVOID Dll_بنسټ,اندازه_T Dll_اندازه,PVOID Reserved);
    تعريفنوع VOID (NTAPI *RTL_VERIFIER_NTDLLHEAPFREE_CALLBACK)(PVOID ویش_بنسټ,اندازه_T ویش_اندازه);

    تعريفنوع بنية _RTL_VERIFIER_THUNK_DESCRIPTOR {
      PCHAR ThunkName;
      PVOID Thunk_Old_پته;
      PVOID Thunk_New_پته;
    } RTL_VERIFIER_THUNK_DESCRIPTOR,*PRTL_VERIFIER_THUNK_DESCRIPTOR;

    تعريفنوع بنية _RTL_VERIFIER_DLL_DESCRIPTOR {
      PWCHAR DllName;
      DWORD DllFlags;
      PVOID Dll_پته;
      PRTL_VERIFIER_THUNK_DESCRIPTOR DllThunks;
    } RTL_VERIFIER_DLL_DESCRIPTOR,*PRTL_VERIFIER_DLL_DESCRIPTOR;

    تعريفنوع بنية _RTL_VERIFIER_PROVIDER_DESCRIPTOR {
      DWORD اوږدتیا_2;
      PRTL_VERIFIER_DLL_DESCRIPTOR ProviderDlls;
      RTL_VERIFIER_DLL_بارول_CALLBACK Provider_Dll_بارول_Callback;
      RTL_VERIFIER_DLL_UNLOAD_CALLBACK ProviderDllUnloadCallback;
      PWSTR VerifierImage;
      DWORD VerifierFlags;
      DWORD VerifierDebug;
      PVOID Rtlp_Get_ډېری_Trace_پته;
      PVOID Rtlp_Debug_پاڼه_ډېرۍ_Create;
      PVOID Rtlp_Debug_پاڼه_ډېرۍ_Destroy;
      RTL_VERIFIER_NTDLLHEAPFREE_CALLBACK Provider_Ntdll_ډېرۍ_Free_Callback;
    } RTL_VERIFIER_PROVIDER_DESCRIPTOR,*PRTL_VERIFIER_PROVIDER_DESCRIPTOR;

#تعریف_کړه RTL_VRF_FLG_ډک_پاڼه_ډېرۍ 0x00000001
#تعریف_کړه RTL_VRF_FLG_RESERVED_DONOTUSE 0x00000002
#تعریف_کړه RTL_VRF_FLG_HANDLE_CHECKS 0x00000004
#تعریف_کړه RTL_VRF_FLG_ډېری_CHECKS 0x00000008
#تعریف_کړه RTL_VRF_FLG_APPCOMPAT_CHECKS 0x00000010
#تعریف_کړه RTL_VRF_FLG_TLS_CHECKS 0x00000020
#تعریف_کړه RTL_VRF_FLG_DIRTY_STACKS 0x00000040
#تعریف_کړه RTL_VRF_FLG_RPC_CHECKS 0x00000080
#تعریف_کړه RTL_VRF_FLG_COM_CHECKS 0x00000100
#تعریف_کړه RTL_VRF_FLG_DANGEROUS_APIS 0x00000200
#تعریف_کړه RTL_VRF_FLG_RACE_CHECKS 0x00000400
#تعریف_کړه RTL_VRF_FLG_DEADLOCK_CHECKS 0x00000800
#تعریف_کړه RTL_VRF_FLG_لومړی_CHANCE_EXCEPTION_CHECKS 0x00001000
#تعریف_کړه RTL_VRF_FLG_VIRTUAL_MEM_CHECKS 0x00002000
#تعریف_کړه RTL_VRF_FLG_ENABLE_LOGGING 0x00004000
#تعریف_کړه RTL_VRF_FLG_FAST_FILL_ډېرۍ 0x00008000
#تعریف_کړه RTL_VRF_FLG_VIRTUAL_SPACE_TRACKING 0x00010000
#تعریف_کړه RTL_VRF_FLG_ENABLED_SYSTEM_WIDE 0x00020000
#تعریف_کړه RTL_VRF_FLG_MISCELLANEOUS_CHECKS 0x00020000
#تعریف_کړه RTL_VRF_FLG_قلف_CHECKS 0x00040000

#تعریف_کړه APPLICATION_VERIFIER_دننی_ERROR 0x80000000
#تعریف_کړه APPLICATION_VERIFIER_دننی_WARNING 0x40000000
#تعریف_کړه APPLICATION_VERIFIER_NO_BREAK 0x20000000
#تعریف_کړه APPLICATION_VERIFIER_CONTINUABLE_BREAK 0x10000000

#تعریف_کړه APPLICATION_VERIFIER_UNKNOWN_ERROR 0x0001
#تعریف_کړه APPLICATION_VERIFIER_ACCESS_VIOLATION 0x0002
#تعریف_کړه APPLICATION_VERIFIER_UNSYNCHRONIZED_ACCESS 0x0003
#تعریف_کړه APPLICATION_VERIFIER_EXTREME_اندازه_REQUEST 0x0004
#تعریف_کړه APPLICATION_VERIFIER_BAD_ډېرۍ_HANDLE 0x0005
#تعریف_کړه APPLICATION_VERIFIER_SWITCHED_ډېرۍ_HANDLE 0x0006
#تعریف_کړه APPLICATION_VERIFIER_DOUBLE_FREE 0x0007
#تعریف_کړه APPLICATION_VERIFIER_CORRUPTED_ډېرۍ_بلاک 0x0008
#تعریف_کړه APPLICATION_VERIFIER_DESTROY_PROCESS_ډېرۍ 0x0009
#تعریف_کړه APPLICATION_VERIFIER_UNEXPECTED_EXCEPTION 0x000A
#تعریف_کړه APPLICATION_VERIFIER_CORRUPTED_ډېرۍ_بلاک_EXCEPTION_RAISED_FOR_سرلیک 0x000B
#تعریف_کړه APPLICATION_VERIFIER_CORRUPTED_ډېرۍ_بلاک_EXCEPTION_RAISED_FOR_PROBING 0x000C
#تعریف_کړه APPLICATION_VERIFIER_CORRUPTED_ډېرۍ_بلاک_سرلیک 0x000D
#تعریف_کړه APPLICATION_VERIFIER_CORRUPTED_FREED_ډېرۍ_بلاک 0x000E
#تعریف_کړه APPLICATION_VERIFIER_CORRUPTED_ډېرۍ_بلاک_SUFFIX 0x000F
#تعریف_کړه APPLICATION_VERIFIER_CORRUPTED_ډېرۍ_بلاک_پیل_STAMP 0x0010
#تعریف_کړه APPLICATION_VERIFIER_CORRUPTED_ډېرۍ_بلاک_پای_ټکی_STAMP 0x0011
#تعریف_کړه APPLICATION_VERIFIER_CORRUPTED_ډېرۍ_بلاک_مختاړی 0x0012
#تعریف_کړه APPLICATION_VERIFIER_لومړی_CHANCE_ACCESS_VIOLATION 0x0013
#تعریف_کړه APPLICATION_VERIFIER_CORRUPTED_ډېرۍ_LIST 0x0014

#تعریف_کړه APPLICATION_VERIFIER_TERMINATE_THREAD_CALL 0x0100
#تعریف_کړه APPLICATION_VERIFIER_ډېری_ډکېدنه 0x0101
#تعریف_کړه APPLICATION_VERIFIER_INVALID_EXIT_PROCESS_CALL 0x0102

#تعریف_کړه APPLICATION_VERIFIER_EXIT_THREAD_OWNS_قلف 0x0200
#تعریف_کړه APPLICATION_VERIFIER_قلف_دننه_UNLOADED_DLL 0x0201
#تعریف_کړه APPLICATION_VERIFIER_قلف_دننه_FREED_ډېرۍ 0x0202
#تعریف_کړه APPLICATION_VERIFIER_قلف_DOUBLE_INITIALIZE 0x0203
#تعریف_کړه APPLICATION_VERIFIER_قلف_دننه_FREED_حافظه 0x0204
#تعریف_کړه APPLICATION_VERIFIER_قلف_CORRUPTED 0x0205
#تعریف_کړه APPLICATION_VERIFIER_قلف_INVALID_OWNER 0x0206
#تعریف_کړه APPLICATION_VERIFIER_قلف_INVALID_RECURSION_شمېر 0x0207
#تعریف_کړه APPLICATION_VERIFIER_قلف_INVALID_قلف_شمېر 0x0208
#تعریف_کړه APPLICATION_VERIFIER_قلف_OVER_RELEASED 0x0209
#تعریف_کړه APPLICATION_VERIFIER_قلف_NOT_INITIALIZED 0x0210
#تعریف_کړه APPLICATION_VERIFIER_قلف_ALREADY_INITIALIZED 0x0211
#تعریف_کړه APPLICATION_VERIFIER_قلف_دننه_FREED_VMEM 0x0212
#تعریف_کړه APPLICATION_VERIFIER_قلف_دننه_UNMAPPED_MEM 0x0213
#تعریف_کړه APPLICATION_VERIFIER_THREAD_NOT_قلف_OWNER 0x0214

#تعریف_کړه APPLICATION_VERIFIER_INVALID_HANDLE 0x0300
#تعریف_کړه APPLICATION_VERIFIER_INVALID_TLS_ارزښت 0x0301
#تعریف_کړه APPLICATION_VERIFIER_INCORRECT_WAIT_CALL 0x0302
#تعریف_کړه APPLICATION_VERIFIER_NULL_HANDLE 0x0303
#تعریف_کړه APPLICATION_VERIFIER_WAIT_دننه_DLLMAIN 0x0304

#تعریف_کړه APPLICATION_VERIFIER_COM_ERROR 0x0400
#تعریف_کړه APPLICATION_VERIFIER_COM_API_دننه_DLLMAIN 0x0401
#تعریف_کړه APPLICATION_VERIFIER_COM_UNHANDLED_EXCEPTION 0x0402
#تعریف_کړه APPLICATION_VERIFIER_COM_UNBALANCED_COINIT 0x0403
#تعریف_کړه APPLICATION_VERIFIER_COM_UNBALANCED_OLEINIT 0x0404
#تعریف_کړه APPLICATION_VERIFIER_COM_UNBALANCED_SWC 0x0405
#تعریف_کړه APPLICATION_VERIFIER_COM_NULL_DACL 0x0406
#تعریف_کړه APPLICATION_VERIFIER_COM_UNSAFE_IMPERSONATION 0x0407
#تعریف_کړه APPLICATION_VERIFIER_COM_SMUGGLED_WRAPPER 0x0408
#تعریف_کړه APPLICATION_VERIFIER_COM_SMUGGLED_PROXY 0x0409
#تعریف_کړه APPLICATION_VERIFIER_COM_CF_SUCCESS_WITH_NULL 0x040A
#تعریف_کړه APPLICATION_VERIFIER_COM_GCO_SUCCESS_WITH_NULL 0x040B
#تعریف_کړه APPLICATION_VERIFIER_COM_OBJECT_دننه_FREED_حافظه 0x040C
#تعریف_کړه APPLICATION_VERIFIER_COM_OBJECT_دننه_UNLOADED_DLL 0x040D
#تعریف_کړه APPLICATION_VERIFIER_COM_VTBL_دننه_FREED_حافظه 0x040E
#تعریف_کړه APPLICATION_VERIFIER_COM_VTBL_دننه_UNLOADED_DLL 0x040F
#تعریف_کړه APPLICATION_VERIFIER_COM_HOLDING_LOCKS_ON_CALL 0x0410

#تعریف_کړه APPLICATION_VERIFIER_RPC_ERROR 0x0500

#تعریف_کړه APPLICATION_VERIFIER_INVALID_FREEMEM 0x0600
#تعریف_کړه APPLICATION_VERIFIER_INVALID_ALLOCMEM 0x0601
#تعریف_کړه APPLICATION_VERIFIER_INVALID_MAPVIEW 0x0602
#تعریف_کړه APPLICATION_VERIFIER_PROBE_INVALID_پته 0x0603
#تعریف_کړه APPLICATION_VERIFIER_PROBE_FREE_MEM 0x0604
#تعریف_کړه APPLICATION_VERIFIER_PROBE_GUARD_پاڼه 0x0605
#تعریف_کړه APPLICATION_VERIFIER_PROBE_NULL 0x0606
#تعریف_کړه APPLICATION_VERIFIER_PROBE_INVALID_پیل_OR_اندازه 0x0607
#تعریف_کړه APPLICATION_VERIFIER_اندازه_ډېرۍ_UNEXPECTED_EXCEPTION 0x0618

#تعریف_کړه VERIFIER_STOP(کوډ_4,پیغام_5,P1,S1,P2,S2,P3,S3,P4,S4) { RtlApplicationVerifierStop ((کوډ_4),(پیغام_5),(ULONG_PTR)(P1),(S1),(ULONG_PTR)(P2),(S2),(ULONG_PTR)(P3),(S3),(ULONG_PTR)(P4),(S4)); }

    VOID NTAPI RtlApplicationVerifierStop(ULONG_PTR کوډ_4,PSTR پیغام_6,ULONG_PTR Param1,PSTR Description1,ULONG_PTR Param2,PSTR Description2,ULONG_PTR Param3,PSTR Description3,ULONG_PTR Param4,PSTR Description4);

    تعريفنوع LONG (NTAPI *PVECTORED_EXCEPTION_HANDLER)(بنية EXCEPTION_اشارې_2 *ExceptionInfo);
#تعریف_کړه SEF_DACL_AUTO_INHERIT 0x01
#تعریف_کړه SEF_SACL_AUTO_INHERIT 0x02
#تعریف_کړه SEF_DEFAULT_DESCRIPTOR_FOR_OBJECT 0x04
#تعریف_کړه SEF_AVOID_PRIVILEGE_CHECK 0x08
#تعریف_کړه SEF_AVOID_OWNER_CHECK 0x10
#تعریف_کړه SEF_DEFAULT_OWNER_FROM_پلار 0x20
#تعریف_کړه SEF_DEFAULT_ډله_FROM_پلار 0x40

    تعريفنوع تعداد ډېرۍ_INFORMATION_CLASS_2 {
      ډېرۍ_Compatibility_Information
    } ډېرۍ_INFORMATION_CLASS;

    NTSYSAPI DWORD NTAPI Rtl_سېټ_ډېرۍ_Information(PVOID ډېرۍ_Handle,ډېرۍ_INFORMATION_CLASS ډېرۍ_Information_Class,PVOID ډېرۍ_Information,اندازه_T ډېرۍ_Information_اوږدتیا);
    NTSYSAPI DWORD NTAPI Rtl_Query_ډېرۍ_Information(PVOID ډېرۍ_Handle,ډېرۍ_INFORMATION_CLASS ډېرۍ_Information_Class,PVOID ډېرۍ_Information,اندازه_T ډېرۍ_Information_اوږدتیا,PSIZE_T Return_اوږدتیا);
    DWORD NTAPI Rtl_مضرب_Allocate_ډېرۍ(PVOID ډېرۍ_Handle,DWORD Flags,اندازه_T اندازه_3,DWORD شمېر_3,PVOID *Array);
    DWORD NTAPI Rtl_مضرب_Free_ډېرۍ(PVOID ډېرۍ_Handle,DWORD Flags,DWORD شمېر_3,PVOID *Array);

#تعریف_کړه WT_EXECUTEDEFAULT 0x00000000
#تعریف_کړه WT_EXECUTEINIOTHREAD 0x00000001
#تعریف_کړه WT_EXECUTEINUITHREAD 0x00000002
#تعریف_کړه WT_EXECUTEINWAITTHREAD 0x00000004
#تعریف_کړه WT_EXECUTEONLYONCE 0x00000008
#تعریف_کړه WT_EXECUTEINTIMERTHREAD 0x00000020
#تعریف_کړه WT_EXECUTELONGFUNCTION 0x00000010
#تعریف_کړه WT_EXECUTEINPERSISTENTIOTHREAD 0x00000040
#تعریف_کړه WT_EXECUTEINPERSISTENTTHREAD 0x00000080
#تعریف_کړه WT_TRANSFER_IMPERSONATION 0x00000100
#تعریف_کړه WT_سېټ_MAX_THREADPOOL_تارونه(Flags,حد_2) ((Flags) |= (حد_2)<<16)
    تعريفنوع VOID (NTAPI *WAITORTIMERCALLBACKFUNC)(PVOID,BOOLEAN);
    تعريفنوع VOID (NTAPI *WORKERCALLBACKFUNC)(PVOID);
    تعريفنوع VOID (NTAPI *APC_CALLBACK_FUNCTION)(DWORD ,PVOID,PVOID);
    تعريفنوع
      VOID
      (NTAPI *PFLS_CALLBACK_FUNCTION)(PVOID lp_Fls_معلومات);
#تعریف_کړه WT_EXECUTEINLONGTHREAD 0x00000010
#تعریف_کړه WT_EXECUTEDELETEWAIT 0x00000008

    تعريفنوع تعداد _ACTIVATION_CONTEXT_INFO_CLASS {
      ActivationContextBasicInformation = 1,ActivationContextDetailedInformation = 2,Assembly_Detailed_Information_دننه_Activation_Context = 3,File_Information_دننه_Assembly_د_Assembly_دننه_Activation_Context = 4,MaxActivationContextInfoClass,Assembly_Detailed_Information_دننه_Activation_Contxt = 3,File_Information_دننه_Assembly_د_Assembly_دننه_Activation_Contxt = 4
    } ACTIVATION_CONTEXT_INFO_CLASS;

#تعریف_کړه ACTIVATIONCONTEXTINFOCLASS ACTIVATION_CONTEXT_INFO_CLASS

    تعريفنوع بنية ACTIVATION_CONTEXT_QUERY_شاخص {
      DWORD ul_Assembly_شاخص;
      DWORD ul_File_شاخص_دننه_Assembly;
    } ACTIVATION_CONTEXT_QUERY_شاخص_2,*PACTIVATION_CONTEXT_QUERY_شاخص;

    تعريفنوع ثابت بنية ACTIVATION_CONTEXT_QUERY_شاخص *PCACTIVATION_CONTEXT_QUERY_شاخص;

#تعریف_کړه ACTIVATION_CONTEXT_لار_TYPE_NONE (1)
#تعریف_کړه ACTIVATION_CONTEXT_لار_TYPE_WIN32_FILE (2)
#تعریف_کړه ACTIVATION_CONTEXT_لار_TYPE_URL (3)
#تعریف_کړه ACTIVATION_CONTEXT_لار_TYPE_ASSEMBLYREF (4)

    تعريفنوع بنية _ASSEMBLY_FILE_DETAILED_INFORMATION {
      DWORD ulFlags;
      DWORD ul_Filename_اوږدتیا;
      DWORD ul_لار_اوږدتیا;

      PCWSTR lpFileName;
      PCWSTR lp_File_لار;
    } ASSEMBLY_FILE_DETAILED_INFORMATION,*PASSEMBLY_FILE_DETAILED_INFORMATION;
    تعريفنوع ثابت ASSEMBLY_FILE_DETAILED_INFORMATION *PCASSEMBLY_FILE_DETAILED_INFORMATION;

#تعریف_کړه _ASSEMBLY_DLL_REDIRECTION_DETAILED_INFORMATION _ASSEMBLY_FILE_DETAILED_INFORMATION
#تعریف_کړه ASSEMBLY_DLL_REDIRECTION_DETAILED_INFORMATION ASSEMBLY_FILE_DETAILED_INFORMATION
#تعریف_کړه PASSEMBLY_DLL_REDIRECTION_DETAILED_INFORMATION PASSEMBLY_FILE_DETAILED_INFORMATION
#تعریف_کړه PCASSEMBLY_DLL_REDIRECTION_DETAILED_INFORMATION PCASSEMBLY_FILE_DETAILED_INFORMATION

    تعريفنوع بنية _ACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION {
      DWORD ulFlags;
      DWORD ul_Encoded_Assembly_بې_اغېزه_عنصر_اوږدتیا;
      DWORD ul_Manifest_لار_Type;
      DWORD ul_Manifest_لار_اوږدتیا;
      LARGE_INTEGER li_Manifest_وروستی_Write_وخت;
      DWORD ul_Policy_لار_Type;
      DWORD ul_Policy_لار_اوږدتیا;
      LARGE_INTEGER li_Policy_وروستی_Write_وخت;
      DWORD ul_Metadata_Satellite_Roster_شاخص;
      DWORD ul_Manifest_نسخه_Major;
      DWORD ul_Manifest_نسخه_Minor;
      DWORD ul_Policy_نسخه_Major;
      DWORD ul_Policy_نسخه_Minor;
      DWORD ul_Assembly_Directory_Name_اوږدتیا;
      PCWSTR lp_Assembly_Encoded_Assembly_بې_اغېزه_عنصر;
      PCWSTR lp_Assembly_Manifest_لار;
      PCWSTR lp_Assembly_Policy_لار;
      PCWSTR lpAssemblyDirectoryName;
      DWORD ul_File_شمېر;
    } ACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION,*PACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION;

    تعريفنوع ثابت بنية _ACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION *PCACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION;

    تعريفنوع بنية _ACTIVATION_CONTEXT_DETAILED_INFORMATION {
      DWORD dwFlags;
      DWORD ul_Format_نسخه;
      DWORD ul_Assembly_شمېر;
      DWORD ul_ریښه_Manifest_لار_Type;
      DWORD ul_ریښه_Manifest_لار_Chars;
      DWORD ul_ریښه_Configuration_لار_Type;
      DWORD ul_ریښه_Configuration_لار_Chars;
      DWORD ul_App_Dir_لار_Type;
      DWORD ul_App_Dir_لار_Chars;
      PCWSTR lp_ریښه_Manifest_لار;
      PCWSTR lp_ریښه_Configuration_لار;
      PCWSTR lp_App_Dir_لار;
    } ACTIVATION_CONTEXT_DETAILED_INFORMATION,*PACTIVATION_CONTEXT_DETAILED_INFORMATION;

    تعريفنوع ثابت بنية _ACTIVATION_CONTEXT_DETAILED_INFORMATION *PCACTIVATION_CONTEXT_DETAILED_INFORMATION;

#تعریف_کړه DLL_PROCESS_ATTACH 1
#تعریف_کړه DLL_THREAD_ATTACH 2
#تعریف_کړه DLL_THREAD_DETACH 3
#تعریف_کړه DLL_PROCESS_DETACH 0
#تعریف_کړه DLL_PROCESS_VERIFIER 4

#تعریف_کړه EVENTLOG_SEQUENTIAL_READ 0x0001
#تعریف_کړه EVENTLOG_SEEK_READ 0x0002
#تعریف_کړه EVENTLOG_FORWARDS_READ 0x0004
#تعریف_کړه EVENTLOG_BACKWARDS_READ 0x0008

#تعریف_کړه EVENTLOG_SUCCESS 0x0000
#تعریف_کړه EVENTLOG_ERROR_TYPE 0x0001
#تعریف_کړه EVENTLOG_WARNING_TYPE 0x0002
#تعریف_کړه EVENTLOG_INFORMATION_TYPE 0x0004
#تعریف_کړه EVENTLOG_AUDIT_SUCCESS 0x0008
#تعریف_کړه EVENTLOG_AUDIT_FAILURE 0x0010

#تعریف_کړه EVENTLOG_پیل_PAIRED_EVENT 0x0001
#تعریف_کړه EVENTLOG_پای_ټکی_PAIRED_EVENT 0x0002
#تعریف_کړه EVENTLOG_پای_ټکی_ALL_PAIRED_EVENTS 0x0004
#تعریف_کړه EVENTLOG_PAIRED_EVENT_فعال 0x0008
#تعریف_کړه EVENTLOG_PAIRED_EVENT_INACTIVE 0x0010

    تعريفنوع بنية _EVENTLOGRECORD {
      DWORD اوږدتیا_2;
      DWORD Reserved;
      DWORD ریکارډ_شمېره;
      DWORD وخت_Generated;
      DWORD وخت_Written;
      DWORD EventID;
      کلمه_3 EventType;
      کلمه_3 عدد_مزي_ګانې;
      کلمه_3 EventCategory;
      کلمه_3 ReservedFlags;
      DWORD Closing_ریکارډ_شمېره;
      DWORD String_دننه_واټن;
      DWORD User_Sid_اوږدتیا;
      DWORD User_Sid_دننه_واټن;
      DWORD معلومات_اوږدتیا;
      DWORD معلومات_دننه_واټن_2;
    } EVENTLOGRECORD,*PEVENTLOGRECORD;

#تعریف_کړه MAXLOGICALLOGNAMESIZE 256

    تعريفنوع بنية _EVENTSFORLOGFILE{
      DWORD ul_اندازه;
      WCHAR szLogicalLogFile[MAXLOGICALLOGNAMESIZE];
      DWORD ul_عدد_ریکارډونه;
      EVENTLOGRECORD p_Event_Log_ریکارډونه[];
    } EVENTSFORLOGFILE,*PEVENTSFORLOGFILE;

    تعريفنوع بنية _PACKEDEVENTINFO{
      DWORD ul_اندازه;
      DWORD ul_عدد_Events_For_Log_File;
      DWORD ulOffsets[];
    } PACKEDEVENTINFO,*PPACKEDEVENTINFO;

#تعریف_کړه کلی_QUERY_ارزښت (0x0001)
#تعریف_کړه کلی_سېټ_ارزښت (0x0002)
#تعریف_کړه کلی_CREATE_SUB_کلی (0x0004)
#تعریف_کړه کلی_ENUMERATE_SUB_کلیګانې (0x0008)
#تعریف_کړه کلی_NOTIFY (0x0010)
#تعریف_کړه کلی_CREATE_LINK (0x0020)
#تعریف_کړه کلی_WOW64_32_کلی (0x0200)
#تعریف_کړه کلی_WOW64_64_کلی (0x0100)
#تعریف_کړه کلی_WOW64_RES (0x0300)

#تعریف_کړه کلی_READ ((STANDARD_RIGHTS_READ | کلی_QUERY_ارزښت | کلی_ENUMERATE_SUB_کلیګانې | کلی_NOTIFY) & (~SYNCHRONIZE))
#تعریف_کړه کلی_WRITE ((STANDARD_RIGHTS_WRITE | کلی_سېټ_ارزښت | کلی_CREATE_SUB_کلی) & (~SYNCHRONIZE))
#تعریف_کړه کلی_EXECUTE ((کلی_READ) & (~SYNCHRONIZE))
#تعریف_کړه کلی_ALL_ACCESS ((STANDARD_RIGHTS_ALL | کلی_QUERY_ارزښت | کلی_سېټ_ارزښت | کلی_CREATE_SUB_کلی | کلی_ENUMERATE_SUB_کلیګانې | کلی_NOTIFY | کلی_CREATE_LINK) & (~SYNCHRONIZE))
#تعریف_کړه REG_OPTION_RESERVED (0x00000000L)

#تعریف_کړه REG_OPTION_NON_VOLATILE (0x00000000L)
#تعریف_کړه REG_OPTION_VOLATILE (0x00000001L)
#تعریف_کړه REG_OPTION_CREATE_LINK (0x00000002L)
#تعریف_کړه REG_OPTION_BACKUP_RESTORE (0x00000004L)
#تعریف_کړه REG_OPTION_OPEN_LINK (0x00000008L)
#تعریف_کړه REG_LEGAL_OPTION (REG_OPTION_RESERVED | REG_OPTION_NON_VOLATILE | REG_OPTION_VOLATILE | REG_OPTION_CREATE_LINK | REG_OPTION_BACKUP_RESTORE | REG_OPTION_OPEN_LINK)
#تعریف_کړه REG_CREATED_NEW_کلی (0x00000001L)
#تعریف_کړه REG_OPENED_EXISTING_کلی (0x00000002L)
#تعریف_کړه REG_STANDARD_FORMAT 1
#تعریف_کړه REG_LATEST_FORMAT 2
#تعریف_کړه REG_NO_COMPRESSION 4
#تعریف_کړه REG_ټولیز_HIVE_VOLATILE (0x00000001L)
#تعریف_کړه REG_REFRESH_HIVE (0x00000002L)
#تعریف_کړه REG_NO_LAZY_FLUSH (0x00000004L)
#تعریف_کړه REG_FORCE_RESTORE (0x00000008L)
#تعریف_کړه REG_FORCE_UNLOAD 1

#تعریف_کړه REG_NOTIFY_CHANGE_NAME (0x00000001L)
#تعریف_کړه REG_NOTIFY_CHANGE_ځانګړتیاوې (0x00000002L)
#تعریف_کړه REG_NOTIFY_CHANGE_وروستی_سېټ (0x00000004L)
#تعریف_کړه REG_NOTIFY_CHANGE_SECURITY (0x00000008L)

#تعریف_کړه REG_LEGAL_CHANGE_FILTER (REG_NOTIFY_CHANGE_NAME | REG_NOTIFY_CHANGE_ځانګړتیاوې | REG_NOTIFY_CHANGE_وروستی_سېټ | REG_NOTIFY_CHANGE_SECURITY)

#تعریف_کړه REG_NONE (0)
#تعریف_کړه REG_SZ (1)
#تعریف_کړه REG_EXPAND_SZ (2)

#تعریف_کړه REG_دوګونی (3)
#تعریف_کړه REG_DWORD (4)
#تعریف_کړه REG_DWORD_LITTLE_ENDIAN (4)
#تعریف_کړه REG_DWORD_BIG_ENDIAN (5)
#تعریف_کړه REG_LINK (6)
#تعریف_کړه REG_MULTI_SZ (7)
#تعریف_کړه REG_RESOURCE_LIST (8)
#تعریف_کړه REG_ډک_RESOURCE_DESCRIPTOR (9)
#تعریف_کړه REG_RESOURCE_REQUIREMENTS_LIST (10)
#تعریف_کړه REG_QWORD (11)
#تعریف_کړه REG_QWORD_LITTLE_ENDIAN (11)

#تعریف_کړه SERVICE_KERNEL_DRIVER 0x00000001
#تعریف_کړه SERVICE_FILE_SYSTEM_DRIVER 0x00000002
#تعریف_کړه SERVICE_ADAPTER 0x00000004
#تعریف_کړه SERVICE_RECOGNIZER_DRIVER 0x00000008

#تعریف_کړه SERVICE_DRIVER (SERVICE_KERNEL_DRIVER | SERVICE_FILE_SYSTEM_DRIVER | SERVICE_RECOGNIZER_DRIVER)

#تعریف_کړه SERVICE_WIN32_OWN_PROCESS 0x00000010
#تعریف_کړه SERVICE_WIN32_SHARE_PROCESS 0x00000020
#تعریف_کړه SERVICE_WIN32 (SERVICE_WIN32_OWN_PROCESS | SERVICE_WIN32_SHARE_PROCESS)

#تعریف_کړه SERVICE_INTERACTIVE_PROCESS 0x00000100

#تعریف_کړه SERVICE_TYPE_ALL (SERVICE_WIN32 | SERVICE_ADAPTER | SERVICE_DRIVER | SERVICE_INTERACTIVE_PROCESS)

#تعریف_کړه SERVICE_BOOT_پیل 0x00000000
#تعریف_کړه SERVICE_SYSTEM_پیل 0x00000001
#تعریف_کړه SERVICE_AUTO_پیل 0x00000002
#تعریف_کړه SERVICE_DEMAND_پیل 0x00000003
#تعریف_کړه SERVICE_DISABLED 0x00000004

#تعریف_کړه SERVICE_ERROR_IGNORE 0x00000000
#تعریف_کړه SERVICE_ERROR_نورمال 0x00000001
#تعریف_کړه SERVICE_ERROR_SEVERE 0x00000002
#تعریف_کړه SERVICE_ERROR_CRITICAL 0x00000003

    تعريفنوع تعداد CM_SERVICE_غوټه_TYPE {
      DriverType = SERVICE_KERNEL_DRIVER,FileSystemType = SERVICE_FILE_SYSTEM_DRIVER,Win32ServiceOwnProcess = SERVICE_WIN32_OWN_PROCESS,
      Win32ServiceShareProcess = SERVICE_WIN32_SHARE_PROCESS,AdapterType = SERVICE_ADAPTER,RecognizerType = SERVICE_RECOGNIZER_DRIVER
    } SERVICE_غوټه_TYPE;

    تعريفنوع تعداد CM_SERVICE_بارول_TYPE {
      Boot_بارول = SERVICE_BOOT_پیل,System_بارول = SERVICE_SYSTEM_پیل,Auto_بارول = SERVICE_AUTO_پیل,Demand_بارول = SERVICE_DEMAND_پیل,
      Disable_بارول = SERVICE_DISABLED
    } SERVICE_بارول_TYPE;

    تعريفنوع تعداد _CM_ERROR_CONTROL_TYPE {
      IgnoreError = SERVICE_ERROR_IGNORE,نورمال_Error = SERVICE_ERROR_نورمال,SevereError = SERVICE_ERROR_SEVERE,CriticalError = SERVICE_ERROR_CRITICAL
    } SERVICE_ERROR_TYPE;

#تعریف_کړه فیته_ERASE_SHORT 0L
#تعریف_کړه فیته_ERASE_LONG 1L

    تعريفنوع بنية فیته_ERASE {
      DWORD Type;
      BOOLEAN سمدستي_2;
    } فیته_ERASE_2,*PTAPE_ERASE;

#تعریف_کړه فیته_بارول 0L
#تعریف_کړه فیته_UNLOAD 1L
#تعریف_کړه فیته_TENSION 2L
#تعریف_کړه فیته_قلف 3L
#تعریف_کړه فیته_UNLOCK 4L
#تعریف_کړه فیته_FORMAT 5L

    تعريفنوع بنية فیته_PREPARE {
      DWORD Operation;
      BOOLEAN سمدستي_2;
    } فیته_PREPARE_2,*PTAPE_PREPARE;

#تعریف_کړه فیته_SETMARKS 0L
#تعریف_کړه فیته_FILEMARKS 1L
#تعریف_کړه فیته_SHORT_FILEMARKS 2L
#تعریف_کړه فیته_LONG_FILEMARKS 3L

    تعريفنوع بنية فیته_WRITE_MARKS {
      DWORD Type;
      DWORD شمېر_3;
      BOOLEAN سمدستي_2;
    } فیته_WRITE_MARKS_2,*PTAPE_WRITE_MARKS;

#تعریف_کړه فیته_ABSOLUTE_POSITION 0L
#تعریف_کړه فیته_LOGICAL_POSITION 1L
#تعریف_کړه فیته_PSEUDO_LOGICAL_POSITION 2L

    تعريفنوع بنية فیته_GET_POSITION {
      DWORD Type;
      DWORD برخه_کول_2;
      LARGE_INTEGER دننه_واټن_3;
    } فیته_GET_POSITION_2,*PTAPE_GET_POSITION;

#تعریف_کړه فیته_REWIND 0L
#تعریف_کړه فیته_ABSOLUTE_بلاک 1L
#تعریف_کړه فیته_LOGICAL_بلاک 2L
#تعریف_کړه فیته_PSEUDO_LOGICAL_بلاک 3L
#تعریف_کړه فیته_SPACE_پای_ټکی_د_معلومات 4L
#تعریف_کړه فیته_SPACE_RELATIVE_بلاکونه 5L
#تعریف_کړه فیته_SPACE_FILEMARKS 6L
#تعریف_کړه فیته_SPACE_SEQUENTIAL_FMKS 7L
#تعریف_کړه فیته_SPACE_SETMARKS 8L
#تعریف_کړه فیته_SPACE_SEQUENTIAL_SMKS 9L

    تعريفنوع بنية فیته_سېټ_POSITION {
      DWORD لاره_2;
      DWORD برخه_کول_2;
      LARGE_INTEGER دننه_واټن_3;
      BOOLEAN سمدستي_2;
    } فیته_سېټ_POSITION_2,*PTAPE_سېټ_POSITION;

#تعریف_کړه فیته_DRIVE_FIXED 0x00000001
#تعریف_کړه فیته_DRIVE_SELECT 0x00000002
#تعریف_کړه فیته_DRIVE_INITIATOR 0x00000004

#تعریف_کړه فیته_DRIVE_ERASE_SHORT 0x00000010
#تعریف_کړه فیته_DRIVE_ERASE_LONG 0x00000020
#تعریف_کړه فیته_DRIVE_ERASE_BOP_ONLY 0x00000040
#تعریف_کړه فیته_DRIVE_ERASE_سمدستي 0x00000080

#تعریف_کړه فیته_DRIVE_فیته_ظرفیت 0x00000100
#تعریف_کړه فیته_DRIVE_فیته_پاتې_شوی 0x00000200
#تعریف_کړه فیته_DRIVE_FIXED_بلاک 0x00000400
#تعریف_کړه فیته_DRIVE_VARIABLE_بلاک 0x00000800

#تعریف_کړه فیته_DRIVE_WRITE_PROTECT 0x00001000
#تعریف_کړه فیته_DRIVE_EOT_WZ_اندازه 0x00002000

#تعریف_کړه فیته_DRIVE_ECC 0x00010000
#تعریف_کړه فیته_DRIVE_COMPRESSION 0x00020000
#تعریف_کړه فیته_DRIVE_PADDING 0x00040000
#تعریف_کړه فیته_DRIVE_REPORT_SMKS 0x00080000

#تعریف_کړه فیته_DRIVE_GET_ABSOLUTE_BLK 0x00100000
#تعریف_کړه فیته_DRIVE_GET_LOGICAL_BLK 0x00200000
#تعریف_کړه فیته_DRIVE_سېټ_EOT_WZ_اندازه 0x00400000

#تعریف_کړه فیته_DRIVE_EJECT_MEDIA 0x01000000
#تعریف_کړه فیته_DRIVE_CLEAN_غوښتنې 0x02000000
#تعریف_کړه فیته_DRIVE_سېټ_CMP_BOP_ONLY 0x04000000

#تعریف_کړه فیته_DRIVE_RESERVED_بټ 0x80000000

#تعریف_کړه فیته_DRIVE_بارول_UNLOAD 0x80000001
#تعریف_کړه فیته_DRIVE_TENSION 0x80000002
#تعریف_کړه فیته_DRIVE_قلف_UNLOCK 0x80000004
#تعریف_کړه فیته_DRIVE_REWIND_سمدستي 0x80000008

#تعریف_کړه فیته_DRIVE_سېټ_بلاک_اندازه 0x80000010
#تعریف_کړه فیته_DRIVE_بارول_UNLD_IMMED 0x80000020
#تعریف_کړه فیته_DRIVE_TENSION_IMMED 0x80000040
#تعریف_کړه فیته_DRIVE_قلف_UNLK_IMMED 0x80000080

#تعریف_کړه فیته_DRIVE_سېټ_ECC 0x80000100
#تعریف_کړه فیته_DRIVE_سېټ_COMPRESSION 0x80000200
#تعریف_کړه فیته_DRIVE_سېټ_PADDING 0x80000400
#تعریف_کړه فیته_DRIVE_سېټ_REPORT_SMKS 0x80000800

#تعریف_کړه فیته_DRIVE_ABSOLUTE_BLK 0x80001000
#تعریف_کړه فیته_DRIVE_ABS_BLK_IMMED 0x80002000
#تعریف_کړه فیته_DRIVE_LOGICAL_BLK 0x80004000
#تعریف_کړه فیته_DRIVE_LOG_BLK_IMMED 0x80008000

#تعریف_کړه فیته_DRIVE_پای_ټکی_د_معلومات 0x80010000
#تعریف_کړه فیته_DRIVE_RELATIVE_BLKS 0x80020000
#تعریف_کړه فیته_DRIVE_FILEMARKS 0x80040000
#تعریف_کړه فیته_DRIVE_SEQUENTIAL_FMKS 0x80080000

#تعریف_کړه فیته_DRIVE_SETMARKS 0x80100000
#تعریف_کړه فیته_DRIVE_SEQUENTIAL_SMKS 0x80200000
#تعریف_کړه فیته_DRIVE_سرچپه_POSITION 0x80400000
#تعریف_کړه فیته_DRIVE_SPACE_سمدستي 0x80800000

#تعریف_کړه فیته_DRIVE_WRITE_SETMARKS 0x81000000
#تعریف_کړه فیته_DRIVE_WRITE_FILEMARKS 0x82000000
#تعریف_کړه فیته_DRIVE_WRITE_SHORT_FMKS 0x84000000
#تعریف_کړه فیته_DRIVE_WRITE_LONG_FMKS 0x88000000

#تعریف_کړه فیته_DRIVE_WRITE_MARK_IMMED 0x90000000
#تعریف_کړه فیته_DRIVE_FORMAT 0xA0000000
#تعریف_کړه فیته_DRIVE_FORMAT_سمدستي 0xC0000000
#تعریف_کړه فیته_DRIVE_لوړ_FEATURES 0x80000000

    تعريفنوع بنية فیته_GET_DRIVE_PARAMETERS {
      BOOLEAN ECC;
      BOOLEAN Compression;
      BOOLEAN معلومات_Padding;
      BOOLEAN ReportSetmarks;
      DWORD Default_بلاک_اندازه;
      DWORD اعظمي_بلاک_اندازه;
      DWORD Minimum_بلاک_اندازه;
      DWORD اعظمي_برخه_کول_شمېر;
      DWORD Features_ټیټ;
      DWORD Features_لوړ;
      DWORD EOTWarning_Zone_اندازه;
    } فیته_GET_DRIVE_PARAMETERS_2,*PTAPE_GET_DRIVE_PARAMETERS;

    تعريفنوع بنية فیته_سېټ_DRIVE_PARAMETERS {
      BOOLEAN ECC;
      BOOLEAN Compression;
      BOOLEAN معلومات_Padding;
      BOOLEAN ReportSetmarks;
      DWORD EOTWarning_Zone_اندازه;
    } فیته_سېټ_DRIVE_PARAMETERS_2,*PTAPE_سېټ_DRIVE_PARAMETERS;

    تعريفنوع بنية فیته_GET_MEDIA_PARAMETERS {
      LARGE_INTEGER ظرفیت;
      LARGE_INTEGER پاتې_شوی;
      DWORD بلاک_اندازه;
      DWORD برخه_کول_شمېر;
      BOOLEAN WriteProtected;
    } فیته_GET_MEDIA_PARAMETERS_2,*PTAPE_GET_MEDIA_PARAMETERS;

    تعريفنوع بنية فیته_سېټ_MEDIA_PARAMETERS {
      DWORD بلاک_اندازه;
    } فیته_سېټ_MEDIA_PARAMETERS_2,*PTAPE_سېټ_MEDIA_PARAMETERS;

#تعریف_کړه فیته_FIXED_PARTITIONS 0L
#تعریف_کړه فیته_SELECT_PARTITIONS 1L
#تعریف_کړه فیته_INITIATOR_PARTITIONS 2L

    تعريفنوع بنية فیته_CREATE_برخه_کول {
      DWORD لاره_2;
      DWORD شمېر_3;
      DWORD اندازه_3;
    } فیته_CREATE_برخه_کول_2,*PTAPE_CREATE_برخه_کول;

#تعریف_کړه فیته_QUERY_DRIVE_PARAMETERS 0L
#تعریف_کړه فیته_QUERY_MEDIA_ظرفیت 1L
#تعریف_کړه فیته_CHECK_FOR_DRIVE_PROBLEM 2L
#تعریف_کړه فیته_QUERY_IO_ERROR_معلومات 3L
#تعریف_کړه فیته_QUERY_DEVICE_ERROR_معلومات 4L

    تعريفنوع بنية فیته_WMI_OPERATIONS {
      DWORD لاره_2;
      DWORD معلومات_بفر_اندازه;
      PVOID معلومات_بفر;
    } فیته_WMI_OPERATIONS_2,*PTAPE_WMI_OPERATIONS;

    تعريفنوع تعداد فیته_DRIVE_PROBLEM_TYPE {
      فیته_Drive_Problem_None,فیته_Drive_Read_Write_Warning,فیته_Drive_Read_Write_Error,فیته_Drive_Read_Warning,فیته_Drive_Write_Warning,فیته_Drive_Read_Error,فیته_Drive_Write_Error,فیته_Drive_Hardware_Error,فیته_Drive_Unsupported_Media,فیته_Drive_Scsi_Connection_Error,فیته_Drive_Timeto_Clean,فیته_Drive_Clean_Drive_Now,فیته_Drive_Media_Life_Expired,فیته_Drive_Snapped_فیته
    } فیته_DRIVE_PROBLEM_TYPE_2;

#إذا defined(__x86_64)
    __CRT_INLINE بنية _TEB *NtCurrentTeb(VOID) { أرجع (بنية _TEB *)__readgsqword(ډګر_دننه_واټن(NT_TIB,Self)); }
    __CRT_INLINE PVOID GetCurrentFiber(VOID) { أرجع(PVOID)__readgsqword(ډګر_دننه_واټن(NT_TIB,Fiber_معلومات)); }
    __CRT_INLINE PVOID Get_Fiber_معلومات(VOID) {
      أرجع *(PVOID *)GetCurrentFiber();
    }
#د_که_پای

#إذا(defined(_X86_) && !defined(__x86_64))
#تعریف_کړه PcTeb 0x18
    __CRT_INLINE بنية _TEB *NtCurrentTeb(فراغ) {
      بنية _TEB *ret;
      __asm__ متطاير ("movl	%%fs:0x18,%0"
	: "=r" (ret));
      أرجع ret;
    }
#د_که_پای

#تعریف_کړه ACTIVATION_CONTEXT_SECTION_ASSEMBLY_INFORMATION (1)
#تعریف_کړه ACTIVATION_CONTEXT_SECTION_DLL_REDIRECTION (2)
#تعریف_کړه ACTIVATION_CONTEXT_SECTION_کړکۍ_CLASS_REDIRECTION (3)
#تعریف_کړه ACTIVATION_CONTEXT_SECTION_COM_SERVER_REDIRECTION (4)
#تعریف_کړه ACTIVATION_CONTEXT_SECTION_COM_INTERFACE_REDIRECTION (5)
#تعریف_کړه ACTIVATION_CONTEXT_SECTION_COM_TYPE_LIBRARY_REDIRECTION (6)
#تعریف_کړه ACTIVATION_CONTEXT_SECTION_COM_PROGID_REDIRECTION (7)
#تعریف_کړه ACTIVATION_CONTEXT_SECTION_GLOBAL_OBJECT_RENAME_جدول (8)
#تعریف_کړه ACTIVATION_CONTEXT_SECTION_CLR_SURROGATES (9)
#تعریف_کړه ACTIVATION_CONTEXT_SECTION_APPLICATION_SETTINGS (10)

#که_تعریف_شوی __cplusplus
  }
#د_که_پای
#د_که_پای
