/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جيڪڏهن_وصف_نه_ٿيل _WINNT_
#وصف_ڪريو _WINNT_

#جيڪڏهن_وصف_ٿيل __cplusplus
خارجي "C" {
#جيڪڏهن_پورو

#ضمن <ctype.h>
#وصف_ڪريو ANYSIZE_ARRAY 1

//gr #include <specstrings.h>

#وصف_ڪريو RESTRICTED_اشارو

#جيڪڏهن_وصف_نه_ٿيل __CRT_UNALIGNED
#وصف_ڪريو __CRT_UNALIGNED
#جيڪڏهن_پورو

#إذا defined(__ia64__) || defined(__x86_64) || defined(__aarch64__)
#وصف_ڪريو UNALIGNED __CRT_UNALIGNED
#جيڪڏهن_وصف_ٿيل _WIN64
#وصف_ڪريو UNALIGNED64 __CRT_UNALIGNED
#وإلا
#وصف_ڪريو UNALIGNED64
#جيڪڏهن_پورو
#وإلا
#وصف_ڪريو UNALIGNED
#وصف_ڪريو UNALIGNED64
#جيڪڏهن_پورو

#إذا !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && (defined(_X86_) && !defined(__x86_64))
#وصف_ڪريو I_X86_
#جيڪڏهن_پورو

#إذا !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && defined(__x86_64)
#وصف_ڪريو _AMD64_
#جيڪڏهن_پورو

#إذا !defined(I_X86_) && !(defined(_X86_) && !defined(__x86_64)) && !defined(_AMD64_) && defined(__ia64__)
#إذا !defined(_IA64_)
#وصف_ڪريو _IA64_
#جيڪڏهن_پورو
#جيڪڏهن_پورو


#جيڪڏهن_وصف_ٿيل _WIN64
#وصف_ڪريو MAX_NATURAL_ALIGNMENT حجم(ULONGLONG)
#وصف_ڪريو يادگيري_ورهاست_ALIGNMENT 16
#وإلا
#وصف_ڪريو MAX_NATURAL_ALIGNMENT حجم(DWORD)
#وصف_ڪريو يادگيري_ورهاست_ALIGNMENT 8
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل __cplusplus
#وصف_ڪريو TYPE_ALIGNMENT(t) __alignof__ (t)
#وإلا
#وصف_ڪريو TYPE_ALIGNMENT(t) ميدان_وٿي(بنية { حرف x; t test; },test)
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل _WIN64
#جيڪڏهن_وصف_ٿيل _AMD64_
#وصف_ڪريو PROBE_ALIGNMENT(_s) TYPE_ALIGNMENT(DWORD)
#وإلاإذا defined(_IA64_) || defined(_ARM64_)
#وصف_ڪريو PROBE_ALIGNMENT(_s) (TYPE_ALIGNMENT(_s) > TYPE_ALIGNMENT(DWORD) ? TYPE_ALIGNMENT(_s) : TYPE_ALIGNMENT(DWORD))
#وإلا
#غلطي No هدف_2 Architecture
#جيڪڏهن_پورو
#وصف_ڪريو PROBE_ALIGNMENT32(_s) TYPE_ALIGNMENT(DWORD)
#وإلا
#وصف_ڪريو PROBE_ALIGNMENT(_s) TYPE_ALIGNMENT(DWORD)
#جيڪڏهن_پورو

#وصف_ڪريو C_ASSERT(e) تعريفنوع حرف __C_ASSERT__[(e)?1:-1]

#ضمن <basetsd.h>

#إذا defined(_X86_) || defined(__ia64__) || defined(__x86_64) || defined(__aarch64__)
#وصف_ڪريو DECLSPEC_IMPORT __declspec(dllimport)
#وإلا
#وصف_ڪريو DECLSPEC_IMPORT
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل DECLSPEC_NORETURN
#وصف_ڪريو DECLSPEC_NORETURN __declspec(noreturn)
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل DECLSPEC_ALIGN
#وصف_ڪريو DECLSPEC_ALIGN(x) __attribute__ ((aligned(x)))
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل SYSTEM_CACHE_ALIGNMENT_سائيز
#إذا defined(_AMD64_) || defined(I_X86_)
#وصف_ڪريو SYSTEM_CACHE_ALIGNMENT_سائيز 64
#وإلا
#وصف_ڪريو SYSTEM_CACHE_ALIGNMENT_سائيز 128
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل DECLSPEC_CACHEALIGN
#وصف_ڪريو DECLSPEC_CACHEALIGN DECLSPEC_ALIGN(SYSTEM_CACHE_ALIGNMENT_سائيز)
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل DECLSPEC_UUID
#وصف_ڪريو DECLSPEC_UUID(x)
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل DECLSPEC_NOVTABLE
#وصف_ڪريو DECLSPEC_NOVTABLE
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل DECLSPEC_SELECTANY
#وصف_ڪريو DECLSPEC_SELECTANY __declspec(selectany)
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل NOP_FUNCTION
#وصف_ڪريو NOP_FUNCTION (فراغ)0
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل DECLSPEC_NOINLINE
#وصف_ڪريو DECLSPEC_NOINLINE
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل FORCEINLINE
#وصف_ڪريو FORCEINLINE ساكن __inline__
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل DECLSPEC_DEPRECATED
#وصف_ڪريو DECLSPEC_DEPRECATED __declspec(deprecated)
#وصف_ڪريو DEPRECATE_SUPPORTED
#جيڪڏهن_پورو

#وصف_ڪريو DECLSPEC_DEPRECATED_DDK
#وصف_ڪريو PRAGMA_DEPRECATED_DDK 0

  تعريفنوع فراغ *PVOID;
  تعريفنوع فراغ *PVOID64;

#وصف_ڪريو NTAPI __stdcall
#وصف_ڪريو NTSYSAPI DECLSPEC_IMPORT
#وصف_ڪريو NTSYSCALLAPI DECLSPEC_IMPORT

#جيڪڏهن_وصف_نه_ٿيل VOID
#وصف_ڪريو VOID فراغ
  تعريفنوع حرف CHAR;
  تعريفنوع ننڍو SHORT;
  تعريفنوع ڊگهو LONG;
#جيڪڏهن_پورو

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

#جيڪڏهن_وصف_ٿيل UNICODE
#جيڪڏهن_وصف_نه_ٿيل _TCHAR_DEFINED
#وصف_ڪريو _TCHAR_DEFINED
  تعريفنوع WCHAR TCHAR,*PTCHAR;
  تعريفنوع WCHAR TBYTE ,*PTBYTE;
#جيڪڏهن_پورو

  تعريفنوع LPWSTR LPTCH,PTCH;
  تعريفنوع LPWSTR PTSTR,LPTSTR;
  تعريفنوع LPCWSTR PCTSTR,LPCTSTR;
  تعريفنوع LPUWSTR PUTSTR,LPUTSTR;
  تعريفنوع LPCUWSTR PCUTSTR,LPCUTSTR;
  تعريفنوع LPWSTR LP;
#وصف_ڪريو __TEXT(quote) L##quote
#وإلا
#جيڪڏهن_وصف_نه_ٿيل _TCHAR_DEFINED
#وصف_ڪريو _TCHAR_DEFINED
  تعريفنوع حرف TCHAR,*PTCHAR;
  تعريفنوع بنانشان حرف TBYTE ,*PTBYTE;
#جيڪڏهن_پورو

  تعريفنوع LPSTR LPTCH,PTCH;
  تعريفنوع LPSTR PTSTR,LPTSTR,PUTSTR,LPUTSTR;
  تعريفنوع LPCSTR PCTSTR,LPCTSTR,PCUTSTR,LPCUTSTR;
#وصف_ڪريو __TEXT(quote) quote
#جيڪڏهن_پورو

#وصف_ڪريو متن_3(quote) __TEXT(quote)

  تعريفنوع SHORT *PSHORT;
  تعريفنوع LONG *PLONG;

  تعريفنوع فراغ *HANDLE;
#وصف_ڪريو DECLARE_HANDLE(name) بنية name##__ { صحيح اڻ_استعمال_ٿيل; }; تعريفنوع بنية name##__ *name
  تعريفنوع HANDLE *PHANDLE;

  تعريفنوع BYTE FCHAR;
  تعريفنوع لفظ_3 FSHORT;
  تعريفنوع DWORD FLONG;

#جيڪڏهن_وصف_نه_ٿيل _HRESULT_DEFINED
#وصف_ڪريو _HRESULT_DEFINED
  تعريفنوع LONG HRESULT;
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل __cplusplus
#وصف_ڪريو EXTERN_C خارجي "C"
#وإلا
#وصف_ڪريو EXTERN_C خارجي
#جيڪڏهن_پورو

#وصف_ڪريو STDMETHODCALLTYPE WINAPI
#وصف_ڪريو STDMETHODVCALLTYPE __cdecl
#وصف_ڪريو STDAPICALLTYPE WINAPI
#وصف_ڪريو STDAPIVCALLTYPE __cdecl
#وصف_ڪريو STDAPI EXTERN_C HRESULT WINAPI
#وصف_ڪريو STDAPI_(type) EXTERN_C type WINAPI
#وصف_ڪريو STDMETHODIMP HRESULT WINAPI
#وصف_ڪريو STDMETHODIMP_(type) type WINAPI
#وصف_ڪريو STDAPIV EXTERN_C HRESULT STDAPIVCALLTYPE
#وصف_ڪريو STDAPIV_(type) EXTERN_C type STDAPIVCALLTYPE
#وصف_ڪريو STDMETHODIMPV HRESULT STDMETHODVCALLTYPE
#وصف_ڪريو STDMETHODIMPV_(type) type STDMETHODVCALLTYPE

  تعريفنوع حرف CCHAR;
#جيڪڏهن_وصف_نه_ٿيل _LCID_DEFINED
#وصف_ڪريو _LCID_DEFINED
تعريفنوع DWORD LCID;
#جيڪڏهن_پورو
  تعريفنوع PDWORD PLCID;
#جيڪڏهن_وصف_نه_ٿيل _LANGID_DEFINED
#وصف_ڪريو _LANGID_DEFINED
  تعريفنوع لفظ_3 LANGID;
#جيڪڏهن_پورو
#وصف_ڪريو APPLICATION_ERROR_نقاب 0x20000000
#وصف_ڪريو ERROR_SEVERITY_SUCCESS 0x00000000
#وصف_ڪريو ERROR_SEVERITY_INFORMATIONAL 0x40000000
#وصف_ڪريو ERROR_SEVERITY_WARNING 0x80000000
#وصف_ڪريو ERROR_SEVERITY_ERROR 0xC0000000

#جيڪڏهن_وصف_ٿيل __ia64__
  __declspec(align(16))
#جيڪڏهن_پورو
    تعريفنوع بنية _FLOAT128 {
      __int64 هيٺيون_Part;
      __int64 مٿاهون_Part;
  } FLOAT128;

  تعريفنوع FLOAT128 *PFLOAT128;

#وصف_ڪريو _ULONGLONG_
#إذا((!(defined(_X86_) && !defined(__x86_64)) || (defined(INTEGRAL_MAX_بٽ) && INTEGRAL_MAX_بٽ >= 64)))
  تعريفنوع __int64 LONGLONG;
  تعريفنوع بنانشان __int64 ULONGLONG;

#وصف_ڪريو MAXLONGLONG (0x7fffffffffffffff)
#وإلا

  تعريفنوع مزدوج LONGLONG;
  تعريفنوع مزدوج ULONGLONG;
#جيڪڏهن_پورو

  تعريفنوع LONGLONG *PLONGLONG;
  تعريفنوع ULONGLONG *PULONGLONG;

  تعريفنوع LONGLONG USN;

  تعريفنوع اتحاد _LARGE_INTEGER {
    بنية {
      DWORD هيٺيون_Part;
      LONG مٿاهون_Part;
    };
    بنية {
      DWORD هيٺيون_Part;
      LONG مٿاهون_Part;
    } u;
    LONGLONG QuadPart;
  } LARGE_INTEGER;

  تعريفنوع LARGE_INTEGER *PLARGE_INTEGER;

  تعريفنوع اتحاد _ULARGE_INTEGER {
    بنية {
      DWORD هيٺيون_Part;
      DWORD مٿاهون_Part;
    };
    بنية {
      DWORD هيٺيون_Part;
      DWORD مٿاهون_Part;
    } u;
    ULONGLONG QuadPart;
  } ULARGE_INTEGER;

  تعريفنوع ULARGE_INTEGER *PULARGE_INTEGER;

  تعريفنوع بنية _LUID {
    DWORD هيٺيون_Part;
    LONG مٿاهون_Part;
  } LUID,*PLUID;

#وصف_ڪريو _DWORDLONG_
  تعريفنوع ULONGLONG DWORDLONG;
  تعريفنوع DWORDLONG *PDWORDLONG;

#جيڪڏهن_وصف_ٿيل RC_INVOKED
#وصف_ڪريو Int32x32To64(a,b) ((LONGLONG)((LONG)(a)) *(LONGLONG)((LONG)(b)))
#وصف_ڪريو UInt32x32To64(a,b) ((ULONGLONG)((DWORD)(a)) *(ULONGLONG)((DWORD)(b)))
#وصف_ڪريو Int64ShrlMod32(a,b) ((ULONGLONG)(a) >> (b))
#وإلاإذا (defined(_X86_) && !defined(__x86_64))
#وصف_ڪريو Int32x32To64(a,b) (LONGLONG)((LONGLONG)(LONG)(a) *(LONG)(b))
#وصف_ڪريو UInt32x32To64(a,b) (ULONGLONG)((ULONGLONG)(DWORD)(a) *(DWORD)(b))
#وصف_ڪريو Int64ShrlMod32(a,b) ((DWORDLONG)(a)>>(b))
#وإلاإذا defined(__ia64__) || defined(__x86_64) || defined(__aarch64__)
#وصف_ڪريو Int32x32To64(a,b) ((LONGLONG)((LONG)(a)) *(LONGLONG)((LONG)(b)))
#وصف_ڪريو UInt32x32To64(a,b) ((ULONGLONG)((DWORD)(a)) *(ULONGLONG)((DWORD)(b)))
#وصف_ڪريو Int64ShrlMod32(a,b) ((ULONGLONG)(a) >> (b))
#وإلا
#غلطي Must define a هدف architecture.
#جيڪڏهن_پورو

#وصف_ڪريو Int64ShraMod32(a,b) ((LONGLONG)(a) >> (b))
#وصف_ڪريو Int64ShllMod32(a,b) ((ULONGLONG)(a) << (b))

#جيڪڏهن_وصف_ٿيل __cplusplus
  خارجي "C" {
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل __x86_64

#وصف_ڪريو RotateLeft8 _rotl8
#وصف_ڪريو RotateLeft16 _rotl16
#وصف_ڪريو RotateRight8 _rotr8
#وصف_ڪريو RotateRight16 _rotr16

    بنانشان حرف __cdecl _rotl8(بنانشان حرف قدر_3,بنانشان حرف سرڪايو_3);
    بنانشان ننڍو __cdecl _rotl16(بنانشان ننڍو قدر_3,بنانشان حرف سرڪايو_3);
    بنانشان حرف __cdecl _rotr8(بنانشان حرف قدر_3,بنانشان حرف سرڪايو_3);
    بنانشان ننڍو __cdecl _rotr16(بنانشان ننڍو قدر_3,بنانشان حرف سرڪايو_3);
#جيڪڏهن_پورو

#وصف_ڪريو RotateLeft32 _rotl
#وصف_ڪريو RotateLeft64 _rotl64
#وصف_ڪريو RotateRight32 _rotr
#وصف_ڪريو RotateRight64 _rotr64

    بنانشان صحيح __cdecl _rotl(بنانشان صحيح قدر_3,صحيح سرڪايو_3);
    بنانشان __int64 __cdecl _rotl64(بنانشان __int64 قدر_3,صحيح سرڪايو_3);
    بنانشان صحيح __cdecl _rotr(بنانشان صحيح قدر_3,صحيح سرڪايو_3);
    بنانشان __int64 __cdecl _rotr64(بنانشان __int64 قدر_3,صحيح سرڪايو_3);
#جيڪڏهن_وصف_ٿيل __cplusplus
  }
#جيڪڏهن_پورو

#وصف_ڪريو ANSI_NULL ((CHAR)0)
#وصف_ڪريو UNICODE_NULL ((WCHAR)0)
#وصف_ڪريو UNICODE_STRING_MAX_بائيٽون ((لفظ_3) 65534)
#وصف_ڪريو UNICODE_STRING_MAX_CHARS (32767)

#جيڪڏهن_وصف_نه_ٿيل _BOOLEAN_
#وصف_ڪريو _BOOLEAN_
  تعريفنوع BYTE BOOLEAN;
#جيڪڏهن_پورو
  تعريفنوع BOOLEAN *PBOOLEAN;

  تعريفنوع بنية LIST_داخلا {
    بنية LIST_داخلا *Flink;
    بنية LIST_داخلا *Blink;
  } LIST_داخلا_2,*PLIST_داخلا,*RESTRICTED_اشارو PRLIST_داخلا;

  تعريفنوع بنية SINGLE_LIST_داخلا {
    بنية SINGLE_LIST_داخلا *ايندڙ_2;
  } SINGLE_LIST_داخلا_2,*PSINGLE_LIST_داخلا;

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

#جيڪڏهن_وصف_نه_ٿيل __OBJECTID_DEFINED
#وصف_ڪريو __OBJECTID_DEFINED
  تعريفنوع بنية _OBJECTID {
    GUID Lineage;
    DWORD Uniquifier;
  } OBJECTID;
#جيڪڏهن_پورو

#وصف_ڪريو MINCHAR 0x80
#وصف_ڪريو MAXCHAR 0x7f
#وصف_ڪريو MINSHORT 0x8000
#وصف_ڪريو MAXSHORT 0x7fff
#وصف_ڪريو MINLONG 0x80000000
#وصف_ڪريو MAXLONG 0x7fffffff
#وصف_ڪريو MAXBYTE 0xff
#وصف_ڪريو MAXWORD 0xffff
#وصف_ڪريو MAXDWORD 0xffffffff

#وصف_ڪريو ميدان_وٿي(type,ميدان) ((LONG)(LONG_PTR)&(((type *)0)->ميدان))
#وصف_ڪريو RTL_ميدان_سائيز(type,ميدان) (حجم(((type *)0)->ميدان))
#وصف_ڪريو RTL_SIZEOF_THROUGH_ميدان(type,ميدان) (ميدان_وٿي(type,ميدان) + RTL_ميدان_سائيز(type,ميدان))
#وصف_ڪريو RTL_شامل_آهي_ميدان(Struct,سائيز_3,ميدان_2) ((((PCHAR)(&(Struct)->ميدان_2)) + حجم((Struct)->ميدان_2)) <= (((PCHAR)(Struct))+(سائيز_3)))
#وصف_ڪريو RTL_عدد_جو_V1(A) (حجم(A)/حجم((A)[0]))
#وصف_ڪريو RTL_عدد_جو_V2(A) RTL_عدد_جو_V1(A)

#جيڪڏهن_وصف_ٿيل ENABLE_RTL_عدد_جو_V2
#وصف_ڪريو RTL_عدد_جو(A) RTL_عدد_جو_V2(A)
#وإلا
#وصف_ڪريو RTL_عدد_جو(A) RTL_عدد_جو_V1(A)
#جيڪڏهن_پورو

#وصف_ڪريو ARRAYSIZE(A) RTL_عدد_جو_V2(A)
#وصف_ڪريو _ARRAYSIZE(A) RTL_عدد_جو_V1(A)

#وصف_ڪريو RTL_ميدان_TYPE(type,ميدان) (((type*)0)->ميدان)
#وصف_ڪريو RTL_عدد_جو_ميدان(type,ميدان) (RTL_عدد_جو(RTL_ميدان_TYPE(type,ميدان)))
#وصف_ڪريو RTL_PADDING_BETWEEN_FIELDS(T,F1,F2) ((ميدان_وٿي(T,F2) > ميدان_وٿي(T,F1)) ? (ميدان_وٿي(T,F2) - ميدان_وٿي(T,F1) - RTL_ميدان_سائيز(T,F1)) : (ميدان_وٿي(T,F1) - ميدان_وٿي(T,F2) - RTL_ميدان_سائيز(T,F2)))

#جيڪڏهن_وصف_ٿيل __cplusplus
#وصف_ڪريو RTL_CONST_CAST(type) const_cast<type>
#وإلا
#وصف_ڪريو RTL_CONST_CAST(type) (type)
#جيڪڏهن_پورو

#وصف_ڪريو RTL_بٽ_جو(سائيز_جو_Arg) (حجم(سائيز_جو_Arg) *8)
#وصف_ڪريو RTL_بٽ_جو_ميدان(type,ميدان) (RTL_بٽ_جو(RTL_ميدان_TYPE(type,ميدان)))
#وصف_ڪريو CONTAINING_رڪارڊ(پتو,type,ميدان) ((type *)((PCHAR)(پتو) - (ULONG_PTR)(&((type *)0)->ميدان)))

#وصف_ڪريو VER_SERVER_NT 0x80000000
#وصف_ڪريو VER_WORKSTATION_NT 0x40000000
#وصف_ڪريو VER_SUITE_SMALLBUSINESS 0x00000001
#وصف_ڪريو VER_SUITE_ENTERPRISE 0x00000002
#وصف_ڪريو VER_SUITE_BACKOFFICE 0x00000004
#وصف_ڪريو VER_SUITE_COMMUNICATIONS 0x00000008
#وصف_ڪريو VER_SUITE_TERMINAL 0x00000010
#وصف_ڪريو VER_SUITE_SMALLBUSINESS_RESTRICTED 0x00000020
#وصف_ڪريو VER_SUITE_EMBEDDEDNT 0x00000040
#وصف_ڪريو VER_SUITE_DATACENTER 0x00000080
#وصف_ڪريو VER_SUITE_SINGLEUSERTS 0x00000100
#وصف_ڪريو VER_SUITE_PERSONAL 0x00000200
#وصف_ڪريو VER_SUITE_BLADE 0x00000400
#وصف_ڪريو VER_SUITE_EMBEDDED_RESTRICTED 0x00000800
#وصف_ڪريو VER_SUITE_SECURITY_APPLIANCE 0x00001000
#وصف_ڪريو VER_SUITE_STORAGE_SERVER 0x00002000
#وصف_ڪريو VER_SUITE_COMPUTE_SERVER 0x00004000

#وصف_ڪريو حاصل_ضرب_UNDEFINED                       0x0

#وصف_ڪريو حاصل_ضرب_ULTIMATE                        0x1
#وصف_ڪريو حاصل_ضرب_HOME_BASIC                      0x2
#وصف_ڪريو حاصل_ضرب_HOME_PREMIUM                    0x3
#وصف_ڪريو حاصل_ضرب_ENTERPRISE                      0x4
#وصف_ڪريو حاصل_ضرب_HOME_BASIC_N                    0x5
#وصف_ڪريو حاصل_ضرب_BUSINESS                        0x6
#وصف_ڪريو حاصل_ضرب_STANDARD_SERVER                 0x7
#وصف_ڪريو حاصل_ضرب_DATACENTER_SERVER               0x8
#وصف_ڪريو حاصل_ضرب_SMALLBUSINESS_SERVER            0x9
#وصف_ڪريو حاصل_ضرب_ENTERPRISE_SERVER               0xa
#وصف_ڪريو حاصل_ضرب_STARTER                         0xb
#وصف_ڪريو حاصل_ضرب_DATACENTER_SERVER_CORE          0xc
#وصف_ڪريو حاصل_ضرب_STANDARD_SERVER_CORE            0xd
#وصف_ڪريو حاصل_ضرب_ENTERPRISE_SERVER_CORE          0xe
#وصف_ڪريو حاصل_ضرب_ENTERPRISE_SERVER_IA64          0xf
#وصف_ڪريو حاصل_ضرب_BUSINESS_N                      0x10
#وصف_ڪريو حاصل_ضرب_WEB_SERVER                      0x11
#وصف_ڪريو حاصل_ضرب_CLUSTER_SERVER                  0x12
#وصف_ڪريو حاصل_ضرب_HOME_SERVER                     0x13
#وصف_ڪريو حاصل_ضرب_STORAGE_EXPRESS_SERVER          0x14
#وصف_ڪريو حاصل_ضرب_STORAGE_STANDARD_SERVER         0x15
#وصف_ڪريو حاصل_ضرب_STORAGE_WORKGROUP_SERVER        0x16
#وصف_ڪريو حاصل_ضرب_STORAGE_ENTERPRISE_SERVER       0x17
#وصف_ڪريو حاصل_ضرب_SERVER_FOR_SMALLBUSINESS        0x18
#وصف_ڪريو حاصل_ضرب_SMALLBUSINESS_SERVER_PREMIUM    0x19

#وصف_ڪريو حاصل_ضرب_UNLICENSED                      0xabcdabcd

#وصف_ڪريو LANG_NEUTRAL 0x00
#وصف_ڪريو LANG_INVARIANT 0x7f

#وصف_ڪريو LANG_AFRIKAANS 0x36
#وصف_ڪريو LANG_ALBANIAN 0x1c
#وصف_ڪريو LANG_ALSATIAN 0x84
#وصف_ڪريو LANG_AMHARIC 0x5e
#وصف_ڪريو LANG_ARABIC 0x01
#وصف_ڪريو LANG_ARMENIAN 0x2b
#وصف_ڪريو LANG_ASSAMESE 0x4d
#وصف_ڪريو LANG_AZERI 0x2c
#وصف_ڪريو LANG_BASHKIR 0x6d
#وصف_ڪريو LANG_BASQUE 0x2d
#وصف_ڪريو LANG_BELARUSIAN 0x23
#وصف_ڪريو LANG_BENGALI 0x45
#وصف_ڪريو LANG_BRETON 0x7e
#وصف_ڪريو LANG_BOSNIAN 0x1a
#وصف_ڪريو LANG_BOSNIAN_NEUTRAL 0x781a
#وصف_ڪريو LANG_BULGARIAN 0x02
#وصف_ڪريو LANG_ڪيٽالان 0x03
#وصف_ڪريو LANG_CHINESE 0x04
#وصف_ڪريو LANG_CHINESE_SIMPLIFIED 0x04
#وصف_ڪريو LANG_CHINESE_TRADITIONAL 0x7c04
#وصف_ڪريو LANG_CORSICAN 0x83
#وصف_ڪريو LANG_CROATIAN 0x1a
#وصف_ڪريو LANG_CZECH 0x05
#وصف_ڪريو LANG_DANISH 0x06
#وصف_ڪريو LANG_DARI 0x8c
#وصف_ڪريو LANG_DIVEHI 0x65
#وصف_ڪريو LANG_DUTCH 0x13
#وصف_ڪريو LANG_ENGLISH 0x09
#وصف_ڪريو LANG_ESTONIAN 0x25
#وصف_ڪريو LANG_FAEROESE 0x38
#وصف_ڪريو LANG_FARSI 0x29
#وصف_ڪريو LANG_FILIPINO 0x64
#وصف_ڪريو LANG_FINNISH 0x0b
#وصف_ڪريو LANG_FRENCH 0x0c
#وصف_ڪريو LANG_FRISIAN 0x62
#وصف_ڪريو LANG_GALICIAN 0x56
#وصف_ڪريو LANG_GEORGIAN 0x37
#وصف_ڪريو LANG_GERMAN 0x07
#وصف_ڪريو LANG_GREEK 0x08
#وصف_ڪريو LANG_GREENLANDIC 0x6f
#وصف_ڪريو LANG_GUJARATI 0x47
#وصف_ڪريو LANG_HAUSA 0x68
#وصف_ڪريو LANG_HEBREW 0x0d
#وصف_ڪريو LANG_HINDI 0x39
#وصف_ڪريو LANG_HUNGARIAN 0x0e
#وصف_ڪريو LANG_ICELANDIC 0x0f
#وصف_ڪريو LANG_IGBO 0x70
#وصف_ڪريو LANG_INDONESIAN 0x21
#وصف_ڪريو LANG_INUKTITUT 0x5d
#وصف_ڪريو LANG_IRISH 0x3c
#وصف_ڪريو LANG_ITALIAN 0x10
#وصف_ڪريو LANG_JAPANESE 0x11
#وصف_ڪريو LANG_KANNADA 0x4b
#وصف_ڪريو LANG_KASHMIRI 0x60
#وصف_ڪريو LANG_KAZAK 0x3f
#وصف_ڪريو LANG_KHMER 0x53
#وصف_ڪريو LANG_KICHE 0x86
#وصف_ڪريو LANG_KINYARWANDA 0x87
#وصف_ڪريو LANG_KONKANI 0x57
#وصف_ڪريو LANG_KOREAN 0x12
#وصف_ڪريو LANG_KYRGYZ 0x40
#وصف_ڪريو LANG_LAO 0x54
#وصف_ڪريو LANG_LATVIAN 0x26
#وصف_ڪريو LANG_LITHUANIAN 0x27
#وصف_ڪريو LANG_هيٺاهون_SORBIAN 0x2e
#وصف_ڪريو LANG_LUXEMBOURGISH 0x6e
#وصف_ڪريو LANG_MACEDONIAN 0x2f
#وصف_ڪريو LANG_MALAY 0x3e
#وصف_ڪريو LANG_MALAYALAM 0x4c
#وصف_ڪريو LANG_MALTESE 0x3a
#وصف_ڪريو LANG_MANIPURI 0x58
#وصف_ڪريو LANG_MAORI 0x81
#وصف_ڪريو LANG_MAPUDUNGUN 0x7a
#وصف_ڪريو LANG_MARATHI 0x4e
#وصف_ڪريو LANG_MOHAWK 0x7c
#وصف_ڪريو LANG_MONGOLIAN 0x50
#وصف_ڪريو LANG_NEPALI 0x61
#وصف_ڪريو LANG_NORWEGIAN 0x14
#وصف_ڪريو LANG_OCCITAN 0x82
#وصف_ڪريو LANG_ORIYA 0x48
#وصف_ڪريو LANG_PASHTO 0x63
#وصف_ڪريو LANG_PERSIAN 0x29
#وصف_ڪريو LANG_POLISH 0x15
#وصف_ڪريو LANG_PORTUGUESE 0x16
#وصف_ڪريو LANG_PUNJABI 0x46
#وصف_ڪريو LANG_QUECHUA 0x6b
#وصف_ڪريو LANG_ROMANIAN 0x18
#وصف_ڪريو LANG_RUSSIAN 0x19
#وصف_ڪريو LANG_SAMI 0x3b
#وصف_ڪريو LANG_ROMANSH 0x17
#وصف_ڪريو LANG_SANSKRIT 0x4f
#وصف_ڪريو LANG_SERBIAN 0x1a
#وصف_ڪريو LANG_SERBIAN_NEUTRAL 0x7c1a
#وصف_ڪريو LANG_SINDHI 0x59
#وصف_ڪريو LANG_SINHALESE 0x5b
#وصف_ڪريو LANG_SLOVAK 0x1b
#وصف_ڪريو LANG_SLOVENIAN 0x24
#وصف_ڪريو LANG_SOTHO 0x6c
#وصف_ڪريو LANG_SPANISH 0x0a
#وصف_ڪريو LANG_SWAHILI 0x41
#وصف_ڪريو LANG_SWEDISH 0x1d
#وصف_ڪريو LANG_SYRIAC 0x5a
#وصف_ڪريو LANG_TAJIK 0x28
#وصف_ڪريو LANG_TAMAZIGHT 0x5f
#وصف_ڪريو LANG_TAMIL 0x49
#وصف_ڪريو LANG_TATAR 0x44
#وصف_ڪريو LANG_TELUGU 0x4a
#وصف_ڪريو LANG_THAI 0x1e
#وصف_ڪريو LANG_TIBETAN 0x51
#وصف_ڪريو LANG_TIGRIGNA 0x73
#وصف_ڪريو LANG_TSWANA 0x32
#وصف_ڪريو LANG_TURKISH 0x1f
#وصف_ڪريو LANG_TURKMEN 0x42
#وصف_ڪريو LANG_UIGHUR 0x80
#وصف_ڪريو LANG_UKRAINIAN 0x22
#وصف_ڪريو LANG_مٿانهون_SORBIAN 0x2e
#وصف_ڪريو LANG_URDU 0x20
#وصف_ڪريو LANG_UZBEK 0x43
#وصف_ڪريو LANG_VIETNAMESE 0x2a
#وصف_ڪريو LANG_WELSH 0x52
#وصف_ڪريو LANG_WOLOF 0x88
#وصف_ڪريو LANG_XHOSA 0x34
#وصف_ڪريو LANG_YAKUT 0x85
#وصف_ڪريو LANG_YI 0x78
#وصف_ڪريو LANG_YORUBA 0x6a
#وصف_ڪريو LANG_ZULU 0x35

#وصف_ڪريو SUBLANG_NEUTRAL 0x0
#وصف_ڪريو SUBLANG_DEFAULT 0x1
#وصف_ڪريو SUBLANG_SYS_DEFAULT 0x2
#وصف_ڪريو SUBLANG_CUSTOM_DEFAULT 0x3
#وصف_ڪريو SUBLANG_CUSTOM_UNSPECIFIED 0x4
#وصف_ڪريو SUBLANG_UI_CUSTOM_DEFAULT 0x5

#وصف_ڪريو SUBLANG_ARABIC_SAUDI_ARABIA 0x01
#وصف_ڪريو SUBLANG_ARABIC_IRAQ 0x02
#وصف_ڪريو SUBLANG_ARABIC_EGYPT 0x03
#وصف_ڪريو SUBLANG_ARABIC_LIBYA 0x04
#وصف_ڪريو SUBLANG_ARABIC_ALGERIA 0x05
#وصف_ڪريو SUBLANG_ARABIC_MOROCCO 0x06
#وصف_ڪريو SUBLANG_ARABIC_TUNISIA 0x07
#وصف_ڪريو SUBLANG_ARABIC_OMAN 0x08
#وصف_ڪريو SUBLANG_ARABIC_YEMEN 0x09
#وصف_ڪريو SUBLANG_ARABIC_SYRIA 0x0a
#وصف_ڪريو SUBLANG_ARABIC_JORDAN 0x0b
#وصف_ڪريو SUBLANG_ARABIC_LEBANON 0x0c
#وصف_ڪريو SUBLANG_ARABIC_KUWAIT 0x0d
#وصف_ڪريو SUBLANG_ARABIC_UAE 0x0e
#وصف_ڪريو SUBLANG_ARABIC_BAHRAIN 0x0f
#وصف_ڪريو SUBLANG_ARABIC_QATAR 0x10
#وصف_ڪريو SUBLANG_AZERI_LATIN 0x01
#وصف_ڪريو SUBLANG_AZERI_CYRILLIC 0x02
#وصف_ڪريو SUBLANG_CHINESE_TRADITIONAL 0x01
#وصف_ڪريو SUBLANG_CHINESE_SIMPLIFIED 0x02
#وصف_ڪريو SUBLANG_CHINESE_HONGKONG 0x03
#وصف_ڪريو SUBLANG_CHINESE_SINGAPORE 0x04
#وصف_ڪريو SUBLANG_CHINESE_MACAU 0x05
#وصف_ڪريو SUBLANG_DUTCH 0x01
#وصف_ڪريو SUBLANG_DUTCH_BELGIAN 0x02
#وصف_ڪريو SUBLANG_ENGLISH_US 0x01
#وصف_ڪريو SUBLANG_ENGLISH_UK 0x02
#وصف_ڪريو SUBLANG_ENGLISH_AUS 0x03
#وصف_ڪريو SUBLANG_ENGLISH_CAN 0x04
#وصف_ڪريو SUBLANG_ENGLISH_NZ 0x05
#وصف_ڪريو SUBLANG_ENGLISH_EIRE 0x06
#وصف_ڪريو SUBLANG_ENGLISH_SOUTH_AFRICA 0x07
#وصف_ڪريو SUBLANG_ENGLISH_JAMAICA 0x08
#وصف_ڪريو SUBLANG_ENGLISH_CARIBBEAN 0x09
#وصف_ڪريو SUBLANG_ENGLISH_BELIZE 0x0a
#وصف_ڪريو SUBLANG_ENGLISH_TRINIDAD 0x0b
#وصف_ڪريو SUBLANG_ENGLISH_ZIMBABWE 0x0c
#وصف_ڪريو SUBLANG_ENGLISH_PHILIPPINES 0x0d
#وصف_ڪريو SUBLANG_FRENCH 0x01
#وصف_ڪريو SUBLANG_FRENCH_BELGIAN 0x02
#وصف_ڪريو SUBLANG_FRENCH_CANADIAN 0x03
#وصف_ڪريو SUBLANG_FRENCH_SWISS 0x04
#وصف_ڪريو SUBLANG_FRENCH_LUXEMBOURG 0x05
#وصف_ڪريو SUBLANG_FRENCH_MONACO 0x06
#وصف_ڪريو SUBLANG_GERMAN 0x01
#وصف_ڪريو SUBLANG_GERMAN_SWISS 0x02
#وصف_ڪريو SUBLANG_GERMAN_AUSTRIAN 0x03
#وصف_ڪريو SUBLANG_GERMAN_LUXEMBOURG 0x04
#وصف_ڪريو SUBLANG_GERMAN_LIECHTENSTEIN 0x05
#وصف_ڪريو SUBLANG_ITALIAN 0x01
#وصف_ڪريو SUBLANG_ITALIAN_SWISS 0x02
#وصف_ڪريو SUBLANG_KASHMIRI_SASIA 0x02
#وصف_ڪريو SUBLANG_KASHMIRI_INDIA 0x02
#وصف_ڪريو SUBLANG_KOREAN 0x01
#وصف_ڪريو SUBLANG_LITHUANIAN 0x01
#وصف_ڪريو SUBLANG_MALAY_MALAYSIA 0x01
#وصف_ڪريو SUBLANG_MALAY_BRUNEI_DARUSSALAM 0x02
#وصف_ڪريو SUBLANG_NEPALI_INDIA 0x02
#وصف_ڪريو SUBLANG_NORWEGIAN_BOKMAL 0x01
#وصف_ڪريو SUBLANG_NORWEGIAN_NYNORSK 0x02
#وصف_ڪريو SUBLANG_PORTUGUESE 0x02
#وصف_ڪريو SUBLANG_PORTUGUESE_BRAZILIAN 0x01
#وصف_ڪريو SUBLANG_SERBIAN_LATIN 0x02
#وصف_ڪريو SUBLANG_SERBIAN_CYRILLIC 0x03
#وصف_ڪريو SUBLANG_SPANISH 0x01
#وصف_ڪريو SUBLANG_SPANISH_MEXICAN 0x02
#وصف_ڪريو SUBLANG_SPANISH_MODERN 0x03
#وصف_ڪريو SUBLANG_SPANISH_GUATEMALA 0x04
#وصف_ڪريو SUBLANG_SPANISH_COSTA_RICA 0x05
#وصف_ڪريو SUBLANG_SPANISH_PANAMA 0x06
#وصف_ڪريو SUBLANG_SPANISH_DOMINICAN_REPUBLIC 0x07
#وصف_ڪريو SUBLANG_SPANISH_VENEZUELA 0x08
#وصف_ڪريو SUBLANG_SPANISH_COLOMBIA 0x09
#وصف_ڪريو SUBLANG_SPANISH_PERU 0x0a
#وصف_ڪريو SUBLANG_SPANISH_ARGENTINA 0x0b
#وصف_ڪريو SUBLANG_SPANISH_ECUADOR 0x0c
#وصف_ڪريو SUBLANG_SPANISH_CHILE 0x0d
#وصف_ڪريو SUBLANG_SPANISH_URUGUAY 0x0e
#وصف_ڪريو SUBLANG_SPANISH_PARAGUAY 0x0f
#وصف_ڪريو SUBLANG_SPANISH_BOLIVIA 0x10
#وصف_ڪريو SUBLANG_SPANISH_EL_SALVADOR 0x11
#وصف_ڪريو SUBLANG_SPANISH_HONDURAS 0x12
#وصف_ڪريو SUBLANG_SPANISH_NICARAGUA 0x13
#وصف_ڪريو SUBLANG_SPANISH_PUERTO_RICO 0x14
#وصف_ڪريو SUBLANG_SWEDISH 0x01
#وصف_ڪريو SUBLANG_SWEDISH_FINLAND 0x02
#وصف_ڪريو SUBLANG_URDU_PAKISTAN 0x01
#وصف_ڪريو SUBLANG_URDU_INDIA 0x02
#وصف_ڪريو SUBLANG_UZBEK_LATIN 0x01
#وصف_ڪريو SUBLANG_UZBEK_CYRILLIC 0x02

#وصف_ڪريو ترتيب_ڏيو_DEFAULT 0x0
#وصف_ڪريو ترتيب_ڏيو_INVARIANT_MATH 0x1

#وصف_ڪريو ترتيب_ڏيو_JAPANESE_XJIS 0x0
#وصف_ڪريو ترتيب_ڏيو_JAPANESE_UNICODE 0x1
#وصف_ڪريو ترتيب_ڏيو_JAPANESE_RADICALSTROKE 0x4

#وصف_ڪريو ترتيب_ڏيو_CHINESE_BIG5 0x0
#وصف_ڪريو ترتيب_ڏيو_CHINESE_PRCP 0x0
#وصف_ڪريو ترتيب_ڏيو_CHINESE_UNICODE 0x1
#وصف_ڪريو ترتيب_ڏيو_CHINESE_PRC 0x2
#وصف_ڪريو ترتيب_ڏيو_CHINESE_BOPOMOFO 0x3

#وصف_ڪريو ترتيب_ڏيو_KOREAN_KSC 0x0
#وصف_ڪريو ترتيب_ڏيو_KOREAN_UNICODE 0x1

#وصف_ڪريو ترتيب_ڏيو_GERMAN_PHONE_BOOK 0x1

#وصف_ڪريو ترتيب_ڏيو_HUNGARIAN_DEFAULT 0x0
#وصف_ڪريو ترتيب_ڏيو_HUNGARIAN_TECHNICAL 0x1

#وصف_ڪريو ترتيب_ڏيو_GEORGIAN_TRADITIONAL 0x0
#وصف_ڪريو ترتيب_ڏيو_GEORGIAN_MODERN 0x1

#وصف_ڪريو MAKELANGID(p,s) ((((لفظ_3)(s)) << 10) | (لفظ_3)(p))
#وصف_ڪريو PRIMARYLANGID(lgid) ((لفظ_3)(lgid) & 0x3ff)
#وصف_ڪريو SUBLANGID(lgid) ((لفظ_3)(lgid) >> 10)

#وصف_ڪريو NLS_VALID_LOCALE_نقاب 0x000fffff

#وصف_ڪريو MAKELCID(lgid,srtid) ((DWORD)((((DWORD)((لفظ_3)(srtid))) << 16) | ((DWORD)((لفظ_3)(lgid)))))
#وصف_ڪريو MAKESORTLCID(lgid,srtid,ver) ((DWORD)((MAKELCID(lgid,srtid)) | (((DWORD)((لفظ_3)(ver))) << 20)))
#وصف_ڪريو LANGIDFROMLCID(lcid) ((لفظ_3)(lcid))
#وصف_ڪريو SORTIDFROMLCID(lcid) ((لفظ_3)((((DWORD)(lcid)) >> 16) & 0xf))
#وصف_ڪريو SORTVERSIONFROMLCID(lcid) ((لفظ_3)((((DWORD)(lcid)) >> 20) & 0xf))

#وصف_ڪريو LOCALE_NAME_MAX_ڊيگهائي 85
#وصف_ڪريو LANG_SYSTEM_DEFAULT (MAKELANGID(LANG_NEUTRAL,SUBLANG_SYS_DEFAULT))
#وصف_ڪريو LANG_USER_DEFAULT (MAKELANGID(LANG_NEUTRAL,SUBLANG_DEFAULT))

#وصف_ڪريو LOCALE_SYSTEM_DEFAULT (MAKELCID(LANG_SYSTEM_DEFAULT,ترتيب_ڏيو_DEFAULT))
#وصف_ڪريو LOCALE_USER_DEFAULT (MAKELCID(LANG_USER_DEFAULT,ترتيب_ڏيو_DEFAULT))

#وصف_ڪريو LOCALE_NEUTRAL (MAKELCID(MAKELANGID(LANG_NEUTRAL,SUBLANG_NEUTRAL),ترتيب_ڏيو_DEFAULT))

#وصف_ڪريو LOCALE_CUSTOM_DEFAULT (MAKELCID(MAKELANGID(LANG_NEUTRAL, SUBLANG_CUSTOM_DEFAULT), ترتيب_ڏيو_DEFAULT))
#وصف_ڪريو LOCALE_CUSTOM_UNSPECIFIED (MAKELCID(MAKELANGID(LANG_NEUTRAL, SUBLANG_CUSTOM_UNSPECIFIED), ترتيب_ڏيو_DEFAULT))
#وصف_ڪريو LOCALE_CUSTOM_UI_DEFAULT (MAKELCID(MAKELANGID(LANG_NEUTRAL, SUBLANG_UI_CUSTOM_DEFAULT), ترتيب_ڏيو_DEFAULT))

#وصف_ڪريو LOCALE_INVARIANT (MAKELCID(MAKELANGID(LANG_INVARIANT,SUBLANG_NEUTRAL),ترتيب_ڏيو_DEFAULT))

#وصف_ڪريو UNREFERENCED_PARAMETER(P) (P)
#وصف_ڪريو DBG_UNREFERENCED_PARAMETER(P) (P)
#وصف_ڪريو DBG_UNREFERENCED_LOCAL_VARIABLE(V) (V)

#وصف_ڪريو DEFAULT_UNREACHABLE

#جيڪڏهن_وصف_نه_ٿيل WIN32_NO_حالت
#وصف_ڪريو حالت_WAIT_0 ((DWORD)0x00000000L)
#وصف_ڪريو حالت_ABANDONED_WAIT_0 ((DWORD)0x00000080L)
#وصف_ڪريو حالت_USER_APC ((DWORD)0x000000C0L)
#وصف_ڪريو حالت_TIMEOUT ((DWORD)0x00000102L)
#وصف_ڪريو حالت_PENDING ((DWORD)0x00000103L)
#وصف_ڪريو DBG_EXCEPTION_HANDLED ((DWORD)0x00010001L)
#وصف_ڪريو DBG_CONTINUE ((DWORD)0x00010002L)
#وصف_ڪريو حالت_SEGMENT_NOTIFICATION ((DWORD)0x40000005L)
#وصف_ڪريو DBG_TERMINATE_THREAD ((DWORD)0x40010003L)
#وصف_ڪريو DBG_TERMINATE_PROCESS ((DWORD)0x40010004L)
#وصف_ڪريو DBG_CONTROL_C ((DWORD)0x40010005L)
#وصف_ڪريو DBG_CONTROL_BREAK ((DWORD)0x40010008L)
#وصف_ڪريو DBG_COMMAND_EXCEPTION ((DWORD)0x40010009L)
#وصف_ڪريو حالت_GUARD_صفحو_VIOLATION ((DWORD)0x80000001L)
#وصف_ڪريو حالت_DATATYPE_MISALIGNMENT ((DWORD)0x80000002L)
#وصف_ڪريو حالت_BREAKPOINT ((DWORD)0x80000003L)
#وصف_ڪريو حالت_SINGLE_قدم ((DWORD)0x80000004L)
#وصف_ڪريو DBG_EXCEPTION_NOT_HANDLED ((DWORD)0x80010001L)
#وصف_ڪريو حالت_ACCESS_VIOLATION ((DWORD)0xC0000005L)
#وصف_ڪريو حالت_اندريون_صفحو_ERROR ((DWORD)0xC0000006L)
#وصف_ڪريو حالت_INVALID_HANDLE ((DWORD)0xC0000008L)
#وصف_ڪريو حالت_NO_يادگيري ((DWORD)0xC0000017L)
#وصف_ڪريو حالت_ILLEGAL_INSTRUCTION ((DWORD)0xC000001DL)
#وصف_ڪريو حالت_NONCONTINUABLE_EXCEPTION ((DWORD)0xC0000025L)
#وصف_ڪريو حالت_INVALID_DISPOSITION ((DWORD)0xC0000026L)
#وصف_ڪريو حالت_ARRAY_BOUNDS_EXCEEDED ((DWORD)0xC000008CL)
#وصف_ڪريو حالت_FLOAT_DENORMAL_عمليو ((DWORD)0xC000008DL)
#وصف_ڪريو حالت_FLOAT_DIVIDE_BY_ZERO ((DWORD)0xC000008EL)
#وصف_ڪريو حالت_FLOAT_INEXACT_نتيجو ((DWORD)0xC000008FL)
#وصف_ڪريو حالت_FLOAT_INVALID_OPERATION ((DWORD)0xC0000090L)
#وصف_ڪريو حالت_FLOAT_حد_کان_مٿي ((DWORD)0xC0000091L)
#وصف_ڪريو حالت_FLOAT_ڍير_CHECK ((DWORD)0xC0000092L)
#وصف_ڪريو حالت_FLOAT_UNDERFLOW ((DWORD)0xC0000093L)
#وصف_ڪريو حالت_INTEGER_DIVIDE_BY_ZERO ((DWORD)0xC0000094L)
#وصف_ڪريو حالت_INTEGER_حد_کان_مٿي ((DWORD)0xC0000095L)
#وصف_ڪريو حالت_PRIVILEGED_INSTRUCTION ((DWORD)0xC0000096L)
#وصف_ڪريو حالت_ڍير_حد_کان_مٿي ((DWORD)0xC00000FDL)
#وصف_ڪريو حالت_CONTROL_C_EXIT ((DWORD)0xC000013AL)
#وصف_ڪريو حالت_FLOAT_گڻو_نقص ((DWORD)0xC00002B4L)
#وصف_ڪريو حالت_FLOAT_گڻو_TRAPS ((DWORD)0xC00002B5L)
#وصف_ڪريو حالت_REG_NAT_CONSUMPTION ((DWORD)0xC00002C9L)
#وصف_ڪريو حالت_SXS_EARLY_DEACTIVATION ((DWORD)0xC015000FL)
#وصف_ڪريو حالت_SXS_INVALID_DEACTIVATION ((DWORD)0xC0150010L)
#جيڪڏهن_پورو

#وصف_ڪريو وڌ_کان_وڌ_WAIT_OBJECTS 64
#وصف_ڪريو وڌ_کان_وڌ_SUSPEND_ڳڻپ MAXCHAR

  تعريفنوع ULONG_PTR KSPIN_تالو;
  تعريفنوع KSPIN_تالو *PKSPIN_تالو;

#إذا defined(__x86_64) && !defined(RC_INVOKED)

#جيڪڏهن_وصف_ٿيل __cplusplus
  خارجي "C" {
#جيڪڏهن_پورو

#وصف_ڪريو ٻٽو_انگ_Test _bittest
#وصف_ڪريو ٻٽو_انگ_Test_And_Complement _bittestandcomplement
#وصف_ڪريو ٻٽو_انگ_Test_And_سيٽ _bittestandset
#وصف_ڪريو ٻٽو_انگ_Test_And_Reset _bittestandreset
#وصف_ڪريو Interlocked_ٻٽو_انگ_Test_And_سيٽ _interlockedbittestandset
#وصف_ڪريو Interlocked_ٻٽو_انگ_Test_And_Reset _interlockedbittestandreset
#وصف_ڪريو ٻٽو_انگ_Test64 _bittest64
#وصف_ڪريو ٻٽو_انگ_Test_And_Complement64 _bittestandcomplement64
#وصف_ڪريو ٻٽو_انگ_Test_And_Set64 _bittestandset64
#وصف_ڪريو ٻٽو_انگ_Test_And_Reset64 _bittestandreset64
#وصف_ڪريو Interlocked_ٻٽو_انگ_Test_And_Set64 _interlockedbittestandset64
#وصف_ڪريو Interlocked_ٻٽو_انگ_Test_And_Reset64 _interlockedbittestandreset64

    __CRT_INLINE BOOLEAN _bittest(LONG ثابت *بنياد_2,LONG وٿي_3) {
      صحيح old = 0;
      __asm__ __volatile__("btl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متطاير ڊگهو *) بنياد_2))
	:"Ir" (وٿي_3));
      أرجع (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandcomplement(LONG *بنياد_2,LONG وٿي_3) {
      صحيح old = 0;
      __asm__ __volatile__("btcl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متطاير ڊگهو *) بنياد_2))
	:"Ir" (وٿي_3));
      أرجع (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN Interlocked_ٻٽو_انگ_Test_And_Complement(LONG *بنياد_2,LONG ٻٽو_انگ_2) {
      صحيح old = 0;
      __asm__ __volatile__("lock ; btcl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متطاير ڊگهو *) بنياد_2))
	:"Ir" (ٻٽو_انگ_2));
      أرجع (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandset(LONG *بنياد_2,LONG وٿي_3) {
      صحيح old = 0;
      __asm__ __volatile__("btsl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متطاير ڊگهو *) بنياد_2))
	:"Ir" (وٿي_3));
      أرجع (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandreset(LONG *بنياد_2,LONG وٿي_3) {
      صحيح old = 0;
      __asm__ __volatile__("btrl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متطاير ڊگهو *) بنياد_2))
	:"Ir" (وٿي_3));
      أرجع (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _interlockedbittestandset(LONG *بنياد_2,LONG وٿي_3) {
      صحيح old = 0;
      __asm__ __volatile__("lock ; btsl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متطاير ڊگهو *) بنياد_2))
	:"Ir" (وٿي_3));
      أرجع (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _interlockedbittestandreset(LONG *بنياد_2,LONG وٿي_3) {
      صحيح old = 0;
      __asm__ __volatile__("lock ; btrl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متطاير ڊگهو *) بنياد_2))
	:"Ir" (وٿي_3));
      أرجع (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittest64(LONG64 ثابت *بنياد_2,LONG64 وٿي_3) {
      صحيح old = 0;
      __asm__ __volatile__("btq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متطاير ڊگهو ڊگهو *) بنياد_2))
	:"Ir" (وٿي_3));
      أرجع (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandcomplement64(LONG64 *بنياد_2,LONG64 وٿي_3) {
      صحيح old = 0;
      __asm__ __volatile__("btcq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متطاير ڊگهو ڊگهو *) بنياد_2))
	:"Ir" (وٿي_3));
      أرجع (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandset64(LONG64 *بنياد_2,LONG64 وٿي_3) {
      صحيح old = 0;
      __asm__ __volatile__("btsq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متطاير ڊگهو ڊگهو *) بنياد_2))
	:"Ir" (وٿي_3));
      أرجع (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandreset64(LONG64 *بنياد_2,LONG64 وٿي_3) {
      صحيح old = 0;
      __asm__ __volatile__("btrq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متطاير ڊگهو ڊگهو *) بنياد_2))
	:"Ir" (وٿي_3));
      أرجع (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _interlockedbittestandset64(LONG64 *بنياد_2,LONG64 وٿي_3) {
      صحيح old = 0;
      __asm__ __volatile__("lock ; btsq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متطاير ڊگهو ڊگهو *) بنياد_2))
	:"Ir" (وٿي_3));
      أرجع (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _interlockedbittestandreset64(LONG64 *بنياد_2,LONG64 وٿي_3) {
      صحيح old = 0;
      __asm__ __volatile__("lock ; btrq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متطاير ڊگهو ڊگهو *) بنياد_2))
	:"Ir" (وٿي_3));
      أرجع (BOOLEAN) (old!=0);
    }
#وصف_ڪريو ٻٽو_انگ_جاچ_Forward ٻٽو_انگ_جاچ_Forward_2
#وصف_ڪريو ٻٽو_انگ_جاچ_ابتو ٻٽو_انگ_جاچ_ابتو_2
#وصف_ڪريو ٻٽو_انگ_جاچ_Forward64 ٻٽو_انگ_جاچ_Forward64_2
#وصف_ڪريو ٻٽو_انگ_جاچ_Reverse64 ٻٽو_انگ_جاچ_Reverse64_2

    __CRT_INLINE BOOLEAN ٻٽو_انگ_جاچ_Forward_2(DWORD *اشاريو_3,DWORD نقاب_3) {
      __asm__ __volatile__("bsfl %1,%0" : "=r" (نقاب_3),"=m" ((*(متطاير ڊگهو *)اشاريو_3)));
      أرجع نقاب_3!=0;
    }
    __CRT_INLINE BOOLEAN ٻٽو_انگ_جاچ_ابتو_2(DWORD *اشاريو_3,DWORD نقاب_3) {
      __asm__ __volatile__("bsrl %1,%0" : "=r" (نقاب_3),"=m" ((*(متطاير ڊگهو *)اشاريو_3)));
      أرجع نقاب_3!=0;
    }
    __CRT_INLINE BOOLEAN ٻٽو_انگ_جاچ_Forward64_2(DWORD *اشاريو_3,DWORD64 نقاب_3) {
      __asm__ __volatile__("bsfq %1,%0" : "=r" (نقاب_3),"=m" ((*(متطاير ڊگهو ڊگهو *)اشاريو_3)));
      أرجع نقاب_3!=0;
    }
    __CRT_INLINE BOOLEAN ٻٽو_انگ_جاچ_Reverse64_2(DWORD *اشاريو_3,DWORD64 نقاب_3) {
      __asm__ __volatile__("bsrq %1,%0" : "=r" (نقاب_3),"=m" ((*(متطاير ڊگهو ڊگهو *)اشاريو_3)));
      أرجع نقاب_3!=0;
    }

#وصف_ڪريو InterlockedIncrement16 _InterlockedIncrement16
#وصف_ڪريو InterlockedDecrement16 _InterlockedDecrement16
#وصف_ڪريو InterlockedCompareExchange16 _InterlockedCompareExchange16

#وصف_ڪريو InterlockedAnd _InterlockedAnd
#وصف_ڪريو InterlockedOr _InterlockedOr
#وصف_ڪريو InterlockedXor _InterlockedXor
#وصف_ڪريو InterlockedIncrement _InterlockedIncrement
#وصف_ڪريو InterlockedIncrementAcquire InterlockedIncrement
#وصف_ڪريو InterlockedIncrementRelease InterlockedIncrement
#وصف_ڪريو InterlockedDecrement _InterlockedDecrement
#وصف_ڪريو InterlockedDecrementAcquire InterlockedDecrement
#وصف_ڪريو InterlockedDecrementRelease InterlockedDecrement
#وصف_ڪريو Interlocked_جوڙيو Interlocked_جوڙيو_2
#وصف_ڪريو InterlockedExchange _InterlockedExchange
#وصف_ڪريو Interlocked_Exchange_جوڙيو Interlocked_Exchange_جوڙيو_2
#وصف_ڪريو InterlockedCompareExchange _InterlockedCompareExchange
#وصف_ڪريو InterlockedCompareExchangeAcquire InterlockedCompareExchange
#وصف_ڪريو InterlockedCompareExchangeRelease InterlockedCompareExchange

#وصف_ڪريو InterlockedAnd64 _InterlockedAnd64
#وصف_ڪريو InterlockedAndAffinity InterlockedAnd64
#وصف_ڪريو InterlockedOr64 _InterlockedOr64
#وصف_ڪريو InterlockedOrAffinity InterlockedOr64
#وصف_ڪريو InterlockedXor64 _InterlockedXor64
#وصف_ڪريو InterlockedIncrement64 _InterlockedIncrement64
#وصف_ڪريو InterlockedDecrement64 _InterlockedDecrement64
#وصف_ڪريو InterlockedAdd64 _InterlockedAdd64
#وصف_ڪريو InterlockedExchange64 _InterlockedExchange64
#وصف_ڪريو InterlockedExchangeAcquire64 InterlockedExchange64
#وصف_ڪريو InterlockedExchangeAdd64 _InterlockedExchangeAdd64
#وصف_ڪريو InterlockedCompareExchange64 _InterlockedCompareExchange64
#وصف_ڪريو InterlockedCompareExchangeAcquire64 InterlockedCompareExchange64
#وصف_ڪريو InterlockedCompareExchangeRelease64 InterlockedCompareExchange64

#وصف_ڪريو Interlocked_Exchange_اشارو Interlocked_Exchange_اشارو_2
#وصف_ڪريو Interlocked_Compare_Exchange_اشارو Interlocked_Compare_Exchange_اشارو_2
#وصف_ڪريو Interlocked_Compare_Exchange_اشارو_Acquire Interlocked_Compare_Exchange_اشارو_2
#وصف_ڪريو Interlocked_Compare_Exchange_اشارو_Release Interlocked_Compare_Exchange_اشارو_2

#وصف_ڪريو Interlocked_Exchange_جوڙيو_سائيز_T(a,b) InterlockedExchangeAdd64((LONG64 *)a,b)
#وصف_ڪريو Interlocked_Increment_سائيز_T(a) InterlockedIncrement64((LONG64 *)a)
#وصف_ڪريو Interlocked_Decrement_سائيز_T(a) InterlockedDecrement64((LONG64 *)a)

    __CRT_INLINE SHORT InterlockedIncrement16(SHORT متطاير *Addend) {
      بنانشان حرف c;
      بنانشان حرف s;
      __asm__ __volatile__(
	"lock ; addw $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      أرجع (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE SHORT InterlockedDecrement16(SHORT متطاير *Addend) {
      بنانشان حرف c;
      بنانشان حرف s;
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
    __CRT_INLINE LONG InterlockedAnd(LONG متطاير *Destination,LONG قدر_3) {
      __asm__ __volatile__("lock ; andl %0,%1"
	: :"r"(قدر_3),"m"(*Destination)
	: "memory");
      أرجع *Destination;
    }
    __CRT_INLINE LONG InterlockedOr(LONG متطاير *Destination,LONG قدر_3) {
      __asm__ __volatile__("lock ; orl %0,%1"
	: : "r"(قدر_3),"m"(*Destination) : "memory");
      أرجع *Destination;
    }
    __CRT_INLINE LONG InterlockedXor(LONG متطاير *Destination,LONG قدر_3) {
      __asm__ __volatile__("lock ; xorl %0,%1"
	: : "r"(قدر_3),"m"(*Destination) : "memory");
      أرجع *Destination;
    }
    //		$$$$
    __CRT_INLINE LONG64 InterlockedAnd64(LONG64 متطاير *Destination,LONG64 قدر_3) {
      __asm__ __volatile__("lock ; andq %0,%1"
	: : "r"(قدر_3),"m"(*Destination) : "memory");
      أرجع *Destination;
    }
    __CRT_INLINE LONG64 InterlockedOr64(LONG64 متطاير *Destination,LONG64 قدر_3) {
      __asm__ __volatile__("lock ; orq %0,%1"
	: : "r"(قدر_3),"m"(*Destination) : "memory");
      أرجع *Destination;
    }
    __CRT_INLINE LONG64 InterlockedXor64(LONG64 متطاير *Destination,LONG64 قدر_3) {
      __asm__ __volatile__("lock ; xorq %0,%1"
	: : "r"(قدر_3),"m"(*Destination) : "memory");
      أرجع *Destination;
    }
    __CRT_INLINE LONG InterlockedIncrement(LONG متطاير *Addend) {
      بنانشان حرف c;
      بنانشان حرف s;
      __asm__ __volatile__(
	"lock ; addl $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      أرجع (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE LONG InterlockedDecrement(LONG متطاير *Addend) {
      بنانشان حرف c;
      بنانشان حرف s;
      __asm__ __volatile__(
	"lock ; subl $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      أرجع (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE LONG InterlockedExchange(LONG متطاير *هدف_2,LONG قدر_3) {
      __asm__ __volatile("lock ; xchgl %0,%1"
	: "=r"(قدر_3)
	: "m"(*هدف_2),"0"(قدر_3)
	: "memory");
      أرجع قدر_3;
    }
    LONG Interlocked_Exchange_جوڙيو(LONG متطاير *Addend,LONG قدر_3);

#جيڪڏهن_وصف_نه_ٿيل _X86AMD64_
    __CRT_INLINE LONG Interlocked_جوڙيو(LONG متطاير *Addend,LONG قدر_3) { أرجع Interlocked_Exchange_جوڙيو(Addend,قدر_3) + قدر_3; }
#جيڪڏهن_پورو
    __CRT_INLINE LONG InterlockedCompareExchange(LONG متطاير *Destination,LONG ExChange,LONG Comperand) {
      LONG prev;
      __asm__ __volatile__("lock ; cmpxchgl %1,%2" : "=a" (prev) : "q" (ExChange),"m" (*Destination), "0" (Comperand) : "memory");
      أرجع prev;
    }
    __CRT_INLINE LONG64 InterlockedIncrement64(LONG64 متطاير *Addend) {
      بنانشان حرف c;
      بنانشان حرف s;
      __asm__ __volatile__(
	"lock ; addq $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      أرجع (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE LONG64 InterlockedDecrement64(LONG64 متطاير *Addend) {
      بنانشان حرف c;
      بنانشان حرف s;
      __asm__ __volatile__(
	"lock ; subq $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      أرجع (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE LONG64 InterlockedExchange64(LONG64 متطاير *هدف_2,LONG64 قدر_3) {
      __asm__ __volatile("lock ; xchgq %0,%1"
	: "=r"(قدر_3)
	: "m"(*هدف_2),"0"(قدر_3)
	: "memory");
      أرجع قدر_3;
    }
    LONG64 InterlockedExchangeAdd64(LONG64 متطاير *Addend,LONG64 قدر_3);

#جيڪڏهن_وصف_نه_ٿيل _X86AMD64_
    __CRT_INLINE LONG64 InterlockedAdd64(LONG64 متطاير *Addend,LONG64 قدر_3) { أرجع InterlockedExchangeAdd64(Addend,قدر_3) + قدر_3; }
#جيڪڏهن_پورو

    __CRT_INLINE LONG64 InterlockedCompareExchange64(LONG64 متطاير *Destination,LONG64 ExChange,LONG64 Comperand) {
      LONG64 prev;
      __asm__ __volatile__("lock ; cmpxchgq %1,%2" : "=a" (prev) : "q" (ExChange),"m" (*Destination), "0" (Comperand) : "memory");
      أرجع prev;
    }
    __CRT_INLINE PVOID Interlocked_Compare_Exchange_اشارو(PVOID متطاير *Destination,PVOID ExChange,PVOID Comperand) {
      PVOID prev;
      __asm__ __volatile__("lock ; cmpxchgq %1,%2" : "=a" (prev) : "q" (ExChange),"m" (*Destination), "0" (Comperand) : "memory");
      أرجع prev;
    }
    __CRT_INLINE PVOID Interlocked_Exchange_اشارو(PVOID متطاير *هدف_2,PVOID قدر_3) {
      __asm__ __volatile("lock ; xchgq %0,%1"
	: "=r"(قدر_3)
	: "m"(*هدف_2),"0"(قدر_3)
	: "memory");
      أرجع قدر_3;
    }

#وصف_ڪريو Cache_سٽ_Flush(پتو_2) _mm_clflush(پتو_2)

    VOID _ReadWriteBarrier(VOID);

#وصف_ڪريو FastFence __faststorefence
#وصف_ڪريو ڀريو_Fence _mm_lfence
#وصف_ڪريو يادگيري_Fence _mm_mfence
#وصف_ڪريو StoreFence _mm_sfence

    VOID __faststorefence(VOID);
    VOID _m_prefetchw(متطاير CONST VOID *ذريعو_2);

//!__TINYC__: #include <intrin.h>

#وصف_ڪريو YieldProcessor _mm_pause
#وصف_ڪريو يادگيري_Barrier __faststorefence
#وصف_ڪريو Pre_Fetch_Cache_سٽ(l,a) _mm_prefetch((CHAR CONST *) a,l)
#وصف_ڪريو PrefetchForWrite(p) _m_prefetchw(p)
#وصف_ڪريو ReadForWriteAccess(p) (_m_prefetchw(p),*(p))

#وصف_ڪريو PF_TEMPORAL_LEVEL_1 _MM_HINT_T0
#وصف_ڪريو PF_TEMPORAL_LEVEL_2 _MM_HINT_T1
#وصف_ڪريو PF_TEMPORAL_LEVEL_3 _MM_HINT_T2
#وصف_ڪريو PF_NON_TEMPORAL_LEVEL_ALL _MM_HINT_NTA

#وصف_ڪريو ReadMxCsr _mm_getcsr
#وصف_ڪريو WriteMxCsr _mm_setcsr

    VOID __int2c(VOID);

#وصف_ڪريو DbgRaiseAssertionFailure() __int2c()
#وصف_ڪريو GetCallersEflags() __getcallerseflags()

    بنانشان __int32 __getcallerseflags(VOID);

#وصف_ڪريو Get_Segment_حد_بندي __segmentlimit

    DWORD __segmentlimit(DWORD Selector);

#وصف_ڪريو Read_وقت_Stamp_Counter() __rdtsc()

    DWORD64 __rdtsc(VOID);
    VOID __movsb(PBYTE Destination,BYTE ثابت *ذريعو_2,سائيز_T ڳڻپ_3);
    VOID __movsw(PWORD Destination,لفظ_3 ثابت *ذريعو_2,سائيز_T ڳڻپ_3);
    VOID __movsd(PDWORD Destination,DWORD ثابت *ذريعو_2,سائيز_T ڳڻپ_3);
    VOID __movsq(PDWORD64 Destination,DWORD64 ثابت *ذريعو_2,سائيز_T ڳڻپ_3);
    VOID __stosb(PBYTE Destination,BYTE قدر_3,سائيز_T ڳڻپ_3);
    VOID __stosw(PWORD Destination,لفظ_3 قدر_3,سائيز_T ڳڻپ_3);
    VOID __stosd(PDWORD Destination,DWORD قدر_3,سائيز_T ڳڻپ_3);
    VOID __stosq(PDWORD64 Destination,DWORD64 قدر_3,سائيز_T ڳڻپ_3);

#وصف_ڪريو Multiply_مٿاهون __mulh
#وصف_ڪريو Unsigned_Multiply_مٿاهون __umulh

    LONGLONG Multiply_مٿاهون(LONGLONG Multiplier,LONGLONG Multiplicand);
    ULONGLONG Unsigned_Multiply_مٿاهون(ULONGLONG Multiplier,ULONGLONG Multiplicand);

#وصف_ڪريو سرڪايو_Left128 __shiftleft128
#وصف_ڪريو سرڪايو_Right128 __shiftright128

    DWORD64 سرڪايو_Left128(DWORD64 هيٺيون_Part,DWORD64 مٿاهون_Part,BYTE سرڪايو_3);
    DWORD64 سرڪايو_Right128(DWORD64 هيٺيون_Part,DWORD64 مٿاهون_Part,BYTE سرڪايو_3);

#وصف_ڪريو Multiply128 _mul128

    LONG64 Multiply128(LONG64 Multiplier,LONG64 Multiplicand,LONG64 *مٿاهون_حاصل_ضرب);

#وصف_ڪريو UnsignedMultiply128 _umul128

    DWORD64 UnsignedMultiply128(DWORD64 Multiplier,DWORD64 Multiplicand,DWORD64 *مٿاهون_حاصل_ضرب);

    __CRT_INLINE LONG64 MultiplyExtract128(LONG64 Multiplier,LONG64 Multiplicand,BYTE سرڪايو_3) {
      LONG64 extracted_حاصل_ضرب;
      LONG64 مٿاهون_حاصل_ضرب_2;
      LONG64 هيٺيون_حاصل_ضرب;
      هيٺيون_حاصل_ضرب = Multiply128(Multiplier,Multiplicand,&مٿاهون_حاصل_ضرب_2);
      extracted_حاصل_ضرب = (LONG64)سرڪايو_Right128((LONG64)هيٺيون_حاصل_ضرب,(LONG64)مٿاهون_حاصل_ضرب_2,سرڪايو_3);
      أرجع extracted_حاصل_ضرب;
    }

    __CRT_INLINE DWORD64 UnsignedMultiplyExtract128(DWORD64 Multiplier,DWORD64 Multiplicand,BYTE سرڪايو_3) {
      DWORD64 extracted_حاصل_ضرب;
      DWORD64 مٿاهون_حاصل_ضرب_2;
      DWORD64 هيٺيون_حاصل_ضرب;
      هيٺيون_حاصل_ضرب = UnsignedMultiply128(Multiplier,Multiplicand,&مٿاهون_حاصل_ضرب_2);
      extracted_حاصل_ضرب = سرڪايو_Right128(هيٺيون_حاصل_ضرب,مٿاهون_حاصل_ضرب_2,سرڪايو_3);
      أرجع extracted_حاصل_ضرب;
    }

    __CRT_INLINE BYTE __readgsbyte(DWORD وٿي_3) {
      BYTE ret;
      __asm__ متطاير ("movb	%%gs:%1,%0"
	: "=r" (ret) ,"=m" ((*(متطاير ڊگهو *) (DWORD64) وٿي_3)));
      أرجع ret;
    }
    __CRT_INLINE لفظ_3 __readgsword(DWORD وٿي_3) {
      لفظ_3 ret;
      __asm__ متطاير ("movw	%%gs:%1,%0"
	: "=r" (ret) ,"=m" ((*(متطاير ڊگهو *) (DWORD64) وٿي_3)));
      أرجع ret;
    }
    __CRT_INLINE DWORD __readgsdword(DWORD وٿي_3) {
      DWORD ret;
      __asm__ متطاير ("movl	%%gs:%1,%0"
	: "=r" (ret) ,"=m" ((*(متطاير ڊگهو *) (DWORD64) وٿي_3)));
      أرجع ret;
    }
    __CRT_INLINE DWORD64 __readgsqword(DWORD وٿي_3) {
      فراغ *ret;
      __asm__ متطاير ("movq	%%gs:%1,%0"
	: "=r" (ret) ,"=m" ((*(متطاير ڊگهو *) (DWORD64) وٿي_3)));
      أرجع (DWORD64) ret;
    }
    __CRT_INLINE VOID __writegsbyte(DWORD وٿي_3,BYTE معلومات_3) {
      __asm__ متطاير ("movb	%0,%%gs:%1"
	: "=r" (معلومات_3) ,"=m" ((*(متطاير ڊگهو *) (DWORD64) وٿي_3)));
    }
    __CRT_INLINE VOID __writegsword(DWORD وٿي_3,لفظ_3 معلومات_3) {
      __asm__ متطاير ("movw	%0,%%gs:%1"
	: "=r" (معلومات_3) ,"=m" ((*(متطاير ڊگهو *) (DWORD64) وٿي_3)));
    }
    __CRT_INLINE VOID __writegsdword(DWORD وٿي_3,DWORD معلومات_3) {
      __asm__ متطاير ("movl	%0,%%gs:%1"
	: "=r" (معلومات_3) ,"=m" ((*(متطاير ڊگهو *) (DWORD64) وٿي_3)));
    }
    __CRT_INLINE VOID __writegsqword(DWORD وٿي_3,DWORD64 معلومات_3) {
      __asm__ متطاير ("movq	%0,%%gs:%1"
	: "=r" (معلومات_3) ,"=m" ((*(متطاير ڊگهو *) (DWORD64) وٿي_3)));
    }

#جيڪڏهن_وصف_ٿيل __cplusplus
  }
#جيڪڏهن_پورو

#وصف_ڪريو EXCEPTION_READ_FAULT 0
#وصف_ڪريو EXCEPTION_WRITE_FAULT 1
#وصف_ڪريو EXCEPTION_EXECUTE_FAULT 8

#إذا !defined(RC_INVOKED)

#وصف_ڪريو CONTEXT_AMD64 0x100000

#وصف_ڪريو CONTEXT_CONTROL (CONTEXT_AMD64 | 0x1L)
#وصف_ڪريو CONTEXT_INTEGER (CONTEXT_AMD64 | 0x2L)
#وصف_ڪريو CONTEXT_SEGMENTS (CONTEXT_AMD64 | 0x4L)
#وصف_ڪريو CONTEXT_FLOATING_نقطو (CONTEXT_AMD64 | 0x8L)
#وصف_ڪريو CONTEXT_DEBUG_REGISTERS (CONTEXT_AMD64 | 0x10L)

#وصف_ڪريو CONTEXT_ڀريل (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_FLOATING_نقطو)
#وصف_ڪريو CONTEXT_ALL (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_SEGMENTS | CONTEXT_FLOATING_نقطو | CONTEXT_DEBUG_REGISTERS)

#وصف_ڪريو CONTEXT_EXCEPTION_سرگرم 0x8000000
#وصف_ڪريو CONTEXT_SERVICE_سرگرم 0x10000000
#وصف_ڪريو CONTEXT_EXCEPTION_REQUEST 0x40000000
#وصف_ڪريو CONTEXT_EXCEPTION_REPORTING 0x80000000
#جيڪڏهن_پورو

#وصف_ڪريو INITIAL_MXCSR 0x1f80
#وصف_ڪريو INITIAL_FPCSR 0x027f

  تعريفنوع بنية DECLSPEC_ALIGN(16) _M128A {
    ULONGLONG هيٺيون_3;
    LONGLONG مٿاهون_3;
  } M128A,*PM128A;

  تعريفنوع بنية _XMM_SAVE_AREA32 {
    لفظ_3 Control_لفظ;
    لفظ_3 حالت_لفظ;
    BYTE ٽيگ_لفظ;
    BYTE Reserved1;
    لفظ_3 ErrorOpcode;
    DWORD Error_وٿي;
    لفظ_3 ErrorSelector;
    لفظ_3 Reserved2;
    DWORD معلومات_وٿي_2;
    لفظ_3 معلومات_Selector;
    لفظ_3 Reserved3;
    DWORD MxCsr;
    DWORD Mx_Csr_نقاب;
    M128A FloatRegisters[8];
    M128A XmmRegisters[16];
    BYTE Reserved4[96];
  } XMM_SAVE_AREA32,*PXMM_SAVE_AREA32;

#وصف_ڪريو LEGACY_SAVE_AREA_ڊيگهائي حجم(XMM_SAVE_AREA32)

  تعريفنوع بنية DECLSPEC_ALIGN(16) _CONTEXT {
    DWORD64 P1Home;
    DWORD64 P2Home;
    DWORD64 P3Home;
    DWORD64 P4Home;
    DWORD64 P5Home;
    DWORD64 P6Home;
    DWORD ContextFlags;
    DWORD MxCsr;
    لفظ_3 SegCs;
    لفظ_3 SegDs;
    لفظ_3 SegEs;
    لفظ_3 SegFs;
    لفظ_3 SegGs;
    لفظ_3 SegSs;
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
	M128A سرو_2[2];
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
    M128A ويڪٽر_رجسٽر[26];
    DWORD64 ويڪٽر_Control;
    DWORD64 DebugControl;
    DWORD64 آخري_Branch_منزل_Rip;
    DWORD64 آخري_Branch_From_Rip;
    DWORD64 آخري_Exception_منزل_Rip;
    DWORD64 آخري_Exception_From_Rip;
  } CONTEXT,*PCONTEXT;

#وصف_ڪريو RUNTIME_FUNCTION_اڻسڌو 0x1

  تعريفنوع بنية _RUNTIME_FUNCTION {
    DWORD Begin_پتو;
    DWORD پڇاڙي_پتو;
    DWORD Unwind_معلومات;
  } RUNTIME_FUNCTION,*PRUNTIME_FUNCTION;

  تعريفنوع PRUNTIME_FUNCTION (*PGET_RUNTIME_FUNCTION_CALLBACK)(DWORD64 ControlPc,PVOID Context);
  تعريفنوع DWORD (*POUT_جو_PROCESS_FUNCTION_جدول_CALLBACK)(HANDLE Process,PVOID جدول_پتو,PDWORD Entries,PRUNTIME_FUNCTION *Functions);

#وصف_ڪريو ٻاهريون_جو_PROCESS_FUNCTION_جدول_CALLBACK_EXPORT_NAME "OutOfProcessFunctionTableCallback"
#جيڪڏهن_پورو /* defined(__x86_64) && !defined(RC_INVOKED) */

#إذا defined(__TINYC__) && (defined(__aarch64__) || defined(__arm64__)) && !defined(RC_INVOKED)

#وصف_ڪريو __TCC_WINNT_ATOMIC_SEQ_CST 5
/* TCC lowers __atomic_compare_exchange's fourth argument as weak, but the
   ARM64 helper reads it as success_memorder.  Strong CAS passes weak == 0,
   so keep Interlocked's barriers explicit here. */
#وصف_ڪريو __TCC_WINNT_MEMORY_BARRIER() __asm__ __volatile__("dmb ish" : : : "memory")

/* This covers the LONG operations needed by TCC's semaphore code and the
   pointer helpers that winbase.h exposes through Interlocked pointer macros.
   Add local helpers before relying on increment/decrement, add/exchange-add,
   bitwise, or 64-bit Interlocked forms on Windows ARM64 with TCC. */

    __CRT_INLINE LONG InterlockedExchange(LONG متطاير *هدف_2,LONG قدر_3) {
      LONG Old;
      __atomic_load(هدف_2,&Old,__TCC_WINNT_ATOMIC_SEQ_CST);
      __TCC_WINNT_MEMORY_BARRIER();
      طالما (!__atomic_compare_exchange(هدف_2,&Old,&قدر_3,0,
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
    __CRT_INLINE PVOID __TCC_WINNT_InterlockedExchangePointer(PVOID متطاير *هدف_2,PVOID قدر_3) {
      PVOID Old;
      __atomic_load(هدف_2,&Old,__TCC_WINNT_ATOMIC_SEQ_CST);
      __TCC_WINNT_MEMORY_BARRIER();
      طالما (!__atomic_compare_exchange(هدف_2,&Old,&قدر_3,0,
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

#وصف_ڪريو Interlocked_Exchange_اشارو __TCC_WINNT_InterlockedExchangePointer
#وصف_ڪريو Interlocked_Compare_Exchange_اشارو __TCC_WINNT_InterlockedCompareExchangePointer
#وصف_ڪريو Interlocked_Compare_Exchange_اشارو_Acquire Interlocked_Compare_Exchange_اشارو
#وصف_ڪريو Interlocked_Compare_Exchange_اشارو_Release Interlocked_Compare_Exchange_اشارو

#وصف_ڪريو InterlockedCompareExchangeAcquire InterlockedCompareExchange
#وصف_ڪريو InterlockedCompareExchangeRelease InterlockedCompareExchange

#وصف_رد __TCC_WINNT_MEMORY_BARRIER
#وصف_رد __TCC_WINNT_ATOMIC_SEQ_CST

#جيڪڏهن_پورو /* defined(__TINYC__) && (defined(__aarch64__) || defined(__arm64__)) && !defined(RC_INVOKED) */

#إذا defined(_ARM64_)

/* ARM64 Context Definition */
#وصف_ڪريو CONTEXT_ARM64 0x00400000
#وصف_ڪريو CONTEXT_CONTROL (CONTEXT_ARM64 | 0x00000001L)
#وصف_ڪريو CONTEXT_INTEGER (CONTEXT_ARM64 | 0x00000002L)
#وصف_ڪريو CONTEXT_FLOATING_نقطو (CONTEXT_ARM64 | 0x00000004L)
#وصف_ڪريو CONTEXT_DEBUG (CONTEXT_ARM64 | 0x00000008L)
#وصف_ڪريو CONTEXT_ڀريل (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_FLOATING_نقطو)
#وصف_ڪريو CONTEXT_ALL (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_FLOATING_نقطو | CONTEXT_DEBUG)
#وصف_ڪريو ARM64_MAX_BREAKPOINTS 8
#وصف_ڪريو ARM64_MAX_WATCHPOINTS 2

  تعريفنوع اتحاد _ARM64_NT_NEON128 {
    بنية {
      ULONGLONG هيٺيون_3;
      LONGLONG مٿاهون_3;
    } DUMMYSTRUCTNAME;
    مزدوج D[2];
    عائم S[4];
    لفظ_3 H[8];
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
    DWORD Begin_پتو;
    DWORD Unwind_معلومات;
  } RUNTIME_FUNCTION,*PRUNTIME_FUNCTION;

  تعريفنوع PRUNTIME_FUNCTION (*PGET_RUNTIME_FUNCTION_CALLBACK)(DWORD64 ControlPc,PVOID Context);
  تعريفنوع DWORD (*POUT_جو_PROCESS_FUNCTION_جدول_CALLBACK)(HANDLE Process,PVOID جدول_پتو,PDWORD Entries,PRUNTIME_FUNCTION *Functions);

#جيڪڏهن_پورو /* _ARM64_ */

#إذا (defined _ARM64_ || defined _AMD64_) && !defined RC_INVOKED
  NTSYSAPI VOID __cdecl RtlRestoreContext (PCONTEXT Context_رڪارڊ,بنية EXCEPTION_رڪارڊ *Exception_رڪارڊ);
  NTSYSAPI BOOLEAN __cdecl Rtl_جوڙيو_Function_جدول(PRUNTIME_FUNCTION Function_جدول,DWORD داخلا_ڳڻپ,DWORD64 بنياد_پتو);
  NTSYSAPI BOOLEAN __cdecl Rtl_Install_Function_جدول_Callback(DWORD64 جدول_Identifier,DWORD64 بنياد_پتو,DWORD ڊيگهائي_2,PGET_RUNTIME_FUNCTION_CALLBACK Callback,PVOID Context,PCWSTR ٻاهريون_جو_Process_Callback_Dll);
  NTSYSAPI BOOLEAN __cdecl Rtl_Delete_Function_جدول(PRUNTIME_FUNCTION Function_جدول);
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل I_X86_
#إذا(defined(_X86_) && !defined(__x86_64)) && !defined(RC_INVOKED)
#جيڪڏهن_وصف_ٿيل __cplusplus
  خارجي "C" {
#جيڪڏهن_پورو

    __CRT_INLINE BOOLEAN Interlocked_ٻٽو_انگ_Test_And_سيٽ(LONG *بنياد_2,LONG ٻٽو_انگ_2) {
      صحيح old = 0;
      __asm__ __volatile__("lock ; btsl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متطاير ڊگهو *) بنياد_2))
	:"Ir" (ٻٽو_انگ_2));
      أرجع (BOOLEAN) (old!=0);
    }

    __CRT_INLINE BOOLEAN Interlocked_ٻٽو_انگ_Test_And_Reset(LONG *بنياد_2,LONG ٻٽو_انگ_2) {
      صحيح old = 0;
      __asm__ __volatile__("lock ; btrl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متطاير ڊگهو *) بنياد_2))
	:"Ir" (ٻٽو_انگ_2));
      أرجع (BOOLEAN) (old!=0);
    }

    __CRT_INLINE BOOLEAN Interlocked_ٻٽو_انگ_Test_And_Complement(LONG *بنياد_2,LONG ٻٽو_انگ_2) {
      صحيح old = 0;
      __asm__ __volatile__("lock ; btcl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متطاير ڊگهو *) بنياد_2))
	:"Ir" (ٻٽو_انگ_2));
      أرجع (BOOLEAN) (old!=0);
    }

#جيڪڏهن_وصف_ٿيل اڳياڙي_2
    BYTE __readfsbyte(DWORD وٿي_3);
    لفظ_3 __readfsword(DWORD وٿي_3);
    DWORD __readfsdword(DWORD وٿي_3);
    VOID __writefsbyte(DWORD وٿي_3,BYTE معلومات_3);
    VOID __writefsword(DWORD وٿي_3,لفظ_3 معلومات_3);
    VOID __writefsdword(DWORD وٿي_3,DWORD معلومات_3);
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل __cplusplus
  }
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#إذا(defined(_X86_) && !defined(__x86_64))
  __CRT_INLINE VOID يادگيري_Barrier(VOID) {
    LONG Barrier;
    __asm__ __volatile__("xchgl %%eax,%0 "
      :"=r" (Barrier));
  }
#وصف_ڪريو YieldProcessor() __asm__ __volatile__("rep nop ");

#وصف_ڪريو Pre_Fetch_Cache_سٽ(l,a)
#وصف_ڪريو ReadForWriteAccess(p) (*(p))

#وصف_ڪريو PF_TEMPORAL_LEVEL_1
#وصف_ڪريو PF_NON_TEMPORAL_LEVEL_ALL

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
#جيڪڏهن_پورو

#وصف_ڪريو EXCEPTION_READ_FAULT 0
#وصف_ڪريو EXCEPTION_WRITE_FAULT 1
#وصف_ڪريو EXCEPTION_EXECUTE_FAULT 8

#وصف_ڪريو سائيز_جو_80387_REGISTERS 80

#إذا !defined(RC_INVOKED)

#وصف_ڪريو CONTEXT_i386 0x00010000
#وصف_ڪريو CONTEXT_i486 0x00010000

#وصف_ڪريو CONTEXT_CONTROL (CONTEXT_i386 | 0x00000001L)
#وصف_ڪريو CONTEXT_INTEGER (CONTEXT_i386 | 0x00000002L)
#وصف_ڪريو CONTEXT_SEGMENTS (CONTEXT_i386 | 0x00000004L)
#وصف_ڪريو CONTEXT_FLOATING_نقطو (CONTEXT_i386 | 0x00000008L)
#وصف_ڪريو CONTEXT_DEBUG_REGISTERS (CONTEXT_i386 | 0x00000010L)
#وصف_ڪريو CONTEXT_EXTENDED_REGISTERS (CONTEXT_i386 | 0x00000020L)

#وصف_ڪريو CONTEXT_ڀريل (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_SEGMENTS)

#وصف_ڪريو CONTEXT_ALL (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_SEGMENTS | CONTEXT_FLOATING_نقطو | CONTEXT_DEBUG_REGISTERS | CONTEXT_EXTENDED_REGISTERS)
#جيڪڏهن_پورو

#وصف_ڪريو وڌ_کان_وڌ_SUPPORTED_EXTENSION 512

    تعريفنوع بنية _FLOATING_SAVE_AREA {
      DWORD Control_لفظ;
      DWORD حالت_لفظ;
      DWORD ٽيگ_لفظ;
      DWORD Error_وٿي;
      DWORD ErrorSelector;
      DWORD معلومات_وٿي_2;
      DWORD معلومات_Selector;
      BYTE رجسٽر_Area[سائيز_جو_80387_REGISTERS];
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
      BYTE ExtendedRegisters[وڌ_کان_وڌ_SUPPORTED_EXTENSION];
    } CONTEXT;

    تعريفنوع CONTEXT *PCONTEXT;
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل LDT_داخلا_DEFINED
#وصف_ڪريو LDT_داخلا_DEFINED

    تعريفنوع بنية LDT_داخلا {
      لفظ_3 حد_بندي_هيٺيون;
      لفظ_3 بنياد_هيٺيون;
      اتحاد {
	بنية {
	  BYTE بنياد_Mid;
	  BYTE Flags1;
	  BYTE Flags2;
	  BYTE بنياد_Hi;
	} بائيٽون_2;
	بنية {
	  DWORD بنياد_Mid : 8;
	  DWORD Type : 5;
	  DWORD Dpl : 2;
	  DWORD Pres : 1;
	  DWORD حد_بندي_Hi : 4;
	  DWORD Sys : 1;
	  DWORD Reserved_0 : 1;
	  DWORD Default_Big : 1;
	  DWORD Granularity : 1;
	  DWORD بنياد_Hi : 8;
	} بٽ_2;
      } مٿاهون_لفظ;
    } LDT_داخلا_2,*PLDT_داخلا;
#جيڪڏهن_پورو

#إذا defined(__ia64__) && !defined(RC_INVOKED)

#جيڪڏهن_وصف_ٿيل __cplusplus
    خارجي "C" {
#جيڪڏهن_پورو

      BOOLEAN ٻٽو_انگ_جاچ_Forward64(DWORD *اشاريو_3,DWORD64 نقاب_3);
      BOOLEAN ٻٽو_انگ_جاچ_Reverse64(DWORD *اشاريو_3,DWORD64 نقاب_3);

#جيڪڏهن_وصف_ٿيل __cplusplus
    }
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#إذا !defined(GENUTIL) && !defined(_GENIA64_) && defined(_IA64_)

    فراغ *_cdecl _rdteb(فراغ);
#جيڪڏهن_وصف_ٿيل __ia64__

#وصف_ڪريو NtCurrentTeb() ((بنية _TEB *)_rdteb())
#وصف_ڪريو GetCurrentFiber() (((PNT_TIB)NtCurrentTeb())->Fiber_معلومات)
#وصف_ڪريو Get_Fiber_معلومات() (*(PVOID *)(GetCurrentFiber()))

#جيڪڏهن_وصف_ٿيل __cplusplus
    خارجي "C" {
#جيڪڏهن_پورو

      فراغ __break(صحيح);
      فراغ __yield(فراغ);
      فراغ __mf(فراغ);
      فراغ __lfetch(صحيح Level,VOID CONST *پتو_2);
      فراغ __lfetchfault(صحيح Level,VOID CONST *پتو_2);
      فراغ __lfetch_excl(صحيح Level,VOID CONST *پتو_2);
      فراغ __lfetchfault_excl(صحيح Level,VOID CONST *پتو_2);

#وصف_ڪريو MD_LFHINT_NONE 0x00
#وصف_ڪريو MD_LFHINT_NT1 0x01
#وصف_ڪريو MD_LFHINT_NT2 0x02
#وصف_ڪريو MD_LFHINT_NTA 0x03

#جيڪڏهن_وصف_ٿيل __cplusplus
    }
#جيڪڏهن_پورو

#وصف_ڪريو YieldProcessor __yield
#وصف_ڪريو يادگيري_Barrier __mf
#وصف_ڪريو Pre_Fetch_Cache_سٽ __lfetch
#وصف_ڪريو ReadForWriteAccess(p) (*(p))
#وصف_ڪريو DbgRaiseAssertionFailure() __break(ASSERT_BREAKPOINT)

#وصف_ڪريو PF_TEMPORAL_LEVEL_1 MD_LFHINT_NONE
#وصف_ڪريو PF_NON_TEMPORAL_LEVEL_ALL MD_LFHINT_NTA

#وصف_ڪريو Unsigned_Multiply_مٿاهون __UMULH

    ULONGLONG Unsigned_Multiply_مٿاهون(ULONGLONG Multiplier,ULONGLONG Multiplicand);
#وإلا
    بنية _TEB *NtCurrentTeb(فراغ);
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل _IA64_

#وصف_ڪريو EXCEPTION_READ_FAULT 0
#وصف_ڪريو EXCEPTION_WRITE_FAULT 1
#وصف_ڪريو EXCEPTION_EXECUTE_FAULT 2

#إذا !defined(RC_INVOKED)

#وصف_ڪريو CONTEXT_IA64 0x00080000

#وصف_ڪريو CONTEXT_CONTROL (CONTEXT_IA64 | 0x00000001L)
#وصف_ڪريو CONTEXT_هيٺاهون_FLOATING_نقطو (CONTEXT_IA64 | 0x00000002L)
#وصف_ڪريو CONTEXT_HIGHER_FLOATING_نقطو (CONTEXT_IA64 | 0x00000004L)
#وصف_ڪريو CONTEXT_INTEGER (CONTEXT_IA64 | 0x00000008L)
#وصف_ڪريو CONTEXT_DEBUG (CONTEXT_IA64 | 0x00000010L)
#وصف_ڪريو CONTEXT_IA32_CONTROL (CONTEXT_IA64 | 0x00000020L)

#وصف_ڪريو CONTEXT_FLOATING_نقطو (CONTEXT_هيٺاهون_FLOATING_نقطو | CONTEXT_HIGHER_FLOATING_نقطو)
#وصف_ڪريو CONTEXT_ڀريل (CONTEXT_CONTROL | CONTEXT_FLOATING_نقطو | CONTEXT_INTEGER | CONTEXT_IA32_CONTROL)
#وصف_ڪريو CONTEXT_ALL (CONTEXT_CONTROL | CONTEXT_FLOATING_نقطو | CONTEXT_INTEGER | CONTEXT_DEBUG | CONTEXT_IA32_CONTROL)

#وصف_ڪريو CONTEXT_EXCEPTION_سرگرم 0x8000000
#وصف_ڪريو CONTEXT_SERVICE_سرگرم 0x10000000
#وصف_ڪريو CONTEXT_EXCEPTION_REQUEST 0x40000000
#وصف_ڪريو CONTEXT_EXCEPTION_REPORTING 0x80000000
#جيڪڏهن_پورو

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
      ULONGLONG داخلا_نقطو;
      ULONGLONG Global_اشارو_2;
    } PLABEL_DESCRIPTOR,*PPLABEL_DESCRIPTOR;

    تعريفنوع بنية _RUNTIME_FUNCTION {
      DWORD Begin_پتو;
      DWORD پڇاڙي_پتو;
      DWORD Unwind_Info_پتو;
    } RUNTIME_FUNCTION,*PRUNTIME_FUNCTION;

    تعريفنوع PRUNTIME_FUNCTION (*PGET_RUNTIME_FUNCTION_CALLBACK)(DWORD64 ControlPc,PVOID Context);
    تعريفنوع DWORD (*POUT_جو_PROCESS_FUNCTION_جدول_CALLBACK)(HANDLE Process,PVOID جدول_پتو,PDWORD Entries,PRUNTIME_FUNCTION *Functions);

#وصف_ڪريو ٻاهريون_جو_PROCESS_FUNCTION_جدول_CALLBACK_EXPORT_NAME "OutOfProcessFunctionTableCallback"

    BOOLEAN Rtl_جوڙيو_Function_جدول(PRUNTIME_FUNCTION Function_جدول,DWORD داخلا_ڳڻپ,ULONGLONG بنياد_پتو,ULONGLONG هدف_Gp);
    BOOLEAN Rtl_Install_Function_جدول_Callback(DWORD64 جدول_Identifier,DWORD64 بنياد_پتو,DWORD ڊيگهائي_2,DWORD64 هدف_Gp,PGET_RUNTIME_FUNCTION_CALLBACK Callback,PVOID Context,PCWSTR ٻاهريون_جو_Process_Callback_Dll);
    BOOLEAN Rtl_Delete_Function_جدول(PRUNTIME_FUNCTION Function_جدول);
    VOID RtlRestoreContext (PCONTEXT Context_رڪارڊ,بنية EXCEPTION_رڪارڊ *Exception_رڪارڊ);
    VOID __jump_unwind(ULONGLONG هدف_Ms_چوکٺو,ULONGLONG هدف_Bs_چوکٺو,ULONGLONG هدف_Pc);
#جيڪڏهن_پورو

#وصف_ڪريو EXCEPTION_NONCONTINUABLE 0x1
#وصف_ڪريو EXCEPTION_وڌ_کان_وڌ_PARAMETERS 15

    تعريفنوع بنية EXCEPTION_رڪارڊ {
      DWORD Exception_ڪوڊ;
      DWORD ExceptionFlags;
      بنية EXCEPTION_رڪارڊ *Exception_رڪارڊ;
      PVOID Exception_پتو;
      DWORD عدد_Parameters;
      ULONG_PTR ExceptionInformation[EXCEPTION_وڌ_کان_وڌ_PARAMETERS];
    } EXCEPTION_رڪارڊ_2;

    تعريفنوع EXCEPTION_رڪارڊ_2 *PEXCEPTION_رڪارڊ;

    تعريفنوع بنية _EXCEPTION_RECORD32 {
      DWORD Exception_ڪوڊ;
      DWORD ExceptionFlags;
      DWORD Exception_رڪارڊ;
      DWORD Exception_پتو;
      DWORD عدد_Parameters;
      DWORD ExceptionInformation[EXCEPTION_وڌ_کان_وڌ_PARAMETERS];
    } EXCEPTION_RECORD32,*PEXCEPTION_RECORD32;

    تعريفنوع بنية _EXCEPTION_RECORD64 {
      DWORD Exception_ڪوڊ;
      DWORD ExceptionFlags;
      DWORD64 Exception_رڪارڊ;
      DWORD64 Exception_پتو;
      DWORD عدد_Parameters;
      DWORD __unusedAlignment;
      DWORD64 ExceptionInformation[EXCEPTION_وڌ_کان_وڌ_PARAMETERS];
    } EXCEPTION_RECORD64,*PEXCEPTION_RECORD64;

    تعريفنوع بنية EXCEPTION_اشارا_2 {
      PEXCEPTION_رڪارڊ Exception_رڪارڊ;
      PCONTEXT Context_رڪارڊ;
    } EXCEPTION_اشارا,*PEXCEPTION_اشارا;

#جيڪڏهن_وصف_ٿيل __x86_64

    تعريفنوع EXCEPTION_DISPOSITION NTAPI EXCEPTION_ROUTINE (بنية EXCEPTION_رڪارڊ *Exception_رڪارڊ, PVOID Establisher_چوکٺو_2, بنية _CONTEXT *Context_رڪارڊ, PVOID DispatcherContext);
#جيڪڏهن_وصف_نه_ٿيل __PEXCEPTION_ROUTINE_DEFINED
#وصف_ڪريو __PEXCEPTION_ROUTINE_DEFINED
    تعريفنوع EXCEPTION_ROUTINE *PEXCEPTION_ROUTINE;
#جيڪڏهن_پورو

    /* http://msdn.microsoft.com/en-us/library/ms680597(VS.85).aspx */

#وصف_ڪريو UNWIND_HISTORY_جدول_سائيز 12

  تعريفنوع بنية UNWIND_HISTORY_جدول_داخلا {
    ULONG64 Image_بنياد;
    PRUNTIME_FUNCTION Function_داخلا;
  } UNWIND_HISTORY_جدول_داخلا_2, *PUNWIND_HISTORY_جدول_داخلا;

#وصف_ڪريو UNWIND_HISTORY_جدول_NONE    0
#وصف_ڪريو UNWIND_HISTORY_جدول_GLOBAL  1
#وصف_ڪريو UNWIND_HISTORY_جدول_LOCAL   2

  تعريفنوع بنية UNWIND_HISTORY_جدول {
    ULONG ڳڻپ_3;
    UCHAR ڳولا;
    ULONG64 هيٺيون_پتو;
    ULONG64 مٿاهون_پتو;
    UNWIND_HISTORY_جدول_داخلا_2 داخلا_2[UNWIND_HISTORY_جدول_سائيز];
  } UNWIND_HISTORY_جدول_2, *PUNWIND_HISTORY_جدول;

  /* http://msdn.microsoft.com/en-us/library/b6sf5kbd(VS.80).aspx */

  بنية _DISPATCHER_CONTEXT;
  تعريفنوع بنية _DISPATCHER_CONTEXT DISPATCHER_CONTEXT;
  تعريفنوع بنية _DISPATCHER_CONTEXT *PDISPATCHER_CONTEXT;

  بنية _DISPATCHER_CONTEXT {
    ULONG64 ControlPc;
    ULONG64 Image_بنياد;
    PRUNTIME_FUNCTION Function_داخلا;
    ULONG64 Establisher_چوکٺو_2;
    ULONG64 هدف_Ip;
    PCONTEXT Context_رڪارڊ;
    PEXCEPTION_ROUTINE LanguageHandler;
    PVOID Handler_معلومات;
    /* http://www.nynaeve.net/?p=99 */
    PUNWIND_HISTORY_جدول History_جدول;
    ULONG Scope_اشاريو;
    ULONG Fill0;
  };

  /* http://msdn.microsoft.com/en-us/library/ms680617(VS.85).aspx */

  تعريفنوع بنية KNONVOLATILE_CONTEXT_اشارا
  {
    PM128A FloatingContext[16];
    PULONG64 IntegerContext[16];
  } KNONVOLATILE_CONTEXT_اشارا_2, *PKNONVOLATILE_CONTEXT_اشارا;
#جيڪڏهن_پورو /* defined(__x86_64) */

    تعريفنوع PVOID PACCESS_TOKEN;
    تعريفنوع PVOID PSECURITY_DESCRIPTOR;
    تعريفنوع PVOID PSID;

    تعريفنوع DWORD ACCESS_نقاب;
    تعريفنوع ACCESS_نقاب *PACCESS_نقاب;

#وصف_ڪريو DELETE (0x00010000L)
#وصف_ڪريو READ_CONTROL (0x00020000L)
#وصف_ڪريو WRITE_DAC (0x00040000L)
#وصف_ڪريو WRITE_OWNER (0x00080000L)
#وصف_ڪريو SYNCHRONIZE (0x00100000L)

#وصف_ڪريو STANDARD_RIGHTS_REQUIRED (0x000F0000L)
#وصف_ڪريو STANDARD_RIGHTS_READ (READ_CONTROL)
#وصف_ڪريو STANDARD_RIGHTS_WRITE (READ_CONTROL)
#وصف_ڪريو STANDARD_RIGHTS_EXECUTE (READ_CONTROL)
#وصف_ڪريو STANDARD_RIGHTS_ALL (0x001F0000L)

#وصف_ڪريو SPECIFIC_RIGHTS_ALL (0x0000FFFFL)

#وصف_ڪريو ACCESS_SYSTEM_SECURITY (0x01000000L)

#وصف_ڪريو وڌ_کان_وڌ_ALLOWED (0x02000000L)

#وصف_ڪريو GENERIC_READ (0x80000000L)
#وصف_ڪريو GENERIC_WRITE (0x40000000L)
#وصف_ڪريو GENERIC_EXECUTE (0x20000000L)
#وصف_ڪريو GENERIC_ALL (0x10000000L)

    تعريفنوع بنية _GENERIC_MAPPING {
      ACCESS_نقاب GenericRead;
      ACCESS_نقاب GenericWrite;
      ACCESS_نقاب GenericExecute;
      ACCESS_نقاب GenericAll;
    } GENERIC_MAPPING;
    تعريفنوع GENERIC_MAPPING *PGENERIC_MAPPING;

#ضمن <pshpack4.h>

    تعريفنوع بنية LUID_AND_خاصيتون {
      LUID Luid;
      DWORD خاصيتون;
    } LUID_AND_خاصيتون_2,*PLUID_AND_خاصيتون;
    تعريفنوع LUID_AND_خاصيتون_2 LUID_AND_خاصيتون_ARRAY[ANYSIZE_ARRAY];
    تعريفنوع LUID_AND_خاصيتون_ARRAY *PLUID_AND_خاصيتون_ARRAY;

#ضمن <poppack.h>

#جيڪڏهن_وصف_نه_ٿيل SID_IDENTIFIER_AUTHORITY_DEFINED
#وصف_ڪريو SID_IDENTIFIER_AUTHORITY_DEFINED
    تعريفنوع بنية _SID_IDENTIFIER_AUTHORITY {
      BYTE قدر_3[6];
    } SID_IDENTIFIER_AUTHORITY,*PSID_IDENTIFIER_AUTHORITY;
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل SID_DEFINED
#وصف_ڪريو SID_DEFINED
    تعريفنوع بنية _SID {
      BYTE Revision;
      BYTE Sub_Authority_ڳڻپ;
      SID_IDENTIFIER_AUTHORITY IdentifierAuthority;
      DWORD SubAuthority[ANYSIZE_ARRAY];
    } SID,*PISID;
#جيڪڏهن_پورو

#وصف_ڪريو SID_REVISION (1)
#وصف_ڪريو SID_MAX_SUB_AUTHORITIES (15)
#وصف_ڪريو SID_RECOMMENDED_SUB_AUTHORITIES (1)

#وصف_ڪريو SECURITY_MAX_SID_سائيز (حجم(SID) - حجم(DWORD) + (SID_MAX_SUB_AUTHORITIES *حجم(DWORD)))

    تعريفنوع تعداد _SID_NAME_USE {
      SidTypeUser = 1,Sid_Type_گروهه,SidTypeDomain,SidTypeAlias,Sid_Type_Well_معلوم_گروهه,SidTypeDeletedAccount,SidTypeInvalid,SidTypeUnknown,SidTypeComputer
    } SID_NAME_USE,*PSID_NAME_USE;

    تعريفنوع بنية SID_AND_خاصيتون {
      PSID Sid;
      DWORD خاصيتون;
    } SID_AND_خاصيتون_2,*PSID_AND_خاصيتون;

    تعريفنوع SID_AND_خاصيتون_2 SID_AND_خاصيتون_ARRAY[ANYSIZE_ARRAY];
    تعريفنوع SID_AND_خاصيتون_ARRAY *PSID_AND_خاصيتون_ARRAY;

#وصف_ڪريو SECURITY_NULL_SID_AUTHORITY {0,0,0,0,0,0}
#وصف_ڪريو SECURITY_WORLD_SID_AUTHORITY {0,0,0,0,0,1}
#وصف_ڪريو SECURITY_LOCAL_SID_AUTHORITY {0,0,0,0,0,2}
#وصف_ڪريو SECURITY_CREATOR_SID_AUTHORITY {0,0,0,0,0,3}
#وصف_ڪريو SECURITY_NON_UNIQUE_AUTHORITY {0,0,0,0,0,4}
#وصف_ڪريو SECURITY_RESOURCE_MANAGER_AUTHORITY {0,0,0,0,0,9}

#وصف_ڪريو SECURITY_NULL_RID (0x00000000L)
#وصف_ڪريو SECURITY_WORLD_RID (0x00000000L)
#وصف_ڪريو SECURITY_LOCAL_RID (0x00000000L)

#وصف_ڪريو SECURITY_CREATOR_OWNER_RID (0x00000000L)
#وصف_ڪريو SECURITY_CREATOR_گروهه_RID (0x00000001L)

#وصف_ڪريو SECURITY_CREATOR_OWNER_SERVER_RID (0x00000002L)
#وصف_ڪريو SECURITY_CREATOR_گروهه_SERVER_RID (0x00000003L)

#وصف_ڪريو SECURITY_NT_AUTHORITY {0,0,0,0,0,5}

#وصف_ڪريو SECURITY_DIALUP_RID (0x00000001L)
#وصف_ڪريو SECURITY_ڄار_RID (0x00000002L)
#وصف_ڪريو SECURITY_BATCH_RID (0x00000003L)
#وصف_ڪريو SECURITY_INTERACTIVE_RID (0x00000004L)
#وصف_ڪريو SECURITY_LOGON_IDS_RID (0x00000005L)
#وصف_ڪريو SECURITY_LOGON_IDS_RID_ڳڻپ (3L)
#وصف_ڪريو SECURITY_SERVICE_RID (0x00000006L)
#وصف_ڪريو SECURITY_ANONYMOUS_LOGON_RID (0x00000007L)
#وصف_ڪريو SECURITY_PROXY_RID (0x00000008L)
#وصف_ڪريو SECURITY_ENTERPRISE_CONTROLLERS_RID (0x00000009L)
#وصف_ڪريو SECURITY_SERVER_LOGON_RID SECURITY_ENTERPRISE_CONTROLLERS_RID
#وصف_ڪريو SECURITY_PRINCIPAL_SELF_RID (0x0000000AL)
#وصف_ڪريو SECURITY_AUTHENTICATED_USER_RID (0x0000000BL)
#وصف_ڪريو SECURITY_RESTRICTED_ڪوڊ_RID (0x0000000CL)
#وصف_ڪريو SECURITY_TERMINAL_SERVER_RID (0x0000000DL)
#وصف_ڪريو SECURITY_REMOTE_LOGON_RID (0x0000000EL)
#وصف_ڪريو SECURITY_THIS_ORGANIZATION_RID (0x0000000FL)
#وصف_ڪريو SECURITY_IUSER_RID (0x00000011L)

#وصف_ڪريو SECURITY_LOCAL_SYSTEM_RID (0x00000012L)
#وصف_ڪريو SECURITY_LOCAL_SERVICE_RID (0x00000013L)
#وصف_ڪريو SECURITY_ڄار_SERVICE_RID (0x00000014L)

#وصف_ڪريو SECURITY_NT_NON_UNIQUE (0x00000015L)
#وصف_ڪريو SECURITY_NT_NON_UNIQUE_SUB_AUTH_ڳڻپ (3L)

#وصف_ڪريو SECURITY_ENTERPRISE_READONLY_CONTROLLERS_RID (0x00000016L)

#وصف_ڪريو SECURITY_BUILTIN_DOMAIN_RID (0x00000020L)
#وصف_ڪريو SECURITY_WRITE_RESTRICTED_ڪوڊ_RID (0x00000021L)

#وصف_ڪريو SECURITY_PACKAGE_بنياد_RID (0x00000040L)
#وصف_ڪريو SECURITY_PACKAGE_RID_ڳڻپ (2L)
#وصف_ڪريو SECURITY_PACKAGE_NTLM_RID (0x0000000AL)
#وصف_ڪريو SECURITY_PACKAGE_SCHANNEL_RID (0x0000000EL)
#وصف_ڪريو SECURITY_PACKAGE_DIGEST_RID (0x00000015L)

#وصف_ڪريو SECURITY_SERVICE_ID_بنياد_RID (0x00000050L)
#وصف_ڪريو SECURITY_SERVICE_ID_RID_ڳڻپ (6L)

#وصف_ڪريو SECURITY_RESERVED_ID_بنياد_RID (0x00000051L)

#وصف_ڪريو SECURITY_MAX_ALWAYS_FILTERED (0x000003E7L)
#وصف_ڪريو SECURITY_MIN_NEVER_FILTERED (0x000003E8L)

#وصف_ڪريو SECURITY_OTHER_ORGANIZATION_RID (0x000003E8L)

#وصف_ڪريو FOREST_USER_RID_MAX (0x000001F3L)

#وصف_ڪريو DOMAIN_USER_RID_ADMIN (0x000001F4L)
#وصف_ڪريو DOMAIN_USER_RID_GUEST (0x000001F5L)
#وصف_ڪريو DOMAIN_USER_RID_KRBTGT (0x000001F6L)

#وصف_ڪريو DOMAIN_USER_RID_MAX (0x000003E7L)

#وصف_ڪريو DOMAIN_گروهه_RID_ADMINS (0x00000200L)
#وصف_ڪريو DOMAIN_گروهه_RID_USERS (0x00000201L)
#وصف_ڪريو DOMAIN_گروهه_RID_GUESTS (0x00000202L)
#وصف_ڪريو DOMAIN_گروهه_RID_COMPUTERS (0x00000203L)
#وصف_ڪريو DOMAIN_گروهه_RID_CONTROLLERS (0x00000204L)
#وصف_ڪريو DOMAIN_گروهه_RID_CERT_ADMINS (0x00000205L)
#وصف_ڪريو DOMAIN_گروهه_RID_SCHEMA_ADMINS (0x00000206L)
#وصف_ڪريو DOMAIN_گروهه_RID_ENTERPRISE_ADMINS (0x00000207L)
#وصف_ڪريو DOMAIN_گروهه_RID_POLICY_ADMINS (0x00000208L)
#وصف_ڪريو DOMAIN_گروهه_RID_READONLY_CONTROLLERS (0x00000209L)

#وصف_ڪريو DOMAIN_ALIAS_RID_ADMINS (0x00000220L)
#وصف_ڪريو DOMAIN_ALIAS_RID_USERS (0x00000221L)
#وصف_ڪريو DOMAIN_ALIAS_RID_GUESTS (0x00000222L)
#وصف_ڪريو DOMAIN_ALIAS_RID_POWER_USERS (0x00000223L)

#وصف_ڪريو DOMAIN_ALIAS_RID_ACCOUNT_OPS (0x00000224L)
#وصف_ڪريو DOMAIN_ALIAS_RID_SYSTEM_OPS (0x00000225L)
#وصف_ڪريو DOMAIN_ALIAS_RID_PRINT_OPS (0x00000226L)
#وصف_ڪريو DOMAIN_ALIAS_RID_BACKUP_OPS (0x00000227L)

#وصف_ڪريو DOMAIN_ALIAS_RID_REPLICATOR (0x00000228L)
#وصف_ڪريو DOMAIN_ALIAS_RID_RAS_SERVERS (0x00000229L)
#وصف_ڪريو DOMAIN_ALIAS_RID_PREW2KCOMPACCESS (0x0000022AL)
#وصف_ڪريو DOMAIN_ALIAS_RID_REMOTE_DESKTOP_USERS (0x0000022BL)
#وصف_ڪريو DOMAIN_ALIAS_RID_ڄار_CONFIGURATION_OPS (0x0000022CL)
#وصف_ڪريو DOMAIN_ALIAS_RID_INCOMING_FOREST_TRUST_BUILDERS (0x0000022DL)

#وصف_ڪريو DOMAIN_ALIAS_RID_MONITORING_USERS (0x0000022EL)
#وصف_ڪريو DOMAIN_ALIAS_RID_LOGGING_USERS (0x0000022FL)
#وصف_ڪريو DOMAIN_ALIAS_RID_AUTHORIZATIONACCESS (0x00000230L)
#وصف_ڪريو DOMAIN_ALIAS_RID_TS_LICENSE_SERVERS (0x00000231L)
#وصف_ڪريو DOMAIN_ALIAS_RID_DCOM_USERS (0x00000232L)

#وصف_ڪريو DOMAIN_ALIAS_RID_IUSERS (0x00000238L)
#وصف_ڪريو DOMAIN_ALIAS_RID_CRYPTO_OPERATORS (0x00000239L)
#وصف_ڪريو DOMAIN_ALIAS_RID_CACHEABLE_PRINCIPALS_گروهه (0x0000023BL)
#وصف_ڪريو DOMAIN_ALIAS_RID_NON_CACHEABLE_PRINCIPALS_گروهه (0x0000023CL)
#وصف_ڪريو DOMAIN_ALIAS_RID_EVENT_LOG_READERS_گروهه (0x0000023DL)

#وصف_ڪريو SECURITY_MANDATORY_LABEL_AUTHORITY {0,0,0,0,0,16}
#وصف_ڪريو SECURITY_MANDATORY_UNTRUSTED_RID (0x00000000L)
#وصف_ڪريو SECURITY_MANDATORY_هيٺيون_RID (0x00001000L)
#وصف_ڪريو SECURITY_MANDATORY_MEDIUM_RID (0x00002000L)
#وصف_ڪريو SECURITY_MANDATORY_مٿاهون_RID (0x00003000L)
#وصف_ڪريو SECURITY_MANDATORY_SYSTEM_RID (0x00004000L)
#وصف_ڪريو SECURITY_MANDATORY_PROTECTED_PROCESS_RID (0x00005000L)

#وصف_ڪريو SECURITY_MANDATORY_وڌ_کان_وڌ_USER_RID SECURITY_MANDATORY_SYSTEM_RID

#وصف_ڪريو MANDATORY_LEVEL_منزل_MANDATORY_RID(IL) (IL * 0x1000)

    تعريفنوع تعداد {
      WinNullSid = 0,WinWorldSid = 1,WinLocalSid = 2,WinCreatorOwnerSid = 3,Win_Creator_گروهه_Sid = 4,WinCreatorOwnerServerSid = 5,Win_Creator_گروهه_Server_Sid = 6,WinNtAuthoritySid = 7,WinDialupSid = 8,Win_ڄار_Sid = 9,WinBatchSid = 10,WinInteractiveSid = 11,WinServiceSid = 12,WinAnonymousSid = 13,WinProxySid = 14,WinEnterpriseControllersSid = 15,WinSelfSid = 16,WinAuthenticatedUserSid = 17,Win_Restricted_ڪوڊ_Sid = 18,WinTerminalServerSid = 19,WinRemoteLogonIdSid = 20,WinLogonIdsSid = 21,WinLocalSystemSid = 22,WinLocalServiceSid = 23,Win_ڄار_Service_Sid = 24,WinBuiltinDomainSid = 25,WinBuiltinAdministratorsSid = 26,WinBuiltinUsersSid = 27,WinBuiltinGuestsSid = 28,WinBuiltinPowerUsersSid = 29,WinBuiltinAccountOperatorsSid = 30,WinBuiltinSystemOperatorsSid = 31,WinBuiltinPrintOperatorsSid = 32,WinBuiltinBackupOperatorsSid = 33,WinBuiltinReplicatorSid = 34,WinBuiltinPreWindows2000CompatibleAccessSid = 35,WinBuiltinRemoteDesktopUsersSid = 36,Win_Builtin_ڄار_Configuration_Operators_Sid = 37,WinAccountAdministratorSid = 38,WinAccountGuestSid = 39,WinAccountKrbtgtSid = 40,WinAccountDomainAdminsSid = 41,WinAccountDomainUsersSid = 42,WinAccountDomainGuestsSid = 43,WinAccountComputersSid = 44,WinAccountControllersSid = 45,WinAccountCertAdminsSid = 46,WinAccountSchemaAdminsSid = 47,WinAccountEnterpriseAdminsSid = 48,WinAccountPolicyAdminsSid = 49,WinAccountRasAndIasServersSid = 50,WinNTLMAuthenticationSid = 51,WinDigestAuthenticationSid = 52,WinSChannelAuthenticationSid = 53,WinThisOrganizationSid = 54,WinOtherOrganizationSid = 55,WinBuiltinIncomingForestTrustBuildersSid = 56,WinBuiltinPerfMonitoringUsersSid = 57,WinBuiltinPerfLoggingUsersSid = 58,WinBuiltinAuthorizationAccessSid = 59,WinBuiltinTerminalServerLicenseServersSid = 60,WinBuiltinDCOMUsersSid = 61
    } WELL_معلوم_SID_TYPE;

#وصف_ڪريو SYSTEM_LUID { 0x3E7,0x0 }
#وصف_ڪريو ANONYMOUS_LOGON_LUID { 0x3e6,0x0 }
#وصف_ڪريو LOCALSERVICE_LUID { 0x3e5,0x0 }
#وصف_ڪريو NETWORKSERVICE_LUID { 0x3e4,0x0 }
#وصف_ڪريو IUSER_LUID { 0x3e3, 0x0 }

#وصف_ڪريو SE_گروهه_MANDATORY (0x00000001L)
#وصف_ڪريو SE_گروهه_ENABLED_BY_DEFAULT (0x00000002L)
#وصف_ڪريو SE_گروهه_ENABLED (0x00000004L)
#وصف_ڪريو SE_گروهه_OWNER (0x00000008L)
#وصف_ڪريو SE_گروهه_USE_FOR_DENY_ONLY (0x00000010L)
#وصف_ڪريو SE_گروهه_INTEGRITY (0x00000020L)
#وصف_ڪريو SE_گروهه_INTEGRITY_ENABLED (0x00000040L)
#وصف_ڪريو SE_گروهه_LOGON_ID (0xC0000000L)
#وصف_ڪريو SE_گروهه_RESOURCE (0x20000000L)

#وصف_ڪريو ACL_REVISION (2)
#وصف_ڪريو ACL_REVISION_DS (4)

#وصف_ڪريو ACL_REVISION1 (1)
#وصف_ڪريو MIN_ACL_REVISION ACL_REVISION2
#وصف_ڪريو ACL_REVISION2 (2)
#وصف_ڪريو ACL_REVISION3 (3)
#وصف_ڪريو ACL_REVISION4 (4)
#وصف_ڪريو MAX_ACL_REVISION ACL_REVISION4

    تعريفنوع بنية _ACL {
      BYTE AclRevision;
      BYTE Sbz1;
      لفظ_3 Acl_سائيز;
      لفظ_3 Ace_ڳڻپ;
      لفظ_3 Sbz2;
    } ACL;
    تعريفنوع ACL *PACL;

    تعريفنوع بنية ACE_سرو {
      BYTE AceType;
      BYTE AceFlags;
      لفظ_3 Ace_سائيز;
    } ACE_سرو_2;
    تعريفنوع ACE_سرو_2 *PACE_سرو;

#وصف_ڪريو ACCESS_MIN_MS_ACE_TYPE (0x0)
#وصف_ڪريو ACCESS_ALLOWED_ACE_TYPE (0x0)
#وصف_ڪريو ACCESS_DENIED_ACE_TYPE (0x1)
#وصف_ڪريو SYSTEM_AUDIT_ACE_TYPE (0x2)
#وصف_ڪريو SYSTEM_ALARM_ACE_TYPE (0x3)
#وصف_ڪريو ACCESS_MAX_MS_V2_ACE_TYPE (0x3)

#وصف_ڪريو ACCESS_ALLOWED_COMPOUND_ACE_TYPE (0x4)
#وصف_ڪريو ACCESS_MAX_MS_V3_ACE_TYPE (0x4)

#وصف_ڪريو ACCESS_MIN_MS_OBJECT_ACE_TYPE (0x5)
#وصف_ڪريو ACCESS_ALLOWED_OBJECT_ACE_TYPE (0x5)
#وصف_ڪريو ACCESS_DENIED_OBJECT_ACE_TYPE (0x6)
#وصف_ڪريو SYSTEM_AUDIT_OBJECT_ACE_TYPE (0x7)
#وصف_ڪريو SYSTEM_ALARM_OBJECT_ACE_TYPE (0x8)
#وصف_ڪريو ACCESS_MAX_MS_OBJECT_ACE_TYPE (0x8)

#وصف_ڪريو ACCESS_MAX_MS_V4_ACE_TYPE (0x8)
#وصف_ڪريو ACCESS_MAX_MS_ACE_TYPE (0x8)

#وصف_ڪريو ACCESS_ALLOWED_CALLBACK_ACE_TYPE (0x9)
#وصف_ڪريو ACCESS_DENIED_CALLBACK_ACE_TYPE (0xA)
#وصف_ڪريو ACCESS_ALLOWED_CALLBACK_OBJECT_ACE_TYPE (0xB)
#وصف_ڪريو ACCESS_DENIED_CALLBACK_OBJECT_ACE_TYPE (0xC)
#وصف_ڪريو SYSTEM_AUDIT_CALLBACK_ACE_TYPE (0xD)
#وصف_ڪريو SYSTEM_ALARM_CALLBACK_ACE_TYPE (0xE)
#وصف_ڪريو SYSTEM_AUDIT_CALLBACK_OBJECT_ACE_TYPE (0xF)
#وصف_ڪريو SYSTEM_ALARM_CALLBACK_OBJECT_ACE_TYPE (0x10)

#وصف_ڪريو SYSTEM_MANDATORY_LABEL_ACE_TYPE (0x11)
#وصف_ڪريو ACCESS_MAX_MS_V5_ACE_TYPE (0x11)

#وصف_ڪريو OBJECT_INHERIT_ACE (0x1)
#وصف_ڪريو CONTAINER_INHERIT_ACE (0x2)
#وصف_ڪريو NO_PROPAGATE_INHERIT_ACE (0x4)
#وصف_ڪريو INHERIT_ONLY_ACE (0x8)
#وصف_ڪريو INHERITED_ACE (0x10)
#وصف_ڪريو VALID_INHERIT_FLAGS (0x1F)

#وصف_ڪريو SUCCESSFUL_ACCESS_ACE_FLAG (0x40)
#وصف_ڪريو FAILED_ACCESS_ACE_FLAG (0x80)

    تعريفنوع بنية _ACCESS_ALLOWED_ACE {
      ACE_سرو_2 سرو_2;
      ACCESS_نقاب نقاب_3;
      DWORD Sid_شروعات;
    } ACCESS_ALLOWED_ACE;

    تعريفنوع ACCESS_ALLOWED_ACE *PACCESS_ALLOWED_ACE;

    تعريفنوع بنية _ACCESS_DENIED_ACE {
      ACE_سرو_2 سرو_2;
      ACCESS_نقاب نقاب_3;
      DWORD Sid_شروعات;
    } ACCESS_DENIED_ACE;
    تعريفنوع ACCESS_DENIED_ACE *PACCESS_DENIED_ACE;

    تعريفنوع بنية _SYSTEM_AUDIT_ACE {
      ACE_سرو_2 سرو_2;
      ACCESS_نقاب نقاب_3;
      DWORD Sid_شروعات;
    } SYSTEM_AUDIT_ACE;
    تعريفنوع SYSTEM_AUDIT_ACE *PSYSTEM_AUDIT_ACE;

    تعريفنوع بنية _SYSTEM_ALARM_ACE {
      ACE_سرو_2 سرو_2;
      ACCESS_نقاب نقاب_3;
      DWORD Sid_شروعات;
    } SYSTEM_ALARM_ACE;
    تعريفنوع SYSTEM_ALARM_ACE *PSYSTEM_ALARM_ACE;

    تعريفنوع بنية _ACCESS_ALLOWED_OBJECT_ACE {
      ACE_سرو_2 سرو_2;
      ACCESS_نقاب نقاب_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_شروعات;
    } ACCESS_ALLOWED_OBJECT_ACE,*PACCESS_ALLOWED_OBJECT_ACE;

    تعريفنوع بنية _ACCESS_DENIED_OBJECT_ACE {
      ACE_سرو_2 سرو_2;
      ACCESS_نقاب نقاب_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_شروعات;
    } ACCESS_DENIED_OBJECT_ACE,*PACCESS_DENIED_OBJECT_ACE;

    تعريفنوع بنية _SYSTEM_AUDIT_OBJECT_ACE {
      ACE_سرو_2 سرو_2;
      ACCESS_نقاب نقاب_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_شروعات;
    } SYSTEM_AUDIT_OBJECT_ACE,*PSYSTEM_AUDIT_OBJECT_ACE;

    تعريفنوع بنية _SYSTEM_ALARM_OBJECT_ACE {
      ACE_سرو_2 سرو_2;
      ACCESS_نقاب نقاب_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_شروعات;
    } SYSTEM_ALARM_OBJECT_ACE,*PSYSTEM_ALARM_OBJECT_ACE;

    تعريفنوع بنية _ACCESS_ALLOWED_CALLBACK_ACE {
      ACE_سرو_2 سرو_2;
      ACCESS_نقاب نقاب_3;
      DWORD Sid_شروعات;

    } ACCESS_ALLOWED_CALLBACK_ACE,*PACCESS_ALLOWED_CALLBACK_ACE;

    تعريفنوع بنية _ACCESS_DENIED_CALLBACK_ACE {
      ACE_سرو_2 سرو_2;
      ACCESS_نقاب نقاب_3;
      DWORD Sid_شروعات;

    } ACCESS_DENIED_CALLBACK_ACE,*PACCESS_DENIED_CALLBACK_ACE;

    تعريفنوع بنية _SYSTEM_AUDIT_CALLBACK_ACE {
      ACE_سرو_2 سرو_2;
      ACCESS_نقاب نقاب_3;
      DWORD Sid_شروعات;

    } SYSTEM_AUDIT_CALLBACK_ACE,*PSYSTEM_AUDIT_CALLBACK_ACE;

    تعريفنوع بنية _SYSTEM_ALARM_CALLBACK_ACE {
      ACE_سرو_2 سرو_2;
      ACCESS_نقاب نقاب_3;
      DWORD Sid_شروعات;

    } SYSTEM_ALARM_CALLBACK_ACE,*PSYSTEM_ALARM_CALLBACK_ACE;

    تعريفنوع بنية _ACCESS_ALLOWED_CALLBACK_OBJECT_ACE {
      ACE_سرو_2 سرو_2;
      ACCESS_نقاب نقاب_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_شروعات;

    } ACCESS_ALLOWED_CALLBACK_OBJECT_ACE,*PACCESS_ALLOWED_CALLBACK_OBJECT_ACE;

    تعريفنوع بنية _ACCESS_DENIED_CALLBACK_OBJECT_ACE {
      ACE_سرو_2 سرو_2;
      ACCESS_نقاب نقاب_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_شروعات;

    } ACCESS_DENIED_CALLBACK_OBJECT_ACE,*PACCESS_DENIED_CALLBACK_OBJECT_ACE;

    تعريفنوع بنية _SYSTEM_AUDIT_CALLBACK_OBJECT_ACE {
      ACE_سرو_2 سرو_2;
      ACCESS_نقاب نقاب_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_شروعات;

    } SYSTEM_AUDIT_CALLBACK_OBJECT_ACE,*PSYSTEM_AUDIT_CALLBACK_OBJECT_ACE;

    تعريفنوع بنية _SYSTEM_ALARM_CALLBACK_OBJECT_ACE {
      ACE_سرو_2 سرو_2;
      ACCESS_نقاب نقاب_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_شروعات;

    } SYSTEM_ALARM_CALLBACK_OBJECT_ACE,*PSYSTEM_ALARM_CALLBACK_OBJECT_ACE;

#وصف_ڪريو ACE_OBJECT_TYPE_PRESENT 0x1
#وصف_ڪريو ACE_INHERITED_OBJECT_TYPE_PRESENT 0x2

    تعريفنوع تعداد _ACL_INFORMATION_CLASS {
      AclRevisionInformation = 1,Acl_سائيز_Information
    } ACL_INFORMATION_CLASS;

    تعريفنوع بنية _ACL_REVISION_INFORMATION {
      DWORD AclRevision;
    } ACL_REVISION_INFORMATION;
    تعريفنوع ACL_REVISION_INFORMATION *PACL_REVISION_INFORMATION;

    تعريفنوع بنية ACL_سائيز_INFORMATION {
      DWORD Ace_ڳڻپ;
      DWORD Acl_بائيٽون_اندريون_Use;
      DWORD Acl_بائيٽون_Free;
    } ACL_سائيز_INFORMATION_2;
    تعريفنوع ACL_سائيز_INFORMATION_2 *PACL_سائيز_INFORMATION;

#وصف_ڪريو SECURITY_DESCRIPTOR_REVISION (1)
#وصف_ڪريو SECURITY_DESCRIPTOR_REVISION1 (1)

#وصف_ڪريو SECURITY_DESCRIPTOR_MIN_ڊيگهائي (حجم(SECURITY_DESCRIPTOR))

    تعريفنوع لفظ_3 SECURITY_DESCRIPTOR_CONTROL,*PSECURITY_DESCRIPTOR_CONTROL;

#وصف_ڪريو SE_OWNER_DEFAULTED (0x0001)
#وصف_ڪريو SE_گروهه_DEFAULTED (0x0002)
#وصف_ڪريو SE_DACL_PRESENT (0x0004)
#وصف_ڪريو SE_DACL_DEFAULTED (0x0008)
#وصف_ڪريو SE_SACL_PRESENT (0x0010)
#وصف_ڪريو SE_SACL_DEFAULTED (0x0020)
#وصف_ڪريو SE_DACL_AUTO_INHERIT_REQ (0x0100)
#وصف_ڪريو SE_SACL_AUTO_INHERIT_REQ (0x0200)
#وصف_ڪريو SE_DACL_AUTO_INHERITED (0x0400)
#وصف_ڪريو SE_SACL_AUTO_INHERITED (0x0800)
#وصف_ڪريو SE_DACL_PROTECTED (0x1000)
#وصف_ڪريو SE_SACL_PROTECTED (0x2000)
#وصف_ڪريو SE_RM_CONTROL_VALID (0x4000)
#وصف_ڪريو SE_SELF_RELATIVE (0x8000)

    تعريفنوع بنية _SECURITY_DESCRIPTOR_RELATIVE {
      BYTE Revision;
      BYTE Sbz1;
      SECURITY_DESCRIPTOR_CONTROL Control;
      DWORD Owner;
      DWORD گروهه_2;
      DWORD Sacl;
      DWORD Dacl;
    } SECURITY_DESCRIPTOR_RELATIVE,*PISECURITY_DESCRIPTOR_RELATIVE;

    تعريفنوع بنية _SECURITY_DESCRIPTOR {
      BYTE Revision;
      BYTE Sbz1;
      SECURITY_DESCRIPTOR_CONTROL Control;
      PSID Owner;
      PSID گروهه_2;
      PACL Sacl;
      PACL Dacl;

    } SECURITY_DESCRIPTOR,*PISECURITY_DESCRIPTOR;

    تعريفنوع بنية _OBJECT_TYPE_LIST {
      لفظ_3 Level;
      لفظ_3 Sbz;
      GUID *ObjectType;
    } OBJECT_TYPE_LIST,*POBJECT_TYPE_LIST;

#وصف_ڪريو ACCESS_OBJECT_GUID 0
#وصف_ڪريو ACCESS_PROPERTY_سيٽ_GUID 1
#وصف_ڪريو ACCESS_PROPERTY_GUID 2

#وصف_ڪريو ACCESS_MAX_LEVEL 4

    تعريفنوع تعداد _AUDIT_EVENT_TYPE {
      AuditEventObjectAccess,AuditEventDirectoryServiceAccess
    } AUDIT_EVENT_TYPE,*PAUDIT_EVENT_TYPE;

#وصف_ڪريو AUDIT_ALLOW_NO_PRIVILEGE 0x1

#وصف_ڪريو ACCESS_DS_ذريعو_A "DS"
#وصف_ڪريو ACCESS_DS_ذريعو_W L"DS"
#وصف_ڪريو ACCESS_DS_OBJECT_TYPE_NAME_A "Directory Service Object"
#وصف_ڪريو ACCESS_DS_OBJECT_TYPE_NAME_W L"Directory Service Object"

#وصف_ڪريو SE_PRIVILEGE_ENABLED_BY_DEFAULT (0x00000001L)
#وصف_ڪريو SE_PRIVILEGE_ENABLED (0x00000002L)
#وصف_ڪريو SE_PRIVILEGE_REMOVED (0X00000004L)
#وصف_ڪريو SE_PRIVILEGE_استعمال_ٿيل_FOR_ACCESS (0x80000000L)

#وصف_ڪريو PRIVILEGE_سيٽ_ALL_NECESSARY (1)

    تعريفنوع بنية PRIVILEGE_سيٽ {
      DWORD Privilege_ڳڻپ;
      DWORD Control;
      LUID_AND_خاصيتون_2 Privilege[ANYSIZE_ARRAY];
    } PRIVILEGE_سيٽ_2,*PPRIVILEGE_سيٽ;

#وصف_ڪريو SE_CREATE_TOKEN_NAME متن_3("SeCreateTokenPrivilege")
#وصف_ڪريو SE_ASSIGNPRIMARYTOKEN_NAME متن_3("SeAssignPrimaryTokenPrivilege")
#وصف_ڪريو SE_تالو_يادگيري_NAME متن_3("SeLockMemoryPrivilege")
#وصف_ڪريو SE_INCREASE_QUOTA_NAME متن_3("SeIncreaseQuotaPrivilege")
#وصف_ڪريو SE_UNSOLICITED_داخلا_NAME متن_3("SeUnsolicitedInputPrivilege")
#وصف_ڪريو SE_MACHINE_ACCOUNT_NAME متن_3("SeMachineAccountPrivilege")
#وصف_ڪريو SE_TCB_NAME متن_3("SeTcbPrivilege")
#وصف_ڪريو SE_SECURITY_NAME متن_3("SeSecurityPrivilege")
#وصف_ڪريو SE_TAKE_OWNERSHIP_NAME متن_3("SeTakeOwnershipPrivilege")
#وصف_ڪريو SE_ڀريو_DRIVER_NAME متن_3("SeLoadDriverPrivilege")
#وصف_ڪريو SE_SYSTEM_PROFILE_NAME متن_3("SeSystemProfilePrivilege")
#وصف_ڪريو SE_SYSTEMTIME_NAME متن_3("SeSystemtimePrivilege")
#وصف_ڪريو SE_PROF_SINGLE_PROCESS_NAME متن_3("SeProfileSingleProcessPrivilege")
#وصف_ڪريو SE_INC_بنياد_ترجيح_NAME متن_3("SeIncreaseBasePriorityPrivilege")
#وصف_ڪريو SE_CREATE_PAGEFILE_NAME متن_3("SeCreatePagefilePrivilege")
#وصف_ڪريو SE_CREATE_PERMANENT_NAME متن_3("SeCreatePermanentPrivilege")
#وصف_ڪريو SE_BACKUP_NAME متن_3("SeBackupPrivilege")
#وصف_ڪريو SE_RESTORE_NAME متن_3("SeRestorePrivilege")
#وصف_ڪريو SE_SHUTDOWN_NAME متن_3("SeShutdownPrivilege")
#وصف_ڪريو SE_DEBUG_NAME متن_3("SeDebugPrivilege")
#وصف_ڪريو SE_AUDIT_NAME متن_3("SeAuditPrivilege")
#وصف_ڪريو SE_SYSTEM_ENVIRONMENT_NAME متن_3("SeSystemEnvironmentPrivilege")
#وصف_ڪريو SE_CHANGE_NOTIFY_NAME متن_3("SeChangeNotifyPrivilege")
#وصف_ڪريو SE_REMOTE_SHUTDOWN_NAME متن_3("SeRemoteShutdownPrivilege")
#وصف_ڪريو SE_UNDOCK_NAME متن_3("SeUndockPrivilege")
#وصف_ڪريو SE_SYNC_AGENT_NAME متن_3("SeSyncAgentPrivilege")
#وصف_ڪريو SE_ENABLE_DELEGATION_NAME متن_3("SeEnableDelegationPrivilege")
#وصف_ڪريو SE_MANAGE_VOLUME_NAME متن_3("SeManageVolumePrivilege")
#وصف_ڪريو SE_IMPERSONATE_NAME متن_3("SeImpersonatePrivilege")
#وصف_ڪريو SE_CREATE_GLOBAL_NAME متن_3("SeCreateGlobalPrivilege")

    تعريفنوع تعداد _SECURITY_IMPERSONATION_LEVEL {
      SecurityAnonymous,SecurityIdentification,SecurityImpersonation,SecurityDelegation
    } SECURITY_IMPERSONATION_LEVEL,*PSECURITY_IMPERSONATION_LEVEL;

#وصف_ڪريو SECURITY_MAX_IMPERSONATION_LEVEL SecurityDelegation
#وصف_ڪريو SECURITY_MIN_IMPERSONATION_LEVEL SecurityAnonymous
#وصف_ڪريو DEFAULT_IMPERSONATION_LEVEL SecurityImpersonation
#وصف_ڪريو VALID_IMPERSONATION_LEVEL(L) (((L) >= SECURITY_MIN_IMPERSONATION_LEVEL) && ((L) <= SECURITY_MAX_IMPERSONATION_LEVEL))

#وصف_ڪريو TOKEN_سونپيو_PRIMARY (0x0001)
#وصف_ڪريو TOKEN_DUPLICATE (0x0002)
#وصف_ڪريو TOKEN_IMPERSONATE (0x0004)
#وصف_ڪريو TOKEN_QUERY (0x0008)
#وصف_ڪريو TOKEN_QUERY_ذريعو (0x0010)
#وصف_ڪريو TOKEN_ADJUST_PRIVILEGES (0x0020)
#وصف_ڪريو TOKEN_ADJUST_GROUPS (0x0040)
#وصف_ڪريو TOKEN_ADJUST_DEFAULT (0x0080)
#وصف_ڪريو TOKEN_ADJUST_SESSIONID (0x0100)

#وصف_ڪريو TOKEN_ALL_ACCESS_P (STANDARD_RIGHTS_REQUIRED | TOKEN_سونپيو_PRIMARY | TOKEN_DUPLICATE | TOKEN_IMPERSONATE | TOKEN_QUERY | TOKEN_QUERY_ذريعو | TOKEN_ADJUST_PRIVILEGES | TOKEN_ADJUST_GROUPS | TOKEN_ADJUST_DEFAULT)
#وصف_ڪريو TOKEN_ALL_ACCESS (TOKEN_ALL_ACCESS_P | TOKEN_ADJUST_SESSIONID)
#وصف_ڪريو TOKEN_READ (STANDARD_RIGHTS_READ | TOKEN_QUERY)

#وصف_ڪريو TOKEN_WRITE (STANDARD_RIGHTS_WRITE | TOKEN_ADJUST_PRIVILEGES | TOKEN_ADJUST_GROUPS | TOKEN_ADJUST_DEFAULT)

#وصف_ڪريو TOKEN_EXECUTE (STANDARD_RIGHTS_EXECUTE)

    تعريفنوع تعداد _TOKEN_TYPE {
      TokenPrimary = 1,TokenImpersonation
    } TOKEN_TYPE;
    تعريفنوع TOKEN_TYPE *PTOKEN_TYPE;

    تعريفنوع تعداد _TOKEN_INFORMATION_CLASS {
      TokenUser = 1,TokenGroups,TokenPrivileges,TokenOwner,Token_Primary_گروهه,TokenDefaultDacl,Token_ذريعو,TokenType,TokenImpersonationLevel,
      TokenStatistics,TokenRestrictedSids,TokenSessionId,TokenGroupsAndPrivileges,TokenSessionReference,TokenSandBoxInert,TokenAuditPolicy,
      TokenOrigin,MaxTokenInfoClass
    } TOKEN_INFORMATION_CLASS,*PTOKEN_INFORMATION_CLASS;

    تعريفنوع بنية _TOKEN_USER {
      SID_AND_خاصيتون_2 User;
    } TOKEN_USER,*PTOKEN_USER;

    تعريفنوع بنية _TOKEN_GROUPS {
      DWORD گروهه_ڳڻپ;
      SID_AND_خاصيتون_2 Groups[ANYSIZE_ARRAY];
    } TOKEN_GROUPS,*PTOKEN_GROUPS;

    تعريفنوع بنية _TOKEN_PRIVILEGES {
      DWORD Privilege_ڳڻپ;
      LUID_AND_خاصيتون_2 Privileges[ANYSIZE_ARRAY];
    } TOKEN_PRIVILEGES,*PTOKEN_PRIVILEGES;

    تعريفنوع بنية _TOKEN_OWNER {
      PSID Owner;
    } TOKEN_OWNER,*PTOKEN_OWNER;

    تعريفنوع بنية TOKEN_PRIMARY_گروهه {
      PSID Primary_گروهه;
    } TOKEN_PRIMARY_گروهه_2,*PTOKEN_PRIMARY_گروهه;

    تعريفنوع بنية _TOKEN_DEFAULT_DACL {
      PACL DefaultDacl;
    } TOKEN_DEFAULT_DACL,*PTOKEN_DEFAULT_DACL;

    تعريفنوع بنية _TOKEN_GROUPS_AND_PRIVILEGES {
      DWORD Sid_ڳڻپ;
      DWORD Sid_ڊيگهائي;
      PSID_AND_خاصيتون Sids;
      DWORD Restricted_Sid_ڳڻپ;
      DWORD Restricted_Sid_ڊيگهائي;
      PSID_AND_خاصيتون RestrictedSids;
      DWORD Privilege_ڳڻپ;
      DWORD Privilege_ڊيگهائي;
      PLUID_AND_خاصيتون Privileges;
      LUID AuthenticationId;
    } TOKEN_GROUPS_AND_PRIVILEGES,*PTOKEN_GROUPS_AND_PRIVILEGES;

#وصف_ڪريو TOKEN_AUDIT_SUCCESS_INCLUDE 0x1
#وصف_ڪريو TOKEN_AUDIT_SUCCESS_EXCLUDE 0x2
#وصف_ڪريو TOKEN_AUDIT_FAILURE_INCLUDE 0x4
#وصف_ڪريو TOKEN_AUDIT_FAILURE_EXCLUDE 0x8

#وصف_ڪريو VALID_AUDIT_POLICY_بٽ (TOKEN_AUDIT_SUCCESS_INCLUDE | TOKEN_AUDIT_SUCCESS_EXCLUDE | TOKEN_AUDIT_FAILURE_INCLUDE | TOKEN_AUDIT_FAILURE_EXCLUDE)
#وصف_ڪريو VALID_TOKEN_AUDIT_POLICY_ELEMENT(P) ((((P).Policy_نقاب & ~VALID_AUDIT_POLICY_بٽ)==0) && ((P).Category <= AuditEventMaxType))

    تعريفنوع بنية _TOKEN_AUDIT_POLICY_ELEMENT {
      DWORD Category;
      DWORD Policy_نقاب;
    } TOKEN_AUDIT_POLICY_ELEMENT,*PTOKEN_AUDIT_POLICY_ELEMENT;

    تعريفنوع بنية _TOKEN_AUDIT_POLICY {
      DWORD Policy_ڳڻپ;
      TOKEN_AUDIT_POLICY_ELEMENT Policy[ANYSIZE_ARRAY];
    } TOKEN_AUDIT_POLICY,*PTOKEN_AUDIT_POLICY;

#وصف_ڪريو في_USER_AUDITING_POLICY_سائيز(p) (حجم(TOKEN_AUDIT_POLICY) + (((p)->Policy_ڳڻپ > ANYSIZE_ARRAY) ? (حجم(TOKEN_AUDIT_POLICY_ELEMENT) *((p)->Policy_ڳڻپ - ANYSIZE_ARRAY)) : 0))
#وصف_ڪريو في_USER_AUDITING_POLICY_سائيز_BY_ڳڻپ(C) (حجم(TOKEN_AUDIT_POLICY) + (((C) > ANYSIZE_ARRAY) ? (حجم(TOKEN_AUDIT_POLICY_ELEMENT) *((C) - ANYSIZE_ARRAY)) : 0))

#وصف_ڪريو TOKEN_ذريعو_ڊيگهائي 8

    تعريفنوع بنية TOKEN_ذريعو {
      CHAR ذريعو_Name[TOKEN_ذريعو_ڊيگهائي];
      LUID ذريعو_Identifier;
    } TOKEN_ذريعو_2,*PTOKEN_ذريعو;

    تعريفنوع بنية _TOKEN_STATISTICS {
      LUID TokenId;
      LUID AuthenticationId;
      LARGE_INTEGER Expiration_وقت;
      TOKEN_TYPE TokenType;
      SECURITY_IMPERSONATION_LEVEL ImpersonationLevel;
      DWORD DynamicCharged;
      DWORD Dynamic_موجود;
      DWORD گروهه_ڳڻپ;
      DWORD Privilege_ڳڻپ;
      LUID ModifiedId;
    } TOKEN_STATISTICS,*PTOKEN_STATISTICS;

    تعريفنوع بنية _TOKEN_CONTROL {
      LUID TokenId;
      LUID AuthenticationId;
      LUID ModifiedId;
      TOKEN_ذريعو_2 Token_ذريعو;
    } TOKEN_CONTROL,*PTOKEN_CONTROL;

    تعريفنوع بنية _TOKEN_ORIGIN {
      LUID OriginatingLogonSession;
    } TOKEN_ORIGIN,*PTOKEN_ORIGIN;

#وصف_ڪريو SECURITY_DYNAMIC_TRACKING (TRUE)
#وصف_ڪريو SECURITY_STATIC_TRACKING (FALSE)

    تعريفنوع BOOLEAN SECURITY_CONTEXT_TRACKING_گهڻائي,*PSECURITY_CONTEXT_TRACKING_گهڻائي;

    تعريفنوع بنية SECURITY_QUALITY_جو_SERVICE {
      DWORD ڊيگهائي_2;
      SECURITY_IMPERSONATION_LEVEL ImpersonationLevel;
      SECURITY_CONTEXT_TRACKING_گهڻائي Context_Tracking_گهڻائي;
      BOOLEAN EffectiveOnly;
    } SECURITY_QUALITY_جو_SERVICE_2,*PSECURITY_QUALITY_جو_SERVICE;

    تعريفنوع بنية _SE_IMPERSONATION_STATE {
      PACCESS_TOKEN Token;
      BOOLEAN CopyOnOpen;
      BOOLEAN EffectiveOnly;
      SECURITY_IMPERSONATION_LEVEL Level;
    } SE_IMPERSONATION_STATE,*PSE_IMPERSONATION_STATE;

#وصف_ڪريو DISABLE_MAX_PRIVILEGE 0x1
#وصف_ڪريو SANDBOX_INERT 0x2

    تعريفنوع DWORD SECURITY_INFORMATION,*PSECURITY_INFORMATION;

#وصف_ڪريو OWNER_SECURITY_INFORMATION (0x00000001L)
#وصف_ڪريو گروهه_SECURITY_INFORMATION (0x00000002L)
#وصف_ڪريو DACL_SECURITY_INFORMATION (0x00000004L)
#وصف_ڪريو SACL_SECURITY_INFORMATION (0x00000008L)

#وصف_ڪريو PROTECTED_DACL_SECURITY_INFORMATION (0x80000000L)
#وصف_ڪريو PROTECTED_SACL_SECURITY_INFORMATION (0x40000000L)
#وصف_ڪريو UNPROTECTED_DACL_SECURITY_INFORMATION (0x20000000L)
#وصف_ڪريو UNPROTECTED_SACL_SECURITY_INFORMATION (0x10000000L)

#وصف_ڪريو PROCESS_TERMINATE (0x0001)
#وصف_ڪريو PROCESS_CREATE_THREAD (0x0002)
#وصف_ڪريو PROCESS_سيٽ_SESSIONID (0x0004)
#وصف_ڪريو PROCESS_VM_OPERATION (0x0008)
#وصف_ڪريو PROCESS_VM_READ (0x0010)
#وصف_ڪريو PROCESS_VM_WRITE (0x0020)
#وصف_ڪريو PROCESS_DUP_HANDLE (0x0040)
#وصف_ڪريو PROCESS_CREATE_PROCESS (0x0080)
#وصف_ڪريو PROCESS_سيٽ_QUOTA (0x0100)
#وصف_ڪريو PROCESS_سيٽ_INFORMATION (0x0200)
#وصف_ڪريو PROCESS_QUERY_INFORMATION (0x0400)
#وصف_ڪريو PROCESS_SUSPEND_RESUME (0x0800)
#وصف_ڪريو PROCESS_QUERY_LIMITED_INFORMATION (0x1000)
#وصف_ڪريو PROCESS_سيٽ_LIMITED_INFORMATION (0x2000)
#وصف_ڪريو PROCESS_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0xFFF)

#جيڪڏهن_وصف_ٿيل _WIN64
#وصف_ڪريو وڌ_کان_وڌ_PROCESSORS 64
#وإلا
#وصف_ڪريو وڌ_کان_وڌ_PROCESSORS 32
#جيڪڏهن_پورو

#وصف_ڪريو THREAD_TERMINATE (0x0001)
#وصف_ڪريو THREAD_SUSPEND_RESUME (0x0002)
#وصف_ڪريو THREAD_GET_CONTEXT (0x0008)
#وصف_ڪريو THREAD_سيٽ_CONTEXT (0x0010)
#وصف_ڪريو THREAD_سيٽ_INFORMATION (0x0020)
#وصف_ڪريو THREAD_QUERY_INFORMATION (0x0040)
#وصف_ڪريو THREAD_سيٽ_THREAD_TOKEN (0x0080)
#وصف_ڪريو THREAD_IMPERSONATE (0x0100)
#وصف_ڪريو THREAD_سڌو_IMPERSONATION (0x0200)

#وصف_ڪريو THREAD_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0x3FF)

#وصف_ڪريو ڪم_OBJECT_سونپيو_PROCESS (0x0001)
#وصف_ڪريو ڪم_OBJECT_سيٽ_خاصيتون (0x0002)
#وصف_ڪريو ڪم_OBJECT_QUERY (0x0004)
#وصف_ڪريو ڪم_OBJECT_TERMINATE (0x0008)
#وصف_ڪريو ڪم_OBJECT_سيٽ_SECURITY_خاصيتون (0x0010)
#وصف_ڪريو ڪم_OBJECT_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0x1F)

    تعريفنوع بنية ڪم_سيٽ_ARRAY {
      HANDLE ڪم_Handle;
      DWORD MemberLevel;
      DWORD Flags;
    } ڪم_سيٽ_ARRAY_2,*PJOB_سيٽ_ARRAY;

#وصف_ڪريو FLS_وڌ_کان_وڌ_موجود 128
#وصف_ڪريو TLS_MINIMUM_موجود 64

#جيڪڏهن_وصف_نه_ٿيل _NT_TIB_DEFINED
#وصف_ڪريو _NT_TIB_DEFINED
    تعريفنوع بنية _NT_TIB {
      بنية EXCEPTION_REGISTRATION_رڪارڊ_2 *ExceptionList;
      PVOID ڍير_بنياد;
      PVOID ڍير_حد_بندي;
      PVOID SubSystemTib;
      اتحاد {
	PVOID Fiber_معلومات;
	DWORD نسخو_2;
      };
      PVOID Arbitrary_User_اشارو;
      بنية _NT_TIB *Self;
    } NT_TIB;
    تعريفنوع NT_TIB *PNT_TIB;
#جيڪڏهن_پورو

    تعريفنوع بنية _NT_TIB32 {
      DWORD ExceptionList;
      DWORD ڍير_بنياد;
      DWORD ڍير_حد_بندي;
      DWORD SubSystemTib;
      اتحاد {
	DWORD Fiber_معلومات;
	DWORD نسخو_2;
      };
      DWORD Arbitrary_User_اشارو;
      DWORD Self;
    } NT_TIB32,*PNT_TIB32;

    تعريفنوع بنية _NT_TIB64 {
      DWORD64 ExceptionList;
      DWORD64 ڍير_بنياد;
      DWORD64 ڍير_حد_بندي;
      DWORD64 SubSystemTib;
      اتحاد {
	DWORD64 Fiber_معلومات;
	DWORD نسخو_2;
      };
      DWORD64 Arbitrary_User_اشارو;
      DWORD64 Self;
    } NT_TIB64,*PNT_TIB64;

#إذا !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_)
#وصف_ڪريو WX86
#جيڪڏهن_پورو

#وصف_ڪريو THREAD_بنياد_ترجيح_LOWRT 15
#وصف_ڪريو THREAD_بنياد_ترجيح_MAX 2
#وصف_ڪريو THREAD_بنياد_ترجيح_MIN (-2)
#وصف_ڪريو THREAD_بنياد_ترجيح_IDLE (-15)

    تعريفنوع بنية _QUOTA_LIMITS {
      سائيز_T Paged_Pool_حد_بندي;
      سائيز_T Non_Paged_Pool_حد_بندي;
      سائيز_T Minimum_Working_سيٽ_سائيز;
      سائيز_T وڌ_کان_وڌ_Working_سيٽ_سائيز;
      سائيز_T Pagefile_حد_بندي;
      LARGE_INTEGER وقت_حد_بندي;
    } QUOTA_LIMITS,*PQUOTA_LIMITS;

#وصف_ڪريو QUOTA_LIMITS_HARDWS_MIN_ENABLE 0x00000001
#وصف_ڪريو QUOTA_LIMITS_HARDWS_MIN_DISABLE 0x00000002
#وصف_ڪريو QUOTA_LIMITS_HARDWS_MAX_ENABLE 0x00000004
#وصف_ڪريو QUOTA_LIMITS_HARDWS_MAX_DISABLE 0x00000008

    تعريفنوع بنية _QUOTA_LIMITS_EX {
      سائيز_T Paged_Pool_حد_بندي;
      سائيز_T Non_Paged_Pool_حد_بندي;
      سائيز_T Minimum_Working_سيٽ_سائيز;
      سائيز_T وڌ_کان_وڌ_Working_سيٽ_سائيز;
      سائيز_T Pagefile_حد_بندي;
      LARGE_INTEGER وقت_حد_بندي;
      سائيز_T Reserved1;
      سائيز_T Reserved2;
      سائيز_T Reserved3;
      سائيز_T Reserved4;
      DWORD Flags;
      DWORD Reserved5;
    } QUOTA_LIMITS_EX,*PQUOTA_LIMITS_EX;

    تعريفنوع بنية _IO_COUNTERS {
      ULONGLONG Read_Operation_ڳڻپ;
      ULONGLONG Write_Operation_ڳڻپ;
      ULONGLONG Other_Operation_ڳڻپ;
      ULONGLONG Read_Transfer_ڳڻپ;
      ULONGLONG Write_Transfer_ڳڻپ;
      ULONGLONG Other_Transfer_ڳڻپ;
    } IO_COUNTERS;
    تعريفنوع IO_COUNTERS *PIO_COUNTERS;

    تعريفنوع بنية _JOBOBJECT_BASIC_ACCOUNTING_INFORMATION {
      LARGE_INTEGER ڪل_User_وقت;
      LARGE_INTEGER ڪل_Kernel_وقت;
      LARGE_INTEGER This_Period_ڪل_User_وقت;
      LARGE_INTEGER This_Period_ڪل_Kernel_وقت;
      DWORD ڪل_صفحو_Fault_ڳڻپ;
      DWORD ڪل_Processes;
      DWORD سرگرم_Processes;
      DWORD ڪل_Terminated_Processes;
    } JOBOBJECT_BASIC_ACCOUNTING_INFORMATION,*PJOBOBJECT_BASIC_ACCOUNTING_INFORMATION;

    تعريفنوع بنية JOBOBJECT_BASIC_حد_بندي_INFORMATION {
      LARGE_INTEGER في_Process_User_وقت_حد_بندي;
      LARGE_INTEGER في_ڪم_User_وقت_حد_بندي;
      DWORD حد_بندي_Flags;
      سائيز_T Minimum_Working_سيٽ_سائيز;
      سائيز_T وڌ_کان_وڌ_Working_سيٽ_سائيز;
      DWORD سرگرم_Process_حد_بندي;
      ULONG_PTR Affinity;
      DWORD ترجيح_Class;
      DWORD SchedulingClass;
    } JOBOBJECT_BASIC_حد_بندي_INFORMATION_2,*PJOBOBJECT_BASIC_حد_بندي_INFORMATION;

    تعريفنوع بنية JOBOBJECT_EXTENDED_حد_بندي_INFORMATION {
      JOBOBJECT_BASIC_حد_بندي_INFORMATION_2 Basic_حد_بندي_Information;
      IO_COUNTERS IoInfo;
      سائيز_T Process_يادگيري_حد_بندي;
      سائيز_T ڪم_يادگيري_حد_بندي;
      سائيز_T Peak_Process_يادگيري_استعمال_ٿيل;
      سائيز_T Peak_ڪم_يادگيري_استعمال_ٿيل;
    } JOBOBJECT_EXTENDED_حد_بندي_INFORMATION_2,*PJOBOBJECT_EXTENDED_حد_بندي_INFORMATION;

    تعريفنوع بنية _JOBOBJECT_BASIC_PROCESS_ID_LIST {
      DWORD عدد_جو_Assigned_Processes;
      DWORD عدد_جو_Process_Ids_اندريون_List;
      ULONG_PTR ProcessIdList[1];
    } JOBOBJECT_BASIC_PROCESS_ID_LIST,*PJOBOBJECT_BASIC_PROCESS_ID_LIST;

    تعريفنوع بنية _JOBOBJECT_BASIC_UI_RESTRICTIONS {
      DWORD UIRestrictionsClass;
    } JOBOBJECT_BASIC_UI_RESTRICTIONS,*PJOBOBJECT_BASIC_UI_RESTRICTIONS;

    تعريفنوع بنية JOBOBJECT_SECURITY_حد_بندي_INFORMATION {
      DWORD Security_حد_بندي_Flags;
      HANDLE ڪم_Token;
      PTOKEN_GROUPS Sids_منزل_Disable;
      PTOKEN_PRIVILEGES Privileges_منزل_Delete;
      PTOKEN_GROUPS RestrictedSids;
    } JOBOBJECT_SECURITY_حد_بندي_INFORMATION_2,*PJOBOBJECT_SECURITY_حد_بندي_INFORMATION;

    تعريفنوع بنية JOBOBJECT_پڇاڙي_جو_ڪم_وقت_INFORMATION {
      DWORD پڇاڙي_جو_ڪم_وقت_Action;
    } JOBOBJECT_پڇاڙي_جو_ڪم_وقت_INFORMATION_2,*PJOBOBJECT_پڇاڙي_جو_ڪم_وقت_INFORMATION;

    تعريفنوع بنية JOBOBJECT_ASSOCIATE_COMPLETION_پورٽ {
      PVOID Completion_ڪنجي;
      HANDLE Completion_پورٽ;
    } JOBOBJECT_ASSOCIATE_COMPLETION_پورٽ_2,*PJOBOBJECT_ASSOCIATE_COMPLETION_پورٽ;

    تعريفنوع بنية _JOBOBJECT_BASIC_AND_IO_ACCOUNTING_INFORMATION {
      JOBOBJECT_BASIC_ACCOUNTING_INFORMATION BasicInfo;
      IO_COUNTERS IoInfo;
    } JOBOBJECT_BASIC_AND_IO_ACCOUNTING_INFORMATION,*PJOBOBJECT_BASIC_AND_IO_ACCOUNTING_INFORMATION;

    تعريفنوع بنية _JOBOBJECT_JOBSET_INFORMATION {
      DWORD MemberLevel;
    } JOBOBJECT_JOBSET_INFORMATION,*PJOBOBJECT_JOBSET_INFORMATION;

#وصف_ڪريو ڪم_OBJECT_TERMINATE_AT_پڇاڙي_جو_ڪم 0
#وصف_ڪريو ڪم_OBJECT_POST_AT_پڇاڙي_جو_ڪم 1

#وصف_ڪريو ڪم_OBJECT_نياپو_پڇاڙي_جو_ڪم_وقت 1
#وصف_ڪريو ڪم_OBJECT_نياپو_پڇاڙي_جو_PROCESS_وقت 2
#وصف_ڪريو ڪم_OBJECT_نياپو_سرگرم_PROCESS_حد_بندي 3
#وصف_ڪريو ڪم_OBJECT_نياپو_سرگرم_PROCESS_ZERO 4
#وصف_ڪريو ڪم_OBJECT_نياپو_NEW_PROCESS 6
#وصف_ڪريو ڪم_OBJECT_نياپو_EXIT_PROCESS 7
#وصف_ڪريو ڪم_OBJECT_نياپو_ABNORMAL_EXIT_PROCESS 8
#وصف_ڪريو ڪم_OBJECT_نياپو_PROCESS_يادگيري_حد_بندي 9
#وصف_ڪريو ڪم_OBJECT_نياپو_ڪم_يادگيري_حد_بندي 10

#وصف_ڪريو ڪم_OBJECT_حد_بندي_WORKINGSET 0x00000001
#وصف_ڪريو ڪم_OBJECT_حد_بندي_PROCESS_وقت 0x00000002
#وصف_ڪريو ڪم_OBJECT_حد_بندي_ڪم_وقت 0x00000004
#وصف_ڪريو ڪم_OBJECT_حد_بندي_سرگرم_PROCESS 0x00000008
#وصف_ڪريو ڪم_OBJECT_حد_بندي_AFFINITY 0x00000010
#وصف_ڪريو ڪم_OBJECT_حد_بندي_ترجيح_CLASS 0x00000020
#وصف_ڪريو ڪم_OBJECT_حد_بندي_PRESERVE_ڪم_وقت 0x00000040
#وصف_ڪريو ڪم_OBJECT_حد_بندي_SCHEDULING_CLASS 0x00000080

#وصف_ڪريو ڪم_OBJECT_حد_بندي_PROCESS_يادگيري 0x00000100
#وصف_ڪريو ڪم_OBJECT_حد_بندي_ڪم_يادگيري 0x00000200
#وصف_ڪريو ڪم_OBJECT_حد_بندي_DIE_ON_UNHANDLED_EXCEPTION 0x00000400
#وصف_ڪريو ڪم_OBJECT_حد_بندي_BREAKAWAY_OK 0x00000800
#وصف_ڪريو ڪم_OBJECT_حد_بندي_SILENT_BREAKAWAY_OK 0x00001000
#وصف_ڪريو ڪم_OBJECT_حد_بندي_KILL_ON_ڪم_CLOSE 0x00002000

#وصف_ڪريو ڪم_OBJECT_حد_بندي_RESERVED2 0x00004000
#وصف_ڪريو ڪم_OBJECT_حد_بندي_RESERVED3 0x00008000
#وصف_ڪريو ڪم_OBJECT_حد_بندي_RESERVED4 0x00010000
#وصف_ڪريو ڪم_OBJECT_حد_بندي_RESERVED5 0x00020000
#وصف_ڪريو ڪم_OBJECT_حد_بندي_RESERVED6 0x00040000

#وصف_ڪريو ڪم_OBJECT_حد_بندي_VALID_FLAGS 0x0007ffff

#وصف_ڪريو ڪم_OBJECT_BASIC_حد_بندي_VALID_FLAGS 0x000000ff
#وصف_ڪريو ڪم_OBJECT_EXTENDED_حد_بندي_VALID_FLAGS 0x00003fff
#وصف_ڪريو ڪم_OBJECT_RESERVED_حد_بندي_VALID_FLAGS 0x0007ffff

#وصف_ڪريو ڪم_OBJECT_UILIMIT_NONE 0x00000000

#وصف_ڪريو ڪم_OBJECT_UILIMIT_HANDLES 0x00000001
#وصف_ڪريو ڪم_OBJECT_UILIMIT_READCLIPBOARD 0x00000002
#وصف_ڪريو ڪم_OBJECT_UILIMIT_WRITECLIPBOARD 0x00000004
#وصف_ڪريو ڪم_OBJECT_UILIMIT_SYSTEMPARAMETERS 0x00000008
#وصف_ڪريو ڪم_OBJECT_UILIMIT_DISPLAYSETTINGS 0x00000010
#وصف_ڪريو ڪم_OBJECT_UILIMIT_GLOBALATOMS 0x00000020
#وصف_ڪريو ڪم_OBJECT_UILIMIT_DESKTOP 0x00000040
#وصف_ڪريو ڪم_OBJECT_UILIMIT_EXITWINDOWS 0x00000080

#وصف_ڪريو ڪم_OBJECT_UILIMIT_ALL 0x000000FF

#وصف_ڪريو ڪم_OBJECT_UI_VALID_FLAGS 0x000000FF

#وصف_ڪريو ڪم_OBJECT_SECURITY_NO_ADMIN 0x00000001
#وصف_ڪريو ڪم_OBJECT_SECURITY_RESTRICTED_TOKEN 0x00000002
#وصف_ڪريو ڪم_OBJECT_SECURITY_ONLY_TOKEN 0x00000004
#وصف_ڪريو ڪم_OBJECT_SECURITY_FILTER_ٽوڪن 0x00000008

#وصف_ڪريو ڪم_OBJECT_SECURITY_VALID_FLAGS 0x0000000f

    تعريفنوع تعداد _JOBOBJECTINFOCLASS {
      ڪم_Object_Basic_Accounting_Information = 1,ڪم_Object_Basic_حد_بندي_Information,ڪم_Object_Basic_Process_Id_List,ڪم_Object_Basic_UIRestrictions,
      ڪم_Object_Security_حد_بندي_Information,ڪم_Object_پڇاڙي_جو_ڪم_وقت_Information,ڪم_Object_Associate_Completion_پورٽ_Information,
      ڪم_Object_Basic_And_Io_Accounting_Information,ڪم_Object_Extended_حد_بندي_Information,ڪم_Object_ڪم_سيٽ_Information,Max_ڪم_Object_Info_Class
    } JOBOBJECTINFOCLASS;

#وصف_ڪريو EVENT_MODIFY_STATE 0x0002
#وصف_ڪريو EVENT_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x3)

#وصف_ڪريو MUTANT_QUERY_STATE 0x0001

#وصف_ڪريو MUTANT_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE| MUTANT_QUERY_STATE)
#وصف_ڪريو SEMAPHORE_MODIFY_STATE 0x0002
#وصف_ڪريو SEMAPHORE_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x3)

#وصف_ڪريو TIMER_QUERY_STATE 0x0001
#وصف_ڪريو TIMER_MODIFY_STATE 0x0002

#وصف_ڪريو TIMER_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE| TIMER_QUERY_STATE|TIMER_MODIFY_STATE)

#وصف_ڪريو وقت_ZONE_ID_UNKNOWN 0
#وصف_ڪريو وقت_ZONE_ID_STANDARD 1
#وصف_ڪريو وقت_ZONE_ID_DAYLIGHT 2

    تعريفنوع تعداد _LOGICAL_PROCESSOR_RELATIONSHIP {
      لاڳاپو_Processor_Core,لاڳاپو_Numa_ڳنڍ,لاڳاپو_Cache
    } LOGICAL_PROCESSOR_RELATIONSHIP;

#وصف_ڪريو LTP_PC_SMT 0x1

    تعريفنوع تعداد _PROCESSOR_CACHE_TYPE {
      CacheUnified,CacheInstruction,Cache_معلومات,CacheTrace
    } PROCESSOR_CACHE_TYPE;

#وصف_ڪريو CACHE_FULLY_ASSOCIATIVE 0xFF

    تعريفنوع بنية _CACHE_DESCRIPTOR {
      BYTE Level;
      BYTE Associativity;
      لفظ_3 سٽ_سائيز_2;
      DWORD سائيز_3;
      PROCESSOR_CACHE_TYPE Type;
    } CACHE_DESCRIPTOR,*PCACHE_DESCRIPTOR;

    تعريفنوع بنية _SYSTEM_LOGICAL_PROCESSOR_INFORMATION {
      ULONG_PTR Processor_نقاب;
      LOGICAL_PROCESSOR_RELATIONSHIP Relationship;
      اتحاد {
	بنية {
	  BYTE Flags;
	} ProcessorCore;
	بنية {
	  DWORD ڳنڍ_عدد;
	} Numa_ڳنڍ;
	CACHE_DESCRIPTOR Cache;
	ULONGLONG Reserved[2];
      };
    } SYSTEM_LOGICAL_PROCESSOR_INFORMATION,*PSYSTEM_LOGICAL_PROCESSOR_INFORMATION;

#وصف_ڪريو PROCESSOR_INTEL_386 386
#وصف_ڪريو PROCESSOR_INTEL_486 486
#وصف_ڪريو PROCESSOR_INTEL_PENTIUM 586
#وصف_ڪريو PROCESSOR_INTEL_IA64 2200
#وصف_ڪريو PROCESSOR_AMD_X8664 8664
#وصف_ڪريو PROCESSOR_MIPS_R4000 4000
#وصف_ڪريو PROCESSOR_ALPHA_21064 21064
#وصف_ڪريو PROCESSOR_PPC_601 601
#وصف_ڪريو PROCESSOR_PPC_603 603
#وصف_ڪريو PROCESSOR_PPC_604 604
#وصف_ڪريو PROCESSOR_PPC_620 620
#وصف_ڪريو PROCESSOR_HITACHI_SH3 10003
#وصف_ڪريو PROCESSOR_HITACHI_SH3E 10004
#وصف_ڪريو PROCESSOR_HITACHI_SH4 10005
#وصف_ڪريو PROCESSOR_MOTOROLA_821 821
#وصف_ڪريو PROCESSOR_SHx_SH3 103
#وصف_ڪريو PROCESSOR_SHx_SH4 104
#وصف_ڪريو PROCESSOR_STRONGARM 2577
#وصف_ڪريو PROCESSOR_ARM720 1824
#وصف_ڪريو PROCESSOR_ARM820 2080
#وصف_ڪريو PROCESSOR_ARM920 2336
#وصف_ڪريو PROCESSOR_ARM_7TDMI 70001
#وصف_ڪريو PROCESSOR_OPTIL 0x494f

#وصف_ڪريو PROCESSOR_ARCHITECTURE_INTEL 0
#وصف_ڪريو PROCESSOR_ARCHITECTURE_MIPS 1
#وصف_ڪريو PROCESSOR_ARCHITECTURE_ALPHA 2
#وصف_ڪريو PROCESSOR_ARCHITECTURE_PPC 3
#وصف_ڪريو PROCESSOR_ARCHITECTURE_SHX 4
#وصف_ڪريو PROCESSOR_ARCHITECTURE_ARM 5
#وصف_ڪريو PROCESSOR_ARCHITECTURE_IA64 6
#وصف_ڪريو PROCESSOR_ARCHITECTURE_ALPHA64 7
#وصف_ڪريو PROCESSOR_ARCHITECTURE_MSIL 8
#وصف_ڪريو PROCESSOR_ARCHITECTURE_AMD64 9
#وصف_ڪريو PROCESSOR_ARCHITECTURE_IA32_ON_WIN64 10

#وصف_ڪريو PROCESSOR_ARCHITECTURE_UNKNOWN 0xFFFF

#وصف_ڪريو PF_FLOATING_نقطو_PRECISION_ERRATA 0
#وصف_ڪريو PF_FLOATING_نقطو_EMULATED 1
#وصف_ڪريو PF_COMPARE_EXCHANGE_DOUBLE 2
#وصف_ڪريو PF_MMX_INSTRUCTIONS_موجود 3
#وصف_ڪريو PF_PPC_MOVEMEM_64_ٻٽو_انگ_OK 4
#وصف_ڪريو PF_ALPHA_BYTE_INSTRUCTIONS 5
#وصف_ڪريو PF_XMMI_INSTRUCTIONS_موجود 6
#وصف_ڪريو PF_3_DNOW_INSTRUCTIONS_موجود 7
#وصف_ڪريو PF_RDTSC_INSTRUCTION_موجود 8
#وصف_ڪريو PF_PAE_ENABLED 9
#وصف_ڪريو PF_XMMI64_INSTRUCTIONS_موجود 10
#وصف_ڪريو PF_SSE_DAZ_گهڻائي_موجود 11
#وصف_ڪريو PF_NX_ENABLED 12

    تعريفنوع بنية يادگيري_BASIC_INFORMATION_2 {
      PVOID بنياد_پتو;
      PVOID ورهاست_بنياد;
      DWORD ورهاست_Protect;
      سائيز_T Region_سائيز;
      DWORD State;
      DWORD Protect;
      DWORD Type;
    } يادگيري_BASIC_INFORMATION,*PMEMORY_BASIC_INFORMATION;

    تعريفنوع بنية يادگيري_BASIC_INFORMATION32 {
      DWORD بنياد_پتو;
      DWORD ورهاست_بنياد;
      DWORD ورهاست_Protect;
      DWORD Region_سائيز;
      DWORD State;
      DWORD Protect;
      DWORD Type;
    } يادگيري_BASIC_INFORMATION32_2,*PMEMORY_BASIC_INFORMATION32;

    تعريفنوع بنية DECLSPEC_ALIGN(16) يادگيري_BASIC_INFORMATION64 {
      ULONGLONG بنياد_پتو;
      ULONGLONG ورهاست_بنياد;
      DWORD ورهاست_Protect;
      DWORD __alignment1;
      ULONGLONG Region_سائيز;
      DWORD State;
      DWORD Protect;
      DWORD Type;
      DWORD __alignment2;
    } يادگيري_BASIC_INFORMATION64_2,*PMEMORY_BASIC_INFORMATION64;

#وصف_ڪريو SECTION_QUERY 0x0001
#وصف_ڪريو SECTION_MAP_WRITE 0x0002
#وصف_ڪريو SECTION_MAP_READ 0x0004
#وصف_ڪريو SECTION_MAP_EXECUTE 0x0008
#وصف_ڪريو SECTION_EXTEND_سائيز 0x0010
#وصف_ڪريو SECTION_MAP_EXECUTE_EXPLICIT 0x0020

#وصف_ڪريو SECTION_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SECTION_QUERY| SECTION_MAP_WRITE | SECTION_MAP_READ | SECTION_MAP_EXECUTE | SECTION_EXTEND_سائيز)
#وصف_ڪريو صفحو_NOACCESS 0x01
#وصف_ڪريو صفحو_READONLY 0x02
#وصف_ڪريو صفحو_READWRITE 0x04
#وصف_ڪريو صفحو_WRITECOPY 0x08
#وصف_ڪريو صفحو_EXECUTE 0x10
#وصف_ڪريو صفحو_EXECUTE_READ 0x20
#وصف_ڪريو صفحو_EXECUTE_READWRITE 0x40
#وصف_ڪريو صفحو_EXECUTE_WRITECOPY 0x80
#وصف_ڪريو صفحو_GUARD 0x100
#وصف_ڪريو صفحو_NOCACHE 0x200
#وصف_ڪريو صفحو_WRITECOMBINE 0x400
#وصف_ڪريو MEM_COMMIT 0x1000
#وصف_ڪريو MEM_RESERVE 0x2000
#وصف_ڪريو MEM_DECOMMIT 0x4000
#وصف_ڪريو MEM_RELEASE 0x8000
#وصف_ڪريو MEM_FREE 0x10000
#وصف_ڪريو MEM_ذاتي 0x20000
#وصف_ڪريو MEM_MAPPED 0x40000
#وصف_ڪريو MEM_RESET 0x80000
#وصف_ڪريو MEM_چوٽي_هيٺ_ڏانهن 0x100000
#وصف_ڪريو MEM_WRITE_WATCH 0x200000
#وصف_ڪريو MEM_PHYSICAL 0x400000
#وصف_ڪريو MEM_LARGE_صفحا 0x20000000
#وصف_ڪريو MEM_4_MB_صفحا 0x80000000
#وصف_ڪريو SEC_FILE 0x800000
#وصف_ڪريو SEC_IMAGE 0x1000000
#وصف_ڪريو SEC_RESERVE 0x4000000
#وصف_ڪريو SEC_COMMIT 0x8000000
#وصف_ڪريو SEC_NOCACHE 0x10000000
#وصف_ڪريو SEC_LARGE_صفحا 0x80000000
#وصف_ڪريو MEM_IMAGE SEC_IMAGE
#وصف_ڪريو WRITE_WATCH_FLAG_RESET 0x01

#وصف_ڪريو FILE_READ_معلومات (0x0001)
#وصف_ڪريو FILE_LIST_DIRECTORY (0x0001)

#وصف_ڪريو FILE_WRITE_معلومات (0x0002)
#وصف_ڪريو FILE_جوڙيو_FILE (0x0002)

#وصف_ڪريو FILE_APPEND_معلومات (0x0004)
#وصف_ڪريو FILE_جوڙيو_SUBDIRECTORY (0x0004)
#وصف_ڪريو FILE_CREATE_PIPE_INSTANCE (0x0004)

#وصف_ڪريو FILE_READ_EA (0x0008)

#وصف_ڪريو FILE_WRITE_EA (0x0010)

#وصف_ڪريو FILE_EXECUTE (0x0020)
#وصف_ڪريو FILE_TRAVERSE (0x0020)

#وصف_ڪريو FILE_DELETE_ٻار (0x0040)

#وصف_ڪريو FILE_READ_خاصيتون (0x0080)

#وصف_ڪريو FILE_WRITE_خاصيتون (0x0100)

#وصف_ڪريو FILE_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0x1FF)
#وصف_ڪريو FILE_GENERIC_READ (STANDARD_RIGHTS_READ | FILE_READ_معلومات | FILE_READ_خاصيتون | FILE_READ_EA | SYNCHRONIZE)
#وصف_ڪريو FILE_GENERIC_WRITE (STANDARD_RIGHTS_WRITE | FILE_WRITE_معلومات | FILE_WRITE_خاصيتون | FILE_WRITE_EA | FILE_APPEND_معلومات | SYNCHRONIZE)
#وصف_ڪريو FILE_GENERIC_EXECUTE (STANDARD_RIGHTS_EXECUTE | FILE_READ_خاصيتون | FILE_EXECUTE | SYNCHRONIZE)

#وصف_ڪريو FILE_SHARE_READ 0x00000001
#وصف_ڪريو FILE_SHARE_WRITE 0x00000002
#وصف_ڪريو FILE_SHARE_DELETE 0x00000004
#وصف_ڪريو FILE_ATTRIBUTE_READONLY 0x00000001
#وصف_ڪريو FILE_ATTRIBUTE_HIDDEN 0x00000002
#وصف_ڪريو FILE_ATTRIBUTE_SYSTEM 0x00000004
#وصف_ڪريو FILE_ATTRIBUTE_DIRECTORY 0x00000010
#وصف_ڪريو FILE_ATTRIBUTE_ARCHIVE 0x00000020
#وصف_ڪريو FILE_ATTRIBUTE_DEVICE 0x00000040
#وصف_ڪريو FILE_ATTRIBUTE_عام 0x00000080
#وصف_ڪريو FILE_ATTRIBUTE_TEMPORARY 0x00000100
#وصف_ڪريو FILE_ATTRIBUTE_SPARSE_FILE 0x00000200
#وصف_ڪريو FILE_ATTRIBUTE_REPARSE_نقطو 0x00000400
#وصف_ڪريو FILE_ATTRIBUTE_COMPRESSED 0x00000800
#وصف_ڪريو FILE_ATTRIBUTE_OFFLINE 0x00001000
#وصف_ڪريو FILE_ATTRIBUTE_NOT_CONTENT_اشاريي_وارو 0x00002000
#وصف_ڪريو FILE_ATTRIBUTE_ENCRYPTED 0x00004000
#وصف_ڪريو FILE_NOTIFY_CHANGE_FILE_NAME 0x00000001
#وصف_ڪريو FILE_NOTIFY_CHANGE_DIR_NAME 0x00000002
#وصف_ڪريو FILE_NOTIFY_CHANGE_خاصيتون 0x00000004
#وصف_ڪريو FILE_NOTIFY_CHANGE_سائيز 0x00000008
#وصف_ڪريو FILE_NOTIFY_CHANGE_آخري_WRITE 0x00000010
#وصف_ڪريو FILE_NOTIFY_CHANGE_آخري_ACCESS 0x00000020
#وصف_ڪريو FILE_NOTIFY_CHANGE_CREATION 0x00000040
#وصف_ڪريو FILE_NOTIFY_CHANGE_SECURITY 0x00000100
#وصف_ڪريو FILE_ACTION_ADDED 0x00000001
#وصف_ڪريو FILE_ACTION_REMOVED 0x00000002
#وصف_ڪريو FILE_ACTION_MODIFIED 0x00000003
#وصف_ڪريو FILE_ACTION_RENAMED_OLD_NAME 0x00000004
#وصف_ڪريو FILE_ACTION_RENAMED_NEW_NAME 0x00000005
#وصف_ڪريو MAILSLOT_NO_پيغام ((DWORD)-1)
#وصف_ڪريو MAILSLOT_WAIT_FOREVER ((DWORD)-1)
#وصف_ڪريو FILE_CASE_SENSITIVE_ڳولا 0x00000001
#وصف_ڪريو FILE_CASE_PRESERVED_نالا 0x00000002
#وصف_ڪريو FILE_UNICODE_ON_DISK 0x00000004
#وصف_ڪريو FILE_PERSISTENT_ACLS 0x00000008
#وصف_ڪريو FILE_FILE_COMPRESSION 0x00000010
#وصف_ڪريو FILE_VOLUME_QUOTAS 0x00000020
#وصف_ڪريو FILE_SUPPORTS_SPARSE_FILES 0x00000040
#وصف_ڪريو FILE_SUPPORTS_REPARSE_POINTS 0x00000080
#وصف_ڪريو FILE_SUPPORTS_REMOTE_STORAGE 0x00000100
#وصف_ڪريو FILE_VOLUME_IS_COMPRESSED 0x00008000
#وصف_ڪريو FILE_SUPPORTS_OBJECT_IDS 0x00010000
#وصف_ڪريو FILE_SUPPORTS_ENCRYPTION 0x00020000
#وصف_ڪريو FILE_NAMED_STREAMS 0x00040000
#وصف_ڪريو FILE_READ_ONLY_VOLUME 0x00080000

    تعريفنوع بنية _FILE_NOTIFY_INFORMATION {
      DWORD ايندڙ_داخلا_وٿي;
      DWORD Action;
      DWORD File_Name_ڊيگهائي;
      WCHAR FileName[1];
    } FILE_NOTIFY_INFORMATION,*PFILE_NOTIFY_INFORMATION;

    تعريفنوع اتحاد _FILE_SEGMENT_ELEMENT {
      PVOID64 بفر_3;
      ULONGLONG Alignment;
    }FILE_SEGMENT_ELEMENT,*PFILE_SEGMENT_ELEMENT;

    تعريفنوع بنية REPARSE_GUID_معلومات_بفر {
      DWORD Reparse_ٽيگ;
      لفظ_3 Reparse_معلومات_ڊيگهائي;
      لفظ_3 Reserved;
      GUID ReparseGuid;
      بنية {
	BYTE معلومات_بفر[1];
      } Generic_Reparse_بفر;
    } REPARSE_GUID_معلومات_بفر_2,*PREPARSE_GUID_معلومات_بفر;

#وصف_ڪريو REPARSE_GUID_معلومات_بفر_سرو_سائيز ميدان_وٿي(REPARSE_GUID_معلومات_بفر_2,Generic_Reparse_بفر)

#وصف_ڪريو وڌ_کان_وڌ_REPARSE_معلومات_بفر_سائيز (16 *1024)

#وصف_ڪريو IO_REPARSE_ٽيگ_RESERVED_ZERO (0)
#وصف_ڪريو IO_REPARSE_ٽيگ_RESERVED_ONE (1)

#وصف_ڪريو IO_REPARSE_ٽيگ_RESERVED_RANGE IO_REPARSE_ٽيگ_RESERVED_ONE

#وصف_ڪريو Is_Reparse_ٽيگ_Microsoft(ٽيگ_2) (((ٽيگ_2) & 0x80000000))
#وصف_ڪريو Is_Reparse_ٽيگ_Name_Surrogate(ٽيگ_2) (((ٽيگ_2) & 0x20000000))

#وصف_ڪريو IO_REPARSE_ٽيگ_MOUNT_نقطو (0xA0000003L)
#وصف_ڪريو IO_REPARSE_ٽيگ_HSM (0xC0000004L)
#وصف_ڪريو IO_REPARSE_ٽيگ_SIS (0x80000007L)
#وصف_ڪريو IO_REPARSE_ٽيگ_DFS (0x8000000AL)
#وصف_ڪريو IO_REPARSE_ٽيگ_FILTER_MANAGER (0x8000000BL)
#وصف_ڪريو IO_COMPLETION_MODIFY_STATE 0x0002
#وصف_ڪريو IO_COMPLETION_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x3)
#وصف_ڪريو DUPLICATE_CLOSE_ذريعو 0x00000001
#وصف_ڪريو DUPLICATE_SAME_ACCESS 0x00000002

    تعريفنوع تعداد _SYSTEM_POWER_STATE {
      PowerSystemUnspecified = 0,PowerSystemWorking = 1,PowerSystemSleeping1 = 2,PowerSystemSleeping2 = 3,PowerSystemSleeping3 = 4,PowerSystemHibernate = 5,PowerSystemShutdown = 6,Power_System_وڌ_کان_وڌ = 7
    } SYSTEM_POWER_STATE,*PSYSTEM_POWER_STATE;

#وصف_ڪريو POWER_SYSTEM_وڌ_کان_وڌ 7

    تعريفنوع تعداد {
      PowerActionNone = 0,PowerActionReserved,PowerActionSleep,PowerActionHibernate,PowerActionShutdown,PowerActionShutdownReset,PowerActionShutdownOff,PowerActionWarmEject
    } POWER_ACTION,*PPOWER_ACTION;

    تعريفنوع تعداد _DEVICE_POWER_STATE {
      PowerDeviceUnspecified = 0,PowerDeviceD0,PowerDeviceD1,PowerDeviceD2,PowerDeviceD3,Power_Device_وڌ_کان_وڌ
    } DEVICE_POWER_STATE,*PDEVICE_POWER_STATE;

#وصف_ڪريو ES_SYSTEM_REQUIRED ((DWORD)0x00000001)
#وصف_ڪريو ES_DISPLAY_REQUIRED ((DWORD)0x00000002)
#وصف_ڪريو ES_USER_PRESENT ((DWORD)0x00000004)
#وصف_ڪريو ES_CONTINUOUS ((DWORD)0x80000000)

    تعريفنوع DWORD EXECUTION_STATE;

    تعريفنوع تعداد {
      LT_DONT_CARE,LT_سڀ_کان_هيٺ_LATENCY
    } LATENCY_وقت;

#وصف_ڪريو PDCAP_D0_SUPPORTED 0x00000001
#وصف_ڪريو PDCAP_D1_SUPPORTED 0x00000002
#وصف_ڪريو PDCAP_D2_SUPPORTED 0x00000004
#وصف_ڪريو PDCAP_D3_SUPPORTED 0x00000008
#وصف_ڪريو PDCAP_WAKE_FROM_D0_SUPPORTED 0x00000010
#وصف_ڪريو PDCAP_WAKE_FROM_D1_SUPPORTED 0x00000020
#وصف_ڪريو PDCAP_WAKE_FROM_D2_SUPPORTED 0x00000040
#وصف_ڪريو PDCAP_WAKE_FROM_D3_SUPPORTED 0x00000080
#وصف_ڪريو PDCAP_WARM_EJECT_SUPPORTED 0x00000100

    تعريفنوع بنية CM_Power_معلومات_s {
      DWORD PD_سائيز;
      DEVICE_POWER_STATE PD_MostRecentPowerState;
      DWORD PD_Capabilities;
      DWORD PD_D1Latency;
      DWORD PD_D2Latency;
      DWORD PD_D3Latency;
      DEVICE_POWER_STATE PD_PowerStateMapping[POWER_SYSTEM_وڌ_کان_وڌ];
      SYSTEM_POWER_STATE PD_سڀ_کان_اونهو_System_Wake;
    } CM_POWER_معلومات,*PCM_POWER_معلومات;

    تعريفنوع تعداد {
      SystemPowerPolicyAc,SystemPowerPolicyDc,VerifySystemPolicyAc,VerifySystemPolicyDc,SystemPowerCapabilities,SystemBatteryState,SystemPowerStateHandler,ProcessorStateHandler,SystemPowerPolicyCurrent,AdministratorPowerPolicy,SystemReserveHiberFile,ProcessorInformation,SystemPowerInformation,ProcessorStateHandler2,آخري_Wake_وقت,آخري_Sleep_وقت,SystemExecutionState,SystemPowerStateNotifyHandler,ProcessorPowerPolicyAc,ProcessorPowerPolicyDc,VerifyProcessorPowerPolicyAc,VerifyProcessorPowerPolicyDc,ProcessorPowerPolicyCurrent,SystemPowerStateLogging,System_Power_Logging_داخلا
    } POWER_INFORMATION_LEVEL;

    تعريفنوع بنية {
      DWORD Granularity;
      DWORD صلاحيت;
    } BATTERY_REPORTING_SCALE,*PBATTERY_REPORTING_SCALE;

    تعريفنوع بنية {
      POWER_ACTION Action;
      DWORD Flags;
      DWORD Event_ڪوڊ;
    } POWER_ACTION_POLICY,*PPOWER_ACTION_POLICY;

#وصف_ڪريو POWER_ACTION_QUERY_ALLOWED 0x00000001
#وصف_ڪريو POWER_ACTION_UI_ALLOWED 0x00000002
#وصف_ڪريو POWER_ACTION_OVERRIDE_APPS 0x00000004
#وصف_ڪريو POWER_ACTION_LIGHTEST_پهريون 0x10000000
#وصف_ڪريو POWER_ACTION_تالو_CONSOLE 0x20000000
#وصف_ڪريو POWER_ACTION_DISABLE_WAKES 0x40000000
#وصف_ڪريو POWER_ACTION_CRITICAL 0x80000000

#وصف_ڪريو POWER_LEVEL_USER_NOTIFY_متن 0x00000001
#وصف_ڪريو POWER_LEVEL_USER_NOTIFY_SOUND 0x00000002
#وصف_ڪريو POWER_LEVEL_USER_NOTIFY_EXEC 0x00000004
#وصف_ڪريو POWER_USER_NOTIFY_BUTTON 0x00000008
#وصف_ڪريو POWER_USER_NOTIFY_SHUTDOWN 0x00000010
#وصف_ڪريو POWER_FORCE_TRIGGER_RESET 0x80000000

    تعريفنوع بنية {
      BOOLEAN Enable;
      BYTE اضافي_2[3];
      DWORD BatteryLevel;
      POWER_ACTION_POLICY PowerPolicy;
      SYSTEM_POWER_STATE MinSystemState;
    } SYSTEM_POWER_LEVEL,*PSYSTEM_POWER_LEVEL;

#وصف_ڪريو انگ_DISCHARGE_POLICIES 4
#وصف_ڪريو DISCHARGE_POLICY_CRITICAL 0
#وصف_ڪريو DISCHARGE_POLICY_هيٺيون 1

#وصف_ڪريو PO_THROTTLE_NONE 0
#وصف_ڪريو PO_THROTTLE_CONSTANT 1
#وصف_ڪريو PO_THROTTLE_DEGRADE 2
#وصف_ڪريو PO_THROTTLE_ADAPTIVE 3
#وصف_ڪريو PO_THROTTLE_وڌ_کان_وڌ 4

    تعريفنوع بنية _SYSTEM_POWER_POLICY {
      DWORD Revision;
      POWER_ACTION_POLICY PowerButton;
      POWER_ACTION_POLICY SleepButton;
      POWER_ACTION_POLICY LidClose;
      SYSTEM_POWER_STATE LidOpenWake;
      DWORD Reserved;
      POWER_ACTION_POLICY Idle;
      DWORD IdleTimeout;
      BYTE Idle_حساسيت;
      BYTE DynamicThrottle;
      BYTE Spare2[2];
      SYSTEM_POWER_STATE MinSleep;
      SYSTEM_POWER_STATE MaxSleep;
      SYSTEM_POWER_STATE ReducedLatencySleep;
      DWORD WinLogonFlags;
      DWORD Spare3;
      DWORD DozeS4Timeout;
      DWORD نشر_صلاحيت_Resolution;
      SYSTEM_POWER_LEVEL DischargePolicy[انگ_DISCHARGE_POLICIES];
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
      DWORD وقت_Check;
      DWORD Demote_حد_بندي;
      DWORD Promote_حد_بندي;
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
      DWORD Policy_ڳڻپ;
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
      BOOLEAN ڀريل_Wake;
      BOOLEAN VideoDimPresent;
      BOOLEAN ApmPresent;
      BOOLEAN UpsPresent;
      BOOLEAN ThermalControl;
      BOOLEAN ProcessorThrottle;
      BYTE ProcessorMinThrottle;
      BYTE ProcessorMaxThrottle;
      BYTE spare2[4];
      BOOLEAN Disk_Spin_هيٺ_ڏانهن;
      BYTE spare3[8];
      BOOLEAN SystemBatteriesPresent;
      BOOLEAN Batteries_Are_Short_رڪن;
      BATTERY_REPORTING_SCALE BatteryScale[3];
      SYSTEM_POWER_STATE Ac_On_سٽ_Wake;
      SYSTEM_POWER_STATE SoftLidWake;
      SYSTEM_POWER_STATE RtcWake;
      SYSTEM_POWER_STATE MinDeviceWakeState;
      SYSTEM_POWER_STATE Default_هيٺيون_Latency_Wake;
    } SYSTEM_POWER_CAPABILITIES,*PSYSTEM_POWER_CAPABILITIES;

    تعريفنوع بنية {
      BOOLEAN Ac_On_سٽ;
      BOOLEAN BatteryPresent;
      BOOLEAN Charging;
      BOOLEAN Discharging;
      BOOLEAN Spare1[4];
      DWORD Max_صلاحيت;
      DWORD بچيل_صلاحيت;
      DWORD شرح;
      DWORD Estimated_وقت;
      DWORD DefaultAlert1;
      DWORD DefaultAlert2;
    } SYSTEM_BATTERY_STATE,*PSYSTEM_BATTERY_STATE;

#ضمن "pshpack4.h"

#وصف_ڪريو IMAGE_DOS_SIGNATURE 0x5A4D
#وصف_ڪريو IMAGE_OS2_SIGNATURE 0x454E
#وصف_ڪريو IMAGE_OS2_SIGNATURE_LE 0x454C
#وصف_ڪريو IMAGE_VXD_SIGNATURE 0x454C
#وصف_ڪريو IMAGE_NT_SIGNATURE 0x00004550

#ضمن "pshpack2.h"

    تعريفنوع بنية IMAGE_DOS_سرو {
      لفظ_3 e_magic;
      لفظ_3 e_cblp;
      لفظ_3 e_cp;
      لفظ_3 e_crlc;
      لفظ_3 e_cparhdr;
      لفظ_3 e_minalloc;
      لفظ_3 e_maxalloc;
      لفظ_3 e_ss;
      لفظ_3 e_sp;
      لفظ_3 e_csum;
      لفظ_3 e_ip;
      لفظ_3 e_cs;
      لفظ_3 e_lfarlc;
      لفظ_3 e_ovno;
      لفظ_3 e_res[4];
      لفظ_3 e_oemid;
      لفظ_3 e_oeminfo;
      لفظ_3 e_res2[10];
      LONG e_lfanew;
    } IMAGE_DOS_سرو_2,*PIMAGE_DOS_سرو;

    تعريفنوع بنية IMAGE_OS2_سرو {
      لفظ_3 ne_magic;
      CHAR ne_ver;
      CHAR ne_rev;
      لفظ_3 ne_enttab;
      لفظ_3 ne_cbenttab;
      LONG ne_چڪري_جاچ;
      لفظ_3 ne_flags;
      لفظ_3 ne_autodata;
      لفظ_3 ne_ڍير;
      لفظ_3 ne_ڍير_2;
      LONG ne_csip;
      LONG ne_sssp;
      لفظ_3 ne_cseg;
      لفظ_3 ne_cmod;
      لفظ_3 ne_cbnrestab;
      لفظ_3 ne_segtab;
      لفظ_3 ne_rsrctab;
      لفظ_3 ne_restab;
      لفظ_3 ne_modtab;
      لفظ_3 ne_imptab;
      LONG ne_nrestab;
      لفظ_3 ne_cmovent;
      لفظ_3 ne_align;
      لفظ_3 ne_cres;
      BYTE ne_exetyp;
      BYTE ne_flagsothers;
      لفظ_3 ne_pretthunks;
      لفظ_3 ne_psegrefbytes;
      لفظ_3 ne_swaparea;
      لفظ_3 ne_expver;
    } IMAGE_OS2_سرو_2,*PIMAGE_OS2_سرو;

    تعريفنوع بنية IMAGE_VXD_سرو {
      لفظ_3 e32_magic;
      BYTE e32_border;
      BYTE e32_worder;
      DWORD e32_level;
      لفظ_3 e32_cpu;
      لفظ_3 e32_os;
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
      لفظ_3 e32_devid;
      لفظ_3 e32_ddkver;
    } IMAGE_VXD_سرو_2,*PIMAGE_VXD_سرو;

#ضمن "poppack.h"

    تعريفنوع بنية IMAGE_FILE_سرو {
      لفظ_3 Machine;
      لفظ_3 عدد_جو_Sections;
      DWORD وقت_Date_Stamp;
      DWORD اشارو_منزل_نشان_جدول;
      DWORD عدد_جو_Symbols;
      لفظ_3 سائيز_جو_Optional_سرو;
      لفظ_3 Characteristics;
    } IMAGE_FILE_سرو_2,*PIMAGE_FILE_سرو;

#وصف_ڪريو IMAGE_SIZEOF_FILE_سرو 20

#وصف_ڪريو IMAGE_FILE_RELOCS_STRIPPED 0x0001
#وصف_ڪريو IMAGE_FILE_EXECUTABLE_IMAGE 0x0002
#وصف_ڪريو IMAGE_FILE_سٽ_NUMS_STRIPPED 0x0004
#وصف_ڪريو IMAGE_FILE_LOCAL_SYMS_STRIPPED 0x0008
#وصف_ڪريو IMAGE_FILE_AGGRESIVE_WS_TRIM 0x0010
#وصف_ڪريو IMAGE_FILE_LARGE_پتو_AWARE 0x0020
#وصف_ڪريو IMAGE_FILE_بائيٽون_REVERSED_LO 0x0080
#وصف_ڪريو IMAGE_FILE_32_ٻٽو_انگ_MACHINE 0x0100
#وصف_ڪريو IMAGE_FILE_DEBUG_STRIPPED 0x0200
#وصف_ڪريو IMAGE_FILE_REMOVABLE_لاڳيتو_FROM_مٽا_سٽا 0x0400
#وصف_ڪريو IMAGE_FILE_NET_لاڳيتو_FROM_مٽا_سٽا 0x0800
#وصف_ڪريو IMAGE_FILE_SYSTEM 0x1000
#وصف_ڪريو IMAGE_FILE_DLL 0x2000
#وصف_ڪريو IMAGE_FILE_مٿي_SYSTEM_ONLY 0x4000
#وصف_ڪريو IMAGE_FILE_بائيٽون_REVERSED_HI 0x8000

#وصف_ڪريو IMAGE_FILE_MACHINE_UNKNOWN 0
#وصف_ڪريو IMAGE_FILE_MACHINE_I386 0x014c
#وصف_ڪريو IMAGE_FILE_MACHINE_R3000 0x0162
#وصف_ڪريو IMAGE_FILE_MACHINE_R4000 0x0166
#وصف_ڪريو IMAGE_FILE_MACHINE_R10000 0x0168
#وصف_ڪريو IMAGE_FILE_MACHINE_WCEMIPSV2 0x0169
#وصف_ڪريو IMAGE_FILE_MACHINE_ALPHA 0x0184
#وصف_ڪريو IMAGE_FILE_MACHINE_SH3 0x01a2
#وصف_ڪريو IMAGE_FILE_MACHINE_SH3DSP 0x01a3
#وصف_ڪريو IMAGE_FILE_MACHINE_SH3E 0x01a4
#وصف_ڪريو IMAGE_FILE_MACHINE_SH4 0x01a6
#وصف_ڪريو IMAGE_FILE_MACHINE_SH5 0x01a8
#وصف_ڪريو IMAGE_FILE_MACHINE_ARM 0x01c0
#وصف_ڪريو IMAGE_FILE_MACHINE_THUMB 0x01c2
#وصف_ڪريو IMAGE_FILE_MACHINE_AM33 0x01d3
#وصف_ڪريو IMAGE_FILE_MACHINE_POWERPC 0x01F0
#وصف_ڪريو IMAGE_FILE_MACHINE_POWERPCFP 0x01f1
#وصف_ڪريو IMAGE_FILE_MACHINE_IA64 0x0200
#وصف_ڪريو IMAGE_FILE_MACHINE_MIPS16 0x0266
#وصف_ڪريو IMAGE_FILE_MACHINE_ALPHA64 0x0284
#وصف_ڪريو IMAGE_FILE_MACHINE_MIPSFPU 0x0366
#وصف_ڪريو IMAGE_FILE_MACHINE_MIPSFPU16 0x0466
#وصف_ڪريو IMAGE_FILE_MACHINE_AXP64 IMAGE_FILE_MACHINE_ALPHA64
#وصف_ڪريو IMAGE_FILE_MACHINE_TRICORE 0x0520
#وصف_ڪريو IMAGE_FILE_MACHINE_CEF 0x0CEF
#وصف_ڪريو IMAGE_FILE_MACHINE_EBC 0x0EBC
#وصف_ڪريو IMAGE_FILE_MACHINE_AMD64 0x8664
#وصف_ڪريو IMAGE_FILE_MACHINE_ARM64 0xAA64
#وصف_ڪريو IMAGE_FILE_MACHINE_M32R 0x9041
#وصف_ڪريو IMAGE_FILE_MACHINE_CEE 0xC0EE

    تعريفنوع بنية IMAGE_معلومات_DIRECTORY {
      DWORD Virtual_پتو;
      DWORD سائيز_3;
    } IMAGE_معلومات_DIRECTORY_2,*PIMAGE_معلومات_DIRECTORY;

#وصف_ڪريو IMAGE_NUMBEROF_DIRECTORY_ENTRIES 16

    تعريفنوع بنية IMAGE_OPTIONAL_سرو {

      لفظ_3 Magic;
      BYTE Major_Linker_نسخو;
      BYTE Minor_Linker_نسخو;
      DWORD سائيز_جو_ڪوڊ;
      DWORD سائيز_جو_Initialized_معلومات;
      DWORD سائيز_جو_Uninitialized_معلومات;
      DWORD پتو_جو_داخلا_نقطو;
      DWORD بنياد_جو_ڪوڊ;
      DWORD بنياد_جو_معلومات;
      DWORD Image_بنياد;
      DWORD SectionAlignment;
      DWORD FileAlignment;
      لفظ_3 Major_Operating_System_نسخو;
      لفظ_3 Minor_Operating_System_نسخو;
      لفظ_3 Major_Image_نسخو;
      لفظ_3 Minor_Image_نسخو;
      لفظ_3 Major_Subsystem_نسخو;
      لفظ_3 Minor_Subsystem_نسخو;
      DWORD Win32_نسخو_قدر;
      DWORD سائيز_جو_Image;
      DWORD سائيز_جو_سرا;
      DWORD Check_جوڙ;
      لفظ_3 Subsystem;
      لفظ_3 DllCharacteristics;
      DWORD سائيز_جو_ڍير_Reserve;
      DWORD سائيز_جو_ڍير_Commit;
      DWORD سائيز_جو_ڍير_Reserve_2;
      DWORD سائيز_جو_ڍير_Commit_2;
      DWORD LoaderFlags;
      DWORD عدد_جو_Rva_And_Sizes;
      IMAGE_معلومات_DIRECTORY_2 معلومات_Directory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
    } IMAGE_OPTIONAL_HEADER32,*PIMAGE_OPTIONAL_HEADER32;

    تعريفنوع بنية IMAGE_ROM_OPTIONAL_سرو {
      لفظ_3 Magic;
      BYTE Major_Linker_نسخو;
      BYTE Minor_Linker_نسخو;
      DWORD سائيز_جو_ڪوڊ;
      DWORD سائيز_جو_Initialized_معلومات;
      DWORD سائيز_جو_Uninitialized_معلومات;
      DWORD پتو_جو_داخلا_نقطو;
      DWORD بنياد_جو_ڪوڊ;
      DWORD بنياد_جو_معلومات;
      DWORD بنياد_جو_Bss;
      DWORD Gpr_نقاب;
      DWORD Cpr_نقاب[4];
      DWORD Gp_قدر;
    } IMAGE_ROM_OPTIONAL_سرو_2,*PIMAGE_ROM_OPTIONAL_سرو;

    تعريفنوع بنية _IMAGE_OPTIONAL_HEADER64 {
      لفظ_3 Magic;
      BYTE Major_Linker_نسخو;
      BYTE Minor_Linker_نسخو;
      DWORD سائيز_جو_ڪوڊ;
      DWORD سائيز_جو_Initialized_معلومات;
      DWORD سائيز_جو_Uninitialized_معلومات;
      DWORD پتو_جو_داخلا_نقطو;
      DWORD بنياد_جو_ڪوڊ;
      ULONGLONG Image_بنياد;
      DWORD SectionAlignment;
      DWORD FileAlignment;
      لفظ_3 Major_Operating_System_نسخو;
      لفظ_3 Minor_Operating_System_نسخو;
      لفظ_3 Major_Image_نسخو;
      لفظ_3 Minor_Image_نسخو;
      لفظ_3 Major_Subsystem_نسخو;
      لفظ_3 Minor_Subsystem_نسخو;
      DWORD Win32_نسخو_قدر;
      DWORD سائيز_جو_Image;
      DWORD سائيز_جو_سرا;
      DWORD Check_جوڙ;
      لفظ_3 Subsystem;
      لفظ_3 DllCharacteristics;
      ULONGLONG سائيز_جو_ڍير_Reserve;
      ULONGLONG سائيز_جو_ڍير_Commit;
      ULONGLONG سائيز_جو_ڍير_Reserve_2;
      ULONGLONG سائيز_جو_ڍير_Commit_2;
      DWORD LoaderFlags;
      DWORD عدد_جو_Rva_And_Sizes;
      IMAGE_معلومات_DIRECTORY_2 معلومات_Directory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
    } IMAGE_OPTIONAL_HEADER64,*PIMAGE_OPTIONAL_HEADER64;

#وصف_ڪريو IMAGE_SIZEOF_ROM_OPTIONAL_سرو 56
#وصف_ڪريو IMAGE_SIZEOF_STD_OPTIONAL_سرو 28
#وصف_ڪريو IMAGE_SIZEOF_NT_OPTIONAL32_سرو 224
#وصف_ڪريو IMAGE_SIZEOF_NT_OPTIONAL64_سرو 240

#وصف_ڪريو IMAGE_NT_OPTIONAL_HDR32_MAGIC 0x10b
#وصف_ڪريو IMAGE_NT_OPTIONAL_HDR64_MAGIC 0x20b
#وصف_ڪريو IMAGE_ROM_OPTIONAL_HDR_MAGIC 0x107

#جيڪڏهن_وصف_ٿيل _WIN64
    تعريفنوع IMAGE_OPTIONAL_HEADER64 IMAGE_OPTIONAL_سرو_2;
    تعريفنوع PIMAGE_OPTIONAL_HEADER64 PIMAGE_OPTIONAL_سرو;
#وصف_ڪريو IMAGE_SIZEOF_NT_OPTIONAL_سرو IMAGE_SIZEOF_NT_OPTIONAL64_سرو
#وصف_ڪريو IMAGE_NT_OPTIONAL_HDR_MAGIC IMAGE_NT_OPTIONAL_HDR64_MAGIC
#وإلا
    تعريفنوع IMAGE_OPTIONAL_HEADER32 IMAGE_OPTIONAL_سرو_2;
    تعريفنوع PIMAGE_OPTIONAL_HEADER32 PIMAGE_OPTIONAL_سرو;
#وصف_ڪريو IMAGE_SIZEOF_NT_OPTIONAL_سرو IMAGE_SIZEOF_NT_OPTIONAL32_سرو
#وصف_ڪريو IMAGE_NT_OPTIONAL_HDR_MAGIC IMAGE_NT_OPTIONAL_HDR32_MAGIC
#جيڪڏهن_پورو

    تعريفنوع بنية _IMAGE_NT_HEADERS64 {
      DWORD Signature;
      IMAGE_FILE_سرو_2 File_سرو;
      IMAGE_OPTIONAL_HEADER64 Optional_سرو;
    } IMAGE_NT_HEADERS64,*PIMAGE_NT_HEADERS64;

    تعريفنوع بنية IMAGE_NT_سرا {
      DWORD Signature;
      IMAGE_FILE_سرو_2 File_سرو;
      IMAGE_OPTIONAL_HEADER32 Optional_سرو;
    } IMAGE_NT_HEADERS32,*PIMAGE_NT_HEADERS32;

    تعريفنوع بنية IMAGE_ROM_سرا {
      IMAGE_FILE_سرو_2 File_سرو;
      IMAGE_ROM_OPTIONAL_سرو_2 Optional_سرو;
    } IMAGE_ROM_سرا_2,*PIMAGE_ROM_سرا;

#جيڪڏهن_وصف_ٿيل _WIN64
    تعريفنوع IMAGE_NT_HEADERS64 IMAGE_NT_سرا_2;
    تعريفنوع PIMAGE_NT_HEADERS64 PIMAGE_NT_سرا;
#وإلا
    تعريفنوع IMAGE_NT_HEADERS32 IMAGE_NT_سرا_2;
    تعريفنوع PIMAGE_NT_HEADERS32 PIMAGE_NT_سرا;
#جيڪڏهن_پورو

#وصف_ڪريو IMAGE_پهريون_SECTION(ntheader) ((PIMAGE_SECTION_سرو) ((ULONG_PTR)ntheader + ميدان_وٿي(IMAGE_NT_سرا_2,Optional_سرو) + ((PIMAGE_NT_سرا)(ntheader))->File_سرو.سائيز_جو_Optional_سرو))

#وصف_ڪريو IMAGE_SUBSYSTEM_UNKNOWN 0
#وصف_ڪريو IMAGE_SUBSYSTEM_NATIVE 1
#وصف_ڪريو IMAGE_SUBSYSTEM_WINDOWS_GUI 2
#وصف_ڪريو IMAGE_SUBSYSTEM_WINDOWS_CUI 3
#وصف_ڪريو IMAGE_SUBSYSTEM_OS2_CUI 5
#وصف_ڪريو IMAGE_SUBSYSTEM_POSIX_CUI 7
#وصف_ڪريو IMAGE_SUBSYSTEM_NATIVE_WINDOWS 8
#وصف_ڪريو IMAGE_SUBSYSTEM_WINDOWS_CE_GUI 9
#وصف_ڪريو IMAGE_SUBSYSTEM_EFI_APPLICATION 10
#وصف_ڪريو IMAGE_SUBSYSTEM_EFI_BOOT_SERVICE_DRIVER 11
#وصف_ڪريو IMAGE_SUBSYSTEM_EFI_RUNTIME_DRIVER 12
#وصف_ڪريو IMAGE_SUBSYSTEM_EFI_ROM 13
#وصف_ڪريو IMAGE_SUBSYSTEM_XBOX 14

#وصف_ڪريو IMAGE_DLLCHARACTERISTICS_مٿاهون_ENTROPY_VA 0x0020
#وصف_ڪريو IMAGE_DLLCHARACTERISTICS_DYNAMIC_بنياد 0x0040
#وصف_ڪريو IMAGE_DLLCHARACTERISTICS_FORCE_INTEGRITY 0x0080
#وصف_ڪريو IMAGE_DLLCHARACTERISTICS_NX_COMPAT 0x0100
#وصف_ڪريو IMAGE_DLLCHARACTERISTICS_NO_ISOLATION 0x0200
#وصف_ڪريو IMAGE_DLLCHARACTERISTICS_NO_SEH 0x0400
#وصف_ڪريو IMAGE_DLLCHARACTERISTICS_NO_BIND 0x0800
#وصف_ڪريو IMAGE_DLLCHARACTERISTICS_APPCONTAINER 0x1000
#وصف_ڪريو IMAGE_DLLCHARACTERISTICS_WDM_DRIVER 0x2000
#وصف_ڪريو IMAGE_DLLCHARACTERISTICS_GUARD_CF 0x4000
#وصف_ڪريو IMAGE_DLLCHARACTERISTICS_TERMINAL_SERVER_AWARE 0x8000

#وصف_ڪريو IMAGE_DIRECTORY_داخلا_EXPORT 0
#وصف_ڪريو IMAGE_DIRECTORY_داخلا_IMPORT 1
#وصف_ڪريو IMAGE_DIRECTORY_داخلا_RESOURCE 2
#وصف_ڪريو IMAGE_DIRECTORY_داخلا_EXCEPTION 3
#وصف_ڪريو IMAGE_DIRECTORY_داخلا_SECURITY 4
#وصف_ڪريو IMAGE_DIRECTORY_داخلا_BASERELOC 5
#وصف_ڪريو IMAGE_DIRECTORY_داخلا_DEBUG 6

#وصف_ڪريو IMAGE_DIRECTORY_داخلا_ARCHITECTURE 7
#وصف_ڪريو IMAGE_DIRECTORY_داخلا_GLOBALPTR 8
#وصف_ڪريو IMAGE_DIRECTORY_داخلا_TLS 9
#وصف_ڪريو IMAGE_DIRECTORY_داخلا_ڀريو_CONFIG 10
#وصف_ڪريو IMAGE_DIRECTORY_داخلا_BOUND_IMPORT 11
#وصف_ڪريو IMAGE_DIRECTORY_داخلا_IAT 12
#وصف_ڪريو IMAGE_DIRECTORY_داخلا_DELAY_IMPORT 13
#وصف_ڪريو IMAGE_DIRECTORY_داخلا_COM_DESCRIPTOR 14

    تعريفنوع بنية ANON_OBJECT_سرو {
      لفظ_3 Sig1;
      لفظ_3 Sig2;
      لفظ_3 نسخو_2;
      لفظ_3 Machine;
      DWORD وقت_Date_Stamp;
      CLSID ClassID;
      DWORD سائيز_جو_معلومات;
    } ANON_OBJECT_سرو;

#وصف_ڪريو IMAGE_SIZEOF_SHORT_NAME 8

    تعريفنوع بنية IMAGE_SECTION_سرو {
      BYTE Name[IMAGE_SIZEOF_SHORT_NAME];
      اتحاد {
	DWORD Physical_پتو;
	DWORD Virtual_سائيز;
      } Misc;
      DWORD Virtual_پتو;
      DWORD سائيز_جو_Raw_معلومات;
      DWORD اشارو_منزل_Raw_معلومات;
      DWORD اشارو_منزل_Relocations;
      DWORD اشارو_منزل_Linenumbers;
      لفظ_3 عدد_جو_Relocations;
      لفظ_3 عدد_جو_Linenumbers;
      DWORD Characteristics;
    } IMAGE_SECTION_سرو_2,*PIMAGE_SECTION_سرو;

#وصف_ڪريو IMAGE_SIZEOF_SECTION_سرو 40

#وصف_ڪريو IMAGE_SCN_TYPE_NO_PAD 0x00000008

#وصف_ڪريو IMAGE_SCN_CNT_ڪوڊ 0x00000020
#وصف_ڪريو IMAGE_SCN_CNT_INITIALIZED_معلومات 0x00000040
#وصف_ڪريو IMAGE_SCN_CNT_UNINITIALIZED_معلومات 0x00000080
#وصف_ڪريو IMAGE_SCN_LNK_OTHER 0x00000100
#وصف_ڪريو IMAGE_SCN_LNK_INFO 0x00000200
#وصف_ڪريو IMAGE_SCN_LNK_REMOVE 0x00000800
#وصف_ڪريو IMAGE_SCN_LNK_COMDAT 0x00001000
#وصف_ڪريو IMAGE_SCN_NO_DEFER_SPEC_EXC 0x00004000
#وصف_ڪريو IMAGE_SCN_GPREL 0x00008000
#وصف_ڪريو IMAGE_SCN_MEM_FARDATA 0x00008000
#وصف_ڪريو IMAGE_SCN_MEM_PURGEABLE 0x00020000
#وصف_ڪريو IMAGE_SCN_MEM_16_ٻٽو_انگ 0x00020000
#وصف_ڪريو IMAGE_SCN_MEM_LOCKED 0x00040000
#وصف_ڪريو IMAGE_SCN_MEM_PRELOAD 0x00080000

#وصف_ڪريو IMAGE_SCN_ALIGN_1_بائيٽون 0x00100000
#وصف_ڪريو IMAGE_SCN_ALIGN_2_بائيٽون 0x00200000
#وصف_ڪريو IMAGE_SCN_ALIGN_4_بائيٽون 0x00300000
#وصف_ڪريو IMAGE_SCN_ALIGN_8_بائيٽون 0x00400000
#وصف_ڪريو IMAGE_SCN_ALIGN_16_بائيٽون 0x00500000
#وصف_ڪريو IMAGE_SCN_ALIGN_32_بائيٽون 0x00600000
#وصف_ڪريو IMAGE_SCN_ALIGN_64_بائيٽون 0x00700000
#وصف_ڪريو IMAGE_SCN_ALIGN_128_بائيٽون 0x00800000
#وصف_ڪريو IMAGE_SCN_ALIGN_256_بائيٽون 0x00900000
#وصف_ڪريو IMAGE_SCN_ALIGN_512_بائيٽون 0x00A00000
#وصف_ڪريو IMAGE_SCN_ALIGN_1024_بائيٽون 0x00B00000
#وصف_ڪريو IMAGE_SCN_ALIGN_2048_بائيٽون 0x00C00000
#وصف_ڪريو IMAGE_SCN_ALIGN_4096_بائيٽون 0x00D00000
#وصف_ڪريو IMAGE_SCN_ALIGN_8192_بائيٽون 0x00E00000

#وصف_ڪريو IMAGE_SCN_ALIGN_نقاب 0x00F00000

#وصف_ڪريو IMAGE_SCN_LNK_NRELOC_OVFL 0x01000000
#وصف_ڪريو IMAGE_SCN_MEM_DISCARDABLE 0x02000000
#وصف_ڪريو IMAGE_SCN_MEM_NOT_CACHED 0x04000000
#وصف_ڪريو IMAGE_SCN_MEM_NOT_PAGED 0x08000000
#وصف_ڪريو IMAGE_SCN_MEM_SHARED 0x10000000
#وصف_ڪريو IMAGE_SCN_MEM_EXECUTE 0x20000000
#وصف_ڪريو IMAGE_SCN_MEM_READ 0x40000000
#وصف_ڪريو IMAGE_SCN_MEM_WRITE 0x80000000

#وصف_ڪريو IMAGE_SCN_SCALE_اشاريو 0x00000001

#ضمن "pshpack2.h"

    تعريفنوع بنية IMAGE_نشان {
      اتحاد {
	BYTE ShortName[8];
	بنية {
	  DWORD Short;
	  DWORD Long;
	} Name;
	DWORD LongName[2];
      } N;
      DWORD قدر_3;
      SHORT Section_عدد;
      لفظ_3 Type;
      BYTE StorageClass;
      BYTE عدد_جو_Aux_Symbols;
    } IMAGE_نشان_2;
    تعريفنوع IMAGE_نشان_2 UNALIGNED *PIMAGE_نشان;

#وصف_ڪريو IMAGE_SIZEOF_نشان 18

#وصف_ڪريو IMAGE_SYM_UNDEFINED (SHORT)0
#وصف_ڪريو IMAGE_SYM_ABSOLUTE (SHORT)-1
#وصف_ڪريو IMAGE_SYM_DEBUG (SHORT)-2
#وصف_ڪريو IMAGE_SYM_SECTION_MAX 0xFEFF

#وصف_ڪريو IMAGE_SYM_TYPE_NULL 0x0000
#وصف_ڪريو IMAGE_SYM_TYPE_VOID 0x0001
#وصف_ڪريو IMAGE_SYM_TYPE_CHAR 0x0002
#وصف_ڪريو IMAGE_SYM_TYPE_SHORT 0x0003
#وصف_ڪريو IMAGE_SYM_TYPE_INT 0x0004
#وصف_ڪريو IMAGE_SYM_TYPE_LONG 0x0005
#وصف_ڪريو IMAGE_SYM_TYPE_FLOAT 0x0006
#وصف_ڪريو IMAGE_SYM_TYPE_DOUBLE 0x0007
#وصف_ڪريو IMAGE_SYM_TYPE_STRUCT 0x0008
#وصف_ڪريو IMAGE_SYM_TYPE_UNION 0x0009
#وصف_ڪريو IMAGE_SYM_TYPE_ENUM 0x000A
#وصف_ڪريو IMAGE_SYM_TYPE_MOE 0x000B
#وصف_ڪريو IMAGE_SYM_TYPE_BYTE 0x000C
#وصف_ڪريو IMAGE_SYM_TYPE_لفظ 0x000D
#وصف_ڪريو IMAGE_SYM_TYPE_UINT 0x000E
#وصف_ڪريو IMAGE_SYM_TYPE_DWORD 0x000F
#وصف_ڪريو IMAGE_SYM_TYPE_PCODE 0x8000

#وصف_ڪريو IMAGE_SYM_DTYPE_NULL 0
#وصف_ڪريو IMAGE_SYM_DTYPE_اشارو 1
#وصف_ڪريو IMAGE_SYM_DTYPE_FUNCTION 2
#وصف_ڪريو IMAGE_SYM_DTYPE_ARRAY 3

#وصف_ڪريو IMAGE_SYM_CLASS_پڇاڙي_جو_FUNCTION (BYTE)-1
#وصف_ڪريو IMAGE_SYM_CLASS_NULL 0x0000
#وصف_ڪريو IMAGE_SYM_CLASS_AUTOMATIC 0x0001
#وصف_ڪريو IMAGE_SYM_CLASS_EXTERNAL 0x0002
#وصف_ڪريو IMAGE_SYM_CLASS_STATIC 0x0003
#وصف_ڪريو IMAGE_SYM_CLASS_رجسٽر 0x0004
#وصف_ڪريو IMAGE_SYM_CLASS_EXTERNAL_DEF 0x0005
#وصف_ڪريو IMAGE_SYM_CLASS_LABEL 0x0006
#وصف_ڪريو IMAGE_SYM_CLASS_UNDEFINED_LABEL 0x0007
#وصف_ڪريو IMAGE_SYM_CLASS_MEMBER_جو_STRUCT 0x0008
#وصف_ڪريو IMAGE_SYM_CLASS_دليل 0x0009
#وصف_ڪريو IMAGE_SYM_CLASS_STRUCT_ٽيگ 0x000A
#وصف_ڪريو IMAGE_SYM_CLASS_MEMBER_جو_UNION 0x000B
#وصف_ڪريو IMAGE_SYM_CLASS_UNION_ٽيگ 0x000C
#وصف_ڪريو IMAGE_SYM_CLASS_TYPE_DEFINITION 0x000D
#وصف_ڪريو IMAGE_SYM_CLASS_UNDEFINED_STATIC 0x000E
#وصف_ڪريو IMAGE_SYM_CLASS_ENUM_ٽيگ 0x000F
#وصف_ڪريو IMAGE_SYM_CLASS_MEMBER_جو_ENUM 0x0010
#وصف_ڪريو IMAGE_SYM_CLASS_رجسٽر_PARAM 0x0011
#وصف_ڪريو IMAGE_SYM_CLASS_ٻٽو_انگ_ميدان 0x0012
#وصف_ڪريو IMAGE_SYM_CLASS_FAR_EXTERNAL 0x0044
#وصف_ڪريو IMAGE_SYM_CLASS_بلاڪ 0x0064
#وصف_ڪريو IMAGE_SYM_CLASS_FUNCTION 0x0065
#وصف_ڪريو IMAGE_SYM_CLASS_پڇاڙي_جو_STRUCT 0x0066
#وصف_ڪريو IMAGE_SYM_CLASS_FILE 0x0067
#وصف_ڪريو IMAGE_SYM_CLASS_SECTION 0x0068
#وصف_ڪريو IMAGE_SYM_CLASS_WEAK_EXTERNAL 0x0069
#وصف_ڪريو IMAGE_SYM_CLASS_CLR_TOKEN 0x006B

#وصف_ڪريو N_BTMASK 0x000F
#وصف_ڪريو N_TMASK 0x0030
#وصف_ڪريو N_TMASK1 0x00C0
#وصف_ڪريو N_TMASK2 0x00F0
#وصف_ڪريو N_BTSHFT 4
#وصف_ڪريو N_TSHIFT 2

#وصف_ڪريو BTYPE(x) ((x) & N_BTMASK)

#جيڪڏهن_وصف_نه_ٿيل ISPTR
#وصف_ڪريو ISPTR(x) (((x) & N_TMASK)==(IMAGE_SYM_DTYPE_اشارو << N_BTSHFT))
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل ISFCN
#وصف_ڪريو ISFCN(x) (((x) & N_TMASK)==(IMAGE_SYM_DTYPE_FUNCTION << N_BTSHFT))
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل ISARY
#وصف_ڪريو ISARY(x) (((x) & N_TMASK)==(IMAGE_SYM_DTYPE_ARRAY << N_BTSHFT))
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل ISTAG
#وصف_ڪريو ISTAG(x) ((x)==IMAGE_SYM_CLASS_STRUCT_ٽيگ || (x)==IMAGE_SYM_CLASS_UNION_ٽيگ || (x)==IMAGE_SYM_CLASS_ENUM_ٽيگ)
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل INCREF
#وصف_ڪريو INCREF(x) ((((x)&~N_BTMASK)<<N_TSHIFT)|(IMAGE_SYM_DTYPE_اشارو<<N_BTSHFT)|((x)&N_BTMASK))
#جيڪڏهن_پورو
#جيڪڏهن_وصف_نه_ٿيل DECREF
#وصف_ڪريو DECREF(x) ((((x)>>N_TSHIFT)&~N_BTMASK)|((x)&N_BTMASK))
#جيڪڏهن_پورو

    تعريفنوع اتحاد IMAGE_AUX_نشان {
      بنية {
	DWORD ٽيگ_اشاريو;
	اتحاد {
	  بنية {
	    لفظ_3 Linenumber;
	    لفظ_3 سائيز_3;
	  } LnSz;
	  DWORD ڪل_سائيز;
	} Misc;
	اتحاد {
	  بنية {
	    DWORD اشارو_منزل_Linenumber;
	    DWORD اشارو_منزل_ايندڙ_Function;
	  } Function;
	  بنية {
	    لفظ_3 Dimension[4];
	  } Array;
	} FcnAry;
	لفظ_3 Tv_اشاريو;
      } Sym;
      بنية {
	BYTE Name[IMAGE_SIZEOF_نشان];
      } File;
      بنية {
	DWORD ڊيگهائي_2;
	لفظ_3 عدد_جو_Relocations;
	لفظ_3 عدد_جو_Linenumbers;
	DWORD Check_جوڙ;
	SHORT عدد_2;
	BYTE Selection;
      } Section;
    } IMAGE_AUX_نشان_2;
    تعريفنوع IMAGE_AUX_نشان_2 UNALIGNED *PIMAGE_AUX_نشان;

#وصف_ڪريو IMAGE_SIZEOF_AUX_نشان 18

    تعريفنوع تعداد IMAGE_AUX_نشان_TYPE {
      IMAGE_AUX_نشان_TYPE_TOKEN_DEF = 1
    } IMAGE_AUX_نشان_TYPE;

#ضمن <pshpack2.h>

    تعريفنوع بنية IMAGE_AUX_نشان_TOKEN_DEF {
      BYTE bAuxType;
      BYTE bReserved;
      DWORD نشان_جدول_اشاريو;
      BYTE rgbReserved[12];
    } IMAGE_AUX_نشان_TOKEN_DEF;

    تعريفنوع IMAGE_AUX_نشان_TOKEN_DEF UNALIGNED *PIMAGE_AUX_نشان_TOKEN_DEF;

#ضمن <poppack.h>

#وصف_ڪريو IMAGE_COMDAT_SELECT_NODUPLICATES 1
#وصف_ڪريو IMAGE_COMDAT_SELECT_ANY 2
#وصف_ڪريو IMAGE_COMDAT_SELECT_SAME_سائيز 3
#وصف_ڪريو IMAGE_COMDAT_SELECT_EXACT_ميلاپ 4
#وصف_ڪريو IMAGE_COMDAT_SELECT_ASSOCIATIVE 5
#وصف_ڪريو IMAGE_COMDAT_SELECT_سڀ_کان_وڏو 6
#وصف_ڪريو IMAGE_COMDAT_SELECT_NEWEST 7

#وصف_ڪريو IMAGE_WEAK_EXTERN_ڳولا_NOLIBRARY 1
#وصف_ڪريو IMAGE_WEAK_EXTERN_ڳولا_LIBRARY 2
#وصف_ڪريو IMAGE_WEAK_EXTERN_ڳولا_ALIAS 3

    تعريفنوع بنية _IMAGE_RELOCATION {
      اتحاد {
	DWORD Virtual_پتو;
	DWORD Reloc_ڳڻپ;
      };
      DWORD نشان_جدول_اشاريو;
      لفظ_3 Type;
    } IMAGE_RELOCATION;
    تعريفنوع IMAGE_RELOCATION UNALIGNED *PIMAGE_RELOCATION;

#وصف_ڪريو IMAGE_SIZEOF_RELOCATION 10

#وصف_ڪريو IMAGE_REL_I386_ABSOLUTE 0x0000
#وصف_ڪريو IMAGE_REL_I386_DIR16 0x0001
#وصف_ڪريو IMAGE_REL_I386_REL16 0x0002
#وصف_ڪريو IMAGE_REL_I386_DIR32 0x0006
#وصف_ڪريو IMAGE_REL_I386_DIR32NB 0x0007
#وصف_ڪريو IMAGE_REL_I386_SEG12 0x0009
#وصف_ڪريو IMAGE_REL_I386_SECTION 0x000A
#وصف_ڪريو IMAGE_REL_I386_SECREL 0x000B
#وصف_ڪريو IMAGE_REL_I386_TOKEN 0x000C
#وصف_ڪريو IMAGE_REL_I386_SECREL7 0x000D
#وصف_ڪريو IMAGE_REL_I386_REL32 0x0014

#وصف_ڪريو IMAGE_REL_MIPS_ABSOLUTE 0x0000
#وصف_ڪريو IMAGE_REL_MIPS_REFHALF 0x0001
#وصف_ڪريو IMAGE_REL_MIPS_REFWORD 0x0002
#وصف_ڪريو IMAGE_REL_MIPS_JMPADDR 0x0003
#وصف_ڪريو IMAGE_REL_MIPS_REFHI 0x0004
#وصف_ڪريو IMAGE_REL_MIPS_REFLO 0x0005
#وصف_ڪريو IMAGE_REL_MIPS_GPREL 0x0006
#وصف_ڪريو IMAGE_REL_MIPS_LITERAL 0x0007
#وصف_ڪريو IMAGE_REL_MIPS_SECTION 0x000A
#وصف_ڪريو IMAGE_REL_MIPS_SECREL 0x000B
#وصف_ڪريو IMAGE_REL_MIPS_SECRELLO 0x000C
#وصف_ڪريو IMAGE_REL_MIPS_SECRELHI 0x000D
#وصف_ڪريو IMAGE_REL_MIPS_TOKEN 0x000E
#وصف_ڪريو IMAGE_REL_MIPS_JMPADDR16 0x0010
#وصف_ڪريو IMAGE_REL_MIPS_REFWORDNB 0x0022
#وصف_ڪريو IMAGE_REL_MIPS_PAIR 0x0025

#وصف_ڪريو IMAGE_REL_ALPHA_ABSOLUTE 0x0000
#وصف_ڪريو IMAGE_REL_ALPHA_REFLONG 0x0001
#وصف_ڪريو IMAGE_REL_ALPHA_REFQUAD 0x0002
#وصف_ڪريو IMAGE_REL_ALPHA_GPREL32 0x0003
#وصف_ڪريو IMAGE_REL_ALPHA_LITERAL 0x0004
#وصف_ڪريو IMAGE_REL_ALPHA_LITUSE 0x0005
#وصف_ڪريو IMAGE_REL_ALPHA_GPDISP 0x0006
#وصف_ڪريو IMAGE_REL_ALPHA_BRADDR 0x0007
#وصف_ڪريو IMAGE_REL_ALPHA_HINT 0x0008
#وصف_ڪريو IMAGE_REL_ALPHA_INLINE_REFLONG 0x0009
#وصف_ڪريو IMAGE_REL_ALPHA_REFHI 0x000A
#وصف_ڪريو IMAGE_REL_ALPHA_REFLO 0x000B
#وصف_ڪريو IMAGE_REL_ALPHA_PAIR 0x000C
#وصف_ڪريو IMAGE_REL_ALPHA_ميلاپ 0x000D
#وصف_ڪريو IMAGE_REL_ALPHA_SECTION 0x000E
#وصف_ڪريو IMAGE_REL_ALPHA_SECREL 0x000F
#وصف_ڪريو IMAGE_REL_ALPHA_REFLONGNB 0x0010
#وصف_ڪريو IMAGE_REL_ALPHA_SECRELLO 0x0011
#وصف_ڪريو IMAGE_REL_ALPHA_SECRELHI 0x0012
#وصف_ڪريو IMAGE_REL_ALPHA_REFQ3 0x0013
#وصف_ڪريو IMAGE_REL_ALPHA_REFQ2 0x0014
#وصف_ڪريو IMAGE_REL_ALPHA_REFQ1 0x0015
#وصف_ڪريو IMAGE_REL_ALPHA_GPRELLO 0x0016
#وصف_ڪريو IMAGE_REL_ALPHA_GPRELHI 0x0017

#وصف_ڪريو IMAGE_REL_PPC_ABSOLUTE 0x0000
#وصف_ڪريو IMAGE_REL_PPC_ADDR64 0x0001
#وصف_ڪريو IMAGE_REL_PPC_ADDR32 0x0002
#وصف_ڪريو IMAGE_REL_PPC_ADDR24 0x0003
#وصف_ڪريو IMAGE_REL_PPC_ADDR16 0x0004
#وصف_ڪريو IMAGE_REL_PPC_ADDR14 0x0005
#وصف_ڪريو IMAGE_REL_PPC_REL24 0x0006
#وصف_ڪريو IMAGE_REL_PPC_REL14 0x0007
#وصف_ڪريو IMAGE_REL_PPC_TOCREL16 0x0008
#وصف_ڪريو IMAGE_REL_PPC_TOCREL14 0x0009
#وصف_ڪريو IMAGE_REL_PPC_ADDR32NB 0x000A
#وصف_ڪريو IMAGE_REL_PPC_SECREL 0x000B
#وصف_ڪريو IMAGE_REL_PPC_SECTION 0x000C
#وصف_ڪريو IMAGE_REL_PPC_IFGLUE 0x000D
#وصف_ڪريو IMAGE_REL_PPC_IMGLUE 0x000E
#وصف_ڪريو IMAGE_REL_PPC_SECREL16 0x000F
#وصف_ڪريو IMAGE_REL_PPC_REFHI 0x0010
#وصف_ڪريو IMAGE_REL_PPC_REFLO 0x0011
#وصف_ڪريو IMAGE_REL_PPC_PAIR 0x0012
#وصف_ڪريو IMAGE_REL_PPC_SECRELLO 0x0013
#وصف_ڪريو IMAGE_REL_PPC_SECRELHI 0x0014
#وصف_ڪريو IMAGE_REL_PPC_GPREL 0x0015
#وصف_ڪريو IMAGE_REL_PPC_TOKEN 0x0016
#وصف_ڪريو IMAGE_REL_PPC_TYPEMASK 0x00FF
#وصف_ڪريو IMAGE_REL_PPC_NEG 0x0100
#وصف_ڪريو IMAGE_REL_PPC_BRTAKEN 0x0200
#وصف_ڪريو IMAGE_REL_PPC_BRNTAKEN 0x0400
#وصف_ڪريو IMAGE_REL_PPC_TOCDEFN 0x0800

#وصف_ڪريو IMAGE_REL_SH3_ABSOLUTE 0x0000
#وصف_ڪريو IMAGE_REL_SH3_DIRECT16 0x0001
#وصف_ڪريو IMAGE_REL_SH3_DIRECT32 0x0002
#وصف_ڪريو IMAGE_REL_SH3_DIRECT8 0x0003
#وصف_ڪريو IMAGE_REL_SH3_DIRECT8_لفظ 0x0004
#وصف_ڪريو IMAGE_REL_SH3_DIRECT8_LONG 0x0005
#وصف_ڪريو IMAGE_REL_SH3_DIRECT4 0x0006
#وصف_ڪريو IMAGE_REL_SH3_DIRECT4_لفظ 0x0007
#وصف_ڪريو IMAGE_REL_SH3_DIRECT4_LONG 0x0008
#وصف_ڪريو IMAGE_REL_SH3_PCREL8_لفظ 0x0009
#وصف_ڪريو IMAGE_REL_SH3_PCREL8_LONG 0x000A
#وصف_ڪريو IMAGE_REL_SH3_PCREL12_لفظ 0x000B
#وصف_ڪريو IMAGE_REL_SH3_STARTOF_SECTION 0x000C
#وصف_ڪريو IMAGE_REL_SH3_SIZEOF_SECTION 0x000D
#وصف_ڪريو IMAGE_REL_SH3_SECTION 0x000E
#وصف_ڪريو IMAGE_REL_SH3_SECREL 0x000F
#وصف_ڪريو IMAGE_REL_SH3_DIRECT32_NB 0x0010
#وصف_ڪريو IMAGE_REL_SH3_GPREL4_LONG 0x0011
#وصف_ڪريو IMAGE_REL_SH3_TOKEN 0x0012

#وصف_ڪريو IMAGE_REL_SHM_PCRELPT 0x0013
#وصف_ڪريو IMAGE_REL_SHM_REFLO 0x0014
#وصف_ڪريو IMAGE_REL_SHM_REFHALF 0x0015
#وصف_ڪريو IMAGE_REL_SHM_RELLO 0x0016
#وصف_ڪريو IMAGE_REL_SHM_RELHALF 0x0017
#وصف_ڪريو IMAGE_REL_SHM_PAIR 0x0018

#وصف_ڪريو IMAGE_REL_SH_NOMODE 0x8000

#وصف_ڪريو IMAGE_REL_ARM_ABSOLUTE 0x0000
#وصف_ڪريو IMAGE_REL_ARM_ADDR32 0x0001
#وصف_ڪريو IMAGE_REL_ARM_ADDR32NB 0x0002
#وصف_ڪريو IMAGE_REL_ARM_BRANCH24 0x0003
#وصف_ڪريو IMAGE_REL_ARM_BRANCH11 0x0004
#وصف_ڪريو IMAGE_REL_ARM_TOKEN 0x0005
#وصف_ڪريو IMAGE_REL_ARM_GPREL12 0x0006
#وصف_ڪريو IMAGE_REL_ARM_GPREL7 0x0007
#وصف_ڪريو IMAGE_REL_ARM_BLX24 0x0008
#وصف_ڪريو IMAGE_REL_ARM_BLX11 0x0009
#وصف_ڪريو IMAGE_REL_ARM_SECTION 0x000E
#وصف_ڪريو IMAGE_REL_ARM_SECREL 0x000F

#وصف_ڪريو IMAGE_REL_AM_ABSOLUTE 0x0000
#وصف_ڪريو IMAGE_REL_AM_ADDR32 0x0001
#وصف_ڪريو IMAGE_REL_AM_ADDR32NB 0x0002
#وصف_ڪريو IMAGE_REL_AM_CALL32 0x0003
#وصف_ڪريو IMAGE_REL_AM_FUNCINFO 0x0004
#وصف_ڪريو IMAGE_REL_AM_REL32_1 0x0005
#وصف_ڪريو IMAGE_REL_AM_REL32_2 0x0006
#وصف_ڪريو IMAGE_REL_AM_SECREL 0x0007
#وصف_ڪريو IMAGE_REL_AM_SECTION 0x0008
#وصف_ڪريو IMAGE_REL_AM_TOKEN 0x0009

#وصف_ڪريو IMAGE_REL_AMD64_ABSOLUTE 0x0000
#وصف_ڪريو IMAGE_REL_AMD64_ADDR64 0x0001
#وصف_ڪريو IMAGE_REL_AMD64_ADDR32 0x0002
#وصف_ڪريو IMAGE_REL_AMD64_ADDR32NB 0x0003
#وصف_ڪريو IMAGE_REL_AMD64_REL32 0x0004
#وصف_ڪريو IMAGE_REL_AMD64_REL32_1 0x0005
#وصف_ڪريو IMAGE_REL_AMD64_REL32_2 0x0006
#وصف_ڪريو IMAGE_REL_AMD64_REL32_3 0x0007
#وصف_ڪريو IMAGE_REL_AMD64_REL32_4 0x0008
#وصف_ڪريو IMAGE_REL_AMD64_REL32_5 0x0009
#وصف_ڪريو IMAGE_REL_AMD64_SECTION 0x000A
#وصف_ڪريو IMAGE_REL_AMD64_SECREL 0x000B
#وصف_ڪريو IMAGE_REL_AMD64_SECREL7 0x000C
#وصف_ڪريو IMAGE_REL_AMD64_TOKEN 0x000D
#وصف_ڪريو IMAGE_REL_AMD64_SREL32 0x000E
#وصف_ڪريو IMAGE_REL_AMD64_PAIR 0x000F
#وصف_ڪريو IMAGE_REL_AMD64_SSPAN32 0x0010

#وصف_ڪريو IMAGE_REL_IA64_ABSOLUTE 0x0000
#وصف_ڪريو IMAGE_REL_IA64_IMM14 0x0001
#وصف_ڪريو IMAGE_REL_IA64_IMM22 0x0002
#وصف_ڪريو IMAGE_REL_IA64_IMM64 0x0003
#وصف_ڪريو IMAGE_REL_IA64_DIR32 0x0004
#وصف_ڪريو IMAGE_REL_IA64_DIR64 0x0005
#وصف_ڪريو IMAGE_REL_IA64_PCREL21B 0x0006
#وصف_ڪريو IMAGE_REL_IA64_PCREL21M 0x0007
#وصف_ڪريو IMAGE_REL_IA64_PCREL21F 0x0008
#وصف_ڪريو IMAGE_REL_IA64_GPREL22 0x0009
#وصف_ڪريو IMAGE_REL_IA64_LTOFF22 0x000A
#وصف_ڪريو IMAGE_REL_IA64_SECTION 0x000B
#وصف_ڪريو IMAGE_REL_IA64_SECREL22 0x000C
#وصف_ڪريو IMAGE_REL_IA64_SECREL64I 0x000D
#وصف_ڪريو IMAGE_REL_IA64_SECREL32 0x000E

#وصف_ڪريو IMAGE_REL_IA64_DIR32NB 0x0010
#وصف_ڪريو IMAGE_REL_IA64_SREL14 0x0011
#وصف_ڪريو IMAGE_REL_IA64_SREL22 0x0012
#وصف_ڪريو IMAGE_REL_IA64_SREL32 0x0013
#وصف_ڪريو IMAGE_REL_IA64_UREL32 0x0014
#وصف_ڪريو IMAGE_REL_IA64_PCREL60X 0x0015
#وصف_ڪريو IMAGE_REL_IA64_PCREL60B 0x0016
#وصف_ڪريو IMAGE_REL_IA64_PCREL60F 0x0017
#وصف_ڪريو IMAGE_REL_IA64_PCREL60I 0x0018
#وصف_ڪريو IMAGE_REL_IA64_PCREL60M 0x0019
#وصف_ڪريو IMAGE_REL_IA64_IMMGPREL64 0x001A
#وصف_ڪريو IMAGE_REL_IA64_TOKEN 0x001B
#وصف_ڪريو IMAGE_REL_IA64_GPREL32 0x001C
#وصف_ڪريو IMAGE_REL_IA64_ADDEND 0x001F

#وصف_ڪريو IMAGE_REL_CEF_ABSOLUTE 0x0000
#وصف_ڪريو IMAGE_REL_CEF_ADDR32 0x0001
#وصف_ڪريو IMAGE_REL_CEF_ADDR64 0x0002
#وصف_ڪريو IMAGE_REL_CEF_ADDR32NB 0x0003
#وصف_ڪريو IMAGE_REL_CEF_SECTION 0x0004
#وصف_ڪريو IMAGE_REL_CEF_SECREL 0x0005
#وصف_ڪريو IMAGE_REL_CEF_TOKEN 0x0006

#وصف_ڪريو IMAGE_REL_CEE_ABSOLUTE 0x0000
#وصف_ڪريو IMAGE_REL_CEE_ADDR32 0x0001
#وصف_ڪريو IMAGE_REL_CEE_ADDR64 0x0002
#وصف_ڪريو IMAGE_REL_CEE_ADDR32NB 0x0003
#وصف_ڪريو IMAGE_REL_CEE_SECTION 0x0004
#وصف_ڪريو IMAGE_REL_CEE_SECREL 0x0005
#وصف_ڪريو IMAGE_REL_CEE_TOKEN 0x0006

#وصف_ڪريو IMAGE_REL_M32R_ABSOLUTE 0x0000
#وصف_ڪريو IMAGE_REL_M32R_ADDR32 0x0001
#وصف_ڪريو IMAGE_REL_M32R_ADDR32NB 0x0002
#وصف_ڪريو IMAGE_REL_M32R_ADDR24 0x0003
#وصف_ڪريو IMAGE_REL_M32R_GPREL16 0x0004
#وصف_ڪريو IMAGE_REL_M32R_PCREL24 0x0005
#وصف_ڪريو IMAGE_REL_M32R_PCREL16 0x0006
#وصف_ڪريو IMAGE_REL_M32R_PCREL8 0x0007
#وصف_ڪريو IMAGE_REL_M32R_REFHALF 0x0008
#وصف_ڪريو IMAGE_REL_M32R_REFHI 0x0009
#وصف_ڪريو IMAGE_REL_M32R_REFLO 0x000A
#وصف_ڪريو IMAGE_REL_M32R_PAIR 0x000B
#وصف_ڪريو IMAGE_REL_M32R_SECTION 0x000C
#وصف_ڪريو IMAGE_REL_M32R_SECREL32 0x000D
#وصف_ڪريو IMAGE_REL_M32R_TOKEN 0x000E

#وصف_ڪريو EXT_IMM64(قدر_3,پتو_2,سائيز_3,InstPos,ValPos) قدر_3 |= (((ULONGLONG)((*(پتو_2) >> InstPos) & (((ULONGLONG)1 << سائيز_3) - 1))) << ValPos)
#وصف_ڪريو INS_IMM64(قدر_3,پتو_2,سائيز_3,InstPos,ValPos) *(PDWORD)پتو_2 = (*(PDWORD)پتو_2 & ~(((1 << سائيز_3) - 1) << InstPos)) | ((DWORD)((((ULONGLONG)قدر_3 >> ValPos) & (((ULONGLONG)1 << سائيز_3) - 1))) << InstPos)

#وصف_ڪريو EMARCH_ENC_I17_IMM7_B_INST_لفظ_X 3
#وصف_ڪريو EMARCH_ENC_I17_IMM7_B_سائيز_X 7
#وصف_ڪريو EMARCH_ENC_I17_IMM7_B_INST_لفظ_POS_X 4
#وصف_ڪريو EMARCH_ENC_I17_IMM7B_VAL_POS_X 0

#وصف_ڪريو EMARCH_ENC_I17_IMM9_D_INST_لفظ_X 3
#وصف_ڪريو EMARCH_ENC_I17_IMM9_D_سائيز_X 9
#وصف_ڪريو EMARCH_ENC_I17_IMM9_D_INST_لفظ_POS_X 18
#وصف_ڪريو EMARCH_ENC_I17_IMM9D_VAL_POS_X 7

#وصف_ڪريو EMARCH_ENC_I17_IMM5_C_INST_لفظ_X 3
#وصف_ڪريو EMARCH_ENC_I17_IMM5_C_سائيز_X 5
#وصف_ڪريو EMARCH_ENC_I17_IMM5_C_INST_لفظ_POS_X 13
#وصف_ڪريو EMARCH_ENC_I17_IMM5C_VAL_POS_X 16

#وصف_ڪريو EMARCH_ENC_I17_IC_INST_لفظ_X 3
#وصف_ڪريو EMARCH_ENC_I17_IC_سائيز_X 1
#وصف_ڪريو EMARCH_ENC_I17_IC_INST_لفظ_POS_X 12
#وصف_ڪريو EMARCH_ENC_I17_IC_VAL_POS_X 21

#وصف_ڪريو EMARCH_ENC_I17_IMM41a_INST_لفظ_X 1
#وصف_ڪريو EMARCH_ENC_I17_IMM41a_سائيز_X 10
#وصف_ڪريو EMARCH_ENC_I17_IMM41a_INST_لفظ_POS_X 14
#وصف_ڪريو EMARCH_ENC_I17_IMM41a_VAL_POS_X 22

#وصف_ڪريو EMARCH_ENC_I17_IMM41b_INST_لفظ_X 1
#وصف_ڪريو EMARCH_ENC_I17_IMM41b_سائيز_X 8
#وصف_ڪريو EMARCH_ENC_I17_IMM41b_INST_لفظ_POS_X 24
#وصف_ڪريو EMARCH_ENC_I17_IMM41b_VAL_POS_X 32

#وصف_ڪريو EMARCH_ENC_I17_IMM41c_INST_لفظ_X 2
#وصف_ڪريو EMARCH_ENC_I17_IMM41c_سائيز_X 23
#وصف_ڪريو EMARCH_ENC_I17_IMM41c_INST_لفظ_POS_X 0
#وصف_ڪريو EMARCH_ENC_I17_IMM41c_VAL_POS_X 40

#وصف_ڪريو EMARCH_ENC_I17_SIGN_INST_لفظ_X 3
#وصف_ڪريو EMARCH_ENC_I17_SIGN_سائيز_X 1
#وصف_ڪريو EMARCH_ENC_I17_SIGN_INST_لفظ_POS_X 27
#وصف_ڪريو EMARCH_ENC_I17_SIGN_VAL_POS_X 63

#وصف_ڪريو X3_OPCODE_INST_لفظ_X 3
#وصف_ڪريو X3_OPCODE_سائيز_X 4
#وصف_ڪريو X3_OPCODE_INST_لفظ_POS_X 28
#وصف_ڪريو X3_OPCODE_SIGN_VAL_POS_X 0

#وصف_ڪريو X3_I_INST_لفظ_X 3
#وصف_ڪريو X3_I_سائيز_X 1
#وصف_ڪريو X3_I_INST_لفظ_POS_X 27
#وصف_ڪريو X3_I_SIGN_VAL_POS_X 59

#وصف_ڪريو X3_D_WH_INST_لفظ_X 3
#وصف_ڪريو X3_D_WH_سائيز_X 3
#وصف_ڪريو X3_D_WH_INST_لفظ_POS_X 24
#وصف_ڪريو X3_D_WH_SIGN_VAL_POS_X 0

#وصف_ڪريو X3_IMM20_INST_لفظ_X 3
#وصف_ڪريو X3_IMM20_سائيز_X 20
#وصف_ڪريو X3_IMM20_INST_لفظ_POS_X 4
#وصف_ڪريو X3_IMM20_SIGN_VAL_POS_X 0

#وصف_ڪريو X3_IMM39_1_INST_لفظ_X 2
#وصف_ڪريو X3_IMM39_1_سائيز_X 23
#وصف_ڪريو X3_IMM39_1_INST_لفظ_POS_X 0
#وصف_ڪريو X3_IMM39_1_SIGN_VAL_POS_X 36

#وصف_ڪريو X3_IMM39_2_INST_لفظ_X 1
#وصف_ڪريو X3_IMM39_2_سائيز_X 16
#وصف_ڪريو X3_IMM39_2_INST_لفظ_POS_X 16
#وصف_ڪريو X3_IMM39_2_SIGN_VAL_POS_X 20

#وصف_ڪريو X3_P_INST_لفظ_X 3
#وصف_ڪريو X3_P_سائيز_X 4
#وصف_ڪريو X3_P_INST_لفظ_POS_X 0
#وصف_ڪريو X3_P_SIGN_VAL_POS_X 0

#وصف_ڪريو X3_TMPLT_INST_لفظ_X 0
#وصف_ڪريو X3_TMPLT_سائيز_X 4
#وصف_ڪريو X3_TMPLT_INST_لفظ_POS_X 0
#وصف_ڪريو X3_TMPLT_SIGN_VAL_POS_X 0

#وصف_ڪريو X3_BTYPE_QP_INST_لفظ_X 2
#وصف_ڪريو X3_BTYPE_QP_سائيز_X 9
#وصف_ڪريو X3_BTYPE_QP_INST_لفظ_POS_X 23
#وصف_ڪريو X3_BTYPE_QP_INST_VAL_POS_X 0

#وصف_ڪريو X3_خالي_جايون_INST_لفظ_X 1
#وصف_ڪريو X3_خالي_جايون_سائيز_X 2
#وصف_ڪريو X3_خالي_جايون_INST_لفظ_POS_X 14
#وصف_ڪريو X3_خالي_جايون_INST_VAL_POS_X 0

    تعريفنوع بنية _IMAGE_LINENUMBER {
      اتحاد {
	DWORD نشان_جدول_اشاريو;
	DWORD Virtual_پتو;
      } Type;
      لفظ_3 Linenumber;
    } IMAGE_LINENUMBER;
    تعريفنوع IMAGE_LINENUMBER UNALIGNED *PIMAGE_LINENUMBER;

#وصف_ڪريو IMAGE_SIZEOF_LINENUMBER 6

#ضمن "poppack.h"

    تعريفنوع بنية IMAGE_بنياد_RELOCATION {
      DWORD Virtual_پتو;
      DWORD سائيز_جو_بلاڪ;

    } IMAGE_بنياد_RELOCATION_2;
    تعريفنوع IMAGE_بنياد_RELOCATION_2 UNALIGNED *PIMAGE_بنياد_RELOCATION;

#وصف_ڪريو IMAGE_SIZEOF_بنياد_RELOCATION 8

#وصف_ڪريو IMAGE_REL_BASED_ABSOLUTE 0
#وصف_ڪريو IMAGE_REL_BASED_مٿاهون 1
#وصف_ڪريو IMAGE_REL_BASED_هيٺيون 2
#وصف_ڪريو IMAGE_REL_BASED_HIGHLOW 3
#وصف_ڪريو IMAGE_REL_BASED_HIGHADJ 4
#وصف_ڪريو IMAGE_REL_BASED_MIPS_JMPADDR 5
#وصف_ڪريو IMAGE_REL_BASED_MIPS_JMPADDR16 9
#وصف_ڪريو IMAGE_REL_BASED_IA64_IMM64 9
#وصف_ڪريو IMAGE_REL_BASED_DIR64 10

#وصف_ڪريو IMAGE_ARCHIVE_شروعات_سائيز 8
#وصف_ڪريو IMAGE_ARCHIVE_شروعات "!<arch>\n"
#وصف_ڪريو IMAGE_ARCHIVE_پڇاڙي "`\n"
#وصف_ڪريو IMAGE_ARCHIVE_PAD "\n"
#وصف_ڪريو IMAGE_ARCHIVE_LINKER_MEMBER "/               "
#وصف_ڪريو IMAGE_ARCHIVE_LONGNAMES_MEMBER "//              "

    تعريفنوع بنية IMAGE_ARCHIVE_MEMBER_سرو {
      BYTE Name[16];
      BYTE Date[12];
      BYTE UserID[6];
      BYTE گروهه_ID[6];
      BYTE گهڻائي_4[8];
      BYTE سائيز_3[10];
      BYTE پڇاڙي_سرو[2];
    } IMAGE_ARCHIVE_MEMBER_سرو_2,*PIMAGE_ARCHIVE_MEMBER_سرو;

#وصف_ڪريو IMAGE_SIZEOF_ARCHIVE_MEMBER_HDR 60

    تعريفنوع بنية _IMAGE_EXPORT_DIRECTORY {
      DWORD Characteristics;
      DWORD وقت_Date_Stamp;
      لفظ_3 Major_نسخو;
      لفظ_3 Minor_نسخو;
      DWORD Name;
      DWORD بنياد_2;
      DWORD عدد_جو_Functions;
      DWORD عدد_جو_نالا;
      DWORD پتو_جو_Functions;
      DWORD پتو_جو_نالا;
      DWORD پتو_جو_Name_Ordinals;
    } IMAGE_EXPORT_DIRECTORY,*PIMAGE_EXPORT_DIRECTORY;

    تعريفنوع بنية _IMAGE_IMPORT_BY_NAME {
      لفظ_3 Hint;
      BYTE Name[1];
    } IMAGE_IMPORT_BY_NAME,*PIMAGE_IMPORT_BY_NAME;

#ضمن "pshpack8.h"

    تعريفنوع بنية _IMAGE_THUNK_DATA64 {
      اتحاد {
	ULONGLONG ForwarderString;
	ULONGLONG Function;
	ULONGLONG Ordinal;
	ULONGLONG پتو_جو_معلومات;
      } u1;
    } IMAGE_THUNK_DATA64;
    تعريفنوع IMAGE_THUNK_DATA64 *PIMAGE_THUNK_DATA64;

#ضمن "poppack.h"

    تعريفنوع بنية _IMAGE_THUNK_DATA32 {
      اتحاد {
	DWORD ForwarderString;
	DWORD Function;
	DWORD Ordinal;
	DWORD پتو_جو_معلومات;
      } u1;
    } IMAGE_THUNK_DATA32;
    تعريفنوع IMAGE_THUNK_DATA32 *PIMAGE_THUNK_DATA32;

#وصف_ڪريو IMAGE_ORDINAL_FLAG64 0x8000000000000000ull
#وصف_ڪريو IMAGE_ORDINAL_FLAG32 0x80000000
#وصف_ڪريو IMAGE_ORDINAL64(Ordinal) (Ordinal & 0xffffull)
#وصف_ڪريو IMAGE_ORDINAL32(Ordinal) (Ordinal & 0xffff)
#وصف_ڪريو IMAGE_SNAP_BY_ORDINAL64(Ordinal) ((Ordinal & IMAGE_ORDINAL_FLAG64)!=0)
#وصف_ڪريو IMAGE_SNAP_BY_ORDINAL32(Ordinal) ((Ordinal & IMAGE_ORDINAL_FLAG32)!=0)

    تعريفنوع VOID
      (NTAPI *PIMAGE_TLS_CALLBACK)(PVOID DllHandle,DWORD Reason,PVOID Reserved);

    تعريفنوع بنية _IMAGE_TLS_DIRECTORY64 {
      ULONGLONG شروعات_پتو_جو_Raw_معلومات;
      ULONGLONG پڇاڙي_پتو_جو_Raw_معلومات;
      ULONGLONG پتو_جو_اشاريو;
      ULONGLONG پتو_جو_Call_Backs;
      DWORD سائيز_جو_Zero_Fill;
      DWORD Characteristics;
    } IMAGE_TLS_DIRECTORY64;
    تعريفنوع IMAGE_TLS_DIRECTORY64 *PIMAGE_TLS_DIRECTORY64;

    تعريفنوع بنية _IMAGE_TLS_DIRECTORY32 {
      DWORD شروعات_پتو_جو_Raw_معلومات;
      DWORD پڇاڙي_پتو_جو_Raw_معلومات;
      DWORD پتو_جو_اشاريو;
      DWORD پتو_جو_Call_Backs;
      DWORD سائيز_جو_Zero_Fill;
      DWORD Characteristics;
    } IMAGE_TLS_DIRECTORY32;
    تعريفنوع IMAGE_TLS_DIRECTORY32 *PIMAGE_TLS_DIRECTORY32;

#جيڪڏهن_وصف_ٿيل _WIN64
#وصف_ڪريو IMAGE_ORDINAL_FLAG IMAGE_ORDINAL_FLAG64
#وصف_ڪريو IMAGE_ORDINAL(Ordinal) IMAGE_ORDINAL64(Ordinal)
    تعريفنوع IMAGE_THUNK_DATA64 IMAGE_THUNK_معلومات;
    تعريفنوع PIMAGE_THUNK_DATA64 PIMAGE_THUNK_معلومات;
#وصف_ڪريو IMAGE_SNAP_BY_ORDINAL(Ordinal) IMAGE_SNAP_BY_ORDINAL64(Ordinal)
    تعريفنوع IMAGE_TLS_DIRECTORY64 IMAGE_TLS_DIRECTORY;
    تعريفنوع PIMAGE_TLS_DIRECTORY64 PIMAGE_TLS_DIRECTORY;
#وإلا
#وصف_ڪريو IMAGE_ORDINAL_FLAG IMAGE_ORDINAL_FLAG32
#وصف_ڪريو IMAGE_ORDINAL(Ordinal) IMAGE_ORDINAL32(Ordinal)
    تعريفنوع IMAGE_THUNK_DATA32 IMAGE_THUNK_معلومات;
    تعريفنوع PIMAGE_THUNK_DATA32 PIMAGE_THUNK_معلومات;
#وصف_ڪريو IMAGE_SNAP_BY_ORDINAL(Ordinal) IMAGE_SNAP_BY_ORDINAL32(Ordinal)
    تعريفنوع IMAGE_TLS_DIRECTORY32 IMAGE_TLS_DIRECTORY;
    تعريفنوع PIMAGE_TLS_DIRECTORY32 PIMAGE_TLS_DIRECTORY;
#جيڪڏهن_پورو

    تعريفنوع بنية _IMAGE_IMPORT_DESCRIPTOR {
      اتحاد {
	DWORD Characteristics;
	DWORD Original_پهريون_Thunk;
      };
      DWORD وقت_Date_Stamp;

      DWORD ForwarderChain;
      DWORD Name;
      DWORD پهريون_Thunk;
    } IMAGE_IMPORT_DESCRIPTOR;
    تعريفنوع IMAGE_IMPORT_DESCRIPTOR UNALIGNED *PIMAGE_IMPORT_DESCRIPTOR;

    تعريفنوع بنية _IMAGE_BOUND_IMPORT_DESCRIPTOR {
      DWORD وقت_Date_Stamp;
      لفظ_3 وٿي_Module_Name;
      لفظ_3 عدد_جو_Module_Forwarder_Refs;
    } IMAGE_BOUND_IMPORT_DESCRIPTOR,*PIMAGE_BOUND_IMPORT_DESCRIPTOR;

    تعريفنوع بنية _IMAGE_BOUND_FORWARDER_REF {
      DWORD وقت_Date_Stamp;
      لفظ_3 وٿي_Module_Name;
      لفظ_3 Reserved;
    } IMAGE_BOUND_FORWARDER_REF,*PIMAGE_BOUND_FORWARDER_REF;

    تعريفنوع بنية _IMAGE_RESOURCE_DIRECTORY {
      DWORD Characteristics;
      DWORD وقت_Date_Stamp;
      لفظ_3 Major_نسخو;
      لفظ_3 Minor_نسخو;
      لفظ_3 عدد_جو_Named_Entries;
      لفظ_3 عدد_جو_Id_Entries;
    } IMAGE_RESOURCE_DIRECTORY,*PIMAGE_RESOURCE_DIRECTORY;

#وصف_ڪريو IMAGE_RESOURCE_NAME_IS_STRING 0x80000000
#وصف_ڪريو IMAGE_RESOURCE_معلومات_IS_DIRECTORY 0x80000000

    تعريفنوع بنية IMAGE_RESOURCE_DIRECTORY_داخلا {
      اتحاد {
	بنية {
	  DWORD Name_وٿي:31;
	  DWORD NameIsString:1;
	};
	DWORD Name;
	لفظ_3 Id;
      };
      اتحاد {
	DWORD وٿي_منزل_معلومات;
	بنية {
	  DWORD وٿي_منزل_Directory:31;
	  DWORD معلومات_Is_Directory:1;
	};
      };
    } IMAGE_RESOURCE_DIRECTORY_داخلا_2,*PIMAGE_RESOURCE_DIRECTORY_داخلا;

    تعريفنوع بنية _IMAGE_RESOURCE_DIRECTORY_STRING {
      لفظ_3 ڊيگهائي_2;
      CHAR NameString[1];
    } IMAGE_RESOURCE_DIRECTORY_STRING,*PIMAGE_RESOURCE_DIRECTORY_STRING;

    تعريفنوع بنية _IMAGE_RESOURCE_DIR_STRING_U {
      لفظ_3 ڊيگهائي_2;
      WCHAR NameString[1];
    } IMAGE_RESOURCE_DIR_STRING_U,*PIMAGE_RESOURCE_DIR_STRING_U;

    تعريفنوع بنية IMAGE_RESOURCE_معلومات_داخلا {
      DWORD وٿي_منزل_معلومات;
      DWORD سائيز_3;
      DWORD ڪوڊ_صفحو;
      DWORD Reserved;
    } IMAGE_RESOURCE_معلومات_داخلا_2,*PIMAGE_RESOURCE_معلومات_داخلا;

    تعريفنوع بنية {
      DWORD سائيز_3;
      DWORD وقت_Date_Stamp;
      لفظ_3 Major_نسخو;
      لفظ_3 Minor_نسخو;
      DWORD GlobalFlagsClear;
      DWORD Global_Flags_سيٽ;
      DWORD CriticalSectionDefaultTimeout;
      DWORD De_Commit_Free_بلاڪ_حد;
      DWORD De_Commit_ڪل_Free_حد;
      DWORD تالو_اڳياڙي_جدول;
      DWORD وڌ_کان_وڌ_ورهاست_سائيز;
      DWORD Virtual_يادگيري_حد;
      DWORD Process_ڍير_Flags;
      DWORD Process_Affinity_نقاب;
      لفظ_3 CSDVersion;
      لفظ_3 Reserved1;
      DWORD EditList;
      DWORD SecurityCookie;
      DWORD SEHandler_جدول;
      DWORD SEHandler_ڳڻپ;
    } IMAGE_ڀريو_CONFIG_DIRECTORY32,*PIMAGE_ڀريو_CONFIG_DIRECTORY32;

    تعريفنوع بنية {
      DWORD سائيز_3;
      DWORD وقت_Date_Stamp;
      لفظ_3 Major_نسخو;
      لفظ_3 Minor_نسخو;
      DWORD GlobalFlagsClear;
      DWORD Global_Flags_سيٽ;
      DWORD CriticalSectionDefaultTimeout;
      ULONGLONG De_Commit_Free_بلاڪ_حد;
      ULONGLONG De_Commit_ڪل_Free_حد;
      ULONGLONG تالو_اڳياڙي_جدول;
      ULONGLONG وڌ_کان_وڌ_ورهاست_سائيز;
      ULONGLONG Virtual_يادگيري_حد;
      ULONGLONG Process_Affinity_نقاب;
      DWORD Process_ڍير_Flags;
      لفظ_3 CSDVersion;
      لفظ_3 Reserved1;
      ULONGLONG EditList;
      ULONGLONG SecurityCookie;
      ULONGLONG SEHandler_جدول;
      ULONGLONG SEHandler_ڳڻپ;
    } IMAGE_ڀريو_CONFIG_DIRECTORY64,*PIMAGE_ڀريو_CONFIG_DIRECTORY64;

#جيڪڏهن_وصف_ٿيل _WIN64
    تعريفنوع IMAGE_ڀريو_CONFIG_DIRECTORY64 IMAGE_ڀريو_CONFIG_DIRECTORY;
    تعريفنوع PIMAGE_ڀريو_CONFIG_DIRECTORY64 PIMAGE_ڀريو_CONFIG_DIRECTORY;
#وإلا
    تعريفنوع IMAGE_ڀريو_CONFIG_DIRECTORY32 IMAGE_ڀريو_CONFIG_DIRECTORY;
    تعريفنوع PIMAGE_ڀريو_CONFIG_DIRECTORY32 PIMAGE_ڀريو_CONFIG_DIRECTORY;
#جيڪڏهن_پورو

    تعريفنوع بنية IMAGE_CE_RUNTIME_FUNCTION_داخلا {
      DWORD Func_شروعات;
      DWORD PrologLen : 8;
      DWORD FuncLen : 22;
      DWORD Thirty_Two_ٻٽو_انگ : 1;
      DWORD ExceptionFlag : 1;
    } IMAGE_CE_RUNTIME_FUNCTION_داخلا_2,*PIMAGE_CE_RUNTIME_FUNCTION_داخلا;

    تعريفنوع بنية IMAGE_ALPHA64_RUNTIME_FUNCTION_داخلا {
      ULONGLONG Begin_پتو;
      ULONGLONG پڇاڙي_پتو;
      ULONGLONG ExceptionHandler;
      ULONGLONG Handler_معلومات;
      ULONGLONG Prolog_پڇاڙي_پتو;
    } IMAGE_ALPHA64_RUNTIME_FUNCTION_داخلا_2,*PIMAGE_ALPHA64_RUNTIME_FUNCTION_داخلا;

    تعريفنوع بنية IMAGE_ALPHA_RUNTIME_FUNCTION_داخلا {
      DWORD Begin_پتو;
      DWORD پڇاڙي_پتو;
      DWORD ExceptionHandler;
      DWORD Handler_معلومات;
      DWORD Prolog_پڇاڙي_پتو;
    } IMAGE_ALPHA_RUNTIME_FUNCTION_داخلا_2,*PIMAGE_ALPHA_RUNTIME_FUNCTION_داخلا;

    تعريفنوع بنية IMAGE_RUNTIME_FUNCTION_داخلا {
      DWORD Begin_پتو;
      DWORD پڇاڙي_پتو;
      DWORD Unwind_Info_پتو;
    } IMAGE_RUNTIME_FUNCTION_داخلا,*PIMAGE_RUNTIME_FUNCTION_داخلا;

    تعريفنوع IMAGE_RUNTIME_FUNCTION_داخلا IMAGE_IA64_RUNTIME_FUNCTION_داخلا;
    تعريفنوع PIMAGE_RUNTIME_FUNCTION_داخلا PIMAGE_IA64_RUNTIME_FUNCTION_داخلا;

    تعريفنوع IMAGE_RUNTIME_FUNCTION_داخلا IMAGE_RUNTIME_FUNCTION_داخلا_2;
    تعريفنوع PIMAGE_RUNTIME_FUNCTION_داخلا PIMAGE_RUNTIME_FUNCTION_داخلا_2;

    تعريفنوع بنية _IMAGE_DEBUG_DIRECTORY {
      DWORD Characteristics;
      DWORD وقت_Date_Stamp;
      لفظ_3 Major_نسخو;
      لفظ_3 Minor_نسخو;
      DWORD Type;
      DWORD سائيز_جو_معلومات;
      DWORD پتو_جو_Raw_معلومات;
      DWORD اشارو_منزل_Raw_معلومات;
    } IMAGE_DEBUG_DIRECTORY,*PIMAGE_DEBUG_DIRECTORY;

#وصف_ڪريو IMAGE_DEBUG_TYPE_UNKNOWN 0
#وصف_ڪريو IMAGE_DEBUG_TYPE_COFF 1
#وصف_ڪريو IMAGE_DEBUG_TYPE_CODEVIEW 2
#وصف_ڪريو IMAGE_DEBUG_TYPE_FPO 3
#وصف_ڪريو IMAGE_DEBUG_TYPE_MISC 4
#وصف_ڪريو IMAGE_DEBUG_TYPE_EXCEPTION 5
#وصف_ڪريو IMAGE_DEBUG_TYPE_FIXUP 6
#وصف_ڪريو IMAGE_DEBUG_TYPE_OMAP_منزل_SRC 7
#وصف_ڪريو IMAGE_DEBUG_TYPE_OMAP_FROM_SRC 8
#وصف_ڪريو IMAGE_DEBUG_TYPE_BORLAND 9
#وصف_ڪريو IMAGE_DEBUG_TYPE_RESERVED10 10
#وصف_ڪريو IMAGE_DEBUG_TYPE_CLSID 11

    تعريفنوع بنية IMAGE_COFF_SYMBOLS_سرو {
      DWORD عدد_جو_Symbols;
      DWORD Lva_منزل_پهريون_نشان;
      DWORD عدد_جو_Linenumbers;
      DWORD Lva_منزل_پهريون_Linenumber;
      DWORD Rva_منزل_پهريون_Byte_جو_ڪوڊ;
      DWORD Rva_منزل_آخري_Byte_جو_ڪوڊ;
      DWORD Rva_منزل_پهريون_Byte_جو_معلومات;
      DWORD Rva_منزل_آخري_Byte_جو_معلومات;
    } IMAGE_COFF_SYMBOLS_سرو_2,*PIMAGE_COFF_SYMBOLS_سرو;

#وصف_ڪريو چوکٺو_FPO 0
#وصف_ڪريو چوکٺو_TRAP 1
#وصف_ڪريو چوکٺو_TSS 2
#وصف_ڪريو چوکٺو_NONFPO 3

    تعريفنوع بنية FPO_معلومات {
      DWORD ul_Off_شروعات;
      DWORD cb_Proc_سائيز;
      DWORD cdwLocals;
      لفظ_3 cdwParams;
      لفظ_3 cbProlog : 8;
      لفظ_3 cbRegs : 3;
      لفظ_3 fHasSEH : 1;
      لفظ_3 fUseBP : 1;
      لفظ_3 reserved : 1;
      لفظ_3 cb_چوکٺو : 2;
    } FPO_معلومات_2,*PFPO_معلومات;
#وصف_ڪريو SIZEOF_RFPO_معلومات 16

#وصف_ڪريو IMAGE_DEBUG_MISC_EXENAME 1

    تعريفنوع بنية _IMAGE_DEBUG_MISC {
      DWORD معلومات_Type;
      DWORD ڊيگهائي_2;
      BOOLEAN Unicode;
      BYTE Reserved[3];
      BYTE معلومات_3[1];
    } IMAGE_DEBUG_MISC,*PIMAGE_DEBUG_MISC;

    تعريفنوع بنية IMAGE_FUNCTION_داخلا {
      DWORD Starting_پتو;
      DWORD Ending_پتو;
      DWORD پڇاڙي_جو_Prologue;
    } IMAGE_FUNCTION_داخلا_2,*PIMAGE_FUNCTION_داخلا;

    تعريفنوع بنية _IMAGE_FUNCTION_ENTRY64 {
      ULONGLONG Starting_پتو;
      ULONGLONG Ending_پتو;
      اتحاد {
	ULONGLONG پڇاڙي_جو_Prologue;
	ULONGLONG Unwind_Info_پتو;
      };
    } IMAGE_FUNCTION_ENTRY64,*PIMAGE_FUNCTION_ENTRY64;

    تعريفنوع بنية IMAGE_SEPARATE_DEBUG_سرو {
      لفظ_3 Signature;
      لفظ_3 Flags;
      لفظ_3 Machine;
      لفظ_3 Characteristics;
      DWORD وقت_Date_Stamp;
      DWORD Check_جوڙ;
      DWORD Image_بنياد;
      DWORD سائيز_جو_Image;
      DWORD عدد_جو_Sections;
      DWORD Exported_نالا_سائيز;
      DWORD Debug_Directory_سائيز;
      DWORD SectionAlignment;
      DWORD Reserved[2];
    } IMAGE_SEPARATE_DEBUG_سرو_2,*PIMAGE_SEPARATE_DEBUG_سرو;

    تعريفنوع بنية _NON_PAGED_DEBUG_INFO {
      لفظ_3 Signature;
      لفظ_3 Flags;
      DWORD سائيز_3;
      لفظ_3 Machine;
      لفظ_3 Characteristics;
      DWORD وقت_Date_Stamp;
      DWORD Check_جوڙ;
      DWORD سائيز_جو_Image;
      ULONGLONG Image_بنياد;

    } NON_PAGED_DEBUG_INFO,*PNON_PAGED_DEBUG_INFO;

#وصف_ڪريو IMAGE_SEPARATE_DEBUG_SIGNATURE 0x4944
#وصف_ڪريو NON_PAGED_DEBUG_SIGNATURE 0x494E

#وصف_ڪريو IMAGE_SEPARATE_DEBUG_FLAGS_نقاب 0x8000
#وصف_ڪريو IMAGE_SEPARATE_DEBUG_MISMATCH 0x8000

    تعريفنوع بنية Image_Architecture_سرو {
      بنانشان صحيح Amask_قدر: 1;
      صحيح Adummy1 :7;
      بنانشان صحيح Amask_سرڪايو: 8;
      صحيح Adummy2 :16;
      DWORD پهريون_داخلا_RVA;
    } IMAGE_ARCHITECTURE_سرو,*PIMAGE_ARCHITECTURE_سرو;

    تعريفنوع بنية Image_Architecture_داخلا {
      DWORD FixupInstRVA;
      DWORD NewInst;
    } IMAGE_ARCHITECTURE_داخلا,*PIMAGE_ARCHITECTURE_داخلا;

#ضمن "poppack.h"

#وصف_ڪريو IMPORT_OBJECT_HDR_SIG2 0xffff

    تعريفنوع بنية IMPORT_OBJECT_سرو {
      لفظ_3 Sig1;
      لفظ_3 Sig2;
      لفظ_3 نسخو_2;
      لفظ_3 Machine;
      DWORD وقت_Date_Stamp;
      DWORD سائيز_جو_معلومات;
      اتحاد {
	لفظ_3 Ordinal;
	لفظ_3 Hint;
      };
      لفظ_3 Type : 2;
      لفظ_3 NameType : 3;
      لفظ_3 Reserved : 11;
    } IMPORT_OBJECT_سرو;

    تعريفنوع تعداد IMPORT_OBJECT_TYPE {
      IMPORT_OBJECT_ڪوڊ = 0,IMPORT_OBJECT_معلومات = 1,IMPORT_OBJECT_CONST = 2
    } IMPORT_OBJECT_TYPE;

    تعريفنوع تعداد IMPORT_OBJECT_NAME_TYPE {
      IMPORT_OBJECT_ORDINAL = 0,IMPORT_OBJECT_NAME = 1,IMPORT_OBJECT_NAME_NO_اڳياڙي = 2,IMPORT_OBJECT_NAME_UNDECORATE = 3
    } IMPORT_OBJECT_NAME_TYPE;

#جيڪڏهن_وصف_نه_ٿيل __IMAGE_COR20_HEADER_DEFINED__
#وصف_ڪريو __IMAGE_COR20_HEADER_DEFINED__
    تعريفنوع تعداد Replaces_Cor_Hdr_Numeric_مقرر_ڪري {
      COMIMAGE_FLAGS_ILONLY =0x00000001,COMIMAGE_FLAGS_32BITREQUIRED =0x00000002,COMIMAGE_FLAGS_IL_LIBRARY =0x00000004,
      COMIMAGE_FLAGS_STRONGNAMESIGNED =0x00000008,COMIMAGE_FLAGS_TRACKDEBUGDATA =0x00010000,COR_نسخو_MAJOR_V2 =2,
      COR_نسخو_MAJOR =COR_نسخو_MAJOR_V2,COR_نسخو_MINOR =0,COR_DELETED_NAME_ڊيگهائي =8,COR_VTABLEGAP_NAME_ڊيگهائي =8,
      NATIVE_TYPE_MAX_CB =1,COR_ILMETHOD_SECT_SMALL_MAX_DATASIZE=0xFF,IMAGE_COR_MIH_METHODRVA =0x01,IMAGE_COR_MIH_EHRVA =0x02,
      IMAGE_COR_MIH_BASICBLOCK =0x08,COR_VTABLE_32_ٻٽو_انگ =0x01,COR_VTABLE_64_ٻٽو_انگ =0x02,COR_VTABLE_FROM_UNMANAGED =0x04,
      COR_VTABLE_CALL_MOST_DERIVED =0x10,IMAGE_COR_EATJ_THUNK_سائيز =32,MAX_CLASS_NAME =1024,MAX_PACKAGE_NAME =1024
    } Replaces_Cor_Hdr_Numeric_مقرر_ڪري;

    تعريفنوع بنية IMAGE_COR20_سرو {
      DWORD cb;
      لفظ_3 Major_Runtime_نسخو;
      لفظ_3 Minor_Runtime_نسخو;
      IMAGE_معلومات_DIRECTORY_2 Meta_معلومات;
      DWORD Flags;
      DWORD داخلا_نقطو_Token;
      IMAGE_معلومات_DIRECTORY_2 Resources;
      IMAGE_معلومات_DIRECTORY_2 StrongNameSignature;
      IMAGE_معلومات_DIRECTORY_2 ڪوڊ_Manager_جدول;
      IMAGE_معلومات_DIRECTORY_2 VTableFixups;
      IMAGE_معلومات_DIRECTORY_2 Export_پتو_جدول_Jumps;
      IMAGE_معلومات_DIRECTORY_2 Managed_Native_سرو;
    } IMAGE_COR20_سرو,*PIMAGE_COR20_سرو;
#جيڪڏهن_پورو

#إذا defined (__x86_64)
    NTSYSAPI PRUNTIME_FUNCTION NTAPI Rtl_Lookup_Function_داخلا (DWORD64 ControlPc, PDWORD64 Image_بنياد, PUNWIND_HISTORY_جدول History_جدول);
    NTSYSAPI VOID NTAPI RtlUnwindEx (PVOID هدف_چوکٺو, PVOID هدف_Ip, PEXCEPTION_رڪارڊ Exception_رڪارڊ, PVOID Return_قدر_2, PCONTEXT Context_رڪارڊ, PUNWIND_HISTORY_جدول History_جدول);
#جيڪڏهن_پورو

#ضمن <string.h>

#جيڪڏهن_وصف_نه_ٿيل SLIST_سرو
#وصف_ڪريو SLIST_سرو

#جيڪڏهن_وصف_ٿيل _WIN64
    تعريفنوع بنية SLIST_داخلا *PSLIST_داخلا;
    تعريفنوع بنية DECLSPEC_ALIGN(16) SLIST_داخلا {
      PSLIST_داخلا ايندڙ_2;
    } SLIST_داخلا_2;
#وإلا

#وصف_ڪريو SLIST_داخلا_2 SINGLE_LIST_داخلا_2
#وصف_ڪريو SLIST_داخلا SINGLE_LIST_داخلا
#وصف_ڪريو PSLIST_داخلا PSINGLE_LIST_داخلا
#جيڪڏهن_پورو

#إذا defined(_WIN64)

    تعريفنوع بنية DECLSPEC_ALIGN(16) SLIST_سرو_2 {
      ULONGLONG Alignment;
      ULONGLONG Region;
    } SLIST_سرو_3;

    تعريفنوع بنية SLIST_سرو_2 *PSLIST_سرو;
#وإلا

    تعريفنوع اتحاد SLIST_سرو_2 {
      ULONGLONG Alignment;
      بنية {
	SLIST_داخلا_2 ايندڙ_2;
	لفظ_3 اونهائي;
	لفظ_3 Sequence;
      };
    } SLIST_سرو_3,*PSLIST_سرو;
#جيڪڏهن_پورو
#جيڪڏهن_پورو

    NTSYSAPI VOID NTAPI Rtl_Initialize_SList_سر(PSLIST_سرو List_سر);
    NTSYSAPI PSLIST_داخلا NTAPI Rtl_پهريون_داخلا_SList(ثابت SLIST_سرو_3 *List_سر);
    NTSYSAPI PSLIST_داخلا NTAPI Rtl_Interlocked_ڪڍو_داخلا_SList(PSLIST_سرو List_سر);
    NTSYSAPI PSLIST_داخلا NTAPI Rtl_Interlocked_ڌڪو_داخلا_SList(PSLIST_سرو List_سر,PSLIST_داخلا List_داخلا);
    NTSYSAPI PSLIST_داخلا NTAPI RtlInterlockedFlushSList(PSLIST_سرو List_سر);
    NTSYSAPI لفظ_3 NTAPI Rtl_Query_اونهائي_SList(PSLIST_سرو List_سر);

#وصف_ڪريو ڍير_NO_SERIALIZE 0x00000001
#وصف_ڪريو ڍير_GROWABLE 0x00000002
#وصف_ڪريو ڍير_GENERATE_EXCEPTIONS 0x00000004
#وصف_ڪريو ڍير_ZERO_يادگيري 0x00000008
#وصف_ڪريو ڍير_REALLOC_اندريون_رکو_ONLY 0x00000010
#وصف_ڪريو ڍير_پڇ_CHECKING_ENABLED 0x00000020
#وصف_ڪريو ڍير_FREE_CHECKING_ENABLED 0x00000040
#وصف_ڪريو ڍير_DISABLE_COALESCE_ON_FREE 0x00000080
#وصف_ڪريو ڍير_CREATE_ALIGN_16 0x00010000
#وصف_ڪريو ڍير_CREATE_ENABLE_TRACING 0x00020000
#وصف_ڪريو ڍير_CREATE_ENABLE_EXECUTE 0x00040000
#وصف_ڪريو ڍير_وڌ_کان_وڌ_ٽيگ 0x0FFF
#وصف_ڪريو ڍير_PSEUDO_ٽيگ_FLAG 0x8000
#وصف_ڪريو ڍير_ٽيگ_سرڪايو 18
#وصف_ڪريو ڍير_MAKE_ٽيگ_FLAGS(b,o) ((DWORD)((b) + ((o) << 18)))

    NTSYSAPI VOID NTAPI RtlCaptureContext(PCONTEXT Context_رڪارڊ);

#وصف_ڪريو IS_متن_UNICODE_ASCII16 0x0001
#وصف_ڪريو IS_متن_UNICODE_ابتو_ASCII16 0x0010

#وصف_ڪريو IS_متن_UNICODE_STATISTICS 0x0002
#وصف_ڪريو IS_متن_UNICODE_ابتو_STATISTICS 0x0020

#وصف_ڪريو IS_متن_UNICODE_CONTROLS 0x0004
#وصف_ڪريو IS_متن_UNICODE_ابتو_CONTROLS 0x0040

#وصف_ڪريو IS_متن_UNICODE_SIGNATURE 0x0008
#وصف_ڪريو IS_متن_UNICODE_ابتو_SIGNATURE 0x0080

#وصف_ڪريو IS_متن_UNICODE_ILLEGAL_CHARS 0x0100
#وصف_ڪريو IS_متن_UNICODE_ODD_ڊيگهائي 0x0200
#وصف_ڪريو IS_متن_UNICODE_DBCS_LEADBYTE 0x0400
#وصف_ڪريو IS_متن_UNICODE_NULL_بائيٽون 0x1000

#وصف_ڪريو IS_متن_UNICODE_UNICODE_نقاب 0x000F
#وصف_ڪريو IS_متن_UNICODE_ابتو_نقاب 0x00F0
#وصف_ڪريو IS_متن_UNICODE_NOT_UNICODE_نقاب 0x0F00
#وصف_ڪريو IS_متن_UNICODE_NOT_ASCII_نقاب 0xF000

#وصف_ڪريو COMPRESSION_FORMAT_NONE (0x0000)
#وصف_ڪريو COMPRESSION_FORMAT_DEFAULT (0x0001)
#وصف_ڪريو COMPRESSION_FORMAT_LZNT1 (0x0002)
#وصف_ڪريو COMPRESSION_ENGINE_STANDARD (0x0000)
#وصف_ڪريو COMPRESSION_ENGINE_وڌ_کان_وڌ (0x0100)
#وصف_ڪريو COMPRESSION_ENGINE_HIBER (0x0200)

#إذا _DBG_MEMCPY_INLINE_ && !defined(_MEMCPY_INLINE_) && !defined(_CRTBLD)
#وصف_ڪريو _MEMCPY_INLINE_
    __CRT_INLINE PVOID __cdecl memcpy_inline(فراغ *dst,ثابت فراغ *src,سائيز_t سائيز) {
      إذا(((حرف *)dst > (حرف *)src) && ((حرف *)dst < ((حرف *)src + سائيز))) {
	__debugbreak();
      }
      أرجع يادگيري_نقل(dst,src,سائيز);
    }
#وصف_ڪريو يادگيري_نقل memcpy_inline
#جيڪڏهن_پورو

    NTSYSAPI سائيز_T NTAPI Rtl_Compare_يادگيري(ثابت VOID *Source1,ثابت VOID *Source2,سائيز_T ڊيگهائي_2);

#وصف_ڪريو Rtl_Equal_يادگيري(Destination,ذريعو_2,ڊيگهائي_2) (!memcmp((Destination),(ذريعو_2),(ڊيگهائي_2)))
#وصف_ڪريو Rtl_Move_يادگيري(Destination,ذريعو_2,ڊيگهائي_2) memmove((Destination),(ذريعو_2),(ڊيگهائي_2))
#وصف_ڪريو Rtl_Copy_يادگيري(Destination,ذريعو_2,ڊيگهائي_2) يادگيري_نقل((Destination),(ذريعو_2),(ڊيگهائي_2))
#وصف_ڪريو Rtl_Fill_يادگيري(Destination,ڊيگهائي_2,Fill) memset((Destination),(Fill),(ڊيگهائي_2))
#وصف_ڪريو Rtl_Zero_يادگيري(Destination,ڊيگهائي_2) memset((Destination),0,(ڊيگهائي_2))

    __CRT_INLINE PVOID Rtl_Secure_Zero_يادگيري(PVOID ptr,سائيز_T cnt) {
      متطاير حرف *vptr =(متطاير حرف *)ptr;
#جيڪڏهن_وصف_ٿيل __x86_64
      __stosb((PBYTE)((DWORD64)vptr),0,cnt);
#وإلا
      طالما(cnt) {
	*vptr = 0;
	vptr++;
	cnt--;
      }
#جيڪڏهن_پورو
      أرجع ptr;
    }

    تعريفنوع بنية پيغام_RESOURCE_داخلا {
      لفظ_3 ڊيگهائي_2;
      لفظ_3 Flags;
      BYTE متن_4[1];
    } پيغام_RESOURCE_داخلا_2,*PMESSAGE_RESOURCE_داخلا;

#وصف_ڪريو پيغام_RESOURCE_UNICODE 0x0001

    تعريفنوع بنية پيغام_RESOURCE_بلاڪ {
      DWORD هيٺيون_Id;
      DWORD مٿاهون_Id;
      DWORD وٿي_منزل_Entries;
    } پيغام_RESOURCE_بلاڪ_2,*PMESSAGE_RESOURCE_بلاڪ;

    تعريفنوع بنية پيغام_RESOURCE_معلومات {
      DWORD عدد_جو_بلاڪون;
      پيغام_RESOURCE_بلاڪ_2 بلاڪون_2[1];
    } پيغام_RESOURCE_معلومات_2,*PMESSAGE_RESOURCE_معلومات;

    تعريفنوع بنية _OSVERSIONINFOA {
      DWORD dw_OSVersion_Info_سائيز;
      DWORD dw_Major_نسخو;
      DWORD dw_Minor_نسخو;
      DWORD dw_Build_عدد;
      DWORD dwPlatformId;
      CHAR szCSDVersion[128];
    } OSVERSIONINFOA,*POSVERSIONINFOA,*LPOSVERSIONINFOA;

    تعريفنوع بنية _OSVERSIONINFOW {
      DWORD dw_OSVersion_Info_سائيز;
      DWORD dw_Major_نسخو;
      DWORD dw_Minor_نسخو;
      DWORD dw_Build_عدد;
      DWORD dwPlatformId;
      WCHAR szCSDVersion[128];
    } OSVERSIONINFOW,*POSVERSIONINFOW,*LPOSVERSIONINFOW,RTL_OSVERSIONINFOW,*PRTL_OSVERSIONINFOW;

#جيڪڏهن_وصف_ٿيل UNICODE
    تعريفنوع OSVERSIONINFOW OSVERSIONINFO;
    تعريفنوع POSVERSIONINFOW POSVERSIONINFO;
    تعريفنوع LPOSVERSIONINFOW LPOSVERSIONINFO;
#وإلا
    تعريفنوع OSVERSIONINFOA OSVERSIONINFO;
    تعريفنوع POSVERSIONINFOA POSVERSIONINFO;
    تعريفنوع LPOSVERSIONINFOA LPOSVERSIONINFO;
#جيڪڏهن_پورو

    تعريفنوع بنية _OSVERSIONINFOEXA {
      DWORD dw_OSVersion_Info_سائيز;
      DWORD dw_Major_نسخو;
      DWORD dw_Minor_نسخو;
      DWORD dw_Build_عدد;
      DWORD dwPlatformId;
      CHAR szCSDVersion[128];
      لفظ_3 wServicePackMajor;
      لفظ_3 wServicePackMinor;
      لفظ_3 w_Suite_نقاب;
      BYTE w_حاصل_ضرب_Type;
      BYTE wReserved;
    } OSVERSIONINFOEXA,*POSVERSIONINFOEXA,*LPOSVERSIONINFOEXA;

    تعريفنوع بنية _OSVERSIONINFOEXW {
      DWORD dw_OSVersion_Info_سائيز;
      DWORD dw_Major_نسخو;
      DWORD dw_Minor_نسخو;
      DWORD dw_Build_عدد;
      DWORD dwPlatformId;
      WCHAR szCSDVersion[128];
      لفظ_3 wServicePackMajor;
      لفظ_3 wServicePackMinor;
      لفظ_3 w_Suite_نقاب;
      BYTE w_حاصل_ضرب_Type;
      BYTE wReserved;
    } OSVERSIONINFOEXW,*POSVERSIONINFOEXW,*LPOSVERSIONINFOEXW,RTL_OSVERSIONINFOEXW,*PRTL_OSVERSIONINFOEXW;
#جيڪڏهن_وصف_ٿيل UNICODE
    تعريفنوع OSVERSIONINFOEXW OSVERSIONINFOEX;
    تعريفنوع POSVERSIONINFOEXW POSVERSIONINFOEX;
    تعريفنوع LPOSVERSIONINFOEXW LPOSVERSIONINFOEX;
#وإلا
    تعريفنوع OSVERSIONINFOEXA OSVERSIONINFOEX;
    تعريفنوع POSVERSIONINFOEXA POSVERSIONINFOEX;
    تعريفنوع LPOSVERSIONINFOEXA LPOSVERSIONINFOEX;
#جيڪڏهن_پورو

#وصف_ڪريو VER_EQUAL 1
#وصف_ڪريو VER_GREATER 2
#وصف_ڪريو VER_GREATER_EQUAL 3
#وصف_ڪريو VER_LESS 4
#وصف_ڪريو VER_LESS_EQUAL 5
#وصف_ڪريو VER_AND 6
#وصف_ڪريو VER_OR 7

#وصف_ڪريو VER_CONDITION_نقاب 7
#وصف_ڪريو VER_انگ_بٽ_في_CONDITION_نقاب 3

#وصف_ڪريو VER_MINORVERSION 0x0000001
#وصف_ڪريو VER_MAJORVERSION 0x0000002
#وصف_ڪريو VER_BUILDNUMBER 0x0000004
#وصف_ڪريو VER_PLATFORMID 0x0000008
#وصف_ڪريو VER_SERVICEPACKMINOR 0x0000010
#وصف_ڪريو VER_SERVICEPACKMAJOR 0x0000020
#وصف_ڪريو VER_SUITENAME 0x0000040
#وصف_ڪريو VER_حاصل_ضرب_TYPE 0x0000080

#وصف_ڪريو VER_NT_WORKSTATION 0x0000001
#وصف_ڪريو VER_NT_DOMAIN_CONTROLLER 0x0000002
#وصف_ڪريو VER_NT_SERVER 0x0000003

#وصف_ڪريو VER_PLATFORM_WIN32s 0
#وصف_ڪريو VER_PLATFORM_WIN32_WINDOWS 1
#وصف_ڪريو VER_PLATFORM_WIN32_NT 2

#وصف_ڪريو VER_سيٽ_CONDITION(_m_,_t_,_c_) ((_m_)=Ver_سيٽ_Condition_نقاب((_m_),(_t_),(_c_)))

    NTSYSAPI ULONGLONG NTAPI Ver_سيٽ_Condition_نقاب(ULONGLONG Condition_نقاب,DWORD Type_نقاب,BYTE Condition);

    تعريفنوع بنية _RTL_CRITICAL_SECTION_DEBUG {
      لفظ_3 Type;
      لفظ_3 Creator_پٺ_Trace_اشاريو;
      بنية _RTL_CRITICAL_SECTION *CriticalSection;
      LIST_داخلا_2 ProcessLocksList;
      DWORD داخلا_ڳڻپ;
      DWORD Contention_ڳڻپ;
      DWORD اضافي_2[2];
    } RTL_CRITICAL_SECTION_DEBUG,*PRTL_CRITICAL_SECTION_DEBUG,RTL_RESOURCE_DEBUG,*PRTL_RESOURCE_DEBUG;

#وصف_ڪريو RTL_CRITSECT_TYPE 0
#وصف_ڪريو RTL_RESOURCE_TYPE 1

    تعريفنوع بنية _RTL_CRITICAL_SECTION {
      PRTL_CRITICAL_SECTION_DEBUG DebugInfo;
      LONG تالو_ڳڻپ;
      LONG Recursion_ڳڻپ;
      HANDLE OwningThread;
      HANDLE تالو_Semaphore;
      ULONG_PTR Spin_ڳڻپ;
    } RTL_CRITICAL_SECTION,*PRTL_CRITICAL_SECTION;

    تعريفنوع VOID (NTAPI *RTL_VERIFIER_DLL_ڀريو_CALLBACK) (PWSTR DllName,PVOID Dll_بنياد,سائيز_T Dll_سائيز,PVOID Reserved);
    تعريفنوع VOID (NTAPI *RTL_VERIFIER_DLL_UNLOAD_CALLBACK) (PWSTR DllName,PVOID Dll_بنياد,سائيز_T Dll_سائيز,PVOID Reserved);
    تعريفنوع VOID (NTAPI *RTL_VERIFIER_NTDLLHEAPFREE_CALLBACK)(PVOID ورهاست_بنياد,سائيز_T ورهاست_سائيز);

    تعريفنوع بنية _RTL_VERIFIER_THUNK_DESCRIPTOR {
      PCHAR ThunkName;
      PVOID Thunk_Old_پتو;
      PVOID Thunk_New_پتو;
    } RTL_VERIFIER_THUNK_DESCRIPTOR,*PRTL_VERIFIER_THUNK_DESCRIPTOR;

    تعريفنوع بنية _RTL_VERIFIER_DLL_DESCRIPTOR {
      PWCHAR DllName;
      DWORD DllFlags;
      PVOID Dll_پتو;
      PRTL_VERIFIER_THUNK_DESCRIPTOR DllThunks;
    } RTL_VERIFIER_DLL_DESCRIPTOR,*PRTL_VERIFIER_DLL_DESCRIPTOR;

    تعريفنوع بنية _RTL_VERIFIER_PROVIDER_DESCRIPTOR {
      DWORD ڊيگهائي_2;
      PRTL_VERIFIER_DLL_DESCRIPTOR ProviderDlls;
      RTL_VERIFIER_DLL_ڀريو_CALLBACK Provider_Dll_ڀريو_Callback;
      RTL_VERIFIER_DLL_UNLOAD_CALLBACK ProviderDllUnloadCallback;
      PWSTR VerifierImage;
      DWORD VerifierFlags;
      DWORD VerifierDebug;
      PVOID Rtlp_Get_ڍير_Trace_پتو;
      PVOID Rtlp_Debug_صفحو_ڍير_Create;
      PVOID Rtlp_Debug_صفحو_ڍير_Destroy;
      RTL_VERIFIER_NTDLLHEAPFREE_CALLBACK Provider_Ntdll_ڍير_Free_Callback;
    } RTL_VERIFIER_PROVIDER_DESCRIPTOR,*PRTL_VERIFIER_PROVIDER_DESCRIPTOR;

#وصف_ڪريو RTL_VRF_FLG_ڀريل_صفحو_ڍير 0x00000001
#وصف_ڪريو RTL_VRF_FLG_RESERVED_DONOTUSE 0x00000002
#وصف_ڪريو RTL_VRF_FLG_HANDLE_CHECKS 0x00000004
#وصف_ڪريو RTL_VRF_FLG_ڍير_CHECKS 0x00000008
#وصف_ڪريو RTL_VRF_FLG_APPCOMPAT_CHECKS 0x00000010
#وصف_ڪريو RTL_VRF_FLG_TLS_CHECKS 0x00000020
#وصف_ڪريو RTL_VRF_FLG_DIRTY_STACKS 0x00000040
#وصف_ڪريو RTL_VRF_FLG_RPC_CHECKS 0x00000080
#وصف_ڪريو RTL_VRF_FLG_COM_CHECKS 0x00000100
#وصف_ڪريو RTL_VRF_FLG_DANGEROUS_APIS 0x00000200
#وصف_ڪريو RTL_VRF_FLG_RACE_CHECKS 0x00000400
#وصف_ڪريو RTL_VRF_FLG_DEADLOCK_CHECKS 0x00000800
#وصف_ڪريو RTL_VRF_FLG_پهريون_CHANCE_EXCEPTION_CHECKS 0x00001000
#وصف_ڪريو RTL_VRF_FLG_VIRTUAL_MEM_CHECKS 0x00002000
#وصف_ڪريو RTL_VRF_FLG_ENABLE_LOGGING 0x00004000
#وصف_ڪريو RTL_VRF_FLG_FAST_FILL_ڍير 0x00008000
#وصف_ڪريو RTL_VRF_FLG_VIRTUAL_SPACE_TRACKING 0x00010000
#وصف_ڪريو RTL_VRF_FLG_ENABLED_SYSTEM_WIDE 0x00020000
#وصف_ڪريو RTL_VRF_FLG_MISCELLANEOUS_CHECKS 0x00020000
#وصف_ڪريو RTL_VRF_FLG_تالو_CHECKS 0x00040000

#وصف_ڪريو APPLICATION_VERIFIER_اندروني_ERROR 0x80000000
#وصف_ڪريو APPLICATION_VERIFIER_اندروني_WARNING 0x40000000
#وصف_ڪريو APPLICATION_VERIFIER_NO_BREAK 0x20000000
#وصف_ڪريو APPLICATION_VERIFIER_CONTINUABLE_BREAK 0x10000000

#وصف_ڪريو APPLICATION_VERIFIER_UNKNOWN_ERROR 0x0001
#وصف_ڪريو APPLICATION_VERIFIER_ACCESS_VIOLATION 0x0002
#وصف_ڪريو APPLICATION_VERIFIER_UNSYNCHRONIZED_ACCESS 0x0003
#وصف_ڪريو APPLICATION_VERIFIER_EXTREME_سائيز_REQUEST 0x0004
#وصف_ڪريو APPLICATION_VERIFIER_BAD_ڍير_HANDLE 0x0005
#وصف_ڪريو APPLICATION_VERIFIER_SWITCHED_ڍير_HANDLE 0x0006
#وصف_ڪريو APPLICATION_VERIFIER_DOUBLE_FREE 0x0007
#وصف_ڪريو APPLICATION_VERIFIER_CORRUPTED_ڍير_بلاڪ 0x0008
#وصف_ڪريو APPLICATION_VERIFIER_DESTROY_PROCESS_ڍير 0x0009
#وصف_ڪريو APPLICATION_VERIFIER_UNEXPECTED_EXCEPTION 0x000A
#وصف_ڪريو APPLICATION_VERIFIER_CORRUPTED_ڍير_بلاڪ_EXCEPTION_RAISED_FOR_سرو 0x000B
#وصف_ڪريو APPLICATION_VERIFIER_CORRUPTED_ڍير_بلاڪ_EXCEPTION_RAISED_FOR_PROBING 0x000C
#وصف_ڪريو APPLICATION_VERIFIER_CORRUPTED_ڍير_بلاڪ_سرو 0x000D
#وصف_ڪريو APPLICATION_VERIFIER_CORRUPTED_FREED_ڍير_بلاڪ 0x000E
#وصف_ڪريو APPLICATION_VERIFIER_CORRUPTED_ڍير_بلاڪ_SUFFIX 0x000F
#وصف_ڪريو APPLICATION_VERIFIER_CORRUPTED_ڍير_بلاڪ_شروعات_STAMP 0x0010
#وصف_ڪريو APPLICATION_VERIFIER_CORRUPTED_ڍير_بلاڪ_پڇاڙي_STAMP 0x0011
#وصف_ڪريو APPLICATION_VERIFIER_CORRUPTED_ڍير_بلاڪ_اڳياڙي 0x0012
#وصف_ڪريو APPLICATION_VERIFIER_پهريون_CHANCE_ACCESS_VIOLATION 0x0013
#وصف_ڪريو APPLICATION_VERIFIER_CORRUPTED_ڍير_LIST 0x0014

#وصف_ڪريو APPLICATION_VERIFIER_TERMINATE_THREAD_CALL 0x0100
#وصف_ڪريو APPLICATION_VERIFIER_ڍير_حد_کان_مٿي 0x0101
#وصف_ڪريو APPLICATION_VERIFIER_INVALID_EXIT_PROCESS_CALL 0x0102

#وصف_ڪريو APPLICATION_VERIFIER_EXIT_THREAD_OWNS_تالو 0x0200
#وصف_ڪريو APPLICATION_VERIFIER_تالو_اندريون_UNLOADED_DLL 0x0201
#وصف_ڪريو APPLICATION_VERIFIER_تالو_اندريون_FREED_ڍير 0x0202
#وصف_ڪريو APPLICATION_VERIFIER_تالو_DOUBLE_INITIALIZE 0x0203
#وصف_ڪريو APPLICATION_VERIFIER_تالو_اندريون_FREED_يادگيري 0x0204
#وصف_ڪريو APPLICATION_VERIFIER_تالو_CORRUPTED 0x0205
#وصف_ڪريو APPLICATION_VERIFIER_تالو_INVALID_OWNER 0x0206
#وصف_ڪريو APPLICATION_VERIFIER_تالو_INVALID_RECURSION_ڳڻپ 0x0207
#وصف_ڪريو APPLICATION_VERIFIER_تالو_INVALID_تالو_ڳڻپ 0x0208
#وصف_ڪريو APPLICATION_VERIFIER_تالو_OVER_RELEASED 0x0209
#وصف_ڪريو APPLICATION_VERIFIER_تالو_NOT_INITIALIZED 0x0210
#وصف_ڪريو APPLICATION_VERIFIER_تالو_ALREADY_INITIALIZED 0x0211
#وصف_ڪريو APPLICATION_VERIFIER_تالو_اندريون_FREED_VMEM 0x0212
#وصف_ڪريو APPLICATION_VERIFIER_تالو_اندريون_UNMAPPED_MEM 0x0213
#وصف_ڪريو APPLICATION_VERIFIER_THREAD_NOT_تالو_OWNER 0x0214

#وصف_ڪريو APPLICATION_VERIFIER_INVALID_HANDLE 0x0300
#وصف_ڪريو APPLICATION_VERIFIER_INVALID_TLS_قدر 0x0301
#وصف_ڪريو APPLICATION_VERIFIER_INCORRECT_WAIT_CALL 0x0302
#وصف_ڪريو APPLICATION_VERIFIER_NULL_HANDLE 0x0303
#وصف_ڪريو APPLICATION_VERIFIER_WAIT_اندريون_DLLMAIN 0x0304

#وصف_ڪريو APPLICATION_VERIFIER_COM_ERROR 0x0400
#وصف_ڪريو APPLICATION_VERIFIER_COM_API_اندريون_DLLMAIN 0x0401
#وصف_ڪريو APPLICATION_VERIFIER_COM_UNHANDLED_EXCEPTION 0x0402
#وصف_ڪريو APPLICATION_VERIFIER_COM_UNBALANCED_COINIT 0x0403
#وصف_ڪريو APPLICATION_VERIFIER_COM_UNBALANCED_OLEINIT 0x0404
#وصف_ڪريو APPLICATION_VERIFIER_COM_UNBALANCED_SWC 0x0405
#وصف_ڪريو APPLICATION_VERIFIER_COM_NULL_DACL 0x0406
#وصف_ڪريو APPLICATION_VERIFIER_COM_UNSAFE_IMPERSONATION 0x0407
#وصف_ڪريو APPLICATION_VERIFIER_COM_SMUGGLED_WRAPPER 0x0408
#وصف_ڪريو APPLICATION_VERIFIER_COM_SMUGGLED_PROXY 0x0409
#وصف_ڪريو APPLICATION_VERIFIER_COM_CF_SUCCESS_WITH_NULL 0x040A
#وصف_ڪريو APPLICATION_VERIFIER_COM_GCO_SUCCESS_WITH_NULL 0x040B
#وصف_ڪريو APPLICATION_VERIFIER_COM_OBJECT_اندريون_FREED_يادگيري 0x040C
#وصف_ڪريو APPLICATION_VERIFIER_COM_OBJECT_اندريون_UNLOADED_DLL 0x040D
#وصف_ڪريو APPLICATION_VERIFIER_COM_VTBL_اندريون_FREED_يادگيري 0x040E
#وصف_ڪريو APPLICATION_VERIFIER_COM_VTBL_اندريون_UNLOADED_DLL 0x040F
#وصف_ڪريو APPLICATION_VERIFIER_COM_HOLDING_LOCKS_ON_CALL 0x0410

#وصف_ڪريو APPLICATION_VERIFIER_RPC_ERROR 0x0500

#وصف_ڪريو APPLICATION_VERIFIER_INVALID_FREEMEM 0x0600
#وصف_ڪريو APPLICATION_VERIFIER_INVALID_ALLOCMEM 0x0601
#وصف_ڪريو APPLICATION_VERIFIER_INVALID_MAPVIEW 0x0602
#وصف_ڪريو APPLICATION_VERIFIER_PROBE_INVALID_پتو 0x0603
#وصف_ڪريو APPLICATION_VERIFIER_PROBE_FREE_MEM 0x0604
#وصف_ڪريو APPLICATION_VERIFIER_PROBE_GUARD_صفحو 0x0605
#وصف_ڪريو APPLICATION_VERIFIER_PROBE_NULL 0x0606
#وصف_ڪريو APPLICATION_VERIFIER_PROBE_INVALID_شروعات_OR_سائيز 0x0607
#وصف_ڪريو APPLICATION_VERIFIER_سائيز_ڍير_UNEXPECTED_EXCEPTION 0x0618

#وصف_ڪريو VERIFIER_STOP(ڪوڊ_4,نياپو_3,P1,S1,P2,S2,P3,S3,P4,S4) { RtlApplicationVerifierStop ((ڪوڊ_4),(نياپو_3),(ULONG_PTR)(P1),(S1),(ULONG_PTR)(P2),(S2),(ULONG_PTR)(P3),(S3),(ULONG_PTR)(P4),(S4)); }

    VOID NTAPI RtlApplicationVerifierStop(ULONG_PTR ڪوڊ_4,PSTR پيغام_3,ULONG_PTR Param1,PSTR Description1,ULONG_PTR Param2,PSTR Description2,ULONG_PTR Param3,PSTR Description3,ULONG_PTR Param4,PSTR Description4);

    تعريفنوع LONG (NTAPI *PVECTORED_EXCEPTION_HANDLER)(بنية EXCEPTION_اشارا_2 *ExceptionInfo);
#وصف_ڪريو SEF_DACL_AUTO_INHERIT 0x01
#وصف_ڪريو SEF_SACL_AUTO_INHERIT 0x02
#وصف_ڪريو SEF_DEFAULT_DESCRIPTOR_FOR_OBJECT 0x04
#وصف_ڪريو SEF_AVOID_PRIVILEGE_CHECK 0x08
#وصف_ڪريو SEF_AVOID_OWNER_CHECK 0x10
#وصف_ڪريو SEF_DEFAULT_OWNER_FROM_والد 0x20
#وصف_ڪريو SEF_DEFAULT_گروهه_FROM_والد 0x40

    تعريفنوع تعداد ڍير_INFORMATION_CLASS_2 {
      ڍير_Compatibility_Information
    } ڍير_INFORMATION_CLASS;

    NTSYSAPI DWORD NTAPI Rtl_سيٽ_ڍير_Information(PVOID ڍير_Handle,ڍير_INFORMATION_CLASS ڍير_Information_Class,PVOID ڍير_Information,سائيز_T ڍير_Information_ڊيگهائي);
    NTSYSAPI DWORD NTAPI Rtl_Query_ڍير_Information(PVOID ڍير_Handle,ڍير_INFORMATION_CLASS ڍير_Information_Class,PVOID ڍير_Information,سائيز_T ڍير_Information_ڊيگهائي,PSIZE_T Return_ڊيگهائي);
    DWORD NTAPI Rtl_گڻو_Allocate_ڍير(PVOID ڍير_Handle,DWORD Flags,سائيز_T سائيز_3,DWORD ڳڻپ_3,PVOID *Array);
    DWORD NTAPI Rtl_گڻو_Free_ڍير(PVOID ڍير_Handle,DWORD Flags,DWORD ڳڻپ_3,PVOID *Array);

#وصف_ڪريو WT_EXECUTEDEFAULT 0x00000000
#وصف_ڪريو WT_EXECUTEINIOTHREAD 0x00000001
#وصف_ڪريو WT_EXECUTEINUITHREAD 0x00000002
#وصف_ڪريو WT_EXECUTEINWAITTHREAD 0x00000004
#وصف_ڪريو WT_EXECUTEONLYONCE 0x00000008
#وصف_ڪريو WT_EXECUTEINTIMERTHREAD 0x00000020
#وصف_ڪريو WT_EXECUTELONGFUNCTION 0x00000010
#وصف_ڪريو WT_EXECUTEINPERSISTENTIOTHREAD 0x00000040
#وصف_ڪريو WT_EXECUTEINPERSISTENTTHREAD 0x00000080
#وصف_ڪريو WT_TRANSFER_IMPERSONATION 0x00000100
#وصف_ڪريو WT_سيٽ_MAX_THREADPOOL_ڌاڳا(Flags,حد_بندي_2) ((Flags) |= (حد_بندي_2)<<16)
    تعريفنوع VOID (NTAPI *WAITORTIMERCALLBACKFUNC)(PVOID,BOOLEAN);
    تعريفنوع VOID (NTAPI *WORKERCALLBACKFUNC)(PVOID);
    تعريفنوع VOID (NTAPI *APC_CALLBACK_FUNCTION)(DWORD ,PVOID,PVOID);
    تعريفنوع
      VOID
      (NTAPI *PFLS_CALLBACK_FUNCTION)(PVOID lp_Fls_معلومات);
#وصف_ڪريو WT_EXECUTEINLONGTHREAD 0x00000010
#وصف_ڪريو WT_EXECUTEDELETEWAIT 0x00000008

    تعريفنوع تعداد _ACTIVATION_CONTEXT_INFO_CLASS {
      ActivationContextBasicInformation = 1,ActivationContextDetailedInformation = 2,Assembly_Detailed_Information_اندريون_Activation_Context = 3,File_Information_اندريون_Assembly_جو_Assembly_اندريون_Activation_Context = 4,MaxActivationContextInfoClass,Assembly_Detailed_Information_اندريون_Activation_Contxt = 3,File_Information_اندريون_Assembly_جو_Assembly_اندريون_Activation_Contxt = 4
    } ACTIVATION_CONTEXT_INFO_CLASS;

#وصف_ڪريو ACTIVATIONCONTEXTINFOCLASS ACTIVATION_CONTEXT_INFO_CLASS

    تعريفنوع بنية ACTIVATION_CONTEXT_QUERY_اشاريو {
      DWORD ul_Assembly_اشاريو;
      DWORD ul_File_اشاريو_اندريون_Assembly;
    } ACTIVATION_CONTEXT_QUERY_اشاريو_2,*PACTIVATION_CONTEXT_QUERY_اشاريو;

    تعريفنوع ثابت بنية ACTIVATION_CONTEXT_QUERY_اشاريو *PCACTIVATION_CONTEXT_QUERY_اشاريو;

#وصف_ڪريو ACTIVATION_CONTEXT_رستو_TYPE_NONE (1)
#وصف_ڪريو ACTIVATION_CONTEXT_رستو_TYPE_WIN32_FILE (2)
#وصف_ڪريو ACTIVATION_CONTEXT_رستو_TYPE_URL (3)
#وصف_ڪريو ACTIVATION_CONTEXT_رستو_TYPE_ASSEMBLYREF (4)

    تعريفنوع بنية _ASSEMBLY_FILE_DETAILED_INFORMATION {
      DWORD ulFlags;
      DWORD ul_Filename_ڊيگهائي;
      DWORD ul_رستو_ڊيگهائي;

      PCWSTR lpFileName;
      PCWSTR lp_File_رستو;
    } ASSEMBLY_FILE_DETAILED_INFORMATION,*PASSEMBLY_FILE_DETAILED_INFORMATION;
    تعريفنوع ثابت ASSEMBLY_FILE_DETAILED_INFORMATION *PCASSEMBLY_FILE_DETAILED_INFORMATION;

#وصف_ڪريو _ASSEMBLY_DLL_REDIRECTION_DETAILED_INFORMATION _ASSEMBLY_FILE_DETAILED_INFORMATION
#وصف_ڪريو ASSEMBLY_DLL_REDIRECTION_DETAILED_INFORMATION ASSEMBLY_FILE_DETAILED_INFORMATION
#وصف_ڪريو PASSEMBLY_DLL_REDIRECTION_DETAILED_INFORMATION PASSEMBLY_FILE_DETAILED_INFORMATION
#وصف_ڪريو PCASSEMBLY_DLL_REDIRECTION_DETAILED_INFORMATION PCASSEMBLY_FILE_DETAILED_INFORMATION

    تعريفنوع بنية _ACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION {
      DWORD ulFlags;
      DWORD ul_Encoded_Assembly_سڃاڻپ_عنصر_ڊيگهائي;
      DWORD ul_Manifest_رستو_Type;
      DWORD ul_Manifest_رستو_ڊيگهائي;
      LARGE_INTEGER li_Manifest_آخري_Write_وقت;
      DWORD ul_Policy_رستو_Type;
      DWORD ul_Policy_رستو_ڊيگهائي;
      LARGE_INTEGER li_Policy_آخري_Write_وقت;
      DWORD ul_Metadata_Satellite_Roster_اشاريو;
      DWORD ul_Manifest_نسخو_Major;
      DWORD ul_Manifest_نسخو_Minor;
      DWORD ul_Policy_نسخو_Major;
      DWORD ul_Policy_نسخو_Minor;
      DWORD ul_Assembly_Directory_Name_ڊيگهائي;
      PCWSTR lp_Assembly_Encoded_Assembly_سڃاڻپ_عنصر;
      PCWSTR lp_Assembly_Manifest_رستو;
      PCWSTR lp_Assembly_Policy_رستو;
      PCWSTR lpAssemblyDirectoryName;
      DWORD ul_File_ڳڻپ;
    } ACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION,*PACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION;

    تعريفنوع ثابت بنية _ACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION *PCACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION;

    تعريفنوع بنية _ACTIVATION_CONTEXT_DETAILED_INFORMATION {
      DWORD dwFlags;
      DWORD ul_Format_نسخو;
      DWORD ul_Assembly_ڳڻپ;
      DWORD ul_پاڙ_Manifest_رستو_Type;
      DWORD ul_پاڙ_Manifest_رستو_Chars;
      DWORD ul_پاڙ_Configuration_رستو_Type;
      DWORD ul_پاڙ_Configuration_رستو_Chars;
      DWORD ul_App_Dir_رستو_Type;
      DWORD ul_App_Dir_رستو_Chars;
      PCWSTR lp_پاڙ_Manifest_رستو;
      PCWSTR lp_پاڙ_Configuration_رستو;
      PCWSTR lp_App_Dir_رستو;
    } ACTIVATION_CONTEXT_DETAILED_INFORMATION,*PACTIVATION_CONTEXT_DETAILED_INFORMATION;

    تعريفنوع ثابت بنية _ACTIVATION_CONTEXT_DETAILED_INFORMATION *PCACTIVATION_CONTEXT_DETAILED_INFORMATION;

#وصف_ڪريو DLL_PROCESS_ATTACH 1
#وصف_ڪريو DLL_THREAD_ATTACH 2
#وصف_ڪريو DLL_THREAD_DETACH 3
#وصف_ڪريو DLL_PROCESS_DETACH 0
#وصف_ڪريو DLL_PROCESS_VERIFIER 4

#وصف_ڪريو EVENTLOG_SEQUENTIAL_READ 0x0001
#وصف_ڪريو EVENTLOG_SEEK_READ 0x0002
#وصف_ڪريو EVENTLOG_FORWARDS_READ 0x0004
#وصف_ڪريو EVENTLOG_BACKWARDS_READ 0x0008

#وصف_ڪريو EVENTLOG_SUCCESS 0x0000
#وصف_ڪريو EVENTLOG_ERROR_TYPE 0x0001
#وصف_ڪريو EVENTLOG_WARNING_TYPE 0x0002
#وصف_ڪريو EVENTLOG_INFORMATION_TYPE 0x0004
#وصف_ڪريو EVENTLOG_AUDIT_SUCCESS 0x0008
#وصف_ڪريو EVENTLOG_AUDIT_FAILURE 0x0010

#وصف_ڪريو EVENTLOG_شروعات_PAIRED_EVENT 0x0001
#وصف_ڪريو EVENTLOG_پڇاڙي_PAIRED_EVENT 0x0002
#وصف_ڪريو EVENTLOG_پڇاڙي_ALL_PAIRED_EVENTS 0x0004
#وصف_ڪريو EVENTLOG_PAIRED_EVENT_سرگرم 0x0008
#وصف_ڪريو EVENTLOG_PAIRED_EVENT_INACTIVE 0x0010

    تعريفنوع بنية _EVENTLOGRECORD {
      DWORD ڊيگهائي_2;
      DWORD Reserved;
      DWORD رڪارڊ_عدد;
      DWORD وقت_Generated;
      DWORD وقت_Written;
      DWORD EventID;
      لفظ_3 EventType;
      لفظ_3 انگ_لڙيون;
      لفظ_3 EventCategory;
      لفظ_3 ReservedFlags;
      DWORD Closing_رڪارڊ_عدد;
      DWORD String_وٿي;
      DWORD User_Sid_ڊيگهائي;
      DWORD User_Sid_وٿي;
      DWORD معلومات_ڊيگهائي;
      DWORD معلومات_وٿي_2;
    } EVENTLOGRECORD,*PEVENTLOGRECORD;

#وصف_ڪريو MAXLOGICALLOGNAMESIZE 256

    تعريفنوع بنية _EVENTSFORLOGFILE{
      DWORD ul_سائيز;
      WCHAR szLogicalLogFile[MAXLOGICALLOGNAMESIZE];
      DWORD ul_انگ_رڪارڊون;
      EVENTLOGRECORD p_Event_Log_رڪارڊون[];
    } EVENTSFORLOGFILE,*PEVENTSFORLOGFILE;

    تعريفنوع بنية _PACKEDEVENTINFO{
      DWORD ul_سائيز;
      DWORD ul_انگ_Events_For_Log_File;
      DWORD ulOffsets[];
    } PACKEDEVENTINFO,*PPACKEDEVENTINFO;

#وصف_ڪريو ڪنجي_QUERY_قدر (0x0001)
#وصف_ڪريو ڪنجي_سيٽ_قدر (0x0002)
#وصف_ڪريو ڪنجي_CREATE_SUB_ڪنجي (0x0004)
#وصف_ڪريو ڪنجي_ENUMERATE_SUB_ڪنجيون (0x0008)
#وصف_ڪريو ڪنجي_NOTIFY (0x0010)
#وصف_ڪريو ڪنجي_CREATE_LINK (0x0020)
#وصف_ڪريو ڪنجي_WOW64_32_ڪنجي (0x0200)
#وصف_ڪريو ڪنجي_WOW64_64_ڪنجي (0x0100)
#وصف_ڪريو ڪنجي_WOW64_RES (0x0300)

#وصف_ڪريو ڪنجي_READ ((STANDARD_RIGHTS_READ | ڪنجي_QUERY_قدر | ڪنجي_ENUMERATE_SUB_ڪنجيون | ڪنجي_NOTIFY) & (~SYNCHRONIZE))
#وصف_ڪريو ڪنجي_WRITE ((STANDARD_RIGHTS_WRITE | ڪنجي_سيٽ_قدر | ڪنجي_CREATE_SUB_ڪنجي) & (~SYNCHRONIZE))
#وصف_ڪريو ڪنجي_EXECUTE ((ڪنجي_READ) & (~SYNCHRONIZE))
#وصف_ڪريو ڪنجي_ALL_ACCESS ((STANDARD_RIGHTS_ALL | ڪنجي_QUERY_قدر | ڪنجي_سيٽ_قدر | ڪنجي_CREATE_SUB_ڪنجي | ڪنجي_ENUMERATE_SUB_ڪنجيون | ڪنجي_NOTIFY | ڪنجي_CREATE_LINK) & (~SYNCHRONIZE))
#وصف_ڪريو REG_OPTION_RESERVED (0x00000000L)

#وصف_ڪريو REG_OPTION_NON_VOLATILE (0x00000000L)
#وصف_ڪريو REG_OPTION_VOLATILE (0x00000001L)
#وصف_ڪريو REG_OPTION_CREATE_LINK (0x00000002L)
#وصف_ڪريو REG_OPTION_BACKUP_RESTORE (0x00000004L)
#وصف_ڪريو REG_OPTION_OPEN_LINK (0x00000008L)
#وصف_ڪريو REG_LEGAL_OPTION (REG_OPTION_RESERVED | REG_OPTION_NON_VOLATILE | REG_OPTION_VOLATILE | REG_OPTION_CREATE_LINK | REG_OPTION_BACKUP_RESTORE | REG_OPTION_OPEN_LINK)
#وصف_ڪريو REG_CREATED_NEW_ڪنجي (0x00000001L)
#وصف_ڪريو REG_OPENED_EXISTING_ڪنجي (0x00000002L)
#وصف_ڪريو REG_STANDARD_FORMAT 1
#وصف_ڪريو REG_LATEST_FORMAT 2
#وصف_ڪريو REG_NO_COMPRESSION 4
#وصف_ڪريو REG_سڄو_HIVE_VOLATILE (0x00000001L)
#وصف_ڪريو REG_REFRESH_HIVE (0x00000002L)
#وصف_ڪريو REG_NO_LAZY_FLUSH (0x00000004L)
#وصف_ڪريو REG_FORCE_RESTORE (0x00000008L)
#وصف_ڪريو REG_FORCE_UNLOAD 1

#وصف_ڪريو REG_NOTIFY_CHANGE_NAME (0x00000001L)
#وصف_ڪريو REG_NOTIFY_CHANGE_خاصيتون (0x00000002L)
#وصف_ڪريو REG_NOTIFY_CHANGE_آخري_سيٽ (0x00000004L)
#وصف_ڪريو REG_NOTIFY_CHANGE_SECURITY (0x00000008L)

#وصف_ڪريو REG_LEGAL_CHANGE_FILTER (REG_NOTIFY_CHANGE_NAME | REG_NOTIFY_CHANGE_خاصيتون | REG_NOTIFY_CHANGE_آخري_سيٽ | REG_NOTIFY_CHANGE_SECURITY)

#وصف_ڪريو REG_NONE (0)
#وصف_ڪريو REG_SZ (1)
#وصف_ڪريو REG_EXPAND_SZ (2)

#وصف_ڪريو REG_ٻٽو (3)
#وصف_ڪريو REG_DWORD (4)
#وصف_ڪريو REG_DWORD_LITTLE_ENDIAN (4)
#وصف_ڪريو REG_DWORD_BIG_ENDIAN (5)
#وصف_ڪريو REG_LINK (6)
#وصف_ڪريو REG_MULTI_SZ (7)
#وصف_ڪريو REG_RESOURCE_LIST (8)
#وصف_ڪريو REG_ڀريل_RESOURCE_DESCRIPTOR (9)
#وصف_ڪريو REG_RESOURCE_REQUIREMENTS_LIST (10)
#وصف_ڪريو REG_QWORD (11)
#وصف_ڪريو REG_QWORD_LITTLE_ENDIAN (11)

#وصف_ڪريو SERVICE_KERNEL_DRIVER 0x00000001
#وصف_ڪريو SERVICE_FILE_SYSTEM_DRIVER 0x00000002
#وصف_ڪريو SERVICE_ADAPTER 0x00000004
#وصف_ڪريو SERVICE_RECOGNIZER_DRIVER 0x00000008

#وصف_ڪريو SERVICE_DRIVER (SERVICE_KERNEL_DRIVER | SERVICE_FILE_SYSTEM_DRIVER | SERVICE_RECOGNIZER_DRIVER)

#وصف_ڪريو SERVICE_WIN32_OWN_PROCESS 0x00000010
#وصف_ڪريو SERVICE_WIN32_SHARE_PROCESS 0x00000020
#وصف_ڪريو SERVICE_WIN32 (SERVICE_WIN32_OWN_PROCESS | SERVICE_WIN32_SHARE_PROCESS)

#وصف_ڪريو SERVICE_INTERACTIVE_PROCESS 0x00000100

#وصف_ڪريو SERVICE_TYPE_ALL (SERVICE_WIN32 | SERVICE_ADAPTER | SERVICE_DRIVER | SERVICE_INTERACTIVE_PROCESS)

#وصف_ڪريو SERVICE_BOOT_شروعات 0x00000000
#وصف_ڪريو SERVICE_SYSTEM_شروعات 0x00000001
#وصف_ڪريو SERVICE_AUTO_شروعات 0x00000002
#وصف_ڪريو SERVICE_DEMAND_شروعات 0x00000003
#وصف_ڪريو SERVICE_DISABLED 0x00000004

#وصف_ڪريو SERVICE_ERROR_IGNORE 0x00000000
#وصف_ڪريو SERVICE_ERROR_عام 0x00000001
#وصف_ڪريو SERVICE_ERROR_SEVERE 0x00000002
#وصف_ڪريو SERVICE_ERROR_CRITICAL 0x00000003

    تعريفنوع تعداد CM_SERVICE_ڳنڍ_TYPE {
      DriverType = SERVICE_KERNEL_DRIVER,FileSystemType = SERVICE_FILE_SYSTEM_DRIVER,Win32ServiceOwnProcess = SERVICE_WIN32_OWN_PROCESS,
      Win32ServiceShareProcess = SERVICE_WIN32_SHARE_PROCESS,AdapterType = SERVICE_ADAPTER,RecognizerType = SERVICE_RECOGNIZER_DRIVER
    } SERVICE_ڳنڍ_TYPE;

    تعريفنوع تعداد CM_SERVICE_ڀريو_TYPE {
      Boot_ڀريو = SERVICE_BOOT_شروعات,System_ڀريو = SERVICE_SYSTEM_شروعات,Auto_ڀريو = SERVICE_AUTO_شروعات,Demand_ڀريو = SERVICE_DEMAND_شروعات,
      Disable_ڀريو = SERVICE_DISABLED
    } SERVICE_ڀريو_TYPE;

    تعريفنوع تعداد _CM_ERROR_CONTROL_TYPE {
      IgnoreError = SERVICE_ERROR_IGNORE,عام_Error = SERVICE_ERROR_عام,SevereError = SERVICE_ERROR_SEVERE,CriticalError = SERVICE_ERROR_CRITICAL
    } SERVICE_ERROR_TYPE;

#وصف_ڪريو پٽي_ERASE_SHORT 0L
#وصف_ڪريو پٽي_ERASE_LONG 1L

    تعريفنوع بنية پٽي_ERASE {
      DWORD Type;
      BOOLEAN فوري_2;
    } پٽي_ERASE_2,*PTAPE_ERASE;

#وصف_ڪريو پٽي_ڀريو 0L
#وصف_ڪريو پٽي_UNLOAD 1L
#وصف_ڪريو پٽي_TENSION 2L
#وصف_ڪريو پٽي_تالو 3L
#وصف_ڪريو پٽي_UNLOCK 4L
#وصف_ڪريو پٽي_FORMAT 5L

    تعريفنوع بنية پٽي_PREPARE {
      DWORD Operation;
      BOOLEAN فوري_2;
    } پٽي_PREPARE_2,*PTAPE_PREPARE;

#وصف_ڪريو پٽي_SETMARKS 0L
#وصف_ڪريو پٽي_FILEMARKS 1L
#وصف_ڪريو پٽي_SHORT_FILEMARKS 2L
#وصف_ڪريو پٽي_LONG_FILEMARKS 3L

    تعريفنوع بنية پٽي_WRITE_MARKS {
      DWORD Type;
      DWORD ڳڻپ_3;
      BOOLEAN فوري_2;
    } پٽي_WRITE_MARKS_2,*PTAPE_WRITE_MARKS;

#وصف_ڪريو پٽي_ABSOLUTE_POSITION 0L
#وصف_ڪريو پٽي_LOGICAL_POSITION 1L
#وصف_ڪريو پٽي_PSEUDO_LOGICAL_POSITION 2L

    تعريفنوع بنية پٽي_GET_POSITION {
      DWORD Type;
      DWORD حصا_ڪريو_2;
      LARGE_INTEGER وٿي_3;
    } پٽي_GET_POSITION_2,*PTAPE_GET_POSITION;

#وصف_ڪريو پٽي_REWIND 0L
#وصف_ڪريو پٽي_ABSOLUTE_بلاڪ 1L
#وصف_ڪريو پٽي_LOGICAL_بلاڪ 2L
#وصف_ڪريو پٽي_PSEUDO_LOGICAL_بلاڪ 3L
#وصف_ڪريو پٽي_SPACE_پڇاڙي_جو_معلومات 4L
#وصف_ڪريو پٽي_SPACE_RELATIVE_بلاڪون 5L
#وصف_ڪريو پٽي_SPACE_FILEMARKS 6L
#وصف_ڪريو پٽي_SPACE_SEQUENTIAL_FMKS 7L
#وصف_ڪريو پٽي_SPACE_SETMARKS 8L
#وصف_ڪريو پٽي_SPACE_SEQUENTIAL_SMKS 9L

    تعريفنوع بنية پٽي_سيٽ_POSITION {
      DWORD طريقو_2;
      DWORD حصا_ڪريو_2;
      LARGE_INTEGER وٿي_3;
      BOOLEAN فوري_2;
    } پٽي_سيٽ_POSITION_2,*PTAPE_سيٽ_POSITION;

#وصف_ڪريو پٽي_DRIVE_FIXED 0x00000001
#وصف_ڪريو پٽي_DRIVE_SELECT 0x00000002
#وصف_ڪريو پٽي_DRIVE_INITIATOR 0x00000004

#وصف_ڪريو پٽي_DRIVE_ERASE_SHORT 0x00000010
#وصف_ڪريو پٽي_DRIVE_ERASE_LONG 0x00000020
#وصف_ڪريو پٽي_DRIVE_ERASE_BOP_ONLY 0x00000040
#وصف_ڪريو پٽي_DRIVE_ERASE_فوري 0x00000080

#وصف_ڪريو پٽي_DRIVE_پٽي_صلاحيت 0x00000100
#وصف_ڪريو پٽي_DRIVE_پٽي_بچيل 0x00000200
#وصف_ڪريو پٽي_DRIVE_FIXED_بلاڪ 0x00000400
#وصف_ڪريو پٽي_DRIVE_VARIABLE_بلاڪ 0x00000800

#وصف_ڪريو پٽي_DRIVE_WRITE_PROTECT 0x00001000
#وصف_ڪريو پٽي_DRIVE_EOT_WZ_سائيز 0x00002000

#وصف_ڪريو پٽي_DRIVE_ECC 0x00010000
#وصف_ڪريو پٽي_DRIVE_COMPRESSION 0x00020000
#وصف_ڪريو پٽي_DRIVE_PADDING 0x00040000
#وصف_ڪريو پٽي_DRIVE_REPORT_SMKS 0x00080000

#وصف_ڪريو پٽي_DRIVE_GET_ABSOLUTE_BLK 0x00100000
#وصف_ڪريو پٽي_DRIVE_GET_LOGICAL_BLK 0x00200000
#وصف_ڪريو پٽي_DRIVE_سيٽ_EOT_WZ_سائيز 0x00400000

#وصف_ڪريو پٽي_DRIVE_EJECT_MEDIA 0x01000000
#وصف_ڪريو پٽي_DRIVE_CLEAN_درخواستون 0x02000000
#وصف_ڪريو پٽي_DRIVE_سيٽ_CMP_BOP_ONLY 0x04000000

#وصف_ڪريو پٽي_DRIVE_RESERVED_ٻٽو_انگ 0x80000000

#وصف_ڪريو پٽي_DRIVE_ڀريو_UNLOAD 0x80000001
#وصف_ڪريو پٽي_DRIVE_TENSION 0x80000002
#وصف_ڪريو پٽي_DRIVE_تالو_UNLOCK 0x80000004
#وصف_ڪريو پٽي_DRIVE_REWIND_فوري 0x80000008

#وصف_ڪريو پٽي_DRIVE_سيٽ_بلاڪ_سائيز 0x80000010
#وصف_ڪريو پٽي_DRIVE_ڀريو_UNLD_IMMED 0x80000020
#وصف_ڪريو پٽي_DRIVE_TENSION_IMMED 0x80000040
#وصف_ڪريو پٽي_DRIVE_تالو_UNLK_IMMED 0x80000080

#وصف_ڪريو پٽي_DRIVE_سيٽ_ECC 0x80000100
#وصف_ڪريو پٽي_DRIVE_سيٽ_COMPRESSION 0x80000200
#وصف_ڪريو پٽي_DRIVE_سيٽ_PADDING 0x80000400
#وصف_ڪريو پٽي_DRIVE_سيٽ_REPORT_SMKS 0x80000800

#وصف_ڪريو پٽي_DRIVE_ABSOLUTE_BLK 0x80001000
#وصف_ڪريو پٽي_DRIVE_ABS_BLK_IMMED 0x80002000
#وصف_ڪريو پٽي_DRIVE_LOGICAL_BLK 0x80004000
#وصف_ڪريو پٽي_DRIVE_LOG_BLK_IMMED 0x80008000

#وصف_ڪريو پٽي_DRIVE_پڇاڙي_جو_معلومات 0x80010000
#وصف_ڪريو پٽي_DRIVE_RELATIVE_BLKS 0x80020000
#وصف_ڪريو پٽي_DRIVE_FILEMARKS 0x80040000
#وصف_ڪريو پٽي_DRIVE_SEQUENTIAL_FMKS 0x80080000

#وصف_ڪريو پٽي_DRIVE_SETMARKS 0x80100000
#وصف_ڪريو پٽي_DRIVE_SEQUENTIAL_SMKS 0x80200000
#وصف_ڪريو پٽي_DRIVE_ابتو_POSITION 0x80400000
#وصف_ڪريو پٽي_DRIVE_SPACE_فوري 0x80800000

#وصف_ڪريو پٽي_DRIVE_WRITE_SETMARKS 0x81000000
#وصف_ڪريو پٽي_DRIVE_WRITE_FILEMARKS 0x82000000
#وصف_ڪريو پٽي_DRIVE_WRITE_SHORT_FMKS 0x84000000
#وصف_ڪريو پٽي_DRIVE_WRITE_LONG_FMKS 0x88000000

#وصف_ڪريو پٽي_DRIVE_WRITE_MARK_IMMED 0x90000000
#وصف_ڪريو پٽي_DRIVE_FORMAT 0xA0000000
#وصف_ڪريو پٽي_DRIVE_FORMAT_فوري 0xC0000000
#وصف_ڪريو پٽي_DRIVE_مٿاهون_FEATURES 0x80000000

    تعريفنوع بنية پٽي_GET_DRIVE_PARAMETERS {
      BOOLEAN ECC;
      BOOLEAN Compression;
      BOOLEAN معلومات_Padding;
      BOOLEAN ReportSetmarks;
      DWORD Default_بلاڪ_سائيز;
      DWORD وڌ_کان_وڌ_بلاڪ_سائيز;
      DWORD Minimum_بلاڪ_سائيز;
      DWORD وڌ_کان_وڌ_حصا_ڪريو_ڳڻپ;
      DWORD Features_هيٺيون;
      DWORD Features_مٿاهون;
      DWORD EOTWarning_Zone_سائيز;
    } پٽي_GET_DRIVE_PARAMETERS_2,*PTAPE_GET_DRIVE_PARAMETERS;

    تعريفنوع بنية پٽي_سيٽ_DRIVE_PARAMETERS {
      BOOLEAN ECC;
      BOOLEAN Compression;
      BOOLEAN معلومات_Padding;
      BOOLEAN ReportSetmarks;
      DWORD EOTWarning_Zone_سائيز;
    } پٽي_سيٽ_DRIVE_PARAMETERS_2,*PTAPE_سيٽ_DRIVE_PARAMETERS;

    تعريفنوع بنية پٽي_GET_MEDIA_PARAMETERS {
      LARGE_INTEGER صلاحيت;
      LARGE_INTEGER بچيل;
      DWORD بلاڪ_سائيز;
      DWORD حصا_ڪريو_ڳڻپ;
      BOOLEAN WriteProtected;
    } پٽي_GET_MEDIA_PARAMETERS_2,*PTAPE_GET_MEDIA_PARAMETERS;

    تعريفنوع بنية پٽي_سيٽ_MEDIA_PARAMETERS {
      DWORD بلاڪ_سائيز;
    } پٽي_سيٽ_MEDIA_PARAMETERS_2,*PTAPE_سيٽ_MEDIA_PARAMETERS;

#وصف_ڪريو پٽي_FIXED_PARTITIONS 0L
#وصف_ڪريو پٽي_SELECT_PARTITIONS 1L
#وصف_ڪريو پٽي_INITIATOR_PARTITIONS 2L

    تعريفنوع بنية پٽي_CREATE_حصا_ڪريو {
      DWORD طريقو_2;
      DWORD ڳڻپ_3;
      DWORD سائيز_3;
    } پٽي_CREATE_حصا_ڪريو_2,*PTAPE_CREATE_حصا_ڪريو;

#وصف_ڪريو پٽي_QUERY_DRIVE_PARAMETERS 0L
#وصف_ڪريو پٽي_QUERY_MEDIA_صلاحيت 1L
#وصف_ڪريو پٽي_CHECK_FOR_DRIVE_PROBLEM 2L
#وصف_ڪريو پٽي_QUERY_IO_ERROR_معلومات 3L
#وصف_ڪريو پٽي_QUERY_DEVICE_ERROR_معلومات 4L

    تعريفنوع بنية پٽي_WMI_OPERATIONS {
      DWORD طريقو_2;
      DWORD معلومات_بفر_سائيز;
      PVOID معلومات_بفر;
    } پٽي_WMI_OPERATIONS_2,*PTAPE_WMI_OPERATIONS;

    تعريفنوع تعداد پٽي_DRIVE_PROBLEM_TYPE {
      پٽي_Drive_Problem_None,پٽي_Drive_Read_Write_Warning,پٽي_Drive_Read_Write_Error,پٽي_Drive_Read_Warning,پٽي_Drive_Write_Warning,پٽي_Drive_Read_Error,پٽي_Drive_Write_Error,پٽي_Drive_Hardware_Error,پٽي_Drive_Unsupported_Media,پٽي_Drive_Scsi_Connection_Error,پٽي_Drive_Timeto_Clean,پٽي_Drive_Clean_Drive_Now,پٽي_Drive_Media_Life_Expired,پٽي_Drive_Snapped_پٽي
    } پٽي_DRIVE_PROBLEM_TYPE_2;

#إذا defined(__x86_64)
    __CRT_INLINE بنية _TEB *NtCurrentTeb(VOID) { أرجع (بنية _TEB *)__readgsqword(ميدان_وٿي(NT_TIB,Self)); }
    __CRT_INLINE PVOID GetCurrentFiber(VOID) { أرجع(PVOID)__readgsqword(ميدان_وٿي(NT_TIB,Fiber_معلومات)); }
    __CRT_INLINE PVOID Get_Fiber_معلومات(VOID) {
      أرجع *(PVOID *)GetCurrentFiber();
    }
#جيڪڏهن_پورو

#إذا(defined(_X86_) && !defined(__x86_64))
#وصف_ڪريو PcTeb 0x18
    __CRT_INLINE بنية _TEB *NtCurrentTeb(فراغ) {
      بنية _TEB *ret;
      __asm__ متطاير ("movl	%%fs:0x18,%0"
	: "=r" (ret));
      أرجع ret;
    }
#جيڪڏهن_پورو

#وصف_ڪريو ACTIVATION_CONTEXT_SECTION_ASSEMBLY_INFORMATION (1)
#وصف_ڪريو ACTIVATION_CONTEXT_SECTION_DLL_REDIRECTION (2)
#وصف_ڪريو ACTIVATION_CONTEXT_SECTION_دري_CLASS_REDIRECTION (3)
#وصف_ڪريو ACTIVATION_CONTEXT_SECTION_COM_SERVER_REDIRECTION (4)
#وصف_ڪريو ACTIVATION_CONTEXT_SECTION_COM_INTERFACE_REDIRECTION (5)
#وصف_ڪريو ACTIVATION_CONTEXT_SECTION_COM_TYPE_LIBRARY_REDIRECTION (6)
#وصف_ڪريو ACTIVATION_CONTEXT_SECTION_COM_PROGID_REDIRECTION (7)
#وصف_ڪريو ACTIVATION_CONTEXT_SECTION_GLOBAL_OBJECT_RENAME_جدول (8)
#وصف_ڪريو ACTIVATION_CONTEXT_SECTION_CLR_SURROGATES (9)
#وصف_ڪريو ACTIVATION_CONTEXT_SECTION_APPLICATION_SETTINGS (10)

#جيڪڏهن_وصف_ٿيل __cplusplus
  }
#جيڪڏهن_پورو
#جيڪڏهن_پورو
