/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WINNT_
#ವ್ಯಾಖ್ಯಾನಿಸು _WINNT_

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
ಬಾಹ್ಯ "C" {
#ಆದರೆ_ಅಂತ್ಯ

#ಅನ್ತರ್ಭಾವ <ctype.h>
#ವ್ಯಾಖ್ಯಾನಿಸು ANYSIZE_ARRAY 1

//gr #include <specstrings.h>

#ವ್ಯಾಖ್ಯಾನಿಸು RESTRICTED_ಸೂಚಕ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __CRT_UNALIGNED
#ವ್ಯಾಖ್ಯಾನಿಸು __CRT_UNALIGNED
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ defined(__ia64__) || defined(__x86_64) || defined(__aarch64__)
#ವ್ಯಾಖ್ಯಾನಿಸು UNALIGNED __CRT_UNALIGNED
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN64
#ವ್ಯಾಖ್ಯಾನಿಸು UNALIGNED64 __CRT_UNALIGNED
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು UNALIGNED64
#ಆದರೆ_ಅಂತ್ಯ
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು UNALIGNED
#ವ್ಯಾಖ್ಯಾನಿಸು UNALIGNED64
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && (defined(_X86_) && !defined(__x86_64))
#ವ್ಯಾಖ್ಯಾನಿಸು I_X86_
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && defined(__x86_64)
#ವ್ಯಾಖ್ಯಾನಿಸು _AMD64_
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ !defined(I_X86_) && !(defined(_X86_) && !defined(__x86_64)) && !defined(_AMD64_) && defined(__ia64__)
#ಆದರೆ !defined(_IA64_)
#ವ್ಯಾಖ್ಯಾನಿಸು _IA64_
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ


#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN64
#ವ್ಯಾಖ್ಯಾನಿಸು MAX_NATURAL_ALIGNMENT ಗಾತ್ರ(ULONGLONG)
#ವ್ಯಾಖ್ಯಾನಿಸು ಸ್ಮರಣೆ_ಹಂಚಿಕೆ_ALIGNMENT 16
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು MAX_NATURAL_ALIGNMENT ಗಾತ್ರ(DWORD)
#ವ್ಯಾಖ್ಯಾನಿಸು ಸ್ಮರಣೆ_ಹಂಚಿಕೆ_ALIGNMENT 8
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
#ವ್ಯಾಖ್ಯಾನಿಸು TYPE_ALIGNMENT(t) __alignof__ (t)
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು TYPE_ALIGNMENT(t) ಕ್ಷೇತ್ರ_ಸ್ಥಾನಾಂತರ(ರಚನೆ { ಅಕ್ಷರ x; t test; },test)
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN64
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _AMD64_
#ವ್ಯಾಖ್ಯಾನಿಸು PROBE_ALIGNMENT(_s) TYPE_ALIGNMENT(DWORD)
#ಅಥವಾಆದರೆ defined(_IA64_) || defined(_ARM64_)
#ವ್ಯಾಖ್ಯಾನಿಸು PROBE_ALIGNMENT(_s) (TYPE_ALIGNMENT(_s) > TYPE_ALIGNMENT(DWORD) ? TYPE_ALIGNMENT(_s) : TYPE_ALIGNMENT(DWORD))
#ಇಲ್ಲದಿದ್ದರೆ
#ದೋಷ No ಗುರಿ_2 Architecture
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿಸು PROBE_ALIGNMENT32(_s) TYPE_ALIGNMENT(DWORD)
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು PROBE_ALIGNMENT(_s) TYPE_ALIGNMENT(DWORD)
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು C_ASSERT(e) ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಅಕ್ಷರ __C_ASSERT__[(e)?1:-1]

#ಅನ್ತರ್ಭಾವ <basetsd.h>

#ಆದರೆ defined(_X86_) || defined(__ia64__) || defined(__x86_64) || defined(__aarch64__)
#ವ್ಯಾಖ್ಯಾನಿಸು DECLSPEC_IMPORT __declspec(dllimport)
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು DECLSPEC_IMPORT
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ DECLSPEC_NORETURN
#ವ್ಯಾಖ್ಯಾನಿಸು DECLSPEC_NORETURN __declspec(noreturn)
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ DECLSPEC_ALIGN
#ವ್ಯಾಖ್ಯಾನಿಸು DECLSPEC_ALIGN(x) __attribute__ ((aligned(x)))
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ SYSTEM_CACHE_ALIGNMENT_ಗಾತ್ರ
#ಆದರೆ defined(_AMD64_) || defined(I_X86_)
#ವ್ಯಾಖ್ಯಾನಿಸು SYSTEM_CACHE_ALIGNMENT_ಗಾತ್ರ 64
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು SYSTEM_CACHE_ALIGNMENT_ಗಾತ್ರ 128
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ DECLSPEC_CACHEALIGN
#ವ್ಯಾಖ್ಯಾನಿಸು DECLSPEC_CACHEALIGN DECLSPEC_ALIGN(SYSTEM_CACHE_ALIGNMENT_ಗಾತ್ರ)
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ DECLSPEC_UUID
#ವ್ಯಾಖ್ಯಾನಿಸು DECLSPEC_UUID(x)
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ DECLSPEC_NOVTABLE
#ವ್ಯಾಖ್ಯಾನಿಸು DECLSPEC_NOVTABLE
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ DECLSPEC_SELECTANY
#ವ್ಯಾಖ್ಯಾನಿಸು DECLSPEC_SELECTANY __declspec(selectany)
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOP_FUNCTION
#ವ್ಯಾಖ್ಯಾನಿಸು NOP_FUNCTION (ಶೂನ್ಯ)0
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ DECLSPEC_NOINLINE
#ವ್ಯಾಖ್ಯಾನಿಸು DECLSPEC_NOINLINE
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ FORCEINLINE
#ವ್ಯಾಖ್ಯಾನಿಸು FORCEINLINE ಸ್ಥಿರ __inline__
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ DECLSPEC_DEPRECATED
#ವ್ಯಾಖ್ಯಾನಿಸು DECLSPEC_DEPRECATED __declspec(deprecated)
#ವ್ಯಾಖ್ಯಾನಿಸು DEPRECATE_SUPPORTED
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು DECLSPEC_DEPRECATED_DDK
#ವ್ಯಾಖ್ಯಾನಿಸು PRAGMA_DEPRECATED_DDK 0

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಶೂನ್ಯ *PVOID;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಶೂನ್ಯ *PVOID64;

#ವ್ಯಾಖ್ಯಾನಿಸು NTAPI __stdcall
#ವ್ಯಾಖ್ಯಾನಿಸು NTSYSAPI DECLSPEC_IMPORT
#ವ್ಯಾಖ್ಯಾನಿಸು NTSYSCALLAPI DECLSPEC_IMPORT

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ VOID
#ವ್ಯಾಖ್ಯಾನಿಸು VOID ಶೂನ್ಯ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಅಕ್ಷರ CHAR;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಗಿಡ್ಡ SHORT;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ದೀರ್ಘ LONG;
#ಆದರೆ_ಅಂತ್ಯ

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ wchar_t WCHAR;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ WCHAR *PWCHAR,*LPWCH,*PWCH;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ CONST WCHAR *LPCWCH,*PCWCH;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ WCHAR *NWPSTR,*LPWSTR,*PWSTR;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PWSTR *PZPWSTR;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ CONST PWSTR *PCZPWSTR;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ WCHAR UNALIGNED *LPUWSTR,*PUWSTR;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ CONST WCHAR *LPCWSTR,*PCWSTR;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PCWSTR *PZPCWSTR;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ CONST WCHAR UNALIGNED *LPCUWSTR,*PCUWSTR;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ CHAR *PCHAR,*LPCH,*PCH;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ CONST CHAR *LPCCH,*PCCH;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ CHAR *NPSTR,*LPSTR,*PSTR;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PSTR *PZPSTR;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ CONST PSTR *PCZPSTR;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ CONST CHAR *LPCSTR,*PCSTR;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PCSTR *PZPCSTR;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _TCHAR_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _TCHAR_DEFINED
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ WCHAR TCHAR,*PTCHAR;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ WCHAR TBYTE ,*PTBYTE;
#ಆದರೆ_ಅಂತ್ಯ

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPWSTR LPTCH,PTCH;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPWSTR PTSTR,LPTSTR;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPCWSTR PCTSTR,LPCTSTR;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPUWSTR PUTSTR,LPUTSTR;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPCUWSTR PCUTSTR,LPCUTSTR;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPWSTR LP;
#ವ್ಯಾಖ್ಯಾನಿಸು __TEXT(quote) L##quote
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _TCHAR_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _TCHAR_DEFINED
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಅಕ್ಷರ TCHAR,*PTCHAR;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ TBYTE ,*PTBYTE;
#ಆದರೆ_ಅಂತ್ಯ

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPSTR LPTCH,PTCH;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPSTR PTSTR,LPTSTR,PUTSTR,LPUTSTR;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPCSTR PCTSTR,LPCTSTR,PCUTSTR,LPCUTSTR;
#ವ್ಯಾಖ್ಯಾನಿಸು __TEXT(quote) quote
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು ಪಠ್ಯ_3(quote) __TEXT(quote)

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ SHORT *PSHORT;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LONG *PLONG;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಶೂನ್ಯ *HANDLE;
#ವ್ಯಾಖ್ಯಾನಿಸು DECLARE_HANDLE(name) ರಚನೆ name##__ { ಪೂರ್ಣಾಂಕ ಬಳಸದ; }; ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ name##__ *name
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ HANDLE *PHANDLE;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ BYTE FCHAR;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಶಬ್ದ_3 FSHORT;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ DWORD FLONG;

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _HRESULT_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _HRESULT_DEFINED
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LONG HRESULT;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
#ವ್ಯಾಖ್ಯಾನಿಸು EXTERN_C ಬಾಹ್ಯ "C"
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು EXTERN_C ಬಾಹ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು STDMETHODCALLTYPE WINAPI
#ವ್ಯಾಖ್ಯಾನಿಸು STDMETHODVCALLTYPE __cdecl
#ವ್ಯಾಖ್ಯಾನಿಸು STDAPICALLTYPE WINAPI
#ವ್ಯಾಖ್ಯಾನಿಸು STDAPIVCALLTYPE __cdecl
#ವ್ಯಾಖ್ಯಾನಿಸು STDAPI EXTERN_C HRESULT WINAPI
#ವ್ಯಾಖ್ಯಾನಿಸು STDAPI_(type) EXTERN_C type WINAPI
#ವ್ಯಾಖ್ಯಾನಿಸು STDMETHODIMP HRESULT WINAPI
#ವ್ಯಾಖ್ಯಾನಿಸು STDMETHODIMP_(type) type WINAPI
#ವ್ಯಾಖ್ಯಾನಿಸು STDAPIV EXTERN_C HRESULT STDAPIVCALLTYPE
#ವ್ಯಾಖ್ಯಾನಿಸು STDAPIV_(type) EXTERN_C type STDAPIVCALLTYPE
#ವ್ಯಾಖ್ಯಾನಿಸು STDMETHODIMPV HRESULT STDMETHODVCALLTYPE
#ವ್ಯಾಖ್ಯಾನಿಸು STDMETHODIMPV_(type) type STDMETHODVCALLTYPE

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಅಕ್ಷರ CCHAR;
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _LCID_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _LCID_DEFINED
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ DWORD LCID;
#ಆದರೆ_ಅಂತ್ಯ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PDWORD PLCID;
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _LANGID_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _LANGID_DEFINED
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಶಬ್ದ_3 LANGID;
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_ERROR_ಮುಖವಾಡ 0x20000000
#ವ್ಯಾಖ್ಯಾನಿಸು ERROR_SEVERITY_SUCCESS 0x00000000
#ವ್ಯಾಖ್ಯಾನಿಸು ERROR_SEVERITY_INFORMATIONAL 0x40000000
#ವ್ಯಾಖ್ಯಾನಿಸು ERROR_SEVERITY_WARNING 0x80000000
#ವ್ಯಾಖ್ಯಾನಿಸು ERROR_SEVERITY_ERROR 0xC0000000

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __ia64__
  __declspec(align(16))
#ಆದರೆ_ಅಂತ್ಯ
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _FLOAT128 {
      __int64 ಕೆಳಗಿನ_Part;
      __int64 ಮೇಲಿನ_Part;
  } FLOAT128;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ FLOAT128 *PFLOAT128;

#ವ್ಯಾಖ್ಯಾನಿಸು _ULONGLONG_
#ಆದರೆ((!(defined(_X86_) && !defined(__x86_64)) || (defined(INTEGRAL_MAX_ಬಿಟ್ಟುಗಳು) && INTEGRAL_MAX_ಬಿಟ್ಟುಗಳು >= 64)))
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ __int64 LONGLONG;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ __int64 ULONGLONG;

#ವ್ಯಾಖ್ಯಾನಿಸು MAXLONGLONG (0x7fffffffffffffff)
#ಇಲ್ಲದಿದ್ದರೆ

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ದ್ವಿಗುಣ LONGLONG;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ದ್ವಿಗುಣ ULONGLONG;
#ಆದರೆ_ಅಂತ್ಯ

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LONGLONG *PLONGLONG;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ULONGLONG *PULONGLONG;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LONGLONG USN;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಒಕ್ಕೂಟ _LARGE_INTEGER {
    ರಚನೆ {
      DWORD ಕೆಳಗಿನ_Part;
      LONG ಮೇಲಿನ_Part;
    };
    ರಚನೆ {
      DWORD ಕೆಳಗಿನ_Part;
      LONG ಮೇಲಿನ_Part;
    } u;
    LONGLONG QuadPart;
  } LARGE_INTEGER;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LARGE_INTEGER *PLARGE_INTEGER;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಒಕ್ಕೂಟ _ULARGE_INTEGER {
    ರಚನೆ {
      DWORD ಕೆಳಗಿನ_Part;
      DWORD ಮೇಲಿನ_Part;
    };
    ರಚನೆ {
      DWORD ಕೆಳಗಿನ_Part;
      DWORD ಮೇಲಿನ_Part;
    } u;
    ULONGLONG QuadPart;
  } ULARGE_INTEGER;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ULARGE_INTEGER *PULARGE_INTEGER;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _LUID {
    DWORD ಕೆಳಗಿನ_Part;
    LONG ಮೇಲಿನ_Part;
  } LUID,*PLUID;

#ವ್ಯಾಖ್ಯಾನಿಸು _DWORDLONG_
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ULONGLONG DWORDLONG;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ DWORDLONG *PDWORDLONG;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ RC_INVOKED
#ವ್ಯಾಖ್ಯಾನಿಸು Int32x32To64(a,b) ((LONGLONG)((LONG)(a)) *(LONGLONG)((LONG)(b)))
#ವ್ಯಾಖ್ಯಾನಿಸು UInt32x32To64(a,b) ((ULONGLONG)((DWORD)(a)) *(ULONGLONG)((DWORD)(b)))
#ವ್ಯಾಖ್ಯಾನಿಸು Int64ShrlMod32(a,b) ((ULONGLONG)(a) >> (b))
#ಅಥವಾಆದರೆ (defined(_X86_) && !defined(__x86_64))
#ವ್ಯಾಖ್ಯಾನಿಸು Int32x32To64(a,b) (LONGLONG)((LONGLONG)(LONG)(a) *(LONG)(b))
#ವ್ಯಾಖ್ಯಾನಿಸು UInt32x32To64(a,b) (ULONGLONG)((ULONGLONG)(DWORD)(a) *(DWORD)(b))
#ವ್ಯಾಖ್ಯಾನಿಸು Int64ShrlMod32(a,b) ((DWORDLONG)(a)>>(b))
#ಅಥವಾಆದರೆ defined(__ia64__) || defined(__x86_64) || defined(__aarch64__)
#ವ್ಯಾಖ್ಯಾನಿಸು Int32x32To64(a,b) ((LONGLONG)((LONG)(a)) *(LONGLONG)((LONG)(b)))
#ವ್ಯಾಖ್ಯಾನಿಸು UInt32x32To64(a,b) ((ULONGLONG)((DWORD)(a)) *(ULONGLONG)((DWORD)(b)))
#ವ್ಯಾಖ್ಯಾನಿಸು Int64ShrlMod32(a,b) ((ULONGLONG)(a) >> (b))
#ಇಲ್ಲದಿದ್ದರೆ
#ದೋಷ Must define a ಗುರಿ architecture.
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು Int64ShraMod32(a,b) ((LONGLONG)(a) >> (b))
#ವ್ಯಾಖ್ಯಾನಿಸು Int64ShllMod32(a,b) ((ULONGLONG)(a) << (b))

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
  ಬಾಹ್ಯ "C" {
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __x86_64

#ವ್ಯಾಖ್ಯಾನಿಸು RotateLeft8 _rotl8
#ವ್ಯಾಖ್ಯಾನಿಸು RotateLeft16 _rotl16
#ವ್ಯಾಖ್ಯಾನಿಸು RotateRight8 _rotr8
#ವ್ಯಾಖ್ಯಾನಿಸು RotateRight16 _rotr16

    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ __cdecl _rotl8(ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ ಮೌಲ್ಯ_3,ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ ಸರಿಸು_3);
    ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ __cdecl _rotl16(ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ ಮೌಲ್ಯ_3,ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ ಸರಿಸು_3);
    ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ __cdecl _rotr8(ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ ಮೌಲ್ಯ_3,ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ ಸರಿಸು_3);
    ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ __cdecl _rotr16(ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ ಮೌಲ್ಯ_3,ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ ಸರಿಸು_3);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು RotateLeft32 _rotl
#ವ್ಯಾಖ್ಯಾನಿಸು RotateLeft64 _rotl64
#ವ್ಯಾಖ್ಯಾನಿಸು RotateRight32 _rotr
#ವ್ಯಾಖ್ಯಾನಿಸು RotateRight64 _rotr64

    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ __cdecl _rotl(ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ ಮೌಲ್ಯ_3,ಪೂರ್ಣಾಂಕ ಸರಿಸು_3);
    ಚಿಹ್ನೆರಹಿತ __int64 __cdecl _rotl64(ಚಿಹ್ನೆರಹಿತ __int64 ಮೌಲ್ಯ_3,ಪೂರ್ಣಾಂಕ ಸರಿಸು_3);
    ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ __cdecl _rotr(ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ ಮೌಲ್ಯ_3,ಪೂರ್ಣಾಂಕ ಸರಿಸು_3);
    ಚಿಹ್ನೆರಹಿತ __int64 __cdecl _rotr64(ಚಿಹ್ನೆರಹಿತ __int64 ಮೌಲ್ಯ_3,ಪೂರ್ಣಾಂಕ ಸರಿಸು_3);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
  }
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು ANSI_NULL ((CHAR)0)
#ವ್ಯಾಖ್ಯಾನಿಸು UNICODE_NULL ((WCHAR)0)
#ವ್ಯಾಖ್ಯಾನಿಸು UNICODE_STRING_MAX_ಬೈಟುಗಳು ((ಶಬ್ದ_3) 65534)
#ವ್ಯಾಖ್ಯಾನಿಸು UNICODE_STRING_MAX_CHARS (32767)

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _BOOLEAN_
#ವ್ಯಾಖ್ಯಾನಿಸು _BOOLEAN_
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ BYTE BOOLEAN;
#ಆದರೆ_ಅಂತ್ಯ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ BOOLEAN *PBOOLEAN;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ LIST_ನಮೂದು {
    ರಚನೆ LIST_ನಮೂದು *Flink;
    ರಚನೆ LIST_ನಮೂದು *Blink;
  } LIST_ನಮೂದು_2,*PLIST_ನಮೂದು,*RESTRICTED_ಸೂಚಕ PRLIST_ನಮೂದು;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ SINGLE_LIST_ನಮೂದು {
    ರಚನೆ SINGLE_LIST_ನಮೂದು *ಮುಂದಿನ_2;
  } SINGLE_LIST_ನಮೂದು_2,*PSINGLE_LIST_ನಮೂದು;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ LIST_ENTRY32 {
    DWORD Flink;
    DWORD Blink;
  } LIST_ENTRY32;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LIST_ENTRY32 *PLIST_ENTRY32;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ LIST_ENTRY64 {
    ULONGLONG Flink;
    ULONGLONG Blink;
  } LIST_ENTRY64;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LIST_ENTRY64 *PLIST_ENTRY64;

#ಅನ್ತರ್ಭಾವ <guiddef.h>

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __OBJECTID_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು __OBJECTID_DEFINED
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _OBJECTID {
    GUID Lineage;
    DWORD Uniquifier;
  } OBJECTID;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು MINCHAR 0x80
#ವ್ಯಾಖ್ಯಾನಿಸು MAXCHAR 0x7f
#ವ್ಯಾಖ್ಯಾನಿಸು MINSHORT 0x8000
#ವ್ಯಾಖ್ಯಾನಿಸು MAXSHORT 0x7fff
#ವ್ಯಾಖ್ಯಾನಿಸು MINLONG 0x80000000
#ವ್ಯಾಖ್ಯಾನಿಸು MAXLONG 0x7fffffff
#ವ್ಯಾಖ್ಯಾನಿಸು MAXBYTE 0xff
#ವ್ಯಾಖ್ಯಾನಿಸು MAXWORD 0xffff
#ವ್ಯಾಖ್ಯಾನಿಸು MAXDWORD 0xffffffff

#ವ್ಯಾಖ್ಯಾನಿಸು ಕ್ಷೇತ್ರ_ಸ್ಥಾನಾಂತರ(type,ಕ್ಷೇತ್ರ) ((LONG)(LONG_PTR)&(((type *)0)->ಕ್ಷೇತ್ರ))
#ವ್ಯಾಖ್ಯಾನಿಸು RTL_ಕ್ಷೇತ್ರ_ಗಾತ್ರ(type,ಕ್ಷೇತ್ರ) (ಗಾತ್ರ(((type *)0)->ಕ್ಷೇತ್ರ))
#ವ್ಯಾಖ್ಯಾನಿಸು RTL_SIZEOF_THROUGH_ಕ್ಷೇತ್ರ(type,ಕ್ಷೇತ್ರ) (ಕ್ಷೇತ್ರ_ಸ್ಥಾನಾಂತರ(type,ಕ್ಷೇತ್ರ) + RTL_ಕ್ಷೇತ್ರ_ಗಾತ್ರ(type,ಕ್ಷೇತ್ರ))
#ವ್ಯಾಖ್ಯಾನಿಸು RTL_ಒಳಗೊಂಡಿದೆ_ಕ್ಷೇತ್ರ(Struct,ಗಾತ್ರ_4,ಕ್ಷೇತ್ರ_2) ((((PCHAR)(&(Struct)->ಕ್ಷೇತ್ರ_2)) + ಗಾತ್ರ((Struct)->ಕ್ಷೇತ್ರ_2)) <= (((PCHAR)(Struct))+(ಗಾತ್ರ_4)))
#ವ್ಯಾಖ್ಯಾನಿಸು RTL_ಸಂಖ್ಯೆ_ದ_V1(A) (ಗಾತ್ರ(A)/ಗಾತ್ರ((A)[0]))
#ವ್ಯಾಖ್ಯಾನಿಸು RTL_ಸಂಖ್ಯೆ_ದ_V2(A) RTL_ಸಂಖ್ಯೆ_ದ_V1(A)

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ ENABLE_RTL_ಸಂಖ್ಯೆ_ದ_V2
#ವ್ಯಾಖ್ಯಾನಿಸು RTL_ಸಂಖ್ಯೆ_ದ(A) RTL_ಸಂಖ್ಯೆ_ದ_V2(A)
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು RTL_ಸಂಖ್ಯೆ_ದ(A) RTL_ಸಂಖ್ಯೆ_ದ_V1(A)
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು ARRAYSIZE(A) RTL_ಸಂಖ್ಯೆ_ದ_V2(A)
#ವ್ಯಾಖ್ಯಾನಿಸು _ARRAYSIZE(A) RTL_ಸಂಖ್ಯೆ_ದ_V1(A)

#ವ್ಯಾಖ್ಯಾನಿಸು RTL_ಕ್ಷೇತ್ರ_TYPE(type,ಕ್ಷೇತ್ರ) (((type*)0)->ಕ್ಷೇತ್ರ)
#ವ್ಯಾಖ್ಯಾನಿಸು RTL_ಸಂಖ್ಯೆ_ದ_ಕ್ಷೇತ್ರ(type,ಕ್ಷೇತ್ರ) (RTL_ಸಂಖ್ಯೆ_ದ(RTL_ಕ್ಷೇತ್ರ_TYPE(type,ಕ್ಷೇತ್ರ)))
#ವ್ಯಾಖ್ಯಾನಿಸು RTL_PADDING_BETWEEN_FIELDS(T,F1,F2) ((ಕ್ಷೇತ್ರ_ಸ್ಥಾನಾಂತರ(T,F2) > ಕ್ಷೇತ್ರ_ಸ್ಥಾನಾಂತರ(T,F1)) ? (ಕ್ಷೇತ್ರ_ಸ್ಥಾನಾಂತರ(T,F2) - ಕ್ಷೇತ್ರ_ಸ್ಥಾನಾಂತರ(T,F1) - RTL_ಕ್ಷೇತ್ರ_ಗಾತ್ರ(T,F1)) : (ಕ್ಷೇತ್ರ_ಸ್ಥಾನಾಂತರ(T,F1) - ಕ್ಷೇತ್ರ_ಸ್ಥಾನಾಂತರ(T,F2) - RTL_ಕ್ಷೇತ್ರ_ಗಾತ್ರ(T,F2)))

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
#ವ್ಯಾಖ್ಯಾನಿಸು RTL_CONST_CAST(type) const_cast<type>
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು RTL_CONST_CAST(type) (type)
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು RTL_ಬಿಟ್ಟುಗಳು_ದ(ಗಾತ್ರ_ದ_Arg) (ಗಾತ್ರ(ಗಾತ್ರ_ದ_Arg) *8)
#ವ್ಯಾಖ್ಯಾನಿಸು RTL_ಬಿಟ್ಟುಗಳು_ದ_ಕ್ಷೇತ್ರ(type,ಕ್ಷೇತ್ರ) (RTL_ಬಿಟ್ಟುಗಳು_ದ(RTL_ಕ್ಷೇತ್ರ_TYPE(type,ಕ್ಷೇತ್ರ)))
#ವ್ಯಾಖ್ಯಾನಿಸು CONTAINING_ದಾಖಲೆ(ವಿಳಾಸ,type,ಕ್ಷೇತ್ರ) ((type *)((PCHAR)(ವಿಳಾಸ) - (ULONG_PTR)(&((type *)0)->ಕ್ಷೇತ್ರ)))

#ವ್ಯಾಖ್ಯಾನಿಸು VER_SERVER_NT 0x80000000
#ವ್ಯಾಖ್ಯಾನಿಸು VER_WORKSTATION_NT 0x40000000
#ವ್ಯಾಖ್ಯಾನಿಸು VER_SUITE_SMALLBUSINESS 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು VER_SUITE_ENTERPRISE 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು VER_SUITE_BACKOFFICE 0x00000004
#ವ್ಯಾಖ್ಯಾನಿಸು VER_SUITE_COMMUNICATIONS 0x00000008
#ವ್ಯಾಖ್ಯಾನಿಸು VER_SUITE_TERMINAL 0x00000010
#ವ್ಯಾಖ್ಯಾನಿಸು VER_SUITE_SMALLBUSINESS_RESTRICTED 0x00000020
#ವ್ಯಾಖ್ಯಾನಿಸು VER_SUITE_EMBEDDEDNT 0x00000040
#ವ್ಯಾಖ್ಯಾನಿಸು VER_SUITE_DATACENTER 0x00000080
#ವ್ಯಾಖ್ಯಾನಿಸು VER_SUITE_SINGLEUSERTS 0x00000100
#ವ್ಯಾಖ್ಯಾನಿಸು VER_SUITE_PERSONAL 0x00000200
#ವ್ಯಾಖ್ಯಾನಿಸು VER_SUITE_BLADE 0x00000400
#ವ್ಯಾಖ್ಯಾನಿಸು VER_SUITE_EMBEDDED_RESTRICTED 0x00000800
#ವ್ಯಾಖ್ಯಾನಿಸು VER_SUITE_SECURITY_APPLIANCE 0x00001000
#ವ್ಯಾಖ್ಯಾನಿಸು VER_SUITE_STORAGE_SERVER 0x00002000
#ವ್ಯಾಖ್ಯಾನಿಸು VER_SUITE_COMPUTE_SERVER 0x00004000

#ವ್ಯಾಖ್ಯಾನಿಸು ಗುಣಲಬ್ಧ_UNDEFINED                       0x0

#ವ್ಯಾಖ್ಯಾನಿಸು ಗುಣಲಬ್ಧ_ULTIMATE                        0x1
#ವ್ಯಾಖ್ಯಾನಿಸು ಗುಣಲಬ್ಧ_HOME_BASIC                      0x2
#ವ್ಯಾಖ್ಯಾನಿಸು ಗುಣಲಬ್ಧ_HOME_PREMIUM                    0x3
#ವ್ಯಾಖ್ಯಾನಿಸು ಗುಣಲಬ್ಧ_ENTERPRISE                      0x4
#ವ್ಯಾಖ್ಯಾನಿಸು ಗುಣಲಬ್ಧ_HOME_BASIC_N                    0x5
#ವ್ಯಾಖ್ಯಾನಿಸು ಗುಣಲಬ್ಧ_BUSINESS                        0x6
#ವ್ಯಾಖ್ಯಾನಿಸು ಗುಣಲಬ್ಧ_STANDARD_SERVER                 0x7
#ವ್ಯಾಖ್ಯಾನಿಸು ಗುಣಲಬ್ಧ_DATACENTER_SERVER               0x8
#ವ್ಯಾಖ್ಯಾನಿಸು ಗುಣಲಬ್ಧ_SMALLBUSINESS_SERVER            0x9
#ವ್ಯಾಖ್ಯಾನಿಸು ಗುಣಲಬ್ಧ_ENTERPRISE_SERVER               0xa
#ವ್ಯಾಖ್ಯಾನಿಸು ಗುಣಲಬ್ಧ_STARTER                         0xb
#ವ್ಯಾಖ್ಯಾನಿಸು ಗುಣಲಬ್ಧ_DATACENTER_SERVER_CORE          0xc
#ವ್ಯಾಖ್ಯಾನಿಸು ಗುಣಲಬ್ಧ_STANDARD_SERVER_CORE            0xd
#ವ್ಯಾಖ್ಯಾನಿಸು ಗುಣಲಬ್ಧ_ENTERPRISE_SERVER_CORE          0xe
#ವ್ಯಾಖ್ಯಾನಿಸು ಗುಣಲಬ್ಧ_ENTERPRISE_SERVER_IA64          0xf
#ವ್ಯಾಖ್ಯಾನಿಸು ಗುಣಲಬ್ಧ_BUSINESS_N                      0x10
#ವ್ಯಾಖ್ಯಾನಿಸು ಗುಣಲಬ್ಧ_WEB_SERVER                      0x11
#ವ್ಯಾಖ್ಯಾನಿಸು ಗುಣಲಬ್ಧ_CLUSTER_SERVER                  0x12
#ವ್ಯಾಖ್ಯಾನಿಸು ಗುಣಲಬ್ಧ_HOME_SERVER                     0x13
#ವ್ಯಾಖ್ಯಾನಿಸು ಗುಣಲಬ್ಧ_STORAGE_EXPRESS_SERVER          0x14
#ವ್ಯಾಖ್ಯಾನಿಸು ಗುಣಲಬ್ಧ_STORAGE_STANDARD_SERVER         0x15
#ವ್ಯಾಖ್ಯಾನಿಸು ಗುಣಲಬ್ಧ_STORAGE_WORKGROUP_SERVER        0x16
#ವ್ಯಾಖ್ಯಾನಿಸು ಗುಣಲಬ್ಧ_STORAGE_ENTERPRISE_SERVER       0x17
#ವ್ಯಾಖ್ಯಾನಿಸು ಗುಣಲಬ್ಧ_SERVER_FOR_SMALLBUSINESS        0x18
#ವ್ಯಾಖ್ಯಾನಿಸು ಗುಣಲಬ್ಧ_SMALLBUSINESS_SERVER_PREMIUM    0x19

#ವ್ಯಾಖ್ಯಾನಿಸು ಗುಣಲಬ್ಧ_UNLICENSED                      0xabcdabcd

#ವ್ಯಾಖ್ಯಾನಿಸು LANG_NEUTRAL 0x00
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_INVARIANT 0x7f

#ವ್ಯಾಖ್ಯಾನಿಸು LANG_AFRIKAANS 0x36
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_ALBANIAN 0x1c
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_ALSATIAN 0x84
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_AMHARIC 0x5e
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_ARABIC 0x01
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_ARMENIAN 0x2b
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_ASSAMESE 0x4d
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_AZERI 0x2c
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_BASHKIR 0x6d
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_BASQUE 0x2d
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_BELARUSIAN 0x23
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_BENGALI 0x45
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_BRETON 0x7e
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_BOSNIAN 0x1a
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_BOSNIAN_NEUTRAL 0x781a
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_BULGARIAN 0x02
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_ಕ್ಯಾಟಲಾನ್ 0x03
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_CHINESE 0x04
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_CHINESE_SIMPLIFIED 0x04
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_CHINESE_TRADITIONAL 0x7c04
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_CORSICAN 0x83
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_CROATIAN 0x1a
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_CZECH 0x05
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_DANISH 0x06
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_DARI 0x8c
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_DIVEHI 0x65
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_DUTCH 0x13
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_ENGLISH 0x09
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_ESTONIAN 0x25
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_FAEROESE 0x38
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_FARSI 0x29
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_FILIPINO 0x64
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_FINNISH 0x0b
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_FRENCH 0x0c
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_FRISIAN 0x62
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_GALICIAN 0x56
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_GEORGIAN 0x37
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_GERMAN 0x07
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_GREEK 0x08
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_GREENLANDIC 0x6f
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_GUJARATI 0x47
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_HAUSA 0x68
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_HEBREW 0x0d
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_HINDI 0x39
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_HUNGARIAN 0x0e
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_ICELANDIC 0x0f
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_IGBO 0x70
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_INDONESIAN 0x21
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_INUKTITUT 0x5d
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_IRISH 0x3c
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_ITALIAN 0x10
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_JAPANESE 0x11
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_KANNADA 0x4b
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_KASHMIRI 0x60
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_KAZAK 0x3f
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_KHMER 0x53
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_KICHE 0x86
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_KINYARWANDA 0x87
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_KONKANI 0x57
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_KOREAN 0x12
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_KYRGYZ 0x40
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_LAO 0x54
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_LATVIAN 0x26
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_LITHUANIAN 0x27
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_ಅಧೋ_SORBIAN 0x2e
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_LUXEMBOURGISH 0x6e
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_MACEDONIAN 0x2f
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_MALAY 0x3e
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_MALAYALAM 0x4c
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_MALTESE 0x3a
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_MANIPURI 0x58
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_MAORI 0x81
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_MAPUDUNGUN 0x7a
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_MARATHI 0x4e
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_MOHAWK 0x7c
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_MONGOLIAN 0x50
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_NEPALI 0x61
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_NORWEGIAN 0x14
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_OCCITAN 0x82
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_ORIYA 0x48
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_PASHTO 0x63
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_PERSIAN 0x29
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_POLISH 0x15
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_PORTUGUESE 0x16
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_PUNJABI 0x46
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_QUECHUA 0x6b
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_ROMANIAN 0x18
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_RUSSIAN 0x19
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_SAMI 0x3b
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_ROMANSH 0x17
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_SANSKRIT 0x4f
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_SERBIAN 0x1a
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_SERBIAN_NEUTRAL 0x7c1a
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_SINDHI 0x59
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_SINHALESE 0x5b
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_SLOVAK 0x1b
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_SLOVENIAN 0x24
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_SOTHO 0x6c
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_SPANISH 0x0a
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_SWAHILI 0x41
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_SWEDISH 0x1d
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_SYRIAC 0x5a
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_TAJIK 0x28
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_TAMAZIGHT 0x5f
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_TAMIL 0x49
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_TATAR 0x44
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_TELUGU 0x4a
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_THAI 0x1e
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_TIBETAN 0x51
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_TIGRIGNA 0x73
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_TSWANA 0x32
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_TURKISH 0x1f
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_TURKMEN 0x42
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_UIGHUR 0x80
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_UKRAINIAN 0x22
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_ಊರ್ಧ್ವ_SORBIAN 0x2e
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_URDU 0x20
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_UZBEK 0x43
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_VIETNAMESE 0x2a
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_WELSH 0x52
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_WOLOF 0x88
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_XHOSA 0x34
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_YAKUT 0x85
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_YI 0x78
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_YORUBA 0x6a
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_ZULU 0x35

#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_NEUTRAL 0x0
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_DEFAULT 0x1
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_SYS_DEFAULT 0x2
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_CUSTOM_DEFAULT 0x3
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_CUSTOM_UNSPECIFIED 0x4
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_UI_CUSTOM_DEFAULT 0x5

#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_ARABIC_SAUDI_ARABIA 0x01
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_ARABIC_IRAQ 0x02
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_ARABIC_EGYPT 0x03
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_ARABIC_LIBYA 0x04
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_ARABIC_ALGERIA 0x05
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_ARABIC_MOROCCO 0x06
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_ARABIC_TUNISIA 0x07
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_ARABIC_OMAN 0x08
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_ARABIC_YEMEN 0x09
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_ARABIC_SYRIA 0x0a
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_ARABIC_JORDAN 0x0b
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_ARABIC_LEBANON 0x0c
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_ARABIC_KUWAIT 0x0d
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_ARABIC_UAE 0x0e
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_ARABIC_BAHRAIN 0x0f
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_ARABIC_QATAR 0x10
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_AZERI_LATIN 0x01
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_AZERI_CYRILLIC 0x02
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_CHINESE_TRADITIONAL 0x01
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_CHINESE_SIMPLIFIED 0x02
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_CHINESE_HONGKONG 0x03
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_CHINESE_SINGAPORE 0x04
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_CHINESE_MACAU 0x05
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_DUTCH 0x01
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_DUTCH_BELGIAN 0x02
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_ENGLISH_US 0x01
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_ENGLISH_UK 0x02
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_ENGLISH_AUS 0x03
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_ENGLISH_CAN 0x04
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_ENGLISH_NZ 0x05
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_ENGLISH_EIRE 0x06
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_ENGLISH_SOUTH_AFRICA 0x07
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_ENGLISH_JAMAICA 0x08
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_ENGLISH_CARIBBEAN 0x09
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_ENGLISH_BELIZE 0x0a
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_ENGLISH_TRINIDAD 0x0b
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_ENGLISH_ZIMBABWE 0x0c
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_ENGLISH_PHILIPPINES 0x0d
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_FRENCH 0x01
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_FRENCH_BELGIAN 0x02
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_FRENCH_CANADIAN 0x03
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_FRENCH_SWISS 0x04
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_FRENCH_LUXEMBOURG 0x05
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_FRENCH_MONACO 0x06
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_GERMAN 0x01
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_GERMAN_SWISS 0x02
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_GERMAN_AUSTRIAN 0x03
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_GERMAN_LUXEMBOURG 0x04
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_GERMAN_LIECHTENSTEIN 0x05
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_ITALIAN 0x01
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_ITALIAN_SWISS 0x02
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_KASHMIRI_SASIA 0x02
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_KASHMIRI_INDIA 0x02
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_KOREAN 0x01
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_LITHUANIAN 0x01
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_MALAY_MALAYSIA 0x01
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_MALAY_BRUNEI_DARUSSALAM 0x02
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_NEPALI_INDIA 0x02
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_NORWEGIAN_BOKMAL 0x01
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_NORWEGIAN_NYNORSK 0x02
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_PORTUGUESE 0x02
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_PORTUGUESE_BRAZILIAN 0x01
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_SERBIAN_LATIN 0x02
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_SERBIAN_CYRILLIC 0x03
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_SPANISH 0x01
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_SPANISH_MEXICAN 0x02
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_SPANISH_MODERN 0x03
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_SPANISH_GUATEMALA 0x04
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_SPANISH_COSTA_RICA 0x05
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_SPANISH_PANAMA 0x06
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_SPANISH_DOMINICAN_REPUBLIC 0x07
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_SPANISH_VENEZUELA 0x08
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_SPANISH_COLOMBIA 0x09
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_SPANISH_PERU 0x0a
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_SPANISH_ARGENTINA 0x0b
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_SPANISH_ECUADOR 0x0c
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_SPANISH_CHILE 0x0d
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_SPANISH_URUGUAY 0x0e
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_SPANISH_PARAGUAY 0x0f
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_SPANISH_BOLIVIA 0x10
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_SPANISH_EL_SALVADOR 0x11
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_SPANISH_HONDURAS 0x12
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_SPANISH_NICARAGUA 0x13
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_SPANISH_PUERTO_RICO 0x14
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_SWEDISH 0x01
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_SWEDISH_FINLAND 0x02
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_URDU_PAKISTAN 0x01
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_URDU_INDIA 0x02
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_UZBEK_LATIN 0x01
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANG_UZBEK_CYRILLIC 0x02

#ವ್ಯಾಖ್ಯಾನಿಸು ವಿಂಗಡಿಸು_DEFAULT 0x0
#ವ್ಯಾಖ್ಯಾನಿಸು ವಿಂಗಡಿಸು_INVARIANT_MATH 0x1

#ವ್ಯಾಖ್ಯಾನಿಸು ವಿಂಗಡಿಸು_JAPANESE_XJIS 0x0
#ವ್ಯಾಖ್ಯಾನಿಸು ವಿಂಗಡಿಸು_JAPANESE_UNICODE 0x1
#ವ್ಯಾಖ್ಯಾನಿಸು ವಿಂಗಡಿಸು_JAPANESE_RADICALSTROKE 0x4

#ವ್ಯಾಖ್ಯಾನಿಸು ವಿಂಗಡಿಸು_CHINESE_BIG5 0x0
#ವ್ಯಾಖ್ಯಾನಿಸು ವಿಂಗಡಿಸು_CHINESE_PRCP 0x0
#ವ್ಯಾಖ್ಯಾನಿಸು ವಿಂಗಡಿಸು_CHINESE_UNICODE 0x1
#ವ್ಯಾಖ್ಯಾನಿಸು ವಿಂಗಡಿಸು_CHINESE_PRC 0x2
#ವ್ಯಾಖ್ಯಾನಿಸು ವಿಂಗಡಿಸು_CHINESE_BOPOMOFO 0x3

#ವ್ಯಾಖ್ಯಾನಿಸು ವಿಂಗಡಿಸು_KOREAN_KSC 0x0
#ವ್ಯಾಖ್ಯಾನಿಸು ವಿಂಗಡಿಸು_KOREAN_UNICODE 0x1

#ವ್ಯಾಖ್ಯಾನಿಸು ವಿಂಗಡಿಸು_GERMAN_PHONE_BOOK 0x1

#ವ್ಯಾಖ್ಯಾನಿಸು ವಿಂಗಡಿಸು_HUNGARIAN_DEFAULT 0x0
#ವ್ಯಾಖ್ಯಾನಿಸು ವಿಂಗಡಿಸು_HUNGARIAN_TECHNICAL 0x1

#ವ್ಯಾಖ್ಯಾನಿಸು ವಿಂಗಡಿಸು_GEORGIAN_TRADITIONAL 0x0
#ವ್ಯಾಖ್ಯಾನಿಸು ವಿಂಗಡಿಸು_GEORGIAN_MODERN 0x1

#ವ್ಯಾಖ್ಯಾನಿಸು MAKELANGID(p,s) ((((ಶಬ್ದ_3)(s)) << 10) | (ಶಬ್ದ_3)(p))
#ವ್ಯಾಖ್ಯಾನಿಸು PRIMARYLANGID(lgid) ((ಶಬ್ದ_3)(lgid) & 0x3ff)
#ವ್ಯಾಖ್ಯಾನಿಸು SUBLANGID(lgid) ((ಶಬ್ದ_3)(lgid) >> 10)

#ವ್ಯಾಖ್ಯಾನಿಸು NLS_VALID_LOCALE_ಮುಖವಾಡ 0x000fffff

#ವ್ಯಾಖ್ಯಾನಿಸು MAKELCID(lgid,srtid) ((DWORD)((((DWORD)((ಶಬ್ದ_3)(srtid))) << 16) | ((DWORD)((ಶಬ್ದ_3)(lgid)))))
#ವ್ಯಾಖ್ಯಾನಿಸು MAKESORTLCID(lgid,srtid,ver) ((DWORD)((MAKELCID(lgid,srtid)) | (((DWORD)((ಶಬ್ದ_3)(ver))) << 20)))
#ವ್ಯಾಖ್ಯಾನಿಸು LANGIDFROMLCID(lcid) ((ಶಬ್ದ_3)(lcid))
#ವ್ಯಾಖ್ಯಾನಿಸು SORTIDFROMLCID(lcid) ((ಶಬ್ದ_3)((((DWORD)(lcid)) >> 16) & 0xf))
#ವ್ಯಾಖ್ಯಾನಿಸು SORTVERSIONFROMLCID(lcid) ((ಶಬ್ದ_3)((((DWORD)(lcid)) >> 20) & 0xf))

#ವ್ಯಾಖ್ಯಾನಿಸು LOCALE_NAME_MAX_ಉದ್ದಳತೆ 85
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_SYSTEM_DEFAULT (MAKELANGID(LANG_NEUTRAL,SUBLANG_SYS_DEFAULT))
#ವ್ಯಾಖ್ಯಾನಿಸು LANG_USER_DEFAULT (MAKELANGID(LANG_NEUTRAL,SUBLANG_DEFAULT))

#ವ್ಯಾಖ್ಯಾನಿಸು LOCALE_SYSTEM_DEFAULT (MAKELCID(LANG_SYSTEM_DEFAULT,ವಿಂಗಡಿಸು_DEFAULT))
#ವ್ಯಾಖ್ಯಾನಿಸು LOCALE_USER_DEFAULT (MAKELCID(LANG_USER_DEFAULT,ವಿಂಗಡಿಸು_DEFAULT))

#ವ್ಯಾಖ್ಯಾನಿಸು LOCALE_NEUTRAL (MAKELCID(MAKELANGID(LANG_NEUTRAL,SUBLANG_NEUTRAL),ವಿಂಗಡಿಸು_DEFAULT))

#ವ್ಯಾಖ್ಯಾನಿಸು LOCALE_CUSTOM_DEFAULT (MAKELCID(MAKELANGID(LANG_NEUTRAL, SUBLANG_CUSTOM_DEFAULT), ವಿಂಗಡಿಸು_DEFAULT))
#ವ್ಯಾಖ್ಯಾನಿಸು LOCALE_CUSTOM_UNSPECIFIED (MAKELCID(MAKELANGID(LANG_NEUTRAL, SUBLANG_CUSTOM_UNSPECIFIED), ವಿಂಗಡಿಸು_DEFAULT))
#ವ್ಯಾಖ್ಯಾನಿಸು LOCALE_CUSTOM_UI_DEFAULT (MAKELCID(MAKELANGID(LANG_NEUTRAL, SUBLANG_UI_CUSTOM_DEFAULT), ವಿಂಗಡಿಸು_DEFAULT))

#ವ್ಯಾಖ್ಯಾನಿಸು LOCALE_INVARIANT (MAKELCID(MAKELANGID(LANG_INVARIANT,SUBLANG_NEUTRAL),ವಿಂಗಡಿಸು_DEFAULT))

#ವ್ಯಾಖ್ಯಾನಿಸು UNREFERENCED_PARAMETER(P) (P)
#ವ್ಯಾಖ್ಯಾನಿಸು DBG_UNREFERENCED_PARAMETER(P) (P)
#ವ್ಯಾಖ್ಯಾನಿಸು DBG_UNREFERENCED_LOCAL_VARIABLE(V) (V)

#ವ್ಯಾಖ್ಯಾನಿಸು DEFAULT_UNREACHABLE

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ WIN32_NO_ಸ್ಥಿತಿ
#ವ್ಯಾಖ್ಯಾನಿಸು ಸ್ಥಿತಿ_WAIT_0 ((DWORD)0x00000000L)
#ವ್ಯಾಖ್ಯಾನಿಸು ಸ್ಥಿತಿ_ABANDONED_WAIT_0 ((DWORD)0x00000080L)
#ವ್ಯಾಖ್ಯಾನಿಸು ಸ್ಥಿತಿ_USER_APC ((DWORD)0x000000C0L)
#ವ್ಯಾಖ್ಯಾನಿಸು ಸ್ಥಿತಿ_TIMEOUT ((DWORD)0x00000102L)
#ವ್ಯಾಖ್ಯಾನಿಸು ಸ್ಥಿತಿ_PENDING ((DWORD)0x00000103L)
#ವ್ಯಾಖ್ಯಾನಿಸು DBG_EXCEPTION_HANDLED ((DWORD)0x00010001L)
#ವ್ಯಾಖ್ಯಾನಿಸು DBG_CONTINUE ((DWORD)0x00010002L)
#ವ್ಯಾಖ್ಯಾನಿಸು ಸ್ಥಿತಿ_SEGMENT_NOTIFICATION ((DWORD)0x40000005L)
#ವ್ಯಾಖ್ಯಾನಿಸು DBG_TERMINATE_THREAD ((DWORD)0x40010003L)
#ವ್ಯಾಖ್ಯಾನಿಸು DBG_TERMINATE_PROCESS ((DWORD)0x40010004L)
#ವ್ಯಾಖ್ಯಾನಿಸು DBG_CONTROL_C ((DWORD)0x40010005L)
#ವ್ಯಾಖ್ಯಾನಿಸು DBG_CONTROL_BREAK ((DWORD)0x40010008L)
#ವ್ಯಾಖ್ಯಾನಿಸು DBG_COMMAND_EXCEPTION ((DWORD)0x40010009L)
#ವ್ಯಾಖ್ಯಾನಿಸು ಸ್ಥಿತಿ_GUARD_ಪುಟ_VIOLATION ((DWORD)0x80000001L)
#ವ್ಯಾಖ್ಯಾನಿಸು ಸ್ಥಿತಿ_DATATYPE_MISALIGNMENT ((DWORD)0x80000002L)
#ವ್ಯಾಖ್ಯಾನಿಸು ಸ್ಥಿತಿ_BREAKPOINT ((DWORD)0x80000003L)
#ವ್ಯಾಖ್ಯಾನಿಸು ಸ್ಥಿತಿ_SINGLE_ಹೆಜ್ಜೆ ((DWORD)0x80000004L)
#ವ್ಯಾಖ್ಯಾನಿಸು DBG_EXCEPTION_NOT_HANDLED ((DWORD)0x80010001L)
#ವ್ಯಾಖ್ಯಾನಿಸು ಸ್ಥಿತಿ_ACCESS_VIOLATION ((DWORD)0xC0000005L)
#ವ್ಯಾಖ್ಯಾನಿಸು ಸ್ಥಿತಿ_ಒಳ_ಪುಟ_ERROR ((DWORD)0xC0000006L)
#ವ್ಯಾಖ್ಯಾನಿಸು ಸ್ಥಿತಿ_INVALID_HANDLE ((DWORD)0xC0000008L)
#ವ್ಯಾಖ್ಯಾನಿಸು ಸ್ಥಿತಿ_NO_ಸ್ಮರಣೆ ((DWORD)0xC0000017L)
#ವ್ಯಾಖ್ಯಾನಿಸು ಸ್ಥಿತಿ_ILLEGAL_INSTRUCTION ((DWORD)0xC000001DL)
#ವ್ಯಾಖ್ಯಾನಿಸು ಸ್ಥಿತಿ_NONCONTINUABLE_EXCEPTION ((DWORD)0xC0000025L)
#ವ್ಯಾಖ್ಯಾನಿಸು ಸ್ಥಿತಿ_INVALID_DISPOSITION ((DWORD)0xC0000026L)
#ವ್ಯಾಖ್ಯಾನಿಸು ಸ್ಥಿತಿ_ARRAY_BOUNDS_EXCEEDED ((DWORD)0xC000008CL)
#ವ್ಯಾಖ್ಯಾನಿಸು ಸ್ಥಿತಿ_FLOAT_DENORMAL_ಕಾರ್ಯಾಂಶ ((DWORD)0xC000008DL)
#ವ್ಯಾಖ್ಯಾನಿಸು ಸ್ಥಿತಿ_FLOAT_DIVIDE_BY_ZERO ((DWORD)0xC000008EL)
#ವ್ಯಾಖ್ಯಾನಿಸು ಸ್ಥಿತಿ_FLOAT_INEXACT_ಫಲಿತಾಂಶ ((DWORD)0xC000008FL)
#ವ್ಯಾಖ್ಯಾನಿಸು ಸ್ಥಿತಿ_FLOAT_INVALID_OPERATION ((DWORD)0xC0000090L)
#ವ್ಯಾಖ್ಯಾನಿಸು ಸ್ಥಿತಿ_FLOAT_ಅತಿಪ್ರವಾಹ ((DWORD)0xC0000091L)
#ವ್ಯಾಖ್ಯಾನಿಸು ಸ್ಥಿತಿ_FLOAT_ರಾಶಿ_CHECK ((DWORD)0xC0000092L)
#ವ್ಯಾಖ್ಯಾನಿಸು ಸ್ಥಿತಿ_FLOAT_UNDERFLOW ((DWORD)0xC0000093L)
#ವ್ಯಾಖ್ಯಾನಿಸು ಸ್ಥಿತಿ_INTEGER_DIVIDE_BY_ZERO ((DWORD)0xC0000094L)
#ವ್ಯಾಖ್ಯಾನಿಸು ಸ್ಥಿತಿ_INTEGER_ಅತಿಪ್ರವಾಹ ((DWORD)0xC0000095L)
#ವ್ಯಾಖ್ಯಾನಿಸು ಸ್ಥಿತಿ_PRIVILEGED_INSTRUCTION ((DWORD)0xC0000096L)
#ವ್ಯಾಖ್ಯಾನಿಸು ಸ್ಥಿತಿ_ರಾಶಿ_ಅತಿಪ್ರವಾಹ ((DWORD)0xC00000FDL)
#ವ್ಯಾಖ್ಯಾನಿಸು ಸ್ಥಿತಿ_CONTROL_C_EXIT ((DWORD)0xC000013AL)
#ವ್ಯಾಖ್ಯಾನಿಸು ಸ್ಥಿತಿ_FLOAT_ಅಪವರ್ತ್ಯ_ದೋಷಗಳು ((DWORD)0xC00002B4L)
#ವ್ಯಾಖ್ಯಾನಿಸು ಸ್ಥಿತಿ_FLOAT_ಅಪವರ್ತ್ಯ_TRAPS ((DWORD)0xC00002B5L)
#ವ್ಯಾಖ್ಯಾನಿಸು ಸ್ಥಿತಿ_REG_NAT_CONSUMPTION ((DWORD)0xC00002C9L)
#ವ್ಯಾಖ್ಯಾನಿಸು ಸ್ಥಿತಿ_SXS_EARLY_DEACTIVATION ((DWORD)0xC015000FL)
#ವ್ಯಾಖ್ಯಾನಿಸು ಸ್ಥಿತಿ_SXS_INVALID_DEACTIVATION ((DWORD)0xC0150010L)
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು ಗರಿಷ್ಠ_WAIT_OBJECTS 64
#ವ್ಯಾಖ್ಯಾನಿಸು ಗರಿಷ್ಠ_SUSPEND_ಎಣಿಕೆ MAXCHAR

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ULONG_PTR KSPIN_ಬೀಗ;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ KSPIN_ಬೀಗ *PKSPIN_ಬೀಗ;

#ಆದರೆ defined(__x86_64) && !defined(RC_INVOKED)

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
  ಬಾಹ್ಯ "C" {
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು ಬಿಟ್_Test _bittest
#ವ್ಯಾಖ್ಯಾನಿಸು ಬಿಟ್_Test_And_Complement _bittestandcomplement
#ವ್ಯಾಖ್ಯಾನಿಸು ಬಿಟ್_Test_And_ಗಣ _bittestandset
#ವ್ಯಾಖ್ಯಾನಿಸು ಬಿಟ್_Test_And_Reset _bittestandreset
#ವ್ಯಾಖ್ಯಾನಿಸು Interlocked_ಬಿಟ್_Test_And_ಗಣ _interlockedbittestandset
#ವ್ಯಾಖ್ಯಾನಿಸು Interlocked_ಬಿಟ್_Test_And_Reset _interlockedbittestandreset
#ವ್ಯಾಖ್ಯಾನಿಸು ಬಿಟ್_Test64 _bittest64
#ವ್ಯಾಖ್ಯಾನಿಸು ಬಿಟ್_Test_And_Complement64 _bittestandcomplement64
#ವ್ಯಾಖ್ಯಾನಿಸು ಬಿಟ್_Test_And_Set64 _bittestandset64
#ವ್ಯಾಖ್ಯಾನಿಸು ಬಿಟ್_Test_And_Reset64 _bittestandreset64
#ವ್ಯಾಖ್ಯಾನಿಸು Interlocked_ಬಿಟ್_Test_And_Set64 _interlockedbittestandset64
#ವ್ಯಾಖ್ಯಾನಿಸು Interlocked_ಬಿಟ್_Test_And_Reset64 _interlockedbittestandreset64

    __CRT_INLINE BOOLEAN _bittest(LONG ಸ್ಥಿರಾಂಕ *ತಳ_2,LONG ಸ್ಥಾನಾಂತರ_3) {
      ಪೂರ್ಣಾಂಕ old = 0;
      __asm__ __volatile__("btl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(ಅಸ್ಥಿರ ದೀರ್ಘ *) ತಳ_2))
	:"Ir" (ಸ್ಥಾನಾಂತರ_3));
      ಹಿಂತಿರುಗಿ (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandcomplement(LONG *ತಳ_2,LONG ಸ್ಥಾನಾಂತರ_3) {
      ಪೂರ್ಣಾಂಕ old = 0;
      __asm__ __volatile__("btcl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(ಅಸ್ಥಿರ ದೀರ್ಘ *) ತಳ_2))
	:"Ir" (ಸ್ಥಾನಾಂತರ_3));
      ಹಿಂತಿರುಗಿ (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN Interlocked_ಬಿಟ್_Test_And_Complement(LONG *ತಳ_2,LONG ಬಿಟ್_2) {
      ಪೂರ್ಣಾಂಕ old = 0;
      __asm__ __volatile__("lock ; btcl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(ಅಸ್ಥಿರ ದೀರ್ಘ *) ತಳ_2))
	:"Ir" (ಬಿಟ್_2));
      ಹಿಂತಿರುಗಿ (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandset(LONG *ತಳ_2,LONG ಸ್ಥಾನಾಂತರ_3) {
      ಪೂರ್ಣಾಂಕ old = 0;
      __asm__ __volatile__("btsl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(ಅಸ್ಥಿರ ದೀರ್ಘ *) ತಳ_2))
	:"Ir" (ಸ್ಥಾನಾಂತರ_3));
      ಹಿಂತಿರುಗಿ (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandreset(LONG *ತಳ_2,LONG ಸ್ಥಾನಾಂತರ_3) {
      ಪೂರ್ಣಾಂಕ old = 0;
      __asm__ __volatile__("btrl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(ಅಸ್ಥಿರ ದೀರ್ಘ *) ತಳ_2))
	:"Ir" (ಸ್ಥಾನಾಂತರ_3));
      ಹಿಂತಿರುಗಿ (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _interlockedbittestandset(LONG *ತಳ_2,LONG ಸ್ಥಾನಾಂತರ_3) {
      ಪೂರ್ಣಾಂಕ old = 0;
      __asm__ __volatile__("lock ; btsl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(ಅಸ್ಥಿರ ದೀರ್ಘ *) ತಳ_2))
	:"Ir" (ಸ್ಥಾನಾಂತರ_3));
      ಹಿಂತಿರುಗಿ (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _interlockedbittestandreset(LONG *ತಳ_2,LONG ಸ್ಥಾನಾಂತರ_3) {
      ಪೂರ್ಣಾಂಕ old = 0;
      __asm__ __volatile__("lock ; btrl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(ಅಸ್ಥಿರ ದೀರ್ಘ *) ತಳ_2))
	:"Ir" (ಸ್ಥಾನಾಂತರ_3));
      ಹಿಂತಿರುಗಿ (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittest64(LONG64 ಸ್ಥಿರಾಂಕ *ತಳ_2,LONG64 ಸ್ಥಾನಾಂತರ_3) {
      ಪೂರ್ಣಾಂಕ old = 0;
      __asm__ __volatile__("btq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(ಅಸ್ಥಿರ ದೀರ್ಘ ದೀರ್ಘ *) ತಳ_2))
	:"Ir" (ಸ್ಥಾನಾಂತರ_3));
      ಹಿಂತಿರುಗಿ (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandcomplement64(LONG64 *ತಳ_2,LONG64 ಸ್ಥಾನಾಂತರ_3) {
      ಪೂರ್ಣಾಂಕ old = 0;
      __asm__ __volatile__("btcq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(ಅಸ್ಥಿರ ದೀರ್ಘ ದೀರ್ಘ *) ತಳ_2))
	:"Ir" (ಸ್ಥಾನಾಂತರ_3));
      ಹಿಂತಿರುಗಿ (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandset64(LONG64 *ತಳ_2,LONG64 ಸ್ಥಾನಾಂತರ_3) {
      ಪೂರ್ಣಾಂಕ old = 0;
      __asm__ __volatile__("btsq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(ಅಸ್ಥಿರ ದೀರ್ಘ ದೀರ್ಘ *) ತಳ_2))
	:"Ir" (ಸ್ಥಾನಾಂತರ_3));
      ಹಿಂತಿರುಗಿ (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandreset64(LONG64 *ತಳ_2,LONG64 ಸ್ಥಾನಾಂತರ_3) {
      ಪೂರ್ಣಾಂಕ old = 0;
      __asm__ __volatile__("btrq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(ಅಸ್ಥಿರ ದೀರ್ಘ ದೀರ್ಘ *) ತಳ_2))
	:"Ir" (ಸ್ಥಾನಾಂತರ_3));
      ಹಿಂತಿರುಗಿ (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _interlockedbittestandset64(LONG64 *ತಳ_2,LONG64 ಸ್ಥಾನಾಂತರ_3) {
      ಪೂರ್ಣಾಂಕ old = 0;
      __asm__ __volatile__("lock ; btsq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(ಅಸ್ಥಿರ ದೀರ್ಘ ದೀರ್ಘ *) ತಳ_2))
	:"Ir" (ಸ್ಥಾನಾಂತರ_3));
      ಹಿಂತಿರುಗಿ (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _interlockedbittestandreset64(LONG64 *ತಳ_2,LONG64 ಸ್ಥಾನಾಂತರ_3) {
      ಪೂರ್ಣಾಂಕ old = 0;
      __asm__ __volatile__("lock ; btrq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(ಅಸ್ಥಿರ ದೀರ್ಘ ದೀರ್ಘ *) ತಳ_2))
	:"Ir" (ಸ್ಥಾನಾಂತರ_3));
      ಹಿಂತಿರುಗಿ (BOOLEAN) (old!=0);
    }
#ವ್ಯಾಖ್ಯಾನಿಸು ಬಿಟ್_ಪರಿಶೀಲನೆ_Forward ಬಿಟ್_ಪರಿಶೀಲನೆ_Forward_2
#ವ್ಯಾಖ್ಯಾನಿಸು ಬಿಟ್_ಪರಿಶೀಲನೆ_ಹಿಮ್ಮುಖ ಬಿಟ್_ಪರಿಶೀಲನೆ_ಹಿಮ್ಮುಖ_2
#ವ್ಯಾಖ್ಯಾನಿಸು ಬಿಟ್_ಪರಿಶೀಲನೆ_Forward64 ಬಿಟ್_ಪರಿಶೀಲನೆ_Forward64_2
#ವ್ಯಾಖ್ಯಾನಿಸು ಬಿಟ್_ಪರಿಶೀಲನೆ_Reverse64 ಬಿಟ್_ಪರಿಶೀಲನೆ_Reverse64_2

    __CRT_INLINE BOOLEAN ಬಿಟ್_ಪರಿಶೀಲನೆ_Forward_2(DWORD *ಸೂಚ್ಯಂಕ_3,DWORD ಮುಖವಾಡ_3) {
      __asm__ __volatile__("bsfl %1,%0" : "=r" (ಮುಖವಾಡ_3),"=m" ((*(ಅಸ್ಥಿರ ದೀರ್ಘ *)ಸೂಚ್ಯಂಕ_3)));
      ಹಿಂತಿರುಗಿ ಮುಖವಾಡ_3!=0;
    }
    __CRT_INLINE BOOLEAN ಬಿಟ್_ಪರಿಶೀಲನೆ_ಹಿಮ್ಮುಖ_2(DWORD *ಸೂಚ್ಯಂಕ_3,DWORD ಮುಖವಾಡ_3) {
      __asm__ __volatile__("bsrl %1,%0" : "=r" (ಮುಖವಾಡ_3),"=m" ((*(ಅಸ್ಥಿರ ದೀರ್ಘ *)ಸೂಚ್ಯಂಕ_3)));
      ಹಿಂತಿರುಗಿ ಮುಖವಾಡ_3!=0;
    }
    __CRT_INLINE BOOLEAN ಬಿಟ್_ಪರಿಶೀಲನೆ_Forward64_2(DWORD *ಸೂಚ್ಯಂಕ_3,DWORD64 ಮುಖವಾಡ_3) {
      __asm__ __volatile__("bsfq %1,%0" : "=r" (ಮುಖವಾಡ_3),"=m" ((*(ಅಸ್ಥಿರ ದೀರ್ಘ ದೀರ್ಘ *)ಸೂಚ್ಯಂಕ_3)));
      ಹಿಂತಿರುಗಿ ಮುಖವಾಡ_3!=0;
    }
    __CRT_INLINE BOOLEAN ಬಿಟ್_ಪರಿಶೀಲನೆ_Reverse64_2(DWORD *ಸೂಚ್ಯಂಕ_3,DWORD64 ಮುಖವಾಡ_3) {
      __asm__ __volatile__("bsrq %1,%0" : "=r" (ಮುಖವಾಡ_3),"=m" ((*(ಅಸ್ಥಿರ ದೀರ್ಘ ದೀರ್ಘ *)ಸೂಚ್ಯಂಕ_3)));
      ಹಿಂತಿರುಗಿ ಮುಖವಾಡ_3!=0;
    }

#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedIncrement16 _InterlockedIncrement16
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedDecrement16 _InterlockedDecrement16
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedCompareExchange16 _InterlockedCompareExchange16

#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedAnd _InterlockedAnd
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedOr _InterlockedOr
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedXor _InterlockedXor
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedIncrement _InterlockedIncrement
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedIncrementAcquire InterlockedIncrement
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedIncrementRelease InterlockedIncrement
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedDecrement _InterlockedDecrement
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedDecrementAcquire InterlockedDecrement
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedDecrementRelease InterlockedDecrement
#ವ್ಯಾಖ್ಯಾನಿಸು Interlocked_ಕೂಡಿಸು Interlocked_ಕೂಡಿಸು_2
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedExchange _InterlockedExchange
#ವ್ಯಾಖ್ಯಾನಿಸು Interlocked_Exchange_ಕೂಡಿಸು Interlocked_Exchange_ಕೂಡಿಸು_2
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedCompareExchange _InterlockedCompareExchange
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedCompareExchangeAcquire InterlockedCompareExchange
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedCompareExchangeRelease InterlockedCompareExchange

#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedAnd64 _InterlockedAnd64
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedAndAffinity InterlockedAnd64
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedOr64 _InterlockedOr64
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedOrAffinity InterlockedOr64
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedXor64 _InterlockedXor64
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedIncrement64 _InterlockedIncrement64
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedDecrement64 _InterlockedDecrement64
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedAdd64 _InterlockedAdd64
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedExchange64 _InterlockedExchange64
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedExchangeAcquire64 InterlockedExchange64
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedExchangeAdd64 _InterlockedExchangeAdd64
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedCompareExchange64 _InterlockedCompareExchange64
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedCompareExchangeAcquire64 InterlockedCompareExchange64
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedCompareExchangeRelease64 InterlockedCompareExchange64

#ವ್ಯಾಖ್ಯಾನಿಸು Interlocked_Exchange_ಸೂಚಕ Interlocked_Exchange_ಸೂಚಕ_2
#ವ್ಯಾಖ್ಯಾನಿಸು Interlocked_Compare_Exchange_ಸೂಚಕ Interlocked_Compare_Exchange_ಸೂಚಕ_2
#ವ್ಯಾಖ್ಯಾನಿಸು Interlocked_Compare_Exchange_ಸೂಚಕ_Acquire Interlocked_Compare_Exchange_ಸೂಚಕ_2
#ವ್ಯಾಖ್ಯಾನಿಸು Interlocked_Compare_Exchange_ಸೂಚಕ_Release Interlocked_Compare_Exchange_ಸೂಚಕ_2

#ವ್ಯಾಖ್ಯಾನಿಸು Interlocked_Exchange_ಕೂಡಿಸು_ಗಾತ್ರ_T(a,b) InterlockedExchangeAdd64((LONG64 *)a,b)
#ವ್ಯಾಖ್ಯಾನಿಸು Interlocked_Increment_ಗಾತ್ರ_T(a) InterlockedIncrement64((LONG64 *)a)
#ವ್ಯಾಖ್ಯಾನಿಸು Interlocked_Decrement_ಗಾತ್ರ_T(a) InterlockedDecrement64((LONG64 *)a)

    __CRT_INLINE SHORT InterlockedIncrement16(SHORT ಅಸ್ಥಿರ *Addend) {
      ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ c;
      ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ s;
      __asm__ __volatile__(
	"lock ; addw $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      ಹಿಂತಿರುಗಿ (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE SHORT InterlockedDecrement16(SHORT ಅಸ್ಥಿರ *Addend) {
      ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ c;
      ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ s;
      __asm__ __volatile__(
	"lock ; subw $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      ಹಿಂತಿರುಗಿ (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE SHORT InterlockedCompareExchange16(SHORT ಅಸ್ಥಿರ *Destination,SHORT ExChange,SHORT Comperand) {
      SHORT prev;
      __asm__ __volatile__("lock ; cmpxchgw %w1,%2"
	:"=a"(prev)
	:"q"(ExChange), "m"(*Destination), "0"(Comperand)
	: "memory");
      ಹಿಂತಿರುಗಿ prev;
    }
    __CRT_INLINE LONG InterlockedAnd(LONG ಅಸ್ಥಿರ *Destination,LONG ಮೌಲ್ಯ_3) {
      __asm__ __volatile__("lock ; andl %0,%1"
	: :"r"(ಮೌಲ್ಯ_3),"m"(*Destination)
	: "memory");
      ಹಿಂತಿರುಗಿ *Destination;
    }
    __CRT_INLINE LONG InterlockedOr(LONG ಅಸ್ಥಿರ *Destination,LONG ಮೌಲ್ಯ_3) {
      __asm__ __volatile__("lock ; orl %0,%1"
	: : "r"(ಮೌಲ್ಯ_3),"m"(*Destination) : "memory");
      ಹಿಂತಿರುಗಿ *Destination;
    }
    __CRT_INLINE LONG InterlockedXor(LONG ಅಸ್ಥಿರ *Destination,LONG ಮೌಲ್ಯ_3) {
      __asm__ __volatile__("lock ; xorl %0,%1"
	: : "r"(ಮೌಲ್ಯ_3),"m"(*Destination) : "memory");
      ಹಿಂತಿರುಗಿ *Destination;
    }
    //		$$$$
    __CRT_INLINE LONG64 InterlockedAnd64(LONG64 ಅಸ್ಥಿರ *Destination,LONG64 ಮೌಲ್ಯ_3) {
      __asm__ __volatile__("lock ; andq %0,%1"
	: : "r"(ಮೌಲ್ಯ_3),"m"(*Destination) : "memory");
      ಹಿಂತಿರುಗಿ *Destination;
    }
    __CRT_INLINE LONG64 InterlockedOr64(LONG64 ಅಸ್ಥಿರ *Destination,LONG64 ಮೌಲ್ಯ_3) {
      __asm__ __volatile__("lock ; orq %0,%1"
	: : "r"(ಮೌಲ್ಯ_3),"m"(*Destination) : "memory");
      ಹಿಂತಿರುಗಿ *Destination;
    }
    __CRT_INLINE LONG64 InterlockedXor64(LONG64 ಅಸ್ಥಿರ *Destination,LONG64 ಮೌಲ್ಯ_3) {
      __asm__ __volatile__("lock ; xorq %0,%1"
	: : "r"(ಮೌಲ್ಯ_3),"m"(*Destination) : "memory");
      ಹಿಂತಿರುಗಿ *Destination;
    }
    __CRT_INLINE LONG InterlockedIncrement(LONG ಅಸ್ಥಿರ *Addend) {
      ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ c;
      ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ s;
      __asm__ __volatile__(
	"lock ; addl $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      ಹಿಂತಿರುಗಿ (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE LONG InterlockedDecrement(LONG ಅಸ್ಥಿರ *Addend) {
      ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ c;
      ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ s;
      __asm__ __volatile__(
	"lock ; subl $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      ಹಿಂತಿರುಗಿ (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE LONG InterlockedExchange(LONG ಅಸ್ಥಿರ *ಗುರಿ_2,LONG ಮೌಲ್ಯ_3) {
      __asm__ __volatile("lock ; xchgl %0,%1"
	: "=r"(ಮೌಲ್ಯ_3)
	: "m"(*ಗುರಿ_2),"0"(ಮೌಲ್ಯ_3)
	: "memory");
      ಹಿಂತಿರುಗಿ ಮೌಲ್ಯ_3;
    }
    LONG Interlocked_Exchange_ಕೂಡಿಸು(LONG ಅಸ್ಥಿರ *Addend,LONG ಮೌಲ್ಯ_3);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _X86AMD64_
    __CRT_INLINE LONG Interlocked_ಕೂಡಿಸು(LONG ಅಸ್ಥಿರ *Addend,LONG ಮೌಲ್ಯ_3) { ಹಿಂತಿರುಗಿ Interlocked_Exchange_ಕೂಡಿಸು(Addend,ಮೌಲ್ಯ_3) + ಮೌಲ್ಯ_3; }
#ಆದರೆ_ಅಂತ್ಯ
    __CRT_INLINE LONG InterlockedCompareExchange(LONG ಅಸ್ಥಿರ *Destination,LONG ExChange,LONG Comperand) {
      LONG prev;
      __asm__ __volatile__("lock ; cmpxchgl %1,%2" : "=a" (prev) : "q" (ExChange),"m" (*Destination), "0" (Comperand) : "memory");
      ಹಿಂತಿರುಗಿ prev;
    }
    __CRT_INLINE LONG64 InterlockedIncrement64(LONG64 ಅಸ್ಥಿರ *Addend) {
      ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ c;
      ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ s;
      __asm__ __volatile__(
	"lock ; addq $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      ಹಿಂತಿರುಗಿ (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE LONG64 InterlockedDecrement64(LONG64 ಅಸ್ಥಿರ *Addend) {
      ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ c;
      ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ s;
      __asm__ __volatile__(
	"lock ; subq $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      ಹಿಂತಿರುಗಿ (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE LONG64 InterlockedExchange64(LONG64 ಅಸ್ಥಿರ *ಗುರಿ_2,LONG64 ಮೌಲ್ಯ_3) {
      __asm__ __volatile("lock ; xchgq %0,%1"
	: "=r"(ಮೌಲ್ಯ_3)
	: "m"(*ಗುರಿ_2),"0"(ಮೌಲ್ಯ_3)
	: "memory");
      ಹಿಂತಿರುಗಿ ಮೌಲ್ಯ_3;
    }
    LONG64 InterlockedExchangeAdd64(LONG64 ಅಸ್ಥಿರ *Addend,LONG64 ಮೌಲ್ಯ_3);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _X86AMD64_
    __CRT_INLINE LONG64 InterlockedAdd64(LONG64 ಅಸ್ಥಿರ *Addend,LONG64 ಮೌಲ್ಯ_3) { ಹಿಂತಿರುಗಿ InterlockedExchangeAdd64(Addend,ಮೌಲ್ಯ_3) + ಮೌಲ್ಯ_3; }
#ಆದರೆ_ಅಂತ್ಯ

    __CRT_INLINE LONG64 InterlockedCompareExchange64(LONG64 ಅಸ್ಥಿರ *Destination,LONG64 ExChange,LONG64 Comperand) {
      LONG64 prev;
      __asm__ __volatile__("lock ; cmpxchgq %1,%2" : "=a" (prev) : "q" (ExChange),"m" (*Destination), "0" (Comperand) : "memory");
      ಹಿಂತಿರುಗಿ prev;
    }
    __CRT_INLINE PVOID Interlocked_Compare_Exchange_ಸೂಚಕ(PVOID ಅಸ್ಥಿರ *Destination,PVOID ExChange,PVOID Comperand) {
      PVOID prev;
      __asm__ __volatile__("lock ; cmpxchgq %1,%2" : "=a" (prev) : "q" (ExChange),"m" (*Destination), "0" (Comperand) : "memory");
      ಹಿಂತಿರುಗಿ prev;
    }
    __CRT_INLINE PVOID Interlocked_Exchange_ಸೂಚಕ(PVOID ಅಸ್ಥಿರ *ಗುರಿ_2,PVOID ಮೌಲ್ಯ_3) {
      __asm__ __volatile("lock ; xchgq %0,%1"
	: "=r"(ಮೌಲ್ಯ_3)
	: "m"(*ಗುರಿ_2),"0"(ಮೌಲ್ಯ_3)
	: "memory");
      ಹಿಂತಿರುಗಿ ಮೌಲ್ಯ_3;
    }

#ವ್ಯಾಖ್ಯಾನಿಸು Cache_ಸಾಲು_Flush(ವಿಳಾಸ_2) _mm_clflush(ವಿಳಾಸ_2)

    VOID _ReadWriteBarrier(VOID);

#ವ್ಯಾಖ್ಯಾನಿಸು FastFence __faststorefence
#ವ್ಯಾಖ್ಯಾನಿಸು ತುಂಬು_Fence _mm_lfence
#ವ್ಯಾಖ್ಯಾನಿಸು ಸ್ಮರಣೆ_Fence _mm_mfence
#ವ್ಯಾಖ್ಯಾನಿಸು StoreFence _mm_sfence

    VOID __faststorefence(VOID);
    VOID _m_prefetchw(ಅಸ್ಥಿರ CONST VOID *ಮೂಲ_2);

//!__TINYC__: #include <intrin.h>

#ವ್ಯಾಖ್ಯಾನಿಸು YieldProcessor _mm_pause
#ವ್ಯಾಖ್ಯಾನಿಸು ಸ್ಮರಣೆ_Barrier __faststorefence
#ವ್ಯಾಖ್ಯಾನಿಸು Pre_Fetch_Cache_ಸಾಲು(l,a) _mm_prefetch((CHAR CONST *) a,l)
#ವ್ಯಾಖ್ಯಾನಿಸು PrefetchForWrite(p) _m_prefetchw(p)
#ವ್ಯಾಖ್ಯಾನಿಸು ReadForWriteAccess(p) (_m_prefetchw(p),*(p))

#ವ್ಯಾಖ್ಯಾನಿಸು PF_TEMPORAL_LEVEL_1 _MM_HINT_T0
#ವ್ಯಾಖ್ಯಾನಿಸು PF_TEMPORAL_LEVEL_2 _MM_HINT_T1
#ವ್ಯಾಖ್ಯಾನಿಸು PF_TEMPORAL_LEVEL_3 _MM_HINT_T2
#ವ್ಯಾಖ್ಯಾನಿಸು PF_NON_TEMPORAL_LEVEL_ALL _MM_HINT_NTA

#ವ್ಯಾಖ್ಯಾನಿಸು ReadMxCsr _mm_getcsr
#ವ್ಯಾಖ್ಯಾನಿಸು WriteMxCsr _mm_setcsr

    VOID __int2c(VOID);

#ವ್ಯಾಖ್ಯಾನಿಸು DbgRaiseAssertionFailure() __int2c()
#ವ್ಯಾಖ್ಯಾನಿಸು GetCallersEflags() __getcallerseflags()

    ಚಿಹ್ನೆರಹಿತ __int32 __getcallerseflags(VOID);

#ವ್ಯಾಖ್ಯಾನಿಸು Get_Segment_ಎಲ್ಲೆ __segmentlimit

    DWORD __segmentlimit(DWORD Selector);

#ವ್ಯಾಖ್ಯಾನಿಸು Read_ಸಮಯ_Stamp_Counter() __rdtsc()

    DWORD64 __rdtsc(VOID);
    VOID __movsb(PBYTE Destination,BYTE ಸ್ಥಿರಾಂಕ *ಮೂಲ_2,ಗಾತ್ರ_T ಎಣಿಕೆ_4);
    VOID __movsw(PWORD Destination,ಶಬ್ದ_3 ಸ್ಥಿರಾಂಕ *ಮೂಲ_2,ಗಾತ್ರ_T ಎಣಿಕೆ_4);
    VOID __movsd(PDWORD Destination,DWORD ಸ್ಥಿರಾಂಕ *ಮೂಲ_2,ಗಾತ್ರ_T ಎಣಿಕೆ_4);
    VOID __movsq(PDWORD64 Destination,DWORD64 ಸ್ಥಿರಾಂಕ *ಮೂಲ_2,ಗಾತ್ರ_T ಎಣಿಕೆ_4);
    VOID __stosb(PBYTE Destination,BYTE ಮೌಲ್ಯ_3,ಗಾತ್ರ_T ಎಣಿಕೆ_4);
    VOID __stosw(PWORD Destination,ಶಬ್ದ_3 ಮೌಲ್ಯ_3,ಗಾತ್ರ_T ಎಣಿಕೆ_4);
    VOID __stosd(PDWORD Destination,DWORD ಮೌಲ್ಯ_3,ಗಾತ್ರ_T ಎಣಿಕೆ_4);
    VOID __stosq(PDWORD64 Destination,DWORD64 ಮೌಲ್ಯ_3,ಗಾತ್ರ_T ಎಣಿಕೆ_4);

#ವ್ಯಾಖ್ಯಾನಿಸು Multiply_ಮೇಲಿನ __mulh
#ವ್ಯಾಖ್ಯಾನಿಸು Unsigned_Multiply_ಮೇಲಿನ __umulh

    LONGLONG Multiply_ಮೇಲಿನ(LONGLONG Multiplier,LONGLONG Multiplicand);
    ULONGLONG Unsigned_Multiply_ಮೇಲಿನ(ULONGLONG Multiplier,ULONGLONG Multiplicand);

#ವ್ಯಾಖ್ಯಾನಿಸು ಸರಿಸು_Left128 __shiftleft128
#ವ್ಯಾಖ್ಯಾನಿಸು ಸರಿಸು_Right128 __shiftright128

    DWORD64 ಸರಿಸು_Left128(DWORD64 ಕೆಳಗಿನ_Part,DWORD64 ಮೇಲಿನ_Part,BYTE ಸರಿಸು_3);
    DWORD64 ಸರಿಸು_Right128(DWORD64 ಕೆಳಗಿನ_Part,DWORD64 ಮೇಲಿನ_Part,BYTE ಸರಿಸು_3);

#ವ್ಯಾಖ್ಯಾನಿಸು Multiply128 _mul128

    LONG64 Multiply128(LONG64 Multiplier,LONG64 Multiplicand,LONG64 *ಮೇಲಿನ_ಗುಣಲಬ್ಧ);

#ವ್ಯಾಖ್ಯಾನಿಸು UnsignedMultiply128 _umul128

    DWORD64 UnsignedMultiply128(DWORD64 Multiplier,DWORD64 Multiplicand,DWORD64 *ಮೇಲಿನ_ಗುಣಲಬ್ಧ);

    __CRT_INLINE LONG64 MultiplyExtract128(LONG64 Multiplier,LONG64 Multiplicand,BYTE ಸರಿಸು_3) {
      LONG64 extracted_ಗುಣಲಬ್ಧ;
      LONG64 ಮೇಲಿನ_ಗುಣಲಬ್ಧ_2;
      LONG64 ಕೆಳಗಿನ_ಗುಣಲಬ್ಧ;
      ಕೆಳಗಿನ_ಗುಣಲಬ್ಧ = Multiply128(Multiplier,Multiplicand,&ಮೇಲಿನ_ಗುಣಲಬ್ಧ_2);
      extracted_ಗುಣಲಬ್ಧ = (LONG64)ಸರಿಸು_Right128((LONG64)ಕೆಳಗಿನ_ಗುಣಲಬ್ಧ,(LONG64)ಮೇಲಿನ_ಗುಣಲಬ್ಧ_2,ಸರಿಸು_3);
      ಹಿಂತಿರುಗಿ extracted_ಗುಣಲಬ್ಧ;
    }

    __CRT_INLINE DWORD64 UnsignedMultiplyExtract128(DWORD64 Multiplier,DWORD64 Multiplicand,BYTE ಸರಿಸು_3) {
      DWORD64 extracted_ಗುಣಲಬ್ಧ;
      DWORD64 ಮೇಲಿನ_ಗುಣಲಬ್ಧ_2;
      DWORD64 ಕೆಳಗಿನ_ಗುಣಲಬ್ಧ;
      ಕೆಳಗಿನ_ಗುಣಲಬ್ಧ = UnsignedMultiply128(Multiplier,Multiplicand,&ಮೇಲಿನ_ಗುಣಲಬ್ಧ_2);
      extracted_ಗುಣಲಬ್ಧ = ಸರಿಸು_Right128(ಕೆಳಗಿನ_ಗುಣಲಬ್ಧ,ಮೇಲಿನ_ಗುಣಲಬ್ಧ_2,ಸರಿಸು_3);
      ಹಿಂತಿರುಗಿ extracted_ಗುಣಲಬ್ಧ;
    }

    __CRT_INLINE BYTE __readgsbyte(DWORD ಸ್ಥಾನಾಂತರ_3) {
      BYTE ret;
      __asm__ ಅಸ್ಥಿರ ("movb	%%gs:%1,%0"
	: "=r" (ret) ,"=m" ((*(ಅಸ್ಥಿರ ದೀರ್ಘ *) (DWORD64) ಸ್ಥಾನಾಂತರ_3)));
      ಹಿಂತಿರುಗಿ ret;
    }
    __CRT_INLINE ಶಬ್ದ_3 __readgsword(DWORD ಸ್ಥಾನಾಂತರ_3) {
      ಶಬ್ದ_3 ret;
      __asm__ ಅಸ್ಥಿರ ("movw	%%gs:%1,%0"
	: "=r" (ret) ,"=m" ((*(ಅಸ್ಥಿರ ದೀರ್ಘ *) (DWORD64) ಸ್ಥಾನಾಂತರ_3)));
      ಹಿಂತಿರುಗಿ ret;
    }
    __CRT_INLINE DWORD __readgsdword(DWORD ಸ್ಥಾನಾಂತರ_3) {
      DWORD ret;
      __asm__ ಅಸ್ಥಿರ ("movl	%%gs:%1,%0"
	: "=r" (ret) ,"=m" ((*(ಅಸ್ಥಿರ ದೀರ್ಘ *) (DWORD64) ಸ್ಥಾನಾಂತರ_3)));
      ಹಿಂತಿರುಗಿ ret;
    }
    __CRT_INLINE DWORD64 __readgsqword(DWORD ಸ್ಥಾನಾಂತರ_3) {
      ಶೂನ್ಯ *ret;
      __asm__ ಅಸ್ಥಿರ ("movq	%%gs:%1,%0"
	: "=r" (ret) ,"=m" ((*(ಅಸ್ಥಿರ ದೀರ್ಘ *) (DWORD64) ಸ್ಥಾನಾಂತರ_3)));
      ಹಿಂತಿರುಗಿ (DWORD64) ret;
    }
    __CRT_INLINE VOID __writegsbyte(DWORD ಸ್ಥಾನಾಂತರ_3,BYTE ದತ್ತಾಂಶ_3) {
      __asm__ ಅಸ್ಥಿರ ("movb	%0,%%gs:%1"
	: "=r" (ದತ್ತಾಂಶ_3) ,"=m" ((*(ಅಸ್ಥಿರ ದೀರ್ಘ *) (DWORD64) ಸ್ಥಾನಾಂತರ_3)));
    }
    __CRT_INLINE VOID __writegsword(DWORD ಸ್ಥಾನಾಂತರ_3,ಶಬ್ದ_3 ದತ್ತಾಂಶ_3) {
      __asm__ ಅಸ್ಥಿರ ("movw	%0,%%gs:%1"
	: "=r" (ದತ್ತಾಂಶ_3) ,"=m" ((*(ಅಸ್ಥಿರ ದೀರ್ಘ *) (DWORD64) ಸ್ಥಾನಾಂತರ_3)));
    }
    __CRT_INLINE VOID __writegsdword(DWORD ಸ್ಥಾನಾಂತರ_3,DWORD ದತ್ತಾಂಶ_3) {
      __asm__ ಅಸ್ಥಿರ ("movl	%0,%%gs:%1"
	: "=r" (ದತ್ತಾಂಶ_3) ,"=m" ((*(ಅಸ್ಥಿರ ದೀರ್ಘ *) (DWORD64) ಸ್ಥಾನಾಂತರ_3)));
    }
    __CRT_INLINE VOID __writegsqword(DWORD ಸ್ಥಾನಾಂತರ_3,DWORD64 ದತ್ತಾಂಶ_3) {
      __asm__ ಅಸ್ಥಿರ ("movq	%0,%%gs:%1"
	: "=r" (ದತ್ತಾಂಶ_3) ,"=m" ((*(ಅಸ್ಥಿರ ದೀರ್ಘ *) (DWORD64) ಸ್ಥಾನಾಂತರ_3)));
    }

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
  }
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು EXCEPTION_READ_FAULT 0
#ವ್ಯಾಖ್ಯಾನಿಸು EXCEPTION_WRITE_FAULT 1
#ವ್ಯಾಖ್ಯಾನಿಸು EXCEPTION_EXECUTE_FAULT 8

#ಆದರೆ !defined(RC_INVOKED)

#ವ್ಯಾಖ್ಯಾನಿಸು CONTEXT_AMD64 0x100000

#ವ್ಯಾಖ್ಯಾನಿಸು CONTEXT_CONTROL (CONTEXT_AMD64 | 0x1L)
#ವ್ಯಾಖ್ಯಾನಿಸು CONTEXT_INTEGER (CONTEXT_AMD64 | 0x2L)
#ವ್ಯಾಖ್ಯಾನಿಸು CONTEXT_SEGMENTS (CONTEXT_AMD64 | 0x4L)
#ವ್ಯಾಖ್ಯಾನಿಸು CONTEXT_FLOATING_ಬಿಂದು (CONTEXT_AMD64 | 0x8L)
#ವ್ಯಾಖ್ಯಾನಿಸು CONTEXT_DEBUG_REGISTERS (CONTEXT_AMD64 | 0x10L)

#ವ್ಯಾಖ್ಯಾನಿಸು CONTEXT_ತುಂಬಿದ (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_FLOATING_ಬಿಂದು)
#ವ್ಯಾಖ್ಯಾನಿಸು CONTEXT_ALL (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_SEGMENTS | CONTEXT_FLOATING_ಬಿಂದು | CONTEXT_DEBUG_REGISTERS)

#ವ್ಯಾಖ್ಯಾನಿಸು CONTEXT_EXCEPTION_ಸಕ್ರಿಯ 0x8000000
#ವ್ಯಾಖ್ಯಾನಿಸು CONTEXT_SERVICE_ಸಕ್ರಿಯ 0x10000000
#ವ್ಯಾಖ್ಯಾನಿಸು CONTEXT_EXCEPTION_REQUEST 0x40000000
#ವ್ಯಾಖ್ಯಾನಿಸು CONTEXT_EXCEPTION_REPORTING 0x80000000
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು INITIAL_MXCSR 0x1f80
#ವ್ಯಾಖ್ಯಾನಿಸು INITIAL_FPCSR 0x027f

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ DECLSPEC_ALIGN(16) _M128A {
    ULONGLONG ಕೆಳಗಿನ_3;
    LONGLONG ಮೇಲಿನ_3;
  } M128A,*PM128A;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _XMM_SAVE_AREA32 {
    ಶಬ್ದ_3 Control_ಶಬ್ದ;
    ಶಬ್ದ_3 ಸ್ಥಿತಿ_ಶಬ್ದ;
    BYTE ಟ್ಯಾಗ್_ಶಬ್ದ;
    BYTE Reserved1;
    ಶಬ್ದ_3 ErrorOpcode;
    DWORD Error_ಸ್ಥಾನಾಂತರ;
    ಶಬ್ದ_3 ErrorSelector;
    ಶಬ್ದ_3 Reserved2;
    DWORD ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ_2;
    ಶಬ್ದ_3 ದತ್ತಾಂಶ_Selector;
    ಶಬ್ದ_3 Reserved3;
    DWORD MxCsr;
    DWORD Mx_Csr_ಮುಖವಾಡ;
    M128A FloatRegisters[8];
    M128A XmmRegisters[16];
    BYTE Reserved4[96];
  } XMM_SAVE_AREA32,*PXMM_SAVE_AREA32;

#ವ್ಯಾಖ್ಯಾನಿಸು LEGACY_SAVE_AREA_ಉದ್ದಳತೆ ಗಾತ್ರ(XMM_SAVE_AREA32)

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ DECLSPEC_ALIGN(16) _CONTEXT {
    DWORD64 P1Home;
    DWORD64 P2Home;
    DWORD64 P3Home;
    DWORD64 P4Home;
    DWORD64 P5Home;
    DWORD64 P6Home;
    DWORD ContextFlags;
    DWORD MxCsr;
    ಶಬ್ದ_3 SegCs;
    ಶಬ್ದ_3 SegDs;
    ಶಬ್ದ_3 SegEs;
    ಶಬ್ದ_3 SegFs;
    ಶಬ್ದ_3 SegGs;
    ಶಬ್ದ_3 SegSs;
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
    ಒಕ್ಕೂಟ {
      XMM_SAVE_AREA32 FltSave;
      XMM_SAVE_AREA32 FloatSave;
      ರಚನೆ {
	M128A ಶೀರ್ಷಿಕೆ_2[2];
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
    M128A ಸದಿಶ_ರಿಜಿಸ್ಟರ್[26];
    DWORD64 ಸದಿಶ_Control;
    DWORD64 DebugControl;
    DWORD64 ಕೊನೆಯ_Branch_ಗಮ್ಯ_Rip;
    DWORD64 ಕೊನೆಯ_Branch_From_Rip;
    DWORD64 ಕೊನೆಯ_Exception_ಗಮ್ಯ_Rip;
    DWORD64 ಕೊನೆಯ_Exception_From_Rip;
  } CONTEXT,*PCONTEXT;

#ವ್ಯಾಖ್ಯಾನಿಸು RUNTIME_FUNCTION_ಪರೋಕ್ಷ 0x1

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _RUNTIME_FUNCTION {
    DWORD Begin_ವಿಳಾಸ;
    DWORD ಕೊನೆ_ವಿಳಾಸ;
    DWORD Unwind_ದತ್ತಾಂಶ;
  } RUNTIME_FUNCTION,*PRUNTIME_FUNCTION;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PRUNTIME_FUNCTION (*PGET_RUNTIME_FUNCTION_CALLBACK)(DWORD64 ControlPc,PVOID Context);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ DWORD (*POUT_ದ_PROCESS_FUNCTION_ಕೋಷ್ಟಕ_CALLBACK)(HANDLE Process,PVOID ಕೋಷ್ಟಕ_ವಿಳಾಸ,PDWORD Entries,PRUNTIME_FUNCTION *Functions);

#ವ್ಯಾಖ್ಯಾನಿಸು ಹೊರಹೋಗು_ದ_PROCESS_FUNCTION_ಕೋಷ್ಟಕ_CALLBACK_EXPORT_NAME "OutOfProcessFunctionTableCallback"
#ಆದರೆ_ಅಂತ್ಯ /* defined(__x86_64) && !defined(RC_INVOKED) */

#ಆದರೆ defined(__TINYC__) && (defined(__aarch64__) || defined(__arm64__)) && !defined(RC_INVOKED)

#ವ್ಯಾಖ್ಯಾನಿಸು __TCC_WINNT_ATOMIC_SEQ_CST 5
/* TCC lowers __atomic_compare_exchange's fourth argument as weak, but the
   ARM64 helper reads it as success_memorder.  Strong CAS passes weak == 0,
   so keep Interlocked's barriers explicit here. */
#ವ್ಯಾಖ್ಯಾನಿಸು __TCC_WINNT_MEMORY_BARRIER() __asm__ __volatile__("dmb ish" : : : "memory")

/* This covers the LONG operations needed by TCC's semaphore code and the
   pointer helpers that winbase.h exposes through Interlocked pointer macros.
   Add local helpers before relying on increment/decrement, add/exchange-add,
   bitwise, or 64-bit Interlocked forms on Windows ARM64 with TCC. */

    __CRT_INLINE LONG InterlockedExchange(LONG ಅಸ್ಥಿರ *ಗುರಿ_2,LONG ಮೌಲ್ಯ_3) {
      LONG Old;
      __atomic_load(ಗುರಿ_2,&Old,__TCC_WINNT_ATOMIC_SEQ_CST);
      __TCC_WINNT_MEMORY_BARRIER();
      ಆಗ (!__atomic_compare_exchange(ಗುರಿ_2,&Old,&ಮೌಲ್ಯ_3,0,
	__TCC_WINNT_ATOMIC_SEQ_CST,__TCC_WINNT_ATOMIC_SEQ_CST))
	;
      __TCC_WINNT_MEMORY_BARRIER();
      ಹಿಂತಿರುಗಿ Old;
    }
    __CRT_INLINE LONG InterlockedCompareExchange(LONG ಅಸ್ಥಿರ *Destination,LONG ExChange,LONG Comperand) {
      LONG Old = Comperand;
      __TCC_WINNT_MEMORY_BARRIER();
      __atomic_compare_exchange(Destination,&Old,&ExChange,0,
	__TCC_WINNT_ATOMIC_SEQ_CST,__TCC_WINNT_ATOMIC_SEQ_CST);
      __TCC_WINNT_MEMORY_BARRIER();
      ಹಿಂತಿರುಗಿ Old;
    }
    __CRT_INLINE PVOID __TCC_WINNT_InterlockedExchangePointer(PVOID ಅಸ್ಥಿರ *ಗುರಿ_2,PVOID ಮೌಲ್ಯ_3) {
      PVOID Old;
      __atomic_load(ಗುರಿ_2,&Old,__TCC_WINNT_ATOMIC_SEQ_CST);
      __TCC_WINNT_MEMORY_BARRIER();
      ಆಗ (!__atomic_compare_exchange(ಗುರಿ_2,&Old,&ಮೌಲ್ಯ_3,0,
	__TCC_WINNT_ATOMIC_SEQ_CST,__TCC_WINNT_ATOMIC_SEQ_CST))
	;
      __TCC_WINNT_MEMORY_BARRIER();
      ಹಿಂತಿರುಗಿ Old;
    }
    __CRT_INLINE PVOID __TCC_WINNT_InterlockedCompareExchangePointer(PVOID ಅಸ್ಥಿರ *Destination,PVOID ExChange,PVOID Comperand) {
      PVOID Old = Comperand;
      __TCC_WINNT_MEMORY_BARRIER();
      __atomic_compare_exchange(Destination,&Old,&ExChange,0,
	__TCC_WINNT_ATOMIC_SEQ_CST,__TCC_WINNT_ATOMIC_SEQ_CST);
      __TCC_WINNT_MEMORY_BARRIER();
      ಹಿಂತಿರುಗಿ Old;
    }

#ವ್ಯಾಖ್ಯಾನಿಸು Interlocked_Exchange_ಸೂಚಕ __TCC_WINNT_InterlockedExchangePointer
#ವ್ಯಾಖ್ಯಾನಿಸು Interlocked_Compare_Exchange_ಸೂಚಕ __TCC_WINNT_InterlockedCompareExchangePointer
#ವ್ಯಾಖ್ಯಾನಿಸು Interlocked_Compare_Exchange_ಸೂಚಕ_Acquire Interlocked_Compare_Exchange_ಸೂಚಕ
#ವ್ಯಾಖ್ಯಾನಿಸು Interlocked_Compare_Exchange_ಸೂಚಕ_Release Interlocked_Compare_Exchange_ಸೂಚಕ

#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedCompareExchangeAcquire InterlockedCompareExchange
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedCompareExchangeRelease InterlockedCompareExchange

#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು __TCC_WINNT_MEMORY_BARRIER
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು __TCC_WINNT_ATOMIC_SEQ_CST

#ಆದರೆ_ಅಂತ್ಯ /* defined(__TINYC__) && (defined(__aarch64__) || defined(__arm64__)) && !defined(RC_INVOKED) */

#ಆದರೆ defined(_ARM64_)

/* ARM64 Context Definition */
#ವ್ಯಾಖ್ಯಾನಿಸು CONTEXT_ARM64 0x00400000
#ವ್ಯಾಖ್ಯಾನಿಸು CONTEXT_CONTROL (CONTEXT_ARM64 | 0x00000001L)
#ವ್ಯಾಖ್ಯಾನಿಸು CONTEXT_INTEGER (CONTEXT_ARM64 | 0x00000002L)
#ವ್ಯಾಖ್ಯಾನಿಸು CONTEXT_FLOATING_ಬಿಂದು (CONTEXT_ARM64 | 0x00000004L)
#ವ್ಯಾಖ್ಯಾನಿಸು CONTEXT_DEBUG (CONTEXT_ARM64 | 0x00000008L)
#ವ್ಯಾಖ್ಯಾನಿಸು CONTEXT_ತುಂಬಿದ (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_FLOATING_ಬಿಂದು)
#ವ್ಯಾಖ್ಯಾನಿಸು CONTEXT_ALL (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_FLOATING_ಬಿಂದು | CONTEXT_DEBUG)
#ವ್ಯಾಖ್ಯಾನಿಸು ARM64_MAX_BREAKPOINTS 8
#ವ್ಯಾಖ್ಯಾನಿಸು ARM64_MAX_WATCHPOINTS 2

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಒಕ್ಕೂಟ _ARM64_NT_NEON128 {
    ರಚನೆ {
      ULONGLONG ಕೆಳಗಿನ_3;
      LONGLONG ಮೇಲಿನ_3;
    } DUMMYSTRUCTNAME;
    ದ್ವಿಗುಣ D[2];
    ದಶಮಾಂಶ S[4];
    ಶಬ್ದ_3 H[8];
    BYTE B[16];
  } ARM64_NT_NEON128,*PARM64_NT_NEON128;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ DECLSPEC_ALIGN(16) _ARM64_NT_CONTEXT {
    ULONG ContextFlags;
    ULONG Cpsr;
    ಒಕ್ಕೂಟ {
      ರಚನೆ {
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

  C_ASSERT(ಗಾತ್ರ(ARM64_NT_CONTEXT) == 0x390);

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ARM64_NT_CONTEXT CONTEXT,*PCONTEXT;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _RUNTIME_FUNCTION {
    DWORD Begin_ವಿಳಾಸ;
    DWORD Unwind_ದತ್ತಾಂಶ;
  } RUNTIME_FUNCTION,*PRUNTIME_FUNCTION;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PRUNTIME_FUNCTION (*PGET_RUNTIME_FUNCTION_CALLBACK)(DWORD64 ControlPc,PVOID Context);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ DWORD (*POUT_ದ_PROCESS_FUNCTION_ಕೋಷ್ಟಕ_CALLBACK)(HANDLE Process,PVOID ಕೋಷ್ಟಕ_ವಿಳಾಸ,PDWORD Entries,PRUNTIME_FUNCTION *Functions);

#ಆದರೆ_ಅಂತ್ಯ /* _ARM64_ */

#ಆದರೆ (defined _ARM64_ || defined _AMD64_) && !defined RC_INVOKED
  NTSYSAPI VOID __cdecl RtlRestoreContext (PCONTEXT Context_ದಾಖಲೆ,ರಚನೆ EXCEPTION_ದಾಖಲೆ *Exception_ದಾಖಲೆ);
  NTSYSAPI BOOLEAN __cdecl Rtl_ಕೂಡಿಸು_Function_ಕೋಷ್ಟಕ(PRUNTIME_FUNCTION Function_ಕೋಷ್ಟಕ,DWORD ನಮೂದು_ಎಣಿಕೆ,DWORD64 ತಳ_ವಿಳಾಸ);
  NTSYSAPI BOOLEAN __cdecl Rtl_Install_Function_ಕೋಷ್ಟಕ_Callback(DWORD64 ಕೋಷ್ಟಕ_Identifier,DWORD64 ತಳ_ವಿಳಾಸ,DWORD ಉದ್ದಳತೆ_2,PGET_RUNTIME_FUNCTION_CALLBACK Callback,PVOID Context,PCWSTR ಹೊರಹೋಗು_ದ_Process_Callback_Dll);
  NTSYSAPI BOOLEAN __cdecl Rtl_Delete_Function_ಕೋಷ್ಟಕ(PRUNTIME_FUNCTION Function_ಕೋಷ್ಟಕ);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ I_X86_
#ಆದರೆ(defined(_X86_) && !defined(__x86_64)) && !defined(RC_INVOKED)
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
  ಬಾಹ್ಯ "C" {
#ಆದರೆ_ಅಂತ್ಯ

    __CRT_INLINE BOOLEAN Interlocked_ಬಿಟ್_Test_And_ಗಣ(LONG *ತಳ_2,LONG ಬಿಟ್_2) {
      ಪೂರ್ಣಾಂಕ old = 0;
      __asm__ __volatile__("lock ; btsl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(ಅಸ್ಥಿರ ದೀರ್ಘ *) ತಳ_2))
	:"Ir" (ಬಿಟ್_2));
      ಹಿಂತಿರುಗಿ (BOOLEAN) (old!=0);
    }

    __CRT_INLINE BOOLEAN Interlocked_ಬಿಟ್_Test_And_Reset(LONG *ತಳ_2,LONG ಬಿಟ್_2) {
      ಪೂರ್ಣಾಂಕ old = 0;
      __asm__ __volatile__("lock ; btrl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(ಅಸ್ಥಿರ ದೀರ್ಘ *) ತಳ_2))
	:"Ir" (ಬಿಟ್_2));
      ಹಿಂತಿರುಗಿ (BOOLEAN) (old!=0);
    }

    __CRT_INLINE BOOLEAN Interlocked_ಬಿಟ್_Test_And_Complement(LONG *ತಳ_2,LONG ಬಿಟ್_2) {
      ಪೂರ್ಣಾಂಕ old = 0;
      __asm__ __volatile__("lock ; btcl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(ಅಸ್ಥಿರ ದೀರ್ಘ *) ತಳ_2))
	:"Ir" (ಬಿಟ್_2));
      ಹಿಂತಿರುಗಿ (BOOLEAN) (old!=0);
    }

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ ಪೂರ್ವಪ್ರತ್ಯಯ_2
    BYTE __readfsbyte(DWORD ಸ್ಥಾನಾಂತರ_3);
    ಶಬ್ದ_3 __readfsword(DWORD ಸ್ಥಾನಾಂತರ_3);
    DWORD __readfsdword(DWORD ಸ್ಥಾನಾಂತರ_3);
    VOID __writefsbyte(DWORD ಸ್ಥಾನಾಂತರ_3,BYTE ದತ್ತಾಂಶ_3);
    VOID __writefsword(DWORD ಸ್ಥಾನಾಂತರ_3,ಶಬ್ದ_3 ದತ್ತಾಂಶ_3);
    VOID __writefsdword(DWORD ಸ್ಥಾನಾಂತರ_3,DWORD ದತ್ತಾಂಶ_3);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
  }
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ(defined(_X86_) && !defined(__x86_64))
  __CRT_INLINE VOID ಸ್ಮರಣೆ_Barrier(VOID) {
    LONG Barrier;
    __asm__ __volatile__("xchgl %%eax,%0 "
      :"=r" (Barrier));
  }
#ವ್ಯಾಖ್ಯಾನಿಸು YieldProcessor() __asm__ __volatile__("rep nop ");

#ವ್ಯಾಖ್ಯಾನಿಸು Pre_Fetch_Cache_ಸಾಲು(l,a)
#ವ್ಯಾಖ್ಯಾನಿಸು ReadForWriteAccess(p) (*(p))

#ವ್ಯಾಖ್ಯಾನಿಸು PF_TEMPORAL_LEVEL_1
#ವ್ಯಾಖ್ಯಾನಿಸು PF_NON_TEMPORAL_LEVEL_ALL

  __CRT_INLINE VOID DbgRaiseAssertionFailure(ಶೂನ್ಯ) {
    __asm__ __volatile__("int $0x2c ");
  }
  PVOID GetCurrentFiber(ಶೂನ್ಯ);
  __CRT_INLINE PVOID GetCurrentFiber(ಶೂನ್ಯ)
  {
    ಶೂನ್ಯ *ret;
    __asm__ ಅಸ್ಥಿರ ("movl	%%fs:0x10,%0"
	: "=r" (ret));
    ಹಿಂತಿರುಗಿ ret;
  }
  PVOID Get_Fiber_ದತ್ತಾಂಶ(ಶೂನ್ಯ);
  __CRT_INLINE PVOID Get_Fiber_ದತ್ತಾಂಶ(ಶೂನ್ಯ)
  {
    ಶೂನ್ಯ *ret;
    __asm__ ಅಸ್ಥಿರ ("movl	%%fs:0x10,%0\n"
	"movl	(%0),%0"
	: "=r" (ret));
    ಹಿಂತಿರುಗಿ ret;
  }
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು EXCEPTION_READ_FAULT 0
#ವ್ಯಾಖ್ಯಾನಿಸು EXCEPTION_WRITE_FAULT 1
#ವ್ಯಾಖ್ಯಾನಿಸು EXCEPTION_EXECUTE_FAULT 8

#ವ್ಯಾಖ್ಯಾನಿಸು ಗಾತ್ರ_ದ_80387_REGISTERS 80

#ಆದರೆ !defined(RC_INVOKED)

#ವ್ಯಾಖ್ಯಾನಿಸು CONTEXT_i386 0x00010000
#ವ್ಯಾಖ್ಯಾನಿಸು CONTEXT_i486 0x00010000

#ವ್ಯಾಖ್ಯಾನಿಸು CONTEXT_CONTROL (CONTEXT_i386 | 0x00000001L)
#ವ್ಯಾಖ್ಯಾನಿಸು CONTEXT_INTEGER (CONTEXT_i386 | 0x00000002L)
#ವ್ಯಾಖ್ಯಾನಿಸು CONTEXT_SEGMENTS (CONTEXT_i386 | 0x00000004L)
#ವ್ಯಾಖ್ಯಾನಿಸು CONTEXT_FLOATING_ಬಿಂದು (CONTEXT_i386 | 0x00000008L)
#ವ್ಯಾಖ್ಯಾನಿಸು CONTEXT_DEBUG_REGISTERS (CONTEXT_i386 | 0x00000010L)
#ವ್ಯಾಖ್ಯಾನಿಸು CONTEXT_EXTENDED_REGISTERS (CONTEXT_i386 | 0x00000020L)

#ವ್ಯಾಖ್ಯಾನಿಸು CONTEXT_ತುಂಬಿದ (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_SEGMENTS)

#ವ್ಯಾಖ್ಯಾನಿಸು CONTEXT_ALL (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_SEGMENTS | CONTEXT_FLOATING_ಬಿಂದು | CONTEXT_DEBUG_REGISTERS | CONTEXT_EXTENDED_REGISTERS)
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು ಗರಿಷ್ಠ_SUPPORTED_EXTENSION 512

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _FLOATING_SAVE_AREA {
      DWORD Control_ಶಬ್ದ;
      DWORD ಸ್ಥಿತಿ_ಶಬ್ದ;
      DWORD ಟ್ಯಾಗ್_ಶಬ್ದ;
      DWORD Error_ಸ್ಥಾನಾಂತರ;
      DWORD ErrorSelector;
      DWORD ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ_2;
      DWORD ದತ್ತಾಂಶ_Selector;
      BYTE ರಿಜಿಸ್ಟರ್_Area[ಗಾತ್ರ_ದ_80387_REGISTERS];
      DWORD Cr0NpxState;
    } FLOATING_SAVE_AREA;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ FLOATING_SAVE_AREA *PFLOATING_SAVE_AREA;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _CONTEXT {
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
      BYTE ExtendedRegisters[ಗರಿಷ್ಠ_SUPPORTED_EXTENSION];
    } CONTEXT;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ CONTEXT *PCONTEXT;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ LDT_ನಮೂದು_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು LDT_ನಮೂದು_DEFINED

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ LDT_ನಮೂದು {
      ಶಬ್ದ_3 ಎಲ್ಲೆ_ಕೆಳಗಿನ;
      ಶಬ್ದ_3 ತಳ_ಕೆಳಗಿನ;
      ಒಕ್ಕೂಟ {
	ರಚನೆ {
	  BYTE ತಳ_Mid;
	  BYTE Flags1;
	  BYTE Flags2;
	  BYTE ತಳ_Hi;
	} ಬೈಟುಗಳು_2;
	ರಚನೆ {
	  DWORD ತಳ_Mid : 8;
	  DWORD Type : 5;
	  DWORD Dpl : 2;
	  DWORD Pres : 1;
	  DWORD ಎಲ್ಲೆ_Hi : 4;
	  DWORD Sys : 1;
	  DWORD Reserved_0 : 1;
	  DWORD Default_Big : 1;
	  DWORD Granularity : 1;
	  DWORD ತಳ_Hi : 8;
	} ಬಿಟ್ಟುಗಳು_2;
      } ಮೇಲಿನ_ಶಬ್ದ;
    } LDT_ನಮೂದು_2,*PLDT_ನಮೂದು;
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ defined(__ia64__) && !defined(RC_INVOKED)

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
    ಬಾಹ್ಯ "C" {
#ಆದರೆ_ಅಂತ್ಯ

      BOOLEAN ಬಿಟ್_ಪರಿಶೀಲನೆ_Forward64(DWORD *ಸೂಚ್ಯಂಕ_3,DWORD64 ಮುಖವಾಡ_3);
      BOOLEAN ಬಿಟ್_ಪರಿಶೀಲನೆ_Reverse64(DWORD *ಸೂಚ್ಯಂಕ_3,DWORD64 ಮುಖವಾಡ_3);

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
    }
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ !defined(GENUTIL) && !defined(_GENIA64_) && defined(_IA64_)

    ಶೂನ್ಯ *_cdecl _rdteb(ಶೂನ್ಯ);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __ia64__

#ವ್ಯಾಖ್ಯಾನಿಸು NtCurrentTeb() ((ರಚನೆ _TEB *)_rdteb())
#ವ್ಯಾಖ್ಯಾನಿಸು GetCurrentFiber() (((PNT_TIB)NtCurrentTeb())->Fiber_ದತ್ತಾಂಶ)
#ವ್ಯಾಖ್ಯಾನಿಸು Get_Fiber_ದತ್ತಾಂಶ() (*(PVOID *)(GetCurrentFiber()))

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
    ಬಾಹ್ಯ "C" {
#ಆದರೆ_ಅಂತ್ಯ

      ಶೂನ್ಯ __break(ಪೂರ್ಣಾಂಕ);
      ಶೂನ್ಯ __yield(ಶೂನ್ಯ);
      ಶೂನ್ಯ __mf(ಶೂನ್ಯ);
      ಶೂನ್ಯ __lfetch(ಪೂರ್ಣಾಂಕ Level,VOID CONST *ವಿಳಾಸ_2);
      ಶೂನ್ಯ __lfetchfault(ಪೂರ್ಣಾಂಕ Level,VOID CONST *ವಿಳಾಸ_2);
      ಶೂನ್ಯ __lfetch_excl(ಪೂರ್ಣಾಂಕ Level,VOID CONST *ವಿಳಾಸ_2);
      ಶೂನ್ಯ __lfetchfault_excl(ಪೂರ್ಣಾಂಕ Level,VOID CONST *ವಿಳಾಸ_2);

#ವ್ಯಾಖ್ಯಾನಿಸು MD_LFHINT_NONE 0x00
#ವ್ಯಾಖ್ಯಾನಿಸು MD_LFHINT_NT1 0x01
#ವ್ಯಾಖ್ಯಾನಿಸು MD_LFHINT_NT2 0x02
#ವ್ಯಾಖ್ಯಾನಿಸು MD_LFHINT_NTA 0x03

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
    }
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು YieldProcessor __yield
#ವ್ಯಾಖ್ಯಾನಿಸು ಸ್ಮರಣೆ_Barrier __mf
#ವ್ಯಾಖ್ಯಾನಿಸು Pre_Fetch_Cache_ಸಾಲು __lfetch
#ವ್ಯಾಖ್ಯಾನಿಸು ReadForWriteAccess(p) (*(p))
#ವ್ಯಾಖ್ಯಾನಿಸು DbgRaiseAssertionFailure() __break(ASSERT_BREAKPOINT)

#ವ್ಯಾಖ್ಯಾನಿಸು PF_TEMPORAL_LEVEL_1 MD_LFHINT_NONE
#ವ್ಯಾಖ್ಯಾನಿಸು PF_NON_TEMPORAL_LEVEL_ALL MD_LFHINT_NTA

#ವ್ಯಾಖ್ಯಾನಿಸು Unsigned_Multiply_ಮೇಲಿನ __UMULH

    ULONGLONG Unsigned_Multiply_ಮೇಲಿನ(ULONGLONG Multiplier,ULONGLONG Multiplicand);
#ಇಲ್ಲದಿದ್ದರೆ
    ರಚನೆ _TEB *NtCurrentTeb(ಶೂನ್ಯ);
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _IA64_

#ವ್ಯಾಖ್ಯಾನಿಸು EXCEPTION_READ_FAULT 0
#ವ್ಯಾಖ್ಯಾನಿಸು EXCEPTION_WRITE_FAULT 1
#ವ್ಯಾಖ್ಯಾನಿಸು EXCEPTION_EXECUTE_FAULT 2

#ಆದರೆ !defined(RC_INVOKED)

#ವ್ಯಾಖ್ಯಾನಿಸು CONTEXT_IA64 0x00080000

#ವ್ಯಾಖ್ಯಾನಿಸು CONTEXT_CONTROL (CONTEXT_IA64 | 0x00000001L)
#ವ್ಯಾಖ್ಯಾನಿಸು CONTEXT_ಅಧೋ_FLOATING_ಬಿಂದು (CONTEXT_IA64 | 0x00000002L)
#ವ್ಯಾಖ್ಯಾನಿಸು CONTEXT_HIGHER_FLOATING_ಬಿಂದು (CONTEXT_IA64 | 0x00000004L)
#ವ್ಯಾಖ್ಯಾನಿಸು CONTEXT_INTEGER (CONTEXT_IA64 | 0x00000008L)
#ವ್ಯಾಖ್ಯಾನಿಸು CONTEXT_DEBUG (CONTEXT_IA64 | 0x00000010L)
#ವ್ಯಾಖ್ಯಾನಿಸು CONTEXT_IA32_CONTROL (CONTEXT_IA64 | 0x00000020L)

#ವ್ಯಾಖ್ಯಾನಿಸು CONTEXT_FLOATING_ಬಿಂದು (CONTEXT_ಅಧೋ_FLOATING_ಬಿಂದು | CONTEXT_HIGHER_FLOATING_ಬಿಂದು)
#ವ್ಯಾಖ್ಯಾನಿಸು CONTEXT_ತುಂಬಿದ (CONTEXT_CONTROL | CONTEXT_FLOATING_ಬಿಂದು | CONTEXT_INTEGER | CONTEXT_IA32_CONTROL)
#ವ್ಯಾಖ್ಯಾನಿಸು CONTEXT_ALL (CONTEXT_CONTROL | CONTEXT_FLOATING_ಬಿಂದು | CONTEXT_INTEGER | CONTEXT_DEBUG | CONTEXT_IA32_CONTROL)

#ವ್ಯಾಖ್ಯಾನಿಸು CONTEXT_EXCEPTION_ಸಕ್ರಿಯ 0x8000000
#ವ್ಯಾಖ್ಯಾನಿಸು CONTEXT_SERVICE_ಸಕ್ರಿಯ 0x10000000
#ವ್ಯಾಖ್ಯಾನಿಸು CONTEXT_EXCEPTION_REQUEST 0x40000000
#ವ್ಯಾಖ್ಯಾನಿಸು CONTEXT_EXCEPTION_REPORTING 0x80000000
#ಆದರೆ_ಅಂತ್ಯ

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _CONTEXT {
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

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _PLABEL_DESCRIPTOR {
      ULONGLONG ನಮೂದು_ಬಿಂದು;
      ULONGLONG Global_ಸೂಚಕ_2;
    } PLABEL_DESCRIPTOR,*PPLABEL_DESCRIPTOR;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _RUNTIME_FUNCTION {
      DWORD Begin_ವಿಳಾಸ;
      DWORD ಕೊನೆ_ವಿಳಾಸ;
      DWORD Unwind_Info_ವಿಳಾಸ;
    } RUNTIME_FUNCTION,*PRUNTIME_FUNCTION;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PRUNTIME_FUNCTION (*PGET_RUNTIME_FUNCTION_CALLBACK)(DWORD64 ControlPc,PVOID Context);
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ DWORD (*POUT_ದ_PROCESS_FUNCTION_ಕೋಷ್ಟಕ_CALLBACK)(HANDLE Process,PVOID ಕೋಷ್ಟಕ_ವಿಳಾಸ,PDWORD Entries,PRUNTIME_FUNCTION *Functions);

#ವ್ಯಾಖ್ಯಾನಿಸು ಹೊರಹೋಗು_ದ_PROCESS_FUNCTION_ಕೋಷ್ಟಕ_CALLBACK_EXPORT_NAME "OutOfProcessFunctionTableCallback"

    BOOLEAN Rtl_ಕೂಡಿಸು_Function_ಕೋಷ್ಟಕ(PRUNTIME_FUNCTION Function_ಕೋಷ್ಟಕ,DWORD ನಮೂದು_ಎಣಿಕೆ,ULONGLONG ತಳ_ವಿಳಾಸ,ULONGLONG ಗುರಿ_Gp);
    BOOLEAN Rtl_Install_Function_ಕೋಷ್ಟಕ_Callback(DWORD64 ಕೋಷ್ಟಕ_Identifier,DWORD64 ತಳ_ವಿಳಾಸ,DWORD ಉದ್ದಳತೆ_2,DWORD64 ಗುರಿ_Gp,PGET_RUNTIME_FUNCTION_CALLBACK Callback,PVOID Context,PCWSTR ಹೊರಹೋಗು_ದ_Process_Callback_Dll);
    BOOLEAN Rtl_Delete_Function_ಕೋಷ್ಟಕ(PRUNTIME_FUNCTION Function_ಕೋಷ್ಟಕ);
    VOID RtlRestoreContext (PCONTEXT Context_ದಾಖಲೆ,ರಚನೆ EXCEPTION_ದಾಖಲೆ *Exception_ದಾಖಲೆ);
    VOID __jump_unwind(ULONGLONG ಗುರಿ_Ms_ಚೌಕಟ್ಟು,ULONGLONG ಗುರಿ_Bs_ಚೌಕಟ್ಟು,ULONGLONG ಗುರಿ_Pc);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು EXCEPTION_NONCONTINUABLE 0x1
#ವ್ಯಾಖ್ಯಾನಿಸು EXCEPTION_ಗರಿಷ್ಠ_PARAMETERS 15

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ EXCEPTION_ದಾಖಲೆ {
      DWORD Exception_ಸಂಕೇತ;
      DWORD ExceptionFlags;
      ರಚನೆ EXCEPTION_ದಾಖಲೆ *Exception_ದಾಖಲೆ;
      PVOID Exception_ವಿಳಾಸ;
      DWORD ಸಂಖ್ಯೆ_Parameters;
      ULONG_PTR ExceptionInformation[EXCEPTION_ಗರಿಷ್ಠ_PARAMETERS];
    } EXCEPTION_ದಾಖಲೆ_2;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ EXCEPTION_ದಾಖಲೆ_2 *PEXCEPTION_ದಾಖಲೆ;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _EXCEPTION_RECORD32 {
      DWORD Exception_ಸಂಕೇತ;
      DWORD ExceptionFlags;
      DWORD Exception_ದಾಖಲೆ;
      DWORD Exception_ವಿಳಾಸ;
      DWORD ಸಂಖ್ಯೆ_Parameters;
      DWORD ExceptionInformation[EXCEPTION_ಗರಿಷ್ಠ_PARAMETERS];
    } EXCEPTION_RECORD32,*PEXCEPTION_RECORD32;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _EXCEPTION_RECORD64 {
      DWORD Exception_ಸಂಕೇತ;
      DWORD ExceptionFlags;
      DWORD64 Exception_ದಾಖಲೆ;
      DWORD64 Exception_ವಿಳಾಸ;
      DWORD ಸಂಖ್ಯೆ_Parameters;
      DWORD __unusedAlignment;
      DWORD64 ExceptionInformation[EXCEPTION_ಗರಿಷ್ಠ_PARAMETERS];
    } EXCEPTION_RECORD64,*PEXCEPTION_RECORD64;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ EXCEPTION_ಸೂಚಕಗಳು_2 {
      PEXCEPTION_ದಾಖಲೆ Exception_ದಾಖಲೆ;
      PCONTEXT Context_ದಾಖಲೆ;
    } EXCEPTION_ಸೂಚಕಗಳು,*PEXCEPTION_ಸೂಚಕಗಳು;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __x86_64

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ EXCEPTION_DISPOSITION NTAPI EXCEPTION_ROUTINE (ರಚನೆ EXCEPTION_ದಾಖಲೆ *Exception_ದಾಖಲೆ, PVOID Establisher_ಚೌಕಟ್ಟು_2, ರಚನೆ _CONTEXT *Context_ದಾಖಲೆ, PVOID DispatcherContext);
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __PEXCEPTION_ROUTINE_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು __PEXCEPTION_ROUTINE_DEFINED
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ EXCEPTION_ROUTINE *PEXCEPTION_ROUTINE;
#ಆದರೆ_ಅಂತ್ಯ

    /* http://msdn.microsoft.com/en-us/library/ms680597(VS.85).aspx */

#ವ್ಯಾಖ್ಯಾನಿಸು UNWIND_HISTORY_ಕೋಷ್ಟಕ_ಗಾತ್ರ 12

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ UNWIND_HISTORY_ಕೋಷ್ಟಕ_ನಮೂದು {
    ULONG64 Image_ತಳ;
    PRUNTIME_FUNCTION Function_ನಮೂದು;
  } UNWIND_HISTORY_ಕೋಷ್ಟಕ_ನಮೂದು_2, *PUNWIND_HISTORY_ಕೋಷ್ಟಕ_ನಮೂದು;

#ವ್ಯಾಖ್ಯಾನಿಸು UNWIND_HISTORY_ಕೋಷ್ಟಕ_NONE    0
#ವ್ಯಾಖ್ಯಾನಿಸು UNWIND_HISTORY_ಕೋಷ್ಟಕ_GLOBAL  1
#ವ್ಯಾಖ್ಯಾನಿಸು UNWIND_HISTORY_ಕೋಷ್ಟಕ_LOCAL   2

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ UNWIND_HISTORY_ಕೋಷ್ಟಕ {
    ULONG ಎಣಿಕೆ_4;
    UCHAR ಹುಡುಕು;
    ULONG64 ಕೆಳಗಿನ_ವಿಳಾಸ;
    ULONG64 ಮೇಲಿನ_ವಿಳಾಸ;
    UNWIND_HISTORY_ಕೋಷ್ಟಕ_ನಮೂದು_2 ನಮೂದು[UNWIND_HISTORY_ಕೋಷ್ಟಕ_ಗಾತ್ರ];
  } UNWIND_HISTORY_ಕೋಷ್ಟಕ_2, *PUNWIND_HISTORY_ಕೋಷ್ಟಕ;

  /* http://msdn.microsoft.com/en-us/library/b6sf5kbd(VS.80).aspx */

  ರಚನೆ _DISPATCHER_CONTEXT;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _DISPATCHER_CONTEXT DISPATCHER_CONTEXT;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _DISPATCHER_CONTEXT *PDISPATCHER_CONTEXT;

  ರಚನೆ _DISPATCHER_CONTEXT {
    ULONG64 ControlPc;
    ULONG64 Image_ತಳ;
    PRUNTIME_FUNCTION Function_ನಮೂದು;
    ULONG64 Establisher_ಚೌಕಟ್ಟು_2;
    ULONG64 ಗುರಿ_Ip;
    PCONTEXT Context_ದಾಖಲೆ;
    PEXCEPTION_ROUTINE LanguageHandler;
    PVOID Handler_ದತ್ತಾಂಶ;
    /* http://www.nynaeve.net/?p=99 */
    PUNWIND_HISTORY_ಕೋಷ್ಟಕ History_ಕೋಷ್ಟಕ;
    ULONG Scope_ಸೂಚ್ಯಂಕ;
    ULONG Fill0;
  };

  /* http://msdn.microsoft.com/en-us/library/ms680617(VS.85).aspx */

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ KNONVOLATILE_CONTEXT_ಸೂಚಕಗಳು
  {
    PM128A FloatingContext[16];
    PULONG64 IntegerContext[16];
  } KNONVOLATILE_CONTEXT_ಸೂಚಕಗಳು_2, *PKNONVOLATILE_CONTEXT_ಸೂಚಕಗಳು;
#ಆದರೆ_ಅಂತ್ಯ /* defined(__x86_64) */

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PVOID PACCESS_TOKEN;
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PVOID PSECURITY_DESCRIPTOR;
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PVOID PSID;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ DWORD ACCESS_ಮುಖವಾಡ;
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ACCESS_ಮುಖವಾಡ *PACCESS_ಮುಖವಾಡ;

#ವ್ಯಾಖ್ಯಾನಿಸು DELETE (0x00010000L)
#ವ್ಯಾಖ್ಯಾನಿಸು READ_CONTROL (0x00020000L)
#ವ್ಯಾಖ್ಯಾನಿಸು WRITE_DAC (0x00040000L)
#ವ್ಯಾಖ್ಯಾನಿಸು WRITE_OWNER (0x00080000L)
#ವ್ಯಾಖ್ಯಾನಿಸು SYNCHRONIZE (0x00100000L)

#ವ್ಯಾಖ್ಯಾನಿಸು STANDARD_RIGHTS_REQUIRED (0x000F0000L)
#ವ್ಯಾಖ್ಯಾನಿಸು STANDARD_RIGHTS_READ (READ_CONTROL)
#ವ್ಯಾಖ್ಯಾನಿಸು STANDARD_RIGHTS_WRITE (READ_CONTROL)
#ವ್ಯಾಖ್ಯಾನಿಸು STANDARD_RIGHTS_EXECUTE (READ_CONTROL)
#ವ್ಯಾಖ್ಯಾನಿಸು STANDARD_RIGHTS_ALL (0x001F0000L)

#ವ್ಯಾಖ್ಯಾನಿಸು SPECIFIC_RIGHTS_ALL (0x0000FFFFL)

#ವ್ಯಾಖ್ಯಾನಿಸು ACCESS_SYSTEM_SECURITY (0x01000000L)

#ವ್ಯಾಖ್ಯಾನಿಸು ಗರಿಷ್ಠ_ALLOWED (0x02000000L)

#ವ್ಯಾಖ್ಯಾನಿಸು GENERIC_READ (0x80000000L)
#ವ್ಯಾಖ್ಯಾನಿಸು GENERIC_WRITE (0x40000000L)
#ವ್ಯಾಖ್ಯಾನಿಸು GENERIC_EXECUTE (0x20000000L)
#ವ್ಯಾಖ್ಯಾನಿಸು GENERIC_ALL (0x10000000L)

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _GENERIC_MAPPING {
      ACCESS_ಮುಖವಾಡ GenericRead;
      ACCESS_ಮುಖವಾಡ GenericWrite;
      ACCESS_ಮುಖವಾಡ GenericExecute;
      ACCESS_ಮುಖವಾಡ GenericAll;
    } GENERIC_MAPPING;
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ GENERIC_MAPPING *PGENERIC_MAPPING;

#ಅನ್ತರ್ಭಾವ <pshpack4.h>

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ LUID_AND_ಗುಣಲಕ್ಷಣಗಳು {
      LUID Luid;
      DWORD ಗುಣಲಕ್ಷಣಗಳು;
    } LUID_AND_ಗುಣಲಕ್ಷಣಗಳು_2,*PLUID_AND_ಗುಣಲಕ್ಷಣಗಳು;
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LUID_AND_ಗುಣಲಕ್ಷಣಗಳು_2 LUID_AND_ಗುಣಲಕ್ಷಣಗಳು_ARRAY[ANYSIZE_ARRAY];
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LUID_AND_ಗುಣಲಕ್ಷಣಗಳು_ARRAY *PLUID_AND_ಗುಣಲಕ್ಷಣಗಳು_ARRAY;

#ಅನ್ತರ್ಭಾವ <poppack.h>

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ SID_IDENTIFIER_AUTHORITY_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು SID_IDENTIFIER_AUTHORITY_DEFINED
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _SID_IDENTIFIER_AUTHORITY {
      BYTE ಮೌಲ್ಯ_3[6];
    } SID_IDENTIFIER_AUTHORITY,*PSID_IDENTIFIER_AUTHORITY;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ SID_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು SID_DEFINED
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _SID {
      BYTE Revision;
      BYTE Sub_Authority_ಎಣಿಕೆ;
      SID_IDENTIFIER_AUTHORITY IdentifierAuthority;
      DWORD SubAuthority[ANYSIZE_ARRAY];
    } SID,*PISID;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು SID_REVISION (1)
#ವ್ಯಾಖ್ಯಾನಿಸು SID_MAX_SUB_AUTHORITIES (15)
#ವ್ಯಾಖ್ಯಾನಿಸು SID_RECOMMENDED_SUB_AUTHORITIES (1)

#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_MAX_SID_ಗಾತ್ರ (ಗಾತ್ರ(SID) - ಗಾತ್ರ(DWORD) + (SID_MAX_SUB_AUTHORITIES *ಗಾತ್ರ(DWORD)))

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಎಣಿಕೆ _SID_NAME_USE {
      SidTypeUser = 1,Sid_Type_ಗುಂಪು,SidTypeDomain,SidTypeAlias,Sid_Type_Well_ತಿಳಿದ_ಗುಂಪು,SidTypeDeletedAccount,SidTypeInvalid,SidTypeUnknown,SidTypeComputer
    } SID_NAME_USE,*PSID_NAME_USE;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ SID_AND_ಗುಣಲಕ್ಷಣಗಳು {
      PSID Sid;
      DWORD ಗುಣಲಕ್ಷಣಗಳು;
    } SID_AND_ಗುಣಲಕ್ಷಣಗಳು_2,*PSID_AND_ಗುಣಲಕ್ಷಣಗಳು;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ SID_AND_ಗುಣಲಕ್ಷಣಗಳು_2 SID_AND_ಗುಣಲಕ್ಷಣಗಳು_ARRAY[ANYSIZE_ARRAY];
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ SID_AND_ಗುಣಲಕ್ಷಣಗಳು_ARRAY *PSID_AND_ಗುಣಲಕ್ಷಣಗಳು_ARRAY;

#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_NULL_SID_AUTHORITY {0,0,0,0,0,0}
#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_WORLD_SID_AUTHORITY {0,0,0,0,0,1}
#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_LOCAL_SID_AUTHORITY {0,0,0,0,0,2}
#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_CREATOR_SID_AUTHORITY {0,0,0,0,0,3}
#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_NON_UNIQUE_AUTHORITY {0,0,0,0,0,4}
#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_RESOURCE_MANAGER_AUTHORITY {0,0,0,0,0,9}

#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_NULL_RID (0x00000000L)
#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_WORLD_RID (0x00000000L)
#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_LOCAL_RID (0x00000000L)

#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_CREATOR_OWNER_RID (0x00000000L)
#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_CREATOR_ಗುಂಪು_RID (0x00000001L)

#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_CREATOR_OWNER_SERVER_RID (0x00000002L)
#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_CREATOR_ಗುಂಪು_SERVER_RID (0x00000003L)

#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_NT_AUTHORITY {0,0,0,0,0,5}

#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_DIALUP_RID (0x00000001L)
#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_ಜಾಲ_RID (0x00000002L)
#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_BATCH_RID (0x00000003L)
#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_INTERACTIVE_RID (0x00000004L)
#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_LOGON_IDS_RID (0x00000005L)
#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_LOGON_IDS_RID_ಎಣಿಕೆ (3L)
#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_SERVICE_RID (0x00000006L)
#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_ANONYMOUS_LOGON_RID (0x00000007L)
#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_PROXY_RID (0x00000008L)
#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_ENTERPRISE_CONTROLLERS_RID (0x00000009L)
#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_SERVER_LOGON_RID SECURITY_ENTERPRISE_CONTROLLERS_RID
#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_PRINCIPAL_SELF_RID (0x0000000AL)
#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_AUTHENTICATED_USER_RID (0x0000000BL)
#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_RESTRICTED_ಸಂಕೇತ_RID (0x0000000CL)
#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_TERMINAL_SERVER_RID (0x0000000DL)
#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_REMOTE_LOGON_RID (0x0000000EL)
#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_THIS_ORGANIZATION_RID (0x0000000FL)
#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_IUSER_RID (0x00000011L)

#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_LOCAL_SYSTEM_RID (0x00000012L)
#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_LOCAL_SERVICE_RID (0x00000013L)
#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_ಜಾಲ_SERVICE_RID (0x00000014L)

#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_NT_NON_UNIQUE (0x00000015L)
#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_NT_NON_UNIQUE_SUB_AUTH_ಎಣಿಕೆ (3L)

#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_ENTERPRISE_READONLY_CONTROLLERS_RID (0x00000016L)

#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_BUILTIN_DOMAIN_RID (0x00000020L)
#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_WRITE_RESTRICTED_ಸಂಕೇತ_RID (0x00000021L)

#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_PACKAGE_ತಳ_RID (0x00000040L)
#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_PACKAGE_RID_ಎಣಿಕೆ (2L)
#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_PACKAGE_NTLM_RID (0x0000000AL)
#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_PACKAGE_SCHANNEL_RID (0x0000000EL)
#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_PACKAGE_DIGEST_RID (0x00000015L)

#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_SERVICE_ID_ತಳ_RID (0x00000050L)
#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_SERVICE_ID_RID_ಎಣಿಕೆ (6L)

#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_RESERVED_ID_ತಳ_RID (0x00000051L)

#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_MAX_ALWAYS_FILTERED (0x000003E7L)
#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_MIN_NEVER_FILTERED (0x000003E8L)

#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_OTHER_ORGANIZATION_RID (0x000003E8L)

#ವ್ಯಾಖ್ಯಾನಿಸು FOREST_USER_RID_MAX (0x000001F3L)

#ವ್ಯಾಖ್ಯಾನಿಸು DOMAIN_USER_RID_ADMIN (0x000001F4L)
#ವ್ಯಾಖ್ಯಾನಿಸು DOMAIN_USER_RID_GUEST (0x000001F5L)
#ವ್ಯಾಖ್ಯಾನಿಸು DOMAIN_USER_RID_KRBTGT (0x000001F6L)

#ವ್ಯಾಖ್ಯಾನಿಸು DOMAIN_USER_RID_MAX (0x000003E7L)

#ವ್ಯಾಖ್ಯಾನಿಸು DOMAIN_ಗುಂಪು_RID_ADMINS (0x00000200L)
#ವ್ಯಾಖ್ಯಾನಿಸು DOMAIN_ಗುಂಪು_RID_USERS (0x00000201L)
#ವ್ಯಾಖ್ಯಾನಿಸು DOMAIN_ಗುಂಪು_RID_GUESTS (0x00000202L)
#ವ್ಯಾಖ್ಯಾನಿಸು DOMAIN_ಗುಂಪು_RID_COMPUTERS (0x00000203L)
#ವ್ಯಾಖ್ಯಾನಿಸು DOMAIN_ಗುಂಪು_RID_CONTROLLERS (0x00000204L)
#ವ್ಯಾಖ್ಯಾನಿಸು DOMAIN_ಗುಂಪು_RID_CERT_ADMINS (0x00000205L)
#ವ್ಯಾಖ್ಯಾನಿಸು DOMAIN_ಗುಂಪು_RID_SCHEMA_ADMINS (0x00000206L)
#ವ್ಯಾಖ್ಯಾನಿಸು DOMAIN_ಗುಂಪು_RID_ENTERPRISE_ADMINS (0x00000207L)
#ವ್ಯಾಖ್ಯಾನಿಸು DOMAIN_ಗುಂಪು_RID_POLICY_ADMINS (0x00000208L)
#ವ್ಯಾಖ್ಯಾನಿಸು DOMAIN_ಗುಂಪು_RID_READONLY_CONTROLLERS (0x00000209L)

#ವ್ಯಾಖ್ಯಾನಿಸು DOMAIN_ALIAS_RID_ADMINS (0x00000220L)
#ವ್ಯಾಖ್ಯಾನಿಸು DOMAIN_ALIAS_RID_USERS (0x00000221L)
#ವ್ಯಾಖ್ಯಾನಿಸು DOMAIN_ALIAS_RID_GUESTS (0x00000222L)
#ವ್ಯಾಖ್ಯಾನಿಸು DOMAIN_ALIAS_RID_POWER_USERS (0x00000223L)

#ವ್ಯಾಖ್ಯಾನಿಸು DOMAIN_ALIAS_RID_ACCOUNT_OPS (0x00000224L)
#ವ್ಯಾಖ್ಯಾನಿಸು DOMAIN_ALIAS_RID_SYSTEM_OPS (0x00000225L)
#ವ್ಯಾಖ್ಯಾನಿಸು DOMAIN_ALIAS_RID_PRINT_OPS (0x00000226L)
#ವ್ಯಾಖ್ಯಾನಿಸು DOMAIN_ALIAS_RID_BACKUP_OPS (0x00000227L)

#ವ್ಯಾಖ್ಯಾನಿಸು DOMAIN_ALIAS_RID_REPLICATOR (0x00000228L)
#ವ್ಯಾಖ್ಯಾನಿಸು DOMAIN_ALIAS_RID_RAS_SERVERS (0x00000229L)
#ವ್ಯಾಖ್ಯಾನಿಸು DOMAIN_ALIAS_RID_PREW2KCOMPACCESS (0x0000022AL)
#ವ್ಯಾಖ್ಯಾನಿಸು DOMAIN_ALIAS_RID_REMOTE_DESKTOP_USERS (0x0000022BL)
#ವ್ಯಾಖ್ಯಾನಿಸು DOMAIN_ALIAS_RID_ಜಾಲ_CONFIGURATION_OPS (0x0000022CL)
#ವ್ಯಾಖ್ಯಾನಿಸು DOMAIN_ALIAS_RID_INCOMING_FOREST_TRUST_BUILDERS (0x0000022DL)

#ವ್ಯಾಖ್ಯಾನಿಸು DOMAIN_ALIAS_RID_MONITORING_USERS (0x0000022EL)
#ವ್ಯಾಖ್ಯಾನಿಸು DOMAIN_ALIAS_RID_LOGGING_USERS (0x0000022FL)
#ವ್ಯಾಖ್ಯಾನಿಸು DOMAIN_ALIAS_RID_AUTHORIZATIONACCESS (0x00000230L)
#ವ್ಯಾಖ್ಯಾನಿಸು DOMAIN_ALIAS_RID_TS_LICENSE_SERVERS (0x00000231L)
#ವ್ಯಾಖ್ಯಾನಿಸು DOMAIN_ALIAS_RID_DCOM_USERS (0x00000232L)

#ವ್ಯಾಖ್ಯಾನಿಸು DOMAIN_ALIAS_RID_IUSERS (0x00000238L)
#ವ್ಯಾಖ್ಯಾನಿಸು DOMAIN_ALIAS_RID_CRYPTO_OPERATORS (0x00000239L)
#ವ್ಯಾಖ್ಯಾನಿಸು DOMAIN_ALIAS_RID_CACHEABLE_PRINCIPALS_ಗುಂಪು (0x0000023BL)
#ವ್ಯಾಖ್ಯಾನಿಸು DOMAIN_ALIAS_RID_NON_CACHEABLE_PRINCIPALS_ಗುಂಪು (0x0000023CL)
#ವ್ಯಾಖ್ಯಾನಿಸು DOMAIN_ALIAS_RID_EVENT_LOG_READERS_ಗುಂಪು (0x0000023DL)

#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_MANDATORY_LABEL_AUTHORITY {0,0,0,0,0,16}
#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_MANDATORY_UNTRUSTED_RID (0x00000000L)
#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_MANDATORY_ಕೆಳಗಿನ_RID (0x00001000L)
#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_MANDATORY_MEDIUM_RID (0x00002000L)
#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_MANDATORY_ಮೇಲಿನ_RID (0x00003000L)
#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_MANDATORY_SYSTEM_RID (0x00004000L)
#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_MANDATORY_PROTECTED_PROCESS_RID (0x00005000L)

#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_MANDATORY_ಗರಿಷ್ಠ_USER_RID SECURITY_MANDATORY_SYSTEM_RID

#ವ್ಯಾಖ್ಯಾನಿಸು MANDATORY_LEVEL_ಗಮ್ಯ_MANDATORY_RID(IL) (IL * 0x1000)

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಎಣಿಕೆ {
      WinNullSid = 0,WinWorldSid = 1,WinLocalSid = 2,WinCreatorOwnerSid = 3,Win_Creator_ಗುಂಪು_Sid = 4,WinCreatorOwnerServerSid = 5,Win_Creator_ಗುಂಪು_Server_Sid = 6,WinNtAuthoritySid = 7,WinDialupSid = 8,Win_ಜಾಲ_Sid = 9,WinBatchSid = 10,WinInteractiveSid = 11,WinServiceSid = 12,WinAnonymousSid = 13,WinProxySid = 14,WinEnterpriseControllersSid = 15,WinSelfSid = 16,WinAuthenticatedUserSid = 17,Win_Restricted_ಸಂಕೇತ_Sid = 18,WinTerminalServerSid = 19,WinRemoteLogonIdSid = 20,WinLogonIdsSid = 21,WinLocalSystemSid = 22,WinLocalServiceSid = 23,Win_ಜಾಲ_Service_Sid = 24,WinBuiltinDomainSid = 25,WinBuiltinAdministratorsSid = 26,WinBuiltinUsersSid = 27,WinBuiltinGuestsSid = 28,WinBuiltinPowerUsersSid = 29,WinBuiltinAccountOperatorsSid = 30,WinBuiltinSystemOperatorsSid = 31,WinBuiltinPrintOperatorsSid = 32,WinBuiltinBackupOperatorsSid = 33,WinBuiltinReplicatorSid = 34,WinBuiltinPreWindows2000CompatibleAccessSid = 35,WinBuiltinRemoteDesktopUsersSid = 36,Win_Builtin_ಜಾಲ_Configuration_Operators_Sid = 37,WinAccountAdministratorSid = 38,WinAccountGuestSid = 39,WinAccountKrbtgtSid = 40,WinAccountDomainAdminsSid = 41,WinAccountDomainUsersSid = 42,WinAccountDomainGuestsSid = 43,WinAccountComputersSid = 44,WinAccountControllersSid = 45,WinAccountCertAdminsSid = 46,WinAccountSchemaAdminsSid = 47,WinAccountEnterpriseAdminsSid = 48,WinAccountPolicyAdminsSid = 49,WinAccountRasAndIasServersSid = 50,WinNTLMAuthenticationSid = 51,WinDigestAuthenticationSid = 52,WinSChannelAuthenticationSid = 53,WinThisOrganizationSid = 54,WinOtherOrganizationSid = 55,WinBuiltinIncomingForestTrustBuildersSid = 56,WinBuiltinPerfMonitoringUsersSid = 57,WinBuiltinPerfLoggingUsersSid = 58,WinBuiltinAuthorizationAccessSid = 59,WinBuiltinTerminalServerLicenseServersSid = 60,WinBuiltinDCOMUsersSid = 61
    } WELL_ತಿಳಿದ_SID_TYPE;

#ವ್ಯಾಖ್ಯಾನಿಸು SYSTEM_LUID { 0x3E7,0x0 }
#ವ್ಯಾಖ್ಯಾನಿಸು ANONYMOUS_LOGON_LUID { 0x3e6,0x0 }
#ವ್ಯಾಖ್ಯಾನಿಸು LOCALSERVICE_LUID { 0x3e5,0x0 }
#ವ್ಯಾಖ್ಯಾನಿಸು NETWORKSERVICE_LUID { 0x3e4,0x0 }
#ವ್ಯಾಖ್ಯಾನಿಸು IUSER_LUID { 0x3e3, 0x0 }

#ವ್ಯಾಖ್ಯಾನಿಸು SE_ಗುಂಪು_MANDATORY (0x00000001L)
#ವ್ಯಾಖ್ಯಾನಿಸು SE_ಗುಂಪು_ENABLED_BY_DEFAULT (0x00000002L)
#ವ್ಯಾಖ್ಯಾನಿಸು SE_ಗುಂಪು_ENABLED (0x00000004L)
#ವ್ಯಾಖ್ಯಾನಿಸು SE_ಗುಂಪು_OWNER (0x00000008L)
#ವ್ಯಾಖ್ಯಾನಿಸು SE_ಗುಂಪು_USE_FOR_DENY_ONLY (0x00000010L)
#ವ್ಯಾಖ್ಯಾನಿಸು SE_ಗುಂಪು_INTEGRITY (0x00000020L)
#ವ್ಯಾಖ್ಯಾನಿಸು SE_ಗುಂಪು_INTEGRITY_ENABLED (0x00000040L)
#ವ್ಯಾಖ್ಯಾನಿಸು SE_ಗುಂಪು_LOGON_ID (0xC0000000L)
#ವ್ಯಾಖ್ಯಾನಿಸು SE_ಗುಂಪು_RESOURCE (0x20000000L)

#ವ್ಯಾಖ್ಯಾನಿಸು ACL_REVISION (2)
#ವ್ಯಾಖ್ಯಾನಿಸು ACL_REVISION_DS (4)

#ವ್ಯಾಖ್ಯಾನಿಸು ACL_REVISION1 (1)
#ವ್ಯಾಖ್ಯಾನಿಸು MIN_ACL_REVISION ACL_REVISION2
#ವ್ಯಾಖ್ಯಾನಿಸು ACL_REVISION2 (2)
#ವ್ಯಾಖ್ಯಾನಿಸು ACL_REVISION3 (3)
#ವ್ಯಾಖ್ಯಾನಿಸು ACL_REVISION4 (4)
#ವ್ಯಾಖ್ಯಾನಿಸು MAX_ACL_REVISION ACL_REVISION4

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _ACL {
      BYTE AclRevision;
      BYTE Sbz1;
      ಶಬ್ದ_3 Acl_ಗಾತ್ರ;
      ಶಬ್ದ_3 Ace_ಎಣಿಕೆ;
      ಶಬ್ದ_3 Sbz2;
    } ACL;
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ACL *PACL;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ACE_ಶೀರ್ಷಿಕೆ {
      BYTE AceType;
      BYTE AceFlags;
      ಶಬ್ದ_3 Ace_ಗಾತ್ರ;
    } ACE_ಶೀರ್ಷಿಕೆ_2;
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ACE_ಶೀರ್ಷಿಕೆ_2 *PACE_ಶೀರ್ಷಿಕೆ;

#ವ್ಯಾಖ್ಯಾನಿಸು ACCESS_MIN_MS_ACE_TYPE (0x0)
#ವ್ಯಾಖ್ಯಾನಿಸು ACCESS_ALLOWED_ACE_TYPE (0x0)
#ವ್ಯಾಖ್ಯಾನಿಸು ACCESS_DENIED_ACE_TYPE (0x1)
#ವ್ಯಾಖ್ಯಾನಿಸು SYSTEM_AUDIT_ACE_TYPE (0x2)
#ವ್ಯಾಖ್ಯಾನಿಸು SYSTEM_ALARM_ACE_TYPE (0x3)
#ವ್ಯಾಖ್ಯಾನಿಸು ACCESS_MAX_MS_V2_ACE_TYPE (0x3)

#ವ್ಯಾಖ್ಯಾನಿಸು ACCESS_ALLOWED_COMPOUND_ACE_TYPE (0x4)
#ವ್ಯಾಖ್ಯಾನಿಸು ACCESS_MAX_MS_V3_ACE_TYPE (0x4)

#ವ್ಯಾಖ್ಯಾನಿಸು ACCESS_MIN_MS_OBJECT_ACE_TYPE (0x5)
#ವ್ಯಾಖ್ಯಾನಿಸು ACCESS_ALLOWED_OBJECT_ACE_TYPE (0x5)
#ವ್ಯಾಖ್ಯಾನಿಸು ACCESS_DENIED_OBJECT_ACE_TYPE (0x6)
#ವ್ಯಾಖ್ಯಾನಿಸು SYSTEM_AUDIT_OBJECT_ACE_TYPE (0x7)
#ವ್ಯಾಖ್ಯಾನಿಸು SYSTEM_ALARM_OBJECT_ACE_TYPE (0x8)
#ವ್ಯಾಖ್ಯಾನಿಸು ACCESS_MAX_MS_OBJECT_ACE_TYPE (0x8)

#ವ್ಯಾಖ್ಯಾನಿಸು ACCESS_MAX_MS_V4_ACE_TYPE (0x8)
#ವ್ಯಾಖ್ಯಾನಿಸು ACCESS_MAX_MS_ACE_TYPE (0x8)

#ವ್ಯಾಖ್ಯಾನಿಸು ACCESS_ALLOWED_CALLBACK_ACE_TYPE (0x9)
#ವ್ಯಾಖ್ಯಾನಿಸು ACCESS_DENIED_CALLBACK_ACE_TYPE (0xA)
#ವ್ಯಾಖ್ಯಾನಿಸು ACCESS_ALLOWED_CALLBACK_OBJECT_ACE_TYPE (0xB)
#ವ್ಯಾಖ್ಯಾನಿಸು ACCESS_DENIED_CALLBACK_OBJECT_ACE_TYPE (0xC)
#ವ್ಯಾಖ್ಯಾನಿಸು SYSTEM_AUDIT_CALLBACK_ACE_TYPE (0xD)
#ವ್ಯಾಖ್ಯಾನಿಸು SYSTEM_ALARM_CALLBACK_ACE_TYPE (0xE)
#ವ್ಯಾಖ್ಯಾನಿಸು SYSTEM_AUDIT_CALLBACK_OBJECT_ACE_TYPE (0xF)
#ವ್ಯಾಖ್ಯಾನಿಸು SYSTEM_ALARM_CALLBACK_OBJECT_ACE_TYPE (0x10)

#ವ್ಯಾಖ್ಯಾನಿಸು SYSTEM_MANDATORY_LABEL_ACE_TYPE (0x11)
#ವ್ಯಾಖ್ಯಾನಿಸು ACCESS_MAX_MS_V5_ACE_TYPE (0x11)

#ವ್ಯಾಖ್ಯಾನಿಸು OBJECT_INHERIT_ACE (0x1)
#ವ್ಯಾಖ್ಯಾನಿಸು CONTAINER_INHERIT_ACE (0x2)
#ವ್ಯಾಖ್ಯಾನಿಸು NO_PROPAGATE_INHERIT_ACE (0x4)
#ವ್ಯಾಖ್ಯಾನಿಸು INHERIT_ONLY_ACE (0x8)
#ವ್ಯಾಖ್ಯಾನಿಸು INHERITED_ACE (0x10)
#ವ್ಯಾಖ್ಯಾನಿಸು VALID_INHERIT_FLAGS (0x1F)

#ವ್ಯಾಖ್ಯಾನಿಸು SUCCESSFUL_ACCESS_ACE_FLAG (0x40)
#ವ್ಯಾಖ್ಯಾನಿಸು FAILED_ACCESS_ACE_FLAG (0x80)

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _ACCESS_ALLOWED_ACE {
      ACE_ಶೀರ್ಷಿಕೆ_2 ಶೀರ್ಷಿಕೆ_2;
      ACCESS_ಮುಖವಾಡ ಮುಖವಾಡ_3;
      DWORD Sid_ಆರಂಭ;
    } ACCESS_ALLOWED_ACE;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ACCESS_ALLOWED_ACE *PACCESS_ALLOWED_ACE;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _ACCESS_DENIED_ACE {
      ACE_ಶೀರ್ಷಿಕೆ_2 ಶೀರ್ಷಿಕೆ_2;
      ACCESS_ಮುಖವಾಡ ಮುಖವಾಡ_3;
      DWORD Sid_ಆರಂಭ;
    } ACCESS_DENIED_ACE;
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ACCESS_DENIED_ACE *PACCESS_DENIED_ACE;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _SYSTEM_AUDIT_ACE {
      ACE_ಶೀರ್ಷಿಕೆ_2 ಶೀರ್ಷಿಕೆ_2;
      ACCESS_ಮುಖವಾಡ ಮುಖವಾಡ_3;
      DWORD Sid_ಆರಂಭ;
    } SYSTEM_AUDIT_ACE;
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ SYSTEM_AUDIT_ACE *PSYSTEM_AUDIT_ACE;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _SYSTEM_ALARM_ACE {
      ACE_ಶೀರ್ಷಿಕೆ_2 ಶೀರ್ಷಿಕೆ_2;
      ACCESS_ಮುಖವಾಡ ಮುಖವಾಡ_3;
      DWORD Sid_ಆರಂಭ;
    } SYSTEM_ALARM_ACE;
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ SYSTEM_ALARM_ACE *PSYSTEM_ALARM_ACE;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _ACCESS_ALLOWED_OBJECT_ACE {
      ACE_ಶೀರ್ಷಿಕೆ_2 ಶೀರ್ಷಿಕೆ_2;
      ACCESS_ಮುಖವಾಡ ಮುಖವಾಡ_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_ಆರಂಭ;
    } ACCESS_ALLOWED_OBJECT_ACE,*PACCESS_ALLOWED_OBJECT_ACE;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _ACCESS_DENIED_OBJECT_ACE {
      ACE_ಶೀರ್ಷಿಕೆ_2 ಶೀರ್ಷಿಕೆ_2;
      ACCESS_ಮುಖವಾಡ ಮುಖವಾಡ_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_ಆರಂಭ;
    } ACCESS_DENIED_OBJECT_ACE,*PACCESS_DENIED_OBJECT_ACE;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _SYSTEM_AUDIT_OBJECT_ACE {
      ACE_ಶೀರ್ಷಿಕೆ_2 ಶೀರ್ಷಿಕೆ_2;
      ACCESS_ಮುಖವಾಡ ಮುಖವಾಡ_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_ಆರಂಭ;
    } SYSTEM_AUDIT_OBJECT_ACE,*PSYSTEM_AUDIT_OBJECT_ACE;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _SYSTEM_ALARM_OBJECT_ACE {
      ACE_ಶೀರ್ಷಿಕೆ_2 ಶೀರ್ಷಿಕೆ_2;
      ACCESS_ಮುಖವಾಡ ಮುಖವಾಡ_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_ಆರಂಭ;
    } SYSTEM_ALARM_OBJECT_ACE,*PSYSTEM_ALARM_OBJECT_ACE;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _ACCESS_ALLOWED_CALLBACK_ACE {
      ACE_ಶೀರ್ಷಿಕೆ_2 ಶೀರ್ಷಿಕೆ_2;
      ACCESS_ಮುಖವಾಡ ಮುಖವಾಡ_3;
      DWORD Sid_ಆರಂಭ;

    } ACCESS_ALLOWED_CALLBACK_ACE,*PACCESS_ALLOWED_CALLBACK_ACE;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _ACCESS_DENIED_CALLBACK_ACE {
      ACE_ಶೀರ್ಷಿಕೆ_2 ಶೀರ್ಷಿಕೆ_2;
      ACCESS_ಮುಖವಾಡ ಮುಖವಾಡ_3;
      DWORD Sid_ಆರಂಭ;

    } ACCESS_DENIED_CALLBACK_ACE,*PACCESS_DENIED_CALLBACK_ACE;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _SYSTEM_AUDIT_CALLBACK_ACE {
      ACE_ಶೀರ್ಷಿಕೆ_2 ಶೀರ್ಷಿಕೆ_2;
      ACCESS_ಮುಖವಾಡ ಮುಖವಾಡ_3;
      DWORD Sid_ಆರಂಭ;

    } SYSTEM_AUDIT_CALLBACK_ACE,*PSYSTEM_AUDIT_CALLBACK_ACE;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _SYSTEM_ALARM_CALLBACK_ACE {
      ACE_ಶೀರ್ಷಿಕೆ_2 ಶೀರ್ಷಿಕೆ_2;
      ACCESS_ಮುಖವಾಡ ಮುಖವಾಡ_3;
      DWORD Sid_ಆರಂಭ;

    } SYSTEM_ALARM_CALLBACK_ACE,*PSYSTEM_ALARM_CALLBACK_ACE;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _ACCESS_ALLOWED_CALLBACK_OBJECT_ACE {
      ACE_ಶೀರ್ಷಿಕೆ_2 ಶೀರ್ಷಿಕೆ_2;
      ACCESS_ಮುಖವಾಡ ಮುಖವಾಡ_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_ಆರಂಭ;

    } ACCESS_ALLOWED_CALLBACK_OBJECT_ACE,*PACCESS_ALLOWED_CALLBACK_OBJECT_ACE;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _ACCESS_DENIED_CALLBACK_OBJECT_ACE {
      ACE_ಶೀರ್ಷಿಕೆ_2 ಶೀರ್ಷಿಕೆ_2;
      ACCESS_ಮುಖವಾಡ ಮುಖವಾಡ_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_ಆರಂಭ;

    } ACCESS_DENIED_CALLBACK_OBJECT_ACE,*PACCESS_DENIED_CALLBACK_OBJECT_ACE;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _SYSTEM_AUDIT_CALLBACK_OBJECT_ACE {
      ACE_ಶೀರ್ಷಿಕೆ_2 ಶೀರ್ಷಿಕೆ_2;
      ACCESS_ಮುಖವಾಡ ಮುಖವಾಡ_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_ಆರಂಭ;

    } SYSTEM_AUDIT_CALLBACK_OBJECT_ACE,*PSYSTEM_AUDIT_CALLBACK_OBJECT_ACE;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _SYSTEM_ALARM_CALLBACK_OBJECT_ACE {
      ACE_ಶೀರ್ಷಿಕೆ_2 ಶೀರ್ಷಿಕೆ_2;
      ACCESS_ಮುಖವಾಡ ಮುಖವಾಡ_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_ಆರಂಭ;

    } SYSTEM_ALARM_CALLBACK_OBJECT_ACE,*PSYSTEM_ALARM_CALLBACK_OBJECT_ACE;

#ವ್ಯಾಖ್ಯಾನಿಸು ACE_OBJECT_TYPE_PRESENT 0x1
#ವ್ಯಾಖ್ಯಾನಿಸು ACE_INHERITED_OBJECT_TYPE_PRESENT 0x2

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಎಣಿಕೆ _ACL_INFORMATION_CLASS {
      AclRevisionInformation = 1,Acl_ಗಾತ್ರ_Information
    } ACL_INFORMATION_CLASS;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _ACL_REVISION_INFORMATION {
      DWORD AclRevision;
    } ACL_REVISION_INFORMATION;
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ACL_REVISION_INFORMATION *PACL_REVISION_INFORMATION;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ACL_ಗಾತ್ರ_INFORMATION {
      DWORD Ace_ಎಣಿಕೆ;
      DWORD Acl_ಬೈಟುಗಳು_ಒಳ_Use;
      DWORD Acl_ಬೈಟುಗಳು_Free;
    } ACL_ಗಾತ್ರ_INFORMATION_2;
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ACL_ಗಾತ್ರ_INFORMATION_2 *PACL_ಗಾತ್ರ_INFORMATION;

#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_DESCRIPTOR_REVISION (1)
#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_DESCRIPTOR_REVISION1 (1)

#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_DESCRIPTOR_MIN_ಉದ್ದಳತೆ (ಗಾತ್ರ(SECURITY_DESCRIPTOR))

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಶಬ್ದ_3 SECURITY_DESCRIPTOR_CONTROL,*PSECURITY_DESCRIPTOR_CONTROL;

#ವ್ಯಾಖ್ಯಾನಿಸು SE_OWNER_DEFAULTED (0x0001)
#ವ್ಯಾಖ್ಯಾನಿಸು SE_ಗುಂಪು_DEFAULTED (0x0002)
#ವ್ಯಾಖ್ಯಾನಿಸು SE_DACL_PRESENT (0x0004)
#ವ್ಯಾಖ್ಯಾನಿಸು SE_DACL_DEFAULTED (0x0008)
#ವ್ಯಾಖ್ಯಾನಿಸು SE_SACL_PRESENT (0x0010)
#ವ್ಯಾಖ್ಯಾನಿಸು SE_SACL_DEFAULTED (0x0020)
#ವ್ಯಾಖ್ಯಾನಿಸು SE_DACL_AUTO_INHERIT_REQ (0x0100)
#ವ್ಯಾಖ್ಯಾನಿಸು SE_SACL_AUTO_INHERIT_REQ (0x0200)
#ವ್ಯಾಖ್ಯಾನಿಸು SE_DACL_AUTO_INHERITED (0x0400)
#ವ್ಯಾಖ್ಯಾನಿಸು SE_SACL_AUTO_INHERITED (0x0800)
#ವ್ಯಾಖ್ಯಾನಿಸು SE_DACL_PROTECTED (0x1000)
#ವ್ಯಾಖ್ಯಾನಿಸು SE_SACL_PROTECTED (0x2000)
#ವ್ಯಾಖ್ಯಾನಿಸು SE_RM_CONTROL_VALID (0x4000)
#ವ್ಯಾಖ್ಯಾನಿಸು SE_SELF_RELATIVE (0x8000)

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _SECURITY_DESCRIPTOR_RELATIVE {
      BYTE Revision;
      BYTE Sbz1;
      SECURITY_DESCRIPTOR_CONTROL Control;
      DWORD Owner;
      DWORD ಗುಂಪು_2;
      DWORD Sacl;
      DWORD Dacl;
    } SECURITY_DESCRIPTOR_RELATIVE,*PISECURITY_DESCRIPTOR_RELATIVE;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _SECURITY_DESCRIPTOR {
      BYTE Revision;
      BYTE Sbz1;
      SECURITY_DESCRIPTOR_CONTROL Control;
      PSID Owner;
      PSID ಗುಂಪು_2;
      PACL Sacl;
      PACL Dacl;

    } SECURITY_DESCRIPTOR,*PISECURITY_DESCRIPTOR;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _OBJECT_TYPE_LIST {
      ಶಬ್ದ_3 Level;
      ಶಬ್ದ_3 Sbz;
      GUID *ObjectType;
    } OBJECT_TYPE_LIST,*POBJECT_TYPE_LIST;

#ವ್ಯಾಖ್ಯಾನಿಸು ACCESS_OBJECT_GUID 0
#ವ್ಯಾಖ್ಯಾನಿಸು ACCESS_PROPERTY_ಗಣ_GUID 1
#ವ್ಯಾಖ್ಯಾನಿಸು ACCESS_PROPERTY_GUID 2

#ವ್ಯಾಖ್ಯಾನಿಸು ACCESS_MAX_LEVEL 4

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಎಣಿಕೆ _AUDIT_EVENT_TYPE {
      AuditEventObjectAccess,AuditEventDirectoryServiceAccess
    } AUDIT_EVENT_TYPE,*PAUDIT_EVENT_TYPE;

#ವ್ಯಾಖ್ಯಾನಿಸು AUDIT_ALLOW_NO_PRIVILEGE 0x1

#ವ್ಯಾಖ್ಯಾನಿಸು ACCESS_DS_ಮೂಲ_A "DS"
#ವ್ಯಾಖ್ಯಾನಿಸು ACCESS_DS_ಮೂಲ_W L"DS"
#ವ್ಯಾಖ್ಯಾನಿಸು ACCESS_DS_OBJECT_TYPE_NAME_A "Directory Service Object"
#ವ್ಯಾಖ್ಯಾನಿಸು ACCESS_DS_OBJECT_TYPE_NAME_W L"Directory Service Object"

#ವ್ಯಾಖ್ಯಾನಿಸು SE_PRIVILEGE_ENABLED_BY_DEFAULT (0x00000001L)
#ವ್ಯಾಖ್ಯಾನಿಸು SE_PRIVILEGE_ENABLED (0x00000002L)
#ವ್ಯಾಖ್ಯಾನಿಸು SE_PRIVILEGE_REMOVED (0X00000004L)
#ವ್ಯಾಖ್ಯಾನಿಸು SE_PRIVILEGE_ಬಳಸಿದ_FOR_ACCESS (0x80000000L)

#ವ್ಯಾಖ್ಯಾನಿಸು PRIVILEGE_ಗಣ_ALL_NECESSARY (1)

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ PRIVILEGE_ಗಣ {
      DWORD Privilege_ಎಣಿಕೆ;
      DWORD Control;
      LUID_AND_ಗುಣಲಕ್ಷಣಗಳು_2 Privilege[ANYSIZE_ARRAY];
    } PRIVILEGE_ಗಣ_2,*PPRIVILEGE_ಗಣ;

#ವ್ಯಾಖ್ಯಾನಿಸು SE_CREATE_TOKEN_NAME ಪಠ್ಯ_3("SeCreateTokenPrivilege")
#ವ್ಯಾಖ್ಯಾನಿಸು SE_ASSIGNPRIMARYTOKEN_NAME ಪಠ್ಯ_3("SeAssignPrimaryTokenPrivilege")
#ವ್ಯಾಖ್ಯಾನಿಸು SE_ಬೀಗ_ಸ್ಮರಣೆ_NAME ಪಠ್ಯ_3("SeLockMemoryPrivilege")
#ವ್ಯಾಖ್ಯಾನಿಸು SE_INCREASE_QUOTA_NAME ಪಠ್ಯ_3("SeIncreaseQuotaPrivilege")
#ವ್ಯಾಖ್ಯಾನಿಸು SE_UNSOLICITED_ಒಳಹರಿವು_NAME ಪಠ್ಯ_3("SeUnsolicitedInputPrivilege")
#ವ್ಯಾಖ್ಯಾನಿಸು SE_MACHINE_ACCOUNT_NAME ಪಠ್ಯ_3("SeMachineAccountPrivilege")
#ವ್ಯಾಖ್ಯಾನಿಸು SE_TCB_NAME ಪಠ್ಯ_3("SeTcbPrivilege")
#ವ್ಯಾಖ್ಯಾನಿಸು SE_SECURITY_NAME ಪಠ್ಯ_3("SeSecurityPrivilege")
#ವ್ಯಾಖ್ಯಾನಿಸು SE_TAKE_OWNERSHIP_NAME ಪಠ್ಯ_3("SeTakeOwnershipPrivilege")
#ವ್ಯಾಖ್ಯಾನಿಸು SE_ತುಂಬು_DRIVER_NAME ಪಠ್ಯ_3("SeLoadDriverPrivilege")
#ವ್ಯಾಖ್ಯಾನಿಸು SE_SYSTEM_PROFILE_NAME ಪಠ್ಯ_3("SeSystemProfilePrivilege")
#ವ್ಯಾಖ್ಯಾನಿಸು SE_SYSTEMTIME_NAME ಪಠ್ಯ_3("SeSystemtimePrivilege")
#ವ್ಯಾಖ್ಯಾನಿಸು SE_PROF_SINGLE_PROCESS_NAME ಪಠ್ಯ_3("SeProfileSingleProcessPrivilege")
#ವ್ಯಾಖ್ಯಾನಿಸು SE_INC_ತಳ_ಆದ್ಯತೆ_NAME ಪಠ್ಯ_3("SeIncreaseBasePriorityPrivilege")
#ವ್ಯಾಖ್ಯಾನಿಸು SE_CREATE_PAGEFILE_NAME ಪಠ್ಯ_3("SeCreatePagefilePrivilege")
#ವ್ಯಾಖ್ಯಾನಿಸು SE_CREATE_PERMANENT_NAME ಪಠ್ಯ_3("SeCreatePermanentPrivilege")
#ವ್ಯಾಖ್ಯಾನಿಸು SE_BACKUP_NAME ಪಠ್ಯ_3("SeBackupPrivilege")
#ವ್ಯಾಖ್ಯಾನಿಸು SE_RESTORE_NAME ಪಠ್ಯ_3("SeRestorePrivilege")
#ವ್ಯಾಖ್ಯಾನಿಸು SE_SHUTDOWN_NAME ಪಠ್ಯ_3("SeShutdownPrivilege")
#ವ್ಯಾಖ್ಯಾನಿಸು SE_DEBUG_NAME ಪಠ್ಯ_3("SeDebugPrivilege")
#ವ್ಯಾಖ್ಯಾನಿಸು SE_AUDIT_NAME ಪಠ್ಯ_3("SeAuditPrivilege")
#ವ್ಯಾಖ್ಯಾನಿಸು SE_SYSTEM_ENVIRONMENT_NAME ಪಠ್ಯ_3("SeSystemEnvironmentPrivilege")
#ವ್ಯಾಖ್ಯಾನಿಸು SE_CHANGE_NOTIFY_NAME ಪಠ್ಯ_3("SeChangeNotifyPrivilege")
#ವ್ಯಾಖ್ಯಾನಿಸು SE_REMOTE_SHUTDOWN_NAME ಪಠ್ಯ_3("SeRemoteShutdownPrivilege")
#ವ್ಯಾಖ್ಯಾನಿಸು SE_UNDOCK_NAME ಪಠ್ಯ_3("SeUndockPrivilege")
#ವ್ಯಾಖ್ಯಾನಿಸು SE_SYNC_AGENT_NAME ಪಠ್ಯ_3("SeSyncAgentPrivilege")
#ವ್ಯಾಖ್ಯಾನಿಸು SE_ENABLE_DELEGATION_NAME ಪಠ್ಯ_3("SeEnableDelegationPrivilege")
#ವ್ಯಾಖ್ಯಾನಿಸು SE_MANAGE_VOLUME_NAME ಪಠ್ಯ_3("SeManageVolumePrivilege")
#ವ್ಯಾಖ್ಯಾನಿಸು SE_IMPERSONATE_NAME ಪಠ್ಯ_3("SeImpersonatePrivilege")
#ವ್ಯಾಖ್ಯಾನಿಸು SE_CREATE_GLOBAL_NAME ಪಠ್ಯ_3("SeCreateGlobalPrivilege")

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಎಣಿಕೆ _SECURITY_IMPERSONATION_LEVEL {
      SecurityAnonymous,SecurityIdentification,SecurityImpersonation,SecurityDelegation
    } SECURITY_IMPERSONATION_LEVEL,*PSECURITY_IMPERSONATION_LEVEL;

#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_MAX_IMPERSONATION_LEVEL SecurityDelegation
#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_MIN_IMPERSONATION_LEVEL SecurityAnonymous
#ವ್ಯಾಖ್ಯಾನಿಸು DEFAULT_IMPERSONATION_LEVEL SecurityImpersonation
#ವ್ಯಾಖ್ಯಾನಿಸು VALID_IMPERSONATION_LEVEL(L) (((L) >= SECURITY_MIN_IMPERSONATION_LEVEL) && ((L) <= SECURITY_MAX_IMPERSONATION_LEVEL))

#ವ್ಯಾಖ್ಯಾನಿಸು TOKEN_ನಿಯೋಜಿಸು_PRIMARY (0x0001)
#ವ್ಯಾಖ್ಯಾನಿಸು TOKEN_DUPLICATE (0x0002)
#ವ್ಯಾಖ್ಯಾನಿಸು TOKEN_IMPERSONATE (0x0004)
#ವ್ಯಾಖ್ಯಾನಿಸು TOKEN_QUERY (0x0008)
#ವ್ಯಾಖ್ಯಾನಿಸು TOKEN_QUERY_ಮೂಲ (0x0010)
#ವ್ಯಾಖ್ಯಾನಿಸು TOKEN_ADJUST_PRIVILEGES (0x0020)
#ವ್ಯಾಖ್ಯಾನಿಸು TOKEN_ADJUST_GROUPS (0x0040)
#ವ್ಯಾಖ್ಯಾನಿಸು TOKEN_ADJUST_DEFAULT (0x0080)
#ವ್ಯಾಖ್ಯಾನಿಸು TOKEN_ADJUST_SESSIONID (0x0100)

#ವ್ಯಾಖ್ಯಾನಿಸು TOKEN_ALL_ACCESS_P (STANDARD_RIGHTS_REQUIRED | TOKEN_ನಿಯೋಜಿಸು_PRIMARY | TOKEN_DUPLICATE | TOKEN_IMPERSONATE | TOKEN_QUERY | TOKEN_QUERY_ಮೂಲ | TOKEN_ADJUST_PRIVILEGES | TOKEN_ADJUST_GROUPS | TOKEN_ADJUST_DEFAULT)
#ವ್ಯಾಖ್ಯಾನಿಸು TOKEN_ALL_ACCESS (TOKEN_ALL_ACCESS_P | TOKEN_ADJUST_SESSIONID)
#ವ್ಯಾಖ್ಯಾನಿಸು TOKEN_READ (STANDARD_RIGHTS_READ | TOKEN_QUERY)

#ವ್ಯಾಖ್ಯಾನಿಸು TOKEN_WRITE (STANDARD_RIGHTS_WRITE | TOKEN_ADJUST_PRIVILEGES | TOKEN_ADJUST_GROUPS | TOKEN_ADJUST_DEFAULT)

#ವ್ಯಾಖ್ಯಾನಿಸು TOKEN_EXECUTE (STANDARD_RIGHTS_EXECUTE)

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಎಣಿಕೆ _TOKEN_TYPE {
      TokenPrimary = 1,TokenImpersonation
    } TOKEN_TYPE;
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ TOKEN_TYPE *PTOKEN_TYPE;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಎಣಿಕೆ _TOKEN_INFORMATION_CLASS {
      TokenUser = 1,TokenGroups,TokenPrivileges,TokenOwner,Token_Primary_ಗುಂಪು,TokenDefaultDacl,Token_ಮೂಲ,TokenType,TokenImpersonationLevel,
      TokenStatistics,TokenRestrictedSids,TokenSessionId,TokenGroupsAndPrivileges,TokenSessionReference,TokenSandBoxInert,TokenAuditPolicy,
      TokenOrigin,MaxTokenInfoClass
    } TOKEN_INFORMATION_CLASS,*PTOKEN_INFORMATION_CLASS;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _TOKEN_USER {
      SID_AND_ಗುಣಲಕ್ಷಣಗಳು_2 User;
    } TOKEN_USER,*PTOKEN_USER;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _TOKEN_GROUPS {
      DWORD ಗುಂಪು_ಎಣಿಕೆ;
      SID_AND_ಗುಣಲಕ್ಷಣಗಳು_2 Groups[ANYSIZE_ARRAY];
    } TOKEN_GROUPS,*PTOKEN_GROUPS;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _TOKEN_PRIVILEGES {
      DWORD Privilege_ಎಣಿಕೆ;
      LUID_AND_ಗುಣಲಕ್ಷಣಗಳು_2 Privileges[ANYSIZE_ARRAY];
    } TOKEN_PRIVILEGES,*PTOKEN_PRIVILEGES;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _TOKEN_OWNER {
      PSID Owner;
    } TOKEN_OWNER,*PTOKEN_OWNER;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ TOKEN_PRIMARY_ಗುಂಪು {
      PSID Primary_ಗುಂಪು;
    } TOKEN_PRIMARY_ಗುಂಪು_2,*PTOKEN_PRIMARY_ಗುಂಪು;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _TOKEN_DEFAULT_DACL {
      PACL DefaultDacl;
    } TOKEN_DEFAULT_DACL,*PTOKEN_DEFAULT_DACL;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _TOKEN_GROUPS_AND_PRIVILEGES {
      DWORD Sid_ಎಣಿಕೆ;
      DWORD Sid_ಉದ್ದಳತೆ;
      PSID_AND_ಗುಣಲಕ್ಷಣಗಳು Sids;
      DWORD Restricted_Sid_ಎಣಿಕೆ;
      DWORD Restricted_Sid_ಉದ್ದಳತೆ;
      PSID_AND_ಗುಣಲಕ್ಷಣಗಳು RestrictedSids;
      DWORD Privilege_ಎಣಿಕೆ;
      DWORD Privilege_ಉದ್ದಳತೆ;
      PLUID_AND_ಗುಣಲಕ್ಷಣಗಳು Privileges;
      LUID AuthenticationId;
    } TOKEN_GROUPS_AND_PRIVILEGES,*PTOKEN_GROUPS_AND_PRIVILEGES;

#ವ್ಯಾಖ್ಯಾನಿಸು TOKEN_AUDIT_SUCCESS_INCLUDE 0x1
#ವ್ಯಾಖ್ಯಾನಿಸು TOKEN_AUDIT_SUCCESS_EXCLUDE 0x2
#ವ್ಯಾಖ್ಯಾನಿಸು TOKEN_AUDIT_FAILURE_INCLUDE 0x4
#ವ್ಯಾಖ್ಯಾನಿಸು TOKEN_AUDIT_FAILURE_EXCLUDE 0x8

#ವ್ಯಾಖ್ಯಾನಿಸು VALID_AUDIT_POLICY_ಬಿಟ್ಟುಗಳು (TOKEN_AUDIT_SUCCESS_INCLUDE | TOKEN_AUDIT_SUCCESS_EXCLUDE | TOKEN_AUDIT_FAILURE_INCLUDE | TOKEN_AUDIT_FAILURE_EXCLUDE)
#ವ್ಯಾಖ್ಯಾನಿಸು VALID_TOKEN_AUDIT_POLICY_ELEMENT(P) ((((P).Policy_ಮುಖವಾಡ & ~VALID_AUDIT_POLICY_ಬಿಟ್ಟುಗಳು)==0) && ((P).Category <= AuditEventMaxType))

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _TOKEN_AUDIT_POLICY_ELEMENT {
      DWORD Category;
      DWORD Policy_ಮುಖವಾಡ;
    } TOKEN_AUDIT_POLICY_ELEMENT,*PTOKEN_AUDIT_POLICY_ELEMENT;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _TOKEN_AUDIT_POLICY {
      DWORD Policy_ಎಣಿಕೆ;
      TOKEN_AUDIT_POLICY_ELEMENT Policy[ANYSIZE_ARRAY];
    } TOKEN_AUDIT_POLICY,*PTOKEN_AUDIT_POLICY;

#ವ್ಯಾಖ್ಯಾನಿಸು ಪ್ರತಿ_USER_AUDITING_POLICY_ಗಾತ್ರ(p) (ಗಾತ್ರ(TOKEN_AUDIT_POLICY) + (((p)->Policy_ಎಣಿಕೆ > ANYSIZE_ARRAY) ? (ಗಾತ್ರ(TOKEN_AUDIT_POLICY_ELEMENT) *((p)->Policy_ಎಣಿಕೆ - ANYSIZE_ARRAY)) : 0))
#ವ್ಯಾಖ್ಯಾನಿಸು ಪ್ರತಿ_USER_AUDITING_POLICY_ಗಾತ್ರ_BY_ಎಣಿಕೆ(C) (ಗಾತ್ರ(TOKEN_AUDIT_POLICY) + (((C) > ANYSIZE_ARRAY) ? (ಗಾತ್ರ(TOKEN_AUDIT_POLICY_ELEMENT) *((C) - ANYSIZE_ARRAY)) : 0))

#ವ್ಯಾಖ್ಯಾನಿಸು TOKEN_ಮೂಲ_ಉದ್ದಳತೆ 8

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ TOKEN_ಮೂಲ {
      CHAR ಮೂಲ_Name[TOKEN_ಮೂಲ_ಉದ್ದಳತೆ];
      LUID ಮೂಲ_Identifier;
    } TOKEN_ಮೂಲ_2,*PTOKEN_ಮೂಲ;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _TOKEN_STATISTICS {
      LUID TokenId;
      LUID AuthenticationId;
      LARGE_INTEGER Expiration_ಸಮಯ;
      TOKEN_TYPE TokenType;
      SECURITY_IMPERSONATION_LEVEL ImpersonationLevel;
      DWORD DynamicCharged;
      DWORD Dynamic_ಲಭ್ಯ;
      DWORD ಗುಂಪು_ಎಣಿಕೆ;
      DWORD Privilege_ಎಣಿಕೆ;
      LUID ModifiedId;
    } TOKEN_STATISTICS,*PTOKEN_STATISTICS;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _TOKEN_CONTROL {
      LUID TokenId;
      LUID AuthenticationId;
      LUID ModifiedId;
      TOKEN_ಮೂಲ_2 Token_ಮೂಲ;
    } TOKEN_CONTROL,*PTOKEN_CONTROL;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _TOKEN_ORIGIN {
      LUID OriginatingLogonSession;
    } TOKEN_ORIGIN,*PTOKEN_ORIGIN;

#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_DYNAMIC_TRACKING (TRUE)
#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_STATIC_TRACKING (FALSE)

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ BOOLEAN SECURITY_CONTEXT_TRACKING_ಬಹುಲಕ,*PSECURITY_CONTEXT_TRACKING_ಬಹುಲಕ;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ SECURITY_QUALITY_ದ_SERVICE {
      DWORD ಉದ್ದಳತೆ_2;
      SECURITY_IMPERSONATION_LEVEL ImpersonationLevel;
      SECURITY_CONTEXT_TRACKING_ಬಹುಲಕ Context_Tracking_ಬಹುಲಕ;
      BOOLEAN EffectiveOnly;
    } SECURITY_QUALITY_ದ_SERVICE_2,*PSECURITY_QUALITY_ದ_SERVICE;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _SE_IMPERSONATION_STATE {
      PACCESS_TOKEN Token;
      BOOLEAN CopyOnOpen;
      BOOLEAN EffectiveOnly;
      SECURITY_IMPERSONATION_LEVEL Level;
    } SE_IMPERSONATION_STATE,*PSE_IMPERSONATION_STATE;

#ವ್ಯಾಖ್ಯಾನಿಸು DISABLE_MAX_PRIVILEGE 0x1
#ವ್ಯಾಖ್ಯಾನಿಸು SANDBOX_INERT 0x2

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ DWORD SECURITY_INFORMATION,*PSECURITY_INFORMATION;

#ವ್ಯಾಖ್ಯಾನಿಸು OWNER_SECURITY_INFORMATION (0x00000001L)
#ವ್ಯಾಖ್ಯಾನಿಸು ಗುಂಪು_SECURITY_INFORMATION (0x00000002L)
#ವ್ಯಾಖ್ಯಾನಿಸು DACL_SECURITY_INFORMATION (0x00000004L)
#ವ್ಯಾಖ್ಯಾನಿಸು SACL_SECURITY_INFORMATION (0x00000008L)

#ವ್ಯಾಖ್ಯಾನಿಸು PROTECTED_DACL_SECURITY_INFORMATION (0x80000000L)
#ವ್ಯಾಖ್ಯಾನಿಸು PROTECTED_SACL_SECURITY_INFORMATION (0x40000000L)
#ವ್ಯಾಖ್ಯಾನಿಸು UNPROTECTED_DACL_SECURITY_INFORMATION (0x20000000L)
#ವ್ಯಾಖ್ಯಾನಿಸು UNPROTECTED_SACL_SECURITY_INFORMATION (0x10000000L)

#ವ್ಯಾಖ್ಯಾನಿಸು PROCESS_TERMINATE (0x0001)
#ವ್ಯಾಖ್ಯಾನಿಸು PROCESS_CREATE_THREAD (0x0002)
#ವ್ಯಾಖ್ಯಾನಿಸು PROCESS_ಗಣ_SESSIONID (0x0004)
#ವ್ಯಾಖ್ಯಾನಿಸು PROCESS_VM_OPERATION (0x0008)
#ವ್ಯಾಖ್ಯಾನಿಸು PROCESS_VM_READ (0x0010)
#ವ್ಯಾಖ್ಯಾನಿಸು PROCESS_VM_WRITE (0x0020)
#ವ್ಯಾಖ್ಯಾನಿಸು PROCESS_DUP_HANDLE (0x0040)
#ವ್ಯಾಖ್ಯಾನಿಸು PROCESS_CREATE_PROCESS (0x0080)
#ವ್ಯಾಖ್ಯಾನಿಸು PROCESS_ಗಣ_QUOTA (0x0100)
#ವ್ಯಾಖ್ಯಾನಿಸು PROCESS_ಗಣ_INFORMATION (0x0200)
#ವ್ಯಾಖ್ಯಾನಿಸು PROCESS_QUERY_INFORMATION (0x0400)
#ವ್ಯಾಖ್ಯಾನಿಸು PROCESS_SUSPEND_RESUME (0x0800)
#ವ್ಯಾಖ್ಯಾನಿಸು PROCESS_QUERY_LIMITED_INFORMATION (0x1000)
#ವ್ಯಾಖ್ಯಾನಿಸು PROCESS_ಗಣ_LIMITED_INFORMATION (0x2000)
#ವ್ಯಾಖ್ಯಾನಿಸು PROCESS_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0xFFF)

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN64
#ವ್ಯಾಖ್ಯಾನಿಸು ಗರಿಷ್ಠ_PROCESSORS 64
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು ಗರಿಷ್ಠ_PROCESSORS 32
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು THREAD_TERMINATE (0x0001)
#ವ್ಯಾಖ್ಯಾನಿಸು THREAD_SUSPEND_RESUME (0x0002)
#ವ್ಯಾಖ್ಯಾನಿಸು THREAD_GET_CONTEXT (0x0008)
#ವ್ಯಾಖ್ಯಾನಿಸು THREAD_ಗಣ_CONTEXT (0x0010)
#ವ್ಯಾಖ್ಯಾನಿಸು THREAD_ಗಣ_INFORMATION (0x0020)
#ವ್ಯಾಖ್ಯಾನಿಸು THREAD_QUERY_INFORMATION (0x0040)
#ವ್ಯಾಖ್ಯಾನಿಸು THREAD_ಗಣ_THREAD_TOKEN (0x0080)
#ವ್ಯಾಖ್ಯಾನಿಸು THREAD_IMPERSONATE (0x0100)
#ವ್ಯಾಖ್ಯಾನಿಸು THREAD_ನೇರ_IMPERSONATION (0x0200)

#ವ್ಯಾಖ್ಯಾನಿಸು THREAD_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0x3FF)

#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_ನಿಯೋಜಿಸು_PROCESS (0x0001)
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_ಗಣ_ಗುಣಲಕ್ಷಣಗಳು (0x0002)
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_QUERY (0x0004)
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_TERMINATE (0x0008)
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_ಗಣ_SECURITY_ಗುಣಲಕ್ಷಣಗಳು (0x0010)
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0x1F)

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಕೆಲಸ_ಗಣ_ARRAY {
      HANDLE ಕೆಲಸ_Handle;
      DWORD MemberLevel;
      DWORD Flags;
    } ಕೆಲಸ_ಗಣ_ARRAY_2,*PJOB_ಗಣ_ARRAY;

#ವ್ಯಾಖ್ಯಾನಿಸು FLS_ಗರಿಷ್ಠ_ಲಭ್ಯ 128
#ವ್ಯಾಖ್ಯಾನಿಸು TLS_MINIMUM_ಲಭ್ಯ 64

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _NT_TIB_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _NT_TIB_DEFINED
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _NT_TIB {
      ರಚನೆ EXCEPTION_REGISTRATION_ದಾಖಲೆ_2 *ExceptionList;
      PVOID ರಾಶಿ_ತಳ;
      PVOID ರಾಶಿ_ಎಲ್ಲೆ;
      PVOID SubSystemTib;
      ಒಕ್ಕೂಟ {
	PVOID Fiber_ದತ್ತಾಂಶ;
	DWORD ಆವೃತ್ತಿ_2;
      };
      PVOID Arbitrary_User_ಸೂಚಕ;
      ರಚನೆ _NT_TIB *Self;
    } NT_TIB;
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ NT_TIB *PNT_TIB;
#ಆದರೆ_ಅಂತ್ಯ

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _NT_TIB32 {
      DWORD ExceptionList;
      DWORD ರಾಶಿ_ತಳ;
      DWORD ರಾಶಿ_ಎಲ್ಲೆ;
      DWORD SubSystemTib;
      ಒಕ್ಕೂಟ {
	DWORD Fiber_ದತ್ತಾಂಶ;
	DWORD ಆವೃತ್ತಿ_2;
      };
      DWORD Arbitrary_User_ಸೂಚಕ;
      DWORD Self;
    } NT_TIB32,*PNT_TIB32;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _NT_TIB64 {
      DWORD64 ExceptionList;
      DWORD64 ರಾಶಿ_ತಳ;
      DWORD64 ರಾಶಿ_ಎಲ್ಲೆ;
      DWORD64 SubSystemTib;
      ಒಕ್ಕೂಟ {
	DWORD64 Fiber_ದತ್ತಾಂಶ;
	DWORD ಆವೃತ್ತಿ_2;
      };
      DWORD64 Arbitrary_User_ಸೂಚಕ;
      DWORD64 Self;
    } NT_TIB64,*PNT_TIB64;

#ಆದರೆ !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_)
#ವ್ಯಾಖ್ಯಾನಿಸು WX86
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು THREAD_ತಳ_ಆದ್ಯತೆ_LOWRT 15
#ವ್ಯಾಖ್ಯಾನಿಸು THREAD_ತಳ_ಆದ್ಯತೆ_MAX 2
#ವ್ಯಾಖ್ಯಾನಿಸು THREAD_ತಳ_ಆದ್ಯತೆ_MIN (-2)
#ವ್ಯಾಖ್ಯಾನಿಸು THREAD_ತಳ_ಆದ್ಯತೆ_IDLE (-15)

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _QUOTA_LIMITS {
      ಗಾತ್ರ_T Paged_Pool_ಎಲ್ಲೆ;
      ಗಾತ್ರ_T Non_Paged_Pool_ಎಲ್ಲೆ;
      ಗಾತ್ರ_T Minimum_Working_ಗಣ_ಗಾತ್ರ;
      ಗಾತ್ರ_T ಗರಿಷ್ಠ_Working_ಗಣ_ಗಾತ್ರ;
      ಗಾತ್ರ_T Pagefile_ಎಲ್ಲೆ;
      LARGE_INTEGER ಸಮಯ_ಎಲ್ಲೆ;
    } QUOTA_LIMITS,*PQUOTA_LIMITS;

#ವ್ಯಾಖ್ಯಾನಿಸು QUOTA_LIMITS_HARDWS_MIN_ENABLE 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು QUOTA_LIMITS_HARDWS_MIN_DISABLE 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು QUOTA_LIMITS_HARDWS_MAX_ENABLE 0x00000004
#ವ್ಯಾಖ್ಯಾನಿಸು QUOTA_LIMITS_HARDWS_MAX_DISABLE 0x00000008

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _QUOTA_LIMITS_EX {
      ಗಾತ್ರ_T Paged_Pool_ಎಲ್ಲೆ;
      ಗಾತ್ರ_T Non_Paged_Pool_ಎಲ್ಲೆ;
      ಗಾತ್ರ_T Minimum_Working_ಗಣ_ಗಾತ್ರ;
      ಗಾತ್ರ_T ಗರಿಷ್ಠ_Working_ಗಣ_ಗಾತ್ರ;
      ಗಾತ್ರ_T Pagefile_ಎಲ್ಲೆ;
      LARGE_INTEGER ಸಮಯ_ಎಲ್ಲೆ;
      ಗಾತ್ರ_T Reserved1;
      ಗಾತ್ರ_T Reserved2;
      ಗಾತ್ರ_T Reserved3;
      ಗಾತ್ರ_T Reserved4;
      DWORD Flags;
      DWORD Reserved5;
    } QUOTA_LIMITS_EX,*PQUOTA_LIMITS_EX;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _IO_COUNTERS {
      ULONGLONG Read_Operation_ಎಣಿಕೆ;
      ULONGLONG Write_Operation_ಎಣಿಕೆ;
      ULONGLONG Other_Operation_ಎಣಿಕೆ;
      ULONGLONG Read_Transfer_ಎಣಿಕೆ;
      ULONGLONG Write_Transfer_ಎಣಿಕೆ;
      ULONGLONG Other_Transfer_ಎಣಿಕೆ;
    } IO_COUNTERS;
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ IO_COUNTERS *PIO_COUNTERS;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _JOBOBJECT_BASIC_ACCOUNTING_INFORMATION {
      LARGE_INTEGER ಒಟ್ಟು_User_ಸಮಯ;
      LARGE_INTEGER ಒಟ್ಟು_Kernel_ಸಮಯ;
      LARGE_INTEGER This_Period_ಒಟ್ಟು_User_ಸಮಯ;
      LARGE_INTEGER This_Period_ಒಟ್ಟು_Kernel_ಸಮಯ;
      DWORD ಒಟ್ಟು_ಪುಟ_Fault_ಎಣಿಕೆ;
      DWORD ಒಟ್ಟು_Processes;
      DWORD ಸಕ್ರಿಯ_Processes;
      DWORD ಒಟ್ಟು_Terminated_Processes;
    } JOBOBJECT_BASIC_ACCOUNTING_INFORMATION,*PJOBOBJECT_BASIC_ACCOUNTING_INFORMATION;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ JOBOBJECT_BASIC_ಎಲ್ಲೆ_INFORMATION {
      LARGE_INTEGER ಪ್ರತಿ_Process_User_ಸಮಯ_ಎಲ್ಲೆ;
      LARGE_INTEGER ಪ್ರತಿ_ಕೆಲಸ_User_ಸಮಯ_ಎಲ್ಲೆ;
      DWORD ಎಲ್ಲೆ_Flags;
      ಗಾತ್ರ_T Minimum_Working_ಗಣ_ಗಾತ್ರ;
      ಗಾತ್ರ_T ಗರಿಷ್ಠ_Working_ಗಣ_ಗಾತ್ರ;
      DWORD ಸಕ್ರಿಯ_Process_ಎಲ್ಲೆ;
      ULONG_PTR Affinity;
      DWORD ಆದ್ಯತೆ_Class;
      DWORD SchedulingClass;
    } JOBOBJECT_BASIC_ಎಲ್ಲೆ_INFORMATION_2,*PJOBOBJECT_BASIC_ಎಲ್ಲೆ_INFORMATION;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ JOBOBJECT_EXTENDED_ಎಲ್ಲೆ_INFORMATION {
      JOBOBJECT_BASIC_ಎಲ್ಲೆ_INFORMATION_2 Basic_ಎಲ್ಲೆ_Information;
      IO_COUNTERS IoInfo;
      ಗಾತ್ರ_T Process_ಸ್ಮರಣೆ_ಎಲ್ಲೆ;
      ಗಾತ್ರ_T ಕೆಲಸ_ಸ್ಮರಣೆ_ಎಲ್ಲೆ;
      ಗಾತ್ರ_T Peak_Process_ಸ್ಮರಣೆ_ಬಳಸಿದ;
      ಗಾತ್ರ_T Peak_ಕೆಲಸ_ಸ್ಮರಣೆ_ಬಳಸಿದ;
    } JOBOBJECT_EXTENDED_ಎಲ್ಲೆ_INFORMATION_2,*PJOBOBJECT_EXTENDED_ಎಲ್ಲೆ_INFORMATION;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _JOBOBJECT_BASIC_PROCESS_ID_LIST {
      DWORD ಸಂಖ್ಯೆ_ದ_Assigned_Processes;
      DWORD ಸಂಖ್ಯೆ_ದ_Process_Ids_ಒಳ_List;
      ULONG_PTR ProcessIdList[1];
    } JOBOBJECT_BASIC_PROCESS_ID_LIST,*PJOBOBJECT_BASIC_PROCESS_ID_LIST;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _JOBOBJECT_BASIC_UI_RESTRICTIONS {
      DWORD UIRestrictionsClass;
    } JOBOBJECT_BASIC_UI_RESTRICTIONS,*PJOBOBJECT_BASIC_UI_RESTRICTIONS;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ JOBOBJECT_SECURITY_ಎಲ್ಲೆ_INFORMATION {
      DWORD Security_ಎಲ್ಲೆ_Flags;
      HANDLE ಕೆಲಸ_Token;
      PTOKEN_GROUPS Sids_ಗಮ್ಯ_Disable;
      PTOKEN_PRIVILEGES Privileges_ಗಮ್ಯ_Delete;
      PTOKEN_GROUPS RestrictedSids;
    } JOBOBJECT_SECURITY_ಎಲ್ಲೆ_INFORMATION_2,*PJOBOBJECT_SECURITY_ಎಲ್ಲೆ_INFORMATION;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ JOBOBJECT_ಕೊನೆ_ದ_ಕೆಲಸ_ಸಮಯ_INFORMATION {
      DWORD ಕೊನೆ_ದ_ಕೆಲಸ_ಸಮಯ_Action;
    } JOBOBJECT_ಕೊನೆ_ದ_ಕೆಲಸ_ಸಮಯ_INFORMATION_2,*PJOBOBJECT_ಕೊನೆ_ದ_ಕೆಲಸ_ಸಮಯ_INFORMATION;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ JOBOBJECT_ASSOCIATE_COMPLETION_ಪೋರ್ಟ್ {
      PVOID Completion_ಕೀಲಿ;
      HANDLE Completion_ಪೋರ್ಟ್;
    } JOBOBJECT_ASSOCIATE_COMPLETION_ಪೋರ್ಟ್_2,*PJOBOBJECT_ASSOCIATE_COMPLETION_ಪೋರ್ಟ್;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _JOBOBJECT_BASIC_AND_IO_ACCOUNTING_INFORMATION {
      JOBOBJECT_BASIC_ACCOUNTING_INFORMATION BasicInfo;
      IO_COUNTERS IoInfo;
    } JOBOBJECT_BASIC_AND_IO_ACCOUNTING_INFORMATION,*PJOBOBJECT_BASIC_AND_IO_ACCOUNTING_INFORMATION;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _JOBOBJECT_JOBSET_INFORMATION {
      DWORD MemberLevel;
    } JOBOBJECT_JOBSET_INFORMATION,*PJOBOBJECT_JOBSET_INFORMATION;

#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_TERMINATE_AT_ಕೊನೆ_ದ_ಕೆಲಸ 0
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_POST_AT_ಕೊನೆ_ದ_ಕೆಲಸ 1

#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_ಸಂದೇಶ_ಕೊನೆ_ದ_ಕೆಲಸ_ಸಮಯ 1
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_ಸಂದೇಶ_ಕೊನೆ_ದ_PROCESS_ಸಮಯ 2
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_ಸಂದೇಶ_ಸಕ್ರಿಯ_PROCESS_ಎಲ್ಲೆ 3
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_ಸಂದೇಶ_ಸಕ್ರಿಯ_PROCESS_ZERO 4
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_ಸಂದೇಶ_NEW_PROCESS 6
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_ಸಂದೇಶ_EXIT_PROCESS 7
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_ಸಂದೇಶ_ABNORMAL_EXIT_PROCESS 8
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_ಸಂದೇಶ_PROCESS_ಸ್ಮರಣೆ_ಎಲ್ಲೆ 9
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_ಸಂದೇಶ_ಕೆಲಸ_ಸ್ಮರಣೆ_ಎಲ್ಲೆ 10

#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_ಎಲ್ಲೆ_WORKINGSET 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_ಎಲ್ಲೆ_PROCESS_ಸಮಯ 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_ಎಲ್ಲೆ_ಕೆಲಸ_ಸಮಯ 0x00000004
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_ಎಲ್ಲೆ_ಸಕ್ರಿಯ_PROCESS 0x00000008
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_ಎಲ್ಲೆ_AFFINITY 0x00000010
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_ಎಲ್ಲೆ_ಆದ್ಯತೆ_CLASS 0x00000020
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_ಎಲ್ಲೆ_PRESERVE_ಕೆಲಸ_ಸಮಯ 0x00000040
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_ಎಲ್ಲೆ_SCHEDULING_CLASS 0x00000080

#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_ಎಲ್ಲೆ_PROCESS_ಸ್ಮರಣೆ 0x00000100
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_ಎಲ್ಲೆ_ಕೆಲಸ_ಸ್ಮರಣೆ 0x00000200
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_ಎಲ್ಲೆ_DIE_ON_UNHANDLED_EXCEPTION 0x00000400
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_ಎಲ್ಲೆ_BREAKAWAY_OK 0x00000800
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_ಎಲ್ಲೆ_SILENT_BREAKAWAY_OK 0x00001000
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_ಎಲ್ಲೆ_KILL_ON_ಕೆಲಸ_CLOSE 0x00002000

#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_ಎಲ್ಲೆ_RESERVED2 0x00004000
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_ಎಲ್ಲೆ_RESERVED3 0x00008000
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_ಎಲ್ಲೆ_RESERVED4 0x00010000
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_ಎಲ್ಲೆ_RESERVED5 0x00020000
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_ಎಲ್ಲೆ_RESERVED6 0x00040000

#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_ಎಲ್ಲೆ_VALID_FLAGS 0x0007ffff

#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_BASIC_ಎಲ್ಲೆ_VALID_FLAGS 0x000000ff
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_EXTENDED_ಎಲ್ಲೆ_VALID_FLAGS 0x00003fff
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_RESERVED_ಎಲ್ಲೆ_VALID_FLAGS 0x0007ffff

#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_UILIMIT_NONE 0x00000000

#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_UILIMIT_HANDLES 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_UILIMIT_READCLIPBOARD 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_UILIMIT_WRITECLIPBOARD 0x00000004
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_UILIMIT_SYSTEMPARAMETERS 0x00000008
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_UILIMIT_DISPLAYSETTINGS 0x00000010
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_UILIMIT_GLOBALATOMS 0x00000020
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_UILIMIT_DESKTOP 0x00000040
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_UILIMIT_EXITWINDOWS 0x00000080

#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_UILIMIT_ALL 0x000000FF

#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_UI_VALID_FLAGS 0x000000FF

#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_SECURITY_NO_ADMIN 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_SECURITY_RESTRICTED_TOKEN 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_SECURITY_ONLY_TOKEN 0x00000004
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_SECURITY_FILTER_ಟೋಕನುಗಳು 0x00000008

#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಲಸ_OBJECT_SECURITY_VALID_FLAGS 0x0000000f

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಎಣಿಕೆ _JOBOBJECTINFOCLASS {
      ಕೆಲಸ_Object_Basic_Accounting_Information = 1,ಕೆಲಸ_Object_Basic_ಎಲ್ಲೆ_Information,ಕೆಲಸ_Object_Basic_Process_Id_List,ಕೆಲಸ_Object_Basic_UIRestrictions,
      ಕೆಲಸ_Object_Security_ಎಲ್ಲೆ_Information,ಕೆಲಸ_Object_ಕೊನೆ_ದ_ಕೆಲಸ_ಸಮಯ_Information,ಕೆಲಸ_Object_Associate_Completion_ಪೋರ್ಟ್_Information,
      ಕೆಲಸ_Object_Basic_And_Io_Accounting_Information,ಕೆಲಸ_Object_Extended_ಎಲ್ಲೆ_Information,ಕೆಲಸ_Object_ಕೆಲಸ_ಗಣ_Information,Max_ಕೆಲಸ_Object_Info_Class
    } JOBOBJECTINFOCLASS;

#ವ್ಯಾಖ್ಯಾನಿಸು EVENT_MODIFY_STATE 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು EVENT_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x3)

#ವ್ಯಾಖ್ಯಾನಿಸು MUTANT_QUERY_STATE 0x0001

#ವ್ಯಾಖ್ಯಾನಿಸು MUTANT_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE| MUTANT_QUERY_STATE)
#ವ್ಯಾಖ್ಯಾನಿಸು SEMAPHORE_MODIFY_STATE 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು SEMAPHORE_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x3)

#ವ್ಯಾಖ್ಯಾನಿಸು TIMER_QUERY_STATE 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು TIMER_MODIFY_STATE 0x0002

#ವ್ಯಾಖ್ಯಾನಿಸು TIMER_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE| TIMER_QUERY_STATE|TIMER_MODIFY_STATE)

#ವ್ಯಾಖ್ಯಾನಿಸು ಸಮಯ_ZONE_ID_UNKNOWN 0
#ವ್ಯಾಖ್ಯಾನಿಸು ಸಮಯ_ZONE_ID_STANDARD 1
#ವ್ಯಾಖ್ಯಾನಿಸು ಸಮಯ_ZONE_ID_DAYLIGHT 2

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಎಣಿಕೆ _LOGICAL_PROCESSOR_RELATIONSHIP {
      ಸಂಬಂಧ_Processor_Core,ಸಂಬಂಧ_Numa_ಗಂಟು,ಸಂಬಂಧ_Cache
    } LOGICAL_PROCESSOR_RELATIONSHIP;

#ವ್ಯಾಖ್ಯಾನಿಸು LTP_PC_SMT 0x1

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಎಣಿಕೆ _PROCESSOR_CACHE_TYPE {
      CacheUnified,CacheInstruction,Cache_ದತ್ತಾಂಶ,CacheTrace
    } PROCESSOR_CACHE_TYPE;

#ವ್ಯಾಖ್ಯಾನಿಸು CACHE_FULLY_ASSOCIATIVE 0xFF

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _CACHE_DESCRIPTOR {
      BYTE Level;
      BYTE Associativity;
      ಶಬ್ದ_3 ಸಾಲು_ಗಾತ್ರ_2;
      DWORD ಗಾತ್ರ_4;
      PROCESSOR_CACHE_TYPE Type;
    } CACHE_DESCRIPTOR,*PCACHE_DESCRIPTOR;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _SYSTEM_LOGICAL_PROCESSOR_INFORMATION {
      ULONG_PTR Processor_ಮುಖವಾಡ;
      LOGICAL_PROCESSOR_RELATIONSHIP Relationship;
      ಒಕ್ಕೂಟ {
	ರಚನೆ {
	  BYTE Flags;
	} ProcessorCore;
	ರಚನೆ {
	  DWORD ಗಂಟು_ಸಂಖ್ಯೆ;
	} Numa_ಗಂಟು;
	CACHE_DESCRIPTOR Cache;
	ULONGLONG Reserved[2];
      };
    } SYSTEM_LOGICAL_PROCESSOR_INFORMATION,*PSYSTEM_LOGICAL_PROCESSOR_INFORMATION;

#ವ್ಯಾಖ್ಯಾನಿಸು PROCESSOR_INTEL_386 386
#ವ್ಯಾಖ್ಯಾನಿಸು PROCESSOR_INTEL_486 486
#ವ್ಯಾಖ್ಯಾನಿಸು PROCESSOR_INTEL_PENTIUM 586
#ವ್ಯಾಖ್ಯಾನಿಸು PROCESSOR_INTEL_IA64 2200
#ವ್ಯಾಖ್ಯಾನಿಸು PROCESSOR_AMD_X8664 8664
#ವ್ಯಾಖ್ಯಾನಿಸು PROCESSOR_MIPS_R4000 4000
#ವ್ಯಾಖ್ಯಾನಿಸು PROCESSOR_ALPHA_21064 21064
#ವ್ಯಾಖ್ಯಾನಿಸು PROCESSOR_PPC_601 601
#ವ್ಯಾಖ್ಯಾನಿಸು PROCESSOR_PPC_603 603
#ವ್ಯಾಖ್ಯಾನಿಸು PROCESSOR_PPC_604 604
#ವ್ಯಾಖ್ಯಾನಿಸು PROCESSOR_PPC_620 620
#ವ್ಯಾಖ್ಯಾನಿಸು PROCESSOR_HITACHI_SH3 10003
#ವ್ಯಾಖ್ಯಾನಿಸು PROCESSOR_HITACHI_SH3E 10004
#ವ್ಯಾಖ್ಯಾನಿಸು PROCESSOR_HITACHI_SH4 10005
#ವ್ಯಾಖ್ಯಾನಿಸು PROCESSOR_MOTOROLA_821 821
#ವ್ಯಾಖ್ಯಾನಿಸು PROCESSOR_SHx_SH3 103
#ವ್ಯಾಖ್ಯಾನಿಸು PROCESSOR_SHx_SH4 104
#ವ್ಯಾಖ್ಯಾನಿಸು PROCESSOR_STRONGARM 2577
#ವ್ಯಾಖ್ಯಾನಿಸು PROCESSOR_ARM720 1824
#ವ್ಯಾಖ್ಯಾನಿಸು PROCESSOR_ARM820 2080
#ವ್ಯಾಖ್ಯಾನಿಸು PROCESSOR_ARM920 2336
#ವ್ಯಾಖ್ಯಾನಿಸು PROCESSOR_ARM_7TDMI 70001
#ವ್ಯಾಖ್ಯಾನಿಸು PROCESSOR_OPTIL 0x494f

#ವ್ಯಾಖ್ಯಾನಿಸು PROCESSOR_ARCHITECTURE_INTEL 0
#ವ್ಯಾಖ್ಯಾನಿಸು PROCESSOR_ARCHITECTURE_MIPS 1
#ವ್ಯಾಖ್ಯಾನಿಸು PROCESSOR_ARCHITECTURE_ALPHA 2
#ವ್ಯಾಖ್ಯಾನಿಸು PROCESSOR_ARCHITECTURE_PPC 3
#ವ್ಯಾಖ್ಯಾನಿಸು PROCESSOR_ARCHITECTURE_SHX 4
#ವ್ಯಾಖ್ಯಾನಿಸು PROCESSOR_ARCHITECTURE_ARM 5
#ವ್ಯಾಖ್ಯಾನಿಸು PROCESSOR_ARCHITECTURE_IA64 6
#ವ್ಯಾಖ್ಯಾನಿಸು PROCESSOR_ARCHITECTURE_ALPHA64 7
#ವ್ಯಾಖ್ಯಾನಿಸು PROCESSOR_ARCHITECTURE_MSIL 8
#ವ್ಯಾಖ್ಯಾನಿಸು PROCESSOR_ARCHITECTURE_AMD64 9
#ವ್ಯಾಖ್ಯಾನಿಸು PROCESSOR_ARCHITECTURE_IA32_ON_WIN64 10

#ವ್ಯಾಖ್ಯಾನಿಸು PROCESSOR_ARCHITECTURE_UNKNOWN 0xFFFF

#ವ್ಯಾಖ್ಯಾನಿಸು PF_FLOATING_ಬಿಂದು_PRECISION_ERRATA 0
#ವ್ಯಾಖ್ಯಾನಿಸು PF_FLOATING_ಬಿಂದು_EMULATED 1
#ವ್ಯಾಖ್ಯಾನಿಸು PF_COMPARE_EXCHANGE_DOUBLE 2
#ವ್ಯಾಖ್ಯಾನಿಸು PF_MMX_INSTRUCTIONS_ಲಭ್ಯ 3
#ವ್ಯಾಖ್ಯಾನಿಸು PF_PPC_MOVEMEM_64_ಬಿಟ್_OK 4
#ವ್ಯಾಖ್ಯಾನಿಸು PF_ALPHA_BYTE_INSTRUCTIONS 5
#ವ್ಯಾಖ್ಯಾನಿಸು PF_XMMI_INSTRUCTIONS_ಲಭ್ಯ 6
#ವ್ಯಾಖ್ಯಾನಿಸು PF_3_DNOW_INSTRUCTIONS_ಲಭ್ಯ 7
#ವ್ಯಾಖ್ಯಾನಿಸು PF_RDTSC_INSTRUCTION_ಲಭ್ಯ 8
#ವ್ಯಾಖ್ಯಾನಿಸು PF_PAE_ENABLED 9
#ವ್ಯಾಖ್ಯಾನಿಸು PF_XMMI64_INSTRUCTIONS_ಲಭ್ಯ 10
#ವ್ಯಾಖ್ಯಾನಿಸು PF_SSE_DAZ_ಬಹುಲಕ_ಲಭ್ಯ 11
#ವ್ಯಾಖ್ಯಾನಿಸು PF_NX_ENABLED 12

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಸ್ಮರಣೆ_BASIC_INFORMATION_2 {
      PVOID ತಳ_ವಿಳಾಸ;
      PVOID ಹಂಚಿಕೆ_ತಳ;
      DWORD ಹಂಚಿಕೆ_Protect;
      ಗಾತ್ರ_T Region_ಗಾತ್ರ;
      DWORD State;
      DWORD Protect;
      DWORD Type;
    } ಸ್ಮರಣೆ_BASIC_INFORMATION,*PMEMORY_BASIC_INFORMATION;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಸ್ಮರಣೆ_BASIC_INFORMATION32 {
      DWORD ತಳ_ವಿಳಾಸ;
      DWORD ಹಂಚಿಕೆ_ತಳ;
      DWORD ಹಂಚಿಕೆ_Protect;
      DWORD Region_ಗಾತ್ರ;
      DWORD State;
      DWORD Protect;
      DWORD Type;
    } ಸ್ಮರಣೆ_BASIC_INFORMATION32_2,*PMEMORY_BASIC_INFORMATION32;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ DECLSPEC_ALIGN(16) ಸ್ಮರಣೆ_BASIC_INFORMATION64 {
      ULONGLONG ತಳ_ವಿಳಾಸ;
      ULONGLONG ಹಂಚಿಕೆ_ತಳ;
      DWORD ಹಂಚಿಕೆ_Protect;
      DWORD __alignment1;
      ULONGLONG Region_ಗಾತ್ರ;
      DWORD State;
      DWORD Protect;
      DWORD Type;
      DWORD __alignment2;
    } ಸ್ಮರಣೆ_BASIC_INFORMATION64_2,*PMEMORY_BASIC_INFORMATION64;

#ವ್ಯಾಖ್ಯಾನಿಸು SECTION_QUERY 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು SECTION_MAP_WRITE 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು SECTION_MAP_READ 0x0004
#ವ್ಯಾಖ್ಯಾನಿಸು SECTION_MAP_EXECUTE 0x0008
#ವ್ಯಾಖ್ಯಾನಿಸು SECTION_EXTEND_ಗಾತ್ರ 0x0010
#ವ್ಯಾಖ್ಯಾನಿಸು SECTION_MAP_EXECUTE_EXPLICIT 0x0020

#ವ್ಯಾಖ್ಯಾನಿಸು SECTION_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SECTION_QUERY| SECTION_MAP_WRITE | SECTION_MAP_READ | SECTION_MAP_EXECUTE | SECTION_EXTEND_ಗಾತ್ರ)
#ವ್ಯಾಖ್ಯಾನಿಸು ಪುಟ_NOACCESS 0x01
#ವ್ಯಾಖ್ಯಾನಿಸು ಪುಟ_READONLY 0x02
#ವ್ಯಾಖ್ಯಾನಿಸು ಪುಟ_READWRITE 0x04
#ವ್ಯಾಖ್ಯಾನಿಸು ಪುಟ_WRITECOPY 0x08
#ವ್ಯಾಖ್ಯಾನಿಸು ಪುಟ_EXECUTE 0x10
#ವ್ಯಾಖ್ಯಾನಿಸು ಪುಟ_EXECUTE_READ 0x20
#ವ್ಯಾಖ್ಯಾನಿಸು ಪುಟ_EXECUTE_READWRITE 0x40
#ವ್ಯಾಖ್ಯಾನಿಸು ಪುಟ_EXECUTE_WRITECOPY 0x80
#ವ್ಯಾಖ್ಯಾನಿಸು ಪುಟ_GUARD 0x100
#ವ್ಯಾಖ್ಯಾನಿಸು ಪುಟ_NOCACHE 0x200
#ವ್ಯಾಖ್ಯಾನಿಸು ಪುಟ_WRITECOMBINE 0x400
#ವ್ಯಾಖ್ಯಾನಿಸು MEM_COMMIT 0x1000
#ವ್ಯಾಖ್ಯಾನಿಸು MEM_RESERVE 0x2000
#ವ್ಯಾಖ್ಯಾನಿಸು MEM_DECOMMIT 0x4000
#ವ್ಯಾಖ್ಯಾನಿಸು MEM_RELEASE 0x8000
#ವ್ಯಾಖ್ಯಾನಿಸು MEM_FREE 0x10000
#ವ್ಯಾಖ್ಯಾನಿಸು MEM_ಖಾಸಗಿ 0x20000
#ವ್ಯಾಖ್ಯಾನಿಸು MEM_MAPPED 0x40000
#ವ್ಯಾಖ್ಯಾನಿಸು MEM_RESET 0x80000
#ವ್ಯಾಖ್ಯಾನಿಸು MEM_ತುದಿ_ಕೆಳಕ್ಕೆ 0x100000
#ವ್ಯಾಖ್ಯಾನಿಸು MEM_WRITE_WATCH 0x200000
#ವ್ಯಾಖ್ಯಾನಿಸು MEM_PHYSICAL 0x400000
#ವ್ಯಾಖ್ಯಾನಿಸು MEM_LARGE_ಪುಟಗಳು 0x20000000
#ವ್ಯಾಖ್ಯಾನಿಸು MEM_4_MB_ಪುಟಗಳು 0x80000000
#ವ್ಯಾಖ್ಯಾನಿಸು SEC_FILE 0x800000
#ವ್ಯಾಖ್ಯಾನಿಸು SEC_IMAGE 0x1000000
#ವ್ಯಾಖ್ಯಾನಿಸು SEC_RESERVE 0x4000000
#ವ್ಯಾಖ್ಯಾನಿಸು SEC_COMMIT 0x8000000
#ವ್ಯಾಖ್ಯಾನಿಸು SEC_NOCACHE 0x10000000
#ವ್ಯಾಖ್ಯಾನಿಸು SEC_LARGE_ಪುಟಗಳು 0x80000000
#ವ್ಯಾಖ್ಯಾನಿಸು MEM_IMAGE SEC_IMAGE
#ವ್ಯಾಖ್ಯಾನಿಸು WRITE_WATCH_FLAG_RESET 0x01

#ವ್ಯಾಖ್ಯಾನಿಸು FILE_READ_ದತ್ತಾಂಶ (0x0001)
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_LIST_DIRECTORY (0x0001)

#ವ್ಯಾಖ್ಯಾನಿಸು FILE_WRITE_ದತ್ತಾಂಶ (0x0002)
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_ಕೂಡಿಸು_FILE (0x0002)

#ವ್ಯಾಖ್ಯಾನಿಸು FILE_APPEND_ದತ್ತಾಂಶ (0x0004)
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_ಕೂಡಿಸು_SUBDIRECTORY (0x0004)
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_CREATE_PIPE_INSTANCE (0x0004)

#ವ್ಯಾಖ್ಯಾನಿಸು FILE_READ_EA (0x0008)

#ವ್ಯಾಖ್ಯಾನಿಸು FILE_WRITE_EA (0x0010)

#ವ್ಯಾಖ್ಯಾನಿಸು FILE_EXECUTE (0x0020)
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_TRAVERSE (0x0020)

#ವ್ಯಾಖ್ಯಾನಿಸು FILE_DELETE_ಮಗು (0x0040)

#ವ್ಯಾಖ್ಯಾನಿಸು FILE_READ_ಗುಣಲಕ್ಷಣಗಳು (0x0080)

#ವ್ಯಾಖ್ಯಾನಿಸು FILE_WRITE_ಗುಣಲಕ್ಷಣಗಳು (0x0100)

#ವ್ಯಾಖ್ಯಾನಿಸು FILE_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0x1FF)
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_GENERIC_READ (STANDARD_RIGHTS_READ | FILE_READ_ದತ್ತಾಂಶ | FILE_READ_ಗುಣಲಕ್ಷಣಗಳು | FILE_READ_EA | SYNCHRONIZE)
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_GENERIC_WRITE (STANDARD_RIGHTS_WRITE | FILE_WRITE_ದತ್ತಾಂಶ | FILE_WRITE_ಗುಣಲಕ್ಷಣಗಳು | FILE_WRITE_EA | FILE_APPEND_ದತ್ತಾಂಶ | SYNCHRONIZE)
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_GENERIC_EXECUTE (STANDARD_RIGHTS_EXECUTE | FILE_READ_ಗುಣಲಕ್ಷಣಗಳು | FILE_EXECUTE | SYNCHRONIZE)

#ವ್ಯಾಖ್ಯಾನಿಸು FILE_SHARE_READ 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_SHARE_WRITE 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_SHARE_DELETE 0x00000004
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_ATTRIBUTE_READONLY 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_ATTRIBUTE_HIDDEN 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_ATTRIBUTE_SYSTEM 0x00000004
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_ATTRIBUTE_DIRECTORY 0x00000010
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_ATTRIBUTE_ARCHIVE 0x00000020
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_ATTRIBUTE_DEVICE 0x00000040
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_ATTRIBUTE_ಸಾಮಾನ್ಯ 0x00000080
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_ATTRIBUTE_TEMPORARY 0x00000100
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_ATTRIBUTE_SPARSE_FILE 0x00000200
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_ATTRIBUTE_REPARSE_ಬಿಂದು 0x00000400
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_ATTRIBUTE_COMPRESSED 0x00000800
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_ATTRIBUTE_OFFLINE 0x00001000
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_ATTRIBUTE_NOT_CONTENT_ಸೂಚ್ಯಂಕಿತ 0x00002000
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_ATTRIBUTE_ENCRYPTED 0x00004000
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_NOTIFY_CHANGE_FILE_NAME 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_NOTIFY_CHANGE_DIR_NAME 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_NOTIFY_CHANGE_ಗುಣಲಕ್ಷಣಗಳು 0x00000004
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_NOTIFY_CHANGE_ಗಾತ್ರ 0x00000008
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_NOTIFY_CHANGE_ಕೊನೆಯ_WRITE 0x00000010
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_NOTIFY_CHANGE_ಕೊನೆಯ_ACCESS 0x00000020
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_NOTIFY_CHANGE_CREATION 0x00000040
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_NOTIFY_CHANGE_SECURITY 0x00000100
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_ACTION_ADDED 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_ACTION_REMOVED 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_ACTION_MODIFIED 0x00000003
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_ACTION_RENAMED_OLD_NAME 0x00000004
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_ACTION_RENAMED_NEW_NAME 0x00000005
#ವ್ಯಾಖ್ಯಾನಿಸು MAILSLOT_NO_ಸಂದೇಶ ((DWORD)-1)
#ವ್ಯಾಖ್ಯಾನಿಸು MAILSLOT_WAIT_FOREVER ((DWORD)-1)
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_CASE_SENSITIVE_ಹುಡುಕು 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_CASE_PRESERVED_ಹೆಸರುಗಳು 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_UNICODE_ON_DISK 0x00000004
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_PERSISTENT_ACLS 0x00000008
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_FILE_COMPRESSION 0x00000010
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_VOLUME_QUOTAS 0x00000020
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_SUPPORTS_SPARSE_FILES 0x00000040
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_SUPPORTS_REPARSE_POINTS 0x00000080
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_SUPPORTS_REMOTE_STORAGE 0x00000100
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_VOLUME_IS_COMPRESSED 0x00008000
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_SUPPORTS_OBJECT_IDS 0x00010000
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_SUPPORTS_ENCRYPTION 0x00020000
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_NAMED_STREAMS 0x00040000
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_READ_ONLY_VOLUME 0x00080000

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _FILE_NOTIFY_INFORMATION {
      DWORD ಮುಂದಿನ_ನಮೂದು_ಸ್ಥಾನಾಂತರ;
      DWORD Action;
      DWORD File_Name_ಉದ್ದಳತೆ;
      WCHAR FileName[1];
    } FILE_NOTIFY_INFORMATION,*PFILE_NOTIFY_INFORMATION;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಒಕ್ಕೂಟ _FILE_SEGMENT_ELEMENT {
      PVOID64 ಬಫರ್_3;
      ULONGLONG Alignment;
    }FILE_SEGMENT_ELEMENT,*PFILE_SEGMENT_ELEMENT;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ REPARSE_GUID_ದತ್ತಾಂಶ_ಬಫರ್ {
      DWORD Reparse_ಟ್ಯಾಗ್;
      ಶಬ್ದ_3 Reparse_ದತ್ತಾಂಶ_ಉದ್ದಳತೆ;
      ಶಬ್ದ_3 Reserved;
      GUID ReparseGuid;
      ರಚನೆ {
	BYTE ದತ್ತಾಂಶ_ಬಫರ್[1];
      } Generic_Reparse_ಬಫರ್;
    } REPARSE_GUID_ದತ್ತಾಂಶ_ಬಫರ್_2,*PREPARSE_GUID_ದತ್ತಾಂಶ_ಬಫರ್;

#ವ್ಯಾಖ್ಯಾನಿಸು REPARSE_GUID_ದತ್ತಾಂಶ_ಬಫರ್_ಶೀರ್ಷಿಕೆ_ಗಾತ್ರ ಕ್ಷೇತ್ರ_ಸ್ಥಾನಾಂತರ(REPARSE_GUID_ದತ್ತಾಂಶ_ಬಫರ್_2,Generic_Reparse_ಬಫರ್)

#ವ್ಯಾಖ್ಯಾನಿಸು ಗರಿಷ್ಠ_REPARSE_ದತ್ತಾಂಶ_ಬಫರ್_ಗಾತ್ರ (16 *1024)

#ವ್ಯಾಖ್ಯಾನಿಸು IO_REPARSE_ಟ್ಯಾಗ್_RESERVED_ZERO (0)
#ವ್ಯಾಖ್ಯಾನಿಸು IO_REPARSE_ಟ್ಯಾಗ್_RESERVED_ONE (1)

#ವ್ಯಾಖ್ಯಾನಿಸು IO_REPARSE_ಟ್ಯಾಗ್_RESERVED_RANGE IO_REPARSE_ಟ್ಯಾಗ್_RESERVED_ONE

#ವ್ಯಾಖ್ಯಾನಿಸು Is_Reparse_ಟ್ಯಾಗ್_Microsoft(ಟ್ಯಾಗ್_2) (((ಟ್ಯಾಗ್_2) & 0x80000000))
#ವ್ಯಾಖ್ಯಾನಿಸು Is_Reparse_ಟ್ಯಾಗ್_Name_Surrogate(ಟ್ಯಾಗ್_2) (((ಟ್ಯಾಗ್_2) & 0x20000000))

#ವ್ಯಾಖ್ಯಾನಿಸು IO_REPARSE_ಟ್ಯಾಗ್_MOUNT_ಬಿಂದು (0xA0000003L)
#ವ್ಯಾಖ್ಯಾನಿಸು IO_REPARSE_ಟ್ಯಾಗ್_HSM (0xC0000004L)
#ವ್ಯಾಖ್ಯಾನಿಸು IO_REPARSE_ಟ್ಯಾಗ್_SIS (0x80000007L)
#ವ್ಯಾಖ್ಯಾನಿಸು IO_REPARSE_ಟ್ಯಾಗ್_DFS (0x8000000AL)
#ವ್ಯಾಖ್ಯಾನಿಸು IO_REPARSE_ಟ್ಯಾಗ್_FILTER_MANAGER (0x8000000BL)
#ವ್ಯಾಖ್ಯಾನಿಸು IO_COMPLETION_MODIFY_STATE 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು IO_COMPLETION_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x3)
#ವ್ಯಾಖ್ಯಾನಿಸು DUPLICATE_CLOSE_ಮೂಲ 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು DUPLICATE_SAME_ACCESS 0x00000002

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಎಣಿಕೆ _SYSTEM_POWER_STATE {
      PowerSystemUnspecified = 0,PowerSystemWorking = 1,PowerSystemSleeping1 = 2,PowerSystemSleeping2 = 3,PowerSystemSleeping3 = 4,PowerSystemHibernate = 5,PowerSystemShutdown = 6,Power_System_ಗರಿಷ್ಠ = 7
    } SYSTEM_POWER_STATE,*PSYSTEM_POWER_STATE;

#ವ್ಯಾಖ್ಯಾನಿಸು POWER_SYSTEM_ಗರಿಷ್ಠ 7

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಎಣಿಕೆ {
      PowerActionNone = 0,PowerActionReserved,PowerActionSleep,PowerActionHibernate,PowerActionShutdown,PowerActionShutdownReset,PowerActionShutdownOff,PowerActionWarmEject
    } POWER_ACTION,*PPOWER_ACTION;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಎಣಿಕೆ _DEVICE_POWER_STATE {
      PowerDeviceUnspecified = 0,PowerDeviceD0,PowerDeviceD1,PowerDeviceD2,PowerDeviceD3,Power_Device_ಗರಿಷ್ಠ
    } DEVICE_POWER_STATE,*PDEVICE_POWER_STATE;

#ವ್ಯಾಖ್ಯಾನಿಸು ES_SYSTEM_REQUIRED ((DWORD)0x00000001)
#ವ್ಯಾಖ್ಯಾನಿಸು ES_DISPLAY_REQUIRED ((DWORD)0x00000002)
#ವ್ಯಾಖ್ಯಾನಿಸು ES_USER_PRESENT ((DWORD)0x00000004)
#ವ್ಯಾಖ್ಯಾನಿಸು ES_CONTINUOUS ((DWORD)0x80000000)

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ DWORD EXECUTION_STATE;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಎಣಿಕೆ {
      LT_DONT_CARE,LT_ಅತಿಕಡಿಮೆ_LATENCY
    } LATENCY_ಸಮಯ;

#ವ್ಯಾಖ್ಯಾನಿಸು PDCAP_D0_SUPPORTED 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು PDCAP_D1_SUPPORTED 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು PDCAP_D2_SUPPORTED 0x00000004
#ವ್ಯಾಖ್ಯಾನಿಸು PDCAP_D3_SUPPORTED 0x00000008
#ವ್ಯಾಖ್ಯಾನಿಸು PDCAP_WAKE_FROM_D0_SUPPORTED 0x00000010
#ವ್ಯಾಖ್ಯಾನಿಸು PDCAP_WAKE_FROM_D1_SUPPORTED 0x00000020
#ವ್ಯಾಖ್ಯಾನಿಸು PDCAP_WAKE_FROM_D2_SUPPORTED 0x00000040
#ವ್ಯಾಖ್ಯಾನಿಸು PDCAP_WAKE_FROM_D3_SUPPORTED 0x00000080
#ವ್ಯಾಖ್ಯಾನಿಸು PDCAP_WARM_EJECT_SUPPORTED 0x00000100

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ CM_Power_ದತ್ತಾಂಶ_s {
      DWORD PD_ಗಾತ್ರ;
      DEVICE_POWER_STATE PD_MostRecentPowerState;
      DWORD PD_Capabilities;
      DWORD PD_D1Latency;
      DWORD PD_D2Latency;
      DWORD PD_D3Latency;
      DEVICE_POWER_STATE PD_PowerStateMapping[POWER_SYSTEM_ಗರಿಷ್ಠ];
      SYSTEM_POWER_STATE PD_ಅತ್ಯಂತಆಳ_System_Wake;
    } CM_POWER_ದತ್ತಾಂಶ,*PCM_POWER_ದತ್ತಾಂಶ;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಎಣಿಕೆ {
      SystemPowerPolicyAc,SystemPowerPolicyDc,VerifySystemPolicyAc,VerifySystemPolicyDc,SystemPowerCapabilities,SystemBatteryState,SystemPowerStateHandler,ProcessorStateHandler,SystemPowerPolicyCurrent,AdministratorPowerPolicy,SystemReserveHiberFile,ProcessorInformation,SystemPowerInformation,ProcessorStateHandler2,ಕೊನೆಯ_Wake_ಸಮಯ,ಕೊನೆಯ_Sleep_ಸಮಯ,SystemExecutionState,SystemPowerStateNotifyHandler,ProcessorPowerPolicyAc,ProcessorPowerPolicyDc,VerifyProcessorPowerPolicyAc,VerifyProcessorPowerPolicyDc,ProcessorPowerPolicyCurrent,SystemPowerStateLogging,System_Power_Logging_ನಮೂದು
    } POWER_INFORMATION_LEVEL;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ {
      DWORD Granularity;
      DWORD ಸಾಮರ್ಥ್ಯ;
    } BATTERY_REPORTING_SCALE,*PBATTERY_REPORTING_SCALE;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ {
      POWER_ACTION Action;
      DWORD Flags;
      DWORD Event_ಸಂಕೇತ;
    } POWER_ACTION_POLICY,*PPOWER_ACTION_POLICY;

#ವ್ಯಾಖ್ಯಾನಿಸು POWER_ACTION_QUERY_ALLOWED 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು POWER_ACTION_UI_ALLOWED 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು POWER_ACTION_OVERRIDE_APPS 0x00000004
#ವ್ಯಾಖ್ಯಾನಿಸು POWER_ACTION_LIGHTEST_ಮೊದಲ 0x10000000
#ವ್ಯಾಖ್ಯಾನಿಸು POWER_ACTION_ಬೀಗ_CONSOLE 0x20000000
#ವ್ಯಾಖ್ಯಾನಿಸು POWER_ACTION_DISABLE_WAKES 0x40000000
#ವ್ಯಾಖ್ಯಾನಿಸು POWER_ACTION_CRITICAL 0x80000000

#ವ್ಯಾಖ್ಯಾನಿಸು POWER_LEVEL_USER_NOTIFY_ಪಠ್ಯ 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು POWER_LEVEL_USER_NOTIFY_SOUND 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು POWER_LEVEL_USER_NOTIFY_EXEC 0x00000004
#ವ್ಯಾಖ್ಯಾನಿಸು POWER_USER_NOTIFY_BUTTON 0x00000008
#ವ್ಯಾಖ್ಯಾನಿಸು POWER_USER_NOTIFY_SHUTDOWN 0x00000010
#ವ್ಯಾಖ್ಯಾನಿಸು POWER_FORCE_TRIGGER_RESET 0x80000000

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ {
      BOOLEAN Enable;
      BYTE ಹೆಚ್ಚುವರಿ_2[3];
      DWORD BatteryLevel;
      POWER_ACTION_POLICY PowerPolicy;
      SYSTEM_POWER_STATE MinSystemState;
    } SYSTEM_POWER_LEVEL,*PSYSTEM_POWER_LEVEL;

#ವ್ಯಾಖ್ಯಾನಿಸು ಅಂಕೆ_DISCHARGE_POLICIES 4
#ವ್ಯಾಖ್ಯಾನಿಸು DISCHARGE_POLICY_CRITICAL 0
#ವ್ಯಾಖ್ಯಾನಿಸು DISCHARGE_POLICY_ಕೆಳಗಿನ 1

#ವ್ಯಾಖ್ಯಾನಿಸು PO_THROTTLE_NONE 0
#ವ್ಯಾಖ್ಯಾನಿಸು PO_THROTTLE_CONSTANT 1
#ವ್ಯಾಖ್ಯಾನಿಸು PO_THROTTLE_DEGRADE 2
#ವ್ಯಾಖ್ಯಾನಿಸು PO_THROTTLE_ADAPTIVE 3
#ವ್ಯಾಖ್ಯಾನಿಸು PO_THROTTLE_ಗರಿಷ್ಠ 4

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _SYSTEM_POWER_POLICY {
      DWORD Revision;
      POWER_ACTION_POLICY PowerButton;
      POWER_ACTION_POLICY SleepButton;
      POWER_ACTION_POLICY LidClose;
      SYSTEM_POWER_STATE LidOpenWake;
      DWORD Reserved;
      POWER_ACTION_POLICY Idle;
      DWORD IdleTimeout;
      BYTE Idle_ಸಂವೇದನಾಶೀಲತೆ;
      BYTE DynamicThrottle;
      BYTE Spare2[2];
      SYSTEM_POWER_STATE MinSleep;
      SYSTEM_POWER_STATE MaxSleep;
      SYSTEM_POWER_STATE ReducedLatencySleep;
      DWORD WinLogonFlags;
      DWORD Spare3;
      DWORD DozeS4Timeout;
      DWORD ಪ್ರಸಾರ_ಸಾಮರ್ಥ್ಯ_Resolution;
      SYSTEM_POWER_LEVEL DischargePolicy[ಅಂಕೆ_DISCHARGE_POLICIES];
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

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _PROCESSOR_POWER_POLICY_INFO {
      DWORD ಸಮಯ_Check;
      DWORD Demote_ಎಲ್ಲೆ;
      DWORD Promote_ಎಲ್ಲೆ;
      BYTE DemotePercent;
      BYTE PromotePercent;
      BYTE ಹೆಚ್ಚುವರಿ_2[2];
      DWORD AllowDemotion:1;
      DWORD AllowPromotion:1;
      DWORD Reserved:30;
    } PROCESSOR_POWER_POLICY_INFO,*PPROCESSOR_POWER_POLICY_INFO;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _PROCESSOR_POWER_POLICY {
      DWORD Revision;
      BYTE DynamicThrottle;
      BYTE ಹೆಚ್ಚುವರಿ_2[3];
      DWORD DisableCStates:1;
      DWORD Reserved:31;
      DWORD Policy_ಎಣಿಕೆ;
      PROCESSOR_POWER_POLICY_INFO Policy[3];
    } PROCESSOR_POWER_POLICY,*PPROCESSOR_POWER_POLICY;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _ADMINISTRATOR_POWER_POLICY {
      SYSTEM_POWER_STATE MinSleep;
      SYSTEM_POWER_STATE MaxSleep;
      DWORD MinVideoTimeout;
      DWORD MaxVideoTimeout;
      DWORD MinSpindownTimeout;
      DWORD MaxSpindownTimeout;
    } ADMINISTRATOR_POWER_POLICY,*PADMINISTRATOR_POWER_POLICY;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ {
      BOOLEAN PowerButtonPresent;
      BOOLEAN SleepButtonPresent;
      BOOLEAN LidPresent;
      BOOLEAN SystemS1;
      BOOLEAN SystemS2;
      BOOLEAN SystemS3;
      BOOLEAN SystemS4;
      BOOLEAN SystemS5;
      BOOLEAN HiberFilePresent;
      BOOLEAN ತುಂಬಿದ_Wake;
      BOOLEAN VideoDimPresent;
      BOOLEAN ApmPresent;
      BOOLEAN UpsPresent;
      BOOLEAN ThermalControl;
      BOOLEAN ProcessorThrottle;
      BYTE ProcessorMinThrottle;
      BYTE ProcessorMaxThrottle;
      BYTE spare2[4];
      BOOLEAN Disk_Spin_ಕೆಳಕ್ಕೆ;
      BYTE spare3[8];
      BOOLEAN SystemBatteriesPresent;
      BOOLEAN Batteries_Are_Short_ಪದ;
      BATTERY_REPORTING_SCALE BatteryScale[3];
      SYSTEM_POWER_STATE Ac_On_ಸಾಲು_Wake;
      SYSTEM_POWER_STATE SoftLidWake;
      SYSTEM_POWER_STATE RtcWake;
      SYSTEM_POWER_STATE MinDeviceWakeState;
      SYSTEM_POWER_STATE Default_ಕೆಳಗಿನ_Latency_Wake;
    } SYSTEM_POWER_CAPABILITIES,*PSYSTEM_POWER_CAPABILITIES;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ {
      BOOLEAN Ac_On_ಸಾಲು;
      BOOLEAN BatteryPresent;
      BOOLEAN Charging;
      BOOLEAN Discharging;
      BOOLEAN Spare1[4];
      DWORD Max_ಸಾಮರ್ಥ್ಯ;
      DWORD ಉಳಿದ_ಸಾಮರ್ಥ್ಯ;
      DWORD ದರ;
      DWORD Estimated_ಸಮಯ;
      DWORD DefaultAlert1;
      DWORD DefaultAlert2;
    } SYSTEM_BATTERY_STATE,*PSYSTEM_BATTERY_STATE;

#ಅನ್ತರ್ಭಾವ "pshpack4.h"

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DOS_SIGNATURE 0x5A4D
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_OS2_SIGNATURE 0x454E
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_OS2_SIGNATURE_LE 0x454C
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_VXD_SIGNATURE 0x454C
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_NT_SIGNATURE 0x00004550

#ಅನ್ತರ್ಭಾವ "pshpack2.h"

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ IMAGE_DOS_ಶೀರ್ಷಿಕೆ {
      ಶಬ್ದ_3 e_magic;
      ಶಬ್ದ_3 e_cblp;
      ಶಬ್ದ_3 e_cp;
      ಶಬ್ದ_3 e_crlc;
      ಶಬ್ದ_3 e_cparhdr;
      ಶಬ್ದ_3 e_minalloc;
      ಶಬ್ದ_3 e_maxalloc;
      ಶಬ್ದ_3 e_ss;
      ಶಬ್ದ_3 e_sp;
      ಶಬ್ದ_3 e_csum;
      ಶಬ್ದ_3 e_ip;
      ಶಬ್ದ_3 e_cs;
      ಶಬ್ದ_3 e_lfarlc;
      ಶಬ್ದ_3 e_ovno;
      ಶಬ್ದ_3 e_res[4];
      ಶಬ್ದ_3 e_oemid;
      ಶಬ್ದ_3 e_oeminfo;
      ಶಬ್ದ_3 e_res2[10];
      LONG e_lfanew;
    } IMAGE_DOS_ಶೀರ್ಷಿಕೆ_2,*PIMAGE_DOS_ಶೀರ್ಷಿಕೆ;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ IMAGE_OS2_ಶೀರ್ಷಿಕೆ {
      ಶಬ್ದ_3 ne_magic;
      CHAR ne_ver;
      CHAR ne_rev;
      ಶಬ್ದ_3 ne_enttab;
      ಶಬ್ದ_3 ne_cbenttab;
      LONG ne_ಚಕ್ರೀಯ_ಪರೀಕ್ಷೆ;
      ಶಬ್ದ_3 ne_flags;
      ಶಬ್ದ_3 ne_autodata;
      ಶಬ್ದ_3 ne_ರಾಶಿ;
      ಶಬ್ದ_3 ne_ರಾಶಿ_2;
      LONG ne_csip;
      LONG ne_sssp;
      ಶಬ್ದ_3 ne_cseg;
      ಶಬ್ದ_3 ne_cmod;
      ಶಬ್ದ_3 ne_cbnrestab;
      ಶಬ್ದ_3 ne_segtab;
      ಶಬ್ದ_3 ne_rsrctab;
      ಶಬ್ದ_3 ne_restab;
      ಶಬ್ದ_3 ne_modtab;
      ಶಬ್ದ_3 ne_imptab;
      LONG ne_nrestab;
      ಶಬ್ದ_3 ne_cmovent;
      ಶಬ್ದ_3 ne_align;
      ಶಬ್ದ_3 ne_cres;
      BYTE ne_exetyp;
      BYTE ne_flagsothers;
      ಶಬ್ದ_3 ne_pretthunks;
      ಶಬ್ದ_3 ne_psegrefbytes;
      ಶಬ್ದ_3 ne_swaparea;
      ಶಬ್ದ_3 ne_expver;
    } IMAGE_OS2_ಶೀರ್ಷಿಕೆ_2,*PIMAGE_OS2_ಶೀರ್ಷಿಕೆ;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ IMAGE_VXD_ಶೀರ್ಷಿಕೆ {
      ಶಬ್ದ_3 e32_magic;
      BYTE e32_border;
      BYTE e32_worder;
      DWORD e32_level;
      ಶಬ್ದ_3 e32_cpu;
      ಶಬ್ದ_3 e32_os;
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
      ಶಬ್ದ_3 e32_devid;
      ಶಬ್ದ_3 e32_ddkver;
    } IMAGE_VXD_ಶೀರ್ಷಿಕೆ_2,*PIMAGE_VXD_ಶೀರ್ಷಿಕೆ;

#ಅನ್ತರ್ಭಾವ "poppack.h"

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ IMAGE_FILE_ಶೀರ್ಷಿಕೆ {
      ಶಬ್ದ_3 Machine;
      ಶಬ್ದ_3 ಸಂಖ್ಯೆ_ದ_Sections;
      DWORD ಸಮಯ_Date_Stamp;
      DWORD ಸೂಚಕ_ಗಮ್ಯ_ಚಿಹ್ನೆ_ಕೋಷ್ಟಕ;
      DWORD ಸಂಖ್ಯೆ_ದ_Symbols;
      ಶಬ್ದ_3 ಗಾತ್ರ_ದ_Optional_ಶೀರ್ಷಿಕೆ;
      ಶಬ್ದ_3 Characteristics;
    } IMAGE_FILE_ಶೀರ್ಷಿಕೆ_2,*PIMAGE_FILE_ಶೀರ್ಷಿಕೆ;

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SIZEOF_FILE_ಶೀರ್ಷಿಕೆ 20

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_FILE_RELOCS_STRIPPED 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_FILE_EXECUTABLE_IMAGE 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_FILE_ಸಾಲು_NUMS_STRIPPED 0x0004
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_FILE_LOCAL_SYMS_STRIPPED 0x0008
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_FILE_AGGRESIVE_WS_TRIM 0x0010
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_FILE_LARGE_ವಿಳಾಸ_AWARE 0x0020
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_FILE_ಬೈಟುಗಳು_REVERSED_LO 0x0080
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_FILE_32_ಬಿಟ್_MACHINE 0x0100
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_FILE_DEBUG_STRIPPED 0x0200
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_FILE_REMOVABLE_ಸತತ_FROM_ಅದಲುಬದಲು 0x0400
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_FILE_NET_ಸತತ_FROM_ಅದಲುಬದಲು 0x0800
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_FILE_SYSTEM 0x1000
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_FILE_DLL 0x2000
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_FILE_ಮೇಲೆ_SYSTEM_ONLY 0x4000
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_FILE_ಬೈಟುಗಳು_REVERSED_HI 0x8000

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_FILE_MACHINE_UNKNOWN 0
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_FILE_MACHINE_I386 0x014c
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_FILE_MACHINE_R3000 0x0162
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_FILE_MACHINE_R4000 0x0166
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_FILE_MACHINE_R10000 0x0168
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_FILE_MACHINE_WCEMIPSV2 0x0169
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_FILE_MACHINE_ALPHA 0x0184
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_FILE_MACHINE_SH3 0x01a2
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_FILE_MACHINE_SH3DSP 0x01a3
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_FILE_MACHINE_SH3E 0x01a4
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_FILE_MACHINE_SH4 0x01a6
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_FILE_MACHINE_SH5 0x01a8
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_FILE_MACHINE_ARM 0x01c0
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_FILE_MACHINE_THUMB 0x01c2
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_FILE_MACHINE_AM33 0x01d3
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_FILE_MACHINE_POWERPC 0x01F0
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_FILE_MACHINE_POWERPCFP 0x01f1
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_FILE_MACHINE_IA64 0x0200
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_FILE_MACHINE_MIPS16 0x0266
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_FILE_MACHINE_ALPHA64 0x0284
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_FILE_MACHINE_MIPSFPU 0x0366
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_FILE_MACHINE_MIPSFPU16 0x0466
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_FILE_MACHINE_AXP64 IMAGE_FILE_MACHINE_ALPHA64
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_FILE_MACHINE_TRICORE 0x0520
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_FILE_MACHINE_CEF 0x0CEF
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_FILE_MACHINE_EBC 0x0EBC
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_FILE_MACHINE_AMD64 0x8664
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_FILE_MACHINE_ARM64 0xAA64
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_FILE_MACHINE_M32R 0x9041
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_FILE_MACHINE_CEE 0xC0EE

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ IMAGE_ದತ್ತಾಂಶ_DIRECTORY {
      DWORD Virtual_ವಿಳಾಸ;
      DWORD ಗಾತ್ರ_4;
    } IMAGE_ದತ್ತಾಂಶ_DIRECTORY_2,*PIMAGE_ದತ್ತಾಂಶ_DIRECTORY;

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_NUMBEROF_DIRECTORY_ENTRIES 16

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ IMAGE_OPTIONAL_ಶೀರ್ಷಿಕೆ {

      ಶಬ್ದ_3 Magic;
      BYTE Major_Linker_ಆವೃತ್ತಿ;
      BYTE Minor_Linker_ಆವೃತ್ತಿ;
      DWORD ಗಾತ್ರ_ದ_ಸಂಕೇತ;
      DWORD ಗಾತ್ರ_ದ_Initialized_ದತ್ತಾಂಶ;
      DWORD ಗಾತ್ರ_ದ_Uninitialized_ದತ್ತಾಂಶ;
      DWORD ವಿಳಾಸ_ದ_ನಮೂದು_ಬಿಂದು;
      DWORD ತಳ_ದ_ಸಂಕೇತ;
      DWORD ತಳ_ದ_ದತ್ತಾಂಶ;
      DWORD Image_ತಳ;
      DWORD SectionAlignment;
      DWORD FileAlignment;
      ಶಬ್ದ_3 Major_Operating_System_ಆವೃತ್ತಿ;
      ಶಬ್ದ_3 Minor_Operating_System_ಆವೃತ್ತಿ;
      ಶಬ್ದ_3 Major_Image_ಆವೃತ್ತಿ;
      ಶಬ್ದ_3 Minor_Image_ಆವೃತ್ತಿ;
      ಶಬ್ದ_3 Major_Subsystem_ಆವೃತ್ತಿ;
      ಶಬ್ದ_3 Minor_Subsystem_ಆವೃತ್ತಿ;
      DWORD Win32_ಆವೃತ್ತಿ_ಮೌಲ್ಯ;
      DWORD ಗಾತ್ರ_ದ_Image;
      DWORD ಗಾತ್ರ_ದ_ಶೀರ್ಷಿಕೆಗಳು;
      DWORD Check_ಮೊತ್ತ;
      ಶಬ್ದ_3 Subsystem;
      ಶಬ್ದ_3 DllCharacteristics;
      DWORD ಗಾತ್ರ_ದ_ರಾಶಿ_Reserve;
      DWORD ಗಾತ್ರ_ದ_ರಾಶಿ_Commit;
      DWORD ಗಾತ್ರ_ದ_ರಾಶಿ_Reserve_2;
      DWORD ಗಾತ್ರ_ದ_ರಾಶಿ_Commit_2;
      DWORD LoaderFlags;
      DWORD ಸಂಖ್ಯೆ_ದ_Rva_And_Sizes;
      IMAGE_ದತ್ತಾಂಶ_DIRECTORY_2 ದತ್ತಾಂಶ_Directory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
    } IMAGE_OPTIONAL_HEADER32,*PIMAGE_OPTIONAL_HEADER32;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ IMAGE_ROM_OPTIONAL_ಶೀರ್ಷಿಕೆ {
      ಶಬ್ದ_3 Magic;
      BYTE Major_Linker_ಆವೃತ್ತಿ;
      BYTE Minor_Linker_ಆವೃತ್ತಿ;
      DWORD ಗಾತ್ರ_ದ_ಸಂಕೇತ;
      DWORD ಗಾತ್ರ_ದ_Initialized_ದತ್ತಾಂಶ;
      DWORD ಗಾತ್ರ_ದ_Uninitialized_ದತ್ತಾಂಶ;
      DWORD ವಿಳಾಸ_ದ_ನಮೂದು_ಬಿಂದು;
      DWORD ತಳ_ದ_ಸಂಕೇತ;
      DWORD ತಳ_ದ_ದತ್ತಾಂಶ;
      DWORD ತಳ_ದ_Bss;
      DWORD Gpr_ಮುಖವಾಡ;
      DWORD Cpr_ಮುಖವಾಡ[4];
      DWORD Gp_ಮೌಲ್ಯ;
    } IMAGE_ROM_OPTIONAL_ಶೀರ್ಷಿಕೆ_2,*PIMAGE_ROM_OPTIONAL_ಶೀರ್ಷಿಕೆ;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _IMAGE_OPTIONAL_HEADER64 {
      ಶಬ್ದ_3 Magic;
      BYTE Major_Linker_ಆವೃತ್ತಿ;
      BYTE Minor_Linker_ಆವೃತ್ತಿ;
      DWORD ಗಾತ್ರ_ದ_ಸಂಕೇತ;
      DWORD ಗಾತ್ರ_ದ_Initialized_ದತ್ತಾಂಶ;
      DWORD ಗಾತ್ರ_ದ_Uninitialized_ದತ್ತಾಂಶ;
      DWORD ವಿಳಾಸ_ದ_ನಮೂದು_ಬಿಂದು;
      DWORD ತಳ_ದ_ಸಂಕೇತ;
      ULONGLONG Image_ತಳ;
      DWORD SectionAlignment;
      DWORD FileAlignment;
      ಶಬ್ದ_3 Major_Operating_System_ಆವೃತ್ತಿ;
      ಶಬ್ದ_3 Minor_Operating_System_ಆವೃತ್ತಿ;
      ಶಬ್ದ_3 Major_Image_ಆವೃತ್ತಿ;
      ಶಬ್ದ_3 Minor_Image_ಆವೃತ್ತಿ;
      ಶಬ್ದ_3 Major_Subsystem_ಆವೃತ್ತಿ;
      ಶಬ್ದ_3 Minor_Subsystem_ಆವೃತ್ತಿ;
      DWORD Win32_ಆವೃತ್ತಿ_ಮೌಲ್ಯ;
      DWORD ಗಾತ್ರ_ದ_Image;
      DWORD ಗಾತ್ರ_ದ_ಶೀರ್ಷಿಕೆಗಳು;
      DWORD Check_ಮೊತ್ತ;
      ಶಬ್ದ_3 Subsystem;
      ಶಬ್ದ_3 DllCharacteristics;
      ULONGLONG ಗಾತ್ರ_ದ_ರಾಶಿ_Reserve;
      ULONGLONG ಗಾತ್ರ_ದ_ರಾಶಿ_Commit;
      ULONGLONG ಗಾತ್ರ_ದ_ರಾಶಿ_Reserve_2;
      ULONGLONG ಗಾತ್ರ_ದ_ರಾಶಿ_Commit_2;
      DWORD LoaderFlags;
      DWORD ಸಂಖ್ಯೆ_ದ_Rva_And_Sizes;
      IMAGE_ದತ್ತಾಂಶ_DIRECTORY_2 ದತ್ತಾಂಶ_Directory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
    } IMAGE_OPTIONAL_HEADER64,*PIMAGE_OPTIONAL_HEADER64;

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SIZEOF_ROM_OPTIONAL_ಶೀರ್ಷಿಕೆ 56
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SIZEOF_STD_OPTIONAL_ಶೀರ್ಷಿಕೆ 28
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SIZEOF_NT_OPTIONAL32_ಶೀರ್ಷಿಕೆ 224
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SIZEOF_NT_OPTIONAL64_ಶೀರ್ಷಿಕೆ 240

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_NT_OPTIONAL_HDR32_MAGIC 0x10b
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_NT_OPTIONAL_HDR64_MAGIC 0x20b
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_ROM_OPTIONAL_HDR_MAGIC 0x107

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN64
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ IMAGE_OPTIONAL_HEADER64 IMAGE_OPTIONAL_ಶೀರ್ಷಿಕೆ_2;
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PIMAGE_OPTIONAL_HEADER64 PIMAGE_OPTIONAL_ಶೀರ್ಷಿಕೆ;
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SIZEOF_NT_OPTIONAL_ಶೀರ್ಷಿಕೆ IMAGE_SIZEOF_NT_OPTIONAL64_ಶೀರ್ಷಿಕೆ
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_NT_OPTIONAL_HDR_MAGIC IMAGE_NT_OPTIONAL_HDR64_MAGIC
#ಇಲ್ಲದಿದ್ದರೆ
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ IMAGE_OPTIONAL_HEADER32 IMAGE_OPTIONAL_ಶೀರ್ಷಿಕೆ_2;
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PIMAGE_OPTIONAL_HEADER32 PIMAGE_OPTIONAL_ಶೀರ್ಷಿಕೆ;
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SIZEOF_NT_OPTIONAL_ಶೀರ್ಷಿಕೆ IMAGE_SIZEOF_NT_OPTIONAL32_ಶೀರ್ಷಿಕೆ
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_NT_OPTIONAL_HDR_MAGIC IMAGE_NT_OPTIONAL_HDR32_MAGIC
#ಆದರೆ_ಅಂತ್ಯ

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _IMAGE_NT_HEADERS64 {
      DWORD Signature;
      IMAGE_FILE_ಶೀರ್ಷಿಕೆ_2 File_ಶೀರ್ಷಿಕೆ;
      IMAGE_OPTIONAL_HEADER64 Optional_ಶೀರ್ಷಿಕೆ;
    } IMAGE_NT_HEADERS64,*PIMAGE_NT_HEADERS64;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ IMAGE_NT_ಶೀರ್ಷಿಕೆಗಳು {
      DWORD Signature;
      IMAGE_FILE_ಶೀರ್ಷಿಕೆ_2 File_ಶೀರ್ಷಿಕೆ;
      IMAGE_OPTIONAL_HEADER32 Optional_ಶೀರ್ಷಿಕೆ;
    } IMAGE_NT_HEADERS32,*PIMAGE_NT_HEADERS32;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ IMAGE_ROM_ಶೀರ್ಷಿಕೆಗಳು {
      IMAGE_FILE_ಶೀರ್ಷಿಕೆ_2 File_ಶೀರ್ಷಿಕೆ;
      IMAGE_ROM_OPTIONAL_ಶೀರ್ಷಿಕೆ_2 Optional_ಶೀರ್ಷಿಕೆ;
    } IMAGE_ROM_ಶೀರ್ಷಿಕೆಗಳು_2,*PIMAGE_ROM_ಶೀರ್ಷಿಕೆಗಳು;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN64
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ IMAGE_NT_HEADERS64 IMAGE_NT_ಶೀರ್ಷಿಕೆಗಳು_2;
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PIMAGE_NT_HEADERS64 PIMAGE_NT_ಶೀರ್ಷಿಕೆಗಳು;
#ಇಲ್ಲದಿದ್ದರೆ
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ IMAGE_NT_HEADERS32 IMAGE_NT_ಶೀರ್ಷಿಕೆಗಳು_2;
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PIMAGE_NT_HEADERS32 PIMAGE_NT_ಶೀರ್ಷಿಕೆಗಳು;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_ಮೊದಲ_SECTION(ntheader) ((PIMAGE_SECTION_ಶೀರ್ಷಿಕೆ) ((ULONG_PTR)ntheader + ಕ್ಷೇತ್ರ_ಸ್ಥಾನಾಂತರ(IMAGE_NT_ಶೀರ್ಷಿಕೆಗಳು_2,Optional_ಶೀರ್ಷಿಕೆ) + ((PIMAGE_NT_ಶೀರ್ಷಿಕೆಗಳು)(ntheader))->File_ಶೀರ್ಷಿಕೆ.ಗಾತ್ರ_ದ_Optional_ಶೀರ್ಷಿಕೆ))

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SUBSYSTEM_UNKNOWN 0
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SUBSYSTEM_NATIVE 1
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SUBSYSTEM_WINDOWS_GUI 2
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SUBSYSTEM_WINDOWS_CUI 3
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SUBSYSTEM_OS2_CUI 5
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SUBSYSTEM_POSIX_CUI 7
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SUBSYSTEM_NATIVE_WINDOWS 8
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SUBSYSTEM_WINDOWS_CE_GUI 9
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SUBSYSTEM_EFI_APPLICATION 10
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SUBSYSTEM_EFI_BOOT_SERVICE_DRIVER 11
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SUBSYSTEM_EFI_RUNTIME_DRIVER 12
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SUBSYSTEM_EFI_ROM 13
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SUBSYSTEM_XBOX 14

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DLLCHARACTERISTICS_ಮೇಲಿನ_ENTROPY_VA 0x0020
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DLLCHARACTERISTICS_DYNAMIC_ತಳ 0x0040
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DLLCHARACTERISTICS_FORCE_INTEGRITY 0x0080
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DLLCHARACTERISTICS_NX_COMPAT 0x0100
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DLLCHARACTERISTICS_NO_ISOLATION 0x0200
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DLLCHARACTERISTICS_NO_SEH 0x0400
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DLLCHARACTERISTICS_NO_BIND 0x0800
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DLLCHARACTERISTICS_APPCONTAINER 0x1000
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DLLCHARACTERISTICS_WDM_DRIVER 0x2000
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DLLCHARACTERISTICS_GUARD_CF 0x4000
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DLLCHARACTERISTICS_TERMINAL_SERVER_AWARE 0x8000

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DIRECTORY_ನಮೂದು_EXPORT 0
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DIRECTORY_ನಮೂದು_IMPORT 1
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DIRECTORY_ನಮೂದು_RESOURCE 2
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DIRECTORY_ನಮೂದು_EXCEPTION 3
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DIRECTORY_ನಮೂದು_SECURITY 4
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DIRECTORY_ನಮೂದು_BASERELOC 5
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DIRECTORY_ನಮೂದು_DEBUG 6

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DIRECTORY_ನಮೂದು_ARCHITECTURE 7
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DIRECTORY_ನಮೂದು_GLOBALPTR 8
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DIRECTORY_ನಮೂದು_TLS 9
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DIRECTORY_ನಮೂದು_ತುಂಬು_CONFIG 10
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DIRECTORY_ನಮೂದು_BOUND_IMPORT 11
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DIRECTORY_ನಮೂದು_IAT 12
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DIRECTORY_ನಮೂದು_DELAY_IMPORT 13
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DIRECTORY_ನಮೂದು_COM_DESCRIPTOR 14

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ANON_OBJECT_ಶೀರ್ಷಿಕೆ {
      ಶಬ್ದ_3 Sig1;
      ಶಬ್ದ_3 Sig2;
      ಶಬ್ದ_3 ಆವೃತ್ತಿ_2;
      ಶಬ್ದ_3 Machine;
      DWORD ಸಮಯ_Date_Stamp;
      CLSID ClassID;
      DWORD ಗಾತ್ರ_ದ_ದತ್ತಾಂಶ;
    } ANON_OBJECT_ಶೀರ್ಷಿಕೆ;

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SIZEOF_SHORT_NAME 8

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ IMAGE_SECTION_ಶೀರ್ಷಿಕೆ {
      BYTE Name[IMAGE_SIZEOF_SHORT_NAME];
      ಒಕ್ಕೂಟ {
	DWORD Physical_ವಿಳಾಸ;
	DWORD Virtual_ಗಾತ್ರ;
      } Misc;
      DWORD Virtual_ವಿಳಾಸ;
      DWORD ಗಾತ್ರ_ದ_Raw_ದತ್ತಾಂಶ;
      DWORD ಸೂಚಕ_ಗಮ್ಯ_Raw_ದತ್ತಾಂಶ;
      DWORD ಸೂಚಕ_ಗಮ್ಯ_Relocations;
      DWORD ಸೂಚಕ_ಗಮ್ಯ_Linenumbers;
      ಶಬ್ದ_3 ಸಂಖ್ಯೆ_ದ_Relocations;
      ಶಬ್ದ_3 ಸಂಖ್ಯೆ_ದ_Linenumbers;
      DWORD Characteristics;
    } IMAGE_SECTION_ಶೀರ್ಷಿಕೆ_2,*PIMAGE_SECTION_ಶೀರ್ಷಿಕೆ;

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SIZEOF_SECTION_ಶೀರ್ಷಿಕೆ 40

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SCN_TYPE_NO_PAD 0x00000008

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SCN_CNT_ಸಂಕೇತ 0x00000020
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SCN_CNT_INITIALIZED_ದತ್ತಾಂಶ 0x00000040
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SCN_CNT_UNINITIALIZED_ದತ್ತಾಂಶ 0x00000080
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SCN_LNK_OTHER 0x00000100
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SCN_LNK_INFO 0x00000200
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SCN_LNK_REMOVE 0x00000800
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SCN_LNK_COMDAT 0x00001000
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SCN_NO_DEFER_SPEC_EXC 0x00004000
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SCN_GPREL 0x00008000
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SCN_MEM_FARDATA 0x00008000
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SCN_MEM_PURGEABLE 0x00020000
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SCN_MEM_16_ಬಿಟ್ 0x00020000
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SCN_MEM_LOCKED 0x00040000
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SCN_MEM_PRELOAD 0x00080000

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SCN_ALIGN_1_ಬೈಟುಗಳು 0x00100000
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SCN_ALIGN_2_ಬೈಟುಗಳು 0x00200000
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SCN_ALIGN_4_ಬೈಟುಗಳು 0x00300000
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SCN_ALIGN_8_ಬೈಟುಗಳು 0x00400000
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SCN_ALIGN_16_ಬೈಟುಗಳು 0x00500000
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SCN_ALIGN_32_ಬೈಟುಗಳು 0x00600000
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SCN_ALIGN_64_ಬೈಟುಗಳು 0x00700000
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SCN_ALIGN_128_ಬೈಟುಗಳು 0x00800000
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SCN_ALIGN_256_ಬೈಟುಗಳು 0x00900000
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SCN_ALIGN_512_ಬೈಟುಗಳು 0x00A00000
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SCN_ALIGN_1024_ಬೈಟುಗಳು 0x00B00000
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SCN_ALIGN_2048_ಬೈಟುಗಳು 0x00C00000
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SCN_ALIGN_4096_ಬೈಟುಗಳು 0x00D00000
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SCN_ALIGN_8192_ಬೈಟುಗಳು 0x00E00000

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SCN_ALIGN_ಮುಖವಾಡ 0x00F00000

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SCN_LNK_NRELOC_OVFL 0x01000000
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SCN_MEM_DISCARDABLE 0x02000000
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SCN_MEM_NOT_CACHED 0x04000000
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SCN_MEM_NOT_PAGED 0x08000000
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SCN_MEM_SHARED 0x10000000
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SCN_MEM_EXECUTE 0x20000000
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SCN_MEM_READ 0x40000000
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SCN_MEM_WRITE 0x80000000

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SCN_SCALE_ಸೂಚ್ಯಂಕ 0x00000001

#ಅನ್ತರ್ಭಾವ "pshpack2.h"

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ IMAGE_ಚಿಹ್ನೆ {
      ಒಕ್ಕೂಟ {
	BYTE ShortName[8];
	ರಚನೆ {
	  DWORD Short;
	  DWORD Long;
	} Name;
	DWORD LongName[2];
      } N;
      DWORD ಮೌಲ್ಯ_3;
      SHORT Section_ಸಂಖ್ಯೆ;
      ಶಬ್ದ_3 Type;
      BYTE StorageClass;
      BYTE ಸಂಖ್ಯೆ_ದ_Aux_Symbols;
    } IMAGE_ಚಿಹ್ನೆ_2;
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ IMAGE_ಚಿಹ್ನೆ_2 UNALIGNED *PIMAGE_ಚಿಹ್ನೆ;

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SIZEOF_ಚಿಹ್ನೆ 18

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SYM_UNDEFINED (SHORT)0
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SYM_ABSOLUTE (SHORT)-1
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SYM_DEBUG (SHORT)-2
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SYM_SECTION_MAX 0xFEFF

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SYM_TYPE_NULL 0x0000
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SYM_TYPE_VOID 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SYM_TYPE_CHAR 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SYM_TYPE_SHORT 0x0003
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SYM_TYPE_INT 0x0004
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SYM_TYPE_LONG 0x0005
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SYM_TYPE_FLOAT 0x0006
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SYM_TYPE_DOUBLE 0x0007
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SYM_TYPE_STRUCT 0x0008
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SYM_TYPE_UNION 0x0009
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SYM_TYPE_ENUM 0x000A
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SYM_TYPE_MOE 0x000B
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SYM_TYPE_BYTE 0x000C
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SYM_TYPE_ಶಬ್ದ 0x000D
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SYM_TYPE_UINT 0x000E
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SYM_TYPE_DWORD 0x000F
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SYM_TYPE_PCODE 0x8000

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SYM_DTYPE_NULL 0
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SYM_DTYPE_ಸೂಚಕ 1
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SYM_DTYPE_FUNCTION 2
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SYM_DTYPE_ARRAY 3

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SYM_CLASS_ಕೊನೆ_ದ_FUNCTION (BYTE)-1
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SYM_CLASS_NULL 0x0000
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SYM_CLASS_AUTOMATIC 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SYM_CLASS_EXTERNAL 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SYM_CLASS_STATIC 0x0003
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SYM_CLASS_ರಿಜಿಸ್ಟರ್ 0x0004
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SYM_CLASS_EXTERNAL_DEF 0x0005
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SYM_CLASS_LABEL 0x0006
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SYM_CLASS_UNDEFINED_LABEL 0x0007
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SYM_CLASS_MEMBER_ದ_STRUCT 0x0008
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SYM_CLASS_ವಾದ 0x0009
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SYM_CLASS_STRUCT_ಟ್ಯಾಗ್ 0x000A
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SYM_CLASS_MEMBER_ದ_UNION 0x000B
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SYM_CLASS_UNION_ಟ್ಯಾಗ್ 0x000C
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SYM_CLASS_TYPE_DEFINITION 0x000D
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SYM_CLASS_UNDEFINED_STATIC 0x000E
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SYM_CLASS_ENUM_ಟ್ಯಾಗ್ 0x000F
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SYM_CLASS_MEMBER_ದ_ENUM 0x0010
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SYM_CLASS_ರಿಜಿಸ್ಟರ್_PARAM 0x0011
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SYM_CLASS_ಬಿಟ್_ಕ್ಷೇತ್ರ 0x0012
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SYM_CLASS_FAR_EXTERNAL 0x0044
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SYM_CLASS_ಖಂಡ 0x0064
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SYM_CLASS_FUNCTION 0x0065
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SYM_CLASS_ಕೊನೆ_ದ_STRUCT 0x0066
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SYM_CLASS_FILE 0x0067
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SYM_CLASS_SECTION 0x0068
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SYM_CLASS_WEAK_EXTERNAL 0x0069
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SYM_CLASS_CLR_TOKEN 0x006B

#ವ್ಯಾಖ್ಯಾನಿಸು N_BTMASK 0x000F
#ವ್ಯಾಖ್ಯಾನಿಸು N_TMASK 0x0030
#ವ್ಯಾಖ್ಯಾನಿಸು N_TMASK1 0x00C0
#ವ್ಯಾಖ್ಯಾನಿಸು N_TMASK2 0x00F0
#ವ್ಯಾಖ್ಯಾನಿಸು N_BTSHFT 4
#ವ್ಯಾಖ್ಯಾನಿಸು N_TSHIFT 2

#ವ್ಯಾಖ್ಯಾನಿಸು BTYPE(x) ((x) & N_BTMASK)

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ ISPTR
#ವ್ಯಾಖ್ಯಾನಿಸು ISPTR(x) (((x) & N_TMASK)==(IMAGE_SYM_DTYPE_ಸೂಚಕ << N_BTSHFT))
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ ISFCN
#ವ್ಯಾಖ್ಯಾನಿಸು ISFCN(x) (((x) & N_TMASK)==(IMAGE_SYM_DTYPE_FUNCTION << N_BTSHFT))
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ ISARY
#ವ್ಯಾಖ್ಯಾನಿಸು ISARY(x) (((x) & N_TMASK)==(IMAGE_SYM_DTYPE_ARRAY << N_BTSHFT))
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ ISTAG
#ವ್ಯಾಖ್ಯಾನಿಸು ISTAG(x) ((x)==IMAGE_SYM_CLASS_STRUCT_ಟ್ಯಾಗ್ || (x)==IMAGE_SYM_CLASS_UNION_ಟ್ಯಾಗ್ || (x)==IMAGE_SYM_CLASS_ENUM_ಟ್ಯಾಗ್)
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ INCREF
#ವ್ಯಾಖ್ಯಾನಿಸು INCREF(x) ((((x)&~N_BTMASK)<<N_TSHIFT)|(IMAGE_SYM_DTYPE_ಸೂಚಕ<<N_BTSHFT)|((x)&N_BTMASK))
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ DECREF
#ವ್ಯಾಖ್ಯಾನಿಸು DECREF(x) ((((x)>>N_TSHIFT)&~N_BTMASK)|((x)&N_BTMASK))
#ಆದರೆ_ಅಂತ್ಯ

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಒಕ್ಕೂಟ IMAGE_AUX_ಚಿಹ್ನೆ {
      ರಚನೆ {
	DWORD ಟ್ಯಾಗ್_ಸೂಚ್ಯಂಕ;
	ಒಕ್ಕೂಟ {
	  ರಚನೆ {
	    ಶಬ್ದ_3 Linenumber;
	    ಶಬ್ದ_3 ಗಾತ್ರ_4;
	  } LnSz;
	  DWORD ಒಟ್ಟು_ಗಾತ್ರ;
	} Misc;
	ಒಕ್ಕೂಟ {
	  ರಚನೆ {
	    DWORD ಸೂಚಕ_ಗಮ್ಯ_Linenumber;
	    DWORD ಸೂಚಕ_ಗಮ್ಯ_ಮುಂದಿನ_Function;
	  } Function;
	  ರಚನೆ {
	    ಶಬ್ದ_3 Dimension[4];
	  } Array;
	} FcnAry;
	ಶಬ್ದ_3 Tv_ಸೂಚ್ಯಂಕ;
      } Sym;
      ರಚನೆ {
	BYTE Name[IMAGE_SIZEOF_ಚಿಹ್ನೆ];
      } File;
      ರಚನೆ {
	DWORD ಉದ್ದಳತೆ_2;
	ಶಬ್ದ_3 ಸಂಖ್ಯೆ_ದ_Relocations;
	ಶಬ್ದ_3 ಸಂಖ್ಯೆ_ದ_Linenumbers;
	DWORD Check_ಮೊತ್ತ;
	SHORT ಸಂಖ್ಯೆ_2;
	BYTE Selection;
      } Section;
    } IMAGE_AUX_ಚಿಹ್ನೆ_2;
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ IMAGE_AUX_ಚಿಹ್ನೆ_2 UNALIGNED *PIMAGE_AUX_ಚಿಹ್ನೆ;

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SIZEOF_AUX_ಚಿಹ್ನೆ 18

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಎಣಿಕೆ IMAGE_AUX_ಚಿಹ್ನೆ_TYPE {
      IMAGE_AUX_ಚಿಹ್ನೆ_TYPE_TOKEN_DEF = 1
    } IMAGE_AUX_ಚಿಹ್ನೆ_TYPE;

#ಅನ್ತರ್ಭಾವ <pshpack2.h>

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ IMAGE_AUX_ಚಿಹ್ನೆ_TOKEN_DEF {
      BYTE bAuxType;
      BYTE bReserved;
      DWORD ಚಿಹ್ನೆ_ಕೋಷ್ಟಕ_ಸೂಚ್ಯಂಕ;
      BYTE rgbReserved[12];
    } IMAGE_AUX_ಚಿಹ್ನೆ_TOKEN_DEF;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ IMAGE_AUX_ಚಿಹ್ನೆ_TOKEN_DEF UNALIGNED *PIMAGE_AUX_ಚಿಹ್ನೆ_TOKEN_DEF;

#ಅನ್ತರ್ಭಾವ <poppack.h>

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_COMDAT_SELECT_NODUPLICATES 1
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_COMDAT_SELECT_ANY 2
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_COMDAT_SELECT_SAME_ಗಾತ್ರ 3
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_COMDAT_SELECT_EXACT_ಹೊಂದಿಕೆ 4
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_COMDAT_SELECT_ASSOCIATIVE 5
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_COMDAT_SELECT_ಅತಿದೊಡ್ಡ 6
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_COMDAT_SELECT_NEWEST 7

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_WEAK_EXTERN_ಹುಡುಕು_NOLIBRARY 1
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_WEAK_EXTERN_ಹುಡುಕು_LIBRARY 2
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_WEAK_EXTERN_ಹುಡುಕು_ALIAS 3

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _IMAGE_RELOCATION {
      ಒಕ್ಕೂಟ {
	DWORD Virtual_ವಿಳಾಸ;
	DWORD Reloc_ಎಣಿಕೆ;
      };
      DWORD ಚಿಹ್ನೆ_ಕೋಷ್ಟಕ_ಸೂಚ್ಯಂಕ;
      ಶಬ್ದ_3 Type;
    } IMAGE_RELOCATION;
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ IMAGE_RELOCATION UNALIGNED *PIMAGE_RELOCATION;

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SIZEOF_RELOCATION 10

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_I386_ABSOLUTE 0x0000
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_I386_DIR16 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_I386_REL16 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_I386_DIR32 0x0006
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_I386_DIR32NB 0x0007
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_I386_SEG12 0x0009
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_I386_SECTION 0x000A
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_I386_SECREL 0x000B
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_I386_TOKEN 0x000C
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_I386_SECREL7 0x000D
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_I386_REL32 0x0014

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_MIPS_ABSOLUTE 0x0000
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_MIPS_REFHALF 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_MIPS_REFWORD 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_MIPS_JMPADDR 0x0003
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_MIPS_REFHI 0x0004
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_MIPS_REFLO 0x0005
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_MIPS_GPREL 0x0006
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_MIPS_LITERAL 0x0007
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_MIPS_SECTION 0x000A
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_MIPS_SECREL 0x000B
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_MIPS_SECRELLO 0x000C
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_MIPS_SECRELHI 0x000D
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_MIPS_TOKEN 0x000E
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_MIPS_JMPADDR16 0x0010
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_MIPS_REFWORDNB 0x0022
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_MIPS_PAIR 0x0025

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_ALPHA_ABSOLUTE 0x0000
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_ALPHA_REFLONG 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_ALPHA_REFQUAD 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_ALPHA_GPREL32 0x0003
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_ALPHA_LITERAL 0x0004
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_ALPHA_LITUSE 0x0005
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_ALPHA_GPDISP 0x0006
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_ALPHA_BRADDR 0x0007
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_ALPHA_HINT 0x0008
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_ALPHA_INLINE_REFLONG 0x0009
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_ALPHA_REFHI 0x000A
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_ALPHA_REFLO 0x000B
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_ALPHA_PAIR 0x000C
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_ALPHA_ಹೊಂದಿಕೆ 0x000D
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_ALPHA_SECTION 0x000E
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_ALPHA_SECREL 0x000F
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_ALPHA_REFLONGNB 0x0010
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_ALPHA_SECRELLO 0x0011
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_ALPHA_SECRELHI 0x0012
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_ALPHA_REFQ3 0x0013
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_ALPHA_REFQ2 0x0014
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_ALPHA_REFQ1 0x0015
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_ALPHA_GPRELLO 0x0016
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_ALPHA_GPRELHI 0x0017

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_PPC_ABSOLUTE 0x0000
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_PPC_ADDR64 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_PPC_ADDR32 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_PPC_ADDR24 0x0003
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_PPC_ADDR16 0x0004
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_PPC_ADDR14 0x0005
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_PPC_REL24 0x0006
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_PPC_REL14 0x0007
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_PPC_TOCREL16 0x0008
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_PPC_TOCREL14 0x0009
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_PPC_ADDR32NB 0x000A
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_PPC_SECREL 0x000B
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_PPC_SECTION 0x000C
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_PPC_IFGLUE 0x000D
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_PPC_IMGLUE 0x000E
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_PPC_SECREL16 0x000F
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_PPC_REFHI 0x0010
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_PPC_REFLO 0x0011
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_PPC_PAIR 0x0012
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_PPC_SECRELLO 0x0013
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_PPC_SECRELHI 0x0014
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_PPC_GPREL 0x0015
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_PPC_TOKEN 0x0016
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_PPC_TYPEMASK 0x00FF
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_PPC_NEG 0x0100
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_PPC_BRTAKEN 0x0200
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_PPC_BRNTAKEN 0x0400
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_PPC_TOCDEFN 0x0800

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_SH3_ABSOLUTE 0x0000
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_SH3_DIRECT16 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_SH3_DIRECT32 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_SH3_DIRECT8 0x0003
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_SH3_DIRECT8_ಶಬ್ದ 0x0004
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_SH3_DIRECT8_LONG 0x0005
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_SH3_DIRECT4 0x0006
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_SH3_DIRECT4_ಶಬ್ದ 0x0007
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_SH3_DIRECT4_LONG 0x0008
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_SH3_PCREL8_ಶಬ್ದ 0x0009
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_SH3_PCREL8_LONG 0x000A
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_SH3_PCREL12_ಶಬ್ದ 0x000B
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_SH3_STARTOF_SECTION 0x000C
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_SH3_SIZEOF_SECTION 0x000D
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_SH3_SECTION 0x000E
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_SH3_SECREL 0x000F
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_SH3_DIRECT32_NB 0x0010
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_SH3_GPREL4_LONG 0x0011
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_SH3_TOKEN 0x0012

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_SHM_PCRELPT 0x0013
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_SHM_REFLO 0x0014
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_SHM_REFHALF 0x0015
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_SHM_RELLO 0x0016
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_SHM_RELHALF 0x0017
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_SHM_PAIR 0x0018

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_SH_NOMODE 0x8000

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_ARM_ABSOLUTE 0x0000
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_ARM_ADDR32 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_ARM_ADDR32NB 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_ARM_BRANCH24 0x0003
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_ARM_BRANCH11 0x0004
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_ARM_TOKEN 0x0005
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_ARM_GPREL12 0x0006
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_ARM_GPREL7 0x0007
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_ARM_BLX24 0x0008
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_ARM_BLX11 0x0009
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_ARM_SECTION 0x000E
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_ARM_SECREL 0x000F

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_AM_ABSOLUTE 0x0000
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_AM_ADDR32 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_AM_ADDR32NB 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_AM_CALL32 0x0003
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_AM_FUNCINFO 0x0004
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_AM_REL32_1 0x0005
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_AM_REL32_2 0x0006
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_AM_SECREL 0x0007
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_AM_SECTION 0x0008
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_AM_TOKEN 0x0009

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_AMD64_ABSOLUTE 0x0000
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_AMD64_ADDR64 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_AMD64_ADDR32 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_AMD64_ADDR32NB 0x0003
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_AMD64_REL32 0x0004
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_AMD64_REL32_1 0x0005
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_AMD64_REL32_2 0x0006
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_AMD64_REL32_3 0x0007
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_AMD64_REL32_4 0x0008
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_AMD64_REL32_5 0x0009
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_AMD64_SECTION 0x000A
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_AMD64_SECREL 0x000B
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_AMD64_SECREL7 0x000C
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_AMD64_TOKEN 0x000D
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_AMD64_SREL32 0x000E
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_AMD64_PAIR 0x000F
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_AMD64_SSPAN32 0x0010

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_IA64_ABSOLUTE 0x0000
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_IA64_IMM14 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_IA64_IMM22 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_IA64_IMM64 0x0003
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_IA64_DIR32 0x0004
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_IA64_DIR64 0x0005
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_IA64_PCREL21B 0x0006
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_IA64_PCREL21M 0x0007
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_IA64_PCREL21F 0x0008
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_IA64_GPREL22 0x0009
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_IA64_LTOFF22 0x000A
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_IA64_SECTION 0x000B
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_IA64_SECREL22 0x000C
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_IA64_SECREL64I 0x000D
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_IA64_SECREL32 0x000E

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_IA64_DIR32NB 0x0010
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_IA64_SREL14 0x0011
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_IA64_SREL22 0x0012
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_IA64_SREL32 0x0013
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_IA64_UREL32 0x0014
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_IA64_PCREL60X 0x0015
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_IA64_PCREL60B 0x0016
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_IA64_PCREL60F 0x0017
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_IA64_PCREL60I 0x0018
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_IA64_PCREL60M 0x0019
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_IA64_IMMGPREL64 0x001A
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_IA64_TOKEN 0x001B
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_IA64_GPREL32 0x001C
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_IA64_ADDEND 0x001F

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_CEF_ABSOLUTE 0x0000
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_CEF_ADDR32 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_CEF_ADDR64 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_CEF_ADDR32NB 0x0003
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_CEF_SECTION 0x0004
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_CEF_SECREL 0x0005
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_CEF_TOKEN 0x0006

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_CEE_ABSOLUTE 0x0000
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_CEE_ADDR32 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_CEE_ADDR64 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_CEE_ADDR32NB 0x0003
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_CEE_SECTION 0x0004
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_CEE_SECREL 0x0005
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_CEE_TOKEN 0x0006

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_M32R_ABSOLUTE 0x0000
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_M32R_ADDR32 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_M32R_ADDR32NB 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_M32R_ADDR24 0x0003
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_M32R_GPREL16 0x0004
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_M32R_PCREL24 0x0005
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_M32R_PCREL16 0x0006
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_M32R_PCREL8 0x0007
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_M32R_REFHALF 0x0008
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_M32R_REFHI 0x0009
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_M32R_REFLO 0x000A
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_M32R_PAIR 0x000B
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_M32R_SECTION 0x000C
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_M32R_SECREL32 0x000D
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_M32R_TOKEN 0x000E

#ವ್ಯಾಖ್ಯಾನಿಸು EXT_IMM64(ಮೌಲ್ಯ_3,ವಿಳಾಸ_2,ಗಾತ್ರ_4,InstPos,ValPos) ಮೌಲ್ಯ_3 |= (((ULONGLONG)((*(ವಿಳಾಸ_2) >> InstPos) & (((ULONGLONG)1 << ಗಾತ್ರ_4) - 1))) << ValPos)
#ವ್ಯಾಖ್ಯಾನಿಸು INS_IMM64(ಮೌಲ್ಯ_3,ವಿಳಾಸ_2,ಗಾತ್ರ_4,InstPos,ValPos) *(PDWORD)ವಿಳಾಸ_2 = (*(PDWORD)ವಿಳಾಸ_2 & ~(((1 << ಗಾತ್ರ_4) - 1) << InstPos)) | ((DWORD)((((ULONGLONG)ಮೌಲ್ಯ_3 >> ValPos) & (((ULONGLONG)1 << ಗಾತ್ರ_4) - 1))) << InstPos)

#ವ್ಯಾಖ್ಯಾನಿಸು EMARCH_ENC_I17_IMM7_B_INST_ಶಬ್ದ_X 3
#ವ್ಯಾಖ್ಯಾನಿಸು EMARCH_ENC_I17_IMM7_B_ಗಾತ್ರ_X 7
#ವ್ಯಾಖ್ಯಾನಿಸು EMARCH_ENC_I17_IMM7_B_INST_ಶಬ್ದ_POS_X 4
#ವ್ಯಾಖ್ಯಾನಿಸು EMARCH_ENC_I17_IMM7B_VAL_POS_X 0

#ವ್ಯಾಖ್ಯಾನಿಸು EMARCH_ENC_I17_IMM9_D_INST_ಶಬ್ದ_X 3
#ವ್ಯಾಖ್ಯಾನಿಸು EMARCH_ENC_I17_IMM9_D_ಗಾತ್ರ_X 9
#ವ್ಯಾಖ್ಯಾನಿಸು EMARCH_ENC_I17_IMM9_D_INST_ಶಬ್ದ_POS_X 18
#ವ್ಯಾಖ್ಯಾನಿಸು EMARCH_ENC_I17_IMM9D_VAL_POS_X 7

#ವ್ಯಾಖ್ಯಾನಿಸು EMARCH_ENC_I17_IMM5_C_INST_ಶಬ್ದ_X 3
#ವ್ಯಾಖ್ಯಾನಿಸು EMARCH_ENC_I17_IMM5_C_ಗಾತ್ರ_X 5
#ವ್ಯಾಖ್ಯಾನಿಸು EMARCH_ENC_I17_IMM5_C_INST_ಶಬ್ದ_POS_X 13
#ವ್ಯಾಖ್ಯಾನಿಸು EMARCH_ENC_I17_IMM5C_VAL_POS_X 16

#ವ್ಯಾಖ್ಯಾನಿಸು EMARCH_ENC_I17_IC_INST_ಶಬ್ದ_X 3
#ವ್ಯಾಖ್ಯಾನಿಸು EMARCH_ENC_I17_IC_ಗಾತ್ರ_X 1
#ವ್ಯಾಖ್ಯಾನಿಸು EMARCH_ENC_I17_IC_INST_ಶಬ್ದ_POS_X 12
#ವ್ಯಾಖ್ಯಾನಿಸು EMARCH_ENC_I17_IC_VAL_POS_X 21

#ವ್ಯಾಖ್ಯಾನಿಸು EMARCH_ENC_I17_IMM41a_INST_ಶಬ್ದ_X 1
#ವ್ಯಾಖ್ಯಾನಿಸು EMARCH_ENC_I17_IMM41a_ಗಾತ್ರ_X 10
#ವ್ಯಾಖ್ಯಾನಿಸು EMARCH_ENC_I17_IMM41a_INST_ಶಬ್ದ_POS_X 14
#ವ್ಯಾಖ್ಯಾನಿಸು EMARCH_ENC_I17_IMM41a_VAL_POS_X 22

#ವ್ಯಾಖ್ಯಾನಿಸು EMARCH_ENC_I17_IMM41b_INST_ಶಬ್ದ_X 1
#ವ್ಯಾಖ್ಯಾನಿಸು EMARCH_ENC_I17_IMM41b_ಗಾತ್ರ_X 8
#ವ್ಯಾಖ್ಯಾನಿಸು EMARCH_ENC_I17_IMM41b_INST_ಶಬ್ದ_POS_X 24
#ವ್ಯಾಖ್ಯಾನಿಸು EMARCH_ENC_I17_IMM41b_VAL_POS_X 32

#ವ್ಯಾಖ್ಯಾನಿಸು EMARCH_ENC_I17_IMM41c_INST_ಶಬ್ದ_X 2
#ವ್ಯಾಖ್ಯಾನಿಸು EMARCH_ENC_I17_IMM41c_ಗಾತ್ರ_X 23
#ವ್ಯಾಖ್ಯಾನಿಸು EMARCH_ENC_I17_IMM41c_INST_ಶಬ್ದ_POS_X 0
#ವ್ಯಾಖ್ಯಾನಿಸು EMARCH_ENC_I17_IMM41c_VAL_POS_X 40

#ವ್ಯಾಖ್ಯಾನಿಸು EMARCH_ENC_I17_SIGN_INST_ಶಬ್ದ_X 3
#ವ್ಯಾಖ್ಯಾನಿಸು EMARCH_ENC_I17_SIGN_ಗಾತ್ರ_X 1
#ವ್ಯಾಖ್ಯಾನಿಸು EMARCH_ENC_I17_SIGN_INST_ಶಬ್ದ_POS_X 27
#ವ್ಯಾಖ್ಯಾನಿಸು EMARCH_ENC_I17_SIGN_VAL_POS_X 63

#ವ್ಯಾಖ್ಯಾನಿಸು X3_OPCODE_INST_ಶಬ್ದ_X 3
#ವ್ಯಾಖ್ಯಾನಿಸು X3_OPCODE_ಗಾತ್ರ_X 4
#ವ್ಯಾಖ್ಯಾನಿಸು X3_OPCODE_INST_ಶಬ್ದ_POS_X 28
#ವ್ಯಾಖ್ಯಾನಿಸು X3_OPCODE_SIGN_VAL_POS_X 0

#ವ್ಯಾಖ್ಯಾನಿಸು X3_I_INST_ಶಬ್ದ_X 3
#ವ್ಯಾಖ್ಯಾನಿಸು X3_I_ಗಾತ್ರ_X 1
#ವ್ಯಾಖ್ಯಾನಿಸು X3_I_INST_ಶಬ್ದ_POS_X 27
#ವ್ಯಾಖ್ಯಾನಿಸು X3_I_SIGN_VAL_POS_X 59

#ವ್ಯಾಖ್ಯಾನಿಸು X3_D_WH_INST_ಶಬ್ದ_X 3
#ವ್ಯಾಖ್ಯಾನಿಸು X3_D_WH_ಗಾತ್ರ_X 3
#ವ್ಯಾಖ್ಯಾನಿಸು X3_D_WH_INST_ಶಬ್ದ_POS_X 24
#ವ್ಯಾಖ್ಯಾನಿಸು X3_D_WH_SIGN_VAL_POS_X 0

#ವ್ಯಾಖ್ಯಾನಿಸು X3_IMM20_INST_ಶಬ್ದ_X 3
#ವ್ಯಾಖ್ಯಾನಿಸು X3_IMM20_ಗಾತ್ರ_X 20
#ವ್ಯಾಖ್ಯಾನಿಸು X3_IMM20_INST_ಶಬ್ದ_POS_X 4
#ವ್ಯಾಖ್ಯಾನಿಸು X3_IMM20_SIGN_VAL_POS_X 0

#ವ್ಯಾಖ್ಯಾನಿಸು X3_IMM39_1_INST_ಶಬ್ದ_X 2
#ವ್ಯಾಖ್ಯಾನಿಸು X3_IMM39_1_ಗಾತ್ರ_X 23
#ವ್ಯಾಖ್ಯಾನಿಸು X3_IMM39_1_INST_ಶಬ್ದ_POS_X 0
#ವ್ಯಾಖ್ಯಾನಿಸು X3_IMM39_1_SIGN_VAL_POS_X 36

#ವ್ಯಾಖ್ಯಾನಿಸು X3_IMM39_2_INST_ಶಬ್ದ_X 1
#ವ್ಯಾಖ್ಯಾನಿಸು X3_IMM39_2_ಗಾತ್ರ_X 16
#ವ್ಯಾಖ್ಯಾನಿಸು X3_IMM39_2_INST_ಶಬ್ದ_POS_X 16
#ವ್ಯಾಖ್ಯಾನಿಸು X3_IMM39_2_SIGN_VAL_POS_X 20

#ವ್ಯಾಖ್ಯಾನಿಸು X3_P_INST_ಶಬ್ದ_X 3
#ವ್ಯಾಖ್ಯಾನಿಸು X3_P_ಗಾತ್ರ_X 4
#ವ್ಯಾಖ್ಯಾನಿಸು X3_P_INST_ಶಬ್ದ_POS_X 0
#ವ್ಯಾಖ್ಯಾನಿಸು X3_P_SIGN_VAL_POS_X 0

#ವ್ಯಾಖ್ಯಾನಿಸು X3_TMPLT_INST_ಶಬ್ದ_X 0
#ವ್ಯಾಖ್ಯಾನಿಸು X3_TMPLT_ಗಾತ್ರ_X 4
#ವ್ಯಾಖ್ಯಾನಿಸು X3_TMPLT_INST_ಶಬ್ದ_POS_X 0
#ವ್ಯಾಖ್ಯಾನಿಸು X3_TMPLT_SIGN_VAL_POS_X 0

#ವ್ಯಾಖ್ಯಾನಿಸು X3_BTYPE_QP_INST_ಶಬ್ದ_X 2
#ವ್ಯಾಖ್ಯಾನಿಸು X3_BTYPE_QP_ಗಾತ್ರ_X 9
#ವ್ಯಾಖ್ಯಾನಿಸು X3_BTYPE_QP_INST_ಶಬ್ದ_POS_X 23
#ವ್ಯಾಖ್ಯಾನಿಸು X3_BTYPE_QP_INST_VAL_POS_X 0

#ವ್ಯಾಖ್ಯಾನಿಸು X3_ಖಾಲಿಗಳು_INST_ಶಬ್ದ_X 1
#ವ್ಯಾಖ್ಯಾನಿಸು X3_ಖಾಲಿಗಳು_ಗಾತ್ರ_X 2
#ವ್ಯಾಖ್ಯಾನಿಸು X3_ಖಾಲಿಗಳು_INST_ಶಬ್ದ_POS_X 14
#ವ್ಯಾಖ್ಯಾನಿಸು X3_ಖಾಲಿಗಳು_INST_VAL_POS_X 0

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _IMAGE_LINENUMBER {
      ಒಕ್ಕೂಟ {
	DWORD ಚಿಹ್ನೆ_ಕೋಷ್ಟಕ_ಸೂಚ್ಯಂಕ;
	DWORD Virtual_ವಿಳಾಸ;
      } Type;
      ಶಬ್ದ_3 Linenumber;
    } IMAGE_LINENUMBER;
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ IMAGE_LINENUMBER UNALIGNED *PIMAGE_LINENUMBER;

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SIZEOF_LINENUMBER 6

#ಅನ್ತರ್ಭಾವ "poppack.h"

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ IMAGE_ತಳ_RELOCATION {
      DWORD Virtual_ವಿಳಾಸ;
      DWORD ಗಾತ್ರ_ದ_ಖಂಡ;

    } IMAGE_ತಳ_RELOCATION_2;
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ IMAGE_ತಳ_RELOCATION_2 UNALIGNED *PIMAGE_ತಳ_RELOCATION;

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SIZEOF_ತಳ_RELOCATION 8

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_BASED_ABSOLUTE 0
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_BASED_ಮೇಲಿನ 1
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_BASED_ಕೆಳಗಿನ 2
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_BASED_HIGHLOW 3
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_BASED_HIGHADJ 4
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_BASED_MIPS_JMPADDR 5
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_BASED_MIPS_JMPADDR16 9
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_BASED_IA64_IMM64 9
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_REL_BASED_DIR64 10

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_ARCHIVE_ಆರಂಭ_ಗಾತ್ರ 8
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_ARCHIVE_ಆರಂಭ "!<arch>\n"
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_ARCHIVE_ಕೊನೆ "`\n"
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_ARCHIVE_PAD "\n"
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_ARCHIVE_LINKER_MEMBER "/               "
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_ARCHIVE_LONGNAMES_MEMBER "//              "

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ IMAGE_ARCHIVE_MEMBER_ಶೀರ್ಷಿಕೆ {
      BYTE Name[16];
      BYTE Date[12];
      BYTE UserID[6];
      BYTE ಗುಂಪು_ID[6];
      BYTE ಬಹುಲಕ_4[8];
      BYTE ಗಾತ್ರ_4[10];
      BYTE ಕೊನೆ_ಶೀರ್ಷಿಕೆ[2];
    } IMAGE_ARCHIVE_MEMBER_ಶೀರ್ಷಿಕೆ_2,*PIMAGE_ARCHIVE_MEMBER_ಶೀರ್ಷಿಕೆ;

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SIZEOF_ARCHIVE_MEMBER_HDR 60

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _IMAGE_EXPORT_DIRECTORY {
      DWORD Characteristics;
      DWORD ಸಮಯ_Date_Stamp;
      ಶಬ್ದ_3 Major_ಆವೃತ್ತಿ;
      ಶಬ್ದ_3 Minor_ಆವೃತ್ತಿ;
      DWORD Name;
      DWORD ತಳ_2;
      DWORD ಸಂಖ್ಯೆ_ದ_Functions;
      DWORD ಸಂಖ್ಯೆ_ದ_ಹೆಸರುಗಳು;
      DWORD ವಿಳಾಸ_ದ_Functions;
      DWORD ವಿಳಾಸ_ದ_ಹೆಸರುಗಳು;
      DWORD ವಿಳಾಸ_ದ_Name_Ordinals;
    } IMAGE_EXPORT_DIRECTORY,*PIMAGE_EXPORT_DIRECTORY;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _IMAGE_IMPORT_BY_NAME {
      ಶಬ್ದ_3 Hint;
      BYTE Name[1];
    } IMAGE_IMPORT_BY_NAME,*PIMAGE_IMPORT_BY_NAME;

#ಅನ್ತರ್ಭಾವ "pshpack8.h"

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _IMAGE_THUNK_DATA64 {
      ಒಕ್ಕೂಟ {
	ULONGLONG ForwarderString;
	ULONGLONG Function;
	ULONGLONG Ordinal;
	ULONGLONG ವಿಳಾಸ_ದ_ದತ್ತಾಂಶ;
      } u1;
    } IMAGE_THUNK_DATA64;
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ IMAGE_THUNK_DATA64 *PIMAGE_THUNK_DATA64;

#ಅನ್ತರ್ಭಾವ "poppack.h"

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _IMAGE_THUNK_DATA32 {
      ಒಕ್ಕೂಟ {
	DWORD ForwarderString;
	DWORD Function;
	DWORD Ordinal;
	DWORD ವಿಳಾಸ_ದ_ದತ್ತಾಂಶ;
      } u1;
    } IMAGE_THUNK_DATA32;
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ IMAGE_THUNK_DATA32 *PIMAGE_THUNK_DATA32;

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_ORDINAL_FLAG64 0x8000000000000000ull
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_ORDINAL_FLAG32 0x80000000
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_ORDINAL64(Ordinal) (Ordinal & 0xffffull)
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_ORDINAL32(Ordinal) (Ordinal & 0xffff)
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SNAP_BY_ORDINAL64(Ordinal) ((Ordinal & IMAGE_ORDINAL_FLAG64)!=0)
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SNAP_BY_ORDINAL32(Ordinal) ((Ordinal & IMAGE_ORDINAL_FLAG32)!=0)

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ VOID
      (NTAPI *PIMAGE_TLS_CALLBACK)(PVOID DllHandle,DWORD Reason,PVOID Reserved);

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _IMAGE_TLS_DIRECTORY64 {
      ULONGLONG ಆರಂಭ_ವಿಳಾಸ_ದ_Raw_ದತ್ತಾಂಶ;
      ULONGLONG ಕೊನೆ_ವಿಳಾಸ_ದ_Raw_ದತ್ತಾಂಶ;
      ULONGLONG ವಿಳಾಸ_ದ_ಸೂಚ್ಯಂಕ;
      ULONGLONG ವಿಳಾಸ_ದ_Call_Backs;
      DWORD ಗಾತ್ರ_ದ_Zero_Fill;
      DWORD Characteristics;
    } IMAGE_TLS_DIRECTORY64;
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ IMAGE_TLS_DIRECTORY64 *PIMAGE_TLS_DIRECTORY64;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _IMAGE_TLS_DIRECTORY32 {
      DWORD ಆರಂಭ_ವಿಳಾಸ_ದ_Raw_ದತ್ತಾಂಶ;
      DWORD ಕೊನೆ_ವಿಳಾಸ_ದ_Raw_ದತ್ತಾಂಶ;
      DWORD ವಿಳಾಸ_ದ_ಸೂಚ್ಯಂಕ;
      DWORD ವಿಳಾಸ_ದ_Call_Backs;
      DWORD ಗಾತ್ರ_ದ_Zero_Fill;
      DWORD Characteristics;
    } IMAGE_TLS_DIRECTORY32;
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ IMAGE_TLS_DIRECTORY32 *PIMAGE_TLS_DIRECTORY32;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN64
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_ORDINAL_FLAG IMAGE_ORDINAL_FLAG64
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_ORDINAL(Ordinal) IMAGE_ORDINAL64(Ordinal)
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ IMAGE_THUNK_DATA64 IMAGE_THUNK_ದತ್ತಾಂಶ;
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PIMAGE_THUNK_DATA64 PIMAGE_THUNK_ದತ್ತಾಂಶ;
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SNAP_BY_ORDINAL(Ordinal) IMAGE_SNAP_BY_ORDINAL64(Ordinal)
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ IMAGE_TLS_DIRECTORY64 IMAGE_TLS_DIRECTORY;
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PIMAGE_TLS_DIRECTORY64 PIMAGE_TLS_DIRECTORY;
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_ORDINAL_FLAG IMAGE_ORDINAL_FLAG32
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_ORDINAL(Ordinal) IMAGE_ORDINAL32(Ordinal)
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ IMAGE_THUNK_DATA32 IMAGE_THUNK_ದತ್ತಾಂಶ;
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PIMAGE_THUNK_DATA32 PIMAGE_THUNK_ದತ್ತಾಂಶ;
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SNAP_BY_ORDINAL(Ordinal) IMAGE_SNAP_BY_ORDINAL32(Ordinal)
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ IMAGE_TLS_DIRECTORY32 IMAGE_TLS_DIRECTORY;
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PIMAGE_TLS_DIRECTORY32 PIMAGE_TLS_DIRECTORY;
#ಆದರೆ_ಅಂತ್ಯ

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _IMAGE_IMPORT_DESCRIPTOR {
      ಒಕ್ಕೂಟ {
	DWORD Characteristics;
	DWORD Original_ಮೊದಲ_Thunk;
      };
      DWORD ಸಮಯ_Date_Stamp;

      DWORD ForwarderChain;
      DWORD Name;
      DWORD ಮೊದಲ_Thunk;
    } IMAGE_IMPORT_DESCRIPTOR;
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ IMAGE_IMPORT_DESCRIPTOR UNALIGNED *PIMAGE_IMPORT_DESCRIPTOR;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _IMAGE_BOUND_IMPORT_DESCRIPTOR {
      DWORD ಸಮಯ_Date_Stamp;
      ಶಬ್ದ_3 ಸ್ಥಾನಾಂತರ_Module_Name;
      ಶಬ್ದ_3 ಸಂಖ್ಯೆ_ದ_Module_Forwarder_Refs;
    } IMAGE_BOUND_IMPORT_DESCRIPTOR,*PIMAGE_BOUND_IMPORT_DESCRIPTOR;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _IMAGE_BOUND_FORWARDER_REF {
      DWORD ಸಮಯ_Date_Stamp;
      ಶಬ್ದ_3 ಸ್ಥಾನಾಂತರ_Module_Name;
      ಶಬ್ದ_3 Reserved;
    } IMAGE_BOUND_FORWARDER_REF,*PIMAGE_BOUND_FORWARDER_REF;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _IMAGE_RESOURCE_DIRECTORY {
      DWORD Characteristics;
      DWORD ಸಮಯ_Date_Stamp;
      ಶಬ್ದ_3 Major_ಆವೃತ್ತಿ;
      ಶಬ್ದ_3 Minor_ಆವೃತ್ತಿ;
      ಶಬ್ದ_3 ಸಂಖ್ಯೆ_ದ_Named_Entries;
      ಶಬ್ದ_3 ಸಂಖ್ಯೆ_ದ_Id_Entries;
    } IMAGE_RESOURCE_DIRECTORY,*PIMAGE_RESOURCE_DIRECTORY;

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_RESOURCE_NAME_IS_STRING 0x80000000
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_RESOURCE_ದತ್ತಾಂಶ_IS_DIRECTORY 0x80000000

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ IMAGE_RESOURCE_DIRECTORY_ನಮೂದು {
      ಒಕ್ಕೂಟ {
	ರಚನೆ {
	  DWORD Name_ಸ್ಥಾನಾಂತರ:31;
	  DWORD NameIsString:1;
	};
	DWORD Name;
	ಶಬ್ದ_3 Id;
      };
      ಒಕ್ಕೂಟ {
	DWORD ಸ್ಥಾನಾಂತರ_ಗಮ್ಯ_ದತ್ತಾಂಶ;
	ರಚನೆ {
	  DWORD ಸ್ಥಾನಾಂತರ_ಗಮ್ಯ_Directory:31;
	  DWORD ದತ್ತಾಂಶ_Is_Directory:1;
	};
      };
    } IMAGE_RESOURCE_DIRECTORY_ನಮೂದು_2,*PIMAGE_RESOURCE_DIRECTORY_ನಮೂದು;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _IMAGE_RESOURCE_DIRECTORY_STRING {
      ಶಬ್ದ_3 ಉದ್ದಳತೆ_2;
      CHAR NameString[1];
    } IMAGE_RESOURCE_DIRECTORY_STRING,*PIMAGE_RESOURCE_DIRECTORY_STRING;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _IMAGE_RESOURCE_DIR_STRING_U {
      ಶಬ್ದ_3 ಉದ್ದಳತೆ_2;
      WCHAR NameString[1];
    } IMAGE_RESOURCE_DIR_STRING_U,*PIMAGE_RESOURCE_DIR_STRING_U;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ IMAGE_RESOURCE_ದತ್ತಾಂಶ_ನಮೂದು {
      DWORD ಸ್ಥಾನಾಂತರ_ಗಮ್ಯ_ದತ್ತಾಂಶ;
      DWORD ಗಾತ್ರ_4;
      DWORD ಸಂಕೇತ_ಪುಟ;
      DWORD Reserved;
    } IMAGE_RESOURCE_ದತ್ತಾಂಶ_ನಮೂದು_2,*PIMAGE_RESOURCE_ದತ್ತಾಂಶ_ನಮೂದು;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ {
      DWORD ಗಾತ್ರ_4;
      DWORD ಸಮಯ_Date_Stamp;
      ಶಬ್ದ_3 Major_ಆವೃತ್ತಿ;
      ಶಬ್ದ_3 Minor_ಆವೃತ್ತಿ;
      DWORD GlobalFlagsClear;
      DWORD Global_Flags_ಗಣ;
      DWORD CriticalSectionDefaultTimeout;
      DWORD De_Commit_Free_ಖಂಡ_ಮಿತಿ;
      DWORD De_Commit_ಒಟ್ಟು_Free_ಮಿತಿ;
      DWORD ಬೀಗ_ಪೂರ್ವಪ್ರತ್ಯಯ_ಕೋಷ್ಟಕ;
      DWORD ಗರಿಷ್ಠ_ಹಂಚಿಕೆ_ಗಾತ್ರ;
      DWORD Virtual_ಸ್ಮರಣೆ_ಮಿತಿ;
      DWORD Process_ರಾಶಿ_Flags;
      DWORD Process_Affinity_ಮುಖವಾಡ;
      ಶಬ್ದ_3 CSDVersion;
      ಶಬ್ದ_3 Reserved1;
      DWORD EditList;
      DWORD SecurityCookie;
      DWORD SEHandler_ಕೋಷ್ಟಕ;
      DWORD SEHandler_ಎಣಿಕೆ;
    } IMAGE_ತುಂಬು_CONFIG_DIRECTORY32,*PIMAGE_ತುಂಬು_CONFIG_DIRECTORY32;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ {
      DWORD ಗಾತ್ರ_4;
      DWORD ಸಮಯ_Date_Stamp;
      ಶಬ್ದ_3 Major_ಆವೃತ್ತಿ;
      ಶಬ್ದ_3 Minor_ಆವೃತ್ತಿ;
      DWORD GlobalFlagsClear;
      DWORD Global_Flags_ಗಣ;
      DWORD CriticalSectionDefaultTimeout;
      ULONGLONG De_Commit_Free_ಖಂಡ_ಮಿತಿ;
      ULONGLONG De_Commit_ಒಟ್ಟು_Free_ಮಿತಿ;
      ULONGLONG ಬೀಗ_ಪೂರ್ವಪ್ರತ್ಯಯ_ಕೋಷ್ಟಕ;
      ULONGLONG ಗರಿಷ್ಠ_ಹಂಚಿಕೆ_ಗಾತ್ರ;
      ULONGLONG Virtual_ಸ್ಮರಣೆ_ಮಿತಿ;
      ULONGLONG Process_Affinity_ಮುಖವಾಡ;
      DWORD Process_ರಾಶಿ_Flags;
      ಶಬ್ದ_3 CSDVersion;
      ಶಬ್ದ_3 Reserved1;
      ULONGLONG EditList;
      ULONGLONG SecurityCookie;
      ULONGLONG SEHandler_ಕೋಷ್ಟಕ;
      ULONGLONG SEHandler_ಎಣಿಕೆ;
    } IMAGE_ತುಂಬು_CONFIG_DIRECTORY64,*PIMAGE_ತುಂಬು_CONFIG_DIRECTORY64;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN64
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ IMAGE_ತುಂಬು_CONFIG_DIRECTORY64 IMAGE_ತುಂಬು_CONFIG_DIRECTORY;
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PIMAGE_ತುಂಬು_CONFIG_DIRECTORY64 PIMAGE_ತುಂಬು_CONFIG_DIRECTORY;
#ಇಲ್ಲದಿದ್ದರೆ
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ IMAGE_ತುಂಬು_CONFIG_DIRECTORY32 IMAGE_ತುಂಬು_CONFIG_DIRECTORY;
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PIMAGE_ತುಂಬು_CONFIG_DIRECTORY32 PIMAGE_ತುಂಬು_CONFIG_DIRECTORY;
#ಆದರೆ_ಅಂತ್ಯ

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ IMAGE_CE_RUNTIME_FUNCTION_ನಮೂದು {
      DWORD Func_ಆರಂಭ;
      DWORD PrologLen : 8;
      DWORD FuncLen : 22;
      DWORD Thirty_Two_ಬಿಟ್ : 1;
      DWORD ExceptionFlag : 1;
    } IMAGE_CE_RUNTIME_FUNCTION_ನಮೂದು_2,*PIMAGE_CE_RUNTIME_FUNCTION_ನಮೂದು;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ IMAGE_ALPHA64_RUNTIME_FUNCTION_ನಮೂದು {
      ULONGLONG Begin_ವಿಳಾಸ;
      ULONGLONG ಕೊನೆ_ವಿಳಾಸ;
      ULONGLONG ExceptionHandler;
      ULONGLONG Handler_ದತ್ತಾಂಶ;
      ULONGLONG Prolog_ಕೊನೆ_ವಿಳಾಸ;
    } IMAGE_ALPHA64_RUNTIME_FUNCTION_ನಮೂದು_2,*PIMAGE_ALPHA64_RUNTIME_FUNCTION_ನಮೂದು;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ IMAGE_ALPHA_RUNTIME_FUNCTION_ನಮೂದು {
      DWORD Begin_ವಿಳಾಸ;
      DWORD ಕೊನೆ_ವಿಳಾಸ;
      DWORD ExceptionHandler;
      DWORD Handler_ದತ್ತಾಂಶ;
      DWORD Prolog_ಕೊನೆ_ವಿಳಾಸ;
    } IMAGE_ALPHA_RUNTIME_FUNCTION_ನಮೂದು_2,*PIMAGE_ALPHA_RUNTIME_FUNCTION_ನಮೂದು;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ IMAGE_RUNTIME_FUNCTION_ನಮೂದು {
      DWORD Begin_ವಿಳಾಸ;
      DWORD ಕೊನೆ_ವಿಳಾಸ;
      DWORD Unwind_Info_ವಿಳಾಸ;
    } IMAGE_RUNTIME_FUNCTION_ನಮೂದು,*PIMAGE_RUNTIME_FUNCTION_ನಮೂದು;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ IMAGE_RUNTIME_FUNCTION_ನಮೂದು IMAGE_IA64_RUNTIME_FUNCTION_ನಮೂದು;
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PIMAGE_RUNTIME_FUNCTION_ನಮೂದು PIMAGE_IA64_RUNTIME_FUNCTION_ನಮೂದು;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ IMAGE_RUNTIME_FUNCTION_ನಮೂದು IMAGE_RUNTIME_FUNCTION_ನಮೂದು_2;
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PIMAGE_RUNTIME_FUNCTION_ನಮೂದು PIMAGE_RUNTIME_FUNCTION_ನಮೂದು_2;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _IMAGE_DEBUG_DIRECTORY {
      DWORD Characteristics;
      DWORD ಸಮಯ_Date_Stamp;
      ಶಬ್ದ_3 Major_ಆವೃತ್ತಿ;
      ಶಬ್ದ_3 Minor_ಆವೃತ್ತಿ;
      DWORD Type;
      DWORD ಗಾತ್ರ_ದ_ದತ್ತಾಂಶ;
      DWORD ವಿಳಾಸ_ದ_Raw_ದತ್ತಾಂಶ;
      DWORD ಸೂಚಕ_ಗಮ್ಯ_Raw_ದತ್ತಾಂಶ;
    } IMAGE_DEBUG_DIRECTORY,*PIMAGE_DEBUG_DIRECTORY;

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DEBUG_TYPE_UNKNOWN 0
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DEBUG_TYPE_COFF 1
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DEBUG_TYPE_CODEVIEW 2
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DEBUG_TYPE_FPO 3
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DEBUG_TYPE_MISC 4
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DEBUG_TYPE_EXCEPTION 5
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DEBUG_TYPE_FIXUP 6
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DEBUG_TYPE_OMAP_ಗಮ್ಯ_SRC 7
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DEBUG_TYPE_OMAP_FROM_SRC 8
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DEBUG_TYPE_BORLAND 9
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DEBUG_TYPE_RESERVED10 10
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DEBUG_TYPE_CLSID 11

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ IMAGE_COFF_SYMBOLS_ಶೀರ್ಷಿಕೆ {
      DWORD ಸಂಖ್ಯೆ_ದ_Symbols;
      DWORD Lva_ಗಮ್ಯ_ಮೊದಲ_ಚಿಹ್ನೆ;
      DWORD ಸಂಖ್ಯೆ_ದ_Linenumbers;
      DWORD Lva_ಗಮ್ಯ_ಮೊದಲ_Linenumber;
      DWORD Rva_ಗಮ್ಯ_ಮೊದಲ_Byte_ದ_ಸಂಕೇತ;
      DWORD Rva_ಗಮ್ಯ_ಕೊನೆಯ_Byte_ದ_ಸಂಕೇತ;
      DWORD Rva_ಗಮ್ಯ_ಮೊದಲ_Byte_ದ_ದತ್ತಾಂಶ;
      DWORD Rva_ಗಮ್ಯ_ಕೊನೆಯ_Byte_ದ_ದತ್ತಾಂಶ;
    } IMAGE_COFF_SYMBOLS_ಶೀರ್ಷಿಕೆ_2,*PIMAGE_COFF_SYMBOLS_ಶೀರ್ಷಿಕೆ;

#ವ್ಯಾಖ್ಯಾನಿಸು ಚೌಕಟ್ಟು_FPO 0
#ವ್ಯಾಖ್ಯಾನಿಸು ಚೌಕಟ್ಟು_TRAP 1
#ವ್ಯಾಖ್ಯಾನಿಸು ಚೌಕಟ್ಟು_TSS 2
#ವ್ಯಾಖ್ಯಾನಿಸು ಚೌಕಟ್ಟು_NONFPO 3

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ FPO_ದತ್ತಾಂಶ {
      DWORD ul_Off_ಆರಂಭ;
      DWORD cb_Proc_ಗಾತ್ರ;
      DWORD cdwLocals;
      ಶಬ್ದ_3 cdwParams;
      ಶಬ್ದ_3 cbProlog : 8;
      ಶಬ್ದ_3 cbRegs : 3;
      ಶಬ್ದ_3 fHasSEH : 1;
      ಶಬ್ದ_3 fUseBP : 1;
      ಶಬ್ದ_3 reserved : 1;
      ಶಬ್ದ_3 cb_ಚೌಕಟ್ಟು : 2;
    } FPO_ದತ್ತಾಂಶ_2,*PFPO_ದತ್ತಾಂಶ;
#ವ್ಯಾಖ್ಯಾನಿಸು SIZEOF_RFPO_ದತ್ತಾಂಶ 16

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_DEBUG_MISC_EXENAME 1

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _IMAGE_DEBUG_MISC {
      DWORD ದತ್ತಾಂಶ_Type;
      DWORD ಉದ್ದಳತೆ_2;
      BOOLEAN Unicode;
      BYTE Reserved[3];
      BYTE ದತ್ತಾಂಶ_3[1];
    } IMAGE_DEBUG_MISC,*PIMAGE_DEBUG_MISC;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ IMAGE_FUNCTION_ನಮೂದು {
      DWORD Starting_ವಿಳಾಸ;
      DWORD Ending_ವಿಳಾಸ;
      DWORD ಕೊನೆ_ದ_Prologue;
    } IMAGE_FUNCTION_ನಮೂದು_2,*PIMAGE_FUNCTION_ನಮೂದು;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _IMAGE_FUNCTION_ENTRY64 {
      ULONGLONG Starting_ವಿಳಾಸ;
      ULONGLONG Ending_ವಿಳಾಸ;
      ಒಕ್ಕೂಟ {
	ULONGLONG ಕೊನೆ_ದ_Prologue;
	ULONGLONG Unwind_Info_ವಿಳಾಸ;
      };
    } IMAGE_FUNCTION_ENTRY64,*PIMAGE_FUNCTION_ENTRY64;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ IMAGE_SEPARATE_DEBUG_ಶೀರ್ಷಿಕೆ {
      ಶಬ್ದ_3 Signature;
      ಶಬ್ದ_3 Flags;
      ಶಬ್ದ_3 Machine;
      ಶಬ್ದ_3 Characteristics;
      DWORD ಸಮಯ_Date_Stamp;
      DWORD Check_ಮೊತ್ತ;
      DWORD Image_ತಳ;
      DWORD ಗಾತ್ರ_ದ_Image;
      DWORD ಸಂಖ್ಯೆ_ದ_Sections;
      DWORD Exported_ಹೆಸರುಗಳು_ಗಾತ್ರ;
      DWORD Debug_Directory_ಗಾತ್ರ;
      DWORD SectionAlignment;
      DWORD Reserved[2];
    } IMAGE_SEPARATE_DEBUG_ಶೀರ್ಷಿಕೆ_2,*PIMAGE_SEPARATE_DEBUG_ಶೀರ್ಷಿಕೆ;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _NON_PAGED_DEBUG_INFO {
      ಶಬ್ದ_3 Signature;
      ಶಬ್ದ_3 Flags;
      DWORD ಗಾತ್ರ_4;
      ಶಬ್ದ_3 Machine;
      ಶಬ್ದ_3 Characteristics;
      DWORD ಸಮಯ_Date_Stamp;
      DWORD Check_ಮೊತ್ತ;
      DWORD ಗಾತ್ರ_ದ_Image;
      ULONGLONG Image_ತಳ;

    } NON_PAGED_DEBUG_INFO,*PNON_PAGED_DEBUG_INFO;

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SEPARATE_DEBUG_SIGNATURE 0x4944
#ವ್ಯಾಖ್ಯಾನಿಸು NON_PAGED_DEBUG_SIGNATURE 0x494E

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SEPARATE_DEBUG_FLAGS_ಮುಖವಾಡ 0x8000
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_SEPARATE_DEBUG_MISMATCH 0x8000

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ Image_Architecture_ಶೀರ್ಷಿಕೆ {
      ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ Amask_ಮೌಲ್ಯ: 1;
      ಪೂರ್ಣಾಂಕ Adummy1 :7;
      ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ Amask_ಸರಿಸು: 8;
      ಪೂರ್ಣಾಂಕ Adummy2 :16;
      DWORD ಮೊದಲ_ನಮೂದು_RVA;
    } IMAGE_ARCHITECTURE_ಶೀರ್ಷಿಕೆ,*PIMAGE_ARCHITECTURE_ಶೀರ್ಷಿಕೆ;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ Image_Architecture_ನಮೂದು {
      DWORD FixupInstRVA;
      DWORD NewInst;
    } IMAGE_ARCHITECTURE_ನಮೂದು,*PIMAGE_ARCHITECTURE_ನಮೂದು;

#ಅನ್ತರ್ಭಾವ "poppack.h"

#ವ್ಯಾಖ್ಯಾನಿಸು IMPORT_OBJECT_HDR_SIG2 0xffff

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ IMPORT_OBJECT_ಶೀರ್ಷಿಕೆ {
      ಶಬ್ದ_3 Sig1;
      ಶಬ್ದ_3 Sig2;
      ಶಬ್ದ_3 ಆವೃತ್ತಿ_2;
      ಶಬ್ದ_3 Machine;
      DWORD ಸಮಯ_Date_Stamp;
      DWORD ಗಾತ್ರ_ದ_ದತ್ತಾಂಶ;
      ಒಕ್ಕೂಟ {
	ಶಬ್ದ_3 Ordinal;
	ಶಬ್ದ_3 Hint;
      };
      ಶಬ್ದ_3 Type : 2;
      ಶಬ್ದ_3 NameType : 3;
      ಶಬ್ದ_3 Reserved : 11;
    } IMPORT_OBJECT_ಶೀರ್ಷಿಕೆ;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಎಣಿಕೆ IMPORT_OBJECT_TYPE {
      IMPORT_OBJECT_ಸಂಕೇತ = 0,IMPORT_OBJECT_ದತ್ತಾಂಶ = 1,IMPORT_OBJECT_CONST = 2
    } IMPORT_OBJECT_TYPE;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಎಣಿಕೆ IMPORT_OBJECT_NAME_TYPE {
      IMPORT_OBJECT_ORDINAL = 0,IMPORT_OBJECT_NAME = 1,IMPORT_OBJECT_NAME_NO_ಪೂರ್ವಪ್ರತ್ಯಯ = 2,IMPORT_OBJECT_NAME_UNDECORATE = 3
    } IMPORT_OBJECT_NAME_TYPE;

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __IMAGE_COR20_HEADER_DEFINED__
#ವ್ಯಾಖ್ಯಾನಿಸು __IMAGE_COR20_HEADER_DEFINED__
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಎಣಿಕೆ Replaces_Cor_Hdr_Numeric_ನಿರೂಪಿಸುತ್ತದೆ {
      COMIMAGE_FLAGS_ILONLY =0x00000001,COMIMAGE_FLAGS_32BITREQUIRED =0x00000002,COMIMAGE_FLAGS_IL_LIBRARY =0x00000004,
      COMIMAGE_FLAGS_STRONGNAMESIGNED =0x00000008,COMIMAGE_FLAGS_TRACKDEBUGDATA =0x00010000,COR_ಆವೃತ್ತಿ_MAJOR_V2 =2,
      COR_ಆವೃತ್ತಿ_MAJOR =COR_ಆವೃತ್ತಿ_MAJOR_V2,COR_ಆವೃತ್ತಿ_MINOR =0,COR_DELETED_NAME_ಉದ್ದಳತೆ =8,COR_VTABLEGAP_NAME_ಉದ್ದಳತೆ =8,
      NATIVE_TYPE_MAX_CB =1,COR_ILMETHOD_SECT_SMALL_MAX_DATASIZE=0xFF,IMAGE_COR_MIH_METHODRVA =0x01,IMAGE_COR_MIH_EHRVA =0x02,
      IMAGE_COR_MIH_BASICBLOCK =0x08,COR_VTABLE_32_ಬಿಟ್ =0x01,COR_VTABLE_64_ಬಿಟ್ =0x02,COR_VTABLE_FROM_UNMANAGED =0x04,
      COR_VTABLE_CALL_MOST_DERIVED =0x10,IMAGE_COR_EATJ_THUNK_ಗಾತ್ರ =32,MAX_CLASS_NAME =1024,MAX_PACKAGE_NAME =1024
    } Replaces_Cor_Hdr_Numeric_ನಿರೂಪಿಸುತ್ತದೆ;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ IMAGE_COR20_ಶೀರ್ಷಿಕೆ {
      DWORD cb;
      ಶಬ್ದ_3 Major_Runtime_ಆವೃತ್ತಿ;
      ಶಬ್ದ_3 Minor_Runtime_ಆವೃತ್ತಿ;
      IMAGE_ದತ್ತಾಂಶ_DIRECTORY_2 Meta_ದತ್ತಾಂಶ;
      DWORD Flags;
      DWORD ನಮೂದು_ಬಿಂದು_Token;
      IMAGE_ದತ್ತಾಂಶ_DIRECTORY_2 Resources;
      IMAGE_ದತ್ತಾಂಶ_DIRECTORY_2 StrongNameSignature;
      IMAGE_ದತ್ತಾಂಶ_DIRECTORY_2 ಸಂಕೇತ_Manager_ಕೋಷ್ಟಕ;
      IMAGE_ದತ್ತಾಂಶ_DIRECTORY_2 VTableFixups;
      IMAGE_ದತ್ತಾಂಶ_DIRECTORY_2 Export_ವಿಳಾಸ_ಕೋಷ್ಟಕ_Jumps;
      IMAGE_ದತ್ತಾಂಶ_DIRECTORY_2 Managed_Native_ಶೀರ್ಷಿಕೆ;
    } IMAGE_COR20_ಶೀರ್ಷಿಕೆ,*PIMAGE_COR20_ಶೀರ್ಷಿಕೆ;
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ defined (__x86_64)
    NTSYSAPI PRUNTIME_FUNCTION NTAPI Rtl_Lookup_Function_ನಮೂದು (DWORD64 ControlPc, PDWORD64 Image_ತಳ, PUNWIND_HISTORY_ಕೋಷ್ಟಕ History_ಕೋಷ್ಟಕ);
    NTSYSAPI VOID NTAPI RtlUnwindEx (PVOID ಗುರಿ_ಚೌಕಟ್ಟು, PVOID ಗುರಿ_Ip, PEXCEPTION_ದಾಖಲೆ Exception_ದಾಖಲೆ, PVOID Return_ಮೌಲ್ಯ_2, PCONTEXT Context_ದಾಖಲೆ, PUNWIND_HISTORY_ಕೋಷ್ಟಕ History_ಕೋಷ್ಟಕ);
#ಆದರೆ_ಅಂತ್ಯ

#ಅನ್ತರ್ಭಾವ <string.h>

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ SLIST_ಶೀರ್ಷಿಕೆ
#ವ್ಯಾಖ್ಯಾನಿಸು SLIST_ಶೀರ್ಷಿಕೆ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN64
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ SLIST_ನಮೂದು *PSLIST_ನಮೂದು;
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ DECLSPEC_ALIGN(16) SLIST_ನಮೂದು {
      PSLIST_ನಮೂದು ಮುಂದಿನ_2;
    } SLIST_ನಮೂದು_2;
#ಇಲ್ಲದಿದ್ದರೆ

#ವ್ಯಾಖ್ಯಾನಿಸು SLIST_ನಮೂದು_2 SINGLE_LIST_ನಮೂದು_2
#ವ್ಯಾಖ್ಯಾನಿಸು SLIST_ನಮೂದು SINGLE_LIST_ನಮೂದು
#ವ್ಯಾಖ್ಯಾನಿಸು PSLIST_ನಮೂದು PSINGLE_LIST_ನಮೂದು
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ defined(_WIN64)

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ DECLSPEC_ALIGN(16) SLIST_ಶೀರ್ಷಿಕೆ_2 {
      ULONGLONG Alignment;
      ULONGLONG Region;
    } SLIST_ಶೀರ್ಷಿಕೆ_3;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ SLIST_ಶೀರ್ಷಿಕೆ_2 *PSLIST_ಶೀರ್ಷಿಕೆ;
#ಇಲ್ಲದಿದ್ದರೆ

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಒಕ್ಕೂಟ SLIST_ಶೀರ್ಷಿಕೆ_2 {
      ULONGLONG Alignment;
      ರಚನೆ {
	SLIST_ನಮೂದು_2 ಮುಂದಿನ_2;
	ಶಬ್ದ_3 ಆಳ;
	ಶಬ್ದ_3 Sequence;
      };
    } SLIST_ಶೀರ್ಷಿಕೆ_3,*PSLIST_ಶೀರ್ಷಿಕೆ;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

    NTSYSAPI VOID NTAPI Rtl_Initialize_SList_ತಲೆ(PSLIST_ಶೀರ್ಷಿಕೆ List_ತಲೆ);
    NTSYSAPI PSLIST_ನಮೂದು NTAPI Rtl_ಮೊದಲ_ನಮೂದು_SList(ಸ್ಥಿರಾಂಕ SLIST_ಶೀರ್ಷಿಕೆ_3 *List_ತಲೆ);
    NTSYSAPI PSLIST_ನಮೂದು NTAPI Rtl_Interlocked_ತೆಗೆ_ನಮೂದು_SList(PSLIST_ಶೀರ್ಷಿಕೆ List_ತಲೆ);
    NTSYSAPI PSLIST_ನಮೂದು NTAPI Rtl_Interlocked_ತಳ್ಳು_ನಮೂದು_SList(PSLIST_ಶೀರ್ಷಿಕೆ List_ತಲೆ,PSLIST_ನಮೂದು List_ನಮೂದು);
    NTSYSAPI PSLIST_ನಮೂದು NTAPI RtlInterlockedFlushSList(PSLIST_ಶೀರ್ಷಿಕೆ List_ತಲೆ);
    NTSYSAPI ಶಬ್ದ_3 NTAPI Rtl_Query_ಆಳ_SList(PSLIST_ಶೀರ್ಷಿಕೆ List_ತಲೆ);

#ವ್ಯಾಖ್ಯಾನಿಸು ರಾಶಿ_NO_SERIALIZE 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು ರಾಶಿ_GROWABLE 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು ರಾಶಿ_GENERATE_EXCEPTIONS 0x00000004
#ವ್ಯಾಖ್ಯಾನಿಸು ರಾಶಿ_ZERO_ಸ್ಮರಣೆ 0x00000008
#ವ್ಯಾಖ್ಯಾನಿಸು ರಾಶಿ_REALLOC_ಒಳ_ಇರಿಸು_ONLY 0x00000010
#ವ್ಯಾಖ್ಯಾನಿಸು ರಾಶಿ_ಬಾಲ_CHECKING_ENABLED 0x00000020
#ವ್ಯಾಖ್ಯಾನಿಸು ರಾಶಿ_FREE_CHECKING_ENABLED 0x00000040
#ವ್ಯಾಖ್ಯಾನಿಸು ರಾಶಿ_DISABLE_COALESCE_ON_FREE 0x00000080
#ವ್ಯಾಖ್ಯಾನಿಸು ರಾಶಿ_CREATE_ALIGN_16 0x00010000
#ವ್ಯಾಖ್ಯಾನಿಸು ರಾಶಿ_CREATE_ENABLE_TRACING 0x00020000
#ವ್ಯಾಖ್ಯಾನಿಸು ರಾಶಿ_CREATE_ENABLE_EXECUTE 0x00040000
#ವ್ಯಾಖ್ಯಾನಿಸು ರಾಶಿ_ಗರಿಷ್ಠ_ಟ್ಯಾಗ್ 0x0FFF
#ವ್ಯಾಖ್ಯಾನಿಸು ರಾಶಿ_PSEUDO_ಟ್ಯಾಗ್_FLAG 0x8000
#ವ್ಯಾಖ್ಯಾನಿಸು ರಾಶಿ_ಟ್ಯಾಗ್_ಸರಿಸು 18
#ವ್ಯಾಖ್ಯಾನಿಸು ರಾಶಿ_MAKE_ಟ್ಯಾಗ್_FLAGS(b,o) ((DWORD)((b) + ((o) << 18)))

    NTSYSAPI VOID NTAPI RtlCaptureContext(PCONTEXT Context_ದಾಖಲೆ);

#ವ್ಯಾಖ್ಯಾನಿಸು IS_ಪಠ್ಯ_UNICODE_ASCII16 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು IS_ಪಠ್ಯ_UNICODE_ಹಿಮ್ಮುಖ_ASCII16 0x0010

#ವ್ಯಾಖ್ಯಾನಿಸು IS_ಪಠ್ಯ_UNICODE_STATISTICS 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು IS_ಪಠ್ಯ_UNICODE_ಹಿಮ್ಮುಖ_STATISTICS 0x0020

#ವ್ಯಾಖ್ಯಾನಿಸು IS_ಪಠ್ಯ_UNICODE_CONTROLS 0x0004
#ವ್ಯಾಖ್ಯಾನಿಸು IS_ಪಠ್ಯ_UNICODE_ಹಿಮ್ಮುಖ_CONTROLS 0x0040

#ವ್ಯಾಖ್ಯಾನಿಸು IS_ಪಠ್ಯ_UNICODE_SIGNATURE 0x0008
#ವ್ಯಾಖ್ಯಾನಿಸು IS_ಪಠ್ಯ_UNICODE_ಹಿಮ್ಮುಖ_SIGNATURE 0x0080

#ವ್ಯಾಖ್ಯಾನಿಸು IS_ಪಠ್ಯ_UNICODE_ILLEGAL_CHARS 0x0100
#ವ್ಯಾಖ್ಯಾನಿಸು IS_ಪಠ್ಯ_UNICODE_ODD_ಉದ್ದಳತೆ 0x0200
#ವ್ಯಾಖ್ಯಾನಿಸು IS_ಪಠ್ಯ_UNICODE_DBCS_LEADBYTE 0x0400
#ವ್ಯಾಖ್ಯಾನಿಸು IS_ಪಠ್ಯ_UNICODE_NULL_ಬೈಟುಗಳು 0x1000

#ವ್ಯಾಖ್ಯಾನಿಸು IS_ಪಠ್ಯ_UNICODE_UNICODE_ಮುಖವಾಡ 0x000F
#ವ್ಯಾಖ್ಯಾನಿಸು IS_ಪಠ್ಯ_UNICODE_ಹಿಮ್ಮುಖ_ಮುಖವಾಡ 0x00F0
#ವ್ಯಾಖ್ಯಾನಿಸು IS_ಪಠ್ಯ_UNICODE_NOT_UNICODE_ಮುಖವಾಡ 0x0F00
#ವ್ಯಾಖ್ಯಾನಿಸು IS_ಪಠ್ಯ_UNICODE_NOT_ASCII_ಮುಖವಾಡ 0xF000

#ವ್ಯಾಖ್ಯಾನಿಸು COMPRESSION_FORMAT_NONE (0x0000)
#ವ್ಯಾಖ್ಯಾನಿಸು COMPRESSION_FORMAT_DEFAULT (0x0001)
#ವ್ಯಾಖ್ಯಾನಿಸು COMPRESSION_FORMAT_LZNT1 (0x0002)
#ವ್ಯಾಖ್ಯಾನಿಸು COMPRESSION_ENGINE_STANDARD (0x0000)
#ವ್ಯಾಖ್ಯಾನಿಸು COMPRESSION_ENGINE_ಗರಿಷ್ಠ (0x0100)
#ವ್ಯಾಖ್ಯಾನಿಸು COMPRESSION_ENGINE_HIBER (0x0200)

#ಆದರೆ _DBG_MEMCPY_INLINE_ && !defined(_MEMCPY_INLINE_) && !defined(_CRTBLD)
#ವ್ಯಾಖ್ಯಾನಿಸು _MEMCPY_INLINE_
    __CRT_INLINE PVOID __cdecl memcpy_inline(ಶೂನ್ಯ *dst,ಸ್ಥಿರಾಂಕ ಶೂನ್ಯ *src,ಗಾತ್ರ_t ಗಾತ್ರ_2) {
      ಆದರೆ(((ಅಕ್ಷರ *)dst > (ಅಕ್ಷರ *)src) && ((ಅಕ್ಷರ *)dst < ((ಅಕ್ಷರ *)src + ಗಾತ್ರ_2))) {
	__debugbreak();
      }
      ಹಿಂತಿರುಗಿ ಸ್ಮರಣೆ_ನಕಲು(dst,src,ಗಾತ್ರ_2);
    }
#ವ್ಯಾಖ್ಯಾನಿಸು ಸ್ಮರಣೆ_ನಕಲು memcpy_inline
#ಆದರೆ_ಅಂತ್ಯ

    NTSYSAPI ಗಾತ್ರ_T NTAPI Rtl_Compare_ಸ್ಮರಣೆ(ಸ್ಥಿರಾಂಕ VOID *Source1,ಸ್ಥಿರಾಂಕ VOID *Source2,ಗಾತ್ರ_T ಉದ್ದಳತೆ_2);

#ವ್ಯಾಖ್ಯಾನಿಸು Rtl_Equal_ಸ್ಮರಣೆ(Destination,ಮೂಲ_2,ಉದ್ದಳತೆ_2) (!memcmp((Destination),(ಮೂಲ_2),(ಉದ್ದಳತೆ_2)))
#ವ್ಯಾಖ್ಯಾನಿಸು Rtl_Move_ಸ್ಮರಣೆ(Destination,ಮೂಲ_2,ಉದ್ದಳತೆ_2) memmove((Destination),(ಮೂಲ_2),(ಉದ್ದಳತೆ_2))
#ವ್ಯಾಖ್ಯಾನಿಸು Rtl_Copy_ಸ್ಮರಣೆ(Destination,ಮೂಲ_2,ಉದ್ದಳತೆ_2) ಸ್ಮರಣೆ_ನಕಲು((Destination),(ಮೂಲ_2),(ಉದ್ದಳತೆ_2))
#ವ್ಯಾಖ್ಯಾನಿಸು Rtl_Fill_ಸ್ಮರಣೆ(Destination,ಉದ್ದಳತೆ_2,Fill) memset((Destination),(Fill),(ಉದ್ದಳತೆ_2))
#ವ್ಯಾಖ್ಯಾನಿಸು Rtl_Zero_ಸ್ಮರಣೆ(Destination,ಉದ್ದಳತೆ_2) memset((Destination),0,(ಉದ್ದಳತೆ_2))

    __CRT_INLINE PVOID Rtl_Secure_Zero_ಸ್ಮರಣೆ(PVOID ptr,ಗಾತ್ರ_T cnt) {
      ಅಸ್ಥಿರ ಅಕ್ಷರ *vptr =(ಅಸ್ಥಿರ ಅಕ್ಷರ *)ptr;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __x86_64
      __stosb((PBYTE)((DWORD64)vptr),0,cnt);
#ಇಲ್ಲದಿದ್ದರೆ
      ಆಗ(cnt) {
	*vptr = 0;
	vptr++;
	cnt--;
      }
#ಆದರೆ_ಅಂತ್ಯ
      ಹಿಂತಿರುಗಿ ptr;
    }

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಸಂದೇಶ_RESOURCE_ನಮೂದು {
      ಶಬ್ದ_3 ಉದ್ದಳತೆ_2;
      ಶಬ್ದ_3 Flags;
      BYTE ಪಠ್ಯ_4[1];
    } ಸಂದೇಶ_RESOURCE_ನಮೂದು_2,*PMESSAGE_RESOURCE_ನಮೂದು;

#ವ್ಯಾಖ್ಯಾನಿಸು ಸಂದೇಶ_RESOURCE_UNICODE 0x0001

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಸಂದೇಶ_RESOURCE_ಖಂಡ {
      DWORD ಕೆಳಗಿನ_Id;
      DWORD ಮೇಲಿನ_Id;
      DWORD ಸ್ಥಾನಾಂತರ_ಗಮ್ಯ_Entries;
    } ಸಂದೇಶ_RESOURCE_ಖಂಡ_2,*PMESSAGE_RESOURCE_ಖಂಡ;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಸಂದೇಶ_RESOURCE_ದತ್ತಾಂಶ {
      DWORD ಸಂಖ್ಯೆ_ದ_ಖಂಡಗಳು;
      ಸಂದೇಶ_RESOURCE_ಖಂಡ_2 ಖಂಡಗಳು_2[1];
    } ಸಂದೇಶ_RESOURCE_ದತ್ತಾಂಶ_2,*PMESSAGE_RESOURCE_ದತ್ತಾಂಶ;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _OSVERSIONINFOA {
      DWORD dw_OSVersion_Info_ಗಾತ್ರ;
      DWORD dw_Major_ಆವೃತ್ತಿ;
      DWORD dw_Minor_ಆವೃತ್ತಿ;
      DWORD dw_Build_ಸಂಖ್ಯೆ;
      DWORD dwPlatformId;
      CHAR szCSDVersion[128];
    } OSVERSIONINFOA,*POSVERSIONINFOA,*LPOSVERSIONINFOA;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _OSVERSIONINFOW {
      DWORD dw_OSVersion_Info_ಗಾತ್ರ;
      DWORD dw_Major_ಆವೃತ್ತಿ;
      DWORD dw_Minor_ಆವೃತ್ತಿ;
      DWORD dw_Build_ಸಂಖ್ಯೆ;
      DWORD dwPlatformId;
      WCHAR szCSDVersion[128];
    } OSVERSIONINFOW,*POSVERSIONINFOW,*LPOSVERSIONINFOW,RTL_OSVERSIONINFOW,*PRTL_OSVERSIONINFOW;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ OSVERSIONINFOW OSVERSIONINFO;
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ POSVERSIONINFOW POSVERSIONINFO;
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPOSVERSIONINFOW LPOSVERSIONINFO;
#ಇಲ್ಲದಿದ್ದರೆ
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ OSVERSIONINFOA OSVERSIONINFO;
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ POSVERSIONINFOA POSVERSIONINFO;
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPOSVERSIONINFOA LPOSVERSIONINFO;
#ಆದರೆ_ಅಂತ್ಯ

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _OSVERSIONINFOEXA {
      DWORD dw_OSVersion_Info_ಗಾತ್ರ;
      DWORD dw_Major_ಆವೃತ್ತಿ;
      DWORD dw_Minor_ಆವೃತ್ತಿ;
      DWORD dw_Build_ಸಂಖ್ಯೆ;
      DWORD dwPlatformId;
      CHAR szCSDVersion[128];
      ಶಬ್ದ_3 wServicePackMajor;
      ಶಬ್ದ_3 wServicePackMinor;
      ಶಬ್ದ_3 w_Suite_ಮುಖವಾಡ;
      BYTE w_ಗುಣಲಬ್ಧ_Type;
      BYTE wReserved;
    } OSVERSIONINFOEXA,*POSVERSIONINFOEXA,*LPOSVERSIONINFOEXA;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _OSVERSIONINFOEXW {
      DWORD dw_OSVersion_Info_ಗಾತ್ರ;
      DWORD dw_Major_ಆವೃತ್ತಿ;
      DWORD dw_Minor_ಆವೃತ್ತಿ;
      DWORD dw_Build_ಸಂಖ್ಯೆ;
      DWORD dwPlatformId;
      WCHAR szCSDVersion[128];
      ಶಬ್ದ_3 wServicePackMajor;
      ಶಬ್ದ_3 wServicePackMinor;
      ಶಬ್ದ_3 w_Suite_ಮುಖವಾಡ;
      BYTE w_ಗುಣಲಬ್ಧ_Type;
      BYTE wReserved;
    } OSVERSIONINFOEXW,*POSVERSIONINFOEXW,*LPOSVERSIONINFOEXW,RTL_OSVERSIONINFOEXW,*PRTL_OSVERSIONINFOEXW;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ OSVERSIONINFOEXW OSVERSIONINFOEX;
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ POSVERSIONINFOEXW POSVERSIONINFOEX;
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPOSVERSIONINFOEXW LPOSVERSIONINFOEX;
#ಇಲ್ಲದಿದ್ದರೆ
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ OSVERSIONINFOEXA OSVERSIONINFOEX;
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ POSVERSIONINFOEXA POSVERSIONINFOEX;
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPOSVERSIONINFOEXA LPOSVERSIONINFOEX;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು VER_EQUAL 1
#ವ್ಯಾಖ್ಯಾನಿಸು VER_GREATER 2
#ವ್ಯಾಖ್ಯಾನಿಸು VER_GREATER_EQUAL 3
#ವ್ಯಾಖ್ಯಾನಿಸು VER_LESS 4
#ವ್ಯಾಖ್ಯಾನಿಸು VER_LESS_EQUAL 5
#ವ್ಯಾಖ್ಯಾನಿಸು VER_AND 6
#ವ್ಯಾಖ್ಯಾನಿಸು VER_OR 7

#ವ್ಯಾಖ್ಯಾನಿಸು VER_CONDITION_ಮುಖವಾಡ 7
#ವ್ಯಾಖ್ಯಾನಿಸು VER_ಅಂಕೆ_ಬಿಟ್ಟುಗಳು_ಪ್ರತಿ_CONDITION_ಮುಖವಾಡ 3

#ವ್ಯಾಖ್ಯಾನಿಸು VER_MINORVERSION 0x0000001
#ವ್ಯಾಖ್ಯಾನಿಸು VER_MAJORVERSION 0x0000002
#ವ್ಯಾಖ್ಯಾನಿಸು VER_BUILDNUMBER 0x0000004
#ವ್ಯಾಖ್ಯಾನಿಸು VER_PLATFORMID 0x0000008
#ವ್ಯಾಖ್ಯಾನಿಸು VER_SERVICEPACKMINOR 0x0000010
#ವ್ಯಾಖ್ಯಾನಿಸು VER_SERVICEPACKMAJOR 0x0000020
#ವ್ಯಾಖ್ಯಾನಿಸು VER_SUITENAME 0x0000040
#ವ್ಯಾಖ್ಯಾನಿಸು VER_ಗುಣಲಬ್ಧ_TYPE 0x0000080

#ವ್ಯಾಖ್ಯಾನಿಸು VER_NT_WORKSTATION 0x0000001
#ವ್ಯಾಖ್ಯಾನಿಸು VER_NT_DOMAIN_CONTROLLER 0x0000002
#ವ್ಯಾಖ್ಯಾನಿಸು VER_NT_SERVER 0x0000003

#ವ್ಯಾಖ್ಯಾನಿಸು VER_PLATFORM_WIN32s 0
#ವ್ಯಾಖ್ಯಾನಿಸು VER_PLATFORM_WIN32_WINDOWS 1
#ವ್ಯಾಖ್ಯಾನಿಸು VER_PLATFORM_WIN32_NT 2

#ವ್ಯಾಖ್ಯಾನಿಸು VER_ಗಣ_CONDITION(_m_,_t_,_c_) ((_m_)=Ver_ಗಣ_Condition_ಮುಖವಾಡ((_m_),(_t_),(_c_)))

    NTSYSAPI ULONGLONG NTAPI Ver_ಗಣ_Condition_ಮುಖವಾಡ(ULONGLONG Condition_ಮುಖವಾಡ,DWORD Type_ಮುಖವಾಡ,BYTE Condition);

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _RTL_CRITICAL_SECTION_DEBUG {
      ಶಬ್ದ_3 Type;
      ಶಬ್ದ_3 Creator_ಹಿಂಭಾಗ_Trace_ಸೂಚ್ಯಂಕ;
      ರಚನೆ _RTL_CRITICAL_SECTION *CriticalSection;
      LIST_ನಮೂದು_2 ProcessLocksList;
      DWORD ನಮೂದು_ಎಣಿಕೆ;
      DWORD Contention_ಎಣಿಕೆ;
      DWORD ಹೆಚ್ಚುವರಿ_2[2];
    } RTL_CRITICAL_SECTION_DEBUG,*PRTL_CRITICAL_SECTION_DEBUG,RTL_RESOURCE_DEBUG,*PRTL_RESOURCE_DEBUG;

#ವ್ಯಾಖ್ಯಾನಿಸು RTL_CRITSECT_TYPE 0
#ವ್ಯಾಖ್ಯಾನಿಸು RTL_RESOURCE_TYPE 1

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _RTL_CRITICAL_SECTION {
      PRTL_CRITICAL_SECTION_DEBUG DebugInfo;
      LONG ಬೀಗ_ಎಣಿಕೆ;
      LONG Recursion_ಎಣಿಕೆ;
      HANDLE OwningThread;
      HANDLE ಬೀಗ_Semaphore;
      ULONG_PTR Spin_ಎಣಿಕೆ;
    } RTL_CRITICAL_SECTION,*PRTL_CRITICAL_SECTION;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ VOID (NTAPI *RTL_VERIFIER_DLL_ತುಂಬು_CALLBACK) (PWSTR DllName,PVOID Dll_ತಳ,ಗಾತ್ರ_T Dll_ಗಾತ್ರ,PVOID Reserved);
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ VOID (NTAPI *RTL_VERIFIER_DLL_UNLOAD_CALLBACK) (PWSTR DllName,PVOID Dll_ತಳ,ಗಾತ್ರ_T Dll_ಗಾತ್ರ,PVOID Reserved);
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ VOID (NTAPI *RTL_VERIFIER_NTDLLHEAPFREE_CALLBACK)(PVOID ಹಂಚಿಕೆ_ತಳ,ಗಾತ್ರ_T ಹಂಚಿಕೆ_ಗಾತ್ರ);

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _RTL_VERIFIER_THUNK_DESCRIPTOR {
      PCHAR ThunkName;
      PVOID Thunk_Old_ವಿಳಾಸ;
      PVOID Thunk_New_ವಿಳಾಸ;
    } RTL_VERIFIER_THUNK_DESCRIPTOR,*PRTL_VERIFIER_THUNK_DESCRIPTOR;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _RTL_VERIFIER_DLL_DESCRIPTOR {
      PWCHAR DllName;
      DWORD DllFlags;
      PVOID Dll_ವಿಳಾಸ;
      PRTL_VERIFIER_THUNK_DESCRIPTOR DllThunks;
    } RTL_VERIFIER_DLL_DESCRIPTOR,*PRTL_VERIFIER_DLL_DESCRIPTOR;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _RTL_VERIFIER_PROVIDER_DESCRIPTOR {
      DWORD ಉದ್ದಳತೆ_2;
      PRTL_VERIFIER_DLL_DESCRIPTOR ProviderDlls;
      RTL_VERIFIER_DLL_ತುಂಬು_CALLBACK Provider_Dll_ತುಂಬು_Callback;
      RTL_VERIFIER_DLL_UNLOAD_CALLBACK ProviderDllUnloadCallback;
      PWSTR VerifierImage;
      DWORD VerifierFlags;
      DWORD VerifierDebug;
      PVOID Rtlp_Get_ರಾಶಿ_Trace_ವಿಳಾಸ;
      PVOID Rtlp_Debug_ಪುಟ_ರಾಶಿ_Create;
      PVOID Rtlp_Debug_ಪುಟ_ರಾಶಿ_Destroy;
      RTL_VERIFIER_NTDLLHEAPFREE_CALLBACK Provider_Ntdll_ರಾಶಿ_Free_Callback;
    } RTL_VERIFIER_PROVIDER_DESCRIPTOR,*PRTL_VERIFIER_PROVIDER_DESCRIPTOR;

#ವ್ಯಾಖ್ಯಾನಿಸು RTL_VRF_FLG_ತುಂಬಿದ_ಪುಟ_ರಾಶಿ 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು RTL_VRF_FLG_RESERVED_DONOTUSE 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು RTL_VRF_FLG_HANDLE_CHECKS 0x00000004
#ವ್ಯಾಖ್ಯಾನಿಸು RTL_VRF_FLG_ರಾಶಿ_CHECKS 0x00000008
#ವ್ಯಾಖ್ಯಾನಿಸು RTL_VRF_FLG_APPCOMPAT_CHECKS 0x00000010
#ವ್ಯಾಖ್ಯಾನಿಸು RTL_VRF_FLG_TLS_CHECKS 0x00000020
#ವ್ಯಾಖ್ಯಾನಿಸು RTL_VRF_FLG_DIRTY_STACKS 0x00000040
#ವ್ಯಾಖ್ಯಾನಿಸು RTL_VRF_FLG_RPC_CHECKS 0x00000080
#ವ್ಯಾಖ್ಯಾನಿಸು RTL_VRF_FLG_COM_CHECKS 0x00000100
#ವ್ಯಾಖ್ಯಾನಿಸು RTL_VRF_FLG_DANGEROUS_APIS 0x00000200
#ವ್ಯಾಖ್ಯಾನಿಸು RTL_VRF_FLG_RACE_CHECKS 0x00000400
#ವ್ಯಾಖ್ಯಾನಿಸು RTL_VRF_FLG_DEADLOCK_CHECKS 0x00000800
#ವ್ಯಾಖ್ಯಾನಿಸು RTL_VRF_FLG_ಮೊದಲ_CHANCE_EXCEPTION_CHECKS 0x00001000
#ವ್ಯಾಖ್ಯಾನಿಸು RTL_VRF_FLG_VIRTUAL_MEM_CHECKS 0x00002000
#ವ್ಯಾಖ್ಯಾನಿಸು RTL_VRF_FLG_ENABLE_LOGGING 0x00004000
#ವ್ಯಾಖ್ಯಾನಿಸು RTL_VRF_FLG_FAST_FILL_ರಾಶಿ 0x00008000
#ವ್ಯಾಖ್ಯಾನಿಸು RTL_VRF_FLG_VIRTUAL_SPACE_TRACKING 0x00010000
#ವ್ಯಾಖ್ಯಾನಿಸು RTL_VRF_FLG_ENABLED_SYSTEM_WIDE 0x00020000
#ವ್ಯಾಖ್ಯಾನಿಸು RTL_VRF_FLG_MISCELLANEOUS_CHECKS 0x00020000
#ವ್ಯಾಖ್ಯಾನಿಸು RTL_VRF_FLG_ಬೀಗ_CHECKS 0x00040000

#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_ಆಂತರಿಕ_ERROR 0x80000000
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_ಆಂತರಿಕ_WARNING 0x40000000
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_NO_BREAK 0x20000000
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_CONTINUABLE_BREAK 0x10000000

#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_UNKNOWN_ERROR 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_ACCESS_VIOLATION 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_UNSYNCHRONIZED_ACCESS 0x0003
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_EXTREME_ಗಾತ್ರ_REQUEST 0x0004
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_BAD_ರಾಶಿ_HANDLE 0x0005
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_SWITCHED_ರಾಶಿ_HANDLE 0x0006
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_DOUBLE_FREE 0x0007
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_CORRUPTED_ರಾಶಿ_ಖಂಡ 0x0008
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_DESTROY_PROCESS_ರಾಶಿ 0x0009
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_UNEXPECTED_EXCEPTION 0x000A
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_CORRUPTED_ರಾಶಿ_ಖಂಡ_EXCEPTION_RAISED_FOR_ಶೀರ್ಷಿಕೆ 0x000B
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_CORRUPTED_ರಾಶಿ_ಖಂಡ_EXCEPTION_RAISED_FOR_PROBING 0x000C
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_CORRUPTED_ರಾಶಿ_ಖಂಡ_ಶೀರ್ಷಿಕೆ 0x000D
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_CORRUPTED_FREED_ರಾಶಿ_ಖಂಡ 0x000E
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_CORRUPTED_ರಾಶಿ_ಖಂಡ_SUFFIX 0x000F
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_CORRUPTED_ರಾಶಿ_ಖಂಡ_ಆರಂಭ_STAMP 0x0010
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_CORRUPTED_ರಾಶಿ_ಖಂಡ_ಕೊನೆ_STAMP 0x0011
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_CORRUPTED_ರಾಶಿ_ಖಂಡ_ಪೂರ್ವಪ್ರತ್ಯಯ 0x0012
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_ಮೊದಲ_CHANCE_ACCESS_VIOLATION 0x0013
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_CORRUPTED_ರಾಶಿ_LIST 0x0014

#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_TERMINATE_THREAD_CALL 0x0100
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_ರಾಶಿ_ಅತಿಪ್ರವಾಹ 0x0101
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_INVALID_EXIT_PROCESS_CALL 0x0102

#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_EXIT_THREAD_OWNS_ಬೀಗ 0x0200
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_ಬೀಗ_ಒಳ_UNLOADED_DLL 0x0201
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_ಬೀಗ_ಒಳ_FREED_ರಾಶಿ 0x0202
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_ಬೀಗ_DOUBLE_INITIALIZE 0x0203
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_ಬೀಗ_ಒಳ_FREED_ಸ್ಮರಣೆ 0x0204
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_ಬೀಗ_CORRUPTED 0x0205
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_ಬೀಗ_INVALID_OWNER 0x0206
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_ಬೀಗ_INVALID_RECURSION_ಎಣಿಕೆ 0x0207
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_ಬೀಗ_INVALID_ಬೀಗ_ಎಣಿಕೆ 0x0208
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_ಬೀಗ_OVER_RELEASED 0x0209
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_ಬೀಗ_NOT_INITIALIZED 0x0210
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_ಬೀಗ_ALREADY_INITIALIZED 0x0211
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_ಬೀಗ_ಒಳ_FREED_VMEM 0x0212
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_ಬೀಗ_ಒಳ_UNMAPPED_MEM 0x0213
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_THREAD_NOT_ಬೀಗ_OWNER 0x0214

#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_INVALID_HANDLE 0x0300
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_INVALID_TLS_ಮೌಲ್ಯ 0x0301
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_INCORRECT_WAIT_CALL 0x0302
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_NULL_HANDLE 0x0303
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_WAIT_ಒಳ_DLLMAIN 0x0304

#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_COM_ERROR 0x0400
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_COM_API_ಒಳ_DLLMAIN 0x0401
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_COM_UNHANDLED_EXCEPTION 0x0402
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_COM_UNBALANCED_COINIT 0x0403
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_COM_UNBALANCED_OLEINIT 0x0404
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_COM_UNBALANCED_SWC 0x0405
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_COM_NULL_DACL 0x0406
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_COM_UNSAFE_IMPERSONATION 0x0407
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_COM_SMUGGLED_WRAPPER 0x0408
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_COM_SMUGGLED_PROXY 0x0409
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_COM_CF_SUCCESS_WITH_NULL 0x040A
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_COM_GCO_SUCCESS_WITH_NULL 0x040B
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_COM_OBJECT_ಒಳ_FREED_ಸ್ಮರಣೆ 0x040C
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_COM_OBJECT_ಒಳ_UNLOADED_DLL 0x040D
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_COM_VTBL_ಒಳ_FREED_ಸ್ಮರಣೆ 0x040E
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_COM_VTBL_ಒಳ_UNLOADED_DLL 0x040F
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_COM_HOLDING_LOCKS_ON_CALL 0x0410

#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_RPC_ERROR 0x0500

#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_INVALID_FREEMEM 0x0600
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_INVALID_ALLOCMEM 0x0601
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_INVALID_MAPVIEW 0x0602
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_PROBE_INVALID_ವಿಳಾಸ 0x0603
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_PROBE_FREE_MEM 0x0604
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_PROBE_GUARD_ಪುಟ 0x0605
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_PROBE_NULL 0x0606
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_PROBE_INVALID_ಆರಂಭ_OR_ಗಾತ್ರ 0x0607
#ವ್ಯಾಖ್ಯಾನಿಸು APPLICATION_VERIFIER_ಗಾತ್ರ_ರಾಶಿ_UNEXPECTED_EXCEPTION 0x0618

#ವ್ಯಾಖ್ಯಾನಿಸು VERIFIER_STOP(ಸಂಕೇತ_5,ಸಂದೇಶ_5,P1,S1,P2,S2,P3,S3,P4,S4) { RtlApplicationVerifierStop ((ಸಂಕೇತ_5),(ಸಂದೇಶ_5),(ULONG_PTR)(P1),(S1),(ULONG_PTR)(P2),(S2),(ULONG_PTR)(P3),(S3),(ULONG_PTR)(P4),(S4)); }

    VOID NTAPI RtlApplicationVerifierStop(ULONG_PTR ಸಂಕೇತ_5,PSTR ಸಂದೇಶ_6,ULONG_PTR Param1,PSTR Description1,ULONG_PTR Param2,PSTR Description2,ULONG_PTR Param3,PSTR Description3,ULONG_PTR Param4,PSTR Description4);

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LONG (NTAPI *PVECTORED_EXCEPTION_HANDLER)(ರಚನೆ EXCEPTION_ಸೂಚಕಗಳು_2 *ExceptionInfo);
#ವ್ಯಾಖ್ಯಾನಿಸು SEF_DACL_AUTO_INHERIT 0x01
#ವ್ಯಾಖ್ಯಾನಿಸು SEF_SACL_AUTO_INHERIT 0x02
#ವ್ಯಾಖ್ಯಾನಿಸು SEF_DEFAULT_DESCRIPTOR_FOR_OBJECT 0x04
#ವ್ಯಾಖ್ಯಾನಿಸು SEF_AVOID_PRIVILEGE_CHECK 0x08
#ವ್ಯಾಖ್ಯಾನಿಸು SEF_AVOID_OWNER_CHECK 0x10
#ವ್ಯಾಖ್ಯಾನಿಸು SEF_DEFAULT_OWNER_FROM_ಪೋಷಕ 0x20
#ವ್ಯಾಖ್ಯಾನಿಸು SEF_DEFAULT_ಗುಂಪು_FROM_ಪೋಷಕ 0x40

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಎಣಿಕೆ ರಾಶಿ_INFORMATION_CLASS_2 {
      ರಾಶಿ_Compatibility_Information
    } ರಾಶಿ_INFORMATION_CLASS;

    NTSYSAPI DWORD NTAPI Rtl_ಗಣ_ರಾಶಿ_Information(PVOID ರಾಶಿ_Handle,ರಾಶಿ_INFORMATION_CLASS ರಾಶಿ_Information_Class,PVOID ರಾಶಿ_Information,ಗಾತ್ರ_T ರಾಶಿ_Information_ಉದ್ದಳತೆ);
    NTSYSAPI DWORD NTAPI Rtl_Query_ರಾಶಿ_Information(PVOID ರಾಶಿ_Handle,ರಾಶಿ_INFORMATION_CLASS ರಾಶಿ_Information_Class,PVOID ರಾಶಿ_Information,ಗಾತ್ರ_T ರಾಶಿ_Information_ಉದ್ದಳತೆ,PSIZE_T Return_ಉದ್ದಳತೆ);
    DWORD NTAPI Rtl_ಅಪವರ್ತ್ಯ_Allocate_ರಾಶಿ(PVOID ರಾಶಿ_Handle,DWORD Flags,ಗಾತ್ರ_T ಗಾತ್ರ_4,DWORD ಎಣಿಕೆ_4,PVOID *Array);
    DWORD NTAPI Rtl_ಅಪವರ್ತ್ಯ_Free_ರಾಶಿ(PVOID ರಾಶಿ_Handle,DWORD Flags,DWORD ಎಣಿಕೆ_4,PVOID *Array);

#ವ್ಯಾಖ್ಯಾನಿಸು WT_EXECUTEDEFAULT 0x00000000
#ವ್ಯಾಖ್ಯಾನಿಸು WT_EXECUTEINIOTHREAD 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು WT_EXECUTEINUITHREAD 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು WT_EXECUTEINWAITTHREAD 0x00000004
#ವ್ಯಾಖ್ಯಾನಿಸು WT_EXECUTEONLYONCE 0x00000008
#ವ್ಯಾಖ್ಯಾನಿಸು WT_EXECUTEINTIMERTHREAD 0x00000020
#ವ್ಯಾಖ್ಯಾನಿಸು WT_EXECUTELONGFUNCTION 0x00000010
#ವ್ಯಾಖ್ಯಾನಿಸು WT_EXECUTEINPERSISTENTIOTHREAD 0x00000040
#ವ್ಯಾಖ್ಯಾನಿಸು WT_EXECUTEINPERSISTENTTHREAD 0x00000080
#ವ್ಯಾಖ್ಯಾನಿಸು WT_TRANSFER_IMPERSONATION 0x00000100
#ವ್ಯಾಖ್ಯಾನಿಸು WT_ಗಣ_MAX_THREADPOOL_ಎಳೆಗಳು(Flags,ಎಲ್ಲೆ_2) ((Flags) |= (ಎಲ್ಲೆ_2)<<16)
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ VOID (NTAPI *WAITORTIMERCALLBACKFUNC)(PVOID,BOOLEAN);
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ VOID (NTAPI *WORKERCALLBACKFUNC)(PVOID);
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ VOID (NTAPI *APC_CALLBACK_FUNCTION)(DWORD ,PVOID,PVOID);
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ
      VOID
      (NTAPI *PFLS_CALLBACK_FUNCTION)(PVOID lp_Fls_ದತ್ತಾಂಶ);
#ವ್ಯಾಖ್ಯಾನಿಸು WT_EXECUTEINLONGTHREAD 0x00000010
#ವ್ಯಾಖ್ಯಾನಿಸು WT_EXECUTEDELETEWAIT 0x00000008

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಎಣಿಕೆ _ACTIVATION_CONTEXT_INFO_CLASS {
      ActivationContextBasicInformation = 1,ActivationContextDetailedInformation = 2,Assembly_Detailed_Information_ಒಳ_Activation_Context = 3,File_Information_ಒಳ_Assembly_ದ_Assembly_ಒಳ_Activation_Context = 4,MaxActivationContextInfoClass,Assembly_Detailed_Information_ಒಳ_Activation_Contxt = 3,File_Information_ಒಳ_Assembly_ದ_Assembly_ಒಳ_Activation_Contxt = 4
    } ACTIVATION_CONTEXT_INFO_CLASS;

#ವ್ಯಾಖ್ಯಾನಿಸು ACTIVATIONCONTEXTINFOCLASS ACTIVATION_CONTEXT_INFO_CLASS

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ACTIVATION_CONTEXT_QUERY_ಸೂಚ್ಯಂಕ {
      DWORD ul_Assembly_ಸೂಚ್ಯಂಕ;
      DWORD ul_File_ಸೂಚ್ಯಂಕ_ಒಳ_Assembly;
    } ACTIVATION_CONTEXT_QUERY_ಸೂಚ್ಯಂಕ_2,*PACTIVATION_CONTEXT_QUERY_ಸೂಚ್ಯಂಕ;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಸ್ಥಿರಾಂಕ ರಚನೆ ACTIVATION_CONTEXT_QUERY_ಸೂಚ್ಯಂಕ *PCACTIVATION_CONTEXT_QUERY_ಸೂಚ್ಯಂಕ;

#ವ್ಯಾಖ್ಯಾನಿಸು ACTIVATION_CONTEXT_ಮಾರ್ಗ_TYPE_NONE (1)
#ವ್ಯಾಖ್ಯಾನಿಸು ACTIVATION_CONTEXT_ಮಾರ್ಗ_TYPE_WIN32_FILE (2)
#ವ್ಯಾಖ್ಯಾನಿಸು ACTIVATION_CONTEXT_ಮಾರ್ಗ_TYPE_URL (3)
#ವ್ಯಾಖ್ಯಾನಿಸು ACTIVATION_CONTEXT_ಮಾರ್ಗ_TYPE_ASSEMBLYREF (4)

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _ASSEMBLY_FILE_DETAILED_INFORMATION {
      DWORD ulFlags;
      DWORD ul_Filename_ಉದ್ದಳತೆ;
      DWORD ul_ಮಾರ್ಗ_ಉದ್ದಳತೆ;

      PCWSTR lpFileName;
      PCWSTR lp_File_ಮಾರ್ಗ;
    } ASSEMBLY_FILE_DETAILED_INFORMATION,*PASSEMBLY_FILE_DETAILED_INFORMATION;
    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಸ್ಥಿರಾಂಕ ASSEMBLY_FILE_DETAILED_INFORMATION *PCASSEMBLY_FILE_DETAILED_INFORMATION;

#ವ್ಯಾಖ್ಯಾನಿಸು _ASSEMBLY_DLL_REDIRECTION_DETAILED_INFORMATION _ASSEMBLY_FILE_DETAILED_INFORMATION
#ವ್ಯಾಖ್ಯಾನಿಸು ASSEMBLY_DLL_REDIRECTION_DETAILED_INFORMATION ASSEMBLY_FILE_DETAILED_INFORMATION
#ವ್ಯಾಖ್ಯಾನಿಸು PASSEMBLY_DLL_REDIRECTION_DETAILED_INFORMATION PASSEMBLY_FILE_DETAILED_INFORMATION
#ವ್ಯಾಖ್ಯಾನಿಸು PCASSEMBLY_DLL_REDIRECTION_DETAILED_INFORMATION PCASSEMBLY_FILE_DETAILED_INFORMATION

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _ACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION {
      DWORD ulFlags;
      DWORD ul_Encoded_Assembly_ತಟಸ್ಥ_ಉದ್ದಳತೆ;
      DWORD ul_Manifest_ಮಾರ್ಗ_Type;
      DWORD ul_Manifest_ಮಾರ್ಗ_ಉದ್ದಳತೆ;
      LARGE_INTEGER li_Manifest_ಕೊನೆಯ_Write_ಸಮಯ;
      DWORD ul_Policy_ಮಾರ್ಗ_Type;
      DWORD ul_Policy_ಮಾರ್ಗ_ಉದ್ದಳತೆ;
      LARGE_INTEGER li_Policy_ಕೊನೆಯ_Write_ಸಮಯ;
      DWORD ul_Metadata_Satellite_Roster_ಸೂಚ್ಯಂಕ;
      DWORD ul_Manifest_ಆವೃತ್ತಿ_Major;
      DWORD ul_Manifest_ಆವೃತ್ತಿ_Minor;
      DWORD ul_Policy_ಆವೃತ್ತಿ_Major;
      DWORD ul_Policy_ಆವೃತ್ತಿ_Minor;
      DWORD ul_Assembly_Directory_Name_ಉದ್ದಳತೆ;
      PCWSTR lp_Assembly_Encoded_Assembly_ತಟಸ್ಥ;
      PCWSTR lp_Assembly_Manifest_ಮಾರ್ಗ;
      PCWSTR lp_Assembly_Policy_ಮಾರ್ಗ;
      PCWSTR lpAssemblyDirectoryName;
      DWORD ul_File_ಎಣಿಕೆ;
    } ACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION,*PACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಸ್ಥಿರಾಂಕ ರಚನೆ _ACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION *PCACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _ACTIVATION_CONTEXT_DETAILED_INFORMATION {
      DWORD dwFlags;
      DWORD ul_Format_ಆವೃತ್ತಿ;
      DWORD ul_Assembly_ಎಣಿಕೆ;
      DWORD ul_ಬೇರು_Manifest_ಮಾರ್ಗ_Type;
      DWORD ul_ಬೇರು_Manifest_ಮಾರ್ಗ_Chars;
      DWORD ul_ಬೇರು_Configuration_ಮಾರ್ಗ_Type;
      DWORD ul_ಬೇರು_Configuration_ಮಾರ್ಗ_Chars;
      DWORD ul_App_Dir_ಮಾರ್ಗ_Type;
      DWORD ul_App_Dir_ಮಾರ್ಗ_Chars;
      PCWSTR lp_ಬೇರು_Manifest_ಮಾರ್ಗ;
      PCWSTR lp_ಬೇರು_Configuration_ಮಾರ್ಗ;
      PCWSTR lp_App_Dir_ಮಾರ್ಗ;
    } ACTIVATION_CONTEXT_DETAILED_INFORMATION,*PACTIVATION_CONTEXT_DETAILED_INFORMATION;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಸ್ಥಿರಾಂಕ ರಚನೆ _ACTIVATION_CONTEXT_DETAILED_INFORMATION *PCACTIVATION_CONTEXT_DETAILED_INFORMATION;

#ವ್ಯಾಖ್ಯಾನಿಸು DLL_PROCESS_ATTACH 1
#ವ್ಯಾಖ್ಯಾನಿಸು DLL_THREAD_ATTACH 2
#ವ್ಯಾಖ್ಯಾನಿಸು DLL_THREAD_DETACH 3
#ವ್ಯಾಖ್ಯಾನಿಸು DLL_PROCESS_DETACH 0
#ವ್ಯಾಖ್ಯಾನಿಸು DLL_PROCESS_VERIFIER 4

#ವ್ಯಾಖ್ಯಾನಿಸು EVENTLOG_SEQUENTIAL_READ 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು EVENTLOG_SEEK_READ 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು EVENTLOG_FORWARDS_READ 0x0004
#ವ್ಯಾಖ್ಯಾನಿಸು EVENTLOG_BACKWARDS_READ 0x0008

#ವ್ಯಾಖ್ಯಾನಿಸು EVENTLOG_SUCCESS 0x0000
#ವ್ಯಾಖ್ಯಾನಿಸು EVENTLOG_ERROR_TYPE 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು EVENTLOG_WARNING_TYPE 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು EVENTLOG_INFORMATION_TYPE 0x0004
#ವ್ಯಾಖ್ಯಾನಿಸು EVENTLOG_AUDIT_SUCCESS 0x0008
#ವ್ಯಾಖ್ಯಾನಿಸು EVENTLOG_AUDIT_FAILURE 0x0010

#ವ್ಯಾಖ್ಯಾನಿಸು EVENTLOG_ಆರಂಭ_PAIRED_EVENT 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು EVENTLOG_ಕೊನೆ_PAIRED_EVENT 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು EVENTLOG_ಕೊನೆ_ALL_PAIRED_EVENTS 0x0004
#ವ್ಯಾಖ್ಯಾನಿಸು EVENTLOG_PAIRED_EVENT_ಸಕ್ರಿಯ 0x0008
#ವ್ಯಾಖ್ಯಾನಿಸು EVENTLOG_PAIRED_EVENT_INACTIVE 0x0010

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _EVENTLOGRECORD {
      DWORD ಉದ್ದಳತೆ_2;
      DWORD Reserved;
      DWORD ದಾಖಲೆ_ಸಂಖ್ಯೆ;
      DWORD ಸಮಯ_Generated;
      DWORD ಸಮಯ_Written;
      DWORD EventID;
      ಶಬ್ದ_3 EventType;
      ಶಬ್ದ_3 ಅಂಕೆ_ಅಕ್ಷರಸರಣಿಗಳು;
      ಶಬ್ದ_3 EventCategory;
      ಶಬ್ದ_3 ReservedFlags;
      DWORD Closing_ದಾಖಲೆ_ಸಂಖ್ಯೆ;
      DWORD String_ಸ್ಥಾನಾಂತರ;
      DWORD User_Sid_ಉದ್ದಳತೆ;
      DWORD User_Sid_ಸ್ಥಾನಾಂತರ;
      DWORD ದತ್ತಾಂಶ_ಉದ್ದಳತೆ;
      DWORD ದತ್ತಾಂಶ_ಸ್ಥಾನಾಂತರ_2;
    } EVENTLOGRECORD,*PEVENTLOGRECORD;

#ವ್ಯಾಖ್ಯಾನಿಸು MAXLOGICALLOGNAMESIZE 256

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _EVENTSFORLOGFILE{
      DWORD ul_ಗಾತ್ರ;
      WCHAR szLogicalLogFile[MAXLOGICALLOGNAMESIZE];
      DWORD ul_ಅಂಕೆ_ದಾಖಲೆಗಳು;
      EVENTLOGRECORD p_Event_Log_ದಾಖಲೆಗಳು[];
    } EVENTSFORLOGFILE,*PEVENTSFORLOGFILE;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _PACKEDEVENTINFO{
      DWORD ul_ಗಾತ್ರ;
      DWORD ul_ಅಂಕೆ_Events_For_Log_File;
      DWORD ulOffsets[];
    } PACKEDEVENTINFO,*PPACKEDEVENTINFO;

#ವ್ಯಾಖ್ಯಾನಿಸು ಕೀಲಿ_QUERY_ಮೌಲ್ಯ (0x0001)
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೀಲಿ_ಗಣ_ಮೌಲ್ಯ (0x0002)
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೀಲಿ_CREATE_SUB_ಕೀಲಿ (0x0004)
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೀಲಿ_ENUMERATE_SUB_ಕೀಲಿಗಳು (0x0008)
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೀಲಿ_NOTIFY (0x0010)
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೀಲಿ_CREATE_LINK (0x0020)
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೀಲಿ_WOW64_32_ಕೀಲಿ (0x0200)
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೀಲಿ_WOW64_64_ಕೀಲಿ (0x0100)
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೀಲಿ_WOW64_RES (0x0300)

#ವ್ಯಾಖ್ಯಾನಿಸು ಕೀಲಿ_READ ((STANDARD_RIGHTS_READ | ಕೀಲಿ_QUERY_ಮೌಲ್ಯ | ಕೀಲಿ_ENUMERATE_SUB_ಕೀಲಿಗಳು | ಕೀಲಿ_NOTIFY) & (~SYNCHRONIZE))
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೀಲಿ_WRITE ((STANDARD_RIGHTS_WRITE | ಕೀಲಿ_ಗಣ_ಮೌಲ್ಯ | ಕೀಲಿ_CREATE_SUB_ಕೀಲಿ) & (~SYNCHRONIZE))
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೀಲಿ_EXECUTE ((ಕೀಲಿ_READ) & (~SYNCHRONIZE))
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೀಲಿ_ALL_ACCESS ((STANDARD_RIGHTS_ALL | ಕೀಲಿ_QUERY_ಮೌಲ್ಯ | ಕೀಲಿ_ಗಣ_ಮೌಲ್ಯ | ಕೀಲಿ_CREATE_SUB_ಕೀಲಿ | ಕೀಲಿ_ENUMERATE_SUB_ಕೀಲಿಗಳು | ಕೀಲಿ_NOTIFY | ಕೀಲಿ_CREATE_LINK) & (~SYNCHRONIZE))
#ವ್ಯಾಖ್ಯಾನಿಸು REG_OPTION_RESERVED (0x00000000L)

#ವ್ಯಾಖ್ಯಾನಿಸು REG_OPTION_NON_VOLATILE (0x00000000L)
#ವ್ಯಾಖ್ಯಾನಿಸು REG_OPTION_VOLATILE (0x00000001L)
#ವ್ಯಾಖ್ಯಾನಿಸು REG_OPTION_CREATE_LINK (0x00000002L)
#ವ್ಯಾಖ್ಯಾನಿಸು REG_OPTION_BACKUP_RESTORE (0x00000004L)
#ವ್ಯಾಖ್ಯಾನಿಸು REG_OPTION_OPEN_LINK (0x00000008L)
#ವ್ಯಾಖ್ಯಾನಿಸು REG_LEGAL_OPTION (REG_OPTION_RESERVED | REG_OPTION_NON_VOLATILE | REG_OPTION_VOLATILE | REG_OPTION_CREATE_LINK | REG_OPTION_BACKUP_RESTORE | REG_OPTION_OPEN_LINK)
#ವ್ಯಾಖ್ಯಾನಿಸು REG_CREATED_NEW_ಕೀಲಿ (0x00000001L)
#ವ್ಯಾಖ್ಯಾನಿಸು REG_OPENED_EXISTING_ಕೀಲಿ (0x00000002L)
#ವ್ಯಾಖ್ಯಾನಿಸು REG_STANDARD_FORMAT 1
#ವ್ಯಾಖ್ಯಾನಿಸು REG_LATEST_FORMAT 2
#ವ್ಯಾಖ್ಯಾನಿಸು REG_NO_COMPRESSION 4
#ವ್ಯಾಖ್ಯಾನಿಸು REG_ಸಂಪೂರ್ಣ_HIVE_VOLATILE (0x00000001L)
#ವ್ಯಾಖ್ಯಾನಿಸು REG_REFRESH_HIVE (0x00000002L)
#ವ್ಯಾಖ್ಯಾನಿಸು REG_NO_LAZY_FLUSH (0x00000004L)
#ವ್ಯಾಖ್ಯಾನಿಸು REG_FORCE_RESTORE (0x00000008L)
#ವ್ಯಾಖ್ಯಾನಿಸು REG_FORCE_UNLOAD 1

#ವ್ಯಾಖ್ಯಾನಿಸು REG_NOTIFY_CHANGE_NAME (0x00000001L)
#ವ್ಯಾಖ್ಯಾನಿಸು REG_NOTIFY_CHANGE_ಗುಣಲಕ್ಷಣಗಳು (0x00000002L)
#ವ್ಯಾಖ್ಯಾನಿಸು REG_NOTIFY_CHANGE_ಕೊನೆಯ_ಗಣ (0x00000004L)
#ವ್ಯಾಖ್ಯಾನಿಸು REG_NOTIFY_CHANGE_SECURITY (0x00000008L)

#ವ್ಯಾಖ್ಯಾನಿಸು REG_LEGAL_CHANGE_FILTER (REG_NOTIFY_CHANGE_NAME | REG_NOTIFY_CHANGE_ಗುಣಲಕ್ಷಣಗಳು | REG_NOTIFY_CHANGE_ಕೊನೆಯ_ಗಣ | REG_NOTIFY_CHANGE_SECURITY)

#ವ್ಯಾಖ್ಯಾನಿಸು REG_NONE (0)
#ವ್ಯಾಖ್ಯಾನಿಸು REG_SZ (1)
#ವ್ಯಾಖ್ಯಾನಿಸು REG_EXPAND_SZ (2)

#ವ್ಯಾಖ್ಯಾನಿಸು REG_ದ್ವಿಮಾನ (3)
#ವ್ಯಾಖ್ಯಾನಿಸು REG_DWORD (4)
#ವ್ಯಾಖ್ಯಾನಿಸು REG_DWORD_LITTLE_ENDIAN (4)
#ವ್ಯಾಖ್ಯಾನಿಸು REG_DWORD_BIG_ENDIAN (5)
#ವ್ಯಾಖ್ಯಾನಿಸು REG_LINK (6)
#ವ್ಯಾಖ್ಯಾನಿಸು REG_MULTI_SZ (7)
#ವ್ಯಾಖ್ಯಾನಿಸು REG_RESOURCE_LIST (8)
#ವ್ಯಾಖ್ಯಾನಿಸು REG_ತುಂಬಿದ_RESOURCE_DESCRIPTOR (9)
#ವ್ಯಾಖ್ಯಾನಿಸು REG_RESOURCE_REQUIREMENTS_LIST (10)
#ವ್ಯಾಖ್ಯಾನಿಸು REG_QWORD (11)
#ವ್ಯಾಖ್ಯಾನಿಸು REG_QWORD_LITTLE_ENDIAN (11)

#ವ್ಯಾಖ್ಯಾನಿಸು SERVICE_KERNEL_DRIVER 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು SERVICE_FILE_SYSTEM_DRIVER 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು SERVICE_ADAPTER 0x00000004
#ವ್ಯಾಖ್ಯಾನಿಸು SERVICE_RECOGNIZER_DRIVER 0x00000008

#ವ್ಯಾಖ್ಯಾನಿಸು SERVICE_DRIVER (SERVICE_KERNEL_DRIVER | SERVICE_FILE_SYSTEM_DRIVER | SERVICE_RECOGNIZER_DRIVER)

#ವ್ಯಾಖ್ಯಾನಿಸು SERVICE_WIN32_OWN_PROCESS 0x00000010
#ವ್ಯಾಖ್ಯಾನಿಸು SERVICE_WIN32_SHARE_PROCESS 0x00000020
#ವ್ಯಾಖ್ಯಾನಿಸು SERVICE_WIN32 (SERVICE_WIN32_OWN_PROCESS | SERVICE_WIN32_SHARE_PROCESS)

#ವ್ಯಾಖ್ಯಾನಿಸು SERVICE_INTERACTIVE_PROCESS 0x00000100

#ವ್ಯಾಖ್ಯಾನಿಸು SERVICE_TYPE_ALL (SERVICE_WIN32 | SERVICE_ADAPTER | SERVICE_DRIVER | SERVICE_INTERACTIVE_PROCESS)

#ವ್ಯಾಖ್ಯಾನಿಸು SERVICE_BOOT_ಆರಂಭ 0x00000000
#ವ್ಯಾಖ್ಯಾನಿಸು SERVICE_SYSTEM_ಆರಂಭ 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು SERVICE_AUTO_ಆರಂಭ 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು SERVICE_DEMAND_ಆರಂಭ 0x00000003
#ವ್ಯಾಖ್ಯಾನಿಸು SERVICE_DISABLED 0x00000004

#ವ್ಯಾಖ್ಯಾನಿಸು SERVICE_ERROR_IGNORE 0x00000000
#ವ್ಯಾಖ್ಯಾನಿಸು SERVICE_ERROR_ಸಾಮಾನ್ಯ 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು SERVICE_ERROR_SEVERE 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು SERVICE_ERROR_CRITICAL 0x00000003

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಎಣಿಕೆ CM_SERVICE_ಗಂಟು_TYPE {
      DriverType = SERVICE_KERNEL_DRIVER,FileSystemType = SERVICE_FILE_SYSTEM_DRIVER,Win32ServiceOwnProcess = SERVICE_WIN32_OWN_PROCESS,
      Win32ServiceShareProcess = SERVICE_WIN32_SHARE_PROCESS,AdapterType = SERVICE_ADAPTER,RecognizerType = SERVICE_RECOGNIZER_DRIVER
    } SERVICE_ಗಂಟು_TYPE;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಎಣಿಕೆ CM_SERVICE_ತುಂಬು_TYPE {
      Boot_ತುಂಬು = SERVICE_BOOT_ಆರಂಭ,System_ತುಂಬು = SERVICE_SYSTEM_ಆರಂಭ,Auto_ತುಂಬು = SERVICE_AUTO_ಆರಂಭ,Demand_ತುಂಬು = SERVICE_DEMAND_ಆರಂಭ,
      Disable_ತುಂಬು = SERVICE_DISABLED
    } SERVICE_ತುಂಬು_TYPE;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಎಣಿಕೆ _CM_ERROR_CONTROL_TYPE {
      IgnoreError = SERVICE_ERROR_IGNORE,ಸಾಮಾನ್ಯ_Error = SERVICE_ERROR_ಸಾಮಾನ್ಯ,SevereError = SERVICE_ERROR_SEVERE,CriticalError = SERVICE_ERROR_CRITICAL
    } SERVICE_ERROR_TYPE;

#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_ERASE_SHORT 0L
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_ERASE_LONG 1L

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಪಟ್ಟಿ_ERASE {
      DWORD Type;
      BOOLEAN ತಕ್ಷಣ_2;
    } ಪಟ್ಟಿ_ERASE_2,*PTAPE_ERASE;

#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_ತುಂಬು 0L
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_UNLOAD 1L
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_TENSION 2L
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_ಬೀಗ 3L
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_UNLOCK 4L
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_FORMAT 5L

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಪಟ್ಟಿ_PREPARE {
      DWORD Operation;
      BOOLEAN ತಕ್ಷಣ_2;
    } ಪಟ್ಟಿ_PREPARE_2,*PTAPE_PREPARE;

#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_SETMARKS 0L
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_FILEMARKS 1L
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_SHORT_FILEMARKS 2L
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_LONG_FILEMARKS 3L

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಪಟ್ಟಿ_WRITE_MARKS {
      DWORD Type;
      DWORD ಎಣಿಕೆ_4;
      BOOLEAN ತಕ್ಷಣ_2;
    } ಪಟ್ಟಿ_WRITE_MARKS_2,*PTAPE_WRITE_MARKS;

#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_ABSOLUTE_POSITION 0L
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_LOGICAL_POSITION 1L
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_PSEUDO_LOGICAL_POSITION 2L

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಪಟ್ಟಿ_GET_POSITION {
      DWORD Type;
      DWORD ವಿಭಜನೆ_2;
      LARGE_INTEGER ಸ್ಥಾನಾಂತರ_3;
    } ಪಟ್ಟಿ_GET_POSITION_2,*PTAPE_GET_POSITION;

#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_REWIND 0L
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_ABSOLUTE_ಖಂಡ 1L
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_LOGICAL_ಖಂಡ 2L
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_PSEUDO_LOGICAL_ಖಂಡ 3L
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_SPACE_ಕೊನೆ_ದ_ದತ್ತಾಂಶ 4L
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_SPACE_RELATIVE_ಖಂಡಗಳು 5L
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_SPACE_FILEMARKS 6L
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_SPACE_SEQUENTIAL_FMKS 7L
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_SPACE_SETMARKS 8L
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_SPACE_SEQUENTIAL_SMKS 9L

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಪಟ್ಟಿ_ಗಣ_POSITION {
      DWORD ವಿಧಾನ_3;
      DWORD ವಿಭಜನೆ_2;
      LARGE_INTEGER ಸ್ಥಾನಾಂತರ_3;
      BOOLEAN ತಕ್ಷಣ_2;
    } ಪಟ್ಟಿ_ಗಣ_POSITION_2,*PTAPE_ಗಣ_POSITION;

#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_FIXED 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_SELECT 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_INITIATOR 0x00000004

#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_ERASE_SHORT 0x00000010
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_ERASE_LONG 0x00000020
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_ERASE_BOP_ONLY 0x00000040
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_ERASE_ತಕ್ಷಣ 0x00000080

#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_ಪಟ್ಟಿ_ಸಾಮರ್ಥ್ಯ 0x00000100
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_ಪಟ್ಟಿ_ಉಳಿದ 0x00000200
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_FIXED_ಖಂಡ 0x00000400
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_VARIABLE_ಖಂಡ 0x00000800

#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_WRITE_PROTECT 0x00001000
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_EOT_WZ_ಗಾತ್ರ 0x00002000

#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_ECC 0x00010000
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_COMPRESSION 0x00020000
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_PADDING 0x00040000
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_REPORT_SMKS 0x00080000

#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_GET_ABSOLUTE_BLK 0x00100000
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_GET_LOGICAL_BLK 0x00200000
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_ಗಣ_EOT_WZ_ಗಾತ್ರ 0x00400000

#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_EJECT_MEDIA 0x01000000
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_CLEAN_ವಿನಂತಿಗಳು 0x02000000
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_ಗಣ_CMP_BOP_ONLY 0x04000000

#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_RESERVED_ಬಿಟ್ 0x80000000

#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_ತುಂಬು_UNLOAD 0x80000001
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_TENSION 0x80000002
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_ಬೀಗ_UNLOCK 0x80000004
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_REWIND_ತಕ್ಷಣ 0x80000008

#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_ಗಣ_ಖಂಡ_ಗಾತ್ರ 0x80000010
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_ತುಂಬು_UNLD_IMMED 0x80000020
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_TENSION_IMMED 0x80000040
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_ಬೀಗ_UNLK_IMMED 0x80000080

#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_ಗಣ_ECC 0x80000100
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_ಗಣ_COMPRESSION 0x80000200
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_ಗಣ_PADDING 0x80000400
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_ಗಣ_REPORT_SMKS 0x80000800

#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_ABSOLUTE_BLK 0x80001000
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_ABS_BLK_IMMED 0x80002000
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_LOGICAL_BLK 0x80004000
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_LOG_BLK_IMMED 0x80008000

#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_ಕೊನೆ_ದ_ದತ್ತಾಂಶ 0x80010000
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_RELATIVE_BLKS 0x80020000
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_FILEMARKS 0x80040000
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_SEQUENTIAL_FMKS 0x80080000

#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_SETMARKS 0x80100000
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_SEQUENTIAL_SMKS 0x80200000
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_ಹಿಮ್ಮುಖ_POSITION 0x80400000
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_SPACE_ತಕ್ಷಣ 0x80800000

#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_WRITE_SETMARKS 0x81000000
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_WRITE_FILEMARKS 0x82000000
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_WRITE_SHORT_FMKS 0x84000000
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_WRITE_LONG_FMKS 0x88000000

#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_WRITE_MARK_IMMED 0x90000000
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_FORMAT 0xA0000000
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_FORMAT_ತಕ್ಷಣ 0xC0000000
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_DRIVE_ಮೇಲಿನ_FEATURES 0x80000000

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಪಟ್ಟಿ_GET_DRIVE_PARAMETERS {
      BOOLEAN ECC;
      BOOLEAN Compression;
      BOOLEAN ದತ್ತಾಂಶ_Padding;
      BOOLEAN ReportSetmarks;
      DWORD Default_ಖಂಡ_ಗಾತ್ರ;
      DWORD ಗರಿಷ್ಠ_ಖಂಡ_ಗಾತ್ರ;
      DWORD Minimum_ಖಂಡ_ಗಾತ್ರ;
      DWORD ಗರಿಷ್ಠ_ವಿಭಜನೆ_ಎಣಿಕೆ;
      DWORD Features_ಕೆಳಗಿನ;
      DWORD Features_ಮೇಲಿನ;
      DWORD EOTWarning_Zone_ಗಾತ್ರ;
    } ಪಟ್ಟಿ_GET_DRIVE_PARAMETERS_2,*PTAPE_GET_DRIVE_PARAMETERS;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಪಟ್ಟಿ_ಗಣ_DRIVE_PARAMETERS {
      BOOLEAN ECC;
      BOOLEAN Compression;
      BOOLEAN ದತ್ತಾಂಶ_Padding;
      BOOLEAN ReportSetmarks;
      DWORD EOTWarning_Zone_ಗಾತ್ರ;
    } ಪಟ್ಟಿ_ಗಣ_DRIVE_PARAMETERS_2,*PTAPE_ಗಣ_DRIVE_PARAMETERS;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಪಟ್ಟಿ_GET_MEDIA_PARAMETERS {
      LARGE_INTEGER ಸಾಮರ್ಥ್ಯ;
      LARGE_INTEGER ಉಳಿದ;
      DWORD ಖಂಡ_ಗಾತ್ರ;
      DWORD ವಿಭಜನೆ_ಎಣಿಕೆ;
      BOOLEAN WriteProtected;
    } ಪಟ್ಟಿ_GET_MEDIA_PARAMETERS_2,*PTAPE_GET_MEDIA_PARAMETERS;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಪಟ್ಟಿ_ಗಣ_MEDIA_PARAMETERS {
      DWORD ಖಂಡ_ಗಾತ್ರ;
    } ಪಟ್ಟಿ_ಗಣ_MEDIA_PARAMETERS_2,*PTAPE_ಗಣ_MEDIA_PARAMETERS;

#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_FIXED_PARTITIONS 0L
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_SELECT_PARTITIONS 1L
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_INITIATOR_PARTITIONS 2L

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಪಟ್ಟಿ_CREATE_ವಿಭಜನೆ {
      DWORD ವಿಧಾನ_3;
      DWORD ಎಣಿಕೆ_4;
      DWORD ಗಾತ್ರ_4;
    } ಪಟ್ಟಿ_CREATE_ವಿಭಜನೆ_2,*PTAPE_CREATE_ವಿಭಜನೆ;

#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_QUERY_DRIVE_PARAMETERS 0L
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_QUERY_MEDIA_ಸಾಮರ್ಥ್ಯ 1L
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_CHECK_FOR_DRIVE_PROBLEM 2L
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_QUERY_IO_ERROR_ದತ್ತಾಂಶ 3L
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಟ್ಟಿ_QUERY_DEVICE_ERROR_ದತ್ತಾಂಶ 4L

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಪಟ್ಟಿ_WMI_OPERATIONS {
      DWORD ವಿಧಾನ_3;
      DWORD ದತ್ತಾಂಶ_ಬಫರ್_ಗಾತ್ರ;
      PVOID ದತ್ತಾಂಶ_ಬಫರ್;
    } ಪಟ್ಟಿ_WMI_OPERATIONS_2,*PTAPE_WMI_OPERATIONS;

    ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಎಣಿಕೆ ಪಟ್ಟಿ_DRIVE_PROBLEM_TYPE {
      ಪಟ್ಟಿ_Drive_Problem_None,ಪಟ್ಟಿ_Drive_Read_Write_Warning,ಪಟ್ಟಿ_Drive_Read_Write_Error,ಪಟ್ಟಿ_Drive_Read_Warning,ಪಟ್ಟಿ_Drive_Write_Warning,ಪಟ್ಟಿ_Drive_Read_Error,ಪಟ್ಟಿ_Drive_Write_Error,ಪಟ್ಟಿ_Drive_Hardware_Error,ಪಟ್ಟಿ_Drive_Unsupported_Media,ಪಟ್ಟಿ_Drive_Scsi_Connection_Error,ಪಟ್ಟಿ_Drive_Timeto_Clean,ಪಟ್ಟಿ_Drive_Clean_Drive_Now,ಪಟ್ಟಿ_Drive_Media_Life_Expired,ಪಟ್ಟಿ_Drive_Snapped_ಪಟ್ಟಿ
    } ಪಟ್ಟಿ_DRIVE_PROBLEM_TYPE_2;

#ಆದರೆ defined(__x86_64)
    __CRT_INLINE ರಚನೆ _TEB *NtCurrentTeb(VOID) { ಹಿಂತಿರುಗಿ (ರಚನೆ _TEB *)__readgsqword(ಕ್ಷೇತ್ರ_ಸ್ಥಾನಾಂತರ(NT_TIB,Self)); }
    __CRT_INLINE PVOID GetCurrentFiber(VOID) { ಹಿಂತಿರುಗಿ(PVOID)__readgsqword(ಕ್ಷೇತ್ರ_ಸ್ಥಾನಾಂತರ(NT_TIB,Fiber_ದತ್ತಾಂಶ)); }
    __CRT_INLINE PVOID Get_Fiber_ದತ್ತಾಂಶ(VOID) {
      ಹಿಂತಿರುಗಿ *(PVOID *)GetCurrentFiber();
    }
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ(defined(_X86_) && !defined(__x86_64))
#ವ್ಯಾಖ್ಯಾನಿಸು PcTeb 0x18
    __CRT_INLINE ರಚನೆ _TEB *NtCurrentTeb(ಶೂನ್ಯ) {
      ರಚನೆ _TEB *ret;
      __asm__ ಅಸ್ಥಿರ ("movl	%%fs:0x18,%0"
	: "=r" (ret));
      ಹಿಂತಿರುಗಿ ret;
    }
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು ACTIVATION_CONTEXT_SECTION_ASSEMBLY_INFORMATION (1)
#ವ್ಯಾಖ್ಯಾನಿಸು ACTIVATION_CONTEXT_SECTION_DLL_REDIRECTION (2)
#ವ್ಯಾಖ್ಯಾನಿಸು ACTIVATION_CONTEXT_SECTION_ಕಿಟಕಿ_CLASS_REDIRECTION (3)
#ವ್ಯಾಖ್ಯಾನಿಸು ACTIVATION_CONTEXT_SECTION_COM_SERVER_REDIRECTION (4)
#ವ್ಯಾಖ್ಯಾನಿಸು ACTIVATION_CONTEXT_SECTION_COM_INTERFACE_REDIRECTION (5)
#ವ್ಯಾಖ್ಯಾನಿಸು ACTIVATION_CONTEXT_SECTION_COM_TYPE_LIBRARY_REDIRECTION (6)
#ವ್ಯಾಖ್ಯಾನಿಸು ACTIVATION_CONTEXT_SECTION_COM_PROGID_REDIRECTION (7)
#ವ್ಯಾಖ್ಯಾನಿಸು ACTIVATION_CONTEXT_SECTION_GLOBAL_OBJECT_RENAME_ಕೋಷ್ಟಕ (8)
#ವ್ಯಾಖ್ಯಾನಿಸು ACTIVATION_CONTEXT_SECTION_CLR_SURROGATES (9)
#ವ್ಯಾಖ್ಯಾನಿಸು ACTIVATION_CONTEXT_SECTION_APPLICATION_SETTINGS (10)

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
  }
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
