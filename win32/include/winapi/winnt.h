/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_غیر_تعریف_شدہ _WINNT_
#تعریف_کرو _WINNT_

#اگر_تعریف_شدہ __cplusplus
خارجی "C" {
#اگر_ختم

#شامل <ctype.h>
#تعریف_کرو ANYSIZE_ARRAY 1

//gr #include <specstrings.h>

#تعریف_کرو RESTRICTED_اشارہ_گر

#اگر_غیر_تعریف_شدہ __CRT_UNALIGNED
#تعریف_کرو __CRT_UNALIGNED
#اگر_ختم

#اگر defined(__ia64__) || defined(__x86_64) || defined(__aarch64__)
#تعریف_کرو UNALIGNED __CRT_UNALIGNED
#اگر_تعریف_شدہ _WIN64
#تعریف_کرو UNALIGNED64 __CRT_UNALIGNED
#ورنہ
#تعریف_کرو UNALIGNED64
#اگر_ختم
#ورنہ
#تعریف_کرو UNALIGNED
#تعریف_کرو UNALIGNED64
#اگر_ختم

#اگر !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && (defined(_X86_) && !defined(__x86_64))
#تعریف_کرو I_X86_
#اگر_ختم

#اگر !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && defined(__x86_64)
#تعریف_کرو _AMD64_
#اگر_ختم

#اگر !defined(I_X86_) && !(defined(_X86_) && !defined(__x86_64)) && !defined(_AMD64_) && defined(__ia64__)
#اگر !defined(_IA64_)
#تعریف_کرو _IA64_
#اگر_ختم
#اگر_ختم


#اگر_تعریف_شدہ _WIN64
#تعریف_کرو MAX_NATURAL_ALIGNMENT حجم(ULONGLONG)
#تعریف_کرو حافظہ_تخصیص_ALIGNMENT 16
#ورنہ
#تعریف_کرو MAX_NATURAL_ALIGNMENT حجم(DWORD)
#تعریف_کرو حافظہ_تخصیص_ALIGNMENT 8
#اگر_ختم

#اگر_تعریف_شدہ __cplusplus
#تعریف_کرو TYPE_ALIGNMENT(t) __alignof__ (t)
#ورنہ
#تعریف_کرو TYPE_ALIGNMENT(t) میدان_انحراف(ساخت { حرف x; t test; },test)
#اگر_ختم

#اگر_تعریف_شدہ _WIN64
#اگر_تعریف_شدہ _AMD64_
#تعریف_کرو PROBE_ALIGNMENT(_s) TYPE_ALIGNMENT(DWORD)
#وگرنہ_اگر defined(_IA64_) || defined(_ARM64_)
#تعریف_کرو PROBE_ALIGNMENT(_s) (TYPE_ALIGNMENT(_s) > TYPE_ALIGNMENT(DWORD) ? TYPE_ALIGNMENT(_s) : TYPE_ALIGNMENT(DWORD))
#ورنہ
#غلطی No ہدف_2 Architecture
#اگر_ختم
#تعریف_کرو PROBE_ALIGNMENT32(_s) TYPE_ALIGNMENT(DWORD)
#ورنہ
#تعریف_کرو PROBE_ALIGNMENT(_s) TYPE_ALIGNMENT(DWORD)
#اگر_ختم

#تعریف_کرو C_ASSERT(e) قسمتعریف حرف __C_ASSERT__[(e)?1:-1]

#شامل <basetsd.h>

#اگر defined(_X86_) || defined(__ia64__) || defined(__x86_64) || defined(__aarch64__)
#تعریف_کرو DECLSPEC_IMPORT __declspec(dllimport)
#ورنہ
#تعریف_کرو DECLSPEC_IMPORT
#اگر_ختم

#اگر_غیر_تعریف_شدہ DECLSPEC_NORETURN
#تعریف_کرو DECLSPEC_NORETURN __declspec(noreturn)
#اگر_ختم

#اگر_غیر_تعریف_شدہ DECLSPEC_ALIGN
#تعریف_کرو DECLSPEC_ALIGN(x) __attribute__ ((aligned(x)))
#اگر_ختم

#اگر_غیر_تعریف_شدہ SYSTEM_CACHE_ALIGNMENT_سائز
#اگر defined(_AMD64_) || defined(I_X86_)
#تعریف_کرو SYSTEM_CACHE_ALIGNMENT_سائز 64
#ورنہ
#تعریف_کرو SYSTEM_CACHE_ALIGNMENT_سائز 128
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ DECLSPEC_CACHEALIGN
#تعریف_کرو DECLSPEC_CACHEALIGN DECLSPEC_ALIGN(SYSTEM_CACHE_ALIGNMENT_سائز)
#اگر_ختم

#اگر_غیر_تعریف_شدہ DECLSPEC_UUID
#تعریف_کرو DECLSPEC_UUID(x)
#اگر_ختم

#اگر_غیر_تعریف_شدہ DECLSPEC_NOVTABLE
#تعریف_کرو DECLSPEC_NOVTABLE
#اگر_ختم

#اگر_غیر_تعریف_شدہ DECLSPEC_SELECTANY
#تعریف_کرو DECLSPEC_SELECTANY __declspec(selectany)
#اگر_ختم

#اگر_غیر_تعریف_شدہ NOP_FUNCTION
#تعریف_کرو NOP_FUNCTION (خالی)0
#اگر_ختم

#اگر_غیر_تعریف_شدہ DECLSPEC_NOINLINE
#تعریف_کرو DECLSPEC_NOINLINE
#اگر_ختم

#اگر_غیر_تعریف_شدہ FORCEINLINE
#تعریف_کرو FORCEINLINE ساکن __inline__
#اگر_ختم

#اگر_غیر_تعریف_شدہ DECLSPEC_DEPRECATED
#تعریف_کرو DECLSPEC_DEPRECATED __declspec(deprecated)
#تعریف_کرو DEPRECATE_SUPPORTED
#اگر_ختم

#تعریف_کرو DECLSPEC_DEPRECATED_DDK
#تعریف_کرو PRAGMA_DEPRECATED_DDK 0

  قسمتعریف خالی *PVOID;
  قسمتعریف خالی *PVOID64;

#تعریف_کرو NTAPI __stdcall
#تعریف_کرو NTSYSAPI DECLSPEC_IMPORT
#تعریف_کرو NTSYSCALLAPI DECLSPEC_IMPORT

#اگر_غیر_تعریف_شدہ VOID
#تعریف_کرو VOID خالی
  قسمتعریف حرف CHAR;
  قسمتعریف مختصر SHORT;
  قسمتعریف طویل LONG;
#اگر_ختم

  قسمتعریف wchar_t WCHAR;
  قسمتعریف WCHAR *PWCHAR,*LPWCH,*PWCH;
  قسمتعریف CONST WCHAR *LPCWCH,*PCWCH;
  قسمتعریف WCHAR *NWPSTR,*LPWSTR,*PWSTR;
  قسمتعریف PWSTR *PZPWSTR;
  قسمتعریف CONST PWSTR *PCZPWSTR;
  قسمتعریف WCHAR UNALIGNED *LPUWSTR,*PUWSTR;
  قسمتعریف CONST WCHAR *LPCWSTR,*PCWSTR;
  قسمتعریف PCWSTR *PZPCWSTR;
  قسمتعریف CONST WCHAR UNALIGNED *LPCUWSTR,*PCUWSTR;
  قسمتعریف CHAR *PCHAR,*LPCH,*PCH;
  قسمتعریف CONST CHAR *LPCCH,*PCCH;
  قسمتعریف CHAR *NPSTR,*LPSTR,*PSTR;
  قسمتعریف PSTR *PZPSTR;
  قسمتعریف CONST PSTR *PCZPSTR;
  قسمتعریف CONST CHAR *LPCSTR,*PCSTR;
  قسمتعریف PCSTR *PZPCSTR;

#اگر_تعریف_شدہ UNICODE
#اگر_غیر_تعریف_شدہ _TCHAR_DEFINED
#تعریف_کرو _TCHAR_DEFINED
  قسمتعریف WCHAR TCHAR,*PTCHAR;
  قسمتعریف WCHAR TBYTE ,*PTBYTE;
#اگر_ختم

  قسمتعریف LPWSTR LPTCH,PTCH;
  قسمتعریف LPWSTR PTSTR,LPTSTR;
  قسمتعریف LPCWSTR PCTSTR,LPCTSTR;
  قسمتعریف LPUWSTR PUTSTR,LPUTSTR;
  قسمتعریف LPCUWSTR PCUTSTR,LPCUTSTR;
  قسمتعریف LPWSTR LP;
#تعریف_کرو __TEXT(quote) L##quote
#ورنہ
#اگر_غیر_تعریف_شدہ _TCHAR_DEFINED
#تعریف_کرو _TCHAR_DEFINED
  قسمتعریف حرف TCHAR,*PTCHAR;
  قسمتعریف غیرعلامتی حرف TBYTE ,*PTBYTE;
#اگر_ختم

  قسمتعریف LPSTR LPTCH,PTCH;
  قسمتعریف LPSTR PTSTR,LPTSTR,PUTSTR,LPUTSTR;
  قسمتعریف LPCSTR PCTSTR,LPCTSTR,PCUTSTR,LPCUTSTR;
#تعریف_کرو __TEXT(quote) quote
#اگر_ختم

#تعریف_کرو متن_3(quote) __TEXT(quote)

  قسمتعریف SHORT *PSHORT;
  قسمتعریف LONG *PLONG;

  قسمتعریف خالی *HANDLE;
#تعریف_کرو DECLARE_HANDLE(name) ساخت name##__ { صحیح غیر_مستعمل; }; قسمتعریف ساخت name##__ *name
  قسمتعریف HANDLE *PHANDLE;

  قسمتعریف BYTE FCHAR;
  قسمتعریف لفظ_3 FSHORT;
  قسمتعریف DWORD FLONG;

#اگر_غیر_تعریف_شدہ _HRESULT_DEFINED
#تعریف_کرو _HRESULT_DEFINED
  قسمتعریف LONG HRESULT;
#اگر_ختم

#اگر_تعریف_شدہ __cplusplus
#تعریف_کرو EXTERN_C خارجی "C"
#ورنہ
#تعریف_کرو EXTERN_C خارجی
#اگر_ختم

#تعریف_کرو STDMETHODCALLTYPE WINAPI
#تعریف_کرو STDMETHODVCALLTYPE __cdecl
#تعریف_کرو STDAPICALLTYPE WINAPI
#تعریف_کرو STDAPIVCALLTYPE __cdecl
#تعریف_کرو STDAPI EXTERN_C HRESULT WINAPI
#تعریف_کرو STDAPI_(type) EXTERN_C type WINAPI
#تعریف_کرو STDMETHODIMP HRESULT WINAPI
#تعریف_کرو STDMETHODIMP_(type) type WINAPI
#تعریف_کرو STDAPIV EXTERN_C HRESULT STDAPIVCALLTYPE
#تعریف_کرو STDAPIV_(type) EXTERN_C type STDAPIVCALLTYPE
#تعریف_کرو STDMETHODIMPV HRESULT STDMETHODVCALLTYPE
#تعریف_کرو STDMETHODIMPV_(type) type STDMETHODVCALLTYPE

  قسمتعریف حرف CCHAR;
#اگر_غیر_تعریف_شدہ _LCID_DEFINED
#تعریف_کرو _LCID_DEFINED
قسمتعریف DWORD LCID;
#اگر_ختم
  قسمتعریف PDWORD PLCID;
#اگر_غیر_تعریف_شدہ _LANGID_DEFINED
#تعریف_کرو _LANGID_DEFINED
  قسمتعریف لفظ_3 LANGID;
#اگر_ختم
#تعریف_کرو APPLICATION_ERROR_نقاب 0x20000000
#تعریف_کرو ERROR_SEVERITY_SUCCESS 0x00000000
#تعریف_کرو ERROR_SEVERITY_INFORMATIONAL 0x40000000
#تعریف_کرو ERROR_SEVERITY_WARNING 0x80000000
#تعریف_کرو ERROR_SEVERITY_ERROR 0xC0000000

#اگر_تعریف_شدہ __ia64__
  __declspec(align(16))
#اگر_ختم
    قسمتعریف ساخت _FLOAT128 {
      __int64 کم_Part;
      __int64 بلند_Part;
  } FLOAT128;

  قسمتعریف FLOAT128 *PFLOAT128;

#تعریف_کرو _ULONGLONG_
#اگر((!(defined(_X86_) && !defined(__x86_64)) || (defined(INTEGRAL_MAX_بٹ) && INTEGRAL_MAX_بٹ >= 64)))
  قسمتعریف __int64 LONGLONG;
  قسمتعریف غیرعلامتی __int64 ULONGLONG;

#تعریف_کرو MAXLONGLONG (0x7fffffffffffffff)
#ورنہ

  قسمتعریف دوہرا LONGLONG;
  قسمتعریف دوہرا ULONGLONG;
#اگر_ختم

  قسمتعریف LONGLONG *PLONGLONG;
  قسمتعریف ULONGLONG *PULONGLONG;

  قسمتعریف LONGLONG USN;

  قسمتعریف اتحاد _LARGE_INTEGER {
    ساخت {
      DWORD کم_Part;
      LONG بلند_Part;
    };
    ساخت {
      DWORD کم_Part;
      LONG بلند_Part;
    } u;
    LONGLONG QuadPart;
  } LARGE_INTEGER;

  قسمتعریف LARGE_INTEGER *PLARGE_INTEGER;

  قسمتعریف اتحاد _ULARGE_INTEGER {
    ساخت {
      DWORD کم_Part;
      DWORD بلند_Part;
    };
    ساخت {
      DWORD کم_Part;
      DWORD بلند_Part;
    } u;
    ULONGLONG QuadPart;
  } ULARGE_INTEGER;

  قسمتعریف ULARGE_INTEGER *PULARGE_INTEGER;

  قسمتعریف ساخت _LUID {
    DWORD کم_Part;
    LONG بلند_Part;
  } LUID,*PLUID;

#تعریف_کرو _DWORDLONG_
  قسمتعریف ULONGLONG DWORDLONG;
  قسمتعریف DWORDLONG *PDWORDLONG;

#اگر_تعریف_شدہ RC_INVOKED
#تعریف_کرو Int32x32To64(a,b) ((LONGLONG)((LONG)(a)) *(LONGLONG)((LONG)(b)))
#تعریف_کرو UInt32x32To64(a,b) ((ULONGLONG)((DWORD)(a)) *(ULONGLONG)((DWORD)(b)))
#تعریف_کرو Int64ShrlMod32(a,b) ((ULONGLONG)(a) >> (b))
#وگرنہ_اگر (defined(_X86_) && !defined(__x86_64))
#تعریف_کرو Int32x32To64(a,b) (LONGLONG)((LONGLONG)(LONG)(a) *(LONG)(b))
#تعریف_کرو UInt32x32To64(a,b) (ULONGLONG)((ULONGLONG)(DWORD)(a) *(DWORD)(b))
#تعریف_کرو Int64ShrlMod32(a,b) ((DWORDLONG)(a)>>(b))
#وگرنہ_اگر defined(__ia64__) || defined(__x86_64) || defined(__aarch64__)
#تعریف_کرو Int32x32To64(a,b) ((LONGLONG)((LONG)(a)) *(LONGLONG)((LONG)(b)))
#تعریف_کرو UInt32x32To64(a,b) ((ULONGLONG)((DWORD)(a)) *(ULONGLONG)((DWORD)(b)))
#تعریف_کرو Int64ShrlMod32(a,b) ((ULONGLONG)(a) >> (b))
#ورنہ
#غلطی Must define a ہدف architecture.
#اگر_ختم

#تعریف_کرو Int64ShraMod32(a,b) ((LONGLONG)(a) >> (b))
#تعریف_کرو Int64ShllMod32(a,b) ((ULONGLONG)(a) << (b))

#اگر_تعریف_شدہ __cplusplus
  خارجی "C" {
#اگر_ختم

#اگر_تعریف_شدہ __x86_64

#تعریف_کرو RotateLeft8 _rotl8
#تعریف_کرو RotateLeft16 _rotl16
#تعریف_کرو RotateRight8 _rotr8
#تعریف_کرو RotateRight16 _rotr16

    غیرعلامتی حرف __cdecl _rotl8(غیرعلامتی حرف قدر_3,غیرعلامتی حرف سرکاؤ_3);
    غیرعلامتی مختصر __cdecl _rotl16(غیرعلامتی مختصر قدر_3,غیرعلامتی حرف سرکاؤ_3);
    غیرعلامتی حرف __cdecl _rotr8(غیرعلامتی حرف قدر_3,غیرعلامتی حرف سرکاؤ_3);
    غیرعلامتی مختصر __cdecl _rotr16(غیرعلامتی مختصر قدر_3,غیرعلامتی حرف سرکاؤ_3);
#اگر_ختم

#تعریف_کرو RotateLeft32 _rotl
#تعریف_کرو RotateLeft64 _rotl64
#تعریف_کرو RotateRight32 _rotr
#تعریف_کرو RotateRight64 _rotr64

    غیرعلامتی صحیح __cdecl _rotl(غیرعلامتی صحیح قدر_3,صحیح سرکاؤ_3);
    غیرعلامتی __int64 __cdecl _rotl64(غیرعلامتی __int64 قدر_3,صحیح سرکاؤ_3);
    غیرعلامتی صحیح __cdecl _rotr(غیرعلامتی صحیح قدر_3,صحیح سرکاؤ_3);
    غیرعلامتی __int64 __cdecl _rotr64(غیرعلامتی __int64 قدر_3,صحیح سرکاؤ_3);
#اگر_تعریف_شدہ __cplusplus
  }
#اگر_ختم

#تعریف_کرو ANSI_NULL ((CHAR)0)
#تعریف_کرو UNICODE_NULL ((WCHAR)0)
#تعریف_کرو UNICODE_STRING_MAX_بائٹیں ((لفظ_3) 65534)
#تعریف_کرو UNICODE_STRING_MAX_CHARS (32767)

#اگر_غیر_تعریف_شدہ _BOOLEAN_
#تعریف_کرو _BOOLEAN_
  قسمتعریف BYTE BOOLEAN;
#اگر_ختم
  قسمتعریف BOOLEAN *PBOOLEAN;

  قسمتعریف ساخت LIST_اندراج {
    ساخت LIST_اندراج *Flink;
    ساخت LIST_اندراج *Blink;
  } LIST_اندراج_2,*PLIST_اندراج,*RESTRICTED_اشارہ_گر PRLIST_اندراج;

  قسمتعریف ساخت SINGLE_LIST_اندراج {
    ساخت SINGLE_LIST_اندراج *اگلا_2;
  } SINGLE_LIST_اندراج_2,*PSINGLE_LIST_اندراج;

  قسمتعریف ساخت LIST_ENTRY32 {
    DWORD Flink;
    DWORD Blink;
  } LIST_ENTRY32;
  قسمتعریف LIST_ENTRY32 *PLIST_ENTRY32;

  قسمتعریف ساخت LIST_ENTRY64 {
    ULONGLONG Flink;
    ULONGLONG Blink;
  } LIST_ENTRY64;
  قسمتعریف LIST_ENTRY64 *PLIST_ENTRY64;

#شامل <guiddef.h>

#اگر_غیر_تعریف_شدہ __OBJECTID_DEFINED
#تعریف_کرو __OBJECTID_DEFINED
  قسمتعریف ساخت _OBJECTID {
    GUID Lineage;
    DWORD Uniquifier;
  } OBJECTID;
#اگر_ختم

#تعریف_کرو MINCHAR 0x80
#تعریف_کرو MAXCHAR 0x7f
#تعریف_کرو MINSHORT 0x8000
#تعریف_کرو MAXSHORT 0x7fff
#تعریف_کرو MINLONG 0x80000000
#تعریف_کرو MAXLONG 0x7fffffff
#تعریف_کرو MAXBYTE 0xff
#تعریف_کرو MAXWORD 0xffff
#تعریف_کرو MAXDWORD 0xffffffff

#تعریف_کرو میدان_انحراف(type,میدان) ((LONG)(LONG_PTR)&(((type *)0)->میدان))
#تعریف_کرو RTL_میدان_سائز(type,میدان) (حجم(((type *)0)->میدان))
#تعریف_کرو RTL_SIZEOF_THROUGH_میدان(type,میدان) (میدان_انحراف(type,میدان) + RTL_میدان_سائز(type,میدان))
#تعریف_کرو RTL_شامل_ہے_میدان(Struct,سائز_3,میدان_2) ((((PCHAR)(&(Struct)->میدان_2)) + حجم((Struct)->میدان_2)) <= (((PCHAR)(Struct))+(سائز_3)))
#تعریف_کرو RTL_نمبر_کا_V1(A) (حجم(A)/حجم((A)[0]))
#تعریف_کرو RTL_نمبر_کا_V2(A) RTL_نمبر_کا_V1(A)

#اگر_تعریف_شدہ ENABLE_RTL_نمبر_کا_V2
#تعریف_کرو RTL_نمبر_کا(A) RTL_نمبر_کا_V2(A)
#ورنہ
#تعریف_کرو RTL_نمبر_کا(A) RTL_نمبر_کا_V1(A)
#اگر_ختم

#تعریف_کرو ARRAYSIZE(A) RTL_نمبر_کا_V2(A)
#تعریف_کرو _ARRAYSIZE(A) RTL_نمبر_کا_V1(A)

#تعریف_کرو RTL_میدان_TYPE(type,میدان) (((type*)0)->میدان)
#تعریف_کرو RTL_نمبر_کا_میدان(type,میدان) (RTL_نمبر_کا(RTL_میدان_TYPE(type,میدان)))
#تعریف_کرو RTL_PADDING_BETWEEN_FIELDS(T,F1,F2) ((میدان_انحراف(T,F2) > میدان_انحراف(T,F1)) ? (میدان_انحراف(T,F2) - میدان_انحراف(T,F1) - RTL_میدان_سائز(T,F1)) : (میدان_انحراف(T,F1) - میدان_انحراف(T,F2) - RTL_میدان_سائز(T,F2)))

#اگر_تعریف_شدہ __cplusplus
#تعریف_کرو RTL_CONST_CAST(type) const_cast<type>
#ورنہ
#تعریف_کرو RTL_CONST_CAST(type) (type)
#اگر_ختم

#تعریف_کرو RTL_بٹ_کا(سائز_کا_Arg) (حجم(سائز_کا_Arg) *8)
#تعریف_کرو RTL_بٹ_کا_میدان(type,میدان) (RTL_بٹ_کا(RTL_میدان_TYPE(type,میدان)))
#تعریف_کرو CONTAINING_ریکارڈ(پتہ,type,میدان) ((type *)((PCHAR)(پتہ) - (ULONG_PTR)(&((type *)0)->میدان)))

#تعریف_کرو VER_SERVER_NT 0x80000000
#تعریف_کرو VER_WORKSTATION_NT 0x40000000
#تعریف_کرو VER_SUITE_SMALLBUSINESS 0x00000001
#تعریف_کرو VER_SUITE_ENTERPRISE 0x00000002
#تعریف_کرو VER_SUITE_BACKOFFICE 0x00000004
#تعریف_کرو VER_SUITE_COMMUNICATIONS 0x00000008
#تعریف_کرو VER_SUITE_TERMINAL 0x00000010
#تعریف_کرو VER_SUITE_SMALLBUSINESS_RESTRICTED 0x00000020
#تعریف_کرو VER_SUITE_EMBEDDEDNT 0x00000040
#تعریف_کرو VER_SUITE_DATACENTER 0x00000080
#تعریف_کرو VER_SUITE_SINGLEUSERTS 0x00000100
#تعریف_کرو VER_SUITE_PERSONAL 0x00000200
#تعریف_کرو VER_SUITE_BLADE 0x00000400
#تعریف_کرو VER_SUITE_EMBEDDED_RESTRICTED 0x00000800
#تعریف_کرو VER_SUITE_SECURITY_APPLIANCE 0x00001000
#تعریف_کرو VER_SUITE_STORAGE_SERVER 0x00002000
#تعریف_کرو VER_SUITE_COMPUTE_SERVER 0x00004000

#تعریف_کرو حاصل_ضرب_UNDEFINED                       0x0

#تعریف_کرو حاصل_ضرب_ULTIMATE                        0x1
#تعریف_کرو حاصل_ضرب_HOME_BASIC                      0x2
#تعریف_کرو حاصل_ضرب_HOME_PREMIUM                    0x3
#تعریف_کرو حاصل_ضرب_ENTERPRISE                      0x4
#تعریف_کرو حاصل_ضرب_HOME_BASIC_N                    0x5
#تعریف_کرو حاصل_ضرب_BUSINESS                        0x6
#تعریف_کرو حاصل_ضرب_STANDARD_SERVER                 0x7
#تعریف_کرو حاصل_ضرب_DATACENTER_SERVER               0x8
#تعریف_کرو حاصل_ضرب_SMALLBUSINESS_SERVER            0x9
#تعریف_کرو حاصل_ضرب_ENTERPRISE_SERVER               0xa
#تعریف_کرو حاصل_ضرب_STARTER                         0xb
#تعریف_کرو حاصل_ضرب_DATACENTER_SERVER_CORE          0xc
#تعریف_کرو حاصل_ضرب_STANDARD_SERVER_CORE            0xd
#تعریف_کرو حاصل_ضرب_ENTERPRISE_SERVER_CORE          0xe
#تعریف_کرو حاصل_ضرب_ENTERPRISE_SERVER_IA64          0xf
#تعریف_کرو حاصل_ضرب_BUSINESS_N                      0x10
#تعریف_کرو حاصل_ضرب_WEB_SERVER                      0x11
#تعریف_کرو حاصل_ضرب_CLUSTER_SERVER                  0x12
#تعریف_کرو حاصل_ضرب_HOME_SERVER                     0x13
#تعریف_کرو حاصل_ضرب_STORAGE_EXPRESS_SERVER          0x14
#تعریف_کرو حاصل_ضرب_STORAGE_STANDARD_SERVER         0x15
#تعریف_کرو حاصل_ضرب_STORAGE_WORKGROUP_SERVER        0x16
#تعریف_کرو حاصل_ضرب_STORAGE_ENTERPRISE_SERVER       0x17
#تعریف_کرو حاصل_ضرب_SERVER_FOR_SMALLBUSINESS        0x18
#تعریف_کرو حاصل_ضرب_SMALLBUSINESS_SERVER_PREMIUM    0x19

#تعریف_کرو حاصل_ضرب_UNLICENSED                      0xabcdabcd

#تعریف_کرو LANG_NEUTRAL 0x00
#تعریف_کرو LANG_INVARIANT 0x7f

#تعریف_کرو LANG_AFRIKAANS 0x36
#تعریف_کرو LANG_ALBANIAN 0x1c
#تعریف_کرو LANG_ALSATIAN 0x84
#تعریف_کرو LANG_AMHARIC 0x5e
#تعریف_کرو LANG_ARABIC 0x01
#تعریف_کرو LANG_ARMENIAN 0x2b
#تعریف_کرو LANG_ASSAMESE 0x4d
#تعریف_کرو LANG_AZERI 0x2c
#تعریف_کرو LANG_BASHKIR 0x6d
#تعریف_کرو LANG_BASQUE 0x2d
#تعریف_کرو LANG_BELARUSIAN 0x23
#تعریف_کرو LANG_BENGALI 0x45
#تعریف_کرو LANG_BRETON 0x7e
#تعریف_کرو LANG_BOSNIAN 0x1a
#تعریف_کرو LANG_BOSNIAN_NEUTRAL 0x781a
#تعریف_کرو LANG_BULGARIAN 0x02
#تعریف_کرو LANG_کیٹالان 0x03
#تعریف_کرو LANG_CHINESE 0x04
#تعریف_کرو LANG_CHINESE_SIMPLIFIED 0x04
#تعریف_کرو LANG_CHINESE_TRADITIONAL 0x7c04
#تعریف_کرو LANG_CORSICAN 0x83
#تعریف_کرو LANG_CROATIAN 0x1a
#تعریف_کرو LANG_CZECH 0x05
#تعریف_کرو LANG_DANISH 0x06
#تعریف_کرو LANG_DARI 0x8c
#تعریف_کرو LANG_DIVEHI 0x65
#تعریف_کرو LANG_DUTCH 0x13
#تعریف_کرو LANG_ENGLISH 0x09
#تعریف_کرو LANG_ESTONIAN 0x25
#تعریف_کرو LANG_FAEROESE 0x38
#تعریف_کرو LANG_FARSI 0x29
#تعریف_کرو LANG_FILIPINO 0x64
#تعریف_کرو LANG_FINNISH 0x0b
#تعریف_کرو LANG_FRENCH 0x0c
#تعریف_کرو LANG_FRISIAN 0x62
#تعریف_کرو LANG_GALICIAN 0x56
#تعریف_کرو LANG_GEORGIAN 0x37
#تعریف_کرو LANG_GERMAN 0x07
#تعریف_کرو LANG_GREEK 0x08
#تعریف_کرو LANG_GREENLANDIC 0x6f
#تعریف_کرو LANG_GUJARATI 0x47
#تعریف_کرو LANG_HAUSA 0x68
#تعریف_کرو LANG_HEBREW 0x0d
#تعریف_کرو LANG_HINDI 0x39
#تعریف_کرو LANG_HUNGARIAN 0x0e
#تعریف_کرو LANG_ICELANDIC 0x0f
#تعریف_کرو LANG_IGBO 0x70
#تعریف_کرو LANG_INDONESIAN 0x21
#تعریف_کرو LANG_INUKTITUT 0x5d
#تعریف_کرو LANG_IRISH 0x3c
#تعریف_کرو LANG_ITALIAN 0x10
#تعریف_کرو LANG_JAPANESE 0x11
#تعریف_کرو LANG_KANNADA 0x4b
#تعریف_کرو LANG_KASHMIRI 0x60
#تعریف_کرو LANG_KAZAK 0x3f
#تعریف_کرو LANG_KHMER 0x53
#تعریف_کرو LANG_KICHE 0x86
#تعریف_کرو LANG_KINYARWANDA 0x87
#تعریف_کرو LANG_KONKANI 0x57
#تعریف_کرو LANG_KOREAN 0x12
#تعریف_کرو LANG_KYRGYZ 0x40
#تعریف_کرو LANG_LAO 0x54
#تعریف_کرو LANG_LATVIAN 0x26
#تعریف_کرو LANG_LITHUANIAN 0x27
#تعریف_کرو LANG_زیریں_SORBIAN 0x2e
#تعریف_کرو LANG_LUXEMBOURGISH 0x6e
#تعریف_کرو LANG_MACEDONIAN 0x2f
#تعریف_کرو LANG_MALAY 0x3e
#تعریف_کرو LANG_MALAYALAM 0x4c
#تعریف_کرو LANG_MALTESE 0x3a
#تعریف_کرو LANG_MANIPURI 0x58
#تعریف_کرو LANG_MAORI 0x81
#تعریف_کرو LANG_MAPUDUNGUN 0x7a
#تعریف_کرو LANG_MARATHI 0x4e
#تعریف_کرو LANG_MOHAWK 0x7c
#تعریف_کرو LANG_MONGOLIAN 0x50
#تعریف_کرو LANG_NEPALI 0x61
#تعریف_کرو LANG_NORWEGIAN 0x14
#تعریف_کرو LANG_OCCITAN 0x82
#تعریف_کرو LANG_ORIYA 0x48
#تعریف_کرو LANG_PASHTO 0x63
#تعریف_کرو LANG_PERSIAN 0x29
#تعریف_کرو LANG_POLISH 0x15
#تعریف_کرو LANG_PORTUGUESE 0x16
#تعریف_کرو LANG_PUNJABI 0x46
#تعریف_کرو LANG_QUECHUA 0x6b
#تعریف_کرو LANG_ROMANIAN 0x18
#تعریف_کرو LANG_RUSSIAN 0x19
#تعریف_کرو LANG_SAMI 0x3b
#تعریف_کرو LANG_ROMANSH 0x17
#تعریف_کرو LANG_SANSKRIT 0x4f
#تعریف_کرو LANG_SERBIAN 0x1a
#تعریف_کرو LANG_SERBIAN_NEUTRAL 0x7c1a
#تعریف_کرو LANG_SINDHI 0x59
#تعریف_کرو LANG_SINHALESE 0x5b
#تعریف_کرو LANG_SLOVAK 0x1b
#تعریف_کرو LANG_SLOVENIAN 0x24
#تعریف_کرو LANG_SOTHO 0x6c
#تعریف_کرو LANG_SPANISH 0x0a
#تعریف_کرو LANG_SWAHILI 0x41
#تعریف_کرو LANG_SWEDISH 0x1d
#تعریف_کرو LANG_SYRIAC 0x5a
#تعریف_کرو LANG_TAJIK 0x28
#تعریف_کرو LANG_TAMAZIGHT 0x5f
#تعریف_کرو LANG_TAMIL 0x49
#تعریف_کرو LANG_TATAR 0x44
#تعریف_کرو LANG_TELUGU 0x4a
#تعریف_کرو LANG_THAI 0x1e
#تعریف_کرو LANG_TIBETAN 0x51
#تعریف_کرو LANG_TIGRIGNA 0x73
#تعریف_کرو LANG_TSWANA 0x32
#تعریف_کرو LANG_TURKISH 0x1f
#تعریف_کرو LANG_TURKMEN 0x42
#تعریف_کرو LANG_UIGHUR 0x80
#تعریف_کرو LANG_UKRAINIAN 0x22
#تعریف_کرو LANG_بالائی_SORBIAN 0x2e
#تعریف_کرو LANG_URDU 0x20
#تعریف_کرو LANG_UZBEK 0x43
#تعریف_کرو LANG_VIETNAMESE 0x2a
#تعریف_کرو LANG_WELSH 0x52
#تعریف_کرو LANG_WOLOF 0x88
#تعریف_کرو LANG_XHOSA 0x34
#تعریف_کرو LANG_YAKUT 0x85
#تعریف_کرو LANG_YI 0x78
#تعریف_کرو LANG_YORUBA 0x6a
#تعریف_کرو LANG_ZULU 0x35

#تعریف_کرو SUBLANG_NEUTRAL 0x0
#تعریف_کرو SUBLANG_DEFAULT 0x1
#تعریف_کرو SUBLANG_SYS_DEFAULT 0x2
#تعریف_کرو SUBLANG_CUSTOM_DEFAULT 0x3
#تعریف_کرو SUBLANG_CUSTOM_UNSPECIFIED 0x4
#تعریف_کرو SUBLANG_UI_CUSTOM_DEFAULT 0x5

#تعریف_کرو SUBLANG_ARABIC_SAUDI_ARABIA 0x01
#تعریف_کرو SUBLANG_ARABIC_IRAQ 0x02
#تعریف_کرو SUBLANG_ARABIC_EGYPT 0x03
#تعریف_کرو SUBLANG_ARABIC_LIBYA 0x04
#تعریف_کرو SUBLANG_ARABIC_ALGERIA 0x05
#تعریف_کرو SUBLANG_ARABIC_MOROCCO 0x06
#تعریف_کرو SUBLANG_ARABIC_TUNISIA 0x07
#تعریف_کرو SUBLANG_ARABIC_OMAN 0x08
#تعریف_کرو SUBLANG_ARABIC_YEMEN 0x09
#تعریف_کرو SUBLANG_ARABIC_SYRIA 0x0a
#تعریف_کرو SUBLANG_ARABIC_JORDAN 0x0b
#تعریف_کرو SUBLANG_ARABIC_LEBANON 0x0c
#تعریف_کرو SUBLANG_ARABIC_KUWAIT 0x0d
#تعریف_کرو SUBLANG_ARABIC_UAE 0x0e
#تعریف_کرو SUBLANG_ARABIC_BAHRAIN 0x0f
#تعریف_کرو SUBLANG_ARABIC_QATAR 0x10
#تعریف_کرو SUBLANG_AZERI_LATIN 0x01
#تعریف_کرو SUBLANG_AZERI_CYRILLIC 0x02
#تعریف_کرو SUBLANG_CHINESE_TRADITIONAL 0x01
#تعریف_کرو SUBLANG_CHINESE_SIMPLIFIED 0x02
#تعریف_کرو SUBLANG_CHINESE_HONGKONG 0x03
#تعریف_کرو SUBLANG_CHINESE_SINGAPORE 0x04
#تعریف_کرو SUBLANG_CHINESE_MACAU 0x05
#تعریف_کرو SUBLANG_DUTCH 0x01
#تعریف_کرو SUBLANG_DUTCH_BELGIAN 0x02
#تعریف_کرو SUBLANG_ENGLISH_US 0x01
#تعریف_کرو SUBLANG_ENGLISH_UK 0x02
#تعریف_کرو SUBLANG_ENGLISH_AUS 0x03
#تعریف_کرو SUBLANG_ENGLISH_CAN 0x04
#تعریف_کرو SUBLANG_ENGLISH_NZ 0x05
#تعریف_کرو SUBLANG_ENGLISH_EIRE 0x06
#تعریف_کرو SUBLANG_ENGLISH_SOUTH_AFRICA 0x07
#تعریف_کرو SUBLANG_ENGLISH_JAMAICA 0x08
#تعریف_کرو SUBLANG_ENGLISH_CARIBBEAN 0x09
#تعریف_کرو SUBLANG_ENGLISH_BELIZE 0x0a
#تعریف_کرو SUBLANG_ENGLISH_TRINIDAD 0x0b
#تعریف_کرو SUBLANG_ENGLISH_ZIMBABWE 0x0c
#تعریف_کرو SUBLANG_ENGLISH_PHILIPPINES 0x0d
#تعریف_کرو SUBLANG_FRENCH 0x01
#تعریف_کرو SUBLANG_FRENCH_BELGIAN 0x02
#تعریف_کرو SUBLANG_FRENCH_CANADIAN 0x03
#تعریف_کرو SUBLANG_FRENCH_SWISS 0x04
#تعریف_کرو SUBLANG_FRENCH_LUXEMBOURG 0x05
#تعریف_کرو SUBLANG_FRENCH_MONACO 0x06
#تعریف_کرو SUBLANG_GERMAN 0x01
#تعریف_کرو SUBLANG_GERMAN_SWISS 0x02
#تعریف_کرو SUBLANG_GERMAN_AUSTRIAN 0x03
#تعریف_کرو SUBLANG_GERMAN_LUXEMBOURG 0x04
#تعریف_کرو SUBLANG_GERMAN_LIECHTENSTEIN 0x05
#تعریف_کرو SUBLANG_ITALIAN 0x01
#تعریف_کرو SUBLANG_ITALIAN_SWISS 0x02
#تعریف_کرو SUBLANG_KASHMIRI_SASIA 0x02
#تعریف_کرو SUBLANG_KASHMIRI_INDIA 0x02
#تعریف_کرو SUBLANG_KOREAN 0x01
#تعریف_کرو SUBLANG_LITHUANIAN 0x01
#تعریف_کرو SUBLANG_MALAY_MALAYSIA 0x01
#تعریف_کرو SUBLANG_MALAY_BRUNEI_DARUSSALAM 0x02
#تعریف_کرو SUBLANG_NEPALI_INDIA 0x02
#تعریف_کرو SUBLANG_NORWEGIAN_BOKMAL 0x01
#تعریف_کرو SUBLANG_NORWEGIAN_NYNORSK 0x02
#تعریف_کرو SUBLANG_PORTUGUESE 0x02
#تعریف_کرو SUBLANG_PORTUGUESE_BRAZILIAN 0x01
#تعریف_کرو SUBLANG_SERBIAN_LATIN 0x02
#تعریف_کرو SUBLANG_SERBIAN_CYRILLIC 0x03
#تعریف_کرو SUBLANG_SPANISH 0x01
#تعریف_کرو SUBLANG_SPANISH_MEXICAN 0x02
#تعریف_کرو SUBLANG_SPANISH_MODERN 0x03
#تعریف_کرو SUBLANG_SPANISH_GUATEMALA 0x04
#تعریف_کرو SUBLANG_SPANISH_COSTA_RICA 0x05
#تعریف_کرو SUBLANG_SPANISH_PANAMA 0x06
#تعریف_کرو SUBLANG_SPANISH_DOMINICAN_REPUBLIC 0x07
#تعریف_کرو SUBLANG_SPANISH_VENEZUELA 0x08
#تعریف_کرو SUBLANG_SPANISH_COLOMBIA 0x09
#تعریف_کرو SUBLANG_SPANISH_PERU 0x0a
#تعریف_کرو SUBLANG_SPANISH_ARGENTINA 0x0b
#تعریف_کرو SUBLANG_SPANISH_ECUADOR 0x0c
#تعریف_کرو SUBLANG_SPANISH_CHILE 0x0d
#تعریف_کرو SUBLANG_SPANISH_URUGUAY 0x0e
#تعریف_کرو SUBLANG_SPANISH_PARAGUAY 0x0f
#تعریف_کرو SUBLANG_SPANISH_BOLIVIA 0x10
#تعریف_کرو SUBLANG_SPANISH_EL_SALVADOR 0x11
#تعریف_کرو SUBLANG_SPANISH_HONDURAS 0x12
#تعریف_کرو SUBLANG_SPANISH_NICARAGUA 0x13
#تعریف_کرو SUBLANG_SPANISH_PUERTO_RICO 0x14
#تعریف_کرو SUBLANG_SWEDISH 0x01
#تعریف_کرو SUBLANG_SWEDISH_FINLAND 0x02
#تعریف_کرو SUBLANG_URDU_PAKISTAN 0x01
#تعریف_کرو SUBLANG_URDU_INDIA 0x02
#تعریف_کرو SUBLANG_UZBEK_LATIN 0x01
#تعریف_کرو SUBLANG_UZBEK_CYRILLIC 0x02

#تعریف_کرو ترتیب_دو_DEFAULT 0x0
#تعریف_کرو ترتیب_دو_INVARIANT_MATH 0x1

#تعریف_کرو ترتیب_دو_JAPANESE_XJIS 0x0
#تعریف_کرو ترتیب_دو_JAPANESE_UNICODE 0x1
#تعریف_کرو ترتیب_دو_JAPANESE_RADICALSTROKE 0x4

#تعریف_کرو ترتیب_دو_CHINESE_BIG5 0x0
#تعریف_کرو ترتیب_دو_CHINESE_PRCP 0x0
#تعریف_کرو ترتیب_دو_CHINESE_UNICODE 0x1
#تعریف_کرو ترتیب_دو_CHINESE_PRC 0x2
#تعریف_کرو ترتیب_دو_CHINESE_BOPOMOFO 0x3

#تعریف_کرو ترتیب_دو_KOREAN_KSC 0x0
#تعریف_کرو ترتیب_دو_KOREAN_UNICODE 0x1

#تعریف_کرو ترتیب_دو_GERMAN_PHONE_BOOK 0x1

#تعریف_کرو ترتیب_دو_HUNGARIAN_DEFAULT 0x0
#تعریف_کرو ترتیب_دو_HUNGARIAN_TECHNICAL 0x1

#تعریف_کرو ترتیب_دو_GEORGIAN_TRADITIONAL 0x0
#تعریف_کرو ترتیب_دو_GEORGIAN_MODERN 0x1

#تعریف_کرو MAKELANGID(p,s) ((((لفظ_3)(s)) << 10) | (لفظ_3)(p))
#تعریف_کرو PRIMARYLANGID(lgid) ((لفظ_3)(lgid) & 0x3ff)
#تعریف_کرو SUBLANGID(lgid) ((لفظ_3)(lgid) >> 10)

#تعریف_کرو NLS_VALID_LOCALE_نقاب 0x000fffff

#تعریف_کرو MAKELCID(lgid,srtid) ((DWORD)((((DWORD)((لفظ_3)(srtid))) << 16) | ((DWORD)((لفظ_3)(lgid)))))
#تعریف_کرو MAKESORTLCID(lgid,srtid,ver) ((DWORD)((MAKELCID(lgid,srtid)) | (((DWORD)((لفظ_3)(ver))) << 20)))
#تعریف_کرو LANGIDFROMLCID(lcid) ((لفظ_3)(lcid))
#تعریف_کرو SORTIDFROMLCID(lcid) ((لفظ_3)((((DWORD)(lcid)) >> 16) & 0xf))
#تعریف_کرو SORTVERSIONFROMLCID(lcid) ((لفظ_3)((((DWORD)(lcid)) >> 20) & 0xf))

#تعریف_کرو LOCALE_NAME_MAX_لمبائی 85
#تعریف_کرو LANG_SYSTEM_DEFAULT (MAKELANGID(LANG_NEUTRAL,SUBLANG_SYS_DEFAULT))
#تعریف_کرو LANG_USER_DEFAULT (MAKELANGID(LANG_NEUTRAL,SUBLANG_DEFAULT))

#تعریف_کرو LOCALE_SYSTEM_DEFAULT (MAKELCID(LANG_SYSTEM_DEFAULT,ترتیب_دو_DEFAULT))
#تعریف_کرو LOCALE_USER_DEFAULT (MAKELCID(LANG_USER_DEFAULT,ترتیب_دو_DEFAULT))

#تعریف_کرو LOCALE_NEUTRAL (MAKELCID(MAKELANGID(LANG_NEUTRAL,SUBLANG_NEUTRAL),ترتیب_دو_DEFAULT))

#تعریف_کرو LOCALE_CUSTOM_DEFAULT (MAKELCID(MAKELANGID(LANG_NEUTRAL, SUBLANG_CUSTOM_DEFAULT), ترتیب_دو_DEFAULT))
#تعریف_کرو LOCALE_CUSTOM_UNSPECIFIED (MAKELCID(MAKELANGID(LANG_NEUTRAL, SUBLANG_CUSTOM_UNSPECIFIED), ترتیب_دو_DEFAULT))
#تعریف_کرو LOCALE_CUSTOM_UI_DEFAULT (MAKELCID(MAKELANGID(LANG_NEUTRAL, SUBLANG_UI_CUSTOM_DEFAULT), ترتیب_دو_DEFAULT))

#تعریف_کرو LOCALE_INVARIANT (MAKELCID(MAKELANGID(LANG_INVARIANT,SUBLANG_NEUTRAL),ترتیب_دو_DEFAULT))

#تعریف_کرو UNREFERENCED_PARAMETER(P) (P)
#تعریف_کرو DBG_UNREFERENCED_PARAMETER(P) (P)
#تعریف_کرو DBG_UNREFERENCED_LOCAL_VARIABLE(V) (V)

#تعریف_کرو DEFAULT_UNREACHABLE

#اگر_غیر_تعریف_شدہ WIN32_NO_حالت
#تعریف_کرو حالت_WAIT_0 ((DWORD)0x00000000L)
#تعریف_کرو حالت_ABANDONED_WAIT_0 ((DWORD)0x00000080L)
#تعریف_کرو حالت_USER_APC ((DWORD)0x000000C0L)
#تعریف_کرو حالت_TIMEOUT ((DWORD)0x00000102L)
#تعریف_کرو حالت_PENDING ((DWORD)0x00000103L)
#تعریف_کرو DBG_EXCEPTION_HANDLED ((DWORD)0x00010001L)
#تعریف_کرو DBG_CONTINUE ((DWORD)0x00010002L)
#تعریف_کرو حالت_SEGMENT_NOTIFICATION ((DWORD)0x40000005L)
#تعریف_کرو DBG_TERMINATE_THREAD ((DWORD)0x40010003L)
#تعریف_کرو DBG_TERMINATE_PROCESS ((DWORD)0x40010004L)
#تعریف_کرو DBG_CONTROL_C ((DWORD)0x40010005L)
#تعریف_کرو DBG_CONTROL_BREAK ((DWORD)0x40010008L)
#تعریف_کرو DBG_COMMAND_EXCEPTION ((DWORD)0x40010009L)
#تعریف_کرو حالت_GUARD_صفحہ_VIOLATION ((DWORD)0x80000001L)
#تعریف_کرو حالت_DATATYPE_MISALIGNMENT ((DWORD)0x80000002L)
#تعریف_کرو حالت_BREAKPOINT ((DWORD)0x80000003L)
#تعریف_کرو حالت_SINGLE_قدم ((DWORD)0x80000004L)
#تعریف_کرو DBG_EXCEPTION_NOT_HANDLED ((DWORD)0x80010001L)
#تعریف_کرو حالت_ACCESS_VIOLATION ((DWORD)0xC0000005L)
#تعریف_کرو حالت_اندر_صفحہ_ERROR ((DWORD)0xC0000006L)
#تعریف_کرو حالت_INVALID_HANDLE ((DWORD)0xC0000008L)
#تعریف_کرو حالت_NO_حافظہ ((DWORD)0xC0000017L)
#تعریف_کرو حالت_ILLEGAL_INSTRUCTION ((DWORD)0xC000001DL)
#تعریف_کرو حالت_NONCONTINUABLE_EXCEPTION ((DWORD)0xC0000025L)
#تعریف_کرو حالت_INVALID_DISPOSITION ((DWORD)0xC0000026L)
#تعریف_کرو حالت_ARRAY_BOUNDS_EXCEEDED ((DWORD)0xC000008CL)
#تعریف_کرو حالت_FLOAT_DENORMAL_عملیہ ((DWORD)0xC000008DL)
#تعریف_کرو حالت_FLOAT_DIVIDE_BY_ZERO ((DWORD)0xC000008EL)
#تعریف_کرو حالت_FLOAT_INEXACT_نتیجہ ((DWORD)0xC000008FL)
#تعریف_کرو حالت_FLOAT_INVALID_OPERATION ((DWORD)0xC0000090L)
#تعریف_کرو حالت_FLOAT_حد_سے_تجاوز ((DWORD)0xC0000091L)
#تعریف_کرو حالت_FLOAT_ڈھیر_CHECK ((DWORD)0xC0000092L)
#تعریف_کرو حالت_FLOAT_UNDERFLOW ((DWORD)0xC0000093L)
#تعریف_کرو حالت_INTEGER_DIVIDE_BY_ZERO ((DWORD)0xC0000094L)
#تعریف_کرو حالت_INTEGER_حد_سے_تجاوز ((DWORD)0xC0000095L)
#تعریف_کرو حالت_PRIVILEGED_INSTRUCTION ((DWORD)0xC0000096L)
#تعریف_کرو حالت_ڈھیر_حد_سے_تجاوز ((DWORD)0xC00000FDL)
#تعریف_کرو حالت_CONTROL_C_EXIT ((DWORD)0xC000013AL)
#تعریف_کرو حالت_FLOAT_مضرب_خرابیاں ((DWORD)0xC00002B4L)
#تعریف_کرو حالت_FLOAT_مضرب_TRAPS ((DWORD)0xC00002B5L)
#تعریف_کرو حالت_REG_NAT_CONSUMPTION ((DWORD)0xC00002C9L)
#تعریف_کرو حالت_SXS_EARLY_DEACTIVATION ((DWORD)0xC015000FL)
#تعریف_کرو حالت_SXS_INVALID_DEACTIVATION ((DWORD)0xC0150010L)
#اگر_ختم

#تعریف_کرو زیادہ_سے_زیادہ_WAIT_OBJECTS 64
#تعریف_کرو زیادہ_سے_زیادہ_SUSPEND_گنتی MAXCHAR

  قسمتعریف ULONG_PTR KSPIN_تالا;
  قسمتعریف KSPIN_تالا *PKSPIN_تالا;

#اگر defined(__x86_64) && !defined(RC_INVOKED)

#اگر_تعریف_شدہ __cplusplus
  خارجی "C" {
#اگر_ختم

#تعریف_کرو ثنائی_ہندسہ_Test _bittest
#تعریف_کرو ثنائی_ہندسہ_Test_And_Complement _bittestandcomplement
#تعریف_کرو ثنائی_ہندسہ_Test_And_سیٹ _bittestandset
#تعریف_کرو ثنائی_ہندسہ_Test_And_Reset _bittestandreset
#تعریف_کرو Interlocked_ثنائی_ہندسہ_Test_And_سیٹ _interlockedbittestandset
#تعریف_کرو Interlocked_ثنائی_ہندسہ_Test_And_Reset _interlockedbittestandreset
#تعریف_کرو ثنائی_ہندسہ_Test64 _bittest64
#تعریف_کرو ثنائی_ہندسہ_Test_And_Complement64 _bittestandcomplement64
#تعریف_کرو ثنائی_ہندسہ_Test_And_Set64 _bittestandset64
#تعریف_کرو ثنائی_ہندسہ_Test_And_Reset64 _bittestandreset64
#تعریف_کرو Interlocked_ثنائی_ہندسہ_Test_And_Set64 _interlockedbittestandset64
#تعریف_کرو Interlocked_ثنائی_ہندسہ_Test_And_Reset64 _interlockedbittestandreset64

    __CRT_INLINE BOOLEAN _bittest(LONG ثابت *بنیاد_2,LONG انحراف_3) {
      صحیح old = 0;
      __asm__ __volatile__("btl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متلون طویل *) بنیاد_2))
	:"Ir" (انحراف_3));
      واپس (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandcomplement(LONG *بنیاد_2,LONG انحراف_3) {
      صحیح old = 0;
      __asm__ __volatile__("btcl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متلون طویل *) بنیاد_2))
	:"Ir" (انحراف_3));
      واپس (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN Interlocked_ثنائی_ہندسہ_Test_And_Complement(LONG *بنیاد_2,LONG ثنائی_ہندسہ_2) {
      صحیح old = 0;
      __asm__ __volatile__("lock ; btcl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متلون طویل *) بنیاد_2))
	:"Ir" (ثنائی_ہندسہ_2));
      واپس (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandset(LONG *بنیاد_2,LONG انحراف_3) {
      صحیح old = 0;
      __asm__ __volatile__("btsl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متلون طویل *) بنیاد_2))
	:"Ir" (انحراف_3));
      واپس (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandreset(LONG *بنیاد_2,LONG انحراف_3) {
      صحیح old = 0;
      __asm__ __volatile__("btrl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متلون طویل *) بنیاد_2))
	:"Ir" (انحراف_3));
      واپس (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _interlockedbittestandset(LONG *بنیاد_2,LONG انحراف_3) {
      صحیح old = 0;
      __asm__ __volatile__("lock ; btsl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متلون طویل *) بنیاد_2))
	:"Ir" (انحراف_3));
      واپس (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _interlockedbittestandreset(LONG *بنیاد_2,LONG انحراف_3) {
      صحیح old = 0;
      __asm__ __volatile__("lock ; btrl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متلون طویل *) بنیاد_2))
	:"Ir" (انحراف_3));
      واپس (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittest64(LONG64 ثابت *بنیاد_2,LONG64 انحراف_3) {
      صحیح old = 0;
      __asm__ __volatile__("btq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متلون طویل طویل *) بنیاد_2))
	:"Ir" (انحراف_3));
      واپس (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandcomplement64(LONG64 *بنیاد_2,LONG64 انحراف_3) {
      صحیح old = 0;
      __asm__ __volatile__("btcq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متلون طویل طویل *) بنیاد_2))
	:"Ir" (انحراف_3));
      واپس (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandset64(LONG64 *بنیاد_2,LONG64 انحراف_3) {
      صحیح old = 0;
      __asm__ __volatile__("btsq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متلون طویل طویل *) بنیاد_2))
	:"Ir" (انحراف_3));
      واپس (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandreset64(LONG64 *بنیاد_2,LONG64 انحراف_3) {
      صحیح old = 0;
      __asm__ __volatile__("btrq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متلون طویل طویل *) بنیاد_2))
	:"Ir" (انحراف_3));
      واپس (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _interlockedbittestandset64(LONG64 *بنیاد_2,LONG64 انحراف_3) {
      صحیح old = 0;
      __asm__ __volatile__("lock ; btsq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متلون طویل طویل *) بنیاد_2))
	:"Ir" (انحراف_3));
      واپس (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _interlockedbittestandreset64(LONG64 *بنیاد_2,LONG64 انحراف_3) {
      صحیح old = 0;
      __asm__ __volatile__("lock ; btrq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متلون طویل طویل *) بنیاد_2))
	:"Ir" (انحراف_3));
      واپس (BOOLEAN) (old!=0);
    }
#تعریف_کرو ثنائی_ہندسہ_جائزہ_Forward ثنائی_ہندسہ_جائزہ_Forward_2
#تعریف_کرو ثنائی_ہندسہ_جائزہ_الٹ ثنائی_ہندسہ_جائزہ_الٹ_2
#تعریف_کرو ثنائی_ہندسہ_جائزہ_Forward64 ثنائی_ہندسہ_جائزہ_Forward64_2
#تعریف_کرو ثنائی_ہندسہ_جائزہ_Reverse64 ثنائی_ہندسہ_جائزہ_Reverse64_2

    __CRT_INLINE BOOLEAN ثنائی_ہندسہ_جائزہ_Forward_2(DWORD *اشاریہ_3,DWORD نقاب_3) {
      __asm__ __volatile__("bsfl %1,%0" : "=r" (نقاب_3),"=m" ((*(متلون طویل *)اشاریہ_3)));
      واپس نقاب_3!=0;
    }
    __CRT_INLINE BOOLEAN ثنائی_ہندسہ_جائزہ_الٹ_2(DWORD *اشاریہ_3,DWORD نقاب_3) {
      __asm__ __volatile__("bsrl %1,%0" : "=r" (نقاب_3),"=m" ((*(متلون طویل *)اشاریہ_3)));
      واپس نقاب_3!=0;
    }
    __CRT_INLINE BOOLEAN ثنائی_ہندسہ_جائزہ_Forward64_2(DWORD *اشاریہ_3,DWORD64 نقاب_3) {
      __asm__ __volatile__("bsfq %1,%0" : "=r" (نقاب_3),"=m" ((*(متلون طویل طویل *)اشاریہ_3)));
      واپس نقاب_3!=0;
    }
    __CRT_INLINE BOOLEAN ثنائی_ہندسہ_جائزہ_Reverse64_2(DWORD *اشاریہ_3,DWORD64 نقاب_3) {
      __asm__ __volatile__("bsrq %1,%0" : "=r" (نقاب_3),"=m" ((*(متلون طویل طویل *)اشاریہ_3)));
      واپس نقاب_3!=0;
    }

#تعریف_کرو InterlockedIncrement16 _InterlockedIncrement16
#تعریف_کرو InterlockedDecrement16 _InterlockedDecrement16
#تعریف_کرو InterlockedCompareExchange16 _InterlockedCompareExchange16

#تعریف_کرو InterlockedAnd _InterlockedAnd
#تعریف_کرو InterlockedOr _InterlockedOr
#تعریف_کرو InterlockedXor _InterlockedXor
#تعریف_کرو InterlockedIncrement _InterlockedIncrement
#تعریف_کرو InterlockedIncrementAcquire InterlockedIncrement
#تعریف_کرو InterlockedIncrementRelease InterlockedIncrement
#تعریف_کرو InterlockedDecrement _InterlockedDecrement
#تعریف_کرو InterlockedDecrementAcquire InterlockedDecrement
#تعریف_کرو InterlockedDecrementRelease InterlockedDecrement
#تعریف_کرو Interlocked_جوڑو Interlocked_جوڑو_2
#تعریف_کرو InterlockedExchange _InterlockedExchange
#تعریف_کرو Interlocked_Exchange_جوڑو Interlocked_Exchange_جوڑو_2
#تعریف_کرو InterlockedCompareExchange _InterlockedCompareExchange
#تعریف_کرو InterlockedCompareExchangeAcquire InterlockedCompareExchange
#تعریف_کرو InterlockedCompareExchangeRelease InterlockedCompareExchange

#تعریف_کرو InterlockedAnd64 _InterlockedAnd64
#تعریف_کرو InterlockedAndAffinity InterlockedAnd64
#تعریف_کرو InterlockedOr64 _InterlockedOr64
#تعریف_کرو InterlockedOrAffinity InterlockedOr64
#تعریف_کرو InterlockedXor64 _InterlockedXor64
#تعریف_کرو InterlockedIncrement64 _InterlockedIncrement64
#تعریف_کرو InterlockedDecrement64 _InterlockedDecrement64
#تعریف_کرو InterlockedAdd64 _InterlockedAdd64
#تعریف_کرو InterlockedExchange64 _InterlockedExchange64
#تعریف_کرو InterlockedExchangeAcquire64 InterlockedExchange64
#تعریف_کرو InterlockedExchangeAdd64 _InterlockedExchangeAdd64
#تعریف_کرو InterlockedCompareExchange64 _InterlockedCompareExchange64
#تعریف_کرو InterlockedCompareExchangeAcquire64 InterlockedCompareExchange64
#تعریف_کرو InterlockedCompareExchangeRelease64 InterlockedCompareExchange64

#تعریف_کرو Interlocked_Exchange_اشارہ_گر Interlocked_Exchange_اشارہ_گر_2
#تعریف_کرو Interlocked_Compare_Exchange_اشارہ_گر Interlocked_Compare_Exchange_اشارہ_گر_2
#تعریف_کرو Interlocked_Compare_Exchange_اشارہ_گر_Acquire Interlocked_Compare_Exchange_اشارہ_گر_2
#تعریف_کرو Interlocked_Compare_Exchange_اشارہ_گر_Release Interlocked_Compare_Exchange_اشارہ_گر_2

#تعریف_کرو Interlocked_Exchange_جوڑو_سائز_T(a,b) InterlockedExchangeAdd64((LONG64 *)a,b)
#تعریف_کرو Interlocked_Increment_سائز_T(a) InterlockedIncrement64((LONG64 *)a)
#تعریف_کرو Interlocked_Decrement_سائز_T(a) InterlockedDecrement64((LONG64 *)a)

    __CRT_INLINE SHORT InterlockedIncrement16(SHORT متلون *Addend) {
      غیرعلامتی حرف c;
      غیرعلامتی حرف s;
      __asm__ __volatile__(
	"lock ; addw $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      واپس (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE SHORT InterlockedDecrement16(SHORT متلون *Addend) {
      غیرعلامتی حرف c;
      غیرعلامتی حرف s;
      __asm__ __volatile__(
	"lock ; subw $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      واپس (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE SHORT InterlockedCompareExchange16(SHORT متلون *Destination,SHORT ExChange,SHORT Comperand) {
      SHORT پچھلا;
      __asm__ __volatile__("lock ; cmpxchgw %w1,%2"
	:"=a"(پچھلا)
	:"q"(ExChange), "m"(*Destination), "0"(Comperand)
	: "memory");
      واپس پچھلا;
    }
    __CRT_INLINE LONG InterlockedAnd(LONG متلون *Destination,LONG قدر_3) {
      __asm__ __volatile__("lock ; andl %0,%1"
	: :"r"(قدر_3),"m"(*Destination)
	: "memory");
      واپس *Destination;
    }
    __CRT_INLINE LONG InterlockedOr(LONG متلون *Destination,LONG قدر_3) {
      __asm__ __volatile__("lock ; orl %0,%1"
	: : "r"(قدر_3),"m"(*Destination) : "memory");
      واپس *Destination;
    }
    __CRT_INLINE LONG InterlockedXor(LONG متلون *Destination,LONG قدر_3) {
      __asm__ __volatile__("lock ; xorl %0,%1"
	: : "r"(قدر_3),"m"(*Destination) : "memory");
      واپس *Destination;
    }
    //		$$$$
    __CRT_INLINE LONG64 InterlockedAnd64(LONG64 متلون *Destination,LONG64 قدر_3) {
      __asm__ __volatile__("lock ; andq %0,%1"
	: : "r"(قدر_3),"m"(*Destination) : "memory");
      واپس *Destination;
    }
    __CRT_INLINE LONG64 InterlockedOr64(LONG64 متلون *Destination,LONG64 قدر_3) {
      __asm__ __volatile__("lock ; orq %0,%1"
	: : "r"(قدر_3),"m"(*Destination) : "memory");
      واپس *Destination;
    }
    __CRT_INLINE LONG64 InterlockedXor64(LONG64 متلون *Destination,LONG64 قدر_3) {
      __asm__ __volatile__("lock ; xorq %0,%1"
	: : "r"(قدر_3),"m"(*Destination) : "memory");
      واپس *Destination;
    }
    __CRT_INLINE LONG InterlockedIncrement(LONG متلون *Addend) {
      غیرعلامتی حرف c;
      غیرعلامتی حرف s;
      __asm__ __volatile__(
	"lock ; addl $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      واپس (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE LONG InterlockedDecrement(LONG متلون *Addend) {
      غیرعلامتی حرف c;
      غیرعلامتی حرف s;
      __asm__ __volatile__(
	"lock ; subl $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      واپس (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE LONG InterlockedExchange(LONG متلون *ہدف_2,LONG قدر_3) {
      __asm__ __volatile("lock ; xchgl %0,%1"
	: "=r"(قدر_3)
	: "m"(*ہدف_2),"0"(قدر_3)
	: "memory");
      واپس قدر_3;
    }
    LONG Interlocked_Exchange_جوڑو(LONG متلون *Addend,LONG قدر_3);

#اگر_غیر_تعریف_شدہ _X86AMD64_
    __CRT_INLINE LONG Interlocked_جوڑو(LONG متلون *Addend,LONG قدر_3) { واپس Interlocked_Exchange_جوڑو(Addend,قدر_3) + قدر_3; }
#اگر_ختم
    __CRT_INLINE LONG InterlockedCompareExchange(LONG متلون *Destination,LONG ExChange,LONG Comperand) {
      LONG پچھلا;
      __asm__ __volatile__("lock ; cmpxchgl %1,%2" : "=a" (پچھلا) : "q" (ExChange),"m" (*Destination), "0" (Comperand) : "memory");
      واپس پچھلا;
    }
    __CRT_INLINE LONG64 InterlockedIncrement64(LONG64 متلون *Addend) {
      غیرعلامتی حرف c;
      غیرعلامتی حرف s;
      __asm__ __volatile__(
	"lock ; addq $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      واپس (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE LONG64 InterlockedDecrement64(LONG64 متلون *Addend) {
      غیرعلامتی حرف c;
      غیرعلامتی حرف s;
      __asm__ __volatile__(
	"lock ; subq $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      واپس (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE LONG64 InterlockedExchange64(LONG64 متلون *ہدف_2,LONG64 قدر_3) {
      __asm__ __volatile("lock ; xchgq %0,%1"
	: "=r"(قدر_3)
	: "m"(*ہدف_2),"0"(قدر_3)
	: "memory");
      واپس قدر_3;
    }
    LONG64 InterlockedExchangeAdd64(LONG64 متلون *Addend,LONG64 قدر_3);

#اگر_غیر_تعریف_شدہ _X86AMD64_
    __CRT_INLINE LONG64 InterlockedAdd64(LONG64 متلون *Addend,LONG64 قدر_3) { واپس InterlockedExchangeAdd64(Addend,قدر_3) + قدر_3; }
#اگر_ختم

    __CRT_INLINE LONG64 InterlockedCompareExchange64(LONG64 متلون *Destination,LONG64 ExChange,LONG64 Comperand) {
      LONG64 پچھلا;
      __asm__ __volatile__("lock ; cmpxchgq %1,%2" : "=a" (پچھلا) : "q" (ExChange),"m" (*Destination), "0" (Comperand) : "memory");
      واپس پچھلا;
    }
    __CRT_INLINE PVOID Interlocked_Compare_Exchange_اشارہ_گر(PVOID متلون *Destination,PVOID ExChange,PVOID Comperand) {
      PVOID پچھلا;
      __asm__ __volatile__("lock ; cmpxchgq %1,%2" : "=a" (پچھلا) : "q" (ExChange),"m" (*Destination), "0" (Comperand) : "memory");
      واپس پچھلا;
    }
    __CRT_INLINE PVOID Interlocked_Exchange_اشارہ_گر(PVOID متلون *ہدف_2,PVOID قدر_3) {
      __asm__ __volatile("lock ; xchgq %0,%1"
	: "=r"(قدر_3)
	: "m"(*ہدف_2),"0"(قدر_3)
	: "memory");
      واپس قدر_3;
    }

#تعریف_کرو Cache_سطر_Flush(پتہ_2) _mm_clflush(پتہ_2)

    VOID _ReadWriteBarrier(VOID);

#تعریف_کرو FastFence __faststorefence
#تعریف_کرو بھرو_Fence _mm_lfence
#تعریف_کرو حافظہ_Fence _mm_mfence
#تعریف_کرو StoreFence _mm_sfence

    VOID __faststorefence(VOID);
    VOID _m_prefetchw(متلون CONST VOID *ماخذ_2);

//!__TINYC__: #include <intrin.h>

#تعریف_کرو YieldProcessor _mm_pause
#تعریف_کرو حافظہ_Barrier __faststorefence
#تعریف_کرو Pre_Fetch_Cache_سطر(l,a) _mm_prefetch((CHAR CONST *) a,l)
#تعریف_کرو PrefetchForWrite(p) _m_prefetchw(p)
#تعریف_کرو ReadForWriteAccess(p) (_m_prefetchw(p),*(p))

#تعریف_کرو PF_TEMPORAL_LEVEL_1 _MM_HINT_T0
#تعریف_کرو PF_TEMPORAL_LEVEL_2 _MM_HINT_T1
#تعریف_کرو PF_TEMPORAL_LEVEL_3 _MM_HINT_T2
#تعریف_کرو PF_NON_TEMPORAL_LEVEL_ALL _MM_HINT_NTA

#تعریف_کرو ReadMxCsr _mm_getcsr
#تعریف_کرو WriteMxCsr _mm_setcsr

    VOID __int2c(VOID);

#تعریف_کرو DbgRaiseAssertionFailure() __int2c()
#تعریف_کرو GetCallersEflags() __getcallerseflags()

    غیرعلامتی __int32 __getcallerseflags(VOID);

#تعریف_کرو Get_Segment_حد_بندی __segmentlimit

    DWORD __segmentlimit(DWORD Selector);

#تعریف_کرو Read_وقت_Stamp_شمار() __rdtsc()

    DWORD64 __rdtsc(VOID);
    VOID __movsb(PBYTE Destination,BYTE ثابت *ماخذ_2,سائز_T گنتی_3);
    VOID __movsw(PWORD Destination,لفظ_3 ثابت *ماخذ_2,سائز_T گنتی_3);
    VOID __movsd(PDWORD Destination,DWORD ثابت *ماخذ_2,سائز_T گنتی_3);
    VOID __movsq(PDWORD64 Destination,DWORD64 ثابت *ماخذ_2,سائز_T گنتی_3);
    VOID __stosb(PBYTE Destination,BYTE قدر_3,سائز_T گنتی_3);
    VOID __stosw(PWORD Destination,لفظ_3 قدر_3,سائز_T گنتی_3);
    VOID __stosd(PDWORD Destination,DWORD قدر_3,سائز_T گنتی_3);
    VOID __stosq(PDWORD64 Destination,DWORD64 قدر_3,سائز_T گنتی_3);

#تعریف_کرو Multiply_بلند __mulh
#تعریف_کرو Unsigned_Multiply_بلند __umulh

    LONGLONG Multiply_بلند(LONGLONG Multiplier,LONGLONG Multiplicand);
    ULONGLONG Unsigned_Multiply_بلند(ULONGLONG Multiplier,ULONGLONG Multiplicand);

#تعریف_کرو سرکاؤ_Left128 __shiftleft128
#تعریف_کرو سرکاؤ_Right128 __shiftright128

    DWORD64 سرکاؤ_Left128(DWORD64 کم_Part,DWORD64 بلند_Part,BYTE سرکاؤ_3);
    DWORD64 سرکاؤ_Right128(DWORD64 کم_Part,DWORD64 بلند_Part,BYTE سرکاؤ_3);

#تعریف_کرو Multiply128 _mul128

    LONG64 Multiply128(LONG64 Multiplier,LONG64 Multiplicand,LONG64 *بلند_حاصل_ضرب);

#تعریف_کرو UnsignedMultiply128 _umul128

    DWORD64 UnsignedMultiply128(DWORD64 Multiplier,DWORD64 Multiplicand,DWORD64 *بلند_حاصل_ضرب);

    __CRT_INLINE LONG64 MultiplyExtract128(LONG64 Multiplier,LONG64 Multiplicand,BYTE سرکاؤ_3) {
      LONG64 extracted_حاصل_ضرب;
      LONG64 بلند_حاصل_ضرب_2;
      LONG64 کم_حاصل_ضرب;
      کم_حاصل_ضرب = Multiply128(Multiplier,Multiplicand,&بلند_حاصل_ضرب_2);
      extracted_حاصل_ضرب = (LONG64)سرکاؤ_Right128((LONG64)کم_حاصل_ضرب,(LONG64)بلند_حاصل_ضرب_2,سرکاؤ_3);
      واپس extracted_حاصل_ضرب;
    }

    __CRT_INLINE DWORD64 UnsignedMultiplyExtract128(DWORD64 Multiplier,DWORD64 Multiplicand,BYTE سرکاؤ_3) {
      DWORD64 extracted_حاصل_ضرب;
      DWORD64 بلند_حاصل_ضرب_2;
      DWORD64 کم_حاصل_ضرب;
      کم_حاصل_ضرب = UnsignedMultiply128(Multiplier,Multiplicand,&بلند_حاصل_ضرب_2);
      extracted_حاصل_ضرب = سرکاؤ_Right128(کم_حاصل_ضرب,بلند_حاصل_ضرب_2,سرکاؤ_3);
      واپس extracted_حاصل_ضرب;
    }

    __CRT_INLINE BYTE __readgsbyte(DWORD انحراف_3) {
      BYTE ret;
      __asm__ متلون ("movb	%%gs:%1,%0"
	: "=r" (ret) ,"=m" ((*(متلون طویل *) (DWORD64) انحراف_3)));
      واپس ret;
    }
    __CRT_INLINE لفظ_3 __readgsword(DWORD انحراف_3) {
      لفظ_3 ret;
      __asm__ متلون ("movw	%%gs:%1,%0"
	: "=r" (ret) ,"=m" ((*(متلون طویل *) (DWORD64) انحراف_3)));
      واپس ret;
    }
    __CRT_INLINE DWORD __readgsdword(DWORD انحراف_3) {
      DWORD ret;
      __asm__ متلون ("movl	%%gs:%1,%0"
	: "=r" (ret) ,"=m" ((*(متلون طویل *) (DWORD64) انحراف_3)));
      واپس ret;
    }
    __CRT_INLINE DWORD64 __readgsqword(DWORD انحراف_3) {
      خالی *ret;
      __asm__ متلون ("movq	%%gs:%1,%0"
	: "=r" (ret) ,"=m" ((*(متلون طویل *) (DWORD64) انحراف_3)));
      واپس (DWORD64) ret;
    }
    __CRT_INLINE VOID __writegsbyte(DWORD انحراف_3,BYTE ڈیٹا_3) {
      __asm__ متلون ("movb	%0,%%gs:%1"
	: "=r" (ڈیٹا_3) ,"=m" ((*(متلون طویل *) (DWORD64) انحراف_3)));
    }
    __CRT_INLINE VOID __writegsword(DWORD انحراف_3,لفظ_3 ڈیٹا_3) {
      __asm__ متلون ("movw	%0,%%gs:%1"
	: "=r" (ڈیٹا_3) ,"=m" ((*(متلون طویل *) (DWORD64) انحراف_3)));
    }
    __CRT_INLINE VOID __writegsdword(DWORD انحراف_3,DWORD ڈیٹا_3) {
      __asm__ متلون ("movl	%0,%%gs:%1"
	: "=r" (ڈیٹا_3) ,"=m" ((*(متلون طویل *) (DWORD64) انحراف_3)));
    }
    __CRT_INLINE VOID __writegsqword(DWORD انحراف_3,DWORD64 ڈیٹا_3) {
      __asm__ متلون ("movq	%0,%%gs:%1"
	: "=r" (ڈیٹا_3) ,"=m" ((*(متلون طویل *) (DWORD64) انحراف_3)));
    }

#اگر_تعریف_شدہ __cplusplus
  }
#اگر_ختم

#تعریف_کرو EXCEPTION_READ_FAULT 0
#تعریف_کرو EXCEPTION_WRITE_FAULT 1
#تعریف_کرو EXCEPTION_EXECUTE_FAULT 8

#اگر !defined(RC_INVOKED)

#تعریف_کرو CONTEXT_AMD64 0x100000

#تعریف_کرو CONTEXT_CONTROL (CONTEXT_AMD64 | 0x1L)
#تعریف_کرو CONTEXT_INTEGER (CONTEXT_AMD64 | 0x2L)
#تعریف_کرو CONTEXT_SEGMENTS (CONTEXT_AMD64 | 0x4L)
#تعریف_کرو CONTEXT_FLOATING_نقطہ (CONTEXT_AMD64 | 0x8L)
#تعریف_کرو CONTEXT_DEBUG_REGISTERS (CONTEXT_AMD64 | 0x10L)

#تعریف_کرو CONTEXT_بھرا (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_FLOATING_نقطہ)
#تعریف_کرو CONTEXT_ALL (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_SEGMENTS | CONTEXT_FLOATING_نقطہ | CONTEXT_DEBUG_REGISTERS)

#تعریف_کرو CONTEXT_EXCEPTION_فعال 0x8000000
#تعریف_کرو CONTEXT_SERVICE_فعال 0x10000000
#تعریف_کرو CONTEXT_EXCEPTION_REQUEST 0x40000000
#تعریف_کرو CONTEXT_EXCEPTION_REPORTING 0x80000000
#اگر_ختم

#تعریف_کرو INITIAL_MXCSR 0x1f80
#تعریف_کرو INITIAL_FPCSR 0x027f

  قسمتعریف ساخت DECLSPEC_ALIGN(16) _M128A {
    ULONGLONG کم_3;
    LONGLONG بلند_3;
  } M128A,*PM128A;

  قسمتعریف ساخت _XMM_SAVE_AREA32 {
    لفظ_3 Control_لفظ;
    لفظ_3 حالت_لفظ;
    BYTE لیبل_لفظ;
    BYTE Reserved1;
    لفظ_3 ErrorOpcode;
    DWORD Error_انحراف;
    لفظ_3 ErrorSelector;
    لفظ_3 Reserved2;
    DWORD ڈیٹا_انحراف_2;
    لفظ_3 ڈیٹا_Selector;
    لفظ_3 Reserved3;
    DWORD MxCsr;
    DWORD Mx_Csr_نقاب;
    M128A FloatRegisters[8];
    M128A XmmRegisters[16];
    BYTE Reserved4[96];
  } XMM_SAVE_AREA32,*PXMM_SAVE_AREA32;

#تعریف_کرو LEGACY_SAVE_AREA_لمبائی حجم(XMM_SAVE_AREA32)

  قسمتعریف ساخت DECLSPEC_ALIGN(16) _CONTEXT {
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
      ساخت {
	M128A سرخی_2[2];
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
    M128A سمتیہ_رجسٹر[26];
    DWORD64 سمتیہ_Control;
    DWORD64 DebugControl;
    DWORD64 آخری_Branch_مقصد_Rip;
    DWORD64 آخری_Branch_From_Rip;
    DWORD64 آخری_Exception_مقصد_Rip;
    DWORD64 آخری_Exception_From_Rip;
  } CONTEXT,*PCONTEXT;

#تعریف_کرو RUNTIME_FUNCTION_بالواسطہ 0x1

  قسمتعریف ساخت _RUNTIME_FUNCTION {
    DWORD Begin_پتہ;
    DWORD انتہا_پتہ;
    DWORD Unwind_ڈیٹا;
  } RUNTIME_FUNCTION,*PRUNTIME_FUNCTION;

  قسمتعریف PRUNTIME_FUNCTION (*PGET_RUNTIME_FUNCTION_CALLBACK)(DWORD64 ControlPc,PVOID Context);
  قسمتعریف DWORD (*POUT_کا_PROCESS_FUNCTION_جدول_CALLBACK)(HANDLE Process,PVOID جدول_پتہ,PDWORD Entries,PRUNTIME_FUNCTION *Functions);

#تعریف_کرو برآمد_کا_PROCESS_FUNCTION_جدول_CALLBACK_EXPORT_NAME "OutOfProcessFunctionTableCallback"
#اگر_ختم /* defined(__x86_64) && !defined(RC_INVOKED) */

#اگر defined(__TINYC__) && (defined(__aarch64__) || defined(__arm64__)) && !defined(RC_INVOKED)

#تعریف_کرو __TCC_WINNT_ATOMIC_SEQ_CST 5
/* TCC lowers __atomic_compare_exchange's fourth argument as weak, but the
   ARM64 helper reads it as success_memorder.  Strong CAS passes weak == 0,
   so keep Interlocked's barriers explicit here. */
#تعریف_کرو __TCC_WINNT_MEMORY_BARRIER() __asm__ __volatile__("dmb ish" : : : "memory")

/* This covers the LONG operations needed by TCC's semaphore code and the
   pointer helpers that winbase.h exposes through Interlocked pointer macros.
   Add local helpers before relying on increment/decrement, add/exchange-add,
   bitwise, or 64-bit Interlocked forms on Windows ARM64 with TCC. */

    __CRT_INLINE LONG InterlockedExchange(LONG متلون *ہدف_2,LONG قدر_3) {
      LONG Old;
      __atomic_load(ہدف_2,&Old,__TCC_WINNT_ATOMIC_SEQ_CST);
      __TCC_WINNT_MEMORY_BARRIER();
      جب (!__atomic_compare_exchange(ہدف_2,&Old,&قدر_3,0,
	__TCC_WINNT_ATOMIC_SEQ_CST,__TCC_WINNT_ATOMIC_SEQ_CST))
	;
      __TCC_WINNT_MEMORY_BARRIER();
      واپس Old;
    }
    __CRT_INLINE LONG InterlockedCompareExchange(LONG متلون *Destination,LONG ExChange,LONG Comperand) {
      LONG Old = Comperand;
      __TCC_WINNT_MEMORY_BARRIER();
      __atomic_compare_exchange(Destination,&Old,&ExChange,0,
	__TCC_WINNT_ATOMIC_SEQ_CST,__TCC_WINNT_ATOMIC_SEQ_CST);
      __TCC_WINNT_MEMORY_BARRIER();
      واپس Old;
    }
    __CRT_INLINE PVOID __TCC_WINNT_InterlockedExchangePointer(PVOID متلون *ہدف_2,PVOID قدر_3) {
      PVOID Old;
      __atomic_load(ہدف_2,&Old,__TCC_WINNT_ATOMIC_SEQ_CST);
      __TCC_WINNT_MEMORY_BARRIER();
      جب (!__atomic_compare_exchange(ہدف_2,&Old,&قدر_3,0,
	__TCC_WINNT_ATOMIC_SEQ_CST,__TCC_WINNT_ATOMIC_SEQ_CST))
	;
      __TCC_WINNT_MEMORY_BARRIER();
      واپس Old;
    }
    __CRT_INLINE PVOID __TCC_WINNT_InterlockedCompareExchangePointer(PVOID متلون *Destination,PVOID ExChange,PVOID Comperand) {
      PVOID Old = Comperand;
      __TCC_WINNT_MEMORY_BARRIER();
      __atomic_compare_exchange(Destination,&Old,&ExChange,0,
	__TCC_WINNT_ATOMIC_SEQ_CST,__TCC_WINNT_ATOMIC_SEQ_CST);
      __TCC_WINNT_MEMORY_BARRIER();
      واپس Old;
    }

#تعریف_کرو Interlocked_Exchange_اشارہ_گر __TCC_WINNT_InterlockedExchangePointer
#تعریف_کرو Interlocked_Compare_Exchange_اشارہ_گر __TCC_WINNT_InterlockedCompareExchangePointer
#تعریف_کرو Interlocked_Compare_Exchange_اشارہ_گر_Acquire Interlocked_Compare_Exchange_اشارہ_گر
#تعریف_کرو Interlocked_Compare_Exchange_اشارہ_گر_Release Interlocked_Compare_Exchange_اشارہ_گر

#تعریف_کرو InterlockedCompareExchangeAcquire InterlockedCompareExchange
#تعریف_کرو InterlockedCompareExchangeRelease InterlockedCompareExchange

#تعریف_منسوخ __TCC_WINNT_MEMORY_BARRIER
#تعریف_منسوخ __TCC_WINNT_ATOMIC_SEQ_CST

#اگر_ختم /* defined(__TINYC__) && (defined(__aarch64__) || defined(__arm64__)) && !defined(RC_INVOKED) */

#اگر defined(_ARM64_)

/* ARM64 Context Definition */
#تعریف_کرو CONTEXT_ARM64 0x00400000
#تعریف_کرو CONTEXT_CONTROL (CONTEXT_ARM64 | 0x00000001L)
#تعریف_کرو CONTEXT_INTEGER (CONTEXT_ARM64 | 0x00000002L)
#تعریف_کرو CONTEXT_FLOATING_نقطہ (CONTEXT_ARM64 | 0x00000004L)
#تعریف_کرو CONTEXT_DEBUG (CONTEXT_ARM64 | 0x00000008L)
#تعریف_کرو CONTEXT_بھرا (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_FLOATING_نقطہ)
#تعریف_کرو CONTEXT_ALL (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_FLOATING_نقطہ | CONTEXT_DEBUG)
#تعریف_کرو ARM64_MAX_BREAKPOINTS 8
#تعریف_کرو ARM64_MAX_WATCHPOINTS 2

  قسمتعریف اتحاد _ARM64_NT_NEON128 {
    ساخت {
      ULONGLONG کم_3;
      LONGLONG بلند_3;
    } DUMMYSTRUCTNAME;
    دوہرا D[2];
    اعشاری S[4];
    لفظ_3 H[8];
    BYTE B[16];
  } ARM64_NT_NEON128,*PARM64_NT_NEON128;

  قسمتعریف ساخت DECLSPEC_ALIGN(16) _ARM64_NT_CONTEXT {
    ULONG ContextFlags;
    ULONG Cpsr;
    اتحاد {
      ساخت {
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

  قسمتعریف ARM64_NT_CONTEXT CONTEXT,*PCONTEXT;

  قسمتعریف ساخت _RUNTIME_FUNCTION {
    DWORD Begin_پتہ;
    DWORD Unwind_ڈیٹا;
  } RUNTIME_FUNCTION,*PRUNTIME_FUNCTION;

  قسمتعریف PRUNTIME_FUNCTION (*PGET_RUNTIME_FUNCTION_CALLBACK)(DWORD64 ControlPc,PVOID Context);
  قسمتعریف DWORD (*POUT_کا_PROCESS_FUNCTION_جدول_CALLBACK)(HANDLE Process,PVOID جدول_پتہ,PDWORD Entries,PRUNTIME_FUNCTION *Functions);

#اگر_ختم /* _ARM64_ */

#اگر (defined _ARM64_ || defined _AMD64_) && !defined RC_INVOKED
  NTSYSAPI VOID __cdecl RtlRestoreContext (PCONTEXT Context_ریکارڈ,ساخت EXCEPTION_ریکارڈ *Exception_ریکارڈ);
  NTSYSAPI BOOLEAN __cdecl Rtl_جوڑو_Function_جدول(PRUNTIME_FUNCTION Function_جدول,DWORD اندراج_گنتی,DWORD64 بنیاد_پتہ);
  NTSYSAPI BOOLEAN __cdecl Rtl_Install_Function_جدول_Callback(DWORD64 جدول_Identifier,DWORD64 بنیاد_پتہ,DWORD لمبائی_2,PGET_RUNTIME_FUNCTION_CALLBACK Callback,PVOID Context,PCWSTR برآمد_کا_Process_Callback_Dll);
  NTSYSAPI BOOLEAN __cdecl Rtl_Delete_Function_جدول(PRUNTIME_FUNCTION Function_جدول);
#اگر_ختم

#اگر_تعریف_شدہ I_X86_
#اگر(defined(_X86_) && !defined(__x86_64)) && !defined(RC_INVOKED)
#اگر_تعریف_شدہ __cplusplus
  خارجی "C" {
#اگر_ختم

    __CRT_INLINE BOOLEAN Interlocked_ثنائی_ہندسہ_Test_And_سیٹ(LONG *بنیاد_2,LONG ثنائی_ہندسہ_2) {
      صحیح old = 0;
      __asm__ __volatile__("lock ; btsl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متلون طویل *) بنیاد_2))
	:"Ir" (ثنائی_ہندسہ_2));
      واپس (BOOLEAN) (old!=0);
    }

    __CRT_INLINE BOOLEAN Interlocked_ثنائی_ہندسہ_Test_And_Reset(LONG *بنیاد_2,LONG ثنائی_ہندسہ_2) {
      صحیح old = 0;
      __asm__ __volatile__("lock ; btrl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متلون طویل *) بنیاد_2))
	:"Ir" (ثنائی_ہندسہ_2));
      واپس (BOOLEAN) (old!=0);
    }

    __CRT_INLINE BOOLEAN Interlocked_ثنائی_ہندسہ_Test_And_Complement(LONG *بنیاد_2,LONG ثنائی_ہندسہ_2) {
      صحیح old = 0;
      __asm__ __volatile__("lock ; btcl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(متلون طویل *) بنیاد_2))
	:"Ir" (ثنائی_ہندسہ_2));
      واپس (BOOLEAN) (old!=0);
    }

#اگر_تعریف_شدہ سابقہ_2
    BYTE __readfsbyte(DWORD انحراف_3);
    لفظ_3 __readfsword(DWORD انحراف_3);
    DWORD __readfsdword(DWORD انحراف_3);
    VOID __writefsbyte(DWORD انحراف_3,BYTE ڈیٹا_3);
    VOID __writefsword(DWORD انحراف_3,لفظ_3 ڈیٹا_3);
    VOID __writefsdword(DWORD انحراف_3,DWORD ڈیٹا_3);
#اگر_ختم

#اگر_تعریف_شدہ __cplusplus
  }
#اگر_ختم
#اگر_ختم

#اگر(defined(_X86_) && !defined(__x86_64))
  __CRT_INLINE VOID حافظہ_Barrier(VOID) {
    LONG Barrier;
    __asm__ __volatile__("xchgl %%eax,%0 "
      :"=r" (Barrier));
  }
#تعریف_کرو YieldProcessor() __asm__ __volatile__("rep nop ");

#تعریف_کرو Pre_Fetch_Cache_سطر(l,a)
#تعریف_کرو ReadForWriteAccess(p) (*(p))

#تعریف_کرو PF_TEMPORAL_LEVEL_1
#تعریف_کرو PF_NON_TEMPORAL_LEVEL_ALL

  __CRT_INLINE VOID DbgRaiseAssertionFailure(خالی) {
    __asm__ __volatile__("int $0x2c ");
  }
  PVOID GetCurrentFiber(خالی);
  __CRT_INLINE PVOID GetCurrentFiber(خالی)
  {
    خالی *ret;
    __asm__ متلون ("movl	%%fs:0x10,%0"
	: "=r" (ret));
    واپس ret;
  }
  PVOID Get_Fiber_ڈیٹا(خالی);
  __CRT_INLINE PVOID Get_Fiber_ڈیٹا(خالی)
  {
    خالی *ret;
    __asm__ متلون ("movl	%%fs:0x10,%0\n"
	"movl	(%0),%0"
	: "=r" (ret));
    واپس ret;
  }
#اگر_ختم

#تعریف_کرو EXCEPTION_READ_FAULT 0
#تعریف_کرو EXCEPTION_WRITE_FAULT 1
#تعریف_کرو EXCEPTION_EXECUTE_FAULT 8

#تعریف_کرو سائز_کا_80387_REGISTERS 80

#اگر !defined(RC_INVOKED)

#تعریف_کرو CONTEXT_i386 0x00010000
#تعریف_کرو CONTEXT_i486 0x00010000

#تعریف_کرو CONTEXT_CONTROL (CONTEXT_i386 | 0x00000001L)
#تعریف_کرو CONTEXT_INTEGER (CONTEXT_i386 | 0x00000002L)
#تعریف_کرو CONTEXT_SEGMENTS (CONTEXT_i386 | 0x00000004L)
#تعریف_کرو CONTEXT_FLOATING_نقطہ (CONTEXT_i386 | 0x00000008L)
#تعریف_کرو CONTEXT_DEBUG_REGISTERS (CONTEXT_i386 | 0x00000010L)
#تعریف_کرو CONTEXT_EXTENDED_REGISTERS (CONTEXT_i386 | 0x00000020L)

#تعریف_کرو CONTEXT_بھرا (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_SEGMENTS)

#تعریف_کرو CONTEXT_ALL (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_SEGMENTS | CONTEXT_FLOATING_نقطہ | CONTEXT_DEBUG_REGISTERS | CONTEXT_EXTENDED_REGISTERS)
#اگر_ختم

#تعریف_کرو زیادہ_سے_زیادہ_SUPPORTED_EXTENSION 512

    قسمتعریف ساخت _FLOATING_SAVE_AREA {
      DWORD Control_لفظ;
      DWORD حالت_لفظ;
      DWORD لیبل_لفظ;
      DWORD Error_انحراف;
      DWORD ErrorSelector;
      DWORD ڈیٹا_انحراف_2;
      DWORD ڈیٹا_Selector;
      BYTE رجسٹر_Area[سائز_کا_80387_REGISTERS];
      DWORD Cr0NpxState;
    } FLOATING_SAVE_AREA;

    قسمتعریف FLOATING_SAVE_AREA *PFLOATING_SAVE_AREA;

    قسمتعریف ساخت _CONTEXT {
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
      BYTE ExtendedRegisters[زیادہ_سے_زیادہ_SUPPORTED_EXTENSION];
    } CONTEXT;

    قسمتعریف CONTEXT *PCONTEXT;
#اگر_ختم

#اگر_غیر_تعریف_شدہ LDT_اندراج_DEFINED
#تعریف_کرو LDT_اندراج_DEFINED

    قسمتعریف ساخت LDT_اندراج {
      لفظ_3 حد_بندی_کم;
      لفظ_3 بنیاد_کم;
      اتحاد {
	ساخت {
	  BYTE بنیاد_Mid;
	  BYTE Flags1;
	  BYTE Flags2;
	  BYTE بنیاد_Hi;
	} بائٹیں_2;
	ساخت {
	  DWORD بنیاد_Mid : 8;
	  DWORD Type : 5;
	  DWORD Dpl : 2;
	  DWORD Pres : 1;
	  DWORD حد_بندی_Hi : 4;
	  DWORD Sys : 1;
	  DWORD Reserved_0 : 1;
	  DWORD Default_Big : 1;
	  DWORD Granularity : 1;
	  DWORD بنیاد_Hi : 8;
	} بٹ_2;
      } بلند_لفظ;
    } LDT_اندراج_2,*PLDT_اندراج;
#اگر_ختم

#اگر defined(__ia64__) && !defined(RC_INVOKED)

#اگر_تعریف_شدہ __cplusplus
    خارجی "C" {
#اگر_ختم

      BOOLEAN ثنائی_ہندسہ_جائزہ_Forward64(DWORD *اشاریہ_3,DWORD64 نقاب_3);
      BOOLEAN ثنائی_ہندسہ_جائزہ_Reverse64(DWORD *اشاریہ_3,DWORD64 نقاب_3);

#اگر_تعریف_شدہ __cplusplus
    }
#اگر_ختم
#اگر_ختم

#اگر !defined(GENUTIL) && !defined(_GENIA64_) && defined(_IA64_)

    خالی *_cdecl _rdteb(خالی);
#اگر_تعریف_شدہ __ia64__

#تعریف_کرو NtCurrentTeb() ((ساخت _TEB *)_rdteb())
#تعریف_کرو GetCurrentFiber() (((PNT_TIB)NtCurrentTeb())->Fiber_ڈیٹا)
#تعریف_کرو Get_Fiber_ڈیٹا() (*(PVOID *)(GetCurrentFiber()))

#اگر_تعریف_شدہ __cplusplus
    خارجی "C" {
#اگر_ختم

      خالی __break(صحیح);
      خالی __yield(خالی);
      خالی __mf(خالی);
      خالی __lfetch(صحیح Level,VOID CONST *پتہ_2);
      خالی __lfetchfault(صحیح Level,VOID CONST *پتہ_2);
      خالی __lfetch_excl(صحیح Level,VOID CONST *پتہ_2);
      خالی __lfetchfault_excl(صحیح Level,VOID CONST *پتہ_2);

#تعریف_کرو MD_LFHINT_NONE 0x00
#تعریف_کرو MD_LFHINT_NT1 0x01
#تعریف_کرو MD_LFHINT_NT2 0x02
#تعریف_کرو MD_LFHINT_NTA 0x03

#اگر_تعریف_شدہ __cplusplus
    }
#اگر_ختم

#تعریف_کرو YieldProcessor __yield
#تعریف_کرو حافظہ_Barrier __mf
#تعریف_کرو Pre_Fetch_Cache_سطر __lfetch
#تعریف_کرو ReadForWriteAccess(p) (*(p))
#تعریف_کرو DbgRaiseAssertionFailure() __break(ASSERT_BREAKPOINT)

#تعریف_کرو PF_TEMPORAL_LEVEL_1 MD_LFHINT_NONE
#تعریف_کرو PF_NON_TEMPORAL_LEVEL_ALL MD_LFHINT_NTA

#تعریف_کرو Unsigned_Multiply_بلند __UMULH

    ULONGLONG Unsigned_Multiply_بلند(ULONGLONG Multiplier,ULONGLONG Multiplicand);
#ورنہ
    ساخت _TEB *NtCurrentTeb(خالی);
#اگر_ختم
#اگر_ختم

#اگر_تعریف_شدہ _IA64_

#تعریف_کرو EXCEPTION_READ_FAULT 0
#تعریف_کرو EXCEPTION_WRITE_FAULT 1
#تعریف_کرو EXCEPTION_EXECUTE_FAULT 2

#اگر !defined(RC_INVOKED)

#تعریف_کرو CONTEXT_IA64 0x00080000

#تعریف_کرو CONTEXT_CONTROL (CONTEXT_IA64 | 0x00000001L)
#تعریف_کرو CONTEXT_زیریں_FLOATING_نقطہ (CONTEXT_IA64 | 0x00000002L)
#تعریف_کرو CONTEXT_HIGHER_FLOATING_نقطہ (CONTEXT_IA64 | 0x00000004L)
#تعریف_کرو CONTEXT_INTEGER (CONTEXT_IA64 | 0x00000008L)
#تعریف_کرو CONTEXT_DEBUG (CONTEXT_IA64 | 0x00000010L)
#تعریف_کرو CONTEXT_IA32_CONTROL (CONTEXT_IA64 | 0x00000020L)

#تعریف_کرو CONTEXT_FLOATING_نقطہ (CONTEXT_زیریں_FLOATING_نقطہ | CONTEXT_HIGHER_FLOATING_نقطہ)
#تعریف_کرو CONTEXT_بھرا (CONTEXT_CONTROL | CONTEXT_FLOATING_نقطہ | CONTEXT_INTEGER | CONTEXT_IA32_CONTROL)
#تعریف_کرو CONTEXT_ALL (CONTEXT_CONTROL | CONTEXT_FLOATING_نقطہ | CONTEXT_INTEGER | CONTEXT_DEBUG | CONTEXT_IA32_CONTROL)

#تعریف_کرو CONTEXT_EXCEPTION_فعال 0x8000000
#تعریف_کرو CONTEXT_SERVICE_فعال 0x10000000
#تعریف_کرو CONTEXT_EXCEPTION_REQUEST 0x40000000
#تعریف_کرو CONTEXT_EXCEPTION_REPORTING 0x80000000
#اگر_ختم

    قسمتعریف ساخت _CONTEXT {
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

    قسمتعریف ساخت _PLABEL_DESCRIPTOR {
      ULONGLONG اندراج_نقطہ;
      ULONGLONG Global_اشارہ_گر_2;
    } PLABEL_DESCRIPTOR,*PPLABEL_DESCRIPTOR;

    قسمتعریف ساخت _RUNTIME_FUNCTION {
      DWORD Begin_پتہ;
      DWORD انتہا_پتہ;
      DWORD Unwind_Info_پتہ;
    } RUNTIME_FUNCTION,*PRUNTIME_FUNCTION;

    قسمتعریف PRUNTIME_FUNCTION (*PGET_RUNTIME_FUNCTION_CALLBACK)(DWORD64 ControlPc,PVOID Context);
    قسمتعریف DWORD (*POUT_کا_PROCESS_FUNCTION_جدول_CALLBACK)(HANDLE Process,PVOID جدول_پتہ,PDWORD Entries,PRUNTIME_FUNCTION *Functions);

#تعریف_کرو برآمد_کا_PROCESS_FUNCTION_جدول_CALLBACK_EXPORT_NAME "OutOfProcessFunctionTableCallback"

    BOOLEAN Rtl_جوڑو_Function_جدول(PRUNTIME_FUNCTION Function_جدول,DWORD اندراج_گنتی,ULONGLONG بنیاد_پتہ,ULONGLONG ہدف_Gp);
    BOOLEAN Rtl_Install_Function_جدول_Callback(DWORD64 جدول_Identifier,DWORD64 بنیاد_پتہ,DWORD لمبائی_2,DWORD64 ہدف_Gp,PGET_RUNTIME_FUNCTION_CALLBACK Callback,PVOID Context,PCWSTR برآمد_کا_Process_Callback_Dll);
    BOOLEAN Rtl_Delete_Function_جدول(PRUNTIME_FUNCTION Function_جدول);
    VOID RtlRestoreContext (PCONTEXT Context_ریکارڈ,ساخت EXCEPTION_ریکارڈ *Exception_ریکارڈ);
    VOID __jump_unwind(ULONGLONG ہدف_Ms_چوکھٹا,ULONGLONG ہدف_Bs_چوکھٹا,ULONGLONG ہدف_Pc);
#اگر_ختم

#تعریف_کرو EXCEPTION_NONCONTINUABLE 0x1
#تعریف_کرو EXCEPTION_زیادہ_سے_زیادہ_PARAMETERS 15

    قسمتعریف ساخت EXCEPTION_ریکارڈ {
      DWORD Exception_رمز;
      DWORD ExceptionFlags;
      ساخت EXCEPTION_ریکارڈ *Exception_ریکارڈ;
      PVOID Exception_پتہ;
      DWORD نمبر_Parameters;
      ULONG_PTR ExceptionInformation[EXCEPTION_زیادہ_سے_زیادہ_PARAMETERS];
    } EXCEPTION_ریکارڈ_2;

    قسمتعریف EXCEPTION_ریکارڈ_2 *PEXCEPTION_ریکارڈ;

    قسمتعریف ساخت _EXCEPTION_RECORD32 {
      DWORD Exception_رمز;
      DWORD ExceptionFlags;
      DWORD Exception_ریکارڈ;
      DWORD Exception_پتہ;
      DWORD نمبر_Parameters;
      DWORD ExceptionInformation[EXCEPTION_زیادہ_سے_زیادہ_PARAMETERS];
    } EXCEPTION_RECORD32,*PEXCEPTION_RECORD32;

    قسمتعریف ساخت _EXCEPTION_RECORD64 {
      DWORD Exception_رمز;
      DWORD ExceptionFlags;
      DWORD64 Exception_ریکارڈ;
      DWORD64 Exception_پتہ;
      DWORD نمبر_Parameters;
      DWORD __unusedAlignment;
      DWORD64 ExceptionInformation[EXCEPTION_زیادہ_سے_زیادہ_PARAMETERS];
    } EXCEPTION_RECORD64,*PEXCEPTION_RECORD64;

    قسمتعریف ساخت EXCEPTION_اشارے_2 {
      PEXCEPTION_ریکارڈ Exception_ریکارڈ;
      PCONTEXT Context_ریکارڈ;
    } EXCEPTION_اشارے,*PEXCEPTION_اشارے;

#اگر_تعریف_شدہ __x86_64

    قسمتعریف EXCEPTION_DISPOSITION NTAPI EXCEPTION_ROUTINE (ساخت EXCEPTION_ریکارڈ *Exception_ریکارڈ, PVOID Establisher_چوکھٹا_2, ساخت _CONTEXT *Context_ریکارڈ, PVOID DispatcherContext);
#اگر_غیر_تعریف_شدہ __PEXCEPTION_ROUTINE_DEFINED
#تعریف_کرو __PEXCEPTION_ROUTINE_DEFINED
    قسمتعریف EXCEPTION_ROUTINE *PEXCEPTION_ROUTINE;
#اگر_ختم

    /* http://msdn.microsoft.com/en-us/library/ms680597(VS.85).aspx */

#تعریف_کرو UNWIND_HISTORY_جدول_سائز 12

  قسمتعریف ساخت UNWIND_HISTORY_جدول_اندراج {
    ULONG64 Image_بنیاد;
    PRUNTIME_FUNCTION Function_اندراج;
  } UNWIND_HISTORY_جدول_اندراج_2, *PUNWIND_HISTORY_جدول_اندراج;

#تعریف_کرو UNWIND_HISTORY_جدول_NONE    0
#تعریف_کرو UNWIND_HISTORY_جدول_GLOBAL  1
#تعریف_کرو UNWIND_HISTORY_جدول_LOCAL   2

  قسمتعریف ساخت UNWIND_HISTORY_جدول {
    ULONG گنتی_3;
    UCHAR تلاش;
    ULONG64 کم_پتہ;
    ULONG64 بلند_پتہ;
    UNWIND_HISTORY_جدول_اندراج_2 اندراج_2[UNWIND_HISTORY_جدول_سائز];
  } UNWIND_HISTORY_جدول_2, *PUNWIND_HISTORY_جدول;

  /* http://msdn.microsoft.com/en-us/library/b6sf5kbd(VS.80).aspx */

  ساخت _DISPATCHER_CONTEXT;
  قسمتعریف ساخت _DISPATCHER_CONTEXT DISPATCHER_CONTEXT;
  قسمتعریف ساخت _DISPATCHER_CONTEXT *PDISPATCHER_CONTEXT;

  ساخت _DISPATCHER_CONTEXT {
    ULONG64 ControlPc;
    ULONG64 Image_بنیاد;
    PRUNTIME_FUNCTION Function_اندراج;
    ULONG64 Establisher_چوکھٹا_2;
    ULONG64 ہدف_Ip;
    PCONTEXT Context_ریکارڈ;
    PEXCEPTION_ROUTINE LanguageHandler;
    PVOID Handler_ڈیٹا;
    /* http://www.nynaeve.net/?p=99 */
    PUNWIND_HISTORY_جدول History_جدول;
    ULONG Scope_اشاریہ;
    ULONG Fill0;
  };

  /* http://msdn.microsoft.com/en-us/library/ms680617(VS.85).aspx */

  قسمتعریف ساخت KNONVOLATILE_CONTEXT_اشارے
  {
    PM128A FloatingContext[16];
    PULONG64 IntegerContext[16];
  } KNONVOLATILE_CONTEXT_اشارے_2, *PKNONVOLATILE_CONTEXT_اشارے;
#اگر_ختم /* defined(__x86_64) */

    قسمتعریف PVOID PACCESS_TOKEN;
    قسمتعریف PVOID PSECURITY_DESCRIPTOR;
    قسمتعریف PVOID PSID;

    قسمتعریف DWORD ACCESS_نقاب;
    قسمتعریف ACCESS_نقاب *PACCESS_نقاب;

#تعریف_کرو DELETE (0x00010000L)
#تعریف_کرو READ_CONTROL (0x00020000L)
#تعریف_کرو WRITE_DAC (0x00040000L)
#تعریف_کرو WRITE_OWNER (0x00080000L)
#تعریف_کرو SYNCHRONIZE (0x00100000L)

#تعریف_کرو STANDARD_RIGHTS_REQUIRED (0x000F0000L)
#تعریف_کرو STANDARD_RIGHTS_READ (READ_CONTROL)
#تعریف_کرو STANDARD_RIGHTS_WRITE (READ_CONTROL)
#تعریف_کرو STANDARD_RIGHTS_EXECUTE (READ_CONTROL)
#تعریف_کرو STANDARD_RIGHTS_ALL (0x001F0000L)

#تعریف_کرو SPECIFIC_RIGHTS_ALL (0x0000FFFFL)

#تعریف_کرو ACCESS_SYSTEM_SECURITY (0x01000000L)

#تعریف_کرو زیادہ_سے_زیادہ_ALLOWED (0x02000000L)

#تعریف_کرو GENERIC_READ (0x80000000L)
#تعریف_کرو GENERIC_WRITE (0x40000000L)
#تعریف_کرو GENERIC_EXECUTE (0x20000000L)
#تعریف_کرو GENERIC_ALL (0x10000000L)

    قسمتعریف ساخت _GENERIC_MAPPING {
      ACCESS_نقاب GenericRead;
      ACCESS_نقاب GenericWrite;
      ACCESS_نقاب GenericExecute;
      ACCESS_نقاب GenericAll;
    } GENERIC_MAPPING;
    قسمتعریف GENERIC_MAPPING *PGENERIC_MAPPING;

#شامل <pshpack4.h>

    قسمتعریف ساخت LUID_AND_اوصاف {
      LUID Luid;
      DWORD اوصاف;
    } LUID_AND_اوصاف_2,*PLUID_AND_اوصاف;
    قسمتعریف LUID_AND_اوصاف_2 LUID_AND_اوصاف_ARRAY[ANYSIZE_ARRAY];
    قسمتعریف LUID_AND_اوصاف_ARRAY *PLUID_AND_اوصاف_ARRAY;

#شامل <poppack.h>

#اگر_غیر_تعریف_شدہ SID_IDENTIFIER_AUTHORITY_DEFINED
#تعریف_کرو SID_IDENTIFIER_AUTHORITY_DEFINED
    قسمتعریف ساخت _SID_IDENTIFIER_AUTHORITY {
      BYTE قدر_3[6];
    } SID_IDENTIFIER_AUTHORITY,*PSID_IDENTIFIER_AUTHORITY;
#اگر_ختم

#اگر_غیر_تعریف_شدہ SID_DEFINED
#تعریف_کرو SID_DEFINED
    قسمتعریف ساخت _SID {
      BYTE Revision;
      BYTE Sub_Authority_گنتی;
      SID_IDENTIFIER_AUTHORITY IdentifierAuthority;
      DWORD SubAuthority[ANYSIZE_ARRAY];
    } SID,*PISID;
#اگر_ختم

#تعریف_کرو SID_REVISION (1)
#تعریف_کرو SID_MAX_SUB_AUTHORITIES (15)
#تعریف_کرو SID_RECOMMENDED_SUB_AUTHORITIES (1)

#تعریف_کرو SECURITY_MAX_SID_سائز (حجم(SID) - حجم(DWORD) + (SID_MAX_SUB_AUTHORITIES *حجم(DWORD)))

    قسمتعریف شمار _SID_NAME_USE {
      SidTypeUser = 1,Sid_Type_گروہ,SidTypeDomain,SidTypeAlias,Sid_Type_Well_معلوم_گروہ,SidTypeDeletedAccount,SidTypeInvalid,SidTypeUnknown,SidTypeComputer
    } SID_NAME_USE,*PSID_NAME_USE;

    قسمتعریف ساخت SID_AND_اوصاف {
      PSID Sid;
      DWORD اوصاف;
    } SID_AND_اوصاف_2,*PSID_AND_اوصاف;

    قسمتعریف SID_AND_اوصاف_2 SID_AND_اوصاف_ARRAY[ANYSIZE_ARRAY];
    قسمتعریف SID_AND_اوصاف_ARRAY *PSID_AND_اوصاف_ARRAY;

#تعریف_کرو SECURITY_NULL_SID_AUTHORITY {0,0,0,0,0,0}
#تعریف_کرو SECURITY_WORLD_SID_AUTHORITY {0,0,0,0,0,1}
#تعریف_کرو SECURITY_LOCAL_SID_AUTHORITY {0,0,0,0,0,2}
#تعریف_کرو SECURITY_CREATOR_SID_AUTHORITY {0,0,0,0,0,3}
#تعریف_کرو SECURITY_NON_UNIQUE_AUTHORITY {0,0,0,0,0,4}
#تعریف_کرو SECURITY_RESOURCE_MANAGER_AUTHORITY {0,0,0,0,0,9}

#تعریف_کرو SECURITY_NULL_RID (0x00000000L)
#تعریف_کرو SECURITY_WORLD_RID (0x00000000L)
#تعریف_کرو SECURITY_LOCAL_RID (0x00000000L)

#تعریف_کرو SECURITY_CREATOR_OWNER_RID (0x00000000L)
#تعریف_کرو SECURITY_CREATOR_گروہ_RID (0x00000001L)

#تعریف_کرو SECURITY_CREATOR_OWNER_SERVER_RID (0x00000002L)
#تعریف_کرو SECURITY_CREATOR_گروہ_SERVER_RID (0x00000003L)

#تعریف_کرو SECURITY_NT_AUTHORITY {0,0,0,0,0,5}

#تعریف_کرو SECURITY_DIALUP_RID (0x00000001L)
#تعریف_کرو SECURITY_جال_RID (0x00000002L)
#تعریف_کرو SECURITY_BATCH_RID (0x00000003L)
#تعریف_کرو SECURITY_INTERACTIVE_RID (0x00000004L)
#تعریف_کرو SECURITY_LOGON_IDS_RID (0x00000005L)
#تعریف_کرو SECURITY_LOGON_IDS_RID_گنتی (3L)
#تعریف_کرو SECURITY_SERVICE_RID (0x00000006L)
#تعریف_کرو SECURITY_ANONYMOUS_LOGON_RID (0x00000007L)
#تعریف_کرو SECURITY_PROXY_RID (0x00000008L)
#تعریف_کرو SECURITY_ENTERPRISE_CONTROLLERS_RID (0x00000009L)
#تعریف_کرو SECURITY_SERVER_LOGON_RID SECURITY_ENTERPRISE_CONTROLLERS_RID
#تعریف_کرو SECURITY_PRINCIPAL_SELF_RID (0x0000000AL)
#تعریف_کرو SECURITY_AUTHENTICATED_USER_RID (0x0000000BL)
#تعریف_کرو SECURITY_RESTRICTED_رمز_RID (0x0000000CL)
#تعریف_کرو SECURITY_TERMINAL_SERVER_RID (0x0000000DL)
#تعریف_کرو SECURITY_REMOTE_LOGON_RID (0x0000000EL)
#تعریف_کرو SECURITY_THIS_ORGANIZATION_RID (0x0000000FL)
#تعریف_کرو SECURITY_IUSER_RID (0x00000011L)

#تعریف_کرو SECURITY_LOCAL_SYSTEM_RID (0x00000012L)
#تعریف_کرو SECURITY_LOCAL_SERVICE_RID (0x00000013L)
#تعریف_کرو SECURITY_جال_SERVICE_RID (0x00000014L)

#تعریف_کرو SECURITY_NT_NON_UNIQUE (0x00000015L)
#تعریف_کرو SECURITY_NT_NON_UNIQUE_SUB_AUTH_گنتی (3L)

#تعریف_کرو SECURITY_ENTERPRISE_READONLY_CONTROLLERS_RID (0x00000016L)

#تعریف_کرو SECURITY_BUILTIN_DOMAIN_RID (0x00000020L)
#تعریف_کرو SECURITY_WRITE_RESTRICTED_رمز_RID (0x00000021L)

#تعریف_کرو SECURITY_PACKAGE_بنیاد_RID (0x00000040L)
#تعریف_کرو SECURITY_PACKAGE_RID_گنتی (2L)
#تعریف_کرو SECURITY_PACKAGE_NTLM_RID (0x0000000AL)
#تعریف_کرو SECURITY_PACKAGE_SCHANNEL_RID (0x0000000EL)
#تعریف_کرو SECURITY_PACKAGE_DIGEST_RID (0x00000015L)

#تعریف_کرو SECURITY_SERVICE_ID_بنیاد_RID (0x00000050L)
#تعریف_کرو SECURITY_SERVICE_ID_RID_گنتی (6L)

#تعریف_کرو SECURITY_RESERVED_ID_بنیاد_RID (0x00000051L)

#تعریف_کرو SECURITY_MAX_ALWAYS_FILTERED (0x000003E7L)
#تعریف_کرو SECURITY_MIN_NEVER_FILTERED (0x000003E8L)

#تعریف_کرو SECURITY_OTHER_ORGANIZATION_RID (0x000003E8L)

#تعریف_کرو FOREST_USER_RID_MAX (0x000001F3L)

#تعریف_کرو DOMAIN_USER_RID_ADMIN (0x000001F4L)
#تعریف_کرو DOMAIN_USER_RID_GUEST (0x000001F5L)
#تعریف_کرو DOMAIN_USER_RID_KRBTGT (0x000001F6L)

#تعریف_کرو DOMAIN_USER_RID_MAX (0x000003E7L)

#تعریف_کرو DOMAIN_گروہ_RID_ADMINS (0x00000200L)
#تعریف_کرو DOMAIN_گروہ_RID_USERS (0x00000201L)
#تعریف_کرو DOMAIN_گروہ_RID_GUESTS (0x00000202L)
#تعریف_کرو DOMAIN_گروہ_RID_COMPUTERS (0x00000203L)
#تعریف_کرو DOMAIN_گروہ_RID_CONTROLLERS (0x00000204L)
#تعریف_کرو DOMAIN_گروہ_RID_CERT_ADMINS (0x00000205L)
#تعریف_کرو DOMAIN_گروہ_RID_SCHEMA_ADMINS (0x00000206L)
#تعریف_کرو DOMAIN_گروہ_RID_ENTERPRISE_ADMINS (0x00000207L)
#تعریف_کرو DOMAIN_گروہ_RID_POLICY_ADMINS (0x00000208L)
#تعریف_کرو DOMAIN_گروہ_RID_READONLY_CONTROLLERS (0x00000209L)

#تعریف_کرو DOMAIN_ALIAS_RID_ADMINS (0x00000220L)
#تعریف_کرو DOMAIN_ALIAS_RID_USERS (0x00000221L)
#تعریف_کرو DOMAIN_ALIAS_RID_GUESTS (0x00000222L)
#تعریف_کرو DOMAIN_ALIAS_RID_POWER_USERS (0x00000223L)

#تعریف_کرو DOMAIN_ALIAS_RID_ACCOUNT_OPS (0x00000224L)
#تعریف_کرو DOMAIN_ALIAS_RID_SYSTEM_OPS (0x00000225L)
#تعریف_کرو DOMAIN_ALIAS_RID_PRINT_OPS (0x00000226L)
#تعریف_کرو DOMAIN_ALIAS_RID_BACKUP_OPS (0x00000227L)

#تعریف_کرو DOMAIN_ALIAS_RID_REPLICATOR (0x00000228L)
#تعریف_کرو DOMAIN_ALIAS_RID_RAS_SERVERS (0x00000229L)
#تعریف_کرو DOMAIN_ALIAS_RID_PREW2KCOMPACCESS (0x0000022AL)
#تعریف_کرو DOMAIN_ALIAS_RID_REMOTE_DESKTOP_USERS (0x0000022BL)
#تعریف_کرو DOMAIN_ALIAS_RID_جال_CONFIGURATION_OPS (0x0000022CL)
#تعریف_کرو DOMAIN_ALIAS_RID_INCOMING_FOREST_TRUST_BUILDERS (0x0000022DL)

#تعریف_کرو DOMAIN_ALIAS_RID_MONITORING_USERS (0x0000022EL)
#تعریف_کرو DOMAIN_ALIAS_RID_LOGGING_USERS (0x0000022FL)
#تعریف_کرو DOMAIN_ALIAS_RID_AUTHORIZATIONACCESS (0x00000230L)
#تعریف_کرو DOMAIN_ALIAS_RID_TS_LICENSE_SERVERS (0x00000231L)
#تعریف_کرو DOMAIN_ALIAS_RID_DCOM_USERS (0x00000232L)

#تعریف_کرو DOMAIN_ALIAS_RID_IUSERS (0x00000238L)
#تعریف_کرو DOMAIN_ALIAS_RID_CRYPTO_OPERATORS (0x00000239L)
#تعریف_کرو DOMAIN_ALIAS_RID_CACHEABLE_PRINCIPALS_گروہ (0x0000023BL)
#تعریف_کرو DOMAIN_ALIAS_RID_NON_CACHEABLE_PRINCIPALS_گروہ (0x0000023CL)
#تعریف_کرو DOMAIN_ALIAS_RID_EVENT_LOG_READERS_گروہ (0x0000023DL)

#تعریف_کرو SECURITY_MANDATORY_LABEL_AUTHORITY {0,0,0,0,0,16}
#تعریف_کرو SECURITY_MANDATORY_UNTRUSTED_RID (0x00000000L)
#تعریف_کرو SECURITY_MANDATORY_کم_RID (0x00001000L)
#تعریف_کرو SECURITY_MANDATORY_MEDIUM_RID (0x00002000L)
#تعریف_کرو SECURITY_MANDATORY_بلند_RID (0x00003000L)
#تعریف_کرو SECURITY_MANDATORY_SYSTEM_RID (0x00004000L)
#تعریف_کرو SECURITY_MANDATORY_PROTECTED_PROCESS_RID (0x00005000L)

#تعریف_کرو SECURITY_MANDATORY_زیادہ_سے_زیادہ_USER_RID SECURITY_MANDATORY_SYSTEM_RID

#تعریف_کرو MANDATORY_LEVEL_مقصد_MANDATORY_RID(IL) (IL * 0x1000)

    قسمتعریف شمار {
      WinNullSid = 0,WinWorldSid = 1,WinLocalSid = 2,WinCreatorOwnerSid = 3,Win_Creator_گروہ_Sid = 4,WinCreatorOwnerServerSid = 5,Win_Creator_گروہ_Server_Sid = 6,WinNtAuthoritySid = 7,WinDialupSid = 8,Win_جال_Sid = 9,WinBatchSid = 10,WinInteractiveSid = 11,WinServiceSid = 12,WinAnonymousSid = 13,WinProxySid = 14,WinEnterpriseControllersSid = 15,WinSelfSid = 16,WinAuthenticatedUserSid = 17,Win_Restricted_رمز_Sid = 18,WinTerminalServerSid = 19,WinRemoteLogonIdSid = 20,WinLogonIdsSid = 21,WinLocalSystemSid = 22,WinLocalServiceSid = 23,Win_جال_Service_Sid = 24,WinBuiltinDomainSid = 25,WinBuiltinAdministratorsSid = 26,WinBuiltinUsersSid = 27,WinBuiltinGuestsSid = 28,WinBuiltinPowerUsersSid = 29,WinBuiltinAccountOperatorsSid = 30,WinBuiltinSystemOperatorsSid = 31,WinBuiltinPrintOperatorsSid = 32,WinBuiltinBackupOperatorsSid = 33,WinBuiltinReplicatorSid = 34,WinBuiltinPreWindows2000CompatibleAccessSid = 35,WinBuiltinRemoteDesktopUsersSid = 36,Win_Builtin_جال_Configuration_Operators_Sid = 37,WinAccountAdministratorSid = 38,WinAccountGuestSid = 39,WinAccountKrbtgtSid = 40,WinAccountDomainAdminsSid = 41,WinAccountDomainUsersSid = 42,WinAccountDomainGuestsSid = 43,WinAccountComputersSid = 44,WinAccountControllersSid = 45,WinAccountCertAdminsSid = 46,WinAccountSchemaAdminsSid = 47,WinAccountEnterpriseAdminsSid = 48,WinAccountPolicyAdminsSid = 49,WinAccountRasAndIasServersSid = 50,WinNTLMAuthenticationSid = 51,WinDigestAuthenticationSid = 52,WinSChannelAuthenticationSid = 53,WinThisOrganizationSid = 54,WinOtherOrganizationSid = 55,WinBuiltinIncomingForestTrustBuildersSid = 56,WinBuiltinPerfMonitoringUsersSid = 57,WinBuiltinPerfLoggingUsersSid = 58,WinBuiltinAuthorizationAccessSid = 59,WinBuiltinTerminalServerLicenseServersSid = 60,WinBuiltinDCOMUsersSid = 61
    } WELL_معلوم_SID_TYPE;

#تعریف_کرو SYSTEM_LUID { 0x3E7,0x0 }
#تعریف_کرو ANONYMOUS_LOGON_LUID { 0x3e6,0x0 }
#تعریف_کرو LOCALSERVICE_LUID { 0x3e5,0x0 }
#تعریف_کرو NETWORKSERVICE_LUID { 0x3e4,0x0 }
#تعریف_کرو IUSER_LUID { 0x3e3, 0x0 }

#تعریف_کرو SE_گروہ_MANDATORY (0x00000001L)
#تعریف_کرو SE_گروہ_ENABLED_BY_DEFAULT (0x00000002L)
#تعریف_کرو SE_گروہ_ENABLED (0x00000004L)
#تعریف_کرو SE_گروہ_OWNER (0x00000008L)
#تعریف_کرو SE_گروہ_USE_FOR_DENY_ONLY (0x00000010L)
#تعریف_کرو SE_گروہ_INTEGRITY (0x00000020L)
#تعریف_کرو SE_گروہ_INTEGRITY_ENABLED (0x00000040L)
#تعریف_کرو SE_گروہ_LOGON_ID (0xC0000000L)
#تعریف_کرو SE_گروہ_RESOURCE (0x20000000L)

#تعریف_کرو ACL_REVISION (2)
#تعریف_کرو ACL_REVISION_DS (4)

#تعریف_کرو ACL_REVISION1 (1)
#تعریف_کرو MIN_ACL_REVISION ACL_REVISION2
#تعریف_کرو ACL_REVISION2 (2)
#تعریف_کرو ACL_REVISION3 (3)
#تعریف_کرو ACL_REVISION4 (4)
#تعریف_کرو MAX_ACL_REVISION ACL_REVISION4

    قسمتعریف ساخت _ACL {
      BYTE AclRevision;
      BYTE Sbz1;
      لفظ_3 Acl_سائز;
      لفظ_3 Ace_گنتی;
      لفظ_3 Sbz2;
    } ACL;
    قسمتعریف ACL *PACL;

    قسمتعریف ساخت ACE_سرخی {
      BYTE AceType;
      BYTE AceFlags;
      لفظ_3 Ace_سائز;
    } ACE_سرخی_2;
    قسمتعریف ACE_سرخی_2 *PACE_سرخی;

#تعریف_کرو ACCESS_MIN_MS_ACE_TYPE (0x0)
#تعریف_کرو ACCESS_ALLOWED_ACE_TYPE (0x0)
#تعریف_کرو ACCESS_DENIED_ACE_TYPE (0x1)
#تعریف_کرو SYSTEM_AUDIT_ACE_TYPE (0x2)
#تعریف_کرو SYSTEM_ALARM_ACE_TYPE (0x3)
#تعریف_کرو ACCESS_MAX_MS_V2_ACE_TYPE (0x3)

#تعریف_کرو ACCESS_ALLOWED_COMPOUND_ACE_TYPE (0x4)
#تعریف_کرو ACCESS_MAX_MS_V3_ACE_TYPE (0x4)

#تعریف_کرو ACCESS_MIN_MS_OBJECT_ACE_TYPE (0x5)
#تعریف_کرو ACCESS_ALLOWED_OBJECT_ACE_TYPE (0x5)
#تعریف_کرو ACCESS_DENIED_OBJECT_ACE_TYPE (0x6)
#تعریف_کرو SYSTEM_AUDIT_OBJECT_ACE_TYPE (0x7)
#تعریف_کرو SYSTEM_ALARM_OBJECT_ACE_TYPE (0x8)
#تعریف_کرو ACCESS_MAX_MS_OBJECT_ACE_TYPE (0x8)

#تعریف_کرو ACCESS_MAX_MS_V4_ACE_TYPE (0x8)
#تعریف_کرو ACCESS_MAX_MS_ACE_TYPE (0x8)

#تعریف_کرو ACCESS_ALLOWED_CALLBACK_ACE_TYPE (0x9)
#تعریف_کرو ACCESS_DENIED_CALLBACK_ACE_TYPE (0xA)
#تعریف_کرو ACCESS_ALLOWED_CALLBACK_OBJECT_ACE_TYPE (0xB)
#تعریف_کرو ACCESS_DENIED_CALLBACK_OBJECT_ACE_TYPE (0xC)
#تعریف_کرو SYSTEM_AUDIT_CALLBACK_ACE_TYPE (0xD)
#تعریف_کرو SYSTEM_ALARM_CALLBACK_ACE_TYPE (0xE)
#تعریف_کرو SYSTEM_AUDIT_CALLBACK_OBJECT_ACE_TYPE (0xF)
#تعریف_کرو SYSTEM_ALARM_CALLBACK_OBJECT_ACE_TYPE (0x10)

#تعریف_کرو SYSTEM_MANDATORY_LABEL_ACE_TYPE (0x11)
#تعریف_کرو ACCESS_MAX_MS_V5_ACE_TYPE (0x11)

#تعریف_کرو OBJECT_INHERIT_ACE (0x1)
#تعریف_کرو CONTAINER_INHERIT_ACE (0x2)
#تعریف_کرو NO_PROPAGATE_INHERIT_ACE (0x4)
#تعریف_کرو INHERIT_ONLY_ACE (0x8)
#تعریف_کرو INHERITED_ACE (0x10)
#تعریف_کرو VALID_INHERIT_FLAGS (0x1F)

#تعریف_کرو SUCCESSFUL_ACCESS_ACE_FLAG (0x40)
#تعریف_کرو FAILED_ACCESS_ACE_FLAG (0x80)

    قسمتعریف ساخت _ACCESS_ALLOWED_ACE {
      ACE_سرخی_2 سرخی_2;
      ACCESS_نقاب نقاب_3;
      DWORD Sid_آغاز;
    } ACCESS_ALLOWED_ACE;

    قسمتعریف ACCESS_ALLOWED_ACE *PACCESS_ALLOWED_ACE;

    قسمتعریف ساخت _ACCESS_DENIED_ACE {
      ACE_سرخی_2 سرخی_2;
      ACCESS_نقاب نقاب_3;
      DWORD Sid_آغاز;
    } ACCESS_DENIED_ACE;
    قسمتعریف ACCESS_DENIED_ACE *PACCESS_DENIED_ACE;

    قسمتعریف ساخت _SYSTEM_AUDIT_ACE {
      ACE_سرخی_2 سرخی_2;
      ACCESS_نقاب نقاب_3;
      DWORD Sid_آغاز;
    } SYSTEM_AUDIT_ACE;
    قسمتعریف SYSTEM_AUDIT_ACE *PSYSTEM_AUDIT_ACE;

    قسمتعریف ساخت _SYSTEM_ALARM_ACE {
      ACE_سرخی_2 سرخی_2;
      ACCESS_نقاب نقاب_3;
      DWORD Sid_آغاز;
    } SYSTEM_ALARM_ACE;
    قسمتعریف SYSTEM_ALARM_ACE *PSYSTEM_ALARM_ACE;

    قسمتعریف ساخت _ACCESS_ALLOWED_OBJECT_ACE {
      ACE_سرخی_2 سرخی_2;
      ACCESS_نقاب نقاب_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_آغاز;
    } ACCESS_ALLOWED_OBJECT_ACE,*PACCESS_ALLOWED_OBJECT_ACE;

    قسمتعریف ساخت _ACCESS_DENIED_OBJECT_ACE {
      ACE_سرخی_2 سرخی_2;
      ACCESS_نقاب نقاب_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_آغاز;
    } ACCESS_DENIED_OBJECT_ACE,*PACCESS_DENIED_OBJECT_ACE;

    قسمتعریف ساخت _SYSTEM_AUDIT_OBJECT_ACE {
      ACE_سرخی_2 سرخی_2;
      ACCESS_نقاب نقاب_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_آغاز;
    } SYSTEM_AUDIT_OBJECT_ACE,*PSYSTEM_AUDIT_OBJECT_ACE;

    قسمتعریف ساخت _SYSTEM_ALARM_OBJECT_ACE {
      ACE_سرخی_2 سرخی_2;
      ACCESS_نقاب نقاب_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_آغاز;
    } SYSTEM_ALARM_OBJECT_ACE,*PSYSTEM_ALARM_OBJECT_ACE;

    قسمتعریف ساخت _ACCESS_ALLOWED_CALLBACK_ACE {
      ACE_سرخی_2 سرخی_2;
      ACCESS_نقاب نقاب_3;
      DWORD Sid_آغاز;

    } ACCESS_ALLOWED_CALLBACK_ACE,*PACCESS_ALLOWED_CALLBACK_ACE;

    قسمتعریف ساخت _ACCESS_DENIED_CALLBACK_ACE {
      ACE_سرخی_2 سرخی_2;
      ACCESS_نقاب نقاب_3;
      DWORD Sid_آغاز;

    } ACCESS_DENIED_CALLBACK_ACE,*PACCESS_DENIED_CALLBACK_ACE;

    قسمتعریف ساخت _SYSTEM_AUDIT_CALLBACK_ACE {
      ACE_سرخی_2 سرخی_2;
      ACCESS_نقاب نقاب_3;
      DWORD Sid_آغاز;

    } SYSTEM_AUDIT_CALLBACK_ACE,*PSYSTEM_AUDIT_CALLBACK_ACE;

    قسمتعریف ساخت _SYSTEM_ALARM_CALLBACK_ACE {
      ACE_سرخی_2 سرخی_2;
      ACCESS_نقاب نقاب_3;
      DWORD Sid_آغاز;

    } SYSTEM_ALARM_CALLBACK_ACE,*PSYSTEM_ALARM_CALLBACK_ACE;

    قسمتعریف ساخت _ACCESS_ALLOWED_CALLBACK_OBJECT_ACE {
      ACE_سرخی_2 سرخی_2;
      ACCESS_نقاب نقاب_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_آغاز;

    } ACCESS_ALLOWED_CALLBACK_OBJECT_ACE,*PACCESS_ALLOWED_CALLBACK_OBJECT_ACE;

    قسمتعریف ساخت _ACCESS_DENIED_CALLBACK_OBJECT_ACE {
      ACE_سرخی_2 سرخی_2;
      ACCESS_نقاب نقاب_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_آغاز;

    } ACCESS_DENIED_CALLBACK_OBJECT_ACE,*PACCESS_DENIED_CALLBACK_OBJECT_ACE;

    قسمتعریف ساخت _SYSTEM_AUDIT_CALLBACK_OBJECT_ACE {
      ACE_سرخی_2 سرخی_2;
      ACCESS_نقاب نقاب_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_آغاز;

    } SYSTEM_AUDIT_CALLBACK_OBJECT_ACE,*PSYSTEM_AUDIT_CALLBACK_OBJECT_ACE;

    قسمتعریف ساخت _SYSTEM_ALARM_CALLBACK_OBJECT_ACE {
      ACE_سرخی_2 سرخی_2;
      ACCESS_نقاب نقاب_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_آغاز;

    } SYSTEM_ALARM_CALLBACK_OBJECT_ACE,*PSYSTEM_ALARM_CALLBACK_OBJECT_ACE;

#تعریف_کرو ACE_OBJECT_TYPE_PRESENT 0x1
#تعریف_کرو ACE_INHERITED_OBJECT_TYPE_PRESENT 0x2

    قسمتعریف شمار _ACL_INFORMATION_CLASS {
      AclRevisionInformation = 1,Acl_سائز_Information
    } ACL_INFORMATION_CLASS;

    قسمتعریف ساخت _ACL_REVISION_INFORMATION {
      DWORD AclRevision;
    } ACL_REVISION_INFORMATION;
    قسمتعریف ACL_REVISION_INFORMATION *PACL_REVISION_INFORMATION;

    قسمتعریف ساخت ACL_سائز_INFORMATION {
      DWORD Ace_گنتی;
      DWORD Acl_بائٹیں_اندر_Use;
      DWORD Acl_بائٹیں_Free;
    } ACL_سائز_INFORMATION_2;
    قسمتعریف ACL_سائز_INFORMATION_2 *PACL_سائز_INFORMATION;

#تعریف_کرو SECURITY_DESCRIPTOR_REVISION (1)
#تعریف_کرو SECURITY_DESCRIPTOR_REVISION1 (1)

#تعریف_کرو SECURITY_DESCRIPTOR_MIN_لمبائی (حجم(SECURITY_DESCRIPTOR))

    قسمتعریف لفظ_3 SECURITY_DESCRIPTOR_CONTROL,*PSECURITY_DESCRIPTOR_CONTROL;

#تعریف_کرو SE_OWNER_DEFAULTED (0x0001)
#تعریف_کرو SE_گروہ_DEFAULTED (0x0002)
#تعریف_کرو SE_DACL_PRESENT (0x0004)
#تعریف_کرو SE_DACL_DEFAULTED (0x0008)
#تعریف_کرو SE_SACL_PRESENT (0x0010)
#تعریف_کرو SE_SACL_DEFAULTED (0x0020)
#تعریف_کرو SE_DACL_AUTO_INHERIT_REQ (0x0100)
#تعریف_کرو SE_SACL_AUTO_INHERIT_REQ (0x0200)
#تعریف_کرو SE_DACL_AUTO_INHERITED (0x0400)
#تعریف_کرو SE_SACL_AUTO_INHERITED (0x0800)
#تعریف_کرو SE_DACL_PROTECTED (0x1000)
#تعریف_کرو SE_SACL_PROTECTED (0x2000)
#تعریف_کرو SE_RM_CONTROL_VALID (0x4000)
#تعریف_کرو SE_SELF_RELATIVE (0x8000)

    قسمتعریف ساخت _SECURITY_DESCRIPTOR_RELATIVE {
      BYTE Revision;
      BYTE Sbz1;
      SECURITY_DESCRIPTOR_CONTROL Control;
      DWORD Owner;
      DWORD گروہ_2;
      DWORD Sacl;
      DWORD Dacl;
    } SECURITY_DESCRIPTOR_RELATIVE,*PISECURITY_DESCRIPTOR_RELATIVE;

    قسمتعریف ساخت _SECURITY_DESCRIPTOR {
      BYTE Revision;
      BYTE Sbz1;
      SECURITY_DESCRIPTOR_CONTROL Control;
      PSID Owner;
      PSID گروہ_2;
      PACL Sacl;
      PACL Dacl;

    } SECURITY_DESCRIPTOR,*PISECURITY_DESCRIPTOR;

    قسمتعریف ساخت _OBJECT_TYPE_LIST {
      لفظ_3 Level;
      لفظ_3 Sbz;
      GUID *ObjectType;
    } OBJECT_TYPE_LIST,*POBJECT_TYPE_LIST;

#تعریف_کرو ACCESS_OBJECT_GUID 0
#تعریف_کرو ACCESS_PROPERTY_سیٹ_GUID 1
#تعریف_کرو ACCESS_PROPERTY_GUID 2

#تعریف_کرو ACCESS_MAX_LEVEL 4

    قسمتعریف شمار _AUDIT_EVENT_TYPE {
      AuditEventObjectAccess,AuditEventDirectoryServiceAccess
    } AUDIT_EVENT_TYPE,*PAUDIT_EVENT_TYPE;

#تعریف_کرو AUDIT_ALLOW_NO_PRIVILEGE 0x1

#تعریف_کرو ACCESS_DS_ماخذ_A "DS"
#تعریف_کرو ACCESS_DS_ماخذ_W L"DS"
#تعریف_کرو ACCESS_DS_OBJECT_TYPE_NAME_A "Directory Service Object"
#تعریف_کرو ACCESS_DS_OBJECT_TYPE_NAME_W L"Directory Service Object"

#تعریف_کرو SE_PRIVILEGE_ENABLED_BY_DEFAULT (0x00000001L)
#تعریف_کرو SE_PRIVILEGE_ENABLED (0x00000002L)
#تعریف_کرو SE_PRIVILEGE_REMOVED (0X00000004L)
#تعریف_کرو SE_PRIVILEGE_مستعمل_FOR_ACCESS (0x80000000L)

#تعریف_کرو PRIVILEGE_سیٹ_ALL_NECESSARY (1)

    قسمتعریف ساخت PRIVILEGE_سیٹ {
      DWORD Privilege_گنتی;
      DWORD Control;
      LUID_AND_اوصاف_2 Privilege[ANYSIZE_ARRAY];
    } PRIVILEGE_سیٹ_2,*PPRIVILEGE_سیٹ;

#تعریف_کرو SE_CREATE_TOKEN_NAME متن_3("SeCreateTokenPrivilege")
#تعریف_کرو SE_ASSIGNPRIMARYTOKEN_NAME متن_3("SeAssignPrimaryTokenPrivilege")
#تعریف_کرو SE_تالا_حافظہ_NAME متن_3("SeLockMemoryPrivilege")
#تعریف_کرو SE_INCREASE_QUOTA_NAME متن_3("SeIncreaseQuotaPrivilege")
#تعریف_کرو SE_UNSOLICITED_داخلہ_NAME متن_3("SeUnsolicitedInputPrivilege")
#تعریف_کرو SE_MACHINE_ACCOUNT_NAME متن_3("SeMachineAccountPrivilege")
#تعریف_کرو SE_TCB_NAME متن_3("SeTcbPrivilege")
#تعریف_کرو SE_SECURITY_NAME متن_3("SeSecurityPrivilege")
#تعریف_کرو SE_TAKE_OWNERSHIP_NAME متن_3("SeTakeOwnershipPrivilege")
#تعریف_کرو SE_بھرو_DRIVER_NAME متن_3("SeLoadDriverPrivilege")
#تعریف_کرو SE_SYSTEM_PROFILE_NAME متن_3("SeSystemProfilePrivilege")
#تعریف_کرو SE_SYSTEMTIME_NAME متن_3("SeSystemtimePrivilege")
#تعریف_کرو SE_PROF_SINGLE_PROCESS_NAME متن_3("SeProfileSingleProcessPrivilege")
#تعریف_کرو SE_INC_بنیاد_ترجیح_NAME متن_3("SeIncreaseBasePriorityPrivilege")
#تعریف_کرو SE_CREATE_PAGEFILE_NAME متن_3("SeCreatePagefilePrivilege")
#تعریف_کرو SE_CREATE_PERMANENT_NAME متن_3("SeCreatePermanentPrivilege")
#تعریف_کرو SE_BACKUP_NAME متن_3("SeBackupPrivilege")
#تعریف_کرو SE_RESTORE_NAME متن_3("SeRestorePrivilege")
#تعریف_کرو SE_SHUTDOWN_NAME متن_3("SeShutdownPrivilege")
#تعریف_کرو SE_DEBUG_NAME متن_3("SeDebugPrivilege")
#تعریف_کرو SE_AUDIT_NAME متن_3("SeAuditPrivilege")
#تعریف_کرو SE_SYSTEM_ENVIRONMENT_NAME متن_3("SeSystemEnvironmentPrivilege")
#تعریف_کرو SE_CHANGE_NOTIFY_NAME متن_3("SeChangeNotifyPrivilege")
#تعریف_کرو SE_REMOTE_SHUTDOWN_NAME متن_3("SeRemoteShutdownPrivilege")
#تعریف_کرو SE_UNDOCK_NAME متن_3("SeUndockPrivilege")
#تعریف_کرو SE_SYNC_AGENT_NAME متن_3("SeSyncAgentPrivilege")
#تعریف_کرو SE_ENABLE_DELEGATION_NAME متن_3("SeEnableDelegationPrivilege")
#تعریف_کرو SE_MANAGE_VOLUME_NAME متن_3("SeManageVolumePrivilege")
#تعریف_کرو SE_IMPERSONATE_NAME متن_3("SeImpersonatePrivilege")
#تعریف_کرو SE_CREATE_GLOBAL_NAME متن_3("SeCreateGlobalPrivilege")

    قسمتعریف شمار _SECURITY_IMPERSONATION_LEVEL {
      SecurityAnonymous,SecurityIdentification,SecurityImpersonation,SecurityDelegation
    } SECURITY_IMPERSONATION_LEVEL,*PSECURITY_IMPERSONATION_LEVEL;

#تعریف_کرو SECURITY_MAX_IMPERSONATION_LEVEL SecurityDelegation
#تعریف_کرو SECURITY_MIN_IMPERSONATION_LEVEL SecurityAnonymous
#تعریف_کرو DEFAULT_IMPERSONATION_LEVEL SecurityImpersonation
#تعریف_کرو VALID_IMPERSONATION_LEVEL(L) (((L) >= SECURITY_MIN_IMPERSONATION_LEVEL) && ((L) <= SECURITY_MAX_IMPERSONATION_LEVEL))

#تعریف_کرو TOKEN_تفویض_PRIMARY (0x0001)
#تعریف_کرو TOKEN_DUPLICATE (0x0002)
#تعریف_کرو TOKEN_IMPERSONATE (0x0004)
#تعریف_کرو TOKEN_QUERY (0x0008)
#تعریف_کرو TOKEN_QUERY_ماخذ (0x0010)
#تعریف_کرو TOKEN_ADJUST_PRIVILEGES (0x0020)
#تعریف_کرو TOKEN_ADJUST_GROUPS (0x0040)
#تعریف_کرو TOKEN_ADJUST_DEFAULT (0x0080)
#تعریف_کرو TOKEN_ADJUST_SESSIONID (0x0100)

#تعریف_کرو TOKEN_ALL_ACCESS_P (STANDARD_RIGHTS_REQUIRED | TOKEN_تفویض_PRIMARY | TOKEN_DUPLICATE | TOKEN_IMPERSONATE | TOKEN_QUERY | TOKEN_QUERY_ماخذ | TOKEN_ADJUST_PRIVILEGES | TOKEN_ADJUST_GROUPS | TOKEN_ADJUST_DEFAULT)
#تعریف_کرو TOKEN_ALL_ACCESS (TOKEN_ALL_ACCESS_P | TOKEN_ADJUST_SESSIONID)
#تعریف_کرو TOKEN_READ (STANDARD_RIGHTS_READ | TOKEN_QUERY)

#تعریف_کرو TOKEN_WRITE (STANDARD_RIGHTS_WRITE | TOKEN_ADJUST_PRIVILEGES | TOKEN_ADJUST_GROUPS | TOKEN_ADJUST_DEFAULT)

#تعریف_کرو TOKEN_EXECUTE (STANDARD_RIGHTS_EXECUTE)

    قسمتعریف شمار _TOKEN_TYPE {
      TokenPrimary = 1,TokenImpersonation
    } TOKEN_TYPE;
    قسمتعریف TOKEN_TYPE *PTOKEN_TYPE;

    قسمتعریف شمار _TOKEN_INFORMATION_CLASS {
      TokenUser = 1,TokenGroups,TokenPrivileges,TokenOwner,Token_Primary_گروہ,TokenDefaultDacl,Token_ماخذ,TokenType,TokenImpersonationLevel,
      TokenStatistics,TokenRestrictedSids,TokenSessionId,TokenGroupsAndPrivileges,TokenSessionReference,TokenSandBoxInert,TokenAuditPolicy,
      TokenOrigin,MaxTokenInfoClass
    } TOKEN_INFORMATION_CLASS,*PTOKEN_INFORMATION_CLASS;

    قسمتعریف ساخت _TOKEN_USER {
      SID_AND_اوصاف_2 User;
    } TOKEN_USER,*PTOKEN_USER;

    قسمتعریف ساخت _TOKEN_GROUPS {
      DWORD گروہ_گنتی;
      SID_AND_اوصاف_2 Groups[ANYSIZE_ARRAY];
    } TOKEN_GROUPS,*PTOKEN_GROUPS;

    قسمتعریف ساخت _TOKEN_PRIVILEGES {
      DWORD Privilege_گنتی;
      LUID_AND_اوصاف_2 Privileges[ANYSIZE_ARRAY];
    } TOKEN_PRIVILEGES,*PTOKEN_PRIVILEGES;

    قسمتعریف ساخت _TOKEN_OWNER {
      PSID Owner;
    } TOKEN_OWNER,*PTOKEN_OWNER;

    قسمتعریف ساخت TOKEN_PRIMARY_گروہ {
      PSID Primary_گروہ;
    } TOKEN_PRIMARY_گروہ_2,*PTOKEN_PRIMARY_گروہ;

    قسمتعریف ساخت _TOKEN_DEFAULT_DACL {
      PACL DefaultDacl;
    } TOKEN_DEFAULT_DACL,*PTOKEN_DEFAULT_DACL;

    قسمتعریف ساخت _TOKEN_GROUPS_AND_PRIVILEGES {
      DWORD Sid_گنتی;
      DWORD Sid_لمبائی;
      PSID_AND_اوصاف Sids;
      DWORD Restricted_Sid_گنتی;
      DWORD Restricted_Sid_لمبائی;
      PSID_AND_اوصاف RestrictedSids;
      DWORD Privilege_گنتی;
      DWORD Privilege_لمبائی;
      PLUID_AND_اوصاف Privileges;
      LUID AuthenticationId;
    } TOKEN_GROUPS_AND_PRIVILEGES,*PTOKEN_GROUPS_AND_PRIVILEGES;

#تعریف_کرو TOKEN_AUDIT_SUCCESS_INCLUDE 0x1
#تعریف_کرو TOKEN_AUDIT_SUCCESS_EXCLUDE 0x2
#تعریف_کرو TOKEN_AUDIT_FAILURE_INCLUDE 0x4
#تعریف_کرو TOKEN_AUDIT_FAILURE_EXCLUDE 0x8

#تعریف_کرو VALID_AUDIT_POLICY_بٹ (TOKEN_AUDIT_SUCCESS_INCLUDE | TOKEN_AUDIT_SUCCESS_EXCLUDE | TOKEN_AUDIT_FAILURE_INCLUDE | TOKEN_AUDIT_FAILURE_EXCLUDE)
#تعریف_کرو VALID_TOKEN_AUDIT_POLICY_ELEMENT(P) ((((P).Policy_نقاب & ~VALID_AUDIT_POLICY_بٹ)==0) && ((P).Category <= AuditEventMaxType))

    قسمتعریف ساخت _TOKEN_AUDIT_POLICY_ELEMENT {
      DWORD Category;
      DWORD Policy_نقاب;
    } TOKEN_AUDIT_POLICY_ELEMENT,*PTOKEN_AUDIT_POLICY_ELEMENT;

    قسمتعریف ساخت _TOKEN_AUDIT_POLICY {
      DWORD Policy_گنتی;
      TOKEN_AUDIT_POLICY_ELEMENT Policy[ANYSIZE_ARRAY];
    } TOKEN_AUDIT_POLICY,*PTOKEN_AUDIT_POLICY;

#تعریف_کرو فی_USER_AUDITING_POLICY_سائز(p) (حجم(TOKEN_AUDIT_POLICY) + (((p)->Policy_گنتی > ANYSIZE_ARRAY) ? (حجم(TOKEN_AUDIT_POLICY_ELEMENT) *((p)->Policy_گنتی - ANYSIZE_ARRAY)) : 0))
#تعریف_کرو فی_USER_AUDITING_POLICY_سائز_BY_گنتی(C) (حجم(TOKEN_AUDIT_POLICY) + (((C) > ANYSIZE_ARRAY) ? (حجم(TOKEN_AUDIT_POLICY_ELEMENT) *((C) - ANYSIZE_ARRAY)) : 0))

#تعریف_کرو TOKEN_ماخذ_لمبائی 8

    قسمتعریف ساخت TOKEN_ماخذ {
      CHAR ماخذ_Name[TOKEN_ماخذ_لمبائی];
      LUID ماخذ_Identifier;
    } TOKEN_ماخذ_2,*PTOKEN_ماخذ;

    قسمتعریف ساخت _TOKEN_STATISTICS {
      LUID TokenId;
      LUID AuthenticationId;
      LARGE_INTEGER Expiration_وقت;
      TOKEN_TYPE TokenType;
      SECURITY_IMPERSONATION_LEVEL ImpersonationLevel;
      DWORD DynamicCharged;
      DWORD Dynamic_دستیاب;
      DWORD گروہ_گنتی;
      DWORD Privilege_گنتی;
      LUID ModifiedId;
    } TOKEN_STATISTICS,*PTOKEN_STATISTICS;

    قسمتعریف ساخت _TOKEN_CONTROL {
      LUID TokenId;
      LUID AuthenticationId;
      LUID ModifiedId;
      TOKEN_ماخذ_2 Token_ماخذ;
    } TOKEN_CONTROL,*PTOKEN_CONTROL;

    قسمتعریف ساخت _TOKEN_ORIGIN {
      LUID OriginatingLogonSession;
    } TOKEN_ORIGIN,*PTOKEN_ORIGIN;

#تعریف_کرو SECURITY_DYNAMIC_TRACKING (TRUE)
#تعریف_کرو SECURITY_STATIC_TRACKING (FALSE)

    قسمتعریف BOOLEAN SECURITY_CONTEXT_TRACKING_منوال,*PSECURITY_CONTEXT_TRACKING_منوال;

    قسمتعریف ساخت SECURITY_QUALITY_کا_SERVICE {
      DWORD لمبائی_2;
      SECURITY_IMPERSONATION_LEVEL ImpersonationLevel;
      SECURITY_CONTEXT_TRACKING_منوال Context_Tracking_منوال;
      BOOLEAN EffectiveOnly;
    } SECURITY_QUALITY_کا_SERVICE_2,*PSECURITY_QUALITY_کا_SERVICE;

    قسمتعریف ساخت _SE_IMPERSONATION_STATE {
      PACCESS_TOKEN Token;
      BOOLEAN CopyOnOpen;
      BOOLEAN EffectiveOnly;
      SECURITY_IMPERSONATION_LEVEL Level;
    } SE_IMPERSONATION_STATE,*PSE_IMPERSONATION_STATE;

#تعریف_کرو DISABLE_MAX_PRIVILEGE 0x1
#تعریف_کرو SANDBOX_INERT 0x2

    قسمتعریف DWORD SECURITY_INFORMATION,*PSECURITY_INFORMATION;

#تعریف_کرو OWNER_SECURITY_INFORMATION (0x00000001L)
#تعریف_کرو گروہ_SECURITY_INFORMATION (0x00000002L)
#تعریف_کرو DACL_SECURITY_INFORMATION (0x00000004L)
#تعریف_کرو SACL_SECURITY_INFORMATION (0x00000008L)

#تعریف_کرو PROTECTED_DACL_SECURITY_INFORMATION (0x80000000L)
#تعریف_کرو PROTECTED_SACL_SECURITY_INFORMATION (0x40000000L)
#تعریف_کرو UNPROTECTED_DACL_SECURITY_INFORMATION (0x20000000L)
#تعریف_کرو UNPROTECTED_SACL_SECURITY_INFORMATION (0x10000000L)

#تعریف_کرو PROCESS_TERMINATE (0x0001)
#تعریف_کرو PROCESS_CREATE_THREAD (0x0002)
#تعریف_کرو PROCESS_سیٹ_SESSIONID (0x0004)
#تعریف_کرو PROCESS_VM_OPERATION (0x0008)
#تعریف_کرو PROCESS_VM_READ (0x0010)
#تعریف_کرو PROCESS_VM_WRITE (0x0020)
#تعریف_کرو PROCESS_DUP_HANDLE (0x0040)
#تعریف_کرو PROCESS_CREATE_PROCESS (0x0080)
#تعریف_کرو PROCESS_سیٹ_QUOTA (0x0100)
#تعریف_کرو PROCESS_سیٹ_INFORMATION (0x0200)
#تعریف_کرو PROCESS_QUERY_INFORMATION (0x0400)
#تعریف_کرو PROCESS_SUSPEND_RESUME (0x0800)
#تعریف_کرو PROCESS_QUERY_LIMITED_INFORMATION (0x1000)
#تعریف_کرو PROCESS_سیٹ_LIMITED_INFORMATION (0x2000)
#تعریف_کرو PROCESS_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0xFFF)

#اگر_تعریف_شدہ _WIN64
#تعریف_کرو زیادہ_سے_زیادہ_PROCESSORS 64
#ورنہ
#تعریف_کرو زیادہ_سے_زیادہ_PROCESSORS 32
#اگر_ختم

#تعریف_کرو THREAD_TERMINATE (0x0001)
#تعریف_کرو THREAD_SUSPEND_RESUME (0x0002)
#تعریف_کرو THREAD_GET_CONTEXT (0x0008)
#تعریف_کرو THREAD_سیٹ_CONTEXT (0x0010)
#تعریف_کرو THREAD_سیٹ_INFORMATION (0x0020)
#تعریف_کرو THREAD_QUERY_INFORMATION (0x0040)
#تعریف_کرو THREAD_سیٹ_THREAD_TOKEN (0x0080)
#تعریف_کرو THREAD_IMPERSONATE (0x0100)
#تعریف_کرو THREAD_براہ_راست_IMPERSONATION (0x0200)

#تعریف_کرو THREAD_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0x3FF)

#تعریف_کرو کام_OBJECT_تفویض_PROCESS (0x0001)
#تعریف_کرو کام_OBJECT_سیٹ_اوصاف (0x0002)
#تعریف_کرو کام_OBJECT_QUERY (0x0004)
#تعریف_کرو کام_OBJECT_TERMINATE (0x0008)
#تعریف_کرو کام_OBJECT_سیٹ_SECURITY_اوصاف (0x0010)
#تعریف_کرو کام_OBJECT_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0x1F)

    قسمتعریف ساخت کام_سیٹ_ARRAY {
      HANDLE کام_Handle;
      DWORD MemberLevel;
      DWORD Flags;
    } کام_سیٹ_ARRAY_2,*PJOB_سیٹ_ARRAY;

#تعریف_کرو FLS_زیادہ_سے_زیادہ_دستیاب 128
#تعریف_کرو TLS_MINIMUM_دستیاب 64

#اگر_غیر_تعریف_شدہ _NT_TIB_DEFINED
#تعریف_کرو _NT_TIB_DEFINED
    قسمتعریف ساخت _NT_TIB {
      ساخت EXCEPTION_REGISTRATION_ریکارڈ_2 *ExceptionList;
      PVOID ڈھیر_بنیاد;
      PVOID ڈھیر_حد_بندی;
      PVOID SubSystemTib;
      اتحاد {
	PVOID Fiber_ڈیٹا;
	DWORD نسخہ_2;
      };
      PVOID Arbitrary_User_اشارہ_گر;
      ساخت _NT_TIB *Self;
    } NT_TIB;
    قسمتعریف NT_TIB *PNT_TIB;
#اگر_ختم

    قسمتعریف ساخت _NT_TIB32 {
      DWORD ExceptionList;
      DWORD ڈھیر_بنیاد;
      DWORD ڈھیر_حد_بندی;
      DWORD SubSystemTib;
      اتحاد {
	DWORD Fiber_ڈیٹا;
	DWORD نسخہ_2;
      };
      DWORD Arbitrary_User_اشارہ_گر;
      DWORD Self;
    } NT_TIB32,*PNT_TIB32;

    قسمتعریف ساخت _NT_TIB64 {
      DWORD64 ExceptionList;
      DWORD64 ڈھیر_بنیاد;
      DWORD64 ڈھیر_حد_بندی;
      DWORD64 SubSystemTib;
      اتحاد {
	DWORD64 Fiber_ڈیٹا;
	DWORD نسخہ_2;
      };
      DWORD64 Arbitrary_User_اشارہ_گر;
      DWORD64 Self;
    } NT_TIB64,*PNT_TIB64;

#اگر !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_)
#تعریف_کرو WX86
#اگر_ختم

#تعریف_کرو THREAD_بنیاد_ترجیح_LOWRT 15
#تعریف_کرو THREAD_بنیاد_ترجیح_MAX 2
#تعریف_کرو THREAD_بنیاد_ترجیح_MIN (-2)
#تعریف_کرو THREAD_بنیاد_ترجیح_IDLE (-15)

    قسمتعریف ساخت _QUOTA_LIMITS {
      سائز_T Paged_Pool_حد_بندی;
      سائز_T Non_Paged_Pool_حد_بندی;
      سائز_T Minimum_Working_سیٹ_سائز;
      سائز_T زیادہ_سے_زیادہ_Working_سیٹ_سائز;
      سائز_T Pagefile_حد_بندی;
      LARGE_INTEGER وقت_حد_بندی;
    } QUOTA_LIMITS,*PQUOTA_LIMITS;

#تعریف_کرو QUOTA_LIMITS_HARDWS_MIN_ENABLE 0x00000001
#تعریف_کرو QUOTA_LIMITS_HARDWS_MIN_DISABLE 0x00000002
#تعریف_کرو QUOTA_LIMITS_HARDWS_MAX_ENABLE 0x00000004
#تعریف_کرو QUOTA_LIMITS_HARDWS_MAX_DISABLE 0x00000008

    قسمتعریف ساخت _QUOTA_LIMITS_EX {
      سائز_T Paged_Pool_حد_بندی;
      سائز_T Non_Paged_Pool_حد_بندی;
      سائز_T Minimum_Working_سیٹ_سائز;
      سائز_T زیادہ_سے_زیادہ_Working_سیٹ_سائز;
      سائز_T Pagefile_حد_بندی;
      LARGE_INTEGER وقت_حد_بندی;
      سائز_T Reserved1;
      سائز_T Reserved2;
      سائز_T Reserved3;
      سائز_T Reserved4;
      DWORD Flags;
      DWORD Reserved5;
    } QUOTA_LIMITS_EX,*PQUOTA_LIMITS_EX;

    قسمتعریف ساخت _IO_COUNTERS {
      ULONGLONG Read_Operation_گنتی;
      ULONGLONG Write_Operation_گنتی;
      ULONGLONG Other_Operation_گنتی;
      ULONGLONG Read_Transfer_گنتی;
      ULONGLONG Write_Transfer_گنتی;
      ULONGLONG Other_Transfer_گنتی;
    } IO_COUNTERS;
    قسمتعریف IO_COUNTERS *PIO_COUNTERS;

    قسمتعریف ساخت _JOBOBJECT_BASIC_ACCOUNTING_INFORMATION {
      LARGE_INTEGER کل_User_وقت;
      LARGE_INTEGER کل_Kernel_وقت;
      LARGE_INTEGER This_Period_کل_User_وقت;
      LARGE_INTEGER This_Period_کل_Kernel_وقت;
      DWORD کل_صفحہ_Fault_گنتی;
      DWORD کل_Processes;
      DWORD فعال_Processes;
      DWORD کل_Terminated_Processes;
    } JOBOBJECT_BASIC_ACCOUNTING_INFORMATION,*PJOBOBJECT_BASIC_ACCOUNTING_INFORMATION;

    قسمتعریف ساخت JOBOBJECT_BASIC_حد_بندی_INFORMATION {
      LARGE_INTEGER فی_Process_User_وقت_حد_بندی;
      LARGE_INTEGER فی_کام_User_وقت_حد_بندی;
      DWORD حد_بندی_Flags;
      سائز_T Minimum_Working_سیٹ_سائز;
      سائز_T زیادہ_سے_زیادہ_Working_سیٹ_سائز;
      DWORD فعال_Process_حد_بندی;
      ULONG_PTR Affinity;
      DWORD ترجیح_Class;
      DWORD SchedulingClass;
    } JOBOBJECT_BASIC_حد_بندی_INFORMATION_2,*PJOBOBJECT_BASIC_حد_بندی_INFORMATION;

    قسمتعریف ساخت JOBOBJECT_EXTENDED_حد_بندی_INFORMATION {
      JOBOBJECT_BASIC_حد_بندی_INFORMATION_2 Basic_حد_بندی_Information;
      IO_COUNTERS IoInfo;
      سائز_T Process_حافظہ_حد_بندی;
      سائز_T کام_حافظہ_حد_بندی;
      سائز_T Peak_Process_حافظہ_مستعمل;
      سائز_T Peak_کام_حافظہ_مستعمل;
    } JOBOBJECT_EXTENDED_حد_بندی_INFORMATION_2,*PJOBOBJECT_EXTENDED_حد_بندی_INFORMATION;

    قسمتعریف ساخت _JOBOBJECT_BASIC_PROCESS_ID_LIST {
      DWORD نمبر_کا_Assigned_Processes;
      DWORD نمبر_کا_Process_Ids_اندر_List;
      ULONG_PTR ProcessIdList[1];
    } JOBOBJECT_BASIC_PROCESS_ID_LIST,*PJOBOBJECT_BASIC_PROCESS_ID_LIST;

    قسمتعریف ساخت _JOBOBJECT_BASIC_UI_RESTRICTIONS {
      DWORD UIRestrictionsClass;
    } JOBOBJECT_BASIC_UI_RESTRICTIONS,*PJOBOBJECT_BASIC_UI_RESTRICTIONS;

    قسمتعریف ساخت JOBOBJECT_SECURITY_حد_بندی_INFORMATION {
      DWORD Security_حد_بندی_Flags;
      HANDLE کام_Token;
      PTOKEN_GROUPS Sids_مقصد_Disable;
      PTOKEN_PRIVILEGES Privileges_مقصد_Delete;
      PTOKEN_GROUPS RestrictedSids;
    } JOBOBJECT_SECURITY_حد_بندی_INFORMATION_2,*PJOBOBJECT_SECURITY_حد_بندی_INFORMATION;

    قسمتعریف ساخت JOBOBJECT_انتہا_کا_کام_وقت_INFORMATION {
      DWORD انتہا_کا_کام_وقت_Action;
    } JOBOBJECT_انتہا_کا_کام_وقت_INFORMATION_2,*PJOBOBJECT_انتہا_کا_کام_وقت_INFORMATION;

    قسمتعریف ساخت JOBOBJECT_ASSOCIATE_COMPLETION_پورٹ {
      PVOID Completion_کلید;
      HANDLE Completion_پورٹ;
    } JOBOBJECT_ASSOCIATE_COMPLETION_پورٹ_2,*PJOBOBJECT_ASSOCIATE_COMPLETION_پورٹ;

    قسمتعریف ساخت _JOBOBJECT_BASIC_AND_IO_ACCOUNTING_INFORMATION {
      JOBOBJECT_BASIC_ACCOUNTING_INFORMATION BasicInfo;
      IO_COUNTERS IoInfo;
    } JOBOBJECT_BASIC_AND_IO_ACCOUNTING_INFORMATION,*PJOBOBJECT_BASIC_AND_IO_ACCOUNTING_INFORMATION;

    قسمتعریف ساخت _JOBOBJECT_JOBSET_INFORMATION {
      DWORD MemberLevel;
    } JOBOBJECT_JOBSET_INFORMATION,*PJOBOBJECT_JOBSET_INFORMATION;

#تعریف_کرو کام_OBJECT_TERMINATE_AT_انتہا_کا_کام 0
#تعریف_کرو کام_OBJECT_POST_AT_انتہا_کا_کام 1

#تعریف_کرو کام_OBJECT_پیغام_انتہا_کا_کام_وقت 1
#تعریف_کرو کام_OBJECT_پیغام_انتہا_کا_PROCESS_وقت 2
#تعریف_کرو کام_OBJECT_پیغام_فعال_PROCESS_حد_بندی 3
#تعریف_کرو کام_OBJECT_پیغام_فعال_PROCESS_ZERO 4
#تعریف_کرو کام_OBJECT_پیغام_NEW_PROCESS 6
#تعریف_کرو کام_OBJECT_پیغام_EXIT_PROCESS 7
#تعریف_کرو کام_OBJECT_پیغام_ABNORMAL_EXIT_PROCESS 8
#تعریف_کرو کام_OBJECT_پیغام_PROCESS_حافظہ_حد_بندی 9
#تعریف_کرو کام_OBJECT_پیغام_کام_حافظہ_حد_بندی 10

#تعریف_کرو کام_OBJECT_حد_بندی_WORKINGSET 0x00000001
#تعریف_کرو کام_OBJECT_حد_بندی_PROCESS_وقت 0x00000002
#تعریف_کرو کام_OBJECT_حد_بندی_کام_وقت 0x00000004
#تعریف_کرو کام_OBJECT_حد_بندی_فعال_PROCESS 0x00000008
#تعریف_کرو کام_OBJECT_حد_بندی_AFFINITY 0x00000010
#تعریف_کرو کام_OBJECT_حد_بندی_ترجیح_CLASS 0x00000020
#تعریف_کرو کام_OBJECT_حد_بندی_PRESERVE_کام_وقت 0x00000040
#تعریف_کرو کام_OBJECT_حد_بندی_SCHEDULING_CLASS 0x00000080

#تعریف_کرو کام_OBJECT_حد_بندی_PROCESS_حافظہ 0x00000100
#تعریف_کرو کام_OBJECT_حد_بندی_کام_حافظہ 0x00000200
#تعریف_کرو کام_OBJECT_حد_بندی_DIE_ON_UNHANDLED_EXCEPTION 0x00000400
#تعریف_کرو کام_OBJECT_حد_بندی_BREAKAWAY_OK 0x00000800
#تعریف_کرو کام_OBJECT_حد_بندی_SILENT_BREAKAWAY_OK 0x00001000
#تعریف_کرو کام_OBJECT_حد_بندی_KILL_ON_کام_CLOSE 0x00002000

#تعریف_کرو کام_OBJECT_حد_بندی_RESERVED2 0x00004000
#تعریف_کرو کام_OBJECT_حد_بندی_RESERVED3 0x00008000
#تعریف_کرو کام_OBJECT_حد_بندی_RESERVED4 0x00010000
#تعریف_کرو کام_OBJECT_حد_بندی_RESERVED5 0x00020000
#تعریف_کرو کام_OBJECT_حد_بندی_RESERVED6 0x00040000

#تعریف_کرو کام_OBJECT_حد_بندی_VALID_FLAGS 0x0007ffff

#تعریف_کرو کام_OBJECT_BASIC_حد_بندی_VALID_FLAGS 0x000000ff
#تعریف_کرو کام_OBJECT_EXTENDED_حد_بندی_VALID_FLAGS 0x00003fff
#تعریف_کرو کام_OBJECT_RESERVED_حد_بندی_VALID_FLAGS 0x0007ffff

#تعریف_کرو کام_OBJECT_UILIMIT_NONE 0x00000000

#تعریف_کرو کام_OBJECT_UILIMIT_HANDLES 0x00000001
#تعریف_کرو کام_OBJECT_UILIMIT_READCLIPBOARD 0x00000002
#تعریف_کرو کام_OBJECT_UILIMIT_WRITECLIPBOARD 0x00000004
#تعریف_کرو کام_OBJECT_UILIMIT_SYSTEMPARAMETERS 0x00000008
#تعریف_کرو کام_OBJECT_UILIMIT_DISPLAYSETTINGS 0x00000010
#تعریف_کرو کام_OBJECT_UILIMIT_GLOBALATOMS 0x00000020
#تعریف_کرو کام_OBJECT_UILIMIT_DESKTOP 0x00000040
#تعریف_کرو کام_OBJECT_UILIMIT_EXITWINDOWS 0x00000080

#تعریف_کرو کام_OBJECT_UILIMIT_ALL 0x000000FF

#تعریف_کرو کام_OBJECT_UI_VALID_FLAGS 0x000000FF

#تعریف_کرو کام_OBJECT_SECURITY_NO_ADMIN 0x00000001
#تعریف_کرو کام_OBJECT_SECURITY_RESTRICTED_TOKEN 0x00000002
#تعریف_کرو کام_OBJECT_SECURITY_ONLY_TOKEN 0x00000004
#تعریف_کرو کام_OBJECT_SECURITY_FILTER_علامات 0x00000008

#تعریف_کرو کام_OBJECT_SECURITY_VALID_FLAGS 0x0000000f

    قسمتعریف شمار _JOBOBJECTINFOCLASS {
      کام_Object_Basic_Accounting_Information = 1,کام_Object_Basic_حد_بندی_Information,کام_Object_Basic_Process_Id_List,کام_Object_Basic_UIRestrictions,
      کام_Object_Security_حد_بندی_Information,کام_Object_انتہا_کا_کام_وقت_Information,کام_Object_Associate_Completion_پورٹ_Information,
      کام_Object_Basic_And_Io_Accounting_Information,کام_Object_Extended_حد_بندی_Information,کام_Object_کام_سیٹ_Information,Max_کام_Object_Info_Class
    } JOBOBJECTINFOCLASS;

#تعریف_کرو EVENT_MODIFY_STATE 0x0002
#تعریف_کرو EVENT_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x3)

#تعریف_کرو MUTANT_QUERY_STATE 0x0001

#تعریف_کرو MUTANT_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE| MUTANT_QUERY_STATE)
#تعریف_کرو SEMAPHORE_MODIFY_STATE 0x0002
#تعریف_کرو SEMAPHORE_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x3)

#تعریف_کرو TIMER_QUERY_STATE 0x0001
#تعریف_کرو TIMER_MODIFY_STATE 0x0002

#تعریف_کرو TIMER_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE| TIMER_QUERY_STATE|TIMER_MODIFY_STATE)

#تعریف_کرو وقت_ZONE_ID_UNKNOWN 0
#تعریف_کرو وقت_ZONE_ID_STANDARD 1
#تعریف_کرو وقت_ZONE_ID_DAYLIGHT 2

    قسمتعریف شمار _LOGICAL_PROCESSOR_RELATIONSHIP {
      رشتہ_Processor_Core,رشتہ_Numa_گرہ,رشتہ_Cache
    } LOGICAL_PROCESSOR_RELATIONSHIP;

#تعریف_کرو LTP_PC_SMT 0x1

    قسمتعریف شمار _PROCESSOR_CACHE_TYPE {
      CacheUnified,CacheInstruction,Cache_ڈیٹا,CacheTrace
    } PROCESSOR_CACHE_TYPE;

#تعریف_کرو CACHE_FULLY_ASSOCIATIVE 0xFF

    قسمتعریف ساخت _CACHE_DESCRIPTOR {
      BYTE Level;
      BYTE Associativity;
      لفظ_3 سطر_سائز_2;
      DWORD سائز_3;
      PROCESSOR_CACHE_TYPE Type;
    } CACHE_DESCRIPTOR,*PCACHE_DESCRIPTOR;

    قسمتعریف ساخت _SYSTEM_LOGICAL_PROCESSOR_INFORMATION {
      ULONG_PTR Processor_نقاب;
      LOGICAL_PROCESSOR_RELATIONSHIP Relationship;
      اتحاد {
	ساخت {
	  BYTE Flags;
	} ProcessorCore;
	ساخت {
	  DWORD گرہ_نمبر;
	} Numa_گرہ;
	CACHE_DESCRIPTOR Cache;
	ULONGLONG Reserved[2];
      };
    } SYSTEM_LOGICAL_PROCESSOR_INFORMATION,*PSYSTEM_LOGICAL_PROCESSOR_INFORMATION;

#تعریف_کرو PROCESSOR_INTEL_386 386
#تعریف_کرو PROCESSOR_INTEL_486 486
#تعریف_کرو PROCESSOR_INTEL_PENTIUM 586
#تعریف_کرو PROCESSOR_INTEL_IA64 2200
#تعریف_کرو PROCESSOR_AMD_X8664 8664
#تعریف_کرو PROCESSOR_MIPS_R4000 4000
#تعریف_کرو PROCESSOR_ALPHA_21064 21064
#تعریف_کرو PROCESSOR_PPC_601 601
#تعریف_کرو PROCESSOR_PPC_603 603
#تعریف_کرو PROCESSOR_PPC_604 604
#تعریف_کرو PROCESSOR_PPC_620 620
#تعریف_کرو PROCESSOR_HITACHI_SH3 10003
#تعریف_کرو PROCESSOR_HITACHI_SH3E 10004
#تعریف_کرو PROCESSOR_HITACHI_SH4 10005
#تعریف_کرو PROCESSOR_MOTOROLA_821 821
#تعریف_کرو PROCESSOR_SHx_SH3 103
#تعریف_کرو PROCESSOR_SHx_SH4 104
#تعریف_کرو PROCESSOR_STRONGARM 2577
#تعریف_کرو PROCESSOR_ARM720 1824
#تعریف_کرو PROCESSOR_ARM820 2080
#تعریف_کرو PROCESSOR_ARM920 2336
#تعریف_کرو PROCESSOR_ARM_7TDMI 70001
#تعریف_کرو PROCESSOR_OPTIL 0x494f

#تعریف_کرو PROCESSOR_ARCHITECTURE_INTEL 0
#تعریف_کرو PROCESSOR_ARCHITECTURE_MIPS 1
#تعریف_کرو PROCESSOR_ARCHITECTURE_ALPHA 2
#تعریف_کرو PROCESSOR_ARCHITECTURE_PPC 3
#تعریف_کرو PROCESSOR_ARCHITECTURE_SHX 4
#تعریف_کرو PROCESSOR_ARCHITECTURE_ARM 5
#تعریف_کرو PROCESSOR_ARCHITECTURE_IA64 6
#تعریف_کرو PROCESSOR_ARCHITECTURE_ALPHA64 7
#تعریف_کرو PROCESSOR_ARCHITECTURE_MSIL 8
#تعریف_کرو PROCESSOR_ARCHITECTURE_AMD64 9
#تعریف_کرو PROCESSOR_ARCHITECTURE_IA32_ON_WIN64 10

#تعریف_کرو PROCESSOR_ARCHITECTURE_UNKNOWN 0xFFFF

#تعریف_کرو PF_FLOATING_نقطہ_PRECISION_ERRATA 0
#تعریف_کرو PF_FLOATING_نقطہ_EMULATED 1
#تعریف_کرو PF_COMPARE_EXCHANGE_DOUBLE 2
#تعریف_کرو PF_MMX_INSTRUCTIONS_دستیاب 3
#تعریف_کرو PF_PPC_MOVEMEM_64_ثنائی_ہندسہ_OK 4
#تعریف_کرو PF_ALPHA_BYTE_INSTRUCTIONS 5
#تعریف_کرو PF_XMMI_INSTRUCTIONS_دستیاب 6
#تعریف_کرو PF_3_DNOW_INSTRUCTIONS_دستیاب 7
#تعریف_کرو PF_RDTSC_INSTRUCTION_دستیاب 8
#تعریف_کرو PF_PAE_ENABLED 9
#تعریف_کرو PF_XMMI64_INSTRUCTIONS_دستیاب 10
#تعریف_کرو PF_SSE_DAZ_منوال_دستیاب 11
#تعریف_کرو PF_NX_ENABLED 12

    قسمتعریف ساخت حافظہ_BASIC_INFORMATION_2 {
      PVOID بنیاد_پتہ;
      PVOID تخصیص_بنیاد;
      DWORD تخصیص_Protect;
      سائز_T Region_سائز;
      DWORD State;
      DWORD Protect;
      DWORD Type;
    } حافظہ_BASIC_INFORMATION,*PMEMORY_BASIC_INFORMATION;

    قسمتعریف ساخت حافظہ_BASIC_INFORMATION32 {
      DWORD بنیاد_پتہ;
      DWORD تخصیص_بنیاد;
      DWORD تخصیص_Protect;
      DWORD Region_سائز;
      DWORD State;
      DWORD Protect;
      DWORD Type;
    } حافظہ_BASIC_INFORMATION32_2,*PMEMORY_BASIC_INFORMATION32;

    قسمتعریف ساخت DECLSPEC_ALIGN(16) حافظہ_BASIC_INFORMATION64 {
      ULONGLONG بنیاد_پتہ;
      ULONGLONG تخصیص_بنیاد;
      DWORD تخصیص_Protect;
      DWORD __alignment1;
      ULONGLONG Region_سائز;
      DWORD State;
      DWORD Protect;
      DWORD Type;
      DWORD __alignment2;
    } حافظہ_BASIC_INFORMATION64_2,*PMEMORY_BASIC_INFORMATION64;

#تعریف_کرو SECTION_QUERY 0x0001
#تعریف_کرو SECTION_MAP_WRITE 0x0002
#تعریف_کرو SECTION_MAP_READ 0x0004
#تعریف_کرو SECTION_MAP_EXECUTE 0x0008
#تعریف_کرو SECTION_EXTEND_سائز 0x0010
#تعریف_کرو SECTION_MAP_EXECUTE_EXPLICIT 0x0020

#تعریف_کرو SECTION_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SECTION_QUERY| SECTION_MAP_WRITE | SECTION_MAP_READ | SECTION_MAP_EXECUTE | SECTION_EXTEND_سائز)
#تعریف_کرو صفحہ_NOACCESS 0x01
#تعریف_کرو صفحہ_READONLY 0x02
#تعریف_کرو صفحہ_READWRITE 0x04
#تعریف_کرو صفحہ_WRITECOPY 0x08
#تعریف_کرو صفحہ_EXECUTE 0x10
#تعریف_کرو صفحہ_EXECUTE_READ 0x20
#تعریف_کرو صفحہ_EXECUTE_READWRITE 0x40
#تعریف_کرو صفحہ_EXECUTE_WRITECOPY 0x80
#تعریف_کرو صفحہ_GUARD 0x100
#تعریف_کرو صفحہ_NOCACHE 0x200
#تعریف_کرو صفحہ_WRITECOMBINE 0x400
#تعریف_کرو MEM_COMMIT 0x1000
#تعریف_کرو MEM_RESERVE 0x2000
#تعریف_کرو MEM_DECOMMIT 0x4000
#تعریف_کرو MEM_RELEASE 0x8000
#تعریف_کرو MEM_FREE 0x10000
#تعریف_کرو MEM_نجی 0x20000
#تعریف_کرو MEM_MAPPED 0x40000
#تعریف_کرو MEM_RESET 0x80000
#تعریف_کرو MEM_چوٹی_نیچے_کو 0x100000
#تعریف_کرو MEM_WRITE_WATCH 0x200000
#تعریف_کرو MEM_PHYSICAL 0x400000
#تعریف_کرو MEM_LARGE_صفحات 0x20000000
#تعریف_کرو MEM_4_MB_صفحات 0x80000000
#تعریف_کرو SEC_FILE 0x800000
#تعریف_کرو SEC_IMAGE 0x1000000
#تعریف_کرو SEC_RESERVE 0x4000000
#تعریف_کرو SEC_COMMIT 0x8000000
#تعریف_کرو SEC_NOCACHE 0x10000000
#تعریف_کرو SEC_LARGE_صفحات 0x80000000
#تعریف_کرو MEM_IMAGE SEC_IMAGE
#تعریف_کرو WRITE_WATCH_FLAG_RESET 0x01

#تعریف_کرو FILE_READ_ڈیٹا (0x0001)
#تعریف_کرو FILE_LIST_DIRECTORY (0x0001)

#تعریف_کرو FILE_WRITE_ڈیٹا (0x0002)
#تعریف_کرو FILE_جوڑو_FILE (0x0002)

#تعریف_کرو FILE_APPEND_ڈیٹا (0x0004)
#تعریف_کرو FILE_جوڑو_SUBDIRECTORY (0x0004)
#تعریف_کرو FILE_CREATE_PIPE_INSTANCE (0x0004)

#تعریف_کرو FILE_READ_EA (0x0008)

#تعریف_کرو FILE_WRITE_EA (0x0010)

#تعریف_کرو FILE_EXECUTE (0x0020)
#تعریف_کرو FILE_TRAVERSE (0x0020)

#تعریف_کرو FILE_DELETE_بچہ (0x0040)

#تعریف_کرو FILE_READ_اوصاف (0x0080)

#تعریف_کرو FILE_WRITE_اوصاف (0x0100)

#تعریف_کرو FILE_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0x1FF)
#تعریف_کرو FILE_GENERIC_READ (STANDARD_RIGHTS_READ | FILE_READ_ڈیٹا | FILE_READ_اوصاف | FILE_READ_EA | SYNCHRONIZE)
#تعریف_کرو FILE_GENERIC_WRITE (STANDARD_RIGHTS_WRITE | FILE_WRITE_ڈیٹا | FILE_WRITE_اوصاف | FILE_WRITE_EA | FILE_APPEND_ڈیٹا | SYNCHRONIZE)
#تعریف_کرو FILE_GENERIC_EXECUTE (STANDARD_RIGHTS_EXECUTE | FILE_READ_اوصاف | FILE_EXECUTE | SYNCHRONIZE)

#تعریف_کرو FILE_SHARE_READ 0x00000001
#تعریف_کرو FILE_SHARE_WRITE 0x00000002
#تعریف_کرو FILE_SHARE_DELETE 0x00000004
#تعریف_کرو FILE_ATTRIBUTE_READONLY 0x00000001
#تعریف_کرو FILE_ATTRIBUTE_HIDDEN 0x00000002
#تعریف_کرو FILE_ATTRIBUTE_SYSTEM 0x00000004
#تعریف_کرو FILE_ATTRIBUTE_DIRECTORY 0x00000010
#تعریف_کرو FILE_ATTRIBUTE_ARCHIVE 0x00000020
#تعریف_کرو FILE_ATTRIBUTE_DEVICE 0x00000040
#تعریف_کرو FILE_ATTRIBUTE_معمول 0x00000080
#تعریف_کرو FILE_ATTRIBUTE_TEMPORARY 0x00000100
#تعریف_کرو FILE_ATTRIBUTE_SPARSE_FILE 0x00000200
#تعریف_کرو FILE_ATTRIBUTE_REPARSE_نقطہ 0x00000400
#تعریف_کرو FILE_ATTRIBUTE_COMPRESSED 0x00000800
#تعریف_کرو FILE_ATTRIBUTE_OFFLINE 0x00001000
#تعریف_کرو FILE_ATTRIBUTE_NOT_CONTENT_اشاریہ_دار 0x00002000
#تعریف_کرو FILE_ATTRIBUTE_ENCRYPTED 0x00004000
#تعریف_کرو FILE_NOTIFY_CHANGE_FILE_NAME 0x00000001
#تعریف_کرو FILE_NOTIFY_CHANGE_DIR_NAME 0x00000002
#تعریف_کرو FILE_NOTIFY_CHANGE_اوصاف 0x00000004
#تعریف_کرو FILE_NOTIFY_CHANGE_سائز 0x00000008
#تعریف_کرو FILE_NOTIFY_CHANGE_آخری_WRITE 0x00000010
#تعریف_کرو FILE_NOTIFY_CHANGE_آخری_ACCESS 0x00000020
#تعریف_کرو FILE_NOTIFY_CHANGE_CREATION 0x00000040
#تعریف_کرو FILE_NOTIFY_CHANGE_SECURITY 0x00000100
#تعریف_کرو FILE_ACTION_ADDED 0x00000001
#تعریف_کرو FILE_ACTION_REMOVED 0x00000002
#تعریف_کرو FILE_ACTION_MODIFIED 0x00000003
#تعریف_کرو FILE_ACTION_RENAMED_OLD_NAME 0x00000004
#تعریف_کرو FILE_ACTION_RENAMED_NEW_NAME 0x00000005
#تعریف_کرو MAILSLOT_NO_پیغام ((DWORD)-1)
#تعریف_کرو MAILSLOT_WAIT_FOREVER ((DWORD)-1)
#تعریف_کرو FILE_CASE_SENSITIVE_تلاش 0x00000001
#تعریف_کرو FILE_CASE_PRESERVED_نام 0x00000002
#تعریف_کرو FILE_UNICODE_ON_DISK 0x00000004
#تعریف_کرو FILE_PERSISTENT_ACLS 0x00000008
#تعریف_کرو FILE_FILE_COMPRESSION 0x00000010
#تعریف_کرو FILE_VOLUME_QUOTAS 0x00000020
#تعریف_کرو FILE_SUPPORTS_SPARSE_FILES 0x00000040
#تعریف_کرو FILE_SUPPORTS_REPARSE_POINTS 0x00000080
#تعریف_کرو FILE_SUPPORTS_REMOTE_STORAGE 0x00000100
#تعریف_کرو FILE_VOLUME_IS_COMPRESSED 0x00008000
#تعریف_کرو FILE_SUPPORTS_OBJECT_IDS 0x00010000
#تعریف_کرو FILE_SUPPORTS_ENCRYPTION 0x00020000
#تعریف_کرو FILE_NAMED_STREAMS 0x00040000
#تعریف_کرو FILE_READ_ONLY_VOLUME 0x00080000

    قسمتعریف ساخت _FILE_NOTIFY_INFORMATION {
      DWORD اگلا_اندراج_انحراف;
      DWORD Action;
      DWORD File_Name_لمبائی;
      WCHAR FileName[1];
    } FILE_NOTIFY_INFORMATION,*PFILE_NOTIFY_INFORMATION;

    قسمتعریف اتحاد _FILE_SEGMENT_ELEMENT {
      PVOID64 بفر_3;
      ULONGLONG Alignment;
    }FILE_SEGMENT_ELEMENT,*PFILE_SEGMENT_ELEMENT;

    قسمتعریف ساخت REPARSE_GUID_ڈیٹا_بفر {
      DWORD Reparse_لیبل;
      لفظ_3 Reparse_ڈیٹا_لمبائی;
      لفظ_3 Reserved;
      GUID ReparseGuid;
      ساخت {
	BYTE ڈیٹا_بفر[1];
      } Generic_Reparse_بفر;
    } REPARSE_GUID_ڈیٹا_بفر_2,*PREPARSE_GUID_ڈیٹا_بفر;

#تعریف_کرو REPARSE_GUID_ڈیٹا_بفر_سرخی_سائز میدان_انحراف(REPARSE_GUID_ڈیٹا_بفر_2,Generic_Reparse_بفر)

#تعریف_کرو زیادہ_سے_زیادہ_REPARSE_ڈیٹا_بفر_سائز (16 *1024)

#تعریف_کرو IO_REPARSE_لیبل_RESERVED_ZERO (0)
#تعریف_کرو IO_REPARSE_لیبل_RESERVED_ONE (1)

#تعریف_کرو IO_REPARSE_لیبل_RESERVED_RANGE IO_REPARSE_لیبل_RESERVED_ONE

#تعریف_کرو Is_Reparse_لیبل_Microsoft(لیبل_2) (((لیبل_2) & 0x80000000))
#تعریف_کرو Is_Reparse_لیبل_Name_Surrogate(لیبل_2) (((لیبل_2) & 0x20000000))

#تعریف_کرو IO_REPARSE_لیبل_MOUNT_نقطہ (0xA0000003L)
#تعریف_کرو IO_REPARSE_لیبل_HSM (0xC0000004L)
#تعریف_کرو IO_REPARSE_لیبل_SIS (0x80000007L)
#تعریف_کرو IO_REPARSE_لیبل_DFS (0x8000000AL)
#تعریف_کرو IO_REPARSE_لیبل_FILTER_MANAGER (0x8000000BL)
#تعریف_کرو IO_COMPLETION_MODIFY_STATE 0x0002
#تعریف_کرو IO_COMPLETION_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x3)
#تعریف_کرو DUPLICATE_CLOSE_ماخذ 0x00000001
#تعریف_کرو DUPLICATE_SAME_ACCESS 0x00000002

    قسمتعریف شمار _SYSTEM_POWER_STATE {
      PowerSystemUnspecified = 0,PowerSystemWorking = 1,PowerSystemSleeping1 = 2,PowerSystemSleeping2 = 3,PowerSystemSleeping3 = 4,PowerSystemHibernate = 5,PowerSystemShutdown = 6,Power_System_زیادہ_سے_زیادہ = 7
    } SYSTEM_POWER_STATE,*PSYSTEM_POWER_STATE;

#تعریف_کرو POWER_SYSTEM_زیادہ_سے_زیادہ 7

    قسمتعریف شمار {
      PowerActionNone = 0,PowerActionReserved,PowerActionSleep,PowerActionHibernate,PowerActionShutdown,PowerActionShutdownReset,PowerActionShutdownOff,PowerActionWarmEject
    } POWER_ACTION,*PPOWER_ACTION;

    قسمتعریف شمار _DEVICE_POWER_STATE {
      PowerDeviceUnspecified = 0,PowerDeviceD0,PowerDeviceD1,PowerDeviceD2,PowerDeviceD3,Power_Device_زیادہ_سے_زیادہ
    } DEVICE_POWER_STATE,*PDEVICE_POWER_STATE;

#تعریف_کرو ES_SYSTEM_REQUIRED ((DWORD)0x00000001)
#تعریف_کرو ES_DISPLAY_REQUIRED ((DWORD)0x00000002)
#تعریف_کرو ES_USER_PRESENT ((DWORD)0x00000004)
#تعریف_کرو ES_CONTINUOUS ((DWORD)0x80000000)

    قسمتعریف DWORD EXECUTION_STATE;

    قسمتعریف شمار {
      LT_DONT_CARE,LT_سب_سے_نیچا_LATENCY
    } LATENCY_وقت;

#تعریف_کرو PDCAP_D0_SUPPORTED 0x00000001
#تعریف_کرو PDCAP_D1_SUPPORTED 0x00000002
#تعریف_کرو PDCAP_D2_SUPPORTED 0x00000004
#تعریف_کرو PDCAP_D3_SUPPORTED 0x00000008
#تعریف_کرو PDCAP_WAKE_FROM_D0_SUPPORTED 0x00000010
#تعریف_کرو PDCAP_WAKE_FROM_D1_SUPPORTED 0x00000020
#تعریف_کرو PDCAP_WAKE_FROM_D2_SUPPORTED 0x00000040
#تعریف_کرو PDCAP_WAKE_FROM_D3_SUPPORTED 0x00000080
#تعریف_کرو PDCAP_WARM_EJECT_SUPPORTED 0x00000100

    قسمتعریف ساخت CM_Power_ڈیٹا_s {
      DWORD PD_سائز;
      DEVICE_POWER_STATE PD_MostRecentPowerState;
      DWORD PD_Capabilities;
      DWORD PD_D1Latency;
      DWORD PD_D2Latency;
      DWORD PD_D3Latency;
      DEVICE_POWER_STATE PD_PowerStateMapping[POWER_SYSTEM_زیادہ_سے_زیادہ];
      SYSTEM_POWER_STATE PD_گہرا_ترین_System_Wake;
    } CM_POWER_ڈیٹا,*PCM_POWER_ڈیٹا;

    قسمتعریف شمار {
      SystemPowerPolicyAc,SystemPowerPolicyDc,VerifySystemPolicyAc,VerifySystemPolicyDc,SystemPowerCapabilities,SystemBatteryState,SystemPowerStateHandler,ProcessorStateHandler,SystemPowerPolicyCurrent,AdministratorPowerPolicy,SystemReserveHiberFile,ProcessorInformation,SystemPowerInformation,ProcessorStateHandler2,آخری_Wake_وقت,آخری_Sleep_وقت,SystemExecutionState,SystemPowerStateNotifyHandler,ProcessorPowerPolicyAc,ProcessorPowerPolicyDc,VerifyProcessorPowerPolicyAc,VerifyProcessorPowerPolicyDc,ProcessorPowerPolicyCurrent,SystemPowerStateLogging,System_Power_Logging_اندراج
    } POWER_INFORMATION_LEVEL;

    قسمتعریف ساخت {
      DWORD Granularity;
      DWORD استعداد;
    } BATTERY_REPORTING_SCALE,*PBATTERY_REPORTING_SCALE;

    قسمتعریف ساخت {
      POWER_ACTION Action;
      DWORD Flags;
      DWORD Event_رمز;
    } POWER_ACTION_POLICY,*PPOWER_ACTION_POLICY;

#تعریف_کرو POWER_ACTION_QUERY_ALLOWED 0x00000001
#تعریف_کرو POWER_ACTION_UI_ALLOWED 0x00000002
#تعریف_کرو POWER_ACTION_OVERRIDE_APPS 0x00000004
#تعریف_کرو POWER_ACTION_LIGHTEST_پہلا 0x10000000
#تعریف_کرو POWER_ACTION_تالا_CONSOLE 0x20000000
#تعریف_کرو POWER_ACTION_DISABLE_WAKES 0x40000000
#تعریف_کرو POWER_ACTION_CRITICAL 0x80000000

#تعریف_کرو POWER_LEVEL_USER_NOTIFY_متن 0x00000001
#تعریف_کرو POWER_LEVEL_USER_NOTIFY_SOUND 0x00000002
#تعریف_کرو POWER_LEVEL_USER_NOTIFY_EXEC 0x00000004
#تعریف_کرو POWER_USER_NOTIFY_BUTTON 0x00000008
#تعریف_کرو POWER_USER_NOTIFY_SHUTDOWN 0x00000010
#تعریف_کرو POWER_FORCE_TRIGGER_RESET 0x80000000

    قسمتعریف ساخت {
      BOOLEAN Enable;
      BYTE فالتو_2[3];
      DWORD BatteryLevel;
      POWER_ACTION_POLICY PowerPolicy;
      SYSTEM_POWER_STATE MinSystemState;
    } SYSTEM_POWER_LEVEL,*PSYSTEM_POWER_LEVEL;

#تعریف_کرو عدد_DISCHARGE_POLICIES 4
#تعریف_کرو DISCHARGE_POLICY_CRITICAL 0
#تعریف_کرو DISCHARGE_POLICY_کم 1

#تعریف_کرو PO_THROTTLE_NONE 0
#تعریف_کرو PO_THROTTLE_CONSTANT 1
#تعریف_کرو PO_THROTTLE_DEGRADE 2
#تعریف_کرو PO_THROTTLE_ADAPTIVE 3
#تعریف_کرو PO_THROTTLE_زیادہ_سے_زیادہ 4

    قسمتعریف ساخت _SYSTEM_POWER_POLICY {
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
      DWORD نشر_استعداد_Resolution;
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

    قسمتعریف ساخت _PROCESSOR_POWER_POLICY_INFO {
      DWORD وقت_Check;
      DWORD Demote_حد_بندی;
      DWORD Promote_حد_بندی;
      BYTE DemotePercent;
      BYTE PromotePercent;
      BYTE فالتو_2[2];
      DWORD AllowDemotion:1;
      DWORD AllowPromotion:1;
      DWORD Reserved:30;
    } PROCESSOR_POWER_POLICY_INFO,*PPROCESSOR_POWER_POLICY_INFO;

    قسمتعریف ساخت _PROCESSOR_POWER_POLICY {
      DWORD Revision;
      BYTE DynamicThrottle;
      BYTE فالتو_2[3];
      DWORD DisableCStates:1;
      DWORD Reserved:31;
      DWORD Policy_گنتی;
      PROCESSOR_POWER_POLICY_INFO Policy[3];
    } PROCESSOR_POWER_POLICY,*PPROCESSOR_POWER_POLICY;

    قسمتعریف ساخت _ADMINISTRATOR_POWER_POLICY {
      SYSTEM_POWER_STATE MinSleep;
      SYSTEM_POWER_STATE MaxSleep;
      DWORD MinVideoTimeout;
      DWORD MaxVideoTimeout;
      DWORD MinSpindownTimeout;
      DWORD MaxSpindownTimeout;
    } ADMINISTRATOR_POWER_POLICY,*PADMINISTRATOR_POWER_POLICY;

    قسمتعریف ساخت {
      BOOLEAN PowerButtonPresent;
      BOOLEAN SleepButtonPresent;
      BOOLEAN LidPresent;
      BOOLEAN SystemS1;
      BOOLEAN SystemS2;
      BOOLEAN SystemS3;
      BOOLEAN SystemS4;
      BOOLEAN SystemS5;
      BOOLEAN HiberFilePresent;
      BOOLEAN بھرا_Wake;
      BOOLEAN VideoDimPresent;
      BOOLEAN ApmPresent;
      BOOLEAN UpsPresent;
      BOOLEAN ThermalControl;
      BOOLEAN ProcessorThrottle;
      BYTE ProcessorMinThrottle;
      BYTE ProcessorMaxThrottle;
      BYTE spare2[4];
      BOOLEAN Disk_Spin_نیچے_کو;
      BYTE spare3[8];
      BOOLEAN SystemBatteriesPresent;
      BOOLEAN Batteries_Are_Short_رکن;
      BATTERY_REPORTING_SCALE BatteryScale[3];
      SYSTEM_POWER_STATE Ac_On_سطر_Wake;
      SYSTEM_POWER_STATE SoftLidWake;
      SYSTEM_POWER_STATE RtcWake;
      SYSTEM_POWER_STATE MinDeviceWakeState;
      SYSTEM_POWER_STATE Default_کم_Latency_Wake;
    } SYSTEM_POWER_CAPABILITIES,*PSYSTEM_POWER_CAPABILITIES;

    قسمتعریف ساخت {
      BOOLEAN Ac_On_سطر;
      BOOLEAN BatteryPresent;
      BOOLEAN Charging;
      BOOLEAN Discharging;
      BOOLEAN Spare1[4];
      DWORD Max_استعداد;
      DWORD بقایا_استعداد;
      DWORD شرح;
      DWORD Estimated_وقت;
      DWORD DefaultAlert1;
      DWORD DefaultAlert2;
    } SYSTEM_BATTERY_STATE,*PSYSTEM_BATTERY_STATE;

#شامل "pshpack4.h"

#تعریف_کرو IMAGE_DOS_SIGNATURE 0x5A4D
#تعریف_کرو IMAGE_OS2_SIGNATURE 0x454E
#تعریف_کرو IMAGE_OS2_SIGNATURE_LE 0x454C
#تعریف_کرو IMAGE_VXD_SIGNATURE 0x454C
#تعریف_کرو IMAGE_NT_SIGNATURE 0x00004550

#شامل "pshpack2.h"

    قسمتعریف ساخت IMAGE_DOS_سرخی {
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
    } IMAGE_DOS_سرخی_2,*PIMAGE_DOS_سرخی;

    قسمتعریف ساخت IMAGE_OS2_سرخی {
      لفظ_3 ne_magic;
      CHAR ne_ver;
      CHAR ne_rev;
      لفظ_3 ne_enttab;
      لفظ_3 ne_cbenttab;
      LONG ne_چکری_جانچ;
      لفظ_3 ne_flags;
      لفظ_3 ne_autodata;
      لفظ_3 ne_ڈھیر;
      لفظ_3 ne_ڈھیر_2;
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
    } IMAGE_OS2_سرخی_2,*PIMAGE_OS2_سرخی;

    قسمتعریف ساخت IMAGE_VXD_سرخی {
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
    } IMAGE_VXD_سرخی_2,*PIMAGE_VXD_سرخی;

#شامل "poppack.h"

    قسمتعریف ساخت IMAGE_FILE_سرخی {
      لفظ_3 Machine;
      لفظ_3 نمبر_کا_Sections;
      DWORD وقت_Date_Stamp;
      DWORD اشارہ_گر_مقصد_علامت_جدول;
      DWORD نمبر_کا_Symbols;
      لفظ_3 سائز_کا_Optional_سرخی;
      لفظ_3 Characteristics;
    } IMAGE_FILE_سرخی_2,*PIMAGE_FILE_سرخی;

#تعریف_کرو IMAGE_SIZEOF_FILE_سرخی 20

#تعریف_کرو IMAGE_FILE_RELOCS_STRIPPED 0x0001
#تعریف_کرو IMAGE_FILE_EXECUTABLE_IMAGE 0x0002
#تعریف_کرو IMAGE_FILE_سطر_NUMS_STRIPPED 0x0004
#تعریف_کرو IMAGE_FILE_LOCAL_SYMS_STRIPPED 0x0008
#تعریف_کرو IMAGE_FILE_AGGRESIVE_WS_TRIM 0x0010
#تعریف_کرو IMAGE_FILE_LARGE_پتہ_AWARE 0x0020
#تعریف_کرو IMAGE_FILE_بائٹیں_REVERSED_LO 0x0080
#تعریف_کرو IMAGE_FILE_32_ثنائی_ہندسہ_MACHINE 0x0100
#تعریف_کرو IMAGE_FILE_DEBUG_STRIPPED 0x0200
#تعریف_کرو IMAGE_FILE_REMOVABLE_تسلسل_FROM_تبادلہ 0x0400
#تعریف_کرو IMAGE_FILE_NET_تسلسل_FROM_تبادلہ 0x0800
#تعریف_کرو IMAGE_FILE_SYSTEM 0x1000
#تعریف_کرو IMAGE_FILE_DLL 0x2000
#تعریف_کرو IMAGE_FILE_اوپر_SYSTEM_ONLY 0x4000
#تعریف_کرو IMAGE_FILE_بائٹیں_REVERSED_HI 0x8000

#تعریف_کرو IMAGE_FILE_MACHINE_UNKNOWN 0
#تعریف_کرو IMAGE_FILE_MACHINE_I386 0x014c
#تعریف_کرو IMAGE_FILE_MACHINE_R3000 0x0162
#تعریف_کرو IMAGE_FILE_MACHINE_R4000 0x0166
#تعریف_کرو IMAGE_FILE_MACHINE_R10000 0x0168
#تعریف_کرو IMAGE_FILE_MACHINE_WCEMIPSV2 0x0169
#تعریف_کرو IMAGE_FILE_MACHINE_ALPHA 0x0184
#تعریف_کرو IMAGE_FILE_MACHINE_SH3 0x01a2
#تعریف_کرو IMAGE_FILE_MACHINE_SH3DSP 0x01a3
#تعریف_کرو IMAGE_FILE_MACHINE_SH3E 0x01a4
#تعریف_کرو IMAGE_FILE_MACHINE_SH4 0x01a6
#تعریف_کرو IMAGE_FILE_MACHINE_SH5 0x01a8
#تعریف_کرو IMAGE_FILE_MACHINE_ARM 0x01c0
#تعریف_کرو IMAGE_FILE_MACHINE_THUMB 0x01c2
#تعریف_کرو IMAGE_FILE_MACHINE_AM33 0x01d3
#تعریف_کرو IMAGE_FILE_MACHINE_POWERPC 0x01F0
#تعریف_کرو IMAGE_FILE_MACHINE_POWERPCFP 0x01f1
#تعریف_کرو IMAGE_FILE_MACHINE_IA64 0x0200
#تعریف_کرو IMAGE_FILE_MACHINE_MIPS16 0x0266
#تعریف_کرو IMAGE_FILE_MACHINE_ALPHA64 0x0284
#تعریف_کرو IMAGE_FILE_MACHINE_MIPSFPU 0x0366
#تعریف_کرو IMAGE_FILE_MACHINE_MIPSFPU16 0x0466
#تعریف_کرو IMAGE_FILE_MACHINE_AXP64 IMAGE_FILE_MACHINE_ALPHA64
#تعریف_کرو IMAGE_FILE_MACHINE_TRICORE 0x0520
#تعریف_کرو IMAGE_FILE_MACHINE_CEF 0x0CEF
#تعریف_کرو IMAGE_FILE_MACHINE_EBC 0x0EBC
#تعریف_کرو IMAGE_FILE_MACHINE_AMD64 0x8664
#تعریف_کرو IMAGE_FILE_MACHINE_ARM64 0xAA64
#تعریف_کرو IMAGE_FILE_MACHINE_M32R 0x9041
#تعریف_کرو IMAGE_FILE_MACHINE_CEE 0xC0EE

    قسمتعریف ساخت IMAGE_ڈیٹا_DIRECTORY {
      DWORD Virtual_پتہ;
      DWORD سائز_3;
    } IMAGE_ڈیٹا_DIRECTORY_2,*PIMAGE_ڈیٹا_DIRECTORY;

#تعریف_کرو IMAGE_NUMBEROF_DIRECTORY_ENTRIES 16

    قسمتعریف ساخت IMAGE_OPTIONAL_سرخی {

      لفظ_3 Magic;
      BYTE Major_Linker_نسخہ;
      BYTE Minor_Linker_نسخہ;
      DWORD سائز_کا_رمز;
      DWORD سائز_کا_Initialized_ڈیٹا;
      DWORD سائز_کا_Uninitialized_ڈیٹا;
      DWORD پتہ_کا_اندراج_نقطہ;
      DWORD بنیاد_کا_رمز;
      DWORD بنیاد_کا_ڈیٹا;
      DWORD Image_بنیاد;
      DWORD SectionAlignment;
      DWORD FileAlignment;
      لفظ_3 Major_Operating_System_نسخہ;
      لفظ_3 Minor_Operating_System_نسخہ;
      لفظ_3 Major_Image_نسخہ;
      لفظ_3 Minor_Image_نسخہ;
      لفظ_3 Major_Subsystem_نسخہ;
      لفظ_3 Minor_Subsystem_نسخہ;
      DWORD Win32_نسخہ_قدر;
      DWORD سائز_کا_Image;
      DWORD سائز_کا_سرخیاں;
      DWORD Check_مجموع;
      لفظ_3 Subsystem;
      لفظ_3 DllCharacteristics;
      DWORD سائز_کا_ڈھیر_Reserve;
      DWORD سائز_کا_ڈھیر_Commit;
      DWORD سائز_کا_ڈھیر_Reserve_2;
      DWORD سائز_کا_ڈھیر_Commit_2;
      DWORD LoaderFlags;
      DWORD نمبر_کا_Rva_And_Sizes;
      IMAGE_ڈیٹا_DIRECTORY_2 ڈیٹا_Directory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
    } IMAGE_OPTIONAL_HEADER32,*PIMAGE_OPTIONAL_HEADER32;

    قسمتعریف ساخت IMAGE_ROM_OPTIONAL_سرخی {
      لفظ_3 Magic;
      BYTE Major_Linker_نسخہ;
      BYTE Minor_Linker_نسخہ;
      DWORD سائز_کا_رمز;
      DWORD سائز_کا_Initialized_ڈیٹا;
      DWORD سائز_کا_Uninitialized_ڈیٹا;
      DWORD پتہ_کا_اندراج_نقطہ;
      DWORD بنیاد_کا_رمز;
      DWORD بنیاد_کا_ڈیٹا;
      DWORD بنیاد_کا_Bss;
      DWORD Gpr_نقاب;
      DWORD Cpr_نقاب[4];
      DWORD Gp_قدر;
    } IMAGE_ROM_OPTIONAL_سرخی_2,*PIMAGE_ROM_OPTIONAL_سرخی;

    قسمتعریف ساخت _IMAGE_OPTIONAL_HEADER64 {
      لفظ_3 Magic;
      BYTE Major_Linker_نسخہ;
      BYTE Minor_Linker_نسخہ;
      DWORD سائز_کا_رمز;
      DWORD سائز_کا_Initialized_ڈیٹا;
      DWORD سائز_کا_Uninitialized_ڈیٹا;
      DWORD پتہ_کا_اندراج_نقطہ;
      DWORD بنیاد_کا_رمز;
      ULONGLONG Image_بنیاد;
      DWORD SectionAlignment;
      DWORD FileAlignment;
      لفظ_3 Major_Operating_System_نسخہ;
      لفظ_3 Minor_Operating_System_نسخہ;
      لفظ_3 Major_Image_نسخہ;
      لفظ_3 Minor_Image_نسخہ;
      لفظ_3 Major_Subsystem_نسخہ;
      لفظ_3 Minor_Subsystem_نسخہ;
      DWORD Win32_نسخہ_قدر;
      DWORD سائز_کا_Image;
      DWORD سائز_کا_سرخیاں;
      DWORD Check_مجموع;
      لفظ_3 Subsystem;
      لفظ_3 DllCharacteristics;
      ULONGLONG سائز_کا_ڈھیر_Reserve;
      ULONGLONG سائز_کا_ڈھیر_Commit;
      ULONGLONG سائز_کا_ڈھیر_Reserve_2;
      ULONGLONG سائز_کا_ڈھیر_Commit_2;
      DWORD LoaderFlags;
      DWORD نمبر_کا_Rva_And_Sizes;
      IMAGE_ڈیٹا_DIRECTORY_2 ڈیٹا_Directory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
    } IMAGE_OPTIONAL_HEADER64,*PIMAGE_OPTIONAL_HEADER64;

#تعریف_کرو IMAGE_SIZEOF_ROM_OPTIONAL_سرخی 56
#تعریف_کرو IMAGE_SIZEOF_STD_OPTIONAL_سرخی 28
#تعریف_کرو IMAGE_SIZEOF_NT_OPTIONAL32_سرخی 224
#تعریف_کرو IMAGE_SIZEOF_NT_OPTIONAL64_سرخی 240

#تعریف_کرو IMAGE_NT_OPTIONAL_HDR32_MAGIC 0x10b
#تعریف_کرو IMAGE_NT_OPTIONAL_HDR64_MAGIC 0x20b
#تعریف_کرو IMAGE_ROM_OPTIONAL_HDR_MAGIC 0x107

#اگر_تعریف_شدہ _WIN64
    قسمتعریف IMAGE_OPTIONAL_HEADER64 IMAGE_OPTIONAL_سرخی_2;
    قسمتعریف PIMAGE_OPTIONAL_HEADER64 PIMAGE_OPTIONAL_سرخی;
#تعریف_کرو IMAGE_SIZEOF_NT_OPTIONAL_سرخی IMAGE_SIZEOF_NT_OPTIONAL64_سرخی
#تعریف_کرو IMAGE_NT_OPTIONAL_HDR_MAGIC IMAGE_NT_OPTIONAL_HDR64_MAGIC
#ورنہ
    قسمتعریف IMAGE_OPTIONAL_HEADER32 IMAGE_OPTIONAL_سرخی_2;
    قسمتعریف PIMAGE_OPTIONAL_HEADER32 PIMAGE_OPTIONAL_سرخی;
#تعریف_کرو IMAGE_SIZEOF_NT_OPTIONAL_سرخی IMAGE_SIZEOF_NT_OPTIONAL32_سرخی
#تعریف_کرو IMAGE_NT_OPTIONAL_HDR_MAGIC IMAGE_NT_OPTIONAL_HDR32_MAGIC
#اگر_ختم

    قسمتعریف ساخت _IMAGE_NT_HEADERS64 {
      DWORD Signature;
      IMAGE_FILE_سرخی_2 File_سرخی;
      IMAGE_OPTIONAL_HEADER64 Optional_سرخی;
    } IMAGE_NT_HEADERS64,*PIMAGE_NT_HEADERS64;

    قسمتعریف ساخت IMAGE_NT_سرخیاں {
      DWORD Signature;
      IMAGE_FILE_سرخی_2 File_سرخی;
      IMAGE_OPTIONAL_HEADER32 Optional_سرخی;
    } IMAGE_NT_HEADERS32,*PIMAGE_NT_HEADERS32;

    قسمتعریف ساخت IMAGE_ROM_سرخیاں {
      IMAGE_FILE_سرخی_2 File_سرخی;
      IMAGE_ROM_OPTIONAL_سرخی_2 Optional_سرخی;
    } IMAGE_ROM_سرخیاں_2,*PIMAGE_ROM_سرخیاں;

#اگر_تعریف_شدہ _WIN64
    قسمتعریف IMAGE_NT_HEADERS64 IMAGE_NT_سرخیاں_2;
    قسمتعریف PIMAGE_NT_HEADERS64 PIMAGE_NT_سرخیاں;
#ورنہ
    قسمتعریف IMAGE_NT_HEADERS32 IMAGE_NT_سرخیاں_2;
    قسمتعریف PIMAGE_NT_HEADERS32 PIMAGE_NT_سرخیاں;
#اگر_ختم

#تعریف_کرو IMAGE_پہلا_SECTION(ntheader) ((PIMAGE_SECTION_سرخی) ((ULONG_PTR)ntheader + میدان_انحراف(IMAGE_NT_سرخیاں_2,Optional_سرخی) + ((PIMAGE_NT_سرخیاں)(ntheader))->File_سرخی.سائز_کا_Optional_سرخی))

#تعریف_کرو IMAGE_SUBSYSTEM_UNKNOWN 0
#تعریف_کرو IMAGE_SUBSYSTEM_NATIVE 1
#تعریف_کرو IMAGE_SUBSYSTEM_WINDOWS_GUI 2
#تعریف_کرو IMAGE_SUBSYSTEM_WINDOWS_CUI 3
#تعریف_کرو IMAGE_SUBSYSTEM_OS2_CUI 5
#تعریف_کرو IMAGE_SUBSYSTEM_POSIX_CUI 7
#تعریف_کرو IMAGE_SUBSYSTEM_NATIVE_WINDOWS 8
#تعریف_کرو IMAGE_SUBSYSTEM_WINDOWS_CE_GUI 9
#تعریف_کرو IMAGE_SUBSYSTEM_EFI_APPLICATION 10
#تعریف_کرو IMAGE_SUBSYSTEM_EFI_BOOT_SERVICE_DRIVER 11
#تعریف_کرو IMAGE_SUBSYSTEM_EFI_RUNTIME_DRIVER 12
#تعریف_کرو IMAGE_SUBSYSTEM_EFI_ROM 13
#تعریف_کرو IMAGE_SUBSYSTEM_XBOX 14

#تعریف_کرو IMAGE_DLLCHARACTERISTICS_بلند_ENTROPY_VA 0x0020
#تعریف_کرو IMAGE_DLLCHARACTERISTICS_DYNAMIC_بنیاد 0x0040
#تعریف_کرو IMAGE_DLLCHARACTERISTICS_FORCE_INTEGRITY 0x0080
#تعریف_کرو IMAGE_DLLCHARACTERISTICS_NX_COMPAT 0x0100
#تعریف_کرو IMAGE_DLLCHARACTERISTICS_NO_ISOLATION 0x0200
#تعریف_کرو IMAGE_DLLCHARACTERISTICS_NO_SEH 0x0400
#تعریف_کرو IMAGE_DLLCHARACTERISTICS_NO_BIND 0x0800
#تعریف_کرو IMAGE_DLLCHARACTERISTICS_APPCONTAINER 0x1000
#تعریف_کرو IMAGE_DLLCHARACTERISTICS_WDM_DRIVER 0x2000
#تعریف_کرو IMAGE_DLLCHARACTERISTICS_GUARD_CF 0x4000
#تعریف_کرو IMAGE_DLLCHARACTERISTICS_TERMINAL_SERVER_AWARE 0x8000

#تعریف_کرو IMAGE_DIRECTORY_اندراج_EXPORT 0
#تعریف_کرو IMAGE_DIRECTORY_اندراج_IMPORT 1
#تعریف_کرو IMAGE_DIRECTORY_اندراج_RESOURCE 2
#تعریف_کرو IMAGE_DIRECTORY_اندراج_EXCEPTION 3
#تعریف_کرو IMAGE_DIRECTORY_اندراج_SECURITY 4
#تعریف_کرو IMAGE_DIRECTORY_اندراج_BASERELOC 5
#تعریف_کرو IMAGE_DIRECTORY_اندراج_DEBUG 6

#تعریف_کرو IMAGE_DIRECTORY_اندراج_ARCHITECTURE 7
#تعریف_کرو IMAGE_DIRECTORY_اندراج_GLOBALPTR 8
#تعریف_کرو IMAGE_DIRECTORY_اندراج_TLS 9
#تعریف_کرو IMAGE_DIRECTORY_اندراج_بھرو_CONFIG 10
#تعریف_کرو IMAGE_DIRECTORY_اندراج_BOUND_IMPORT 11
#تعریف_کرو IMAGE_DIRECTORY_اندراج_IAT 12
#تعریف_کرو IMAGE_DIRECTORY_اندراج_DELAY_IMPORT 13
#تعریف_کرو IMAGE_DIRECTORY_اندراج_COM_DESCRIPTOR 14

    قسمتعریف ساخت ANON_OBJECT_سرخی {
      لفظ_3 Sig1;
      لفظ_3 Sig2;
      لفظ_3 نسخہ_2;
      لفظ_3 Machine;
      DWORD وقت_Date_Stamp;
      CLSID ClassID;
      DWORD سائز_کا_ڈیٹا;
    } ANON_OBJECT_سرخی;

#تعریف_کرو IMAGE_SIZEOF_SHORT_NAME 8

    قسمتعریف ساخت IMAGE_SECTION_سرخی {
      BYTE Name[IMAGE_SIZEOF_SHORT_NAME];
      اتحاد {
	DWORD Physical_پتہ;
	DWORD Virtual_سائز;
      } Misc;
      DWORD Virtual_پتہ;
      DWORD سائز_کا_Raw_ڈیٹا;
      DWORD اشارہ_گر_مقصد_Raw_ڈیٹا;
      DWORD اشارہ_گر_مقصد_Relocations;
      DWORD اشارہ_گر_مقصد_Linenumbers;
      لفظ_3 نمبر_کا_Relocations;
      لفظ_3 نمبر_کا_Linenumbers;
      DWORD Characteristics;
    } IMAGE_SECTION_سرخی_2,*PIMAGE_SECTION_سرخی;

#تعریف_کرو IMAGE_SIZEOF_SECTION_سرخی 40

#تعریف_کرو IMAGE_SCN_TYPE_NO_PAD 0x00000008

#تعریف_کرو IMAGE_SCN_CNT_رمز 0x00000020
#تعریف_کرو IMAGE_SCN_CNT_INITIALIZED_ڈیٹا 0x00000040
#تعریف_کرو IMAGE_SCN_CNT_UNINITIALIZED_ڈیٹا 0x00000080
#تعریف_کرو IMAGE_SCN_LNK_OTHER 0x00000100
#تعریف_کرو IMAGE_SCN_LNK_INFO 0x00000200
#تعریف_کرو IMAGE_SCN_LNK_REMOVE 0x00000800
#تعریف_کرو IMAGE_SCN_LNK_COMDAT 0x00001000
#تعریف_کرو IMAGE_SCN_NO_DEFER_SPEC_EXC 0x00004000
#تعریف_کرو IMAGE_SCN_GPREL 0x00008000
#تعریف_کرو IMAGE_SCN_MEM_FARDATA 0x00008000
#تعریف_کرو IMAGE_SCN_MEM_PURGEABLE 0x00020000
#تعریف_کرو IMAGE_SCN_MEM_16_ثنائی_ہندسہ 0x00020000
#تعریف_کرو IMAGE_SCN_MEM_LOCKED 0x00040000
#تعریف_کرو IMAGE_SCN_MEM_PRELOAD 0x00080000

#تعریف_کرو IMAGE_SCN_ALIGN_1_بائٹیں 0x00100000
#تعریف_کرو IMAGE_SCN_ALIGN_2_بائٹیں 0x00200000
#تعریف_کرو IMAGE_SCN_ALIGN_4_بائٹیں 0x00300000
#تعریف_کرو IMAGE_SCN_ALIGN_8_بائٹیں 0x00400000
#تعریف_کرو IMAGE_SCN_ALIGN_16_بائٹیں 0x00500000
#تعریف_کرو IMAGE_SCN_ALIGN_32_بائٹیں 0x00600000
#تعریف_کرو IMAGE_SCN_ALIGN_64_بائٹیں 0x00700000
#تعریف_کرو IMAGE_SCN_ALIGN_128_بائٹیں 0x00800000
#تعریف_کرو IMAGE_SCN_ALIGN_256_بائٹیں 0x00900000
#تعریف_کرو IMAGE_SCN_ALIGN_512_بائٹیں 0x00A00000
#تعریف_کرو IMAGE_SCN_ALIGN_1024_بائٹیں 0x00B00000
#تعریف_کرو IMAGE_SCN_ALIGN_2048_بائٹیں 0x00C00000
#تعریف_کرو IMAGE_SCN_ALIGN_4096_بائٹیں 0x00D00000
#تعریف_کرو IMAGE_SCN_ALIGN_8192_بائٹیں 0x00E00000

#تعریف_کرو IMAGE_SCN_ALIGN_نقاب 0x00F00000

#تعریف_کرو IMAGE_SCN_LNK_NRELOC_OVFL 0x01000000
#تعریف_کرو IMAGE_SCN_MEM_DISCARDABLE 0x02000000
#تعریف_کرو IMAGE_SCN_MEM_NOT_CACHED 0x04000000
#تعریف_کرو IMAGE_SCN_MEM_NOT_PAGED 0x08000000
#تعریف_کرو IMAGE_SCN_MEM_SHARED 0x10000000
#تعریف_کرو IMAGE_SCN_MEM_EXECUTE 0x20000000
#تعریف_کرو IMAGE_SCN_MEM_READ 0x40000000
#تعریف_کرو IMAGE_SCN_MEM_WRITE 0x80000000

#تعریف_کرو IMAGE_SCN_SCALE_اشاریہ 0x00000001

#شامل "pshpack2.h"

    قسمتعریف ساخت IMAGE_علامت {
      اتحاد {
	BYTE ShortName[8];
	ساخت {
	  DWORD Short;
	  DWORD Long;
	} Name;
	DWORD LongName[2];
      } N;
      DWORD قدر_3;
      SHORT Section_نمبر;
      لفظ_3 Type;
      BYTE StorageClass;
      BYTE نمبر_کا_Aux_Symbols;
    } IMAGE_علامت_2;
    قسمتعریف IMAGE_علامت_2 UNALIGNED *PIMAGE_علامت;

#تعریف_کرو IMAGE_SIZEOF_علامت 18

#تعریف_کرو IMAGE_SYM_UNDEFINED (SHORT)0
#تعریف_کرو IMAGE_SYM_ABSOLUTE (SHORT)-1
#تعریف_کرو IMAGE_SYM_DEBUG (SHORT)-2
#تعریف_کرو IMAGE_SYM_SECTION_MAX 0xFEFF

#تعریف_کرو IMAGE_SYM_TYPE_NULL 0x0000
#تعریف_کرو IMAGE_SYM_TYPE_VOID 0x0001
#تعریف_کرو IMAGE_SYM_TYPE_CHAR 0x0002
#تعریف_کرو IMAGE_SYM_TYPE_SHORT 0x0003
#تعریف_کرو IMAGE_SYM_TYPE_INT 0x0004
#تعریف_کرو IMAGE_SYM_TYPE_LONG 0x0005
#تعریف_کرو IMAGE_SYM_TYPE_FLOAT 0x0006
#تعریف_کرو IMAGE_SYM_TYPE_DOUBLE 0x0007
#تعریف_کرو IMAGE_SYM_TYPE_STRUCT 0x0008
#تعریف_کرو IMAGE_SYM_TYPE_UNION 0x0009
#تعریف_کرو IMAGE_SYM_TYPE_ENUM 0x000A
#تعریف_کرو IMAGE_SYM_TYPE_MOE 0x000B
#تعریف_کرو IMAGE_SYM_TYPE_BYTE 0x000C
#تعریف_کرو IMAGE_SYM_TYPE_لفظ 0x000D
#تعریف_کرو IMAGE_SYM_TYPE_UINT 0x000E
#تعریف_کرو IMAGE_SYM_TYPE_DWORD 0x000F
#تعریف_کرو IMAGE_SYM_TYPE_PCODE 0x8000

#تعریف_کرو IMAGE_SYM_DTYPE_NULL 0
#تعریف_کرو IMAGE_SYM_DTYPE_اشارہ_گر 1
#تعریف_کرو IMAGE_SYM_DTYPE_FUNCTION 2
#تعریف_کرو IMAGE_SYM_DTYPE_ARRAY 3

#تعریف_کرو IMAGE_SYM_CLASS_انتہا_کا_FUNCTION (BYTE)-1
#تعریف_کرو IMAGE_SYM_CLASS_NULL 0x0000
#تعریف_کرو IMAGE_SYM_CLASS_AUTOMATIC 0x0001
#تعریف_کرو IMAGE_SYM_CLASS_EXTERNAL 0x0002
#تعریف_کرو IMAGE_SYM_CLASS_STATIC 0x0003
#تعریف_کرو IMAGE_SYM_CLASS_رجسٹر 0x0004
#تعریف_کرو IMAGE_SYM_CLASS_EXTERNAL_DEF 0x0005
#تعریف_کرو IMAGE_SYM_CLASS_LABEL 0x0006
#تعریف_کرو IMAGE_SYM_CLASS_UNDEFINED_LABEL 0x0007
#تعریف_کرو IMAGE_SYM_CLASS_MEMBER_کا_STRUCT 0x0008
#تعریف_کرو IMAGE_SYM_CLASS_دلیل 0x0009
#تعریف_کرو IMAGE_SYM_CLASS_STRUCT_لیبل 0x000A
#تعریف_کرو IMAGE_SYM_CLASS_MEMBER_کا_UNION 0x000B
#تعریف_کرو IMAGE_SYM_CLASS_UNION_لیبل 0x000C
#تعریف_کرو IMAGE_SYM_CLASS_TYPE_DEFINITION 0x000D
#تعریف_کرو IMAGE_SYM_CLASS_UNDEFINED_STATIC 0x000E
#تعریف_کرو IMAGE_SYM_CLASS_ENUM_لیبل 0x000F
#تعریف_کرو IMAGE_SYM_CLASS_MEMBER_کا_ENUM 0x0010
#تعریف_کرو IMAGE_SYM_CLASS_رجسٹر_PARAM 0x0011
#تعریف_کرو IMAGE_SYM_CLASS_ثنائی_ہندسہ_میدان 0x0012
#تعریف_کرو IMAGE_SYM_CLASS_FAR_EXTERNAL 0x0044
#تعریف_کرو IMAGE_SYM_CLASS_بلاک 0x0064
#تعریف_کرو IMAGE_SYM_CLASS_FUNCTION 0x0065
#تعریف_کرو IMAGE_SYM_CLASS_انتہا_کا_STRUCT 0x0066
#تعریف_کرو IMAGE_SYM_CLASS_FILE 0x0067
#تعریف_کرو IMAGE_SYM_CLASS_SECTION 0x0068
#تعریف_کرو IMAGE_SYM_CLASS_WEAK_EXTERNAL 0x0069
#تعریف_کرو IMAGE_SYM_CLASS_CLR_TOKEN 0x006B

#تعریف_کرو N_BTMASK 0x000F
#تعریف_کرو N_TMASK 0x0030
#تعریف_کرو N_TMASK1 0x00C0
#تعریف_کرو N_TMASK2 0x00F0
#تعریف_کرو N_BTSHFT 4
#تعریف_کرو N_TSHIFT 2

#تعریف_کرو BTYPE(x) ((x) & N_BTMASK)

#اگر_غیر_تعریف_شدہ ISPTR
#تعریف_کرو ISPTR(x) (((x) & N_TMASK)==(IMAGE_SYM_DTYPE_اشارہ_گر << N_BTSHFT))
#اگر_ختم

#اگر_غیر_تعریف_شدہ ISFCN
#تعریف_کرو ISFCN(x) (((x) & N_TMASK)==(IMAGE_SYM_DTYPE_FUNCTION << N_BTSHFT))
#اگر_ختم

#اگر_غیر_تعریف_شدہ ISARY
#تعریف_کرو ISARY(x) (((x) & N_TMASK)==(IMAGE_SYM_DTYPE_ARRAY << N_BTSHFT))
#اگر_ختم

#اگر_غیر_تعریف_شدہ ISTAG
#تعریف_کرو ISTAG(x) ((x)==IMAGE_SYM_CLASS_STRUCT_لیبل || (x)==IMAGE_SYM_CLASS_UNION_لیبل || (x)==IMAGE_SYM_CLASS_ENUM_لیبل)
#اگر_ختم

#اگر_غیر_تعریف_شدہ INCREF
#تعریف_کرو INCREF(x) ((((x)&~N_BTMASK)<<N_TSHIFT)|(IMAGE_SYM_DTYPE_اشارہ_گر<<N_BTSHFT)|((x)&N_BTMASK))
#اگر_ختم
#اگر_غیر_تعریف_شدہ DECREF
#تعریف_کرو DECREF(x) ((((x)>>N_TSHIFT)&~N_BTMASK)|((x)&N_BTMASK))
#اگر_ختم

    قسمتعریف اتحاد IMAGE_AUX_علامت {
      ساخت {
	DWORD لیبل_اشاریہ;
	اتحاد {
	  ساخت {
	    لفظ_3 Linenumber;
	    لفظ_3 سائز_3;
	  } LnSz;
	  DWORD کل_سائز;
	} Misc;
	اتحاد {
	  ساخت {
	    DWORD اشارہ_گر_مقصد_Linenumber;
	    DWORD اشارہ_گر_مقصد_اگلا_Function;
	  } Function;
	  ساخت {
	    لفظ_3 Dimension[4];
	  } Array;
	} FcnAry;
	لفظ_3 Tv_اشاریہ;
      } Sym;
      ساخت {
	BYTE Name[IMAGE_SIZEOF_علامت];
      } File;
      ساخت {
	DWORD لمبائی_2;
	لفظ_3 نمبر_کا_Relocations;
	لفظ_3 نمبر_کا_Linenumbers;
	DWORD Check_مجموع;
	SHORT نمبر_2;
	BYTE Selection;
      } Section;
    } IMAGE_AUX_علامت_2;
    قسمتعریف IMAGE_AUX_علامت_2 UNALIGNED *PIMAGE_AUX_علامت;

#تعریف_کرو IMAGE_SIZEOF_AUX_علامت 18

    قسمتعریف شمار IMAGE_AUX_علامت_TYPE {
      IMAGE_AUX_علامت_TYPE_TOKEN_DEF = 1
    } IMAGE_AUX_علامت_TYPE;

#شامل <pshpack2.h>

    قسمتعریف ساخت IMAGE_AUX_علامت_TOKEN_DEF {
      BYTE bAuxType;
      BYTE bReserved;
      DWORD علامت_جدول_اشاریہ;
      BYTE rgbReserved[12];
    } IMAGE_AUX_علامت_TOKEN_DEF;

    قسمتعریف IMAGE_AUX_علامت_TOKEN_DEF UNALIGNED *PIMAGE_AUX_علامت_TOKEN_DEF;

#شامل <poppack.h>

#تعریف_کرو IMAGE_COMDAT_SELECT_NODUPLICATES 1
#تعریف_کرو IMAGE_COMDAT_SELECT_ANY 2
#تعریف_کرو IMAGE_COMDAT_SELECT_SAME_سائز 3
#تعریف_کرو IMAGE_COMDAT_SELECT_EXACT_مطابقت 4
#تعریف_کرو IMAGE_COMDAT_SELECT_ASSOCIATIVE 5
#تعریف_کرو IMAGE_COMDAT_SELECT_سب_سے_بڑا 6
#تعریف_کرو IMAGE_COMDAT_SELECT_NEWEST 7

#تعریف_کرو IMAGE_WEAK_EXTERN_تلاش_NOLIBRARY 1
#تعریف_کرو IMAGE_WEAK_EXTERN_تلاش_LIBRARY 2
#تعریف_کرو IMAGE_WEAK_EXTERN_تلاش_ALIAS 3

    قسمتعریف ساخت _IMAGE_RELOCATION {
      اتحاد {
	DWORD Virtual_پتہ;
	DWORD Reloc_گنتی;
      };
      DWORD علامت_جدول_اشاریہ;
      لفظ_3 Type;
    } IMAGE_RELOCATION;
    قسمتعریف IMAGE_RELOCATION UNALIGNED *PIMAGE_RELOCATION;

#تعریف_کرو IMAGE_SIZEOF_RELOCATION 10

#تعریف_کرو IMAGE_REL_I386_ABSOLUTE 0x0000
#تعریف_کرو IMAGE_REL_I386_DIR16 0x0001
#تعریف_کرو IMAGE_REL_I386_REL16 0x0002
#تعریف_کرو IMAGE_REL_I386_DIR32 0x0006
#تعریف_کرو IMAGE_REL_I386_DIR32NB 0x0007
#تعریف_کرو IMAGE_REL_I386_SEG12 0x0009
#تعریف_کرو IMAGE_REL_I386_SECTION 0x000A
#تعریف_کرو IMAGE_REL_I386_SECREL 0x000B
#تعریف_کرو IMAGE_REL_I386_TOKEN 0x000C
#تعریف_کرو IMAGE_REL_I386_SECREL7 0x000D
#تعریف_کرو IMAGE_REL_I386_REL32 0x0014

#تعریف_کرو IMAGE_REL_MIPS_ABSOLUTE 0x0000
#تعریف_کرو IMAGE_REL_MIPS_REFHALF 0x0001
#تعریف_کرو IMAGE_REL_MIPS_REFWORD 0x0002
#تعریف_کرو IMAGE_REL_MIPS_JMPADDR 0x0003
#تعریف_کرو IMAGE_REL_MIPS_REFHI 0x0004
#تعریف_کرو IMAGE_REL_MIPS_REFLO 0x0005
#تعریف_کرو IMAGE_REL_MIPS_GPREL 0x0006
#تعریف_کرو IMAGE_REL_MIPS_LITERAL 0x0007
#تعریف_کرو IMAGE_REL_MIPS_SECTION 0x000A
#تعریف_کرو IMAGE_REL_MIPS_SECREL 0x000B
#تعریف_کرو IMAGE_REL_MIPS_SECRELLO 0x000C
#تعریف_کرو IMAGE_REL_MIPS_SECRELHI 0x000D
#تعریف_کرو IMAGE_REL_MIPS_TOKEN 0x000E
#تعریف_کرو IMAGE_REL_MIPS_JMPADDR16 0x0010
#تعریف_کرو IMAGE_REL_MIPS_REFWORDNB 0x0022
#تعریف_کرو IMAGE_REL_MIPS_PAIR 0x0025

#تعریف_کرو IMAGE_REL_ALPHA_ABSOLUTE 0x0000
#تعریف_کرو IMAGE_REL_ALPHA_REFLONG 0x0001
#تعریف_کرو IMAGE_REL_ALPHA_REFQUAD 0x0002
#تعریف_کرو IMAGE_REL_ALPHA_GPREL32 0x0003
#تعریف_کرو IMAGE_REL_ALPHA_LITERAL 0x0004
#تعریف_کرو IMAGE_REL_ALPHA_LITUSE 0x0005
#تعریف_کرو IMAGE_REL_ALPHA_GPDISP 0x0006
#تعریف_کرو IMAGE_REL_ALPHA_BRADDR 0x0007
#تعریف_کرو IMAGE_REL_ALPHA_HINT 0x0008
#تعریف_کرو IMAGE_REL_ALPHA_INLINE_REFLONG 0x0009
#تعریف_کرو IMAGE_REL_ALPHA_REFHI 0x000A
#تعریف_کرو IMAGE_REL_ALPHA_REFLO 0x000B
#تعریف_کرو IMAGE_REL_ALPHA_PAIR 0x000C
#تعریف_کرو IMAGE_REL_ALPHA_مطابقت 0x000D
#تعریف_کرو IMAGE_REL_ALPHA_SECTION 0x000E
#تعریف_کرو IMAGE_REL_ALPHA_SECREL 0x000F
#تعریف_کرو IMAGE_REL_ALPHA_REFLONGNB 0x0010
#تعریف_کرو IMAGE_REL_ALPHA_SECRELLO 0x0011
#تعریف_کرو IMAGE_REL_ALPHA_SECRELHI 0x0012
#تعریف_کرو IMAGE_REL_ALPHA_REFQ3 0x0013
#تعریف_کرو IMAGE_REL_ALPHA_REFQ2 0x0014
#تعریف_کرو IMAGE_REL_ALPHA_REFQ1 0x0015
#تعریف_کرو IMAGE_REL_ALPHA_GPRELLO 0x0016
#تعریف_کرو IMAGE_REL_ALPHA_GPRELHI 0x0017

#تعریف_کرو IMAGE_REL_PPC_ABSOLUTE 0x0000
#تعریف_کرو IMAGE_REL_PPC_ADDR64 0x0001
#تعریف_کرو IMAGE_REL_PPC_ADDR32 0x0002
#تعریف_کرو IMAGE_REL_PPC_ADDR24 0x0003
#تعریف_کرو IMAGE_REL_PPC_ADDR16 0x0004
#تعریف_کرو IMAGE_REL_PPC_ADDR14 0x0005
#تعریف_کرو IMAGE_REL_PPC_REL24 0x0006
#تعریف_کرو IMAGE_REL_PPC_REL14 0x0007
#تعریف_کرو IMAGE_REL_PPC_TOCREL16 0x0008
#تعریف_کرو IMAGE_REL_PPC_TOCREL14 0x0009
#تعریف_کرو IMAGE_REL_PPC_ADDR32NB 0x000A
#تعریف_کرو IMAGE_REL_PPC_SECREL 0x000B
#تعریف_کرو IMAGE_REL_PPC_SECTION 0x000C
#تعریف_کرو IMAGE_REL_PPC_IFGLUE 0x000D
#تعریف_کرو IMAGE_REL_PPC_IMGLUE 0x000E
#تعریف_کرو IMAGE_REL_PPC_SECREL16 0x000F
#تعریف_کرو IMAGE_REL_PPC_REFHI 0x0010
#تعریف_کرو IMAGE_REL_PPC_REFLO 0x0011
#تعریف_کرو IMAGE_REL_PPC_PAIR 0x0012
#تعریف_کرو IMAGE_REL_PPC_SECRELLO 0x0013
#تعریف_کرو IMAGE_REL_PPC_SECRELHI 0x0014
#تعریف_کرو IMAGE_REL_PPC_GPREL 0x0015
#تعریف_کرو IMAGE_REL_PPC_TOKEN 0x0016
#تعریف_کرو IMAGE_REL_PPC_TYPEMASK 0x00FF
#تعریف_کرو IMAGE_REL_PPC_NEG 0x0100
#تعریف_کرو IMAGE_REL_PPC_BRTAKEN 0x0200
#تعریف_کرو IMAGE_REL_PPC_BRNTAKEN 0x0400
#تعریف_کرو IMAGE_REL_PPC_TOCDEFN 0x0800

#تعریف_کرو IMAGE_REL_SH3_ABSOLUTE 0x0000
#تعریف_کرو IMAGE_REL_SH3_DIRECT16 0x0001
#تعریف_کرو IMAGE_REL_SH3_DIRECT32 0x0002
#تعریف_کرو IMAGE_REL_SH3_DIRECT8 0x0003
#تعریف_کرو IMAGE_REL_SH3_DIRECT8_لفظ 0x0004
#تعریف_کرو IMAGE_REL_SH3_DIRECT8_LONG 0x0005
#تعریف_کرو IMAGE_REL_SH3_DIRECT4 0x0006
#تعریف_کرو IMAGE_REL_SH3_DIRECT4_لفظ 0x0007
#تعریف_کرو IMAGE_REL_SH3_DIRECT4_LONG 0x0008
#تعریف_کرو IMAGE_REL_SH3_PCREL8_لفظ 0x0009
#تعریف_کرو IMAGE_REL_SH3_PCREL8_LONG 0x000A
#تعریف_کرو IMAGE_REL_SH3_PCREL12_لفظ 0x000B
#تعریف_کرو IMAGE_REL_SH3_STARTOF_SECTION 0x000C
#تعریف_کرو IMAGE_REL_SH3_SIZEOF_SECTION 0x000D
#تعریف_کرو IMAGE_REL_SH3_SECTION 0x000E
#تعریف_کرو IMAGE_REL_SH3_SECREL 0x000F
#تعریف_کرو IMAGE_REL_SH3_DIRECT32_NB 0x0010
#تعریف_کرو IMAGE_REL_SH3_GPREL4_LONG 0x0011
#تعریف_کرو IMAGE_REL_SH3_TOKEN 0x0012

#تعریف_کرو IMAGE_REL_SHM_PCRELPT 0x0013
#تعریف_کرو IMAGE_REL_SHM_REFLO 0x0014
#تعریف_کرو IMAGE_REL_SHM_REFHALF 0x0015
#تعریف_کرو IMAGE_REL_SHM_RELLO 0x0016
#تعریف_کرو IMAGE_REL_SHM_RELHALF 0x0017
#تعریف_کرو IMAGE_REL_SHM_PAIR 0x0018

#تعریف_کرو IMAGE_REL_SH_NOMODE 0x8000

#تعریف_کرو IMAGE_REL_ARM_ABSOLUTE 0x0000
#تعریف_کرو IMAGE_REL_ARM_ADDR32 0x0001
#تعریف_کرو IMAGE_REL_ARM_ADDR32NB 0x0002
#تعریف_کرو IMAGE_REL_ARM_BRANCH24 0x0003
#تعریف_کرو IMAGE_REL_ARM_BRANCH11 0x0004
#تعریف_کرو IMAGE_REL_ARM_TOKEN 0x0005
#تعریف_کرو IMAGE_REL_ARM_GPREL12 0x0006
#تعریف_کرو IMAGE_REL_ARM_GPREL7 0x0007
#تعریف_کرو IMAGE_REL_ARM_BLX24 0x0008
#تعریف_کرو IMAGE_REL_ARM_BLX11 0x0009
#تعریف_کرو IMAGE_REL_ARM_SECTION 0x000E
#تعریف_کرو IMAGE_REL_ARM_SECREL 0x000F

#تعریف_کرو IMAGE_REL_AM_ABSOLUTE 0x0000
#تعریف_کرو IMAGE_REL_AM_ADDR32 0x0001
#تعریف_کرو IMAGE_REL_AM_ADDR32NB 0x0002
#تعریف_کرو IMAGE_REL_AM_CALL32 0x0003
#تعریف_کرو IMAGE_REL_AM_FUNCINFO 0x0004
#تعریف_کرو IMAGE_REL_AM_REL32_1 0x0005
#تعریف_کرو IMAGE_REL_AM_REL32_2 0x0006
#تعریف_کرو IMAGE_REL_AM_SECREL 0x0007
#تعریف_کرو IMAGE_REL_AM_SECTION 0x0008
#تعریف_کرو IMAGE_REL_AM_TOKEN 0x0009

#تعریف_کرو IMAGE_REL_AMD64_ABSOLUTE 0x0000
#تعریف_کرو IMAGE_REL_AMD64_ADDR64 0x0001
#تعریف_کرو IMAGE_REL_AMD64_ADDR32 0x0002
#تعریف_کرو IMAGE_REL_AMD64_ADDR32NB 0x0003
#تعریف_کرو IMAGE_REL_AMD64_REL32 0x0004
#تعریف_کرو IMAGE_REL_AMD64_REL32_1 0x0005
#تعریف_کرو IMAGE_REL_AMD64_REL32_2 0x0006
#تعریف_کرو IMAGE_REL_AMD64_REL32_3 0x0007
#تعریف_کرو IMAGE_REL_AMD64_REL32_4 0x0008
#تعریف_کرو IMAGE_REL_AMD64_REL32_5 0x0009
#تعریف_کرو IMAGE_REL_AMD64_SECTION 0x000A
#تعریف_کرو IMAGE_REL_AMD64_SECREL 0x000B
#تعریف_کرو IMAGE_REL_AMD64_SECREL7 0x000C
#تعریف_کرو IMAGE_REL_AMD64_TOKEN 0x000D
#تعریف_کرو IMAGE_REL_AMD64_SREL32 0x000E
#تعریف_کرو IMAGE_REL_AMD64_PAIR 0x000F
#تعریف_کرو IMAGE_REL_AMD64_SSPAN32 0x0010

#تعریف_کرو IMAGE_REL_IA64_ABSOLUTE 0x0000
#تعریف_کرو IMAGE_REL_IA64_IMM14 0x0001
#تعریف_کرو IMAGE_REL_IA64_IMM22 0x0002
#تعریف_کرو IMAGE_REL_IA64_IMM64 0x0003
#تعریف_کرو IMAGE_REL_IA64_DIR32 0x0004
#تعریف_کرو IMAGE_REL_IA64_DIR64 0x0005
#تعریف_کرو IMAGE_REL_IA64_PCREL21B 0x0006
#تعریف_کرو IMAGE_REL_IA64_PCREL21M 0x0007
#تعریف_کرو IMAGE_REL_IA64_PCREL21F 0x0008
#تعریف_کرو IMAGE_REL_IA64_GPREL22 0x0009
#تعریف_کرو IMAGE_REL_IA64_LTOFF22 0x000A
#تعریف_کرو IMAGE_REL_IA64_SECTION 0x000B
#تعریف_کرو IMAGE_REL_IA64_SECREL22 0x000C
#تعریف_کرو IMAGE_REL_IA64_SECREL64I 0x000D
#تعریف_کرو IMAGE_REL_IA64_SECREL32 0x000E

#تعریف_کرو IMAGE_REL_IA64_DIR32NB 0x0010
#تعریف_کرو IMAGE_REL_IA64_SREL14 0x0011
#تعریف_کرو IMAGE_REL_IA64_SREL22 0x0012
#تعریف_کرو IMAGE_REL_IA64_SREL32 0x0013
#تعریف_کرو IMAGE_REL_IA64_UREL32 0x0014
#تعریف_کرو IMAGE_REL_IA64_PCREL60X 0x0015
#تعریف_کرو IMAGE_REL_IA64_PCREL60B 0x0016
#تعریف_کرو IMAGE_REL_IA64_PCREL60F 0x0017
#تعریف_کرو IMAGE_REL_IA64_PCREL60I 0x0018
#تعریف_کرو IMAGE_REL_IA64_PCREL60M 0x0019
#تعریف_کرو IMAGE_REL_IA64_IMMGPREL64 0x001A
#تعریف_کرو IMAGE_REL_IA64_TOKEN 0x001B
#تعریف_کرو IMAGE_REL_IA64_GPREL32 0x001C
#تعریف_کرو IMAGE_REL_IA64_ADDEND 0x001F

#تعریف_کرو IMAGE_REL_CEF_ABSOLUTE 0x0000
#تعریف_کرو IMAGE_REL_CEF_ADDR32 0x0001
#تعریف_کرو IMAGE_REL_CEF_ADDR64 0x0002
#تعریف_کرو IMAGE_REL_CEF_ADDR32NB 0x0003
#تعریف_کرو IMAGE_REL_CEF_SECTION 0x0004
#تعریف_کرو IMAGE_REL_CEF_SECREL 0x0005
#تعریف_کرو IMAGE_REL_CEF_TOKEN 0x0006

#تعریف_کرو IMAGE_REL_CEE_ABSOLUTE 0x0000
#تعریف_کرو IMAGE_REL_CEE_ADDR32 0x0001
#تعریف_کرو IMAGE_REL_CEE_ADDR64 0x0002
#تعریف_کرو IMAGE_REL_CEE_ADDR32NB 0x0003
#تعریف_کرو IMAGE_REL_CEE_SECTION 0x0004
#تعریف_کرو IMAGE_REL_CEE_SECREL 0x0005
#تعریف_کرو IMAGE_REL_CEE_TOKEN 0x0006

#تعریف_کرو IMAGE_REL_M32R_ABSOLUTE 0x0000
#تعریف_کرو IMAGE_REL_M32R_ADDR32 0x0001
#تعریف_کرو IMAGE_REL_M32R_ADDR32NB 0x0002
#تعریف_کرو IMAGE_REL_M32R_ADDR24 0x0003
#تعریف_کرو IMAGE_REL_M32R_GPREL16 0x0004
#تعریف_کرو IMAGE_REL_M32R_PCREL24 0x0005
#تعریف_کرو IMAGE_REL_M32R_PCREL16 0x0006
#تعریف_کرو IMAGE_REL_M32R_PCREL8 0x0007
#تعریف_کرو IMAGE_REL_M32R_REFHALF 0x0008
#تعریف_کرو IMAGE_REL_M32R_REFHI 0x0009
#تعریف_کرو IMAGE_REL_M32R_REFLO 0x000A
#تعریف_کرو IMAGE_REL_M32R_PAIR 0x000B
#تعریف_کرو IMAGE_REL_M32R_SECTION 0x000C
#تعریف_کرو IMAGE_REL_M32R_SECREL32 0x000D
#تعریف_کرو IMAGE_REL_M32R_TOKEN 0x000E

#تعریف_کرو EXT_IMM64(قدر_3,پتہ_2,سائز_3,InstPos,ValPos) قدر_3 |= (((ULONGLONG)((*(پتہ_2) >> InstPos) & (((ULONGLONG)1 << سائز_3) - 1))) << ValPos)
#تعریف_کرو INS_IMM64(قدر_3,پتہ_2,سائز_3,InstPos,ValPos) *(PDWORD)پتہ_2 = (*(PDWORD)پتہ_2 & ~(((1 << سائز_3) - 1) << InstPos)) | ((DWORD)((((ULONGLONG)قدر_3 >> ValPos) & (((ULONGLONG)1 << سائز_3) - 1))) << InstPos)

#تعریف_کرو EMARCH_ENC_I17_IMM7_B_INST_لفظ_X 3
#تعریف_کرو EMARCH_ENC_I17_IMM7_B_سائز_X 7
#تعریف_کرو EMARCH_ENC_I17_IMM7_B_INST_لفظ_POS_X 4
#تعریف_کرو EMARCH_ENC_I17_IMM7B_VAL_POS_X 0

#تعریف_کرو EMARCH_ENC_I17_IMM9_D_INST_لفظ_X 3
#تعریف_کرو EMARCH_ENC_I17_IMM9_D_سائز_X 9
#تعریف_کرو EMARCH_ENC_I17_IMM9_D_INST_لفظ_POS_X 18
#تعریف_کرو EMARCH_ENC_I17_IMM9D_VAL_POS_X 7

#تعریف_کرو EMARCH_ENC_I17_IMM5_C_INST_لفظ_X 3
#تعریف_کرو EMARCH_ENC_I17_IMM5_C_سائز_X 5
#تعریف_کرو EMARCH_ENC_I17_IMM5_C_INST_لفظ_POS_X 13
#تعریف_کرو EMARCH_ENC_I17_IMM5C_VAL_POS_X 16

#تعریف_کرو EMARCH_ENC_I17_IC_INST_لفظ_X 3
#تعریف_کرو EMARCH_ENC_I17_IC_سائز_X 1
#تعریف_کرو EMARCH_ENC_I17_IC_INST_لفظ_POS_X 12
#تعریف_کرو EMARCH_ENC_I17_IC_VAL_POS_X 21

#تعریف_کرو EMARCH_ENC_I17_IMM41a_INST_لفظ_X 1
#تعریف_کرو EMARCH_ENC_I17_IMM41a_سائز_X 10
#تعریف_کرو EMARCH_ENC_I17_IMM41a_INST_لفظ_POS_X 14
#تعریف_کرو EMARCH_ENC_I17_IMM41a_VAL_POS_X 22

#تعریف_کرو EMARCH_ENC_I17_IMM41b_INST_لفظ_X 1
#تعریف_کرو EMARCH_ENC_I17_IMM41b_سائز_X 8
#تعریف_کرو EMARCH_ENC_I17_IMM41b_INST_لفظ_POS_X 24
#تعریف_کرو EMARCH_ENC_I17_IMM41b_VAL_POS_X 32

#تعریف_کرو EMARCH_ENC_I17_IMM41c_INST_لفظ_X 2
#تعریف_کرو EMARCH_ENC_I17_IMM41c_سائز_X 23
#تعریف_کرو EMARCH_ENC_I17_IMM41c_INST_لفظ_POS_X 0
#تعریف_کرو EMARCH_ENC_I17_IMM41c_VAL_POS_X 40

#تعریف_کرو EMARCH_ENC_I17_SIGN_INST_لفظ_X 3
#تعریف_کرو EMARCH_ENC_I17_SIGN_سائز_X 1
#تعریف_کرو EMARCH_ENC_I17_SIGN_INST_لفظ_POS_X 27
#تعریف_کرو EMARCH_ENC_I17_SIGN_VAL_POS_X 63

#تعریف_کرو X3_OPCODE_INST_لفظ_X 3
#تعریف_کرو X3_OPCODE_سائز_X 4
#تعریف_کرو X3_OPCODE_INST_لفظ_POS_X 28
#تعریف_کرو X3_OPCODE_SIGN_VAL_POS_X 0

#تعریف_کرو X3_I_INST_لفظ_X 3
#تعریف_کرو X3_I_سائز_X 1
#تعریف_کرو X3_I_INST_لفظ_POS_X 27
#تعریف_کرو X3_I_SIGN_VAL_POS_X 59

#تعریف_کرو X3_D_WH_INST_لفظ_X 3
#تعریف_کرو X3_D_WH_سائز_X 3
#تعریف_کرو X3_D_WH_INST_لفظ_POS_X 24
#تعریف_کرو X3_D_WH_SIGN_VAL_POS_X 0

#تعریف_کرو X3_IMM20_INST_لفظ_X 3
#تعریف_کرو X3_IMM20_سائز_X 20
#تعریف_کرو X3_IMM20_INST_لفظ_POS_X 4
#تعریف_کرو X3_IMM20_SIGN_VAL_POS_X 0

#تعریف_کرو X3_IMM39_1_INST_لفظ_X 2
#تعریف_کرو X3_IMM39_1_سائز_X 23
#تعریف_کرو X3_IMM39_1_INST_لفظ_POS_X 0
#تعریف_کرو X3_IMM39_1_SIGN_VAL_POS_X 36

#تعریف_کرو X3_IMM39_2_INST_لفظ_X 1
#تعریف_کرو X3_IMM39_2_سائز_X 16
#تعریف_کرو X3_IMM39_2_INST_لفظ_POS_X 16
#تعریف_کرو X3_IMM39_2_SIGN_VAL_POS_X 20

#تعریف_کرو X3_P_INST_لفظ_X 3
#تعریف_کرو X3_P_سائز_X 4
#تعریف_کرو X3_P_INST_لفظ_POS_X 0
#تعریف_کرو X3_P_SIGN_VAL_POS_X 0

#تعریف_کرو X3_TMPLT_INST_لفظ_X 0
#تعریف_کرو X3_TMPLT_سائز_X 4
#تعریف_کرو X3_TMPLT_INST_لفظ_POS_X 0
#تعریف_کرو X3_TMPLT_SIGN_VAL_POS_X 0

#تعریف_کرو X3_BTYPE_QP_INST_لفظ_X 2
#تعریف_کرو X3_BTYPE_QP_سائز_X 9
#تعریف_کرو X3_BTYPE_QP_INST_لفظ_POS_X 23
#تعریف_کرو X3_BTYPE_QP_INST_VAL_POS_X 0

#تعریف_کرو X3_خالی_خانے_INST_لفظ_X 1
#تعریف_کرو X3_خالی_خانے_سائز_X 2
#تعریف_کرو X3_خالی_خانے_INST_لفظ_POS_X 14
#تعریف_کرو X3_خالی_خانے_INST_VAL_POS_X 0

    قسمتعریف ساخت _IMAGE_LINENUMBER {
      اتحاد {
	DWORD علامت_جدول_اشاریہ;
	DWORD Virtual_پتہ;
      } Type;
      لفظ_3 Linenumber;
    } IMAGE_LINENUMBER;
    قسمتعریف IMAGE_LINENUMBER UNALIGNED *PIMAGE_LINENUMBER;

#تعریف_کرو IMAGE_SIZEOF_LINENUMBER 6

#شامل "poppack.h"

    قسمتعریف ساخت IMAGE_بنیاد_RELOCATION {
      DWORD Virtual_پتہ;
      DWORD سائز_کا_بلاک;

    } IMAGE_بنیاد_RELOCATION_2;
    قسمتعریف IMAGE_بنیاد_RELOCATION_2 UNALIGNED *PIMAGE_بنیاد_RELOCATION;

#تعریف_کرو IMAGE_SIZEOF_بنیاد_RELOCATION 8

#تعریف_کرو IMAGE_REL_BASED_ABSOLUTE 0
#تعریف_کرو IMAGE_REL_BASED_بلند 1
#تعریف_کرو IMAGE_REL_BASED_کم 2
#تعریف_کرو IMAGE_REL_BASED_HIGHLOW 3
#تعریف_کرو IMAGE_REL_BASED_HIGHADJ 4
#تعریف_کرو IMAGE_REL_BASED_MIPS_JMPADDR 5
#تعریف_کرو IMAGE_REL_BASED_MIPS_JMPADDR16 9
#تعریف_کرو IMAGE_REL_BASED_IA64_IMM64 9
#تعریف_کرو IMAGE_REL_BASED_DIR64 10

#تعریف_کرو IMAGE_ARCHIVE_آغاز_سائز 8
#تعریف_کرو IMAGE_ARCHIVE_آغاز "!<arch>\n"
#تعریف_کرو IMAGE_ARCHIVE_انتہا "`\n"
#تعریف_کرو IMAGE_ARCHIVE_PAD "\n"
#تعریف_کرو IMAGE_ARCHIVE_LINKER_MEMBER "/               "
#تعریف_کرو IMAGE_ARCHIVE_LONGNAMES_MEMBER "//              "

    قسمتعریف ساخت IMAGE_ARCHIVE_MEMBER_سرخی {
      BYTE Name[16];
      BYTE Date[12];
      BYTE UserID[6];
      BYTE گروہ_ID[6];
      BYTE منوال_4[8];
      BYTE سائز_3[10];
      BYTE انتہا_سرخی[2];
    } IMAGE_ARCHIVE_MEMBER_سرخی_2,*PIMAGE_ARCHIVE_MEMBER_سرخی;

#تعریف_کرو IMAGE_SIZEOF_ARCHIVE_MEMBER_HDR 60

    قسمتعریف ساخت _IMAGE_EXPORT_DIRECTORY {
      DWORD Characteristics;
      DWORD وقت_Date_Stamp;
      لفظ_3 Major_نسخہ;
      لفظ_3 Minor_نسخہ;
      DWORD Name;
      DWORD بنیاد_2;
      DWORD نمبر_کا_Functions;
      DWORD نمبر_کا_نام;
      DWORD پتہ_کا_Functions;
      DWORD پتہ_کا_نام;
      DWORD پتہ_کا_Name_Ordinals;
    } IMAGE_EXPORT_DIRECTORY,*PIMAGE_EXPORT_DIRECTORY;

    قسمتعریف ساخت _IMAGE_IMPORT_BY_NAME {
      لفظ_3 Hint;
      BYTE Name[1];
    } IMAGE_IMPORT_BY_NAME,*PIMAGE_IMPORT_BY_NAME;

#شامل "pshpack8.h"

    قسمتعریف ساخت _IMAGE_THUNK_DATA64 {
      اتحاد {
	ULONGLONG ForwarderString;
	ULONGLONG Function;
	ULONGLONG Ordinal;
	ULONGLONG پتہ_کا_ڈیٹا;
      } u1;
    } IMAGE_THUNK_DATA64;
    قسمتعریف IMAGE_THUNK_DATA64 *PIMAGE_THUNK_DATA64;

#شامل "poppack.h"

    قسمتعریف ساخت _IMAGE_THUNK_DATA32 {
      اتحاد {
	DWORD ForwarderString;
	DWORD Function;
	DWORD Ordinal;
	DWORD پتہ_کا_ڈیٹا;
      } u1;
    } IMAGE_THUNK_DATA32;
    قسمتعریف IMAGE_THUNK_DATA32 *PIMAGE_THUNK_DATA32;

#تعریف_کرو IMAGE_ORDINAL_FLAG64 0x8000000000000000ull
#تعریف_کرو IMAGE_ORDINAL_FLAG32 0x80000000
#تعریف_کرو IMAGE_ORDINAL64(Ordinal) (Ordinal & 0xffffull)
#تعریف_کرو IMAGE_ORDINAL32(Ordinal) (Ordinal & 0xffff)
#تعریف_کرو IMAGE_SNAP_BY_ORDINAL64(Ordinal) ((Ordinal & IMAGE_ORDINAL_FLAG64)!=0)
#تعریف_کرو IMAGE_SNAP_BY_ORDINAL32(Ordinal) ((Ordinal & IMAGE_ORDINAL_FLAG32)!=0)

    قسمتعریف VOID
      (NTAPI *PIMAGE_TLS_CALLBACK)(PVOID DllHandle,DWORD Reason,PVOID Reserved);

    قسمتعریف ساخت _IMAGE_TLS_DIRECTORY64 {
      ULONGLONG آغاز_پتہ_کا_Raw_ڈیٹا;
      ULONGLONG انتہا_پتہ_کا_Raw_ڈیٹا;
      ULONGLONG پتہ_کا_اشاریہ;
      ULONGLONG پتہ_کا_Call_Backs;
      DWORD سائز_کا_Zero_Fill;
      DWORD Characteristics;
    } IMAGE_TLS_DIRECTORY64;
    قسمتعریف IMAGE_TLS_DIRECTORY64 *PIMAGE_TLS_DIRECTORY64;

    قسمتعریف ساخت _IMAGE_TLS_DIRECTORY32 {
      DWORD آغاز_پتہ_کا_Raw_ڈیٹا;
      DWORD انتہا_پتہ_کا_Raw_ڈیٹا;
      DWORD پتہ_کا_اشاریہ;
      DWORD پتہ_کا_Call_Backs;
      DWORD سائز_کا_Zero_Fill;
      DWORD Characteristics;
    } IMAGE_TLS_DIRECTORY32;
    قسمتعریف IMAGE_TLS_DIRECTORY32 *PIMAGE_TLS_DIRECTORY32;

#اگر_تعریف_شدہ _WIN64
#تعریف_کرو IMAGE_ORDINAL_FLAG IMAGE_ORDINAL_FLAG64
#تعریف_کرو IMAGE_ORDINAL(Ordinal) IMAGE_ORDINAL64(Ordinal)
    قسمتعریف IMAGE_THUNK_DATA64 IMAGE_THUNK_ڈیٹا;
    قسمتعریف PIMAGE_THUNK_DATA64 PIMAGE_THUNK_ڈیٹا;
#تعریف_کرو IMAGE_SNAP_BY_ORDINAL(Ordinal) IMAGE_SNAP_BY_ORDINAL64(Ordinal)
    قسمتعریف IMAGE_TLS_DIRECTORY64 IMAGE_TLS_DIRECTORY;
    قسمتعریف PIMAGE_TLS_DIRECTORY64 PIMAGE_TLS_DIRECTORY;
#ورنہ
#تعریف_کرو IMAGE_ORDINAL_FLAG IMAGE_ORDINAL_FLAG32
#تعریف_کرو IMAGE_ORDINAL(Ordinal) IMAGE_ORDINAL32(Ordinal)
    قسمتعریف IMAGE_THUNK_DATA32 IMAGE_THUNK_ڈیٹا;
    قسمتعریف PIMAGE_THUNK_DATA32 PIMAGE_THUNK_ڈیٹا;
#تعریف_کرو IMAGE_SNAP_BY_ORDINAL(Ordinal) IMAGE_SNAP_BY_ORDINAL32(Ordinal)
    قسمتعریف IMAGE_TLS_DIRECTORY32 IMAGE_TLS_DIRECTORY;
    قسمتعریف PIMAGE_TLS_DIRECTORY32 PIMAGE_TLS_DIRECTORY;
#اگر_ختم

    قسمتعریف ساخت _IMAGE_IMPORT_DESCRIPTOR {
      اتحاد {
	DWORD Characteristics;
	DWORD Original_پہلا_Thunk;
      };
      DWORD وقت_Date_Stamp;

      DWORD ForwarderChain;
      DWORD Name;
      DWORD پہلا_Thunk;
    } IMAGE_IMPORT_DESCRIPTOR;
    قسمتعریف IMAGE_IMPORT_DESCRIPTOR UNALIGNED *PIMAGE_IMPORT_DESCRIPTOR;

    قسمتعریف ساخت _IMAGE_BOUND_IMPORT_DESCRIPTOR {
      DWORD وقت_Date_Stamp;
      لفظ_3 انحراف_Module_Name;
      لفظ_3 نمبر_کا_Module_Forwarder_Refs;
    } IMAGE_BOUND_IMPORT_DESCRIPTOR,*PIMAGE_BOUND_IMPORT_DESCRIPTOR;

    قسمتعریف ساخت _IMAGE_BOUND_FORWARDER_REF {
      DWORD وقت_Date_Stamp;
      لفظ_3 انحراف_Module_Name;
      لفظ_3 Reserved;
    } IMAGE_BOUND_FORWARDER_REF,*PIMAGE_BOUND_FORWARDER_REF;

    قسمتعریف ساخت _IMAGE_RESOURCE_DIRECTORY {
      DWORD Characteristics;
      DWORD وقت_Date_Stamp;
      لفظ_3 Major_نسخہ;
      لفظ_3 Minor_نسخہ;
      لفظ_3 نمبر_کا_Named_Entries;
      لفظ_3 نمبر_کا_Id_Entries;
    } IMAGE_RESOURCE_DIRECTORY,*PIMAGE_RESOURCE_DIRECTORY;

#تعریف_کرو IMAGE_RESOURCE_NAME_IS_STRING 0x80000000
#تعریف_کرو IMAGE_RESOURCE_ڈیٹا_IS_DIRECTORY 0x80000000

    قسمتعریف ساخت IMAGE_RESOURCE_DIRECTORY_اندراج {
      اتحاد {
	ساخت {
	  DWORD Name_انحراف:31;
	  DWORD NameIsString:1;
	};
	DWORD Name;
	لفظ_3 Id;
      };
      اتحاد {
	DWORD انحراف_مقصد_ڈیٹا;
	ساخت {
	  DWORD انحراف_مقصد_Directory:31;
	  DWORD ڈیٹا_Is_Directory:1;
	};
      };
    } IMAGE_RESOURCE_DIRECTORY_اندراج_2,*PIMAGE_RESOURCE_DIRECTORY_اندراج;

    قسمتعریف ساخت _IMAGE_RESOURCE_DIRECTORY_STRING {
      لفظ_3 لمبائی_2;
      CHAR NameString[1];
    } IMAGE_RESOURCE_DIRECTORY_STRING,*PIMAGE_RESOURCE_DIRECTORY_STRING;

    قسمتعریف ساخت _IMAGE_RESOURCE_DIR_STRING_U {
      لفظ_3 لمبائی_2;
      WCHAR NameString[1];
    } IMAGE_RESOURCE_DIR_STRING_U,*PIMAGE_RESOURCE_DIR_STRING_U;

    قسمتعریف ساخت IMAGE_RESOURCE_ڈیٹا_اندراج {
      DWORD انحراف_مقصد_ڈیٹا;
      DWORD سائز_3;
      DWORD رمز_صفحہ;
      DWORD Reserved;
    } IMAGE_RESOURCE_ڈیٹا_اندراج_2,*PIMAGE_RESOURCE_ڈیٹا_اندراج;

    قسمتعریف ساخت {
      DWORD سائز_3;
      DWORD وقت_Date_Stamp;
      لفظ_3 Major_نسخہ;
      لفظ_3 Minor_نسخہ;
      DWORD GlobalFlagsClear;
      DWORD Global_Flags_سیٹ;
      DWORD CriticalSectionDefaultTimeout;
      DWORD De_Commit_Free_بلاک_حد;
      DWORD De_Commit_کل_Free_حد;
      DWORD تالا_سابقہ_جدول;
      DWORD زیادہ_سے_زیادہ_تخصیص_سائز;
      DWORD Virtual_حافظہ_حد;
      DWORD Process_ڈھیر_Flags;
      DWORD Process_Affinity_نقاب;
      لفظ_3 CSDVersion;
      لفظ_3 Reserved1;
      DWORD EditList;
      DWORD SecurityCookie;
      DWORD SEHandler_جدول;
      DWORD SEHandler_گنتی;
    } IMAGE_بھرو_CONFIG_DIRECTORY32,*PIMAGE_بھرو_CONFIG_DIRECTORY32;

    قسمتعریف ساخت {
      DWORD سائز_3;
      DWORD وقت_Date_Stamp;
      لفظ_3 Major_نسخہ;
      لفظ_3 Minor_نسخہ;
      DWORD GlobalFlagsClear;
      DWORD Global_Flags_سیٹ;
      DWORD CriticalSectionDefaultTimeout;
      ULONGLONG De_Commit_Free_بلاک_حد;
      ULONGLONG De_Commit_کل_Free_حد;
      ULONGLONG تالا_سابقہ_جدول;
      ULONGLONG زیادہ_سے_زیادہ_تخصیص_سائز;
      ULONGLONG Virtual_حافظہ_حد;
      ULONGLONG Process_Affinity_نقاب;
      DWORD Process_ڈھیر_Flags;
      لفظ_3 CSDVersion;
      لفظ_3 Reserved1;
      ULONGLONG EditList;
      ULONGLONG SecurityCookie;
      ULONGLONG SEHandler_جدول;
      ULONGLONG SEHandler_گنتی;
    } IMAGE_بھرو_CONFIG_DIRECTORY64,*PIMAGE_بھرو_CONFIG_DIRECTORY64;

#اگر_تعریف_شدہ _WIN64
    قسمتعریف IMAGE_بھرو_CONFIG_DIRECTORY64 IMAGE_بھرو_CONFIG_DIRECTORY;
    قسمتعریف PIMAGE_بھرو_CONFIG_DIRECTORY64 PIMAGE_بھرو_CONFIG_DIRECTORY;
#ورنہ
    قسمتعریف IMAGE_بھرو_CONFIG_DIRECTORY32 IMAGE_بھرو_CONFIG_DIRECTORY;
    قسمتعریف PIMAGE_بھرو_CONFIG_DIRECTORY32 PIMAGE_بھرو_CONFIG_DIRECTORY;
#اگر_ختم

    قسمتعریف ساخت IMAGE_CE_RUNTIME_FUNCTION_اندراج {
      DWORD Func_آغاز;
      DWORD PrologLen : 8;
      DWORD FuncLen : 22;
      DWORD Thirty_Two_ثنائی_ہندسہ : 1;
      DWORD ExceptionFlag : 1;
    } IMAGE_CE_RUNTIME_FUNCTION_اندراج_2,*PIMAGE_CE_RUNTIME_FUNCTION_اندراج;

    قسمتعریف ساخت IMAGE_ALPHA64_RUNTIME_FUNCTION_اندراج {
      ULONGLONG Begin_پتہ;
      ULONGLONG انتہا_پتہ;
      ULONGLONG ExceptionHandler;
      ULONGLONG Handler_ڈیٹا;
      ULONGLONG Prolog_انتہا_پتہ;
    } IMAGE_ALPHA64_RUNTIME_FUNCTION_اندراج_2,*PIMAGE_ALPHA64_RUNTIME_FUNCTION_اندراج;

    قسمتعریف ساخت IMAGE_ALPHA_RUNTIME_FUNCTION_اندراج {
      DWORD Begin_پتہ;
      DWORD انتہا_پتہ;
      DWORD ExceptionHandler;
      DWORD Handler_ڈیٹا;
      DWORD Prolog_انتہا_پتہ;
    } IMAGE_ALPHA_RUNTIME_FUNCTION_اندراج_2,*PIMAGE_ALPHA_RUNTIME_FUNCTION_اندراج;

    قسمتعریف ساخت IMAGE_RUNTIME_FUNCTION_اندراج {
      DWORD Begin_پتہ;
      DWORD انتہا_پتہ;
      DWORD Unwind_Info_پتہ;
    } IMAGE_RUNTIME_FUNCTION_اندراج,*PIMAGE_RUNTIME_FUNCTION_اندراج;

    قسمتعریف IMAGE_RUNTIME_FUNCTION_اندراج IMAGE_IA64_RUNTIME_FUNCTION_اندراج;
    قسمتعریف PIMAGE_RUNTIME_FUNCTION_اندراج PIMAGE_IA64_RUNTIME_FUNCTION_اندراج;

    قسمتعریف IMAGE_RUNTIME_FUNCTION_اندراج IMAGE_RUNTIME_FUNCTION_اندراج_2;
    قسمتعریف PIMAGE_RUNTIME_FUNCTION_اندراج PIMAGE_RUNTIME_FUNCTION_اندراج_2;

    قسمتعریف ساخت _IMAGE_DEBUG_DIRECTORY {
      DWORD Characteristics;
      DWORD وقت_Date_Stamp;
      لفظ_3 Major_نسخہ;
      لفظ_3 Minor_نسخہ;
      DWORD Type;
      DWORD سائز_کا_ڈیٹا;
      DWORD پتہ_کا_Raw_ڈیٹا;
      DWORD اشارہ_گر_مقصد_Raw_ڈیٹا;
    } IMAGE_DEBUG_DIRECTORY,*PIMAGE_DEBUG_DIRECTORY;

#تعریف_کرو IMAGE_DEBUG_TYPE_UNKNOWN 0
#تعریف_کرو IMAGE_DEBUG_TYPE_COFF 1
#تعریف_کرو IMAGE_DEBUG_TYPE_CODEVIEW 2
#تعریف_کرو IMAGE_DEBUG_TYPE_FPO 3
#تعریف_کرو IMAGE_DEBUG_TYPE_MISC 4
#تعریف_کرو IMAGE_DEBUG_TYPE_EXCEPTION 5
#تعریف_کرو IMAGE_DEBUG_TYPE_FIXUP 6
#تعریف_کرو IMAGE_DEBUG_TYPE_OMAP_مقصد_SRC 7
#تعریف_کرو IMAGE_DEBUG_TYPE_OMAP_FROM_SRC 8
#تعریف_کرو IMAGE_DEBUG_TYPE_BORLAND 9
#تعریف_کرو IMAGE_DEBUG_TYPE_RESERVED10 10
#تعریف_کرو IMAGE_DEBUG_TYPE_CLSID 11

    قسمتعریف ساخت IMAGE_COFF_SYMBOLS_سرخی {
      DWORD نمبر_کا_Symbols;
      DWORD Lva_مقصد_پہلا_علامت;
      DWORD نمبر_کا_Linenumbers;
      DWORD Lva_مقصد_پہلا_Linenumber;
      DWORD Rva_مقصد_پہلا_Byte_کا_رمز;
      DWORD Rva_مقصد_آخری_Byte_کا_رمز;
      DWORD Rva_مقصد_پہلا_Byte_کا_ڈیٹا;
      DWORD Rva_مقصد_آخری_Byte_کا_ڈیٹا;
    } IMAGE_COFF_SYMBOLS_سرخی_2,*PIMAGE_COFF_SYMBOLS_سرخی;

#تعریف_کرو چوکھٹا_FPO 0
#تعریف_کرو چوکھٹا_TRAP 1
#تعریف_کرو چوکھٹا_TSS 2
#تعریف_کرو چوکھٹا_NONFPO 3

    قسمتعریف ساخت FPO_ڈیٹا {
      DWORD ul_Off_آغاز;
      DWORD cb_Proc_سائز;
      DWORD cdwLocals;
      لفظ_3 cdwParams;
      لفظ_3 cbProlog : 8;
      لفظ_3 cbRegs : 3;
      لفظ_3 fHasSEH : 1;
      لفظ_3 fUseBP : 1;
      لفظ_3 reserved : 1;
      لفظ_3 cb_چوکھٹا : 2;
    } FPO_ڈیٹا_2,*PFPO_ڈیٹا;
#تعریف_کرو SIZEOF_RFPO_ڈیٹا 16

#تعریف_کرو IMAGE_DEBUG_MISC_EXENAME 1

    قسمتعریف ساخت _IMAGE_DEBUG_MISC {
      DWORD ڈیٹا_Type;
      DWORD لمبائی_2;
      BOOLEAN Unicode;
      BYTE Reserved[3];
      BYTE ڈیٹا_3[1];
    } IMAGE_DEBUG_MISC,*PIMAGE_DEBUG_MISC;

    قسمتعریف ساخت IMAGE_FUNCTION_اندراج {
      DWORD Starting_پتہ;
      DWORD Ending_پتہ;
      DWORD انتہا_کا_Prologue;
    } IMAGE_FUNCTION_اندراج_2,*PIMAGE_FUNCTION_اندراج;

    قسمتعریف ساخت _IMAGE_FUNCTION_ENTRY64 {
      ULONGLONG Starting_پتہ;
      ULONGLONG Ending_پتہ;
      اتحاد {
	ULONGLONG انتہا_کا_Prologue;
	ULONGLONG Unwind_Info_پتہ;
      };
    } IMAGE_FUNCTION_ENTRY64,*PIMAGE_FUNCTION_ENTRY64;

    قسمتعریف ساخت IMAGE_SEPARATE_DEBUG_سرخی {
      لفظ_3 Signature;
      لفظ_3 Flags;
      لفظ_3 Machine;
      لفظ_3 Characteristics;
      DWORD وقت_Date_Stamp;
      DWORD Check_مجموع;
      DWORD Image_بنیاد;
      DWORD سائز_کا_Image;
      DWORD نمبر_کا_Sections;
      DWORD Exported_نام_سائز;
      DWORD Debug_Directory_سائز;
      DWORD SectionAlignment;
      DWORD Reserved[2];
    } IMAGE_SEPARATE_DEBUG_سرخی_2,*PIMAGE_SEPARATE_DEBUG_سرخی;

    قسمتعریف ساخت _NON_PAGED_DEBUG_INFO {
      لفظ_3 Signature;
      لفظ_3 Flags;
      DWORD سائز_3;
      لفظ_3 Machine;
      لفظ_3 Characteristics;
      DWORD وقت_Date_Stamp;
      DWORD Check_مجموع;
      DWORD سائز_کا_Image;
      ULONGLONG Image_بنیاد;

    } NON_PAGED_DEBUG_INFO,*PNON_PAGED_DEBUG_INFO;

#تعریف_کرو IMAGE_SEPARATE_DEBUG_SIGNATURE 0x4944
#تعریف_کرو NON_PAGED_DEBUG_SIGNATURE 0x494E

#تعریف_کرو IMAGE_SEPARATE_DEBUG_FLAGS_نقاب 0x8000
#تعریف_کرو IMAGE_SEPARATE_DEBUG_MISMATCH 0x8000

    قسمتعریف ساخت Image_Architecture_سرخی {
      غیرعلامتی صحیح Amask_قدر: 1;
      صحیح Adummy1 :7;
      غیرعلامتی صحیح Amask_سرکاؤ: 8;
      صحیح Adummy2 :16;
      DWORD پہلا_اندراج_RVA;
    } IMAGE_ARCHITECTURE_سرخی,*PIMAGE_ARCHITECTURE_سرخی;

    قسمتعریف ساخت Image_Architecture_اندراج {
      DWORD FixupInstRVA;
      DWORD NewInst;
    } IMAGE_ARCHITECTURE_اندراج,*PIMAGE_ARCHITECTURE_اندراج;

#شامل "poppack.h"

#تعریف_کرو IMPORT_OBJECT_HDR_SIG2 0xffff

    قسمتعریف ساخت IMPORT_OBJECT_سرخی {
      لفظ_3 Sig1;
      لفظ_3 Sig2;
      لفظ_3 نسخہ_2;
      لفظ_3 Machine;
      DWORD وقت_Date_Stamp;
      DWORD سائز_کا_ڈیٹا;
      اتحاد {
	لفظ_3 Ordinal;
	لفظ_3 Hint;
      };
      لفظ_3 Type : 2;
      لفظ_3 NameType : 3;
      لفظ_3 Reserved : 11;
    } IMPORT_OBJECT_سرخی;

    قسمتعریف شمار IMPORT_OBJECT_TYPE {
      IMPORT_OBJECT_رمز = 0,IMPORT_OBJECT_ڈیٹا = 1,IMPORT_OBJECT_CONST = 2
    } IMPORT_OBJECT_TYPE;

    قسمتعریف شمار IMPORT_OBJECT_NAME_TYPE {
      IMPORT_OBJECT_ORDINAL = 0,IMPORT_OBJECT_NAME = 1,IMPORT_OBJECT_NAME_NO_سابقہ = 2,IMPORT_OBJECT_NAME_UNDECORATE = 3
    } IMPORT_OBJECT_NAME_TYPE;

#اگر_غیر_تعریف_شدہ __IMAGE_COR20_HEADER_DEFINED__
#تعریف_کرو __IMAGE_COR20_HEADER_DEFINED__
    قسمتعریف شمار Replaces_Cor_Hdr_Numeric_متعین_کرتا {
      COMIMAGE_FLAGS_ILONLY =0x00000001,COMIMAGE_FLAGS_32BITREQUIRED =0x00000002,COMIMAGE_FLAGS_IL_LIBRARY =0x00000004,
      COMIMAGE_FLAGS_STRONGNAMESIGNED =0x00000008,COMIMAGE_FLAGS_TRACKDEBUGDATA =0x00010000,COR_نسخہ_MAJOR_V2 =2,
      COR_نسخہ_MAJOR =COR_نسخہ_MAJOR_V2,COR_نسخہ_MINOR =0,COR_DELETED_NAME_لمبائی =8,COR_VTABLEGAP_NAME_لمبائی =8,
      NATIVE_TYPE_MAX_CB =1,COR_ILMETHOD_SECT_SMALL_MAX_DATASIZE=0xFF,IMAGE_COR_MIH_METHODRVA =0x01,IMAGE_COR_MIH_EHRVA =0x02,
      IMAGE_COR_MIH_BASICBLOCK =0x08,COR_VTABLE_32_ثنائی_ہندسہ =0x01,COR_VTABLE_64_ثنائی_ہندسہ =0x02,COR_VTABLE_FROM_UNMANAGED =0x04,
      COR_VTABLE_CALL_MOST_DERIVED =0x10,IMAGE_COR_EATJ_THUNK_سائز =32,MAX_CLASS_NAME =1024,MAX_PACKAGE_NAME =1024
    } Replaces_Cor_Hdr_Numeric_متعین_کرتا;

    قسمتعریف ساخت IMAGE_COR20_سرخی {
      DWORD cb;
      لفظ_3 Major_Runtime_نسخہ;
      لفظ_3 Minor_Runtime_نسخہ;
      IMAGE_ڈیٹا_DIRECTORY_2 Meta_ڈیٹا;
      DWORD Flags;
      DWORD اندراج_نقطہ_Token;
      IMAGE_ڈیٹا_DIRECTORY_2 Resources;
      IMAGE_ڈیٹا_DIRECTORY_2 StrongNameSignature;
      IMAGE_ڈیٹا_DIRECTORY_2 رمز_Manager_جدول;
      IMAGE_ڈیٹا_DIRECTORY_2 VTableFixups;
      IMAGE_ڈیٹا_DIRECTORY_2 Export_پتہ_جدول_Jumps;
      IMAGE_ڈیٹا_DIRECTORY_2 Managed_Native_سرخی;
    } IMAGE_COR20_سرخی,*PIMAGE_COR20_سرخی;
#اگر_ختم

#اگر defined (__x86_64)
    NTSYSAPI PRUNTIME_FUNCTION NTAPI Rtl_Lookup_Function_اندراج (DWORD64 ControlPc, PDWORD64 Image_بنیاد, PUNWIND_HISTORY_جدول History_جدول);
    NTSYSAPI VOID NTAPI RtlUnwindEx (PVOID ہدف_چوکھٹا, PVOID ہدف_Ip, PEXCEPTION_ریکارڈ Exception_ریکارڈ, PVOID Return_قدر_2, PCONTEXT Context_ریکارڈ, PUNWIND_HISTORY_جدول History_جدول);
#اگر_ختم

#شامل <string.h>

#اگر_غیر_تعریف_شدہ SLIST_سرخی
#تعریف_کرو SLIST_سرخی

#اگر_تعریف_شدہ _WIN64
    قسمتعریف ساخت SLIST_اندراج *PSLIST_اندراج;
    قسمتعریف ساخت DECLSPEC_ALIGN(16) SLIST_اندراج {
      PSLIST_اندراج اگلا_2;
    } SLIST_اندراج_2;
#ورنہ

#تعریف_کرو SLIST_اندراج_2 SINGLE_LIST_اندراج_2
#تعریف_کرو SLIST_اندراج SINGLE_LIST_اندراج
#تعریف_کرو PSLIST_اندراج PSINGLE_LIST_اندراج
#اگر_ختم

#اگر defined(_WIN64)

    قسمتعریف ساخت DECLSPEC_ALIGN(16) SLIST_سرخی_2 {
      ULONGLONG Alignment;
      ULONGLONG Region;
    } SLIST_سرخی_3;

    قسمتعریف ساخت SLIST_سرخی_2 *PSLIST_سرخی;
#ورنہ

    قسمتعریف اتحاد SLIST_سرخی_2 {
      ULONGLONG Alignment;
      ساخت {
	SLIST_اندراج_2 اگلا_2;
	لفظ_3 گہرائی;
	لفظ_3 Sequence;
      };
    } SLIST_سرخی_3,*PSLIST_سرخی;
#اگر_ختم
#اگر_ختم

    NTSYSAPI VOID NTAPI Rtl_Initialize_SList_سر(PSLIST_سرخی List_سر);
    NTSYSAPI PSLIST_اندراج NTAPI Rtl_پہلا_اندراج_SList(ثابت SLIST_سرخی_3 *List_سر);
    NTSYSAPI PSLIST_اندراج NTAPI Rtl_Interlocked_نکالو_اندراج_SList(PSLIST_سرخی List_سر);
    NTSYSAPI PSLIST_اندراج NTAPI Rtl_Interlocked_ڈالو_اندراج_SList(PSLIST_سرخی List_سر,PSLIST_اندراج List_اندراج);
    NTSYSAPI PSLIST_اندراج NTAPI RtlInterlockedFlushSList(PSLIST_سرخی List_سر);
    NTSYSAPI لفظ_3 NTAPI Rtl_Query_گہرائی_SList(PSLIST_سرخی List_سر);

#تعریف_کرو ڈھیر_NO_SERIALIZE 0x00000001
#تعریف_کرو ڈھیر_GROWABLE 0x00000002
#تعریف_کرو ڈھیر_GENERATE_EXCEPTIONS 0x00000004
#تعریف_کرو ڈھیر_ZERO_حافظہ 0x00000008
#تعریف_کرو ڈھیر_REALLOC_اندر_رکھو_ONLY 0x00000010
#تعریف_کرو ڈھیر_دم_CHECKING_ENABLED 0x00000020
#تعریف_کرو ڈھیر_FREE_CHECKING_ENABLED 0x00000040
#تعریف_کرو ڈھیر_DISABLE_COALESCE_ON_FREE 0x00000080
#تعریف_کرو ڈھیر_CREATE_ALIGN_16 0x00010000
#تعریف_کرو ڈھیر_CREATE_ENABLE_TRACING 0x00020000
#تعریف_کرو ڈھیر_CREATE_ENABLE_EXECUTE 0x00040000
#تعریف_کرو ڈھیر_زیادہ_سے_زیادہ_لیبل 0x0FFF
#تعریف_کرو ڈھیر_PSEUDO_لیبل_FLAG 0x8000
#تعریف_کرو ڈھیر_لیبل_سرکاؤ 18
#تعریف_کرو ڈھیر_MAKE_لیبل_FLAGS(b,o) ((DWORD)((b) + ((o) << 18)))

    NTSYSAPI VOID NTAPI RtlCaptureContext(PCONTEXT Context_ریکارڈ);

#تعریف_کرو IS_متن_UNICODE_ASCII16 0x0001
#تعریف_کرو IS_متن_UNICODE_الٹ_ASCII16 0x0010

#تعریف_کرو IS_متن_UNICODE_STATISTICS 0x0002
#تعریف_کرو IS_متن_UNICODE_الٹ_STATISTICS 0x0020

#تعریف_کرو IS_متن_UNICODE_CONTROLS 0x0004
#تعریف_کرو IS_متن_UNICODE_الٹ_CONTROLS 0x0040

#تعریف_کرو IS_متن_UNICODE_SIGNATURE 0x0008
#تعریف_کرو IS_متن_UNICODE_الٹ_SIGNATURE 0x0080

#تعریف_کرو IS_متن_UNICODE_ILLEGAL_CHARS 0x0100
#تعریف_کرو IS_متن_UNICODE_ODD_لمبائی 0x0200
#تعریف_کرو IS_متن_UNICODE_DBCS_LEADBYTE 0x0400
#تعریف_کرو IS_متن_UNICODE_NULL_بائٹیں 0x1000

#تعریف_کرو IS_متن_UNICODE_UNICODE_نقاب 0x000F
#تعریف_کرو IS_متن_UNICODE_الٹ_نقاب 0x00F0
#تعریف_کرو IS_متن_UNICODE_NOT_UNICODE_نقاب 0x0F00
#تعریف_کرو IS_متن_UNICODE_NOT_ASCII_نقاب 0xF000

#تعریف_کرو COMPRESSION_FORMAT_NONE (0x0000)
#تعریف_کرو COMPRESSION_FORMAT_DEFAULT (0x0001)
#تعریف_کرو COMPRESSION_FORMAT_LZNT1 (0x0002)
#تعریف_کرو COMPRESSION_ENGINE_STANDARD (0x0000)
#تعریف_کرو COMPRESSION_ENGINE_زیادہ_سے_زیادہ (0x0100)
#تعریف_کرو COMPRESSION_ENGINE_HIBER (0x0200)

#اگر _DBG_MEMCPY_INLINE_ && !defined(_MEMCPY_INLINE_) && !defined(_CRTBLD)
#تعریف_کرو _MEMCPY_INLINE_
    __CRT_INLINE PVOID __cdecl memcpy_inline(خالی *dst,ثابت خالی *src,سائز_t سائز) {
      اگر(((حرف *)dst > (حرف *)src) && ((حرف *)dst < ((حرف *)src + سائز))) {
	__debugbreak();
      }
      واپس حافظہ_نقل(dst,src,سائز);
    }
#تعریف_کرو حافظہ_نقل memcpy_inline
#اگر_ختم

    NTSYSAPI سائز_T NTAPI Rtl_Compare_حافظہ(ثابت VOID *Source1,ثابت VOID *Source2,سائز_T لمبائی_2);

#تعریف_کرو Rtl_Equal_حافظہ(Destination,ماخذ_2,لمبائی_2) (!memcmp((Destination),(ماخذ_2),(لمبائی_2)))
#تعریف_کرو Rtl_Move_حافظہ(Destination,ماخذ_2,لمبائی_2) memmove((Destination),(ماخذ_2),(لمبائی_2))
#تعریف_کرو Rtl_Copy_حافظہ(Destination,ماخذ_2,لمبائی_2) حافظہ_نقل((Destination),(ماخذ_2),(لمبائی_2))
#تعریف_کرو Rtl_Fill_حافظہ(Destination,لمبائی_2,Fill) memset((Destination),(Fill),(لمبائی_2))
#تعریف_کرو Rtl_Zero_حافظہ(Destination,لمبائی_2) memset((Destination),0,(لمبائی_2))

    __CRT_INLINE PVOID Rtl_Secure_Zero_حافظہ(PVOID ptr,سائز_T cnt) {
      متلون حرف *vptr =(متلون حرف *)ptr;
#اگر_تعریف_شدہ __x86_64
      __stosb((PBYTE)((DWORD64)vptr),0,cnt);
#ورنہ
      جب(cnt) {
	*vptr = 0;
	vptr++;
	cnt--;
      }
#اگر_ختم
      واپس ptr;
    }

    قسمتعریف ساخت پیغام_RESOURCE_اندراج {
      لفظ_3 لمبائی_2;
      لفظ_3 Flags;
      BYTE متن_4[1];
    } پیغام_RESOURCE_اندراج_2,*PMESSAGE_RESOURCE_اندراج;

#تعریف_کرو پیغام_RESOURCE_UNICODE 0x0001

    قسمتعریف ساخت پیغام_RESOURCE_بلاک {
      DWORD کم_Id;
      DWORD بلند_Id;
      DWORD انحراف_مقصد_Entries;
    } پیغام_RESOURCE_بلاک_2,*PMESSAGE_RESOURCE_بلاک;

    قسمتعریف ساخت پیغام_RESOURCE_ڈیٹا {
      DWORD نمبر_کا_بلاکیں;
      پیغام_RESOURCE_بلاک_2 بلاکیں_2[1];
    } پیغام_RESOURCE_ڈیٹا_2,*PMESSAGE_RESOURCE_ڈیٹا;

    قسمتعریف ساخت _OSVERSIONINFOA {
      DWORD dw_OSVersion_Info_سائز;
      DWORD dw_Major_نسخہ;
      DWORD dw_Minor_نسخہ;
      DWORD dw_Build_نمبر;
      DWORD dwPlatformId;
      CHAR szCSDVersion[128];
    } OSVERSIONINFOA,*POSVERSIONINFOA,*LPOSVERSIONINFOA;

    قسمتعریف ساخت _OSVERSIONINFOW {
      DWORD dw_OSVersion_Info_سائز;
      DWORD dw_Major_نسخہ;
      DWORD dw_Minor_نسخہ;
      DWORD dw_Build_نمبر;
      DWORD dwPlatformId;
      WCHAR szCSDVersion[128];
    } OSVERSIONINFOW,*POSVERSIONINFOW,*LPOSVERSIONINFOW,RTL_OSVERSIONINFOW,*PRTL_OSVERSIONINFOW;

#اگر_تعریف_شدہ UNICODE
    قسمتعریف OSVERSIONINFOW OSVERSIONINFO;
    قسمتعریف POSVERSIONINFOW POSVERSIONINFO;
    قسمتعریف LPOSVERSIONINFOW LPOSVERSIONINFO;
#ورنہ
    قسمتعریف OSVERSIONINFOA OSVERSIONINFO;
    قسمتعریف POSVERSIONINFOA POSVERSIONINFO;
    قسمتعریف LPOSVERSIONINFOA LPOSVERSIONINFO;
#اگر_ختم

    قسمتعریف ساخت _OSVERSIONINFOEXA {
      DWORD dw_OSVersion_Info_سائز;
      DWORD dw_Major_نسخہ;
      DWORD dw_Minor_نسخہ;
      DWORD dw_Build_نمبر;
      DWORD dwPlatformId;
      CHAR szCSDVersion[128];
      لفظ_3 wServicePackMajor;
      لفظ_3 wServicePackMinor;
      لفظ_3 w_Suite_نقاب;
      BYTE w_حاصل_ضرب_Type;
      BYTE wReserved;
    } OSVERSIONINFOEXA,*POSVERSIONINFOEXA,*LPOSVERSIONINFOEXA;

    قسمتعریف ساخت _OSVERSIONINFOEXW {
      DWORD dw_OSVersion_Info_سائز;
      DWORD dw_Major_نسخہ;
      DWORD dw_Minor_نسخہ;
      DWORD dw_Build_نمبر;
      DWORD dwPlatformId;
      WCHAR szCSDVersion[128];
      لفظ_3 wServicePackMajor;
      لفظ_3 wServicePackMinor;
      لفظ_3 w_Suite_نقاب;
      BYTE w_حاصل_ضرب_Type;
      BYTE wReserved;
    } OSVERSIONINFOEXW,*POSVERSIONINFOEXW,*LPOSVERSIONINFOEXW,RTL_OSVERSIONINFOEXW,*PRTL_OSVERSIONINFOEXW;
#اگر_تعریف_شدہ UNICODE
    قسمتعریف OSVERSIONINFOEXW OSVERSIONINFOEX;
    قسمتعریف POSVERSIONINFOEXW POSVERSIONINFOEX;
    قسمتعریف LPOSVERSIONINFOEXW LPOSVERSIONINFOEX;
#ورنہ
    قسمتعریف OSVERSIONINFOEXA OSVERSIONINFOEX;
    قسمتعریف POSVERSIONINFOEXA POSVERSIONINFOEX;
    قسمتعریف LPOSVERSIONINFOEXA LPOSVERSIONINFOEX;
#اگر_ختم

#تعریف_کرو VER_EQUAL 1
#تعریف_کرو VER_GREATER 2
#تعریف_کرو VER_GREATER_EQUAL 3
#تعریف_کرو VER_LESS 4
#تعریف_کرو VER_LESS_EQUAL 5
#تعریف_کرو VER_AND 6
#تعریف_کرو VER_OR 7

#تعریف_کرو VER_CONDITION_نقاب 7
#تعریف_کرو VER_عدد_بٹ_فی_CONDITION_نقاب 3

#تعریف_کرو VER_MINORVERSION 0x0000001
#تعریف_کرو VER_MAJORVERSION 0x0000002
#تعریف_کرو VER_BUILDNUMBER 0x0000004
#تعریف_کرو VER_PLATFORMID 0x0000008
#تعریف_کرو VER_SERVICEPACKMINOR 0x0000010
#تعریف_کرو VER_SERVICEPACKMAJOR 0x0000020
#تعریف_کرو VER_SUITENAME 0x0000040
#تعریف_کرو VER_حاصل_ضرب_TYPE 0x0000080

#تعریف_کرو VER_NT_WORKSTATION 0x0000001
#تعریف_کرو VER_NT_DOMAIN_CONTROLLER 0x0000002
#تعریف_کرو VER_NT_SERVER 0x0000003

#تعریف_کرو VER_PLATFORM_WIN32s 0
#تعریف_کرو VER_PLATFORM_WIN32_WINDOWS 1
#تعریف_کرو VER_PLATFORM_WIN32_NT 2

#تعریف_کرو VER_سیٹ_CONDITION(_m_,_t_,_c_) ((_m_)=Ver_سیٹ_Condition_نقاب((_m_),(_t_),(_c_)))

    NTSYSAPI ULONGLONG NTAPI Ver_سیٹ_Condition_نقاب(ULONGLONG Condition_نقاب,DWORD Type_نقاب,BYTE Condition);

    قسمتعریف ساخت _RTL_CRITICAL_SECTION_DEBUG {
      لفظ_3 Type;
      لفظ_3 Creator_عقب_Trace_اشاریہ;
      ساخت _RTL_CRITICAL_SECTION *CriticalSection;
      LIST_اندراج_2 ProcessLocksList;
      DWORD اندراج_گنتی;
      DWORD Contention_گنتی;
      DWORD فالتو_2[2];
    } RTL_CRITICAL_SECTION_DEBUG,*PRTL_CRITICAL_SECTION_DEBUG,RTL_RESOURCE_DEBUG,*PRTL_RESOURCE_DEBUG;

#تعریف_کرو RTL_CRITSECT_TYPE 0
#تعریف_کرو RTL_RESOURCE_TYPE 1

    قسمتعریف ساخت _RTL_CRITICAL_SECTION {
      PRTL_CRITICAL_SECTION_DEBUG DebugInfo;
      LONG تالا_گنتی;
      LONG Recursion_گنتی;
      HANDLE OwningThread;
      HANDLE تالا_Semaphore;
      ULONG_PTR Spin_گنتی;
    } RTL_CRITICAL_SECTION,*PRTL_CRITICAL_SECTION;

    قسمتعریف VOID (NTAPI *RTL_VERIFIER_DLL_بھرو_CALLBACK) (PWSTR DllName,PVOID Dll_بنیاد,سائز_T Dll_سائز,PVOID Reserved);
    قسمتعریف VOID (NTAPI *RTL_VERIFIER_DLL_UNLOAD_CALLBACK) (PWSTR DllName,PVOID Dll_بنیاد,سائز_T Dll_سائز,PVOID Reserved);
    قسمتعریف VOID (NTAPI *RTL_VERIFIER_NTDLLHEAPFREE_CALLBACK)(PVOID تخصیص_بنیاد,سائز_T تخصیص_سائز);

    قسمتعریف ساخت _RTL_VERIFIER_THUNK_DESCRIPTOR {
      PCHAR ThunkName;
      PVOID Thunk_Old_پتہ;
      PVOID Thunk_New_پتہ;
    } RTL_VERIFIER_THUNK_DESCRIPTOR,*PRTL_VERIFIER_THUNK_DESCRIPTOR;

    قسمتعریف ساخت _RTL_VERIFIER_DLL_DESCRIPTOR {
      PWCHAR DllName;
      DWORD DllFlags;
      PVOID Dll_پتہ;
      PRTL_VERIFIER_THUNK_DESCRIPTOR DllThunks;
    } RTL_VERIFIER_DLL_DESCRIPTOR,*PRTL_VERIFIER_DLL_DESCRIPTOR;

    قسمتعریف ساخت _RTL_VERIFIER_PROVIDER_DESCRIPTOR {
      DWORD لمبائی_2;
      PRTL_VERIFIER_DLL_DESCRIPTOR ProviderDlls;
      RTL_VERIFIER_DLL_بھرو_CALLBACK Provider_Dll_بھرو_Callback;
      RTL_VERIFIER_DLL_UNLOAD_CALLBACK ProviderDllUnloadCallback;
      PWSTR VerifierImage;
      DWORD VerifierFlags;
      DWORD VerifierDebug;
      PVOID Rtlp_Get_ڈھیر_Trace_پتہ;
      PVOID Rtlp_Debug_صفحہ_ڈھیر_Create;
      PVOID Rtlp_Debug_صفحہ_ڈھیر_Destroy;
      RTL_VERIFIER_NTDLLHEAPFREE_CALLBACK Provider_Ntdll_ڈھیر_Free_Callback;
    } RTL_VERIFIER_PROVIDER_DESCRIPTOR,*PRTL_VERIFIER_PROVIDER_DESCRIPTOR;

#تعریف_کرو RTL_VRF_FLG_بھرا_صفحہ_ڈھیر 0x00000001
#تعریف_کرو RTL_VRF_FLG_RESERVED_DONOTUSE 0x00000002
#تعریف_کرو RTL_VRF_FLG_HANDLE_CHECKS 0x00000004
#تعریف_کرو RTL_VRF_FLG_ڈھیر_CHECKS 0x00000008
#تعریف_کرو RTL_VRF_FLG_APPCOMPAT_CHECKS 0x00000010
#تعریف_کرو RTL_VRF_FLG_TLS_CHECKS 0x00000020
#تعریف_کرو RTL_VRF_FLG_DIRTY_STACKS 0x00000040
#تعریف_کرو RTL_VRF_FLG_RPC_CHECKS 0x00000080
#تعریف_کرو RTL_VRF_FLG_COM_CHECKS 0x00000100
#تعریف_کرو RTL_VRF_FLG_DANGEROUS_APIS 0x00000200
#تعریف_کرو RTL_VRF_FLG_RACE_CHECKS 0x00000400
#تعریف_کرو RTL_VRF_FLG_DEADLOCK_CHECKS 0x00000800
#تعریف_کرو RTL_VRF_FLG_پہلا_CHANCE_EXCEPTION_CHECKS 0x00001000
#تعریف_کرو RTL_VRF_FLG_VIRTUAL_MEM_CHECKS 0x00002000
#تعریف_کرو RTL_VRF_FLG_ENABLE_LOGGING 0x00004000
#تعریف_کرو RTL_VRF_FLG_FAST_FILL_ڈھیر 0x00008000
#تعریف_کرو RTL_VRF_FLG_VIRTUAL_SPACE_TRACKING 0x00010000
#تعریف_کرو RTL_VRF_FLG_ENABLED_SYSTEM_WIDE 0x00020000
#تعریف_کرو RTL_VRF_FLG_MISCELLANEOUS_CHECKS 0x00020000
#تعریف_کرو RTL_VRF_FLG_تالا_CHECKS 0x00040000

#تعریف_کرو APPLICATION_VERIFIER_اندرونی_ERROR 0x80000000
#تعریف_کرو APPLICATION_VERIFIER_اندرونی_WARNING 0x40000000
#تعریف_کرو APPLICATION_VERIFIER_NO_BREAK 0x20000000
#تعریف_کرو APPLICATION_VERIFIER_CONTINUABLE_BREAK 0x10000000

#تعریف_کرو APPLICATION_VERIFIER_UNKNOWN_ERROR 0x0001
#تعریف_کرو APPLICATION_VERIFIER_ACCESS_VIOLATION 0x0002
#تعریف_کرو APPLICATION_VERIFIER_UNSYNCHRONIZED_ACCESS 0x0003
#تعریف_کرو APPLICATION_VERIFIER_EXTREME_سائز_REQUEST 0x0004
#تعریف_کرو APPLICATION_VERIFIER_BAD_ڈھیر_HANDLE 0x0005
#تعریف_کرو APPLICATION_VERIFIER_SWITCHED_ڈھیر_HANDLE 0x0006
#تعریف_کرو APPLICATION_VERIFIER_DOUBLE_FREE 0x0007
#تعریف_کرو APPLICATION_VERIFIER_CORRUPTED_ڈھیر_بلاک 0x0008
#تعریف_کرو APPLICATION_VERIFIER_DESTROY_PROCESS_ڈھیر 0x0009
#تعریف_کرو APPLICATION_VERIFIER_UNEXPECTED_EXCEPTION 0x000A
#تعریف_کرو APPLICATION_VERIFIER_CORRUPTED_ڈھیر_بلاک_EXCEPTION_RAISED_FOR_سرخی 0x000B
#تعریف_کرو APPLICATION_VERIFIER_CORRUPTED_ڈھیر_بلاک_EXCEPTION_RAISED_FOR_PROBING 0x000C
#تعریف_کرو APPLICATION_VERIFIER_CORRUPTED_ڈھیر_بلاک_سرخی 0x000D
#تعریف_کرو APPLICATION_VERIFIER_CORRUPTED_FREED_ڈھیر_بلاک 0x000E
#تعریف_کرو APPLICATION_VERIFIER_CORRUPTED_ڈھیر_بلاک_SUFFIX 0x000F
#تعریف_کرو APPLICATION_VERIFIER_CORRUPTED_ڈھیر_بلاک_آغاز_STAMP 0x0010
#تعریف_کرو APPLICATION_VERIFIER_CORRUPTED_ڈھیر_بلاک_انتہا_STAMP 0x0011
#تعریف_کرو APPLICATION_VERIFIER_CORRUPTED_ڈھیر_بلاک_سابقہ 0x0012
#تعریف_کرو APPLICATION_VERIFIER_پہلا_CHANCE_ACCESS_VIOLATION 0x0013
#تعریف_کرو APPLICATION_VERIFIER_CORRUPTED_ڈھیر_LIST 0x0014

#تعریف_کرو APPLICATION_VERIFIER_TERMINATE_THREAD_CALL 0x0100
#تعریف_کرو APPLICATION_VERIFIER_ڈھیر_حد_سے_تجاوز 0x0101
#تعریف_کرو APPLICATION_VERIFIER_INVALID_EXIT_PROCESS_CALL 0x0102

#تعریف_کرو APPLICATION_VERIFIER_EXIT_THREAD_OWNS_تالا 0x0200
#تعریف_کرو APPLICATION_VERIFIER_تالا_اندر_UNLOADED_DLL 0x0201
#تعریف_کرو APPLICATION_VERIFIER_تالا_اندر_FREED_ڈھیر 0x0202
#تعریف_کرو APPLICATION_VERIFIER_تالا_DOUBLE_INITIALIZE 0x0203
#تعریف_کرو APPLICATION_VERIFIER_تالا_اندر_FREED_حافظہ 0x0204
#تعریف_کرو APPLICATION_VERIFIER_تالا_CORRUPTED 0x0205
#تعریف_کرو APPLICATION_VERIFIER_تالا_INVALID_OWNER 0x0206
#تعریف_کرو APPLICATION_VERIFIER_تالا_INVALID_RECURSION_گنتی 0x0207
#تعریف_کرو APPLICATION_VERIFIER_تالا_INVALID_تالا_گنتی 0x0208
#تعریف_کرو APPLICATION_VERIFIER_تالا_OVER_RELEASED 0x0209
#تعریف_کرو APPLICATION_VERIFIER_تالا_NOT_INITIALIZED 0x0210
#تعریف_کرو APPLICATION_VERIFIER_تالا_ALREADY_INITIALIZED 0x0211
#تعریف_کرو APPLICATION_VERIFIER_تالا_اندر_FREED_VMEM 0x0212
#تعریف_کرو APPLICATION_VERIFIER_تالا_اندر_UNMAPPED_MEM 0x0213
#تعریف_کرو APPLICATION_VERIFIER_THREAD_NOT_تالا_OWNER 0x0214

#تعریف_کرو APPLICATION_VERIFIER_INVALID_HANDLE 0x0300
#تعریف_کرو APPLICATION_VERIFIER_INVALID_TLS_قدر 0x0301
#تعریف_کرو APPLICATION_VERIFIER_INCORRECT_WAIT_CALL 0x0302
#تعریف_کرو APPLICATION_VERIFIER_NULL_HANDLE 0x0303
#تعریف_کرو APPLICATION_VERIFIER_WAIT_اندر_DLLMAIN 0x0304

#تعریف_کرو APPLICATION_VERIFIER_COM_ERROR 0x0400
#تعریف_کرو APPLICATION_VERIFIER_COM_API_اندر_DLLMAIN 0x0401
#تعریف_کرو APPLICATION_VERIFIER_COM_UNHANDLED_EXCEPTION 0x0402
#تعریف_کرو APPLICATION_VERIFIER_COM_UNBALANCED_COINIT 0x0403
#تعریف_کرو APPLICATION_VERIFIER_COM_UNBALANCED_OLEINIT 0x0404
#تعریف_کرو APPLICATION_VERIFIER_COM_UNBALANCED_SWC 0x0405
#تعریف_کرو APPLICATION_VERIFIER_COM_NULL_DACL 0x0406
#تعریف_کرو APPLICATION_VERIFIER_COM_UNSAFE_IMPERSONATION 0x0407
#تعریف_کرو APPLICATION_VERIFIER_COM_SMUGGLED_WRAPPER 0x0408
#تعریف_کرو APPLICATION_VERIFIER_COM_SMUGGLED_PROXY 0x0409
#تعریف_کرو APPLICATION_VERIFIER_COM_CF_SUCCESS_WITH_NULL 0x040A
#تعریف_کرو APPLICATION_VERIFIER_COM_GCO_SUCCESS_WITH_NULL 0x040B
#تعریف_کرو APPLICATION_VERIFIER_COM_OBJECT_اندر_FREED_حافظہ 0x040C
#تعریف_کرو APPLICATION_VERIFIER_COM_OBJECT_اندر_UNLOADED_DLL 0x040D
#تعریف_کرو APPLICATION_VERIFIER_COM_VTBL_اندر_FREED_حافظہ 0x040E
#تعریف_کرو APPLICATION_VERIFIER_COM_VTBL_اندر_UNLOADED_DLL 0x040F
#تعریف_کرو APPLICATION_VERIFIER_COM_HOLDING_LOCKS_ON_CALL 0x0410

#تعریف_کرو APPLICATION_VERIFIER_RPC_ERROR 0x0500

#تعریف_کرو APPLICATION_VERIFIER_INVALID_FREEMEM 0x0600
#تعریف_کرو APPLICATION_VERIFIER_INVALID_ALLOCMEM 0x0601
#تعریف_کرو APPLICATION_VERIFIER_INVALID_MAPVIEW 0x0602
#تعریف_کرو APPLICATION_VERIFIER_PROBE_INVALID_پتہ 0x0603
#تعریف_کرو APPLICATION_VERIFIER_PROBE_FREE_MEM 0x0604
#تعریف_کرو APPLICATION_VERIFIER_PROBE_GUARD_صفحہ 0x0605
#تعریف_کرو APPLICATION_VERIFIER_PROBE_NULL 0x0606
#تعریف_کرو APPLICATION_VERIFIER_PROBE_INVALID_آغاز_OR_سائز 0x0607
#تعریف_کرو APPLICATION_VERIFIER_سائز_ڈھیر_UNEXPECTED_EXCEPTION 0x0618

#تعریف_کرو VERIFIER_STOP(رمز_4,پیغام_5,P1,S1,P2,S2,P3,S3,P4,S4) { RtlApplicationVerifierStop ((رمز_4),(پیغام_5),(ULONG_PTR)(P1),(S1),(ULONG_PTR)(P2),(S2),(ULONG_PTR)(P3),(S3),(ULONG_PTR)(P4),(S4)); }

    VOID NTAPI RtlApplicationVerifierStop(ULONG_PTR رمز_4,PSTR پیغام_6,ULONG_PTR Param1,PSTR Description1,ULONG_PTR Param2,PSTR Description2,ULONG_PTR Param3,PSTR Description3,ULONG_PTR Param4,PSTR Description4);

    قسمتعریف LONG (NTAPI *PVECTORED_EXCEPTION_HANDLER)(ساخت EXCEPTION_اشارے_2 *ExceptionInfo);
#تعریف_کرو SEF_DACL_AUTO_INHERIT 0x01
#تعریف_کرو SEF_SACL_AUTO_INHERIT 0x02
#تعریف_کرو SEF_DEFAULT_DESCRIPTOR_FOR_OBJECT 0x04
#تعریف_کرو SEF_AVOID_PRIVILEGE_CHECK 0x08
#تعریف_کرو SEF_AVOID_OWNER_CHECK 0x10
#تعریف_کرو SEF_DEFAULT_OWNER_FROM_والد 0x20
#تعریف_کرو SEF_DEFAULT_گروہ_FROM_والد 0x40

    قسمتعریف شمار ڈھیر_INFORMATION_CLASS_2 {
      ڈھیر_Compatibility_Information
    } ڈھیر_INFORMATION_CLASS;

    NTSYSAPI DWORD NTAPI Rtl_سیٹ_ڈھیر_Information(PVOID ڈھیر_Handle,ڈھیر_INFORMATION_CLASS ڈھیر_Information_Class,PVOID ڈھیر_Information,سائز_T ڈھیر_Information_لمبائی);
    NTSYSAPI DWORD NTAPI Rtl_Query_ڈھیر_Information(PVOID ڈھیر_Handle,ڈھیر_INFORMATION_CLASS ڈھیر_Information_Class,PVOID ڈھیر_Information,سائز_T ڈھیر_Information_لمبائی,PSIZE_T Return_لمبائی);
    DWORD NTAPI Rtl_مضرب_Allocate_ڈھیر(PVOID ڈھیر_Handle,DWORD Flags,سائز_T سائز_3,DWORD گنتی_3,PVOID *Array);
    DWORD NTAPI Rtl_مضرب_Free_ڈھیر(PVOID ڈھیر_Handle,DWORD Flags,DWORD گنتی_3,PVOID *Array);

#تعریف_کرو WT_EXECUTEDEFAULT 0x00000000
#تعریف_کرو WT_EXECUTEINIOTHREAD 0x00000001
#تعریف_کرو WT_EXECUTEINUITHREAD 0x00000002
#تعریف_کرو WT_EXECUTEINWAITTHREAD 0x00000004
#تعریف_کرو WT_EXECUTEONLYONCE 0x00000008
#تعریف_کرو WT_EXECUTEINTIMERTHREAD 0x00000020
#تعریف_کرو WT_EXECUTELONGFUNCTION 0x00000010
#تعریف_کرو WT_EXECUTEINPERSISTENTIOTHREAD 0x00000040
#تعریف_کرو WT_EXECUTEINPERSISTENTTHREAD 0x00000080
#تعریف_کرو WT_TRANSFER_IMPERSONATION 0x00000100
#تعریف_کرو WT_سیٹ_MAX_THREADPOOL_دھاگے(Flags,حد_بندی_2) ((Flags) |= (حد_بندی_2)<<16)
    قسمتعریف VOID (NTAPI *WAITORTIMERCALLBACKFUNC)(PVOID,BOOLEAN);
    قسمتعریف VOID (NTAPI *WORKERCALLBACKFUNC)(PVOID);
    قسمتعریف VOID (NTAPI *APC_CALLBACK_FUNCTION)(DWORD ,PVOID,PVOID);
    قسمتعریف
      VOID
      (NTAPI *PFLS_CALLBACK_FUNCTION)(PVOID lp_Fls_ڈیٹا);
#تعریف_کرو WT_EXECUTEINLONGTHREAD 0x00000010
#تعریف_کرو WT_EXECUTEDELETEWAIT 0x00000008

    قسمتعریف شمار _ACTIVATION_CONTEXT_INFO_CLASS {
      ActivationContextBasicInformation = 1,ActivationContextDetailedInformation = 2,Assembly_Detailed_Information_اندر_Activation_Context = 3,File_Information_اندر_Assembly_کا_Assembly_اندر_Activation_Context = 4,MaxActivationContextInfoClass,Assembly_Detailed_Information_اندر_Activation_Contxt = 3,File_Information_اندر_Assembly_کا_Assembly_اندر_Activation_Contxt = 4
    } ACTIVATION_CONTEXT_INFO_CLASS;

#تعریف_کرو ACTIVATIONCONTEXTINFOCLASS ACTIVATION_CONTEXT_INFO_CLASS

    قسمتعریف ساخت ACTIVATION_CONTEXT_QUERY_اشاریہ {
      DWORD ul_Assembly_اشاریہ;
      DWORD ul_File_اشاریہ_اندر_Assembly;
    } ACTIVATION_CONTEXT_QUERY_اشاریہ_2,*PACTIVATION_CONTEXT_QUERY_اشاریہ;

    قسمتعریف ثابت ساخت ACTIVATION_CONTEXT_QUERY_اشاریہ *PCACTIVATION_CONTEXT_QUERY_اشاریہ;

#تعریف_کرو ACTIVATION_CONTEXT_راستہ_TYPE_NONE (1)
#تعریف_کرو ACTIVATION_CONTEXT_راستہ_TYPE_WIN32_FILE (2)
#تعریف_کرو ACTIVATION_CONTEXT_راستہ_TYPE_URL (3)
#تعریف_کرو ACTIVATION_CONTEXT_راستہ_TYPE_ASSEMBLYREF (4)

    قسمتعریف ساخت _ASSEMBLY_FILE_DETAILED_INFORMATION {
      DWORD ulFlags;
      DWORD ul_Filename_لمبائی;
      DWORD ul_راستہ_لمبائی;

      PCWSTR lpFileName;
      PCWSTR lp_File_راستہ;
    } ASSEMBLY_FILE_DETAILED_INFORMATION,*PASSEMBLY_FILE_DETAILED_INFORMATION;
    قسمتعریف ثابت ASSEMBLY_FILE_DETAILED_INFORMATION *PCASSEMBLY_FILE_DETAILED_INFORMATION;

#تعریف_کرو _ASSEMBLY_DLL_REDIRECTION_DETAILED_INFORMATION _ASSEMBLY_FILE_DETAILED_INFORMATION
#تعریف_کرو ASSEMBLY_DLL_REDIRECTION_DETAILED_INFORMATION ASSEMBLY_FILE_DETAILED_INFORMATION
#تعریف_کرو PASSEMBLY_DLL_REDIRECTION_DETAILED_INFORMATION PASSEMBLY_FILE_DETAILED_INFORMATION
#تعریف_کرو PCASSEMBLY_DLL_REDIRECTION_DETAILED_INFORMATION PCASSEMBLY_FILE_DETAILED_INFORMATION

    قسمتعریف ساخت _ACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION {
      DWORD ulFlags;
      DWORD ul_Encoded_Assembly_شناختی_عنصر_لمبائی;
      DWORD ul_Manifest_راستہ_Type;
      DWORD ul_Manifest_راستہ_لمبائی;
      LARGE_INTEGER li_Manifest_آخری_Write_وقت;
      DWORD ul_Policy_راستہ_Type;
      DWORD ul_Policy_راستہ_لمبائی;
      LARGE_INTEGER li_Policy_آخری_Write_وقت;
      DWORD ul_Metadata_Satellite_Roster_اشاریہ;
      DWORD ul_Manifest_نسخہ_Major;
      DWORD ul_Manifest_نسخہ_Minor;
      DWORD ul_Policy_نسخہ_Major;
      DWORD ul_Policy_نسخہ_Minor;
      DWORD ul_Assembly_Directory_Name_لمبائی;
      PCWSTR lp_Assembly_Encoded_Assembly_شناختی_عنصر;
      PCWSTR lp_Assembly_Manifest_راستہ;
      PCWSTR lp_Assembly_Policy_راستہ;
      PCWSTR lpAssemblyDirectoryName;
      DWORD ul_File_گنتی;
    } ACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION,*PACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION;

    قسمتعریف ثابت ساخت _ACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION *PCACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION;

    قسمتعریف ساخت _ACTIVATION_CONTEXT_DETAILED_INFORMATION {
      DWORD dwFlags;
      DWORD ul_Format_نسخہ;
      DWORD ul_Assembly_گنتی;
      DWORD ul_جڑ_Manifest_راستہ_Type;
      DWORD ul_جڑ_Manifest_راستہ_Chars;
      DWORD ul_جڑ_Configuration_راستہ_Type;
      DWORD ul_جڑ_Configuration_راستہ_Chars;
      DWORD ul_App_Dir_راستہ_Type;
      DWORD ul_App_Dir_راستہ_Chars;
      PCWSTR lp_جڑ_Manifest_راستہ;
      PCWSTR lp_جڑ_Configuration_راستہ;
      PCWSTR lp_App_Dir_راستہ;
    } ACTIVATION_CONTEXT_DETAILED_INFORMATION,*PACTIVATION_CONTEXT_DETAILED_INFORMATION;

    قسمتعریف ثابت ساخت _ACTIVATION_CONTEXT_DETAILED_INFORMATION *PCACTIVATION_CONTEXT_DETAILED_INFORMATION;

#تعریف_کرو DLL_PROCESS_ATTACH 1
#تعریف_کرو DLL_THREAD_ATTACH 2
#تعریف_کرو DLL_THREAD_DETACH 3
#تعریف_کرو DLL_PROCESS_DETACH 0
#تعریف_کرو DLL_PROCESS_VERIFIER 4

#تعریف_کرو EVENTLOG_SEQUENTIAL_READ 0x0001
#تعریف_کرو EVENTLOG_SEEK_READ 0x0002
#تعریف_کرو EVENTLOG_FORWARDS_READ 0x0004
#تعریف_کرو EVENTLOG_BACKWARDS_READ 0x0008

#تعریف_کرو EVENTLOG_SUCCESS 0x0000
#تعریف_کرو EVENTLOG_ERROR_TYPE 0x0001
#تعریف_کرو EVENTLOG_WARNING_TYPE 0x0002
#تعریف_کرو EVENTLOG_INFORMATION_TYPE 0x0004
#تعریف_کرو EVENTLOG_AUDIT_SUCCESS 0x0008
#تعریف_کرو EVENTLOG_AUDIT_FAILURE 0x0010

#تعریف_کرو EVENTLOG_آغاز_PAIRED_EVENT 0x0001
#تعریف_کرو EVENTLOG_انتہا_PAIRED_EVENT 0x0002
#تعریف_کرو EVENTLOG_انتہا_ALL_PAIRED_EVENTS 0x0004
#تعریف_کرو EVENTLOG_PAIRED_EVENT_فعال 0x0008
#تعریف_کرو EVENTLOG_PAIRED_EVENT_INACTIVE 0x0010

    قسمتعریف ساخت _EVENTLOGRECORD {
      DWORD لمبائی_2;
      DWORD Reserved;
      DWORD ریکارڈ_نمبر;
      DWORD وقت_Generated;
      DWORD وقت_Written;
      DWORD EventID;
      لفظ_3 EventType;
      لفظ_3 عدد_لڑیاں;
      لفظ_3 EventCategory;
      لفظ_3 ReservedFlags;
      DWORD Closing_ریکارڈ_نمبر;
      DWORD String_انحراف;
      DWORD User_Sid_لمبائی;
      DWORD User_Sid_انحراف;
      DWORD ڈیٹا_لمبائی;
      DWORD ڈیٹا_انحراف_2;
    } EVENTLOGRECORD,*PEVENTLOGRECORD;

#تعریف_کرو MAXLOGICALLOGNAMESIZE 256

    قسمتعریف ساخت _EVENTSFORLOGFILE{
      DWORD ul_سائز;
      WCHAR szLogicalLogFile[MAXLOGICALLOGNAMESIZE];
      DWORD ul_عدد_اندراجات;
      EVENTLOGRECORD p_Event_Log_اندراجات[];
    } EVENTSFORLOGFILE,*PEVENTSFORLOGFILE;

    قسمتعریف ساخت _PACKEDEVENTINFO{
      DWORD ul_سائز;
      DWORD ul_عدد_Events_For_Log_File;
      DWORD ulOffsets[];
    } PACKEDEVENTINFO,*PPACKEDEVENTINFO;

#تعریف_کرو کلید_QUERY_قدر (0x0001)
#تعریف_کرو کلید_سیٹ_قدر (0x0002)
#تعریف_کرو کلید_CREATE_SUB_کلید (0x0004)
#تعریف_کرو کلید_ENUMERATE_SUB_کلیدیں (0x0008)
#تعریف_کرو کلید_NOTIFY (0x0010)
#تعریف_کرو کلید_CREATE_LINK (0x0020)
#تعریف_کرو کلید_WOW64_32_کلید (0x0200)
#تعریف_کرو کلید_WOW64_64_کلید (0x0100)
#تعریف_کرو کلید_WOW64_RES (0x0300)

#تعریف_کرو کلید_READ ((STANDARD_RIGHTS_READ | کلید_QUERY_قدر | کلید_ENUMERATE_SUB_کلیدیں | کلید_NOTIFY) & (~SYNCHRONIZE))
#تعریف_کرو کلید_WRITE ((STANDARD_RIGHTS_WRITE | کلید_سیٹ_قدر | کلید_CREATE_SUB_کلید) & (~SYNCHRONIZE))
#تعریف_کرو کلید_EXECUTE ((کلید_READ) & (~SYNCHRONIZE))
#تعریف_کرو کلید_ALL_ACCESS ((STANDARD_RIGHTS_ALL | کلید_QUERY_قدر | کلید_سیٹ_قدر | کلید_CREATE_SUB_کلید | کلید_ENUMERATE_SUB_کلیدیں | کلید_NOTIFY | کلید_CREATE_LINK) & (~SYNCHRONIZE))
#تعریف_کرو REG_OPTION_RESERVED (0x00000000L)

#تعریف_کرو REG_OPTION_NON_VOLATILE (0x00000000L)
#تعریف_کرو REG_OPTION_VOLATILE (0x00000001L)
#تعریف_کرو REG_OPTION_CREATE_LINK (0x00000002L)
#تعریف_کرو REG_OPTION_BACKUP_RESTORE (0x00000004L)
#تعریف_کرو REG_OPTION_OPEN_LINK (0x00000008L)
#تعریف_کرو REG_LEGAL_OPTION (REG_OPTION_RESERVED | REG_OPTION_NON_VOLATILE | REG_OPTION_VOLATILE | REG_OPTION_CREATE_LINK | REG_OPTION_BACKUP_RESTORE | REG_OPTION_OPEN_LINK)
#تعریف_کرو REG_CREATED_NEW_کلید (0x00000001L)
#تعریف_کرو REG_OPENED_EXISTING_کلید (0x00000002L)
#تعریف_کرو REG_STANDARD_FORMAT 1
#تعریف_کرو REG_LATEST_FORMAT 2
#تعریف_کرو REG_NO_COMPRESSION 4
#تعریف_کرو REG_پورا_HIVE_VOLATILE (0x00000001L)
#تعریف_کرو REG_REFRESH_HIVE (0x00000002L)
#تعریف_کرو REG_NO_LAZY_FLUSH (0x00000004L)
#تعریف_کرو REG_FORCE_RESTORE (0x00000008L)
#تعریف_کرو REG_FORCE_UNLOAD 1

#تعریف_کرو REG_NOTIFY_CHANGE_NAME (0x00000001L)
#تعریف_کرو REG_NOTIFY_CHANGE_اوصاف (0x00000002L)
#تعریف_کرو REG_NOTIFY_CHANGE_آخری_سیٹ (0x00000004L)
#تعریف_کرو REG_NOTIFY_CHANGE_SECURITY (0x00000008L)

#تعریف_کرو REG_LEGAL_CHANGE_FILTER (REG_NOTIFY_CHANGE_NAME | REG_NOTIFY_CHANGE_اوصاف | REG_NOTIFY_CHANGE_آخری_سیٹ | REG_NOTIFY_CHANGE_SECURITY)

#تعریف_کرو REG_NONE (0)
#تعریف_کرو REG_SZ (1)
#تعریف_کرو REG_EXPAND_SZ (2)

#تعریف_کرو REG_ثنائی (3)
#تعریف_کرو REG_DWORD (4)
#تعریف_کرو REG_DWORD_LITTLE_ENDIAN (4)
#تعریف_کرو REG_DWORD_BIG_ENDIAN (5)
#تعریف_کرو REG_LINK (6)
#تعریف_کرو REG_MULTI_SZ (7)
#تعریف_کرو REG_RESOURCE_LIST (8)
#تعریف_کرو REG_بھرا_RESOURCE_DESCRIPTOR (9)
#تعریف_کرو REG_RESOURCE_REQUIREMENTS_LIST (10)
#تعریف_کرو REG_QWORD (11)
#تعریف_کرو REG_QWORD_LITTLE_ENDIAN (11)

#تعریف_کرو SERVICE_KERNEL_DRIVER 0x00000001
#تعریف_کرو SERVICE_FILE_SYSTEM_DRIVER 0x00000002
#تعریف_کرو SERVICE_ADAPTER 0x00000004
#تعریف_کرو SERVICE_RECOGNIZER_DRIVER 0x00000008

#تعریف_کرو SERVICE_DRIVER (SERVICE_KERNEL_DRIVER | SERVICE_FILE_SYSTEM_DRIVER | SERVICE_RECOGNIZER_DRIVER)

#تعریف_کرو SERVICE_WIN32_OWN_PROCESS 0x00000010
#تعریف_کرو SERVICE_WIN32_SHARE_PROCESS 0x00000020
#تعریف_کرو SERVICE_WIN32 (SERVICE_WIN32_OWN_PROCESS | SERVICE_WIN32_SHARE_PROCESS)

#تعریف_کرو SERVICE_INTERACTIVE_PROCESS 0x00000100

#تعریف_کرو SERVICE_TYPE_ALL (SERVICE_WIN32 | SERVICE_ADAPTER | SERVICE_DRIVER | SERVICE_INTERACTIVE_PROCESS)

#تعریف_کرو SERVICE_BOOT_آغاز 0x00000000
#تعریف_کرو SERVICE_SYSTEM_آغاز 0x00000001
#تعریف_کرو SERVICE_AUTO_آغاز 0x00000002
#تعریف_کرو SERVICE_DEMAND_آغاز 0x00000003
#تعریف_کرو SERVICE_DISABLED 0x00000004

#تعریف_کرو SERVICE_ERROR_IGNORE 0x00000000
#تعریف_کرو SERVICE_ERROR_معمول 0x00000001
#تعریف_کرو SERVICE_ERROR_SEVERE 0x00000002
#تعریف_کرو SERVICE_ERROR_CRITICAL 0x00000003

    قسمتعریف شمار CM_SERVICE_گرہ_TYPE {
      DriverType = SERVICE_KERNEL_DRIVER,FileSystemType = SERVICE_FILE_SYSTEM_DRIVER,Win32ServiceOwnProcess = SERVICE_WIN32_OWN_PROCESS,
      Win32ServiceShareProcess = SERVICE_WIN32_SHARE_PROCESS,AdapterType = SERVICE_ADAPTER,RecognizerType = SERVICE_RECOGNIZER_DRIVER
    } SERVICE_گرہ_TYPE;

    قسمتعریف شمار CM_SERVICE_بھرو_TYPE {
      Boot_بھرو = SERVICE_BOOT_آغاز,System_بھرو = SERVICE_SYSTEM_آغاز,Auto_بھرو = SERVICE_AUTO_آغاز,Demand_بھرو = SERVICE_DEMAND_آغاز,
      Disable_بھرو = SERVICE_DISABLED
    } SERVICE_بھرو_TYPE;

    قسمتعریف شمار _CM_ERROR_CONTROL_TYPE {
      IgnoreError = SERVICE_ERROR_IGNORE,معمول_Error = SERVICE_ERROR_معمول,SevereError = SERVICE_ERROR_SEVERE,CriticalError = SERVICE_ERROR_CRITICAL
    } SERVICE_ERROR_TYPE;

#تعریف_کرو فیتہ_ERASE_SHORT 0L
#تعریف_کرو فیتہ_ERASE_LONG 1L

    قسمتعریف ساخت فیتہ_ERASE {
      DWORD Type;
      BOOLEAN فوری_2;
    } فیتہ_ERASE_2,*PTAPE_ERASE;

#تعریف_کرو فیتہ_بھرو 0L
#تعریف_کرو فیتہ_UNLOAD 1L
#تعریف_کرو فیتہ_TENSION 2L
#تعریف_کرو فیتہ_تالا 3L
#تعریف_کرو فیتہ_UNLOCK 4L
#تعریف_کرو فیتہ_FORMAT 5L

    قسمتعریف ساخت فیتہ_PREPARE {
      DWORD Operation;
      BOOLEAN فوری_2;
    } فیتہ_PREPARE_2,*PTAPE_PREPARE;

#تعریف_کرو فیتہ_SETMARKS 0L
#تعریف_کرو فیتہ_FILEMARKS 1L
#تعریف_کرو فیتہ_SHORT_FILEMARKS 2L
#تعریف_کرو فیتہ_LONG_FILEMARKS 3L

    قسمتعریف ساخت فیتہ_WRITE_MARKS {
      DWORD Type;
      DWORD گنتی_3;
      BOOLEAN فوری_2;
    } فیتہ_WRITE_MARKS_2,*PTAPE_WRITE_MARKS;

#تعریف_کرو فیتہ_ABSOLUTE_POSITION 0L
#تعریف_کرو فیتہ_LOGICAL_POSITION 1L
#تعریف_کرو فیتہ_PSEUDO_LOGICAL_POSITION 2L

    قسمتعریف ساخت فیتہ_GET_POSITION {
      DWORD Type;
      DWORD تقسیم_2;
      LARGE_INTEGER انحراف_3;
    } فیتہ_GET_POSITION_2,*PTAPE_GET_POSITION;

#تعریف_کرو فیتہ_REWIND 0L
#تعریف_کرو فیتہ_ABSOLUTE_بلاک 1L
#تعریف_کرو فیتہ_LOGICAL_بلاک 2L
#تعریف_کرو فیتہ_PSEUDO_LOGICAL_بلاک 3L
#تعریف_کرو فیتہ_SPACE_انتہا_کا_ڈیٹا 4L
#تعریف_کرو فیتہ_SPACE_RELATIVE_بلاکیں 5L
#تعریف_کرو فیتہ_SPACE_FILEMARKS 6L
#تعریف_کرو فیتہ_SPACE_SEQUENTIAL_FMKS 7L
#تعریف_کرو فیتہ_SPACE_SETMARKS 8L
#تعریف_کرو فیتہ_SPACE_SEQUENTIAL_SMKS 9L

    قسمتعریف ساخت فیتہ_سیٹ_POSITION {
      DWORD طریقہ_3;
      DWORD تقسیم_2;
      LARGE_INTEGER انحراف_3;
      BOOLEAN فوری_2;
    } فیتہ_سیٹ_POSITION_2,*PTAPE_سیٹ_POSITION;

#تعریف_کرو فیتہ_DRIVE_FIXED 0x00000001
#تعریف_کرو فیتہ_DRIVE_SELECT 0x00000002
#تعریف_کرو فیتہ_DRIVE_INITIATOR 0x00000004

#تعریف_کرو فیتہ_DRIVE_ERASE_SHORT 0x00000010
#تعریف_کرو فیتہ_DRIVE_ERASE_LONG 0x00000020
#تعریف_کرو فیتہ_DRIVE_ERASE_BOP_ONLY 0x00000040
#تعریف_کرو فیتہ_DRIVE_ERASE_فوری 0x00000080

#تعریف_کرو فیتہ_DRIVE_فیتہ_استعداد 0x00000100
#تعریف_کرو فیتہ_DRIVE_فیتہ_بقایا 0x00000200
#تعریف_کرو فیتہ_DRIVE_FIXED_بلاک 0x00000400
#تعریف_کرو فیتہ_DRIVE_VARIABLE_بلاک 0x00000800

#تعریف_کرو فیتہ_DRIVE_WRITE_PROTECT 0x00001000
#تعریف_کرو فیتہ_DRIVE_EOT_WZ_سائز 0x00002000

#تعریف_کرو فیتہ_DRIVE_ECC 0x00010000
#تعریف_کرو فیتہ_DRIVE_COMPRESSION 0x00020000
#تعریف_کرو فیتہ_DRIVE_PADDING 0x00040000
#تعریف_کرو فیتہ_DRIVE_REPORT_SMKS 0x00080000

#تعریف_کرو فیتہ_DRIVE_GET_ABSOLUTE_BLK 0x00100000
#تعریف_کرو فیتہ_DRIVE_GET_LOGICAL_BLK 0x00200000
#تعریف_کرو فیتہ_DRIVE_سیٹ_EOT_WZ_سائز 0x00400000

#تعریف_کرو فیتہ_DRIVE_EJECT_MEDIA 0x01000000
#تعریف_کرو فیتہ_DRIVE_CLEAN_درخواستیں 0x02000000
#تعریف_کرو فیتہ_DRIVE_سیٹ_CMP_BOP_ONLY 0x04000000

#تعریف_کرو فیتہ_DRIVE_RESERVED_ثنائی_ہندسہ 0x80000000

#تعریف_کرو فیتہ_DRIVE_بھرو_UNLOAD 0x80000001
#تعریف_کرو فیتہ_DRIVE_TENSION 0x80000002
#تعریف_کرو فیتہ_DRIVE_تالا_UNLOCK 0x80000004
#تعریف_کرو فیتہ_DRIVE_REWIND_فوری 0x80000008

#تعریف_کرو فیتہ_DRIVE_سیٹ_بلاک_سائز 0x80000010
#تعریف_کرو فیتہ_DRIVE_بھرو_UNLD_IMMED 0x80000020
#تعریف_کرو فیتہ_DRIVE_TENSION_IMMED 0x80000040
#تعریف_کرو فیتہ_DRIVE_تالا_UNLK_IMMED 0x80000080

#تعریف_کرو فیتہ_DRIVE_سیٹ_ECC 0x80000100
#تعریف_کرو فیتہ_DRIVE_سیٹ_COMPRESSION 0x80000200
#تعریف_کرو فیتہ_DRIVE_سیٹ_PADDING 0x80000400
#تعریف_کرو فیتہ_DRIVE_سیٹ_REPORT_SMKS 0x80000800

#تعریف_کرو فیتہ_DRIVE_ABSOLUTE_BLK 0x80001000
#تعریف_کرو فیتہ_DRIVE_ABS_BLK_IMMED 0x80002000
#تعریف_کرو فیتہ_DRIVE_LOGICAL_BLK 0x80004000
#تعریف_کرو فیتہ_DRIVE_LOG_BLK_IMMED 0x80008000

#تعریف_کرو فیتہ_DRIVE_انتہا_کا_ڈیٹا 0x80010000
#تعریف_کرو فیتہ_DRIVE_RELATIVE_BLKS 0x80020000
#تعریف_کرو فیتہ_DRIVE_FILEMARKS 0x80040000
#تعریف_کرو فیتہ_DRIVE_SEQUENTIAL_FMKS 0x80080000

#تعریف_کرو فیتہ_DRIVE_SETMARKS 0x80100000
#تعریف_کرو فیتہ_DRIVE_SEQUENTIAL_SMKS 0x80200000
#تعریف_کرو فیتہ_DRIVE_الٹ_POSITION 0x80400000
#تعریف_کرو فیتہ_DRIVE_SPACE_فوری 0x80800000

#تعریف_کرو فیتہ_DRIVE_WRITE_SETMARKS 0x81000000
#تعریف_کرو فیتہ_DRIVE_WRITE_FILEMARKS 0x82000000
#تعریف_کرو فیتہ_DRIVE_WRITE_SHORT_FMKS 0x84000000
#تعریف_کرو فیتہ_DRIVE_WRITE_LONG_FMKS 0x88000000

#تعریف_کرو فیتہ_DRIVE_WRITE_MARK_IMMED 0x90000000
#تعریف_کرو فیتہ_DRIVE_FORMAT 0xA0000000
#تعریف_کرو فیتہ_DRIVE_FORMAT_فوری 0xC0000000
#تعریف_کرو فیتہ_DRIVE_بلند_FEATURES 0x80000000

    قسمتعریف ساخت فیتہ_GET_DRIVE_PARAMETERS {
      BOOLEAN ECC;
      BOOLEAN Compression;
      BOOLEAN ڈیٹا_Padding;
      BOOLEAN ReportSetmarks;
      DWORD Default_بلاک_سائز;
      DWORD زیادہ_سے_زیادہ_بلاک_سائز;
      DWORD Minimum_بلاک_سائز;
      DWORD زیادہ_سے_زیادہ_تقسیم_گنتی;
      DWORD Features_کم;
      DWORD Features_بلند;
      DWORD EOTWarning_Zone_سائز;
    } فیتہ_GET_DRIVE_PARAMETERS_2,*PTAPE_GET_DRIVE_PARAMETERS;

    قسمتعریف ساخت فیتہ_سیٹ_DRIVE_PARAMETERS {
      BOOLEAN ECC;
      BOOLEAN Compression;
      BOOLEAN ڈیٹا_Padding;
      BOOLEAN ReportSetmarks;
      DWORD EOTWarning_Zone_سائز;
    } فیتہ_سیٹ_DRIVE_PARAMETERS_2,*PTAPE_سیٹ_DRIVE_PARAMETERS;

    قسمتعریف ساخت فیتہ_GET_MEDIA_PARAMETERS {
      LARGE_INTEGER استعداد;
      LARGE_INTEGER بقایا;
      DWORD بلاک_سائز;
      DWORD تقسیم_گنتی;
      BOOLEAN WriteProtected;
    } فیتہ_GET_MEDIA_PARAMETERS_2,*PTAPE_GET_MEDIA_PARAMETERS;

    قسمتعریف ساخت فیتہ_سیٹ_MEDIA_PARAMETERS {
      DWORD بلاک_سائز;
    } فیتہ_سیٹ_MEDIA_PARAMETERS_2,*PTAPE_سیٹ_MEDIA_PARAMETERS;

#تعریف_کرو فیتہ_FIXED_PARTITIONS 0L
#تعریف_کرو فیتہ_SELECT_PARTITIONS 1L
#تعریف_کرو فیتہ_INITIATOR_PARTITIONS 2L

    قسمتعریف ساخت فیتہ_CREATE_تقسیم {
      DWORD طریقہ_3;
      DWORD گنتی_3;
      DWORD سائز_3;
    } فیتہ_CREATE_تقسیم_2,*PTAPE_CREATE_تقسیم;

#تعریف_کرو فیتہ_QUERY_DRIVE_PARAMETERS 0L
#تعریف_کرو فیتہ_QUERY_MEDIA_استعداد 1L
#تعریف_کرو فیتہ_CHECK_FOR_DRIVE_PROBLEM 2L
#تعریف_کرو فیتہ_QUERY_IO_ERROR_ڈیٹا 3L
#تعریف_کرو فیتہ_QUERY_DEVICE_ERROR_ڈیٹا 4L

    قسمتعریف ساخت فیتہ_WMI_OPERATIONS {
      DWORD طریقہ_3;
      DWORD ڈیٹا_بفر_سائز;
      PVOID ڈیٹا_بفر;
    } فیتہ_WMI_OPERATIONS_2,*PTAPE_WMI_OPERATIONS;

    قسمتعریف شمار فیتہ_DRIVE_PROBLEM_TYPE {
      فیتہ_Drive_Problem_None,فیتہ_Drive_Read_Write_Warning,فیتہ_Drive_Read_Write_Error,فیتہ_Drive_Read_Warning,فیتہ_Drive_Write_Warning,فیتہ_Drive_Read_Error,فیتہ_Drive_Write_Error,فیتہ_Drive_Hardware_Error,فیتہ_Drive_Unsupported_Media,فیتہ_Drive_Scsi_Connection_Error,فیتہ_Drive_Timeto_Clean,فیتہ_Drive_Clean_Drive_Now,فیتہ_Drive_Media_Life_Expired,فیتہ_Drive_Snapped_فیتہ
    } فیتہ_DRIVE_PROBLEM_TYPE_2;

#اگر defined(__x86_64)
    __CRT_INLINE ساخت _TEB *NtCurrentTeb(VOID) { واپس (ساخت _TEB *)__readgsqword(میدان_انحراف(NT_TIB,Self)); }
    __CRT_INLINE PVOID GetCurrentFiber(VOID) { واپس(PVOID)__readgsqword(میدان_انحراف(NT_TIB,Fiber_ڈیٹا)); }
    __CRT_INLINE PVOID Get_Fiber_ڈیٹا(VOID) {
      واپس *(PVOID *)GetCurrentFiber();
    }
#اگر_ختم

#اگر(defined(_X86_) && !defined(__x86_64))
#تعریف_کرو PcTeb 0x18
    __CRT_INLINE ساخت _TEB *NtCurrentTeb(خالی) {
      ساخت _TEB *ret;
      __asm__ متلون ("movl	%%fs:0x18,%0"
	: "=r" (ret));
      واپس ret;
    }
#اگر_ختم

#تعریف_کرو ACTIVATION_CONTEXT_SECTION_ASSEMBLY_INFORMATION (1)
#تعریف_کرو ACTIVATION_CONTEXT_SECTION_DLL_REDIRECTION (2)
#تعریف_کرو ACTIVATION_CONTEXT_SECTION_کھڑکی_CLASS_REDIRECTION (3)
#تعریف_کرو ACTIVATION_CONTEXT_SECTION_COM_SERVER_REDIRECTION (4)
#تعریف_کرو ACTIVATION_CONTEXT_SECTION_COM_INTERFACE_REDIRECTION (5)
#تعریف_کرو ACTIVATION_CONTEXT_SECTION_COM_TYPE_LIBRARY_REDIRECTION (6)
#تعریف_کرو ACTIVATION_CONTEXT_SECTION_COM_PROGID_REDIRECTION (7)
#تعریف_کرو ACTIVATION_CONTEXT_SECTION_GLOBAL_OBJECT_RENAME_جدول (8)
#تعریف_کرو ACTIVATION_CONTEXT_SECTION_CLR_SURROGATES (9)
#تعریف_کرو ACTIVATION_CONTEXT_SECTION_APPLICATION_SETTINGS (10)

#اگر_تعریف_شدہ __cplusplus
  }
#اگر_ختم
#اگر_ختم
