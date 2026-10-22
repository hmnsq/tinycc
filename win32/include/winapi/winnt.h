/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WINNT_
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WINNT_

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
ਬਾਹਰੀ "C" {
#ਜੇ_ਅੰਤ

#ਅਨ੍ਤਰ੍ਭਾਵ <ctype.h>
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ANYSIZE_ARRAY 1

//gr #include <specstrings.h>

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RESTRICTED_ਸੂਚਕ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __CRT_UNALIGNED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __CRT_UNALIGNED
#ਜੇ_ਅੰਤ

#ਜੇ defined(__ia64__) || defined(__x86_64) || defined(__aarch64__)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UNALIGNED __CRT_UNALIGNED
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UNALIGNED64 __CRT_UNALIGNED
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UNALIGNED64
#ਜੇ_ਅੰਤ
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UNALIGNED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UNALIGNED64
#ਜੇ_ਅੰਤ

#ਜੇ !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && (defined(_X86_) && !defined(__x86_64))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ I_X86_
#ਜੇ_ਅੰਤ

#ਜੇ !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && defined(__x86_64)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _AMD64_
#ਜੇ_ਅੰਤ

#ਜੇ !defined(I_X86_) && !(defined(_X86_) && !defined(__x86_64)) && !defined(_AMD64_) && defined(__ia64__)
#ਜੇ !defined(_IA64_)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _IA64_
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ


#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAX_NATURAL_ALIGNMENT ਆਕਾਰ(ULONGLONG)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਮ੍ਰਿਤੀ_ਵੰਡ_ALIGNMENT 16
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAX_NATURAL_ALIGNMENT ਆਕਾਰ(DWORD)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਮ੍ਰਿਤੀ_ਵੰਡ_ALIGNMENT 8
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TYPE_ALIGNMENT(t) __alignof__ (t)
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TYPE_ALIGNMENT(t) ਖੇਤਰ_ਵਿੱਥ(ਬਣਤਰ { ਅੱਖਰ x; t test; },test)
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN64
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _AMD64_
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROBE_ALIGNMENT(_s) TYPE_ALIGNMENT(DWORD)
#ਜਾਂਜੇ defined(_IA64_) || defined(_ARM64_)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROBE_ALIGNMENT(_s) (TYPE_ALIGNMENT(_s) > TYPE_ALIGNMENT(DWORD) ? TYPE_ALIGNMENT(_s) : TYPE_ALIGNMENT(DWORD))
#ਨਹੀਂਤਾਂ
#ਗਲਤੀ No ਨਿਸ਼ਾਨਾ_2 Architecture
#ਜੇ_ਅੰਤ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROBE_ALIGNMENT32(_s) TYPE_ALIGNMENT(DWORD)
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROBE_ALIGNMENT(_s) TYPE_ALIGNMENT(DWORD)
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ C_ASSERT(e) ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਅੱਖਰ __C_ASSERT__[(e)?1:-1]

#ਅਨ੍ਤਰ੍ਭਾਵ <basetsd.h>

#ਜੇ defined(_X86_) || defined(__ia64__) || defined(__x86_64) || defined(__aarch64__)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DECLSPEC_IMPORT __declspec(dllimport)
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DECLSPEC_IMPORT
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ DECLSPEC_NORETURN
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DECLSPEC_NORETURN __declspec(noreturn)
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ DECLSPEC_ALIGN
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DECLSPEC_ALIGN(x) __attribute__ ((aligned(x)))
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ SYSTEM_CACHE_ALIGNMENT_ਮਾਪ
#ਜੇ defined(_AMD64_) || defined(I_X86_)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SYSTEM_CACHE_ALIGNMENT_ਮਾਪ 64
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SYSTEM_CACHE_ALIGNMENT_ਮਾਪ 128
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ DECLSPEC_CACHEALIGN
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DECLSPEC_CACHEALIGN DECLSPEC_ALIGN(SYSTEM_CACHE_ALIGNMENT_ਮਾਪ)
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ DECLSPEC_UUID
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DECLSPEC_UUID(x)
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ DECLSPEC_NOVTABLE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DECLSPEC_NOVTABLE
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ DECLSPEC_SELECTANY
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DECLSPEC_SELECTANY __declspec(selectany)
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOP_FUNCTION
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NOP_FUNCTION (ਖਾਲੀ)0
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ DECLSPEC_NOINLINE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DECLSPEC_NOINLINE
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ FORCEINLINE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FORCEINLINE ਸਥਿਰ __inline__
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ DECLSPEC_DEPRECATED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DECLSPEC_DEPRECATED __declspec(deprecated)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DEPRECATE_SUPPORTED
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DECLSPEC_DEPRECATED_DDK
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRAGMA_DEPRECATED_DDK 0

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਖਾਲੀ *PVOID;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਖਾਲੀ *PVOID64;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NTAPI __stdcall
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NTSYSAPI DECLSPEC_IMPORT
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NTSYSCALLAPI DECLSPEC_IMPORT

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ VOID
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VOID ਖਾਲੀ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਅੱਖਰ CHAR;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਛੋਟਾ SHORT;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਲੰਮਾ LONG;
#ਜੇ_ਅੰਤ

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ wchar_t WCHAR;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ WCHAR *PWCHAR,*LPWCH,*PWCH;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ CONST WCHAR *LPCWCH,*PCWCH;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ WCHAR *NWPSTR,*LPWSTR,*PWSTR;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PWSTR *PZPWSTR;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ CONST PWSTR *PCZPWSTR;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ WCHAR UNALIGNED *LPUWSTR,*PUWSTR;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ CONST WCHAR *LPCWSTR,*PCWSTR;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PCWSTR *PZPCWSTR;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ CONST WCHAR UNALIGNED *LPCUWSTR,*PCUWSTR;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ CHAR *PCHAR,*LPCH,*PCH;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ CONST CHAR *LPCCH,*PCCH;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ CHAR *NPSTR,*LPSTR,*PSTR;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PSTR *PZPSTR;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ CONST PSTR *PCZPSTR;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ CONST CHAR *LPCSTR,*PCSTR;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PCSTR *PZPCSTR;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _TCHAR_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _TCHAR_DEFINED
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ WCHAR TCHAR,*PTCHAR;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ WCHAR TBYTE ,*PTBYTE;
#ਜੇ_ਅੰਤ

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPWSTR LPTCH,PTCH;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPWSTR PTSTR,LPTSTR;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPCWSTR PCTSTR,LPCTSTR;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPUWSTR PUTSTR,LPUTSTR;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPCUWSTR PCUTSTR,LPCUTSTR;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPWSTR LP;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __TEXT(quote) L##quote
#ਨਹੀਂਤਾਂ
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _TCHAR_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _TCHAR_DEFINED
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਅੱਖਰ TCHAR,*PTCHAR;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ TBYTE ,*PTBYTE;
#ਜੇ_ਅੰਤ

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPSTR LPTCH,PTCH;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPSTR PTSTR,LPTSTR,PUTSTR,LPUTSTR;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPCSTR PCTSTR,LPCTSTR,PCUTSTR,LPCUTSTR;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __TEXT(quote) quote
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਪਾਠ_3(quote) __TEXT(quote)

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ SHORT *PSHORT;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LONG *PLONG;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਖਾਲੀ *HANDLE;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DECLARE_HANDLE(name) ਬਣਤਰ name##__ { ਪੂਰਨ ਅਣਵਰਤਿਆ; }; ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ name##__ *name
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ HANDLE *PHANDLE;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ BYTE FCHAR;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਸ਼ਬਦ_3 FSHORT;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ DWORD FLONG;

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _HRESULT_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _HRESULT_DEFINED
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LONG HRESULT;
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXTERN_C ਬਾਹਰੀ "C"
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXTERN_C ਬਾਹਰੀ
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STDMETHODCALLTYPE WINAPI
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STDMETHODVCALLTYPE __cdecl
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STDAPICALLTYPE WINAPI
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STDAPIVCALLTYPE __cdecl
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STDAPI EXTERN_C HRESULT WINAPI
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STDAPI_(type) EXTERN_C type WINAPI
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STDMETHODIMP HRESULT WINAPI
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STDMETHODIMP_(type) type WINAPI
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STDAPIV EXTERN_C HRESULT STDAPIVCALLTYPE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STDAPIV_(type) EXTERN_C type STDAPIVCALLTYPE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STDMETHODIMPV HRESULT STDMETHODVCALLTYPE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STDMETHODIMPV_(type) type STDMETHODVCALLTYPE

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਅੱਖਰ CCHAR;
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _LCID_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _LCID_DEFINED
ਕਿਸਮਪਰਿਭਾਸ਼ਾ DWORD LCID;
#ਜੇ_ਅੰਤ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PDWORD PLCID;
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _LANGID_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _LANGID_DEFINED
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਸ਼ਬਦ_3 LANGID;
#ਜੇ_ਅੰਤ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_ERROR_ਨਕਾਬ 0x20000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ERROR_SEVERITY_SUCCESS 0x00000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ERROR_SEVERITY_INFORMATIONAL 0x40000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ERROR_SEVERITY_WARNING 0x80000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ERROR_SEVERITY_ERROR 0xC0000000

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __ia64__
  __declspec(align(16))
#ਜੇ_ਅੰਤ
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _FLOAT128 {
      __int64 ਨੀਵਾਂ_Part;
      __int64 ਉੱਚਾ_Part;
  } FLOAT128;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ FLOAT128 *PFLOAT128;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _ULONGLONG_
#ਜੇ((!(defined(_X86_) && !defined(__x86_64)) || (defined(INTEGRAL_MAX_ਬਿੱਟ) && INTEGRAL_MAX_ਬਿੱਟ >= 64)))
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ __int64 LONGLONG;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 ULONGLONG;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAXLONGLONG (0x7fffffffffffffff)
#ਨਹੀਂਤਾਂ

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਦੁੱਗਣਾ LONGLONG;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਦੁੱਗਣਾ ULONGLONG;
#ਜੇ_ਅੰਤ

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LONGLONG *PLONGLONG;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ULONGLONG *PULONGLONG;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LONGLONG USN;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਸੰਘ _LARGE_INTEGER {
    ਬਣਤਰ {
      DWORD ਨੀਵਾਂ_Part;
      LONG ਉੱਚਾ_Part;
    };
    ਬਣਤਰ {
      DWORD ਨੀਵਾਂ_Part;
      LONG ਉੱਚਾ_Part;
    } u;
    LONGLONG QuadPart;
  } LARGE_INTEGER;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LARGE_INTEGER *PLARGE_INTEGER;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਸੰਘ _ULARGE_INTEGER {
    ਬਣਤਰ {
      DWORD ਨੀਵਾਂ_Part;
      DWORD ਉੱਚਾ_Part;
    };
    ਬਣਤਰ {
      DWORD ਨੀਵਾਂ_Part;
      DWORD ਉੱਚਾ_Part;
    } u;
    ULONGLONG QuadPart;
  } ULARGE_INTEGER;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ULARGE_INTEGER *PULARGE_INTEGER;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _LUID {
    DWORD ਨੀਵਾਂ_Part;
    LONG ਉੱਚਾ_Part;
  } LUID,*PLUID;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _DWORDLONG_
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ULONGLONG DWORDLONG;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ DWORDLONG *PDWORDLONG;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ RC_INVOKED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Int32x32To64(a,b) ((LONGLONG)((LONG)(a)) *(LONGLONG)((LONG)(b)))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UInt32x32To64(a,b) ((ULONGLONG)((DWORD)(a)) *(ULONGLONG)((DWORD)(b)))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Int64ShrlMod32(a,b) ((ULONGLONG)(a) >> (b))
#ਜਾਂਜੇ (defined(_X86_) && !defined(__x86_64))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Int32x32To64(a,b) (LONGLONG)((LONGLONG)(LONG)(a) *(LONG)(b))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UInt32x32To64(a,b) (ULONGLONG)((ULONGLONG)(DWORD)(a) *(DWORD)(b))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Int64ShrlMod32(a,b) ((DWORDLONG)(a)>>(b))
#ਜਾਂਜੇ defined(__ia64__) || defined(__x86_64) || defined(__aarch64__)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Int32x32To64(a,b) ((LONGLONG)((LONG)(a)) *(LONGLONG)((LONG)(b)))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UInt32x32To64(a,b) ((ULONGLONG)((DWORD)(a)) *(ULONGLONG)((DWORD)(b)))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Int64ShrlMod32(a,b) ((ULONGLONG)(a) >> (b))
#ਨਹੀਂਤਾਂ
#ਗਲਤੀ Must define a ਨਿਸ਼ਾਨਾ architecture.
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Int64ShraMod32(a,b) ((LONGLONG)(a) >> (b))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Int64ShllMod32(a,b) ((ULONGLONG)(a) << (b))

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
  ਬਾਹਰੀ "C" {
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __x86_64

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RotateLeft8 _rotl8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RotateLeft16 _rotl16
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RotateRight8 _rotr8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RotateRight16 _rotr16

    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ __cdecl _rotl8(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ ਮੁੱਲ_3,ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ ਖਿਸਕਾਓ_3);
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ __cdecl _rotl16(ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ ਮੁੱਲ_3,ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ ਖਿਸਕਾਓ_3);
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ __cdecl _rotr8(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ ਮੁੱਲ_3,ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ ਖਿਸਕਾਓ_3);
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ __cdecl _rotr16(ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ ਮੁੱਲ_3,ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ ਖਿਸਕਾਓ_3);
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RotateLeft32 _rotl
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RotateLeft64 _rotl64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RotateRight32 _rotr
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RotateRight64 _rotr64

    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ __cdecl _rotl(ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ ਮੁੱਲ_3,ਪੂਰਨ ਖਿਸਕਾਓ_3);
    ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 __cdecl _rotl64(ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 ਮੁੱਲ_3,ਪੂਰਨ ਖਿਸਕਾਓ_3);
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ __cdecl _rotr(ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ ਮੁੱਲ_3,ਪੂਰਨ ਖਿਸਕਾਓ_3);
    ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 __cdecl _rotr64(ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 ਮੁੱਲ_3,ਪੂਰਨ ਖਿਸਕਾਓ_3);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
  }
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ANSI_NULL ((CHAR)0)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UNICODE_NULL ((WCHAR)0)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UNICODE_STRING_MAX_ਬਾਈਟਾਂ ((ਸ਼ਬਦ_3) 65534)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UNICODE_STRING_MAX_CHARS (32767)

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _BOOLEAN_
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _BOOLEAN_
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ BYTE BOOLEAN;
#ਜੇ_ਅੰਤ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ BOOLEAN *PBOOLEAN;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ LIST_ਇੰਦਰਾਜ {
    ਬਣਤਰ LIST_ਇੰਦਰਾਜ *Flink;
    ਬਣਤਰ LIST_ਇੰਦਰਾਜ *Blink;
  } LIST_ਇੰਦਰਾਜ_2,*PLIST_ਇੰਦਰਾਜ,*RESTRICTED_ਸੂਚਕ PRLIST_ਇੰਦਰਾਜ;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ SINGLE_LIST_ਇੰਦਰਾਜ {
    ਬਣਤਰ SINGLE_LIST_ਇੰਦਰਾਜ *ਅਗਲਾ_2;
  } SINGLE_LIST_ਇੰਦਰਾਜ_2,*PSINGLE_LIST_ਇੰਦਰਾਜ;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ LIST_ENTRY32 {
    DWORD Flink;
    DWORD Blink;
  } LIST_ENTRY32;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LIST_ENTRY32 *PLIST_ENTRY32;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ LIST_ENTRY64 {
    ULONGLONG Flink;
    ULONGLONG Blink;
  } LIST_ENTRY64;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LIST_ENTRY64 *PLIST_ENTRY64;

#ਅਨ੍ਤਰ੍ਭਾਵ <guiddef.h>

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __OBJECTID_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __OBJECTID_DEFINED
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _OBJECTID {
    GUID Lineage;
    DWORD Uniquifier;
  } OBJECTID;
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MINCHAR 0x80
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAXCHAR 0x7f
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MINSHORT 0x8000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAXSHORT 0x7fff
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MINLONG 0x80000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAXLONG 0x7fffffff
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAXBYTE 0xff
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAXWORD 0xffff
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAXDWORD 0xffffffff

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਖੇਤਰ_ਵਿੱਥ(type,ਖੇਤਰ) ((LONG)(LONG_PTR)&(((type *)0)->ਖੇਤਰ))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RTL_ਖੇਤਰ_ਮਾਪ(type,ਖੇਤਰ) (ਆਕਾਰ(((type *)0)->ਖੇਤਰ))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RTL_SIZEOF_THROUGH_ਖੇਤਰ(type,ਖੇਤਰ) (ਖੇਤਰ_ਵਿੱਥ(type,ਖੇਤਰ) + RTL_ਖੇਤਰ_ਮਾਪ(type,ਖੇਤਰ))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RTL_ਸ਼ਾਮਲ_ਹੈ_ਖੇਤਰ(Struct,ਮਾਪ_3,ਖੇਤਰ_2) ((((PCHAR)(&(Struct)->ਖੇਤਰ_2)) + ਆਕਾਰ((Struct)->ਖੇਤਰ_2)) <= (((PCHAR)(Struct))+(ਮਾਪ_3)))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RTL_ਸੰਖਿਆ_ਦਾ_V1(A) (ਆਕਾਰ(A)/ਆਕਾਰ((A)[0]))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RTL_ਸੰਖਿਆ_ਦਾ_V2(A) RTL_ਸੰਖਿਆ_ਦਾ_V1(A)

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ ENABLE_RTL_ਸੰਖਿਆ_ਦਾ_V2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RTL_ਸੰਖਿਆ_ਦਾ(A) RTL_ਸੰਖਿਆ_ਦਾ_V2(A)
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RTL_ਸੰਖਿਆ_ਦਾ(A) RTL_ਸੰਖਿਆ_ਦਾ_V1(A)
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ARRAYSIZE(A) RTL_ਸੰਖਿਆ_ਦਾ_V2(A)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _ARRAYSIZE(A) RTL_ਸੰਖਿਆ_ਦਾ_V1(A)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RTL_ਖੇਤਰ_TYPE(type,ਖੇਤਰ) (((type*)0)->ਖੇਤਰ)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RTL_ਸੰਖਿਆ_ਦਾ_ਖੇਤਰ(type,ਖੇਤਰ) (RTL_ਸੰਖਿਆ_ਦਾ(RTL_ਖੇਤਰ_TYPE(type,ਖੇਤਰ)))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RTL_PADDING_BETWEEN_FIELDS(T,F1,F2) ((ਖੇਤਰ_ਵਿੱਥ(T,F2) > ਖੇਤਰ_ਵਿੱਥ(T,F1)) ? (ਖੇਤਰ_ਵਿੱਥ(T,F2) - ਖੇਤਰ_ਵਿੱਥ(T,F1) - RTL_ਖੇਤਰ_ਮਾਪ(T,F1)) : (ਖੇਤਰ_ਵਿੱਥ(T,F1) - ਖੇਤਰ_ਵਿੱਥ(T,F2) - RTL_ਖੇਤਰ_ਮਾਪ(T,F2)))

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RTL_CONST_CAST(type) const_cast<type>
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RTL_CONST_CAST(type) (type)
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RTL_ਬਿੱਟ_ਦਾ(ਮਾਪ_ਦਾ_Arg) (ਆਕਾਰ(ਮਾਪ_ਦਾ_Arg) *8)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RTL_ਬਿੱਟ_ਦਾ_ਖੇਤਰ(type,ਖੇਤਰ) (RTL_ਬਿੱਟ_ਦਾ(RTL_ਖੇਤਰ_TYPE(type,ਖੇਤਰ)))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONTAINING_ਰਿਕਾਰਡ(ਪਤਾ,type,ਖੇਤਰ) ((type *)((PCHAR)(ਪਤਾ) - (ULONG_PTR)(&((type *)0)->ਖੇਤਰ)))

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VER_SERVER_NT 0x80000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VER_WORKSTATION_NT 0x40000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VER_SUITE_SMALLBUSINESS 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VER_SUITE_ENTERPRISE 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VER_SUITE_BACKOFFICE 0x00000004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VER_SUITE_COMMUNICATIONS 0x00000008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VER_SUITE_TERMINAL 0x00000010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VER_SUITE_SMALLBUSINESS_RESTRICTED 0x00000020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VER_SUITE_EMBEDDEDNT 0x00000040
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VER_SUITE_DATACENTER 0x00000080
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VER_SUITE_SINGLEUSERTS 0x00000100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VER_SUITE_PERSONAL 0x00000200
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VER_SUITE_BLADE 0x00000400
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VER_SUITE_EMBEDDED_RESTRICTED 0x00000800
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VER_SUITE_SECURITY_APPLIANCE 0x00001000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VER_SUITE_STORAGE_SERVER 0x00002000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VER_SUITE_COMPUTE_SERVER 0x00004000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਗੁਣਨਫਲ_UNDEFINED                       0x0

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਗੁਣਨਫਲ_ULTIMATE                        0x1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਗੁਣਨਫਲ_HOME_BASIC                      0x2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਗੁਣਨਫਲ_HOME_PREMIUM                    0x3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਗੁਣਨਫਲ_ENTERPRISE                      0x4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਗੁਣਨਫਲ_HOME_BASIC_N                    0x5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਗੁਣਨਫਲ_BUSINESS                        0x6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਗੁਣਨਫਲ_STANDARD_SERVER                 0x7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਗੁਣਨਫਲ_DATACENTER_SERVER               0x8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਗੁਣਨਫਲ_SMALLBUSINESS_SERVER            0x9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਗੁਣਨਫਲ_ENTERPRISE_SERVER               0xa
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਗੁਣਨਫਲ_STARTER                         0xb
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਗੁਣਨਫਲ_DATACENTER_SERVER_CORE          0xc
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਗੁਣਨਫਲ_STANDARD_SERVER_CORE            0xd
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਗੁਣਨਫਲ_ENTERPRISE_SERVER_CORE          0xe
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਗੁਣਨਫਲ_ENTERPRISE_SERVER_IA64          0xf
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਗੁਣਨਫਲ_BUSINESS_N                      0x10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਗੁਣਨਫਲ_WEB_SERVER                      0x11
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਗੁਣਨਫਲ_CLUSTER_SERVER                  0x12
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਗੁਣਨਫਲ_HOME_SERVER                     0x13
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਗੁਣਨਫਲ_STORAGE_EXPRESS_SERVER          0x14
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਗੁਣਨਫਲ_STORAGE_STANDARD_SERVER         0x15
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਗੁਣਨਫਲ_STORAGE_WORKGROUP_SERVER        0x16
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਗੁਣਨਫਲ_STORAGE_ENTERPRISE_SERVER       0x17
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਗੁਣਨਫਲ_SERVER_FOR_SMALLBUSINESS        0x18
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਗੁਣਨਫਲ_SMALLBUSINESS_SERVER_PREMIUM    0x19

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਗੁਣਨਫਲ_UNLICENSED                      0xabcdabcd

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_NEUTRAL 0x00
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_INVARIANT 0x7f

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_AFRIKAANS 0x36
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_ALBANIAN 0x1c
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_ALSATIAN 0x84
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_AMHARIC 0x5e
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_ARABIC 0x01
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_ARMENIAN 0x2b
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_ASSAMESE 0x4d
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_AZERI 0x2c
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_BASHKIR 0x6d
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_BASQUE 0x2d
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_BELARUSIAN 0x23
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_BENGALI 0x45
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_BRETON 0x7e
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_BOSNIAN 0x1a
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_BOSNIAN_NEUTRAL 0x781a
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_BULGARIAN 0x02
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_ਕੈਟਾਲਨ 0x03
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_CHINESE 0x04
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_CHINESE_SIMPLIFIED 0x04
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_CHINESE_TRADITIONAL 0x7c04
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_CORSICAN 0x83
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_CROATIAN 0x1a
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_CZECH 0x05
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_DANISH 0x06
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_DARI 0x8c
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_DIVEHI 0x65
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_DUTCH 0x13
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_ENGLISH 0x09
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_ESTONIAN 0x25
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_FAEROESE 0x38
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_FARSI 0x29
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_FILIPINO 0x64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_FINNISH 0x0b
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_FRENCH 0x0c
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_FRISIAN 0x62
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_GALICIAN 0x56
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_GEORGIAN 0x37
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_GERMAN 0x07
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_GREEK 0x08
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_GREENLANDIC 0x6f
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_GUJARATI 0x47
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_HAUSA 0x68
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_HEBREW 0x0d
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_HINDI 0x39
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_HUNGARIAN 0x0e
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_ICELANDIC 0x0f
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_IGBO 0x70
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_INDONESIAN 0x21
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_INUKTITUT 0x5d
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_IRISH 0x3c
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_ITALIAN 0x10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_JAPANESE 0x11
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_KANNADA 0x4b
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_KASHMIRI 0x60
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_KAZAK 0x3f
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_KHMER 0x53
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_KICHE 0x86
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_KINYARWANDA 0x87
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_KONKANI 0x57
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_KOREAN 0x12
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_KYRGYZ 0x40
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_LAO 0x54
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_LATVIAN 0x26
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_LITHUANIAN 0x27
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_ਹੇਠਲਾ_SORBIAN 0x2e
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_LUXEMBOURGISH 0x6e
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_MACEDONIAN 0x2f
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_MALAY 0x3e
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_MALAYALAM 0x4c
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_MALTESE 0x3a
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_MANIPURI 0x58
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_MAORI 0x81
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_MAPUDUNGUN 0x7a
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_MARATHI 0x4e
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_MOHAWK 0x7c
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_MONGOLIAN 0x50
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_NEPALI 0x61
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_NORWEGIAN 0x14
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_OCCITAN 0x82
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_ORIYA 0x48
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_PASHTO 0x63
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_PERSIAN 0x29
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_POLISH 0x15
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_PORTUGUESE 0x16
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_PUNJABI 0x46
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_QUECHUA 0x6b
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_ROMANIAN 0x18
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_RUSSIAN 0x19
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_SAMI 0x3b
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_ROMANSH 0x17
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_SANSKRIT 0x4f
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_SERBIAN 0x1a
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_SERBIAN_NEUTRAL 0x7c1a
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_SINDHI 0x59
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_SINHALESE 0x5b
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_SLOVAK 0x1b
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_SLOVENIAN 0x24
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_SOTHO 0x6c
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_SPANISH 0x0a
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_SWAHILI 0x41
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_SWEDISH 0x1d
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_SYRIAC 0x5a
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_TAJIK 0x28
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_TAMAZIGHT 0x5f
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_TAMIL 0x49
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_TATAR 0x44
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_TELUGU 0x4a
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_THAI 0x1e
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_TIBETAN 0x51
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_TIGRIGNA 0x73
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_TSWANA 0x32
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_TURKISH 0x1f
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_TURKMEN 0x42
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_UIGHUR 0x80
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_UKRAINIAN 0x22
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_ਉੱਤਲਾ_SORBIAN 0x2e
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_URDU 0x20
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_UZBEK 0x43
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_VIETNAMESE 0x2a
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_WELSH 0x52
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_WOLOF 0x88
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_XHOSA 0x34
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_YAKUT 0x85
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_YI 0x78
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_YORUBA 0x6a
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_ZULU 0x35

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_NEUTRAL 0x0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_DEFAULT 0x1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_SYS_DEFAULT 0x2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_CUSTOM_DEFAULT 0x3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_CUSTOM_UNSPECIFIED 0x4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_UI_CUSTOM_DEFAULT 0x5

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_ARABIC_SAUDI_ARABIA 0x01
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_ARABIC_IRAQ 0x02
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_ARABIC_EGYPT 0x03
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_ARABIC_LIBYA 0x04
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_ARABIC_ALGERIA 0x05
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_ARABIC_MOROCCO 0x06
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_ARABIC_TUNISIA 0x07
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_ARABIC_OMAN 0x08
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_ARABIC_YEMEN 0x09
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_ARABIC_SYRIA 0x0a
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_ARABIC_JORDAN 0x0b
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_ARABIC_LEBANON 0x0c
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_ARABIC_KUWAIT 0x0d
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_ARABIC_UAE 0x0e
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_ARABIC_BAHRAIN 0x0f
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_ARABIC_QATAR 0x10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_AZERI_LATIN 0x01
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_AZERI_CYRILLIC 0x02
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_CHINESE_TRADITIONAL 0x01
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_CHINESE_SIMPLIFIED 0x02
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_CHINESE_HONGKONG 0x03
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_CHINESE_SINGAPORE 0x04
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_CHINESE_MACAU 0x05
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_DUTCH 0x01
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_DUTCH_BELGIAN 0x02
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_ENGLISH_US 0x01
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_ENGLISH_UK 0x02
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_ENGLISH_AUS 0x03
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_ENGLISH_CAN 0x04
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_ENGLISH_NZ 0x05
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_ENGLISH_EIRE 0x06
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_ENGLISH_SOUTH_AFRICA 0x07
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_ENGLISH_JAMAICA 0x08
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_ENGLISH_CARIBBEAN 0x09
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_ENGLISH_BELIZE 0x0a
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_ENGLISH_TRINIDAD 0x0b
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_ENGLISH_ZIMBABWE 0x0c
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_ENGLISH_PHILIPPINES 0x0d
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_FRENCH 0x01
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_FRENCH_BELGIAN 0x02
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_FRENCH_CANADIAN 0x03
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_FRENCH_SWISS 0x04
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_FRENCH_LUXEMBOURG 0x05
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_FRENCH_MONACO 0x06
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_GERMAN 0x01
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_GERMAN_SWISS 0x02
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_GERMAN_AUSTRIAN 0x03
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_GERMAN_LUXEMBOURG 0x04
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_GERMAN_LIECHTENSTEIN 0x05
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_ITALIAN 0x01
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_ITALIAN_SWISS 0x02
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_KASHMIRI_SASIA 0x02
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_KASHMIRI_INDIA 0x02
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_KOREAN 0x01
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_LITHUANIAN 0x01
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_MALAY_MALAYSIA 0x01
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_MALAY_BRUNEI_DARUSSALAM 0x02
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_NEPALI_INDIA 0x02
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_NORWEGIAN_BOKMAL 0x01
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_NORWEGIAN_NYNORSK 0x02
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_PORTUGUESE 0x02
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_PORTUGUESE_BRAZILIAN 0x01
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_SERBIAN_LATIN 0x02
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_SERBIAN_CYRILLIC 0x03
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_SPANISH 0x01
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_SPANISH_MEXICAN 0x02
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_SPANISH_MODERN 0x03
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_SPANISH_GUATEMALA 0x04
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_SPANISH_COSTA_RICA 0x05
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_SPANISH_PANAMA 0x06
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_SPANISH_DOMINICAN_REPUBLIC 0x07
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_SPANISH_VENEZUELA 0x08
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_SPANISH_COLOMBIA 0x09
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_SPANISH_PERU 0x0a
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_SPANISH_ARGENTINA 0x0b
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_SPANISH_ECUADOR 0x0c
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_SPANISH_CHILE 0x0d
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_SPANISH_URUGUAY 0x0e
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_SPANISH_PARAGUAY 0x0f
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_SPANISH_BOLIVIA 0x10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_SPANISH_EL_SALVADOR 0x11
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_SPANISH_HONDURAS 0x12
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_SPANISH_NICARAGUA 0x13
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_SPANISH_PUERTO_RICO 0x14
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_SWEDISH 0x01
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_SWEDISH_FINLAND 0x02
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_URDU_PAKISTAN 0x01
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_URDU_INDIA 0x02
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_UZBEK_LATIN 0x01
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANG_UZBEK_CYRILLIC 0x02

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਛਾਂਟੋ_DEFAULT 0x0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਛਾਂਟੋ_INVARIANT_MATH 0x1

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਛਾਂਟੋ_JAPANESE_XJIS 0x0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਛਾਂਟੋ_JAPANESE_UNICODE 0x1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਛਾਂਟੋ_JAPANESE_RADICALSTROKE 0x4

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਛਾਂਟੋ_CHINESE_BIG5 0x0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਛਾਂਟੋ_CHINESE_PRCP 0x0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਛਾਂਟੋ_CHINESE_UNICODE 0x1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਛਾਂਟੋ_CHINESE_PRC 0x2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਛਾਂਟੋ_CHINESE_BOPOMOFO 0x3

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਛਾਂਟੋ_KOREAN_KSC 0x0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਛਾਂਟੋ_KOREAN_UNICODE 0x1

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਛਾਂਟੋ_GERMAN_PHONE_BOOK 0x1

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਛਾਂਟੋ_HUNGARIAN_DEFAULT 0x0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਛਾਂਟੋ_HUNGARIAN_TECHNICAL 0x1

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਛਾਂਟੋ_GEORGIAN_TRADITIONAL 0x0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਛਾਂਟੋ_GEORGIAN_MODERN 0x1

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAKELANGID(p,s) ((((ਸ਼ਬਦ_3)(s)) << 10) | (ਸ਼ਬਦ_3)(p))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIMARYLANGID(lgid) ((ਸ਼ਬਦ_3)(lgid) & 0x3ff)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUBLANGID(lgid) ((ਸ਼ਬਦ_3)(lgid) >> 10)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NLS_VALID_LOCALE_ਨਕਾਬ 0x000fffff

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAKELCID(lgid,srtid) ((DWORD)((((DWORD)((ਸ਼ਬਦ_3)(srtid))) << 16) | ((DWORD)((ਸ਼ਬਦ_3)(lgid)))))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAKESORTLCID(lgid,srtid,ver) ((DWORD)((MAKELCID(lgid,srtid)) | (((DWORD)((ਸ਼ਬਦ_3)(ver))) << 20)))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANGIDFROMLCID(lcid) ((ਸ਼ਬਦ_3)(lcid))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SORTIDFROMLCID(lcid) ((ਸ਼ਬਦ_3)((((DWORD)(lcid)) >> 16) & 0xf))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SORTVERSIONFROMLCID(lcid) ((ਸ਼ਬਦ_3)((((DWORD)(lcid)) >> 20) & 0xf))

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LOCALE_NAME_MAX_ਲੰਮਾਈ 85
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_SYSTEM_DEFAULT (MAKELANGID(LANG_NEUTRAL,SUBLANG_SYS_DEFAULT))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LANG_USER_DEFAULT (MAKELANGID(LANG_NEUTRAL,SUBLANG_DEFAULT))

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LOCALE_SYSTEM_DEFAULT (MAKELCID(LANG_SYSTEM_DEFAULT,ਛਾਂਟੋ_DEFAULT))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LOCALE_USER_DEFAULT (MAKELCID(LANG_USER_DEFAULT,ਛਾਂਟੋ_DEFAULT))

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LOCALE_NEUTRAL (MAKELCID(MAKELANGID(LANG_NEUTRAL,SUBLANG_NEUTRAL),ਛਾਂਟੋ_DEFAULT))

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LOCALE_CUSTOM_DEFAULT (MAKELCID(MAKELANGID(LANG_NEUTRAL, SUBLANG_CUSTOM_DEFAULT), ਛਾਂਟੋ_DEFAULT))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LOCALE_CUSTOM_UNSPECIFIED (MAKELCID(MAKELANGID(LANG_NEUTRAL, SUBLANG_CUSTOM_UNSPECIFIED), ਛਾਂਟੋ_DEFAULT))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LOCALE_CUSTOM_UI_DEFAULT (MAKELCID(MAKELANGID(LANG_NEUTRAL, SUBLANG_UI_CUSTOM_DEFAULT), ਛਾਂਟੋ_DEFAULT))

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LOCALE_INVARIANT (MAKELCID(MAKELANGID(LANG_INVARIANT,SUBLANG_NEUTRAL),ਛਾਂਟੋ_DEFAULT))

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UNREFERENCED_PARAMETER(P) (P)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DBG_UNREFERENCED_PARAMETER(P) (P)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DBG_UNREFERENCED_LOCAL_VARIABLE(V) (V)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DEFAULT_UNREACHABLE

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ WIN32_NO_ਸਥਿਤੀ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਥਿਤੀ_WAIT_0 ((DWORD)0x00000000L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਥਿਤੀ_ABANDONED_WAIT_0 ((DWORD)0x00000080L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਥਿਤੀ_USER_APC ((DWORD)0x000000C0L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਥਿਤੀ_TIMEOUT ((DWORD)0x00000102L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਥਿਤੀ_PENDING ((DWORD)0x00000103L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DBG_EXCEPTION_HANDLED ((DWORD)0x00010001L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DBG_CONTINUE ((DWORD)0x00010002L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਥਿਤੀ_SEGMENT_NOTIFICATION ((DWORD)0x40000005L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DBG_TERMINATE_THREAD ((DWORD)0x40010003L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DBG_TERMINATE_PROCESS ((DWORD)0x40010004L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DBG_CONTROL_C ((DWORD)0x40010005L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DBG_CONTROL_BREAK ((DWORD)0x40010008L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DBG_COMMAND_EXCEPTION ((DWORD)0x40010009L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਥਿਤੀ_GUARD_ਪੰਨਾ_VIOLATION ((DWORD)0x80000001L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਥਿਤੀ_DATATYPE_MISALIGNMENT ((DWORD)0x80000002L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਥਿਤੀ_BREAKPOINT ((DWORD)0x80000003L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਥਿਤੀ_SINGLE_ਕਦਮ ((DWORD)0x80000004L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DBG_EXCEPTION_NOT_HANDLED ((DWORD)0x80010001L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਥਿਤੀ_ACCESS_VIOLATION ((DWORD)0xC0000005L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਥਿਤੀ_ਵਿੱਚ_ਪੰਨਾ_ERROR ((DWORD)0xC0000006L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਥਿਤੀ_INVALID_HANDLE ((DWORD)0xC0000008L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਥਿਤੀ_NO_ਸਮ੍ਰਿਤੀ ((DWORD)0xC0000017L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਥਿਤੀ_ILLEGAL_INSTRUCTION ((DWORD)0xC000001DL)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਥਿਤੀ_NONCONTINUABLE_EXCEPTION ((DWORD)0xC0000025L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਥਿਤੀ_INVALID_DISPOSITION ((DWORD)0xC0000026L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਥਿਤੀ_ARRAY_BOUNDS_EXCEEDED ((DWORD)0xC000008CL)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਥਿਤੀ_FLOAT_DENORMAL_ਸੰਕਾਰਜ ((DWORD)0xC000008DL)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਥਿਤੀ_FLOAT_DIVIDE_BY_ZERO ((DWORD)0xC000008EL)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਥਿਤੀ_FLOAT_INEXACT_ਨਤੀਜਾ ((DWORD)0xC000008FL)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਥਿਤੀ_FLOAT_INVALID_OPERATION ((DWORD)0xC0000090L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਥਿਤੀ_FLOAT_ਉਛਾਲ ((DWORD)0xC0000091L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਥਿਤੀ_FLOAT_ਢੇਰ_CHECK ((DWORD)0xC0000092L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਥਿਤੀ_FLOAT_UNDERFLOW ((DWORD)0xC0000093L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਥਿਤੀ_INTEGER_DIVIDE_BY_ZERO ((DWORD)0xC0000094L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਥਿਤੀ_INTEGER_ਉਛਾਲ ((DWORD)0xC0000095L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਥਿਤੀ_PRIVILEGED_INSTRUCTION ((DWORD)0xC0000096L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਥਿਤੀ_ਢੇਰ_ਉਛਾਲ ((DWORD)0xC00000FDL)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਥਿਤੀ_CONTROL_C_EXIT ((DWORD)0xC000013AL)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਥਿਤੀ_FLOAT_ਗੁਣਜ_ਨੁਕਸ ((DWORD)0xC00002B4L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਥਿਤੀ_FLOAT_ਗੁਣਜ_TRAPS ((DWORD)0xC00002B5L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਥਿਤੀ_REG_NAT_CONSUMPTION ((DWORD)0xC00002C9L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਥਿਤੀ_SXS_EARLY_DEACTIVATION ((DWORD)0xC015000FL)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਥਿਤੀ_SXS_INVALID_DEACTIVATION ((DWORD)0xC0150010L)
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਵੱਧ_ਤੋਂ_ਵੱਧ_WAIT_OBJECTS 64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਵੱਧ_ਤੋਂ_ਵੱਧ_SUSPEND_ਗਿਣਤੀ MAXCHAR

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ULONG_PTR KSPIN_ਤਾਲਾ;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ KSPIN_ਤਾਲਾ *PKSPIN_ਤਾਲਾ;

#ਜੇ defined(__x86_64) && !defined(RC_INVOKED)

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
  ਬਾਹਰੀ "C" {
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਦੋਆਧਾਰੀ_ਅੰਕ_Test _bittest
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਦੋਆਧਾਰੀ_ਅੰਕ_Test_And_Complement _bittestandcomplement
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਦੋਆਧਾਰੀ_ਅੰਕ_Test_And_ਸੈੱਟ _bittestandset
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਦੋਆਧਾਰੀ_ਅੰਕ_Test_And_Reset _bittestandreset
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Interlocked_ਦੋਆਧਾਰੀ_ਅੰਕ_Test_And_ਸੈੱਟ _interlockedbittestandset
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Interlocked_ਦੋਆਧਾਰੀ_ਅੰਕ_Test_And_Reset _interlockedbittestandreset
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਦੋਆਧਾਰੀ_ਅੰਕ_Test64 _bittest64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਦੋਆਧਾਰੀ_ਅੰਕ_Test_And_Complement64 _bittestandcomplement64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਦੋਆਧਾਰੀ_ਅੰਕ_Test_And_Set64 _bittestandset64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਦੋਆਧਾਰੀ_ਅੰਕ_Test_And_Reset64 _bittestandreset64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Interlocked_ਦੋਆਧਾਰੀ_ਅੰਕ_Test_And_Set64 _interlockedbittestandset64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Interlocked_ਦੋਆਧਾਰੀ_ਅੰਕ_Test_And_Reset64 _interlockedbittestandreset64

    __CRT_INLINE BOOLEAN _bittest(LONG ਅਚਲ *ਅਧਾਰ_2,LONG ਵਿੱਥ_3) {
      ਪੂਰਨ old = 0;
      __asm__ __volatile__("btl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(ਅਸਥਿਰ ਲੰਮਾ *) ਅਧਾਰ_2))
	:"Ir" (ਵਿੱਥ_3));
      ਵਾਪਸ (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandcomplement(LONG *ਅਧਾਰ_2,LONG ਵਿੱਥ_3) {
      ਪੂਰਨ old = 0;
      __asm__ __volatile__("btcl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(ਅਸਥਿਰ ਲੰਮਾ *) ਅਧਾਰ_2))
	:"Ir" (ਵਿੱਥ_3));
      ਵਾਪਸ (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN Interlocked_ਦੋਆਧਾਰੀ_ਅੰਕ_Test_And_Complement(LONG *ਅਧਾਰ_2,LONG ਦੋਆਧਾਰੀ_ਅੰਕ_2) {
      ਪੂਰਨ old = 0;
      __asm__ __volatile__("lock ; btcl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(ਅਸਥਿਰ ਲੰਮਾ *) ਅਧਾਰ_2))
	:"Ir" (ਦੋਆਧਾਰੀ_ਅੰਕ_2));
      ਵਾਪਸ (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandset(LONG *ਅਧਾਰ_2,LONG ਵਿੱਥ_3) {
      ਪੂਰਨ old = 0;
      __asm__ __volatile__("btsl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(ਅਸਥਿਰ ਲੰਮਾ *) ਅਧਾਰ_2))
	:"Ir" (ਵਿੱਥ_3));
      ਵਾਪਸ (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandreset(LONG *ਅਧਾਰ_2,LONG ਵਿੱਥ_3) {
      ਪੂਰਨ old = 0;
      __asm__ __volatile__("btrl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(ਅਸਥਿਰ ਲੰਮਾ *) ਅਧਾਰ_2))
	:"Ir" (ਵਿੱਥ_3));
      ਵਾਪਸ (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _interlockedbittestandset(LONG *ਅਧਾਰ_2,LONG ਵਿੱਥ_3) {
      ਪੂਰਨ old = 0;
      __asm__ __volatile__("lock ; btsl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(ਅਸਥਿਰ ਲੰਮਾ *) ਅਧਾਰ_2))
	:"Ir" (ਵਿੱਥ_3));
      ਵਾਪਸ (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _interlockedbittestandreset(LONG *ਅਧਾਰ_2,LONG ਵਿੱਥ_3) {
      ਪੂਰਨ old = 0;
      __asm__ __volatile__("lock ; btrl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(ਅਸਥਿਰ ਲੰਮਾ *) ਅਧਾਰ_2))
	:"Ir" (ਵਿੱਥ_3));
      ਵਾਪਸ (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittest64(LONG64 ਅਚਲ *ਅਧਾਰ_2,LONG64 ਵਿੱਥ_3) {
      ਪੂਰਨ old = 0;
      __asm__ __volatile__("btq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(ਅਸਥਿਰ ਲੰਮਾ ਲੰਮਾ *) ਅਧਾਰ_2))
	:"Ir" (ਵਿੱਥ_3));
      ਵਾਪਸ (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandcomplement64(LONG64 *ਅਧਾਰ_2,LONG64 ਵਿੱਥ_3) {
      ਪੂਰਨ old = 0;
      __asm__ __volatile__("btcq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(ਅਸਥਿਰ ਲੰਮਾ ਲੰਮਾ *) ਅਧਾਰ_2))
	:"Ir" (ਵਿੱਥ_3));
      ਵਾਪਸ (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandset64(LONG64 *ਅਧਾਰ_2,LONG64 ਵਿੱਥ_3) {
      ਪੂਰਨ old = 0;
      __asm__ __volatile__("btsq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(ਅਸਥਿਰ ਲੰਮਾ ਲੰਮਾ *) ਅਧਾਰ_2))
	:"Ir" (ਵਿੱਥ_3));
      ਵਾਪਸ (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandreset64(LONG64 *ਅਧਾਰ_2,LONG64 ਵਿੱਥ_3) {
      ਪੂਰਨ old = 0;
      __asm__ __volatile__("btrq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(ਅਸਥਿਰ ਲੰਮਾ ਲੰਮਾ *) ਅਧਾਰ_2))
	:"Ir" (ਵਿੱਥ_3));
      ਵਾਪਸ (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _interlockedbittestandset64(LONG64 *ਅਧਾਰ_2,LONG64 ਵਿੱਥ_3) {
      ਪੂਰਨ old = 0;
      __asm__ __volatile__("lock ; btsq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(ਅਸਥਿਰ ਲੰਮਾ ਲੰਮਾ *) ਅਧਾਰ_2))
	:"Ir" (ਵਿੱਥ_3));
      ਵਾਪਸ (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _interlockedbittestandreset64(LONG64 *ਅਧਾਰ_2,LONG64 ਵਿੱਥ_3) {
      ਪੂਰਨ old = 0;
      __asm__ __volatile__("lock ; btrq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(ਅਸਥਿਰ ਲੰਮਾ ਲੰਮਾ *) ਅਧਾਰ_2))
	:"Ir" (ਵਿੱਥ_3));
      ਵਾਪਸ (BOOLEAN) (old!=0);
    }
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਦੋਆਧਾਰੀ_ਅੰਕ_ਜਾਂਚ_Forward ਦੋਆਧਾਰੀ_ਅੰਕ_ਜਾਂਚ_Forward_2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਦੋਆਧਾਰੀ_ਅੰਕ_ਜਾਂਚ_ਉਲਟ ਦੋਆਧਾਰੀ_ਅੰਕ_ਜਾਂਚ_ਉਲਟ_2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਦੋਆਧਾਰੀ_ਅੰਕ_ਜਾਂਚ_Forward64 ਦੋਆਧਾਰੀ_ਅੰਕ_ਜਾਂਚ_Forward64_2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਦੋਆਧਾਰੀ_ਅੰਕ_ਜਾਂਚ_Reverse64 ਦੋਆਧਾਰੀ_ਅੰਕ_ਜਾਂਚ_Reverse64_2

    __CRT_INLINE BOOLEAN ਦੋਆਧਾਰੀ_ਅੰਕ_ਜਾਂਚ_Forward_2(DWORD *ਸੂਚਕਾਂਕ_3,DWORD ਨਕਾਬ_3) {
      __asm__ __volatile__("bsfl %1,%0" : "=r" (ਨਕਾਬ_3),"=m" ((*(ਅਸਥਿਰ ਲੰਮਾ *)ਸੂਚਕਾਂਕ_3)));
      ਵਾਪਸ ਨਕਾਬ_3!=0;
    }
    __CRT_INLINE BOOLEAN ਦੋਆਧਾਰੀ_ਅੰਕ_ਜਾਂਚ_ਉਲਟ_2(DWORD *ਸੂਚਕਾਂਕ_3,DWORD ਨਕਾਬ_3) {
      __asm__ __volatile__("bsrl %1,%0" : "=r" (ਨਕਾਬ_3),"=m" ((*(ਅਸਥਿਰ ਲੰਮਾ *)ਸੂਚਕਾਂਕ_3)));
      ਵਾਪਸ ਨਕਾਬ_3!=0;
    }
    __CRT_INLINE BOOLEAN ਦੋਆਧਾਰੀ_ਅੰਕ_ਜਾਂਚ_Forward64_2(DWORD *ਸੂਚਕਾਂਕ_3,DWORD64 ਨਕਾਬ_3) {
      __asm__ __volatile__("bsfq %1,%0" : "=r" (ਨਕਾਬ_3),"=m" ((*(ਅਸਥਿਰ ਲੰਮਾ ਲੰਮਾ *)ਸੂਚਕਾਂਕ_3)));
      ਵਾਪਸ ਨਕਾਬ_3!=0;
    }
    __CRT_INLINE BOOLEAN ਦੋਆਧਾਰੀ_ਅੰਕ_ਜਾਂਚ_Reverse64_2(DWORD *ਸੂਚਕਾਂਕ_3,DWORD64 ਨਕਾਬ_3) {
      __asm__ __volatile__("bsrq %1,%0" : "=r" (ਨਕਾਬ_3),"=m" ((*(ਅਸਥਿਰ ਲੰਮਾ ਲੰਮਾ *)ਸੂਚਕਾਂਕ_3)));
      ਵਾਪਸ ਨਕਾਬ_3!=0;
    }

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedIncrement16 _InterlockedIncrement16
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedDecrement16 _InterlockedDecrement16
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedCompareExchange16 _InterlockedCompareExchange16

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedAnd _InterlockedAnd
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedOr _InterlockedOr
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedXor _InterlockedXor
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedIncrement _InterlockedIncrement
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedIncrementAcquire InterlockedIncrement
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedIncrementRelease InterlockedIncrement
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedDecrement _InterlockedDecrement
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedDecrementAcquire InterlockedDecrement
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedDecrementRelease InterlockedDecrement
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Interlocked_ਜੋੜੋ Interlocked_ਜੋੜੋ_2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedExchange _InterlockedExchange
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Interlocked_Exchange_ਜੋੜੋ Interlocked_Exchange_ਜੋੜੋ_2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedCompareExchange _InterlockedCompareExchange
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedCompareExchangeAcquire InterlockedCompareExchange
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedCompareExchangeRelease InterlockedCompareExchange

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedAnd64 _InterlockedAnd64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedAndAffinity InterlockedAnd64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedOr64 _InterlockedOr64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedOrAffinity InterlockedOr64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedXor64 _InterlockedXor64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedIncrement64 _InterlockedIncrement64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedDecrement64 _InterlockedDecrement64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedAdd64 _InterlockedAdd64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedExchange64 _InterlockedExchange64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedExchangeAcquire64 InterlockedExchange64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedExchangeAdd64 _InterlockedExchangeAdd64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedCompareExchange64 _InterlockedCompareExchange64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedCompareExchangeAcquire64 InterlockedCompareExchange64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedCompareExchangeRelease64 InterlockedCompareExchange64

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Interlocked_Exchange_ਸੂਚਕ Interlocked_Exchange_ਸੂਚਕ_2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Interlocked_Compare_Exchange_ਸੂਚਕ Interlocked_Compare_Exchange_ਸੂਚਕ_2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Interlocked_Compare_Exchange_ਸੂਚਕ_Acquire Interlocked_Compare_Exchange_ਸੂਚਕ_2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Interlocked_Compare_Exchange_ਸੂਚਕ_Release Interlocked_Compare_Exchange_ਸੂਚਕ_2

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Interlocked_Exchange_ਜੋੜੋ_ਮਾਪ_T(a,b) InterlockedExchangeAdd64((LONG64 *)a,b)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Interlocked_Increment_ਮਾਪ_T(a) InterlockedIncrement64((LONG64 *)a)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Interlocked_Decrement_ਮਾਪ_T(a) InterlockedDecrement64((LONG64 *)a)

    __CRT_INLINE SHORT InterlockedIncrement16(SHORT ਅਸਥਿਰ *Addend) {
      ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ c;
      ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ s;
      __asm__ __volatile__(
	"lock ; addw $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      ਵਾਪਸ (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE SHORT InterlockedDecrement16(SHORT ਅਸਥਿਰ *Addend) {
      ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ c;
      ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ s;
      __asm__ __volatile__(
	"lock ; subw $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      ਵਾਪਸ (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE SHORT InterlockedCompareExchange16(SHORT ਅਸਥਿਰ *Destination,SHORT ExChange,SHORT Comperand) {
      SHORT prev;
      __asm__ __volatile__("lock ; cmpxchgw %w1,%2"
	:"=a"(prev)
	:"q"(ExChange), "m"(*Destination), "0"(Comperand)
	: "memory");
      ਵਾਪਸ prev;
    }
    __CRT_INLINE LONG InterlockedAnd(LONG ਅਸਥਿਰ *Destination,LONG ਮੁੱਲ_3) {
      __asm__ __volatile__("lock ; andl %0,%1"
	: :"r"(ਮੁੱਲ_3),"m"(*Destination)
	: "memory");
      ਵਾਪਸ *Destination;
    }
    __CRT_INLINE LONG InterlockedOr(LONG ਅਸਥਿਰ *Destination,LONG ਮੁੱਲ_3) {
      __asm__ __volatile__("lock ; orl %0,%1"
	: : "r"(ਮੁੱਲ_3),"m"(*Destination) : "memory");
      ਵਾਪਸ *Destination;
    }
    __CRT_INLINE LONG InterlockedXor(LONG ਅਸਥਿਰ *Destination,LONG ਮੁੱਲ_3) {
      __asm__ __volatile__("lock ; xorl %0,%1"
	: : "r"(ਮੁੱਲ_3),"m"(*Destination) : "memory");
      ਵਾਪਸ *Destination;
    }
    //		$$$$
    __CRT_INLINE LONG64 InterlockedAnd64(LONG64 ਅਸਥਿਰ *Destination,LONG64 ਮੁੱਲ_3) {
      __asm__ __volatile__("lock ; andq %0,%1"
	: : "r"(ਮੁੱਲ_3),"m"(*Destination) : "memory");
      ਵਾਪਸ *Destination;
    }
    __CRT_INLINE LONG64 InterlockedOr64(LONG64 ਅਸਥਿਰ *Destination,LONG64 ਮੁੱਲ_3) {
      __asm__ __volatile__("lock ; orq %0,%1"
	: : "r"(ਮੁੱਲ_3),"m"(*Destination) : "memory");
      ਵਾਪਸ *Destination;
    }
    __CRT_INLINE LONG64 InterlockedXor64(LONG64 ਅਸਥਿਰ *Destination,LONG64 ਮੁੱਲ_3) {
      __asm__ __volatile__("lock ; xorq %0,%1"
	: : "r"(ਮੁੱਲ_3),"m"(*Destination) : "memory");
      ਵਾਪਸ *Destination;
    }
    __CRT_INLINE LONG InterlockedIncrement(LONG ਅਸਥਿਰ *Addend) {
      ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ c;
      ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ s;
      __asm__ __volatile__(
	"lock ; addl $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      ਵਾਪਸ (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE LONG InterlockedDecrement(LONG ਅਸਥਿਰ *Addend) {
      ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ c;
      ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ s;
      __asm__ __volatile__(
	"lock ; subl $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      ਵਾਪਸ (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE LONG InterlockedExchange(LONG ਅਸਥਿਰ *ਨਿਸ਼ਾਨਾ_2,LONG ਮੁੱਲ_3) {
      __asm__ __volatile("lock ; xchgl %0,%1"
	: "=r"(ਮੁੱਲ_3)
	: "m"(*ਨਿਸ਼ਾਨਾ_2),"0"(ਮੁੱਲ_3)
	: "memory");
      ਵਾਪਸ ਮੁੱਲ_3;
    }
    LONG Interlocked_Exchange_ਜੋੜੋ(LONG ਅਸਥਿਰ *Addend,LONG ਮੁੱਲ_3);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _X86AMD64_
    __CRT_INLINE LONG Interlocked_ਜੋੜੋ(LONG ਅਸਥਿਰ *Addend,LONG ਮੁੱਲ_3) { ਵਾਪਸ Interlocked_Exchange_ਜੋੜੋ(Addend,ਮੁੱਲ_3) + ਮੁੱਲ_3; }
#ਜੇ_ਅੰਤ
    __CRT_INLINE LONG InterlockedCompareExchange(LONG ਅਸਥਿਰ *Destination,LONG ExChange,LONG Comperand) {
      LONG prev;
      __asm__ __volatile__("lock ; cmpxchgl %1,%2" : "=a" (prev) : "q" (ExChange),"m" (*Destination), "0" (Comperand) : "memory");
      ਵਾਪਸ prev;
    }
    __CRT_INLINE LONG64 InterlockedIncrement64(LONG64 ਅਸਥਿਰ *Addend) {
      ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ c;
      ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ s;
      __asm__ __volatile__(
	"lock ; addq $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      ਵਾਪਸ (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE LONG64 InterlockedDecrement64(LONG64 ਅਸਥਿਰ *Addend) {
      ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ c;
      ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ s;
      __asm__ __volatile__(
	"lock ; subq $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      ਵਾਪਸ (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE LONG64 InterlockedExchange64(LONG64 ਅਸਥਿਰ *ਨਿਸ਼ਾਨਾ_2,LONG64 ਮੁੱਲ_3) {
      __asm__ __volatile("lock ; xchgq %0,%1"
	: "=r"(ਮੁੱਲ_3)
	: "m"(*ਨਿਸ਼ਾਨਾ_2),"0"(ਮੁੱਲ_3)
	: "memory");
      ਵਾਪਸ ਮੁੱਲ_3;
    }
    LONG64 InterlockedExchangeAdd64(LONG64 ਅਸਥਿਰ *Addend,LONG64 ਮੁੱਲ_3);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _X86AMD64_
    __CRT_INLINE LONG64 InterlockedAdd64(LONG64 ਅਸਥਿਰ *Addend,LONG64 ਮੁੱਲ_3) { ਵਾਪਸ InterlockedExchangeAdd64(Addend,ਮੁੱਲ_3) + ਮੁੱਲ_3; }
#ਜੇ_ਅੰਤ

    __CRT_INLINE LONG64 InterlockedCompareExchange64(LONG64 ਅਸਥਿਰ *Destination,LONG64 ExChange,LONG64 Comperand) {
      LONG64 prev;
      __asm__ __volatile__("lock ; cmpxchgq %1,%2" : "=a" (prev) : "q" (ExChange),"m" (*Destination), "0" (Comperand) : "memory");
      ਵਾਪਸ prev;
    }
    __CRT_INLINE PVOID Interlocked_Compare_Exchange_ਸੂਚਕ(PVOID ਅਸਥਿਰ *Destination,PVOID ExChange,PVOID Comperand) {
      PVOID prev;
      __asm__ __volatile__("lock ; cmpxchgq %1,%2" : "=a" (prev) : "q" (ExChange),"m" (*Destination), "0" (Comperand) : "memory");
      ਵਾਪਸ prev;
    }
    __CRT_INLINE PVOID Interlocked_Exchange_ਸੂਚਕ(PVOID ਅਸਥਿਰ *ਨਿਸ਼ਾਨਾ_2,PVOID ਮੁੱਲ_3) {
      __asm__ __volatile("lock ; xchgq %0,%1"
	: "=r"(ਮੁੱਲ_3)
	: "m"(*ਨਿਸ਼ਾਨਾ_2),"0"(ਮੁੱਲ_3)
	: "memory");
      ਵਾਪਸ ਮੁੱਲ_3;
    }

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Cache_ਸਤਰ_Flush(ਪਤਾ_2) _mm_clflush(ਪਤਾ_2)

    VOID _ReadWriteBarrier(VOID);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FastFence __faststorefence
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਦੋ_Fence _mm_lfence
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਮ੍ਰਿਤੀ_Fence _mm_mfence
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ StoreFence _mm_sfence

    VOID __faststorefence(VOID);
    VOID _m_prefetchw(ਅਸਥਿਰ CONST VOID *ਸਰੋਤ_2);

//!__TINYC__: #include <intrin.h>

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ YieldProcessor _mm_pause
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਮ੍ਰਿਤੀ_Barrier __faststorefence
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Pre_Fetch_Cache_ਸਤਰ(l,a) _mm_prefetch((CHAR CONST *) a,l)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PrefetchForWrite(p) _m_prefetchw(p)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ReadForWriteAccess(p) (_m_prefetchw(p),*(p))

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PF_TEMPORAL_LEVEL_1 _MM_HINT_T0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PF_TEMPORAL_LEVEL_2 _MM_HINT_T1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PF_TEMPORAL_LEVEL_3 _MM_HINT_T2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PF_NON_TEMPORAL_LEVEL_ALL _MM_HINT_NTA

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ReadMxCsr _mm_getcsr
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WriteMxCsr _mm_setcsr

    VOID __int2c(VOID);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DbgRaiseAssertionFailure() __int2c()
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetCallersEflags() __getcallerseflags()

    ਬਿਨਾਨਿਸ਼ਾਨੀ __int32 __getcallerseflags(VOID);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_Segment_ਹੱਦਬੰਦੀ __segmentlimit

    DWORD __segmentlimit(DWORD Selector);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Read_ਸਮਾਂ_Stamp_Counter() __rdtsc()

    DWORD64 __rdtsc(VOID);
    VOID __movsb(PBYTE Destination,BYTE ਅਚਲ *ਸਰੋਤ_2,ਮਾਪ_T ਗਿਣਤੀ_4);
    VOID __movsw(PWORD Destination,ਸ਼ਬਦ_3 ਅਚਲ *ਸਰੋਤ_2,ਮਾਪ_T ਗਿਣਤੀ_4);
    VOID __movsd(PDWORD Destination,DWORD ਅਚਲ *ਸਰੋਤ_2,ਮਾਪ_T ਗਿਣਤੀ_4);
    VOID __movsq(PDWORD64 Destination,DWORD64 ਅਚਲ *ਸਰੋਤ_2,ਮਾਪ_T ਗਿਣਤੀ_4);
    VOID __stosb(PBYTE Destination,BYTE ਮੁੱਲ_3,ਮਾਪ_T ਗਿਣਤੀ_4);
    VOID __stosw(PWORD Destination,ਸ਼ਬਦ_3 ਮੁੱਲ_3,ਮਾਪ_T ਗਿਣਤੀ_4);
    VOID __stosd(PDWORD Destination,DWORD ਮੁੱਲ_3,ਮਾਪ_T ਗਿਣਤੀ_4);
    VOID __stosq(PDWORD64 Destination,DWORD64 ਮੁੱਲ_3,ਮਾਪ_T ਗਿਣਤੀ_4);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Multiply_ਉੱਚਾ __mulh
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Unsigned_Multiply_ਉੱਚਾ __umulh

    LONGLONG Multiply_ਉੱਚਾ(LONGLONG Multiplier,LONGLONG Multiplicand);
    ULONGLONG Unsigned_Multiply_ਉੱਚਾ(ULONGLONG Multiplier,ULONGLONG Multiplicand);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਖਿਸਕਾਓ_Left128 __shiftleft128
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਖਿਸਕਾਓ_Right128 __shiftright128

    DWORD64 ਖਿਸਕਾਓ_Left128(DWORD64 ਨੀਵਾਂ_Part,DWORD64 ਉੱਚਾ_Part,BYTE ਖਿਸਕਾਓ_3);
    DWORD64 ਖਿਸਕਾਓ_Right128(DWORD64 ਨੀਵਾਂ_Part,DWORD64 ਉੱਚਾ_Part,BYTE ਖਿਸਕਾਓ_3);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Multiply128 _mul128

    LONG64 Multiply128(LONG64 Multiplier,LONG64 Multiplicand,LONG64 *ਉੱਚਾ_ਗੁਣਨਫਲ);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UnsignedMultiply128 _umul128

    DWORD64 UnsignedMultiply128(DWORD64 Multiplier,DWORD64 Multiplicand,DWORD64 *ਉੱਚਾ_ਗੁਣਨਫਲ);

    __CRT_INLINE LONG64 MultiplyExtract128(LONG64 Multiplier,LONG64 Multiplicand,BYTE ਖਿਸਕਾਓ_3) {
      LONG64 extracted_ਗੁਣਨਫਲ;
      LONG64 ਉੱਚਾ_ਗੁਣਨਫਲ_2;
      LONG64 ਨੀਵਾਂ_ਗੁਣਨਫਲ;
      ਨੀਵਾਂ_ਗੁਣਨਫਲ = Multiply128(Multiplier,Multiplicand,&ਉੱਚਾ_ਗੁਣਨਫਲ_2);
      extracted_ਗੁਣਨਫਲ = (LONG64)ਖਿਸਕਾਓ_Right128((LONG64)ਨੀਵਾਂ_ਗੁਣਨਫਲ,(LONG64)ਉੱਚਾ_ਗੁਣਨਫਲ_2,ਖਿਸਕਾਓ_3);
      ਵਾਪਸ extracted_ਗੁਣਨਫਲ;
    }

    __CRT_INLINE DWORD64 UnsignedMultiplyExtract128(DWORD64 Multiplier,DWORD64 Multiplicand,BYTE ਖਿਸਕਾਓ_3) {
      DWORD64 extracted_ਗੁਣਨਫਲ;
      DWORD64 ਉੱਚਾ_ਗੁਣਨਫਲ_2;
      DWORD64 ਨੀਵਾਂ_ਗੁਣਨਫਲ;
      ਨੀਵਾਂ_ਗੁਣਨਫਲ = UnsignedMultiply128(Multiplier,Multiplicand,&ਉੱਚਾ_ਗੁਣਨਫਲ_2);
      extracted_ਗੁਣਨਫਲ = ਖਿਸਕਾਓ_Right128(ਨੀਵਾਂ_ਗੁਣਨਫਲ,ਉੱਚਾ_ਗੁਣਨਫਲ_2,ਖਿਸਕਾਓ_3);
      ਵਾਪਸ extracted_ਗੁਣਨਫਲ;
    }

    __CRT_INLINE BYTE __readgsbyte(DWORD ਵਿੱਥ_3) {
      BYTE ret;
      __asm__ ਅਸਥਿਰ ("movb	%%gs:%1,%0"
	: "=r" (ret) ,"=m" ((*(ਅਸਥਿਰ ਲੰਮਾ *) (DWORD64) ਵਿੱਥ_3)));
      ਵਾਪਸ ret;
    }
    __CRT_INLINE ਸ਼ਬਦ_3 __readgsword(DWORD ਵਿੱਥ_3) {
      ਸ਼ਬਦ_3 ret;
      __asm__ ਅਸਥਿਰ ("movw	%%gs:%1,%0"
	: "=r" (ret) ,"=m" ((*(ਅਸਥਿਰ ਲੰਮਾ *) (DWORD64) ਵਿੱਥ_3)));
      ਵਾਪਸ ret;
    }
    __CRT_INLINE DWORD __readgsdword(DWORD ਵਿੱਥ_3) {
      DWORD ret;
      __asm__ ਅਸਥਿਰ ("movl	%%gs:%1,%0"
	: "=r" (ret) ,"=m" ((*(ਅਸਥਿਰ ਲੰਮਾ *) (DWORD64) ਵਿੱਥ_3)));
      ਵਾਪਸ ret;
    }
    __CRT_INLINE DWORD64 __readgsqword(DWORD ਵਿੱਥ_3) {
      ਖਾਲੀ *ret;
      __asm__ ਅਸਥਿਰ ("movq	%%gs:%1,%0"
	: "=r" (ret) ,"=m" ((*(ਅਸਥਿਰ ਲੰਮਾ *) (DWORD64) ਵਿੱਥ_3)));
      ਵਾਪਸ (DWORD64) ret;
    }
    __CRT_INLINE VOID __writegsbyte(DWORD ਵਿੱਥ_3,BYTE ਅੰਕੜੇ_3) {
      __asm__ ਅਸਥਿਰ ("movb	%0,%%gs:%1"
	: "=r" (ਅੰਕੜੇ_3) ,"=m" ((*(ਅਸਥਿਰ ਲੰਮਾ *) (DWORD64) ਵਿੱਥ_3)));
    }
    __CRT_INLINE VOID __writegsword(DWORD ਵਿੱਥ_3,ਸ਼ਬਦ_3 ਅੰਕੜੇ_3) {
      __asm__ ਅਸਥਿਰ ("movw	%0,%%gs:%1"
	: "=r" (ਅੰਕੜੇ_3) ,"=m" ((*(ਅਸਥਿਰ ਲੰਮਾ *) (DWORD64) ਵਿੱਥ_3)));
    }
    __CRT_INLINE VOID __writegsdword(DWORD ਵਿੱਥ_3,DWORD ਅੰਕੜੇ_3) {
      __asm__ ਅਸਥਿਰ ("movl	%0,%%gs:%1"
	: "=r" (ਅੰਕੜੇ_3) ,"=m" ((*(ਅਸਥਿਰ ਲੰਮਾ *) (DWORD64) ਵਿੱਥ_3)));
    }
    __CRT_INLINE VOID __writegsqword(DWORD ਵਿੱਥ_3,DWORD64 ਅੰਕੜੇ_3) {
      __asm__ ਅਸਥਿਰ ("movq	%0,%%gs:%1"
	: "=r" (ਅੰਕੜੇ_3) ,"=m" ((*(ਅਸਥਿਰ ਲੰਮਾ *) (DWORD64) ਵਿੱਥ_3)));
    }

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
  }
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXCEPTION_READ_FAULT 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXCEPTION_WRITE_FAULT 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXCEPTION_EXECUTE_FAULT 8

#ਜੇ !defined(RC_INVOKED)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONTEXT_AMD64 0x100000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONTEXT_CONTROL (CONTEXT_AMD64 | 0x1L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONTEXT_INTEGER (CONTEXT_AMD64 | 0x2L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONTEXT_SEGMENTS (CONTEXT_AMD64 | 0x4L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONTEXT_FLOATING_ਬਿੰਦੂ (CONTEXT_AMD64 | 0x8L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONTEXT_DEBUG_REGISTERS (CONTEXT_AMD64 | 0x10L)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONTEXT_ਭਰਿਆ (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_FLOATING_ਬਿੰਦੂ)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONTEXT_ALL (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_SEGMENTS | CONTEXT_FLOATING_ਬਿੰਦੂ | CONTEXT_DEBUG_REGISTERS)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONTEXT_EXCEPTION_ਸਰਗਰਮ 0x8000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONTEXT_SERVICE_ਸਰਗਰਮ 0x10000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONTEXT_EXCEPTION_REQUEST 0x40000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONTEXT_EXCEPTION_REPORTING 0x80000000
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INITIAL_MXCSR 0x1f80
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INITIAL_FPCSR 0x027f

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ DECLSPEC_ALIGN(16) _M128A {
    ULONGLONG ਨੀਵਾਂ_3;
    LONGLONG ਉੱਚਾ_3;
  } M128A,*PM128A;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _XMM_SAVE_AREA32 {
    ਸ਼ਬਦ_3 Control_ਸ਼ਬਦ;
    ਸ਼ਬਦ_3 ਸਥਿਤੀ_ਸ਼ਬਦ;
    BYTE ਟੈਗ_ਸ਼ਬਦ;
    BYTE Reserved1;
    ਸ਼ਬਦ_3 ErrorOpcode;
    DWORD Error_ਵਿੱਥ;
    ਸ਼ਬਦ_3 ErrorSelector;
    ਸ਼ਬਦ_3 Reserved2;
    DWORD ਅੰਕੜੇ_ਵਿੱਥ_2;
    ਸ਼ਬਦ_3 ਅੰਕੜੇ_Selector;
    ਸ਼ਬਦ_3 Reserved3;
    DWORD MxCsr;
    DWORD Mx_Csr_ਨਕਾਬ;
    M128A FloatRegisters[8];
    M128A XmmRegisters[16];
    BYTE Reserved4[96];
  } XMM_SAVE_AREA32,*PXMM_SAVE_AREA32;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LEGACY_SAVE_AREA_ਲੰਮਾਈ ਆਕਾਰ(XMM_SAVE_AREA32)

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ DECLSPEC_ALIGN(16) _CONTEXT {
    DWORD64 P1Home;
    DWORD64 P2Home;
    DWORD64 P3Home;
    DWORD64 P4Home;
    DWORD64 P5Home;
    DWORD64 P6Home;
    DWORD ContextFlags;
    DWORD MxCsr;
    ਸ਼ਬਦ_3 SegCs;
    ਸ਼ਬਦ_3 SegDs;
    ਸ਼ਬਦ_3 SegEs;
    ਸ਼ਬਦ_3 SegFs;
    ਸ਼ਬਦ_3 SegGs;
    ਸ਼ਬਦ_3 SegSs;
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
    ਸੰਘ {
      XMM_SAVE_AREA32 FltSave;
      XMM_SAVE_AREA32 FloatSave;
      ਬਣਤਰ {
	M128A ਸਿਰਲੇਖ_2[2];
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
    M128A ਸਦਿਸ਼_ਰਜਿਸਟਰ[26];
    DWORD64 ਸਦਿਸ਼_Control;
    DWORD64 DebugControl;
    DWORD64 ਆਖਰੀ_Branch_ਮੰਜ਼ਿਲ_Rip;
    DWORD64 ਆਖਰੀ_Branch_From_Rip;
    DWORD64 ਆਖਰੀ_Exception_ਮੰਜ਼ਿਲ_Rip;
    DWORD64 ਆਖਰੀ_Exception_From_Rip;
  } CONTEXT,*PCONTEXT;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RUNTIME_FUNCTION_ਅਸਿੱਧਾ 0x1

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _RUNTIME_FUNCTION {
    DWORD Begin_ਪਤਾ;
    DWORD ਸਿਰਾ_ਪਤਾ;
    DWORD Unwind_ਅੰਕੜੇ;
  } RUNTIME_FUNCTION,*PRUNTIME_FUNCTION;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PRUNTIME_FUNCTION (*PGET_RUNTIME_FUNCTION_CALLBACK)(DWORD64 ControlPc,PVOID Context);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ DWORD (*POUT_ਦਾ_PROCESS_FUNCTION_ਸਾਰਣੀ_CALLBACK)(HANDLE Process,PVOID ਸਾਰਣੀ_ਪਤਾ,PDWORD Entries,PRUNTIME_FUNCTION *Functions);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਬਾਹਰਲਾ_ਦਾ_PROCESS_FUNCTION_ਸਾਰਣੀ_CALLBACK_EXPORT_NAME "OutOfProcessFunctionTableCallback"
#ਜੇ_ਅੰਤ /* defined(__x86_64) && !defined(RC_INVOKED) */

#ਜੇ defined(__TINYC__) && (defined(__aarch64__) || defined(__arm64__)) && !defined(RC_INVOKED)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __TCC_WINNT_ATOMIC_SEQ_CST 5
/* TCC lowers __atomic_compare_exchange's fourth argument as weak, but the
   ARM64 helper reads it as success_memorder.  Strong CAS passes weak == 0,
   so keep Interlocked's barriers explicit here. */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __TCC_WINNT_MEMORY_BARRIER() __asm__ __volatile__("dmb ish" : : : "memory")

/* This covers the LONG operations needed by TCC's semaphore code and the
   pointer helpers that winbase.h exposes through Interlocked pointer macros.
   Add local helpers before relying on increment/decrement, add/exchange-add,
   bitwise, or 64-bit Interlocked forms on Windows ARM64 with TCC. */

    __CRT_INLINE LONG InterlockedExchange(LONG ਅਸਥਿਰ *ਨਿਸ਼ਾਨਾ_2,LONG ਮੁੱਲ_3) {
      LONG Old;
      __atomic_load(ਨਿਸ਼ਾਨਾ_2,&Old,__TCC_WINNT_ATOMIC_SEQ_CST);
      __TCC_WINNT_MEMORY_BARRIER();
      ਜਦੋਂ (!__atomic_compare_exchange(ਨਿਸ਼ਾਨਾ_2,&Old,&ਮੁੱਲ_3,0,
	__TCC_WINNT_ATOMIC_SEQ_CST,__TCC_WINNT_ATOMIC_SEQ_CST))
	;
      __TCC_WINNT_MEMORY_BARRIER();
      ਵਾਪਸ Old;
    }
    __CRT_INLINE LONG InterlockedCompareExchange(LONG ਅਸਥਿਰ *Destination,LONG ExChange,LONG Comperand) {
      LONG Old = Comperand;
      __TCC_WINNT_MEMORY_BARRIER();
      __atomic_compare_exchange(Destination,&Old,&ExChange,0,
	__TCC_WINNT_ATOMIC_SEQ_CST,__TCC_WINNT_ATOMIC_SEQ_CST);
      __TCC_WINNT_MEMORY_BARRIER();
      ਵਾਪਸ Old;
    }
    __CRT_INLINE PVOID __TCC_WINNT_InterlockedExchangePointer(PVOID ਅਸਥਿਰ *ਨਿਸ਼ਾਨਾ_2,PVOID ਮੁੱਲ_3) {
      PVOID Old;
      __atomic_load(ਨਿਸ਼ਾਨਾ_2,&Old,__TCC_WINNT_ATOMIC_SEQ_CST);
      __TCC_WINNT_MEMORY_BARRIER();
      ਜਦੋਂ (!__atomic_compare_exchange(ਨਿਸ਼ਾਨਾ_2,&Old,&ਮੁੱਲ_3,0,
	__TCC_WINNT_ATOMIC_SEQ_CST,__TCC_WINNT_ATOMIC_SEQ_CST))
	;
      __TCC_WINNT_MEMORY_BARRIER();
      ਵਾਪਸ Old;
    }
    __CRT_INLINE PVOID __TCC_WINNT_InterlockedCompareExchangePointer(PVOID ਅਸਥਿਰ *Destination,PVOID ExChange,PVOID Comperand) {
      PVOID Old = Comperand;
      __TCC_WINNT_MEMORY_BARRIER();
      __atomic_compare_exchange(Destination,&Old,&ExChange,0,
	__TCC_WINNT_ATOMIC_SEQ_CST,__TCC_WINNT_ATOMIC_SEQ_CST);
      __TCC_WINNT_MEMORY_BARRIER();
      ਵਾਪਸ Old;
    }

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Interlocked_Exchange_ਸੂਚਕ __TCC_WINNT_InterlockedExchangePointer
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Interlocked_Compare_Exchange_ਸੂਚਕ __TCC_WINNT_InterlockedCompareExchangePointer
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Interlocked_Compare_Exchange_ਸੂਚਕ_Acquire Interlocked_Compare_Exchange_ਸੂਚਕ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Interlocked_Compare_Exchange_ਸੂਚਕ_Release Interlocked_Compare_Exchange_ਸੂਚਕ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedCompareExchangeAcquire InterlockedCompareExchange
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedCompareExchangeRelease InterlockedCompareExchange

#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ __TCC_WINNT_MEMORY_BARRIER
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ __TCC_WINNT_ATOMIC_SEQ_CST

#ਜੇ_ਅੰਤ /* defined(__TINYC__) && (defined(__aarch64__) || defined(__arm64__)) && !defined(RC_INVOKED) */

#ਜੇ defined(_ARM64_)

/* ARM64 Context Definition */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONTEXT_ARM64 0x00400000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONTEXT_CONTROL (CONTEXT_ARM64 | 0x00000001L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONTEXT_INTEGER (CONTEXT_ARM64 | 0x00000002L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONTEXT_FLOATING_ਬਿੰਦੂ (CONTEXT_ARM64 | 0x00000004L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONTEXT_DEBUG (CONTEXT_ARM64 | 0x00000008L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONTEXT_ਭਰਿਆ (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_FLOATING_ਬਿੰਦੂ)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONTEXT_ALL (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_FLOATING_ਬਿੰਦੂ | CONTEXT_DEBUG)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ARM64_MAX_BREAKPOINTS 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ARM64_MAX_WATCHPOINTS 2

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਸੰਘ _ARM64_NT_NEON128 {
    ਬਣਤਰ {
      ULONGLONG ਨੀਵਾਂ_3;
      LONGLONG ਉੱਚਾ_3;
    } DUMMYSTRUCTNAME;
    ਦੁੱਗਣਾ D[2];
    ਦਸ਼ਮਲਵ S[4];
    ਸ਼ਬਦ_3 H[8];
    BYTE B[16];
  } ARM64_NT_NEON128,*PARM64_NT_NEON128;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ DECLSPEC_ALIGN(16) _ARM64_NT_CONTEXT {
    ULONG ContextFlags;
    ULONG Cpsr;
    ਸੰਘ {
      ਬਣਤਰ {
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

  C_ASSERT(ਆਕਾਰ(ARM64_NT_CONTEXT) == 0x390);

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ARM64_NT_CONTEXT CONTEXT,*PCONTEXT;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _RUNTIME_FUNCTION {
    DWORD Begin_ਪਤਾ;
    DWORD Unwind_ਅੰਕੜੇ;
  } RUNTIME_FUNCTION,*PRUNTIME_FUNCTION;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PRUNTIME_FUNCTION (*PGET_RUNTIME_FUNCTION_CALLBACK)(DWORD64 ControlPc,PVOID Context);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ DWORD (*POUT_ਦਾ_PROCESS_FUNCTION_ਸਾਰਣੀ_CALLBACK)(HANDLE Process,PVOID ਸਾਰਣੀ_ਪਤਾ,PDWORD Entries,PRUNTIME_FUNCTION *Functions);

#ਜੇ_ਅੰਤ /* _ARM64_ */

#ਜੇ (defined _ARM64_ || defined _AMD64_) && !defined RC_INVOKED
  NTSYSAPI VOID __cdecl RtlRestoreContext (PCONTEXT Context_ਰਿਕਾਰਡ,ਬਣਤਰ EXCEPTION_ਰਿਕਾਰਡ *Exception_ਰਿਕਾਰਡ);
  NTSYSAPI BOOLEAN __cdecl Rtl_ਜੋੜੋ_Function_ਸਾਰਣੀ(PRUNTIME_FUNCTION Function_ਸਾਰਣੀ,DWORD ਇੰਦਰਾਜ_ਗਿਣਤੀ,DWORD64 ਅਧਾਰ_ਪਤਾ);
  NTSYSAPI BOOLEAN __cdecl Rtl_Install_Function_ਸਾਰਣੀ_Callback(DWORD64 ਸਾਰਣੀ_Identifier,DWORD64 ਅਧਾਰ_ਪਤਾ,DWORD ਲੰਮਾਈ_2,PGET_RUNTIME_FUNCTION_CALLBACK Callback,PVOID Context,PCWSTR ਬਾਹਰਲਾ_ਦਾ_Process_Callback_Dll);
  NTSYSAPI BOOLEAN __cdecl Rtl_Delete_Function_ਸਾਰਣੀ(PRUNTIME_FUNCTION Function_ਸਾਰਣੀ);
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ I_X86_
#ਜੇ(defined(_X86_) && !defined(__x86_64)) && !defined(RC_INVOKED)
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
  ਬਾਹਰੀ "C" {
#ਜੇ_ਅੰਤ

    __CRT_INLINE BOOLEAN Interlocked_ਦੋਆਧਾਰੀ_ਅੰਕ_Test_And_ਸੈੱਟ(LONG *ਅਧਾਰ_2,LONG ਦੋਆਧਾਰੀ_ਅੰਕ_2) {
      ਪੂਰਨ old = 0;
      __asm__ __volatile__("lock ; btsl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(ਅਸਥਿਰ ਲੰਮਾ *) ਅਧਾਰ_2))
	:"Ir" (ਦੋਆਧਾਰੀ_ਅੰਕ_2));
      ਵਾਪਸ (BOOLEAN) (old!=0);
    }

    __CRT_INLINE BOOLEAN Interlocked_ਦੋਆਧਾਰੀ_ਅੰਕ_Test_And_Reset(LONG *ਅਧਾਰ_2,LONG ਦੋਆਧਾਰੀ_ਅੰਕ_2) {
      ਪੂਰਨ old = 0;
      __asm__ __volatile__("lock ; btrl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(ਅਸਥਿਰ ਲੰਮਾ *) ਅਧਾਰ_2))
	:"Ir" (ਦੋਆਧਾਰੀ_ਅੰਕ_2));
      ਵਾਪਸ (BOOLEAN) (old!=0);
    }

    __CRT_INLINE BOOLEAN Interlocked_ਦੋਆਧਾਰੀ_ਅੰਕ_Test_And_Complement(LONG *ਅਧਾਰ_2,LONG ਦੋਆਧਾਰੀ_ਅੰਕ_2) {
      ਪੂਰਨ old = 0;
      __asm__ __volatile__("lock ; btcl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(ਅਸਥਿਰ ਲੰਮਾ *) ਅਧਾਰ_2))
	:"Ir" (ਦੋਆਧਾਰੀ_ਅੰਕ_2));
      ਵਾਪਸ (BOOLEAN) (old!=0);
    }

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ ਅਗੇਤਰ_2
    BYTE __readfsbyte(DWORD ਵਿੱਥ_3);
    ਸ਼ਬਦ_3 __readfsword(DWORD ਵਿੱਥ_3);
    DWORD __readfsdword(DWORD ਵਿੱਥ_3);
    VOID __writefsbyte(DWORD ਵਿੱਥ_3,BYTE ਅੰਕੜੇ_3);
    VOID __writefsword(DWORD ਵਿੱਥ_3,ਸ਼ਬਦ_3 ਅੰਕੜੇ_3);
    VOID __writefsdword(DWORD ਵਿੱਥ_3,DWORD ਅੰਕੜੇ_3);
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
  }
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ(defined(_X86_) && !defined(__x86_64))
  __CRT_INLINE VOID ਸਮ੍ਰਿਤੀ_Barrier(VOID) {
    LONG Barrier;
    __asm__ __volatile__("xchgl %%eax,%0 "
      :"=r" (Barrier));
  }
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ YieldProcessor() __asm__ __volatile__("rep nop ");

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Pre_Fetch_Cache_ਸਤਰ(l,a)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ReadForWriteAccess(p) (*(p))

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PF_TEMPORAL_LEVEL_1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PF_NON_TEMPORAL_LEVEL_ALL

  __CRT_INLINE VOID DbgRaiseAssertionFailure(ਖਾਲੀ) {
    __asm__ __volatile__("int $0x2c ");
  }
  PVOID GetCurrentFiber(ਖਾਲੀ);
  __CRT_INLINE PVOID GetCurrentFiber(ਖਾਲੀ)
  {
    ਖਾਲੀ *ret;
    __asm__ ਅਸਥਿਰ ("movl	%%fs:0x10,%0"
	: "=r" (ret));
    ਵਾਪਸ ret;
  }
  PVOID Get_Fiber_ਅੰਕੜੇ(ਖਾਲੀ);
  __CRT_INLINE PVOID Get_Fiber_ਅੰਕੜੇ(ਖਾਲੀ)
  {
    ਖਾਲੀ *ret;
    __asm__ ਅਸਥਿਰ ("movl	%%fs:0x10,%0\n"
	"movl	(%0),%0"
	: "=r" (ret));
    ਵਾਪਸ ret;
  }
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXCEPTION_READ_FAULT 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXCEPTION_WRITE_FAULT 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXCEPTION_EXECUTE_FAULT 8

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਮਾਪ_ਦਾ_80387_REGISTERS 80

#ਜੇ !defined(RC_INVOKED)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONTEXT_i386 0x00010000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONTEXT_i486 0x00010000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONTEXT_CONTROL (CONTEXT_i386 | 0x00000001L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONTEXT_INTEGER (CONTEXT_i386 | 0x00000002L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONTEXT_SEGMENTS (CONTEXT_i386 | 0x00000004L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONTEXT_FLOATING_ਬਿੰਦੂ (CONTEXT_i386 | 0x00000008L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONTEXT_DEBUG_REGISTERS (CONTEXT_i386 | 0x00000010L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONTEXT_EXTENDED_REGISTERS (CONTEXT_i386 | 0x00000020L)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONTEXT_ਭਰਿਆ (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_SEGMENTS)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONTEXT_ALL (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_SEGMENTS | CONTEXT_FLOATING_ਬਿੰਦੂ | CONTEXT_DEBUG_REGISTERS | CONTEXT_EXTENDED_REGISTERS)
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਵੱਧ_ਤੋਂ_ਵੱਧ_SUPPORTED_EXTENSION 512

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _FLOATING_SAVE_AREA {
      DWORD Control_ਸ਼ਬਦ;
      DWORD ਸਥਿਤੀ_ਸ਼ਬਦ;
      DWORD ਟੈਗ_ਸ਼ਬਦ;
      DWORD Error_ਵਿੱਥ;
      DWORD ErrorSelector;
      DWORD ਅੰਕੜੇ_ਵਿੱਥ_2;
      DWORD ਅੰਕੜੇ_Selector;
      BYTE ਰਜਿਸਟਰ_Area[ਮਾਪ_ਦਾ_80387_REGISTERS];
      DWORD Cr0NpxState;
    } FLOATING_SAVE_AREA;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ FLOATING_SAVE_AREA *PFLOATING_SAVE_AREA;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _CONTEXT {
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
      BYTE ExtendedRegisters[ਵੱਧ_ਤੋਂ_ਵੱਧ_SUPPORTED_EXTENSION];
    } CONTEXT;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ CONTEXT *PCONTEXT;
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ LDT_ਇੰਦਰਾਜ_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LDT_ਇੰਦਰਾਜ_DEFINED

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ LDT_ਇੰਦਰਾਜ {
      ਸ਼ਬਦ_3 ਹੱਦਬੰਦੀ_ਨੀਵਾਂ;
      ਸ਼ਬਦ_3 ਅਧਾਰ_ਨੀਵਾਂ;
      ਸੰਘ {
	ਬਣਤਰ {
	  BYTE ਅਧਾਰ_Mid;
	  BYTE Flags1;
	  BYTE Flags2;
	  BYTE ਅਧਾਰ_Hi;
	} ਬਾਈਟਾਂ_2;
	ਬਣਤਰ {
	  DWORD ਅਧਾਰ_Mid : 8;
	  DWORD Type : 5;
	  DWORD Dpl : 2;
	  DWORD Pres : 1;
	  DWORD ਹੱਦਬੰਦੀ_Hi : 4;
	  DWORD Sys : 1;
	  DWORD Reserved_0 : 1;
	  DWORD Default_Big : 1;
	  DWORD Granularity : 1;
	  DWORD ਅਧਾਰ_Hi : 8;
	} ਬਿੱਟ_2;
      } ਉੱਚਾ_ਸ਼ਬਦ;
    } LDT_ਇੰਦਰਾਜ_2,*PLDT_ਇੰਦਰਾਜ;
#ਜੇ_ਅੰਤ

#ਜੇ defined(__ia64__) && !defined(RC_INVOKED)

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
    ਬਾਹਰੀ "C" {
#ਜੇ_ਅੰਤ

      BOOLEAN ਦੋਆਧਾਰੀ_ਅੰਕ_ਜਾਂਚ_Forward64(DWORD *ਸੂਚਕਾਂਕ_3,DWORD64 ਨਕਾਬ_3);
      BOOLEAN ਦੋਆਧਾਰੀ_ਅੰਕ_ਜਾਂਚ_Reverse64(DWORD *ਸੂਚਕਾਂਕ_3,DWORD64 ਨਕਾਬ_3);

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
    }
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ !defined(GENUTIL) && !defined(_GENIA64_) && defined(_IA64_)

    ਖਾਲੀ *_cdecl _rdteb(ਖਾਲੀ);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __ia64__

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NtCurrentTeb() ((ਬਣਤਰ _TEB *)_rdteb())
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetCurrentFiber() (((PNT_TIB)NtCurrentTeb())->Fiber_ਅੰਕੜੇ)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_Fiber_ਅੰਕੜੇ() (*(PVOID *)(GetCurrentFiber()))

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
    ਬਾਹਰੀ "C" {
#ਜੇ_ਅੰਤ

      ਖਾਲੀ __break(ਪੂਰਨ);
      ਖਾਲੀ __yield(ਖਾਲੀ);
      ਖਾਲੀ __mf(ਖਾਲੀ);
      ਖਾਲੀ __lfetch(ਪੂਰਨ Level,VOID CONST *ਪਤਾ_2);
      ਖਾਲੀ __lfetchfault(ਪੂਰਨ Level,VOID CONST *ਪਤਾ_2);
      ਖਾਲੀ __lfetch_excl(ਪੂਰਨ Level,VOID CONST *ਪਤਾ_2);
      ਖਾਲੀ __lfetchfault_excl(ਪੂਰਨ Level,VOID CONST *ਪਤਾ_2);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MD_LFHINT_NONE 0x00
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MD_LFHINT_NT1 0x01
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MD_LFHINT_NT2 0x02
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MD_LFHINT_NTA 0x03

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
    }
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ YieldProcessor __yield
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਮ੍ਰਿਤੀ_Barrier __mf
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Pre_Fetch_Cache_ਸਤਰ __lfetch
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ReadForWriteAccess(p) (*(p))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DbgRaiseAssertionFailure() __break(ASSERT_BREAKPOINT)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PF_TEMPORAL_LEVEL_1 MD_LFHINT_NONE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PF_NON_TEMPORAL_LEVEL_ALL MD_LFHINT_NTA

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Unsigned_Multiply_ਉੱਚਾ __UMULH

    ULONGLONG Unsigned_Multiply_ਉੱਚਾ(ULONGLONG Multiplier,ULONGLONG Multiplicand);
#ਨਹੀਂਤਾਂ
    ਬਣਤਰ _TEB *NtCurrentTeb(ਖਾਲੀ);
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _IA64_

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXCEPTION_READ_FAULT 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXCEPTION_WRITE_FAULT 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXCEPTION_EXECUTE_FAULT 2

#ਜੇ !defined(RC_INVOKED)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONTEXT_IA64 0x00080000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONTEXT_CONTROL (CONTEXT_IA64 | 0x00000001L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONTEXT_ਹੇਠਲਾ_FLOATING_ਬਿੰਦੂ (CONTEXT_IA64 | 0x00000002L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONTEXT_HIGHER_FLOATING_ਬਿੰਦੂ (CONTEXT_IA64 | 0x00000004L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONTEXT_INTEGER (CONTEXT_IA64 | 0x00000008L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONTEXT_DEBUG (CONTEXT_IA64 | 0x00000010L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONTEXT_IA32_CONTROL (CONTEXT_IA64 | 0x00000020L)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONTEXT_FLOATING_ਬਿੰਦੂ (CONTEXT_ਹੇਠਲਾ_FLOATING_ਬਿੰਦੂ | CONTEXT_HIGHER_FLOATING_ਬਿੰਦੂ)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONTEXT_ਭਰਿਆ (CONTEXT_CONTROL | CONTEXT_FLOATING_ਬਿੰਦੂ | CONTEXT_INTEGER | CONTEXT_IA32_CONTROL)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONTEXT_ALL (CONTEXT_CONTROL | CONTEXT_FLOATING_ਬਿੰਦੂ | CONTEXT_INTEGER | CONTEXT_DEBUG | CONTEXT_IA32_CONTROL)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONTEXT_EXCEPTION_ਸਰਗਰਮ 0x8000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONTEXT_SERVICE_ਸਰਗਰਮ 0x10000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONTEXT_EXCEPTION_REQUEST 0x40000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONTEXT_EXCEPTION_REPORTING 0x80000000
#ਜੇ_ਅੰਤ

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _CONTEXT {
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

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _PLABEL_DESCRIPTOR {
      ULONGLONG ਇੰਦਰਾਜ_ਬਿੰਦੂ;
      ULONGLONG Global_ਸੂਚਕ_2;
    } PLABEL_DESCRIPTOR,*PPLABEL_DESCRIPTOR;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _RUNTIME_FUNCTION {
      DWORD Begin_ਪਤਾ;
      DWORD ਸਿਰਾ_ਪਤਾ;
      DWORD Unwind_Info_ਪਤਾ;
    } RUNTIME_FUNCTION,*PRUNTIME_FUNCTION;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ PRUNTIME_FUNCTION (*PGET_RUNTIME_FUNCTION_CALLBACK)(DWORD64 ControlPc,PVOID Context);
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ DWORD (*POUT_ਦਾ_PROCESS_FUNCTION_ਸਾਰਣੀ_CALLBACK)(HANDLE Process,PVOID ਸਾਰਣੀ_ਪਤਾ,PDWORD Entries,PRUNTIME_FUNCTION *Functions);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਬਾਹਰਲਾ_ਦਾ_PROCESS_FUNCTION_ਸਾਰਣੀ_CALLBACK_EXPORT_NAME "OutOfProcessFunctionTableCallback"

    BOOLEAN Rtl_ਜੋੜੋ_Function_ਸਾਰਣੀ(PRUNTIME_FUNCTION Function_ਸਾਰਣੀ,DWORD ਇੰਦਰਾਜ_ਗਿਣਤੀ,ULONGLONG ਅਧਾਰ_ਪਤਾ,ULONGLONG ਨਿਸ਼ਾਨਾ_Gp);
    BOOLEAN Rtl_Install_Function_ਸਾਰਣੀ_Callback(DWORD64 ਸਾਰਣੀ_Identifier,DWORD64 ਅਧਾਰ_ਪਤਾ,DWORD ਲੰਮਾਈ_2,DWORD64 ਨਿਸ਼ਾਨਾ_Gp,PGET_RUNTIME_FUNCTION_CALLBACK Callback,PVOID Context,PCWSTR ਬਾਹਰਲਾ_ਦਾ_Process_Callback_Dll);
    BOOLEAN Rtl_Delete_Function_ਸਾਰਣੀ(PRUNTIME_FUNCTION Function_ਸਾਰਣੀ);
    VOID RtlRestoreContext (PCONTEXT Context_ਰਿਕਾਰਡ,ਬਣਤਰ EXCEPTION_ਰਿਕਾਰਡ *Exception_ਰਿਕਾਰਡ);
    VOID __jump_unwind(ULONGLONG ਨਿਸ਼ਾਨਾ_Ms_ਚੌਖਟਾ,ULONGLONG ਨਿਸ਼ਾਨਾ_Bs_ਚੌਖਟਾ,ULONGLONG ਨਿਸ਼ਾਨਾ_Pc);
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXCEPTION_NONCONTINUABLE 0x1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXCEPTION_ਵੱਧ_ਤੋਂ_ਵੱਧ_PARAMETERS 15

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ EXCEPTION_ਰਿਕਾਰਡ {
      DWORD Exception_ਕੋਡ;
      DWORD ExceptionFlags;
      ਬਣਤਰ EXCEPTION_ਰਿਕਾਰਡ *Exception_ਰਿਕਾਰਡ;
      PVOID Exception_ਪਤਾ;
      DWORD ਸੰਖਿਆ_Parameters;
      ULONG_PTR ExceptionInformation[EXCEPTION_ਵੱਧ_ਤੋਂ_ਵੱਧ_PARAMETERS];
    } EXCEPTION_ਰਿਕਾਰਡ_2;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ EXCEPTION_ਰਿਕਾਰਡ_2 *PEXCEPTION_ਰਿਕਾਰਡ;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _EXCEPTION_RECORD32 {
      DWORD Exception_ਕੋਡ;
      DWORD ExceptionFlags;
      DWORD Exception_ਰਿਕਾਰਡ;
      DWORD Exception_ਪਤਾ;
      DWORD ਸੰਖਿਆ_Parameters;
      DWORD ExceptionInformation[EXCEPTION_ਵੱਧ_ਤੋਂ_ਵੱਧ_PARAMETERS];
    } EXCEPTION_RECORD32,*PEXCEPTION_RECORD32;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _EXCEPTION_RECORD64 {
      DWORD Exception_ਕੋਡ;
      DWORD ExceptionFlags;
      DWORD64 Exception_ਰਿਕਾਰਡ;
      DWORD64 Exception_ਪਤਾ;
      DWORD ਸੰਖਿਆ_Parameters;
      DWORD __unusedAlignment;
      DWORD64 ExceptionInformation[EXCEPTION_ਵੱਧ_ਤੋਂ_ਵੱਧ_PARAMETERS];
    } EXCEPTION_RECORD64,*PEXCEPTION_RECORD64;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ EXCEPTION_ਸੂਚਕ_ਸਾਰੇ_2 {
      PEXCEPTION_ਰਿਕਾਰਡ Exception_ਰਿਕਾਰਡ;
      PCONTEXT Context_ਰਿਕਾਰਡ;
    } EXCEPTION_ਸੂਚਕ_ਸਾਰੇ,*PEXCEPTION_ਸੂਚਕ_ਸਾਰੇ;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __x86_64

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ EXCEPTION_DISPOSITION NTAPI EXCEPTION_ROUTINE (ਬਣਤਰ EXCEPTION_ਰਿਕਾਰਡ *Exception_ਰਿਕਾਰਡ, PVOID Establisher_ਚੌਖਟਾ_2, ਬਣਤਰ _CONTEXT *Context_ਰਿਕਾਰਡ, PVOID DispatcherContext);
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __PEXCEPTION_ROUTINE_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __PEXCEPTION_ROUTINE_DEFINED
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ EXCEPTION_ROUTINE *PEXCEPTION_ROUTINE;
#ਜੇ_ਅੰਤ

    /* http://msdn.microsoft.com/en-us/library/ms680597(VS.85).aspx */

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UNWIND_HISTORY_ਸਾਰਣੀ_ਮਾਪ 12

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ UNWIND_HISTORY_ਸਾਰਣੀ_ਇੰਦਰਾਜ {
    ULONG64 Image_ਅਧਾਰ;
    PRUNTIME_FUNCTION Function_ਇੰਦਰਾਜ;
  } UNWIND_HISTORY_ਸਾਰਣੀ_ਇੰਦਰਾਜ_2, *PUNWIND_HISTORY_ਸਾਰਣੀ_ਇੰਦਰਾਜ;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UNWIND_HISTORY_ਸਾਰਣੀ_NONE    0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UNWIND_HISTORY_ਸਾਰਣੀ_GLOBAL  1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UNWIND_HISTORY_ਸਾਰਣੀ_LOCAL   2

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ UNWIND_HISTORY_ਸਾਰਣੀ {
    ULONG ਗਿਣਤੀ_4;
    UCHAR ਖੋਜ;
    ULONG64 ਨੀਵਾਂ_ਪਤਾ;
    ULONG64 ਉੱਚਾ_ਪਤਾ;
    UNWIND_HISTORY_ਸਾਰਣੀ_ਇੰਦਰਾਜ_2 ਇੰਦਰਾਜ[UNWIND_HISTORY_ਸਾਰਣੀ_ਮਾਪ];
  } UNWIND_HISTORY_ਸਾਰਣੀ_2, *PUNWIND_HISTORY_ਸਾਰਣੀ;

  /* http://msdn.microsoft.com/en-us/library/b6sf5kbd(VS.80).aspx */

  ਬਣਤਰ _DISPATCHER_CONTEXT;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _DISPATCHER_CONTEXT DISPATCHER_CONTEXT;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _DISPATCHER_CONTEXT *PDISPATCHER_CONTEXT;

  ਬਣਤਰ _DISPATCHER_CONTEXT {
    ULONG64 ControlPc;
    ULONG64 Image_ਅਧਾਰ;
    PRUNTIME_FUNCTION Function_ਇੰਦਰਾਜ;
    ULONG64 Establisher_ਚੌਖਟਾ_2;
    ULONG64 ਨਿਸ਼ਾਨਾ_Ip;
    PCONTEXT Context_ਰਿਕਾਰਡ;
    PEXCEPTION_ROUTINE LanguageHandler;
    PVOID Handler_ਅੰਕੜੇ;
    /* http://www.nynaeve.net/?p=99 */
    PUNWIND_HISTORY_ਸਾਰਣੀ History_ਸਾਰਣੀ;
    ULONG Scope_ਸੂਚਕਾਂਕ;
    ULONG Fill0;
  };

  /* http://msdn.microsoft.com/en-us/library/ms680617(VS.85).aspx */

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ KNONVOLATILE_CONTEXT_ਸੂਚਕ_ਸਾਰੇ
  {
    PM128A FloatingContext[16];
    PULONG64 IntegerContext[16];
  } KNONVOLATILE_CONTEXT_ਸੂਚਕ_ਸਾਰੇ_2, *PKNONVOLATILE_CONTEXT_ਸੂਚਕ_ਸਾਰੇ;
#ਜੇ_ਅੰਤ /* defined(__x86_64) */

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ PVOID PACCESS_TOKEN;
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ PVOID PSECURITY_DESCRIPTOR;
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ PVOID PSID;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ DWORD ACCESS_ਨਕਾਬ;
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ACCESS_ਨਕਾਬ *PACCESS_ਨਕਾਬ;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DELETE (0x00010000L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ READ_CONTROL (0x00020000L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WRITE_DAC (0x00040000L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WRITE_OWNER (0x00080000L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SYNCHRONIZE (0x00100000L)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STANDARD_RIGHTS_REQUIRED (0x000F0000L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STANDARD_RIGHTS_READ (READ_CONTROL)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STANDARD_RIGHTS_WRITE (READ_CONTROL)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STANDARD_RIGHTS_EXECUTE (READ_CONTROL)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STANDARD_RIGHTS_ALL (0x001F0000L)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPECIFIC_RIGHTS_ALL (0x0000FFFFL)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACCESS_SYSTEM_SECURITY (0x01000000L)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਵੱਧ_ਤੋਂ_ਵੱਧ_ALLOWED (0x02000000L)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GENERIC_READ (0x80000000L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GENERIC_WRITE (0x40000000L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GENERIC_EXECUTE (0x20000000L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GENERIC_ALL (0x10000000L)

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _GENERIC_MAPPING {
      ACCESS_ਨਕਾਬ GenericRead;
      ACCESS_ਨਕਾਬ GenericWrite;
      ACCESS_ਨਕਾਬ GenericExecute;
      ACCESS_ਨਕਾਬ GenericAll;
    } GENERIC_MAPPING;
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ GENERIC_MAPPING *PGENERIC_MAPPING;

#ਅਨ੍ਤਰ੍ਭਾਵ <pshpack4.h>

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ LUID_AND_ਗੁਣ {
      LUID Luid;
      DWORD ਗੁਣ;
    } LUID_AND_ਗੁਣ_2,*PLUID_AND_ਗੁਣ;
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ LUID_AND_ਗੁਣ_2 LUID_AND_ਗੁਣ_ARRAY[ANYSIZE_ARRAY];
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ LUID_AND_ਗੁਣ_ARRAY *PLUID_AND_ਗੁਣ_ARRAY;

#ਅਨ੍ਤਰ੍ਭਾਵ <poppack.h>

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ SID_IDENTIFIER_AUTHORITY_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SID_IDENTIFIER_AUTHORITY_DEFINED
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _SID_IDENTIFIER_AUTHORITY {
      BYTE ਮੁੱਲ_3[6];
    } SID_IDENTIFIER_AUTHORITY,*PSID_IDENTIFIER_AUTHORITY;
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ SID_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SID_DEFINED
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _SID {
      BYTE Revision;
      BYTE Sub_Authority_ਗਿਣਤੀ;
      SID_IDENTIFIER_AUTHORITY IdentifierAuthority;
      DWORD SubAuthority[ANYSIZE_ARRAY];
    } SID,*PISID;
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SID_REVISION (1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SID_MAX_SUB_AUTHORITIES (15)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SID_RECOMMENDED_SUB_AUTHORITIES (1)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_MAX_SID_ਮਾਪ (ਆਕਾਰ(SID) - ਆਕਾਰ(DWORD) + (SID_MAX_SUB_AUTHORITIES *ਆਕਾਰ(DWORD)))

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਗਿਣਤੀ _SID_NAME_USE {
      SidTypeUser = 1,Sid_Type_ਸਮੂਹ,SidTypeDomain,SidTypeAlias,Sid_Type_Well_ਗਿਆਤ_ਸਮੂਹ,SidTypeDeletedAccount,SidTypeInvalid,SidTypeUnknown,SidTypeComputer
    } SID_NAME_USE,*PSID_NAME_USE;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ SID_AND_ਗੁਣ {
      PSID Sid;
      DWORD ਗੁਣ;
    } SID_AND_ਗੁਣ_2,*PSID_AND_ਗੁਣ;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ SID_AND_ਗੁਣ_2 SID_AND_ਗੁਣ_ARRAY[ANYSIZE_ARRAY];
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ SID_AND_ਗੁਣ_ARRAY *PSID_AND_ਗੁਣ_ARRAY;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_NULL_SID_AUTHORITY {0,0,0,0,0,0}
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_WORLD_SID_AUTHORITY {0,0,0,0,0,1}
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_LOCAL_SID_AUTHORITY {0,0,0,0,0,2}
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_CREATOR_SID_AUTHORITY {0,0,0,0,0,3}
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_NON_UNIQUE_AUTHORITY {0,0,0,0,0,4}
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_RESOURCE_MANAGER_AUTHORITY {0,0,0,0,0,9}

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_NULL_RID (0x00000000L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_WORLD_RID (0x00000000L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_LOCAL_RID (0x00000000L)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_CREATOR_OWNER_RID (0x00000000L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_CREATOR_ਸਮੂਹ_RID (0x00000001L)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_CREATOR_OWNER_SERVER_RID (0x00000002L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_CREATOR_ਸਮੂਹ_SERVER_RID (0x00000003L)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_NT_AUTHORITY {0,0,0,0,0,5}

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_DIALUP_RID (0x00000001L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_ਜਾਲ_RID (0x00000002L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_BATCH_RID (0x00000003L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_INTERACTIVE_RID (0x00000004L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_LOGON_IDS_RID (0x00000005L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_LOGON_IDS_RID_ਗਿਣਤੀ (3L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_SERVICE_RID (0x00000006L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_ANONYMOUS_LOGON_RID (0x00000007L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_PROXY_RID (0x00000008L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_ENTERPRISE_CONTROLLERS_RID (0x00000009L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_SERVER_LOGON_RID SECURITY_ENTERPRISE_CONTROLLERS_RID
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_PRINCIPAL_SELF_RID (0x0000000AL)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_AUTHENTICATED_USER_RID (0x0000000BL)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_RESTRICTED_ਕੋਡ_RID (0x0000000CL)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_TERMINAL_SERVER_RID (0x0000000DL)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_REMOTE_LOGON_RID (0x0000000EL)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_THIS_ORGANIZATION_RID (0x0000000FL)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_IUSER_RID (0x00000011L)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_LOCAL_SYSTEM_RID (0x00000012L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_LOCAL_SERVICE_RID (0x00000013L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_ਜਾਲ_SERVICE_RID (0x00000014L)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_NT_NON_UNIQUE (0x00000015L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_NT_NON_UNIQUE_SUB_AUTH_ਗਿਣਤੀ (3L)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_ENTERPRISE_READONLY_CONTROLLERS_RID (0x00000016L)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_BUILTIN_DOMAIN_RID (0x00000020L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_WRITE_RESTRICTED_ਕੋਡ_RID (0x00000021L)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_PACKAGE_ਅਧਾਰ_RID (0x00000040L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_PACKAGE_RID_ਗਿਣਤੀ (2L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_PACKAGE_NTLM_RID (0x0000000AL)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_PACKAGE_SCHANNEL_RID (0x0000000EL)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_PACKAGE_DIGEST_RID (0x00000015L)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_SERVICE_ID_ਅਧਾਰ_RID (0x00000050L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_SERVICE_ID_RID_ਗਿਣਤੀ (6L)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_RESERVED_ID_ਅਧਾਰ_RID (0x00000051L)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_MAX_ALWAYS_FILTERED (0x000003E7L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_MIN_NEVER_FILTERED (0x000003E8L)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_OTHER_ORGANIZATION_RID (0x000003E8L)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FOREST_USER_RID_MAX (0x000001F3L)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOMAIN_USER_RID_ADMIN (0x000001F4L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOMAIN_USER_RID_GUEST (0x000001F5L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOMAIN_USER_RID_KRBTGT (0x000001F6L)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOMAIN_USER_RID_MAX (0x000003E7L)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOMAIN_ਸਮੂਹ_RID_ADMINS (0x00000200L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOMAIN_ਸਮੂਹ_RID_USERS (0x00000201L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOMAIN_ਸਮੂਹ_RID_GUESTS (0x00000202L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOMAIN_ਸਮੂਹ_RID_COMPUTERS (0x00000203L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOMAIN_ਸਮੂਹ_RID_CONTROLLERS (0x00000204L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOMAIN_ਸਮੂਹ_RID_CERT_ADMINS (0x00000205L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOMAIN_ਸਮੂਹ_RID_SCHEMA_ADMINS (0x00000206L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOMAIN_ਸਮੂਹ_RID_ENTERPRISE_ADMINS (0x00000207L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOMAIN_ਸਮੂਹ_RID_POLICY_ADMINS (0x00000208L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOMAIN_ਸਮੂਹ_RID_READONLY_CONTROLLERS (0x00000209L)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOMAIN_ALIAS_RID_ADMINS (0x00000220L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOMAIN_ALIAS_RID_USERS (0x00000221L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOMAIN_ALIAS_RID_GUESTS (0x00000222L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOMAIN_ALIAS_RID_POWER_USERS (0x00000223L)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOMAIN_ALIAS_RID_ACCOUNT_OPS (0x00000224L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOMAIN_ALIAS_RID_SYSTEM_OPS (0x00000225L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOMAIN_ALIAS_RID_PRINT_OPS (0x00000226L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOMAIN_ALIAS_RID_BACKUP_OPS (0x00000227L)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOMAIN_ALIAS_RID_REPLICATOR (0x00000228L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOMAIN_ALIAS_RID_RAS_SERVERS (0x00000229L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOMAIN_ALIAS_RID_PREW2KCOMPACCESS (0x0000022AL)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOMAIN_ALIAS_RID_REMOTE_DESKTOP_USERS (0x0000022BL)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOMAIN_ALIAS_RID_ਜਾਲ_CONFIGURATION_OPS (0x0000022CL)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOMAIN_ALIAS_RID_INCOMING_FOREST_TRUST_BUILDERS (0x0000022DL)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOMAIN_ALIAS_RID_MONITORING_USERS (0x0000022EL)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOMAIN_ALIAS_RID_LOGGING_USERS (0x0000022FL)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOMAIN_ALIAS_RID_AUTHORIZATIONACCESS (0x00000230L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOMAIN_ALIAS_RID_TS_LICENSE_SERVERS (0x00000231L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOMAIN_ALIAS_RID_DCOM_USERS (0x00000232L)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOMAIN_ALIAS_RID_IUSERS (0x00000238L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOMAIN_ALIAS_RID_CRYPTO_OPERATORS (0x00000239L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOMAIN_ALIAS_RID_CACHEABLE_PRINCIPALS_ਸਮੂਹ (0x0000023BL)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOMAIN_ALIAS_RID_NON_CACHEABLE_PRINCIPALS_ਸਮੂਹ (0x0000023CL)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOMAIN_ALIAS_RID_EVENT_LOG_READERS_ਸਮੂਹ (0x0000023DL)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_MANDATORY_LABEL_AUTHORITY {0,0,0,0,0,16}
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_MANDATORY_UNTRUSTED_RID (0x00000000L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_MANDATORY_ਨੀਵਾਂ_RID (0x00001000L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_MANDATORY_MEDIUM_RID (0x00002000L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_MANDATORY_ਉੱਚਾ_RID (0x00003000L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_MANDATORY_SYSTEM_RID (0x00004000L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_MANDATORY_PROTECTED_PROCESS_RID (0x00005000L)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_MANDATORY_ਵੱਧ_ਤੋਂ_ਵੱਧ_USER_RID SECURITY_MANDATORY_SYSTEM_RID

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MANDATORY_LEVEL_ਮੰਜ਼ਿਲ_MANDATORY_RID(IL) (IL * 0x1000)

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਗਿਣਤੀ {
      WinNullSid = 0,WinWorldSid = 1,WinLocalSid = 2,WinCreatorOwnerSid = 3,Win_Creator_ਸਮੂਹ_Sid = 4,WinCreatorOwnerServerSid = 5,Win_Creator_ਸਮੂਹ_Server_Sid = 6,WinNtAuthoritySid = 7,WinDialupSid = 8,Win_ਜਾਲ_Sid = 9,WinBatchSid = 10,WinInteractiveSid = 11,WinServiceSid = 12,WinAnonymousSid = 13,WinProxySid = 14,WinEnterpriseControllersSid = 15,WinSelfSid = 16,WinAuthenticatedUserSid = 17,Win_Restricted_ਕੋਡ_Sid = 18,WinTerminalServerSid = 19,WinRemoteLogonIdSid = 20,WinLogonIdsSid = 21,WinLocalSystemSid = 22,WinLocalServiceSid = 23,Win_ਜਾਲ_Service_Sid = 24,WinBuiltinDomainSid = 25,WinBuiltinAdministratorsSid = 26,WinBuiltinUsersSid = 27,WinBuiltinGuestsSid = 28,WinBuiltinPowerUsersSid = 29,WinBuiltinAccountOperatorsSid = 30,WinBuiltinSystemOperatorsSid = 31,WinBuiltinPrintOperatorsSid = 32,WinBuiltinBackupOperatorsSid = 33,WinBuiltinReplicatorSid = 34,WinBuiltinPreWindows2000CompatibleAccessSid = 35,WinBuiltinRemoteDesktopUsersSid = 36,Win_Builtin_ਜਾਲ_Configuration_Operators_Sid = 37,WinAccountAdministratorSid = 38,WinAccountGuestSid = 39,WinAccountKrbtgtSid = 40,WinAccountDomainAdminsSid = 41,WinAccountDomainUsersSid = 42,WinAccountDomainGuestsSid = 43,WinAccountComputersSid = 44,WinAccountControllersSid = 45,WinAccountCertAdminsSid = 46,WinAccountSchemaAdminsSid = 47,WinAccountEnterpriseAdminsSid = 48,WinAccountPolicyAdminsSid = 49,WinAccountRasAndIasServersSid = 50,WinNTLMAuthenticationSid = 51,WinDigestAuthenticationSid = 52,WinSChannelAuthenticationSid = 53,WinThisOrganizationSid = 54,WinOtherOrganizationSid = 55,WinBuiltinIncomingForestTrustBuildersSid = 56,WinBuiltinPerfMonitoringUsersSid = 57,WinBuiltinPerfLoggingUsersSid = 58,WinBuiltinAuthorizationAccessSid = 59,WinBuiltinTerminalServerLicenseServersSid = 60,WinBuiltinDCOMUsersSid = 61
    } WELL_ਗਿਆਤ_SID_TYPE;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SYSTEM_LUID { 0x3E7,0x0 }
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ANONYMOUS_LOGON_LUID { 0x3e6,0x0 }
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LOCALSERVICE_LUID { 0x3e5,0x0 }
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NETWORKSERVICE_LUID { 0x3e4,0x0 }
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IUSER_LUID { 0x3e3, 0x0 }

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_ਸਮੂਹ_MANDATORY (0x00000001L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_ਸਮੂਹ_ENABLED_BY_DEFAULT (0x00000002L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_ਸਮੂਹ_ENABLED (0x00000004L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_ਸਮੂਹ_OWNER (0x00000008L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_ਸਮੂਹ_USE_FOR_DENY_ONLY (0x00000010L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_ਸਮੂਹ_INTEGRITY (0x00000020L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_ਸਮੂਹ_INTEGRITY_ENABLED (0x00000040L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_ਸਮੂਹ_LOGON_ID (0xC0000000L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_ਸਮੂਹ_RESOURCE (0x20000000L)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACL_REVISION (2)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACL_REVISION_DS (4)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACL_REVISION1 (1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MIN_ACL_REVISION ACL_REVISION2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACL_REVISION2 (2)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACL_REVISION3 (3)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACL_REVISION4 (4)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAX_ACL_REVISION ACL_REVISION4

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _ACL {
      BYTE AclRevision;
      BYTE Sbz1;
      ਸ਼ਬਦ_3 Acl_ਮਾਪ;
      ਸ਼ਬਦ_3 Ace_ਗਿਣਤੀ;
      ਸ਼ਬਦ_3 Sbz2;
    } ACL;
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ACL *PACL;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ACE_ਸਿਰਲੇਖ {
      BYTE AceType;
      BYTE AceFlags;
      ਸ਼ਬਦ_3 Ace_ਮਾਪ;
    } ACE_ਸਿਰਲੇਖ_2;
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ACE_ਸਿਰਲੇਖ_2 *PACE_ਸਿਰਲੇਖ;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACCESS_MIN_MS_ACE_TYPE (0x0)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACCESS_ALLOWED_ACE_TYPE (0x0)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACCESS_DENIED_ACE_TYPE (0x1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SYSTEM_AUDIT_ACE_TYPE (0x2)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SYSTEM_ALARM_ACE_TYPE (0x3)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACCESS_MAX_MS_V2_ACE_TYPE (0x3)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACCESS_ALLOWED_COMPOUND_ACE_TYPE (0x4)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACCESS_MAX_MS_V3_ACE_TYPE (0x4)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACCESS_MIN_MS_OBJECT_ACE_TYPE (0x5)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACCESS_ALLOWED_OBJECT_ACE_TYPE (0x5)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACCESS_DENIED_OBJECT_ACE_TYPE (0x6)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SYSTEM_AUDIT_OBJECT_ACE_TYPE (0x7)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SYSTEM_ALARM_OBJECT_ACE_TYPE (0x8)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACCESS_MAX_MS_OBJECT_ACE_TYPE (0x8)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACCESS_MAX_MS_V4_ACE_TYPE (0x8)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACCESS_MAX_MS_ACE_TYPE (0x8)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACCESS_ALLOWED_CALLBACK_ACE_TYPE (0x9)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACCESS_DENIED_CALLBACK_ACE_TYPE (0xA)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACCESS_ALLOWED_CALLBACK_OBJECT_ACE_TYPE (0xB)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACCESS_DENIED_CALLBACK_OBJECT_ACE_TYPE (0xC)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SYSTEM_AUDIT_CALLBACK_ACE_TYPE (0xD)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SYSTEM_ALARM_CALLBACK_ACE_TYPE (0xE)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SYSTEM_AUDIT_CALLBACK_OBJECT_ACE_TYPE (0xF)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SYSTEM_ALARM_CALLBACK_OBJECT_ACE_TYPE (0x10)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SYSTEM_MANDATORY_LABEL_ACE_TYPE (0x11)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACCESS_MAX_MS_V5_ACE_TYPE (0x11)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBJECT_INHERIT_ACE (0x1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONTAINER_INHERIT_ACE (0x2)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NO_PROPAGATE_INHERIT_ACE (0x4)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INHERIT_ONLY_ACE (0x8)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INHERITED_ACE (0x10)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VALID_INHERIT_FLAGS (0x1F)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SUCCESSFUL_ACCESS_ACE_FLAG (0x40)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FAILED_ACCESS_ACE_FLAG (0x80)

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _ACCESS_ALLOWED_ACE {
      ACE_ਸਿਰਲੇਖ_2 ਸਿਰਲੇਖ_2;
      ACCESS_ਨਕਾਬ ਨਕਾਬ_3;
      DWORD Sid_ਸ਼ੁਰੂ;
    } ACCESS_ALLOWED_ACE;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ACCESS_ALLOWED_ACE *PACCESS_ALLOWED_ACE;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _ACCESS_DENIED_ACE {
      ACE_ਸਿਰਲੇਖ_2 ਸਿਰਲੇਖ_2;
      ACCESS_ਨਕਾਬ ਨਕਾਬ_3;
      DWORD Sid_ਸ਼ੁਰੂ;
    } ACCESS_DENIED_ACE;
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ACCESS_DENIED_ACE *PACCESS_DENIED_ACE;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _SYSTEM_AUDIT_ACE {
      ACE_ਸਿਰਲੇਖ_2 ਸਿਰਲੇਖ_2;
      ACCESS_ਨਕਾਬ ਨਕਾਬ_3;
      DWORD Sid_ਸ਼ੁਰੂ;
    } SYSTEM_AUDIT_ACE;
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ SYSTEM_AUDIT_ACE *PSYSTEM_AUDIT_ACE;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _SYSTEM_ALARM_ACE {
      ACE_ਸਿਰਲੇਖ_2 ਸਿਰਲੇਖ_2;
      ACCESS_ਨਕਾਬ ਨਕਾਬ_3;
      DWORD Sid_ਸ਼ੁਰੂ;
    } SYSTEM_ALARM_ACE;
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ SYSTEM_ALARM_ACE *PSYSTEM_ALARM_ACE;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _ACCESS_ALLOWED_OBJECT_ACE {
      ACE_ਸਿਰਲੇਖ_2 ਸਿਰਲੇਖ_2;
      ACCESS_ਨਕਾਬ ਨਕਾਬ_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_ਸ਼ੁਰੂ;
    } ACCESS_ALLOWED_OBJECT_ACE,*PACCESS_ALLOWED_OBJECT_ACE;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _ACCESS_DENIED_OBJECT_ACE {
      ACE_ਸਿਰਲੇਖ_2 ਸਿਰਲੇਖ_2;
      ACCESS_ਨਕਾਬ ਨਕਾਬ_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_ਸ਼ੁਰੂ;
    } ACCESS_DENIED_OBJECT_ACE,*PACCESS_DENIED_OBJECT_ACE;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _SYSTEM_AUDIT_OBJECT_ACE {
      ACE_ਸਿਰਲੇਖ_2 ਸਿਰਲੇਖ_2;
      ACCESS_ਨਕਾਬ ਨਕਾਬ_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_ਸ਼ੁਰੂ;
    } SYSTEM_AUDIT_OBJECT_ACE,*PSYSTEM_AUDIT_OBJECT_ACE;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _SYSTEM_ALARM_OBJECT_ACE {
      ACE_ਸਿਰਲੇਖ_2 ਸਿਰਲੇਖ_2;
      ACCESS_ਨਕਾਬ ਨਕਾਬ_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_ਸ਼ੁਰੂ;
    } SYSTEM_ALARM_OBJECT_ACE,*PSYSTEM_ALARM_OBJECT_ACE;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _ACCESS_ALLOWED_CALLBACK_ACE {
      ACE_ਸਿਰਲੇਖ_2 ਸਿਰਲੇਖ_2;
      ACCESS_ਨਕਾਬ ਨਕਾਬ_3;
      DWORD Sid_ਸ਼ੁਰੂ;

    } ACCESS_ALLOWED_CALLBACK_ACE,*PACCESS_ALLOWED_CALLBACK_ACE;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _ACCESS_DENIED_CALLBACK_ACE {
      ACE_ਸਿਰਲੇਖ_2 ਸਿਰਲੇਖ_2;
      ACCESS_ਨਕਾਬ ਨਕਾਬ_3;
      DWORD Sid_ਸ਼ੁਰੂ;

    } ACCESS_DENIED_CALLBACK_ACE,*PACCESS_DENIED_CALLBACK_ACE;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _SYSTEM_AUDIT_CALLBACK_ACE {
      ACE_ਸਿਰਲੇਖ_2 ਸਿਰਲੇਖ_2;
      ACCESS_ਨਕਾਬ ਨਕਾਬ_3;
      DWORD Sid_ਸ਼ੁਰੂ;

    } SYSTEM_AUDIT_CALLBACK_ACE,*PSYSTEM_AUDIT_CALLBACK_ACE;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _SYSTEM_ALARM_CALLBACK_ACE {
      ACE_ਸਿਰਲੇਖ_2 ਸਿਰਲੇਖ_2;
      ACCESS_ਨਕਾਬ ਨਕਾਬ_3;
      DWORD Sid_ਸ਼ੁਰੂ;

    } SYSTEM_ALARM_CALLBACK_ACE,*PSYSTEM_ALARM_CALLBACK_ACE;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _ACCESS_ALLOWED_CALLBACK_OBJECT_ACE {
      ACE_ਸਿਰਲੇਖ_2 ਸਿਰਲੇਖ_2;
      ACCESS_ਨਕਾਬ ਨਕਾਬ_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_ਸ਼ੁਰੂ;

    } ACCESS_ALLOWED_CALLBACK_OBJECT_ACE,*PACCESS_ALLOWED_CALLBACK_OBJECT_ACE;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _ACCESS_DENIED_CALLBACK_OBJECT_ACE {
      ACE_ਸਿਰਲੇਖ_2 ਸਿਰਲੇਖ_2;
      ACCESS_ਨਕਾਬ ਨਕਾਬ_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_ਸ਼ੁਰੂ;

    } ACCESS_DENIED_CALLBACK_OBJECT_ACE,*PACCESS_DENIED_CALLBACK_OBJECT_ACE;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _SYSTEM_AUDIT_CALLBACK_OBJECT_ACE {
      ACE_ਸਿਰਲੇਖ_2 ਸਿਰਲੇਖ_2;
      ACCESS_ਨਕਾਬ ਨਕਾਬ_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_ਸ਼ੁਰੂ;

    } SYSTEM_AUDIT_CALLBACK_OBJECT_ACE,*PSYSTEM_AUDIT_CALLBACK_OBJECT_ACE;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _SYSTEM_ALARM_CALLBACK_OBJECT_ACE {
      ACE_ਸਿਰਲੇਖ_2 ਸਿਰਲੇਖ_2;
      ACCESS_ਨਕਾਬ ਨਕਾਬ_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_ਸ਼ੁਰੂ;

    } SYSTEM_ALARM_CALLBACK_OBJECT_ACE,*PSYSTEM_ALARM_CALLBACK_OBJECT_ACE;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACE_OBJECT_TYPE_PRESENT 0x1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACE_INHERITED_OBJECT_TYPE_PRESENT 0x2

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਗਿਣਤੀ _ACL_INFORMATION_CLASS {
      AclRevisionInformation = 1,Acl_ਮਾਪ_Information
    } ACL_INFORMATION_CLASS;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _ACL_REVISION_INFORMATION {
      DWORD AclRevision;
    } ACL_REVISION_INFORMATION;
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ACL_REVISION_INFORMATION *PACL_REVISION_INFORMATION;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ACL_ਮਾਪ_INFORMATION {
      DWORD Ace_ਗਿਣਤੀ;
      DWORD Acl_ਬਾਈਟਾਂ_ਵਿੱਚ_Use;
      DWORD Acl_ਬਾਈਟਾਂ_Free;
    } ACL_ਮਾਪ_INFORMATION_2;
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ACL_ਮਾਪ_INFORMATION_2 *PACL_ਮਾਪ_INFORMATION;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_DESCRIPTOR_REVISION (1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_DESCRIPTOR_REVISION1 (1)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_DESCRIPTOR_MIN_ਲੰਮਾਈ (ਆਕਾਰ(SECURITY_DESCRIPTOR))

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਸ਼ਬਦ_3 SECURITY_DESCRIPTOR_CONTROL,*PSECURITY_DESCRIPTOR_CONTROL;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_OWNER_DEFAULTED (0x0001)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_ਸਮੂਹ_DEFAULTED (0x0002)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_DACL_PRESENT (0x0004)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_DACL_DEFAULTED (0x0008)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_SACL_PRESENT (0x0010)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_SACL_DEFAULTED (0x0020)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_DACL_AUTO_INHERIT_REQ (0x0100)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_SACL_AUTO_INHERIT_REQ (0x0200)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_DACL_AUTO_INHERITED (0x0400)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_SACL_AUTO_INHERITED (0x0800)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_DACL_PROTECTED (0x1000)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_SACL_PROTECTED (0x2000)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_RM_CONTROL_VALID (0x4000)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_SELF_RELATIVE (0x8000)

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _SECURITY_DESCRIPTOR_RELATIVE {
      BYTE Revision;
      BYTE Sbz1;
      SECURITY_DESCRIPTOR_CONTROL Control;
      DWORD Owner;
      DWORD ਸਮੂਹ_2;
      DWORD Sacl;
      DWORD Dacl;
    } SECURITY_DESCRIPTOR_RELATIVE,*PISECURITY_DESCRIPTOR_RELATIVE;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _SECURITY_DESCRIPTOR {
      BYTE Revision;
      BYTE Sbz1;
      SECURITY_DESCRIPTOR_CONTROL Control;
      PSID Owner;
      PSID ਸਮੂਹ_2;
      PACL Sacl;
      PACL Dacl;

    } SECURITY_DESCRIPTOR,*PISECURITY_DESCRIPTOR;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _OBJECT_TYPE_LIST {
      ਸ਼ਬਦ_3 Level;
      ਸ਼ਬਦ_3 Sbz;
      GUID *ObjectType;
    } OBJECT_TYPE_LIST,*POBJECT_TYPE_LIST;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACCESS_OBJECT_GUID 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACCESS_PROPERTY_ਸੈੱਟ_GUID 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACCESS_PROPERTY_GUID 2

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACCESS_MAX_LEVEL 4

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਗਿਣਤੀ _AUDIT_EVENT_TYPE {
      AuditEventObjectAccess,AuditEventDirectoryServiceAccess
    } AUDIT_EVENT_TYPE,*PAUDIT_EVENT_TYPE;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AUDIT_ALLOW_NO_PRIVILEGE 0x1

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACCESS_DS_ਸਰੋਤ_A "DS"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACCESS_DS_ਸਰੋਤ_W L"DS"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACCESS_DS_OBJECT_TYPE_NAME_A "Directory Service Object"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACCESS_DS_OBJECT_TYPE_NAME_W L"Directory Service Object"

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_PRIVILEGE_ENABLED_BY_DEFAULT (0x00000001L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_PRIVILEGE_ENABLED (0x00000002L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_PRIVILEGE_REMOVED (0X00000004L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_PRIVILEGE_ਵਰਤਿਆ_FOR_ACCESS (0x80000000L)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRIVILEGE_ਸੈੱਟ_ALL_NECESSARY (1)

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ PRIVILEGE_ਸੈੱਟ {
      DWORD Privilege_ਗਿਣਤੀ;
      DWORD Control;
      LUID_AND_ਗੁਣ_2 Privilege[ANYSIZE_ARRAY];
    } PRIVILEGE_ਸੈੱਟ_2,*PPRIVILEGE_ਸੈੱਟ;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_CREATE_TOKEN_NAME ਪਾਠ_3("SeCreateTokenPrivilege")
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_ASSIGNPRIMARYTOKEN_NAME ਪਾਠ_3("SeAssignPrimaryTokenPrivilege")
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_ਤਾਲਾ_ਸਮ੍ਰਿਤੀ_NAME ਪਾਠ_3("SeLockMemoryPrivilege")
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_INCREASE_QUOTA_NAME ਪਾਠ_3("SeIncreaseQuotaPrivilege")
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_UNSOLICITED_ਨਿਵੇਸ਼_NAME ਪਾਠ_3("SeUnsolicitedInputPrivilege")
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_MACHINE_ACCOUNT_NAME ਪਾਠ_3("SeMachineAccountPrivilege")
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_TCB_NAME ਪਾਠ_3("SeTcbPrivilege")
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_SECURITY_NAME ਪਾਠ_3("SeSecurityPrivilege")
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_TAKE_OWNERSHIP_NAME ਪਾਠ_3("SeTakeOwnershipPrivilege")
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_ਲੱਦੋ_DRIVER_NAME ਪਾਠ_3("SeLoadDriverPrivilege")
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_SYSTEM_PROFILE_NAME ਪਾਠ_3("SeSystemProfilePrivilege")
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_SYSTEMTIME_NAME ਪਾਠ_3("SeSystemtimePrivilege")
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_PROF_SINGLE_PROCESS_NAME ਪਾਠ_3("SeProfileSingleProcessPrivilege")
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_INC_ਅਧਾਰ_ਤਰਜੀਹ_NAME ਪਾਠ_3("SeIncreaseBasePriorityPrivilege")
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_CREATE_PAGEFILE_NAME ਪਾਠ_3("SeCreatePagefilePrivilege")
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_CREATE_PERMANENT_NAME ਪਾਠ_3("SeCreatePermanentPrivilege")
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_BACKUP_NAME ਪਾਠ_3("SeBackupPrivilege")
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_RESTORE_NAME ਪਾਠ_3("SeRestorePrivilege")
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_SHUTDOWN_NAME ਪਾਠ_3("SeShutdownPrivilege")
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_DEBUG_NAME ਪਾਠ_3("SeDebugPrivilege")
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_AUDIT_NAME ਪਾਠ_3("SeAuditPrivilege")
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_SYSTEM_ENVIRONMENT_NAME ਪਾਠ_3("SeSystemEnvironmentPrivilege")
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_CHANGE_NOTIFY_NAME ਪਾਠ_3("SeChangeNotifyPrivilege")
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_REMOTE_SHUTDOWN_NAME ਪਾਠ_3("SeRemoteShutdownPrivilege")
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_UNDOCK_NAME ਪਾਠ_3("SeUndockPrivilege")
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_SYNC_AGENT_NAME ਪਾਠ_3("SeSyncAgentPrivilege")
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_ENABLE_DELEGATION_NAME ਪਾਠ_3("SeEnableDelegationPrivilege")
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_MANAGE_VOLUME_NAME ਪਾਠ_3("SeManageVolumePrivilege")
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_IMPERSONATE_NAME ਪਾਠ_3("SeImpersonatePrivilege")
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SE_CREATE_GLOBAL_NAME ਪਾਠ_3("SeCreateGlobalPrivilege")

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਗਿਣਤੀ _SECURITY_IMPERSONATION_LEVEL {
      SecurityAnonymous,SecurityIdentification,SecurityImpersonation,SecurityDelegation
    } SECURITY_IMPERSONATION_LEVEL,*PSECURITY_IMPERSONATION_LEVEL;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_MAX_IMPERSONATION_LEVEL SecurityDelegation
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_MIN_IMPERSONATION_LEVEL SecurityAnonymous
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DEFAULT_IMPERSONATION_LEVEL SecurityImpersonation
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VALID_IMPERSONATION_LEVEL(L) (((L) >= SECURITY_MIN_IMPERSONATION_LEVEL) && ((L) <= SECURITY_MAX_IMPERSONATION_LEVEL))

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOKEN_ਸੌਂਪੋ_PRIMARY (0x0001)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOKEN_DUPLICATE (0x0002)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOKEN_IMPERSONATE (0x0004)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOKEN_QUERY (0x0008)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOKEN_QUERY_ਸਰੋਤ (0x0010)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOKEN_ADJUST_PRIVILEGES (0x0020)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOKEN_ADJUST_GROUPS (0x0040)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOKEN_ADJUST_DEFAULT (0x0080)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOKEN_ADJUST_SESSIONID (0x0100)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOKEN_ALL_ACCESS_P (STANDARD_RIGHTS_REQUIRED | TOKEN_ਸੌਂਪੋ_PRIMARY | TOKEN_DUPLICATE | TOKEN_IMPERSONATE | TOKEN_QUERY | TOKEN_QUERY_ਸਰੋਤ | TOKEN_ADJUST_PRIVILEGES | TOKEN_ADJUST_GROUPS | TOKEN_ADJUST_DEFAULT)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOKEN_ALL_ACCESS (TOKEN_ALL_ACCESS_P | TOKEN_ADJUST_SESSIONID)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOKEN_READ (STANDARD_RIGHTS_READ | TOKEN_QUERY)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOKEN_WRITE (STANDARD_RIGHTS_WRITE | TOKEN_ADJUST_PRIVILEGES | TOKEN_ADJUST_GROUPS | TOKEN_ADJUST_DEFAULT)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOKEN_EXECUTE (STANDARD_RIGHTS_EXECUTE)

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਗਿਣਤੀ _TOKEN_TYPE {
      TokenPrimary = 1,TokenImpersonation
    } TOKEN_TYPE;
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ TOKEN_TYPE *PTOKEN_TYPE;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਗਿਣਤੀ _TOKEN_INFORMATION_CLASS {
      TokenUser = 1,TokenGroups,TokenPrivileges,TokenOwner,Token_Primary_ਸਮੂਹ,TokenDefaultDacl,Token_ਸਰੋਤ,TokenType,TokenImpersonationLevel,
      TokenStatistics,TokenRestrictedSids,TokenSessionId,TokenGroupsAndPrivileges,TokenSessionReference,TokenSandBoxInert,TokenAuditPolicy,
      TokenOrigin,MaxTokenInfoClass
    } TOKEN_INFORMATION_CLASS,*PTOKEN_INFORMATION_CLASS;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _TOKEN_USER {
      SID_AND_ਗੁਣ_2 User;
    } TOKEN_USER,*PTOKEN_USER;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _TOKEN_GROUPS {
      DWORD ਸਮੂਹ_ਗਿਣਤੀ;
      SID_AND_ਗੁਣ_2 Groups[ANYSIZE_ARRAY];
    } TOKEN_GROUPS,*PTOKEN_GROUPS;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _TOKEN_PRIVILEGES {
      DWORD Privilege_ਗਿਣਤੀ;
      LUID_AND_ਗੁਣ_2 Privileges[ANYSIZE_ARRAY];
    } TOKEN_PRIVILEGES,*PTOKEN_PRIVILEGES;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _TOKEN_OWNER {
      PSID Owner;
    } TOKEN_OWNER,*PTOKEN_OWNER;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ TOKEN_PRIMARY_ਸਮੂਹ {
      PSID Primary_ਸਮੂਹ;
    } TOKEN_PRIMARY_ਸਮੂਹ_2,*PTOKEN_PRIMARY_ਸਮੂਹ;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _TOKEN_DEFAULT_DACL {
      PACL DefaultDacl;
    } TOKEN_DEFAULT_DACL,*PTOKEN_DEFAULT_DACL;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _TOKEN_GROUPS_AND_PRIVILEGES {
      DWORD Sid_ਗਿਣਤੀ;
      DWORD Sid_ਲੰਮਾਈ;
      PSID_AND_ਗੁਣ Sids;
      DWORD Restricted_Sid_ਗਿਣਤੀ;
      DWORD Restricted_Sid_ਲੰਮਾਈ;
      PSID_AND_ਗੁਣ RestrictedSids;
      DWORD Privilege_ਗਿਣਤੀ;
      DWORD Privilege_ਲੰਮਾਈ;
      PLUID_AND_ਗੁਣ Privileges;
      LUID AuthenticationId;
    } TOKEN_GROUPS_AND_PRIVILEGES,*PTOKEN_GROUPS_AND_PRIVILEGES;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOKEN_AUDIT_SUCCESS_INCLUDE 0x1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOKEN_AUDIT_SUCCESS_EXCLUDE 0x2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOKEN_AUDIT_FAILURE_INCLUDE 0x4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOKEN_AUDIT_FAILURE_EXCLUDE 0x8

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VALID_AUDIT_POLICY_ਬਿੱਟ (TOKEN_AUDIT_SUCCESS_INCLUDE | TOKEN_AUDIT_SUCCESS_EXCLUDE | TOKEN_AUDIT_FAILURE_INCLUDE | TOKEN_AUDIT_FAILURE_EXCLUDE)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VALID_TOKEN_AUDIT_POLICY_ELEMENT(P) ((((P).Policy_ਨਕਾਬ & ~VALID_AUDIT_POLICY_ਬਿੱਟ)==0) && ((P).Category <= AuditEventMaxType))

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _TOKEN_AUDIT_POLICY_ELEMENT {
      DWORD Category;
      DWORD Policy_ਨਕਾਬ;
    } TOKEN_AUDIT_POLICY_ELEMENT,*PTOKEN_AUDIT_POLICY_ELEMENT;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _TOKEN_AUDIT_POLICY {
      DWORD Policy_ਗਿਣਤੀ;
      TOKEN_AUDIT_POLICY_ELEMENT Policy[ANYSIZE_ARRAY];
    } TOKEN_AUDIT_POLICY,*PTOKEN_AUDIT_POLICY;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਪ੍ਰਤੀ_USER_AUDITING_POLICY_ਮਾਪ(p) (ਆਕਾਰ(TOKEN_AUDIT_POLICY) + (((p)->Policy_ਗਿਣਤੀ > ANYSIZE_ARRAY) ? (ਆਕਾਰ(TOKEN_AUDIT_POLICY_ELEMENT) *((p)->Policy_ਗਿਣਤੀ - ANYSIZE_ARRAY)) : 0))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਪ੍ਰਤੀ_USER_AUDITING_POLICY_ਮਾਪ_BY_ਗਿਣਤੀ(C) (ਆਕਾਰ(TOKEN_AUDIT_POLICY) + (((C) > ANYSIZE_ARRAY) ? (ਆਕਾਰ(TOKEN_AUDIT_POLICY_ELEMENT) *((C) - ANYSIZE_ARRAY)) : 0))

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TOKEN_ਸਰੋਤ_ਲੰਮਾਈ 8

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ TOKEN_ਸਰੋਤ {
      CHAR ਸਰੋਤ_Name[TOKEN_ਸਰੋਤ_ਲੰਮਾਈ];
      LUID ਸਰੋਤ_Identifier;
    } TOKEN_ਸਰੋਤ_2,*PTOKEN_ਸਰੋਤ;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _TOKEN_STATISTICS {
      LUID TokenId;
      LUID AuthenticationId;
      LARGE_INTEGER Expiration_ਸਮਾਂ;
      TOKEN_TYPE TokenType;
      SECURITY_IMPERSONATION_LEVEL ImpersonationLevel;
      DWORD DynamicCharged;
      DWORD Dynamic_ਉਪਲਬਧ;
      DWORD ਸਮੂਹ_ਗਿਣਤੀ;
      DWORD Privilege_ਗਿਣਤੀ;
      LUID ModifiedId;
    } TOKEN_STATISTICS,*PTOKEN_STATISTICS;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _TOKEN_CONTROL {
      LUID TokenId;
      LUID AuthenticationId;
      LUID ModifiedId;
      TOKEN_ਸਰੋਤ_2 Token_ਸਰੋਤ;
    } TOKEN_CONTROL,*PTOKEN_CONTROL;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _TOKEN_ORIGIN {
      LUID OriginatingLogonSession;
    } TOKEN_ORIGIN,*PTOKEN_ORIGIN;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_DYNAMIC_TRACKING (TRUE)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_STATIC_TRACKING (FALSE)

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ BOOLEAN SECURITY_CONTEXT_TRACKING_ਬਹੁਲਕ,*PSECURITY_CONTEXT_TRACKING_ਬਹੁਲਕ;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ SECURITY_QUALITY_ਦਾ_SERVICE {
      DWORD ਲੰਮਾਈ_2;
      SECURITY_IMPERSONATION_LEVEL ImpersonationLevel;
      SECURITY_CONTEXT_TRACKING_ਬਹੁਲਕ Context_Tracking_ਬਹੁਲਕ;
      BOOLEAN EffectiveOnly;
    } SECURITY_QUALITY_ਦਾ_SERVICE_2,*PSECURITY_QUALITY_ਦਾ_SERVICE;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _SE_IMPERSONATION_STATE {
      PACCESS_TOKEN Token;
      BOOLEAN CopyOnOpen;
      BOOLEAN EffectiveOnly;
      SECURITY_IMPERSONATION_LEVEL Level;
    } SE_IMPERSONATION_STATE,*PSE_IMPERSONATION_STATE;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DISABLE_MAX_PRIVILEGE 0x1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SANDBOX_INERT 0x2

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ DWORD SECURITY_INFORMATION,*PSECURITY_INFORMATION;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OWNER_SECURITY_INFORMATION (0x00000001L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਮੂਹ_SECURITY_INFORMATION (0x00000002L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DACL_SECURITY_INFORMATION (0x00000004L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SACL_SECURITY_INFORMATION (0x00000008L)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROTECTED_DACL_SECURITY_INFORMATION (0x80000000L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROTECTED_SACL_SECURITY_INFORMATION (0x40000000L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UNPROTECTED_DACL_SECURITY_INFORMATION (0x20000000L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UNPROTECTED_SACL_SECURITY_INFORMATION (0x10000000L)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESS_TERMINATE (0x0001)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESS_CREATE_THREAD (0x0002)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESS_ਸੈੱਟ_SESSIONID (0x0004)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESS_VM_OPERATION (0x0008)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESS_VM_READ (0x0010)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESS_VM_WRITE (0x0020)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESS_DUP_HANDLE (0x0040)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESS_CREATE_PROCESS (0x0080)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESS_ਸੈੱਟ_QUOTA (0x0100)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESS_ਸੈੱਟ_INFORMATION (0x0200)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESS_QUERY_INFORMATION (0x0400)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESS_SUSPEND_RESUME (0x0800)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESS_QUERY_LIMITED_INFORMATION (0x1000)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESS_ਸੈੱਟ_LIMITED_INFORMATION (0x2000)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESS_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0xFFF)

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਵੱਧ_ਤੋਂ_ਵੱਧ_PROCESSORS 64
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਵੱਧ_ਤੋਂ_ਵੱਧ_PROCESSORS 32
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ THREAD_TERMINATE (0x0001)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ THREAD_SUSPEND_RESUME (0x0002)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ THREAD_GET_CONTEXT (0x0008)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ THREAD_ਸੈੱਟ_CONTEXT (0x0010)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ THREAD_ਸੈੱਟ_INFORMATION (0x0020)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ THREAD_QUERY_INFORMATION (0x0040)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ THREAD_ਸੈੱਟ_THREAD_TOKEN (0x0080)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ THREAD_IMPERSONATE (0x0100)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ THREAD_ਸਿੱਧਾ_IMPERSONATION (0x0200)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ THREAD_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0x3FF)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_ਸੌਂਪੋ_PROCESS (0x0001)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_ਸੈੱਟ_ਗੁਣ (0x0002)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_QUERY (0x0004)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_TERMINATE (0x0008)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_ਸੈੱਟ_SECURITY_ਗੁਣ (0x0010)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0x1F)

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਕੰਮ_ਸੈੱਟ_ARRAY {
      HANDLE ਕੰਮ_Handle;
      DWORD MemberLevel;
      DWORD Flags;
    } ਕੰਮ_ਸੈੱਟ_ARRAY_2,*PJOB_ਸੈੱਟ_ARRAY;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FLS_ਵੱਧ_ਤੋਂ_ਵੱਧ_ਉਪਲਬਧ 128
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TLS_MINIMUM_ਉਪਲਬਧ 64

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _NT_TIB_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _NT_TIB_DEFINED
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _NT_TIB {
      ਬਣਤਰ EXCEPTION_REGISTRATION_ਰਿਕਾਰਡ_2 *ExceptionList;
      PVOID ਢੇਰ_ਅਧਾਰ;
      PVOID ਢੇਰ_ਹੱਦਬੰਦੀ;
      PVOID SubSystemTib;
      ਸੰਘ {
	PVOID Fiber_ਅੰਕੜੇ;
	DWORD ਸੰਸਕਰਣ_2;
      };
      PVOID Arbitrary_User_ਸੂਚਕ;
      ਬਣਤਰ _NT_TIB *Self;
    } NT_TIB;
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ NT_TIB *PNT_TIB;
#ਜੇ_ਅੰਤ

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _NT_TIB32 {
      DWORD ExceptionList;
      DWORD ਢੇਰ_ਅਧਾਰ;
      DWORD ਢੇਰ_ਹੱਦਬੰਦੀ;
      DWORD SubSystemTib;
      ਸੰਘ {
	DWORD Fiber_ਅੰਕੜੇ;
	DWORD ਸੰਸਕਰਣ_2;
      };
      DWORD Arbitrary_User_ਸੂਚਕ;
      DWORD Self;
    } NT_TIB32,*PNT_TIB32;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _NT_TIB64 {
      DWORD64 ExceptionList;
      DWORD64 ਢੇਰ_ਅਧਾਰ;
      DWORD64 ਢੇਰ_ਹੱਦਬੰਦੀ;
      DWORD64 SubSystemTib;
      ਸੰਘ {
	DWORD64 Fiber_ਅੰਕੜੇ;
	DWORD ਸੰਸਕਰਣ_2;
      };
      DWORD64 Arbitrary_User_ਸੂਚਕ;
      DWORD64 Self;
    } NT_TIB64,*PNT_TIB64;

#ਜੇ !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WX86
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ THREAD_ਅਧਾਰ_ਤਰਜੀਹ_LOWRT 15
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ THREAD_ਅਧਾਰ_ਤਰਜੀਹ_MAX 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ THREAD_ਅਧਾਰ_ਤਰਜੀਹ_MIN (-2)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ THREAD_ਅਧਾਰ_ਤਰਜੀਹ_IDLE (-15)

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _QUOTA_LIMITS {
      ਮਾਪ_T Paged_Pool_ਹੱਦਬੰਦੀ;
      ਮਾਪ_T Non_Paged_Pool_ਹੱਦਬੰਦੀ;
      ਮਾਪ_T Minimum_Working_ਸੈੱਟ_ਮਾਪ;
      ਮਾਪ_T ਵੱਧ_ਤੋਂ_ਵੱਧ_Working_ਸੈੱਟ_ਮਾਪ;
      ਮਾਪ_T Pagefile_ਹੱਦਬੰਦੀ;
      LARGE_INTEGER ਸਮਾਂ_ਹੱਦਬੰਦੀ;
    } QUOTA_LIMITS,*PQUOTA_LIMITS;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ QUOTA_LIMITS_HARDWS_MIN_ENABLE 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ QUOTA_LIMITS_HARDWS_MIN_DISABLE 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ QUOTA_LIMITS_HARDWS_MAX_ENABLE 0x00000004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ QUOTA_LIMITS_HARDWS_MAX_DISABLE 0x00000008

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _QUOTA_LIMITS_EX {
      ਮਾਪ_T Paged_Pool_ਹੱਦਬੰਦੀ;
      ਮਾਪ_T Non_Paged_Pool_ਹੱਦਬੰਦੀ;
      ਮਾਪ_T Minimum_Working_ਸੈੱਟ_ਮਾਪ;
      ਮਾਪ_T ਵੱਧ_ਤੋਂ_ਵੱਧ_Working_ਸੈੱਟ_ਮਾਪ;
      ਮਾਪ_T Pagefile_ਹੱਦਬੰਦੀ;
      LARGE_INTEGER ਸਮਾਂ_ਹੱਦਬੰਦੀ;
      ਮਾਪ_T Reserved1;
      ਮਾਪ_T Reserved2;
      ਮਾਪ_T Reserved3;
      ਮਾਪ_T Reserved4;
      DWORD Flags;
      DWORD Reserved5;
    } QUOTA_LIMITS_EX,*PQUOTA_LIMITS_EX;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _IO_COUNTERS {
      ULONGLONG Read_Operation_ਗਿਣਤੀ;
      ULONGLONG Write_Operation_ਗਿਣਤੀ;
      ULONGLONG Other_Operation_ਗਿਣਤੀ;
      ULONGLONG Read_Transfer_ਗਿਣਤੀ;
      ULONGLONG Write_Transfer_ਗਿਣਤੀ;
      ULONGLONG Other_Transfer_ਗਿਣਤੀ;
    } IO_COUNTERS;
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ IO_COUNTERS *PIO_COUNTERS;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _JOBOBJECT_BASIC_ACCOUNTING_INFORMATION {
      LARGE_INTEGER ਕੁੱਲ_User_ਸਮਾਂ;
      LARGE_INTEGER ਕੁੱਲ_Kernel_ਸਮਾਂ;
      LARGE_INTEGER This_Period_ਕੁੱਲ_User_ਸਮਾਂ;
      LARGE_INTEGER This_Period_ਕੁੱਲ_Kernel_ਸਮਾਂ;
      DWORD ਕੁੱਲ_ਪੰਨਾ_Fault_ਗਿਣਤੀ;
      DWORD ਕੁੱਲ_Processes;
      DWORD ਸਰਗਰਮ_Processes;
      DWORD ਕੁੱਲ_Terminated_Processes;
    } JOBOBJECT_BASIC_ACCOUNTING_INFORMATION,*PJOBOBJECT_BASIC_ACCOUNTING_INFORMATION;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ JOBOBJECT_BASIC_ਹੱਦਬੰਦੀ_INFORMATION {
      LARGE_INTEGER ਪ੍ਰਤੀ_Process_User_ਸਮਾਂ_ਹੱਦਬੰਦੀ;
      LARGE_INTEGER ਪ੍ਰਤੀ_ਕੰਮ_User_ਸਮਾਂ_ਹੱਦਬੰਦੀ;
      DWORD ਹੱਦਬੰਦੀ_Flags;
      ਮਾਪ_T Minimum_Working_ਸੈੱਟ_ਮਾਪ;
      ਮਾਪ_T ਵੱਧ_ਤੋਂ_ਵੱਧ_Working_ਸੈੱਟ_ਮਾਪ;
      DWORD ਸਰਗਰਮ_Process_ਹੱਦਬੰਦੀ;
      ULONG_PTR Affinity;
      DWORD ਤਰਜੀਹ_Class;
      DWORD SchedulingClass;
    } JOBOBJECT_BASIC_ਹੱਦਬੰਦੀ_INFORMATION_2,*PJOBOBJECT_BASIC_ਹੱਦਬੰਦੀ_INFORMATION;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ JOBOBJECT_EXTENDED_ਹੱਦਬੰਦੀ_INFORMATION {
      JOBOBJECT_BASIC_ਹੱਦਬੰਦੀ_INFORMATION_2 Basic_ਹੱਦਬੰਦੀ_Information;
      IO_COUNTERS IoInfo;
      ਮਾਪ_T Process_ਸਮ੍ਰਿਤੀ_ਹੱਦਬੰਦੀ;
      ਮਾਪ_T ਕੰਮ_ਸਮ੍ਰਿਤੀ_ਹੱਦਬੰਦੀ;
      ਮਾਪ_T Peak_Process_ਸਮ੍ਰਿਤੀ_ਵਰਤਿਆ;
      ਮਾਪ_T Peak_ਕੰਮ_ਸਮ੍ਰਿਤੀ_ਵਰਤਿਆ;
    } JOBOBJECT_EXTENDED_ਹੱਦਬੰਦੀ_INFORMATION_2,*PJOBOBJECT_EXTENDED_ਹੱਦਬੰਦੀ_INFORMATION;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _JOBOBJECT_BASIC_PROCESS_ID_LIST {
      DWORD ਸੰਖਿਆ_ਦਾ_Assigned_Processes;
      DWORD ਸੰਖਿਆ_ਦਾ_Process_Ids_ਵਿੱਚ_List;
      ULONG_PTR ProcessIdList[1];
    } JOBOBJECT_BASIC_PROCESS_ID_LIST,*PJOBOBJECT_BASIC_PROCESS_ID_LIST;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _JOBOBJECT_BASIC_UI_RESTRICTIONS {
      DWORD UIRestrictionsClass;
    } JOBOBJECT_BASIC_UI_RESTRICTIONS,*PJOBOBJECT_BASIC_UI_RESTRICTIONS;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ JOBOBJECT_SECURITY_ਹੱਦਬੰਦੀ_INFORMATION {
      DWORD Security_ਹੱਦਬੰਦੀ_Flags;
      HANDLE ਕੰਮ_Token;
      PTOKEN_GROUPS Sids_ਮੰਜ਼ਿਲ_Disable;
      PTOKEN_PRIVILEGES Privileges_ਮੰਜ਼ਿਲ_Delete;
      PTOKEN_GROUPS RestrictedSids;
    } JOBOBJECT_SECURITY_ਹੱਦਬੰਦੀ_INFORMATION_2,*PJOBOBJECT_SECURITY_ਹੱਦਬੰਦੀ_INFORMATION;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ JOBOBJECT_ਸਿਰਾ_ਦਾ_ਕੰਮ_ਸਮਾਂ_INFORMATION {
      DWORD ਸਿਰਾ_ਦਾ_ਕੰਮ_ਸਮਾਂ_Action;
    } JOBOBJECT_ਸਿਰਾ_ਦਾ_ਕੰਮ_ਸਮਾਂ_INFORMATION_2,*PJOBOBJECT_ਸਿਰਾ_ਦਾ_ਕੰਮ_ਸਮਾਂ_INFORMATION;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ JOBOBJECT_ASSOCIATE_COMPLETION_ਪੋਰਟ {
      PVOID Completion_ਕੁੰਜੀ;
      HANDLE Completion_ਪੋਰਟ;
    } JOBOBJECT_ASSOCIATE_COMPLETION_ਪੋਰਟ_2,*PJOBOBJECT_ASSOCIATE_COMPLETION_ਪੋਰਟ;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _JOBOBJECT_BASIC_AND_IO_ACCOUNTING_INFORMATION {
      JOBOBJECT_BASIC_ACCOUNTING_INFORMATION BasicInfo;
      IO_COUNTERS IoInfo;
    } JOBOBJECT_BASIC_AND_IO_ACCOUNTING_INFORMATION,*PJOBOBJECT_BASIC_AND_IO_ACCOUNTING_INFORMATION;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _JOBOBJECT_JOBSET_INFORMATION {
      DWORD MemberLevel;
    } JOBOBJECT_JOBSET_INFORMATION,*PJOBOBJECT_JOBSET_INFORMATION;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_TERMINATE_AT_ਸਿਰਾ_ਦਾ_ਕੰਮ 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_POST_AT_ਸਿਰਾ_ਦਾ_ਕੰਮ 1

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_ਸੁਨੇਹਾ_ਸਿਰਾ_ਦਾ_ਕੰਮ_ਸਮਾਂ 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_ਸੁਨੇਹਾ_ਸਿਰਾ_ਦਾ_PROCESS_ਸਮਾਂ 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_ਸੁਨੇਹਾ_ਸਰਗਰਮ_PROCESS_ਹੱਦਬੰਦੀ 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_ਸੁਨੇਹਾ_ਸਰਗਰਮ_PROCESS_ZERO 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_ਸੁਨੇਹਾ_NEW_PROCESS 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_ਸੁਨੇਹਾ_EXIT_PROCESS 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_ਸੁਨੇਹਾ_ABNORMAL_EXIT_PROCESS 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_ਸੁਨੇਹਾ_PROCESS_ਸਮ੍ਰਿਤੀ_ਹੱਦਬੰਦੀ 9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_ਸੁਨੇਹਾ_ਕੰਮ_ਸਮ੍ਰਿਤੀ_ਹੱਦਬੰਦੀ 10

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_ਹੱਦਬੰਦੀ_WORKINGSET 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_ਹੱਦਬੰਦੀ_PROCESS_ਸਮਾਂ 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_ਹੱਦਬੰਦੀ_ਕੰਮ_ਸਮਾਂ 0x00000004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_ਹੱਦਬੰਦੀ_ਸਰਗਰਮ_PROCESS 0x00000008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_ਹੱਦਬੰਦੀ_AFFINITY 0x00000010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_ਹੱਦਬੰਦੀ_ਤਰਜੀਹ_CLASS 0x00000020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_ਹੱਦਬੰਦੀ_PRESERVE_ਕੰਮ_ਸਮਾਂ 0x00000040
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_ਹੱਦਬੰਦੀ_SCHEDULING_CLASS 0x00000080

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_ਹੱਦਬੰਦੀ_PROCESS_ਸਮ੍ਰਿਤੀ 0x00000100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_ਹੱਦਬੰਦੀ_ਕੰਮ_ਸਮ੍ਰਿਤੀ 0x00000200
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_ਹੱਦਬੰਦੀ_DIE_ON_UNHANDLED_EXCEPTION 0x00000400
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_ਹੱਦਬੰਦੀ_BREAKAWAY_OK 0x00000800
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_ਹੱਦਬੰਦੀ_SILENT_BREAKAWAY_OK 0x00001000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_ਹੱਦਬੰਦੀ_KILL_ON_ਕੰਮ_CLOSE 0x00002000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_ਹੱਦਬੰਦੀ_RESERVED2 0x00004000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_ਹੱਦਬੰਦੀ_RESERVED3 0x00008000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_ਹੱਦਬੰਦੀ_RESERVED4 0x00010000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_ਹੱਦਬੰਦੀ_RESERVED5 0x00020000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_ਹੱਦਬੰਦੀ_RESERVED6 0x00040000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_ਹੱਦਬੰਦੀ_VALID_FLAGS 0x0007ffff

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_BASIC_ਹੱਦਬੰਦੀ_VALID_FLAGS 0x000000ff
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_EXTENDED_ਹੱਦਬੰਦੀ_VALID_FLAGS 0x00003fff
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_RESERVED_ਹੱਦਬੰਦੀ_VALID_FLAGS 0x0007ffff

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_UILIMIT_NONE 0x00000000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_UILIMIT_HANDLES 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_UILIMIT_READCLIPBOARD 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_UILIMIT_WRITECLIPBOARD 0x00000004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_UILIMIT_SYSTEMPARAMETERS 0x00000008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_UILIMIT_DISPLAYSETTINGS 0x00000010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_UILIMIT_GLOBALATOMS 0x00000020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_UILIMIT_DESKTOP 0x00000040
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_UILIMIT_EXITWINDOWS 0x00000080

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_UILIMIT_ALL 0x000000FF

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_UI_VALID_FLAGS 0x000000FF

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_SECURITY_NO_ADMIN 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_SECURITY_RESTRICTED_TOKEN 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_SECURITY_ONLY_TOKEN 0x00000004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_SECURITY_FILTER_ਟੋਕਨ 0x00000008

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੰਮ_OBJECT_SECURITY_VALID_FLAGS 0x0000000f

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਗਿਣਤੀ _JOBOBJECTINFOCLASS {
      ਕੰਮ_Object_Basic_Accounting_Information = 1,ਕੰਮ_Object_Basic_ਹੱਦਬੰਦੀ_Information,ਕੰਮ_Object_Basic_Process_Id_List,ਕੰਮ_Object_Basic_UIRestrictions,
      ਕੰਮ_Object_Security_ਹੱਦਬੰਦੀ_Information,ਕੰਮ_Object_ਸਿਰਾ_ਦਾ_ਕੰਮ_ਸਮਾਂ_Information,ਕੰਮ_Object_Associate_Completion_ਪੋਰਟ_Information,
      ਕੰਮ_Object_Basic_And_Io_Accounting_Information,ਕੰਮ_Object_Extended_ਹੱਦਬੰਦੀ_Information,ਕੰਮ_Object_ਕੰਮ_ਸੈੱਟ_Information,Max_ਕੰਮ_Object_Info_Class
    } JOBOBJECTINFOCLASS;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENT_MODIFY_STATE 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENT_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x3)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MUTANT_QUERY_STATE 0x0001

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MUTANT_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE| MUTANT_QUERY_STATE)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SEMAPHORE_MODIFY_STATE 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SEMAPHORE_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x3)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TIMER_QUERY_STATE 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TIMER_MODIFY_STATE 0x0002

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TIMER_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE| TIMER_QUERY_STATE|TIMER_MODIFY_STATE)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਮਾਂ_ZONE_ID_UNKNOWN 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਮਾਂ_ZONE_ID_STANDARD 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਮਾਂ_ZONE_ID_DAYLIGHT 2

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਗਿਣਤੀ _LOGICAL_PROCESSOR_RELATIONSHIP {
      ਸਬੰਧ_Processor_Core,ਸਬੰਧ_Numa_ਗੰਢ,ਸਬੰਧ_Cache
    } LOGICAL_PROCESSOR_RELATIONSHIP;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LTP_PC_SMT 0x1

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਗਿਣਤੀ _PROCESSOR_CACHE_TYPE {
      CacheUnified,CacheInstruction,Cache_ਅੰਕੜੇ,CacheTrace
    } PROCESSOR_CACHE_TYPE;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CACHE_FULLY_ASSOCIATIVE 0xFF

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _CACHE_DESCRIPTOR {
      BYTE Level;
      BYTE Associativity;
      ਸ਼ਬਦ_3 ਸਤਰ_ਮਾਪ_2;
      DWORD ਮਾਪ_3;
      PROCESSOR_CACHE_TYPE Type;
    } CACHE_DESCRIPTOR,*PCACHE_DESCRIPTOR;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _SYSTEM_LOGICAL_PROCESSOR_INFORMATION {
      ULONG_PTR Processor_ਨਕਾਬ;
      LOGICAL_PROCESSOR_RELATIONSHIP Relationship;
      ਸੰਘ {
	ਬਣਤਰ {
	  BYTE Flags;
	} ProcessorCore;
	ਬਣਤਰ {
	  DWORD ਗੰਢ_ਸੰਖਿਆ;
	} Numa_ਗੰਢ;
	CACHE_DESCRIPTOR Cache;
	ULONGLONG Reserved[2];
      };
    } SYSTEM_LOGICAL_PROCESSOR_INFORMATION,*PSYSTEM_LOGICAL_PROCESSOR_INFORMATION;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESSOR_INTEL_386 386
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESSOR_INTEL_486 486
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESSOR_INTEL_PENTIUM 586
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESSOR_INTEL_IA64 2200
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESSOR_AMD_X8664 8664
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESSOR_MIPS_R4000 4000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESSOR_ALPHA_21064 21064
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESSOR_PPC_601 601
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESSOR_PPC_603 603
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESSOR_PPC_604 604
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESSOR_PPC_620 620
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESSOR_HITACHI_SH3 10003
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESSOR_HITACHI_SH3E 10004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESSOR_HITACHI_SH4 10005
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESSOR_MOTOROLA_821 821
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESSOR_SHx_SH3 103
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESSOR_SHx_SH4 104
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESSOR_STRONGARM 2577
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESSOR_ARM720 1824
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESSOR_ARM820 2080
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESSOR_ARM920 2336
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESSOR_ARM_7TDMI 70001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESSOR_OPTIL 0x494f

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESSOR_ARCHITECTURE_INTEL 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESSOR_ARCHITECTURE_MIPS 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESSOR_ARCHITECTURE_ALPHA 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESSOR_ARCHITECTURE_PPC 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESSOR_ARCHITECTURE_SHX 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESSOR_ARCHITECTURE_ARM 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESSOR_ARCHITECTURE_IA64 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESSOR_ARCHITECTURE_ALPHA64 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESSOR_ARCHITECTURE_MSIL 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESSOR_ARCHITECTURE_AMD64 9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESSOR_ARCHITECTURE_IA32_ON_WIN64 10

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESSOR_ARCHITECTURE_UNKNOWN 0xFFFF

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PF_FLOATING_ਬਿੰਦੂ_PRECISION_ERRATA 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PF_FLOATING_ਬਿੰਦੂ_EMULATED 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PF_COMPARE_EXCHANGE_DOUBLE 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PF_MMX_INSTRUCTIONS_ਉਪਲਬਧ 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PF_PPC_MOVEMEM_64_ਦੋਆਧਾਰੀ_ਅੰਕ_OK 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PF_ALPHA_BYTE_INSTRUCTIONS 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PF_XMMI_INSTRUCTIONS_ਉਪਲਬਧ 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PF_3_DNOW_INSTRUCTIONS_ਉਪਲਬਧ 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PF_RDTSC_INSTRUCTION_ਉਪਲਬਧ 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PF_PAE_ENABLED 9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PF_XMMI64_INSTRUCTIONS_ਉਪਲਬਧ 10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PF_SSE_DAZ_ਬਹੁਲਕ_ਉਪਲਬਧ 11
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PF_NX_ENABLED 12

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਸਮ੍ਰਿਤੀ_BASIC_INFORMATION_2 {
      PVOID ਅਧਾਰ_ਪਤਾ;
      PVOID ਵੰਡ_ਅਧਾਰ;
      DWORD ਵੰਡ_Protect;
      ਮਾਪ_T Region_ਮਾਪ;
      DWORD State;
      DWORD Protect;
      DWORD Type;
    } ਸਮ੍ਰਿਤੀ_BASIC_INFORMATION,*PMEMORY_BASIC_INFORMATION;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਸਮ੍ਰਿਤੀ_BASIC_INFORMATION32 {
      DWORD ਅਧਾਰ_ਪਤਾ;
      DWORD ਵੰਡ_ਅਧਾਰ;
      DWORD ਵੰਡ_Protect;
      DWORD Region_ਮਾਪ;
      DWORD State;
      DWORD Protect;
      DWORD Type;
    } ਸਮ੍ਰਿਤੀ_BASIC_INFORMATION32_2,*PMEMORY_BASIC_INFORMATION32;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ DECLSPEC_ALIGN(16) ਸਮ੍ਰਿਤੀ_BASIC_INFORMATION64 {
      ULONGLONG ਅਧਾਰ_ਪਤਾ;
      ULONGLONG ਵੰਡ_ਅਧਾਰ;
      DWORD ਵੰਡ_Protect;
      DWORD __alignment1;
      ULONGLONG Region_ਮਾਪ;
      DWORD State;
      DWORD Protect;
      DWORD Type;
      DWORD __alignment2;
    } ਸਮ੍ਰਿਤੀ_BASIC_INFORMATION64_2,*PMEMORY_BASIC_INFORMATION64;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECTION_QUERY 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECTION_MAP_WRITE 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECTION_MAP_READ 0x0004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECTION_MAP_EXECUTE 0x0008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECTION_EXTEND_ਮਾਪ 0x0010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECTION_MAP_EXECUTE_EXPLICIT 0x0020

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECTION_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SECTION_QUERY| SECTION_MAP_WRITE | SECTION_MAP_READ | SECTION_MAP_EXECUTE | SECTION_EXTEND_ਮਾਪ)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਪੰਨਾ_NOACCESS 0x01
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਪੰਨਾ_READONLY 0x02
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਪੰਨਾ_READWRITE 0x04
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਪੰਨਾ_WRITECOPY 0x08
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਪੰਨਾ_EXECUTE 0x10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਪੰਨਾ_EXECUTE_READ 0x20
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਪੰਨਾ_EXECUTE_READWRITE 0x40
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਪੰਨਾ_EXECUTE_WRITECOPY 0x80
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਪੰਨਾ_GUARD 0x100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਪੰਨਾ_NOCACHE 0x200
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਪੰਨਾ_WRITECOMBINE 0x400
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MEM_COMMIT 0x1000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MEM_RESERVE 0x2000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MEM_DECOMMIT 0x4000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MEM_RELEASE 0x8000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MEM_FREE 0x10000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MEM_ਨਿੱਜੀ 0x20000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MEM_MAPPED 0x40000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MEM_RESET 0x80000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MEM_ਸਿਖਰ_ਥੱਲੇ 0x100000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MEM_WRITE_WATCH 0x200000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MEM_PHYSICAL 0x400000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MEM_LARGE_ਪੰਨੇ 0x20000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MEM_4_MB_ਪੰਨੇ 0x80000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SEC_FILE 0x800000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SEC_IMAGE 0x1000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SEC_RESERVE 0x4000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SEC_COMMIT 0x8000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SEC_NOCACHE 0x10000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SEC_LARGE_ਪੰਨੇ 0x80000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MEM_IMAGE SEC_IMAGE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WRITE_WATCH_FLAG_RESET 0x01

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_READ_ਅੰਕੜੇ (0x0001)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_LIST_DIRECTORY (0x0001)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_WRITE_ਅੰਕੜੇ (0x0002)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_ਜੋੜੋ_FILE (0x0002)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_APPEND_ਅੰਕੜੇ (0x0004)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_ਜੋੜੋ_SUBDIRECTORY (0x0004)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_CREATE_PIPE_INSTANCE (0x0004)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_READ_EA (0x0008)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_WRITE_EA (0x0010)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_EXECUTE (0x0020)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_TRAVERSE (0x0020)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_DELETE_ਬੱਚਾ (0x0040)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_READ_ਗੁਣ (0x0080)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_WRITE_ਗੁਣ (0x0100)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0x1FF)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_GENERIC_READ (STANDARD_RIGHTS_READ | FILE_READ_ਅੰਕੜੇ | FILE_READ_ਗੁਣ | FILE_READ_EA | SYNCHRONIZE)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_GENERIC_WRITE (STANDARD_RIGHTS_WRITE | FILE_WRITE_ਅੰਕੜੇ | FILE_WRITE_ਗੁਣ | FILE_WRITE_EA | FILE_APPEND_ਅੰਕੜੇ | SYNCHRONIZE)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_GENERIC_EXECUTE (STANDARD_RIGHTS_EXECUTE | FILE_READ_ਗੁਣ | FILE_EXECUTE | SYNCHRONIZE)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_SHARE_READ 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_SHARE_WRITE 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_SHARE_DELETE 0x00000004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_ATTRIBUTE_READONLY 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_ATTRIBUTE_HIDDEN 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_ATTRIBUTE_SYSTEM 0x00000004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_ATTRIBUTE_DIRECTORY 0x00000010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_ATTRIBUTE_ARCHIVE 0x00000020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_ATTRIBUTE_DEVICE 0x00000040
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_ATTRIBUTE_ਸਾਧਾਰਨ 0x00000080
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_ATTRIBUTE_TEMPORARY 0x00000100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_ATTRIBUTE_SPARSE_FILE 0x00000200
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_ATTRIBUTE_REPARSE_ਬਿੰਦੂ 0x00000400
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_ATTRIBUTE_COMPRESSED 0x00000800
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_ATTRIBUTE_OFFLINE 0x00001000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_ATTRIBUTE_NOT_CONTENT_ਸੂਚਕਾਂਕਿਤ 0x00002000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_ATTRIBUTE_ENCRYPTED 0x00004000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_NOTIFY_CHANGE_FILE_NAME 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_NOTIFY_CHANGE_DIR_NAME 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_NOTIFY_CHANGE_ਗੁਣ 0x00000004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_NOTIFY_CHANGE_ਮਾਪ 0x00000008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_NOTIFY_CHANGE_ਆਖਰੀ_WRITE 0x00000010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_NOTIFY_CHANGE_ਆਖਰੀ_ACCESS 0x00000020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_NOTIFY_CHANGE_CREATION 0x00000040
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_NOTIFY_CHANGE_SECURITY 0x00000100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_ACTION_ADDED 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_ACTION_REMOVED 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_ACTION_MODIFIED 0x00000003
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_ACTION_RENAMED_OLD_NAME 0x00000004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_ACTION_RENAMED_NEW_NAME 0x00000005
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAILSLOT_NO_ਸੁਨੇਹਾ ((DWORD)-1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAILSLOT_WAIT_FOREVER ((DWORD)-1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_CASE_SENSITIVE_ਖੋਜ 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_CASE_PRESERVED_ਨਾਂ 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_UNICODE_ON_DISK 0x00000004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_PERSISTENT_ACLS 0x00000008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_FILE_COMPRESSION 0x00000010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_VOLUME_QUOTAS 0x00000020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_SUPPORTS_SPARSE_FILES 0x00000040
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_SUPPORTS_REPARSE_POINTS 0x00000080
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_SUPPORTS_REMOTE_STORAGE 0x00000100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_VOLUME_IS_COMPRESSED 0x00008000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_SUPPORTS_OBJECT_IDS 0x00010000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_SUPPORTS_ENCRYPTION 0x00020000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_NAMED_STREAMS 0x00040000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_READ_ONLY_VOLUME 0x00080000

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _FILE_NOTIFY_INFORMATION {
      DWORD ਅਗਲਾ_ਇੰਦਰਾਜ_ਵਿੱਥ;
      DWORD Action;
      DWORD File_Name_ਲੰਮਾਈ;
      WCHAR FileName[1];
    } FILE_NOTIFY_INFORMATION,*PFILE_NOTIFY_INFORMATION;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਸੰਘ _FILE_SEGMENT_ELEMENT {
      PVOID64 ਬਫਰ_3;
      ULONGLONG Alignment;
    }FILE_SEGMENT_ELEMENT,*PFILE_SEGMENT_ELEMENT;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ REPARSE_GUID_ਅੰਕੜੇ_ਬਫਰ {
      DWORD Reparse_ਟੈਗ;
      ਸ਼ਬਦ_3 Reparse_ਅੰਕੜੇ_ਲੰਮਾਈ;
      ਸ਼ਬਦ_3 Reserved;
      GUID ReparseGuid;
      ਬਣਤਰ {
	BYTE ਅੰਕੜੇ_ਬਫਰ[1];
      } Generic_Reparse_ਬਫਰ;
    } REPARSE_GUID_ਅੰਕੜੇ_ਬਫਰ_2,*PREPARSE_GUID_ਅੰਕੜੇ_ਬਫਰ;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REPARSE_GUID_ਅੰਕੜੇ_ਬਫਰ_ਸਿਰਲੇਖ_ਮਾਪ ਖੇਤਰ_ਵਿੱਥ(REPARSE_GUID_ਅੰਕੜੇ_ਬਫਰ_2,Generic_Reparse_ਬਫਰ)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਵੱਧ_ਤੋਂ_ਵੱਧ_REPARSE_ਅੰਕੜੇ_ਬਫਰ_ਮਾਪ (16 *1024)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IO_REPARSE_ਟੈਗ_RESERVED_ZERO (0)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IO_REPARSE_ਟੈਗ_RESERVED_ONE (1)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IO_REPARSE_ਟੈਗ_RESERVED_RANGE IO_REPARSE_ਟੈਗ_RESERVED_ONE

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Is_Reparse_ਟੈਗ_Microsoft(ਟੈਗ_2) (((ਟੈਗ_2) & 0x80000000))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Is_Reparse_ਟੈਗ_Name_Surrogate(ਟੈਗ_2) (((ਟੈਗ_2) & 0x20000000))

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IO_REPARSE_ਟੈਗ_MOUNT_ਬਿੰਦੂ (0xA0000003L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IO_REPARSE_ਟੈਗ_HSM (0xC0000004L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IO_REPARSE_ਟੈਗ_SIS (0x80000007L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IO_REPARSE_ਟੈਗ_DFS (0x8000000AL)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IO_REPARSE_ਟੈਗ_FILTER_MANAGER (0x8000000BL)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IO_COMPLETION_MODIFY_STATE 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IO_COMPLETION_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x3)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DUPLICATE_CLOSE_ਸਰੋਤ 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DUPLICATE_SAME_ACCESS 0x00000002

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਗਿਣਤੀ _SYSTEM_POWER_STATE {
      PowerSystemUnspecified = 0,PowerSystemWorking = 1,PowerSystemSleeping1 = 2,PowerSystemSleeping2 = 3,PowerSystemSleeping3 = 4,PowerSystemHibernate = 5,PowerSystemShutdown = 6,Power_System_ਵੱਧ_ਤੋਂ_ਵੱਧ = 7
    } SYSTEM_POWER_STATE,*PSYSTEM_POWER_STATE;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ POWER_SYSTEM_ਵੱਧ_ਤੋਂ_ਵੱਧ 7

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਗਿਣਤੀ {
      PowerActionNone = 0,PowerActionReserved,PowerActionSleep,PowerActionHibernate,PowerActionShutdown,PowerActionShutdownReset,PowerActionShutdownOff,PowerActionWarmEject
    } POWER_ACTION,*PPOWER_ACTION;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਗਿਣਤੀ _DEVICE_POWER_STATE {
      PowerDeviceUnspecified = 0,PowerDeviceD0,PowerDeviceD1,PowerDeviceD2,PowerDeviceD3,Power_Device_ਵੱਧ_ਤੋਂ_ਵੱਧ
    } DEVICE_POWER_STATE,*PDEVICE_POWER_STATE;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ES_SYSTEM_REQUIRED ((DWORD)0x00000001)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ES_DISPLAY_REQUIRED ((DWORD)0x00000002)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ES_USER_PRESENT ((DWORD)0x00000004)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ES_CONTINUOUS ((DWORD)0x80000000)

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ DWORD EXECUTION_STATE;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਗਿਣਤੀ {
      LT_DONT_CARE,LT_ਸਭ_ਤੋਂ_ਨੀਵਾਂ_LATENCY
    } LATENCY_ਸਮਾਂ;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PDCAP_D0_SUPPORTED 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PDCAP_D1_SUPPORTED 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PDCAP_D2_SUPPORTED 0x00000004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PDCAP_D3_SUPPORTED 0x00000008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PDCAP_WAKE_FROM_D0_SUPPORTED 0x00000010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PDCAP_WAKE_FROM_D1_SUPPORTED 0x00000020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PDCAP_WAKE_FROM_D2_SUPPORTED 0x00000040
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PDCAP_WAKE_FROM_D3_SUPPORTED 0x00000080
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PDCAP_WARM_EJECT_SUPPORTED 0x00000100

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ CM_Power_ਅੰਕੜੇ_s {
      DWORD PD_ਮਾਪ;
      DEVICE_POWER_STATE PD_MostRecentPowerState;
      DWORD PD_Capabilities;
      DWORD PD_D1Latency;
      DWORD PD_D2Latency;
      DWORD PD_D3Latency;
      DEVICE_POWER_STATE PD_PowerStateMapping[POWER_SYSTEM_ਵੱਧ_ਤੋਂ_ਵੱਧ];
      SYSTEM_POWER_STATE PD_ਸਭ_ਤੋਂ_ਡੂੰਘਾ_System_Wake;
    } CM_POWER_ਅੰਕੜੇ,*PCM_POWER_ਅੰਕੜੇ;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਗਿਣਤੀ {
      SystemPowerPolicyAc,SystemPowerPolicyDc,VerifySystemPolicyAc,VerifySystemPolicyDc,SystemPowerCapabilities,SystemBatteryState,SystemPowerStateHandler,ProcessorStateHandler,SystemPowerPolicyCurrent,AdministratorPowerPolicy,SystemReserveHiberFile,ProcessorInformation,SystemPowerInformation,ProcessorStateHandler2,ਆਖਰੀ_Wake_ਸਮਾਂ,ਆਖਰੀ_Sleep_ਸਮਾਂ,SystemExecutionState,SystemPowerStateNotifyHandler,ProcessorPowerPolicyAc,ProcessorPowerPolicyDc,VerifyProcessorPowerPolicyAc,VerifyProcessorPowerPolicyDc,ProcessorPowerPolicyCurrent,SystemPowerStateLogging,System_Power_Logging_ਇੰਦਰਾਜ
    } POWER_INFORMATION_LEVEL;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ {
      DWORD Granularity;
      DWORD ਸਮਰੱਥਾ;
    } BATTERY_REPORTING_SCALE,*PBATTERY_REPORTING_SCALE;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ {
      POWER_ACTION Action;
      DWORD Flags;
      DWORD Event_ਕੋਡ;
    } POWER_ACTION_POLICY,*PPOWER_ACTION_POLICY;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ POWER_ACTION_QUERY_ALLOWED 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ POWER_ACTION_UI_ALLOWED 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ POWER_ACTION_OVERRIDE_APPS 0x00000004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ POWER_ACTION_LIGHTEST_ਪਹਿਲਾ 0x10000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ POWER_ACTION_ਤਾਲਾ_CONSOLE 0x20000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ POWER_ACTION_DISABLE_WAKES 0x40000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ POWER_ACTION_CRITICAL 0x80000000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ POWER_LEVEL_USER_NOTIFY_ਪਾਠ 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ POWER_LEVEL_USER_NOTIFY_SOUND 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ POWER_LEVEL_USER_NOTIFY_EXEC 0x00000004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ POWER_USER_NOTIFY_BUTTON 0x00000008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ POWER_USER_NOTIFY_SHUTDOWN 0x00000010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ POWER_FORCE_TRIGGER_RESET 0x80000000

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ {
      BOOLEAN Enable;
      BYTE ਵਾਧੂ_2[3];
      DWORD BatteryLevel;
      POWER_ACTION_POLICY PowerPolicy;
      SYSTEM_POWER_STATE MinSystemState;
    } SYSTEM_POWER_LEVEL,*PSYSTEM_POWER_LEVEL;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਅੰਕ_DISCHARGE_POLICIES 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DISCHARGE_POLICY_CRITICAL 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DISCHARGE_POLICY_ਨੀਵਾਂ 1

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PO_THROTTLE_NONE 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PO_THROTTLE_CONSTANT 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PO_THROTTLE_DEGRADE 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PO_THROTTLE_ADAPTIVE 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PO_THROTTLE_ਵੱਧ_ਤੋਂ_ਵੱਧ 4

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _SYSTEM_POWER_POLICY {
      DWORD Revision;
      POWER_ACTION_POLICY PowerButton;
      POWER_ACTION_POLICY SleepButton;
      POWER_ACTION_POLICY LidClose;
      SYSTEM_POWER_STATE LidOpenWake;
      DWORD Reserved;
      POWER_ACTION_POLICY Idle;
      DWORD IdleTimeout;
      BYTE Idle_ਸੰਵੇਦਨਸ਼ੀਲਤਾ;
      BYTE DynamicThrottle;
      BYTE Spare2[2];
      SYSTEM_POWER_STATE MinSleep;
      SYSTEM_POWER_STATE MaxSleep;
      SYSTEM_POWER_STATE ReducedLatencySleep;
      DWORD WinLogonFlags;
      DWORD Spare3;
      DWORD DozeS4Timeout;
      DWORD ਪ੍ਰਸਾਰਣ_ਸਮਰੱਥਾ_Resolution;
      SYSTEM_POWER_LEVEL DischargePolicy[ਅੰਕ_DISCHARGE_POLICIES];
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

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _PROCESSOR_POWER_POLICY_INFO {
      DWORD ਸਮਾਂ_Check;
      DWORD Demote_ਹੱਦਬੰਦੀ;
      DWORD Promote_ਹੱਦਬੰਦੀ;
      BYTE DemotePercent;
      BYTE PromotePercent;
      BYTE ਵਾਧੂ_2[2];
      DWORD AllowDemotion:1;
      DWORD AllowPromotion:1;
      DWORD Reserved:30;
    } PROCESSOR_POWER_POLICY_INFO,*PPROCESSOR_POWER_POLICY_INFO;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _PROCESSOR_POWER_POLICY {
      DWORD Revision;
      BYTE DynamicThrottle;
      BYTE ਵਾਧੂ_2[3];
      DWORD DisableCStates:1;
      DWORD Reserved:31;
      DWORD Policy_ਗਿਣਤੀ;
      PROCESSOR_POWER_POLICY_INFO Policy[3];
    } PROCESSOR_POWER_POLICY,*PPROCESSOR_POWER_POLICY;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _ADMINISTRATOR_POWER_POLICY {
      SYSTEM_POWER_STATE MinSleep;
      SYSTEM_POWER_STATE MaxSleep;
      DWORD MinVideoTimeout;
      DWORD MaxVideoTimeout;
      DWORD MinSpindownTimeout;
      DWORD MaxSpindownTimeout;
    } ADMINISTRATOR_POWER_POLICY,*PADMINISTRATOR_POWER_POLICY;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ {
      BOOLEAN PowerButtonPresent;
      BOOLEAN SleepButtonPresent;
      BOOLEAN LidPresent;
      BOOLEAN SystemS1;
      BOOLEAN SystemS2;
      BOOLEAN SystemS3;
      BOOLEAN SystemS4;
      BOOLEAN SystemS5;
      BOOLEAN HiberFilePresent;
      BOOLEAN ਭਰਿਆ_Wake;
      BOOLEAN VideoDimPresent;
      BOOLEAN ApmPresent;
      BOOLEAN UpsPresent;
      BOOLEAN ThermalControl;
      BOOLEAN ProcessorThrottle;
      BYTE ProcessorMinThrottle;
      BYTE ProcessorMaxThrottle;
      BYTE spare2[4];
      BOOLEAN Disk_Spin_ਥੱਲੇ;
      BYTE spare3[8];
      BOOLEAN SystemBatteriesPresent;
      BOOLEAN Batteries_Are_Short_ਪਦ;
      BATTERY_REPORTING_SCALE BatteryScale[3];
      SYSTEM_POWER_STATE Ac_On_ਸਤਰ_Wake;
      SYSTEM_POWER_STATE SoftLidWake;
      SYSTEM_POWER_STATE RtcWake;
      SYSTEM_POWER_STATE MinDeviceWakeState;
      SYSTEM_POWER_STATE Default_ਨੀਵਾਂ_Latency_Wake;
    } SYSTEM_POWER_CAPABILITIES,*PSYSTEM_POWER_CAPABILITIES;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ {
      BOOLEAN Ac_On_ਸਤਰ;
      BOOLEAN BatteryPresent;
      BOOLEAN Charging;
      BOOLEAN Discharging;
      BOOLEAN Spare1[4];
      DWORD Max_ਸਮਰੱਥਾ;
      DWORD ਬਚਿਆ_ਸਮਰੱਥਾ;
      DWORD ਦਰ;
      DWORD Estimated_ਸਮਾਂ;
      DWORD DefaultAlert1;
      DWORD DefaultAlert2;
    } SYSTEM_BATTERY_STATE,*PSYSTEM_BATTERY_STATE;

#ਅਨ੍ਤਰ੍ਭਾਵ "pshpack4.h"

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DOS_SIGNATURE 0x5A4D
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_OS2_SIGNATURE 0x454E
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_OS2_SIGNATURE_LE 0x454C
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_VXD_SIGNATURE 0x454C
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_NT_SIGNATURE 0x00004550

#ਅਨ੍ਤਰ੍ਭਾਵ "pshpack2.h"

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ IMAGE_DOS_ਸਿਰਲੇਖ {
      ਸ਼ਬਦ_3 e_magic;
      ਸ਼ਬਦ_3 e_cblp;
      ਸ਼ਬਦ_3 e_cp;
      ਸ਼ਬਦ_3 e_crlc;
      ਸ਼ਬਦ_3 e_cparhdr;
      ਸ਼ਬਦ_3 e_minalloc;
      ਸ਼ਬਦ_3 e_maxalloc;
      ਸ਼ਬਦ_3 e_ss;
      ਸ਼ਬਦ_3 e_sp;
      ਸ਼ਬਦ_3 e_csum;
      ਸ਼ਬਦ_3 e_ip;
      ਸ਼ਬਦ_3 e_cs;
      ਸ਼ਬਦ_3 e_lfarlc;
      ਸ਼ਬਦ_3 e_ovno;
      ਸ਼ਬਦ_3 e_res[4];
      ਸ਼ਬਦ_3 e_oemid;
      ਸ਼ਬਦ_3 e_oeminfo;
      ਸ਼ਬਦ_3 e_res2[10];
      LONG e_lfanew;
    } IMAGE_DOS_ਸਿਰਲੇਖ_2,*PIMAGE_DOS_ਸਿਰਲੇਖ;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ IMAGE_OS2_ਸਿਰਲੇਖ {
      ਸ਼ਬਦ_3 ne_magic;
      CHAR ne_ver;
      CHAR ne_rev;
      ਸ਼ਬਦ_3 ne_enttab;
      ਸ਼ਬਦ_3 ne_cbenttab;
      LONG ne_ਚੱਕਰੀ_ਜਾਂਚ;
      ਸ਼ਬਦ_3 ne_flags;
      ਸ਼ਬਦ_3 ne_autodata;
      ਸ਼ਬਦ_3 ne_ਢੇਰ;
      ਸ਼ਬਦ_3 ne_ਢੇਰ_2;
      LONG ne_csip;
      LONG ne_sssp;
      ਸ਼ਬਦ_3 ne_cseg;
      ਸ਼ਬਦ_3 ne_cmod;
      ਸ਼ਬਦ_3 ne_cbnrestab;
      ਸ਼ਬਦ_3 ne_segtab;
      ਸ਼ਬਦ_3 ne_rsrctab;
      ਸ਼ਬਦ_3 ne_restab;
      ਸ਼ਬਦ_3 ne_modtab;
      ਸ਼ਬਦ_3 ne_imptab;
      LONG ne_nrestab;
      ਸ਼ਬਦ_3 ne_cmovent;
      ਸ਼ਬਦ_3 ne_align;
      ਸ਼ਬਦ_3 ne_cres;
      BYTE ne_exetyp;
      BYTE ne_flagsothers;
      ਸ਼ਬਦ_3 ne_pretthunks;
      ਸ਼ਬਦ_3 ne_psegrefbytes;
      ਸ਼ਬਦ_3 ne_swaparea;
      ਸ਼ਬਦ_3 ne_expver;
    } IMAGE_OS2_ਸਿਰਲੇਖ_2,*PIMAGE_OS2_ਸਿਰਲੇਖ;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ IMAGE_VXD_ਸਿਰਲੇਖ {
      ਸ਼ਬਦ_3 e32_magic;
      BYTE e32_border;
      BYTE e32_worder;
      DWORD e32_level;
      ਸ਼ਬਦ_3 e32_cpu;
      ਸ਼ਬਦ_3 e32_os;
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
      ਸ਼ਬਦ_3 e32_devid;
      ਸ਼ਬਦ_3 e32_ddkver;
    } IMAGE_VXD_ਸਿਰਲੇਖ_2,*PIMAGE_VXD_ਸਿਰਲੇਖ;

#ਅਨ੍ਤਰ੍ਭਾਵ "poppack.h"

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ IMAGE_FILE_ਸਿਰਲੇਖ {
      ਸ਼ਬਦ_3 Machine;
      ਸ਼ਬਦ_3 ਸੰਖਿਆ_ਦਾ_Sections;
      DWORD ਸਮਾਂ_Date_Stamp;
      DWORD ਸੂਚਕ_ਮੰਜ਼ਿਲ_ਚਿੰਨ੍ਹ_ਸਾਰਣੀ;
      DWORD ਸੰਖਿਆ_ਦਾ_Symbols;
      ਸ਼ਬਦ_3 ਮਾਪ_ਦਾ_Optional_ਸਿਰਲੇਖ;
      ਸ਼ਬਦ_3 Characteristics;
    } IMAGE_FILE_ਸਿਰਲੇਖ_2,*PIMAGE_FILE_ਸਿਰਲੇਖ;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SIZEOF_FILE_ਸਿਰਲੇਖ 20

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_FILE_RELOCS_STRIPPED 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_FILE_EXECUTABLE_IMAGE 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_FILE_ਸਤਰ_NUMS_STRIPPED 0x0004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_FILE_LOCAL_SYMS_STRIPPED 0x0008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_FILE_AGGRESIVE_WS_TRIM 0x0010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_FILE_LARGE_ਪਤਾ_AWARE 0x0020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_FILE_ਬਾਈਟਾਂ_REVERSED_LO 0x0080
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_FILE_32_ਦੋਆਧਾਰੀ_ਅੰਕ_MACHINE 0x0100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_FILE_DEBUG_STRIPPED 0x0200
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_FILE_REMOVABLE_ਲੜੀਵਾਰ_FROM_ਅਦਲਾ_ਬਦਲੀ 0x0400
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_FILE_NET_ਲੜੀਵਾਰ_FROM_ਅਦਲਾ_ਬਦਲੀ 0x0800
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_FILE_SYSTEM 0x1000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_FILE_DLL 0x2000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_FILE_ਉੱਪਰ_SYSTEM_ONLY 0x4000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_FILE_ਬਾਈਟਾਂ_REVERSED_HI 0x8000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_FILE_MACHINE_UNKNOWN 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_FILE_MACHINE_I386 0x014c
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_FILE_MACHINE_R3000 0x0162
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_FILE_MACHINE_R4000 0x0166
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_FILE_MACHINE_R10000 0x0168
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_FILE_MACHINE_WCEMIPSV2 0x0169
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_FILE_MACHINE_ALPHA 0x0184
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_FILE_MACHINE_SH3 0x01a2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_FILE_MACHINE_SH3DSP 0x01a3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_FILE_MACHINE_SH3E 0x01a4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_FILE_MACHINE_SH4 0x01a6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_FILE_MACHINE_SH5 0x01a8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_FILE_MACHINE_ARM 0x01c0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_FILE_MACHINE_THUMB 0x01c2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_FILE_MACHINE_AM33 0x01d3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_FILE_MACHINE_POWERPC 0x01F0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_FILE_MACHINE_POWERPCFP 0x01f1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_FILE_MACHINE_IA64 0x0200
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_FILE_MACHINE_MIPS16 0x0266
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_FILE_MACHINE_ALPHA64 0x0284
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_FILE_MACHINE_MIPSFPU 0x0366
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_FILE_MACHINE_MIPSFPU16 0x0466
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_FILE_MACHINE_AXP64 IMAGE_FILE_MACHINE_ALPHA64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_FILE_MACHINE_TRICORE 0x0520
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_FILE_MACHINE_CEF 0x0CEF
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_FILE_MACHINE_EBC 0x0EBC
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_FILE_MACHINE_AMD64 0x8664
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_FILE_MACHINE_ARM64 0xAA64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_FILE_MACHINE_M32R 0x9041
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_FILE_MACHINE_CEE 0xC0EE

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ IMAGE_ਅੰਕੜੇ_DIRECTORY {
      DWORD Virtual_ਪਤਾ;
      DWORD ਮਾਪ_3;
    } IMAGE_ਅੰਕੜੇ_DIRECTORY_2,*PIMAGE_ਅੰਕੜੇ_DIRECTORY;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_NUMBEROF_DIRECTORY_ENTRIES 16

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ IMAGE_OPTIONAL_ਸਿਰਲੇਖ {

      ਸ਼ਬਦ_3 Magic;
      BYTE Major_Linker_ਸੰਸਕਰਣ;
      BYTE Minor_Linker_ਸੰਸਕਰਣ;
      DWORD ਮਾਪ_ਦਾ_ਕੋਡ;
      DWORD ਮਾਪ_ਦਾ_Initialized_ਅੰਕੜੇ;
      DWORD ਮਾਪ_ਦਾ_Uninitialized_ਅੰਕੜੇ;
      DWORD ਪਤਾ_ਦਾ_ਇੰਦਰਾਜ_ਬਿੰਦੂ;
      DWORD ਅਧਾਰ_ਦਾ_ਕੋਡ;
      DWORD ਅਧਾਰ_ਦਾ_ਅੰਕੜੇ;
      DWORD Image_ਅਧਾਰ;
      DWORD SectionAlignment;
      DWORD FileAlignment;
      ਸ਼ਬਦ_3 Major_Operating_System_ਸੰਸਕਰਣ;
      ਸ਼ਬਦ_3 Minor_Operating_System_ਸੰਸਕਰਣ;
      ਸ਼ਬਦ_3 Major_Image_ਸੰਸਕਰਣ;
      ਸ਼ਬਦ_3 Minor_Image_ਸੰਸਕਰਣ;
      ਸ਼ਬਦ_3 Major_Subsystem_ਸੰਸਕਰਣ;
      ਸ਼ਬਦ_3 Minor_Subsystem_ਸੰਸਕਰਣ;
      DWORD Win32_ਸੰਸਕਰਣ_ਮੁੱਲ;
      DWORD ਮਾਪ_ਦਾ_Image;
      DWORD ਮਾਪ_ਦਾ_ਸਿਰਲੇਖਾਂ;
      DWORD Check_ਜੋੜ;
      ਸ਼ਬਦ_3 Subsystem;
      ਸ਼ਬਦ_3 DllCharacteristics;
      DWORD ਮਾਪ_ਦਾ_ਢੇਰ_Reserve;
      DWORD ਮਾਪ_ਦਾ_ਢੇਰ_Commit;
      DWORD ਮਾਪ_ਦਾ_ਢੇਰ_Reserve_2;
      DWORD ਮਾਪ_ਦਾ_ਢੇਰ_Commit_2;
      DWORD LoaderFlags;
      DWORD ਸੰਖਿਆ_ਦਾ_Rva_And_Sizes;
      IMAGE_ਅੰਕੜੇ_DIRECTORY_2 ਅੰਕੜੇ_Directory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
    } IMAGE_OPTIONAL_HEADER32,*PIMAGE_OPTIONAL_HEADER32;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ IMAGE_ROM_OPTIONAL_ਸਿਰਲੇਖ {
      ਸ਼ਬਦ_3 Magic;
      BYTE Major_Linker_ਸੰਸਕਰਣ;
      BYTE Minor_Linker_ਸੰਸਕਰਣ;
      DWORD ਮਾਪ_ਦਾ_ਕੋਡ;
      DWORD ਮਾਪ_ਦਾ_Initialized_ਅੰਕੜੇ;
      DWORD ਮਾਪ_ਦਾ_Uninitialized_ਅੰਕੜੇ;
      DWORD ਪਤਾ_ਦਾ_ਇੰਦਰਾਜ_ਬਿੰਦੂ;
      DWORD ਅਧਾਰ_ਦਾ_ਕੋਡ;
      DWORD ਅਧਾਰ_ਦਾ_ਅੰਕੜੇ;
      DWORD ਅਧਾਰ_ਦਾ_Bss;
      DWORD Gpr_ਨਕਾਬ;
      DWORD Cpr_ਨਕਾਬ[4];
      DWORD Gp_ਮੁੱਲ;
    } IMAGE_ROM_OPTIONAL_ਸਿਰਲੇਖ_2,*PIMAGE_ROM_OPTIONAL_ਸਿਰਲੇਖ;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _IMAGE_OPTIONAL_HEADER64 {
      ਸ਼ਬਦ_3 Magic;
      BYTE Major_Linker_ਸੰਸਕਰਣ;
      BYTE Minor_Linker_ਸੰਸਕਰਣ;
      DWORD ਮਾਪ_ਦਾ_ਕੋਡ;
      DWORD ਮਾਪ_ਦਾ_Initialized_ਅੰਕੜੇ;
      DWORD ਮਾਪ_ਦਾ_Uninitialized_ਅੰਕੜੇ;
      DWORD ਪਤਾ_ਦਾ_ਇੰਦਰਾਜ_ਬਿੰਦੂ;
      DWORD ਅਧਾਰ_ਦਾ_ਕੋਡ;
      ULONGLONG Image_ਅਧਾਰ;
      DWORD SectionAlignment;
      DWORD FileAlignment;
      ਸ਼ਬਦ_3 Major_Operating_System_ਸੰਸਕਰਣ;
      ਸ਼ਬਦ_3 Minor_Operating_System_ਸੰਸਕਰਣ;
      ਸ਼ਬਦ_3 Major_Image_ਸੰਸਕਰਣ;
      ਸ਼ਬਦ_3 Minor_Image_ਸੰਸਕਰਣ;
      ਸ਼ਬਦ_3 Major_Subsystem_ਸੰਸਕਰਣ;
      ਸ਼ਬਦ_3 Minor_Subsystem_ਸੰਸਕਰਣ;
      DWORD Win32_ਸੰਸਕਰਣ_ਮੁੱਲ;
      DWORD ਮਾਪ_ਦਾ_Image;
      DWORD ਮਾਪ_ਦਾ_ਸਿਰਲੇਖਾਂ;
      DWORD Check_ਜੋੜ;
      ਸ਼ਬਦ_3 Subsystem;
      ਸ਼ਬਦ_3 DllCharacteristics;
      ULONGLONG ਮਾਪ_ਦਾ_ਢੇਰ_Reserve;
      ULONGLONG ਮਾਪ_ਦਾ_ਢੇਰ_Commit;
      ULONGLONG ਮਾਪ_ਦਾ_ਢੇਰ_Reserve_2;
      ULONGLONG ਮਾਪ_ਦਾ_ਢੇਰ_Commit_2;
      DWORD LoaderFlags;
      DWORD ਸੰਖਿਆ_ਦਾ_Rva_And_Sizes;
      IMAGE_ਅੰਕੜੇ_DIRECTORY_2 ਅੰਕੜੇ_Directory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
    } IMAGE_OPTIONAL_HEADER64,*PIMAGE_OPTIONAL_HEADER64;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SIZEOF_ROM_OPTIONAL_ਸਿਰਲੇਖ 56
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SIZEOF_STD_OPTIONAL_ਸਿਰਲੇਖ 28
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SIZEOF_NT_OPTIONAL32_ਸਿਰਲੇਖ 224
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SIZEOF_NT_OPTIONAL64_ਸਿਰਲੇਖ 240

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_NT_OPTIONAL_HDR32_MAGIC 0x10b
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_NT_OPTIONAL_HDR64_MAGIC 0x20b
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_ROM_OPTIONAL_HDR_MAGIC 0x107

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN64
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ IMAGE_OPTIONAL_HEADER64 IMAGE_OPTIONAL_ਸਿਰਲੇਖ_2;
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ PIMAGE_OPTIONAL_HEADER64 PIMAGE_OPTIONAL_ਸਿਰਲੇਖ;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SIZEOF_NT_OPTIONAL_ਸਿਰਲੇਖ IMAGE_SIZEOF_NT_OPTIONAL64_ਸਿਰਲੇਖ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_NT_OPTIONAL_HDR_MAGIC IMAGE_NT_OPTIONAL_HDR64_MAGIC
#ਨਹੀਂਤਾਂ
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ IMAGE_OPTIONAL_HEADER32 IMAGE_OPTIONAL_ਸਿਰਲੇਖ_2;
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ PIMAGE_OPTIONAL_HEADER32 PIMAGE_OPTIONAL_ਸਿਰਲੇਖ;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SIZEOF_NT_OPTIONAL_ਸਿਰਲੇਖ IMAGE_SIZEOF_NT_OPTIONAL32_ਸਿਰਲੇਖ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_NT_OPTIONAL_HDR_MAGIC IMAGE_NT_OPTIONAL_HDR32_MAGIC
#ਜੇ_ਅੰਤ

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _IMAGE_NT_HEADERS64 {
      DWORD Signature;
      IMAGE_FILE_ਸਿਰਲੇਖ_2 File_ਸਿਰਲੇਖ;
      IMAGE_OPTIONAL_HEADER64 Optional_ਸਿਰਲੇਖ;
    } IMAGE_NT_HEADERS64,*PIMAGE_NT_HEADERS64;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ IMAGE_NT_ਸਿਰਲੇਖਾਂ {
      DWORD Signature;
      IMAGE_FILE_ਸਿਰਲੇਖ_2 File_ਸਿਰਲੇਖ;
      IMAGE_OPTIONAL_HEADER32 Optional_ਸਿਰਲੇਖ;
    } IMAGE_NT_HEADERS32,*PIMAGE_NT_HEADERS32;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ IMAGE_ROM_ਸਿਰਲੇਖਾਂ {
      IMAGE_FILE_ਸਿਰਲੇਖ_2 File_ਸਿਰਲੇਖ;
      IMAGE_ROM_OPTIONAL_ਸਿਰਲੇਖ_2 Optional_ਸਿਰਲੇਖ;
    } IMAGE_ROM_ਸਿਰਲੇਖਾਂ_2,*PIMAGE_ROM_ਸਿਰਲੇਖਾਂ;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN64
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ IMAGE_NT_HEADERS64 IMAGE_NT_ਸਿਰਲੇਖਾਂ_2;
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ PIMAGE_NT_HEADERS64 PIMAGE_NT_ਸਿਰਲੇਖਾਂ;
#ਨਹੀਂਤਾਂ
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ IMAGE_NT_HEADERS32 IMAGE_NT_ਸਿਰਲੇਖਾਂ_2;
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ PIMAGE_NT_HEADERS32 PIMAGE_NT_ਸਿਰਲੇਖਾਂ;
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_ਪਹਿਲਾ_SECTION(ntheader) ((PIMAGE_SECTION_ਸਿਰਲੇਖ) ((ULONG_PTR)ntheader + ਖੇਤਰ_ਵਿੱਥ(IMAGE_NT_ਸਿਰਲੇਖਾਂ_2,Optional_ਸਿਰਲੇਖ) + ((PIMAGE_NT_ਸਿਰਲੇਖਾਂ)(ntheader))->File_ਸਿਰਲੇਖ.ਮਾਪ_ਦਾ_Optional_ਸਿਰਲੇਖ))

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SUBSYSTEM_UNKNOWN 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SUBSYSTEM_NATIVE 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SUBSYSTEM_WINDOWS_GUI 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SUBSYSTEM_WINDOWS_CUI 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SUBSYSTEM_OS2_CUI 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SUBSYSTEM_POSIX_CUI 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SUBSYSTEM_NATIVE_WINDOWS 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SUBSYSTEM_WINDOWS_CE_GUI 9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SUBSYSTEM_EFI_APPLICATION 10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SUBSYSTEM_EFI_BOOT_SERVICE_DRIVER 11
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SUBSYSTEM_EFI_RUNTIME_DRIVER 12
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SUBSYSTEM_EFI_ROM 13
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SUBSYSTEM_XBOX 14

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DLLCHARACTERISTICS_ਉੱਚਾ_ENTROPY_VA 0x0020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DLLCHARACTERISTICS_DYNAMIC_ਅਧਾਰ 0x0040
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DLLCHARACTERISTICS_FORCE_INTEGRITY 0x0080
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DLLCHARACTERISTICS_NX_COMPAT 0x0100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DLLCHARACTERISTICS_NO_ISOLATION 0x0200
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DLLCHARACTERISTICS_NO_SEH 0x0400
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DLLCHARACTERISTICS_NO_BIND 0x0800
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DLLCHARACTERISTICS_APPCONTAINER 0x1000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DLLCHARACTERISTICS_WDM_DRIVER 0x2000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DLLCHARACTERISTICS_GUARD_CF 0x4000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DLLCHARACTERISTICS_TERMINAL_SERVER_AWARE 0x8000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DIRECTORY_ਇੰਦਰਾਜ_EXPORT 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DIRECTORY_ਇੰਦਰਾਜ_IMPORT 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DIRECTORY_ਇੰਦਰਾਜ_RESOURCE 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DIRECTORY_ਇੰਦਰਾਜ_EXCEPTION 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DIRECTORY_ਇੰਦਰਾਜ_SECURITY 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DIRECTORY_ਇੰਦਰਾਜ_BASERELOC 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DIRECTORY_ਇੰਦਰਾਜ_DEBUG 6

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DIRECTORY_ਇੰਦਰਾਜ_ARCHITECTURE 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DIRECTORY_ਇੰਦਰਾਜ_GLOBALPTR 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DIRECTORY_ਇੰਦਰਾਜ_TLS 9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DIRECTORY_ਇੰਦਰਾਜ_ਲੱਦੋ_CONFIG 10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DIRECTORY_ਇੰਦਰਾਜ_BOUND_IMPORT 11
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DIRECTORY_ਇੰਦਰਾਜ_IAT 12
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DIRECTORY_ਇੰਦਰਾਜ_DELAY_IMPORT 13
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DIRECTORY_ਇੰਦਰਾਜ_COM_DESCRIPTOR 14

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ANON_OBJECT_ਸਿਰਲੇਖ {
      ਸ਼ਬਦ_3 Sig1;
      ਸ਼ਬਦ_3 Sig2;
      ਸ਼ਬਦ_3 ਸੰਸਕਰਣ_2;
      ਸ਼ਬਦ_3 Machine;
      DWORD ਸਮਾਂ_Date_Stamp;
      CLSID ClassID;
      DWORD ਮਾਪ_ਦਾ_ਅੰਕੜੇ;
    } ANON_OBJECT_ਸਿਰਲੇਖ;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SIZEOF_SHORT_NAME 8

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ IMAGE_SECTION_ਸਿਰਲੇਖ {
      BYTE Name[IMAGE_SIZEOF_SHORT_NAME];
      ਸੰਘ {
	DWORD Physical_ਪਤਾ;
	DWORD Virtual_ਮਾਪ;
      } Misc;
      DWORD Virtual_ਪਤਾ;
      DWORD ਮਾਪ_ਦਾ_Raw_ਅੰਕੜੇ;
      DWORD ਸੂਚਕ_ਮੰਜ਼ਿਲ_Raw_ਅੰਕੜੇ;
      DWORD ਸੂਚਕ_ਮੰਜ਼ਿਲ_Relocations;
      DWORD ਸੂਚਕ_ਮੰਜ਼ਿਲ_Linenumbers;
      ਸ਼ਬਦ_3 ਸੰਖਿਆ_ਦਾ_Relocations;
      ਸ਼ਬਦ_3 ਸੰਖਿਆ_ਦਾ_Linenumbers;
      DWORD Characteristics;
    } IMAGE_SECTION_ਸਿਰਲੇਖ_2,*PIMAGE_SECTION_ਸਿਰਲੇਖ;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SIZEOF_SECTION_ਸਿਰਲੇਖ 40

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SCN_TYPE_NO_PAD 0x00000008

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SCN_CNT_ਕੋਡ 0x00000020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SCN_CNT_INITIALIZED_ਅੰਕੜੇ 0x00000040
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SCN_CNT_UNINITIALIZED_ਅੰਕੜੇ 0x00000080
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SCN_LNK_OTHER 0x00000100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SCN_LNK_INFO 0x00000200
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SCN_LNK_REMOVE 0x00000800
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SCN_LNK_COMDAT 0x00001000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SCN_NO_DEFER_SPEC_EXC 0x00004000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SCN_GPREL 0x00008000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SCN_MEM_FARDATA 0x00008000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SCN_MEM_PURGEABLE 0x00020000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SCN_MEM_16_ਦੋਆਧਾਰੀ_ਅੰਕ 0x00020000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SCN_MEM_LOCKED 0x00040000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SCN_MEM_PRELOAD 0x00080000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SCN_ALIGN_1_ਬਾਈਟਾਂ 0x00100000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SCN_ALIGN_2_ਬਾਈਟਾਂ 0x00200000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SCN_ALIGN_4_ਬਾਈਟਾਂ 0x00300000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SCN_ALIGN_8_ਬਾਈਟਾਂ 0x00400000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SCN_ALIGN_16_ਬਾਈਟਾਂ 0x00500000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SCN_ALIGN_32_ਬਾਈਟਾਂ 0x00600000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SCN_ALIGN_64_ਬਾਈਟਾਂ 0x00700000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SCN_ALIGN_128_ਬਾਈਟਾਂ 0x00800000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SCN_ALIGN_256_ਬਾਈਟਾਂ 0x00900000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SCN_ALIGN_512_ਬਾਈਟਾਂ 0x00A00000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SCN_ALIGN_1024_ਬਾਈਟਾਂ 0x00B00000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SCN_ALIGN_2048_ਬਾਈਟਾਂ 0x00C00000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SCN_ALIGN_4096_ਬਾਈਟਾਂ 0x00D00000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SCN_ALIGN_8192_ਬਾਈਟਾਂ 0x00E00000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SCN_ALIGN_ਨਕਾਬ 0x00F00000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SCN_LNK_NRELOC_OVFL 0x01000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SCN_MEM_DISCARDABLE 0x02000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SCN_MEM_NOT_CACHED 0x04000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SCN_MEM_NOT_PAGED 0x08000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SCN_MEM_SHARED 0x10000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SCN_MEM_EXECUTE 0x20000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SCN_MEM_READ 0x40000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SCN_MEM_WRITE 0x80000000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SCN_SCALE_ਸੂਚਕਾਂਕ 0x00000001

#ਅਨ੍ਤਰ੍ਭਾਵ "pshpack2.h"

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ IMAGE_ਚਿੰਨ੍ਹ {
      ਸੰਘ {
	BYTE ShortName[8];
	ਬਣਤਰ {
	  DWORD Short;
	  DWORD Long;
	} Name;
	DWORD LongName[2];
      } N;
      DWORD ਮੁੱਲ_3;
      SHORT Section_ਸੰਖਿਆ;
      ਸ਼ਬਦ_3 Type;
      BYTE StorageClass;
      BYTE ਸੰਖਿਆ_ਦਾ_Aux_Symbols;
    } IMAGE_ਚਿੰਨ੍ਹ_2;
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ IMAGE_ਚਿੰਨ੍ਹ_2 UNALIGNED *PIMAGE_ਚਿੰਨ੍ਹ;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SIZEOF_ਚਿੰਨ੍ਹ 18

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SYM_UNDEFINED (SHORT)0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SYM_ABSOLUTE (SHORT)-1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SYM_DEBUG (SHORT)-2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SYM_SECTION_MAX 0xFEFF

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SYM_TYPE_NULL 0x0000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SYM_TYPE_VOID 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SYM_TYPE_CHAR 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SYM_TYPE_SHORT 0x0003
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SYM_TYPE_INT 0x0004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SYM_TYPE_LONG 0x0005
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SYM_TYPE_FLOAT 0x0006
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SYM_TYPE_DOUBLE 0x0007
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SYM_TYPE_STRUCT 0x0008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SYM_TYPE_UNION 0x0009
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SYM_TYPE_ENUM 0x000A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SYM_TYPE_MOE 0x000B
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SYM_TYPE_BYTE 0x000C
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SYM_TYPE_ਸ਼ਬਦ 0x000D
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SYM_TYPE_UINT 0x000E
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SYM_TYPE_DWORD 0x000F
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SYM_TYPE_PCODE 0x8000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SYM_DTYPE_NULL 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SYM_DTYPE_ਸੂਚਕ 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SYM_DTYPE_FUNCTION 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SYM_DTYPE_ARRAY 3

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SYM_CLASS_ਸਿਰਾ_ਦਾ_FUNCTION (BYTE)-1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SYM_CLASS_NULL 0x0000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SYM_CLASS_AUTOMATIC 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SYM_CLASS_EXTERNAL 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SYM_CLASS_STATIC 0x0003
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SYM_CLASS_ਰਜਿਸਟਰ 0x0004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SYM_CLASS_EXTERNAL_DEF 0x0005
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SYM_CLASS_LABEL 0x0006
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SYM_CLASS_UNDEFINED_LABEL 0x0007
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SYM_CLASS_MEMBER_ਦਾ_STRUCT 0x0008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SYM_CLASS_ਦਲੀਲ 0x0009
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SYM_CLASS_STRUCT_ਟੈਗ 0x000A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SYM_CLASS_MEMBER_ਦਾ_UNION 0x000B
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SYM_CLASS_UNION_ਟੈਗ 0x000C
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SYM_CLASS_TYPE_DEFINITION 0x000D
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SYM_CLASS_UNDEFINED_STATIC 0x000E
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SYM_CLASS_ENUM_ਟੈਗ 0x000F
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SYM_CLASS_MEMBER_ਦਾ_ENUM 0x0010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SYM_CLASS_ਰਜਿਸਟਰ_PARAM 0x0011
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SYM_CLASS_ਦੋਆਧਾਰੀ_ਅੰਕ_ਖੇਤਰ 0x0012
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SYM_CLASS_FAR_EXTERNAL 0x0044
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SYM_CLASS_ਖੰਡ 0x0064
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SYM_CLASS_FUNCTION 0x0065
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SYM_CLASS_ਸਿਰਾ_ਦਾ_STRUCT 0x0066
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SYM_CLASS_FILE 0x0067
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SYM_CLASS_SECTION 0x0068
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SYM_CLASS_WEAK_EXTERNAL 0x0069
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SYM_CLASS_CLR_TOKEN 0x006B

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ N_BTMASK 0x000F
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ N_TMASK 0x0030
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ N_TMASK1 0x00C0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ N_TMASK2 0x00F0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ N_BTSHFT 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ N_TSHIFT 2

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BTYPE(x) ((x) & N_BTMASK)

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ ISPTR
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ISPTR(x) (((x) & N_TMASK)==(IMAGE_SYM_DTYPE_ਸੂਚਕ << N_BTSHFT))
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ ISFCN
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ISFCN(x) (((x) & N_TMASK)==(IMAGE_SYM_DTYPE_FUNCTION << N_BTSHFT))
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ ISARY
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ISARY(x) (((x) & N_TMASK)==(IMAGE_SYM_DTYPE_ARRAY << N_BTSHFT))
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ ISTAG
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ISTAG(x) ((x)==IMAGE_SYM_CLASS_STRUCT_ਟੈਗ || (x)==IMAGE_SYM_CLASS_UNION_ਟੈਗ || (x)==IMAGE_SYM_CLASS_ENUM_ਟੈਗ)
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ INCREF
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INCREF(x) ((((x)&~N_BTMASK)<<N_TSHIFT)|(IMAGE_SYM_DTYPE_ਸੂਚਕ<<N_BTSHFT)|((x)&N_BTMASK))
#ਜੇ_ਅੰਤ
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ DECREF
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DECREF(x) ((((x)>>N_TSHIFT)&~N_BTMASK)|((x)&N_BTMASK))
#ਜੇ_ਅੰਤ

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਸੰਘ IMAGE_AUX_ਚਿੰਨ੍ਹ {
      ਬਣਤਰ {
	DWORD ਟੈਗ_ਸੂਚਕਾਂਕ;
	ਸੰਘ {
	  ਬਣਤਰ {
	    ਸ਼ਬਦ_3 Linenumber;
	    ਸ਼ਬਦ_3 ਮਾਪ_3;
	  } LnSz;
	  DWORD ਕੁੱਲ_ਮਾਪ;
	} Misc;
	ਸੰਘ {
	  ਬਣਤਰ {
	    DWORD ਸੂਚਕ_ਮੰਜ਼ਿਲ_Linenumber;
	    DWORD ਸੂਚਕ_ਮੰਜ਼ਿਲ_ਅਗਲਾ_Function;
	  } Function;
	  ਬਣਤਰ {
	    ਸ਼ਬਦ_3 Dimension[4];
	  } Array;
	} FcnAry;
	ਸ਼ਬਦ_3 Tv_ਸੂਚਕਾਂਕ;
      } Sym;
      ਬਣਤਰ {
	BYTE Name[IMAGE_SIZEOF_ਚਿੰਨ੍ਹ];
      } File;
      ਬਣਤਰ {
	DWORD ਲੰਮਾਈ_2;
	ਸ਼ਬਦ_3 ਸੰਖਿਆ_ਦਾ_Relocations;
	ਸ਼ਬਦ_3 ਸੰਖਿਆ_ਦਾ_Linenumbers;
	DWORD Check_ਜੋੜ;
	SHORT ਸੰਖਿਆ_2;
	BYTE Selection;
      } Section;
    } IMAGE_AUX_ਚਿੰਨ੍ਹ_2;
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ IMAGE_AUX_ਚਿੰਨ੍ਹ_2 UNALIGNED *PIMAGE_AUX_ਚਿੰਨ੍ਹ;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SIZEOF_AUX_ਚਿੰਨ੍ਹ 18

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਗਿਣਤੀ IMAGE_AUX_ਚਿੰਨ੍ਹ_TYPE {
      IMAGE_AUX_ਚਿੰਨ੍ਹ_TYPE_TOKEN_DEF = 1
    } IMAGE_AUX_ਚਿੰਨ੍ਹ_TYPE;

#ਅਨ੍ਤਰ੍ਭਾਵ <pshpack2.h>

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ IMAGE_AUX_ਚਿੰਨ੍ਹ_TOKEN_DEF {
      BYTE bAuxType;
      BYTE bReserved;
      DWORD ਚਿੰਨ੍ਹ_ਸਾਰਣੀ_ਸੂਚਕਾਂਕ;
      BYTE rgbReserved[12];
    } IMAGE_AUX_ਚਿੰਨ੍ਹ_TOKEN_DEF;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ IMAGE_AUX_ਚਿੰਨ੍ਹ_TOKEN_DEF UNALIGNED *PIMAGE_AUX_ਚਿੰਨ੍ਹ_TOKEN_DEF;

#ਅਨ੍ਤਰ੍ਭਾਵ <poppack.h>

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_COMDAT_SELECT_NODUPLICATES 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_COMDAT_SELECT_ANY 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_COMDAT_SELECT_SAME_ਮਾਪ 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_COMDAT_SELECT_EXACT_ਮੇਲ 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_COMDAT_SELECT_ASSOCIATIVE 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_COMDAT_SELECT_ਸਭ_ਤੋਂ_ਵੱਡਾ 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_COMDAT_SELECT_NEWEST 7

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_WEAK_EXTERN_ਖੋਜ_NOLIBRARY 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_WEAK_EXTERN_ਖੋਜ_LIBRARY 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_WEAK_EXTERN_ਖੋਜ_ALIAS 3

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _IMAGE_RELOCATION {
      ਸੰਘ {
	DWORD Virtual_ਪਤਾ;
	DWORD Reloc_ਗਿਣਤੀ;
      };
      DWORD ਚਿੰਨ੍ਹ_ਸਾਰਣੀ_ਸੂਚਕਾਂਕ;
      ਸ਼ਬਦ_3 Type;
    } IMAGE_RELOCATION;
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ IMAGE_RELOCATION UNALIGNED *PIMAGE_RELOCATION;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SIZEOF_RELOCATION 10

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_I386_ABSOLUTE 0x0000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_I386_DIR16 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_I386_REL16 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_I386_DIR32 0x0006
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_I386_DIR32NB 0x0007
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_I386_SEG12 0x0009
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_I386_SECTION 0x000A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_I386_SECREL 0x000B
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_I386_TOKEN 0x000C
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_I386_SECREL7 0x000D
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_I386_REL32 0x0014

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_MIPS_ABSOLUTE 0x0000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_MIPS_REFHALF 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_MIPS_REFWORD 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_MIPS_JMPADDR 0x0003
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_MIPS_REFHI 0x0004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_MIPS_REFLO 0x0005
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_MIPS_GPREL 0x0006
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_MIPS_LITERAL 0x0007
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_MIPS_SECTION 0x000A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_MIPS_SECREL 0x000B
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_MIPS_SECRELLO 0x000C
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_MIPS_SECRELHI 0x000D
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_MIPS_TOKEN 0x000E
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_MIPS_JMPADDR16 0x0010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_MIPS_REFWORDNB 0x0022
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_MIPS_PAIR 0x0025

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_ALPHA_ABSOLUTE 0x0000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_ALPHA_REFLONG 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_ALPHA_REFQUAD 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_ALPHA_GPREL32 0x0003
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_ALPHA_LITERAL 0x0004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_ALPHA_LITUSE 0x0005
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_ALPHA_GPDISP 0x0006
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_ALPHA_BRADDR 0x0007
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_ALPHA_HINT 0x0008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_ALPHA_INLINE_REFLONG 0x0009
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_ALPHA_REFHI 0x000A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_ALPHA_REFLO 0x000B
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_ALPHA_PAIR 0x000C
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_ALPHA_ਮੇਲ 0x000D
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_ALPHA_SECTION 0x000E
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_ALPHA_SECREL 0x000F
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_ALPHA_REFLONGNB 0x0010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_ALPHA_SECRELLO 0x0011
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_ALPHA_SECRELHI 0x0012
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_ALPHA_REFQ3 0x0013
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_ALPHA_REFQ2 0x0014
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_ALPHA_REFQ1 0x0015
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_ALPHA_GPRELLO 0x0016
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_ALPHA_GPRELHI 0x0017

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_PPC_ABSOLUTE 0x0000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_PPC_ADDR64 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_PPC_ADDR32 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_PPC_ADDR24 0x0003
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_PPC_ADDR16 0x0004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_PPC_ADDR14 0x0005
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_PPC_REL24 0x0006
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_PPC_REL14 0x0007
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_PPC_TOCREL16 0x0008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_PPC_TOCREL14 0x0009
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_PPC_ADDR32NB 0x000A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_PPC_SECREL 0x000B
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_PPC_SECTION 0x000C
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_PPC_IFGLUE 0x000D
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_PPC_IMGLUE 0x000E
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_PPC_SECREL16 0x000F
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_PPC_REFHI 0x0010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_PPC_REFLO 0x0011
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_PPC_PAIR 0x0012
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_PPC_SECRELLO 0x0013
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_PPC_SECRELHI 0x0014
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_PPC_GPREL 0x0015
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_PPC_TOKEN 0x0016
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_PPC_TYPEMASK 0x00FF
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_PPC_NEG 0x0100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_PPC_BRTAKEN 0x0200
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_PPC_BRNTAKEN 0x0400
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_PPC_TOCDEFN 0x0800

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_SH3_ABSOLUTE 0x0000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_SH3_DIRECT16 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_SH3_DIRECT32 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_SH3_DIRECT8 0x0003
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_SH3_DIRECT8_ਸ਼ਬਦ 0x0004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_SH3_DIRECT8_LONG 0x0005
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_SH3_DIRECT4 0x0006
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_SH3_DIRECT4_ਸ਼ਬਦ 0x0007
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_SH3_DIRECT4_LONG 0x0008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_SH3_PCREL8_ਸ਼ਬਦ 0x0009
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_SH3_PCREL8_LONG 0x000A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_SH3_PCREL12_ਸ਼ਬਦ 0x000B
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_SH3_STARTOF_SECTION 0x000C
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_SH3_SIZEOF_SECTION 0x000D
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_SH3_SECTION 0x000E
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_SH3_SECREL 0x000F
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_SH3_DIRECT32_NB 0x0010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_SH3_GPREL4_LONG 0x0011
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_SH3_TOKEN 0x0012

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_SHM_PCRELPT 0x0013
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_SHM_REFLO 0x0014
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_SHM_REFHALF 0x0015
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_SHM_RELLO 0x0016
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_SHM_RELHALF 0x0017
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_SHM_PAIR 0x0018

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_SH_NOMODE 0x8000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_ARM_ABSOLUTE 0x0000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_ARM_ADDR32 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_ARM_ADDR32NB 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_ARM_BRANCH24 0x0003
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_ARM_BRANCH11 0x0004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_ARM_TOKEN 0x0005
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_ARM_GPREL12 0x0006
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_ARM_GPREL7 0x0007
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_ARM_BLX24 0x0008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_ARM_BLX11 0x0009
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_ARM_SECTION 0x000E
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_ARM_SECREL 0x000F

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_AM_ABSOLUTE 0x0000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_AM_ADDR32 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_AM_ADDR32NB 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_AM_CALL32 0x0003
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_AM_FUNCINFO 0x0004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_AM_REL32_1 0x0005
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_AM_REL32_2 0x0006
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_AM_SECREL 0x0007
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_AM_SECTION 0x0008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_AM_TOKEN 0x0009

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_AMD64_ABSOLUTE 0x0000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_AMD64_ADDR64 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_AMD64_ADDR32 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_AMD64_ADDR32NB 0x0003
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_AMD64_REL32 0x0004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_AMD64_REL32_1 0x0005
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_AMD64_REL32_2 0x0006
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_AMD64_REL32_3 0x0007
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_AMD64_REL32_4 0x0008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_AMD64_REL32_5 0x0009
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_AMD64_SECTION 0x000A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_AMD64_SECREL 0x000B
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_AMD64_SECREL7 0x000C
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_AMD64_TOKEN 0x000D
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_AMD64_SREL32 0x000E
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_AMD64_PAIR 0x000F
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_AMD64_SSPAN32 0x0010

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_IA64_ABSOLUTE 0x0000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_IA64_IMM14 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_IA64_IMM22 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_IA64_IMM64 0x0003
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_IA64_DIR32 0x0004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_IA64_DIR64 0x0005
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_IA64_PCREL21B 0x0006
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_IA64_PCREL21M 0x0007
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_IA64_PCREL21F 0x0008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_IA64_GPREL22 0x0009
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_IA64_LTOFF22 0x000A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_IA64_SECTION 0x000B
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_IA64_SECREL22 0x000C
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_IA64_SECREL64I 0x000D
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_IA64_SECREL32 0x000E

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_IA64_DIR32NB 0x0010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_IA64_SREL14 0x0011
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_IA64_SREL22 0x0012
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_IA64_SREL32 0x0013
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_IA64_UREL32 0x0014
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_IA64_PCREL60X 0x0015
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_IA64_PCREL60B 0x0016
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_IA64_PCREL60F 0x0017
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_IA64_PCREL60I 0x0018
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_IA64_PCREL60M 0x0019
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_IA64_IMMGPREL64 0x001A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_IA64_TOKEN 0x001B
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_IA64_GPREL32 0x001C
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_IA64_ADDEND 0x001F

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_CEF_ABSOLUTE 0x0000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_CEF_ADDR32 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_CEF_ADDR64 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_CEF_ADDR32NB 0x0003
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_CEF_SECTION 0x0004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_CEF_SECREL 0x0005
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_CEF_TOKEN 0x0006

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_CEE_ABSOLUTE 0x0000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_CEE_ADDR32 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_CEE_ADDR64 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_CEE_ADDR32NB 0x0003
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_CEE_SECTION 0x0004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_CEE_SECREL 0x0005
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_CEE_TOKEN 0x0006

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_M32R_ABSOLUTE 0x0000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_M32R_ADDR32 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_M32R_ADDR32NB 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_M32R_ADDR24 0x0003
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_M32R_GPREL16 0x0004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_M32R_PCREL24 0x0005
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_M32R_PCREL16 0x0006
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_M32R_PCREL8 0x0007
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_M32R_REFHALF 0x0008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_M32R_REFHI 0x0009
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_M32R_REFLO 0x000A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_M32R_PAIR 0x000B
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_M32R_SECTION 0x000C
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_M32R_SECREL32 0x000D
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_M32R_TOKEN 0x000E

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXT_IMM64(ਮੁੱਲ_3,ਪਤਾ_2,ਮਾਪ_3,InstPos,ValPos) ਮੁੱਲ_3 |= (((ULONGLONG)((*(ਪਤਾ_2) >> InstPos) & (((ULONGLONG)1 << ਮਾਪ_3) - 1))) << ValPos)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INS_IMM64(ਮੁੱਲ_3,ਪਤਾ_2,ਮਾਪ_3,InstPos,ValPos) *(PDWORD)ਪਤਾ_2 = (*(PDWORD)ਪਤਾ_2 & ~(((1 << ਮਾਪ_3) - 1) << InstPos)) | ((DWORD)((((ULONGLONG)ਮੁੱਲ_3 >> ValPos) & (((ULONGLONG)1 << ਮਾਪ_3) - 1))) << InstPos)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMARCH_ENC_I17_IMM7_B_INST_ਸ਼ਬਦ_X 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMARCH_ENC_I17_IMM7_B_ਮਾਪ_X 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMARCH_ENC_I17_IMM7_B_INST_ਸ਼ਬਦ_POS_X 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMARCH_ENC_I17_IMM7B_VAL_POS_X 0

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMARCH_ENC_I17_IMM9_D_INST_ਸ਼ਬਦ_X 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMARCH_ENC_I17_IMM9_D_ਮਾਪ_X 9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMARCH_ENC_I17_IMM9_D_INST_ਸ਼ਬਦ_POS_X 18
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMARCH_ENC_I17_IMM9D_VAL_POS_X 7

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMARCH_ENC_I17_IMM5_C_INST_ਸ਼ਬਦ_X 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMARCH_ENC_I17_IMM5_C_ਮਾਪ_X 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMARCH_ENC_I17_IMM5_C_INST_ਸ਼ਬਦ_POS_X 13
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMARCH_ENC_I17_IMM5C_VAL_POS_X 16

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMARCH_ENC_I17_IC_INST_ਸ਼ਬਦ_X 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMARCH_ENC_I17_IC_ਮਾਪ_X 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMARCH_ENC_I17_IC_INST_ਸ਼ਬਦ_POS_X 12
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMARCH_ENC_I17_IC_VAL_POS_X 21

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMARCH_ENC_I17_IMM41a_INST_ਸ਼ਬਦ_X 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMARCH_ENC_I17_IMM41a_ਮਾਪ_X 10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMARCH_ENC_I17_IMM41a_INST_ਸ਼ਬਦ_POS_X 14
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMARCH_ENC_I17_IMM41a_VAL_POS_X 22

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMARCH_ENC_I17_IMM41b_INST_ਸ਼ਬਦ_X 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMARCH_ENC_I17_IMM41b_ਮਾਪ_X 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMARCH_ENC_I17_IMM41b_INST_ਸ਼ਬਦ_POS_X 24
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMARCH_ENC_I17_IMM41b_VAL_POS_X 32

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMARCH_ENC_I17_IMM41c_INST_ਸ਼ਬਦ_X 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMARCH_ENC_I17_IMM41c_ਮਾਪ_X 23
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMARCH_ENC_I17_IMM41c_INST_ਸ਼ਬਦ_POS_X 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMARCH_ENC_I17_IMM41c_VAL_POS_X 40

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMARCH_ENC_I17_SIGN_INST_ਸ਼ਬਦ_X 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMARCH_ENC_I17_SIGN_ਮਾਪ_X 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMARCH_ENC_I17_SIGN_INST_ਸ਼ਬਦ_POS_X 27
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMARCH_ENC_I17_SIGN_VAL_POS_X 63

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ X3_OPCODE_INST_ਸ਼ਬਦ_X 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ X3_OPCODE_ਮਾਪ_X 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ X3_OPCODE_INST_ਸ਼ਬਦ_POS_X 28
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ X3_OPCODE_SIGN_VAL_POS_X 0

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ X3_I_INST_ਸ਼ਬਦ_X 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ X3_I_ਮਾਪ_X 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ X3_I_INST_ਸ਼ਬਦ_POS_X 27
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ X3_I_SIGN_VAL_POS_X 59

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ X3_D_WH_INST_ਸ਼ਬਦ_X 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ X3_D_WH_ਮਾਪ_X 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ X3_D_WH_INST_ਸ਼ਬਦ_POS_X 24
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ X3_D_WH_SIGN_VAL_POS_X 0

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ X3_IMM20_INST_ਸ਼ਬਦ_X 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ X3_IMM20_ਮਾਪ_X 20
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ X3_IMM20_INST_ਸ਼ਬਦ_POS_X 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ X3_IMM20_SIGN_VAL_POS_X 0

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ X3_IMM39_1_INST_ਸ਼ਬਦ_X 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ X3_IMM39_1_ਮਾਪ_X 23
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ X3_IMM39_1_INST_ਸ਼ਬਦ_POS_X 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ X3_IMM39_1_SIGN_VAL_POS_X 36

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ X3_IMM39_2_INST_ਸ਼ਬਦ_X 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ X3_IMM39_2_ਮਾਪ_X 16
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ X3_IMM39_2_INST_ਸ਼ਬਦ_POS_X 16
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ X3_IMM39_2_SIGN_VAL_POS_X 20

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ X3_P_INST_ਸ਼ਬਦ_X 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ X3_P_ਮਾਪ_X 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ X3_P_INST_ਸ਼ਬਦ_POS_X 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ X3_P_SIGN_VAL_POS_X 0

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ X3_TMPLT_INST_ਸ਼ਬਦ_X 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ X3_TMPLT_ਮਾਪ_X 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ X3_TMPLT_INST_ਸ਼ਬਦ_POS_X 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ X3_TMPLT_SIGN_VAL_POS_X 0

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ X3_BTYPE_QP_INST_ਸ਼ਬਦ_X 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ X3_BTYPE_QP_ਮਾਪ_X 9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ X3_BTYPE_QP_INST_ਸ਼ਬਦ_POS_X 23
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ X3_BTYPE_QP_INST_VAL_POS_X 0

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ X3_ਖਾਲੀ_ਥਾਵਾਂ_INST_ਸ਼ਬਦ_X 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ X3_ਖਾਲੀ_ਥਾਵਾਂ_ਮਾਪ_X 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ X3_ਖਾਲੀ_ਥਾਵਾਂ_INST_ਸ਼ਬਦ_POS_X 14
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ X3_ਖਾਲੀ_ਥਾਵਾਂ_INST_VAL_POS_X 0

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _IMAGE_LINENUMBER {
      ਸੰਘ {
	DWORD ਚਿੰਨ੍ਹ_ਸਾਰਣੀ_ਸੂਚਕਾਂਕ;
	DWORD Virtual_ਪਤਾ;
      } Type;
      ਸ਼ਬਦ_3 Linenumber;
    } IMAGE_LINENUMBER;
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ IMAGE_LINENUMBER UNALIGNED *PIMAGE_LINENUMBER;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SIZEOF_LINENUMBER 6

#ਅਨ੍ਤਰ੍ਭਾਵ "poppack.h"

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ IMAGE_ਅਧਾਰ_RELOCATION {
      DWORD Virtual_ਪਤਾ;
      DWORD ਮਾਪ_ਦਾ_ਖੰਡ;

    } IMAGE_ਅਧਾਰ_RELOCATION_2;
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ IMAGE_ਅਧਾਰ_RELOCATION_2 UNALIGNED *PIMAGE_ਅਧਾਰ_RELOCATION;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SIZEOF_ਅਧਾਰ_RELOCATION 8

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_BASED_ABSOLUTE 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_BASED_ਉੱਚਾ 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_BASED_ਨੀਵਾਂ 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_BASED_HIGHLOW 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_BASED_HIGHADJ 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_BASED_MIPS_JMPADDR 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_BASED_MIPS_JMPADDR16 9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_BASED_IA64_IMM64 9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_REL_BASED_DIR64 10

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_ARCHIVE_ਸ਼ੁਰੂ_ਮਾਪ 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_ARCHIVE_ਸ਼ੁਰੂ "!<arch>\n"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_ARCHIVE_ਸਿਰਾ "`\n"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_ARCHIVE_PAD "\n"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_ARCHIVE_LINKER_MEMBER "/               "
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_ARCHIVE_LONGNAMES_MEMBER "//              "

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ IMAGE_ARCHIVE_MEMBER_ਸਿਰਲੇਖ {
      BYTE Name[16];
      BYTE Date[12];
      BYTE UserID[6];
      BYTE ਸਮੂਹ_ID[6];
      BYTE ਬਹੁਲਕ_4[8];
      BYTE ਮਾਪ_3[10];
      BYTE ਸਿਰਾ_ਸਿਰਲੇਖ[2];
    } IMAGE_ARCHIVE_MEMBER_ਸਿਰਲੇਖ_2,*PIMAGE_ARCHIVE_MEMBER_ਸਿਰਲੇਖ;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SIZEOF_ARCHIVE_MEMBER_HDR 60

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _IMAGE_EXPORT_DIRECTORY {
      DWORD Characteristics;
      DWORD ਸਮਾਂ_Date_Stamp;
      ਸ਼ਬਦ_3 Major_ਸੰਸਕਰਣ;
      ਸ਼ਬਦ_3 Minor_ਸੰਸਕਰਣ;
      DWORD Name;
      DWORD ਅਧਾਰ_2;
      DWORD ਸੰਖਿਆ_ਦਾ_Functions;
      DWORD ਸੰਖਿਆ_ਦਾ_ਨਾਂ;
      DWORD ਪਤਾ_ਦਾ_Functions;
      DWORD ਪਤਾ_ਦਾ_ਨਾਂ;
      DWORD ਪਤਾ_ਦਾ_Name_Ordinals;
    } IMAGE_EXPORT_DIRECTORY,*PIMAGE_EXPORT_DIRECTORY;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _IMAGE_IMPORT_BY_NAME {
      ਸ਼ਬਦ_3 Hint;
      BYTE Name[1];
    } IMAGE_IMPORT_BY_NAME,*PIMAGE_IMPORT_BY_NAME;

#ਅਨ੍ਤਰ੍ਭਾਵ "pshpack8.h"

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _IMAGE_THUNK_DATA64 {
      ਸੰਘ {
	ULONGLONG ForwarderString;
	ULONGLONG Function;
	ULONGLONG Ordinal;
	ULONGLONG ਪਤਾ_ਦਾ_ਅੰਕੜੇ;
      } u1;
    } IMAGE_THUNK_DATA64;
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ IMAGE_THUNK_DATA64 *PIMAGE_THUNK_DATA64;

#ਅਨ੍ਤਰ੍ਭਾਵ "poppack.h"

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _IMAGE_THUNK_DATA32 {
      ਸੰਘ {
	DWORD ForwarderString;
	DWORD Function;
	DWORD Ordinal;
	DWORD ਪਤਾ_ਦਾ_ਅੰਕੜੇ;
      } u1;
    } IMAGE_THUNK_DATA32;
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ IMAGE_THUNK_DATA32 *PIMAGE_THUNK_DATA32;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_ORDINAL_FLAG64 0x8000000000000000ull
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_ORDINAL_FLAG32 0x80000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_ORDINAL64(Ordinal) (Ordinal & 0xffffull)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_ORDINAL32(Ordinal) (Ordinal & 0xffff)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SNAP_BY_ORDINAL64(Ordinal) ((Ordinal & IMAGE_ORDINAL_FLAG64)!=0)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SNAP_BY_ORDINAL32(Ordinal) ((Ordinal & IMAGE_ORDINAL_FLAG32)!=0)

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ VOID
      (NTAPI *PIMAGE_TLS_CALLBACK)(PVOID DllHandle,DWORD Reason,PVOID Reserved);

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _IMAGE_TLS_DIRECTORY64 {
      ULONGLONG ਸ਼ੁਰੂ_ਪਤਾ_ਦਾ_Raw_ਅੰਕੜੇ;
      ULONGLONG ਸਿਰਾ_ਪਤਾ_ਦਾ_Raw_ਅੰਕੜੇ;
      ULONGLONG ਪਤਾ_ਦਾ_ਸੂਚਕਾਂਕ;
      ULONGLONG ਪਤਾ_ਦਾ_Call_Backs;
      DWORD ਮਾਪ_ਦਾ_Zero_Fill;
      DWORD Characteristics;
    } IMAGE_TLS_DIRECTORY64;
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ IMAGE_TLS_DIRECTORY64 *PIMAGE_TLS_DIRECTORY64;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _IMAGE_TLS_DIRECTORY32 {
      DWORD ਸ਼ੁਰੂ_ਪਤਾ_ਦਾ_Raw_ਅੰਕੜੇ;
      DWORD ਸਿਰਾ_ਪਤਾ_ਦਾ_Raw_ਅੰਕੜੇ;
      DWORD ਪਤਾ_ਦਾ_ਸੂਚਕਾਂਕ;
      DWORD ਪਤਾ_ਦਾ_Call_Backs;
      DWORD ਮਾਪ_ਦਾ_Zero_Fill;
      DWORD Characteristics;
    } IMAGE_TLS_DIRECTORY32;
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ IMAGE_TLS_DIRECTORY32 *PIMAGE_TLS_DIRECTORY32;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_ORDINAL_FLAG IMAGE_ORDINAL_FLAG64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_ORDINAL(Ordinal) IMAGE_ORDINAL64(Ordinal)
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ IMAGE_THUNK_DATA64 IMAGE_THUNK_ਅੰਕੜੇ;
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ PIMAGE_THUNK_DATA64 PIMAGE_THUNK_ਅੰਕੜੇ;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SNAP_BY_ORDINAL(Ordinal) IMAGE_SNAP_BY_ORDINAL64(Ordinal)
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ IMAGE_TLS_DIRECTORY64 IMAGE_TLS_DIRECTORY;
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ PIMAGE_TLS_DIRECTORY64 PIMAGE_TLS_DIRECTORY;
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_ORDINAL_FLAG IMAGE_ORDINAL_FLAG32
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_ORDINAL(Ordinal) IMAGE_ORDINAL32(Ordinal)
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ IMAGE_THUNK_DATA32 IMAGE_THUNK_ਅੰਕੜੇ;
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ PIMAGE_THUNK_DATA32 PIMAGE_THUNK_ਅੰਕੜੇ;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SNAP_BY_ORDINAL(Ordinal) IMAGE_SNAP_BY_ORDINAL32(Ordinal)
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ IMAGE_TLS_DIRECTORY32 IMAGE_TLS_DIRECTORY;
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ PIMAGE_TLS_DIRECTORY32 PIMAGE_TLS_DIRECTORY;
#ਜੇ_ਅੰਤ

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _IMAGE_IMPORT_DESCRIPTOR {
      ਸੰਘ {
	DWORD Characteristics;
	DWORD Original_ਪਹਿਲਾ_Thunk;
      };
      DWORD ਸਮਾਂ_Date_Stamp;

      DWORD ForwarderChain;
      DWORD Name;
      DWORD ਪਹਿਲਾ_Thunk;
    } IMAGE_IMPORT_DESCRIPTOR;
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ IMAGE_IMPORT_DESCRIPTOR UNALIGNED *PIMAGE_IMPORT_DESCRIPTOR;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _IMAGE_BOUND_IMPORT_DESCRIPTOR {
      DWORD ਸਮਾਂ_Date_Stamp;
      ਸ਼ਬਦ_3 ਵਿੱਥ_Module_Name;
      ਸ਼ਬਦ_3 ਸੰਖਿਆ_ਦਾ_Module_Forwarder_Refs;
    } IMAGE_BOUND_IMPORT_DESCRIPTOR,*PIMAGE_BOUND_IMPORT_DESCRIPTOR;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _IMAGE_BOUND_FORWARDER_REF {
      DWORD ਸਮਾਂ_Date_Stamp;
      ਸ਼ਬਦ_3 ਵਿੱਥ_Module_Name;
      ਸ਼ਬਦ_3 Reserved;
    } IMAGE_BOUND_FORWARDER_REF,*PIMAGE_BOUND_FORWARDER_REF;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _IMAGE_RESOURCE_DIRECTORY {
      DWORD Characteristics;
      DWORD ਸਮਾਂ_Date_Stamp;
      ਸ਼ਬਦ_3 Major_ਸੰਸਕਰਣ;
      ਸ਼ਬਦ_3 Minor_ਸੰਸਕਰਣ;
      ਸ਼ਬਦ_3 ਸੰਖਿਆ_ਦਾ_Named_Entries;
      ਸ਼ਬਦ_3 ਸੰਖਿਆ_ਦਾ_Id_Entries;
    } IMAGE_RESOURCE_DIRECTORY,*PIMAGE_RESOURCE_DIRECTORY;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_RESOURCE_NAME_IS_STRING 0x80000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_RESOURCE_ਅੰਕੜੇ_IS_DIRECTORY 0x80000000

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ IMAGE_RESOURCE_DIRECTORY_ਇੰਦਰਾਜ {
      ਸੰਘ {
	ਬਣਤਰ {
	  DWORD Name_ਵਿੱਥ:31;
	  DWORD NameIsString:1;
	};
	DWORD Name;
	ਸ਼ਬਦ_3 Id;
      };
      ਸੰਘ {
	DWORD ਵਿੱਥ_ਮੰਜ਼ਿਲ_ਅੰਕੜੇ;
	ਬਣਤਰ {
	  DWORD ਵਿੱਥ_ਮੰਜ਼ਿਲ_Directory:31;
	  DWORD ਅੰਕੜੇ_Is_Directory:1;
	};
      };
    } IMAGE_RESOURCE_DIRECTORY_ਇੰਦਰਾਜ_2,*PIMAGE_RESOURCE_DIRECTORY_ਇੰਦਰਾਜ;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _IMAGE_RESOURCE_DIRECTORY_STRING {
      ਸ਼ਬਦ_3 ਲੰਮਾਈ_2;
      CHAR NameString[1];
    } IMAGE_RESOURCE_DIRECTORY_STRING,*PIMAGE_RESOURCE_DIRECTORY_STRING;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _IMAGE_RESOURCE_DIR_STRING_U {
      ਸ਼ਬਦ_3 ਲੰਮਾਈ_2;
      WCHAR NameString[1];
    } IMAGE_RESOURCE_DIR_STRING_U,*PIMAGE_RESOURCE_DIR_STRING_U;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ IMAGE_RESOURCE_ਅੰਕੜੇ_ਇੰਦਰਾਜ {
      DWORD ਵਿੱਥ_ਮੰਜ਼ਿਲ_ਅੰਕੜੇ;
      DWORD ਮਾਪ_3;
      DWORD ਕੋਡ_ਪੰਨਾ;
      DWORD Reserved;
    } IMAGE_RESOURCE_ਅੰਕੜੇ_ਇੰਦਰਾਜ_2,*PIMAGE_RESOURCE_ਅੰਕੜੇ_ਇੰਦਰਾਜ;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ {
      DWORD ਮਾਪ_3;
      DWORD ਸਮਾਂ_Date_Stamp;
      ਸ਼ਬਦ_3 Major_ਸੰਸਕਰਣ;
      ਸ਼ਬਦ_3 Minor_ਸੰਸਕਰਣ;
      DWORD GlobalFlagsClear;
      DWORD Global_Flags_ਸੈੱਟ;
      DWORD CriticalSectionDefaultTimeout;
      DWORD De_Commit_Free_ਖੰਡ_ਹੱਦ;
      DWORD De_Commit_ਕੁੱਲ_Free_ਹੱਦ;
      DWORD ਤਾਲਾ_ਅਗੇਤਰ_ਸਾਰਣੀ;
      DWORD ਵੱਧ_ਤੋਂ_ਵੱਧ_ਵੰਡ_ਮਾਪ;
      DWORD Virtual_ਸਮ੍ਰਿਤੀ_ਹੱਦ;
      DWORD Process_ਢੇਰ_Flags;
      DWORD Process_Affinity_ਨਕਾਬ;
      ਸ਼ਬਦ_3 CSDVersion;
      ਸ਼ਬਦ_3 Reserved1;
      DWORD EditList;
      DWORD SecurityCookie;
      DWORD SEHandler_ਸਾਰਣੀ;
      DWORD SEHandler_ਗਿਣਤੀ;
    } IMAGE_ਲੱਦੋ_CONFIG_DIRECTORY32,*PIMAGE_ਲੱਦੋ_CONFIG_DIRECTORY32;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ {
      DWORD ਮਾਪ_3;
      DWORD ਸਮਾਂ_Date_Stamp;
      ਸ਼ਬਦ_3 Major_ਸੰਸਕਰਣ;
      ਸ਼ਬਦ_3 Minor_ਸੰਸਕਰਣ;
      DWORD GlobalFlagsClear;
      DWORD Global_Flags_ਸੈੱਟ;
      DWORD CriticalSectionDefaultTimeout;
      ULONGLONG De_Commit_Free_ਖੰਡ_ਹੱਦ;
      ULONGLONG De_Commit_ਕੁੱਲ_Free_ਹੱਦ;
      ULONGLONG ਤਾਲਾ_ਅਗੇਤਰ_ਸਾਰਣੀ;
      ULONGLONG ਵੱਧ_ਤੋਂ_ਵੱਧ_ਵੰਡ_ਮਾਪ;
      ULONGLONG Virtual_ਸਮ੍ਰਿਤੀ_ਹੱਦ;
      ULONGLONG Process_Affinity_ਨਕਾਬ;
      DWORD Process_ਢੇਰ_Flags;
      ਸ਼ਬਦ_3 CSDVersion;
      ਸ਼ਬਦ_3 Reserved1;
      ULONGLONG EditList;
      ULONGLONG SecurityCookie;
      ULONGLONG SEHandler_ਸਾਰਣੀ;
      ULONGLONG SEHandler_ਗਿਣਤੀ;
    } IMAGE_ਲੱਦੋ_CONFIG_DIRECTORY64,*PIMAGE_ਲੱਦੋ_CONFIG_DIRECTORY64;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN64
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ IMAGE_ਲੱਦੋ_CONFIG_DIRECTORY64 IMAGE_ਲੱਦੋ_CONFIG_DIRECTORY;
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ PIMAGE_ਲੱਦੋ_CONFIG_DIRECTORY64 PIMAGE_ਲੱਦੋ_CONFIG_DIRECTORY;
#ਨਹੀਂਤਾਂ
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ IMAGE_ਲੱਦੋ_CONFIG_DIRECTORY32 IMAGE_ਲੱਦੋ_CONFIG_DIRECTORY;
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ PIMAGE_ਲੱਦੋ_CONFIG_DIRECTORY32 PIMAGE_ਲੱਦੋ_CONFIG_DIRECTORY;
#ਜੇ_ਅੰਤ

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ IMAGE_CE_RUNTIME_FUNCTION_ਇੰਦਰਾਜ {
      DWORD Func_ਸ਼ੁਰੂ;
      DWORD PrologLen : 8;
      DWORD FuncLen : 22;
      DWORD Thirty_Two_ਦੋਆਧਾਰੀ_ਅੰਕ : 1;
      DWORD ExceptionFlag : 1;
    } IMAGE_CE_RUNTIME_FUNCTION_ਇੰਦਰਾਜ_2,*PIMAGE_CE_RUNTIME_FUNCTION_ਇੰਦਰਾਜ;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ IMAGE_ALPHA64_RUNTIME_FUNCTION_ਇੰਦਰਾਜ {
      ULONGLONG Begin_ਪਤਾ;
      ULONGLONG ਸਿਰਾ_ਪਤਾ;
      ULONGLONG ExceptionHandler;
      ULONGLONG Handler_ਅੰਕੜੇ;
      ULONGLONG Prolog_ਸਿਰਾ_ਪਤਾ;
    } IMAGE_ALPHA64_RUNTIME_FUNCTION_ਇੰਦਰਾਜ_2,*PIMAGE_ALPHA64_RUNTIME_FUNCTION_ਇੰਦਰਾਜ;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ IMAGE_ALPHA_RUNTIME_FUNCTION_ਇੰਦਰਾਜ {
      DWORD Begin_ਪਤਾ;
      DWORD ਸਿਰਾ_ਪਤਾ;
      DWORD ExceptionHandler;
      DWORD Handler_ਅੰਕੜੇ;
      DWORD Prolog_ਸਿਰਾ_ਪਤਾ;
    } IMAGE_ALPHA_RUNTIME_FUNCTION_ਇੰਦਰਾਜ_2,*PIMAGE_ALPHA_RUNTIME_FUNCTION_ਇੰਦਰਾਜ;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ IMAGE_RUNTIME_FUNCTION_ਇੰਦਰਾਜ {
      DWORD Begin_ਪਤਾ;
      DWORD ਸਿਰਾ_ਪਤਾ;
      DWORD Unwind_Info_ਪਤਾ;
    } IMAGE_RUNTIME_FUNCTION_ਇੰਦਰਾਜ,*PIMAGE_RUNTIME_FUNCTION_ਇੰਦਰਾਜ;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ IMAGE_RUNTIME_FUNCTION_ਇੰਦਰਾਜ IMAGE_IA64_RUNTIME_FUNCTION_ਇੰਦਰਾਜ;
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ PIMAGE_RUNTIME_FUNCTION_ਇੰਦਰਾਜ PIMAGE_IA64_RUNTIME_FUNCTION_ਇੰਦਰਾਜ;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ IMAGE_RUNTIME_FUNCTION_ਇੰਦਰਾਜ IMAGE_RUNTIME_FUNCTION_ਇੰਦਰਾਜ_2;
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ PIMAGE_RUNTIME_FUNCTION_ਇੰਦਰਾਜ PIMAGE_RUNTIME_FUNCTION_ਇੰਦਰਾਜ_2;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _IMAGE_DEBUG_DIRECTORY {
      DWORD Characteristics;
      DWORD ਸਮਾਂ_Date_Stamp;
      ਸ਼ਬਦ_3 Major_ਸੰਸਕਰਣ;
      ਸ਼ਬਦ_3 Minor_ਸੰਸਕਰਣ;
      DWORD Type;
      DWORD ਮਾਪ_ਦਾ_ਅੰਕੜੇ;
      DWORD ਪਤਾ_ਦਾ_Raw_ਅੰਕੜੇ;
      DWORD ਸੂਚਕ_ਮੰਜ਼ਿਲ_Raw_ਅੰਕੜੇ;
    } IMAGE_DEBUG_DIRECTORY,*PIMAGE_DEBUG_DIRECTORY;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DEBUG_TYPE_UNKNOWN 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DEBUG_TYPE_COFF 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DEBUG_TYPE_CODEVIEW 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DEBUG_TYPE_FPO 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DEBUG_TYPE_MISC 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DEBUG_TYPE_EXCEPTION 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DEBUG_TYPE_FIXUP 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DEBUG_TYPE_OMAP_ਮੰਜ਼ਿਲ_SRC 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DEBUG_TYPE_OMAP_FROM_SRC 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DEBUG_TYPE_BORLAND 9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DEBUG_TYPE_RESERVED10 10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DEBUG_TYPE_CLSID 11

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ IMAGE_COFF_SYMBOLS_ਸਿਰਲੇਖ {
      DWORD ਸੰਖਿਆ_ਦਾ_Symbols;
      DWORD Lva_ਮੰਜ਼ਿਲ_ਪਹਿਲਾ_ਚਿੰਨ੍ਹ;
      DWORD ਸੰਖਿਆ_ਦਾ_Linenumbers;
      DWORD Lva_ਮੰਜ਼ਿਲ_ਪਹਿਲਾ_Linenumber;
      DWORD Rva_ਮੰਜ਼ਿਲ_ਪਹਿਲਾ_Byte_ਦਾ_ਕੋਡ;
      DWORD Rva_ਮੰਜ਼ਿਲ_ਆਖਰੀ_Byte_ਦਾ_ਕੋਡ;
      DWORD Rva_ਮੰਜ਼ਿਲ_ਪਹਿਲਾ_Byte_ਦਾ_ਅੰਕੜੇ;
      DWORD Rva_ਮੰਜ਼ਿਲ_ਆਖਰੀ_Byte_ਦਾ_ਅੰਕੜੇ;
    } IMAGE_COFF_SYMBOLS_ਸਿਰਲੇਖ_2,*PIMAGE_COFF_SYMBOLS_ਸਿਰਲੇਖ;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਚੌਖਟਾ_FPO 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਚੌਖਟਾ_TRAP 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਚੌਖਟਾ_TSS 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਚੌਖਟਾ_NONFPO 3

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ FPO_ਅੰਕੜੇ {
      DWORD ul_Off_ਸ਼ੁਰੂ;
      DWORD cb_Proc_ਮਾਪ;
      DWORD cdwLocals;
      ਸ਼ਬਦ_3 cdwParams;
      ਸ਼ਬਦ_3 cbProlog : 8;
      ਸ਼ਬਦ_3 cbRegs : 3;
      ਸ਼ਬਦ_3 fHasSEH : 1;
      ਸ਼ਬਦ_3 fUseBP : 1;
      ਸ਼ਬਦ_3 reserved : 1;
      ਸ਼ਬਦ_3 cb_ਚੌਖਟਾ : 2;
    } FPO_ਅੰਕੜੇ_2,*PFPO_ਅੰਕੜੇ;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIZEOF_RFPO_ਅੰਕੜੇ 16

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_DEBUG_MISC_EXENAME 1

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _IMAGE_DEBUG_MISC {
      DWORD ਅੰਕੜੇ_Type;
      DWORD ਲੰਮਾਈ_2;
      BOOLEAN Unicode;
      BYTE Reserved[3];
      BYTE ਅੰਕੜੇ_3[1];
    } IMAGE_DEBUG_MISC,*PIMAGE_DEBUG_MISC;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ IMAGE_FUNCTION_ਇੰਦਰਾਜ {
      DWORD Starting_ਪਤਾ;
      DWORD Ending_ਪਤਾ;
      DWORD ਸਿਰਾ_ਦਾ_Prologue;
    } IMAGE_FUNCTION_ਇੰਦਰਾਜ_2,*PIMAGE_FUNCTION_ਇੰਦਰਾਜ;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _IMAGE_FUNCTION_ENTRY64 {
      ULONGLONG Starting_ਪਤਾ;
      ULONGLONG Ending_ਪਤਾ;
      ਸੰਘ {
	ULONGLONG ਸਿਰਾ_ਦਾ_Prologue;
	ULONGLONG Unwind_Info_ਪਤਾ;
      };
    } IMAGE_FUNCTION_ENTRY64,*PIMAGE_FUNCTION_ENTRY64;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ IMAGE_SEPARATE_DEBUG_ਸਿਰਲੇਖ {
      ਸ਼ਬਦ_3 Signature;
      ਸ਼ਬਦ_3 Flags;
      ਸ਼ਬਦ_3 Machine;
      ਸ਼ਬਦ_3 Characteristics;
      DWORD ਸਮਾਂ_Date_Stamp;
      DWORD Check_ਜੋੜ;
      DWORD Image_ਅਧਾਰ;
      DWORD ਮਾਪ_ਦਾ_Image;
      DWORD ਸੰਖਿਆ_ਦਾ_Sections;
      DWORD Exported_ਨਾਂ_ਮਾਪ;
      DWORD Debug_Directory_ਮਾਪ;
      DWORD SectionAlignment;
      DWORD Reserved[2];
    } IMAGE_SEPARATE_DEBUG_ਸਿਰਲੇਖ_2,*PIMAGE_SEPARATE_DEBUG_ਸਿਰਲੇਖ;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _NON_PAGED_DEBUG_INFO {
      ਸ਼ਬਦ_3 Signature;
      ਸ਼ਬਦ_3 Flags;
      DWORD ਮਾਪ_3;
      ਸ਼ਬਦ_3 Machine;
      ਸ਼ਬਦ_3 Characteristics;
      DWORD ਸਮਾਂ_Date_Stamp;
      DWORD Check_ਜੋੜ;
      DWORD ਮਾਪ_ਦਾ_Image;
      ULONGLONG Image_ਅਧਾਰ;

    } NON_PAGED_DEBUG_INFO,*PNON_PAGED_DEBUG_INFO;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SEPARATE_DEBUG_SIGNATURE 0x4944
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NON_PAGED_DEBUG_SIGNATURE 0x494E

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SEPARATE_DEBUG_FLAGS_ਨਕਾਬ 0x8000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_SEPARATE_DEBUG_MISMATCH 0x8000

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ Image_Architecture_ਸਿਰਲੇਖ {
      ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ Amask_ਮੁੱਲ: 1;
      ਪੂਰਨ Adummy1 :7;
      ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ Amask_ਖਿਸਕਾਓ: 8;
      ਪੂਰਨ Adummy2 :16;
      DWORD ਪਹਿਲਾ_ਇੰਦਰਾਜ_RVA;
    } IMAGE_ARCHITECTURE_ਸਿਰਲੇਖ,*PIMAGE_ARCHITECTURE_ਸਿਰਲੇਖ;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ Image_Architecture_ਇੰਦਰਾਜ {
      DWORD FixupInstRVA;
      DWORD NewInst;
    } IMAGE_ARCHITECTURE_ਇੰਦਰਾਜ,*PIMAGE_ARCHITECTURE_ਇੰਦਰਾਜ;

#ਅਨ੍ਤਰ੍ਭਾਵ "poppack.h"

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMPORT_OBJECT_HDR_SIG2 0xffff

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ IMPORT_OBJECT_ਸਿਰਲੇਖ {
      ਸ਼ਬਦ_3 Sig1;
      ਸ਼ਬਦ_3 Sig2;
      ਸ਼ਬਦ_3 ਸੰਸਕਰਣ_2;
      ਸ਼ਬਦ_3 Machine;
      DWORD ਸਮਾਂ_Date_Stamp;
      DWORD ਮਾਪ_ਦਾ_ਅੰਕੜੇ;
      ਸੰਘ {
	ਸ਼ਬਦ_3 Ordinal;
	ਸ਼ਬਦ_3 Hint;
      };
      ਸ਼ਬਦ_3 Type : 2;
      ਸ਼ਬਦ_3 NameType : 3;
      ਸ਼ਬਦ_3 Reserved : 11;
    } IMPORT_OBJECT_ਸਿਰਲੇਖ;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਗਿਣਤੀ IMPORT_OBJECT_TYPE {
      IMPORT_OBJECT_ਕੋਡ = 0,IMPORT_OBJECT_ਅੰਕੜੇ = 1,IMPORT_OBJECT_CONST = 2
    } IMPORT_OBJECT_TYPE;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਗਿਣਤੀ IMPORT_OBJECT_NAME_TYPE {
      IMPORT_OBJECT_ORDINAL = 0,IMPORT_OBJECT_NAME = 1,IMPORT_OBJECT_NAME_NO_ਅਗੇਤਰ = 2,IMPORT_OBJECT_NAME_UNDECORATE = 3
    } IMPORT_OBJECT_NAME_TYPE;

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __IMAGE_COR20_HEADER_DEFINED__
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __IMAGE_COR20_HEADER_DEFINED__
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਗਿਣਤੀ Replaces_Cor_Hdr_Numeric_ਨਿਰਧਾਰਤ_ਕਰਦਾ {
      COMIMAGE_FLAGS_ILONLY =0x00000001,COMIMAGE_FLAGS_32BITREQUIRED =0x00000002,COMIMAGE_FLAGS_IL_LIBRARY =0x00000004,
      COMIMAGE_FLAGS_STRONGNAMESIGNED =0x00000008,COMIMAGE_FLAGS_TRACKDEBUGDATA =0x00010000,COR_ਸੰਸਕਰਣ_MAJOR_V2 =2,
      COR_ਸੰਸਕਰਣ_MAJOR =COR_ਸੰਸਕਰਣ_MAJOR_V2,COR_ਸੰਸਕਰਣ_MINOR =0,COR_DELETED_NAME_ਲੰਮਾਈ =8,COR_VTABLEGAP_NAME_ਲੰਮਾਈ =8,
      NATIVE_TYPE_MAX_CB =1,COR_ILMETHOD_SECT_SMALL_MAX_DATASIZE=0xFF,IMAGE_COR_MIH_METHODRVA =0x01,IMAGE_COR_MIH_EHRVA =0x02,
      IMAGE_COR_MIH_BASICBLOCK =0x08,COR_VTABLE_32_ਦੋਆਧਾਰੀ_ਅੰਕ =0x01,COR_VTABLE_64_ਦੋਆਧਾਰੀ_ਅੰਕ =0x02,COR_VTABLE_FROM_UNMANAGED =0x04,
      COR_VTABLE_CALL_MOST_DERIVED =0x10,IMAGE_COR_EATJ_THUNK_ਮਾਪ =32,MAX_CLASS_NAME =1024,MAX_PACKAGE_NAME =1024
    } Replaces_Cor_Hdr_Numeric_ਨਿਰਧਾਰਤ_ਕਰਦਾ;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ IMAGE_COR20_ਸਿਰਲੇਖ {
      DWORD cb;
      ਸ਼ਬਦ_3 Major_Runtime_ਸੰਸਕਰਣ;
      ਸ਼ਬਦ_3 Minor_Runtime_ਸੰਸਕਰਣ;
      IMAGE_ਅੰਕੜੇ_DIRECTORY_2 Meta_ਅੰਕੜੇ;
      DWORD Flags;
      DWORD ਇੰਦਰਾਜ_ਬਿੰਦੂ_Token;
      IMAGE_ਅੰਕੜੇ_DIRECTORY_2 Resources;
      IMAGE_ਅੰਕੜੇ_DIRECTORY_2 StrongNameSignature;
      IMAGE_ਅੰਕੜੇ_DIRECTORY_2 ਕੋਡ_Manager_ਸਾਰਣੀ;
      IMAGE_ਅੰਕੜੇ_DIRECTORY_2 VTableFixups;
      IMAGE_ਅੰਕੜੇ_DIRECTORY_2 Export_ਪਤਾ_ਸਾਰਣੀ_Jumps;
      IMAGE_ਅੰਕੜੇ_DIRECTORY_2 Managed_Native_ਸਿਰਲੇਖ;
    } IMAGE_COR20_ਸਿਰਲੇਖ,*PIMAGE_COR20_ਸਿਰਲੇਖ;
#ਜੇ_ਅੰਤ

#ਜੇ defined (__x86_64)
    NTSYSAPI PRUNTIME_FUNCTION NTAPI Rtl_Lookup_Function_ਇੰਦਰਾਜ (DWORD64 ControlPc, PDWORD64 Image_ਅਧਾਰ, PUNWIND_HISTORY_ਸਾਰਣੀ History_ਸਾਰਣੀ);
    NTSYSAPI VOID NTAPI RtlUnwindEx (PVOID ਨਿਸ਼ਾਨਾ_ਚੌਖਟਾ, PVOID ਨਿਸ਼ਾਨਾ_Ip, PEXCEPTION_ਰਿਕਾਰਡ Exception_ਰਿਕਾਰਡ, PVOID Return_ਮੁੱਲ_2, PCONTEXT Context_ਰਿਕਾਰਡ, PUNWIND_HISTORY_ਸਾਰਣੀ History_ਸਾਰਣੀ);
#ਜੇ_ਅੰਤ

#ਅਨ੍ਤਰ੍ਭਾਵ <string.h>

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ SLIST_ਸਿਰਲੇਖ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SLIST_ਸਿਰਲੇਖ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN64
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ SLIST_ਇੰਦਰਾਜ *PSLIST_ਇੰਦਰਾਜ;
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ DECLSPEC_ALIGN(16) SLIST_ਇੰਦਰਾਜ {
      PSLIST_ਇੰਦਰਾਜ ਅਗਲਾ_2;
    } SLIST_ਇੰਦਰਾਜ_2;
#ਨਹੀਂਤਾਂ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SLIST_ਇੰਦਰਾਜ_2 SINGLE_LIST_ਇੰਦਰਾਜ_2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SLIST_ਇੰਦਰਾਜ SINGLE_LIST_ਇੰਦਰਾਜ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PSLIST_ਇੰਦਰਾਜ PSINGLE_LIST_ਇੰਦਰਾਜ
#ਜੇ_ਅੰਤ

#ਜੇ defined(_WIN64)

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ DECLSPEC_ALIGN(16) SLIST_ਸਿਰਲੇਖ_2 {
      ULONGLONG Alignment;
      ULONGLONG Region;
    } SLIST_ਸਿਰਲੇਖ_3;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ SLIST_ਸਿਰਲੇਖ_2 *PSLIST_ਸਿਰਲੇਖ;
#ਨਹੀਂਤਾਂ

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਸੰਘ SLIST_ਸਿਰਲੇਖ_2 {
      ULONGLONG Alignment;
      ਬਣਤਰ {
	SLIST_ਇੰਦਰਾਜ_2 ਅਗਲਾ_2;
	ਸ਼ਬਦ_3 ਡੂੰਘਾਈ;
	ਸ਼ਬਦ_3 Sequence;
      };
    } SLIST_ਸਿਰਲੇਖ_3,*PSLIST_ਸਿਰਲੇਖ;
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

    NTSYSAPI VOID NTAPI Rtl_Initialize_SList_ਸਿਰ(PSLIST_ਸਿਰਲੇਖ List_ਸਿਰ);
    NTSYSAPI PSLIST_ਇੰਦਰਾਜ NTAPI Rtl_ਪਹਿਲਾ_ਇੰਦਰਾਜ_SList(ਅਚਲ SLIST_ਸਿਰਲੇਖ_3 *List_ਸਿਰ);
    NTSYSAPI PSLIST_ਇੰਦਰਾਜ NTAPI Rtl_Interlocked_ਕੱਢੋ_ਇੰਦਰਾਜ_SList(PSLIST_ਸਿਰਲੇਖ List_ਸਿਰ);
    NTSYSAPI PSLIST_ਇੰਦਰਾਜ NTAPI Rtl_Interlocked_ਧੱਕੋ_ਇੰਦਰਾਜ_SList(PSLIST_ਸਿਰਲੇਖ List_ਸਿਰ,PSLIST_ਇੰਦਰਾਜ List_ਇੰਦਰਾਜ);
    NTSYSAPI PSLIST_ਇੰਦਰਾਜ NTAPI RtlInterlockedFlushSList(PSLIST_ਸਿਰਲੇਖ List_ਸਿਰ);
    NTSYSAPI ਸ਼ਬਦ_3 NTAPI Rtl_Query_ਡੂੰਘਾਈ_SList(PSLIST_ਸਿਰਲੇਖ List_ਸਿਰ);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਢੇਰ_NO_SERIALIZE 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਢੇਰ_GROWABLE 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਢੇਰ_GENERATE_EXCEPTIONS 0x00000004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਢੇਰ_ZERO_ਸਮ੍ਰਿਤੀ 0x00000008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਢੇਰ_REALLOC_ਵਿੱਚ_ਰੱਖੋ_ONLY 0x00000010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਢੇਰ_ਪੂਛ_CHECKING_ENABLED 0x00000020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਢੇਰ_FREE_CHECKING_ENABLED 0x00000040
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਢੇਰ_DISABLE_COALESCE_ON_FREE 0x00000080
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਢੇਰ_CREATE_ALIGN_16 0x00010000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਢੇਰ_CREATE_ENABLE_TRACING 0x00020000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਢੇਰ_CREATE_ENABLE_EXECUTE 0x00040000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਢੇਰ_ਵੱਧ_ਤੋਂ_ਵੱਧ_ਟੈਗ 0x0FFF
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਢੇਰ_PSEUDO_ਟੈਗ_FLAG 0x8000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਢੇਰ_ਟੈਗ_ਖਿਸਕਾਓ 18
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਢੇਰ_MAKE_ਟੈਗ_FLAGS(b,o) ((DWORD)((b) + ((o) << 18)))

    NTSYSAPI VOID NTAPI RtlCaptureContext(PCONTEXT Context_ਰਿਕਾਰਡ);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IS_ਪਾਠ_UNICODE_ASCII16 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IS_ਪਾਠ_UNICODE_ਉਲਟ_ASCII16 0x0010

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IS_ਪਾਠ_UNICODE_STATISTICS 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IS_ਪਾਠ_UNICODE_ਉਲਟ_STATISTICS 0x0020

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IS_ਪਾਠ_UNICODE_CONTROLS 0x0004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IS_ਪਾਠ_UNICODE_ਉਲਟ_CONTROLS 0x0040

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IS_ਪਾਠ_UNICODE_SIGNATURE 0x0008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IS_ਪਾਠ_UNICODE_ਉਲਟ_SIGNATURE 0x0080

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IS_ਪਾਠ_UNICODE_ILLEGAL_CHARS 0x0100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IS_ਪਾਠ_UNICODE_ODD_ਲੰਮਾਈ 0x0200
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IS_ਪਾਠ_UNICODE_DBCS_LEADBYTE 0x0400
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IS_ਪਾਠ_UNICODE_NULL_ਬਾਈਟਾਂ 0x1000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IS_ਪਾਠ_UNICODE_UNICODE_ਨਕਾਬ 0x000F
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IS_ਪਾਠ_UNICODE_ਉਲਟ_ਨਕਾਬ 0x00F0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IS_ਪਾਠ_UNICODE_NOT_UNICODE_ਨਕਾਬ 0x0F00
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IS_ਪਾਠ_UNICODE_NOT_ASCII_ਨਕਾਬ 0xF000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COMPRESSION_FORMAT_NONE (0x0000)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COMPRESSION_FORMAT_DEFAULT (0x0001)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COMPRESSION_FORMAT_LZNT1 (0x0002)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COMPRESSION_ENGINE_STANDARD (0x0000)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COMPRESSION_ENGINE_ਵੱਧ_ਤੋਂ_ਵੱਧ (0x0100)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COMPRESSION_ENGINE_HIBER (0x0200)

#ਜੇ _DBG_MEMCPY_INLINE_ && !defined(_MEMCPY_INLINE_) && !defined(_CRTBLD)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _MEMCPY_INLINE_
    __CRT_INLINE PVOID __cdecl memcpy_inline(ਖਾਲੀ *dst,ਅਚਲ ਖਾਲੀ *src,ਮਾਪ_t ਮਾਪ) {
      ਜੇ(((ਅੱਖਰ *)dst > (ਅੱਖਰ *)src) && ((ਅੱਖਰ *)dst < ((ਅੱਖਰ *)src + ਮਾਪ))) {
	__debugbreak();
      }
      ਵਾਪਸ ਸਮ੍ਰਿਤੀ_ਨਕਲ(dst,src,ਮਾਪ);
    }
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਮ੍ਰਿਤੀ_ਨਕਲ memcpy_inline
#ਜੇ_ਅੰਤ

    NTSYSAPI ਮਾਪ_T NTAPI Rtl_Compare_ਸਮ੍ਰਿਤੀ(ਅਚਲ VOID *Source1,ਅਚਲ VOID *Source2,ਮਾਪ_T ਲੰਮਾਈ_2);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Rtl_Equal_ਸਮ੍ਰਿਤੀ(Destination,ਸਰੋਤ_2,ਲੰਮਾਈ_2) (!memcmp((Destination),(ਸਰੋਤ_2),(ਲੰਮਾਈ_2)))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Rtl_Move_ਸਮ੍ਰਿਤੀ(Destination,ਸਰੋਤ_2,ਲੰਮਾਈ_2) memmove((Destination),(ਸਰੋਤ_2),(ਲੰਮਾਈ_2))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Rtl_Copy_ਸਮ੍ਰਿਤੀ(Destination,ਸਰੋਤ_2,ਲੰਮਾਈ_2) ਸਮ੍ਰਿਤੀ_ਨਕਲ((Destination),(ਸਰੋਤ_2),(ਲੰਮਾਈ_2))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Rtl_Fill_ਸਮ੍ਰਿਤੀ(Destination,ਲੰਮਾਈ_2,Fill) memset((Destination),(Fill),(ਲੰਮਾਈ_2))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Rtl_Zero_ਸਮ੍ਰਿਤੀ(Destination,ਲੰਮਾਈ_2) memset((Destination),0,(ਲੰਮਾਈ_2))

    __CRT_INLINE PVOID Rtl_Secure_Zero_ਸਮ੍ਰਿਤੀ(PVOID ptr,ਮਾਪ_T cnt) {
      ਅਸਥਿਰ ਅੱਖਰ *vptr =(ਅਸਥਿਰ ਅੱਖਰ *)ptr;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __x86_64
      __stosb((PBYTE)((DWORD64)vptr),0,cnt);
#ਨਹੀਂਤਾਂ
      ਜਦੋਂ(cnt) {
	*vptr = 0;
	vptr++;
	cnt--;
      }
#ਜੇ_ਅੰਤ
      ਵਾਪਸ ptr;
    }

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਸੁਨੇਹਾ_RESOURCE_ਇੰਦਰਾਜ {
      ਸ਼ਬਦ_3 ਲੰਮਾਈ_2;
      ਸ਼ਬਦ_3 Flags;
      BYTE ਪਾਠ_4[1];
    } ਸੁਨੇਹਾ_RESOURCE_ਇੰਦਰਾਜ_2,*PMESSAGE_RESOURCE_ਇੰਦਰਾਜ;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੁਨੇਹਾ_RESOURCE_UNICODE 0x0001

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਸੁਨੇਹਾ_RESOURCE_ਖੰਡ {
      DWORD ਨੀਵਾਂ_Id;
      DWORD ਉੱਚਾ_Id;
      DWORD ਵਿੱਥ_ਮੰਜ਼ਿਲ_Entries;
    } ਸੁਨੇਹਾ_RESOURCE_ਖੰਡ_2,*PMESSAGE_RESOURCE_ਖੰਡ;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਸੁਨੇਹਾ_RESOURCE_ਅੰਕੜੇ {
      DWORD ਸੰਖਿਆ_ਦਾ_ਖੰਡਾਂ;
      ਸੁਨੇਹਾ_RESOURCE_ਖੰਡ_2 ਖੰਡਾਂ_2[1];
    } ਸੁਨੇਹਾ_RESOURCE_ਅੰਕੜੇ_2,*PMESSAGE_RESOURCE_ਅੰਕੜੇ;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _OSVERSIONINFOA {
      DWORD dw_OSVersion_Info_ਮਾਪ;
      DWORD dw_Major_ਸੰਸਕਰਣ;
      DWORD dw_Minor_ਸੰਸਕਰਣ;
      DWORD dw_Build_ਸੰਖਿਆ;
      DWORD dwPlatformId;
      CHAR szCSDVersion[128];
    } OSVERSIONINFOA,*POSVERSIONINFOA,*LPOSVERSIONINFOA;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _OSVERSIONINFOW {
      DWORD dw_OSVersion_Info_ਮਾਪ;
      DWORD dw_Major_ਸੰਸਕਰਣ;
      DWORD dw_Minor_ਸੰਸਕਰਣ;
      DWORD dw_Build_ਸੰਖਿਆ;
      DWORD dwPlatformId;
      WCHAR szCSDVersion[128];
    } OSVERSIONINFOW,*POSVERSIONINFOW,*LPOSVERSIONINFOW,RTL_OSVERSIONINFOW,*PRTL_OSVERSIONINFOW;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ OSVERSIONINFOW OSVERSIONINFO;
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ POSVERSIONINFOW POSVERSIONINFO;
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPOSVERSIONINFOW LPOSVERSIONINFO;
#ਨਹੀਂਤਾਂ
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ OSVERSIONINFOA OSVERSIONINFO;
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ POSVERSIONINFOA POSVERSIONINFO;
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPOSVERSIONINFOA LPOSVERSIONINFO;
#ਜੇ_ਅੰਤ

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _OSVERSIONINFOEXA {
      DWORD dw_OSVersion_Info_ਮਾਪ;
      DWORD dw_Major_ਸੰਸਕਰਣ;
      DWORD dw_Minor_ਸੰਸਕਰਣ;
      DWORD dw_Build_ਸੰਖਿਆ;
      DWORD dwPlatformId;
      CHAR szCSDVersion[128];
      ਸ਼ਬਦ_3 wServicePackMajor;
      ਸ਼ਬਦ_3 wServicePackMinor;
      ਸ਼ਬਦ_3 w_Suite_ਨਕਾਬ;
      BYTE w_ਗੁਣਨਫਲ_Type;
      BYTE wReserved;
    } OSVERSIONINFOEXA,*POSVERSIONINFOEXA,*LPOSVERSIONINFOEXA;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _OSVERSIONINFOEXW {
      DWORD dw_OSVersion_Info_ਮਾਪ;
      DWORD dw_Major_ਸੰਸਕਰਣ;
      DWORD dw_Minor_ਸੰਸਕਰਣ;
      DWORD dw_Build_ਸੰਖਿਆ;
      DWORD dwPlatformId;
      WCHAR szCSDVersion[128];
      ਸ਼ਬਦ_3 wServicePackMajor;
      ਸ਼ਬਦ_3 wServicePackMinor;
      ਸ਼ਬਦ_3 w_Suite_ਨਕਾਬ;
      BYTE w_ਗੁਣਨਫਲ_Type;
      BYTE wReserved;
    } OSVERSIONINFOEXW,*POSVERSIONINFOEXW,*LPOSVERSIONINFOEXW,RTL_OSVERSIONINFOEXW,*PRTL_OSVERSIONINFOEXW;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ OSVERSIONINFOEXW OSVERSIONINFOEX;
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ POSVERSIONINFOEXW POSVERSIONINFOEX;
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPOSVERSIONINFOEXW LPOSVERSIONINFOEX;
#ਨਹੀਂਤਾਂ
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ OSVERSIONINFOEXA OSVERSIONINFOEX;
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ POSVERSIONINFOEXA POSVERSIONINFOEX;
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPOSVERSIONINFOEXA LPOSVERSIONINFOEX;
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VER_EQUAL 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VER_GREATER 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VER_GREATER_EQUAL 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VER_LESS 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VER_LESS_EQUAL 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VER_AND 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VER_OR 7

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VER_CONDITION_ਨਕਾਬ 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VER_ਅੰਕ_ਬਿੱਟ_ਪ੍ਰਤੀ_CONDITION_ਨਕਾਬ 3

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VER_MINORVERSION 0x0000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VER_MAJORVERSION 0x0000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VER_BUILDNUMBER 0x0000004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VER_PLATFORMID 0x0000008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VER_SERVICEPACKMINOR 0x0000010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VER_SERVICEPACKMAJOR 0x0000020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VER_SUITENAME 0x0000040
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VER_ਗੁਣਨਫਲ_TYPE 0x0000080

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VER_NT_WORKSTATION 0x0000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VER_NT_DOMAIN_CONTROLLER 0x0000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VER_NT_SERVER 0x0000003

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VER_PLATFORM_WIN32s 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VER_PLATFORM_WIN32_WINDOWS 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VER_PLATFORM_WIN32_NT 2

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VER_ਸੈੱਟ_CONDITION(_m_,_t_,_c_) ((_m_)=Ver_ਸੈੱਟ_Condition_ਨਕਾਬ((_m_),(_t_),(_c_)))

    NTSYSAPI ULONGLONG NTAPI Ver_ਸੈੱਟ_Condition_ਨਕਾਬ(ULONGLONG Condition_ਨਕਾਬ,DWORD Type_ਨਕਾਬ,BYTE Condition);

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _RTL_CRITICAL_SECTION_DEBUG {
      ਸ਼ਬਦ_3 Type;
      ਸ਼ਬਦ_3 Creator_ਪਿੱਠ_Trace_ਸੂਚਕਾਂਕ;
      ਬਣਤਰ _RTL_CRITICAL_SECTION *CriticalSection;
      LIST_ਇੰਦਰਾਜ_2 ProcessLocksList;
      DWORD ਇੰਦਰਾਜ_ਗਿਣਤੀ;
      DWORD Contention_ਗਿਣਤੀ;
      DWORD ਵਾਧੂ_2[2];
    } RTL_CRITICAL_SECTION_DEBUG,*PRTL_CRITICAL_SECTION_DEBUG,RTL_RESOURCE_DEBUG,*PRTL_RESOURCE_DEBUG;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RTL_CRITSECT_TYPE 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RTL_RESOURCE_TYPE 1

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _RTL_CRITICAL_SECTION {
      PRTL_CRITICAL_SECTION_DEBUG DebugInfo;
      LONG ਤਾਲਾ_ਗਿਣਤੀ;
      LONG Recursion_ਗਿਣਤੀ;
      HANDLE OwningThread;
      HANDLE ਤਾਲਾ_Semaphore;
      ULONG_PTR Spin_ਗਿਣਤੀ;
    } RTL_CRITICAL_SECTION,*PRTL_CRITICAL_SECTION;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ VOID (NTAPI *RTL_VERIFIER_DLL_ਲੱਦੋ_CALLBACK) (PWSTR DllName,PVOID Dll_ਅਧਾਰ,ਮਾਪ_T Dll_ਮਾਪ,PVOID Reserved);
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ VOID (NTAPI *RTL_VERIFIER_DLL_UNLOAD_CALLBACK) (PWSTR DllName,PVOID Dll_ਅਧਾਰ,ਮਾਪ_T Dll_ਮਾਪ,PVOID Reserved);
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ VOID (NTAPI *RTL_VERIFIER_NTDLLHEAPFREE_CALLBACK)(PVOID ਵੰਡ_ਅਧਾਰ,ਮਾਪ_T ਵੰਡ_ਮਾਪ);

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _RTL_VERIFIER_THUNK_DESCRIPTOR {
      PCHAR ThunkName;
      PVOID Thunk_Old_ਪਤਾ;
      PVOID Thunk_New_ਪਤਾ;
    } RTL_VERIFIER_THUNK_DESCRIPTOR,*PRTL_VERIFIER_THUNK_DESCRIPTOR;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _RTL_VERIFIER_DLL_DESCRIPTOR {
      PWCHAR DllName;
      DWORD DllFlags;
      PVOID Dll_ਪਤਾ;
      PRTL_VERIFIER_THUNK_DESCRIPTOR DllThunks;
    } RTL_VERIFIER_DLL_DESCRIPTOR,*PRTL_VERIFIER_DLL_DESCRIPTOR;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _RTL_VERIFIER_PROVIDER_DESCRIPTOR {
      DWORD ਲੰਮਾਈ_2;
      PRTL_VERIFIER_DLL_DESCRIPTOR ProviderDlls;
      RTL_VERIFIER_DLL_ਲੱਦੋ_CALLBACK Provider_Dll_ਲੱਦੋ_Callback;
      RTL_VERIFIER_DLL_UNLOAD_CALLBACK ProviderDllUnloadCallback;
      PWSTR VerifierImage;
      DWORD VerifierFlags;
      DWORD VerifierDebug;
      PVOID Rtlp_Get_ਢੇਰ_Trace_ਪਤਾ;
      PVOID Rtlp_Debug_ਪੰਨਾ_ਢੇਰ_Create;
      PVOID Rtlp_Debug_ਪੰਨਾ_ਢੇਰ_Destroy;
      RTL_VERIFIER_NTDLLHEAPFREE_CALLBACK Provider_Ntdll_ਢੇਰ_Free_Callback;
    } RTL_VERIFIER_PROVIDER_DESCRIPTOR,*PRTL_VERIFIER_PROVIDER_DESCRIPTOR;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RTL_VRF_FLG_ਭਰਿਆ_ਪੰਨਾ_ਢੇਰ 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RTL_VRF_FLG_RESERVED_DONOTUSE 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RTL_VRF_FLG_HANDLE_CHECKS 0x00000004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RTL_VRF_FLG_ਢੇਰ_CHECKS 0x00000008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RTL_VRF_FLG_APPCOMPAT_CHECKS 0x00000010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RTL_VRF_FLG_TLS_CHECKS 0x00000020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RTL_VRF_FLG_DIRTY_STACKS 0x00000040
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RTL_VRF_FLG_RPC_CHECKS 0x00000080
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RTL_VRF_FLG_COM_CHECKS 0x00000100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RTL_VRF_FLG_DANGEROUS_APIS 0x00000200
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RTL_VRF_FLG_RACE_CHECKS 0x00000400
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RTL_VRF_FLG_DEADLOCK_CHECKS 0x00000800
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RTL_VRF_FLG_ਪਹਿਲਾ_CHANCE_EXCEPTION_CHECKS 0x00001000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RTL_VRF_FLG_VIRTUAL_MEM_CHECKS 0x00002000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RTL_VRF_FLG_ENABLE_LOGGING 0x00004000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RTL_VRF_FLG_FAST_FILL_ਢੇਰ 0x00008000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RTL_VRF_FLG_VIRTUAL_SPACE_TRACKING 0x00010000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RTL_VRF_FLG_ENABLED_SYSTEM_WIDE 0x00020000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RTL_VRF_FLG_MISCELLANEOUS_CHECKS 0x00020000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RTL_VRF_FLG_ਤਾਲਾ_CHECKS 0x00040000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_ਅੰਦਰੂਨੀ_ERROR 0x80000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_ਅੰਦਰੂਨੀ_WARNING 0x40000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_NO_BREAK 0x20000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_CONTINUABLE_BREAK 0x10000000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_UNKNOWN_ERROR 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_ACCESS_VIOLATION 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_UNSYNCHRONIZED_ACCESS 0x0003
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_EXTREME_ਮਾਪ_REQUEST 0x0004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_BAD_ਢੇਰ_HANDLE 0x0005
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_SWITCHED_ਢੇਰ_HANDLE 0x0006
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_DOUBLE_FREE 0x0007
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_CORRUPTED_ਢੇਰ_ਖੰਡ 0x0008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_DESTROY_PROCESS_ਢੇਰ 0x0009
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_UNEXPECTED_EXCEPTION 0x000A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_CORRUPTED_ਢੇਰ_ਖੰਡ_EXCEPTION_RAISED_FOR_ਸਿਰਲੇਖ 0x000B
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_CORRUPTED_ਢੇਰ_ਖੰਡ_EXCEPTION_RAISED_FOR_PROBING 0x000C
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_CORRUPTED_ਢੇਰ_ਖੰਡ_ਸਿਰਲੇਖ 0x000D
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_CORRUPTED_FREED_ਢੇਰ_ਖੰਡ 0x000E
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_CORRUPTED_ਢੇਰ_ਖੰਡ_SUFFIX 0x000F
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_CORRUPTED_ਢੇਰ_ਖੰਡ_ਸ਼ੁਰੂ_STAMP 0x0010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_CORRUPTED_ਢੇਰ_ਖੰਡ_ਸਿਰਾ_STAMP 0x0011
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_CORRUPTED_ਢੇਰ_ਖੰਡ_ਅਗੇਤਰ 0x0012
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_ਪਹਿਲਾ_CHANCE_ACCESS_VIOLATION 0x0013
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_CORRUPTED_ਢੇਰ_LIST 0x0014

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_TERMINATE_THREAD_CALL 0x0100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_ਢੇਰ_ਉਛਾਲ 0x0101
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_INVALID_EXIT_PROCESS_CALL 0x0102

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_EXIT_THREAD_OWNS_ਤਾਲਾ 0x0200
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_ਤਾਲਾ_ਵਿੱਚ_UNLOADED_DLL 0x0201
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_ਤਾਲਾ_ਵਿੱਚ_FREED_ਢੇਰ 0x0202
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_ਤਾਲਾ_DOUBLE_INITIALIZE 0x0203
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_ਤਾਲਾ_ਵਿੱਚ_FREED_ਸਮ੍ਰਿਤੀ 0x0204
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_ਤਾਲਾ_CORRUPTED 0x0205
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_ਤਾਲਾ_INVALID_OWNER 0x0206
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_ਤਾਲਾ_INVALID_RECURSION_ਗਿਣਤੀ 0x0207
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_ਤਾਲਾ_INVALID_ਤਾਲਾ_ਗਿਣਤੀ 0x0208
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_ਤਾਲਾ_OVER_RELEASED 0x0209
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_ਤਾਲਾ_NOT_INITIALIZED 0x0210
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_ਤਾਲਾ_ALREADY_INITIALIZED 0x0211
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_ਤਾਲਾ_ਵਿੱਚ_FREED_VMEM 0x0212
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_ਤਾਲਾ_ਵਿੱਚ_UNMAPPED_MEM 0x0213
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_THREAD_NOT_ਤਾਲਾ_OWNER 0x0214

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_INVALID_HANDLE 0x0300
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_INVALID_TLS_ਮੁੱਲ 0x0301
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_INCORRECT_WAIT_CALL 0x0302
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_NULL_HANDLE 0x0303
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_WAIT_ਵਿੱਚ_DLLMAIN 0x0304

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_COM_ERROR 0x0400
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_COM_API_ਵਿੱਚ_DLLMAIN 0x0401
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_COM_UNHANDLED_EXCEPTION 0x0402
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_COM_UNBALANCED_COINIT 0x0403
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_COM_UNBALANCED_OLEINIT 0x0404
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_COM_UNBALANCED_SWC 0x0405
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_COM_NULL_DACL 0x0406
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_COM_UNSAFE_IMPERSONATION 0x0407
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_COM_SMUGGLED_WRAPPER 0x0408
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_COM_SMUGGLED_PROXY 0x0409
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_COM_CF_SUCCESS_WITH_NULL 0x040A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_COM_GCO_SUCCESS_WITH_NULL 0x040B
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_COM_OBJECT_ਵਿੱਚ_FREED_ਸਮ੍ਰਿਤੀ 0x040C
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_COM_OBJECT_ਵਿੱਚ_UNLOADED_DLL 0x040D
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_COM_VTBL_ਵਿੱਚ_FREED_ਸਮ੍ਰਿਤੀ 0x040E
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_COM_VTBL_ਵਿੱਚ_UNLOADED_DLL 0x040F
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_COM_HOLDING_LOCKS_ON_CALL 0x0410

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_RPC_ERROR 0x0500

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_INVALID_FREEMEM 0x0600
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_INVALID_ALLOCMEM 0x0601
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_INVALID_MAPVIEW 0x0602
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_PROBE_INVALID_ਪਤਾ 0x0603
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_PROBE_FREE_MEM 0x0604
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_PROBE_GUARD_ਪੰਨਾ 0x0605
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_PROBE_NULL 0x0606
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_PROBE_INVALID_ਸ਼ੁਰੂ_OR_ਮਾਪ 0x0607
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPLICATION_VERIFIER_ਮਾਪ_ਢੇਰ_UNEXPECTED_EXCEPTION 0x0618

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VERIFIER_STOP(ਕੋਡ_4,ਸੁਨੇਹਾ_5,P1,S1,P2,S2,P3,S3,P4,S4) { RtlApplicationVerifierStop ((ਕੋਡ_4),(ਸੁਨੇਹਾ_5),(ULONG_PTR)(P1),(S1),(ULONG_PTR)(P2),(S2),(ULONG_PTR)(P3),(S3),(ULONG_PTR)(P4),(S4)); }

    VOID NTAPI RtlApplicationVerifierStop(ULONG_PTR ਕੋਡ_4,PSTR ਸੁਨੇਹਾ_6,ULONG_PTR Param1,PSTR Description1,ULONG_PTR Param2,PSTR Description2,ULONG_PTR Param3,PSTR Description3,ULONG_PTR Param4,PSTR Description4);

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ LONG (NTAPI *PVECTORED_EXCEPTION_HANDLER)(ਬਣਤਰ EXCEPTION_ਸੂਚਕ_ਸਾਰੇ_2 *ExceptionInfo);
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SEF_DACL_AUTO_INHERIT 0x01
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SEF_SACL_AUTO_INHERIT 0x02
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SEF_DEFAULT_DESCRIPTOR_FOR_OBJECT 0x04
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SEF_AVOID_PRIVILEGE_CHECK 0x08
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SEF_AVOID_OWNER_CHECK 0x10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SEF_DEFAULT_OWNER_FROM_ਮਾਪਾ 0x20
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SEF_DEFAULT_ਸਮੂਹ_FROM_ਮਾਪਾ 0x40

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਗਿਣਤੀ ਢੇਰ_INFORMATION_CLASS_2 {
      ਢੇਰ_Compatibility_Information
    } ਢੇਰ_INFORMATION_CLASS;

    NTSYSAPI DWORD NTAPI Rtl_ਸੈੱਟ_ਢੇਰ_Information(PVOID ਢੇਰ_Handle,ਢੇਰ_INFORMATION_CLASS ਢੇਰ_Information_Class,PVOID ਢੇਰ_Information,ਮਾਪ_T ਢੇਰ_Information_ਲੰਮਾਈ);
    NTSYSAPI DWORD NTAPI Rtl_Query_ਢੇਰ_Information(PVOID ਢੇਰ_Handle,ਢੇਰ_INFORMATION_CLASS ਢੇਰ_Information_Class,PVOID ਢੇਰ_Information,ਮਾਪ_T ਢੇਰ_Information_ਲੰਮਾਈ,PSIZE_T Return_ਲੰਮਾਈ);
    DWORD NTAPI Rtl_ਗੁਣਜ_Allocate_ਢੇਰ(PVOID ਢੇਰ_Handle,DWORD Flags,ਮਾਪ_T ਮਾਪ_3,DWORD ਗਿਣਤੀ_4,PVOID *Array);
    DWORD NTAPI Rtl_ਗੁਣਜ_Free_ਢੇਰ(PVOID ਢੇਰ_Handle,DWORD Flags,DWORD ਗਿਣਤੀ_4,PVOID *Array);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WT_EXECUTEDEFAULT 0x00000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WT_EXECUTEINIOTHREAD 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WT_EXECUTEINUITHREAD 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WT_EXECUTEINWAITTHREAD 0x00000004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WT_EXECUTEONLYONCE 0x00000008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WT_EXECUTEINTIMERTHREAD 0x00000020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WT_EXECUTELONGFUNCTION 0x00000010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WT_EXECUTEINPERSISTENTIOTHREAD 0x00000040
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WT_EXECUTEINPERSISTENTTHREAD 0x00000080
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WT_TRANSFER_IMPERSONATION 0x00000100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WT_ਸੈੱਟ_MAX_THREADPOOL_ਧਾਗੇ(Flags,ਹੱਦਬੰਦੀ_2) ((Flags) |= (ਹੱਦਬੰਦੀ_2)<<16)
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ VOID (NTAPI *WAITORTIMERCALLBACKFUNC)(PVOID,BOOLEAN);
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ VOID (NTAPI *WORKERCALLBACKFUNC)(PVOID);
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ VOID (NTAPI *APC_CALLBACK_FUNCTION)(DWORD ,PVOID,PVOID);
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ
      VOID
      (NTAPI *PFLS_CALLBACK_FUNCTION)(PVOID lp_Fls_ਅੰਕੜੇ);
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WT_EXECUTEINLONGTHREAD 0x00000010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WT_EXECUTEDELETEWAIT 0x00000008

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਗਿਣਤੀ _ACTIVATION_CONTEXT_INFO_CLASS {
      ActivationContextBasicInformation = 1,ActivationContextDetailedInformation = 2,Assembly_Detailed_Information_ਵਿੱਚ_Activation_Context = 3,File_Information_ਵਿੱਚ_Assembly_ਦਾ_Assembly_ਵਿੱਚ_Activation_Context = 4,MaxActivationContextInfoClass,Assembly_Detailed_Information_ਵਿੱਚ_Activation_Contxt = 3,File_Information_ਵਿੱਚ_Assembly_ਦਾ_Assembly_ਵਿੱਚ_Activation_Contxt = 4
    } ACTIVATION_CONTEXT_INFO_CLASS;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACTIVATIONCONTEXTINFOCLASS ACTIVATION_CONTEXT_INFO_CLASS

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ACTIVATION_CONTEXT_QUERY_ਸੂਚਕਾਂਕ {
      DWORD ul_Assembly_ਸੂਚਕਾਂਕ;
      DWORD ul_File_ਸੂਚਕਾਂਕ_ਵਿੱਚ_Assembly;
    } ACTIVATION_CONTEXT_QUERY_ਸੂਚਕਾਂਕ_2,*PACTIVATION_CONTEXT_QUERY_ਸੂਚਕਾਂਕ;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਅਚਲ ਬਣਤਰ ACTIVATION_CONTEXT_QUERY_ਸੂਚਕਾਂਕ *PCACTIVATION_CONTEXT_QUERY_ਸੂਚਕਾਂਕ;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACTIVATION_CONTEXT_ਰਸਤਾ_TYPE_NONE (1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACTIVATION_CONTEXT_ਰਸਤਾ_TYPE_WIN32_FILE (2)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACTIVATION_CONTEXT_ਰਸਤਾ_TYPE_URL (3)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACTIVATION_CONTEXT_ਰਸਤਾ_TYPE_ASSEMBLYREF (4)

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _ASSEMBLY_FILE_DETAILED_INFORMATION {
      DWORD ulFlags;
      DWORD ul_Filename_ਲੰਮਾਈ;
      DWORD ul_ਰਸਤਾ_ਲੰਮਾਈ;

      PCWSTR lpFileName;
      PCWSTR lp_File_ਰਸਤਾ;
    } ASSEMBLY_FILE_DETAILED_INFORMATION,*PASSEMBLY_FILE_DETAILED_INFORMATION;
    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਅਚਲ ASSEMBLY_FILE_DETAILED_INFORMATION *PCASSEMBLY_FILE_DETAILED_INFORMATION;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _ASSEMBLY_DLL_REDIRECTION_DETAILED_INFORMATION _ASSEMBLY_FILE_DETAILED_INFORMATION
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ASSEMBLY_DLL_REDIRECTION_DETAILED_INFORMATION ASSEMBLY_FILE_DETAILED_INFORMATION
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PASSEMBLY_DLL_REDIRECTION_DETAILED_INFORMATION PASSEMBLY_FILE_DETAILED_INFORMATION
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PCASSEMBLY_DLL_REDIRECTION_DETAILED_INFORMATION PCASSEMBLY_FILE_DETAILED_INFORMATION

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _ACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION {
      DWORD ulFlags;
      DWORD ul_Encoded_Assembly_ਪਛਾਣ_ਤੱਤ_ਲੰਮਾਈ;
      DWORD ul_Manifest_ਰਸਤਾ_Type;
      DWORD ul_Manifest_ਰਸਤਾ_ਲੰਮਾਈ;
      LARGE_INTEGER li_Manifest_ਆਖਰੀ_Write_ਸਮਾਂ;
      DWORD ul_Policy_ਰਸਤਾ_Type;
      DWORD ul_Policy_ਰਸਤਾ_ਲੰਮਾਈ;
      LARGE_INTEGER li_Policy_ਆਖਰੀ_Write_ਸਮਾਂ;
      DWORD ul_Metadata_Satellite_Roster_ਸੂਚਕਾਂਕ;
      DWORD ul_Manifest_ਸੰਸਕਰਣ_Major;
      DWORD ul_Manifest_ਸੰਸਕਰਣ_Minor;
      DWORD ul_Policy_ਸੰਸਕਰਣ_Major;
      DWORD ul_Policy_ਸੰਸਕਰਣ_Minor;
      DWORD ul_Assembly_Directory_Name_ਲੰਮਾਈ;
      PCWSTR lp_Assembly_Encoded_Assembly_ਪਛਾਣ_ਤੱਤ;
      PCWSTR lp_Assembly_Manifest_ਰਸਤਾ;
      PCWSTR lp_Assembly_Policy_ਰਸਤਾ;
      PCWSTR lpAssemblyDirectoryName;
      DWORD ul_File_ਗਿਣਤੀ;
    } ACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION,*PACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਅਚਲ ਬਣਤਰ _ACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION *PCACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _ACTIVATION_CONTEXT_DETAILED_INFORMATION {
      DWORD dwFlags;
      DWORD ul_Format_ਸੰਸਕਰਣ;
      DWORD ul_Assembly_ਗਿਣਤੀ;
      DWORD ul_ਜੜ੍ਹ_Manifest_ਰਸਤਾ_Type;
      DWORD ul_ਜੜ੍ਹ_Manifest_ਰਸਤਾ_Chars;
      DWORD ul_ਜੜ੍ਹ_Configuration_ਰਸਤਾ_Type;
      DWORD ul_ਜੜ੍ਹ_Configuration_ਰਸਤਾ_Chars;
      DWORD ul_App_Dir_ਰਸਤਾ_Type;
      DWORD ul_App_Dir_ਰਸਤਾ_Chars;
      PCWSTR lp_ਜੜ੍ਹ_Manifest_ਰਸਤਾ;
      PCWSTR lp_ਜੜ੍ਹ_Configuration_ਰਸਤਾ;
      PCWSTR lp_App_Dir_ਰਸਤਾ;
    } ACTIVATION_CONTEXT_DETAILED_INFORMATION,*PACTIVATION_CONTEXT_DETAILED_INFORMATION;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਅਚਲ ਬਣਤਰ _ACTIVATION_CONTEXT_DETAILED_INFORMATION *PCACTIVATION_CONTEXT_DETAILED_INFORMATION;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DLL_PROCESS_ATTACH 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DLL_THREAD_ATTACH 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DLL_THREAD_DETACH 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DLL_PROCESS_DETACH 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DLL_PROCESS_VERIFIER 4

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENTLOG_SEQUENTIAL_READ 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENTLOG_SEEK_READ 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENTLOG_FORWARDS_READ 0x0004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENTLOG_BACKWARDS_READ 0x0008

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENTLOG_SUCCESS 0x0000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENTLOG_ERROR_TYPE 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENTLOG_WARNING_TYPE 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENTLOG_INFORMATION_TYPE 0x0004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENTLOG_AUDIT_SUCCESS 0x0008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENTLOG_AUDIT_FAILURE 0x0010

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENTLOG_ਸ਼ੁਰੂ_PAIRED_EVENT 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENTLOG_ਸਿਰਾ_PAIRED_EVENT 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENTLOG_ਸਿਰਾ_ALL_PAIRED_EVENTS 0x0004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENTLOG_PAIRED_EVENT_ਸਰਗਰਮ 0x0008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENTLOG_PAIRED_EVENT_INACTIVE 0x0010

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _EVENTLOGRECORD {
      DWORD ਲੰਮਾਈ_2;
      DWORD Reserved;
      DWORD ਰਿਕਾਰਡ_ਸੰਖਿਆ;
      DWORD ਸਮਾਂ_Generated;
      DWORD ਸਮਾਂ_Written;
      DWORD EventID;
      ਸ਼ਬਦ_3 EventType;
      ਸ਼ਬਦ_3 ਅੰਕ_ਲੜੀਆਂ;
      ਸ਼ਬਦ_3 EventCategory;
      ਸ਼ਬਦ_3 ReservedFlags;
      DWORD Closing_ਰਿਕਾਰਡ_ਸੰਖਿਆ;
      DWORD String_ਵਿੱਥ;
      DWORD User_Sid_ਲੰਮਾਈ;
      DWORD User_Sid_ਵਿੱਥ;
      DWORD ਅੰਕੜੇ_ਲੰਮਾਈ;
      DWORD ਅੰਕੜੇ_ਵਿੱਥ_2;
    } EVENTLOGRECORD,*PEVENTLOGRECORD;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAXLOGICALLOGNAMESIZE 256

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _EVENTSFORLOGFILE{
      DWORD ul_ਮਾਪ;
      WCHAR szLogicalLogFile[MAXLOGICALLOGNAMESIZE];
      DWORD ul_ਅੰਕ_ਰਿਕਾਰਡਾਂ;
      EVENTLOGRECORD p_Event_Log_ਰਿਕਾਰਡਾਂ[];
    } EVENTSFORLOGFILE,*PEVENTSFORLOGFILE;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _PACKEDEVENTINFO{
      DWORD ul_ਮਾਪ;
      DWORD ul_ਅੰਕ_Events_For_Log_File;
      DWORD ulOffsets[];
    } PACKEDEVENTINFO,*PPACKEDEVENTINFO;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੁੰਜੀ_QUERY_ਮੁੱਲ (0x0001)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੁੰਜੀ_ਸੈੱਟ_ਮੁੱਲ (0x0002)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੁੰਜੀ_CREATE_SUB_ਕੁੰਜੀ (0x0004)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੁੰਜੀ_ENUMERATE_SUB_ਕੁੰਜੀਆਂ (0x0008)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੁੰਜੀ_NOTIFY (0x0010)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੁੰਜੀ_CREATE_LINK (0x0020)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੁੰਜੀ_WOW64_32_ਕੁੰਜੀ (0x0200)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੁੰਜੀ_WOW64_64_ਕੁੰਜੀ (0x0100)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੁੰਜੀ_WOW64_RES (0x0300)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੁੰਜੀ_READ ((STANDARD_RIGHTS_READ | ਕੁੰਜੀ_QUERY_ਮੁੱਲ | ਕੁੰਜੀ_ENUMERATE_SUB_ਕੁੰਜੀਆਂ | ਕੁੰਜੀ_NOTIFY) & (~SYNCHRONIZE))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੁੰਜੀ_WRITE ((STANDARD_RIGHTS_WRITE | ਕੁੰਜੀ_ਸੈੱਟ_ਮੁੱਲ | ਕੁੰਜੀ_CREATE_SUB_ਕੁੰਜੀ) & (~SYNCHRONIZE))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੁੰਜੀ_EXECUTE ((ਕੁੰਜੀ_READ) & (~SYNCHRONIZE))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੁੰਜੀ_ALL_ACCESS ((STANDARD_RIGHTS_ALL | ਕੁੰਜੀ_QUERY_ਮੁੱਲ | ਕੁੰਜੀ_ਸੈੱਟ_ਮੁੱਲ | ਕੁੰਜੀ_CREATE_SUB_ਕੁੰਜੀ | ਕੁੰਜੀ_ENUMERATE_SUB_ਕੁੰਜੀਆਂ | ਕੁੰਜੀ_NOTIFY | ਕੁੰਜੀ_CREATE_LINK) & (~SYNCHRONIZE))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_OPTION_RESERVED (0x00000000L)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_OPTION_NON_VOLATILE (0x00000000L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_OPTION_VOLATILE (0x00000001L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_OPTION_CREATE_LINK (0x00000002L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_OPTION_BACKUP_RESTORE (0x00000004L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_OPTION_OPEN_LINK (0x00000008L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_LEGAL_OPTION (REG_OPTION_RESERVED | REG_OPTION_NON_VOLATILE | REG_OPTION_VOLATILE | REG_OPTION_CREATE_LINK | REG_OPTION_BACKUP_RESTORE | REG_OPTION_OPEN_LINK)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_CREATED_NEW_ਕੁੰਜੀ (0x00000001L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_OPENED_EXISTING_ਕੁੰਜੀ (0x00000002L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_STANDARD_FORMAT 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_LATEST_FORMAT 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_NO_COMPRESSION 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_ਸਾਰਾ_HIVE_VOLATILE (0x00000001L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_REFRESH_HIVE (0x00000002L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_NO_LAZY_FLUSH (0x00000004L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_FORCE_RESTORE (0x00000008L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_FORCE_UNLOAD 1

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_NOTIFY_CHANGE_NAME (0x00000001L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_NOTIFY_CHANGE_ਗੁਣ (0x00000002L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_NOTIFY_CHANGE_ਆਖਰੀ_ਸੈੱਟ (0x00000004L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_NOTIFY_CHANGE_SECURITY (0x00000008L)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_LEGAL_CHANGE_FILTER (REG_NOTIFY_CHANGE_NAME | REG_NOTIFY_CHANGE_ਗੁਣ | REG_NOTIFY_CHANGE_ਆਖਰੀ_ਸੈੱਟ | REG_NOTIFY_CHANGE_SECURITY)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_NONE (0)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_SZ (1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_EXPAND_SZ (2)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_ਦੁਆਧਾਰੀ (3)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_DWORD (4)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_DWORD_LITTLE_ENDIAN (4)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_DWORD_BIG_ENDIAN (5)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_LINK (6)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_MULTI_SZ (7)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_RESOURCE_LIST (8)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_ਭਰਿਆ_RESOURCE_DESCRIPTOR (9)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_RESOURCE_REQUIREMENTS_LIST (10)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_QWORD (11)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_QWORD_LITTLE_ENDIAN (11)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERVICE_KERNEL_DRIVER 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERVICE_FILE_SYSTEM_DRIVER 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERVICE_ADAPTER 0x00000004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERVICE_RECOGNIZER_DRIVER 0x00000008

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERVICE_DRIVER (SERVICE_KERNEL_DRIVER | SERVICE_FILE_SYSTEM_DRIVER | SERVICE_RECOGNIZER_DRIVER)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERVICE_WIN32_OWN_PROCESS 0x00000010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERVICE_WIN32_SHARE_PROCESS 0x00000020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERVICE_WIN32 (SERVICE_WIN32_OWN_PROCESS | SERVICE_WIN32_SHARE_PROCESS)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERVICE_INTERACTIVE_PROCESS 0x00000100

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERVICE_TYPE_ALL (SERVICE_WIN32 | SERVICE_ADAPTER | SERVICE_DRIVER | SERVICE_INTERACTIVE_PROCESS)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERVICE_BOOT_ਸ਼ੁਰੂ 0x00000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERVICE_SYSTEM_ਸ਼ੁਰੂ 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERVICE_AUTO_ਸ਼ੁਰੂ 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERVICE_DEMAND_ਸ਼ੁਰੂ 0x00000003
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERVICE_DISABLED 0x00000004

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERVICE_ERROR_IGNORE 0x00000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERVICE_ERROR_ਸਾਧਾਰਨ 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERVICE_ERROR_SEVERE 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERVICE_ERROR_CRITICAL 0x00000003

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਗਿਣਤੀ CM_SERVICE_ਗੰਢ_TYPE {
      DriverType = SERVICE_KERNEL_DRIVER,FileSystemType = SERVICE_FILE_SYSTEM_DRIVER,Win32ServiceOwnProcess = SERVICE_WIN32_OWN_PROCESS,
      Win32ServiceShareProcess = SERVICE_WIN32_SHARE_PROCESS,AdapterType = SERVICE_ADAPTER,RecognizerType = SERVICE_RECOGNIZER_DRIVER
    } SERVICE_ਗੰਢ_TYPE;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਗਿਣਤੀ CM_SERVICE_ਲੱਦੋ_TYPE {
      Boot_ਲੱਦੋ = SERVICE_BOOT_ਸ਼ੁਰੂ,System_ਲੱਦੋ = SERVICE_SYSTEM_ਸ਼ੁਰੂ,Auto_ਲੱਦੋ = SERVICE_AUTO_ਸ਼ੁਰੂ,Demand_ਲੱਦੋ = SERVICE_DEMAND_ਸ਼ੁਰੂ,
      Disable_ਲੱਦੋ = SERVICE_DISABLED
    } SERVICE_ਲੱਦੋ_TYPE;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਗਿਣਤੀ _CM_ERROR_CONTROL_TYPE {
      IgnoreError = SERVICE_ERROR_IGNORE,ਸਾਧਾਰਨ_Error = SERVICE_ERROR_ਸਾਧਾਰਨ,SevereError = SERVICE_ERROR_SEVERE,CriticalError = SERVICE_ERROR_CRITICAL
    } SERVICE_ERROR_TYPE;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_ERASE_SHORT 0L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_ERASE_LONG 1L

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਫੀਤਾ_ERASE {
      DWORD Type;
      BOOLEAN ਤੁਰੰਤ_2;
    } ਫੀਤਾ_ERASE_2,*PTAPE_ERASE;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_ਲੱਦੋ 0L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_UNLOAD 1L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_TENSION 2L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_ਤਾਲਾ 3L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_UNLOCK 4L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_FORMAT 5L

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਫੀਤਾ_PREPARE {
      DWORD Operation;
      BOOLEAN ਤੁਰੰਤ_2;
    } ਫੀਤਾ_PREPARE_2,*PTAPE_PREPARE;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_SETMARKS 0L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_FILEMARKS 1L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_SHORT_FILEMARKS 2L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_LONG_FILEMARKS 3L

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਫੀਤਾ_WRITE_MARKS {
      DWORD Type;
      DWORD ਗਿਣਤੀ_4;
      BOOLEAN ਤੁਰੰਤ_2;
    } ਫੀਤਾ_WRITE_MARKS_2,*PTAPE_WRITE_MARKS;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_ABSOLUTE_POSITION 0L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_LOGICAL_POSITION 1L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_PSEUDO_LOGICAL_POSITION 2L

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਫੀਤਾ_GET_POSITION {
      DWORD Type;
      DWORD ਹਿੱਸੇ_ਕਰੋ_2;
      LARGE_INTEGER ਵਿੱਥ_3;
    } ਫੀਤਾ_GET_POSITION_2,*PTAPE_GET_POSITION;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_REWIND 0L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_ABSOLUTE_ਖੰਡ 1L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_LOGICAL_ਖੰਡ 2L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_PSEUDO_LOGICAL_ਖੰਡ 3L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_SPACE_ਸਿਰਾ_ਦਾ_ਅੰਕੜੇ 4L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_SPACE_RELATIVE_ਖੰਡਾਂ 5L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_SPACE_FILEMARKS 6L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_SPACE_SEQUENTIAL_FMKS 7L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_SPACE_SETMARKS 8L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_SPACE_SEQUENTIAL_SMKS 9L

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਫੀਤਾ_ਸੈੱਟ_POSITION {
      DWORD ਵਿਧੀ_3;
      DWORD ਹਿੱਸੇ_ਕਰੋ_2;
      LARGE_INTEGER ਵਿੱਥ_3;
      BOOLEAN ਤੁਰੰਤ_2;
    } ਫੀਤਾ_ਸੈੱਟ_POSITION_2,*PTAPE_ਸੈੱਟ_POSITION;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_FIXED 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_SELECT 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_INITIATOR 0x00000004

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_ERASE_SHORT 0x00000010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_ERASE_LONG 0x00000020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_ERASE_BOP_ONLY 0x00000040
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_ERASE_ਤੁਰੰਤ 0x00000080

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_ਫੀਤਾ_ਸਮਰੱਥਾ 0x00000100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_ਫੀਤਾ_ਬਚਿਆ 0x00000200
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_FIXED_ਖੰਡ 0x00000400
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_VARIABLE_ਖੰਡ 0x00000800

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_WRITE_PROTECT 0x00001000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_EOT_WZ_ਮਾਪ 0x00002000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_ECC 0x00010000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_COMPRESSION 0x00020000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_PADDING 0x00040000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_REPORT_SMKS 0x00080000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_GET_ABSOLUTE_BLK 0x00100000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_GET_LOGICAL_BLK 0x00200000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_ਸੈੱਟ_EOT_WZ_ਮਾਪ 0x00400000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_EJECT_MEDIA 0x01000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_CLEAN_ਬੇਨਤੀਆਂ 0x02000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_ਸੈੱਟ_CMP_BOP_ONLY 0x04000000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_RESERVED_ਦੋਆਧਾਰੀ_ਅੰਕ 0x80000000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_ਲੱਦੋ_UNLOAD 0x80000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_TENSION 0x80000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_ਤਾਲਾ_UNLOCK 0x80000004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_REWIND_ਤੁਰੰਤ 0x80000008

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_ਸੈੱਟ_ਖੰਡ_ਮਾਪ 0x80000010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_ਲੱਦੋ_UNLD_IMMED 0x80000020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_TENSION_IMMED 0x80000040
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_ਤਾਲਾ_UNLK_IMMED 0x80000080

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_ਸੈੱਟ_ECC 0x80000100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_ਸੈੱਟ_COMPRESSION 0x80000200
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_ਸੈੱਟ_PADDING 0x80000400
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_ਸੈੱਟ_REPORT_SMKS 0x80000800

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_ABSOLUTE_BLK 0x80001000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_ABS_BLK_IMMED 0x80002000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_LOGICAL_BLK 0x80004000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_LOG_BLK_IMMED 0x80008000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_ਸਿਰਾ_ਦਾ_ਅੰਕੜੇ 0x80010000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_RELATIVE_BLKS 0x80020000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_FILEMARKS 0x80040000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_SEQUENTIAL_FMKS 0x80080000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_SETMARKS 0x80100000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_SEQUENTIAL_SMKS 0x80200000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_ਉਲਟ_POSITION 0x80400000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_SPACE_ਤੁਰੰਤ 0x80800000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_WRITE_SETMARKS 0x81000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_WRITE_FILEMARKS 0x82000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_WRITE_SHORT_FMKS 0x84000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_WRITE_LONG_FMKS 0x88000000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_WRITE_MARK_IMMED 0x90000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_FORMAT 0xA0000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_FORMAT_ਤੁਰੰਤ 0xC0000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_DRIVE_ਉੱਚਾ_FEATURES 0x80000000

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਫੀਤਾ_GET_DRIVE_PARAMETERS {
      BOOLEAN ECC;
      BOOLEAN Compression;
      BOOLEAN ਅੰਕੜੇ_Padding;
      BOOLEAN ReportSetmarks;
      DWORD Default_ਖੰਡ_ਮਾਪ;
      DWORD ਵੱਧ_ਤੋਂ_ਵੱਧ_ਖੰਡ_ਮਾਪ;
      DWORD Minimum_ਖੰਡ_ਮਾਪ;
      DWORD ਵੱਧ_ਤੋਂ_ਵੱਧ_ਹਿੱਸੇ_ਕਰੋ_ਗਿਣਤੀ;
      DWORD Features_ਨੀਵਾਂ;
      DWORD Features_ਉੱਚਾ;
      DWORD EOTWarning_Zone_ਮਾਪ;
    } ਫੀਤਾ_GET_DRIVE_PARAMETERS_2,*PTAPE_GET_DRIVE_PARAMETERS;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਫੀਤਾ_ਸੈੱਟ_DRIVE_PARAMETERS {
      BOOLEAN ECC;
      BOOLEAN Compression;
      BOOLEAN ਅੰਕੜੇ_Padding;
      BOOLEAN ReportSetmarks;
      DWORD EOTWarning_Zone_ਮਾਪ;
    } ਫੀਤਾ_ਸੈੱਟ_DRIVE_PARAMETERS_2,*PTAPE_ਸੈੱਟ_DRIVE_PARAMETERS;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਫੀਤਾ_GET_MEDIA_PARAMETERS {
      LARGE_INTEGER ਸਮਰੱਥਾ;
      LARGE_INTEGER ਬਚਿਆ;
      DWORD ਖੰਡ_ਮਾਪ;
      DWORD ਹਿੱਸੇ_ਕਰੋ_ਗਿਣਤੀ;
      BOOLEAN WriteProtected;
    } ਫੀਤਾ_GET_MEDIA_PARAMETERS_2,*PTAPE_GET_MEDIA_PARAMETERS;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਫੀਤਾ_ਸੈੱਟ_MEDIA_PARAMETERS {
      DWORD ਖੰਡ_ਮਾਪ;
    } ਫੀਤਾ_ਸੈੱਟ_MEDIA_PARAMETERS_2,*PTAPE_ਸੈੱਟ_MEDIA_PARAMETERS;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_FIXED_PARTITIONS 0L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_SELECT_PARTITIONS 1L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_INITIATOR_PARTITIONS 2L

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਫੀਤਾ_CREATE_ਹਿੱਸੇ_ਕਰੋ {
      DWORD ਵਿਧੀ_3;
      DWORD ਗਿਣਤੀ_4;
      DWORD ਮਾਪ_3;
    } ਫੀਤਾ_CREATE_ਹਿੱਸੇ_ਕਰੋ_2,*PTAPE_CREATE_ਹਿੱਸੇ_ਕਰੋ;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_QUERY_DRIVE_PARAMETERS 0L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_QUERY_MEDIA_ਸਮਰੱਥਾ 1L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_CHECK_FOR_DRIVE_PROBLEM 2L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_QUERY_IO_ERROR_ਅੰਕੜੇ 3L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਫੀਤਾ_QUERY_DEVICE_ERROR_ਅੰਕੜੇ 4L

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਫੀਤਾ_WMI_OPERATIONS {
      DWORD ਵਿਧੀ_3;
      DWORD ਅੰਕੜੇ_ਬਫਰ_ਮਾਪ;
      PVOID ਅੰਕੜੇ_ਬਫਰ;
    } ਫੀਤਾ_WMI_OPERATIONS_2,*PTAPE_WMI_OPERATIONS;

    ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਗਿਣਤੀ ਫੀਤਾ_DRIVE_PROBLEM_TYPE {
      ਫੀਤਾ_Drive_Problem_None,ਫੀਤਾ_Drive_Read_Write_Warning,ਫੀਤਾ_Drive_Read_Write_Error,ਫੀਤਾ_Drive_Read_Warning,ਫੀਤਾ_Drive_Write_Warning,ਫੀਤਾ_Drive_Read_Error,ਫੀਤਾ_Drive_Write_Error,ਫੀਤਾ_Drive_Hardware_Error,ਫੀਤਾ_Drive_Unsupported_Media,ਫੀਤਾ_Drive_Scsi_Connection_Error,ਫੀਤਾ_Drive_Timeto_Clean,ਫੀਤਾ_Drive_Clean_Drive_Now,ਫੀਤਾ_Drive_Media_Life_Expired,ਫੀਤਾ_Drive_Snapped_ਫੀਤਾ
    } ਫੀਤਾ_DRIVE_PROBLEM_TYPE_2;

#ਜੇ defined(__x86_64)
    __CRT_INLINE ਬਣਤਰ _TEB *NtCurrentTeb(VOID) { ਵਾਪਸ (ਬਣਤਰ _TEB *)__readgsqword(ਖੇਤਰ_ਵਿੱਥ(NT_TIB,Self)); }
    __CRT_INLINE PVOID GetCurrentFiber(VOID) { ਵਾਪਸ(PVOID)__readgsqword(ਖੇਤਰ_ਵਿੱਥ(NT_TIB,Fiber_ਅੰਕੜੇ)); }
    __CRT_INLINE PVOID Get_Fiber_ਅੰਕੜੇ(VOID) {
      ਵਾਪਸ *(PVOID *)GetCurrentFiber();
    }
#ਜੇ_ਅੰਤ

#ਜੇ(defined(_X86_) && !defined(__x86_64))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PcTeb 0x18
    __CRT_INLINE ਬਣਤਰ _TEB *NtCurrentTeb(ਖਾਲੀ) {
      ਬਣਤਰ _TEB *ret;
      __asm__ ਅਸਥਿਰ ("movl	%%fs:0x18,%0"
	: "=r" (ret));
      ਵਾਪਸ ret;
    }
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACTIVATION_CONTEXT_SECTION_ASSEMBLY_INFORMATION (1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACTIVATION_CONTEXT_SECTION_DLL_REDIRECTION (2)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACTIVATION_CONTEXT_SECTION_ਖਿੜਕੀ_CLASS_REDIRECTION (3)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACTIVATION_CONTEXT_SECTION_COM_SERVER_REDIRECTION (4)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACTIVATION_CONTEXT_SECTION_COM_INTERFACE_REDIRECTION (5)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACTIVATION_CONTEXT_SECTION_COM_TYPE_LIBRARY_REDIRECTION (6)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACTIVATION_CONTEXT_SECTION_COM_PROGID_REDIRECTION (7)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACTIVATION_CONTEXT_SECTION_GLOBAL_OBJECT_RENAME_ਸਾਰਣੀ (8)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACTIVATION_CONTEXT_SECTION_CLR_SURROGATES (9)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACTIVATION_CONTEXT_SECTION_APPLICATION_SETTINGS (10)

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
  }
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
