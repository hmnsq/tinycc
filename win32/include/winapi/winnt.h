/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_تعریف_نشده _WINNT_
#تعریف_کن _WINNT_

#اگر_تعریف_شده __cplusplus
خارجي "C" {
#پایان_اگر

#ضمن <ctype.h>
#تعریف_کن ANYSIZE_ARRAY 1

//gr #include <specstrings.h>

#تعریف_کن RESTRICTED_اشاره_گر

#اگر_تعریف_نشده __CRT_UNALIGNED
#تعریف_کن __CRT_UNALIGNED
#پایان_اگر

#إذا defined(__ia64__) || defined(__x86_64) || defined(__aarch64__)
#تعریف_کن UNALIGNED __CRT_UNALIGNED
#اگر_تعریف_شده _WIN64
#تعریف_کن UNALIGNED64 __CRT_UNALIGNED
#وإلا
#تعریف_کن UNALIGNED64
#پایان_اگر
#وإلا
#تعریف_کن UNALIGNED
#تعریف_کن UNALIGNED64
#پایان_اگر

#إذا !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && (defined(_X86_) && !defined(__x86_64))
#تعریف_کن I_X86_
#پایان_اگر

#إذا !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && defined(__x86_64)
#تعریف_کن _AMD64_
#پایان_اگر

#إذا !defined(I_X86_) && !(defined(_X86_) && !defined(__x86_64)) && !defined(_AMD64_) && defined(__ia64__)
#إذا !defined(_IA64_)
#تعریف_کن _IA64_
#پایان_اگر
#پایان_اگر


#اگر_تعریف_شده _WIN64
#تعریف_کن MAX_NATURAL_ALIGNMENT حجم(ULONGLONG)
#تعریف_کن حافظه_تخصیص_ALIGNMENT 16
#وإلا
#تعریف_کن MAX_NATURAL_ALIGNMENT حجم(DWORD)
#تعریف_کن حافظه_تخصیص_ALIGNMENT 8
#پایان_اگر

#اگر_تعریف_شده __cplusplus
#تعریف_کن TYPE_ALIGNMENT(t) __alignof__ (t)
#وإلا
#تعریف_کن TYPE_ALIGNMENT(t) فیلد_جابه_جایی(بنية { حرف x; t test; },test)
#پایان_اگر

#اگر_تعریف_شده _WIN64
#اگر_تعریف_شده _AMD64_
#تعریف_کن PROBE_ALIGNMENT(_s) TYPE_ALIGNMENT(DWORD)
#وإلاإذا defined(_IA64_) || defined(_ARM64_)
#تعریف_کن PROBE_ALIGNMENT(_s) (TYPE_ALIGNMENT(_s) > TYPE_ALIGNMENT(DWORD) ? TYPE_ALIGNMENT(_s) : TYPE_ALIGNMENT(DWORD))
#وإلا
#خطا No هدف_2 Architecture
#پایان_اگر
#تعریف_کن PROBE_ALIGNMENT32(_s) TYPE_ALIGNMENT(DWORD)
#وإلا
#تعریف_کن PROBE_ALIGNMENT(_s) TYPE_ALIGNMENT(DWORD)
#پایان_اگر

#تعریف_کن C_ASSERT(e) تعريفنوع حرف __C_ASSERT__[(e)?1:-1]

#ضمن <basetsd.h>

#إذا defined(_X86_) || defined(__ia64__) || defined(__x86_64) || defined(__aarch64__)
#تعریف_کن DECLSPEC_IMPORT __declspec(dllimport)
#وإلا
#تعریف_کن DECLSPEC_IMPORT
#پایان_اگر

#اگر_تعریف_نشده DECLSPEC_NORETURN
#تعریف_کن DECLSPEC_NORETURN __declspec(noreturn)
#پایان_اگر

#اگر_تعریف_نشده DECLSPEC_ALIGN
#تعریف_کن DECLSPEC_ALIGN(x) __attribute__ ((aligned(x)))
#پایان_اگر

#اگر_تعریف_نشده SYSTEM_CACHE_ALIGNMENT_اندازه
#إذا defined(_AMD64_) || defined(I_X86_)
#تعریف_کن SYSTEM_CACHE_ALIGNMENT_اندازه 64
#وإلا
#تعریف_کن SYSTEM_CACHE_ALIGNMENT_اندازه 128
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده DECLSPEC_CACHEALIGN
#تعریف_کن DECLSPEC_CACHEALIGN DECLSPEC_ALIGN(SYSTEM_CACHE_ALIGNMENT_اندازه)
#پایان_اگر

#اگر_تعریف_نشده DECLSPEC_UUID
#تعریف_کن DECLSPEC_UUID(x)
#پایان_اگر

#اگر_تعریف_نشده DECLSPEC_NOVTABLE
#تعریف_کن DECLSPEC_NOVTABLE
#پایان_اگر

#اگر_تعریف_نشده DECLSPEC_SELECTANY
#تعریف_کن DECLSPEC_SELECTANY __declspec(selectany)
#پایان_اگر

#اگر_تعریف_نشده NOP_FUNCTION
#تعریف_کن NOP_FUNCTION (فراغ)0
#پایان_اگر

#اگر_تعریف_نشده DECLSPEC_NOINLINE
#تعریف_کن DECLSPEC_NOINLINE
#پایان_اگر

#اگر_تعریف_نشده FORCEINLINE
#تعریف_کن FORCEINLINE ساكن __inline__
#پایان_اگر

#اگر_تعریف_نشده DECLSPEC_DEPRECATED
#تعریف_کن DECLSPEC_DEPRECATED __declspec(deprecated)
#تعریف_کن DEPRECATE_SUPPORTED
#پایان_اگر

#تعریف_کن DECLSPEC_DEPRECATED_DDK
#تعریف_کن PRAGMA_DEPRECATED_DDK 0

  تعريفنوع فراغ *PVOID;
  تعريفنوع فراغ *PVOID64;

#تعریف_کن NTAPI __stdcall
#تعریف_کن NTSYSAPI DECLSPEC_IMPORT
#تعریف_کن NTSYSCALLAPI DECLSPEC_IMPORT

#اگر_تعریف_نشده VOID
#تعریف_کن VOID فراغ
  تعريفنوع حرف CHAR;
  تعريفنوع کوتاه SHORT;
  تعريفنوع دراز LONG;
#پایان_اگر

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

#اگر_تعریف_شده UNICODE
#اگر_تعریف_نشده _TCHAR_DEFINED
#تعریف_کن _TCHAR_DEFINED
  تعريفنوع WCHAR TCHAR,*PTCHAR;
  تعريفنوع WCHAR TBYTE ,*PTBYTE;
#پایان_اگر

  تعريفنوع LPWSTR LPTCH,PTCH;
  تعريفنوع LPWSTR PTSTR,LPTSTR;
  تعريفنوع LPCWSTR PCTSTR,LPCTSTR;
  تعريفنوع LPUWSTR PUTSTR,LPUTSTR;
  تعريفنوع LPCUWSTR PCUTSTR,LPCUTSTR;
  تعريفنوع LPWSTR LP;
#تعریف_کن __TEXT(quote) L##quote
#وإلا
#اگر_تعریف_نشده _TCHAR_DEFINED
#تعریف_کن _TCHAR_DEFINED
  تعريفنوع حرف TCHAR,*PTCHAR;
  تعريفنوع بیعلامت حرف TBYTE ,*PTBYTE;
#پایان_اگر

  تعريفنوع LPSTR LPTCH,PTCH;
  تعريفنوع LPSTR PTSTR,LPTSTR,PUTSTR,LPUTSTR;
  تعريفنوع LPCSTR PCTSTR,LPCTSTR,PCUTSTR,LPCUTSTR;
#تعریف_کن __TEXT(quote) quote
#پایان_اگر

#تعریف_کن متن_3(quote) __TEXT(quote)

  تعريفنوع SHORT *PSHORT;
  تعريفنوع LONG *PLONG;

  تعريفنوع فراغ *HANDLE;
#تعریف_کن DECLARE_HANDLE(name) بنية name##__ { صحيح استفادهنشده; }; تعريفنوع بنية name##__ *name
  تعريفنوع HANDLE *PHANDLE;

  تعريفنوع BYTE FCHAR;
  تعريفنوع کلمه_3 FSHORT;
  تعريفنوع DWORD FLONG;

#اگر_تعریف_نشده _HRESULT_DEFINED
#تعریف_کن _HRESULT_DEFINED
  تعريفنوع LONG HRESULT;
#پایان_اگر

#اگر_تعریف_شده __cplusplus
#تعریف_کن EXTERN_C خارجي "C"
#وإلا
#تعریف_کن EXTERN_C خارجي
#پایان_اگر

#تعریف_کن STDMETHODCALLTYPE WINAPI
#تعریف_کن STDMETHODVCALLTYPE __cdecl
#تعریف_کن STDAPICALLTYPE WINAPI
#تعریف_کن STDAPIVCALLTYPE __cdecl
#تعریف_کن STDAPI EXTERN_C HRESULT WINAPI
#تعریف_کن STDAPI_(type) EXTERN_C type WINAPI
#تعریف_کن STDMETHODIMP HRESULT WINAPI
#تعریف_کن STDMETHODIMP_(type) type WINAPI
#تعریف_کن STDAPIV EXTERN_C HRESULT STDAPIVCALLTYPE
#تعریف_کن STDAPIV_(type) EXTERN_C type STDAPIVCALLTYPE
#تعریف_کن STDMETHODIMPV HRESULT STDMETHODVCALLTYPE
#تعریف_کن STDMETHODIMPV_(type) type STDMETHODVCALLTYPE

  تعريفنوع حرف CCHAR;
#اگر_تعریف_نشده _LCID_DEFINED
#تعریف_کن _LCID_DEFINED
تعريفنوع DWORD LCID;
#پایان_اگر
  تعريفنوع PDWORD PLCID;
#اگر_تعریف_نشده _LANGID_DEFINED
#تعریف_کن _LANGID_DEFINED
  تعريفنوع کلمه_3 LANGID;
#پایان_اگر
#تعریف_کن APPLICATION_ERROR_ماسک 0x20000000
#تعریف_کن ERROR_SEVERITY_SUCCESS 0x00000000
#تعریف_کن ERROR_SEVERITY_INFORMATIONAL 0x40000000
#تعریف_کن ERROR_SEVERITY_WARNING 0x80000000
#تعریف_کن ERROR_SEVERITY_ERROR 0xC0000000

#اگر_تعریف_شده __ia64__
  __declspec(align(16))
#پایان_اگر
    تعريفنوع بنية _FLOAT128 {
      __int64 کم_Part;
      __int64 بالا_Part;
  } FLOAT128;

  تعريفنوع FLOAT128 *PFLOAT128;

#تعریف_کن _ULONGLONG_
#إذا((!(defined(_X86_) && !defined(__x86_64)) || (defined(INTEGRAL_MAX_بیتها) && INTEGRAL_MAX_بیتها >= 64)))
  تعريفنوع __int64 LONGLONG;
  تعريفنوع بیعلامت __int64 ULONGLONG;

#تعریف_کن MAXLONGLONG (0x7fffffffffffffff)
#وإلا

  تعريفنوع مزدوج LONGLONG;
  تعريفنوع مزدوج ULONGLONG;
#پایان_اگر

  تعريفنوع LONGLONG *PLONGLONG;
  تعريفنوع ULONGLONG *PULONGLONG;

  تعريفنوع LONGLONG USN;

  تعريفنوع اتحاد _LARGE_INTEGER {
    بنية {
      DWORD کم_Part;
      LONG بالا_Part;
    };
    بنية {
      DWORD کم_Part;
      LONG بالا_Part;
    } u;
    LONGLONG QuadPart;
  } LARGE_INTEGER;

  تعريفنوع LARGE_INTEGER *PLARGE_INTEGER;

  تعريفنوع اتحاد _ULARGE_INTEGER {
    بنية {
      DWORD کم_Part;
      DWORD بالا_Part;
    };
    بنية {
      DWORD کم_Part;
      DWORD بالا_Part;
    } u;
    ULONGLONG QuadPart;
  } ULARGE_INTEGER;

  تعريفنوع ULARGE_INTEGER *PULARGE_INTEGER;

  تعريفنوع بنية _LUID {
    DWORD کم_Part;
    LONG بالا_Part;
  } LUID,*PLUID;

#تعریف_کن _DWORDLONG_
  تعريفنوع ULONGLONG DWORDLONG;
  تعريفنوع DWORDLONG *PDWORDLONG;

#اگر_تعریف_شده RC_INVOKED
#تعریف_کن Int32x32To64(a,b) ((LONGLONG)((LONG)(a)) *(LONGLONG)((LONG)(b)))
#تعریف_کن UInt32x32To64(a,b) ((ULONGLONG)((DWORD)(a)) *(ULONGLONG)((DWORD)(b)))
#تعریف_کن Int64ShrlMod32(a,b) ((ULONGLONG)(a) >> (b))
#وإلاإذا (defined(_X86_) && !defined(__x86_64))
#تعریف_کن Int32x32To64(a,b) (LONGLONG)((LONGLONG)(LONG)(a) *(LONG)(b))
#تعریف_کن UInt32x32To64(a,b) (ULONGLONG)((ULONGLONG)(DWORD)(a) *(DWORD)(b))
#تعریف_کن Int64ShrlMod32(a,b) ((DWORDLONG)(a)>>(b))
#وإلاإذا defined(__ia64__) || defined(__x86_64) || defined(__aarch64__)
#تعریف_کن Int32x32To64(a,b) ((LONGLONG)((LONG)(a)) *(LONGLONG)((LONG)(b)))
#تعریف_کن UInt32x32To64(a,b) ((ULONGLONG)((DWORD)(a)) *(ULONGLONG)((DWORD)(b)))
#تعریف_کن Int64ShrlMod32(a,b) ((ULONGLONG)(a) >> (b))
#وإلا
#خطا Must define a هدف architecture.
#پایان_اگر

#تعریف_کن Int64ShraMod32(a,b) ((LONGLONG)(a) >> (b))
#تعریف_کن Int64ShllMod32(a,b) ((ULONGLONG)(a) << (b))

#اگر_تعریف_شده __cplusplus
  خارجي "C" {
#پایان_اگر

#اگر_تعریف_شده __x86_64

#تعریف_کن RotateLeft8 _rotl8
#تعریف_کن RotateLeft16 _rotl16
#تعریف_کن RotateRight8 _rotr8
#تعریف_کن RotateRight16 _rotr16

    بیعلامت حرف __cdecl _rotl8(بیعلامت حرف مقدار_3,بیعلامت حرف لغزش_3);
    بیعلامت کوتاه __cdecl _rotl16(بیعلامت کوتاه مقدار_3,بیعلامت حرف لغزش_3);
    بیعلامت حرف __cdecl _rotr8(بیعلامت حرف مقدار_3,بیعلامت حرف لغزش_3);
    بیعلامت کوتاه __cdecl _rotr16(بیعلامت کوتاه مقدار_3,بیعلامت حرف لغزش_3);
#پایان_اگر

#تعریف_کن RotateLeft32 _rotl
#تعریف_کن RotateLeft64 _rotl64
#تعریف_کن RotateRight32 _rotr
#تعریف_کن RotateRight64 _rotr64

    بیعلامت صحيح __cdecl _rotl(بیعلامت صحيح مقدار_3,صحيح لغزش_3);
    بیعلامت __int64 __cdecl _rotl64(بیعلامت __int64 مقدار_3,صحيح لغزش_3);
    بیعلامت صحيح __cdecl _rotr(بیعلامت صحيح مقدار_3,صحيح لغزش_3);
    بیعلامت __int64 __cdecl _rotr64(بیعلامت __int64 مقدار_3,صحيح لغزش_3);
#اگر_تعریف_شده __cplusplus
  }
#پایان_اگر

#تعریف_کن ANSI_NULL ((CHAR)0)
#تعریف_کن UNICODE_NULL ((WCHAR)0)
#تعریف_کن UNICODE_STRING_MAX_بایتها ((کلمه_3) 65534)
#تعریف_کن UNICODE_STRING_MAX_CHARS (32767)

#اگر_تعریف_نشده _BOOLEAN_
#تعریف_کن _BOOLEAN_
  تعريفنوع BYTE BOOLEAN;
#پایان_اگر
  تعريفنوع BOOLEAN *PBOOLEAN;

  تعريفنوع بنية LIST_مدخل {
    بنية LIST_مدخل *Flink;
    بنية LIST_مدخل *Blink;
  } LIST_مدخل_2,*PLIST_مدخل,*RESTRICTED_اشاره_گر PRLIST_مدخل;

  تعريفنوع بنية SINGLE_LIST_مدخل {
    بنية SINGLE_LIST_مدخل *بعدی_2;
  } SINGLE_LIST_مدخل_2,*PSINGLE_LIST_مدخل;

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

#اگر_تعریف_نشده __OBJECTID_DEFINED
#تعریف_کن __OBJECTID_DEFINED
  تعريفنوع بنية _OBJECTID {
    GUID Lineage;
    DWORD Uniquifier;
  } OBJECTID;
#پایان_اگر

#تعریف_کن MINCHAR 0x80
#تعریف_کن MAXCHAR 0x7f
#تعریف_کن MINSHORT 0x8000
#تعریف_کن MAXSHORT 0x7fff
#تعریف_کن MINLONG 0x80000000
#تعریف_کن MAXLONG 0x7fffffff
#تعریف_کن MAXBYTE 0xff
#تعریف_کن MAXWORD 0xffff
#تعریف_کن MAXDWORD 0xffffffff

#تعریف_کن فیلد_جابه_جایی(type,فیلد) ((LONG)(LONG_PTR)&(((type *)0)->فیلد))
#تعریف_کن RTL_فیلد_اندازه(type,فیلد) (حجم(((type *)0)->فیلد))
#تعریف_کن RTL_SIZEOF_THROUGH_فیلد(type,فیلد) (فیلد_جابه_جایی(type,فیلد) + RTL_فیلد_اندازه(type,فیلد))
#تعریف_کن RTL_شامل_است_فیلد(Struct,اندازه_3,فیلد_2) ((((PCHAR)(&(Struct)->فیلد_2)) + حجم((Struct)->فیلد_2)) <= (((PCHAR)(Struct))+(اندازه_3)))
#تعریف_کن RTL_عدد_از_V1(A) (حجم(A)/حجم((A)[0]))
#تعریف_کن RTL_عدد_از_V2(A) RTL_عدد_از_V1(A)

#اگر_تعریف_شده ENABLE_RTL_عدد_از_V2
#تعریف_کن RTL_عدد_از(A) RTL_عدد_از_V2(A)
#وإلا
#تعریف_کن RTL_عدد_از(A) RTL_عدد_از_V1(A)
#پایان_اگر

#تعریف_کن ARRAYSIZE(A) RTL_عدد_از_V2(A)
#تعریف_کن _ARRAYSIZE(A) RTL_عدد_از_V1(A)

#تعریف_کن RTL_فیلد_TYPE(type,فیلد) (((type*)0)->فیلد)
#تعریف_کن RTL_عدد_از_فیلد(type,فیلد) (RTL_عدد_از(RTL_فیلد_TYPE(type,فیلد)))
#تعریف_کن RTL_PADDING_BETWEEN_FIELDS(T,F1,F2) ((فیلد_جابه_جایی(T,F2) > فیلد_جابه_جایی(T,F1)) ? (فیلد_جابه_جایی(T,F2) - فیلد_جابه_جایی(T,F1) - RTL_فیلد_اندازه(T,F1)) : (فیلد_جابه_جایی(T,F1) - فیلد_جابه_جایی(T,F2) - RTL_فیلد_اندازه(T,F2)))

#اگر_تعریف_شده __cplusplus
#تعریف_کن RTL_CONST_CAST(type) const_cast<type>
#وإلا
#تعریف_کن RTL_CONST_CAST(type) (type)
#پایان_اگر

#تعریف_کن RTL_بیتها_از(اندازه_از_Arg) (حجم(اندازه_از_Arg) *8)
#تعریف_کن RTL_بیتها_از_فیلد(type,فیلد) (RTL_بیتها_از(RTL_فیلد_TYPE(type,فیلد)))
#تعریف_کن CONTAINING_رکورد(آدرس,type,فیلد) ((type *)((PCHAR)(آدرس) - (ULONG_PTR)(&((type *)0)->فیلد)))

#تعریف_کن VER_SERVER_NT 0x80000000
#تعریف_کن VER_WORKSTATION_NT 0x40000000
#تعریف_کن VER_SUITE_SMALLBUSINESS 0x00000001
#تعریف_کن VER_SUITE_ENTERPRISE 0x00000002
#تعریف_کن VER_SUITE_BACKOFFICE 0x00000004
#تعریف_کن VER_SUITE_COMMUNICATIONS 0x00000008
#تعریف_کن VER_SUITE_TERMINAL 0x00000010
#تعریف_کن VER_SUITE_SMALLBUSINESS_RESTRICTED 0x00000020
#تعریف_کن VER_SUITE_EMBEDDEDNT 0x00000040
#تعریف_کن VER_SUITE_DATACENTER 0x00000080
#تعریف_کن VER_SUITE_SINGLEUSERTS 0x00000100
#تعریف_کن VER_SUITE_PERSONAL 0x00000200
#تعریف_کن VER_SUITE_BLADE 0x00000400
#تعریف_کن VER_SUITE_EMBEDDED_RESTRICTED 0x00000800
#تعریف_کن VER_SUITE_SECURITY_APPLIANCE 0x00001000
#تعریف_کن VER_SUITE_STORAGE_SERVER 0x00002000
#تعریف_کن VER_SUITE_COMPUTE_SERVER 0x00004000

#تعریف_کن حاصلضرب_UNDEFINED                       0x0

#تعریف_کن حاصلضرب_ULTIMATE                        0x1
#تعریف_کن حاصلضرب_HOME_BASIC                      0x2
#تعریف_کن حاصلضرب_HOME_PREMIUM                    0x3
#تعریف_کن حاصلضرب_ENTERPRISE                      0x4
#تعریف_کن حاصلضرب_HOME_BASIC_N                    0x5
#تعریف_کن حاصلضرب_BUSINESS                        0x6
#تعریف_کن حاصلضرب_STANDARD_SERVER                 0x7
#تعریف_کن حاصلضرب_DATACENTER_SERVER               0x8
#تعریف_کن حاصلضرب_SMALLBUSINESS_SERVER            0x9
#تعریف_کن حاصلضرب_ENTERPRISE_SERVER               0xa
#تعریف_کن حاصلضرب_STARTER                         0xb
#تعریف_کن حاصلضرب_DATACENTER_SERVER_CORE          0xc
#تعریف_کن حاصلضرب_STANDARD_SERVER_CORE            0xd
#تعریف_کن حاصلضرب_ENTERPRISE_SERVER_CORE          0xe
#تعریف_کن حاصلضرب_ENTERPRISE_SERVER_IA64          0xf
#تعریف_کن حاصلضرب_BUSINESS_N                      0x10
#تعریف_کن حاصلضرب_WEB_SERVER                      0x11
#تعریف_کن حاصلضرب_CLUSTER_SERVER                  0x12
#تعریف_کن حاصلضرب_HOME_SERVER                     0x13
#تعریف_کن حاصلضرب_STORAGE_EXPRESS_SERVER          0x14
#تعریف_کن حاصلضرب_STORAGE_STANDARD_SERVER         0x15
#تعریف_کن حاصلضرب_STORAGE_WORKGROUP_SERVER        0x16
#تعریف_کن حاصلضرب_STORAGE_ENTERPRISE_SERVER       0x17
#تعریف_کن حاصلضرب_SERVER_FOR_SMALLBUSINESS        0x18
#تعریف_کن حاصلضرب_SMALLBUSINESS_SERVER_PREMIUM    0x19

#تعریف_کن حاصلضرب_UNLICENSED                      0xabcdabcd

#تعریف_کن LANG_NEUTRAL 0x00
#تعریف_کن LANG_INVARIANT 0x7f

#تعریف_کن LANG_AFRIKAANS 0x36
#تعریف_کن LANG_ALBANIAN 0x1c
#تعریف_کن LANG_ALSATIAN 0x84
#تعریف_کن LANG_AMHARIC 0x5e
#تعریف_کن LANG_ARABIC 0x01
#تعریف_کن LANG_ARMENIAN 0x2b
#تعریف_کن LANG_ASSAMESE 0x4d
#تعریف_کن LANG_AZERI 0x2c
#تعریف_کن LANG_BASHKIR 0x6d
#تعریف_کن LANG_BASQUE 0x2d
#تعریف_کن LANG_BELARUSIAN 0x23
#تعریف_کن LANG_BENGALI 0x45
#تعریف_کن LANG_BRETON 0x7e
#تعریف_کن LANG_BOSNIAN 0x1a
#تعریف_کن LANG_BOSNIAN_NEUTRAL 0x781a
#تعریف_کن LANG_BULGARIAN 0x02
#تعریف_کن LANG_کاتالان 0x03
#تعریف_کن LANG_CHINESE 0x04
#تعریف_کن LANG_CHINESE_SIMPLIFIED 0x04
#تعریف_کن LANG_CHINESE_TRADITIONAL 0x7c04
#تعریف_کن LANG_CORSICAN 0x83
#تعریف_کن LANG_CROATIAN 0x1a
#تعریف_کن LANG_CZECH 0x05
#تعریف_کن LANG_DANISH 0x06
#تعریف_کن LANG_DARI 0x8c
#تعریف_کن LANG_DIVEHI 0x65
#تعریف_کن LANG_DUTCH 0x13
#تعریف_کن LANG_ENGLISH 0x09
#تعریف_کن LANG_ESTONIAN 0x25
#تعریف_کن LANG_FAEROESE 0x38
#تعریف_کن LANG_FARSI 0x29
#تعریف_کن LANG_FILIPINO 0x64
#تعریف_کن LANG_FINNISH 0x0b
#تعریف_کن LANG_FRENCH 0x0c
#تعریف_کن LANG_FRISIAN 0x62
#تعریف_کن LANG_GALICIAN 0x56
#تعریف_کن LANG_GEORGIAN 0x37
#تعریف_کن LANG_GERMAN 0x07
#تعریف_کن LANG_GREEK 0x08
#تعریف_کن LANG_GREENLANDIC 0x6f
#تعریف_کن LANG_GUJARATI 0x47
#تعریف_کن LANG_HAUSA 0x68
#تعریف_کن LANG_HEBREW 0x0d
#تعریف_کن LANG_HINDI 0x39
#تعریف_کن LANG_HUNGARIAN 0x0e
#تعریف_کن LANG_ICELANDIC 0x0f
#تعریف_کن LANG_IGBO 0x70
#تعریف_کن LANG_INDONESIAN 0x21
#تعریف_کن LANG_INUKTITUT 0x5d
#تعریف_کن LANG_IRISH 0x3c
#تعریف_کن LANG_ITALIAN 0x10
#تعریف_کن LANG_JAPANESE 0x11
#تعریف_کن LANG_KANNADA 0x4b
#تعریف_کن LANG_KASHMIRI 0x60
#تعریف_کن LANG_KAZAK 0x3f
#تعریف_کن LANG_KHMER 0x53
#تعریف_کن LANG_KICHE 0x86
#تعریف_کن LANG_KINYARWANDA 0x87
#تعریف_کن LANG_KONKANI 0x57
#تعریف_کن LANG_KOREAN 0x12
#تعریف_کن LANG_KYRGYZ 0x40
#تعریف_کن LANG_LAO 0x54
#تعریف_کن LANG_LATVIAN 0x26
#تعریف_کن LANG_LITHUANIAN 0x27
#تعریف_کن LANG_پایینی_SORBIAN 0x2e
#تعریف_کن LANG_LUXEMBOURGISH 0x6e
#تعریف_کن LANG_MACEDONIAN 0x2f
#تعریف_کن LANG_MALAY 0x3e
#تعریف_کن LANG_MALAYALAM 0x4c
#تعریف_کن LANG_MALTESE 0x3a
#تعریف_کن LANG_MANIPURI 0x58
#تعریف_کن LANG_MAORI 0x81
#تعریف_کن LANG_MAPUDUNGUN 0x7a
#تعریف_کن LANG_MARATHI 0x4e
#تعریف_کن LANG_MOHAWK 0x7c
#تعریف_کن LANG_MONGOLIAN 0x50
#تعریف_کن LANG_NEPALI 0x61
#تعریف_کن LANG_NORWEGIAN 0x14
#تعریف_کن LANG_OCCITAN 0x82
#تعریف_کن LANG_ORIYA 0x48
#تعریف_کن LANG_PASHTO 0x63
#تعریف_کن LANG_PERSIAN 0x29
#تعریف_کن LANG_POLISH 0x15
#تعریف_کن LANG_PORTUGUESE 0x16
#تعریف_کن LANG_PUNJABI 0x46
#تعریف_کن LANG_QUECHUA 0x6b
#تعریف_کن LANG_ROMANIAN 0x18
#تعریف_کن LANG_RUSSIAN 0x19
#تعریف_کن LANG_SAMI 0x3b
#تعریف_کن LANG_ROMANSH 0x17
#تعریف_کن LANG_SANSKRIT 0x4f
#تعریف_کن LANG_SERBIAN 0x1a
#تعریف_کن LANG_SERBIAN_NEUTRAL 0x7c1a
#تعریف_کن LANG_SINDHI 0x59
#تعریف_کن LANG_SINHALESE 0x5b
#تعریف_کن LANG_SLOVAK 0x1b
#تعریف_کن LANG_SLOVENIAN 0x24
#تعریف_کن LANG_SOTHO 0x6c
#تعریف_کن LANG_SPANISH 0x0a
#تعریف_کن LANG_SWAHILI 0x41
#تعریف_کن LANG_SWEDISH 0x1d
#تعریف_کن LANG_SYRIAC 0x5a
#تعریف_کن LANG_TAJIK 0x28
#تعریف_کن LANG_TAMAZIGHT 0x5f
#تعریف_کن LANG_TAMIL 0x49
#تعریف_کن LANG_TATAR 0x44
#تعریف_کن LANG_TELUGU 0x4a
#تعریف_کن LANG_THAI 0x1e
#تعریف_کن LANG_TIBETAN 0x51
#تعریف_کن LANG_TIGRIGNA 0x73
#تعریف_کن LANG_TSWANA 0x32
#تعریف_کن LANG_TURKISH 0x1f
#تعریف_کن LANG_TURKMEN 0x42
#تعریف_کن LANG_UIGHUR 0x80
#تعریف_کن LANG_UKRAINIAN 0x22
#تعریف_کن LANG_فوقانی_SORBIAN 0x2e
#تعریف_کن LANG_URDU 0x20
#تعریف_کن LANG_UZBEK 0x43
#تعریف_کن LANG_VIETNAMESE 0x2a
#تعریف_کن LANG_WELSH 0x52
#تعریف_کن LANG_WOLOF 0x88
#تعریف_کن LANG_XHOSA 0x34
#تعریف_کن LANG_YAKUT 0x85
#تعریف_کن LANG_YI 0x78
#تعریف_کن LANG_YORUBA 0x6a
#تعریف_کن LANG_ZULU 0x35

#تعریف_کن SUBLANG_NEUTRAL 0x0
#تعریف_کن SUBLANG_DEFAULT 0x1
#تعریف_کن SUBLANG_SYS_DEFAULT 0x2
#تعریف_کن SUBLANG_CUSTOM_DEFAULT 0x3
#تعریف_کن SUBLANG_CUSTOM_UNSPECIFIED 0x4
#تعریف_کن SUBLANG_UI_CUSTOM_DEFAULT 0x5

#تعریف_کن SUBLANG_ARABIC_SAUDI_ARABIA 0x01
#تعریف_کن SUBLANG_ARABIC_IRAQ 0x02
#تعریف_کن SUBLANG_ARABIC_EGYPT 0x03
#تعریف_کن SUBLANG_ARABIC_LIBYA 0x04
#تعریف_کن SUBLANG_ARABIC_ALGERIA 0x05
#تعریف_کن SUBLANG_ARABIC_MOROCCO 0x06
#تعریف_کن SUBLANG_ARABIC_TUNISIA 0x07
#تعریف_کن SUBLANG_ARABIC_OMAN 0x08
#تعریف_کن SUBLANG_ARABIC_YEMEN 0x09
#تعریف_کن SUBLANG_ARABIC_SYRIA 0x0a
#تعریف_کن SUBLANG_ARABIC_JORDAN 0x0b
#تعریف_کن SUBLANG_ARABIC_LEBANON 0x0c
#تعریف_کن SUBLANG_ARABIC_KUWAIT 0x0d
#تعریف_کن SUBLANG_ARABIC_UAE 0x0e
#تعریف_کن SUBLANG_ARABIC_BAHRAIN 0x0f
#تعریف_کن SUBLANG_ARABIC_QATAR 0x10
#تعریف_کن SUBLANG_AZERI_LATIN 0x01
#تعریف_کن SUBLANG_AZERI_CYRILLIC 0x02
#تعریف_کن SUBLANG_CHINESE_TRADITIONAL 0x01
#تعریف_کن SUBLANG_CHINESE_SIMPLIFIED 0x02
#تعریف_کن SUBLANG_CHINESE_HONGKONG 0x03
#تعریف_کن SUBLANG_CHINESE_SINGAPORE 0x04
#تعریف_کن SUBLANG_CHINESE_MACAU 0x05
#تعریف_کن SUBLANG_DUTCH 0x01
#تعریف_کن SUBLANG_DUTCH_BELGIAN 0x02
#تعریف_کن SUBLANG_ENGLISH_US 0x01
#تعریف_کن SUBLANG_ENGLISH_UK 0x02
#تعریف_کن SUBLANG_ENGLISH_AUS 0x03
#تعریف_کن SUBLANG_ENGLISH_CAN 0x04
#تعریف_کن SUBLANG_ENGLISH_NZ 0x05
#تعریف_کن SUBLANG_ENGLISH_EIRE 0x06
#تعریف_کن SUBLANG_ENGLISH_SOUTH_AFRICA 0x07
#تعریف_کن SUBLANG_ENGLISH_JAMAICA 0x08
#تعریف_کن SUBLANG_ENGLISH_CARIBBEAN 0x09
#تعریف_کن SUBLANG_ENGLISH_BELIZE 0x0a
#تعریف_کن SUBLANG_ENGLISH_TRINIDAD 0x0b
#تعریف_کن SUBLANG_ENGLISH_ZIMBABWE 0x0c
#تعریف_کن SUBLANG_ENGLISH_PHILIPPINES 0x0d
#تعریف_کن SUBLANG_FRENCH 0x01
#تعریف_کن SUBLANG_FRENCH_BELGIAN 0x02
#تعریف_کن SUBLANG_FRENCH_CANADIAN 0x03
#تعریف_کن SUBLANG_FRENCH_SWISS 0x04
#تعریف_کن SUBLANG_FRENCH_LUXEMBOURG 0x05
#تعریف_کن SUBLANG_FRENCH_MONACO 0x06
#تعریف_کن SUBLANG_GERMAN 0x01
#تعریف_کن SUBLANG_GERMAN_SWISS 0x02
#تعریف_کن SUBLANG_GERMAN_AUSTRIAN 0x03
#تعریف_کن SUBLANG_GERMAN_LUXEMBOURG 0x04
#تعریف_کن SUBLANG_GERMAN_LIECHTENSTEIN 0x05
#تعریف_کن SUBLANG_ITALIAN 0x01
#تعریف_کن SUBLANG_ITALIAN_SWISS 0x02
#تعریف_کن SUBLANG_KASHMIRI_SASIA 0x02
#تعریف_کن SUBLANG_KASHMIRI_INDIA 0x02
#تعریف_کن SUBLANG_KOREAN 0x01
#تعریف_کن SUBLANG_LITHUANIAN 0x01
#تعریف_کن SUBLANG_MALAY_MALAYSIA 0x01
#تعریف_کن SUBLANG_MALAY_BRUNEI_DARUSSALAM 0x02
#تعریف_کن SUBLANG_NEPALI_INDIA 0x02
#تعریف_کن SUBLANG_NORWEGIAN_BOKMAL 0x01
#تعریف_کن SUBLANG_NORWEGIAN_NYNORSK 0x02
#تعریف_کن SUBLANG_PORTUGUESE 0x02
#تعریف_کن SUBLANG_PORTUGUESE_BRAZILIAN 0x01
#تعریف_کن SUBLANG_SERBIAN_LATIN 0x02
#تعریف_کن SUBLANG_SERBIAN_CYRILLIC 0x03
#تعریف_کن SUBLANG_SPANISH 0x01
#تعریف_کن SUBLANG_SPANISH_MEXICAN 0x02
#تعریف_کن SUBLANG_SPANISH_MODERN 0x03
#تعریف_کن SUBLANG_SPANISH_GUATEMALA 0x04
#تعریف_کن SUBLANG_SPANISH_COSTA_RICA 0x05
#تعریف_کن SUBLANG_SPANISH_PANAMA 0x06
#تعریف_کن SUBLANG_SPANISH_DOMINICAN_REPUBLIC 0x07
#تعریف_کن SUBLANG_SPANISH_VENEZUELA 0x08
#تعریف_کن SUBLANG_SPANISH_COLOMBIA 0x09
#تعریف_کن SUBLANG_SPANISH_PERU 0x0a
#تعریف_کن SUBLANG_SPANISH_ARGENTINA 0x0b
#تعریف_کن SUBLANG_SPANISH_ECUADOR 0x0c
#تعریف_کن SUBLANG_SPANISH_CHILE 0x0d
#تعریف_کن SUBLANG_SPANISH_URUGUAY 0x0e
#تعریف_کن SUBLANG_SPANISH_PARAGUAY 0x0f
#تعریف_کن SUBLANG_SPANISH_BOLIVIA 0x10
#تعریف_کن SUBLANG_SPANISH_EL_SALVADOR 0x11
#تعریف_کن SUBLANG_SPANISH_HONDURAS 0x12
#تعریف_کن SUBLANG_SPANISH_NICARAGUA 0x13
#تعریف_کن SUBLANG_SPANISH_PUERTO_RICO 0x14
#تعریف_کن SUBLANG_SWEDISH 0x01
#تعریف_کن SUBLANG_SWEDISH_FINLAND 0x02
#تعریف_کن SUBLANG_URDU_PAKISTAN 0x01
#تعریف_کن SUBLANG_URDU_INDIA 0x02
#تعریف_کن SUBLANG_UZBEK_LATIN 0x01
#تعریف_کن SUBLANG_UZBEK_CYRILLIC 0x02

#تعریف_کن مرتب_سازی_DEFAULT 0x0
#تعریف_کن مرتب_سازی_INVARIANT_MATH 0x1

#تعریف_کن مرتب_سازی_JAPANESE_XJIS 0x0
#تعریف_کن مرتب_سازی_JAPANESE_UNICODE 0x1
#تعریف_کن مرتب_سازی_JAPANESE_RADICALSTROKE 0x4

#تعریف_کن مرتب_سازی_CHINESE_BIG5 0x0
#تعریف_کن مرتب_سازی_CHINESE_PRCP 0x0
#تعریف_کن مرتب_سازی_CHINESE_UNICODE 0x1
#تعریف_کن مرتب_سازی_CHINESE_PRC 0x2
#تعریف_کن مرتب_سازی_CHINESE_BOPOMOFO 0x3

#تعریف_کن مرتب_سازی_KOREAN_KSC 0x0
#تعریف_کن مرتب_سازی_KOREAN_UNICODE 0x1

#تعریف_کن مرتب_سازی_GERMAN_PHONE_BOOK 0x1

#تعریف_کن مرتب_سازی_HUNGARIAN_DEFAULT 0x0
#تعریف_کن مرتب_سازی_HUNGARIAN_TECHNICAL 0x1

#تعریف_کن مرتب_سازی_GEORGIAN_TRADITIONAL 0x0
#تعریف_کن مرتب_سازی_GEORGIAN_MODERN 0x1

#تعریف_کن MAKELANGID(p,s) ((((کلمه_3)(s)) << 10) | (کلمه_3)(p))
#تعریف_کن PRIMARYLANGID(lgid) ((کلمه_3)(lgid) & 0x3ff)
#تعریف_کن SUBLANGID(lgid) ((کلمه_3)(lgid) >> 10)

#تعریف_کن NLS_VALID_LOCALE_ماسک 0x000fffff

#تعریف_کن MAKELCID(lgid,srtid) ((DWORD)((((DWORD)((کلمه_3)(srtid))) << 16) | ((DWORD)((کلمه_3)(lgid)))))
#تعریف_کن MAKESORTLCID(lgid,srtid,ver) ((DWORD)((MAKELCID(lgid,srtid)) | (((DWORD)((کلمه_3)(ver))) << 20)))
#تعریف_کن LANGIDFROMLCID(lcid) ((کلمه_3)(lcid))
#تعریف_کن SORTIDFROMLCID(lcid) ((کلمه_3)((((DWORD)(lcid)) >> 16) & 0xf))
#تعریف_کن SORTVERSIONFROMLCID(lcid) ((کلمه_3)((((DWORD)(lcid)) >> 20) & 0xf))

#تعریف_کن LOCALE_NAME_MAX_درازی 85
#تعریف_کن LANG_SYSTEM_DEFAULT (MAKELANGID(LANG_NEUTRAL,SUBLANG_SYS_DEFAULT))
#تعریف_کن LANG_USER_DEFAULT (MAKELANGID(LANG_NEUTRAL,SUBLANG_DEFAULT))

#تعریف_کن LOCALE_SYSTEM_DEFAULT (MAKELCID(LANG_SYSTEM_DEFAULT,مرتب_سازی_DEFAULT))
#تعریف_کن LOCALE_USER_DEFAULT (MAKELCID(LANG_USER_DEFAULT,مرتب_سازی_DEFAULT))

#تعریف_کن LOCALE_NEUTRAL (MAKELCID(MAKELANGID(LANG_NEUTRAL,SUBLANG_NEUTRAL),مرتب_سازی_DEFAULT))

#تعریف_کن LOCALE_CUSTOM_DEFAULT (MAKELCID(MAKELANGID(LANG_NEUTRAL, SUBLANG_CUSTOM_DEFAULT), مرتب_سازی_DEFAULT))
#تعریف_کن LOCALE_CUSTOM_UNSPECIFIED (MAKELCID(MAKELANGID(LANG_NEUTRAL, SUBLANG_CUSTOM_UNSPECIFIED), مرتب_سازی_DEFAULT))
#تعریف_کن LOCALE_CUSTOM_UI_DEFAULT (MAKELCID(MAKELANGID(LANG_NEUTRAL, SUBLANG_UI_CUSTOM_DEFAULT), مرتب_سازی_DEFAULT))

#تعریف_کن LOCALE_INVARIANT (MAKELCID(MAKELANGID(LANG_INVARIANT,SUBLANG_NEUTRAL),مرتب_سازی_DEFAULT))

#تعریف_کن UNREFERENCED_PARAMETER(P) (P)
#تعریف_کن DBG_UNREFERENCED_PARAMETER(P) (P)
#تعریف_کن DBG_UNREFERENCED_LOCAL_VARIABLE(V) (V)

#تعریف_کن DEFAULT_UNREACHABLE

#اگر_تعریف_نشده WIN32_NO_وضعیت
#تعریف_کن وضعیت_WAIT_0 ((DWORD)0x00000000L)
#تعریف_کن وضعیت_ABANDONED_WAIT_0 ((DWORD)0x00000080L)
#تعریف_کن وضعیت_USER_APC ((DWORD)0x000000C0L)
#تعریف_کن وضعیت_TIMEOUT ((DWORD)0x00000102L)
#تعریف_کن وضعیت_PENDING ((DWORD)0x00000103L)
#تعریف_کن DBG_EXCEPTION_HANDLED ((DWORD)0x00010001L)
#تعریف_کن DBG_CONTINUE ((DWORD)0x00010002L)
#تعریف_کن وضعیت_SEGMENT_NOTIFICATION ((DWORD)0x40000005L)
#تعریف_کن DBG_TERMINATE_THREAD ((DWORD)0x40010003L)
#تعریف_کن DBG_TERMINATE_PROCESS ((DWORD)0x40010004L)
#تعریف_کن DBG_CONTROL_C ((DWORD)0x40010005L)
#تعریف_کن DBG_CONTROL_BREAK ((DWORD)0x40010008L)
#تعریف_کن DBG_COMMAND_EXCEPTION ((DWORD)0x40010009L)
#تعریف_کن وضعیت_GUARD_صفحه_VIOLATION ((DWORD)0x80000001L)
#تعریف_کن وضعیت_DATATYPE_MISALIGNMENT ((DWORD)0x80000002L)
#تعریف_کن وضعیت_BREAKPOINT ((DWORD)0x80000003L)
#تعریف_کن وضعیت_SINGLE_گام ((DWORD)0x80000004L)
#تعریف_کن DBG_EXCEPTION_NOT_HANDLED ((DWORD)0x80010001L)
#تعریف_کن وضعیت_ACCESS_VIOLATION ((DWORD)0xC0000005L)
#تعریف_کن وضعیت_درون_صفحه_ERROR ((DWORD)0xC0000006L)
#تعریف_کن وضعیت_INVALID_HANDLE ((DWORD)0xC0000008L)
#تعریف_کن وضعیت_NO_حافظه ((DWORD)0xC0000017L)
#تعریف_کن وضعیت_ILLEGAL_INSTRUCTION ((DWORD)0xC000001DL)
#تعریف_کن وضعیت_NONCONTINUABLE_EXCEPTION ((DWORD)0xC0000025L)
#تعریف_کن وضعیت_INVALID_DISPOSITION ((DWORD)0xC0000026L)
#تعریف_کن وضعیت_ARRAY_BOUNDS_EXCEEDED ((DWORD)0xC000008CL)
#تعریف_کن وضعیت_FLOAT_DENORMAL_عملوند ((DWORD)0xC000008DL)
#تعریف_کن وضعیت_FLOAT_DIVIDE_BY_ZERO ((DWORD)0xC000008EL)
#تعریف_کن وضعیت_FLOAT_INEXACT_نتیجه ((DWORD)0xC000008FL)
#تعریف_کن وضعیت_FLOAT_INVALID_OPERATION ((DWORD)0xC0000090L)
#تعریف_کن وضعیت_FLOAT_سرریز ((DWORD)0xC0000091L)
#تعریف_کن وضعیت_FLOAT_پشته_CHECK ((DWORD)0xC0000092L)
#تعریف_کن وضعیت_FLOAT_UNDERFLOW ((DWORD)0xC0000093L)
#تعریف_کن وضعیت_INTEGER_DIVIDE_BY_ZERO ((DWORD)0xC0000094L)
#تعریف_کن وضعیت_INTEGER_سرریز ((DWORD)0xC0000095L)
#تعریف_کن وضعیت_PRIVILEGED_INSTRUCTION ((DWORD)0xC0000096L)
#تعریف_کن وضعیت_پشته_سرریز ((DWORD)0xC00000FDL)
#تعریف_کن وضعیت_CONTROL_C_EXIT ((DWORD)0xC000013AL)
#تعریف_کن وضعیت_FLOAT_مضرب_خطاها ((DWORD)0xC00002B4L)
#تعریف_کن وضعیت_FLOAT_مضرب_TRAPS ((DWORD)0xC00002B5L)
#تعریف_کن وضعیت_REG_NAT_CONSUMPTION ((DWORD)0xC00002C9L)
#تعریف_کن وضعیت_SXS_EARLY_DEACTIVATION ((DWORD)0xC015000FL)
#تعریف_کن وضعیت_SXS_INVALID_DEACTIVATION ((DWORD)0xC0150010L)
#پایان_اگر

#تعریف_کن بیشینه_WAIT_OBJECTS 64
#تعریف_کن بیشینه_SUSPEND_شمار MAXCHAR

  تعريفنوع ULONG_PTR KSPIN_قفل;
  تعريفنوع KSPIN_قفل *PKSPIN_قفل;

#إذا defined(__x86_64) && !defined(RC_INVOKED)

#اگر_تعریف_شده __cplusplus
  خارجي "C" {
#پایان_اگر

#تعریف_کن بیت_Test _bittest
#تعریف_کن بیت_Test_And_Complement _bittestandcomplement
#تعریف_کن بیت_Test_And_مجموعه _bittestandset
#تعریف_کن بیت_Test_And_Reset _bittestandreset
#تعریف_کن Interlocked_بیت_Test_And_مجموعه _interlockedbittestandset
#تعریف_کن Interlocked_بیت_Test_And_Reset _interlockedbittestandreset
#تعریف_کن بیت_Test64 _bittest64
#تعریف_کن بیت_Test_And_Complement64 _bittestandcomplement64
#تعریف_کن بیت_Test_And_Set64 _bittestandset64
#تعریف_کن بیت_Test_And_Reset64 _bittestandreset64
#تعریف_کن Interlocked_بیت_Test_And_Set64 _interlockedbittestandset64
#تعریف_کن Interlocked_بیت_Test_And_Reset64 _interlockedbittestandreset64

    __CRT_INLINE BOOLEAN _bittest(LONG ثابت *پایه_2,LONG جابه_جایی_3) {
      صحيح old = 0;
      __asm__ __volatile__("btl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متطاير دراز *) پایه_2))
	:"Ir" (جابه_جایی_3));
      أرجع (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandcomplement(LONG *پایه_2,LONG جابه_جایی_3) {
      صحيح old = 0;
      __asm__ __volatile__("btcl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متطاير دراز *) پایه_2))
	:"Ir" (جابه_جایی_3));
      أرجع (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN Interlocked_بیت_Test_And_Complement(LONG *پایه_2,LONG بیت_2) {
      صحيح old = 0;
      __asm__ __volatile__("lock ; btcl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متطاير دراز *) پایه_2))
	:"Ir" (بیت_2));
      أرجع (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandset(LONG *پایه_2,LONG جابه_جایی_3) {
      صحيح old = 0;
      __asm__ __volatile__("btsl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متطاير دراز *) پایه_2))
	:"Ir" (جابه_جایی_3));
      أرجع (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandreset(LONG *پایه_2,LONG جابه_جایی_3) {
      صحيح old = 0;
      __asm__ __volatile__("btrl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متطاير دراز *) پایه_2))
	:"Ir" (جابه_جایی_3));
      أرجع (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _interlockedbittestandset(LONG *پایه_2,LONG جابه_جایی_3) {
      صحيح old = 0;
      __asm__ __volatile__("lock ; btsl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متطاير دراز *) پایه_2))
	:"Ir" (جابه_جایی_3));
      أرجع (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _interlockedbittestandreset(LONG *پایه_2,LONG جابه_جایی_3) {
      صحيح old = 0;
      __asm__ __volatile__("lock ; btrl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متطاير دراز *) پایه_2))
	:"Ir" (جابه_جایی_3));
      أرجع (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittest64(LONG64 ثابت *پایه_2,LONG64 جابه_جایی_3) {
      صحيح old = 0;
      __asm__ __volatile__("btq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متطاير دراز دراز *) پایه_2))
	:"Ir" (جابه_جایی_3));
      أرجع (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandcomplement64(LONG64 *پایه_2,LONG64 جابه_جایی_3) {
      صحيح old = 0;
      __asm__ __volatile__("btcq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متطاير دراز دراز *) پایه_2))
	:"Ir" (جابه_جایی_3));
      أرجع (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandset64(LONG64 *پایه_2,LONG64 جابه_جایی_3) {
      صحيح old = 0;
      __asm__ __volatile__("btsq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متطاير دراز دراز *) پایه_2))
	:"Ir" (جابه_جایی_3));
      أرجع (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandreset64(LONG64 *پایه_2,LONG64 جابه_جایی_3) {
      صحيح old = 0;
      __asm__ __volatile__("btrq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متطاير دراز دراز *) پایه_2))
	:"Ir" (جابه_جایی_3));
      أرجع (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _interlockedbittestandset64(LONG64 *پایه_2,LONG64 جابه_جایی_3) {
      صحيح old = 0;
      __asm__ __volatile__("lock ; btsq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متطاير دراز دراز *) پایه_2))
	:"Ir" (جابه_جایی_3));
      أرجع (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _interlockedbittestandreset64(LONG64 *پایه_2,LONG64 جابه_جایی_3) {
      صحيح old = 0;
      __asm__ __volatile__("lock ; btrq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متطاير دراز دراز *) پایه_2))
	:"Ir" (جابه_جایی_3));
      أرجع (BOOLEAN) (old!=0);
    }
#تعریف_کن بیت_پیمایش_Forward بیت_پیمایش_Forward_2
#تعریف_کن بیت_پیمایش_معکوس بیت_پیمایش_معکوس_2
#تعریف_کن بیت_پیمایش_Forward64 بیت_پیمایش_Forward64_2
#تعریف_کن بیت_پیمایش_Reverse64 بیت_پیمایش_Reverse64_2

    __CRT_INLINE BOOLEAN بیت_پیمایش_Forward_2(DWORD *شاخص_3,DWORD ماسک_3) {
      __asm__ __volatile__("bsfl %1,%0" : "=r" (ماسک_3),"=m" ((*(متطاير دراز *)شاخص_3)));
      أرجع ماسک_3!=0;
    }
    __CRT_INLINE BOOLEAN بیت_پیمایش_معکوس_2(DWORD *شاخص_3,DWORD ماسک_3) {
      __asm__ __volatile__("bsrl %1,%0" : "=r" (ماسک_3),"=m" ((*(متطاير دراز *)شاخص_3)));
      أرجع ماسک_3!=0;
    }
    __CRT_INLINE BOOLEAN بیت_پیمایش_Forward64_2(DWORD *شاخص_3,DWORD64 ماسک_3) {
      __asm__ __volatile__("bsfq %1,%0" : "=r" (ماسک_3),"=m" ((*(متطاير دراز دراز *)شاخص_3)));
      أرجع ماسک_3!=0;
    }
    __CRT_INLINE BOOLEAN بیت_پیمایش_Reverse64_2(DWORD *شاخص_3,DWORD64 ماسک_3) {
      __asm__ __volatile__("bsrq %1,%0" : "=r" (ماسک_3),"=m" ((*(متطاير دراز دراز *)شاخص_3)));
      أرجع ماسک_3!=0;
    }

#تعریف_کن InterlockedIncrement16 _InterlockedIncrement16
#تعریف_کن InterlockedDecrement16 _InterlockedDecrement16
#تعریف_کن InterlockedCompareExchange16 _InterlockedCompareExchange16

#تعریف_کن InterlockedAnd _InterlockedAnd
#تعریف_کن InterlockedOr _InterlockedOr
#تعریف_کن InterlockedXor _InterlockedXor
#تعریف_کن InterlockedIncrement _InterlockedIncrement
#تعریف_کن InterlockedIncrementAcquire InterlockedIncrement
#تعریف_کن InterlockedIncrementRelease InterlockedIncrement
#تعریف_کن InterlockedDecrement _InterlockedDecrement
#تعریف_کن InterlockedDecrementAcquire InterlockedDecrement
#تعریف_کن InterlockedDecrementRelease InterlockedDecrement
#تعریف_کن Interlocked_جمع_کن Interlocked_جمع_کن_2
#تعریف_کن InterlockedExchange _InterlockedExchange
#تعریف_کن Interlocked_Exchange_جمع_کن Interlocked_Exchange_جمع_کن_2
#تعریف_کن InterlockedCompareExchange _InterlockedCompareExchange
#تعریف_کن InterlockedCompareExchangeAcquire InterlockedCompareExchange
#تعریف_کن InterlockedCompareExchangeRelease InterlockedCompareExchange

#تعریف_کن InterlockedAnd64 _InterlockedAnd64
#تعریف_کن InterlockedAndAffinity InterlockedAnd64
#تعریف_کن InterlockedOr64 _InterlockedOr64
#تعریف_کن InterlockedOrAffinity InterlockedOr64
#تعریف_کن InterlockedXor64 _InterlockedXor64
#تعریف_کن InterlockedIncrement64 _InterlockedIncrement64
#تعریف_کن InterlockedDecrement64 _InterlockedDecrement64
#تعریف_کن InterlockedAdd64 _InterlockedAdd64
#تعریف_کن InterlockedExchange64 _InterlockedExchange64
#تعریف_کن InterlockedExchangeAcquire64 InterlockedExchange64
#تعریف_کن InterlockedExchangeAdd64 _InterlockedExchangeAdd64
#تعریف_کن InterlockedCompareExchange64 _InterlockedCompareExchange64
#تعریف_کن InterlockedCompareExchangeAcquire64 InterlockedCompareExchange64
#تعریف_کن InterlockedCompareExchangeRelease64 InterlockedCompareExchange64

#تعریف_کن Interlocked_Exchange_اشاره_گر Interlocked_Exchange_اشاره_گر_2
#تعریف_کن Interlocked_Compare_Exchange_اشاره_گر Interlocked_Compare_Exchange_اشاره_گر_2
#تعریف_کن Interlocked_Compare_Exchange_اشاره_گر_Acquire Interlocked_Compare_Exchange_اشاره_گر_2
#تعریف_کن Interlocked_Compare_Exchange_اشاره_گر_Release Interlocked_Compare_Exchange_اشاره_گر_2

#تعریف_کن Interlocked_Exchange_جمع_کن_اندازه_T(a,b) InterlockedExchangeAdd64((LONG64 *)a,b)
#تعریف_کن Interlocked_Increment_اندازه_T(a) InterlockedIncrement64((LONG64 *)a)
#تعریف_کن Interlocked_Decrement_اندازه_T(a) InterlockedDecrement64((LONG64 *)a)

    __CRT_INLINE SHORT InterlockedIncrement16(SHORT متطاير *Addend) {
      بیعلامت حرف c;
      بیعلامت حرف s;
      __asm__ __volatile__(
	"lock ; addw $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      أرجع (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE SHORT InterlockedDecrement16(SHORT متطاير *Addend) {
      بیعلامت حرف c;
      بیعلامت حرف s;
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
    __CRT_INLINE LONG InterlockedAnd(LONG متطاير *Destination,LONG مقدار_3) {
      __asm__ __volatile__("lock ; andl %0,%1"
	: :"r"(مقدار_3),"m"(*Destination)
	: "memory");
      أرجع *Destination;
    }
    __CRT_INLINE LONG InterlockedOr(LONG متطاير *Destination,LONG مقدار_3) {
      __asm__ __volatile__("lock ; orl %0,%1"
	: : "r"(مقدار_3),"m"(*Destination) : "memory");
      أرجع *Destination;
    }
    __CRT_INLINE LONG InterlockedXor(LONG متطاير *Destination,LONG مقدار_3) {
      __asm__ __volatile__("lock ; xorl %0,%1"
	: : "r"(مقدار_3),"m"(*Destination) : "memory");
      أرجع *Destination;
    }
    //		$$$$
    __CRT_INLINE LONG64 InterlockedAnd64(LONG64 متطاير *Destination,LONG64 مقدار_3) {
      __asm__ __volatile__("lock ; andq %0,%1"
	: : "r"(مقدار_3),"m"(*Destination) : "memory");
      أرجع *Destination;
    }
    __CRT_INLINE LONG64 InterlockedOr64(LONG64 متطاير *Destination,LONG64 مقدار_3) {
      __asm__ __volatile__("lock ; orq %0,%1"
	: : "r"(مقدار_3),"m"(*Destination) : "memory");
      أرجع *Destination;
    }
    __CRT_INLINE LONG64 InterlockedXor64(LONG64 متطاير *Destination,LONG64 مقدار_3) {
      __asm__ __volatile__("lock ; xorq %0,%1"
	: : "r"(مقدار_3),"m"(*Destination) : "memory");
      أرجع *Destination;
    }
    __CRT_INLINE LONG InterlockedIncrement(LONG متطاير *Addend) {
      بیعلامت حرف c;
      بیعلامت حرف s;
      __asm__ __volatile__(
	"lock ; addl $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      أرجع (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE LONG InterlockedDecrement(LONG متطاير *Addend) {
      بیعلامت حرف c;
      بیعلامت حرف s;
      __asm__ __volatile__(
	"lock ; subl $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      أرجع (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE LONG InterlockedExchange(LONG متطاير *هدف_2,LONG مقدار_3) {
      __asm__ __volatile("lock ; xchgl %0,%1"
	: "=r"(مقدار_3)
	: "m"(*هدف_2),"0"(مقدار_3)
	: "memory");
      أرجع مقدار_3;
    }
    LONG Interlocked_Exchange_جمع_کن(LONG متطاير *Addend,LONG مقدار_3);

#اگر_تعریف_نشده _X86AMD64_
    __CRT_INLINE LONG Interlocked_جمع_کن(LONG متطاير *Addend,LONG مقدار_3) { أرجع Interlocked_Exchange_جمع_کن(Addend,مقدار_3) + مقدار_3; }
#پایان_اگر
    __CRT_INLINE LONG InterlockedCompareExchange(LONG متطاير *Destination,LONG ExChange,LONG Comperand) {
      LONG prev;
      __asm__ __volatile__("lock ; cmpxchgl %1,%2" : "=a" (prev) : "q" (ExChange),"m" (*Destination), "0" (Comperand) : "memory");
      أرجع prev;
    }
    __CRT_INLINE LONG64 InterlockedIncrement64(LONG64 متطاير *Addend) {
      بیعلامت حرف c;
      بیعلامت حرف s;
      __asm__ __volatile__(
	"lock ; addq $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      أرجع (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE LONG64 InterlockedDecrement64(LONG64 متطاير *Addend) {
      بیعلامت حرف c;
      بیعلامت حرف s;
      __asm__ __volatile__(
	"lock ; subq $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      أرجع (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE LONG64 InterlockedExchange64(LONG64 متطاير *هدف_2,LONG64 مقدار_3) {
      __asm__ __volatile("lock ; xchgq %0,%1"
	: "=r"(مقدار_3)
	: "m"(*هدف_2),"0"(مقدار_3)
	: "memory");
      أرجع مقدار_3;
    }
    LONG64 InterlockedExchangeAdd64(LONG64 متطاير *Addend,LONG64 مقدار_3);

#اگر_تعریف_نشده _X86AMD64_
    __CRT_INLINE LONG64 InterlockedAdd64(LONG64 متطاير *Addend,LONG64 مقدار_3) { أرجع InterlockedExchangeAdd64(Addend,مقدار_3) + مقدار_3; }
#پایان_اگر

    __CRT_INLINE LONG64 InterlockedCompareExchange64(LONG64 متطاير *Destination,LONG64 ExChange,LONG64 Comperand) {
      LONG64 prev;
      __asm__ __volatile__("lock ; cmpxchgq %1,%2" : "=a" (prev) : "q" (ExChange),"m" (*Destination), "0" (Comperand) : "memory");
      أرجع prev;
    }
    __CRT_INLINE PVOID Interlocked_Compare_Exchange_اشاره_گر(PVOID متطاير *Destination,PVOID ExChange,PVOID Comperand) {
      PVOID prev;
      __asm__ __volatile__("lock ; cmpxchgq %1,%2" : "=a" (prev) : "q" (ExChange),"m" (*Destination), "0" (Comperand) : "memory");
      أرجع prev;
    }
    __CRT_INLINE PVOID Interlocked_Exchange_اشاره_گر(PVOID متطاير *هدف_2,PVOID مقدار_3) {
      __asm__ __volatile("lock ; xchgq %0,%1"
	: "=r"(مقدار_3)
	: "m"(*هدف_2),"0"(مقدار_3)
	: "memory");
      أرجع مقدار_3;
    }

#تعریف_کن Cache_سطر_Flush(آدرس_2) _mm_clflush(آدرس_2)

    VOID _ReadWriteBarrier(VOID);

#تعریف_کن FastFence __faststorefence
#تعریف_کن بارگیری_Fence _mm_lfence
#تعریف_کن حافظه_Fence _mm_mfence
#تعریف_کن StoreFence _mm_sfence

    VOID __faststorefence(VOID);
    VOID _m_prefetchw(متطاير CONST VOID *منبع_2);

//!__TINYC__: #include <intrin.h>

#تعریف_کن YieldProcessor _mm_pause
#تعریف_کن حافظه_Barrier __faststorefence
#تعریف_کن Pre_Fetch_Cache_سطر(l,a) _mm_prefetch((CHAR CONST *) a,l)
#تعریف_کن PrefetchForWrite(p) _m_prefetchw(p)
#تعریف_کن ReadForWriteAccess(p) (_m_prefetchw(p),*(p))

#تعریف_کن PF_TEMPORAL_LEVEL_1 _MM_HINT_T0
#تعریف_کن PF_TEMPORAL_LEVEL_2 _MM_HINT_T1
#تعریف_کن PF_TEMPORAL_LEVEL_3 _MM_HINT_T2
#تعریف_کن PF_NON_TEMPORAL_LEVEL_ALL _MM_HINT_NTA

#تعریف_کن ReadMxCsr _mm_getcsr
#تعریف_کن WriteMxCsr _mm_setcsr

    VOID __int2c(VOID);

#تعریف_کن DbgRaiseAssertionFailure() __int2c()
#تعریف_کن GetCallersEflags() __getcallerseflags()

    بیعلامت __int32 __getcallerseflags(VOID);

#تعریف_کن Get_Segment_حد __segmentlimit

    DWORD __segmentlimit(DWORD Selector);

#تعریف_کن Read_زمان_Stamp_Counter() __rdtsc()

    DWORD64 __rdtsc(VOID);
    VOID __movsb(PBYTE Destination,BYTE ثابت *منبع_2,اندازه_T شمار_3);
    VOID __movsw(PWORD Destination,کلمه_3 ثابت *منبع_2,اندازه_T شمار_3);
    VOID __movsd(PDWORD Destination,DWORD ثابت *منبع_2,اندازه_T شمار_3);
    VOID __movsq(PDWORD64 Destination,DWORD64 ثابت *منبع_2,اندازه_T شمار_3);
    VOID __stosb(PBYTE Destination,BYTE مقدار_3,اندازه_T شمار_3);
    VOID __stosw(PWORD Destination,کلمه_3 مقدار_3,اندازه_T شمار_3);
    VOID __stosd(PDWORD Destination,DWORD مقدار_3,اندازه_T شمار_3);
    VOID __stosq(PDWORD64 Destination,DWORD64 مقدار_3,اندازه_T شمار_3);

#تعریف_کن Multiply_بالا __mulh
#تعریف_کن Unsigned_Multiply_بالا __umulh

    LONGLONG Multiply_بالا(LONGLONG Multiplier,LONGLONG Multiplicand);
    ULONGLONG Unsigned_Multiply_بالا(ULONGLONG Multiplier,ULONGLONG Multiplicand);

#تعریف_کن لغزش_Left128 __shiftleft128
#تعریف_کن لغزش_Right128 __shiftright128

    DWORD64 لغزش_Left128(DWORD64 کم_Part,DWORD64 بالا_Part,BYTE لغزش_3);
    DWORD64 لغزش_Right128(DWORD64 کم_Part,DWORD64 بالا_Part,BYTE لغزش_3);

#تعریف_کن Multiply128 _mul128

    LONG64 Multiply128(LONG64 Multiplier,LONG64 Multiplicand,LONG64 *بالا_حاصلضرب);

#تعریف_کن UnsignedMultiply128 _umul128

    DWORD64 UnsignedMultiply128(DWORD64 Multiplier,DWORD64 Multiplicand,DWORD64 *بالا_حاصلضرب);

    __CRT_INLINE LONG64 MultiplyExtract128(LONG64 Multiplier,LONG64 Multiplicand,BYTE لغزش_3) {
      LONG64 extracted_حاصلضرب;
      LONG64 بالا_حاصلضرب_2;
      LONG64 کم_حاصلضرب;
      کم_حاصلضرب = Multiply128(Multiplier,Multiplicand,&بالا_حاصلضرب_2);
      extracted_حاصلضرب = (LONG64)لغزش_Right128((LONG64)کم_حاصلضرب,(LONG64)بالا_حاصلضرب_2,لغزش_3);
      أرجع extracted_حاصلضرب;
    }

    __CRT_INLINE DWORD64 UnsignedMultiplyExtract128(DWORD64 Multiplier,DWORD64 Multiplicand,BYTE لغزش_3) {
      DWORD64 extracted_حاصلضرب;
      DWORD64 بالا_حاصلضرب_2;
      DWORD64 کم_حاصلضرب;
      کم_حاصلضرب = UnsignedMultiply128(Multiplier,Multiplicand,&بالا_حاصلضرب_2);
      extracted_حاصلضرب = لغزش_Right128(کم_حاصلضرب,بالا_حاصلضرب_2,لغزش_3);
      أرجع extracted_حاصلضرب;
    }

    __CRT_INLINE BYTE __readgsbyte(DWORD جابه_جایی_3) {
      BYTE ret;
      __asm__ متطاير ("movb	%%gs:%1,%0"
	: "=r" (ret) ,"=m" ((*(متطاير دراز *) (DWORD64) جابه_جایی_3)));
      أرجع ret;
    }
    __CRT_INLINE کلمه_3 __readgsword(DWORD جابه_جایی_3) {
      کلمه_3 ret;
      __asm__ متطاير ("movw	%%gs:%1,%0"
	: "=r" (ret) ,"=m" ((*(متطاير دراز *) (DWORD64) جابه_جایی_3)));
      أرجع ret;
    }
    __CRT_INLINE DWORD __readgsdword(DWORD جابه_جایی_3) {
      DWORD ret;
      __asm__ متطاير ("movl	%%gs:%1,%0"
	: "=r" (ret) ,"=m" ((*(متطاير دراز *) (DWORD64) جابه_جایی_3)));
      أرجع ret;
    }
    __CRT_INLINE DWORD64 __readgsqword(DWORD جابه_جایی_3) {
      فراغ *ret;
      __asm__ متطاير ("movq	%%gs:%1,%0"
	: "=r" (ret) ,"=m" ((*(متطاير دراز *) (DWORD64) جابه_جایی_3)));
      أرجع (DWORD64) ret;
    }
    __CRT_INLINE VOID __writegsbyte(DWORD جابه_جایی_3,BYTE داده_3) {
      __asm__ متطاير ("movb	%0,%%gs:%1"
	: "=r" (داده_3) ,"=m" ((*(متطاير دراز *) (DWORD64) جابه_جایی_3)));
    }
    __CRT_INLINE VOID __writegsword(DWORD جابه_جایی_3,کلمه_3 داده_3) {
      __asm__ متطاير ("movw	%0,%%gs:%1"
	: "=r" (داده_3) ,"=m" ((*(متطاير دراز *) (DWORD64) جابه_جایی_3)));
    }
    __CRT_INLINE VOID __writegsdword(DWORD جابه_جایی_3,DWORD داده_3) {
      __asm__ متطاير ("movl	%0,%%gs:%1"
	: "=r" (داده_3) ,"=m" ((*(متطاير دراز *) (DWORD64) جابه_جایی_3)));
    }
    __CRT_INLINE VOID __writegsqword(DWORD جابه_جایی_3,DWORD64 داده_3) {
      __asm__ متطاير ("movq	%0,%%gs:%1"
	: "=r" (داده_3) ,"=m" ((*(متطاير دراز *) (DWORD64) جابه_جایی_3)));
    }

#اگر_تعریف_شده __cplusplus
  }
#پایان_اگر

#تعریف_کن EXCEPTION_READ_FAULT 0
#تعریف_کن EXCEPTION_WRITE_FAULT 1
#تعریف_کن EXCEPTION_EXECUTE_FAULT 8

#إذا !defined(RC_INVOKED)

#تعریف_کن CONTEXT_AMD64 0x100000

#تعریف_کن CONTEXT_CONTROL (CONTEXT_AMD64 | 0x1L)
#تعریف_کن CONTEXT_INTEGER (CONTEXT_AMD64 | 0x2L)
#تعریف_کن CONTEXT_SEGMENTS (CONTEXT_AMD64 | 0x4L)
#تعریف_کن CONTEXT_FLOATING_نقطه (CONTEXT_AMD64 | 0x8L)
#تعریف_کن CONTEXT_DEBUG_REGISTERS (CONTEXT_AMD64 | 0x10L)

#تعریف_کن CONTEXT_پر (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_FLOATING_نقطه)
#تعریف_کن CONTEXT_ALL (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_SEGMENTS | CONTEXT_FLOATING_نقطه | CONTEXT_DEBUG_REGISTERS)

#تعریف_کن CONTEXT_EXCEPTION_فعال 0x8000000
#تعریف_کن CONTEXT_SERVICE_فعال 0x10000000
#تعریف_کن CONTEXT_EXCEPTION_REQUEST 0x40000000
#تعریف_کن CONTEXT_EXCEPTION_REPORTING 0x80000000
#پایان_اگر

#تعریف_کن INITIAL_MXCSR 0x1f80
#تعریف_کن INITIAL_FPCSR 0x027f

  تعريفنوع بنية DECLSPEC_ALIGN(16) _M128A {
    ULONGLONG کم_3;
    LONGLONG بالا_3;
  } M128A,*PM128A;

  تعريفنوع بنية _XMM_SAVE_AREA32 {
    کلمه_3 Control_کلمه;
    کلمه_3 وضعیت_کلمه;
    BYTE برچسب_کلمه;
    BYTE Reserved1;
    کلمه_3 ErrorOpcode;
    DWORD Error_جابه_جایی;
    کلمه_3 ErrorSelector;
    کلمه_3 Reserved2;
    DWORD داده_جابه_جایی_2;
    کلمه_3 داده_Selector;
    کلمه_3 Reserved3;
    DWORD MxCsr;
    DWORD Mx_Csr_ماسک;
    M128A FloatRegisters[8];
    M128A XmmRegisters[16];
    BYTE Reserved4[96];
  } XMM_SAVE_AREA32,*PXMM_SAVE_AREA32;

#تعریف_کن LEGACY_SAVE_AREA_درازی حجم(XMM_SAVE_AREA32)

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
	M128A سرآیند_2[2];
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
    M128A وکتور_ثبات[26];
    DWORD64 وکتور_Control;
    DWORD64 DebugControl;
    DWORD64 آخرین_Branch_مقصد_Rip;
    DWORD64 آخرین_Branch_From_Rip;
    DWORD64 آخرین_Exception_مقصد_Rip;
    DWORD64 آخرین_Exception_From_Rip;
  } CONTEXT,*PCONTEXT;

#تعریف_کن RUNTIME_FUNCTION_غیرمستقیم 0x1

  تعريفنوع بنية _RUNTIME_FUNCTION {
    DWORD Begin_آدرس;
    DWORD انتها_آدرس;
    DWORD Unwind_داده;
  } RUNTIME_FUNCTION,*PRUNTIME_FUNCTION;

  تعريفنوع PRUNTIME_FUNCTION (*PGET_RUNTIME_FUNCTION_CALLBACK)(DWORD64 ControlPc,PVOID Context);
  تعريفنوع DWORD (*POUT_از_PROCESS_FUNCTION_جدول_CALLBACK)(HANDLE Process,PVOID جدول_آدرس,PDWORD Entries,PRUNTIME_FUNCTION *Functions);

#تعریف_کن بیرون_از_PROCESS_FUNCTION_جدول_CALLBACK_EXPORT_NAME "OutOfProcessFunctionTableCallback"
#پایان_اگر /* defined(__x86_64) && !defined(RC_INVOKED) */

#إذا defined(__TINYC__) && (defined(__aarch64__) || defined(__arm64__)) && !defined(RC_INVOKED)

#تعریف_کن __TCC_WINNT_ATOMIC_SEQ_CST 5
/* TCC lowers __atomic_compare_exchange's fourth argument as weak, but the
   ARM64 helper reads it as success_memorder.  Strong CAS passes weak == 0,
   so keep Interlocked's barriers explicit here. */
#تعریف_کن __TCC_WINNT_MEMORY_BARRIER() __asm__ __volatile__("dmb ish" : : : "memory")

/* This covers the LONG operations needed by TCC's semaphore code and the
   pointer helpers that winbase.h exposes through Interlocked pointer macros.
   Add local helpers before relying on increment/decrement, add/exchange-add,
   bitwise, or 64-bit Interlocked forms on Windows ARM64 with TCC. */

    __CRT_INLINE LONG InterlockedExchange(LONG متطاير *هدف_2,LONG مقدار_3) {
      LONG Old;
      __atomic_load(هدف_2,&Old,__TCC_WINNT_ATOMIC_SEQ_CST);
      __TCC_WINNT_MEMORY_BARRIER();
      طالما (!__atomic_compare_exchange(هدف_2,&Old,&مقدار_3,0,
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
    __CRT_INLINE PVOID __TCC_WINNT_InterlockedExchangePointer(PVOID متطاير *هدف_2,PVOID مقدار_3) {
      PVOID Old;
      __atomic_load(هدف_2,&Old,__TCC_WINNT_ATOMIC_SEQ_CST);
      __TCC_WINNT_MEMORY_BARRIER();
      طالما (!__atomic_compare_exchange(هدف_2,&Old,&مقدار_3,0,
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

#تعریف_کن Interlocked_Exchange_اشاره_گر __TCC_WINNT_InterlockedExchangePointer
#تعریف_کن Interlocked_Compare_Exchange_اشاره_گر __TCC_WINNT_InterlockedCompareExchangePointer
#تعریف_کن Interlocked_Compare_Exchange_اشاره_گر_Acquire Interlocked_Compare_Exchange_اشاره_گر
#تعریف_کن Interlocked_Compare_Exchange_اشاره_گر_Release Interlocked_Compare_Exchange_اشاره_گر

#تعریف_کن InterlockedCompareExchangeAcquire InterlockedCompareExchange
#تعریف_کن InterlockedCompareExchangeRelease InterlockedCompareExchange

#لغو_تعریف __TCC_WINNT_MEMORY_BARRIER
#لغو_تعریف __TCC_WINNT_ATOMIC_SEQ_CST

#پایان_اگر /* defined(__TINYC__) && (defined(__aarch64__) || defined(__arm64__)) && !defined(RC_INVOKED) */

#إذا defined(_ARM64_)

/* ARM64 Context Definition */
#تعریف_کن CONTEXT_ARM64 0x00400000
#تعریف_کن CONTEXT_CONTROL (CONTEXT_ARM64 | 0x00000001L)
#تعریف_کن CONTEXT_INTEGER (CONTEXT_ARM64 | 0x00000002L)
#تعریف_کن CONTEXT_FLOATING_نقطه (CONTEXT_ARM64 | 0x00000004L)
#تعریف_کن CONTEXT_DEBUG (CONTEXT_ARM64 | 0x00000008L)
#تعریف_کن CONTEXT_پر (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_FLOATING_نقطه)
#تعریف_کن CONTEXT_ALL (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_FLOATING_نقطه | CONTEXT_DEBUG)
#تعریف_کن ARM64_MAX_BREAKPOINTS 8
#تعریف_کن ARM64_MAX_WATCHPOINTS 2

  تعريفنوع اتحاد _ARM64_NT_NEON128 {
    بنية {
      ULONGLONG کم_3;
      LONGLONG بالا_3;
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
    DWORD Begin_آدرس;
    DWORD Unwind_داده;
  } RUNTIME_FUNCTION,*PRUNTIME_FUNCTION;

  تعريفنوع PRUNTIME_FUNCTION (*PGET_RUNTIME_FUNCTION_CALLBACK)(DWORD64 ControlPc,PVOID Context);
  تعريفنوع DWORD (*POUT_از_PROCESS_FUNCTION_جدول_CALLBACK)(HANDLE Process,PVOID جدول_آدرس,PDWORD Entries,PRUNTIME_FUNCTION *Functions);

#پایان_اگر /* _ARM64_ */

#إذا (defined _ARM64_ || defined _AMD64_) && !defined RC_INVOKED
  NTSYSAPI VOID __cdecl RtlRestoreContext (PCONTEXT Context_رکورد,بنية EXCEPTION_رکورد *Exception_رکورد);
  NTSYSAPI BOOLEAN __cdecl Rtl_جمع_کن_Function_جدول(PRUNTIME_FUNCTION Function_جدول,DWORD مدخل_شمار,DWORD64 پایه_آدرس);
  NTSYSAPI BOOLEAN __cdecl Rtl_Install_Function_جدول_Callback(DWORD64 جدول_Identifier,DWORD64 پایه_آدرس,DWORD درازی_2,PGET_RUNTIME_FUNCTION_CALLBACK Callback,PVOID Context,PCWSTR بیرون_از_Process_Callback_Dll);
  NTSYSAPI BOOLEAN __cdecl Rtl_Delete_Function_جدول(PRUNTIME_FUNCTION Function_جدول);
#پایان_اگر

#اگر_تعریف_شده I_X86_
#إذا(defined(_X86_) && !defined(__x86_64)) && !defined(RC_INVOKED)
#اگر_تعریف_شده __cplusplus
  خارجي "C" {
#پایان_اگر

    __CRT_INLINE BOOLEAN Interlocked_بیت_Test_And_مجموعه(LONG *پایه_2,LONG بیت_2) {
      صحيح old = 0;
      __asm__ __volatile__("lock ; btsl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متطاير دراز *) پایه_2))
	:"Ir" (بیت_2));
      أرجع (BOOLEAN) (old!=0);
    }

    __CRT_INLINE BOOLEAN Interlocked_بیت_Test_And_Reset(LONG *پایه_2,LONG بیت_2) {
      صحيح old = 0;
      __asm__ __volatile__("lock ; btrl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متطاير دراز *) پایه_2))
	:"Ir" (بیت_2));
      أرجع (BOOLEAN) (old!=0);
    }

    __CRT_INLINE BOOLEAN Interlocked_بیت_Test_And_Complement(LONG *پایه_2,LONG بیت_2) {
      صحيح old = 0;
      __asm__ __volatile__("lock ; btcl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متطاير دراز *) پایه_2))
	:"Ir" (بیت_2));
      أرجع (BOOLEAN) (old!=0);
    }

#اگر_تعریف_شده پیشوند_2
    BYTE __readfsbyte(DWORD جابه_جایی_3);
    کلمه_3 __readfsword(DWORD جابه_جایی_3);
    DWORD __readfsdword(DWORD جابه_جایی_3);
    VOID __writefsbyte(DWORD جابه_جایی_3,BYTE داده_3);
    VOID __writefsword(DWORD جابه_جایی_3,کلمه_3 داده_3);
    VOID __writefsdword(DWORD جابه_جایی_3,DWORD داده_3);
#پایان_اگر

#اگر_تعریف_شده __cplusplus
  }
#پایان_اگر
#پایان_اگر

#إذا(defined(_X86_) && !defined(__x86_64))
  __CRT_INLINE VOID حافظه_Barrier(VOID) {
    LONG Barrier;
    __asm__ __volatile__("xchgl %%eax,%0 "
      :"=r" (Barrier));
  }
#تعریف_کن YieldProcessor() __asm__ __volatile__("rep nop ");

#تعریف_کن Pre_Fetch_Cache_سطر(l,a)
#تعریف_کن ReadForWriteAccess(p) (*(p))

#تعریف_کن PF_TEMPORAL_LEVEL_1
#تعریف_کن PF_NON_TEMPORAL_LEVEL_ALL

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
  PVOID Get_Fiber_داده(فراغ);
  __CRT_INLINE PVOID Get_Fiber_داده(فراغ)
  {
    فراغ *ret;
    __asm__ متطاير ("movl	%%fs:0x10,%0\n"
	"movl	(%0),%0"
	: "=r" (ret));
    أرجع ret;
  }
#پایان_اگر

#تعریف_کن EXCEPTION_READ_FAULT 0
#تعریف_کن EXCEPTION_WRITE_FAULT 1
#تعریف_کن EXCEPTION_EXECUTE_FAULT 8

#تعریف_کن اندازه_از_80387_REGISTERS 80

#إذا !defined(RC_INVOKED)

#تعریف_کن CONTEXT_i386 0x00010000
#تعریف_کن CONTEXT_i486 0x00010000

#تعریف_کن CONTEXT_CONTROL (CONTEXT_i386 | 0x00000001L)
#تعریف_کن CONTEXT_INTEGER (CONTEXT_i386 | 0x00000002L)
#تعریف_کن CONTEXT_SEGMENTS (CONTEXT_i386 | 0x00000004L)
#تعریف_کن CONTEXT_FLOATING_نقطه (CONTEXT_i386 | 0x00000008L)
#تعریف_کن CONTEXT_DEBUG_REGISTERS (CONTEXT_i386 | 0x00000010L)
#تعریف_کن CONTEXT_EXTENDED_REGISTERS (CONTEXT_i386 | 0x00000020L)

#تعریف_کن CONTEXT_پر (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_SEGMENTS)

#تعریف_کن CONTEXT_ALL (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_SEGMENTS | CONTEXT_FLOATING_نقطه | CONTEXT_DEBUG_REGISTERS | CONTEXT_EXTENDED_REGISTERS)
#پایان_اگر

#تعریف_کن بیشینه_SUPPORTED_EXTENSION 512

    تعريفنوع بنية _FLOATING_SAVE_AREA {
      DWORD Control_کلمه;
      DWORD وضعیت_کلمه;
      DWORD برچسب_کلمه;
      DWORD Error_جابه_جایی;
      DWORD ErrorSelector;
      DWORD داده_جابه_جایی_2;
      DWORD داده_Selector;
      BYTE ثبات_Area[اندازه_از_80387_REGISTERS];
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
      BYTE ExtendedRegisters[بیشینه_SUPPORTED_EXTENSION];
    } CONTEXT;

    تعريفنوع CONTEXT *PCONTEXT;
#پایان_اگر

#اگر_تعریف_نشده LDT_مدخل_DEFINED
#تعریف_کن LDT_مدخل_DEFINED

    تعريفنوع بنية LDT_مدخل {
      کلمه_3 حد_کم;
      کلمه_3 پایه_کم;
      اتحاد {
	بنية {
	  BYTE پایه_Mid;
	  BYTE Flags1;
	  BYTE Flags2;
	  BYTE پایه_Hi;
	} بایتها_2;
	بنية {
	  DWORD پایه_Mid : 8;
	  DWORD Type : 5;
	  DWORD Dpl : 2;
	  DWORD Pres : 1;
	  DWORD حد_Hi : 4;
	  DWORD Sys : 1;
	  DWORD Reserved_0 : 1;
	  DWORD Default_Big : 1;
	  DWORD Granularity : 1;
	  DWORD پایه_Hi : 8;
	} بیتها_2;
      } بالا_کلمه;
    } LDT_مدخل_2,*PLDT_مدخل;
#پایان_اگر

#إذا defined(__ia64__) && !defined(RC_INVOKED)

#اگر_تعریف_شده __cplusplus
    خارجي "C" {
#پایان_اگر

      BOOLEAN بیت_پیمایش_Forward64(DWORD *شاخص_3,DWORD64 ماسک_3);
      BOOLEAN بیت_پیمایش_Reverse64(DWORD *شاخص_3,DWORD64 ماسک_3);

#اگر_تعریف_شده __cplusplus
    }
#پایان_اگر
#پایان_اگر

#إذا !defined(GENUTIL) && !defined(_GENIA64_) && defined(_IA64_)

    فراغ *_cdecl _rdteb(فراغ);
#اگر_تعریف_شده __ia64__

#تعریف_کن NtCurrentTeb() ((بنية _TEB *)_rdteb())
#تعریف_کن GetCurrentFiber() (((PNT_TIB)NtCurrentTeb())->Fiber_داده)
#تعریف_کن Get_Fiber_داده() (*(PVOID *)(GetCurrentFiber()))

#اگر_تعریف_شده __cplusplus
    خارجي "C" {
#پایان_اگر

      فراغ __break(صحيح);
      فراغ __yield(فراغ);
      فراغ __mf(فراغ);
      فراغ __lfetch(صحيح Level,VOID CONST *آدرس_2);
      فراغ __lfetchfault(صحيح Level,VOID CONST *آدرس_2);
      فراغ __lfetch_excl(صحيح Level,VOID CONST *آدرس_2);
      فراغ __lfetchfault_excl(صحيح Level,VOID CONST *آدرس_2);

#تعریف_کن MD_LFHINT_NONE 0x00
#تعریف_کن MD_LFHINT_NT1 0x01
#تعریف_کن MD_LFHINT_NT2 0x02
#تعریف_کن MD_LFHINT_NTA 0x03

#اگر_تعریف_شده __cplusplus
    }
#پایان_اگر

#تعریف_کن YieldProcessor __yield
#تعریف_کن حافظه_Barrier __mf
#تعریف_کن Pre_Fetch_Cache_سطر __lfetch
#تعریف_کن ReadForWriteAccess(p) (*(p))
#تعریف_کن DbgRaiseAssertionFailure() __break(ASSERT_BREAKPOINT)

#تعریف_کن PF_TEMPORAL_LEVEL_1 MD_LFHINT_NONE
#تعریف_کن PF_NON_TEMPORAL_LEVEL_ALL MD_LFHINT_NTA

#تعریف_کن Unsigned_Multiply_بالا __UMULH

    ULONGLONG Unsigned_Multiply_بالا(ULONGLONG Multiplier,ULONGLONG Multiplicand);
#وإلا
    بنية _TEB *NtCurrentTeb(فراغ);
#پایان_اگر
#پایان_اگر

#اگر_تعریف_شده _IA64_

#تعریف_کن EXCEPTION_READ_FAULT 0
#تعریف_کن EXCEPTION_WRITE_FAULT 1
#تعریف_کن EXCEPTION_EXECUTE_FAULT 2

#إذا !defined(RC_INVOKED)

#تعریف_کن CONTEXT_IA64 0x00080000

#تعریف_کن CONTEXT_CONTROL (CONTEXT_IA64 | 0x00000001L)
#تعریف_کن CONTEXT_پایینی_FLOATING_نقطه (CONTEXT_IA64 | 0x00000002L)
#تعریف_کن CONTEXT_HIGHER_FLOATING_نقطه (CONTEXT_IA64 | 0x00000004L)
#تعریف_کن CONTEXT_INTEGER (CONTEXT_IA64 | 0x00000008L)
#تعریف_کن CONTEXT_DEBUG (CONTEXT_IA64 | 0x00000010L)
#تعریف_کن CONTEXT_IA32_CONTROL (CONTEXT_IA64 | 0x00000020L)

#تعریف_کن CONTEXT_FLOATING_نقطه (CONTEXT_پایینی_FLOATING_نقطه | CONTEXT_HIGHER_FLOATING_نقطه)
#تعریف_کن CONTEXT_پر (CONTEXT_CONTROL | CONTEXT_FLOATING_نقطه | CONTEXT_INTEGER | CONTEXT_IA32_CONTROL)
#تعریف_کن CONTEXT_ALL (CONTEXT_CONTROL | CONTEXT_FLOATING_نقطه | CONTEXT_INTEGER | CONTEXT_DEBUG | CONTEXT_IA32_CONTROL)

#تعریف_کن CONTEXT_EXCEPTION_فعال 0x8000000
#تعریف_کن CONTEXT_SERVICE_فعال 0x10000000
#تعریف_کن CONTEXT_EXCEPTION_REQUEST 0x40000000
#تعریف_کن CONTEXT_EXCEPTION_REPORTING 0x80000000
#پایان_اگر

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
      ULONGLONG مدخل_نقطه;
      ULONGLONG Global_اشاره_گر_2;
    } PLABEL_DESCRIPTOR,*PPLABEL_DESCRIPTOR;

    تعريفنوع بنية _RUNTIME_FUNCTION {
      DWORD Begin_آدرس;
      DWORD انتها_آدرس;
      DWORD Unwind_Info_آدرس;
    } RUNTIME_FUNCTION,*PRUNTIME_FUNCTION;

    تعريفنوع PRUNTIME_FUNCTION (*PGET_RUNTIME_FUNCTION_CALLBACK)(DWORD64 ControlPc,PVOID Context);
    تعريفنوع DWORD (*POUT_از_PROCESS_FUNCTION_جدول_CALLBACK)(HANDLE Process,PVOID جدول_آدرس,PDWORD Entries,PRUNTIME_FUNCTION *Functions);

#تعریف_کن بیرون_از_PROCESS_FUNCTION_جدول_CALLBACK_EXPORT_NAME "OutOfProcessFunctionTableCallback"

    BOOLEAN Rtl_جمع_کن_Function_جدول(PRUNTIME_FUNCTION Function_جدول,DWORD مدخل_شمار,ULONGLONG پایه_آدرس,ULONGLONG هدف_Gp);
    BOOLEAN Rtl_Install_Function_جدول_Callback(DWORD64 جدول_Identifier,DWORD64 پایه_آدرس,DWORD درازی_2,DWORD64 هدف_Gp,PGET_RUNTIME_FUNCTION_CALLBACK Callback,PVOID Context,PCWSTR بیرون_از_Process_Callback_Dll);
    BOOLEAN Rtl_Delete_Function_جدول(PRUNTIME_FUNCTION Function_جدول);
    VOID RtlRestoreContext (PCONTEXT Context_رکورد,بنية EXCEPTION_رکورد *Exception_رکورد);
    VOID __jump_unwind(ULONGLONG هدف_Ms_قاب,ULONGLONG هدف_Bs_قاب,ULONGLONG هدف_Pc);
#پایان_اگر

#تعریف_کن EXCEPTION_NONCONTINUABLE 0x1
#تعریف_کن EXCEPTION_بیشینه_PARAMETERS 15

    تعريفنوع بنية EXCEPTION_رکورد {
      DWORD Exception_کد;
      DWORD ExceptionFlags;
      بنية EXCEPTION_رکورد *Exception_رکورد;
      PVOID Exception_آدرس;
      DWORD عدد_Parameters;
      ULONG_PTR ExceptionInformation[EXCEPTION_بیشینه_PARAMETERS];
    } EXCEPTION_رکورد_2;

    تعريفنوع EXCEPTION_رکورد_2 *PEXCEPTION_رکورد;

    تعريفنوع بنية _EXCEPTION_RECORD32 {
      DWORD Exception_کد;
      DWORD ExceptionFlags;
      DWORD Exception_رکورد;
      DWORD Exception_آدرس;
      DWORD عدد_Parameters;
      DWORD ExceptionInformation[EXCEPTION_بیشینه_PARAMETERS];
    } EXCEPTION_RECORD32,*PEXCEPTION_RECORD32;

    تعريفنوع بنية _EXCEPTION_RECORD64 {
      DWORD Exception_کد;
      DWORD ExceptionFlags;
      DWORD64 Exception_رکورد;
      DWORD64 Exception_آدرس;
      DWORD عدد_Parameters;
      DWORD __unusedAlignment;
      DWORD64 ExceptionInformation[EXCEPTION_بیشینه_PARAMETERS];
    } EXCEPTION_RECORD64,*PEXCEPTION_RECORD64;

    تعريفنوع بنية EXCEPTION_اشارهگرها_2 {
      PEXCEPTION_رکورد Exception_رکورد;
      PCONTEXT Context_رکورد;
    } EXCEPTION_اشارهگرها,*PEXCEPTION_اشارهگرها;

#اگر_تعریف_شده __x86_64

    تعريفنوع EXCEPTION_DISPOSITION NTAPI EXCEPTION_ROUTINE (بنية EXCEPTION_رکورد *Exception_رکورد, PVOID Establisher_قاب_2, بنية _CONTEXT *Context_رکورد, PVOID DispatcherContext);
#اگر_تعریف_نشده __PEXCEPTION_ROUTINE_DEFINED
#تعریف_کن __PEXCEPTION_ROUTINE_DEFINED
    تعريفنوع EXCEPTION_ROUTINE *PEXCEPTION_ROUTINE;
#پایان_اگر

    /* http://msdn.microsoft.com/en-us/library/ms680597(VS.85).aspx */

#تعریف_کن UNWIND_HISTORY_جدول_اندازه 12

  تعريفنوع بنية UNWIND_HISTORY_جدول_مدخل {
    ULONG64 Image_پایه;
    PRUNTIME_FUNCTION Function_مدخل;
  } UNWIND_HISTORY_جدول_مدخل_2, *PUNWIND_HISTORY_جدول_مدخل;

#تعریف_کن UNWIND_HISTORY_جدول_NONE    0
#تعریف_کن UNWIND_HISTORY_جدول_GLOBAL  1
#تعریف_کن UNWIND_HISTORY_جدول_LOCAL   2

  تعريفنوع بنية UNWIND_HISTORY_جدول {
    ULONG شمار_3;
    UCHAR جستجو;
    ULONG64 کم_آدرس;
    ULONG64 بالا_آدرس;
    UNWIND_HISTORY_جدول_مدخل_2 مدخل[UNWIND_HISTORY_جدول_اندازه];
  } UNWIND_HISTORY_جدول_2, *PUNWIND_HISTORY_جدول;

  /* http://msdn.microsoft.com/en-us/library/b6sf5kbd(VS.80).aspx */

  بنية _DISPATCHER_CONTEXT;
  تعريفنوع بنية _DISPATCHER_CONTEXT DISPATCHER_CONTEXT;
  تعريفنوع بنية _DISPATCHER_CONTEXT *PDISPATCHER_CONTEXT;

  بنية _DISPATCHER_CONTEXT {
    ULONG64 ControlPc;
    ULONG64 Image_پایه;
    PRUNTIME_FUNCTION Function_مدخل;
    ULONG64 Establisher_قاب_2;
    ULONG64 هدف_Ip;
    PCONTEXT Context_رکورد;
    PEXCEPTION_ROUTINE LanguageHandler;
    PVOID Handler_داده;
    /* http://www.nynaeve.net/?p=99 */
    PUNWIND_HISTORY_جدول History_جدول;
    ULONG Scope_شاخص;
    ULONG Fill0;
  };

  /* http://msdn.microsoft.com/en-us/library/ms680617(VS.85).aspx */

  تعريفنوع بنية KNONVOLATILE_CONTEXT_اشارهگرها
  {
    PM128A FloatingContext[16];
    PULONG64 IntegerContext[16];
  } KNONVOLATILE_CONTEXT_اشارهگرها_2, *PKNONVOLATILE_CONTEXT_اشارهگرها;
#پایان_اگر /* defined(__x86_64) */

    تعريفنوع PVOID PACCESS_TOKEN;
    تعريفنوع PVOID PSECURITY_DESCRIPTOR;
    تعريفنوع PVOID PSID;

    تعريفنوع DWORD ACCESS_ماسک;
    تعريفنوع ACCESS_ماسک *PACCESS_ماسک;

#تعریف_کن DELETE (0x00010000L)
#تعریف_کن READ_CONTROL (0x00020000L)
#تعریف_کن WRITE_DAC (0x00040000L)
#تعریف_کن WRITE_OWNER (0x00080000L)
#تعریف_کن SYNCHRONIZE (0x00100000L)

#تعریف_کن STANDARD_RIGHTS_REQUIRED (0x000F0000L)
#تعریف_کن STANDARD_RIGHTS_READ (READ_CONTROL)
#تعریف_کن STANDARD_RIGHTS_WRITE (READ_CONTROL)
#تعریف_کن STANDARD_RIGHTS_EXECUTE (READ_CONTROL)
#تعریف_کن STANDARD_RIGHTS_ALL (0x001F0000L)

#تعریف_کن SPECIFIC_RIGHTS_ALL (0x0000FFFFL)

#تعریف_کن ACCESS_SYSTEM_SECURITY (0x01000000L)

#تعریف_کن بیشینه_ALLOWED (0x02000000L)

#تعریف_کن GENERIC_READ (0x80000000L)
#تعریف_کن GENERIC_WRITE (0x40000000L)
#تعریف_کن GENERIC_EXECUTE (0x20000000L)
#تعریف_کن GENERIC_ALL (0x10000000L)

    تعريفنوع بنية _GENERIC_MAPPING {
      ACCESS_ماسک GenericRead;
      ACCESS_ماسک GenericWrite;
      ACCESS_ماسک GenericExecute;
      ACCESS_ماسک GenericAll;
    } GENERIC_MAPPING;
    تعريفنوع GENERIC_MAPPING *PGENERIC_MAPPING;

#ضمن <pshpack4.h>

    تعريفنوع بنية LUID_AND_صفات {
      LUID Luid;
      DWORD صفات;
    } LUID_AND_صفات_2,*PLUID_AND_صفات;
    تعريفنوع LUID_AND_صفات_2 LUID_AND_صفات_ARRAY[ANYSIZE_ARRAY];
    تعريفنوع LUID_AND_صفات_ARRAY *PLUID_AND_صفات_ARRAY;

#ضمن <poppack.h>

#اگر_تعریف_نشده SID_IDENTIFIER_AUTHORITY_DEFINED
#تعریف_کن SID_IDENTIFIER_AUTHORITY_DEFINED
    تعريفنوع بنية _SID_IDENTIFIER_AUTHORITY {
      BYTE مقدار_3[6];
    } SID_IDENTIFIER_AUTHORITY,*PSID_IDENTIFIER_AUTHORITY;
#پایان_اگر

#اگر_تعریف_نشده SID_DEFINED
#تعریف_کن SID_DEFINED
    تعريفنوع بنية _SID {
      BYTE Revision;
      BYTE Sub_Authority_شمار;
      SID_IDENTIFIER_AUTHORITY IdentifierAuthority;
      DWORD SubAuthority[ANYSIZE_ARRAY];
    } SID,*PISID;
#پایان_اگر

#تعریف_کن SID_REVISION (1)
#تعریف_کن SID_MAX_SUB_AUTHORITIES (15)
#تعریف_کن SID_RECOMMENDED_SUB_AUTHORITIES (1)

#تعریف_کن SECURITY_MAX_SID_اندازه (حجم(SID) - حجم(DWORD) + (SID_MAX_SUB_AUTHORITIES *حجم(DWORD)))

    تعريفنوع تعداد _SID_NAME_USE {
      SidTypeUser = 1,Sid_Type_گروه,SidTypeDomain,SidTypeAlias,Sid_Type_Well_معلوم_گروه,SidTypeDeletedAccount,SidTypeInvalid,SidTypeUnknown,SidTypeComputer
    } SID_NAME_USE,*PSID_NAME_USE;

    تعريفنوع بنية SID_AND_صفات {
      PSID Sid;
      DWORD صفات;
    } SID_AND_صفات_2,*PSID_AND_صفات;

    تعريفنوع SID_AND_صفات_2 SID_AND_صفات_ARRAY[ANYSIZE_ARRAY];
    تعريفنوع SID_AND_صفات_ARRAY *PSID_AND_صفات_ARRAY;

#تعریف_کن SECURITY_NULL_SID_AUTHORITY {0,0,0,0,0,0}
#تعریف_کن SECURITY_WORLD_SID_AUTHORITY {0,0,0,0,0,1}
#تعریف_کن SECURITY_LOCAL_SID_AUTHORITY {0,0,0,0,0,2}
#تعریف_کن SECURITY_CREATOR_SID_AUTHORITY {0,0,0,0,0,3}
#تعریف_کن SECURITY_NON_UNIQUE_AUTHORITY {0,0,0,0,0,4}
#تعریف_کن SECURITY_RESOURCE_MANAGER_AUTHORITY {0,0,0,0,0,9}

#تعریف_کن SECURITY_NULL_RID (0x00000000L)
#تعریف_کن SECURITY_WORLD_RID (0x00000000L)
#تعریف_کن SECURITY_LOCAL_RID (0x00000000L)

#تعریف_کن SECURITY_CREATOR_OWNER_RID (0x00000000L)
#تعریف_کن SECURITY_CREATOR_گروه_RID (0x00000001L)

#تعریف_کن SECURITY_CREATOR_OWNER_SERVER_RID (0x00000002L)
#تعریف_کن SECURITY_CREATOR_گروه_SERVER_RID (0x00000003L)

#تعریف_کن SECURITY_NT_AUTHORITY {0,0,0,0,0,5}

#تعریف_کن SECURITY_DIALUP_RID (0x00000001L)
#تعریف_کن SECURITY_شبکه_RID (0x00000002L)
#تعریف_کن SECURITY_BATCH_RID (0x00000003L)
#تعریف_کن SECURITY_INTERACTIVE_RID (0x00000004L)
#تعریف_کن SECURITY_LOGON_IDS_RID (0x00000005L)
#تعریف_کن SECURITY_LOGON_IDS_RID_شمار (3L)
#تعریف_کن SECURITY_SERVICE_RID (0x00000006L)
#تعریف_کن SECURITY_ANONYMOUS_LOGON_RID (0x00000007L)
#تعریف_کن SECURITY_PROXY_RID (0x00000008L)
#تعریف_کن SECURITY_ENTERPRISE_CONTROLLERS_RID (0x00000009L)
#تعریف_کن SECURITY_SERVER_LOGON_RID SECURITY_ENTERPRISE_CONTROLLERS_RID
#تعریف_کن SECURITY_PRINCIPAL_SELF_RID (0x0000000AL)
#تعریف_کن SECURITY_AUTHENTICATED_USER_RID (0x0000000BL)
#تعریف_کن SECURITY_RESTRICTED_کد_RID (0x0000000CL)
#تعریف_کن SECURITY_TERMINAL_SERVER_RID (0x0000000DL)
#تعریف_کن SECURITY_REMOTE_LOGON_RID (0x0000000EL)
#تعریف_کن SECURITY_THIS_ORGANIZATION_RID (0x0000000FL)
#تعریف_کن SECURITY_IUSER_RID (0x00000011L)

#تعریف_کن SECURITY_LOCAL_SYSTEM_RID (0x00000012L)
#تعریف_کن SECURITY_LOCAL_SERVICE_RID (0x00000013L)
#تعریف_کن SECURITY_شبکه_SERVICE_RID (0x00000014L)

#تعریف_کن SECURITY_NT_NON_UNIQUE (0x00000015L)
#تعریف_کن SECURITY_NT_NON_UNIQUE_SUB_AUTH_شمار (3L)

#تعریف_کن SECURITY_ENTERPRISE_READONLY_CONTROLLERS_RID (0x00000016L)

#تعریف_کن SECURITY_BUILTIN_DOMAIN_RID (0x00000020L)
#تعریف_کن SECURITY_WRITE_RESTRICTED_کد_RID (0x00000021L)

#تعریف_کن SECURITY_PACKAGE_پایه_RID (0x00000040L)
#تعریف_کن SECURITY_PACKAGE_RID_شمار (2L)
#تعریف_کن SECURITY_PACKAGE_NTLM_RID (0x0000000AL)
#تعریف_کن SECURITY_PACKAGE_SCHANNEL_RID (0x0000000EL)
#تعریف_کن SECURITY_PACKAGE_DIGEST_RID (0x00000015L)

#تعریف_کن SECURITY_SERVICE_ID_پایه_RID (0x00000050L)
#تعریف_کن SECURITY_SERVICE_ID_RID_شمار (6L)

#تعریف_کن SECURITY_RESERVED_ID_پایه_RID (0x00000051L)

#تعریف_کن SECURITY_MAX_ALWAYS_FILTERED (0x000003E7L)
#تعریف_کن SECURITY_MIN_NEVER_FILTERED (0x000003E8L)

#تعریف_کن SECURITY_OTHER_ORGANIZATION_RID (0x000003E8L)

#تعریف_کن FOREST_USER_RID_MAX (0x000001F3L)

#تعریف_کن DOMAIN_USER_RID_ADMIN (0x000001F4L)
#تعریف_کن DOMAIN_USER_RID_GUEST (0x000001F5L)
#تعریف_کن DOMAIN_USER_RID_KRBTGT (0x000001F6L)

#تعریف_کن DOMAIN_USER_RID_MAX (0x000003E7L)

#تعریف_کن DOMAIN_گروه_RID_ADMINS (0x00000200L)
#تعریف_کن DOMAIN_گروه_RID_USERS (0x00000201L)
#تعریف_کن DOMAIN_گروه_RID_GUESTS (0x00000202L)
#تعریف_کن DOMAIN_گروه_RID_COMPUTERS (0x00000203L)
#تعریف_کن DOMAIN_گروه_RID_CONTROLLERS (0x00000204L)
#تعریف_کن DOMAIN_گروه_RID_CERT_ADMINS (0x00000205L)
#تعریف_کن DOMAIN_گروه_RID_SCHEMA_ADMINS (0x00000206L)
#تعریف_کن DOMAIN_گروه_RID_ENTERPRISE_ADMINS (0x00000207L)
#تعریف_کن DOMAIN_گروه_RID_POLICY_ADMINS (0x00000208L)
#تعریف_کن DOMAIN_گروه_RID_READONLY_CONTROLLERS (0x00000209L)

#تعریف_کن DOMAIN_ALIAS_RID_ADMINS (0x00000220L)
#تعریف_کن DOMAIN_ALIAS_RID_USERS (0x00000221L)
#تعریف_کن DOMAIN_ALIAS_RID_GUESTS (0x00000222L)
#تعریف_کن DOMAIN_ALIAS_RID_POWER_USERS (0x00000223L)

#تعریف_کن DOMAIN_ALIAS_RID_ACCOUNT_OPS (0x00000224L)
#تعریف_کن DOMAIN_ALIAS_RID_SYSTEM_OPS (0x00000225L)
#تعریف_کن DOMAIN_ALIAS_RID_PRINT_OPS (0x00000226L)
#تعریف_کن DOMAIN_ALIAS_RID_BACKUP_OPS (0x00000227L)

#تعریف_کن DOMAIN_ALIAS_RID_REPLICATOR (0x00000228L)
#تعریف_کن DOMAIN_ALIAS_RID_RAS_SERVERS (0x00000229L)
#تعریف_کن DOMAIN_ALIAS_RID_PREW2KCOMPACCESS (0x0000022AL)
#تعریف_کن DOMAIN_ALIAS_RID_REMOTE_DESKTOP_USERS (0x0000022BL)
#تعریف_کن DOMAIN_ALIAS_RID_شبکه_CONFIGURATION_OPS (0x0000022CL)
#تعریف_کن DOMAIN_ALIAS_RID_INCOMING_FOREST_TRUST_BUILDERS (0x0000022DL)

#تعریف_کن DOMAIN_ALIAS_RID_MONITORING_USERS (0x0000022EL)
#تعریف_کن DOMAIN_ALIAS_RID_LOGGING_USERS (0x0000022FL)
#تعریف_کن DOMAIN_ALIAS_RID_AUTHORIZATIONACCESS (0x00000230L)
#تعریف_کن DOMAIN_ALIAS_RID_TS_LICENSE_SERVERS (0x00000231L)
#تعریف_کن DOMAIN_ALIAS_RID_DCOM_USERS (0x00000232L)

#تعریف_کن DOMAIN_ALIAS_RID_IUSERS (0x00000238L)
#تعریف_کن DOMAIN_ALIAS_RID_CRYPTO_OPERATORS (0x00000239L)
#تعریف_کن DOMAIN_ALIAS_RID_CACHEABLE_PRINCIPALS_گروه (0x0000023BL)
#تعریف_کن DOMAIN_ALIAS_RID_NON_CACHEABLE_PRINCIPALS_گروه (0x0000023CL)
#تعریف_کن DOMAIN_ALIAS_RID_EVENT_LOG_READERS_گروه (0x0000023DL)

#تعریف_کن SECURITY_MANDATORY_LABEL_AUTHORITY {0,0,0,0,0,16}
#تعریف_کن SECURITY_MANDATORY_UNTRUSTED_RID (0x00000000L)
#تعریف_کن SECURITY_MANDATORY_کم_RID (0x00001000L)
#تعریف_کن SECURITY_MANDATORY_MEDIUM_RID (0x00002000L)
#تعریف_کن SECURITY_MANDATORY_بالا_RID (0x00003000L)
#تعریف_کن SECURITY_MANDATORY_SYSTEM_RID (0x00004000L)
#تعریف_کن SECURITY_MANDATORY_PROTECTED_PROCESS_RID (0x00005000L)

#تعریف_کن SECURITY_MANDATORY_بیشینه_USER_RID SECURITY_MANDATORY_SYSTEM_RID

#تعریف_کن MANDATORY_LEVEL_مقصد_MANDATORY_RID(IL) (IL * 0x1000)

    تعريفنوع تعداد {
      WinNullSid = 0,WinWorldSid = 1,WinLocalSid = 2,WinCreatorOwnerSid = 3,Win_Creator_گروه_Sid = 4,WinCreatorOwnerServerSid = 5,Win_Creator_گروه_Server_Sid = 6,WinNtAuthoritySid = 7,WinDialupSid = 8,Win_شبکه_Sid = 9,WinBatchSid = 10,WinInteractiveSid = 11,WinServiceSid = 12,WinAnonymousSid = 13,WinProxySid = 14,WinEnterpriseControllersSid = 15,WinSelfSid = 16,WinAuthenticatedUserSid = 17,Win_Restricted_کد_Sid = 18,WinTerminalServerSid = 19,WinRemoteLogonIdSid = 20,WinLogonIdsSid = 21,WinLocalSystemSid = 22,WinLocalServiceSid = 23,Win_شبکه_Service_Sid = 24,WinBuiltinDomainSid = 25,WinBuiltinAdministratorsSid = 26,WinBuiltinUsersSid = 27,WinBuiltinGuestsSid = 28,WinBuiltinPowerUsersSid = 29,WinBuiltinAccountOperatorsSid = 30,WinBuiltinSystemOperatorsSid = 31,WinBuiltinPrintOperatorsSid = 32,WinBuiltinBackupOperatorsSid = 33,WinBuiltinReplicatorSid = 34,WinBuiltinPreWindows2000CompatibleAccessSid = 35,WinBuiltinRemoteDesktopUsersSid = 36,Win_Builtin_شبکه_Configuration_Operators_Sid = 37,WinAccountAdministratorSid = 38,WinAccountGuestSid = 39,WinAccountKrbtgtSid = 40,WinAccountDomainAdminsSid = 41,WinAccountDomainUsersSid = 42,WinAccountDomainGuestsSid = 43,WinAccountComputersSid = 44,WinAccountControllersSid = 45,WinAccountCertAdminsSid = 46,WinAccountSchemaAdminsSid = 47,WinAccountEnterpriseAdminsSid = 48,WinAccountPolicyAdminsSid = 49,WinAccountRasAndIasServersSid = 50,WinNTLMAuthenticationSid = 51,WinDigestAuthenticationSid = 52,WinSChannelAuthenticationSid = 53,WinThisOrganizationSid = 54,WinOtherOrganizationSid = 55,WinBuiltinIncomingForestTrustBuildersSid = 56,WinBuiltinPerfMonitoringUsersSid = 57,WinBuiltinPerfLoggingUsersSid = 58,WinBuiltinAuthorizationAccessSid = 59,WinBuiltinTerminalServerLicenseServersSid = 60,WinBuiltinDCOMUsersSid = 61
    } WELL_معلوم_SID_TYPE;

#تعریف_کن SYSTEM_LUID { 0x3E7,0x0 }
#تعریف_کن ANONYMOUS_LOGON_LUID { 0x3e6,0x0 }
#تعریف_کن LOCALSERVICE_LUID { 0x3e5,0x0 }
#تعریف_کن NETWORKSERVICE_LUID { 0x3e4,0x0 }
#تعریف_کن IUSER_LUID { 0x3e3, 0x0 }

#تعریف_کن SE_گروه_MANDATORY (0x00000001L)
#تعریف_کن SE_گروه_ENABLED_BY_DEFAULT (0x00000002L)
#تعریف_کن SE_گروه_ENABLED (0x00000004L)
#تعریف_کن SE_گروه_OWNER (0x00000008L)
#تعریف_کن SE_گروه_USE_FOR_DENY_ONLY (0x00000010L)
#تعریف_کن SE_گروه_INTEGRITY (0x00000020L)
#تعریف_کن SE_گروه_INTEGRITY_ENABLED (0x00000040L)
#تعریف_کن SE_گروه_LOGON_ID (0xC0000000L)
#تعریف_کن SE_گروه_RESOURCE (0x20000000L)

#تعریف_کن ACL_REVISION (2)
#تعریف_کن ACL_REVISION_DS (4)

#تعریف_کن ACL_REVISION1 (1)
#تعریف_کن MIN_ACL_REVISION ACL_REVISION2
#تعریف_کن ACL_REVISION2 (2)
#تعریف_کن ACL_REVISION3 (3)
#تعریف_کن ACL_REVISION4 (4)
#تعریف_کن MAX_ACL_REVISION ACL_REVISION4

    تعريفنوع بنية _ACL {
      BYTE AclRevision;
      BYTE Sbz1;
      کلمه_3 Acl_اندازه;
      کلمه_3 Ace_شمار;
      کلمه_3 Sbz2;
    } ACL;
    تعريفنوع ACL *PACL;

    تعريفنوع بنية ACE_سرآیند {
      BYTE AceType;
      BYTE AceFlags;
      کلمه_3 Ace_اندازه;
    } ACE_سرآیند_2;
    تعريفنوع ACE_سرآیند_2 *PACE_سرآیند;

#تعریف_کن ACCESS_MIN_MS_ACE_TYPE (0x0)
#تعریف_کن ACCESS_ALLOWED_ACE_TYPE (0x0)
#تعریف_کن ACCESS_DENIED_ACE_TYPE (0x1)
#تعریف_کن SYSTEM_AUDIT_ACE_TYPE (0x2)
#تعریف_کن SYSTEM_ALARM_ACE_TYPE (0x3)
#تعریف_کن ACCESS_MAX_MS_V2_ACE_TYPE (0x3)

#تعریف_کن ACCESS_ALLOWED_COMPOUND_ACE_TYPE (0x4)
#تعریف_کن ACCESS_MAX_MS_V3_ACE_TYPE (0x4)

#تعریف_کن ACCESS_MIN_MS_OBJECT_ACE_TYPE (0x5)
#تعریف_کن ACCESS_ALLOWED_OBJECT_ACE_TYPE (0x5)
#تعریف_کن ACCESS_DENIED_OBJECT_ACE_TYPE (0x6)
#تعریف_کن SYSTEM_AUDIT_OBJECT_ACE_TYPE (0x7)
#تعریف_کن SYSTEM_ALARM_OBJECT_ACE_TYPE (0x8)
#تعریف_کن ACCESS_MAX_MS_OBJECT_ACE_TYPE (0x8)

#تعریف_کن ACCESS_MAX_MS_V4_ACE_TYPE (0x8)
#تعریف_کن ACCESS_MAX_MS_ACE_TYPE (0x8)

#تعریف_کن ACCESS_ALLOWED_CALLBACK_ACE_TYPE (0x9)
#تعریف_کن ACCESS_DENIED_CALLBACK_ACE_TYPE (0xA)
#تعریف_کن ACCESS_ALLOWED_CALLBACK_OBJECT_ACE_TYPE (0xB)
#تعریف_کن ACCESS_DENIED_CALLBACK_OBJECT_ACE_TYPE (0xC)
#تعریف_کن SYSTEM_AUDIT_CALLBACK_ACE_TYPE (0xD)
#تعریف_کن SYSTEM_ALARM_CALLBACK_ACE_TYPE (0xE)
#تعریف_کن SYSTEM_AUDIT_CALLBACK_OBJECT_ACE_TYPE (0xF)
#تعریف_کن SYSTEM_ALARM_CALLBACK_OBJECT_ACE_TYPE (0x10)

#تعریف_کن SYSTEM_MANDATORY_LABEL_ACE_TYPE (0x11)
#تعریف_کن ACCESS_MAX_MS_V5_ACE_TYPE (0x11)

#تعریف_کن OBJECT_INHERIT_ACE (0x1)
#تعریف_کن CONTAINER_INHERIT_ACE (0x2)
#تعریف_کن NO_PROPAGATE_INHERIT_ACE (0x4)
#تعریف_کن INHERIT_ONLY_ACE (0x8)
#تعریف_کن INHERITED_ACE (0x10)
#تعریف_کن VALID_INHERIT_FLAGS (0x1F)

#تعریف_کن SUCCESSFUL_ACCESS_ACE_FLAG (0x40)
#تعریف_کن FAILED_ACCESS_ACE_FLAG (0x80)

    تعريفنوع بنية _ACCESS_ALLOWED_ACE {
      ACE_سرآیند_2 سرآیند_2;
      ACCESS_ماسک ماسک_3;
      DWORD Sid_شروع;
    } ACCESS_ALLOWED_ACE;

    تعريفنوع ACCESS_ALLOWED_ACE *PACCESS_ALLOWED_ACE;

    تعريفنوع بنية _ACCESS_DENIED_ACE {
      ACE_سرآیند_2 سرآیند_2;
      ACCESS_ماسک ماسک_3;
      DWORD Sid_شروع;
    } ACCESS_DENIED_ACE;
    تعريفنوع ACCESS_DENIED_ACE *PACCESS_DENIED_ACE;

    تعريفنوع بنية _SYSTEM_AUDIT_ACE {
      ACE_سرآیند_2 سرآیند_2;
      ACCESS_ماسک ماسک_3;
      DWORD Sid_شروع;
    } SYSTEM_AUDIT_ACE;
    تعريفنوع SYSTEM_AUDIT_ACE *PSYSTEM_AUDIT_ACE;

    تعريفنوع بنية _SYSTEM_ALARM_ACE {
      ACE_سرآیند_2 سرآیند_2;
      ACCESS_ماسک ماسک_3;
      DWORD Sid_شروع;
    } SYSTEM_ALARM_ACE;
    تعريفنوع SYSTEM_ALARM_ACE *PSYSTEM_ALARM_ACE;

    تعريفنوع بنية _ACCESS_ALLOWED_OBJECT_ACE {
      ACE_سرآیند_2 سرآیند_2;
      ACCESS_ماسک ماسک_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_شروع;
    } ACCESS_ALLOWED_OBJECT_ACE,*PACCESS_ALLOWED_OBJECT_ACE;

    تعريفنوع بنية _ACCESS_DENIED_OBJECT_ACE {
      ACE_سرآیند_2 سرآیند_2;
      ACCESS_ماسک ماسک_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_شروع;
    } ACCESS_DENIED_OBJECT_ACE,*PACCESS_DENIED_OBJECT_ACE;

    تعريفنوع بنية _SYSTEM_AUDIT_OBJECT_ACE {
      ACE_سرآیند_2 سرآیند_2;
      ACCESS_ماسک ماسک_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_شروع;
    } SYSTEM_AUDIT_OBJECT_ACE,*PSYSTEM_AUDIT_OBJECT_ACE;

    تعريفنوع بنية _SYSTEM_ALARM_OBJECT_ACE {
      ACE_سرآیند_2 سرآیند_2;
      ACCESS_ماسک ماسک_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_شروع;
    } SYSTEM_ALARM_OBJECT_ACE,*PSYSTEM_ALARM_OBJECT_ACE;

    تعريفنوع بنية _ACCESS_ALLOWED_CALLBACK_ACE {
      ACE_سرآیند_2 سرآیند_2;
      ACCESS_ماسک ماسک_3;
      DWORD Sid_شروع;

    } ACCESS_ALLOWED_CALLBACK_ACE,*PACCESS_ALLOWED_CALLBACK_ACE;

    تعريفنوع بنية _ACCESS_DENIED_CALLBACK_ACE {
      ACE_سرآیند_2 سرآیند_2;
      ACCESS_ماسک ماسک_3;
      DWORD Sid_شروع;

    } ACCESS_DENIED_CALLBACK_ACE,*PACCESS_DENIED_CALLBACK_ACE;

    تعريفنوع بنية _SYSTEM_AUDIT_CALLBACK_ACE {
      ACE_سرآیند_2 سرآیند_2;
      ACCESS_ماسک ماسک_3;
      DWORD Sid_شروع;

    } SYSTEM_AUDIT_CALLBACK_ACE,*PSYSTEM_AUDIT_CALLBACK_ACE;

    تعريفنوع بنية _SYSTEM_ALARM_CALLBACK_ACE {
      ACE_سرآیند_2 سرآیند_2;
      ACCESS_ماسک ماسک_3;
      DWORD Sid_شروع;

    } SYSTEM_ALARM_CALLBACK_ACE,*PSYSTEM_ALARM_CALLBACK_ACE;

    تعريفنوع بنية _ACCESS_ALLOWED_CALLBACK_OBJECT_ACE {
      ACE_سرآیند_2 سرآیند_2;
      ACCESS_ماسک ماسک_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_شروع;

    } ACCESS_ALLOWED_CALLBACK_OBJECT_ACE,*PACCESS_ALLOWED_CALLBACK_OBJECT_ACE;

    تعريفنوع بنية _ACCESS_DENIED_CALLBACK_OBJECT_ACE {
      ACE_سرآیند_2 سرآیند_2;
      ACCESS_ماسک ماسک_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_شروع;

    } ACCESS_DENIED_CALLBACK_OBJECT_ACE,*PACCESS_DENIED_CALLBACK_OBJECT_ACE;

    تعريفنوع بنية _SYSTEM_AUDIT_CALLBACK_OBJECT_ACE {
      ACE_سرآیند_2 سرآیند_2;
      ACCESS_ماسک ماسک_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_شروع;

    } SYSTEM_AUDIT_CALLBACK_OBJECT_ACE,*PSYSTEM_AUDIT_CALLBACK_OBJECT_ACE;

    تعريفنوع بنية _SYSTEM_ALARM_CALLBACK_OBJECT_ACE {
      ACE_سرآیند_2 سرآیند_2;
      ACCESS_ماسک ماسک_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_شروع;

    } SYSTEM_ALARM_CALLBACK_OBJECT_ACE,*PSYSTEM_ALARM_CALLBACK_OBJECT_ACE;

#تعریف_کن ACE_OBJECT_TYPE_PRESENT 0x1
#تعریف_کن ACE_INHERITED_OBJECT_TYPE_PRESENT 0x2

    تعريفنوع تعداد _ACL_INFORMATION_CLASS {
      AclRevisionInformation = 1,Acl_اندازه_Information
    } ACL_INFORMATION_CLASS;

    تعريفنوع بنية _ACL_REVISION_INFORMATION {
      DWORD AclRevision;
    } ACL_REVISION_INFORMATION;
    تعريفنوع ACL_REVISION_INFORMATION *PACL_REVISION_INFORMATION;

    تعريفنوع بنية ACL_اندازه_INFORMATION {
      DWORD Ace_شمار;
      DWORD Acl_بایتها_درون_Use;
      DWORD Acl_بایتها_Free;
    } ACL_اندازه_INFORMATION_2;
    تعريفنوع ACL_اندازه_INFORMATION_2 *PACL_اندازه_INFORMATION;

#تعریف_کن SECURITY_DESCRIPTOR_REVISION (1)
#تعریف_کن SECURITY_DESCRIPTOR_REVISION1 (1)

#تعریف_کن SECURITY_DESCRIPTOR_MIN_درازی (حجم(SECURITY_DESCRIPTOR))

    تعريفنوع کلمه_3 SECURITY_DESCRIPTOR_CONTROL,*PSECURITY_DESCRIPTOR_CONTROL;

#تعریف_کن SE_OWNER_DEFAULTED (0x0001)
#تعریف_کن SE_گروه_DEFAULTED (0x0002)
#تعریف_کن SE_DACL_PRESENT (0x0004)
#تعریف_کن SE_DACL_DEFAULTED (0x0008)
#تعریف_کن SE_SACL_PRESENT (0x0010)
#تعریف_کن SE_SACL_DEFAULTED (0x0020)
#تعریف_کن SE_DACL_AUTO_INHERIT_REQ (0x0100)
#تعریف_کن SE_SACL_AUTO_INHERIT_REQ (0x0200)
#تعریف_کن SE_DACL_AUTO_INHERITED (0x0400)
#تعریف_کن SE_SACL_AUTO_INHERITED (0x0800)
#تعریف_کن SE_DACL_PROTECTED (0x1000)
#تعریف_کن SE_SACL_PROTECTED (0x2000)
#تعریف_کن SE_RM_CONTROL_VALID (0x4000)
#تعریف_کن SE_SELF_RELATIVE (0x8000)

    تعريفنوع بنية _SECURITY_DESCRIPTOR_RELATIVE {
      BYTE Revision;
      BYTE Sbz1;
      SECURITY_DESCRIPTOR_CONTROL Control;
      DWORD Owner;
      DWORD گروه_2;
      DWORD Sacl;
      DWORD Dacl;
    } SECURITY_DESCRIPTOR_RELATIVE,*PISECURITY_DESCRIPTOR_RELATIVE;

    تعريفنوع بنية _SECURITY_DESCRIPTOR {
      BYTE Revision;
      BYTE Sbz1;
      SECURITY_DESCRIPTOR_CONTROL Control;
      PSID Owner;
      PSID گروه_2;
      PACL Sacl;
      PACL Dacl;

    } SECURITY_DESCRIPTOR,*PISECURITY_DESCRIPTOR;

    تعريفنوع بنية _OBJECT_TYPE_LIST {
      کلمه_3 Level;
      کلمه_3 Sbz;
      GUID *ObjectType;
    } OBJECT_TYPE_LIST,*POBJECT_TYPE_LIST;

#تعریف_کن ACCESS_OBJECT_GUID 0
#تعریف_کن ACCESS_PROPERTY_مجموعه_GUID 1
#تعریف_کن ACCESS_PROPERTY_GUID 2

#تعریف_کن ACCESS_MAX_LEVEL 4

    تعريفنوع تعداد _AUDIT_EVENT_TYPE {
      AuditEventObjectAccess,AuditEventDirectoryServiceAccess
    } AUDIT_EVENT_TYPE,*PAUDIT_EVENT_TYPE;

#تعریف_کن AUDIT_ALLOW_NO_PRIVILEGE 0x1

#تعریف_کن ACCESS_DS_منبع_A "DS"
#تعریف_کن ACCESS_DS_منبع_W L"DS"
#تعریف_کن ACCESS_DS_OBJECT_TYPE_NAME_A "Directory Service Object"
#تعریف_کن ACCESS_DS_OBJECT_TYPE_NAME_W L"Directory Service Object"

#تعریف_کن SE_PRIVILEGE_ENABLED_BY_DEFAULT (0x00000001L)
#تعریف_کن SE_PRIVILEGE_ENABLED (0x00000002L)
#تعریف_کن SE_PRIVILEGE_REMOVED (0X00000004L)
#تعریف_کن SE_PRIVILEGE_استفاده_شده_FOR_ACCESS (0x80000000L)

#تعریف_کن PRIVILEGE_مجموعه_ALL_NECESSARY (1)

    تعريفنوع بنية PRIVILEGE_مجموعه {
      DWORD Privilege_شمار;
      DWORD Control;
      LUID_AND_صفات_2 Privilege[ANYSIZE_ARRAY];
    } PRIVILEGE_مجموعه_2,*PPRIVILEGE_مجموعه;

#تعریف_کن SE_CREATE_TOKEN_NAME متن_3("SeCreateTokenPrivilege")
#تعریف_کن SE_ASSIGNPRIMARYTOKEN_NAME متن_3("SeAssignPrimaryTokenPrivilege")
#تعریف_کن SE_قفل_حافظه_NAME متن_3("SeLockMemoryPrivilege")
#تعریف_کن SE_INCREASE_QUOTA_NAME متن_3("SeIncreaseQuotaPrivilege")
#تعریف_کن SE_UNSOLICITED_درون_داد_NAME متن_3("SeUnsolicitedInputPrivilege")
#تعریف_کن SE_MACHINE_ACCOUNT_NAME متن_3("SeMachineAccountPrivilege")
#تعریف_کن SE_TCB_NAME متن_3("SeTcbPrivilege")
#تعریف_کن SE_SECURITY_NAME متن_3("SeSecurityPrivilege")
#تعریف_کن SE_TAKE_OWNERSHIP_NAME متن_3("SeTakeOwnershipPrivilege")
#تعریف_کن SE_بارگیری_DRIVER_NAME متن_3("SeLoadDriverPrivilege")
#تعریف_کن SE_SYSTEM_PROFILE_NAME متن_3("SeSystemProfilePrivilege")
#تعریف_کن SE_SYSTEMTIME_NAME متن_3("SeSystemtimePrivilege")
#تعریف_کن SE_PROF_SINGLE_PROCESS_NAME متن_3("SeProfileSingleProcessPrivilege")
#تعریف_کن SE_INC_پایه_اولویت_NAME متن_3("SeIncreaseBasePriorityPrivilege")
#تعریف_کن SE_CREATE_PAGEFILE_NAME متن_3("SeCreatePagefilePrivilege")
#تعریف_کن SE_CREATE_PERMANENT_NAME متن_3("SeCreatePermanentPrivilege")
#تعریف_کن SE_BACKUP_NAME متن_3("SeBackupPrivilege")
#تعریف_کن SE_RESTORE_NAME متن_3("SeRestorePrivilege")
#تعریف_کن SE_SHUTDOWN_NAME متن_3("SeShutdownPrivilege")
#تعریف_کن SE_DEBUG_NAME متن_3("SeDebugPrivilege")
#تعریف_کن SE_AUDIT_NAME متن_3("SeAuditPrivilege")
#تعریف_کن SE_SYSTEM_ENVIRONMENT_NAME متن_3("SeSystemEnvironmentPrivilege")
#تعریف_کن SE_CHANGE_NOTIFY_NAME متن_3("SeChangeNotifyPrivilege")
#تعریف_کن SE_REMOTE_SHUTDOWN_NAME متن_3("SeRemoteShutdownPrivilege")
#تعریف_کن SE_UNDOCK_NAME متن_3("SeUndockPrivilege")
#تعریف_کن SE_SYNC_AGENT_NAME متن_3("SeSyncAgentPrivilege")
#تعریف_کن SE_ENABLE_DELEGATION_NAME متن_3("SeEnableDelegationPrivilege")
#تعریف_کن SE_MANAGE_VOLUME_NAME متن_3("SeManageVolumePrivilege")
#تعریف_کن SE_IMPERSONATE_NAME متن_3("SeImpersonatePrivilege")
#تعریف_کن SE_CREATE_GLOBAL_NAME متن_3("SeCreateGlobalPrivilege")

    تعريفنوع تعداد _SECURITY_IMPERSONATION_LEVEL {
      SecurityAnonymous,SecurityIdentification,SecurityImpersonation,SecurityDelegation
    } SECURITY_IMPERSONATION_LEVEL,*PSECURITY_IMPERSONATION_LEVEL;

#تعریف_کن SECURITY_MAX_IMPERSONATION_LEVEL SecurityDelegation
#تعریف_کن SECURITY_MIN_IMPERSONATION_LEVEL SecurityAnonymous
#تعریف_کن DEFAULT_IMPERSONATION_LEVEL SecurityImpersonation
#تعریف_کن VALID_IMPERSONATION_LEVEL(L) (((L) >= SECURITY_MIN_IMPERSONATION_LEVEL) && ((L) <= SECURITY_MAX_IMPERSONATION_LEVEL))

#تعریف_کن TOKEN_تخصیص_بده_PRIMARY (0x0001)
#تعریف_کن TOKEN_DUPLICATE (0x0002)
#تعریف_کن TOKEN_IMPERSONATE (0x0004)
#تعریف_کن TOKEN_QUERY (0x0008)
#تعریف_کن TOKEN_QUERY_منبع (0x0010)
#تعریف_کن TOKEN_ADJUST_PRIVILEGES (0x0020)
#تعریف_کن TOKEN_ADJUST_GROUPS (0x0040)
#تعریف_کن TOKEN_ADJUST_DEFAULT (0x0080)
#تعریف_کن TOKEN_ADJUST_SESSIONID (0x0100)

#تعریف_کن TOKEN_ALL_ACCESS_P (STANDARD_RIGHTS_REQUIRED | TOKEN_تخصیص_بده_PRIMARY | TOKEN_DUPLICATE | TOKEN_IMPERSONATE | TOKEN_QUERY | TOKEN_QUERY_منبع | TOKEN_ADJUST_PRIVILEGES | TOKEN_ADJUST_GROUPS | TOKEN_ADJUST_DEFAULT)
#تعریف_کن TOKEN_ALL_ACCESS (TOKEN_ALL_ACCESS_P | TOKEN_ADJUST_SESSIONID)
#تعریف_کن TOKEN_READ (STANDARD_RIGHTS_READ | TOKEN_QUERY)

#تعریف_کن TOKEN_WRITE (STANDARD_RIGHTS_WRITE | TOKEN_ADJUST_PRIVILEGES | TOKEN_ADJUST_GROUPS | TOKEN_ADJUST_DEFAULT)

#تعریف_کن TOKEN_EXECUTE (STANDARD_RIGHTS_EXECUTE)

    تعريفنوع تعداد _TOKEN_TYPE {
      TokenPrimary = 1,TokenImpersonation
    } TOKEN_TYPE;
    تعريفنوع TOKEN_TYPE *PTOKEN_TYPE;

    تعريفنوع تعداد _TOKEN_INFORMATION_CLASS {
      TokenUser = 1,TokenGroups,TokenPrivileges,TokenOwner,Token_Primary_گروه,TokenDefaultDacl,Token_منبع,TokenType,TokenImpersonationLevel,
      TokenStatistics,TokenRestrictedSids,TokenSessionId,TokenGroupsAndPrivileges,TokenSessionReference,TokenSandBoxInert,TokenAuditPolicy,
      TokenOrigin,MaxTokenInfoClass
    } TOKEN_INFORMATION_CLASS,*PTOKEN_INFORMATION_CLASS;

    تعريفنوع بنية _TOKEN_USER {
      SID_AND_صفات_2 User;
    } TOKEN_USER,*PTOKEN_USER;

    تعريفنوع بنية _TOKEN_GROUPS {
      DWORD گروه_شمار;
      SID_AND_صفات_2 Groups[ANYSIZE_ARRAY];
    } TOKEN_GROUPS,*PTOKEN_GROUPS;

    تعريفنوع بنية _TOKEN_PRIVILEGES {
      DWORD Privilege_شمار;
      LUID_AND_صفات_2 Privileges[ANYSIZE_ARRAY];
    } TOKEN_PRIVILEGES,*PTOKEN_PRIVILEGES;

    تعريفنوع بنية _TOKEN_OWNER {
      PSID Owner;
    } TOKEN_OWNER,*PTOKEN_OWNER;

    تعريفنوع بنية TOKEN_PRIMARY_گروه {
      PSID Primary_گروه;
    } TOKEN_PRIMARY_گروه_2,*PTOKEN_PRIMARY_گروه;

    تعريفنوع بنية _TOKEN_DEFAULT_DACL {
      PACL DefaultDacl;
    } TOKEN_DEFAULT_DACL,*PTOKEN_DEFAULT_DACL;

    تعريفنوع بنية _TOKEN_GROUPS_AND_PRIVILEGES {
      DWORD Sid_شمار;
      DWORD Sid_درازی;
      PSID_AND_صفات Sids;
      DWORD Restricted_Sid_شمار;
      DWORD Restricted_Sid_درازی;
      PSID_AND_صفات RestrictedSids;
      DWORD Privilege_شمار;
      DWORD Privilege_درازی;
      PLUID_AND_صفات Privileges;
      LUID AuthenticationId;
    } TOKEN_GROUPS_AND_PRIVILEGES,*PTOKEN_GROUPS_AND_PRIVILEGES;

#تعریف_کن TOKEN_AUDIT_SUCCESS_INCLUDE 0x1
#تعریف_کن TOKEN_AUDIT_SUCCESS_EXCLUDE 0x2
#تعریف_کن TOKEN_AUDIT_FAILURE_INCLUDE 0x4
#تعریف_کن TOKEN_AUDIT_FAILURE_EXCLUDE 0x8

#تعریف_کن VALID_AUDIT_POLICY_بیتها (TOKEN_AUDIT_SUCCESS_INCLUDE | TOKEN_AUDIT_SUCCESS_EXCLUDE | TOKEN_AUDIT_FAILURE_INCLUDE | TOKEN_AUDIT_FAILURE_EXCLUDE)
#تعریف_کن VALID_TOKEN_AUDIT_POLICY_ELEMENT(P) ((((P).Policy_ماسک & ~VALID_AUDIT_POLICY_بیتها)==0) && ((P).Category <= AuditEventMaxType))

    تعريفنوع بنية _TOKEN_AUDIT_POLICY_ELEMENT {
      DWORD Category;
      DWORD Policy_ماسک;
    } TOKEN_AUDIT_POLICY_ELEMENT,*PTOKEN_AUDIT_POLICY_ELEMENT;

    تعريفنوع بنية _TOKEN_AUDIT_POLICY {
      DWORD Policy_شمار;
      TOKEN_AUDIT_POLICY_ELEMENT Policy[ANYSIZE_ARRAY];
    } TOKEN_AUDIT_POLICY,*PTOKEN_AUDIT_POLICY;

#تعریف_کن در_هر_USER_AUDITING_POLICY_اندازه(p) (حجم(TOKEN_AUDIT_POLICY) + (((p)->Policy_شمار > ANYSIZE_ARRAY) ? (حجم(TOKEN_AUDIT_POLICY_ELEMENT) *((p)->Policy_شمار - ANYSIZE_ARRAY)) : 0))
#تعریف_کن در_هر_USER_AUDITING_POLICY_اندازه_BY_شمار(C) (حجم(TOKEN_AUDIT_POLICY) + (((C) > ANYSIZE_ARRAY) ? (حجم(TOKEN_AUDIT_POLICY_ELEMENT) *((C) - ANYSIZE_ARRAY)) : 0))

#تعریف_کن TOKEN_منبع_درازی 8

    تعريفنوع بنية TOKEN_منبع {
      CHAR منبع_Name[TOKEN_منبع_درازی];
      LUID منبع_Identifier;
    } TOKEN_منبع_2,*PTOKEN_منبع;

    تعريفنوع بنية _TOKEN_STATISTICS {
      LUID TokenId;
      LUID AuthenticationId;
      LARGE_INTEGER Expiration_زمان;
      TOKEN_TYPE TokenType;
      SECURITY_IMPERSONATION_LEVEL ImpersonationLevel;
      DWORD DynamicCharged;
      DWORD Dynamic_موجود;
      DWORD گروه_شمار;
      DWORD Privilege_شمار;
      LUID ModifiedId;
    } TOKEN_STATISTICS,*PTOKEN_STATISTICS;

    تعريفنوع بنية _TOKEN_CONTROL {
      LUID TokenId;
      LUID AuthenticationId;
      LUID ModifiedId;
      TOKEN_منبع_2 Token_منبع;
    } TOKEN_CONTROL,*PTOKEN_CONTROL;

    تعريفنوع بنية _TOKEN_ORIGIN {
      LUID OriginatingLogonSession;
    } TOKEN_ORIGIN,*PTOKEN_ORIGIN;

#تعریف_کن SECURITY_DYNAMIC_TRACKING (TRUE)
#تعریف_کن SECURITY_STATIC_TRACKING (FALSE)

    تعريفنوع BOOLEAN SECURITY_CONTEXT_TRACKING_نما,*PSECURITY_CONTEXT_TRACKING_نما;

    تعريفنوع بنية SECURITY_QUALITY_از_SERVICE {
      DWORD درازی_2;
      SECURITY_IMPERSONATION_LEVEL ImpersonationLevel;
      SECURITY_CONTEXT_TRACKING_نما Context_Tracking_نما;
      BOOLEAN EffectiveOnly;
    } SECURITY_QUALITY_از_SERVICE_2,*PSECURITY_QUALITY_از_SERVICE;

    تعريفنوع بنية _SE_IMPERSONATION_STATE {
      PACCESS_TOKEN Token;
      BOOLEAN CopyOnOpen;
      BOOLEAN EffectiveOnly;
      SECURITY_IMPERSONATION_LEVEL Level;
    } SE_IMPERSONATION_STATE,*PSE_IMPERSONATION_STATE;

#تعریف_کن DISABLE_MAX_PRIVILEGE 0x1
#تعریف_کن SANDBOX_INERT 0x2

    تعريفنوع DWORD SECURITY_INFORMATION,*PSECURITY_INFORMATION;

#تعریف_کن OWNER_SECURITY_INFORMATION (0x00000001L)
#تعریف_کن گروه_SECURITY_INFORMATION (0x00000002L)
#تعریف_کن DACL_SECURITY_INFORMATION (0x00000004L)
#تعریف_کن SACL_SECURITY_INFORMATION (0x00000008L)

#تعریف_کن PROTECTED_DACL_SECURITY_INFORMATION (0x80000000L)
#تعریف_کن PROTECTED_SACL_SECURITY_INFORMATION (0x40000000L)
#تعریف_کن UNPROTECTED_DACL_SECURITY_INFORMATION (0x20000000L)
#تعریف_کن UNPROTECTED_SACL_SECURITY_INFORMATION (0x10000000L)

#تعریف_کن PROCESS_TERMINATE (0x0001)
#تعریف_کن PROCESS_CREATE_THREAD (0x0002)
#تعریف_کن PROCESS_مجموعه_SESSIONID (0x0004)
#تعریف_کن PROCESS_VM_OPERATION (0x0008)
#تعریف_کن PROCESS_VM_READ (0x0010)
#تعریف_کن PROCESS_VM_WRITE (0x0020)
#تعریف_کن PROCESS_DUP_HANDLE (0x0040)
#تعریف_کن PROCESS_CREATE_PROCESS (0x0080)
#تعریف_کن PROCESS_مجموعه_QUOTA (0x0100)
#تعریف_کن PROCESS_مجموعه_INFORMATION (0x0200)
#تعریف_کن PROCESS_QUERY_INFORMATION (0x0400)
#تعریف_کن PROCESS_SUSPEND_RESUME (0x0800)
#تعریف_کن PROCESS_QUERY_LIMITED_INFORMATION (0x1000)
#تعریف_کن PROCESS_مجموعه_LIMITED_INFORMATION (0x2000)
#تعریف_کن PROCESS_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0xFFF)

#اگر_تعریف_شده _WIN64
#تعریف_کن بیشینه_PROCESSORS 64
#وإلا
#تعریف_کن بیشینه_PROCESSORS 32
#پایان_اگر

#تعریف_کن THREAD_TERMINATE (0x0001)
#تعریف_کن THREAD_SUSPEND_RESUME (0x0002)
#تعریف_کن THREAD_GET_CONTEXT (0x0008)
#تعریف_کن THREAD_مجموعه_CONTEXT (0x0010)
#تعریف_کن THREAD_مجموعه_INFORMATION (0x0020)
#تعریف_کن THREAD_QUERY_INFORMATION (0x0040)
#تعریف_کن THREAD_مجموعه_THREAD_TOKEN (0x0080)
#تعریف_کن THREAD_IMPERSONATE (0x0100)
#تعریف_کن THREAD_مستقیم_IMPERSONATION (0x0200)

#تعریف_کن THREAD_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0x3FF)

#تعریف_کن کار_OBJECT_تخصیص_بده_PROCESS (0x0001)
#تعریف_کن کار_OBJECT_مجموعه_صفات (0x0002)
#تعریف_کن کار_OBJECT_QUERY (0x0004)
#تعریف_کن کار_OBJECT_TERMINATE (0x0008)
#تعریف_کن کار_OBJECT_مجموعه_SECURITY_صفات (0x0010)
#تعریف_کن کار_OBJECT_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0x1F)

    تعريفنوع بنية کار_مجموعه_ARRAY {
      HANDLE کار_Handle;
      DWORD MemberLevel;
      DWORD Flags;
    } کار_مجموعه_ARRAY_2,*PJOB_مجموعه_ARRAY;

#تعریف_کن FLS_بیشینه_موجود 128
#تعریف_کن TLS_MINIMUM_موجود 64

#اگر_تعریف_نشده _NT_TIB_DEFINED
#تعریف_کن _NT_TIB_DEFINED
    تعريفنوع بنية _NT_TIB {
      بنية EXCEPTION_REGISTRATION_رکورد_2 *ExceptionList;
      PVOID پشته_پایه;
      PVOID پشته_حد;
      PVOID SubSystemTib;
      اتحاد {
	PVOID Fiber_داده;
	DWORD نسخه_2;
      };
      PVOID Arbitrary_User_اشاره_گر;
      بنية _NT_TIB *Self;
    } NT_TIB;
    تعريفنوع NT_TIB *PNT_TIB;
#پایان_اگر

    تعريفنوع بنية _NT_TIB32 {
      DWORD ExceptionList;
      DWORD پشته_پایه;
      DWORD پشته_حد;
      DWORD SubSystemTib;
      اتحاد {
	DWORD Fiber_داده;
	DWORD نسخه_2;
      };
      DWORD Arbitrary_User_اشاره_گر;
      DWORD Self;
    } NT_TIB32,*PNT_TIB32;

    تعريفنوع بنية _NT_TIB64 {
      DWORD64 ExceptionList;
      DWORD64 پشته_پایه;
      DWORD64 پشته_حد;
      DWORD64 SubSystemTib;
      اتحاد {
	DWORD64 Fiber_داده;
	DWORD نسخه_2;
      };
      DWORD64 Arbitrary_User_اشاره_گر;
      DWORD64 Self;
    } NT_TIB64,*PNT_TIB64;

#إذا !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_)
#تعریف_کن WX86
#پایان_اگر

#تعریف_کن THREAD_پایه_اولویت_LOWRT 15
#تعریف_کن THREAD_پایه_اولویت_MAX 2
#تعریف_کن THREAD_پایه_اولویت_MIN (-2)
#تعریف_کن THREAD_پایه_اولویت_IDLE (-15)

    تعريفنوع بنية _QUOTA_LIMITS {
      اندازه_T Paged_Pool_حد;
      اندازه_T Non_Paged_Pool_حد;
      اندازه_T Minimum_Working_مجموعه_اندازه;
      اندازه_T بیشینه_Working_مجموعه_اندازه;
      اندازه_T Pagefile_حد;
      LARGE_INTEGER زمان_حد;
    } QUOTA_LIMITS,*PQUOTA_LIMITS;

#تعریف_کن QUOTA_LIMITS_HARDWS_MIN_ENABLE 0x00000001
#تعریف_کن QUOTA_LIMITS_HARDWS_MIN_DISABLE 0x00000002
#تعریف_کن QUOTA_LIMITS_HARDWS_MAX_ENABLE 0x00000004
#تعریف_کن QUOTA_LIMITS_HARDWS_MAX_DISABLE 0x00000008

    تعريفنوع بنية _QUOTA_LIMITS_EX {
      اندازه_T Paged_Pool_حد;
      اندازه_T Non_Paged_Pool_حد;
      اندازه_T Minimum_Working_مجموعه_اندازه;
      اندازه_T بیشینه_Working_مجموعه_اندازه;
      اندازه_T Pagefile_حد;
      LARGE_INTEGER زمان_حد;
      اندازه_T Reserved1;
      اندازه_T Reserved2;
      اندازه_T Reserved3;
      اندازه_T Reserved4;
      DWORD Flags;
      DWORD Reserved5;
    } QUOTA_LIMITS_EX,*PQUOTA_LIMITS_EX;

    تعريفنوع بنية _IO_COUNTERS {
      ULONGLONG Read_Operation_شمار;
      ULONGLONG Write_Operation_شمار;
      ULONGLONG Other_Operation_شمار;
      ULONGLONG Read_Transfer_شمار;
      ULONGLONG Write_Transfer_شمار;
      ULONGLONG Other_Transfer_شمار;
    } IO_COUNTERS;
    تعريفنوع IO_COUNTERS *PIO_COUNTERS;

    تعريفنوع بنية _JOBOBJECT_BASIC_ACCOUNTING_INFORMATION {
      LARGE_INTEGER مجموع_User_زمان;
      LARGE_INTEGER مجموع_Kernel_زمان;
      LARGE_INTEGER This_Period_مجموع_User_زمان;
      LARGE_INTEGER This_Period_مجموع_Kernel_زمان;
      DWORD مجموع_صفحه_Fault_شمار;
      DWORD مجموع_Processes;
      DWORD فعال_Processes;
      DWORD مجموع_Terminated_Processes;
    } JOBOBJECT_BASIC_ACCOUNTING_INFORMATION,*PJOBOBJECT_BASIC_ACCOUNTING_INFORMATION;

    تعريفنوع بنية JOBOBJECT_BASIC_حد_INFORMATION {
      LARGE_INTEGER در_هر_Process_User_زمان_حد;
      LARGE_INTEGER در_هر_کار_User_زمان_حد;
      DWORD حد_Flags;
      اندازه_T Minimum_Working_مجموعه_اندازه;
      اندازه_T بیشینه_Working_مجموعه_اندازه;
      DWORD فعال_Process_حد;
      ULONG_PTR Affinity;
      DWORD اولویت_Class;
      DWORD SchedulingClass;
    } JOBOBJECT_BASIC_حد_INFORMATION_2,*PJOBOBJECT_BASIC_حد_INFORMATION;

    تعريفنوع بنية JOBOBJECT_EXTENDED_حد_INFORMATION {
      JOBOBJECT_BASIC_حد_INFORMATION_2 Basic_حد_Information;
      IO_COUNTERS IoInfo;
      اندازه_T Process_حافظه_حد;
      اندازه_T کار_حافظه_حد;
      اندازه_T Peak_Process_حافظه_استفاده_شده;
      اندازه_T Peak_کار_حافظه_استفاده_شده;
    } JOBOBJECT_EXTENDED_حد_INFORMATION_2,*PJOBOBJECT_EXTENDED_حد_INFORMATION;

    تعريفنوع بنية _JOBOBJECT_BASIC_PROCESS_ID_LIST {
      DWORD عدد_از_Assigned_Processes;
      DWORD عدد_از_Process_Ids_درون_List;
      ULONG_PTR ProcessIdList[1];
    } JOBOBJECT_BASIC_PROCESS_ID_LIST,*PJOBOBJECT_BASIC_PROCESS_ID_LIST;

    تعريفنوع بنية _JOBOBJECT_BASIC_UI_RESTRICTIONS {
      DWORD UIRestrictionsClass;
    } JOBOBJECT_BASIC_UI_RESTRICTIONS,*PJOBOBJECT_BASIC_UI_RESTRICTIONS;

    تعريفنوع بنية JOBOBJECT_SECURITY_حد_INFORMATION {
      DWORD Security_حد_Flags;
      HANDLE کار_Token;
      PTOKEN_GROUPS Sids_مقصد_Disable;
      PTOKEN_PRIVILEGES Privileges_مقصد_Delete;
      PTOKEN_GROUPS RestrictedSids;
    } JOBOBJECT_SECURITY_حد_INFORMATION_2,*PJOBOBJECT_SECURITY_حد_INFORMATION;

    تعريفنوع بنية JOBOBJECT_انتها_از_کار_زمان_INFORMATION {
      DWORD انتها_از_کار_زمان_Action;
    } JOBOBJECT_انتها_از_کار_زمان_INFORMATION_2,*PJOBOBJECT_انتها_از_کار_زمان_INFORMATION;

    تعريفنوع بنية JOBOBJECT_ASSOCIATE_COMPLETION_پورت {
      PVOID Completion_کلید;
      HANDLE Completion_پورت;
    } JOBOBJECT_ASSOCIATE_COMPLETION_پورت_2,*PJOBOBJECT_ASSOCIATE_COMPLETION_پورت;

    تعريفنوع بنية _JOBOBJECT_BASIC_AND_IO_ACCOUNTING_INFORMATION {
      JOBOBJECT_BASIC_ACCOUNTING_INFORMATION BasicInfo;
      IO_COUNTERS IoInfo;
    } JOBOBJECT_BASIC_AND_IO_ACCOUNTING_INFORMATION,*PJOBOBJECT_BASIC_AND_IO_ACCOUNTING_INFORMATION;

    تعريفنوع بنية _JOBOBJECT_JOBSET_INFORMATION {
      DWORD MemberLevel;
    } JOBOBJECT_JOBSET_INFORMATION,*PJOBOBJECT_JOBSET_INFORMATION;

#تعریف_کن کار_OBJECT_TERMINATE_AT_انتها_از_کار 0
#تعریف_کن کار_OBJECT_POST_AT_انتها_از_کار 1

#تعریف_کن کار_OBJECT_پیام_انتها_از_کار_زمان 1
#تعریف_کن کار_OBJECT_پیام_انتها_از_PROCESS_زمان 2
#تعریف_کن کار_OBJECT_پیام_فعال_PROCESS_حد 3
#تعریف_کن کار_OBJECT_پیام_فعال_PROCESS_ZERO 4
#تعریف_کن کار_OBJECT_پیام_NEW_PROCESS 6
#تعریف_کن کار_OBJECT_پیام_EXIT_PROCESS 7
#تعریف_کن کار_OBJECT_پیام_ABNORMAL_EXIT_PROCESS 8
#تعریف_کن کار_OBJECT_پیام_PROCESS_حافظه_حد 9
#تعریف_کن کار_OBJECT_پیام_کار_حافظه_حد 10

#تعریف_کن کار_OBJECT_حد_WORKINGSET 0x00000001
#تعریف_کن کار_OBJECT_حد_PROCESS_زمان 0x00000002
#تعریف_کن کار_OBJECT_حد_کار_زمان 0x00000004
#تعریف_کن کار_OBJECT_حد_فعال_PROCESS 0x00000008
#تعریف_کن کار_OBJECT_حد_AFFINITY 0x00000010
#تعریف_کن کار_OBJECT_حد_اولویت_CLASS 0x00000020
#تعریف_کن کار_OBJECT_حد_PRESERVE_کار_زمان 0x00000040
#تعریف_کن کار_OBJECT_حد_SCHEDULING_CLASS 0x00000080

#تعریف_کن کار_OBJECT_حد_PROCESS_حافظه 0x00000100
#تعریف_کن کار_OBJECT_حد_کار_حافظه 0x00000200
#تعریف_کن کار_OBJECT_حد_DIE_ON_UNHANDLED_EXCEPTION 0x00000400
#تعریف_کن کار_OBJECT_حد_BREAKAWAY_OK 0x00000800
#تعریف_کن کار_OBJECT_حد_SILENT_BREAKAWAY_OK 0x00001000
#تعریف_کن کار_OBJECT_حد_KILL_ON_کار_CLOSE 0x00002000

#تعریف_کن کار_OBJECT_حد_RESERVED2 0x00004000
#تعریف_کن کار_OBJECT_حد_RESERVED3 0x00008000
#تعریف_کن کار_OBJECT_حد_RESERVED4 0x00010000
#تعریف_کن کار_OBJECT_حد_RESERVED5 0x00020000
#تعریف_کن کار_OBJECT_حد_RESERVED6 0x00040000

#تعریف_کن کار_OBJECT_حد_VALID_FLAGS 0x0007ffff

#تعریف_کن کار_OBJECT_BASIC_حد_VALID_FLAGS 0x000000ff
#تعریف_کن کار_OBJECT_EXTENDED_حد_VALID_FLAGS 0x00003fff
#تعریف_کن کار_OBJECT_RESERVED_حد_VALID_FLAGS 0x0007ffff

#تعریف_کن کار_OBJECT_UILIMIT_NONE 0x00000000

#تعریف_کن کار_OBJECT_UILIMIT_HANDLES 0x00000001
#تعریف_کن کار_OBJECT_UILIMIT_READCLIPBOARD 0x00000002
#تعریف_کن کار_OBJECT_UILIMIT_WRITECLIPBOARD 0x00000004
#تعریف_کن کار_OBJECT_UILIMIT_SYSTEMPARAMETERS 0x00000008
#تعریف_کن کار_OBJECT_UILIMIT_DISPLAYSETTINGS 0x00000010
#تعریف_کن کار_OBJECT_UILIMIT_GLOBALATOMS 0x00000020
#تعریف_کن کار_OBJECT_UILIMIT_DESKTOP 0x00000040
#تعریف_کن کار_OBJECT_UILIMIT_EXITWINDOWS 0x00000080

#تعریف_کن کار_OBJECT_UILIMIT_ALL 0x000000FF

#تعریف_کن کار_OBJECT_UI_VALID_FLAGS 0x000000FF

#تعریف_کن کار_OBJECT_SECURITY_NO_ADMIN 0x00000001
#تعریف_کن کار_OBJECT_SECURITY_RESTRICTED_TOKEN 0x00000002
#تعریف_کن کار_OBJECT_SECURITY_ONLY_TOKEN 0x00000004
#تعریف_کن کار_OBJECT_SECURITY_FILTER_نشانهها 0x00000008

#تعریف_کن کار_OBJECT_SECURITY_VALID_FLAGS 0x0000000f

    تعريفنوع تعداد _JOBOBJECTINFOCLASS {
      کار_Object_Basic_Accounting_Information = 1,کار_Object_Basic_حد_Information,کار_Object_Basic_Process_Id_List,کار_Object_Basic_UIRestrictions,
      کار_Object_Security_حد_Information,کار_Object_انتها_از_کار_زمان_Information,کار_Object_Associate_Completion_پورت_Information,
      کار_Object_Basic_And_Io_Accounting_Information,کار_Object_Extended_حد_Information,کار_Object_کار_مجموعه_Information,Max_کار_Object_Info_Class
    } JOBOBJECTINFOCLASS;

#تعریف_کن EVENT_MODIFY_STATE 0x0002
#تعریف_کن EVENT_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x3)

#تعریف_کن MUTANT_QUERY_STATE 0x0001

#تعریف_کن MUTANT_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE| MUTANT_QUERY_STATE)
#تعریف_کن SEMAPHORE_MODIFY_STATE 0x0002
#تعریف_کن SEMAPHORE_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x3)

#تعریف_کن TIMER_QUERY_STATE 0x0001
#تعریف_کن TIMER_MODIFY_STATE 0x0002

#تعریف_کن TIMER_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE| TIMER_QUERY_STATE|TIMER_MODIFY_STATE)

#تعریف_کن زمان_ZONE_ID_UNKNOWN 0
#تعریف_کن زمان_ZONE_ID_STANDARD 1
#تعریف_کن زمان_ZONE_ID_DAYLIGHT 2

    تعريفنوع تعداد _LOGICAL_PROCESSOR_RELATIONSHIP {
      رابطه_Processor_Core,رابطه_Numa_گره,رابطه_Cache
    } LOGICAL_PROCESSOR_RELATIONSHIP;

#تعریف_کن LTP_PC_SMT 0x1

    تعريفنوع تعداد _PROCESSOR_CACHE_TYPE {
      CacheUnified,CacheInstruction,Cache_داده,CacheTrace
    } PROCESSOR_CACHE_TYPE;

#تعریف_کن CACHE_FULLY_ASSOCIATIVE 0xFF

    تعريفنوع بنية _CACHE_DESCRIPTOR {
      BYTE Level;
      BYTE Associativity;
      کلمه_3 سطر_اندازه_2;
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
	  DWORD گره_عدد;
	} Numa_گره;
	CACHE_DESCRIPTOR Cache;
	ULONGLONG Reserved[2];
      };
    } SYSTEM_LOGICAL_PROCESSOR_INFORMATION,*PSYSTEM_LOGICAL_PROCESSOR_INFORMATION;

#تعریف_کن PROCESSOR_INTEL_386 386
#تعریف_کن PROCESSOR_INTEL_486 486
#تعریف_کن PROCESSOR_INTEL_PENTIUM 586
#تعریف_کن PROCESSOR_INTEL_IA64 2200
#تعریف_کن PROCESSOR_AMD_X8664 8664
#تعریف_کن PROCESSOR_MIPS_R4000 4000
#تعریف_کن PROCESSOR_ALPHA_21064 21064
#تعریف_کن PROCESSOR_PPC_601 601
#تعریف_کن PROCESSOR_PPC_603 603
#تعریف_کن PROCESSOR_PPC_604 604
#تعریف_کن PROCESSOR_PPC_620 620
#تعریف_کن PROCESSOR_HITACHI_SH3 10003
#تعریف_کن PROCESSOR_HITACHI_SH3E 10004
#تعریف_کن PROCESSOR_HITACHI_SH4 10005
#تعریف_کن PROCESSOR_MOTOROLA_821 821
#تعریف_کن PROCESSOR_SHx_SH3 103
#تعریف_کن PROCESSOR_SHx_SH4 104
#تعریف_کن PROCESSOR_STRONGARM 2577
#تعریف_کن PROCESSOR_ARM720 1824
#تعریف_کن PROCESSOR_ARM820 2080
#تعریف_کن PROCESSOR_ARM920 2336
#تعریف_کن PROCESSOR_ARM_7TDMI 70001
#تعریف_کن PROCESSOR_OPTIL 0x494f

#تعریف_کن PROCESSOR_ARCHITECTURE_INTEL 0
#تعریف_کن PROCESSOR_ARCHITECTURE_MIPS 1
#تعریف_کن PROCESSOR_ARCHITECTURE_ALPHA 2
#تعریف_کن PROCESSOR_ARCHITECTURE_PPC 3
#تعریف_کن PROCESSOR_ARCHITECTURE_SHX 4
#تعریف_کن PROCESSOR_ARCHITECTURE_ARM 5
#تعریف_کن PROCESSOR_ARCHITECTURE_IA64 6
#تعریف_کن PROCESSOR_ARCHITECTURE_ALPHA64 7
#تعریف_کن PROCESSOR_ARCHITECTURE_MSIL 8
#تعریف_کن PROCESSOR_ARCHITECTURE_AMD64 9
#تعریف_کن PROCESSOR_ARCHITECTURE_IA32_ON_WIN64 10

#تعریف_کن PROCESSOR_ARCHITECTURE_UNKNOWN 0xFFFF

#تعریف_کن PF_FLOATING_نقطه_PRECISION_ERRATA 0
#تعریف_کن PF_FLOATING_نقطه_EMULATED 1
#تعریف_کن PF_COMPARE_EXCHANGE_DOUBLE 2
#تعریف_کن PF_MMX_INSTRUCTIONS_موجود 3
#تعریف_کن PF_PPC_MOVEMEM_64_بیت_OK 4
#تعریف_کن PF_ALPHA_BYTE_INSTRUCTIONS 5
#تعریف_کن PF_XMMI_INSTRUCTIONS_موجود 6
#تعریف_کن PF_3_DNOW_INSTRUCTIONS_موجود 7
#تعریف_کن PF_RDTSC_INSTRUCTION_موجود 8
#تعریف_کن PF_PAE_ENABLED 9
#تعریف_کن PF_XMMI64_INSTRUCTIONS_موجود 10
#تعریف_کن PF_SSE_DAZ_نما_موجود 11
#تعریف_کن PF_NX_ENABLED 12

    تعريفنوع بنية حافظه_BASIC_INFORMATION_2 {
      PVOID پایه_آدرس;
      PVOID تخصیص_پایه;
      DWORD تخصیص_Protect;
      اندازه_T Region_اندازه;
      DWORD State;
      DWORD Protect;
      DWORD Type;
    } حافظه_BASIC_INFORMATION,*PMEMORY_BASIC_INFORMATION;

    تعريفنوع بنية حافظه_BASIC_INFORMATION32 {
      DWORD پایه_آدرس;
      DWORD تخصیص_پایه;
      DWORD تخصیص_Protect;
      DWORD Region_اندازه;
      DWORD State;
      DWORD Protect;
      DWORD Type;
    } حافظه_BASIC_INFORMATION32_2,*PMEMORY_BASIC_INFORMATION32;

    تعريفنوع بنية DECLSPEC_ALIGN(16) حافظه_BASIC_INFORMATION64 {
      ULONGLONG پایه_آدرس;
      ULONGLONG تخصیص_پایه;
      DWORD تخصیص_Protect;
      DWORD __alignment1;
      ULONGLONG Region_اندازه;
      DWORD State;
      DWORD Protect;
      DWORD Type;
      DWORD __alignment2;
    } حافظه_BASIC_INFORMATION64_2,*PMEMORY_BASIC_INFORMATION64;

#تعریف_کن SECTION_QUERY 0x0001
#تعریف_کن SECTION_MAP_WRITE 0x0002
#تعریف_کن SECTION_MAP_READ 0x0004
#تعریف_کن SECTION_MAP_EXECUTE 0x0008
#تعریف_کن SECTION_EXTEND_اندازه 0x0010
#تعریف_کن SECTION_MAP_EXECUTE_EXPLICIT 0x0020

#تعریف_کن SECTION_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SECTION_QUERY| SECTION_MAP_WRITE | SECTION_MAP_READ | SECTION_MAP_EXECUTE | SECTION_EXTEND_اندازه)
#تعریف_کن صفحه_NOACCESS 0x01
#تعریف_کن صفحه_READONLY 0x02
#تعریف_کن صفحه_READWRITE 0x04
#تعریف_کن صفحه_WRITECOPY 0x08
#تعریف_کن صفحه_EXECUTE 0x10
#تعریف_کن صفحه_EXECUTE_READ 0x20
#تعریف_کن صفحه_EXECUTE_READWRITE 0x40
#تعریف_کن صفحه_EXECUTE_WRITECOPY 0x80
#تعریف_کن صفحه_GUARD 0x100
#تعریف_کن صفحه_NOCACHE 0x200
#تعریف_کن صفحه_WRITECOMBINE 0x400
#تعریف_کن MEM_COMMIT 0x1000
#تعریف_کن MEM_RESERVE 0x2000
#تعریف_کن MEM_DECOMMIT 0x4000
#تعریف_کن MEM_RELEASE 0x8000
#تعریف_کن MEM_FREE 0x10000
#تعریف_کن MEM_خصوصی 0x20000
#تعریف_کن MEM_MAPPED 0x40000
#تعریف_کن MEM_RESET 0x80000
#تعریف_کن MEM_بالاترین_پایین 0x100000
#تعریف_کن MEM_WRITE_WATCH 0x200000
#تعریف_کن MEM_PHYSICAL 0x400000
#تعریف_کن MEM_LARGE_صفحات 0x20000000
#تعریف_کن MEM_4_MB_صفحات 0x80000000
#تعریف_کن SEC_FILE 0x800000
#تعریف_کن SEC_IMAGE 0x1000000
#تعریف_کن SEC_RESERVE 0x4000000
#تعریف_کن SEC_COMMIT 0x8000000
#تعریف_کن SEC_NOCACHE 0x10000000
#تعریف_کن SEC_LARGE_صفحات 0x80000000
#تعریف_کن MEM_IMAGE SEC_IMAGE
#تعریف_کن WRITE_WATCH_FLAG_RESET 0x01

#تعریف_کن FILE_READ_داده (0x0001)
#تعریف_کن FILE_LIST_DIRECTORY (0x0001)

#تعریف_کن FILE_WRITE_داده (0x0002)
#تعریف_کن FILE_جمع_کن_FILE (0x0002)

#تعریف_کن FILE_APPEND_داده (0x0004)
#تعریف_کن FILE_جمع_کن_SUBDIRECTORY (0x0004)
#تعریف_کن FILE_CREATE_PIPE_INSTANCE (0x0004)

#تعریف_کن FILE_READ_EA (0x0008)

#تعریف_کن FILE_WRITE_EA (0x0010)

#تعریف_کن FILE_EXECUTE (0x0020)
#تعریف_کن FILE_TRAVERSE (0x0020)

#تعریف_کن FILE_DELETE_فرزند (0x0040)

#تعریف_کن FILE_READ_صفات (0x0080)

#تعریف_کن FILE_WRITE_صفات (0x0100)

#تعریف_کن FILE_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0x1FF)
#تعریف_کن FILE_GENERIC_READ (STANDARD_RIGHTS_READ | FILE_READ_داده | FILE_READ_صفات | FILE_READ_EA | SYNCHRONIZE)
#تعریف_کن FILE_GENERIC_WRITE (STANDARD_RIGHTS_WRITE | FILE_WRITE_داده | FILE_WRITE_صفات | FILE_WRITE_EA | FILE_APPEND_داده | SYNCHRONIZE)
#تعریف_کن FILE_GENERIC_EXECUTE (STANDARD_RIGHTS_EXECUTE | FILE_READ_صفات | FILE_EXECUTE | SYNCHRONIZE)

#تعریف_کن FILE_SHARE_READ 0x00000001
#تعریف_کن FILE_SHARE_WRITE 0x00000002
#تعریف_کن FILE_SHARE_DELETE 0x00000004
#تعریف_کن FILE_ATTRIBUTE_READONLY 0x00000001
#تعریف_کن FILE_ATTRIBUTE_HIDDEN 0x00000002
#تعریف_کن FILE_ATTRIBUTE_SYSTEM 0x00000004
#تعریف_کن FILE_ATTRIBUTE_DIRECTORY 0x00000010
#تعریف_کن FILE_ATTRIBUTE_ARCHIVE 0x00000020
#تعریف_کن FILE_ATTRIBUTE_DEVICE 0x00000040
#تعریف_کن FILE_ATTRIBUTE_نرمال 0x00000080
#تعریف_کن FILE_ATTRIBUTE_TEMPORARY 0x00000100
#تعریف_کن FILE_ATTRIBUTE_SPARSE_FILE 0x00000200
#تعریف_کن FILE_ATTRIBUTE_REPARSE_نقطه 0x00000400
#تعریف_کن FILE_ATTRIBUTE_COMPRESSED 0x00000800
#تعریف_کن FILE_ATTRIBUTE_OFFLINE 0x00001000
#تعریف_کن FILE_ATTRIBUTE_NOT_CONTENT_نمایهای 0x00002000
#تعریف_کن FILE_ATTRIBUTE_ENCRYPTED 0x00004000
#تعریف_کن FILE_NOTIFY_CHANGE_FILE_NAME 0x00000001
#تعریف_کن FILE_NOTIFY_CHANGE_DIR_NAME 0x00000002
#تعریف_کن FILE_NOTIFY_CHANGE_صفات 0x00000004
#تعریف_کن FILE_NOTIFY_CHANGE_اندازه 0x00000008
#تعریف_کن FILE_NOTIFY_CHANGE_آخرین_WRITE 0x00000010
#تعریف_کن FILE_NOTIFY_CHANGE_آخرین_ACCESS 0x00000020
#تعریف_کن FILE_NOTIFY_CHANGE_CREATION 0x00000040
#تعریف_کن FILE_NOTIFY_CHANGE_SECURITY 0x00000100
#تعریف_کن FILE_ACTION_ADDED 0x00000001
#تعریف_کن FILE_ACTION_REMOVED 0x00000002
#تعریف_کن FILE_ACTION_MODIFIED 0x00000003
#تعریف_کن FILE_ACTION_RENAMED_OLD_NAME 0x00000004
#تعریف_کن FILE_ACTION_RENAMED_NEW_NAME 0x00000005
#تعریف_کن MAILSLOT_NO_پیام ((DWORD)-1)
#تعریف_کن MAILSLOT_WAIT_FOREVER ((DWORD)-1)
#تعریف_کن FILE_CASE_SENSITIVE_جستجو 0x00000001
#تعریف_کن FILE_CASE_PRESERVED_نامها 0x00000002
#تعریف_کن FILE_UNICODE_ON_DISK 0x00000004
#تعریف_کن FILE_PERSISTENT_ACLS 0x00000008
#تعریف_کن FILE_FILE_COMPRESSION 0x00000010
#تعریف_کن FILE_VOLUME_QUOTAS 0x00000020
#تعریف_کن FILE_SUPPORTS_SPARSE_FILES 0x00000040
#تعریف_کن FILE_SUPPORTS_REPARSE_POINTS 0x00000080
#تعریف_کن FILE_SUPPORTS_REMOTE_STORAGE 0x00000100
#تعریف_کن FILE_VOLUME_IS_COMPRESSED 0x00008000
#تعریف_کن FILE_SUPPORTS_OBJECT_IDS 0x00010000
#تعریف_کن FILE_SUPPORTS_ENCRYPTION 0x00020000
#تعریف_کن FILE_NAMED_STREAMS 0x00040000
#تعریف_کن FILE_READ_ONLY_VOLUME 0x00080000

    تعريفنوع بنية _FILE_NOTIFY_INFORMATION {
      DWORD بعدی_مدخل_جابه_جایی;
      DWORD Action;
      DWORD File_Name_درازی;
      WCHAR FileName[1];
    } FILE_NOTIFY_INFORMATION,*PFILE_NOTIFY_INFORMATION;

    تعريفنوع اتحاد _FILE_SEGMENT_ELEMENT {
      PVOID64 میانگیر_3;
      ULONGLONG Alignment;
    }FILE_SEGMENT_ELEMENT,*PFILE_SEGMENT_ELEMENT;

    تعريفنوع بنية REPARSE_GUID_داده_میانگیر {
      DWORD Reparse_برچسب;
      کلمه_3 Reparse_داده_درازی;
      کلمه_3 Reserved;
      GUID ReparseGuid;
      بنية {
	BYTE داده_میانگیر[1];
      } Generic_Reparse_میانگیر;
    } REPARSE_GUID_داده_میانگیر_2,*PREPARSE_GUID_داده_میانگیر;

#تعریف_کن REPARSE_GUID_داده_میانگیر_سرآیند_اندازه فیلد_جابه_جایی(REPARSE_GUID_داده_میانگیر_2,Generic_Reparse_میانگیر)

#تعریف_کن بیشینه_REPARSE_داده_میانگیر_اندازه (16 *1024)

#تعریف_کن IO_REPARSE_برچسب_RESERVED_ZERO (0)
#تعریف_کن IO_REPARSE_برچسب_RESERVED_ONE (1)

#تعریف_کن IO_REPARSE_برچسب_RESERVED_RANGE IO_REPARSE_برچسب_RESERVED_ONE

#تعریف_کن Is_Reparse_برچسب_Microsoft(برچسب_2) (((برچسب_2) & 0x80000000))
#تعریف_کن Is_Reparse_برچسب_Name_Surrogate(برچسب_2) (((برچسب_2) & 0x20000000))

#تعریف_کن IO_REPARSE_برچسب_MOUNT_نقطه (0xA0000003L)
#تعریف_کن IO_REPARSE_برچسب_HSM (0xC0000004L)
#تعریف_کن IO_REPARSE_برچسب_SIS (0x80000007L)
#تعریف_کن IO_REPARSE_برچسب_DFS (0x8000000AL)
#تعریف_کن IO_REPARSE_برچسب_FILTER_MANAGER (0x8000000BL)
#تعریف_کن IO_COMPLETION_MODIFY_STATE 0x0002
#تعریف_کن IO_COMPLETION_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x3)
#تعریف_کن DUPLICATE_CLOSE_منبع 0x00000001
#تعریف_کن DUPLICATE_SAME_ACCESS 0x00000002

    تعريفنوع تعداد _SYSTEM_POWER_STATE {
      PowerSystemUnspecified = 0,PowerSystemWorking = 1,PowerSystemSleeping1 = 2,PowerSystemSleeping2 = 3,PowerSystemSleeping3 = 4,PowerSystemHibernate = 5,PowerSystemShutdown = 6,Power_System_بیشینه = 7
    } SYSTEM_POWER_STATE,*PSYSTEM_POWER_STATE;

#تعریف_کن POWER_SYSTEM_بیشینه 7

    تعريفنوع تعداد {
      PowerActionNone = 0,PowerActionReserved,PowerActionSleep,PowerActionHibernate,PowerActionShutdown,PowerActionShutdownReset,PowerActionShutdownOff,PowerActionWarmEject
    } POWER_ACTION,*PPOWER_ACTION;

    تعريفنوع تعداد _DEVICE_POWER_STATE {
      PowerDeviceUnspecified = 0,PowerDeviceD0,PowerDeviceD1,PowerDeviceD2,PowerDeviceD3,Power_Device_بیشینه
    } DEVICE_POWER_STATE,*PDEVICE_POWER_STATE;

#تعریف_کن ES_SYSTEM_REQUIRED ((DWORD)0x00000001)
#تعریف_کن ES_DISPLAY_REQUIRED ((DWORD)0x00000002)
#تعریف_کن ES_USER_PRESENT ((DWORD)0x00000004)
#تعریف_کن ES_CONTINUOUS ((DWORD)0x80000000)

    تعريفنوع DWORD EXECUTION_STATE;

    تعريفنوع تعداد {
      LT_DONT_CARE,LT_پایینترین_LATENCY
    } LATENCY_زمان;

#تعریف_کن PDCAP_D0_SUPPORTED 0x00000001
#تعریف_کن PDCAP_D1_SUPPORTED 0x00000002
#تعریف_کن PDCAP_D2_SUPPORTED 0x00000004
#تعریف_کن PDCAP_D3_SUPPORTED 0x00000008
#تعریف_کن PDCAP_WAKE_FROM_D0_SUPPORTED 0x00000010
#تعریف_کن PDCAP_WAKE_FROM_D1_SUPPORTED 0x00000020
#تعریف_کن PDCAP_WAKE_FROM_D2_SUPPORTED 0x00000040
#تعریف_کن PDCAP_WAKE_FROM_D3_SUPPORTED 0x00000080
#تعریف_کن PDCAP_WARM_EJECT_SUPPORTED 0x00000100

    تعريفنوع بنية CM_Power_داده_s {
      DWORD PD_اندازه;
      DEVICE_POWER_STATE PD_MostRecentPowerState;
      DWORD PD_Capabilities;
      DWORD PD_D1Latency;
      DWORD PD_D2Latency;
      DWORD PD_D3Latency;
      DEVICE_POWER_STATE PD_PowerStateMapping[POWER_SYSTEM_بیشینه];
      SYSTEM_POWER_STATE PD_عمیقترین_System_Wake;
    } CM_POWER_داده,*PCM_POWER_داده;

    تعريفنوع تعداد {
      SystemPowerPolicyAc,SystemPowerPolicyDc,VerifySystemPolicyAc,VerifySystemPolicyDc,SystemPowerCapabilities,SystemBatteryState,SystemPowerStateHandler,ProcessorStateHandler,SystemPowerPolicyCurrent,AdministratorPowerPolicy,SystemReserveHiberFile,ProcessorInformation,SystemPowerInformation,ProcessorStateHandler2,آخرین_Wake_زمان,آخرین_Sleep_زمان,SystemExecutionState,SystemPowerStateNotifyHandler,ProcessorPowerPolicyAc,ProcessorPowerPolicyDc,VerifyProcessorPowerPolicyAc,VerifyProcessorPowerPolicyDc,ProcessorPowerPolicyCurrent,SystemPowerStateLogging,System_Power_Logging_مدخل
    } POWER_INFORMATION_LEVEL;

    تعريفنوع بنية {
      DWORD Granularity;
      DWORD ظرفیت;
    } BATTERY_REPORTING_SCALE,*PBATTERY_REPORTING_SCALE;

    تعريفنوع بنية {
      POWER_ACTION Action;
      DWORD Flags;
      DWORD Event_کد;
    } POWER_ACTION_POLICY,*PPOWER_ACTION_POLICY;

#تعریف_کن POWER_ACTION_QUERY_ALLOWED 0x00000001
#تعریف_کن POWER_ACTION_UI_ALLOWED 0x00000002
#تعریف_کن POWER_ACTION_OVERRIDE_APPS 0x00000004
#تعریف_کن POWER_ACTION_LIGHTEST_اولی 0x10000000
#تعریف_کن POWER_ACTION_قفل_CONSOLE 0x20000000
#تعریف_کن POWER_ACTION_DISABLE_WAKES 0x40000000
#تعریف_کن POWER_ACTION_CRITICAL 0x80000000

#تعریف_کن POWER_LEVEL_USER_NOTIFY_متن 0x00000001
#تعریف_کن POWER_LEVEL_USER_NOTIFY_SOUND 0x00000002
#تعریف_کن POWER_LEVEL_USER_NOTIFY_EXEC 0x00000004
#تعریف_کن POWER_USER_NOTIFY_BUTTON 0x00000008
#تعریف_کن POWER_USER_NOTIFY_SHUTDOWN 0x00000010
#تعریف_کن POWER_FORCE_TRIGGER_RESET 0x80000000

    تعريفنوع بنية {
      BOOLEAN Enable;
      BYTE یدکی_2[3];
      DWORD BatteryLevel;
      POWER_ACTION_POLICY PowerPolicy;
      SYSTEM_POWER_STATE MinSystemState;
    } SYSTEM_POWER_LEVEL,*PSYSTEM_POWER_LEVEL;

#تعریف_کن رقم_DISCHARGE_POLICIES 4
#تعریف_کن DISCHARGE_POLICY_CRITICAL 0
#تعریف_کن DISCHARGE_POLICY_کم 1

#تعریف_کن PO_THROTTLE_NONE 0
#تعریف_کن PO_THROTTLE_CONSTANT 1
#تعریف_کن PO_THROTTLE_DEGRADE 2
#تعریف_کن PO_THROTTLE_ADAPTIVE 3
#تعریف_کن PO_THROTTLE_بیشینه 4

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
      DWORD پخش_ظرفیت_Resolution;
      SYSTEM_POWER_LEVEL DischargePolicy[رقم_DISCHARGE_POLICIES];
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
      DWORD زمان_Check;
      DWORD Demote_حد;
      DWORD Promote_حد;
      BYTE DemotePercent;
      BYTE PromotePercent;
      BYTE یدکی_2[2];
      DWORD AllowDemotion:1;
      DWORD AllowPromotion:1;
      DWORD Reserved:30;
    } PROCESSOR_POWER_POLICY_INFO,*PPROCESSOR_POWER_POLICY_INFO;

    تعريفنوع بنية _PROCESSOR_POWER_POLICY {
      DWORD Revision;
      BYTE DynamicThrottle;
      BYTE یدکی_2[3];
      DWORD DisableCStates:1;
      DWORD Reserved:31;
      DWORD Policy_شمار;
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
      BOOLEAN پر_Wake;
      BOOLEAN VideoDimPresent;
      BOOLEAN ApmPresent;
      BOOLEAN UpsPresent;
      BOOLEAN ThermalControl;
      BOOLEAN ProcessorThrottle;
      BYTE ProcessorMinThrottle;
      BYTE ProcessorMaxThrottle;
      BYTE spare2[4];
      BOOLEAN Disk_Spin_پایین;
      BYTE spare3[8];
      BOOLEAN SystemBatteriesPresent;
      BOOLEAN Batteries_Are_Short_جمله;
      BATTERY_REPORTING_SCALE BatteryScale[3];
      SYSTEM_POWER_STATE Ac_On_سطر_Wake;
      SYSTEM_POWER_STATE SoftLidWake;
      SYSTEM_POWER_STATE RtcWake;
      SYSTEM_POWER_STATE MinDeviceWakeState;
      SYSTEM_POWER_STATE Default_کم_Latency_Wake;
    } SYSTEM_POWER_CAPABILITIES,*PSYSTEM_POWER_CAPABILITIES;

    تعريفنوع بنية {
      BOOLEAN Ac_On_سطر;
      BOOLEAN BatteryPresent;
      BOOLEAN Charging;
      BOOLEAN Discharging;
      BOOLEAN Spare1[4];
      DWORD Max_ظرفیت;
      DWORD مانده_ظرفیت;
      DWORD نرخ;
      DWORD Estimated_زمان;
      DWORD DefaultAlert1;
      DWORD DefaultAlert2;
    } SYSTEM_BATTERY_STATE,*PSYSTEM_BATTERY_STATE;

#ضمن "pshpack4.h"

#تعریف_کن IMAGE_DOS_SIGNATURE 0x5A4D
#تعریف_کن IMAGE_OS2_SIGNATURE 0x454E
#تعریف_کن IMAGE_OS2_SIGNATURE_LE 0x454C
#تعریف_کن IMAGE_VXD_SIGNATURE 0x454C
#تعریف_کن IMAGE_NT_SIGNATURE 0x00004550

#ضمن "pshpack2.h"

    تعريفنوع بنية IMAGE_DOS_سرآیند {
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
    } IMAGE_DOS_سرآیند_2,*PIMAGE_DOS_سرآیند;

    تعريفنوع بنية IMAGE_OS2_سرآیند {
      کلمه_3 ne_magic;
      CHAR ne_ver;
      CHAR ne_rev;
      کلمه_3 ne_enttab;
      کلمه_3 ne_cbenttab;
      LONG ne_بررسی_چرخهای;
      کلمه_3 ne_flags;
      کلمه_3 ne_autodata;
      کلمه_3 ne_انباشته;
      کلمه_3 ne_پشته;
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
    } IMAGE_OS2_سرآیند_2,*PIMAGE_OS2_سرآیند;

    تعريفنوع بنية IMAGE_VXD_سرآیند {
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
    } IMAGE_VXD_سرآیند_2,*PIMAGE_VXD_سرآیند;

#ضمن "poppack.h"

    تعريفنوع بنية IMAGE_FILE_سرآیند {
      کلمه_3 Machine;
      کلمه_3 عدد_از_Sections;
      DWORD زمان_Date_Stamp;
      DWORD اشاره_گر_مقصد_نماد_جدول;
      DWORD عدد_از_Symbols;
      کلمه_3 اندازه_از_Optional_سرآیند;
      کلمه_3 Characteristics;
    } IMAGE_FILE_سرآیند_2,*PIMAGE_FILE_سرآیند;

#تعریف_کن IMAGE_SIZEOF_FILE_سرآیند 20

#تعریف_کن IMAGE_FILE_RELOCS_STRIPPED 0x0001
#تعریف_کن IMAGE_FILE_EXECUTABLE_IMAGE 0x0002
#تعریف_کن IMAGE_FILE_سطر_NUMS_STRIPPED 0x0004
#تعریف_کن IMAGE_FILE_LOCAL_SYMS_STRIPPED 0x0008
#تعریف_کن IMAGE_FILE_AGGRESIVE_WS_TRIM 0x0010
#تعریف_کن IMAGE_FILE_LARGE_آدرس_AWARE 0x0020
#تعریف_کن IMAGE_FILE_بایتها_REVERSED_LO 0x0080
#تعریف_کن IMAGE_FILE_32_بیت_MACHINE 0x0100
#تعریف_کن IMAGE_FILE_DEBUG_STRIPPED 0x0200
#تعریف_کن IMAGE_FILE_REMOVABLE_پیاپی_FROM_جابجا 0x0400
#تعریف_کن IMAGE_FILE_NET_پیاپی_FROM_جابجا 0x0800
#تعریف_کن IMAGE_FILE_SYSTEM 0x1000
#تعریف_کن IMAGE_FILE_DLL 0x2000
#تعریف_کن IMAGE_FILE_به_بالا_SYSTEM_ONLY 0x4000
#تعریف_کن IMAGE_FILE_بایتها_REVERSED_HI 0x8000

#تعریف_کن IMAGE_FILE_MACHINE_UNKNOWN 0
#تعریف_کن IMAGE_FILE_MACHINE_I386 0x014c
#تعریف_کن IMAGE_FILE_MACHINE_R3000 0x0162
#تعریف_کن IMAGE_FILE_MACHINE_R4000 0x0166
#تعریف_کن IMAGE_FILE_MACHINE_R10000 0x0168
#تعریف_کن IMAGE_FILE_MACHINE_WCEMIPSV2 0x0169
#تعریف_کن IMAGE_FILE_MACHINE_ALPHA 0x0184
#تعریف_کن IMAGE_FILE_MACHINE_SH3 0x01a2
#تعریف_کن IMAGE_FILE_MACHINE_SH3DSP 0x01a3
#تعریف_کن IMAGE_FILE_MACHINE_SH3E 0x01a4
#تعریف_کن IMAGE_FILE_MACHINE_SH4 0x01a6
#تعریف_کن IMAGE_FILE_MACHINE_SH5 0x01a8
#تعریف_کن IMAGE_FILE_MACHINE_ARM 0x01c0
#تعریف_کن IMAGE_FILE_MACHINE_THUMB 0x01c2
#تعریف_کن IMAGE_FILE_MACHINE_AM33 0x01d3
#تعریف_کن IMAGE_FILE_MACHINE_POWERPC 0x01F0
#تعریف_کن IMAGE_FILE_MACHINE_POWERPCFP 0x01f1
#تعریف_کن IMAGE_FILE_MACHINE_IA64 0x0200
#تعریف_کن IMAGE_FILE_MACHINE_MIPS16 0x0266
#تعریف_کن IMAGE_FILE_MACHINE_ALPHA64 0x0284
#تعریف_کن IMAGE_FILE_MACHINE_MIPSFPU 0x0366
#تعریف_کن IMAGE_FILE_MACHINE_MIPSFPU16 0x0466
#تعریف_کن IMAGE_FILE_MACHINE_AXP64 IMAGE_FILE_MACHINE_ALPHA64
#تعریف_کن IMAGE_FILE_MACHINE_TRICORE 0x0520
#تعریف_کن IMAGE_FILE_MACHINE_CEF 0x0CEF
#تعریف_کن IMAGE_FILE_MACHINE_EBC 0x0EBC
#تعریف_کن IMAGE_FILE_MACHINE_AMD64 0x8664
#تعریف_کن IMAGE_FILE_MACHINE_ARM64 0xAA64
#تعریف_کن IMAGE_FILE_MACHINE_M32R 0x9041
#تعریف_کن IMAGE_FILE_MACHINE_CEE 0xC0EE

    تعريفنوع بنية IMAGE_داده_DIRECTORY {
      DWORD Virtual_آدرس;
      DWORD اندازه_3;
    } IMAGE_داده_DIRECTORY_2,*PIMAGE_داده_DIRECTORY;

#تعریف_کن IMAGE_NUMBEROF_DIRECTORY_ENTRIES 16

    تعريفنوع بنية IMAGE_OPTIONAL_سرآیند {

      کلمه_3 Magic;
      BYTE Major_Linker_نسخه;
      BYTE Minor_Linker_نسخه;
      DWORD اندازه_از_کد;
      DWORD اندازه_از_Initialized_داده;
      DWORD اندازه_از_Uninitialized_داده;
      DWORD آدرس_از_مدخل_نقطه;
      DWORD پایه_از_کد;
      DWORD پایه_از_داده;
      DWORD Image_پایه;
      DWORD SectionAlignment;
      DWORD FileAlignment;
      کلمه_3 Major_Operating_System_نسخه;
      کلمه_3 Minor_Operating_System_نسخه;
      کلمه_3 Major_Image_نسخه;
      کلمه_3 Minor_Image_نسخه;
      کلمه_3 Major_Subsystem_نسخه;
      کلمه_3 Minor_Subsystem_نسخه;
      DWORD Win32_نسخه_مقدار;
      DWORD اندازه_از_Image;
      DWORD اندازه_از_سرآیندها;
      DWORD Check_جمع;
      کلمه_3 Subsystem;
      کلمه_3 DllCharacteristics;
      DWORD اندازه_از_پشته_Reserve;
      DWORD اندازه_از_پشته_Commit;
      DWORD اندازه_از_انباشته_Reserve;
      DWORD اندازه_از_انباشته_Commit;
      DWORD LoaderFlags;
      DWORD عدد_از_Rva_And_Sizes;
      IMAGE_داده_DIRECTORY_2 داده_Directory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
    } IMAGE_OPTIONAL_HEADER32,*PIMAGE_OPTIONAL_HEADER32;

    تعريفنوع بنية IMAGE_ROM_OPTIONAL_سرآیند {
      کلمه_3 Magic;
      BYTE Major_Linker_نسخه;
      BYTE Minor_Linker_نسخه;
      DWORD اندازه_از_کد;
      DWORD اندازه_از_Initialized_داده;
      DWORD اندازه_از_Uninitialized_داده;
      DWORD آدرس_از_مدخل_نقطه;
      DWORD پایه_از_کد;
      DWORD پایه_از_داده;
      DWORD پایه_از_Bss;
      DWORD Gpr_ماسک;
      DWORD Cpr_ماسک[4];
      DWORD Gp_مقدار;
    } IMAGE_ROM_OPTIONAL_سرآیند_2,*PIMAGE_ROM_OPTIONAL_سرآیند;

    تعريفنوع بنية _IMAGE_OPTIONAL_HEADER64 {
      کلمه_3 Magic;
      BYTE Major_Linker_نسخه;
      BYTE Minor_Linker_نسخه;
      DWORD اندازه_از_کد;
      DWORD اندازه_از_Initialized_داده;
      DWORD اندازه_از_Uninitialized_داده;
      DWORD آدرس_از_مدخل_نقطه;
      DWORD پایه_از_کد;
      ULONGLONG Image_پایه;
      DWORD SectionAlignment;
      DWORD FileAlignment;
      کلمه_3 Major_Operating_System_نسخه;
      کلمه_3 Minor_Operating_System_نسخه;
      کلمه_3 Major_Image_نسخه;
      کلمه_3 Minor_Image_نسخه;
      کلمه_3 Major_Subsystem_نسخه;
      کلمه_3 Minor_Subsystem_نسخه;
      DWORD Win32_نسخه_مقدار;
      DWORD اندازه_از_Image;
      DWORD اندازه_از_سرآیندها;
      DWORD Check_جمع;
      کلمه_3 Subsystem;
      کلمه_3 DllCharacteristics;
      ULONGLONG اندازه_از_پشته_Reserve;
      ULONGLONG اندازه_از_پشته_Commit;
      ULONGLONG اندازه_از_انباشته_Reserve;
      ULONGLONG اندازه_از_انباشته_Commit;
      DWORD LoaderFlags;
      DWORD عدد_از_Rva_And_Sizes;
      IMAGE_داده_DIRECTORY_2 داده_Directory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
    } IMAGE_OPTIONAL_HEADER64,*PIMAGE_OPTIONAL_HEADER64;

#تعریف_کن IMAGE_SIZEOF_ROM_OPTIONAL_سرآیند 56
#تعریف_کن IMAGE_SIZEOF_STD_OPTIONAL_سرآیند 28
#تعریف_کن IMAGE_SIZEOF_NT_OPTIONAL32_سرآیند 224
#تعریف_کن IMAGE_SIZEOF_NT_OPTIONAL64_سرآیند 240

#تعریف_کن IMAGE_NT_OPTIONAL_HDR32_MAGIC 0x10b
#تعریف_کن IMAGE_NT_OPTIONAL_HDR64_MAGIC 0x20b
#تعریف_کن IMAGE_ROM_OPTIONAL_HDR_MAGIC 0x107

#اگر_تعریف_شده _WIN64
    تعريفنوع IMAGE_OPTIONAL_HEADER64 IMAGE_OPTIONAL_سرآیند_2;
    تعريفنوع PIMAGE_OPTIONAL_HEADER64 PIMAGE_OPTIONAL_سرآیند;
#تعریف_کن IMAGE_SIZEOF_NT_OPTIONAL_سرآیند IMAGE_SIZEOF_NT_OPTIONAL64_سرآیند
#تعریف_کن IMAGE_NT_OPTIONAL_HDR_MAGIC IMAGE_NT_OPTIONAL_HDR64_MAGIC
#وإلا
    تعريفنوع IMAGE_OPTIONAL_HEADER32 IMAGE_OPTIONAL_سرآیند_2;
    تعريفنوع PIMAGE_OPTIONAL_HEADER32 PIMAGE_OPTIONAL_سرآیند;
#تعریف_کن IMAGE_SIZEOF_NT_OPTIONAL_سرآیند IMAGE_SIZEOF_NT_OPTIONAL32_سرآیند
#تعریف_کن IMAGE_NT_OPTIONAL_HDR_MAGIC IMAGE_NT_OPTIONAL_HDR32_MAGIC
#پایان_اگر

    تعريفنوع بنية _IMAGE_NT_HEADERS64 {
      DWORD Signature;
      IMAGE_FILE_سرآیند_2 File_سرآیند;
      IMAGE_OPTIONAL_HEADER64 Optional_سرآیند;
    } IMAGE_NT_HEADERS64,*PIMAGE_NT_HEADERS64;

    تعريفنوع بنية IMAGE_NT_سرآیندها {
      DWORD Signature;
      IMAGE_FILE_سرآیند_2 File_سرآیند;
      IMAGE_OPTIONAL_HEADER32 Optional_سرآیند;
    } IMAGE_NT_HEADERS32,*PIMAGE_NT_HEADERS32;

    تعريفنوع بنية IMAGE_ROM_سرآیندها {
      IMAGE_FILE_سرآیند_2 File_سرآیند;
      IMAGE_ROM_OPTIONAL_سرآیند_2 Optional_سرآیند;
    } IMAGE_ROM_سرآیندها_2,*PIMAGE_ROM_سرآیندها;

#اگر_تعریف_شده _WIN64
    تعريفنوع IMAGE_NT_HEADERS64 IMAGE_NT_سرآیندها_2;
    تعريفنوع PIMAGE_NT_HEADERS64 PIMAGE_NT_سرآیندها;
#وإلا
    تعريفنوع IMAGE_NT_HEADERS32 IMAGE_NT_سرآیندها_2;
    تعريفنوع PIMAGE_NT_HEADERS32 PIMAGE_NT_سرآیندها;
#پایان_اگر

#تعریف_کن IMAGE_اولی_SECTION(ntheader) ((PIMAGE_SECTION_سرآیند) ((ULONG_PTR)ntheader + فیلد_جابه_جایی(IMAGE_NT_سرآیندها_2,Optional_سرآیند) + ((PIMAGE_NT_سرآیندها)(ntheader))->File_سرآیند.اندازه_از_Optional_سرآیند))

#تعریف_کن IMAGE_SUBSYSTEM_UNKNOWN 0
#تعریف_کن IMAGE_SUBSYSTEM_NATIVE 1
#تعریف_کن IMAGE_SUBSYSTEM_WINDOWS_GUI 2
#تعریف_کن IMAGE_SUBSYSTEM_WINDOWS_CUI 3
#تعریف_کن IMAGE_SUBSYSTEM_OS2_CUI 5
#تعریف_کن IMAGE_SUBSYSTEM_POSIX_CUI 7
#تعریف_کن IMAGE_SUBSYSTEM_NATIVE_WINDOWS 8
#تعریف_کن IMAGE_SUBSYSTEM_WINDOWS_CE_GUI 9
#تعریف_کن IMAGE_SUBSYSTEM_EFI_APPLICATION 10
#تعریف_کن IMAGE_SUBSYSTEM_EFI_BOOT_SERVICE_DRIVER 11
#تعریف_کن IMAGE_SUBSYSTEM_EFI_RUNTIME_DRIVER 12
#تعریف_کن IMAGE_SUBSYSTEM_EFI_ROM 13
#تعریف_کن IMAGE_SUBSYSTEM_XBOX 14

#تعریف_کن IMAGE_DLLCHARACTERISTICS_بالا_ENTROPY_VA 0x0020
#تعریف_کن IMAGE_DLLCHARACTERISTICS_DYNAMIC_پایه 0x0040
#تعریف_کن IMAGE_DLLCHARACTERISTICS_FORCE_INTEGRITY 0x0080
#تعریف_کن IMAGE_DLLCHARACTERISTICS_NX_COMPAT 0x0100
#تعریف_کن IMAGE_DLLCHARACTERISTICS_NO_ISOLATION 0x0200
#تعریف_کن IMAGE_DLLCHARACTERISTICS_NO_SEH 0x0400
#تعریف_کن IMAGE_DLLCHARACTERISTICS_NO_BIND 0x0800
#تعریف_کن IMAGE_DLLCHARACTERISTICS_APPCONTAINER 0x1000
#تعریف_کن IMAGE_DLLCHARACTERISTICS_WDM_DRIVER 0x2000
#تعریف_کن IMAGE_DLLCHARACTERISTICS_GUARD_CF 0x4000
#تعریف_کن IMAGE_DLLCHARACTERISTICS_TERMINAL_SERVER_AWARE 0x8000

#تعریف_کن IMAGE_DIRECTORY_مدخل_EXPORT 0
#تعریف_کن IMAGE_DIRECTORY_مدخل_IMPORT 1
#تعریف_کن IMAGE_DIRECTORY_مدخل_RESOURCE 2
#تعریف_کن IMAGE_DIRECTORY_مدخل_EXCEPTION 3
#تعریف_کن IMAGE_DIRECTORY_مدخل_SECURITY 4
#تعریف_کن IMAGE_DIRECTORY_مدخل_BASERELOC 5
#تعریف_کن IMAGE_DIRECTORY_مدخل_DEBUG 6

#تعریف_کن IMAGE_DIRECTORY_مدخل_ARCHITECTURE 7
#تعریف_کن IMAGE_DIRECTORY_مدخل_GLOBALPTR 8
#تعریف_کن IMAGE_DIRECTORY_مدخل_TLS 9
#تعریف_کن IMAGE_DIRECTORY_مدخل_بارگیری_CONFIG 10
#تعریف_کن IMAGE_DIRECTORY_مدخل_BOUND_IMPORT 11
#تعریف_کن IMAGE_DIRECTORY_مدخل_IAT 12
#تعریف_کن IMAGE_DIRECTORY_مدخل_DELAY_IMPORT 13
#تعریف_کن IMAGE_DIRECTORY_مدخل_COM_DESCRIPTOR 14

    تعريفنوع بنية ANON_OBJECT_سرآیند {
      کلمه_3 Sig1;
      کلمه_3 Sig2;
      کلمه_3 نسخه_2;
      کلمه_3 Machine;
      DWORD زمان_Date_Stamp;
      CLSID ClassID;
      DWORD اندازه_از_داده;
    } ANON_OBJECT_سرآیند;

#تعریف_کن IMAGE_SIZEOF_SHORT_NAME 8

    تعريفنوع بنية IMAGE_SECTION_سرآیند {
      BYTE Name[IMAGE_SIZEOF_SHORT_NAME];
      اتحاد {
	DWORD Physical_آدرس;
	DWORD Virtual_اندازه;
      } Misc;
      DWORD Virtual_آدرس;
      DWORD اندازه_از_Raw_داده;
      DWORD اشاره_گر_مقصد_Raw_داده;
      DWORD اشاره_گر_مقصد_Relocations;
      DWORD اشاره_گر_مقصد_Linenumbers;
      کلمه_3 عدد_از_Relocations;
      کلمه_3 عدد_از_Linenumbers;
      DWORD Characteristics;
    } IMAGE_SECTION_سرآیند_2,*PIMAGE_SECTION_سرآیند;

#تعریف_کن IMAGE_SIZEOF_SECTION_سرآیند 40

#تعریف_کن IMAGE_SCN_TYPE_NO_PAD 0x00000008

#تعریف_کن IMAGE_SCN_CNT_کد 0x00000020
#تعریف_کن IMAGE_SCN_CNT_INITIALIZED_داده 0x00000040
#تعریف_کن IMAGE_SCN_CNT_UNINITIALIZED_داده 0x00000080
#تعریف_کن IMAGE_SCN_LNK_OTHER 0x00000100
#تعریف_کن IMAGE_SCN_LNK_INFO 0x00000200
#تعریف_کن IMAGE_SCN_LNK_REMOVE 0x00000800
#تعریف_کن IMAGE_SCN_LNK_COMDAT 0x00001000
#تعریف_کن IMAGE_SCN_NO_DEFER_SPEC_EXC 0x00004000
#تعریف_کن IMAGE_SCN_GPREL 0x00008000
#تعریف_کن IMAGE_SCN_MEM_FARDATA 0x00008000
#تعریف_کن IMAGE_SCN_MEM_PURGEABLE 0x00020000
#تعریف_کن IMAGE_SCN_MEM_16_بیت 0x00020000
#تعریف_کن IMAGE_SCN_MEM_LOCKED 0x00040000
#تعریف_کن IMAGE_SCN_MEM_PRELOAD 0x00080000

#تعریف_کن IMAGE_SCN_ALIGN_1_بایتها 0x00100000
#تعریف_کن IMAGE_SCN_ALIGN_2_بایتها 0x00200000
#تعریف_کن IMAGE_SCN_ALIGN_4_بایتها 0x00300000
#تعریف_کن IMAGE_SCN_ALIGN_8_بایتها 0x00400000
#تعریف_کن IMAGE_SCN_ALIGN_16_بایتها 0x00500000
#تعریف_کن IMAGE_SCN_ALIGN_32_بایتها 0x00600000
#تعریف_کن IMAGE_SCN_ALIGN_64_بایتها 0x00700000
#تعریف_کن IMAGE_SCN_ALIGN_128_بایتها 0x00800000
#تعریف_کن IMAGE_SCN_ALIGN_256_بایتها 0x00900000
#تعریف_کن IMAGE_SCN_ALIGN_512_بایتها 0x00A00000
#تعریف_کن IMAGE_SCN_ALIGN_1024_بایتها 0x00B00000
#تعریف_کن IMAGE_SCN_ALIGN_2048_بایتها 0x00C00000
#تعریف_کن IMAGE_SCN_ALIGN_4096_بایتها 0x00D00000
#تعریف_کن IMAGE_SCN_ALIGN_8192_بایتها 0x00E00000

#تعریف_کن IMAGE_SCN_ALIGN_ماسک 0x00F00000

#تعریف_کن IMAGE_SCN_LNK_NRELOC_OVFL 0x01000000
#تعریف_کن IMAGE_SCN_MEM_DISCARDABLE 0x02000000
#تعریف_کن IMAGE_SCN_MEM_NOT_CACHED 0x04000000
#تعریف_کن IMAGE_SCN_MEM_NOT_PAGED 0x08000000
#تعریف_کن IMAGE_SCN_MEM_SHARED 0x10000000
#تعریف_کن IMAGE_SCN_MEM_EXECUTE 0x20000000
#تعریف_کن IMAGE_SCN_MEM_READ 0x40000000
#تعریف_کن IMAGE_SCN_MEM_WRITE 0x80000000

#تعریف_کن IMAGE_SCN_SCALE_شاخص 0x00000001

#ضمن "pshpack2.h"

    تعريفنوع بنية IMAGE_نماد {
      اتحاد {
	BYTE ShortName[8];
	بنية {
	  DWORD Short;
	  DWORD Long;
	} Name;
	DWORD LongName[2];
      } N;
      DWORD مقدار_3;
      SHORT Section_عدد;
      کلمه_3 Type;
      BYTE StorageClass;
      BYTE عدد_از_Aux_Symbols;
    } IMAGE_نماد_2;
    تعريفنوع IMAGE_نماد_2 UNALIGNED *PIMAGE_نماد;

#تعریف_کن IMAGE_SIZEOF_نماد 18

#تعریف_کن IMAGE_SYM_UNDEFINED (SHORT)0
#تعریف_کن IMAGE_SYM_ABSOLUTE (SHORT)-1
#تعریف_کن IMAGE_SYM_DEBUG (SHORT)-2
#تعریف_کن IMAGE_SYM_SECTION_MAX 0xFEFF

#تعریف_کن IMAGE_SYM_TYPE_NULL 0x0000
#تعریف_کن IMAGE_SYM_TYPE_VOID 0x0001
#تعریف_کن IMAGE_SYM_TYPE_CHAR 0x0002
#تعریف_کن IMAGE_SYM_TYPE_SHORT 0x0003
#تعریف_کن IMAGE_SYM_TYPE_INT 0x0004
#تعریف_کن IMAGE_SYM_TYPE_LONG 0x0005
#تعریف_کن IMAGE_SYM_TYPE_FLOAT 0x0006
#تعریف_کن IMAGE_SYM_TYPE_DOUBLE 0x0007
#تعریف_کن IMAGE_SYM_TYPE_STRUCT 0x0008
#تعریف_کن IMAGE_SYM_TYPE_UNION 0x0009
#تعریف_کن IMAGE_SYM_TYPE_ENUM 0x000A
#تعریف_کن IMAGE_SYM_TYPE_MOE 0x000B
#تعریف_کن IMAGE_SYM_TYPE_BYTE 0x000C
#تعریف_کن IMAGE_SYM_TYPE_کلمه 0x000D
#تعریف_کن IMAGE_SYM_TYPE_UINT 0x000E
#تعریف_کن IMAGE_SYM_TYPE_DWORD 0x000F
#تعریف_کن IMAGE_SYM_TYPE_PCODE 0x8000

#تعریف_کن IMAGE_SYM_DTYPE_NULL 0
#تعریف_کن IMAGE_SYM_DTYPE_اشاره_گر 1
#تعریف_کن IMAGE_SYM_DTYPE_FUNCTION 2
#تعریف_کن IMAGE_SYM_DTYPE_ARRAY 3

#تعریف_کن IMAGE_SYM_CLASS_انتها_از_FUNCTION (BYTE)-1
#تعریف_کن IMAGE_SYM_CLASS_NULL 0x0000
#تعریف_کن IMAGE_SYM_CLASS_AUTOMATIC 0x0001
#تعریف_کن IMAGE_SYM_CLASS_EXTERNAL 0x0002
#تعریف_کن IMAGE_SYM_CLASS_STATIC 0x0003
#تعریف_کن IMAGE_SYM_CLASS_ثبات 0x0004
#تعریف_کن IMAGE_SYM_CLASS_EXTERNAL_DEF 0x0005
#تعریف_کن IMAGE_SYM_CLASS_LABEL 0x0006
#تعریف_کن IMAGE_SYM_CLASS_UNDEFINED_LABEL 0x0007
#تعریف_کن IMAGE_SYM_CLASS_MEMBER_از_STRUCT 0x0008
#تعریف_کن IMAGE_SYM_CLASS_آرگومان 0x0009
#تعریف_کن IMAGE_SYM_CLASS_STRUCT_برچسب 0x000A
#تعریف_کن IMAGE_SYM_CLASS_MEMBER_از_UNION 0x000B
#تعریف_کن IMAGE_SYM_CLASS_UNION_برچسب 0x000C
#تعریف_کن IMAGE_SYM_CLASS_TYPE_DEFINITION 0x000D
#تعریف_کن IMAGE_SYM_CLASS_UNDEFINED_STATIC 0x000E
#تعریف_کن IMAGE_SYM_CLASS_ENUM_برچسب 0x000F
#تعریف_کن IMAGE_SYM_CLASS_MEMBER_از_ENUM 0x0010
#تعریف_کن IMAGE_SYM_CLASS_ثبات_PARAM 0x0011
#تعریف_کن IMAGE_SYM_CLASS_بیت_فیلد 0x0012
#تعریف_کن IMAGE_SYM_CLASS_FAR_EXTERNAL 0x0044
#تعریف_کن IMAGE_SYM_CLASS_بلوک 0x0064
#تعریف_کن IMAGE_SYM_CLASS_FUNCTION 0x0065
#تعریف_کن IMAGE_SYM_CLASS_انتها_از_STRUCT 0x0066
#تعریف_کن IMAGE_SYM_CLASS_FILE 0x0067
#تعریف_کن IMAGE_SYM_CLASS_SECTION 0x0068
#تعریف_کن IMAGE_SYM_CLASS_WEAK_EXTERNAL 0x0069
#تعریف_کن IMAGE_SYM_CLASS_CLR_TOKEN 0x006B

#تعریف_کن N_BTMASK 0x000F
#تعریف_کن N_TMASK 0x0030
#تعریف_کن N_TMASK1 0x00C0
#تعریف_کن N_TMASK2 0x00F0
#تعریف_کن N_BTSHFT 4
#تعریف_کن N_TSHIFT 2

#تعریف_کن BTYPE(x) ((x) & N_BTMASK)

#اگر_تعریف_نشده ISPTR
#تعریف_کن ISPTR(x) (((x) & N_TMASK)==(IMAGE_SYM_DTYPE_اشاره_گر << N_BTSHFT))
#پایان_اگر

#اگر_تعریف_نشده ISFCN
#تعریف_کن ISFCN(x) (((x) & N_TMASK)==(IMAGE_SYM_DTYPE_FUNCTION << N_BTSHFT))
#پایان_اگر

#اگر_تعریف_نشده ISARY
#تعریف_کن ISARY(x) (((x) & N_TMASK)==(IMAGE_SYM_DTYPE_ARRAY << N_BTSHFT))
#پایان_اگر

#اگر_تعریف_نشده ISTAG
#تعریف_کن ISTAG(x) ((x)==IMAGE_SYM_CLASS_STRUCT_برچسب || (x)==IMAGE_SYM_CLASS_UNION_برچسب || (x)==IMAGE_SYM_CLASS_ENUM_برچسب)
#پایان_اگر

#اگر_تعریف_نشده INCREF
#تعریف_کن INCREF(x) ((((x)&~N_BTMASK)<<N_TSHIFT)|(IMAGE_SYM_DTYPE_اشاره_گر<<N_BTSHFT)|((x)&N_BTMASK))
#پایان_اگر
#اگر_تعریف_نشده DECREF
#تعریف_کن DECREF(x) ((((x)>>N_TSHIFT)&~N_BTMASK)|((x)&N_BTMASK))
#پایان_اگر

    تعريفنوع اتحاد IMAGE_AUX_نماد {
      بنية {
	DWORD برچسب_شاخص;
	اتحاد {
	  بنية {
	    کلمه_3 Linenumber;
	    کلمه_3 اندازه_3;
	  } LnSz;
	  DWORD مجموع_اندازه;
	} Misc;
	اتحاد {
	  بنية {
	    DWORD اشاره_گر_مقصد_Linenumber;
	    DWORD اشاره_گر_مقصد_بعدی_Function;
	  } Function;
	  بنية {
	    کلمه_3 Dimension[4];
	  } Array;
	} FcnAry;
	کلمه_3 Tv_شاخص;
      } Sym;
      بنية {
	BYTE Name[IMAGE_SIZEOF_نماد];
      } File;
      بنية {
	DWORD درازی_2;
	کلمه_3 عدد_از_Relocations;
	کلمه_3 عدد_از_Linenumbers;
	DWORD Check_جمع;
	SHORT عدد_2;
	BYTE Selection;
      } Section;
    } IMAGE_AUX_نماد_2;
    تعريفنوع IMAGE_AUX_نماد_2 UNALIGNED *PIMAGE_AUX_نماد;

#تعریف_کن IMAGE_SIZEOF_AUX_نماد 18

    تعريفنوع تعداد IMAGE_AUX_نماد_TYPE {
      IMAGE_AUX_نماد_TYPE_TOKEN_DEF = 1
    } IMAGE_AUX_نماد_TYPE;

#ضمن <pshpack2.h>

    تعريفنوع بنية IMAGE_AUX_نماد_TOKEN_DEF {
      BYTE bAuxType;
      BYTE bReserved;
      DWORD نماد_جدول_شاخص;
      BYTE rgbReserved[12];
    } IMAGE_AUX_نماد_TOKEN_DEF;

    تعريفنوع IMAGE_AUX_نماد_TOKEN_DEF UNALIGNED *PIMAGE_AUX_نماد_TOKEN_DEF;

#ضمن <poppack.h>

#تعریف_کن IMAGE_COMDAT_SELECT_NODUPLICATES 1
#تعریف_کن IMAGE_COMDAT_SELECT_ANY 2
#تعریف_کن IMAGE_COMDAT_SELECT_SAME_اندازه 3
#تعریف_کن IMAGE_COMDAT_SELECT_EXACT_تطابق 4
#تعریف_کن IMAGE_COMDAT_SELECT_ASSOCIATIVE 5
#تعریف_کن IMAGE_COMDAT_SELECT_بزرگترین 6
#تعریف_کن IMAGE_COMDAT_SELECT_NEWEST 7

#تعریف_کن IMAGE_WEAK_EXTERN_جستجو_NOLIBRARY 1
#تعریف_کن IMAGE_WEAK_EXTERN_جستجو_LIBRARY 2
#تعریف_کن IMAGE_WEAK_EXTERN_جستجو_ALIAS 3

    تعريفنوع بنية _IMAGE_RELOCATION {
      اتحاد {
	DWORD Virtual_آدرس;
	DWORD Reloc_شمار;
      };
      DWORD نماد_جدول_شاخص;
      کلمه_3 Type;
    } IMAGE_RELOCATION;
    تعريفنوع IMAGE_RELOCATION UNALIGNED *PIMAGE_RELOCATION;

#تعریف_کن IMAGE_SIZEOF_RELOCATION 10

#تعریف_کن IMAGE_REL_I386_ABSOLUTE 0x0000
#تعریف_کن IMAGE_REL_I386_DIR16 0x0001
#تعریف_کن IMAGE_REL_I386_REL16 0x0002
#تعریف_کن IMAGE_REL_I386_DIR32 0x0006
#تعریف_کن IMAGE_REL_I386_DIR32NB 0x0007
#تعریف_کن IMAGE_REL_I386_SEG12 0x0009
#تعریف_کن IMAGE_REL_I386_SECTION 0x000A
#تعریف_کن IMAGE_REL_I386_SECREL 0x000B
#تعریف_کن IMAGE_REL_I386_TOKEN 0x000C
#تعریف_کن IMAGE_REL_I386_SECREL7 0x000D
#تعریف_کن IMAGE_REL_I386_REL32 0x0014

#تعریف_کن IMAGE_REL_MIPS_ABSOLUTE 0x0000
#تعریف_کن IMAGE_REL_MIPS_REFHALF 0x0001
#تعریف_کن IMAGE_REL_MIPS_REFWORD 0x0002
#تعریف_کن IMAGE_REL_MIPS_JMPADDR 0x0003
#تعریف_کن IMAGE_REL_MIPS_REFHI 0x0004
#تعریف_کن IMAGE_REL_MIPS_REFLO 0x0005
#تعریف_کن IMAGE_REL_MIPS_GPREL 0x0006
#تعریف_کن IMAGE_REL_MIPS_LITERAL 0x0007
#تعریف_کن IMAGE_REL_MIPS_SECTION 0x000A
#تعریف_کن IMAGE_REL_MIPS_SECREL 0x000B
#تعریف_کن IMAGE_REL_MIPS_SECRELLO 0x000C
#تعریف_کن IMAGE_REL_MIPS_SECRELHI 0x000D
#تعریف_کن IMAGE_REL_MIPS_TOKEN 0x000E
#تعریف_کن IMAGE_REL_MIPS_JMPADDR16 0x0010
#تعریف_کن IMAGE_REL_MIPS_REFWORDNB 0x0022
#تعریف_کن IMAGE_REL_MIPS_PAIR 0x0025

#تعریف_کن IMAGE_REL_ALPHA_ABSOLUTE 0x0000
#تعریف_کن IMAGE_REL_ALPHA_REFLONG 0x0001
#تعریف_کن IMAGE_REL_ALPHA_REFQUAD 0x0002
#تعریف_کن IMAGE_REL_ALPHA_GPREL32 0x0003
#تعریف_کن IMAGE_REL_ALPHA_LITERAL 0x0004
#تعریف_کن IMAGE_REL_ALPHA_LITUSE 0x0005
#تعریف_کن IMAGE_REL_ALPHA_GPDISP 0x0006
#تعریف_کن IMAGE_REL_ALPHA_BRADDR 0x0007
#تعریف_کن IMAGE_REL_ALPHA_HINT 0x0008
#تعریف_کن IMAGE_REL_ALPHA_INLINE_REFLONG 0x0009
#تعریف_کن IMAGE_REL_ALPHA_REFHI 0x000A
#تعریف_کن IMAGE_REL_ALPHA_REFLO 0x000B
#تعریف_کن IMAGE_REL_ALPHA_PAIR 0x000C
#تعریف_کن IMAGE_REL_ALPHA_تطابق 0x000D
#تعریف_کن IMAGE_REL_ALPHA_SECTION 0x000E
#تعریف_کن IMAGE_REL_ALPHA_SECREL 0x000F
#تعریف_کن IMAGE_REL_ALPHA_REFLONGNB 0x0010
#تعریف_کن IMAGE_REL_ALPHA_SECRELLO 0x0011
#تعریف_کن IMAGE_REL_ALPHA_SECRELHI 0x0012
#تعریف_کن IMAGE_REL_ALPHA_REFQ3 0x0013
#تعریف_کن IMAGE_REL_ALPHA_REFQ2 0x0014
#تعریف_کن IMAGE_REL_ALPHA_REFQ1 0x0015
#تعریف_کن IMAGE_REL_ALPHA_GPRELLO 0x0016
#تعریف_کن IMAGE_REL_ALPHA_GPRELHI 0x0017

#تعریف_کن IMAGE_REL_PPC_ABSOLUTE 0x0000
#تعریف_کن IMAGE_REL_PPC_ADDR64 0x0001
#تعریف_کن IMAGE_REL_PPC_ADDR32 0x0002
#تعریف_کن IMAGE_REL_PPC_ADDR24 0x0003
#تعریف_کن IMAGE_REL_PPC_ADDR16 0x0004
#تعریف_کن IMAGE_REL_PPC_ADDR14 0x0005
#تعریف_کن IMAGE_REL_PPC_REL24 0x0006
#تعریف_کن IMAGE_REL_PPC_REL14 0x0007
#تعریف_کن IMAGE_REL_PPC_TOCREL16 0x0008
#تعریف_کن IMAGE_REL_PPC_TOCREL14 0x0009
#تعریف_کن IMAGE_REL_PPC_ADDR32NB 0x000A
#تعریف_کن IMAGE_REL_PPC_SECREL 0x000B
#تعریف_کن IMAGE_REL_PPC_SECTION 0x000C
#تعریف_کن IMAGE_REL_PPC_IFGLUE 0x000D
#تعریف_کن IMAGE_REL_PPC_IMGLUE 0x000E
#تعریف_کن IMAGE_REL_PPC_SECREL16 0x000F
#تعریف_کن IMAGE_REL_PPC_REFHI 0x0010
#تعریف_کن IMAGE_REL_PPC_REFLO 0x0011
#تعریف_کن IMAGE_REL_PPC_PAIR 0x0012
#تعریف_کن IMAGE_REL_PPC_SECRELLO 0x0013
#تعریف_کن IMAGE_REL_PPC_SECRELHI 0x0014
#تعریف_کن IMAGE_REL_PPC_GPREL 0x0015
#تعریف_کن IMAGE_REL_PPC_TOKEN 0x0016
#تعریف_کن IMAGE_REL_PPC_TYPEMASK 0x00FF
#تعریف_کن IMAGE_REL_PPC_NEG 0x0100
#تعریف_کن IMAGE_REL_PPC_BRTAKEN 0x0200
#تعریف_کن IMAGE_REL_PPC_BRNTAKEN 0x0400
#تعریف_کن IMAGE_REL_PPC_TOCDEFN 0x0800

#تعریف_کن IMAGE_REL_SH3_ABSOLUTE 0x0000
#تعریف_کن IMAGE_REL_SH3_DIRECT16 0x0001
#تعریف_کن IMAGE_REL_SH3_DIRECT32 0x0002
#تعریف_کن IMAGE_REL_SH3_DIRECT8 0x0003
#تعریف_کن IMAGE_REL_SH3_DIRECT8_کلمه 0x0004
#تعریف_کن IMAGE_REL_SH3_DIRECT8_LONG 0x0005
#تعریف_کن IMAGE_REL_SH3_DIRECT4 0x0006
#تعریف_کن IMAGE_REL_SH3_DIRECT4_کلمه 0x0007
#تعریف_کن IMAGE_REL_SH3_DIRECT4_LONG 0x0008
#تعریف_کن IMAGE_REL_SH3_PCREL8_کلمه 0x0009
#تعریف_کن IMAGE_REL_SH3_PCREL8_LONG 0x000A
#تعریف_کن IMAGE_REL_SH3_PCREL12_کلمه 0x000B
#تعریف_کن IMAGE_REL_SH3_STARTOF_SECTION 0x000C
#تعریف_کن IMAGE_REL_SH3_SIZEOF_SECTION 0x000D
#تعریف_کن IMAGE_REL_SH3_SECTION 0x000E
#تعریف_کن IMAGE_REL_SH3_SECREL 0x000F
#تعریف_کن IMAGE_REL_SH3_DIRECT32_NB 0x0010
#تعریف_کن IMAGE_REL_SH3_GPREL4_LONG 0x0011
#تعریف_کن IMAGE_REL_SH3_TOKEN 0x0012

#تعریف_کن IMAGE_REL_SHM_PCRELPT 0x0013
#تعریف_کن IMAGE_REL_SHM_REFLO 0x0014
#تعریف_کن IMAGE_REL_SHM_REFHALF 0x0015
#تعریف_کن IMAGE_REL_SHM_RELLO 0x0016
#تعریف_کن IMAGE_REL_SHM_RELHALF 0x0017
#تعریف_کن IMAGE_REL_SHM_PAIR 0x0018

#تعریف_کن IMAGE_REL_SH_NOMODE 0x8000

#تعریف_کن IMAGE_REL_ARM_ABSOLUTE 0x0000
#تعریف_کن IMAGE_REL_ARM_ADDR32 0x0001
#تعریف_کن IMAGE_REL_ARM_ADDR32NB 0x0002
#تعریف_کن IMAGE_REL_ARM_BRANCH24 0x0003
#تعریف_کن IMAGE_REL_ARM_BRANCH11 0x0004
#تعریف_کن IMAGE_REL_ARM_TOKEN 0x0005
#تعریف_کن IMAGE_REL_ARM_GPREL12 0x0006
#تعریف_کن IMAGE_REL_ARM_GPREL7 0x0007
#تعریف_کن IMAGE_REL_ARM_BLX24 0x0008
#تعریف_کن IMAGE_REL_ARM_BLX11 0x0009
#تعریف_کن IMAGE_REL_ARM_SECTION 0x000E
#تعریف_کن IMAGE_REL_ARM_SECREL 0x000F

#تعریف_کن IMAGE_REL_AM_ABSOLUTE 0x0000
#تعریف_کن IMAGE_REL_AM_ADDR32 0x0001
#تعریف_کن IMAGE_REL_AM_ADDR32NB 0x0002
#تعریف_کن IMAGE_REL_AM_CALL32 0x0003
#تعریف_کن IMAGE_REL_AM_FUNCINFO 0x0004
#تعریف_کن IMAGE_REL_AM_REL32_1 0x0005
#تعریف_کن IMAGE_REL_AM_REL32_2 0x0006
#تعریف_کن IMAGE_REL_AM_SECREL 0x0007
#تعریف_کن IMAGE_REL_AM_SECTION 0x0008
#تعریف_کن IMAGE_REL_AM_TOKEN 0x0009

#تعریف_کن IMAGE_REL_AMD64_ABSOLUTE 0x0000
#تعریف_کن IMAGE_REL_AMD64_ADDR64 0x0001
#تعریف_کن IMAGE_REL_AMD64_ADDR32 0x0002
#تعریف_کن IMAGE_REL_AMD64_ADDR32NB 0x0003
#تعریف_کن IMAGE_REL_AMD64_REL32 0x0004
#تعریف_کن IMAGE_REL_AMD64_REL32_1 0x0005
#تعریف_کن IMAGE_REL_AMD64_REL32_2 0x0006
#تعریف_کن IMAGE_REL_AMD64_REL32_3 0x0007
#تعریف_کن IMAGE_REL_AMD64_REL32_4 0x0008
#تعریف_کن IMAGE_REL_AMD64_REL32_5 0x0009
#تعریف_کن IMAGE_REL_AMD64_SECTION 0x000A
#تعریف_کن IMAGE_REL_AMD64_SECREL 0x000B
#تعریف_کن IMAGE_REL_AMD64_SECREL7 0x000C
#تعریف_کن IMAGE_REL_AMD64_TOKEN 0x000D
#تعریف_کن IMAGE_REL_AMD64_SREL32 0x000E
#تعریف_کن IMAGE_REL_AMD64_PAIR 0x000F
#تعریف_کن IMAGE_REL_AMD64_SSPAN32 0x0010

#تعریف_کن IMAGE_REL_IA64_ABSOLUTE 0x0000
#تعریف_کن IMAGE_REL_IA64_IMM14 0x0001
#تعریف_کن IMAGE_REL_IA64_IMM22 0x0002
#تعریف_کن IMAGE_REL_IA64_IMM64 0x0003
#تعریف_کن IMAGE_REL_IA64_DIR32 0x0004
#تعریف_کن IMAGE_REL_IA64_DIR64 0x0005
#تعریف_کن IMAGE_REL_IA64_PCREL21B 0x0006
#تعریف_کن IMAGE_REL_IA64_PCREL21M 0x0007
#تعریف_کن IMAGE_REL_IA64_PCREL21F 0x0008
#تعریف_کن IMAGE_REL_IA64_GPREL22 0x0009
#تعریف_کن IMAGE_REL_IA64_LTOFF22 0x000A
#تعریف_کن IMAGE_REL_IA64_SECTION 0x000B
#تعریف_کن IMAGE_REL_IA64_SECREL22 0x000C
#تعریف_کن IMAGE_REL_IA64_SECREL64I 0x000D
#تعریف_کن IMAGE_REL_IA64_SECREL32 0x000E

#تعریف_کن IMAGE_REL_IA64_DIR32NB 0x0010
#تعریف_کن IMAGE_REL_IA64_SREL14 0x0011
#تعریف_کن IMAGE_REL_IA64_SREL22 0x0012
#تعریف_کن IMAGE_REL_IA64_SREL32 0x0013
#تعریف_کن IMAGE_REL_IA64_UREL32 0x0014
#تعریف_کن IMAGE_REL_IA64_PCREL60X 0x0015
#تعریف_کن IMAGE_REL_IA64_PCREL60B 0x0016
#تعریف_کن IMAGE_REL_IA64_PCREL60F 0x0017
#تعریف_کن IMAGE_REL_IA64_PCREL60I 0x0018
#تعریف_کن IMAGE_REL_IA64_PCREL60M 0x0019
#تعریف_کن IMAGE_REL_IA64_IMMGPREL64 0x001A
#تعریف_کن IMAGE_REL_IA64_TOKEN 0x001B
#تعریف_کن IMAGE_REL_IA64_GPREL32 0x001C
#تعریف_کن IMAGE_REL_IA64_ADDEND 0x001F

#تعریف_کن IMAGE_REL_CEF_ABSOLUTE 0x0000
#تعریف_کن IMAGE_REL_CEF_ADDR32 0x0001
#تعریف_کن IMAGE_REL_CEF_ADDR64 0x0002
#تعریف_کن IMAGE_REL_CEF_ADDR32NB 0x0003
#تعریف_کن IMAGE_REL_CEF_SECTION 0x0004
#تعریف_کن IMAGE_REL_CEF_SECREL 0x0005
#تعریف_کن IMAGE_REL_CEF_TOKEN 0x0006

#تعریف_کن IMAGE_REL_CEE_ABSOLUTE 0x0000
#تعریف_کن IMAGE_REL_CEE_ADDR32 0x0001
#تعریف_کن IMAGE_REL_CEE_ADDR64 0x0002
#تعریف_کن IMAGE_REL_CEE_ADDR32NB 0x0003
#تعریف_کن IMAGE_REL_CEE_SECTION 0x0004
#تعریف_کن IMAGE_REL_CEE_SECREL 0x0005
#تعریف_کن IMAGE_REL_CEE_TOKEN 0x0006

#تعریف_کن IMAGE_REL_M32R_ABSOLUTE 0x0000
#تعریف_کن IMAGE_REL_M32R_ADDR32 0x0001
#تعریف_کن IMAGE_REL_M32R_ADDR32NB 0x0002
#تعریف_کن IMAGE_REL_M32R_ADDR24 0x0003
#تعریف_کن IMAGE_REL_M32R_GPREL16 0x0004
#تعریف_کن IMAGE_REL_M32R_PCREL24 0x0005
#تعریف_کن IMAGE_REL_M32R_PCREL16 0x0006
#تعریف_کن IMAGE_REL_M32R_PCREL8 0x0007
#تعریف_کن IMAGE_REL_M32R_REFHALF 0x0008
#تعریف_کن IMAGE_REL_M32R_REFHI 0x0009
#تعریف_کن IMAGE_REL_M32R_REFLO 0x000A
#تعریف_کن IMAGE_REL_M32R_PAIR 0x000B
#تعریف_کن IMAGE_REL_M32R_SECTION 0x000C
#تعریف_کن IMAGE_REL_M32R_SECREL32 0x000D
#تعریف_کن IMAGE_REL_M32R_TOKEN 0x000E

#تعریف_کن EXT_IMM64(مقدار_3,آدرس_2,اندازه_3,InstPos,ValPos) مقدار_3 |= (((ULONGLONG)((*(آدرس_2) >> InstPos) & (((ULONGLONG)1 << اندازه_3) - 1))) << ValPos)
#تعریف_کن INS_IMM64(مقدار_3,آدرس_2,اندازه_3,InstPos,ValPos) *(PDWORD)آدرس_2 = (*(PDWORD)آدرس_2 & ~(((1 << اندازه_3) - 1) << InstPos)) | ((DWORD)((((ULONGLONG)مقدار_3 >> ValPos) & (((ULONGLONG)1 << اندازه_3) - 1))) << InstPos)

#تعریف_کن EMARCH_ENC_I17_IMM7_B_INST_کلمه_X 3
#تعریف_کن EMARCH_ENC_I17_IMM7_B_اندازه_X 7
#تعریف_کن EMARCH_ENC_I17_IMM7_B_INST_کلمه_POS_X 4
#تعریف_کن EMARCH_ENC_I17_IMM7B_VAL_POS_X 0

#تعریف_کن EMARCH_ENC_I17_IMM9_D_INST_کلمه_X 3
#تعریف_کن EMARCH_ENC_I17_IMM9_D_اندازه_X 9
#تعریف_کن EMARCH_ENC_I17_IMM9_D_INST_کلمه_POS_X 18
#تعریف_کن EMARCH_ENC_I17_IMM9D_VAL_POS_X 7

#تعریف_کن EMARCH_ENC_I17_IMM5_C_INST_کلمه_X 3
#تعریف_کن EMARCH_ENC_I17_IMM5_C_اندازه_X 5
#تعریف_کن EMARCH_ENC_I17_IMM5_C_INST_کلمه_POS_X 13
#تعریف_کن EMARCH_ENC_I17_IMM5C_VAL_POS_X 16

#تعریف_کن EMARCH_ENC_I17_IC_INST_کلمه_X 3
#تعریف_کن EMARCH_ENC_I17_IC_اندازه_X 1
#تعریف_کن EMARCH_ENC_I17_IC_INST_کلمه_POS_X 12
#تعریف_کن EMARCH_ENC_I17_IC_VAL_POS_X 21

#تعریف_کن EMARCH_ENC_I17_IMM41a_INST_کلمه_X 1
#تعریف_کن EMARCH_ENC_I17_IMM41a_اندازه_X 10
#تعریف_کن EMARCH_ENC_I17_IMM41a_INST_کلمه_POS_X 14
#تعریف_کن EMARCH_ENC_I17_IMM41a_VAL_POS_X 22

#تعریف_کن EMARCH_ENC_I17_IMM41b_INST_کلمه_X 1
#تعریف_کن EMARCH_ENC_I17_IMM41b_اندازه_X 8
#تعریف_کن EMARCH_ENC_I17_IMM41b_INST_کلمه_POS_X 24
#تعریف_کن EMARCH_ENC_I17_IMM41b_VAL_POS_X 32

#تعریف_کن EMARCH_ENC_I17_IMM41c_INST_کلمه_X 2
#تعریف_کن EMARCH_ENC_I17_IMM41c_اندازه_X 23
#تعریف_کن EMARCH_ENC_I17_IMM41c_INST_کلمه_POS_X 0
#تعریف_کن EMARCH_ENC_I17_IMM41c_VAL_POS_X 40

#تعریف_کن EMARCH_ENC_I17_SIGN_INST_کلمه_X 3
#تعریف_کن EMARCH_ENC_I17_SIGN_اندازه_X 1
#تعریف_کن EMARCH_ENC_I17_SIGN_INST_کلمه_POS_X 27
#تعریف_کن EMARCH_ENC_I17_SIGN_VAL_POS_X 63

#تعریف_کن X3_OPCODE_INST_کلمه_X 3
#تعریف_کن X3_OPCODE_اندازه_X 4
#تعریف_کن X3_OPCODE_INST_کلمه_POS_X 28
#تعریف_کن X3_OPCODE_SIGN_VAL_POS_X 0

#تعریف_کن X3_I_INST_کلمه_X 3
#تعریف_کن X3_I_اندازه_X 1
#تعریف_کن X3_I_INST_کلمه_POS_X 27
#تعریف_کن X3_I_SIGN_VAL_POS_X 59

#تعریف_کن X3_D_WH_INST_کلمه_X 3
#تعریف_کن X3_D_WH_اندازه_X 3
#تعریف_کن X3_D_WH_INST_کلمه_POS_X 24
#تعریف_کن X3_D_WH_SIGN_VAL_POS_X 0

#تعریف_کن X3_IMM20_INST_کلمه_X 3
#تعریف_کن X3_IMM20_اندازه_X 20
#تعریف_کن X3_IMM20_INST_کلمه_POS_X 4
#تعریف_کن X3_IMM20_SIGN_VAL_POS_X 0

#تعریف_کن X3_IMM39_1_INST_کلمه_X 2
#تعریف_کن X3_IMM39_1_اندازه_X 23
#تعریف_کن X3_IMM39_1_INST_کلمه_POS_X 0
#تعریف_کن X3_IMM39_1_SIGN_VAL_POS_X 36

#تعریف_کن X3_IMM39_2_INST_کلمه_X 1
#تعریف_کن X3_IMM39_2_اندازه_X 16
#تعریف_کن X3_IMM39_2_INST_کلمه_POS_X 16
#تعریف_کن X3_IMM39_2_SIGN_VAL_POS_X 20

#تعریف_کن X3_P_INST_کلمه_X 3
#تعریف_کن X3_P_اندازه_X 4
#تعریف_کن X3_P_INST_کلمه_POS_X 0
#تعریف_کن X3_P_SIGN_VAL_POS_X 0

#تعریف_کن X3_TMPLT_INST_کلمه_X 0
#تعریف_کن X3_TMPLT_اندازه_X 4
#تعریف_کن X3_TMPLT_INST_کلمه_POS_X 0
#تعریف_کن X3_TMPLT_SIGN_VAL_POS_X 0

#تعریف_کن X3_BTYPE_QP_INST_کلمه_X 2
#تعریف_کن X3_BTYPE_QP_اندازه_X 9
#تعریف_کن X3_BTYPE_QP_INST_کلمه_POS_X 23
#تعریف_کن X3_BTYPE_QP_INST_VAL_POS_X 0

#تعریف_کن X3_خالی_INST_کلمه_X 1
#تعریف_کن X3_خالی_اندازه_X 2
#تعریف_کن X3_خالی_INST_کلمه_POS_X 14
#تعریف_کن X3_خالی_INST_VAL_POS_X 0

    تعريفنوع بنية _IMAGE_LINENUMBER {
      اتحاد {
	DWORD نماد_جدول_شاخص;
	DWORD Virtual_آدرس;
      } Type;
      کلمه_3 Linenumber;
    } IMAGE_LINENUMBER;
    تعريفنوع IMAGE_LINENUMBER UNALIGNED *PIMAGE_LINENUMBER;

#تعریف_کن IMAGE_SIZEOF_LINENUMBER 6

#ضمن "poppack.h"

    تعريفنوع بنية IMAGE_پایه_RELOCATION {
      DWORD Virtual_آدرس;
      DWORD اندازه_از_بلوک;

    } IMAGE_پایه_RELOCATION_2;
    تعريفنوع IMAGE_پایه_RELOCATION_2 UNALIGNED *PIMAGE_پایه_RELOCATION;

#تعریف_کن IMAGE_SIZEOF_پایه_RELOCATION 8

#تعریف_کن IMAGE_REL_BASED_ABSOLUTE 0
#تعریف_کن IMAGE_REL_BASED_بالا 1
#تعریف_کن IMAGE_REL_BASED_کم 2
#تعریف_کن IMAGE_REL_BASED_HIGHLOW 3
#تعریف_کن IMAGE_REL_BASED_HIGHADJ 4
#تعریف_کن IMAGE_REL_BASED_MIPS_JMPADDR 5
#تعریف_کن IMAGE_REL_BASED_MIPS_JMPADDR16 9
#تعریف_کن IMAGE_REL_BASED_IA64_IMM64 9
#تعریف_کن IMAGE_REL_BASED_DIR64 10

#تعریف_کن IMAGE_ARCHIVE_شروع_اندازه 8
#تعریف_کن IMAGE_ARCHIVE_شروع "!<arch>\n"
#تعریف_کن IMAGE_ARCHIVE_انتها "`\n"
#تعریف_کن IMAGE_ARCHIVE_PAD "\n"
#تعریف_کن IMAGE_ARCHIVE_LINKER_MEMBER "/               "
#تعریف_کن IMAGE_ARCHIVE_LONGNAMES_MEMBER "//              "

    تعريفنوع بنية IMAGE_ARCHIVE_MEMBER_سرآیند {
      BYTE Name[16];
      BYTE Date[12];
      BYTE UserID[6];
      BYTE گروه_ID[6];
      BYTE نما_4[8];
      BYTE اندازه_3[10];
      BYTE انتها_سرآیند[2];
    } IMAGE_ARCHIVE_MEMBER_سرآیند_2,*PIMAGE_ARCHIVE_MEMBER_سرآیند;

#تعریف_کن IMAGE_SIZEOF_ARCHIVE_MEMBER_HDR 60

    تعريفنوع بنية _IMAGE_EXPORT_DIRECTORY {
      DWORD Characteristics;
      DWORD زمان_Date_Stamp;
      کلمه_3 Major_نسخه;
      کلمه_3 Minor_نسخه;
      DWORD Name;
      DWORD پایه_2;
      DWORD عدد_از_Functions;
      DWORD عدد_از_نامها;
      DWORD آدرس_از_Functions;
      DWORD آدرس_از_نامها;
      DWORD آدرس_از_Name_Ordinals;
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
	ULONGLONG آدرس_از_داده;
      } u1;
    } IMAGE_THUNK_DATA64;
    تعريفنوع IMAGE_THUNK_DATA64 *PIMAGE_THUNK_DATA64;

#ضمن "poppack.h"

    تعريفنوع بنية _IMAGE_THUNK_DATA32 {
      اتحاد {
	DWORD ForwarderString;
	DWORD Function;
	DWORD Ordinal;
	DWORD آدرس_از_داده;
      } u1;
    } IMAGE_THUNK_DATA32;
    تعريفنوع IMAGE_THUNK_DATA32 *PIMAGE_THUNK_DATA32;

#تعریف_کن IMAGE_ORDINAL_FLAG64 0x8000000000000000ull
#تعریف_کن IMAGE_ORDINAL_FLAG32 0x80000000
#تعریف_کن IMAGE_ORDINAL64(Ordinal) (Ordinal & 0xffffull)
#تعریف_کن IMAGE_ORDINAL32(Ordinal) (Ordinal & 0xffff)
#تعریف_کن IMAGE_SNAP_BY_ORDINAL64(Ordinal) ((Ordinal & IMAGE_ORDINAL_FLAG64)!=0)
#تعریف_کن IMAGE_SNAP_BY_ORDINAL32(Ordinal) ((Ordinal & IMAGE_ORDINAL_FLAG32)!=0)

    تعريفنوع VOID
      (NTAPI *PIMAGE_TLS_CALLBACK)(PVOID DllHandle,DWORD Reason,PVOID Reserved);

    تعريفنوع بنية _IMAGE_TLS_DIRECTORY64 {
      ULONGLONG شروع_آدرس_از_Raw_داده;
      ULONGLONG انتها_آدرس_از_Raw_داده;
      ULONGLONG آدرس_از_شاخص;
      ULONGLONG آدرس_از_Call_Backs;
      DWORD اندازه_از_Zero_Fill;
      DWORD Characteristics;
    } IMAGE_TLS_DIRECTORY64;
    تعريفنوع IMAGE_TLS_DIRECTORY64 *PIMAGE_TLS_DIRECTORY64;

    تعريفنوع بنية _IMAGE_TLS_DIRECTORY32 {
      DWORD شروع_آدرس_از_Raw_داده;
      DWORD انتها_آدرس_از_Raw_داده;
      DWORD آدرس_از_شاخص;
      DWORD آدرس_از_Call_Backs;
      DWORD اندازه_از_Zero_Fill;
      DWORD Characteristics;
    } IMAGE_TLS_DIRECTORY32;
    تعريفنوع IMAGE_TLS_DIRECTORY32 *PIMAGE_TLS_DIRECTORY32;

#اگر_تعریف_شده _WIN64
#تعریف_کن IMAGE_ORDINAL_FLAG IMAGE_ORDINAL_FLAG64
#تعریف_کن IMAGE_ORDINAL(Ordinal) IMAGE_ORDINAL64(Ordinal)
    تعريفنوع IMAGE_THUNK_DATA64 IMAGE_THUNK_داده;
    تعريفنوع PIMAGE_THUNK_DATA64 PIMAGE_THUNK_داده;
#تعریف_کن IMAGE_SNAP_BY_ORDINAL(Ordinal) IMAGE_SNAP_BY_ORDINAL64(Ordinal)
    تعريفنوع IMAGE_TLS_DIRECTORY64 IMAGE_TLS_DIRECTORY;
    تعريفنوع PIMAGE_TLS_DIRECTORY64 PIMAGE_TLS_DIRECTORY;
#وإلا
#تعریف_کن IMAGE_ORDINAL_FLAG IMAGE_ORDINAL_FLAG32
#تعریف_کن IMAGE_ORDINAL(Ordinal) IMAGE_ORDINAL32(Ordinal)
    تعريفنوع IMAGE_THUNK_DATA32 IMAGE_THUNK_داده;
    تعريفنوع PIMAGE_THUNK_DATA32 PIMAGE_THUNK_داده;
#تعریف_کن IMAGE_SNAP_BY_ORDINAL(Ordinal) IMAGE_SNAP_BY_ORDINAL32(Ordinal)
    تعريفنوع IMAGE_TLS_DIRECTORY32 IMAGE_TLS_DIRECTORY;
    تعريفنوع PIMAGE_TLS_DIRECTORY32 PIMAGE_TLS_DIRECTORY;
#پایان_اگر

    تعريفنوع بنية _IMAGE_IMPORT_DESCRIPTOR {
      اتحاد {
	DWORD Characteristics;
	DWORD Original_اولی_Thunk;
      };
      DWORD زمان_Date_Stamp;

      DWORD ForwarderChain;
      DWORD Name;
      DWORD اولی_Thunk;
    } IMAGE_IMPORT_DESCRIPTOR;
    تعريفنوع IMAGE_IMPORT_DESCRIPTOR UNALIGNED *PIMAGE_IMPORT_DESCRIPTOR;

    تعريفنوع بنية _IMAGE_BOUND_IMPORT_DESCRIPTOR {
      DWORD زمان_Date_Stamp;
      کلمه_3 جابه_جایی_Module_Name;
      کلمه_3 عدد_از_Module_Forwarder_Refs;
    } IMAGE_BOUND_IMPORT_DESCRIPTOR,*PIMAGE_BOUND_IMPORT_DESCRIPTOR;

    تعريفنوع بنية _IMAGE_BOUND_FORWARDER_REF {
      DWORD زمان_Date_Stamp;
      کلمه_3 جابه_جایی_Module_Name;
      کلمه_3 Reserved;
    } IMAGE_BOUND_FORWARDER_REF,*PIMAGE_BOUND_FORWARDER_REF;

    تعريفنوع بنية _IMAGE_RESOURCE_DIRECTORY {
      DWORD Characteristics;
      DWORD زمان_Date_Stamp;
      کلمه_3 Major_نسخه;
      کلمه_3 Minor_نسخه;
      کلمه_3 عدد_از_Named_Entries;
      کلمه_3 عدد_از_Id_Entries;
    } IMAGE_RESOURCE_DIRECTORY,*PIMAGE_RESOURCE_DIRECTORY;

#تعریف_کن IMAGE_RESOURCE_NAME_IS_STRING 0x80000000
#تعریف_کن IMAGE_RESOURCE_داده_IS_DIRECTORY 0x80000000

    تعريفنوع بنية IMAGE_RESOURCE_DIRECTORY_مدخل {
      اتحاد {
	بنية {
	  DWORD Name_جابه_جایی:31;
	  DWORD NameIsString:1;
	};
	DWORD Name;
	کلمه_3 Id;
      };
      اتحاد {
	DWORD جابه_جایی_مقصد_داده;
	بنية {
	  DWORD جابه_جایی_مقصد_Directory:31;
	  DWORD داده_Is_Directory:1;
	};
      };
    } IMAGE_RESOURCE_DIRECTORY_مدخل_2,*PIMAGE_RESOURCE_DIRECTORY_مدخل;

    تعريفنوع بنية _IMAGE_RESOURCE_DIRECTORY_STRING {
      کلمه_3 درازی_2;
      CHAR NameString[1];
    } IMAGE_RESOURCE_DIRECTORY_STRING,*PIMAGE_RESOURCE_DIRECTORY_STRING;

    تعريفنوع بنية _IMAGE_RESOURCE_DIR_STRING_U {
      کلمه_3 درازی_2;
      WCHAR NameString[1];
    } IMAGE_RESOURCE_DIR_STRING_U,*PIMAGE_RESOURCE_DIR_STRING_U;

    تعريفنوع بنية IMAGE_RESOURCE_داده_مدخل {
      DWORD جابه_جایی_مقصد_داده;
      DWORD اندازه_3;
      DWORD کد_صفحه;
      DWORD Reserved;
    } IMAGE_RESOURCE_داده_مدخل_2,*PIMAGE_RESOURCE_داده_مدخل;

    تعريفنوع بنية {
      DWORD اندازه_3;
      DWORD زمان_Date_Stamp;
      کلمه_3 Major_نسخه;
      کلمه_3 Minor_نسخه;
      DWORD GlobalFlagsClear;
      DWORD Global_Flags_مجموعه;
      DWORD CriticalSectionDefaultTimeout;
      DWORD De_Commit_Free_بلوک_آستانه;
      DWORD De_Commit_مجموع_Free_آستانه;
      DWORD قفل_پیشوند_جدول;
      DWORD بیشینه_تخصیص_اندازه;
      DWORD Virtual_حافظه_آستانه;
      DWORD Process_انباشته_Flags;
      DWORD Process_Affinity_ماسک;
      کلمه_3 CSDVersion;
      کلمه_3 Reserved1;
      DWORD EditList;
      DWORD SecurityCookie;
      DWORD SEHandler_جدول;
      DWORD SEHandler_شمار;
    } IMAGE_بارگیری_CONFIG_DIRECTORY32,*PIMAGE_بارگیری_CONFIG_DIRECTORY32;

    تعريفنوع بنية {
      DWORD اندازه_3;
      DWORD زمان_Date_Stamp;
      کلمه_3 Major_نسخه;
      کلمه_3 Minor_نسخه;
      DWORD GlobalFlagsClear;
      DWORD Global_Flags_مجموعه;
      DWORD CriticalSectionDefaultTimeout;
      ULONGLONG De_Commit_Free_بلوک_آستانه;
      ULONGLONG De_Commit_مجموع_Free_آستانه;
      ULONGLONG قفل_پیشوند_جدول;
      ULONGLONG بیشینه_تخصیص_اندازه;
      ULONGLONG Virtual_حافظه_آستانه;
      ULONGLONG Process_Affinity_ماسک;
      DWORD Process_انباشته_Flags;
      کلمه_3 CSDVersion;
      کلمه_3 Reserved1;
      ULONGLONG EditList;
      ULONGLONG SecurityCookie;
      ULONGLONG SEHandler_جدول;
      ULONGLONG SEHandler_شمار;
    } IMAGE_بارگیری_CONFIG_DIRECTORY64,*PIMAGE_بارگیری_CONFIG_DIRECTORY64;

#اگر_تعریف_شده _WIN64
    تعريفنوع IMAGE_بارگیری_CONFIG_DIRECTORY64 IMAGE_بارگیری_CONFIG_DIRECTORY;
    تعريفنوع PIMAGE_بارگیری_CONFIG_DIRECTORY64 PIMAGE_بارگیری_CONFIG_DIRECTORY;
#وإلا
    تعريفنوع IMAGE_بارگیری_CONFIG_DIRECTORY32 IMAGE_بارگیری_CONFIG_DIRECTORY;
    تعريفنوع PIMAGE_بارگیری_CONFIG_DIRECTORY32 PIMAGE_بارگیری_CONFIG_DIRECTORY;
#پایان_اگر

    تعريفنوع بنية IMAGE_CE_RUNTIME_FUNCTION_مدخل {
      DWORD Func_شروع;
      DWORD PrologLen : 8;
      DWORD FuncLen : 22;
      DWORD Thirty_Two_بیت : 1;
      DWORD ExceptionFlag : 1;
    } IMAGE_CE_RUNTIME_FUNCTION_مدخل_2,*PIMAGE_CE_RUNTIME_FUNCTION_مدخل;

    تعريفنوع بنية IMAGE_ALPHA64_RUNTIME_FUNCTION_مدخل {
      ULONGLONG Begin_آدرس;
      ULONGLONG انتها_آدرس;
      ULONGLONG ExceptionHandler;
      ULONGLONG Handler_داده;
      ULONGLONG Prolog_انتها_آدرس;
    } IMAGE_ALPHA64_RUNTIME_FUNCTION_مدخل_2,*PIMAGE_ALPHA64_RUNTIME_FUNCTION_مدخل;

    تعريفنوع بنية IMAGE_ALPHA_RUNTIME_FUNCTION_مدخل {
      DWORD Begin_آدرس;
      DWORD انتها_آدرس;
      DWORD ExceptionHandler;
      DWORD Handler_داده;
      DWORD Prolog_انتها_آدرس;
    } IMAGE_ALPHA_RUNTIME_FUNCTION_مدخل_2,*PIMAGE_ALPHA_RUNTIME_FUNCTION_مدخل;

    تعريفنوع بنية IMAGE_RUNTIME_FUNCTION_مدخل {
      DWORD Begin_آدرس;
      DWORD انتها_آدرس;
      DWORD Unwind_Info_آدرس;
    } IMAGE_RUNTIME_FUNCTION_مدخل,*PIMAGE_RUNTIME_FUNCTION_مدخل;

    تعريفنوع IMAGE_RUNTIME_FUNCTION_مدخل IMAGE_IA64_RUNTIME_FUNCTION_مدخل;
    تعريفنوع PIMAGE_RUNTIME_FUNCTION_مدخل PIMAGE_IA64_RUNTIME_FUNCTION_مدخل;

    تعريفنوع IMAGE_RUNTIME_FUNCTION_مدخل IMAGE_RUNTIME_FUNCTION_مدخل_2;
    تعريفنوع PIMAGE_RUNTIME_FUNCTION_مدخل PIMAGE_RUNTIME_FUNCTION_مدخل_2;

    تعريفنوع بنية _IMAGE_DEBUG_DIRECTORY {
      DWORD Characteristics;
      DWORD زمان_Date_Stamp;
      کلمه_3 Major_نسخه;
      کلمه_3 Minor_نسخه;
      DWORD Type;
      DWORD اندازه_از_داده;
      DWORD آدرس_از_Raw_داده;
      DWORD اشاره_گر_مقصد_Raw_داده;
    } IMAGE_DEBUG_DIRECTORY,*PIMAGE_DEBUG_DIRECTORY;

#تعریف_کن IMAGE_DEBUG_TYPE_UNKNOWN 0
#تعریف_کن IMAGE_DEBUG_TYPE_COFF 1
#تعریف_کن IMAGE_DEBUG_TYPE_CODEVIEW 2
#تعریف_کن IMAGE_DEBUG_TYPE_FPO 3
#تعریف_کن IMAGE_DEBUG_TYPE_MISC 4
#تعریف_کن IMAGE_DEBUG_TYPE_EXCEPTION 5
#تعریف_کن IMAGE_DEBUG_TYPE_FIXUP 6
#تعریف_کن IMAGE_DEBUG_TYPE_OMAP_مقصد_SRC 7
#تعریف_کن IMAGE_DEBUG_TYPE_OMAP_FROM_SRC 8
#تعریف_کن IMAGE_DEBUG_TYPE_BORLAND 9
#تعریف_کن IMAGE_DEBUG_TYPE_RESERVED10 10
#تعریف_کن IMAGE_DEBUG_TYPE_CLSID 11

    تعريفنوع بنية IMAGE_COFF_SYMBOLS_سرآیند {
      DWORD عدد_از_Symbols;
      DWORD Lva_مقصد_اولی_نماد;
      DWORD عدد_از_Linenumbers;
      DWORD Lva_مقصد_اولی_Linenumber;
      DWORD Rva_مقصد_اولی_Byte_از_کد;
      DWORD Rva_مقصد_آخرین_Byte_از_کد;
      DWORD Rva_مقصد_اولی_Byte_از_داده;
      DWORD Rva_مقصد_آخرین_Byte_از_داده;
    } IMAGE_COFF_SYMBOLS_سرآیند_2,*PIMAGE_COFF_SYMBOLS_سرآیند;

#تعریف_کن قاب_FPO 0
#تعریف_کن قاب_TRAP 1
#تعریف_کن قاب_TSS 2
#تعریف_کن قاب_NONFPO 3

    تعريفنوع بنية FPO_داده {
      DWORD ul_Off_شروع;
      DWORD cb_Proc_اندازه;
      DWORD cdwLocals;
      کلمه_3 cdwParams;
      کلمه_3 cbProlog : 8;
      کلمه_3 cbRegs : 3;
      کلمه_3 fHasSEH : 1;
      کلمه_3 fUseBP : 1;
      کلمه_3 reserved : 1;
      کلمه_3 cb_قاب : 2;
    } FPO_داده_2,*PFPO_داده;
#تعریف_کن SIZEOF_RFPO_داده 16

#تعریف_کن IMAGE_DEBUG_MISC_EXENAME 1

    تعريفنوع بنية _IMAGE_DEBUG_MISC {
      DWORD داده_Type;
      DWORD درازی_2;
      BOOLEAN Unicode;
      BYTE Reserved[3];
      BYTE داده_3[1];
    } IMAGE_DEBUG_MISC,*PIMAGE_DEBUG_MISC;

    تعريفنوع بنية IMAGE_FUNCTION_مدخل {
      DWORD Starting_آدرس;
      DWORD Ending_آدرس;
      DWORD انتها_از_Prologue;
    } IMAGE_FUNCTION_مدخل_2,*PIMAGE_FUNCTION_مدخل;

    تعريفنوع بنية _IMAGE_FUNCTION_ENTRY64 {
      ULONGLONG Starting_آدرس;
      ULONGLONG Ending_آدرس;
      اتحاد {
	ULONGLONG انتها_از_Prologue;
	ULONGLONG Unwind_Info_آدرس;
      };
    } IMAGE_FUNCTION_ENTRY64,*PIMAGE_FUNCTION_ENTRY64;

    تعريفنوع بنية IMAGE_SEPARATE_DEBUG_سرآیند {
      کلمه_3 Signature;
      کلمه_3 Flags;
      کلمه_3 Machine;
      کلمه_3 Characteristics;
      DWORD زمان_Date_Stamp;
      DWORD Check_جمع;
      DWORD Image_پایه;
      DWORD اندازه_از_Image;
      DWORD عدد_از_Sections;
      DWORD Exported_نامها_اندازه;
      DWORD Debug_Directory_اندازه;
      DWORD SectionAlignment;
      DWORD Reserved[2];
    } IMAGE_SEPARATE_DEBUG_سرآیند_2,*PIMAGE_SEPARATE_DEBUG_سرآیند;

    تعريفنوع بنية _NON_PAGED_DEBUG_INFO {
      کلمه_3 Signature;
      کلمه_3 Flags;
      DWORD اندازه_3;
      کلمه_3 Machine;
      کلمه_3 Characteristics;
      DWORD زمان_Date_Stamp;
      DWORD Check_جمع;
      DWORD اندازه_از_Image;
      ULONGLONG Image_پایه;

    } NON_PAGED_DEBUG_INFO,*PNON_PAGED_DEBUG_INFO;

#تعریف_کن IMAGE_SEPARATE_DEBUG_SIGNATURE 0x4944
#تعریف_کن NON_PAGED_DEBUG_SIGNATURE 0x494E

#تعریف_کن IMAGE_SEPARATE_DEBUG_FLAGS_ماسک 0x8000
#تعریف_کن IMAGE_SEPARATE_DEBUG_MISMATCH 0x8000

    تعريفنوع بنية Image_Architecture_سرآیند {
      بیعلامت صحيح Amask_مقدار: 1;
      صحيح Adummy1 :7;
      بیعلامت صحيح Amask_لغزش: 8;
      صحيح Adummy2 :16;
      DWORD اولی_مدخل_RVA;
    } IMAGE_ARCHITECTURE_سرآیند,*PIMAGE_ARCHITECTURE_سرآیند;

    تعريفنوع بنية Image_Architecture_مدخل {
      DWORD FixupInstRVA;
      DWORD NewInst;
    } IMAGE_ARCHITECTURE_مدخل,*PIMAGE_ARCHITECTURE_مدخل;

#ضمن "poppack.h"

#تعریف_کن IMPORT_OBJECT_HDR_SIG2 0xffff

    تعريفنوع بنية IMPORT_OBJECT_سرآیند {
      کلمه_3 Sig1;
      کلمه_3 Sig2;
      کلمه_3 نسخه_2;
      کلمه_3 Machine;
      DWORD زمان_Date_Stamp;
      DWORD اندازه_از_داده;
      اتحاد {
	کلمه_3 Ordinal;
	کلمه_3 Hint;
      };
      کلمه_3 Type : 2;
      کلمه_3 NameType : 3;
      کلمه_3 Reserved : 11;
    } IMPORT_OBJECT_سرآیند;

    تعريفنوع تعداد IMPORT_OBJECT_TYPE {
      IMPORT_OBJECT_کد = 0,IMPORT_OBJECT_داده = 1,IMPORT_OBJECT_CONST = 2
    } IMPORT_OBJECT_TYPE;

    تعريفنوع تعداد IMPORT_OBJECT_NAME_TYPE {
      IMPORT_OBJECT_ORDINAL = 0,IMPORT_OBJECT_NAME = 1,IMPORT_OBJECT_NAME_NO_پیشوند = 2,IMPORT_OBJECT_NAME_UNDECORATE = 3
    } IMPORT_OBJECT_NAME_TYPE;

#اگر_تعریف_نشده __IMAGE_COR20_HEADER_DEFINED__
#تعریف_کن __IMAGE_COR20_HEADER_DEFINED__
    تعريفنوع تعداد Replaces_Cor_Hdr_Numeric_تعریف_میکند {
      COMIMAGE_FLAGS_ILONLY =0x00000001,COMIMAGE_FLAGS_32BITREQUIRED =0x00000002,COMIMAGE_FLAGS_IL_LIBRARY =0x00000004,
      COMIMAGE_FLAGS_STRONGNAMESIGNED =0x00000008,COMIMAGE_FLAGS_TRACKDEBUGDATA =0x00010000,COR_نسخه_MAJOR_V2 =2,
      COR_نسخه_MAJOR =COR_نسخه_MAJOR_V2,COR_نسخه_MINOR =0,COR_DELETED_NAME_درازی =8,COR_VTABLEGAP_NAME_درازی =8,
      NATIVE_TYPE_MAX_CB =1,COR_ILMETHOD_SECT_SMALL_MAX_DATASIZE=0xFF,IMAGE_COR_MIH_METHODRVA =0x01,IMAGE_COR_MIH_EHRVA =0x02,
      IMAGE_COR_MIH_BASICBLOCK =0x08,COR_VTABLE_32_بیت =0x01,COR_VTABLE_64_بیت =0x02,COR_VTABLE_FROM_UNMANAGED =0x04,
      COR_VTABLE_CALL_MOST_DERIVED =0x10,IMAGE_COR_EATJ_THUNK_اندازه =32,MAX_CLASS_NAME =1024,MAX_PACKAGE_NAME =1024
    } Replaces_Cor_Hdr_Numeric_تعریف_میکند;

    تعريفنوع بنية IMAGE_COR20_سرآیند {
      DWORD cb;
      کلمه_3 Major_Runtime_نسخه;
      کلمه_3 Minor_Runtime_نسخه;
      IMAGE_داده_DIRECTORY_2 Meta_داده;
      DWORD Flags;
      DWORD مدخل_نقطه_Token;
      IMAGE_داده_DIRECTORY_2 Resources;
      IMAGE_داده_DIRECTORY_2 StrongNameSignature;
      IMAGE_داده_DIRECTORY_2 کد_Manager_جدول;
      IMAGE_داده_DIRECTORY_2 VTableFixups;
      IMAGE_داده_DIRECTORY_2 Export_آدرس_جدول_Jumps;
      IMAGE_داده_DIRECTORY_2 Managed_Native_سرآیند;
    } IMAGE_COR20_سرآیند,*PIMAGE_COR20_سرآیند;
#پایان_اگر

#إذا defined (__x86_64)
    NTSYSAPI PRUNTIME_FUNCTION NTAPI Rtl_Lookup_Function_مدخل (DWORD64 ControlPc, PDWORD64 Image_پایه, PUNWIND_HISTORY_جدول History_جدول);
    NTSYSAPI VOID NTAPI RtlUnwindEx (PVOID هدف_قاب, PVOID هدف_Ip, PEXCEPTION_رکورد Exception_رکورد, PVOID Return_مقدار_2, PCONTEXT Context_رکورد, PUNWIND_HISTORY_جدول History_جدول);
#پایان_اگر

#ضمن <string.h>

#اگر_تعریف_نشده SLIST_سرآیند
#تعریف_کن SLIST_سرآیند

#اگر_تعریف_شده _WIN64
    تعريفنوع بنية SLIST_مدخل *PSLIST_مدخل;
    تعريفنوع بنية DECLSPEC_ALIGN(16) SLIST_مدخل {
      PSLIST_مدخل بعدی_2;
    } SLIST_مدخل_2;
#وإلا

#تعریف_کن SLIST_مدخل_2 SINGLE_LIST_مدخل_2
#تعریف_کن SLIST_مدخل SINGLE_LIST_مدخل
#تعریف_کن PSLIST_مدخل PSINGLE_LIST_مدخل
#پایان_اگر

#إذا defined(_WIN64)

    تعريفنوع بنية DECLSPEC_ALIGN(16) SLIST_سرآیند_2 {
      ULONGLONG Alignment;
      ULONGLONG Region;
    } SLIST_سرآیند_3;

    تعريفنوع بنية SLIST_سرآیند_2 *PSLIST_سرآیند;
#وإلا

    تعريفنوع اتحاد SLIST_سرآیند_2 {
      ULONGLONG Alignment;
      بنية {
	SLIST_مدخل_2 بعدی_2;
	کلمه_3 عمق;
	کلمه_3 Sequence;
      };
    } SLIST_سرآیند_3,*PSLIST_سرآیند;
#پایان_اگر
#پایان_اگر

    NTSYSAPI VOID NTAPI Rtl_Initialize_SList_سر(PSLIST_سرآیند List_سر);
    NTSYSAPI PSLIST_مدخل NTAPI Rtl_اولی_مدخل_SList(ثابت SLIST_سرآیند_3 *List_سر);
    NTSYSAPI PSLIST_مدخل NTAPI Rtl_Interlocked_برداشت_مدخل_SList(PSLIST_سرآیند List_سر);
    NTSYSAPI PSLIST_مدخل NTAPI Rtl_Interlocked_افزودن_مدخل_SList(PSLIST_سرآیند List_سر,PSLIST_مدخل List_مدخل);
    NTSYSAPI PSLIST_مدخل NTAPI RtlInterlockedFlushSList(PSLIST_سرآیند List_سر);
    NTSYSAPI کلمه_3 NTAPI Rtl_Query_عمق_SList(PSLIST_سرآیند List_سر);

#تعریف_کن انباشته_NO_SERIALIZE 0x00000001
#تعریف_کن انباشته_GROWABLE 0x00000002
#تعریف_کن انباشته_GENERATE_EXCEPTIONS 0x00000004
#تعریف_کن انباشته_ZERO_حافظه 0x00000008
#تعریف_کن انباشته_REALLOC_درون_قراربده_ONLY 0x00000010
#تعریف_کن انباشته_دم_CHECKING_ENABLED 0x00000020
#تعریف_کن انباشته_FREE_CHECKING_ENABLED 0x00000040
#تعریف_کن انباشته_DISABLE_COALESCE_ON_FREE 0x00000080
#تعریف_کن انباشته_CREATE_ALIGN_16 0x00010000
#تعریف_کن انباشته_CREATE_ENABLE_TRACING 0x00020000
#تعریف_کن انباشته_CREATE_ENABLE_EXECUTE 0x00040000
#تعریف_کن انباشته_بیشینه_برچسب 0x0FFF
#تعریف_کن انباشته_PSEUDO_برچسب_FLAG 0x8000
#تعریف_کن انباشته_برچسب_لغزش 18
#تعریف_کن انباشته_MAKE_برچسب_FLAGS(b,o) ((DWORD)((b) + ((o) << 18)))

    NTSYSAPI VOID NTAPI RtlCaptureContext(PCONTEXT Context_رکورد);

#تعریف_کن IS_متن_UNICODE_ASCII16 0x0001
#تعریف_کن IS_متن_UNICODE_معکوس_ASCII16 0x0010

#تعریف_کن IS_متن_UNICODE_STATISTICS 0x0002
#تعریف_کن IS_متن_UNICODE_معکوس_STATISTICS 0x0020

#تعریف_کن IS_متن_UNICODE_CONTROLS 0x0004
#تعریف_کن IS_متن_UNICODE_معکوس_CONTROLS 0x0040

#تعریف_کن IS_متن_UNICODE_SIGNATURE 0x0008
#تعریف_کن IS_متن_UNICODE_معکوس_SIGNATURE 0x0080

#تعریف_کن IS_متن_UNICODE_ILLEGAL_CHARS 0x0100
#تعریف_کن IS_متن_UNICODE_ODD_درازی 0x0200
#تعریف_کن IS_متن_UNICODE_DBCS_LEADBYTE 0x0400
#تعریف_کن IS_متن_UNICODE_NULL_بایتها 0x1000

#تعریف_کن IS_متن_UNICODE_UNICODE_ماسک 0x000F
#تعریف_کن IS_متن_UNICODE_معکوس_ماسک 0x00F0
#تعریف_کن IS_متن_UNICODE_NOT_UNICODE_ماسک 0x0F00
#تعریف_کن IS_متن_UNICODE_NOT_ASCII_ماسک 0xF000

#تعریف_کن COMPRESSION_FORMAT_NONE (0x0000)
#تعریف_کن COMPRESSION_FORMAT_DEFAULT (0x0001)
#تعریف_کن COMPRESSION_FORMAT_LZNT1 (0x0002)
#تعریف_کن COMPRESSION_ENGINE_STANDARD (0x0000)
#تعریف_کن COMPRESSION_ENGINE_بیشینه (0x0100)
#تعریف_کن COMPRESSION_ENGINE_HIBER (0x0200)

#إذا _DBG_MEMCPY_INLINE_ && !defined(_MEMCPY_INLINE_) && !defined(_CRTBLD)
#تعریف_کن _MEMCPY_INLINE_
    __CRT_INLINE PVOID __cdecl memcpy_inline(فراغ *dst,ثابت فراغ *src,اندازه_t اندازه) {
      إذا(((حرف *)dst > (حرف *)src) && ((حرف *)dst < ((حرف *)src + اندازه))) {
	__debugbreak();
      }
      أرجع کپی_حافظه(dst,src,اندازه);
    }
#تعریف_کن کپی_حافظه memcpy_inline
#پایان_اگر

    NTSYSAPI اندازه_T NTAPI Rtl_Compare_حافظه(ثابت VOID *Source1,ثابت VOID *Source2,اندازه_T درازی_2);

#تعریف_کن Rtl_Equal_حافظه(Destination,منبع_2,درازی_2) (!memcmp((Destination),(منبع_2),(درازی_2)))
#تعریف_کن Rtl_Move_حافظه(Destination,منبع_2,درازی_2) memmove((Destination),(منبع_2),(درازی_2))
#تعریف_کن Rtl_Copy_حافظه(Destination,منبع_2,درازی_2) کپی_حافظه((Destination),(منبع_2),(درازی_2))
#تعریف_کن Rtl_Fill_حافظه(Destination,درازی_2,Fill) memset((Destination),(Fill),(درازی_2))
#تعریف_کن Rtl_Zero_حافظه(Destination,درازی_2) memset((Destination),0,(درازی_2))

    __CRT_INLINE PVOID Rtl_Secure_Zero_حافظه(PVOID ptr,اندازه_T cnt) {
      متطاير حرف *vptr =(متطاير حرف *)ptr;
#اگر_تعریف_شده __x86_64
      __stosb((PBYTE)((DWORD64)vptr),0,cnt);
#وإلا
      طالما(cnt) {
	*vptr = 0;
	vptr++;
	cnt--;
      }
#پایان_اگر
      أرجع ptr;
    }

    تعريفنوع بنية پیام_RESOURCE_مدخل {
      کلمه_3 درازی_2;
      کلمه_3 Flags;
      BYTE متن_4[1];
    } پیام_RESOURCE_مدخل_2,*PMESSAGE_RESOURCE_مدخل;

#تعریف_کن پیام_RESOURCE_UNICODE 0x0001

    تعريفنوع بنية پیام_RESOURCE_بلوک {
      DWORD کم_Id;
      DWORD بالا_Id;
      DWORD جابه_جایی_مقصد_Entries;
    } پیام_RESOURCE_بلوک_2,*PMESSAGE_RESOURCE_بلوک;

    تعريفنوع بنية پیام_RESOURCE_داده {
      DWORD عدد_از_بلوکها;
      پیام_RESOURCE_بلوک_2 بلوکها_2[1];
    } پیام_RESOURCE_داده_2,*PMESSAGE_RESOURCE_داده;

    تعريفنوع بنية _OSVERSIONINFOA {
      DWORD dw_OSVersion_Info_اندازه;
      DWORD dw_Major_نسخه;
      DWORD dw_Minor_نسخه;
      DWORD dw_Build_عدد;
      DWORD dwPlatformId;
      CHAR szCSDVersion[128];
    } OSVERSIONINFOA,*POSVERSIONINFOA,*LPOSVERSIONINFOA;

    تعريفنوع بنية _OSVERSIONINFOW {
      DWORD dw_OSVersion_Info_اندازه;
      DWORD dw_Major_نسخه;
      DWORD dw_Minor_نسخه;
      DWORD dw_Build_عدد;
      DWORD dwPlatformId;
      WCHAR szCSDVersion[128];
    } OSVERSIONINFOW,*POSVERSIONINFOW,*LPOSVERSIONINFOW,RTL_OSVERSIONINFOW,*PRTL_OSVERSIONINFOW;

#اگر_تعریف_شده UNICODE
    تعريفنوع OSVERSIONINFOW OSVERSIONINFO;
    تعريفنوع POSVERSIONINFOW POSVERSIONINFO;
    تعريفنوع LPOSVERSIONINFOW LPOSVERSIONINFO;
#وإلا
    تعريفنوع OSVERSIONINFOA OSVERSIONINFO;
    تعريفنوع POSVERSIONINFOA POSVERSIONINFO;
    تعريفنوع LPOSVERSIONINFOA LPOSVERSIONINFO;
#پایان_اگر

    تعريفنوع بنية _OSVERSIONINFOEXA {
      DWORD dw_OSVersion_Info_اندازه;
      DWORD dw_Major_نسخه;
      DWORD dw_Minor_نسخه;
      DWORD dw_Build_عدد;
      DWORD dwPlatformId;
      CHAR szCSDVersion[128];
      کلمه_3 wServicePackMajor;
      کلمه_3 wServicePackMinor;
      کلمه_3 w_Suite_ماسک;
      BYTE w_حاصلضرب_Type;
      BYTE wReserved;
    } OSVERSIONINFOEXA,*POSVERSIONINFOEXA,*LPOSVERSIONINFOEXA;

    تعريفنوع بنية _OSVERSIONINFOEXW {
      DWORD dw_OSVersion_Info_اندازه;
      DWORD dw_Major_نسخه;
      DWORD dw_Minor_نسخه;
      DWORD dw_Build_عدد;
      DWORD dwPlatformId;
      WCHAR szCSDVersion[128];
      کلمه_3 wServicePackMajor;
      کلمه_3 wServicePackMinor;
      کلمه_3 w_Suite_ماسک;
      BYTE w_حاصلضرب_Type;
      BYTE wReserved;
    } OSVERSIONINFOEXW,*POSVERSIONINFOEXW,*LPOSVERSIONINFOEXW,RTL_OSVERSIONINFOEXW,*PRTL_OSVERSIONINFOEXW;
#اگر_تعریف_شده UNICODE
    تعريفنوع OSVERSIONINFOEXW OSVERSIONINFOEX;
    تعريفنوع POSVERSIONINFOEXW POSVERSIONINFOEX;
    تعريفنوع LPOSVERSIONINFOEXW LPOSVERSIONINFOEX;
#وإلا
    تعريفنوع OSVERSIONINFOEXA OSVERSIONINFOEX;
    تعريفنوع POSVERSIONINFOEXA POSVERSIONINFOEX;
    تعريفنوع LPOSVERSIONINFOEXA LPOSVERSIONINFOEX;
#پایان_اگر

#تعریف_کن VER_EQUAL 1
#تعریف_کن VER_GREATER 2
#تعریف_کن VER_GREATER_EQUAL 3
#تعریف_کن VER_LESS 4
#تعریف_کن VER_LESS_EQUAL 5
#تعریف_کن VER_AND 6
#تعریف_کن VER_OR 7

#تعریف_کن VER_CONDITION_ماسک 7
#تعریف_کن VER_رقم_بیتها_در_هر_CONDITION_ماسک 3

#تعریف_کن VER_MINORVERSION 0x0000001
#تعریف_کن VER_MAJORVERSION 0x0000002
#تعریف_کن VER_BUILDNUMBER 0x0000004
#تعریف_کن VER_PLATFORMID 0x0000008
#تعریف_کن VER_SERVICEPACKMINOR 0x0000010
#تعریف_کن VER_SERVICEPACKMAJOR 0x0000020
#تعریف_کن VER_SUITENAME 0x0000040
#تعریف_کن VER_حاصلضرب_TYPE 0x0000080

#تعریف_کن VER_NT_WORKSTATION 0x0000001
#تعریف_کن VER_NT_DOMAIN_CONTROLLER 0x0000002
#تعریف_کن VER_NT_SERVER 0x0000003

#تعریف_کن VER_PLATFORM_WIN32s 0
#تعریف_کن VER_PLATFORM_WIN32_WINDOWS 1
#تعریف_کن VER_PLATFORM_WIN32_NT 2

#تعریف_کن VER_مجموعه_CONDITION(_m_,_t_,_c_) ((_m_)=Ver_مجموعه_Condition_ماسک((_m_),(_t_),(_c_)))

    NTSYSAPI ULONGLONG NTAPI Ver_مجموعه_Condition_ماسک(ULONGLONG Condition_ماسک,DWORD Type_ماسک,BYTE Condition);

    تعريفنوع بنية _RTL_CRITICAL_SECTION_DEBUG {
      کلمه_3 Type;
      کلمه_3 Creator_پشت_Trace_شاخص;
      بنية _RTL_CRITICAL_SECTION *CriticalSection;
      LIST_مدخل_2 ProcessLocksList;
      DWORD مدخل_شمار;
      DWORD Contention_شمار;
      DWORD یدکی_2[2];
    } RTL_CRITICAL_SECTION_DEBUG,*PRTL_CRITICAL_SECTION_DEBUG,RTL_RESOURCE_DEBUG,*PRTL_RESOURCE_DEBUG;

#تعریف_کن RTL_CRITSECT_TYPE 0
#تعریف_کن RTL_RESOURCE_TYPE 1

    تعريفنوع بنية _RTL_CRITICAL_SECTION {
      PRTL_CRITICAL_SECTION_DEBUG DebugInfo;
      LONG قفل_شمار;
      LONG Recursion_شمار;
      HANDLE OwningThread;
      HANDLE قفل_Semaphore;
      ULONG_PTR Spin_شمار;
    } RTL_CRITICAL_SECTION,*PRTL_CRITICAL_SECTION;

    تعريفنوع VOID (NTAPI *RTL_VERIFIER_DLL_بارگیری_CALLBACK) (PWSTR DllName,PVOID Dll_پایه,اندازه_T Dll_اندازه,PVOID Reserved);
    تعريفنوع VOID (NTAPI *RTL_VERIFIER_DLL_UNLOAD_CALLBACK) (PWSTR DllName,PVOID Dll_پایه,اندازه_T Dll_اندازه,PVOID Reserved);
    تعريفنوع VOID (NTAPI *RTL_VERIFIER_NTDLLHEAPFREE_CALLBACK)(PVOID تخصیص_پایه,اندازه_T تخصیص_اندازه);

    تعريفنوع بنية _RTL_VERIFIER_THUNK_DESCRIPTOR {
      PCHAR ThunkName;
      PVOID Thunk_Old_آدرس;
      PVOID Thunk_New_آدرس;
    } RTL_VERIFIER_THUNK_DESCRIPTOR,*PRTL_VERIFIER_THUNK_DESCRIPTOR;

    تعريفنوع بنية _RTL_VERIFIER_DLL_DESCRIPTOR {
      PWCHAR DllName;
      DWORD DllFlags;
      PVOID Dll_آدرس;
      PRTL_VERIFIER_THUNK_DESCRIPTOR DllThunks;
    } RTL_VERIFIER_DLL_DESCRIPTOR,*PRTL_VERIFIER_DLL_DESCRIPTOR;

    تعريفنوع بنية _RTL_VERIFIER_PROVIDER_DESCRIPTOR {
      DWORD درازی_2;
      PRTL_VERIFIER_DLL_DESCRIPTOR ProviderDlls;
      RTL_VERIFIER_DLL_بارگیری_CALLBACK Provider_Dll_بارگیری_Callback;
      RTL_VERIFIER_DLL_UNLOAD_CALLBACK ProviderDllUnloadCallback;
      PWSTR VerifierImage;
      DWORD VerifierFlags;
      DWORD VerifierDebug;
      PVOID Rtlp_Get_پشته_Trace_آدرس;
      PVOID Rtlp_Debug_صفحه_انباشته_Create;
      PVOID Rtlp_Debug_صفحه_انباشته_Destroy;
      RTL_VERIFIER_NTDLLHEAPFREE_CALLBACK Provider_Ntdll_انباشته_Free_Callback;
    } RTL_VERIFIER_PROVIDER_DESCRIPTOR,*PRTL_VERIFIER_PROVIDER_DESCRIPTOR;

#تعریف_کن RTL_VRF_FLG_پر_صفحه_انباشته 0x00000001
#تعریف_کن RTL_VRF_FLG_RESERVED_DONOTUSE 0x00000002
#تعریف_کن RTL_VRF_FLG_HANDLE_CHECKS 0x00000004
#تعریف_کن RTL_VRF_FLG_پشته_CHECKS 0x00000008
#تعریف_کن RTL_VRF_FLG_APPCOMPAT_CHECKS 0x00000010
#تعریف_کن RTL_VRF_FLG_TLS_CHECKS 0x00000020
#تعریف_کن RTL_VRF_FLG_DIRTY_STACKS 0x00000040
#تعریف_کن RTL_VRF_FLG_RPC_CHECKS 0x00000080
#تعریف_کن RTL_VRF_FLG_COM_CHECKS 0x00000100
#تعریف_کن RTL_VRF_FLG_DANGEROUS_APIS 0x00000200
#تعریف_کن RTL_VRF_FLG_RACE_CHECKS 0x00000400
#تعریف_کن RTL_VRF_FLG_DEADLOCK_CHECKS 0x00000800
#تعریف_کن RTL_VRF_FLG_اولی_CHANCE_EXCEPTION_CHECKS 0x00001000
#تعریف_کن RTL_VRF_FLG_VIRTUAL_MEM_CHECKS 0x00002000
#تعریف_کن RTL_VRF_FLG_ENABLE_LOGGING 0x00004000
#تعریف_کن RTL_VRF_FLG_FAST_FILL_انباشته 0x00008000
#تعریف_کن RTL_VRF_FLG_VIRTUAL_SPACE_TRACKING 0x00010000
#تعریف_کن RTL_VRF_FLG_ENABLED_SYSTEM_WIDE 0x00020000
#تعریف_کن RTL_VRF_FLG_MISCELLANEOUS_CHECKS 0x00020000
#تعریف_کن RTL_VRF_FLG_قفل_CHECKS 0x00040000

#تعریف_کن APPLICATION_VERIFIER_داخلی_ERROR 0x80000000
#تعریف_کن APPLICATION_VERIFIER_داخلی_WARNING 0x40000000
#تعریف_کن APPLICATION_VERIFIER_NO_BREAK 0x20000000
#تعریف_کن APPLICATION_VERIFIER_CONTINUABLE_BREAK 0x10000000

#تعریف_کن APPLICATION_VERIFIER_UNKNOWN_ERROR 0x0001
#تعریف_کن APPLICATION_VERIFIER_ACCESS_VIOLATION 0x0002
#تعریف_کن APPLICATION_VERIFIER_UNSYNCHRONIZED_ACCESS 0x0003
#تعریف_کن APPLICATION_VERIFIER_EXTREME_اندازه_REQUEST 0x0004
#تعریف_کن APPLICATION_VERIFIER_BAD_انباشته_HANDLE 0x0005
#تعریف_کن APPLICATION_VERIFIER_SWITCHED_انباشته_HANDLE 0x0006
#تعریف_کن APPLICATION_VERIFIER_DOUBLE_FREE 0x0007
#تعریف_کن APPLICATION_VERIFIER_CORRUPTED_انباشته_بلوک 0x0008
#تعریف_کن APPLICATION_VERIFIER_DESTROY_PROCESS_انباشته 0x0009
#تعریف_کن APPLICATION_VERIFIER_UNEXPECTED_EXCEPTION 0x000A
#تعریف_کن APPLICATION_VERIFIER_CORRUPTED_انباشته_بلوک_EXCEPTION_RAISED_FOR_سرآیند 0x000B
#تعریف_کن APPLICATION_VERIFIER_CORRUPTED_انباشته_بلوک_EXCEPTION_RAISED_FOR_PROBING 0x000C
#تعریف_کن APPLICATION_VERIFIER_CORRUPTED_انباشته_بلوک_سرآیند 0x000D
#تعریف_کن APPLICATION_VERIFIER_CORRUPTED_FREED_انباشته_بلوک 0x000E
#تعریف_کن APPLICATION_VERIFIER_CORRUPTED_انباشته_بلوک_SUFFIX 0x000F
#تعریف_کن APPLICATION_VERIFIER_CORRUPTED_انباشته_بلوک_شروع_STAMP 0x0010
#تعریف_کن APPLICATION_VERIFIER_CORRUPTED_انباشته_بلوک_انتها_STAMP 0x0011
#تعریف_کن APPLICATION_VERIFIER_CORRUPTED_انباشته_بلوک_پیشوند 0x0012
#تعریف_کن APPLICATION_VERIFIER_اولی_CHANCE_ACCESS_VIOLATION 0x0013
#تعریف_کن APPLICATION_VERIFIER_CORRUPTED_انباشته_LIST 0x0014

#تعریف_کن APPLICATION_VERIFIER_TERMINATE_THREAD_CALL 0x0100
#تعریف_کن APPLICATION_VERIFIER_پشته_سرریز 0x0101
#تعریف_کن APPLICATION_VERIFIER_INVALID_EXIT_PROCESS_CALL 0x0102

#تعریف_کن APPLICATION_VERIFIER_EXIT_THREAD_OWNS_قفل 0x0200
#تعریف_کن APPLICATION_VERIFIER_قفل_درون_UNLOADED_DLL 0x0201
#تعریف_کن APPLICATION_VERIFIER_قفل_درون_FREED_انباشته 0x0202
#تعریف_کن APPLICATION_VERIFIER_قفل_DOUBLE_INITIALIZE 0x0203
#تعریف_کن APPLICATION_VERIFIER_قفل_درون_FREED_حافظه 0x0204
#تعریف_کن APPLICATION_VERIFIER_قفل_CORRUPTED 0x0205
#تعریف_کن APPLICATION_VERIFIER_قفل_INVALID_OWNER 0x0206
#تعریف_کن APPLICATION_VERIFIER_قفل_INVALID_RECURSION_شمار 0x0207
#تعریف_کن APPLICATION_VERIFIER_قفل_INVALID_قفل_شمار 0x0208
#تعریف_کن APPLICATION_VERIFIER_قفل_OVER_RELEASED 0x0209
#تعریف_کن APPLICATION_VERIFIER_قفل_NOT_INITIALIZED 0x0210
#تعریف_کن APPLICATION_VERIFIER_قفل_ALREADY_INITIALIZED 0x0211
#تعریف_کن APPLICATION_VERIFIER_قفل_درون_FREED_VMEM 0x0212
#تعریف_کن APPLICATION_VERIFIER_قفل_درون_UNMAPPED_MEM 0x0213
#تعریف_کن APPLICATION_VERIFIER_THREAD_NOT_قفل_OWNER 0x0214

#تعریف_کن APPLICATION_VERIFIER_INVALID_HANDLE 0x0300
#تعریف_کن APPLICATION_VERIFIER_INVALID_TLS_مقدار 0x0301
#تعریف_کن APPLICATION_VERIFIER_INCORRECT_WAIT_CALL 0x0302
#تعریف_کن APPLICATION_VERIFIER_NULL_HANDLE 0x0303
#تعریف_کن APPLICATION_VERIFIER_WAIT_درون_DLLMAIN 0x0304

#تعریف_کن APPLICATION_VERIFIER_COM_ERROR 0x0400
#تعریف_کن APPLICATION_VERIFIER_COM_API_درون_DLLMAIN 0x0401
#تعریف_کن APPLICATION_VERIFIER_COM_UNHANDLED_EXCEPTION 0x0402
#تعریف_کن APPLICATION_VERIFIER_COM_UNBALANCED_COINIT 0x0403
#تعریف_کن APPLICATION_VERIFIER_COM_UNBALANCED_OLEINIT 0x0404
#تعریف_کن APPLICATION_VERIFIER_COM_UNBALANCED_SWC 0x0405
#تعریف_کن APPLICATION_VERIFIER_COM_NULL_DACL 0x0406
#تعریف_کن APPLICATION_VERIFIER_COM_UNSAFE_IMPERSONATION 0x0407
#تعریف_کن APPLICATION_VERIFIER_COM_SMUGGLED_WRAPPER 0x0408
#تعریف_کن APPLICATION_VERIFIER_COM_SMUGGLED_PROXY 0x0409
#تعریف_کن APPLICATION_VERIFIER_COM_CF_SUCCESS_WITH_NULL 0x040A
#تعریف_کن APPLICATION_VERIFIER_COM_GCO_SUCCESS_WITH_NULL 0x040B
#تعریف_کن APPLICATION_VERIFIER_COM_OBJECT_درون_FREED_حافظه 0x040C
#تعریف_کن APPLICATION_VERIFIER_COM_OBJECT_درون_UNLOADED_DLL 0x040D
#تعریف_کن APPLICATION_VERIFIER_COM_VTBL_درون_FREED_حافظه 0x040E
#تعریف_کن APPLICATION_VERIFIER_COM_VTBL_درون_UNLOADED_DLL 0x040F
#تعریف_کن APPLICATION_VERIFIER_COM_HOLDING_LOCKS_ON_CALL 0x0410

#تعریف_کن APPLICATION_VERIFIER_RPC_ERROR 0x0500

#تعریف_کن APPLICATION_VERIFIER_INVALID_FREEMEM 0x0600
#تعریف_کن APPLICATION_VERIFIER_INVALID_ALLOCMEM 0x0601
#تعریف_کن APPLICATION_VERIFIER_INVALID_MAPVIEW 0x0602
#تعریف_کن APPLICATION_VERIFIER_PROBE_INVALID_آدرس 0x0603
#تعریف_کن APPLICATION_VERIFIER_PROBE_FREE_MEM 0x0604
#تعریف_کن APPLICATION_VERIFIER_PROBE_GUARD_صفحه 0x0605
#تعریف_کن APPLICATION_VERIFIER_PROBE_NULL 0x0606
#تعریف_کن APPLICATION_VERIFIER_PROBE_INVALID_شروع_OR_اندازه 0x0607
#تعریف_کن APPLICATION_VERIFIER_اندازه_انباشته_UNEXPECTED_EXCEPTION 0x0618

#تعریف_کن VERIFIER_STOP(کد_4,پیام_5,P1,S1,P2,S2,P3,S3,P4,S4) { RtlApplicationVerifierStop ((کد_4),(پیام_5),(ULONG_PTR)(P1),(S1),(ULONG_PTR)(P2),(S2),(ULONG_PTR)(P3),(S3),(ULONG_PTR)(P4),(S4)); }

    VOID NTAPI RtlApplicationVerifierStop(ULONG_PTR کد_4,PSTR پیام_6,ULONG_PTR Param1,PSTR Description1,ULONG_PTR Param2,PSTR Description2,ULONG_PTR Param3,PSTR Description3,ULONG_PTR Param4,PSTR Description4);

    تعريفنوع LONG (NTAPI *PVECTORED_EXCEPTION_HANDLER)(بنية EXCEPTION_اشارهگرها_2 *ExceptionInfo);
#تعریف_کن SEF_DACL_AUTO_INHERIT 0x01
#تعریف_کن SEF_SACL_AUTO_INHERIT 0x02
#تعریف_کن SEF_DEFAULT_DESCRIPTOR_FOR_OBJECT 0x04
#تعریف_کن SEF_AVOID_PRIVILEGE_CHECK 0x08
#تعریف_کن SEF_AVOID_OWNER_CHECK 0x10
#تعریف_کن SEF_DEFAULT_OWNER_FROM_والد 0x20
#تعریف_کن SEF_DEFAULT_گروه_FROM_والد 0x40

    تعريفنوع تعداد انباشته_INFORMATION_CLASS_2 {
      انباشته_Compatibility_Information
    } انباشته_INFORMATION_CLASS;

    NTSYSAPI DWORD NTAPI Rtl_مجموعه_انباشته_Information(PVOID انباشته_Handle,انباشته_INFORMATION_CLASS انباشته_Information_Class,PVOID انباشته_Information,اندازه_T انباشته_Information_درازی);
    NTSYSAPI DWORD NTAPI Rtl_Query_انباشته_Information(PVOID انباشته_Handle,انباشته_INFORMATION_CLASS انباشته_Information_Class,PVOID انباشته_Information,اندازه_T انباشته_Information_درازی,PSIZE_T Return_درازی);
    DWORD NTAPI Rtl_مضرب_Allocate_انباشته(PVOID انباشته_Handle,DWORD Flags,اندازه_T اندازه_3,DWORD شمار_3,PVOID *Array);
    DWORD NTAPI Rtl_مضرب_Free_انباشته(PVOID انباشته_Handle,DWORD Flags,DWORD شمار_3,PVOID *Array);

#تعریف_کن WT_EXECUTEDEFAULT 0x00000000
#تعریف_کن WT_EXECUTEINIOTHREAD 0x00000001
#تعریف_کن WT_EXECUTEINUITHREAD 0x00000002
#تعریف_کن WT_EXECUTEINWAITTHREAD 0x00000004
#تعریف_کن WT_EXECUTEONLYONCE 0x00000008
#تعریف_کن WT_EXECUTEINTIMERTHREAD 0x00000020
#تعریف_کن WT_EXECUTELONGFUNCTION 0x00000010
#تعریف_کن WT_EXECUTEINPERSISTENTIOTHREAD 0x00000040
#تعریف_کن WT_EXECUTEINPERSISTENTTHREAD 0x00000080
#تعریف_کن WT_TRANSFER_IMPERSONATION 0x00000100
#تعریف_کن WT_مجموعه_MAX_THREADPOOL_نخها(Flags,حد_2) ((Flags) |= (حد_2)<<16)
    تعريفنوع VOID (NTAPI *WAITORTIMERCALLBACKFUNC)(PVOID,BOOLEAN);
    تعريفنوع VOID (NTAPI *WORKERCALLBACKFUNC)(PVOID);
    تعريفنوع VOID (NTAPI *APC_CALLBACK_FUNCTION)(DWORD ,PVOID,PVOID);
    تعريفنوع
      VOID
      (NTAPI *PFLS_CALLBACK_FUNCTION)(PVOID lp_Fls_داده);
#تعریف_کن WT_EXECUTEINLONGTHREAD 0x00000010
#تعریف_کن WT_EXECUTEDELETEWAIT 0x00000008

    تعريفنوع تعداد _ACTIVATION_CONTEXT_INFO_CLASS {
      ActivationContextBasicInformation = 1,ActivationContextDetailedInformation = 2,Assembly_Detailed_Information_درون_Activation_Context = 3,File_Information_درون_Assembly_از_Assembly_درون_Activation_Context = 4,MaxActivationContextInfoClass,Assembly_Detailed_Information_درون_Activation_Contxt = 3,File_Information_درون_Assembly_از_Assembly_درون_Activation_Contxt = 4
    } ACTIVATION_CONTEXT_INFO_CLASS;

#تعریف_کن ACTIVATIONCONTEXTINFOCLASS ACTIVATION_CONTEXT_INFO_CLASS

    تعريفنوع بنية ACTIVATION_CONTEXT_QUERY_شاخص {
      DWORD ul_Assembly_شاخص;
      DWORD ul_File_شاخص_درون_Assembly;
    } ACTIVATION_CONTEXT_QUERY_شاخص_2,*PACTIVATION_CONTEXT_QUERY_شاخص;

    تعريفنوع ثابت بنية ACTIVATION_CONTEXT_QUERY_شاخص *PCACTIVATION_CONTEXT_QUERY_شاخص;

#تعریف_کن ACTIVATION_CONTEXT_مسیر_TYPE_NONE (1)
#تعریف_کن ACTIVATION_CONTEXT_مسیر_TYPE_WIN32_FILE (2)
#تعریف_کن ACTIVATION_CONTEXT_مسیر_TYPE_URL (3)
#تعریف_کن ACTIVATION_CONTEXT_مسیر_TYPE_ASSEMBLYREF (4)

    تعريفنوع بنية _ASSEMBLY_FILE_DETAILED_INFORMATION {
      DWORD ulFlags;
      DWORD ul_Filename_درازی;
      DWORD ul_مسیر_درازی;

      PCWSTR lpFileName;
      PCWSTR lp_File_مسیر;
    } ASSEMBLY_FILE_DETAILED_INFORMATION,*PASSEMBLY_FILE_DETAILED_INFORMATION;
    تعريفنوع ثابت ASSEMBLY_FILE_DETAILED_INFORMATION *PCASSEMBLY_FILE_DETAILED_INFORMATION;

#تعریف_کن _ASSEMBLY_DLL_REDIRECTION_DETAILED_INFORMATION _ASSEMBLY_FILE_DETAILED_INFORMATION
#تعریف_کن ASSEMBLY_DLL_REDIRECTION_DETAILED_INFORMATION ASSEMBLY_FILE_DETAILED_INFORMATION
#تعریف_کن PASSEMBLY_DLL_REDIRECTION_DETAILED_INFORMATION PASSEMBLY_FILE_DETAILED_INFORMATION
#تعریف_کن PCASSEMBLY_DLL_REDIRECTION_DETAILED_INFORMATION PCASSEMBLY_FILE_DETAILED_INFORMATION

    تعريفنوع بنية _ACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION {
      DWORD ulFlags;
      DWORD ul_Encoded_Assembly_عنصر_خنثی_درازی;
      DWORD ul_Manifest_مسیر_Type;
      DWORD ul_Manifest_مسیر_درازی;
      LARGE_INTEGER li_Manifest_آخرین_Write_زمان;
      DWORD ul_Policy_مسیر_Type;
      DWORD ul_Policy_مسیر_درازی;
      LARGE_INTEGER li_Policy_آخرین_Write_زمان;
      DWORD ul_Metadata_Satellite_Roster_شاخص;
      DWORD ul_Manifest_نسخه_Major;
      DWORD ul_Manifest_نسخه_Minor;
      DWORD ul_Policy_نسخه_Major;
      DWORD ul_Policy_نسخه_Minor;
      DWORD ul_Assembly_Directory_Name_درازی;
      PCWSTR lp_Assembly_Encoded_Assembly_عنصر_خنثی;
      PCWSTR lp_Assembly_Manifest_مسیر;
      PCWSTR lp_Assembly_Policy_مسیر;
      PCWSTR lpAssemblyDirectoryName;
      DWORD ul_File_شمار;
    } ACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION,*PACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION;

    تعريفنوع ثابت بنية _ACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION *PCACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION;

    تعريفنوع بنية _ACTIVATION_CONTEXT_DETAILED_INFORMATION {
      DWORD dwFlags;
      DWORD ul_Format_نسخه;
      DWORD ul_Assembly_شمار;
      DWORD ul_ریشه_Manifest_مسیر_Type;
      DWORD ul_ریشه_Manifest_مسیر_Chars;
      DWORD ul_ریشه_Configuration_مسیر_Type;
      DWORD ul_ریشه_Configuration_مسیر_Chars;
      DWORD ul_App_Dir_مسیر_Type;
      DWORD ul_App_Dir_مسیر_Chars;
      PCWSTR lp_ریشه_Manifest_مسیر;
      PCWSTR lp_ریشه_Configuration_مسیر;
      PCWSTR lp_App_Dir_مسیر;
    } ACTIVATION_CONTEXT_DETAILED_INFORMATION,*PACTIVATION_CONTEXT_DETAILED_INFORMATION;

    تعريفنوع ثابت بنية _ACTIVATION_CONTEXT_DETAILED_INFORMATION *PCACTIVATION_CONTEXT_DETAILED_INFORMATION;

#تعریف_کن DLL_PROCESS_ATTACH 1
#تعریف_کن DLL_THREAD_ATTACH 2
#تعریف_کن DLL_THREAD_DETACH 3
#تعریف_کن DLL_PROCESS_DETACH 0
#تعریف_کن DLL_PROCESS_VERIFIER 4

#تعریف_کن EVENTLOG_SEQUENTIAL_READ 0x0001
#تعریف_کن EVENTLOG_SEEK_READ 0x0002
#تعریف_کن EVENTLOG_FORWARDS_READ 0x0004
#تعریف_کن EVENTLOG_BACKWARDS_READ 0x0008

#تعریف_کن EVENTLOG_SUCCESS 0x0000
#تعریف_کن EVENTLOG_ERROR_TYPE 0x0001
#تعریف_کن EVENTLOG_WARNING_TYPE 0x0002
#تعریف_کن EVENTLOG_INFORMATION_TYPE 0x0004
#تعریف_کن EVENTLOG_AUDIT_SUCCESS 0x0008
#تعریف_کن EVENTLOG_AUDIT_FAILURE 0x0010

#تعریف_کن EVENTLOG_شروع_PAIRED_EVENT 0x0001
#تعریف_کن EVENTLOG_انتها_PAIRED_EVENT 0x0002
#تعریف_کن EVENTLOG_انتها_ALL_PAIRED_EVENTS 0x0004
#تعریف_کن EVENTLOG_PAIRED_EVENT_فعال 0x0008
#تعریف_کن EVENTLOG_PAIRED_EVENT_INACTIVE 0x0010

    تعريفنوع بنية _EVENTLOGRECORD {
      DWORD درازی_2;
      DWORD Reserved;
      DWORD رکورد_عدد;
      DWORD زمان_Generated;
      DWORD زمان_Written;
      DWORD EventID;
      کلمه_3 EventType;
      کلمه_3 رقم_رشتهها;
      کلمه_3 EventCategory;
      کلمه_3 ReservedFlags;
      DWORD Closing_رکورد_عدد;
      DWORD String_جابه_جایی;
      DWORD User_Sid_درازی;
      DWORD User_Sid_جابه_جایی;
      DWORD داده_درازی;
      DWORD داده_جابه_جایی_2;
    } EVENTLOGRECORD,*PEVENTLOGRECORD;

#تعریف_کن MAXLOGICALLOGNAMESIZE 256

    تعريفنوع بنية _EVENTSFORLOGFILE{
      DWORD ul_اندازه;
      WCHAR szLogicalLogFile[MAXLOGICALLOGNAMESIZE];
      DWORD ul_رقم_رکوردها;
      EVENTLOGRECORD p_Event_Log_رکوردها[];
    } EVENTSFORLOGFILE,*PEVENTSFORLOGFILE;

    تعريفنوع بنية _PACKEDEVENTINFO{
      DWORD ul_اندازه;
      DWORD ul_رقم_Events_For_Log_File;
      DWORD ulOffsets[];
    } PACKEDEVENTINFO,*PPACKEDEVENTINFO;

#تعریف_کن کلید_QUERY_مقدار (0x0001)
#تعریف_کن کلید_مجموعه_مقدار (0x0002)
#تعریف_کن کلید_CREATE_SUB_کلید (0x0004)
#تعریف_کن کلید_ENUMERATE_SUB_کلیدها (0x0008)
#تعریف_کن کلید_NOTIFY (0x0010)
#تعریف_کن کلید_CREATE_LINK (0x0020)
#تعریف_کن کلید_WOW64_32_کلید (0x0200)
#تعریف_کن کلید_WOW64_64_کلید (0x0100)
#تعریف_کن کلید_WOW64_RES (0x0300)

#تعریف_کن کلید_READ ((STANDARD_RIGHTS_READ | کلید_QUERY_مقدار | کلید_ENUMERATE_SUB_کلیدها | کلید_NOTIFY) & (~SYNCHRONIZE))
#تعریف_کن کلید_WRITE ((STANDARD_RIGHTS_WRITE | کلید_مجموعه_مقدار | کلید_CREATE_SUB_کلید) & (~SYNCHRONIZE))
#تعریف_کن کلید_EXECUTE ((کلید_READ) & (~SYNCHRONIZE))
#تعریف_کن کلید_ALL_ACCESS ((STANDARD_RIGHTS_ALL | کلید_QUERY_مقدار | کلید_مجموعه_مقدار | کلید_CREATE_SUB_کلید | کلید_ENUMERATE_SUB_کلیدها | کلید_NOTIFY | کلید_CREATE_LINK) & (~SYNCHRONIZE))
#تعریف_کن REG_OPTION_RESERVED (0x00000000L)

#تعریف_کن REG_OPTION_NON_VOLATILE (0x00000000L)
#تعریف_کن REG_OPTION_VOLATILE (0x00000001L)
#تعریف_کن REG_OPTION_CREATE_LINK (0x00000002L)
#تعریف_کن REG_OPTION_BACKUP_RESTORE (0x00000004L)
#تعریف_کن REG_OPTION_OPEN_LINK (0x00000008L)
#تعریف_کن REG_LEGAL_OPTION (REG_OPTION_RESERVED | REG_OPTION_NON_VOLATILE | REG_OPTION_VOLATILE | REG_OPTION_CREATE_LINK | REG_OPTION_BACKUP_RESTORE | REG_OPTION_OPEN_LINK)
#تعریف_کن REG_CREATED_NEW_کلید (0x00000001L)
#تعریف_کن REG_OPENED_EXISTING_کلید (0x00000002L)
#تعریف_کن REG_STANDARD_FORMAT 1
#تعریف_کن REG_LATEST_FORMAT 2
#تعریف_کن REG_NO_COMPRESSION 4
#تعریف_کن REG_کامل_HIVE_VOLATILE (0x00000001L)
#تعریف_کن REG_REFRESH_HIVE (0x00000002L)
#تعریف_کن REG_NO_LAZY_FLUSH (0x00000004L)
#تعریف_کن REG_FORCE_RESTORE (0x00000008L)
#تعریف_کن REG_FORCE_UNLOAD 1

#تعریف_کن REG_NOTIFY_CHANGE_NAME (0x00000001L)
#تعریف_کن REG_NOTIFY_CHANGE_صفات (0x00000002L)
#تعریف_کن REG_NOTIFY_CHANGE_آخرین_مجموعه (0x00000004L)
#تعریف_کن REG_NOTIFY_CHANGE_SECURITY (0x00000008L)

#تعریف_کن REG_LEGAL_CHANGE_FILTER (REG_NOTIFY_CHANGE_NAME | REG_NOTIFY_CHANGE_صفات | REG_NOTIFY_CHANGE_آخرین_مجموعه | REG_NOTIFY_CHANGE_SECURITY)

#تعریف_کن REG_NONE (0)
#تعریف_کن REG_SZ (1)
#تعریف_کن REG_EXPAND_SZ (2)

#تعریف_کن REG_دودویی (3)
#تعریف_کن REG_DWORD (4)
#تعریف_کن REG_DWORD_LITTLE_ENDIAN (4)
#تعریف_کن REG_DWORD_BIG_ENDIAN (5)
#تعریف_کن REG_LINK (6)
#تعریف_کن REG_MULTI_SZ (7)
#تعریف_کن REG_RESOURCE_LIST (8)
#تعریف_کن REG_پر_RESOURCE_DESCRIPTOR (9)
#تعریف_کن REG_RESOURCE_REQUIREMENTS_LIST (10)
#تعریف_کن REG_QWORD (11)
#تعریف_کن REG_QWORD_LITTLE_ENDIAN (11)

#تعریف_کن SERVICE_KERNEL_DRIVER 0x00000001
#تعریف_کن SERVICE_FILE_SYSTEM_DRIVER 0x00000002
#تعریف_کن SERVICE_ADAPTER 0x00000004
#تعریف_کن SERVICE_RECOGNIZER_DRIVER 0x00000008

#تعریف_کن SERVICE_DRIVER (SERVICE_KERNEL_DRIVER | SERVICE_FILE_SYSTEM_DRIVER | SERVICE_RECOGNIZER_DRIVER)

#تعریف_کن SERVICE_WIN32_OWN_PROCESS 0x00000010
#تعریف_کن SERVICE_WIN32_SHARE_PROCESS 0x00000020
#تعریف_کن SERVICE_WIN32 (SERVICE_WIN32_OWN_PROCESS | SERVICE_WIN32_SHARE_PROCESS)

#تعریف_کن SERVICE_INTERACTIVE_PROCESS 0x00000100

#تعریف_کن SERVICE_TYPE_ALL (SERVICE_WIN32 | SERVICE_ADAPTER | SERVICE_DRIVER | SERVICE_INTERACTIVE_PROCESS)

#تعریف_کن SERVICE_BOOT_شروع 0x00000000
#تعریف_کن SERVICE_SYSTEM_شروع 0x00000001
#تعریف_کن SERVICE_AUTO_شروع 0x00000002
#تعریف_کن SERVICE_DEMAND_شروع 0x00000003
#تعریف_کن SERVICE_DISABLED 0x00000004

#تعریف_کن SERVICE_ERROR_IGNORE 0x00000000
#تعریف_کن SERVICE_ERROR_نرمال 0x00000001
#تعریف_کن SERVICE_ERROR_SEVERE 0x00000002
#تعریف_کن SERVICE_ERROR_CRITICAL 0x00000003

    تعريفنوع تعداد CM_SERVICE_گره_TYPE {
      DriverType = SERVICE_KERNEL_DRIVER,FileSystemType = SERVICE_FILE_SYSTEM_DRIVER,Win32ServiceOwnProcess = SERVICE_WIN32_OWN_PROCESS,
      Win32ServiceShareProcess = SERVICE_WIN32_SHARE_PROCESS,AdapterType = SERVICE_ADAPTER,RecognizerType = SERVICE_RECOGNIZER_DRIVER
    } SERVICE_گره_TYPE;

    تعريفنوع تعداد CM_SERVICE_بارگیری_TYPE {
      Boot_بارگیری = SERVICE_BOOT_شروع,System_بارگیری = SERVICE_SYSTEM_شروع,Auto_بارگیری = SERVICE_AUTO_شروع,Demand_بارگیری = SERVICE_DEMAND_شروع,
      Disable_بارگیری = SERVICE_DISABLED
    } SERVICE_بارگیری_TYPE;

    تعريفنوع تعداد _CM_ERROR_CONTROL_TYPE {
      IgnoreError = SERVICE_ERROR_IGNORE,نرمال_Error = SERVICE_ERROR_نرمال,SevereError = SERVICE_ERROR_SEVERE,CriticalError = SERVICE_ERROR_CRITICAL
    } SERVICE_ERROR_TYPE;

#تعریف_کن نوار_ERASE_SHORT 0L
#تعریف_کن نوار_ERASE_LONG 1L

    تعريفنوع بنية نوار_ERASE {
      DWORD Type;
      BOOLEAN فوری_2;
    } نوار_ERASE_2,*PTAPE_ERASE;

#تعریف_کن نوار_بارگیری 0L
#تعریف_کن نوار_UNLOAD 1L
#تعریف_کن نوار_TENSION 2L
#تعریف_کن نوار_قفل 3L
#تعریف_کن نوار_UNLOCK 4L
#تعریف_کن نوار_FORMAT 5L

    تعريفنوع بنية نوار_PREPARE {
      DWORD Operation;
      BOOLEAN فوری_2;
    } نوار_PREPARE_2,*PTAPE_PREPARE;

#تعریف_کن نوار_SETMARKS 0L
#تعریف_کن نوار_FILEMARKS 1L
#تعریف_کن نوار_SHORT_FILEMARKS 2L
#تعریف_کن نوار_LONG_FILEMARKS 3L

    تعريفنوع بنية نوار_WRITE_MARKS {
      DWORD Type;
      DWORD شمار_3;
      BOOLEAN فوری_2;
    } نوار_WRITE_MARKS_2,*PTAPE_WRITE_MARKS;

#تعریف_کن نوار_ABSOLUTE_POSITION 0L
#تعریف_کن نوار_LOGICAL_POSITION 1L
#تعریف_کن نوار_PSEUDO_LOGICAL_POSITION 2L

    تعريفنوع بنية نوار_GET_POSITION {
      DWORD Type;
      DWORD افراز_2;
      LARGE_INTEGER جابه_جایی_3;
    } نوار_GET_POSITION_2,*PTAPE_GET_POSITION;

#تعریف_کن نوار_REWIND 0L
#تعریف_کن نوار_ABSOLUTE_بلوک 1L
#تعریف_کن نوار_LOGICAL_بلوک 2L
#تعریف_کن نوار_PSEUDO_LOGICAL_بلوک 3L
#تعریف_کن نوار_SPACE_انتها_از_داده 4L
#تعریف_کن نوار_SPACE_RELATIVE_بلوکها 5L
#تعریف_کن نوار_SPACE_FILEMARKS 6L
#تعریف_کن نوار_SPACE_SEQUENTIAL_FMKS 7L
#تعریف_کن نوار_SPACE_SETMARKS 8L
#تعریف_کن نوار_SPACE_SEQUENTIAL_SMKS 9L

    تعريفنوع بنية نوار_مجموعه_POSITION {
      DWORD روش_2;
      DWORD افراز_2;
      LARGE_INTEGER جابه_جایی_3;
      BOOLEAN فوری_2;
    } نوار_مجموعه_POSITION_2,*PTAPE_مجموعه_POSITION;

#تعریف_کن نوار_DRIVE_FIXED 0x00000001
#تعریف_کن نوار_DRIVE_SELECT 0x00000002
#تعریف_کن نوار_DRIVE_INITIATOR 0x00000004

#تعریف_کن نوار_DRIVE_ERASE_SHORT 0x00000010
#تعریف_کن نوار_DRIVE_ERASE_LONG 0x00000020
#تعریف_کن نوار_DRIVE_ERASE_BOP_ONLY 0x00000040
#تعریف_کن نوار_DRIVE_ERASE_فوری 0x00000080

#تعریف_کن نوار_DRIVE_نوار_ظرفیت 0x00000100
#تعریف_کن نوار_DRIVE_نوار_مانده 0x00000200
#تعریف_کن نوار_DRIVE_FIXED_بلوک 0x00000400
#تعریف_کن نوار_DRIVE_VARIABLE_بلوک 0x00000800

#تعریف_کن نوار_DRIVE_WRITE_PROTECT 0x00001000
#تعریف_کن نوار_DRIVE_EOT_WZ_اندازه 0x00002000

#تعریف_کن نوار_DRIVE_ECC 0x00010000
#تعریف_کن نوار_DRIVE_COMPRESSION 0x00020000
#تعریف_کن نوار_DRIVE_PADDING 0x00040000
#تعریف_کن نوار_DRIVE_REPORT_SMKS 0x00080000

#تعریف_کن نوار_DRIVE_GET_ABSOLUTE_BLK 0x00100000
#تعریف_کن نوار_DRIVE_GET_LOGICAL_BLK 0x00200000
#تعریف_کن نوار_DRIVE_مجموعه_EOT_WZ_اندازه 0x00400000

#تعریف_کن نوار_DRIVE_EJECT_MEDIA 0x01000000
#تعریف_کن نوار_DRIVE_CLEAN_درخواستها 0x02000000
#تعریف_کن نوار_DRIVE_مجموعه_CMP_BOP_ONLY 0x04000000

#تعریف_کن نوار_DRIVE_RESERVED_بیت 0x80000000

#تعریف_کن نوار_DRIVE_بارگیری_UNLOAD 0x80000001
#تعریف_کن نوار_DRIVE_TENSION 0x80000002
#تعریف_کن نوار_DRIVE_قفل_UNLOCK 0x80000004
#تعریف_کن نوار_DRIVE_REWIND_فوری 0x80000008

#تعریف_کن نوار_DRIVE_مجموعه_بلوک_اندازه 0x80000010
#تعریف_کن نوار_DRIVE_بارگیری_UNLD_IMMED 0x80000020
#تعریف_کن نوار_DRIVE_TENSION_IMMED 0x80000040
#تعریف_کن نوار_DRIVE_قفل_UNLK_IMMED 0x80000080

#تعریف_کن نوار_DRIVE_مجموعه_ECC 0x80000100
#تعریف_کن نوار_DRIVE_مجموعه_COMPRESSION 0x80000200
#تعریف_کن نوار_DRIVE_مجموعه_PADDING 0x80000400
#تعریف_کن نوار_DRIVE_مجموعه_REPORT_SMKS 0x80000800

#تعریف_کن نوار_DRIVE_ABSOLUTE_BLK 0x80001000
#تعریف_کن نوار_DRIVE_ABS_BLK_IMMED 0x80002000
#تعریف_کن نوار_DRIVE_LOGICAL_BLK 0x80004000
#تعریف_کن نوار_DRIVE_LOG_BLK_IMMED 0x80008000

#تعریف_کن نوار_DRIVE_انتها_از_داده 0x80010000
#تعریف_کن نوار_DRIVE_RELATIVE_BLKS 0x80020000
#تعریف_کن نوار_DRIVE_FILEMARKS 0x80040000
#تعریف_کن نوار_DRIVE_SEQUENTIAL_FMKS 0x80080000

#تعریف_کن نوار_DRIVE_SETMARKS 0x80100000
#تعریف_کن نوار_DRIVE_SEQUENTIAL_SMKS 0x80200000
#تعریف_کن نوار_DRIVE_معکوس_POSITION 0x80400000
#تعریف_کن نوار_DRIVE_SPACE_فوری 0x80800000

#تعریف_کن نوار_DRIVE_WRITE_SETMARKS 0x81000000
#تعریف_کن نوار_DRIVE_WRITE_FILEMARKS 0x82000000
#تعریف_کن نوار_DRIVE_WRITE_SHORT_FMKS 0x84000000
#تعریف_کن نوار_DRIVE_WRITE_LONG_FMKS 0x88000000

#تعریف_کن نوار_DRIVE_WRITE_MARK_IMMED 0x90000000
#تعریف_کن نوار_DRIVE_FORMAT 0xA0000000
#تعریف_کن نوار_DRIVE_FORMAT_فوری 0xC0000000
#تعریف_کن نوار_DRIVE_بالا_FEATURES 0x80000000

    تعريفنوع بنية نوار_GET_DRIVE_PARAMETERS {
      BOOLEAN ECC;
      BOOLEAN Compression;
      BOOLEAN داده_Padding;
      BOOLEAN ReportSetmarks;
      DWORD Default_بلوک_اندازه;
      DWORD بیشینه_بلوک_اندازه;
      DWORD Minimum_بلوک_اندازه;
      DWORD بیشینه_افراز_شمار;
      DWORD Features_کم;
      DWORD Features_بالا;
      DWORD EOTWarning_Zone_اندازه;
    } نوار_GET_DRIVE_PARAMETERS_2,*PTAPE_GET_DRIVE_PARAMETERS;

    تعريفنوع بنية نوار_مجموعه_DRIVE_PARAMETERS {
      BOOLEAN ECC;
      BOOLEAN Compression;
      BOOLEAN داده_Padding;
      BOOLEAN ReportSetmarks;
      DWORD EOTWarning_Zone_اندازه;
    } نوار_مجموعه_DRIVE_PARAMETERS_2,*PTAPE_مجموعه_DRIVE_PARAMETERS;

    تعريفنوع بنية نوار_GET_MEDIA_PARAMETERS {
      LARGE_INTEGER ظرفیت;
      LARGE_INTEGER مانده;
      DWORD بلوک_اندازه;
      DWORD افراز_شمار;
      BOOLEAN WriteProtected;
    } نوار_GET_MEDIA_PARAMETERS_2,*PTAPE_GET_MEDIA_PARAMETERS;

    تعريفنوع بنية نوار_مجموعه_MEDIA_PARAMETERS {
      DWORD بلوک_اندازه;
    } نوار_مجموعه_MEDIA_PARAMETERS_2,*PTAPE_مجموعه_MEDIA_PARAMETERS;

#تعریف_کن نوار_FIXED_PARTITIONS 0L
#تعریف_کن نوار_SELECT_PARTITIONS 1L
#تعریف_کن نوار_INITIATOR_PARTITIONS 2L

    تعريفنوع بنية نوار_CREATE_افراز {
      DWORD روش_2;
      DWORD شمار_3;
      DWORD اندازه_3;
    } نوار_CREATE_افراز_2,*PTAPE_CREATE_افراز;

#تعریف_کن نوار_QUERY_DRIVE_PARAMETERS 0L
#تعریف_کن نوار_QUERY_MEDIA_ظرفیت 1L
#تعریف_کن نوار_CHECK_FOR_DRIVE_PROBLEM 2L
#تعریف_کن نوار_QUERY_IO_ERROR_داده 3L
#تعریف_کن نوار_QUERY_DEVICE_ERROR_داده 4L

    تعريفنوع بنية نوار_WMI_OPERATIONS {
      DWORD روش_2;
      DWORD داده_میانگیر_اندازه;
      PVOID داده_میانگیر;
    } نوار_WMI_OPERATIONS_2,*PTAPE_WMI_OPERATIONS;

    تعريفنوع تعداد نوار_DRIVE_PROBLEM_TYPE {
      نوار_Drive_Problem_None,نوار_Drive_Read_Write_Warning,نوار_Drive_Read_Write_Error,نوار_Drive_Read_Warning,نوار_Drive_Write_Warning,نوار_Drive_Read_Error,نوار_Drive_Write_Error,نوار_Drive_Hardware_Error,نوار_Drive_Unsupported_Media,نوار_Drive_Scsi_Connection_Error,نوار_Drive_Timeto_Clean,نوار_Drive_Clean_Drive_Now,نوار_Drive_Media_Life_Expired,نوار_Drive_Snapped_نوار
    } نوار_DRIVE_PROBLEM_TYPE_2;

#إذا defined(__x86_64)
    __CRT_INLINE بنية _TEB *NtCurrentTeb(VOID) { أرجع (بنية _TEB *)__readgsqword(فیلد_جابه_جایی(NT_TIB,Self)); }
    __CRT_INLINE PVOID GetCurrentFiber(VOID) { أرجع(PVOID)__readgsqword(فیلد_جابه_جایی(NT_TIB,Fiber_داده)); }
    __CRT_INLINE PVOID Get_Fiber_داده(VOID) {
      أرجع *(PVOID *)GetCurrentFiber();
    }
#پایان_اگر

#إذا(defined(_X86_) && !defined(__x86_64))
#تعریف_کن PcTeb 0x18
    __CRT_INLINE بنية _TEB *NtCurrentTeb(فراغ) {
      بنية _TEB *ret;
      __asm__ متطاير ("movl	%%fs:0x18,%0"
	: "=r" (ret));
      أرجع ret;
    }
#پایان_اگر

#تعریف_کن ACTIVATION_CONTEXT_SECTION_ASSEMBLY_INFORMATION (1)
#تعریف_کن ACTIVATION_CONTEXT_SECTION_DLL_REDIRECTION (2)
#تعریف_کن ACTIVATION_CONTEXT_SECTION_پنجره_CLASS_REDIRECTION (3)
#تعریف_کن ACTIVATION_CONTEXT_SECTION_COM_SERVER_REDIRECTION (4)
#تعریف_کن ACTIVATION_CONTEXT_SECTION_COM_INTERFACE_REDIRECTION (5)
#تعریف_کن ACTIVATION_CONTEXT_SECTION_COM_TYPE_LIBRARY_REDIRECTION (6)
#تعریف_کن ACTIVATION_CONTEXT_SECTION_COM_PROGID_REDIRECTION (7)
#تعریف_کن ACTIVATION_CONTEXT_SECTION_GLOBAL_OBJECT_RENAME_جدول (8)
#تعریف_کن ACTIVATION_CONTEXT_SECTION_CLR_SURROGATES (9)
#تعریف_کن ACTIVATION_CONTEXT_SECTION_APPLICATION_SETTINGS (10)

#اگر_تعریف_شده __cplusplus
  }
#پایان_اگر
#پایان_اگر
