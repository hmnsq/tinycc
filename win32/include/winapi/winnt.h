/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#నిర్వచితం_కాకపోతే _WINNT_
#నిర్వచించు _WINNT_

#నిర్వచితమైతే __cplusplus
బాహ్య "C" {
#అయితే_ముగింపు

#అన్తర్భావ <ctype.h>
#నిర్వచించు ANYSIZE_ARRAY 1

//gr #include <specstrings.h>

#నిర్వచించు RESTRICTED_సూచిక

#నిర్వచితం_కాకపోతే __CRT_UNALIGNED
#నిర్వచించు __CRT_UNALIGNED
#అయితే_ముగింపు

#ఒకవేళ defined(__ia64__) || defined(__x86_64) || defined(__aarch64__)
#నిర్వచించు UNALIGNED __CRT_UNALIGNED
#నిర్వచితమైతే _WIN64
#నిర్వచించు UNALIGNED64 __CRT_UNALIGNED
#లేకపోతే
#నిర్వచించు UNALIGNED64
#అయితే_ముగింపు
#లేకపోతే
#నిర్వచించు UNALIGNED
#నిర్వచించు UNALIGNED64
#అయితే_ముగింపు

#ఒకవేళ !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && (defined(_X86_) && !defined(__x86_64))
#నిర్వచించు I_X86_
#అయితే_ముగింపు

#ఒకవేళ !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && defined(__x86_64)
#నిర్వచించు _AMD64_
#అయితే_ముగింపు

#ఒకవేళ !defined(I_X86_) && !(defined(_X86_) && !defined(__x86_64)) && !defined(_AMD64_) && defined(__ia64__)
#ఒకవేళ !defined(_IA64_)
#నిర్వచించు _IA64_
#అయితే_ముగింపు
#అయితే_ముగింపు


#నిర్వచితమైతే _WIN64
#నిర్వచించు MAX_NATURAL_ALIGNMENT పరిమాణం(ULONGLONG)
#నిర్వచించు జ్ఞాపకం_కేటాయింపు_ALIGNMENT 16
#లేకపోతే
#నిర్వచించు MAX_NATURAL_ALIGNMENT పరిమాణం(DWORD)
#నిర్వచించు జ్ఞాపకం_కేటాయింపు_ALIGNMENT 8
#అయితే_ముగింపు

#నిర్వచితమైతే __cplusplus
#నిర్వచించు TYPE_ALIGNMENT(t) __alignof__ (t)
#లేకపోతే
#నిర్వచించు TYPE_ALIGNMENT(t) క్షేత్రం_స్థానభ్రంశం(నిర్మాణం { అక్షరం x; t test; },test)
#అయితే_ముగింపు

#నిర్వచితమైతే _WIN64
#నిర్వచితమైతే _AMD64_
#నిర్వచించు PROBE_ALIGNMENT(_s) TYPE_ALIGNMENT(DWORD)
#లేదావేళ defined(_IA64_) || defined(_ARM64_)
#నిర్వచించు PROBE_ALIGNMENT(_s) (TYPE_ALIGNMENT(_s) > TYPE_ALIGNMENT(DWORD) ? TYPE_ALIGNMENT(_s) : TYPE_ALIGNMENT(DWORD))
#లేకపోతే
#దోషం No లక్ష్యం_2 Architecture
#అయితే_ముగింపు
#నిర్వచించు PROBE_ALIGNMENT32(_s) TYPE_ALIGNMENT(DWORD)
#లేకపోతే
#నిర్వచించు PROBE_ALIGNMENT(_s) TYPE_ALIGNMENT(DWORD)
#అయితే_ముగింపు

#నిర్వచించు C_ASSERT(e) రకనిర్వచనం అక్షరం __C_ASSERT__[(e)?1:-1]

#అన్తర్భావ <basetsd.h>

#ఒకవేళ defined(_X86_) || defined(__ia64__) || defined(__x86_64) || defined(__aarch64__)
#నిర్వచించు DECLSPEC_IMPORT __declspec(dllimport)
#లేకపోతే
#నిర్వచించు DECLSPEC_IMPORT
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే DECLSPEC_NORETURN
#నిర్వచించు DECLSPEC_NORETURN __declspec(noreturn)
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే DECLSPEC_ALIGN
#నిర్వచించు DECLSPEC_ALIGN(x) __attribute__ ((aligned(x)))
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే SYSTEM_CACHE_ALIGNMENT_కొలత
#ఒకవేళ defined(_AMD64_) || defined(I_X86_)
#నిర్వచించు SYSTEM_CACHE_ALIGNMENT_కొలత 64
#లేకపోతే
#నిర్వచించు SYSTEM_CACHE_ALIGNMENT_కొలత 128
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే DECLSPEC_CACHEALIGN
#నిర్వచించు DECLSPEC_CACHEALIGN DECLSPEC_ALIGN(SYSTEM_CACHE_ALIGNMENT_కొలత)
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే DECLSPEC_UUID
#నిర్వచించు DECLSPEC_UUID(x)
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే DECLSPEC_NOVTABLE
#నిర్వచించు DECLSPEC_NOVTABLE
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే DECLSPEC_SELECTANY
#నిర్వచించు DECLSPEC_SELECTANY __declspec(selectany)
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే NOP_FUNCTION
#నిర్వచించు NOP_FUNCTION (శూన్య)0
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే DECLSPEC_NOINLINE
#నిర్వచించు DECLSPEC_NOINLINE
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే FORCEINLINE
#నిర్వచించు FORCEINLINE స్థిర __inline__
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే DECLSPEC_DEPRECATED
#నిర్వచించు DECLSPEC_DEPRECATED __declspec(deprecated)
#నిర్వచించు DEPRECATE_SUPPORTED
#అయితే_ముగింపు

#నిర్వచించు DECLSPEC_DEPRECATED_DDK
#నిర్వచించు PRAGMA_DEPRECATED_DDK 0

  రకనిర్వచనం శూన్య *PVOID;
  రకనిర్వచనం శూన్య *PVOID64;

#నిర్వచించు NTAPI __stdcall
#నిర్వచించు NTSYSAPI DECLSPEC_IMPORT
#నిర్వచించు NTSYSCALLAPI DECLSPEC_IMPORT

#నిర్వచితం_కాకపోతే VOID
#నిర్వచించు VOID శూన్య
  రకనిర్వచనం అక్షరం CHAR;
  రకనిర్వచనం పొట్టి SHORT;
  రకనిర్వచనం దీర్ఘ LONG;
#అయితే_ముగింపు

  రకనిర్వచనం wchar_t WCHAR;
  రకనిర్వచనం WCHAR *PWCHAR,*LPWCH,*PWCH;
  రకనిర్వచనం CONST WCHAR *LPCWCH,*PCWCH;
  రకనిర్వచనం WCHAR *NWPSTR,*LPWSTR,*PWSTR;
  రకనిర్వచనం PWSTR *PZPWSTR;
  రకనిర్వచనం CONST PWSTR *PCZPWSTR;
  రకనిర్వచనం WCHAR UNALIGNED *LPUWSTR,*PUWSTR;
  రకనిర్వచనం CONST WCHAR *LPCWSTR,*PCWSTR;
  రకనిర్వచనం PCWSTR *PZPCWSTR;
  రకనిర్వచనం CONST WCHAR UNALIGNED *LPCUWSTR,*PCUWSTR;
  రకనిర్వచనం CHAR *PCHAR,*LPCH,*PCH;
  రకనిర్వచనం CONST CHAR *LPCCH,*PCCH;
  రకనిర్వచనం CHAR *NPSTR,*LPSTR,*PSTR;
  రకనిర్వచనం PSTR *PZPSTR;
  రకనిర్వచనం CONST PSTR *PCZPSTR;
  రకనిర్వచనం CONST CHAR *LPCSTR,*PCSTR;
  రకనిర్వచనం PCSTR *PZPCSTR;

#నిర్వచితమైతే UNICODE
#నిర్వచితం_కాకపోతే _TCHAR_DEFINED
#నిర్వచించు _TCHAR_DEFINED
  రకనిర్వచనం WCHAR TCHAR,*PTCHAR;
  రకనిర్వచనం WCHAR TBYTE ,*PTBYTE;
#అయితే_ముగింపు

  రకనిర్వచనం LPWSTR LPTCH,PTCH;
  రకనిర్వచనం LPWSTR PTSTR,LPTSTR;
  రకనిర్వచనం LPCWSTR PCTSTR,LPCTSTR;
  రకనిర్వచనం LPUWSTR PUTSTR,LPUTSTR;
  రకనిర్వచనం LPCUWSTR PCUTSTR,LPCUTSTR;
  రకనిర్వచనం LPWSTR LP;
#నిర్వచించు __TEXT(quote) L##quote
#లేకపోతే
#నిర్వచితం_కాకపోతే _TCHAR_DEFINED
#నిర్వచించు _TCHAR_DEFINED
  రకనిర్వచనం అక్షరం TCHAR,*PTCHAR;
  రకనిర్వచనం గుర్తులేని అక్షరం TBYTE ,*PTBYTE;
#అయితే_ముగింపు

  రకనిర్వచనం LPSTR LPTCH,PTCH;
  రకనిర్వచనం LPSTR PTSTR,LPTSTR,PUTSTR,LPUTSTR;
  రకనిర్వచనం LPCSTR PCTSTR,LPCTSTR,PCUTSTR,LPCUTSTR;
#నిర్వచించు __TEXT(quote) quote
#అయితే_ముగింపు

#నిర్వచించు పాఠ్యం_3(quote) __TEXT(quote)

  రకనిర్వచనం SHORT *PSHORT;
  రకనిర్వచనం LONG *PLONG;

  రకనిర్వచనం శూన్య *HANDLE;
#నిర్వచించు DECLARE_HANDLE(name) నిర్మాణం name##__ { పూర్ణాంకం వాడని; }; రకనిర్వచనం నిర్మాణం name##__ *name
  రకనిర్వచనం HANDLE *PHANDLE;

  రకనిర్వచనం BYTE FCHAR;
  రకనిర్వచనం మాట_3 FSHORT;
  రకనిర్వచనం DWORD FLONG;

#నిర్వచితం_కాకపోతే _HRESULT_DEFINED
#నిర్వచించు _HRESULT_DEFINED
  రకనిర్వచనం LONG HRESULT;
#అయితే_ముగింపు

#నిర్వచితమైతే __cplusplus
#నిర్వచించు EXTERN_C బాహ్య "C"
#లేకపోతే
#నిర్వచించు EXTERN_C బాహ్య
#అయితే_ముగింపు

#నిర్వచించు STDMETHODCALLTYPE WINAPI
#నిర్వచించు STDMETHODVCALLTYPE __cdecl
#నిర్వచించు STDAPICALLTYPE WINAPI
#నిర్వచించు STDAPIVCALLTYPE __cdecl
#నిర్వచించు STDAPI EXTERN_C HRESULT WINAPI
#నిర్వచించు STDAPI_(type) EXTERN_C type WINAPI
#నిర్వచించు STDMETHODIMP HRESULT WINAPI
#నిర్వచించు STDMETHODIMP_(type) type WINAPI
#నిర్వచించు STDAPIV EXTERN_C HRESULT STDAPIVCALLTYPE
#నిర్వచించు STDAPIV_(type) EXTERN_C type STDAPIVCALLTYPE
#నిర్వచించు STDMETHODIMPV HRESULT STDMETHODVCALLTYPE
#నిర్వచించు STDMETHODIMPV_(type) type STDMETHODVCALLTYPE

  రకనిర్వచనం అక్షరం CCHAR;
#నిర్వచితం_కాకపోతే _LCID_DEFINED
#నిర్వచించు _LCID_DEFINED
రకనిర్వచనం DWORD LCID;
#అయితే_ముగింపు
  రకనిర్వచనం PDWORD PLCID;
#నిర్వచితం_కాకపోతే _LANGID_DEFINED
#నిర్వచించు _LANGID_DEFINED
  రకనిర్వచనం మాట_3 LANGID;
#అయితే_ముగింపు
#నిర్వచించు APPLICATION_ERROR_ముసుగు 0x20000000
#నిర్వచించు ERROR_SEVERITY_SUCCESS 0x00000000
#నిర్వచించు ERROR_SEVERITY_INFORMATIONAL 0x40000000
#నిర్వచించు ERROR_SEVERITY_WARNING 0x80000000
#నిర్వచించు ERROR_SEVERITY_ERROR 0xC0000000

#నిర్వచితమైతే __ia64__
  __declspec(align(16))
#అయితే_ముగింపు
    రకనిర్వచనం నిర్మాణం _FLOAT128 {
      __int64 దిగువ_Part;
      __int64 ఎగువ_Part;
  } FLOAT128;

  రకనిర్వచనం FLOAT128 *PFLOAT128;

#నిర్వచించు _ULONGLONG_
#ఒకవేళ((!(defined(_X86_) && !defined(__x86_64)) || (defined(INTEGRAL_MAX_బిట్లు) && INTEGRAL_MAX_బిట్లు >= 64)))
  రకనిర్వచనం __int64 LONGLONG;
  రకనిర్వచనం గుర్తులేని __int64 ULONGLONG;

#నిర్వచించు MAXLONGLONG (0x7fffffffffffffff)
#లేకపోతే

  రకనిర్వచనం ద్విగుణ LONGLONG;
  రకనిర్వచనం ద్విగుణ ULONGLONG;
#అయితే_ముగింపు

  రకనిర్వచనం LONGLONG *PLONGLONG;
  రకనిర్వచనం ULONGLONG *PULONGLONG;

  రకనిర్వచనం LONGLONG USN;

  రకనిర్వచనం సంఘం _LARGE_INTEGER {
    నిర్మాణం {
      DWORD దిగువ_Part;
      LONG ఎగువ_Part;
    };
    నిర్మాణం {
      DWORD దిగువ_Part;
      LONG ఎగువ_Part;
    } u;
    LONGLONG QuadPart;
  } LARGE_INTEGER;

  రకనిర్వచనం LARGE_INTEGER *PLARGE_INTEGER;

  రకనిర్వచనం సంఘం _ULARGE_INTEGER {
    నిర్మాణం {
      DWORD దిగువ_Part;
      DWORD ఎగువ_Part;
    };
    నిర్మాణం {
      DWORD దిగువ_Part;
      DWORD ఎగువ_Part;
    } u;
    ULONGLONG QuadPart;
  } ULARGE_INTEGER;

  రకనిర్వచనం ULARGE_INTEGER *PULARGE_INTEGER;

  రకనిర్వచనం నిర్మాణం _LUID {
    DWORD దిగువ_Part;
    LONG ఎగువ_Part;
  } LUID,*PLUID;

#నిర్వచించు _DWORDLONG_
  రకనిర్వచనం ULONGLONG DWORDLONG;
  రకనిర్వచనం DWORDLONG *PDWORDLONG;

#నిర్వచితమైతే RC_INVOKED
#నిర్వచించు Int32x32To64(a,b) ((LONGLONG)((LONG)(a)) *(LONGLONG)((LONG)(b)))
#నిర్వచించు UInt32x32To64(a,b) ((ULONGLONG)((DWORD)(a)) *(ULONGLONG)((DWORD)(b)))
#నిర్వచించు Int64ShrlMod32(a,b) ((ULONGLONG)(a) >> (b))
#లేదావేళ (defined(_X86_) && !defined(__x86_64))
#నిర్వచించు Int32x32To64(a,b) (LONGLONG)((LONGLONG)(LONG)(a) *(LONG)(b))
#నిర్వచించు UInt32x32To64(a,b) (ULONGLONG)((ULONGLONG)(DWORD)(a) *(DWORD)(b))
#నిర్వచించు Int64ShrlMod32(a,b) ((DWORDLONG)(a)>>(b))
#లేదావేళ defined(__ia64__) || defined(__x86_64) || defined(__aarch64__)
#నిర్వచించు Int32x32To64(a,b) ((LONGLONG)((LONG)(a)) *(LONGLONG)((LONG)(b)))
#నిర్వచించు UInt32x32To64(a,b) ((ULONGLONG)((DWORD)(a)) *(ULONGLONG)((DWORD)(b)))
#నిర్వచించు Int64ShrlMod32(a,b) ((ULONGLONG)(a) >> (b))
#లేకపోతే
#దోషం Must define a లక్ష్యం architecture.
#అయితే_ముగింపు

#నిర్వచించు Int64ShraMod32(a,b) ((LONGLONG)(a) >> (b))
#నిర్వచించు Int64ShllMod32(a,b) ((ULONGLONG)(a) << (b))

#నిర్వచితమైతే __cplusplus
  బాహ్య "C" {
#అయితే_ముగింపు

#నిర్వచితమైతే __x86_64

#నిర్వచించు RotateLeft8 _rotl8
#నిర్వచించు RotateLeft16 _rotl16
#నిర్వచించు RotateRight8 _rotr8
#నిర్వచించు RotateRight16 _rotr16

    గుర్తులేని అక్షరం __cdecl _rotl8(గుర్తులేని అక్షరం విలువ_3,గుర్తులేని అక్షరం జరుపు_3);
    గుర్తులేని పొట్టి __cdecl _rotl16(గుర్తులేని పొట్టి విలువ_3,గుర్తులేని అక్షరం జరుపు_3);
    గుర్తులేని అక్షరం __cdecl _rotr8(గుర్తులేని అక్షరం విలువ_3,గుర్తులేని అక్షరం జరుపు_3);
    గుర్తులేని పొట్టి __cdecl _rotr16(గుర్తులేని పొట్టి విలువ_3,గుర్తులేని అక్షరం జరుపు_3);
#అయితే_ముగింపు

#నిర్వచించు RotateLeft32 _rotl
#నిర్వచించు RotateLeft64 _rotl64
#నిర్వచించు RotateRight32 _rotr
#నిర్వచించు RotateRight64 _rotr64

    గుర్తులేని పూర్ణాంకం __cdecl _rotl(గుర్తులేని పూర్ణాంకం విలువ_3,పూర్ణాంకం జరుపు_3);
    గుర్తులేని __int64 __cdecl _rotl64(గుర్తులేని __int64 విలువ_3,పూర్ణాంకం జరుపు_3);
    గుర్తులేని పూర్ణాంకం __cdecl _rotr(గుర్తులేని పూర్ణాంకం విలువ_3,పూర్ణాంకం జరుపు_3);
    గుర్తులేని __int64 __cdecl _rotr64(గుర్తులేని __int64 విలువ_3,పూర్ణాంకం జరుపు_3);
#నిర్వచితమైతే __cplusplus
  }
#అయితే_ముగింపు

#నిర్వచించు ANSI_NULL ((CHAR)0)
#నిర్వచించు UNICODE_NULL ((WCHAR)0)
#నిర్వచించు UNICODE_STRING_MAX_బైట్లు ((మాట_3) 65534)
#నిర్వచించు UNICODE_STRING_MAX_CHARS (32767)

#నిర్వచితం_కాకపోతే _BOOLEAN_
#నిర్వచించు _BOOLEAN_
  రకనిర్వచనం BYTE BOOLEAN;
#అయితే_ముగింపు
  రకనిర్వచనం BOOLEAN *PBOOLEAN;

  రకనిర్వచనం నిర్మాణం LIST_నమోదు {
    నిర్మాణం LIST_నమోదు *Flink;
    నిర్మాణం LIST_నమోదు *Blink;
  } LIST_నమోదు_2,*PLIST_నమోదు,*RESTRICTED_సూచిక PRLIST_నమోదు;

  రకనిర్వచనం నిర్మాణం SINGLE_LIST_నమోదు {
    నిర్మాణం SINGLE_LIST_నమోదు *తదుపరి_2;
  } SINGLE_LIST_నమోదు_2,*PSINGLE_LIST_నమోదు;

  రకనిర్వచనం నిర్మాణం LIST_ENTRY32 {
    DWORD Flink;
    DWORD Blink;
  } LIST_ENTRY32;
  రకనిర్వచనం LIST_ENTRY32 *PLIST_ENTRY32;

  రకనిర్వచనం నిర్మాణం LIST_ENTRY64 {
    ULONGLONG Flink;
    ULONGLONG Blink;
  } LIST_ENTRY64;
  రకనిర్వచనం LIST_ENTRY64 *PLIST_ENTRY64;

#అన్తర్భావ <guiddef.h>

#నిర్వచితం_కాకపోతే __OBJECTID_DEFINED
#నిర్వచించు __OBJECTID_DEFINED
  రకనిర్వచనం నిర్మాణం _OBJECTID {
    GUID Lineage;
    DWORD Uniquifier;
  } OBJECTID;
#అయితే_ముగింపు

#నిర్వచించు MINCHAR 0x80
#నిర్వచించు MAXCHAR 0x7f
#నిర్వచించు MINSHORT 0x8000
#నిర్వచించు MAXSHORT 0x7fff
#నిర్వచించు MINLONG 0x80000000
#నిర్వచించు MAXLONG 0x7fffffff
#నిర్వచించు MAXBYTE 0xff
#నిర్వచించు MAXWORD 0xffff
#నిర్వచించు MAXDWORD 0xffffffff

#నిర్వచించు క్షేత్రం_స్థానభ్రంశం(type,క్షేత్రం) ((LONG)(LONG_PTR)&(((type *)0)->క్షేత్రం))
#నిర్వచించు RTL_క్షేత్రం_కొలత(type,క్షేత్రం) (పరిమాణం(((type *)0)->క్షేత్రం))
#నిర్వచించు RTL_SIZEOF_THROUGH_క్షేత్రం(type,క్షేత్రం) (క్షేత్రం_స్థానభ్రంశం(type,క్షేత్రం) + RTL_క్షేత్రం_కొలత(type,క్షేత్రం))
#నిర్వచించు RTL_కలిగియుంది_క్షేత్రం(Struct,కొలత_3,క్షేత్రం_2) ((((PCHAR)(&(Struct)->క్షేత్రం_2)) + పరిమాణం((Struct)->క్షేత్రం_2)) <= (((PCHAR)(Struct))+(కొలత_3)))
#నిర్వచించు RTL_సంఖ్య_యొక్క_V1(A) (పరిమాణం(A)/పరిమాణం((A)[0]))
#నిర్వచించు RTL_సంఖ్య_యొక్క_V2(A) RTL_సంఖ్య_యొక్క_V1(A)

#నిర్వచితమైతే ENABLE_RTL_సంఖ్య_యొక్క_V2
#నిర్వచించు RTL_సంఖ్య_యొక్క(A) RTL_సంఖ్య_యొక్క_V2(A)
#లేకపోతే
#నిర్వచించు RTL_సంఖ్య_యొక్క(A) RTL_సంఖ్య_యొక్క_V1(A)
#అయితే_ముగింపు

#నిర్వచించు ARRAYSIZE(A) RTL_సంఖ్య_యొక్క_V2(A)
#నిర్వచించు _ARRAYSIZE(A) RTL_సంఖ్య_యొక్క_V1(A)

#నిర్వచించు RTL_క్షేత్రం_TYPE(type,క్షేత్రం) (((type*)0)->క్షేత్రం)
#నిర్వచించు RTL_సంఖ్య_యొక్క_క్షేత్రం(type,క్షేత్రం) (RTL_సంఖ్య_యొక్క(RTL_క్షేత్రం_TYPE(type,క్షేత్రం)))
#నిర్వచించు RTL_PADDING_BETWEEN_FIELDS(T,F1,F2) ((క్షేత్రం_స్థానభ్రంశం(T,F2) > క్షేత్రం_స్థానభ్రంశం(T,F1)) ? (క్షేత్రం_స్థానభ్రంశం(T,F2) - క్షేత్రం_స్థానభ్రంశం(T,F1) - RTL_క్షేత్రం_కొలత(T,F1)) : (క్షేత్రం_స్థానభ్రంశం(T,F1) - క్షేత్రం_స్థానభ్రంశం(T,F2) - RTL_క్షేత్రం_కొలత(T,F2)))

#నిర్వచితమైతే __cplusplus
#నిర్వచించు RTL_CONST_CAST(type) const_cast<type>
#లేకపోతే
#నిర్వచించు RTL_CONST_CAST(type) (type)
#అయితే_ముగింపు

#నిర్వచించు RTL_బిట్లు_యొక్క(కొలత_యొక్క_Arg) (పరిమాణం(కొలత_యొక్క_Arg) *8)
#నిర్వచించు RTL_బిట్లు_యొక్క_క్షేత్రం(type,క్షేత్రం) (RTL_బిట్లు_యొక్క(RTL_క్షేత్రం_TYPE(type,క్షేత్రం)))
#నిర్వచించు CONTAINING_రికార్డు(చిరునామా,type,క్షేత్రం) ((type *)((PCHAR)(చిరునామా) - (ULONG_PTR)(&((type *)0)->క్షేత్రం)))

#నిర్వచించు VER_SERVER_NT 0x80000000
#నిర్వచించు VER_WORKSTATION_NT 0x40000000
#నిర్వచించు VER_SUITE_SMALLBUSINESS 0x00000001
#నిర్వచించు VER_SUITE_ENTERPRISE 0x00000002
#నిర్వచించు VER_SUITE_BACKOFFICE 0x00000004
#నిర్వచించు VER_SUITE_COMMUNICATIONS 0x00000008
#నిర్వచించు VER_SUITE_TERMINAL 0x00000010
#నిర్వచించు VER_SUITE_SMALLBUSINESS_RESTRICTED 0x00000020
#నిర్వచించు VER_SUITE_EMBEDDEDNT 0x00000040
#నిర్వచించు VER_SUITE_DATACENTER 0x00000080
#నిర్వచించు VER_SUITE_SINGLEUSERTS 0x00000100
#నిర్వచించు VER_SUITE_PERSONAL 0x00000200
#నిర్వచించు VER_SUITE_BLADE 0x00000400
#నిర్వచించు VER_SUITE_EMBEDDED_RESTRICTED 0x00000800
#నిర్వచించు VER_SUITE_SECURITY_APPLIANCE 0x00001000
#నిర్వచించు VER_SUITE_STORAGE_SERVER 0x00002000
#నిర్వచించు VER_SUITE_COMPUTE_SERVER 0x00004000

#నిర్వచించు లబ్ధం_UNDEFINED                       0x0

#నిర్వచించు లబ్ధం_ULTIMATE                        0x1
#నిర్వచించు లబ్ధం_HOME_BASIC                      0x2
#నిర్వచించు లబ్ధం_HOME_PREMIUM                    0x3
#నిర్వచించు లబ్ధం_ENTERPRISE                      0x4
#నిర్వచించు లబ్ధం_HOME_BASIC_N                    0x5
#నిర్వచించు లబ్ధం_BUSINESS                        0x6
#నిర్వచించు లబ్ధం_STANDARD_SERVER                 0x7
#నిర్వచించు లబ్ధం_DATACENTER_SERVER               0x8
#నిర్వచించు లబ్ధం_SMALLBUSINESS_SERVER            0x9
#నిర్వచించు లబ్ధం_ENTERPRISE_SERVER               0xa
#నిర్వచించు లబ్ధం_STARTER                         0xb
#నిర్వచించు లబ్ధం_DATACENTER_SERVER_CORE          0xc
#నిర్వచించు లబ్ధం_STANDARD_SERVER_CORE            0xd
#నిర్వచించు లబ్ధం_ENTERPRISE_SERVER_CORE          0xe
#నిర్వచించు లబ్ధం_ENTERPRISE_SERVER_IA64          0xf
#నిర్వచించు లబ్ధం_BUSINESS_N                      0x10
#నిర్వచించు లబ్ధం_WEB_SERVER                      0x11
#నిర్వచించు లబ్ధం_CLUSTER_SERVER                  0x12
#నిర్వచించు లబ్ధం_HOME_SERVER                     0x13
#నిర్వచించు లబ్ధం_STORAGE_EXPRESS_SERVER          0x14
#నిర్వచించు లబ్ధం_STORAGE_STANDARD_SERVER         0x15
#నిర్వచించు లబ్ధం_STORAGE_WORKGROUP_SERVER        0x16
#నిర్వచించు లబ్ధం_STORAGE_ENTERPRISE_SERVER       0x17
#నిర్వచించు లబ్ధం_SERVER_FOR_SMALLBUSINESS        0x18
#నిర్వచించు లబ్ధం_SMALLBUSINESS_SERVER_PREMIUM    0x19

#నిర్వచించు లబ్ధం_UNLICENSED                      0xabcdabcd

#నిర్వచించు LANG_NEUTRAL 0x00
#నిర్వచించు LANG_INVARIANT 0x7f

#నిర్వచించు LANG_AFRIKAANS 0x36
#నిర్వచించు LANG_ALBANIAN 0x1c
#నిర్వచించు LANG_ALSATIAN 0x84
#నిర్వచించు LANG_AMHARIC 0x5e
#నిర్వచించు LANG_ARABIC 0x01
#నిర్వచించు LANG_ARMENIAN 0x2b
#నిర్వచించు LANG_ASSAMESE 0x4d
#నిర్వచించు LANG_AZERI 0x2c
#నిర్వచించు LANG_BASHKIR 0x6d
#నిర్వచించు LANG_BASQUE 0x2d
#నిర్వచించు LANG_BELARUSIAN 0x23
#నిర్వచించు LANG_BENGALI 0x45
#నిర్వచించు LANG_BRETON 0x7e
#నిర్వచించు LANG_BOSNIAN 0x1a
#నిర్వచించు LANG_BOSNIAN_NEUTRAL 0x781a
#నిర్వచించు LANG_BULGARIAN 0x02
#నిర్వచించు LANG_కాటలాన్ 0x03
#నిర్వచించు LANG_CHINESE 0x04
#నిర్వచించు LANG_CHINESE_SIMPLIFIED 0x04
#నిర్వచించు LANG_CHINESE_TRADITIONAL 0x7c04
#నిర్వచించు LANG_CORSICAN 0x83
#నిర్వచించు LANG_CROATIAN 0x1a
#నిర్వచించు LANG_CZECH 0x05
#నిర్వచించు LANG_DANISH 0x06
#నిర్వచించు LANG_DARI 0x8c
#నిర్వచించు LANG_DIVEHI 0x65
#నిర్వచించు LANG_DUTCH 0x13
#నిర్వచించు LANG_ENGLISH 0x09
#నిర్వచించు LANG_ESTONIAN 0x25
#నిర్వచించు LANG_FAEROESE 0x38
#నిర్వచించు LANG_FARSI 0x29
#నిర్వచించు LANG_FILIPINO 0x64
#నిర్వచించు LANG_FINNISH 0x0b
#నిర్వచించు LANG_FRENCH 0x0c
#నిర్వచించు LANG_FRISIAN 0x62
#నిర్వచించు LANG_GALICIAN 0x56
#నిర్వచించు LANG_GEORGIAN 0x37
#నిర్వచించు LANG_GERMAN 0x07
#నిర్వచించు LANG_GREEK 0x08
#నిర్వచించు LANG_GREENLANDIC 0x6f
#నిర్వచించు LANG_GUJARATI 0x47
#నిర్వచించు LANG_HAUSA 0x68
#నిర్వచించు LANG_HEBREW 0x0d
#నిర్వచించు LANG_HINDI 0x39
#నిర్వచించు LANG_HUNGARIAN 0x0e
#నిర్వచించు LANG_ICELANDIC 0x0f
#నిర్వచించు LANG_IGBO 0x70
#నిర్వచించు LANG_INDONESIAN 0x21
#నిర్వచించు LANG_INUKTITUT 0x5d
#నిర్వచించు LANG_IRISH 0x3c
#నిర్వచించు LANG_ITALIAN 0x10
#నిర్వచించు LANG_JAPANESE 0x11
#నిర్వచించు LANG_KANNADA 0x4b
#నిర్వచించు LANG_KASHMIRI 0x60
#నిర్వచించు LANG_KAZAK 0x3f
#నిర్వచించు LANG_KHMER 0x53
#నిర్వచించు LANG_KICHE 0x86
#నిర్వచించు LANG_KINYARWANDA 0x87
#నిర్వచించు LANG_KONKANI 0x57
#నిర్వచించు LANG_KOREAN 0x12
#నిర్వచించు LANG_KYRGYZ 0x40
#నిర్వచించు LANG_LAO 0x54
#నిర్వచించు LANG_LATVIAN 0x26
#నిర్వచించు LANG_LITHUANIAN 0x27
#నిర్వచించు LANG_క్రింది_SORBIAN 0x2e
#నిర్వచించు LANG_LUXEMBOURGISH 0x6e
#నిర్వచించు LANG_MACEDONIAN 0x2f
#నిర్వచించు LANG_MALAY 0x3e
#నిర్వచించు LANG_MALAYALAM 0x4c
#నిర్వచించు LANG_MALTESE 0x3a
#నిర్వచించు LANG_MANIPURI 0x58
#నిర్వచించు LANG_MAORI 0x81
#నిర్వచించు LANG_MAPUDUNGUN 0x7a
#నిర్వచించు LANG_MARATHI 0x4e
#నిర్వచించు LANG_MOHAWK 0x7c
#నిర్వచించు LANG_MONGOLIAN 0x50
#నిర్వచించు LANG_NEPALI 0x61
#నిర్వచించు LANG_NORWEGIAN 0x14
#నిర్వచించు LANG_OCCITAN 0x82
#నిర్వచించు LANG_ORIYA 0x48
#నిర్వచించు LANG_PASHTO 0x63
#నిర్వచించు LANG_PERSIAN 0x29
#నిర్వచించు LANG_POLISH 0x15
#నిర్వచించు LANG_PORTUGUESE 0x16
#నిర్వచించు LANG_PUNJABI 0x46
#నిర్వచించు LANG_QUECHUA 0x6b
#నిర్వచించు LANG_ROMANIAN 0x18
#నిర్వచించు LANG_RUSSIAN 0x19
#నిర్వచించు LANG_SAMI 0x3b
#నిర్వచించు LANG_ROMANSH 0x17
#నిర్వచించు LANG_SANSKRIT 0x4f
#నిర్వచించు LANG_SERBIAN 0x1a
#నిర్వచించు LANG_SERBIAN_NEUTRAL 0x7c1a
#నిర్వచించు LANG_SINDHI 0x59
#నిర్వచించు LANG_SINHALESE 0x5b
#నిర్వచించు LANG_SLOVAK 0x1b
#నిర్వచించు LANG_SLOVENIAN 0x24
#నిర్వచించు LANG_SOTHO 0x6c
#నిర్వచించు LANG_SPANISH 0x0a
#నిర్వచించు LANG_SWAHILI 0x41
#నిర్వచించు LANG_SWEDISH 0x1d
#నిర్వచించు LANG_SYRIAC 0x5a
#నిర్వచించు LANG_TAJIK 0x28
#నిర్వచించు LANG_TAMAZIGHT 0x5f
#నిర్వచించు LANG_TAMIL 0x49
#నిర్వచించు LANG_TATAR 0x44
#నిర్వచించు LANG_TELUGU 0x4a
#నిర్వచించు LANG_THAI 0x1e
#నిర్వచించు LANG_TIBETAN 0x51
#నిర్వచించు LANG_TIGRIGNA 0x73
#నిర్వచించు LANG_TSWANA 0x32
#నిర్వచించు LANG_TURKISH 0x1f
#నిర్వచించు LANG_TURKMEN 0x42
#నిర్వచించు LANG_UIGHUR 0x80
#నిర్వచించు LANG_UKRAINIAN 0x22
#నిర్వచించు LANG_పై_SORBIAN 0x2e
#నిర్వచించు LANG_URDU 0x20
#నిర్వచించు LANG_UZBEK 0x43
#నిర్వచించు LANG_VIETNAMESE 0x2a
#నిర్వచించు LANG_WELSH 0x52
#నిర్వచించు LANG_WOLOF 0x88
#నిర్వచించు LANG_XHOSA 0x34
#నిర్వచించు LANG_YAKUT 0x85
#నిర్వచించు LANG_YI 0x78
#నిర్వచించు LANG_YORUBA 0x6a
#నిర్వచించు LANG_ZULU 0x35

#నిర్వచించు SUBLANG_NEUTRAL 0x0
#నిర్వచించు SUBLANG_DEFAULT 0x1
#నిర్వచించు SUBLANG_SYS_DEFAULT 0x2
#నిర్వచించు SUBLANG_CUSTOM_DEFAULT 0x3
#నిర్వచించు SUBLANG_CUSTOM_UNSPECIFIED 0x4
#నిర్వచించు SUBLANG_UI_CUSTOM_DEFAULT 0x5

#నిర్వచించు SUBLANG_ARABIC_SAUDI_ARABIA 0x01
#నిర్వచించు SUBLANG_ARABIC_IRAQ 0x02
#నిర్వచించు SUBLANG_ARABIC_EGYPT 0x03
#నిర్వచించు SUBLANG_ARABIC_LIBYA 0x04
#నిర్వచించు SUBLANG_ARABIC_ALGERIA 0x05
#నిర్వచించు SUBLANG_ARABIC_MOROCCO 0x06
#నిర్వచించు SUBLANG_ARABIC_TUNISIA 0x07
#నిర్వచించు SUBLANG_ARABIC_OMAN 0x08
#నిర్వచించు SUBLANG_ARABIC_YEMEN 0x09
#నిర్వచించు SUBLANG_ARABIC_SYRIA 0x0a
#నిర్వచించు SUBLANG_ARABIC_JORDAN 0x0b
#నిర్వచించు SUBLANG_ARABIC_LEBANON 0x0c
#నిర్వచించు SUBLANG_ARABIC_KUWAIT 0x0d
#నిర్వచించు SUBLANG_ARABIC_UAE 0x0e
#నిర్వచించు SUBLANG_ARABIC_BAHRAIN 0x0f
#నిర్వచించు SUBLANG_ARABIC_QATAR 0x10
#నిర్వచించు SUBLANG_AZERI_LATIN 0x01
#నిర్వచించు SUBLANG_AZERI_CYRILLIC 0x02
#నిర్వచించు SUBLANG_CHINESE_TRADITIONAL 0x01
#నిర్వచించు SUBLANG_CHINESE_SIMPLIFIED 0x02
#నిర్వచించు SUBLANG_CHINESE_HONGKONG 0x03
#నిర్వచించు SUBLANG_CHINESE_SINGAPORE 0x04
#నిర్వచించు SUBLANG_CHINESE_MACAU 0x05
#నిర్వచించు SUBLANG_DUTCH 0x01
#నిర్వచించు SUBLANG_DUTCH_BELGIAN 0x02
#నిర్వచించు SUBLANG_ENGLISH_US 0x01
#నిర్వచించు SUBLANG_ENGLISH_UK 0x02
#నిర్వచించు SUBLANG_ENGLISH_AUS 0x03
#నిర్వచించు SUBLANG_ENGLISH_CAN 0x04
#నిర్వచించు SUBLANG_ENGLISH_NZ 0x05
#నిర్వచించు SUBLANG_ENGLISH_EIRE 0x06
#నిర్వచించు SUBLANG_ENGLISH_SOUTH_AFRICA 0x07
#నిర్వచించు SUBLANG_ENGLISH_JAMAICA 0x08
#నిర్వచించు SUBLANG_ENGLISH_CARIBBEAN 0x09
#నిర్వచించు SUBLANG_ENGLISH_BELIZE 0x0a
#నిర్వచించు SUBLANG_ENGLISH_TRINIDAD 0x0b
#నిర్వచించు SUBLANG_ENGLISH_ZIMBABWE 0x0c
#నిర్వచించు SUBLANG_ENGLISH_PHILIPPINES 0x0d
#నిర్వచించు SUBLANG_FRENCH 0x01
#నిర్వచించు SUBLANG_FRENCH_BELGIAN 0x02
#నిర్వచించు SUBLANG_FRENCH_CANADIAN 0x03
#నిర్వచించు SUBLANG_FRENCH_SWISS 0x04
#నిర్వచించు SUBLANG_FRENCH_LUXEMBOURG 0x05
#నిర్వచించు SUBLANG_FRENCH_MONACO 0x06
#నిర్వచించు SUBLANG_GERMAN 0x01
#నిర్వచించు SUBLANG_GERMAN_SWISS 0x02
#నిర్వచించు SUBLANG_GERMAN_AUSTRIAN 0x03
#నిర్వచించు SUBLANG_GERMAN_LUXEMBOURG 0x04
#నిర్వచించు SUBLANG_GERMAN_LIECHTENSTEIN 0x05
#నిర్వచించు SUBLANG_ITALIAN 0x01
#నిర్వచించు SUBLANG_ITALIAN_SWISS 0x02
#నిర్వచించు SUBLANG_KASHMIRI_SASIA 0x02
#నిర్వచించు SUBLANG_KASHMIRI_INDIA 0x02
#నిర్వచించు SUBLANG_KOREAN 0x01
#నిర్వచించు SUBLANG_LITHUANIAN 0x01
#నిర్వచించు SUBLANG_MALAY_MALAYSIA 0x01
#నిర్వచించు SUBLANG_MALAY_BRUNEI_DARUSSALAM 0x02
#నిర్వచించు SUBLANG_NEPALI_INDIA 0x02
#నిర్వచించు SUBLANG_NORWEGIAN_BOKMAL 0x01
#నిర్వచించు SUBLANG_NORWEGIAN_NYNORSK 0x02
#నిర్వచించు SUBLANG_PORTUGUESE 0x02
#నిర్వచించు SUBLANG_PORTUGUESE_BRAZILIAN 0x01
#నిర్వచించు SUBLANG_SERBIAN_LATIN 0x02
#నిర్వచించు SUBLANG_SERBIAN_CYRILLIC 0x03
#నిర్వచించు SUBLANG_SPANISH 0x01
#నిర్వచించు SUBLANG_SPANISH_MEXICAN 0x02
#నిర్వచించు SUBLANG_SPANISH_MODERN 0x03
#నిర్వచించు SUBLANG_SPANISH_GUATEMALA 0x04
#నిర్వచించు SUBLANG_SPANISH_COSTA_RICA 0x05
#నిర్వచించు SUBLANG_SPANISH_PANAMA 0x06
#నిర్వచించు SUBLANG_SPANISH_DOMINICAN_REPUBLIC 0x07
#నిర్వచించు SUBLANG_SPANISH_VENEZUELA 0x08
#నిర్వచించు SUBLANG_SPANISH_COLOMBIA 0x09
#నిర్వచించు SUBLANG_SPANISH_PERU 0x0a
#నిర్వచించు SUBLANG_SPANISH_ARGENTINA 0x0b
#నిర్వచించు SUBLANG_SPANISH_ECUADOR 0x0c
#నిర్వచించు SUBLANG_SPANISH_CHILE 0x0d
#నిర్వచించు SUBLANG_SPANISH_URUGUAY 0x0e
#నిర్వచించు SUBLANG_SPANISH_PARAGUAY 0x0f
#నిర్వచించు SUBLANG_SPANISH_BOLIVIA 0x10
#నిర్వచించు SUBLANG_SPANISH_EL_SALVADOR 0x11
#నిర్వచించు SUBLANG_SPANISH_HONDURAS 0x12
#నిర్వచించు SUBLANG_SPANISH_NICARAGUA 0x13
#నిర్వచించు SUBLANG_SPANISH_PUERTO_RICO 0x14
#నిర్వచించు SUBLANG_SWEDISH 0x01
#నిర్వచించు SUBLANG_SWEDISH_FINLAND 0x02
#నిర్వచించు SUBLANG_URDU_PAKISTAN 0x01
#నిర్వచించు SUBLANG_URDU_INDIA 0x02
#నిర్వచించు SUBLANG_UZBEK_LATIN 0x01
#నిర్వచించు SUBLANG_UZBEK_CYRILLIC 0x02

#నిర్వచించు క్రమీకరించు_DEFAULT 0x0
#నిర్వచించు క్రమీకరించు_INVARIANT_MATH 0x1

#నిర్వచించు క్రమీకరించు_JAPANESE_XJIS 0x0
#నిర్వచించు క్రమీకరించు_JAPANESE_UNICODE 0x1
#నిర్వచించు క్రమీకరించు_JAPANESE_RADICALSTROKE 0x4

#నిర్వచించు క్రమీకరించు_CHINESE_BIG5 0x0
#నిర్వచించు క్రమీకరించు_CHINESE_PRCP 0x0
#నిర్వచించు క్రమీకరించు_CHINESE_UNICODE 0x1
#నిర్వచించు క్రమీకరించు_CHINESE_PRC 0x2
#నిర్వచించు క్రమీకరించు_CHINESE_BOPOMOFO 0x3

#నిర్వచించు క్రమీకరించు_KOREAN_KSC 0x0
#నిర్వచించు క్రమీకరించు_KOREAN_UNICODE 0x1

#నిర్వచించు క్రమీకరించు_GERMAN_PHONE_BOOK 0x1

#నిర్వచించు క్రమీకరించు_HUNGARIAN_DEFAULT 0x0
#నిర్వచించు క్రమీకరించు_HUNGARIAN_TECHNICAL 0x1

#నిర్వచించు క్రమీకరించు_GEORGIAN_TRADITIONAL 0x0
#నిర్వచించు క్రమీకరించు_GEORGIAN_MODERN 0x1

#నిర్వచించు MAKELANGID(p,s) ((((మాట_3)(s)) << 10) | (మాట_3)(p))
#నిర్వచించు PRIMARYLANGID(lgid) ((మాట_3)(lgid) & 0x3ff)
#నిర్వచించు SUBLANGID(lgid) ((మాట_3)(lgid) >> 10)

#నిర్వచించు NLS_VALID_LOCALE_ముసుగు 0x000fffff

#నిర్వచించు MAKELCID(lgid,srtid) ((DWORD)((((DWORD)((మాట_3)(srtid))) << 16) | ((DWORD)((మాట_3)(lgid)))))
#నిర్వచించు MAKESORTLCID(lgid,srtid,ver) ((DWORD)((MAKELCID(lgid,srtid)) | (((DWORD)((మాట_3)(ver))) << 20)))
#నిర్వచించు LANGIDFROMLCID(lcid) ((మాట_3)(lcid))
#నిర్వచించు SORTIDFROMLCID(lcid) ((మాట_3)((((DWORD)(lcid)) >> 16) & 0xf))
#నిర్వచించు SORTVERSIONFROMLCID(lcid) ((మాట_3)((((DWORD)(lcid)) >> 20) & 0xf))

#నిర్వచించు LOCALE_NAME_MAX_నిడివి 85
#నిర్వచించు LANG_SYSTEM_DEFAULT (MAKELANGID(LANG_NEUTRAL,SUBLANG_SYS_DEFAULT))
#నిర్వచించు LANG_USER_DEFAULT (MAKELANGID(LANG_NEUTRAL,SUBLANG_DEFAULT))

#నిర్వచించు LOCALE_SYSTEM_DEFAULT (MAKELCID(LANG_SYSTEM_DEFAULT,క్రమీకరించు_DEFAULT))
#నిర్వచించు LOCALE_USER_DEFAULT (MAKELCID(LANG_USER_DEFAULT,క్రమీకరించు_DEFAULT))

#నిర్వచించు LOCALE_NEUTRAL (MAKELCID(MAKELANGID(LANG_NEUTRAL,SUBLANG_NEUTRAL),క్రమీకరించు_DEFAULT))

#నిర్వచించు LOCALE_CUSTOM_DEFAULT (MAKELCID(MAKELANGID(LANG_NEUTRAL, SUBLANG_CUSTOM_DEFAULT), క్రమీకరించు_DEFAULT))
#నిర్వచించు LOCALE_CUSTOM_UNSPECIFIED (MAKELCID(MAKELANGID(LANG_NEUTRAL, SUBLANG_CUSTOM_UNSPECIFIED), క్రమీకరించు_DEFAULT))
#నిర్వచించు LOCALE_CUSTOM_UI_DEFAULT (MAKELCID(MAKELANGID(LANG_NEUTRAL, SUBLANG_UI_CUSTOM_DEFAULT), క్రమీకరించు_DEFAULT))

#నిర్వచించు LOCALE_INVARIANT (MAKELCID(MAKELANGID(LANG_INVARIANT,SUBLANG_NEUTRAL),క్రమీకరించు_DEFAULT))

#నిర్వచించు UNREFERENCED_PARAMETER(P) (P)
#నిర్వచించు DBG_UNREFERENCED_PARAMETER(P) (P)
#నిర్వచించు DBG_UNREFERENCED_LOCAL_VARIABLE(V) (V)

#నిర్వచించు DEFAULT_UNREACHABLE

#నిర్వచితం_కాకపోతే WIN32_NO_స్థితి
#నిర్వచించు స్థితి_WAIT_0 ((DWORD)0x00000000L)
#నిర్వచించు స్థితి_ABANDONED_WAIT_0 ((DWORD)0x00000080L)
#నిర్వచించు స్థితి_USER_APC ((DWORD)0x000000C0L)
#నిర్వచించు స్థితి_TIMEOUT ((DWORD)0x00000102L)
#నిర్వచించు స్థితి_PENDING ((DWORD)0x00000103L)
#నిర్వచించు DBG_EXCEPTION_HANDLED ((DWORD)0x00010001L)
#నిర్వచించు DBG_CONTINUE ((DWORD)0x00010002L)
#నిర్వచించు స్థితి_SEGMENT_NOTIFICATION ((DWORD)0x40000005L)
#నిర్వచించు DBG_TERMINATE_THREAD ((DWORD)0x40010003L)
#నిర్వచించు DBG_TERMINATE_PROCESS ((DWORD)0x40010004L)
#నిర్వచించు DBG_CONTROL_C ((DWORD)0x40010005L)
#నిర్వచించు DBG_CONTROL_BREAK ((DWORD)0x40010008L)
#నిర్వచించు DBG_COMMAND_EXCEPTION ((DWORD)0x40010009L)
#నిర్వచించు స్థితి_GUARD_పుట_VIOLATION ((DWORD)0x80000001L)
#నిర్వచించు స్థితి_DATATYPE_MISALIGNMENT ((DWORD)0x80000002L)
#నిర్వచించు స్థితి_BREAKPOINT ((DWORD)0x80000003L)
#నిర్వచించు స్థితి_SINGLE_అడుగు ((DWORD)0x80000004L)
#నిర్వచించు DBG_EXCEPTION_NOT_HANDLED ((DWORD)0x80010001L)
#నిర్వచించు స్థితి_ACCESS_VIOLATION ((DWORD)0xC0000005L)
#నిర్వచించు స్థితి_లోపల_పుట_ERROR ((DWORD)0xC0000006L)
#నిర్వచించు స్థితి_INVALID_HANDLE ((DWORD)0xC0000008L)
#నిర్వచించు స్థితి_NO_జ్ఞాపకం ((DWORD)0xC0000017L)
#నిర్వచించు స్థితి_ILLEGAL_INSTRUCTION ((DWORD)0xC000001DL)
#నిర్వచించు స్థితి_NONCONTINUABLE_EXCEPTION ((DWORD)0xC0000025L)
#నిర్వచించు స్థితి_INVALID_DISPOSITION ((DWORD)0xC0000026L)
#నిర్వచించు స్థితి_ARRAY_BOUNDS_EXCEEDED ((DWORD)0xC000008CL)
#నిర్వచించు స్థితి_FLOAT_DENORMAL_నిర్వాహ్యం ((DWORD)0xC000008DL)
#నిర్వచించు స్థితి_FLOAT_DIVIDE_BY_ZERO ((DWORD)0xC000008EL)
#నిర్వచించు స్థితి_FLOAT_INEXACT_ఫలితం ((DWORD)0xC000008FL)
#నిర్వచించు స్థితి_FLOAT_INVALID_OPERATION ((DWORD)0xC0000090L)
#నిర్వచించు స్థితి_FLOAT_అధికప్రవాహం ((DWORD)0xC0000091L)
#నిర్వచించు స్థితి_FLOAT_దొంతర_CHECK ((DWORD)0xC0000092L)
#నిర్వచించు స్థితి_FLOAT_UNDERFLOW ((DWORD)0xC0000093L)
#నిర్వచించు స్థితి_INTEGER_DIVIDE_BY_ZERO ((DWORD)0xC0000094L)
#నిర్వచించు స్థితి_INTEGER_అధికప్రవాహం ((DWORD)0xC0000095L)
#నిర్వచించు స్థితి_PRIVILEGED_INSTRUCTION ((DWORD)0xC0000096L)
#నిర్వచించు స్థితి_దొంతర_అధికప్రవాహం ((DWORD)0xC00000FDL)
#నిర్వచించు స్థితి_CONTROL_C_EXIT ((DWORD)0xC000013AL)
#నిర్వచించు స్థితి_FLOAT_గుణిజం_దోషాలు ((DWORD)0xC00002B4L)
#నిర్వచించు స్థితి_FLOAT_గుణిజం_TRAPS ((DWORD)0xC00002B5L)
#నిర్వచించు స్థితి_REG_NAT_CONSUMPTION ((DWORD)0xC00002C9L)
#నిర్వచించు స్థితి_SXS_EARLY_DEACTIVATION ((DWORD)0xC015000FL)
#నిర్వచించు స్థితి_SXS_INVALID_DEACTIVATION ((DWORD)0xC0150010L)
#అయితే_ముగింపు

#నిర్వచించు గరిష్ఠ_WAIT_OBJECTS 64
#నిర్వచించు గరిష్ఠ_SUSPEND_లెక్క MAXCHAR

  రకనిర్వచనం ULONG_PTR KSPIN_తాళం;
  రకనిర్వచనం KSPIN_తాళం *PKSPIN_తాళం;

#ఒకవేళ defined(__x86_64) && !defined(RC_INVOKED)

#నిర్వచితమైతే __cplusplus
  బాహ్య "C" {
#అయితే_ముగింపు

#నిర్వచించు బిట్టు_Test _bittest
#నిర్వచించు బిట్టు_Test_And_Complement _bittestandcomplement
#నిర్వచించు బిట్టు_Test_And_సమితి _bittestandset
#నిర్వచించు బిట్టు_Test_And_Reset _bittestandreset
#నిర్వచించు Interlocked_బిట్టు_Test_And_సమితి _interlockedbittestandset
#నిర్వచించు Interlocked_బిట్టు_Test_And_Reset _interlockedbittestandreset
#నిర్వచించు బిట్టు_Test64 _bittest64
#నిర్వచించు బిట్టు_Test_And_Complement64 _bittestandcomplement64
#నిర్వచించు బిట్టు_Test_And_Set64 _bittestandset64
#నిర్వచించు బిట్టు_Test_And_Reset64 _bittestandreset64
#నిర్వచించు Interlocked_బిట్టు_Test_And_Set64 _interlockedbittestandset64
#నిర్వచించు Interlocked_బిట్టు_Test_And_Reset64 _interlockedbittestandreset64

    __CRT_INLINE BOOLEAN _bittest(LONG స్థిరరాశి *పునాది_2,LONG స్థానభ్రంశం_3) {
      పూర్ణాంకం old = 0;
      __asm__ __volatile__("btl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(అస్థిర దీర్ఘ *) పునాది_2))
	:"Ir" (స్థానభ్రంశం_3));
      తిరిగి (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandcomplement(LONG *పునాది_2,LONG స్థానభ్రంశం_3) {
      పూర్ణాంకం old = 0;
      __asm__ __volatile__("btcl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(అస్థిర దీర్ఘ *) పునాది_2))
	:"Ir" (స్థానభ్రంశం_3));
      తిరిగి (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN Interlocked_బిట్టు_Test_And_Complement(LONG *పునాది_2,LONG బిట్టు_2) {
      పూర్ణాంకం old = 0;
      __asm__ __volatile__("lock ; btcl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(అస్థిర దీర్ఘ *) పునాది_2))
	:"Ir" (బిట్టు_2));
      తిరిగి (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandset(LONG *పునాది_2,LONG స్థానభ్రంశం_3) {
      పూర్ణాంకం old = 0;
      __asm__ __volatile__("btsl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(అస్థిర దీర్ఘ *) పునాది_2))
	:"Ir" (స్థానభ్రంశం_3));
      తిరిగి (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandreset(LONG *పునాది_2,LONG స్థానభ్రంశం_3) {
      పూర్ణాంకం old = 0;
      __asm__ __volatile__("btrl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(అస్థిర దీర్ఘ *) పునాది_2))
	:"Ir" (స్థానభ్రంశం_3));
      తిరిగి (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _interlockedbittestandset(LONG *పునాది_2,LONG స్థానభ్రంశం_3) {
      పూర్ణాంకం old = 0;
      __asm__ __volatile__("lock ; btsl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(అస్థిర దీర్ఘ *) పునాది_2))
	:"Ir" (స్థానభ్రంశం_3));
      తిరిగి (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _interlockedbittestandreset(LONG *పునాది_2,LONG స్థానభ్రంశం_3) {
      పూర్ణాంకం old = 0;
      __asm__ __volatile__("lock ; btrl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(అస్థిర దీర్ఘ *) పునాది_2))
	:"Ir" (స్థానభ్రంశం_3));
      తిరిగి (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittest64(LONG64 స్థిరరాశి *పునాది_2,LONG64 స్థానభ్రంశం_3) {
      పూర్ణాంకం old = 0;
      __asm__ __volatile__("btq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(అస్థిర దీర్ఘ దీర్ఘ *) పునాది_2))
	:"Ir" (స్థానభ్రంశం_3));
      తిరిగి (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandcomplement64(LONG64 *పునాది_2,LONG64 స్థానభ్రంశం_3) {
      పూర్ణాంకం old = 0;
      __asm__ __volatile__("btcq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(అస్థిర దీర్ఘ దీర్ఘ *) పునాది_2))
	:"Ir" (స్థానభ్రంశం_3));
      తిరిగి (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandset64(LONG64 *పునాది_2,LONG64 స్థానభ్రంశం_3) {
      పూర్ణాంకం old = 0;
      __asm__ __volatile__("btsq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(అస్థిర దీర్ఘ దీర్ఘ *) పునాది_2))
	:"Ir" (స్థానభ్రంశం_3));
      తిరిగి (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandreset64(LONG64 *పునాది_2,LONG64 స్థానభ్రంశం_3) {
      పూర్ణాంకం old = 0;
      __asm__ __volatile__("btrq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(అస్థిర దీర్ఘ దీర్ఘ *) పునాది_2))
	:"Ir" (స్థానభ్రంశం_3));
      తిరిగి (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _interlockedbittestandset64(LONG64 *పునాది_2,LONG64 స్థానభ్రంశం_3) {
      పూర్ణాంకం old = 0;
      __asm__ __volatile__("lock ; btsq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(అస్థిర దీర్ఘ దీర్ఘ *) పునాది_2))
	:"Ir" (స్థానభ్రంశం_3));
      తిరిగి (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _interlockedbittestandreset64(LONG64 *పునాది_2,LONG64 స్థానభ్రంశం_3) {
      పూర్ణాంకం old = 0;
      __asm__ __volatile__("lock ; btrq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(అస్థిర దీర్ఘ దీర్ఘ *) పునాది_2))
	:"Ir" (స్థానభ్రంశం_3));
      తిరిగి (BOOLEAN) (old!=0);
    }
#నిర్వచించు బిట్టు_పరిశీలన_Forward బిట్టు_పరిశీలన_Forward_2
#నిర్వచించు బిట్టు_పరిశీలన_తిరగేయి బిట్టు_పరిశీలన_తిరగేయి_2
#నిర్వచించు బిట్టు_పరిశీలన_Forward64 బిట్టు_పరిశీలన_Forward64_2
#నిర్వచించు బిట్టు_పరిశీలన_Reverse64 బిట్టు_పరిశీలన_Reverse64_2

    __CRT_INLINE BOOLEAN బిట్టు_పరిశీలన_Forward_2(DWORD *సూచీ_3,DWORD ముసుగు_3) {
      __asm__ __volatile__("bsfl %1,%0" : "=r" (ముసుగు_3),"=m" ((*(అస్థిర దీర్ఘ *)సూచీ_3)));
      తిరిగి ముసుగు_3!=0;
    }
    __CRT_INLINE BOOLEAN బిట్టు_పరిశీలన_తిరగేయి_2(DWORD *సూచీ_3,DWORD ముసుగు_3) {
      __asm__ __volatile__("bsrl %1,%0" : "=r" (ముసుగు_3),"=m" ((*(అస్థిర దీర్ఘ *)సూచీ_3)));
      తిరిగి ముసుగు_3!=0;
    }
    __CRT_INLINE BOOLEAN బిట్టు_పరిశీలన_Forward64_2(DWORD *సూచీ_3,DWORD64 ముసుగు_3) {
      __asm__ __volatile__("bsfq %1,%0" : "=r" (ముసుగు_3),"=m" ((*(అస్థిర దీర్ఘ దీర్ఘ *)సూచీ_3)));
      తిరిగి ముసుగు_3!=0;
    }
    __CRT_INLINE BOOLEAN బిట్టు_పరిశీలన_Reverse64_2(DWORD *సూచీ_3,DWORD64 ముసుగు_3) {
      __asm__ __volatile__("bsrq %1,%0" : "=r" (ముసుగు_3),"=m" ((*(అస్థిర దీర్ఘ దీర్ఘ *)సూచీ_3)));
      తిరిగి ముసుగు_3!=0;
    }

#నిర్వచించు InterlockedIncrement16 _InterlockedIncrement16
#నిర్వచించు InterlockedDecrement16 _InterlockedDecrement16
#నిర్వచించు InterlockedCompareExchange16 _InterlockedCompareExchange16

#నిర్వచించు InterlockedAnd _InterlockedAnd
#నిర్వచించు InterlockedOr _InterlockedOr
#నిర్వచించు InterlockedXor _InterlockedXor
#నిర్వచించు InterlockedIncrement _InterlockedIncrement
#నిర్వచించు InterlockedIncrementAcquire InterlockedIncrement
#నిర్వచించు InterlockedIncrementRelease InterlockedIncrement
#నిర్వచించు InterlockedDecrement _InterlockedDecrement
#నిర్వచించు InterlockedDecrementAcquire InterlockedDecrement
#నిర్వచించు InterlockedDecrementRelease InterlockedDecrement
#నిర్వచించు Interlocked_కూడు Interlocked_కూడు_2
#నిర్వచించు InterlockedExchange _InterlockedExchange
#నిర్వచించు Interlocked_Exchange_కూడు Interlocked_Exchange_కూడు_2
#నిర్వచించు InterlockedCompareExchange _InterlockedCompareExchange
#నిర్వచించు InterlockedCompareExchangeAcquire InterlockedCompareExchange
#నిర్వచించు InterlockedCompareExchangeRelease InterlockedCompareExchange

#నిర్వచించు InterlockedAnd64 _InterlockedAnd64
#నిర్వచించు InterlockedAndAffinity InterlockedAnd64
#నిర్వచించు InterlockedOr64 _InterlockedOr64
#నిర్వచించు InterlockedOrAffinity InterlockedOr64
#నిర్వచించు InterlockedXor64 _InterlockedXor64
#నిర్వచించు InterlockedIncrement64 _InterlockedIncrement64
#నిర్వచించు InterlockedDecrement64 _InterlockedDecrement64
#నిర్వచించు InterlockedAdd64 _InterlockedAdd64
#నిర్వచించు InterlockedExchange64 _InterlockedExchange64
#నిర్వచించు InterlockedExchangeAcquire64 InterlockedExchange64
#నిర్వచించు InterlockedExchangeAdd64 _InterlockedExchangeAdd64
#నిర్వచించు InterlockedCompareExchange64 _InterlockedCompareExchange64
#నిర్వచించు InterlockedCompareExchangeAcquire64 InterlockedCompareExchange64
#నిర్వచించు InterlockedCompareExchangeRelease64 InterlockedCompareExchange64

#నిర్వచించు Interlocked_Exchange_సూచిక Interlocked_Exchange_సూచిక_2
#నిర్వచించు Interlocked_Compare_Exchange_సూచిక Interlocked_Compare_Exchange_సూచిక_2
#నిర్వచించు Interlocked_Compare_Exchange_సూచిక_Acquire Interlocked_Compare_Exchange_సూచిక_2
#నిర్వచించు Interlocked_Compare_Exchange_సూచిక_Release Interlocked_Compare_Exchange_సూచిక_2

#నిర్వచించు Interlocked_Exchange_కూడు_కొలత_T(a,b) InterlockedExchangeAdd64((LONG64 *)a,b)
#నిర్వచించు Interlocked_Increment_కొలత_T(a) InterlockedIncrement64((LONG64 *)a)
#నిర్వచించు Interlocked_Decrement_కొలత_T(a) InterlockedDecrement64((LONG64 *)a)

    __CRT_INLINE SHORT InterlockedIncrement16(SHORT అస్థిర *Addend) {
      గుర్తులేని అక్షరం c;
      గుర్తులేని అక్షరం s;
      __asm__ __volatile__(
	"lock ; addw $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      తిరిగి (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE SHORT InterlockedDecrement16(SHORT అస్థిర *Addend) {
      గుర్తులేని అక్షరం c;
      గుర్తులేని అక్షరం s;
      __asm__ __volatile__(
	"lock ; subw $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      తిరిగి (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE SHORT InterlockedCompareExchange16(SHORT అస్థిర *Destination,SHORT ExChange,SHORT Comperand) {
      SHORT prev;
      __asm__ __volatile__("lock ; cmpxchgw %w1,%2"
	:"=a"(prev)
	:"q"(ExChange), "m"(*Destination), "0"(Comperand)
	: "memory");
      తిరిగి prev;
    }
    __CRT_INLINE LONG InterlockedAnd(LONG అస్థిర *Destination,LONG విలువ_3) {
      __asm__ __volatile__("lock ; andl %0,%1"
	: :"r"(విలువ_3),"m"(*Destination)
	: "memory");
      తిరిగి *Destination;
    }
    __CRT_INLINE LONG InterlockedOr(LONG అస్థిర *Destination,LONG విలువ_3) {
      __asm__ __volatile__("lock ; orl %0,%1"
	: : "r"(విలువ_3),"m"(*Destination) : "memory");
      తిరిగి *Destination;
    }
    __CRT_INLINE LONG InterlockedXor(LONG అస్థిర *Destination,LONG విలువ_3) {
      __asm__ __volatile__("lock ; xorl %0,%1"
	: : "r"(విలువ_3),"m"(*Destination) : "memory");
      తిరిగి *Destination;
    }
    //		$$$$
    __CRT_INLINE LONG64 InterlockedAnd64(LONG64 అస్థిర *Destination,LONG64 విలువ_3) {
      __asm__ __volatile__("lock ; andq %0,%1"
	: : "r"(విలువ_3),"m"(*Destination) : "memory");
      తిరిగి *Destination;
    }
    __CRT_INLINE LONG64 InterlockedOr64(LONG64 అస్థిర *Destination,LONG64 విలువ_3) {
      __asm__ __volatile__("lock ; orq %0,%1"
	: : "r"(విలువ_3),"m"(*Destination) : "memory");
      తిరిగి *Destination;
    }
    __CRT_INLINE LONG64 InterlockedXor64(LONG64 అస్థిర *Destination,LONG64 విలువ_3) {
      __asm__ __volatile__("lock ; xorq %0,%1"
	: : "r"(విలువ_3),"m"(*Destination) : "memory");
      తిరిగి *Destination;
    }
    __CRT_INLINE LONG InterlockedIncrement(LONG అస్థిర *Addend) {
      గుర్తులేని అక్షరం c;
      గుర్తులేని అక్షరం s;
      __asm__ __volatile__(
	"lock ; addl $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      తిరిగి (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE LONG InterlockedDecrement(LONG అస్థిర *Addend) {
      గుర్తులేని అక్షరం c;
      గుర్తులేని అక్షరం s;
      __asm__ __volatile__(
	"lock ; subl $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      తిరిగి (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE LONG InterlockedExchange(LONG అస్థిర *లక్ష్యం_2,LONG విలువ_3) {
      __asm__ __volatile("lock ; xchgl %0,%1"
	: "=r"(విలువ_3)
	: "m"(*లక్ష్యం_2),"0"(విలువ_3)
	: "memory");
      తిరిగి విలువ_3;
    }
    LONG Interlocked_Exchange_కూడు(LONG అస్థిర *Addend,LONG విలువ_3);

#నిర్వచితం_కాకపోతే _X86AMD64_
    __CRT_INLINE LONG Interlocked_కూడు(LONG అస్థిర *Addend,LONG విలువ_3) { తిరిగి Interlocked_Exchange_కూడు(Addend,విలువ_3) + విలువ_3; }
#అయితే_ముగింపు
    __CRT_INLINE LONG InterlockedCompareExchange(LONG అస్థిర *Destination,LONG ExChange,LONG Comperand) {
      LONG prev;
      __asm__ __volatile__("lock ; cmpxchgl %1,%2" : "=a" (prev) : "q" (ExChange),"m" (*Destination), "0" (Comperand) : "memory");
      తిరిగి prev;
    }
    __CRT_INLINE LONG64 InterlockedIncrement64(LONG64 అస్థిర *Addend) {
      గుర్తులేని అక్షరం c;
      గుర్తులేని అక్షరం s;
      __asm__ __volatile__(
	"lock ; addq $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      తిరిగి (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE LONG64 InterlockedDecrement64(LONG64 అస్థిర *Addend) {
      గుర్తులేని అక్షరం c;
      గుర్తులేని అక్షరం s;
      __asm__ __volatile__(
	"lock ; subq $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      తిరిగి (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE LONG64 InterlockedExchange64(LONG64 అస్థిర *లక్ష్యం_2,LONG64 విలువ_3) {
      __asm__ __volatile("lock ; xchgq %0,%1"
	: "=r"(విలువ_3)
	: "m"(*లక్ష్యం_2),"0"(విలువ_3)
	: "memory");
      తిరిగి విలువ_3;
    }
    LONG64 InterlockedExchangeAdd64(LONG64 అస్థిర *Addend,LONG64 విలువ_3);

#నిర్వచితం_కాకపోతే _X86AMD64_
    __CRT_INLINE LONG64 InterlockedAdd64(LONG64 అస్థిర *Addend,LONG64 విలువ_3) { తిరిగి InterlockedExchangeAdd64(Addend,విలువ_3) + విలువ_3; }
#అయితే_ముగింపు

    __CRT_INLINE LONG64 InterlockedCompareExchange64(LONG64 అస్థిర *Destination,LONG64 ExChange,LONG64 Comperand) {
      LONG64 prev;
      __asm__ __volatile__("lock ; cmpxchgq %1,%2" : "=a" (prev) : "q" (ExChange),"m" (*Destination), "0" (Comperand) : "memory");
      తిరిగి prev;
    }
    __CRT_INLINE PVOID Interlocked_Compare_Exchange_సూచిక(PVOID అస్థిర *Destination,PVOID ExChange,PVOID Comperand) {
      PVOID prev;
      __asm__ __volatile__("lock ; cmpxchgq %1,%2" : "=a" (prev) : "q" (ExChange),"m" (*Destination), "0" (Comperand) : "memory");
      తిరిగి prev;
    }
    __CRT_INLINE PVOID Interlocked_Exchange_సూచిక(PVOID అస్థిర *లక్ష్యం_2,PVOID విలువ_3) {
      __asm__ __volatile("lock ; xchgq %0,%1"
	: "=r"(విలువ_3)
	: "m"(*లక్ష్యం_2),"0"(విలువ_3)
	: "memory");
      తిరిగి విలువ_3;
    }

#నిర్వచించు Cache_పంక్తి_Flush(చిరునామా_2) _mm_clflush(చిరునామా_2)

    VOID _ReadWriteBarrier(VOID);

#నిర్వచించు FastFence __faststorefence
#నిర్వచించు ఎక్కించు_Fence _mm_lfence
#నిర్వచించు జ్ఞాపకం_Fence _mm_mfence
#నిర్వచించు StoreFence _mm_sfence

    VOID __faststorefence(VOID);
    VOID _m_prefetchw(అస్థిర CONST VOID *ఆధారం_2);

//!__TINYC__: #include <intrin.h>

#నిర్వచించు YieldProcessor _mm_pause
#నిర్వచించు జ్ఞాపకం_Barrier __faststorefence
#నిర్వచించు Pre_Fetch_Cache_పంక్తి(l,a) _mm_prefetch((CHAR CONST *) a,l)
#నిర్వచించు PrefetchForWrite(p) _m_prefetchw(p)
#నిర్వచించు ReadForWriteAccess(p) (_m_prefetchw(p),*(p))

#నిర్వచించు PF_TEMPORAL_LEVEL_1 _MM_HINT_T0
#నిర్వచించు PF_TEMPORAL_LEVEL_2 _MM_HINT_T1
#నిర్వచించు PF_TEMPORAL_LEVEL_3 _MM_HINT_T2
#నిర్వచించు PF_NON_TEMPORAL_LEVEL_ALL _MM_HINT_NTA

#నిర్వచించు ReadMxCsr _mm_getcsr
#నిర్వచించు WriteMxCsr _mm_setcsr

    VOID __int2c(VOID);

#నిర్వచించు DbgRaiseAssertionFailure() __int2c()
#నిర్వచించు GetCallersEflags() __getcallerseflags()

    గుర్తులేని __int32 __getcallerseflags(VOID);

#నిర్వచించు Get_Segment_హద్దు __segmentlimit

    DWORD __segmentlimit(DWORD Selector);

#నిర్వచించు Read_సమయం_Stamp_Counter() __rdtsc()

    DWORD64 __rdtsc(VOID);
    VOID __movsb(PBYTE Destination,BYTE స్థిరరాశి *ఆధారం_2,కొలత_T లెక్క_3);
    VOID __movsw(PWORD Destination,మాట_3 స్థిరరాశి *ఆధారం_2,కొలత_T లెక్క_3);
    VOID __movsd(PDWORD Destination,DWORD స్థిరరాశి *ఆధారం_2,కొలత_T లెక్క_3);
    VOID __movsq(PDWORD64 Destination,DWORD64 స్థిరరాశి *ఆధారం_2,కొలత_T లెక్క_3);
    VOID __stosb(PBYTE Destination,BYTE విలువ_3,కొలత_T లెక్క_3);
    VOID __stosw(PWORD Destination,మాట_3 విలువ_3,కొలత_T లెక్క_3);
    VOID __stosd(PDWORD Destination,DWORD విలువ_3,కొలత_T లెక్క_3);
    VOID __stosq(PDWORD64 Destination,DWORD64 విలువ_3,కొలత_T లెక్క_3);

#నిర్వచించు Multiply_ఎగువ __mulh
#నిర్వచించు Unsigned_Multiply_ఎగువ __umulh

    LONGLONG Multiply_ఎగువ(LONGLONG Multiplier,LONGLONG Multiplicand);
    ULONGLONG Unsigned_Multiply_ఎగువ(ULONGLONG Multiplier,ULONGLONG Multiplicand);

#నిర్వచించు జరుపు_Left128 __shiftleft128
#నిర్వచించు జరుపు_Right128 __shiftright128

    DWORD64 జరుపు_Left128(DWORD64 దిగువ_Part,DWORD64 ఎగువ_Part,BYTE జరుపు_3);
    DWORD64 జరుపు_Right128(DWORD64 దిగువ_Part,DWORD64 ఎగువ_Part,BYTE జరుపు_3);

#నిర్వచించు Multiply128 _mul128

    LONG64 Multiply128(LONG64 Multiplier,LONG64 Multiplicand,LONG64 *ఎగువ_లబ్ధం);

#నిర్వచించు UnsignedMultiply128 _umul128

    DWORD64 UnsignedMultiply128(DWORD64 Multiplier,DWORD64 Multiplicand,DWORD64 *ఎగువ_లబ్ధం);

    __CRT_INLINE LONG64 MultiplyExtract128(LONG64 Multiplier,LONG64 Multiplicand,BYTE జరుపు_3) {
      LONG64 extracted_లబ్ధం;
      LONG64 ఎగువ_లబ్ధం_2;
      LONG64 దిగువ_లబ్ధం;
      దిగువ_లబ్ధం = Multiply128(Multiplier,Multiplicand,&ఎగువ_లబ్ధం_2);
      extracted_లబ్ధం = (LONG64)జరుపు_Right128((LONG64)దిగువ_లబ్ధం,(LONG64)ఎగువ_లబ్ధం_2,జరుపు_3);
      తిరిగి extracted_లబ్ధం;
    }

    __CRT_INLINE DWORD64 UnsignedMultiplyExtract128(DWORD64 Multiplier,DWORD64 Multiplicand,BYTE జరుపు_3) {
      DWORD64 extracted_లబ్ధం;
      DWORD64 ఎగువ_లబ్ధం_2;
      DWORD64 దిగువ_లబ్ధం;
      దిగువ_లబ్ధం = UnsignedMultiply128(Multiplier,Multiplicand,&ఎగువ_లబ్ధం_2);
      extracted_లబ్ధం = జరుపు_Right128(దిగువ_లబ్ధం,ఎగువ_లబ్ధం_2,జరుపు_3);
      తిరిగి extracted_లబ్ధం;
    }

    __CRT_INLINE BYTE __readgsbyte(DWORD స్థానభ్రంశం_3) {
      BYTE ret;
      __asm__ అస్థిర ("movb	%%gs:%1,%0"
	: "=r" (ret) ,"=m" ((*(అస్థిర దీర్ఘ *) (DWORD64) స్థానభ్రంశం_3)));
      తిరిగి ret;
    }
    __CRT_INLINE మాట_3 __readgsword(DWORD స్థానభ్రంశం_3) {
      మాట_3 ret;
      __asm__ అస్థిర ("movw	%%gs:%1,%0"
	: "=r" (ret) ,"=m" ((*(అస్థిర దీర్ఘ *) (DWORD64) స్థానభ్రంశం_3)));
      తిరిగి ret;
    }
    __CRT_INLINE DWORD __readgsdword(DWORD స్థానభ్రంశం_3) {
      DWORD ret;
      __asm__ అస్థిర ("movl	%%gs:%1,%0"
	: "=r" (ret) ,"=m" ((*(అస్థిర దీర్ఘ *) (DWORD64) స్థానభ్రంశం_3)));
      తిరిగి ret;
    }
    __CRT_INLINE DWORD64 __readgsqword(DWORD స్థానభ్రంశం_3) {
      శూన్య *ret;
      __asm__ అస్థిర ("movq	%%gs:%1,%0"
	: "=r" (ret) ,"=m" ((*(అస్థిర దీర్ఘ *) (DWORD64) స్థానభ్రంశం_3)));
      తిరిగి (DWORD64) ret;
    }
    __CRT_INLINE VOID __writegsbyte(DWORD స్థానభ్రంశం_3,BYTE దత్తాంశం_3) {
      __asm__ అస్థిర ("movb	%0,%%gs:%1"
	: "=r" (దత్తాంశం_3) ,"=m" ((*(అస్థిర దీర్ఘ *) (DWORD64) స్థానభ్రంశం_3)));
    }
    __CRT_INLINE VOID __writegsword(DWORD స్థానభ్రంశం_3,మాట_3 దత్తాంశం_3) {
      __asm__ అస్థిర ("movw	%0,%%gs:%1"
	: "=r" (దత్తాంశం_3) ,"=m" ((*(అస్థిర దీర్ఘ *) (DWORD64) స్థానభ్రంశం_3)));
    }
    __CRT_INLINE VOID __writegsdword(DWORD స్థానభ్రంశం_3,DWORD దత్తాంశం_3) {
      __asm__ అస్థిర ("movl	%0,%%gs:%1"
	: "=r" (దత్తాంశం_3) ,"=m" ((*(అస్థిర దీర్ఘ *) (DWORD64) స్థానభ్రంశం_3)));
    }
    __CRT_INLINE VOID __writegsqword(DWORD స్థానభ్రంశం_3,DWORD64 దత్తాంశం_3) {
      __asm__ అస్థిర ("movq	%0,%%gs:%1"
	: "=r" (దత్తాంశం_3) ,"=m" ((*(అస్థిర దీర్ఘ *) (DWORD64) స్థానభ్రంశం_3)));
    }

#నిర్వచితమైతే __cplusplus
  }
#అయితే_ముగింపు

#నిర్వచించు EXCEPTION_READ_FAULT 0
#నిర్వచించు EXCEPTION_WRITE_FAULT 1
#నిర్వచించు EXCEPTION_EXECUTE_FAULT 8

#ఒకవేళ !defined(RC_INVOKED)

#నిర్వచించు CONTEXT_AMD64 0x100000

#నిర్వచించు CONTEXT_CONTROL (CONTEXT_AMD64 | 0x1L)
#నిర్వచించు CONTEXT_INTEGER (CONTEXT_AMD64 | 0x2L)
#నిర్వచించు CONTEXT_SEGMENTS (CONTEXT_AMD64 | 0x4L)
#నిర్వచించు CONTEXT_FLOATING_బిందువు (CONTEXT_AMD64 | 0x8L)
#నిర్వచించు CONTEXT_DEBUG_REGISTERS (CONTEXT_AMD64 | 0x10L)

#నిర్వచించు CONTEXT_నిండిన (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_FLOATING_బిందువు)
#నిర్వచించు CONTEXT_ALL (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_SEGMENTS | CONTEXT_FLOATING_బిందువు | CONTEXT_DEBUG_REGISTERS)

#నిర్వచించు CONTEXT_EXCEPTION_చురుకైన 0x8000000
#నిర్వచించు CONTEXT_SERVICE_చురుకైన 0x10000000
#నిర్వచించు CONTEXT_EXCEPTION_REQUEST 0x40000000
#నిర్వచించు CONTEXT_EXCEPTION_REPORTING 0x80000000
#అయితే_ముగింపు

#నిర్వచించు INITIAL_MXCSR 0x1f80
#నిర్వచించు INITIAL_FPCSR 0x027f

  రకనిర్వచనం నిర్మాణం DECLSPEC_ALIGN(16) _M128A {
    ULONGLONG దిగువ_3;
    LONGLONG ఎగువ_3;
  } M128A,*PM128A;

  రకనిర్వచనం నిర్మాణం _XMM_SAVE_AREA32 {
    మాట_3 Control_మాట;
    మాట_3 స్థితి_మాట;
    BYTE ట్యాగ్_మాట;
    BYTE Reserved1;
    మాట_3 ErrorOpcode;
    DWORD Error_స్థానభ్రంశం;
    మాట_3 ErrorSelector;
    మాట_3 Reserved2;
    DWORD దత్తాంశం_స్థానభ్రంశం_2;
    మాట_3 దత్తాంశం_Selector;
    మాట_3 Reserved3;
    DWORD MxCsr;
    DWORD Mx_Csr_ముసుగు;
    M128A FloatRegisters[8];
    M128A XmmRegisters[16];
    BYTE Reserved4[96];
  } XMM_SAVE_AREA32,*PXMM_SAVE_AREA32;

#నిర్వచించు LEGACY_SAVE_AREA_నిడివి పరిమాణం(XMM_SAVE_AREA32)

  రకనిర్వచనం నిర్మాణం DECLSPEC_ALIGN(16) _CONTEXT {
    DWORD64 P1Home;
    DWORD64 P2Home;
    DWORD64 P3Home;
    DWORD64 P4Home;
    DWORD64 P5Home;
    DWORD64 P6Home;
    DWORD ContextFlags;
    DWORD MxCsr;
    మాట_3 SegCs;
    మాట_3 SegDs;
    మాట_3 SegEs;
    మాట_3 SegFs;
    మాట_3 SegGs;
    మాట_3 SegSs;
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
    సంఘం {
      XMM_SAVE_AREA32 FltSave;
      XMM_SAVE_AREA32 FloatSave;
      నిర్మాణం {
	M128A శీర్షిక_2[2];
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
    M128A సదిశ_రిజిస్టరు[26];
    DWORD64 సదిశ_Control;
    DWORD64 DebugControl;
    DWORD64 చివరి_Branch_గమ్యం_Rip;
    DWORD64 చివరి_Branch_From_Rip;
    DWORD64 చివరి_Exception_గమ్యం_Rip;
    DWORD64 చివరి_Exception_From_Rip;
  } CONTEXT,*PCONTEXT;

#నిర్వచించు RUNTIME_FUNCTION_పరోక్ష 0x1

  రకనిర్వచనం నిర్మాణం _RUNTIME_FUNCTION {
    DWORD Begin_చిరునామా;
    DWORD చివర_చిరునామా;
    DWORD Unwind_దత్తాంశం;
  } RUNTIME_FUNCTION,*PRUNTIME_FUNCTION;

  రకనిర్వచనం PRUNTIME_FUNCTION (*PGET_RUNTIME_FUNCTION_CALLBACK)(DWORD64 ControlPc,PVOID Context);
  రకనిర్వచనం DWORD (*POUT_యొక్క_PROCESS_FUNCTION_పట్టిక_CALLBACK)(HANDLE Process,PVOID పట్టిక_చిరునామా,PDWORD Entries,PRUNTIME_FUNCTION *Functions);

#నిర్వచించు బహిర్గతం_యొక్క_PROCESS_FUNCTION_పట్టిక_CALLBACK_EXPORT_NAME "OutOfProcessFunctionTableCallback"
#అయితే_ముగింపు /* defined(__x86_64) && !defined(RC_INVOKED) */

#ఒకవేళ defined(__TINYC__) && (defined(__aarch64__) || defined(__arm64__)) && !defined(RC_INVOKED)

#నిర్వచించు __TCC_WINNT_ATOMIC_SEQ_CST 5
/* TCC lowers __atomic_compare_exchange's fourth argument as weak, but the
   ARM64 helper reads it as success_memorder.  Strong CAS passes weak == 0,
   so keep Interlocked's barriers explicit here. */
#నిర్వచించు __TCC_WINNT_MEMORY_BARRIER() __asm__ __volatile__("dmb ish" : : : "memory")

/* This covers the LONG operations needed by TCC's semaphore code and the
   pointer helpers that winbase.h exposes through Interlocked pointer macros.
   Add local helpers before relying on increment/decrement, add/exchange-add,
   bitwise, or 64-bit Interlocked forms on Windows ARM64 with TCC. */

    __CRT_INLINE LONG InterlockedExchange(LONG అస్థిర *లక్ష్యం_2,LONG విలువ_3) {
      LONG Old;
      __atomic_load(లక్ష్యం_2,&Old,__TCC_WINNT_ATOMIC_SEQ_CST);
      __TCC_WINNT_MEMORY_BARRIER();
      అయితే (!__atomic_compare_exchange(లక్ష్యం_2,&Old,&విలువ_3,0,
	__TCC_WINNT_ATOMIC_SEQ_CST,__TCC_WINNT_ATOMIC_SEQ_CST))
	;
      __TCC_WINNT_MEMORY_BARRIER();
      తిరిగి Old;
    }
    __CRT_INLINE LONG InterlockedCompareExchange(LONG అస్థిర *Destination,LONG ExChange,LONG Comperand) {
      LONG Old = Comperand;
      __TCC_WINNT_MEMORY_BARRIER();
      __atomic_compare_exchange(Destination,&Old,&ExChange,0,
	__TCC_WINNT_ATOMIC_SEQ_CST,__TCC_WINNT_ATOMIC_SEQ_CST);
      __TCC_WINNT_MEMORY_BARRIER();
      తిరిగి Old;
    }
    __CRT_INLINE PVOID __TCC_WINNT_InterlockedExchangePointer(PVOID అస్థిర *లక్ష్యం_2,PVOID విలువ_3) {
      PVOID Old;
      __atomic_load(లక్ష్యం_2,&Old,__TCC_WINNT_ATOMIC_SEQ_CST);
      __TCC_WINNT_MEMORY_BARRIER();
      అయితే (!__atomic_compare_exchange(లక్ష్యం_2,&Old,&విలువ_3,0,
	__TCC_WINNT_ATOMIC_SEQ_CST,__TCC_WINNT_ATOMIC_SEQ_CST))
	;
      __TCC_WINNT_MEMORY_BARRIER();
      తిరిగి Old;
    }
    __CRT_INLINE PVOID __TCC_WINNT_InterlockedCompareExchangePointer(PVOID అస్థిర *Destination,PVOID ExChange,PVOID Comperand) {
      PVOID Old = Comperand;
      __TCC_WINNT_MEMORY_BARRIER();
      __atomic_compare_exchange(Destination,&Old,&ExChange,0,
	__TCC_WINNT_ATOMIC_SEQ_CST,__TCC_WINNT_ATOMIC_SEQ_CST);
      __TCC_WINNT_MEMORY_BARRIER();
      తిరిగి Old;
    }

#నిర్వచించు Interlocked_Exchange_సూచిక __TCC_WINNT_InterlockedExchangePointer
#నిర్వచించు Interlocked_Compare_Exchange_సూచిక __TCC_WINNT_InterlockedCompareExchangePointer
#నిర్వచించు Interlocked_Compare_Exchange_సూచిక_Acquire Interlocked_Compare_Exchange_సూచిక
#నిర్వచించు Interlocked_Compare_Exchange_సూచిక_Release Interlocked_Compare_Exchange_సూచిక

#నిర్వచించు InterlockedCompareExchangeAcquire InterlockedCompareExchange
#నిర్వచించు InterlockedCompareExchangeRelease InterlockedCompareExchange

#నిర్వచనం_రద్దు __TCC_WINNT_MEMORY_BARRIER
#నిర్వచనం_రద్దు __TCC_WINNT_ATOMIC_SEQ_CST

#అయితే_ముగింపు /* defined(__TINYC__) && (defined(__aarch64__) || defined(__arm64__)) && !defined(RC_INVOKED) */

#ఒకవేళ defined(_ARM64_)

/* ARM64 Context Definition */
#నిర్వచించు CONTEXT_ARM64 0x00400000
#నిర్వచించు CONTEXT_CONTROL (CONTEXT_ARM64 | 0x00000001L)
#నిర్వచించు CONTEXT_INTEGER (CONTEXT_ARM64 | 0x00000002L)
#నిర్వచించు CONTEXT_FLOATING_బిందువు (CONTEXT_ARM64 | 0x00000004L)
#నిర్వచించు CONTEXT_DEBUG (CONTEXT_ARM64 | 0x00000008L)
#నిర్వచించు CONTEXT_నిండిన (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_FLOATING_బిందువు)
#నిర్వచించు CONTEXT_ALL (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_FLOATING_బిందువు | CONTEXT_DEBUG)
#నిర్వచించు ARM64_MAX_BREAKPOINTS 8
#నిర్వచించు ARM64_MAX_WATCHPOINTS 2

  రకనిర్వచనం సంఘం _ARM64_NT_NEON128 {
    నిర్మాణం {
      ULONGLONG దిగువ_3;
      LONGLONG ఎగువ_3;
    } DUMMYSTRUCTNAME;
    ద్విగుణ D[2];
    దశాంశం S[4];
    మాట_3 H[8];
    BYTE B[16];
  } ARM64_NT_NEON128,*PARM64_NT_NEON128;

  రకనిర్వచనం నిర్మాణం DECLSPEC_ALIGN(16) _ARM64_NT_CONTEXT {
    ULONG ContextFlags;
    ULONG Cpsr;
    సంఘం {
      నిర్మాణం {
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

  C_ASSERT(పరిమాణం(ARM64_NT_CONTEXT) == 0x390);

  రకనిర్వచనం ARM64_NT_CONTEXT CONTEXT,*PCONTEXT;

  రకనిర్వచనం నిర్మాణం _RUNTIME_FUNCTION {
    DWORD Begin_చిరునామా;
    DWORD Unwind_దత్తాంశం;
  } RUNTIME_FUNCTION,*PRUNTIME_FUNCTION;

  రకనిర్వచనం PRUNTIME_FUNCTION (*PGET_RUNTIME_FUNCTION_CALLBACK)(DWORD64 ControlPc,PVOID Context);
  రకనిర్వచనం DWORD (*POUT_యొక్క_PROCESS_FUNCTION_పట్టిక_CALLBACK)(HANDLE Process,PVOID పట్టిక_చిరునామా,PDWORD Entries,PRUNTIME_FUNCTION *Functions);

#అయితే_ముగింపు /* _ARM64_ */

#ఒకవేళ (defined _ARM64_ || defined _AMD64_) && !defined RC_INVOKED
  NTSYSAPI VOID __cdecl RtlRestoreContext (PCONTEXT Context_రికార్డు,నిర్మాణం EXCEPTION_రికార్డు *Exception_రికార్డు);
  NTSYSAPI BOOLEAN __cdecl Rtl_కూడు_Function_పట్టిక(PRUNTIME_FUNCTION Function_పట్టిక,DWORD నమోదు_లెక్క,DWORD64 పునాది_చిరునామా);
  NTSYSAPI BOOLEAN __cdecl Rtl_Install_Function_పట్టిక_Callback(DWORD64 పట్టిక_Identifier,DWORD64 పునాది_చిరునామా,DWORD నిడివి_2,PGET_RUNTIME_FUNCTION_CALLBACK Callback,PVOID Context,PCWSTR బహిర్గతం_యొక్క_Process_Callback_Dll);
  NTSYSAPI BOOLEAN __cdecl Rtl_Delete_Function_పట్టిక(PRUNTIME_FUNCTION Function_పట్టిక);
#అయితే_ముగింపు

#నిర్వచితమైతే I_X86_
#ఒకవేళ(defined(_X86_) && !defined(__x86_64)) && !defined(RC_INVOKED)
#నిర్వచితమైతే __cplusplus
  బాహ్య "C" {
#అయితే_ముగింపు

    __CRT_INLINE BOOLEAN Interlocked_బిట్టు_Test_And_సమితి(LONG *పునాది_2,LONG బిట్టు_2) {
      పూర్ణాంకం old = 0;
      __asm__ __volatile__("lock ; btsl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(అస్థిర దీర్ఘ *) పునాది_2))
	:"Ir" (బిట్టు_2));
      తిరిగి (BOOLEAN) (old!=0);
    }

    __CRT_INLINE BOOLEAN Interlocked_బిట్టు_Test_And_Reset(LONG *పునాది_2,LONG బిట్టు_2) {
      పూర్ణాంకం old = 0;
      __asm__ __volatile__("lock ; btrl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(అస్థిర దీర్ఘ *) పునాది_2))
	:"Ir" (బిట్టు_2));
      తిరిగి (BOOLEAN) (old!=0);
    }

    __CRT_INLINE BOOLEAN Interlocked_బిట్టు_Test_And_Complement(LONG *పునాది_2,LONG బిట్టు_2) {
      పూర్ణాంకం old = 0;
      __asm__ __volatile__("lock ; btcl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(అస్థిర దీర్ఘ *) పునాది_2))
	:"Ir" (బిట్టు_2));
      తిరిగి (BOOLEAN) (old!=0);
    }

#నిర్వచితమైతే ఉపసర్గ_2
    BYTE __readfsbyte(DWORD స్థానభ్రంశం_3);
    మాట_3 __readfsword(DWORD స్థానభ్రంశం_3);
    DWORD __readfsdword(DWORD స్థానభ్రంశం_3);
    VOID __writefsbyte(DWORD స్థానభ్రంశం_3,BYTE దత్తాంశం_3);
    VOID __writefsword(DWORD స్థానభ్రంశం_3,మాట_3 దత్తాంశం_3);
    VOID __writefsdword(DWORD స్థానభ్రంశం_3,DWORD దత్తాంశం_3);
#అయితే_ముగింపు

#నిర్వచితమైతే __cplusplus
  }
#అయితే_ముగింపు
#అయితే_ముగింపు

#ఒకవేళ(defined(_X86_) && !defined(__x86_64))
  __CRT_INLINE VOID జ్ఞాపకం_Barrier(VOID) {
    LONG Barrier;
    __asm__ __volatile__("xchgl %%eax,%0 "
      :"=r" (Barrier));
  }
#నిర్వచించు YieldProcessor() __asm__ __volatile__("rep nop ");

#నిర్వచించు Pre_Fetch_Cache_పంక్తి(l,a)
#నిర్వచించు ReadForWriteAccess(p) (*(p))

#నిర్వచించు PF_TEMPORAL_LEVEL_1
#నిర్వచించు PF_NON_TEMPORAL_LEVEL_ALL

  __CRT_INLINE VOID DbgRaiseAssertionFailure(శూన్య) {
    __asm__ __volatile__("int $0x2c ");
  }
  PVOID GetCurrentFiber(శూన్య);
  __CRT_INLINE PVOID GetCurrentFiber(శూన్య)
  {
    శూన్య *ret;
    __asm__ అస్థిర ("movl	%%fs:0x10,%0"
	: "=r" (ret));
    తిరిగి ret;
  }
  PVOID Get_Fiber_దత్తాంశం(శూన్య);
  __CRT_INLINE PVOID Get_Fiber_దత్తాంశం(శూన్య)
  {
    శూన్య *ret;
    __asm__ అస్థిర ("movl	%%fs:0x10,%0\n"
	"movl	(%0),%0"
	: "=r" (ret));
    తిరిగి ret;
  }
#అయితే_ముగింపు

#నిర్వచించు EXCEPTION_READ_FAULT 0
#నిర్వచించు EXCEPTION_WRITE_FAULT 1
#నిర్వచించు EXCEPTION_EXECUTE_FAULT 8

#నిర్వచించు కొలత_యొక్క_80387_REGISTERS 80

#ఒకవేళ !defined(RC_INVOKED)

#నిర్వచించు CONTEXT_i386 0x00010000
#నిర్వచించు CONTEXT_i486 0x00010000

#నిర్వచించు CONTEXT_CONTROL (CONTEXT_i386 | 0x00000001L)
#నిర్వచించు CONTEXT_INTEGER (CONTEXT_i386 | 0x00000002L)
#నిర్వచించు CONTEXT_SEGMENTS (CONTEXT_i386 | 0x00000004L)
#నిర్వచించు CONTEXT_FLOATING_బిందువు (CONTEXT_i386 | 0x00000008L)
#నిర్వచించు CONTEXT_DEBUG_REGISTERS (CONTEXT_i386 | 0x00000010L)
#నిర్వచించు CONTEXT_EXTENDED_REGISTERS (CONTEXT_i386 | 0x00000020L)

#నిర్వచించు CONTEXT_నిండిన (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_SEGMENTS)

#నిర్వచించు CONTEXT_ALL (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_SEGMENTS | CONTEXT_FLOATING_బిందువు | CONTEXT_DEBUG_REGISTERS | CONTEXT_EXTENDED_REGISTERS)
#అయితే_ముగింపు

#నిర్వచించు గరిష్ఠ_SUPPORTED_EXTENSION 512

    రకనిర్వచనం నిర్మాణం _FLOATING_SAVE_AREA {
      DWORD Control_మాట;
      DWORD స్థితి_మాట;
      DWORD ట్యాగ్_మాట;
      DWORD Error_స్థానభ్రంశం;
      DWORD ErrorSelector;
      DWORD దత్తాంశం_స్థానభ్రంశం_2;
      DWORD దత్తాంశం_Selector;
      BYTE రిజిస్టరు_Area[కొలత_యొక్క_80387_REGISTERS];
      DWORD Cr0NpxState;
    } FLOATING_SAVE_AREA;

    రకనిర్వచనం FLOATING_SAVE_AREA *PFLOATING_SAVE_AREA;

    రకనిర్వచనం నిర్మాణం _CONTEXT {
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
      BYTE ExtendedRegisters[గరిష్ఠ_SUPPORTED_EXTENSION];
    } CONTEXT;

    రకనిర్వచనం CONTEXT *PCONTEXT;
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే LDT_నమోదు_DEFINED
#నిర్వచించు LDT_నమోదు_DEFINED

    రకనిర్వచనం నిర్మాణం LDT_నమోదు {
      మాట_3 హద్దు_దిగువ;
      మాట_3 పునాది_దిగువ;
      సంఘం {
	నిర్మాణం {
	  BYTE పునాది_Mid;
	  BYTE Flags1;
	  BYTE Flags2;
	  BYTE పునాది_Hi;
	} బైట్లు_2;
	నిర్మాణం {
	  DWORD పునాది_Mid : 8;
	  DWORD Type : 5;
	  DWORD Dpl : 2;
	  DWORD Pres : 1;
	  DWORD హద్దు_Hi : 4;
	  DWORD Sys : 1;
	  DWORD Reserved_0 : 1;
	  DWORD Default_Big : 1;
	  DWORD Granularity : 1;
	  DWORD పునాది_Hi : 8;
	} బిట్లు_2;
      } ఎగువ_మాట;
    } LDT_నమోదు_2,*PLDT_నమోదు;
#అయితే_ముగింపు

#ఒకవేళ defined(__ia64__) && !defined(RC_INVOKED)

#నిర్వచితమైతే __cplusplus
    బాహ్య "C" {
#అయితే_ముగింపు

      BOOLEAN బిట్టు_పరిశీలన_Forward64(DWORD *సూచీ_3,DWORD64 ముసుగు_3);
      BOOLEAN బిట్టు_పరిశీలన_Reverse64(DWORD *సూచీ_3,DWORD64 ముసుగు_3);

#నిర్వచితమైతే __cplusplus
    }
#అయితే_ముగింపు
#అయితే_ముగింపు

#ఒకవేళ !defined(GENUTIL) && !defined(_GENIA64_) && defined(_IA64_)

    శూన్య *_cdecl _rdteb(శూన్య);
#నిర్వచితమైతే __ia64__

#నిర్వచించు NtCurrentTeb() ((నిర్మాణం _TEB *)_rdteb())
#నిర్వచించు GetCurrentFiber() (((PNT_TIB)NtCurrentTeb())->Fiber_దత్తాంశం)
#నిర్వచించు Get_Fiber_దత్తాంశం() (*(PVOID *)(GetCurrentFiber()))

#నిర్వచితమైతే __cplusplus
    బాహ్య "C" {
#అయితే_ముగింపు

      శూన్య __break(పూర్ణాంకం);
      శూన్య __yield(శూన్య);
      శూన్య __mf(శూన్య);
      శూన్య __lfetch(పూర్ణాంకం Level,VOID CONST *చిరునామా_2);
      శూన్య __lfetchfault(పూర్ణాంకం Level,VOID CONST *చిరునామా_2);
      శూన్య __lfetch_excl(పూర్ణాంకం Level,VOID CONST *చిరునామా_2);
      శూన్య __lfetchfault_excl(పూర్ణాంకం Level,VOID CONST *చిరునామా_2);

#నిర్వచించు MD_LFHINT_NONE 0x00
#నిర్వచించు MD_LFHINT_NT1 0x01
#నిర్వచించు MD_LFHINT_NT2 0x02
#నిర్వచించు MD_LFHINT_NTA 0x03

#నిర్వచితమైతే __cplusplus
    }
#అయితే_ముగింపు

#నిర్వచించు YieldProcessor __yield
#నిర్వచించు జ్ఞాపకం_Barrier __mf
#నిర్వచించు Pre_Fetch_Cache_పంక్తి __lfetch
#నిర్వచించు ReadForWriteAccess(p) (*(p))
#నిర్వచించు DbgRaiseAssertionFailure() __break(ASSERT_BREAKPOINT)

#నిర్వచించు PF_TEMPORAL_LEVEL_1 MD_LFHINT_NONE
#నిర్వచించు PF_NON_TEMPORAL_LEVEL_ALL MD_LFHINT_NTA

#నిర్వచించు Unsigned_Multiply_ఎగువ __UMULH

    ULONGLONG Unsigned_Multiply_ఎగువ(ULONGLONG Multiplier,ULONGLONG Multiplicand);
#లేకపోతే
    నిర్మాణం _TEB *NtCurrentTeb(శూన్య);
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితమైతే _IA64_

#నిర్వచించు EXCEPTION_READ_FAULT 0
#నిర్వచించు EXCEPTION_WRITE_FAULT 1
#నిర్వచించు EXCEPTION_EXECUTE_FAULT 2

#ఒకవేళ !defined(RC_INVOKED)

#నిర్వచించు CONTEXT_IA64 0x00080000

#నిర్వచించు CONTEXT_CONTROL (CONTEXT_IA64 | 0x00000001L)
#నిర్వచించు CONTEXT_క్రింది_FLOATING_బిందువు (CONTEXT_IA64 | 0x00000002L)
#నిర్వచించు CONTEXT_HIGHER_FLOATING_బిందువు (CONTEXT_IA64 | 0x00000004L)
#నిర్వచించు CONTEXT_INTEGER (CONTEXT_IA64 | 0x00000008L)
#నిర్వచించు CONTEXT_DEBUG (CONTEXT_IA64 | 0x00000010L)
#నిర్వచించు CONTEXT_IA32_CONTROL (CONTEXT_IA64 | 0x00000020L)

#నిర్వచించు CONTEXT_FLOATING_బిందువు (CONTEXT_క్రింది_FLOATING_బిందువు | CONTEXT_HIGHER_FLOATING_బిందువు)
#నిర్వచించు CONTEXT_నిండిన (CONTEXT_CONTROL | CONTEXT_FLOATING_బిందువు | CONTEXT_INTEGER | CONTEXT_IA32_CONTROL)
#నిర్వచించు CONTEXT_ALL (CONTEXT_CONTROL | CONTEXT_FLOATING_బిందువు | CONTEXT_INTEGER | CONTEXT_DEBUG | CONTEXT_IA32_CONTROL)

#నిర్వచించు CONTEXT_EXCEPTION_చురుకైన 0x8000000
#నిర్వచించు CONTEXT_SERVICE_చురుకైన 0x10000000
#నిర్వచించు CONTEXT_EXCEPTION_REQUEST 0x40000000
#నిర్వచించు CONTEXT_EXCEPTION_REPORTING 0x80000000
#అయితే_ముగింపు

    రకనిర్వచనం నిర్మాణం _CONTEXT {
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

    రకనిర్వచనం నిర్మాణం _PLABEL_DESCRIPTOR {
      ULONGLONG నమోదు_బిందువు;
      ULONGLONG Global_సూచిక_2;
    } PLABEL_DESCRIPTOR,*PPLABEL_DESCRIPTOR;

    రకనిర్వచనం నిర్మాణం _RUNTIME_FUNCTION {
      DWORD Begin_చిరునామా;
      DWORD చివర_చిరునామా;
      DWORD Unwind_Info_చిరునామా;
    } RUNTIME_FUNCTION,*PRUNTIME_FUNCTION;

    రకనిర్వచనం PRUNTIME_FUNCTION (*PGET_RUNTIME_FUNCTION_CALLBACK)(DWORD64 ControlPc,PVOID Context);
    రకనిర్వచనం DWORD (*POUT_యొక్క_PROCESS_FUNCTION_పట్టిక_CALLBACK)(HANDLE Process,PVOID పట్టిక_చిరునామా,PDWORD Entries,PRUNTIME_FUNCTION *Functions);

#నిర్వచించు బహిర్గతం_యొక్క_PROCESS_FUNCTION_పట్టిక_CALLBACK_EXPORT_NAME "OutOfProcessFunctionTableCallback"

    BOOLEAN Rtl_కూడు_Function_పట్టిక(PRUNTIME_FUNCTION Function_పట్టిక,DWORD నమోదు_లెక్క,ULONGLONG పునాది_చిరునామా,ULONGLONG లక్ష్యం_Gp);
    BOOLEAN Rtl_Install_Function_పట్టిక_Callback(DWORD64 పట్టిక_Identifier,DWORD64 పునాది_చిరునామా,DWORD నిడివి_2,DWORD64 లక్ష్యం_Gp,PGET_RUNTIME_FUNCTION_CALLBACK Callback,PVOID Context,PCWSTR బహిర్గతం_యొక్క_Process_Callback_Dll);
    BOOLEAN Rtl_Delete_Function_పట్టిక(PRUNTIME_FUNCTION Function_పట్టిక);
    VOID RtlRestoreContext (PCONTEXT Context_రికార్డు,నిర్మాణం EXCEPTION_రికార్డు *Exception_రికార్డు);
    VOID __jump_unwind(ULONGLONG లక్ష్యం_Ms_చట్రం,ULONGLONG లక్ష్యం_Bs_చట్రం,ULONGLONG లక్ష్యం_Pc);
#అయితే_ముగింపు

#నిర్వచించు EXCEPTION_NONCONTINUABLE 0x1
#నిర్వచించు EXCEPTION_గరిష్ఠ_PARAMETERS 15

    రకనిర్వచనం నిర్మాణం EXCEPTION_రికార్డు {
      DWORD Exception_సంకేతం;
      DWORD ExceptionFlags;
      నిర్మాణం EXCEPTION_రికార్డు *Exception_రికార్డు;
      PVOID Exception_చిరునామా;
      DWORD సంఖ్య_Parameters;
      ULONG_PTR ExceptionInformation[EXCEPTION_గరిష్ఠ_PARAMETERS];
    } EXCEPTION_రికార్డు_2;

    రకనిర్వచనం EXCEPTION_రికార్డు_2 *PEXCEPTION_రికార్డు;

    రకనిర్వచనం నిర్మాణం _EXCEPTION_RECORD32 {
      DWORD Exception_సంకేతం;
      DWORD ExceptionFlags;
      DWORD Exception_రికార్డు;
      DWORD Exception_చిరునామా;
      DWORD సంఖ్య_Parameters;
      DWORD ExceptionInformation[EXCEPTION_గరిష్ఠ_PARAMETERS];
    } EXCEPTION_RECORD32,*PEXCEPTION_RECORD32;

    రకనిర్వచనం నిర్మాణం _EXCEPTION_RECORD64 {
      DWORD Exception_సంకేతం;
      DWORD ExceptionFlags;
      DWORD64 Exception_రికార్డు;
      DWORD64 Exception_చిరునామా;
      DWORD సంఖ్య_Parameters;
      DWORD __unusedAlignment;
      DWORD64 ExceptionInformation[EXCEPTION_గరిష్ఠ_PARAMETERS];
    } EXCEPTION_RECORD64,*PEXCEPTION_RECORD64;

    రకనిర్వచనం నిర్మాణం EXCEPTION_సూచికలు_2 {
      PEXCEPTION_రికార్డు Exception_రికార్డు;
      PCONTEXT Context_రికార్డు;
    } EXCEPTION_సూచికలు,*PEXCEPTION_సూచికలు;

#నిర్వచితమైతే __x86_64

    రకనిర్వచనం EXCEPTION_DISPOSITION NTAPI EXCEPTION_ROUTINE (నిర్మాణం EXCEPTION_రికార్డు *Exception_రికార్డు, PVOID Establisher_చట్రం_2, నిర్మాణం _CONTEXT *Context_రికార్డు, PVOID DispatcherContext);
#నిర్వచితం_కాకపోతే __PEXCEPTION_ROUTINE_DEFINED
#నిర్వచించు __PEXCEPTION_ROUTINE_DEFINED
    రకనిర్వచనం EXCEPTION_ROUTINE *PEXCEPTION_ROUTINE;
#అయితే_ముగింపు

    /* http://msdn.microsoft.com/en-us/library/ms680597(VS.85).aspx */

#నిర్వచించు UNWIND_HISTORY_పట్టిక_కొలత 12

  రకనిర్వచనం నిర్మాణం UNWIND_HISTORY_పట్టిక_నమోదు {
    ULONG64 Image_పునాది;
    PRUNTIME_FUNCTION Function_నమోదు;
  } UNWIND_HISTORY_పట్టిక_నమోదు_2, *PUNWIND_HISTORY_పట్టిక_నమోదు;

#నిర్వచించు UNWIND_HISTORY_పట్టిక_NONE    0
#నిర్వచించు UNWIND_HISTORY_పట్టిక_GLOBAL  1
#నిర్వచించు UNWIND_HISTORY_పట్టిక_LOCAL   2

  రకనిర్వచనం నిర్మాణం UNWIND_HISTORY_పట్టిక {
    ULONG లెక్క_3;
    UCHAR శోధన;
    ULONG64 దిగువ_చిరునామా;
    ULONG64 ఎగువ_చిరునామా;
    UNWIND_HISTORY_పట్టిక_నమోదు_2 నమోదు_2[UNWIND_HISTORY_పట్టిక_కొలత];
  } UNWIND_HISTORY_పట్టిక_2, *PUNWIND_HISTORY_పట్టిక;

  /* http://msdn.microsoft.com/en-us/library/b6sf5kbd(VS.80).aspx */

  నిర్మాణం _DISPATCHER_CONTEXT;
  రకనిర్వచనం నిర్మాణం _DISPATCHER_CONTEXT DISPATCHER_CONTEXT;
  రకనిర్వచనం నిర్మాణం _DISPATCHER_CONTEXT *PDISPATCHER_CONTEXT;

  నిర్మాణం _DISPATCHER_CONTEXT {
    ULONG64 ControlPc;
    ULONG64 Image_పునాది;
    PRUNTIME_FUNCTION Function_నమోదు;
    ULONG64 Establisher_చట్రం_2;
    ULONG64 లక్ష్యం_Ip;
    PCONTEXT Context_రికార్డు;
    PEXCEPTION_ROUTINE LanguageHandler;
    PVOID Handler_దత్తాంశం;
    /* http://www.nynaeve.net/?p=99 */
    PUNWIND_HISTORY_పట్టిక History_పట్టిక;
    ULONG Scope_సూచీ;
    ULONG Fill0;
  };

  /* http://msdn.microsoft.com/en-us/library/ms680617(VS.85).aspx */

  రకనిర్వచనం నిర్మాణం KNONVOLATILE_CONTEXT_సూచికలు
  {
    PM128A FloatingContext[16];
    PULONG64 IntegerContext[16];
  } KNONVOLATILE_CONTEXT_సూచికలు_2, *PKNONVOLATILE_CONTEXT_సూచికలు;
#అయితే_ముగింపు /* defined(__x86_64) */

    రకనిర్వచనం PVOID PACCESS_TOKEN;
    రకనిర్వచనం PVOID PSECURITY_DESCRIPTOR;
    రకనిర్వచనం PVOID PSID;

    రకనిర్వచనం DWORD ACCESS_ముసుగు;
    రకనిర్వచనం ACCESS_ముసుగు *PACCESS_ముసుగు;

#నిర్వచించు DELETE (0x00010000L)
#నిర్వచించు READ_CONTROL (0x00020000L)
#నిర్వచించు WRITE_DAC (0x00040000L)
#నిర్వచించు WRITE_OWNER (0x00080000L)
#నిర్వచించు SYNCHRONIZE (0x00100000L)

#నిర్వచించు STANDARD_RIGHTS_REQUIRED (0x000F0000L)
#నిర్వచించు STANDARD_RIGHTS_READ (READ_CONTROL)
#నిర్వచించు STANDARD_RIGHTS_WRITE (READ_CONTROL)
#నిర్వచించు STANDARD_RIGHTS_EXECUTE (READ_CONTROL)
#నిర్వచించు STANDARD_RIGHTS_ALL (0x001F0000L)

#నిర్వచించు SPECIFIC_RIGHTS_ALL (0x0000FFFFL)

#నిర్వచించు ACCESS_SYSTEM_SECURITY (0x01000000L)

#నిర్వచించు గరిష్ఠ_ALLOWED (0x02000000L)

#నిర్వచించు GENERIC_READ (0x80000000L)
#నిర్వచించు GENERIC_WRITE (0x40000000L)
#నిర్వచించు GENERIC_EXECUTE (0x20000000L)
#నిర్వచించు GENERIC_ALL (0x10000000L)

    రకనిర్వచనం నిర్మాణం _GENERIC_MAPPING {
      ACCESS_ముసుగు GenericRead;
      ACCESS_ముసుగు GenericWrite;
      ACCESS_ముసుగు GenericExecute;
      ACCESS_ముసుగు GenericAll;
    } GENERIC_MAPPING;
    రకనిర్వచనం GENERIC_MAPPING *PGENERIC_MAPPING;

#అన్తర్భావ <pshpack4.h>

    రకనిర్వచనం నిర్మాణం LUID_AND_లక్షణాలు {
      LUID Luid;
      DWORD లక్షణాలు;
    } LUID_AND_లక్షణాలు_2,*PLUID_AND_లక్షణాలు;
    రకనిర్వచనం LUID_AND_లక్షణాలు_2 LUID_AND_లక్షణాలు_ARRAY[ANYSIZE_ARRAY];
    రకనిర్వచనం LUID_AND_లక్షణాలు_ARRAY *PLUID_AND_లక్షణాలు_ARRAY;

#అన్తర్భావ <poppack.h>

#నిర్వచితం_కాకపోతే SID_IDENTIFIER_AUTHORITY_DEFINED
#నిర్వచించు SID_IDENTIFIER_AUTHORITY_DEFINED
    రకనిర్వచనం నిర్మాణం _SID_IDENTIFIER_AUTHORITY {
      BYTE విలువ_3[6];
    } SID_IDENTIFIER_AUTHORITY,*PSID_IDENTIFIER_AUTHORITY;
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే SID_DEFINED
#నిర్వచించు SID_DEFINED
    రకనిర్వచనం నిర్మాణం _SID {
      BYTE Revision;
      BYTE Sub_Authority_లెక్క;
      SID_IDENTIFIER_AUTHORITY IdentifierAuthority;
      DWORD SubAuthority[ANYSIZE_ARRAY];
    } SID,*PISID;
#అయితే_ముగింపు

#నిర్వచించు SID_REVISION (1)
#నిర్వచించు SID_MAX_SUB_AUTHORITIES (15)
#నిర్వచించు SID_RECOMMENDED_SUB_AUTHORITIES (1)

#నిర్వచించు SECURITY_MAX_SID_కొలత (పరిమాణం(SID) - పరిమాణం(DWORD) + (SID_MAX_SUB_AUTHORITIES *పరిమాణం(DWORD)))

    రకనిర్వచనం గణన _SID_NAME_USE {
      SidTypeUser = 1,Sid_Type_సమూహం,SidTypeDomain,SidTypeAlias,Sid_Type_Well_తెలిసిన_సమూహం,SidTypeDeletedAccount,SidTypeInvalid,SidTypeUnknown,SidTypeComputer
    } SID_NAME_USE,*PSID_NAME_USE;

    రకనిర్వచనం నిర్మాణం SID_AND_లక్షణాలు {
      PSID Sid;
      DWORD లక్షణాలు;
    } SID_AND_లక్షణాలు_2,*PSID_AND_లక్షణాలు;

    రకనిర్వచనం SID_AND_లక్షణాలు_2 SID_AND_లక్షణాలు_ARRAY[ANYSIZE_ARRAY];
    రకనిర్వచనం SID_AND_లక్షణాలు_ARRAY *PSID_AND_లక్షణాలు_ARRAY;

#నిర్వచించు SECURITY_NULL_SID_AUTHORITY {0,0,0,0,0,0}
#నిర్వచించు SECURITY_WORLD_SID_AUTHORITY {0,0,0,0,0,1}
#నిర్వచించు SECURITY_LOCAL_SID_AUTHORITY {0,0,0,0,0,2}
#నిర్వచించు SECURITY_CREATOR_SID_AUTHORITY {0,0,0,0,0,3}
#నిర్వచించు SECURITY_NON_UNIQUE_AUTHORITY {0,0,0,0,0,4}
#నిర్వచించు SECURITY_RESOURCE_MANAGER_AUTHORITY {0,0,0,0,0,9}

#నిర్వచించు SECURITY_NULL_RID (0x00000000L)
#నిర్వచించు SECURITY_WORLD_RID (0x00000000L)
#నిర్వచించు SECURITY_LOCAL_RID (0x00000000L)

#నిర్వచించు SECURITY_CREATOR_OWNER_RID (0x00000000L)
#నిర్వచించు SECURITY_CREATOR_సమూహం_RID (0x00000001L)

#నిర్వచించు SECURITY_CREATOR_OWNER_SERVER_RID (0x00000002L)
#నిర్వచించు SECURITY_CREATOR_సమూహం_SERVER_RID (0x00000003L)

#నిర్వచించు SECURITY_NT_AUTHORITY {0,0,0,0,0,5}

#నిర్వచించు SECURITY_DIALUP_RID (0x00000001L)
#నిర్వచించు SECURITY_జాలం_RID (0x00000002L)
#నిర్వచించు SECURITY_BATCH_RID (0x00000003L)
#నిర్వచించు SECURITY_INTERACTIVE_RID (0x00000004L)
#నిర్వచించు SECURITY_LOGON_IDS_RID (0x00000005L)
#నిర్వచించు SECURITY_LOGON_IDS_RID_లెక్క (3L)
#నిర్వచించు SECURITY_SERVICE_RID (0x00000006L)
#నిర్వచించు SECURITY_ANONYMOUS_LOGON_RID (0x00000007L)
#నిర్వచించు SECURITY_PROXY_RID (0x00000008L)
#నిర్వచించు SECURITY_ENTERPRISE_CONTROLLERS_RID (0x00000009L)
#నిర్వచించు SECURITY_SERVER_LOGON_RID SECURITY_ENTERPRISE_CONTROLLERS_RID
#నిర్వచించు SECURITY_PRINCIPAL_SELF_RID (0x0000000AL)
#నిర్వచించు SECURITY_AUTHENTICATED_USER_RID (0x0000000BL)
#నిర్వచించు SECURITY_RESTRICTED_సంకేతం_RID (0x0000000CL)
#నిర్వచించు SECURITY_TERMINAL_SERVER_RID (0x0000000DL)
#నిర్వచించు SECURITY_REMOTE_LOGON_RID (0x0000000EL)
#నిర్వచించు SECURITY_THIS_ORGANIZATION_RID (0x0000000FL)
#నిర్వచించు SECURITY_IUSER_RID (0x00000011L)

#నిర్వచించు SECURITY_LOCAL_SYSTEM_RID (0x00000012L)
#నిర్వచించు SECURITY_LOCAL_SERVICE_RID (0x00000013L)
#నిర్వచించు SECURITY_జాలం_SERVICE_RID (0x00000014L)

#నిర్వచించు SECURITY_NT_NON_UNIQUE (0x00000015L)
#నిర్వచించు SECURITY_NT_NON_UNIQUE_SUB_AUTH_లెక్క (3L)

#నిర్వచించు SECURITY_ENTERPRISE_READONLY_CONTROLLERS_RID (0x00000016L)

#నిర్వచించు SECURITY_BUILTIN_DOMAIN_RID (0x00000020L)
#నిర్వచించు SECURITY_WRITE_RESTRICTED_సంకేతం_RID (0x00000021L)

#నిర్వచించు SECURITY_PACKAGE_పునాది_RID (0x00000040L)
#నిర్వచించు SECURITY_PACKAGE_RID_లెక్క (2L)
#నిర్వచించు SECURITY_PACKAGE_NTLM_RID (0x0000000AL)
#నిర్వచించు SECURITY_PACKAGE_SCHANNEL_RID (0x0000000EL)
#నిర్వచించు SECURITY_PACKAGE_DIGEST_RID (0x00000015L)

#నిర్వచించు SECURITY_SERVICE_ID_పునాది_RID (0x00000050L)
#నిర్వచించు SECURITY_SERVICE_ID_RID_లెక్క (6L)

#నిర్వచించు SECURITY_RESERVED_ID_పునాది_RID (0x00000051L)

#నిర్వచించు SECURITY_MAX_ALWAYS_FILTERED (0x000003E7L)
#నిర్వచించు SECURITY_MIN_NEVER_FILTERED (0x000003E8L)

#నిర్వచించు SECURITY_OTHER_ORGANIZATION_RID (0x000003E8L)

#నిర్వచించు FOREST_USER_RID_MAX (0x000001F3L)

#నిర్వచించు DOMAIN_USER_RID_ADMIN (0x000001F4L)
#నిర్వచించు DOMAIN_USER_RID_GUEST (0x000001F5L)
#నిర్వచించు DOMAIN_USER_RID_KRBTGT (0x000001F6L)

#నిర్వచించు DOMAIN_USER_RID_MAX (0x000003E7L)

#నిర్వచించు DOMAIN_సమూహం_RID_ADMINS (0x00000200L)
#నిర్వచించు DOMAIN_సమూహం_RID_USERS (0x00000201L)
#నిర్వచించు DOMAIN_సమూహం_RID_GUESTS (0x00000202L)
#నిర్వచించు DOMAIN_సమూహం_RID_COMPUTERS (0x00000203L)
#నిర్వచించు DOMAIN_సమూహం_RID_CONTROLLERS (0x00000204L)
#నిర్వచించు DOMAIN_సమూహం_RID_CERT_ADMINS (0x00000205L)
#నిర్వచించు DOMAIN_సమూహం_RID_SCHEMA_ADMINS (0x00000206L)
#నిర్వచించు DOMAIN_సమూహం_RID_ENTERPRISE_ADMINS (0x00000207L)
#నిర్వచించు DOMAIN_సమూహం_RID_POLICY_ADMINS (0x00000208L)
#నిర్వచించు DOMAIN_సమూహం_RID_READONLY_CONTROLLERS (0x00000209L)

#నిర్వచించు DOMAIN_ALIAS_RID_ADMINS (0x00000220L)
#నిర్వచించు DOMAIN_ALIAS_RID_USERS (0x00000221L)
#నిర్వచించు DOMAIN_ALIAS_RID_GUESTS (0x00000222L)
#నిర్వచించు DOMAIN_ALIAS_RID_POWER_USERS (0x00000223L)

#నిర్వచించు DOMAIN_ALIAS_RID_ACCOUNT_OPS (0x00000224L)
#నిర్వచించు DOMAIN_ALIAS_RID_SYSTEM_OPS (0x00000225L)
#నిర్వచించు DOMAIN_ALIAS_RID_PRINT_OPS (0x00000226L)
#నిర్వచించు DOMAIN_ALIAS_RID_BACKUP_OPS (0x00000227L)

#నిర్వచించు DOMAIN_ALIAS_RID_REPLICATOR (0x00000228L)
#నిర్వచించు DOMAIN_ALIAS_RID_RAS_SERVERS (0x00000229L)
#నిర్వచించు DOMAIN_ALIAS_RID_PREW2KCOMPACCESS (0x0000022AL)
#నిర్వచించు DOMAIN_ALIAS_RID_REMOTE_DESKTOP_USERS (0x0000022BL)
#నిర్వచించు DOMAIN_ALIAS_RID_జాలం_CONFIGURATION_OPS (0x0000022CL)
#నిర్వచించు DOMAIN_ALIAS_RID_INCOMING_FOREST_TRUST_BUILDERS (0x0000022DL)

#నిర్వచించు DOMAIN_ALIAS_RID_MONITORING_USERS (0x0000022EL)
#నిర్వచించు DOMAIN_ALIAS_RID_LOGGING_USERS (0x0000022FL)
#నిర్వచించు DOMAIN_ALIAS_RID_AUTHORIZATIONACCESS (0x00000230L)
#నిర్వచించు DOMAIN_ALIAS_RID_TS_LICENSE_SERVERS (0x00000231L)
#నిర్వచించు DOMAIN_ALIAS_RID_DCOM_USERS (0x00000232L)

#నిర్వచించు DOMAIN_ALIAS_RID_IUSERS (0x00000238L)
#నిర్వచించు DOMAIN_ALIAS_RID_CRYPTO_OPERATORS (0x00000239L)
#నిర్వచించు DOMAIN_ALIAS_RID_CACHEABLE_PRINCIPALS_సమూహం (0x0000023BL)
#నిర్వచించు DOMAIN_ALIAS_RID_NON_CACHEABLE_PRINCIPALS_సమూహం (0x0000023CL)
#నిర్వచించు DOMAIN_ALIAS_RID_EVENT_LOG_READERS_సమూహం (0x0000023DL)

#నిర్వచించు SECURITY_MANDATORY_LABEL_AUTHORITY {0,0,0,0,0,16}
#నిర్వచించు SECURITY_MANDATORY_UNTRUSTED_RID (0x00000000L)
#నిర్వచించు SECURITY_MANDATORY_దిగువ_RID (0x00001000L)
#నిర్వచించు SECURITY_MANDATORY_MEDIUM_RID (0x00002000L)
#నిర్వచించు SECURITY_MANDATORY_ఎగువ_RID (0x00003000L)
#నిర్వచించు SECURITY_MANDATORY_SYSTEM_RID (0x00004000L)
#నిర్వచించు SECURITY_MANDATORY_PROTECTED_PROCESS_RID (0x00005000L)

#నిర్వచించు SECURITY_MANDATORY_గరిష్ఠ_USER_RID SECURITY_MANDATORY_SYSTEM_RID

#నిర్వచించు MANDATORY_LEVEL_గమ్యం_MANDATORY_RID(IL) (IL * 0x1000)

    రకనిర్వచనం గణన {
      WinNullSid = 0,WinWorldSid = 1,WinLocalSid = 2,WinCreatorOwnerSid = 3,Win_Creator_సమూహం_Sid = 4,WinCreatorOwnerServerSid = 5,Win_Creator_సమూహం_Server_Sid = 6,WinNtAuthoritySid = 7,WinDialupSid = 8,Win_జాలం_Sid = 9,WinBatchSid = 10,WinInteractiveSid = 11,WinServiceSid = 12,WinAnonymousSid = 13,WinProxySid = 14,WinEnterpriseControllersSid = 15,WinSelfSid = 16,WinAuthenticatedUserSid = 17,Win_Restricted_సంకేతం_Sid = 18,WinTerminalServerSid = 19,WinRemoteLogonIdSid = 20,WinLogonIdsSid = 21,WinLocalSystemSid = 22,WinLocalServiceSid = 23,Win_జాలం_Service_Sid = 24,WinBuiltinDomainSid = 25,WinBuiltinAdministratorsSid = 26,WinBuiltinUsersSid = 27,WinBuiltinGuestsSid = 28,WinBuiltinPowerUsersSid = 29,WinBuiltinAccountOperatorsSid = 30,WinBuiltinSystemOperatorsSid = 31,WinBuiltinPrintOperatorsSid = 32,WinBuiltinBackupOperatorsSid = 33,WinBuiltinReplicatorSid = 34,WinBuiltinPreWindows2000CompatibleAccessSid = 35,WinBuiltinRemoteDesktopUsersSid = 36,Win_Builtin_జాలం_Configuration_Operators_Sid = 37,WinAccountAdministratorSid = 38,WinAccountGuestSid = 39,WinAccountKrbtgtSid = 40,WinAccountDomainAdminsSid = 41,WinAccountDomainUsersSid = 42,WinAccountDomainGuestsSid = 43,WinAccountComputersSid = 44,WinAccountControllersSid = 45,WinAccountCertAdminsSid = 46,WinAccountSchemaAdminsSid = 47,WinAccountEnterpriseAdminsSid = 48,WinAccountPolicyAdminsSid = 49,WinAccountRasAndIasServersSid = 50,WinNTLMAuthenticationSid = 51,WinDigestAuthenticationSid = 52,WinSChannelAuthenticationSid = 53,WinThisOrganizationSid = 54,WinOtherOrganizationSid = 55,WinBuiltinIncomingForestTrustBuildersSid = 56,WinBuiltinPerfMonitoringUsersSid = 57,WinBuiltinPerfLoggingUsersSid = 58,WinBuiltinAuthorizationAccessSid = 59,WinBuiltinTerminalServerLicenseServersSid = 60,WinBuiltinDCOMUsersSid = 61
    } WELL_తెలిసిన_SID_TYPE;

#నిర్వచించు SYSTEM_LUID { 0x3E7,0x0 }
#నిర్వచించు ANONYMOUS_LOGON_LUID { 0x3e6,0x0 }
#నిర్వచించు LOCALSERVICE_LUID { 0x3e5,0x0 }
#నిర్వచించు NETWORKSERVICE_LUID { 0x3e4,0x0 }
#నిర్వచించు IUSER_LUID { 0x3e3, 0x0 }

#నిర్వచించు SE_సమూహం_MANDATORY (0x00000001L)
#నిర్వచించు SE_సమూహం_ENABLED_BY_DEFAULT (0x00000002L)
#నిర్వచించు SE_సమూహం_ENABLED (0x00000004L)
#నిర్వచించు SE_సమూహం_OWNER (0x00000008L)
#నిర్వచించు SE_సమూహం_USE_FOR_DENY_ONLY (0x00000010L)
#నిర్వచించు SE_సమూహం_INTEGRITY (0x00000020L)
#నిర్వచించు SE_సమూహం_INTEGRITY_ENABLED (0x00000040L)
#నిర్వచించు SE_సమూహం_LOGON_ID (0xC0000000L)
#నిర్వచించు SE_సమూహం_RESOURCE (0x20000000L)

#నిర్వచించు ACL_REVISION (2)
#నిర్వచించు ACL_REVISION_DS (4)

#నిర్వచించు ACL_REVISION1 (1)
#నిర్వచించు MIN_ACL_REVISION ACL_REVISION2
#నిర్వచించు ACL_REVISION2 (2)
#నిర్వచించు ACL_REVISION3 (3)
#నిర్వచించు ACL_REVISION4 (4)
#నిర్వచించు MAX_ACL_REVISION ACL_REVISION4

    రకనిర్వచనం నిర్మాణం _ACL {
      BYTE AclRevision;
      BYTE Sbz1;
      మాట_3 Acl_కొలత;
      మాట_3 Ace_లెక్క;
      మాట_3 Sbz2;
    } ACL;
    రకనిర్వచనం ACL *PACL;

    రకనిర్వచనం నిర్మాణం ACE_శీర్షిక {
      BYTE AceType;
      BYTE AceFlags;
      మాట_3 Ace_కొలత;
    } ACE_శీర్షిక_2;
    రకనిర్వచనం ACE_శీర్షిక_2 *PACE_శీర్షిక;

#నిర్వచించు ACCESS_MIN_MS_ACE_TYPE (0x0)
#నిర్వచించు ACCESS_ALLOWED_ACE_TYPE (0x0)
#నిర్వచించు ACCESS_DENIED_ACE_TYPE (0x1)
#నిర్వచించు SYSTEM_AUDIT_ACE_TYPE (0x2)
#నిర్వచించు SYSTEM_ALARM_ACE_TYPE (0x3)
#నిర్వచించు ACCESS_MAX_MS_V2_ACE_TYPE (0x3)

#నిర్వచించు ACCESS_ALLOWED_COMPOUND_ACE_TYPE (0x4)
#నిర్వచించు ACCESS_MAX_MS_V3_ACE_TYPE (0x4)

#నిర్వచించు ACCESS_MIN_MS_OBJECT_ACE_TYPE (0x5)
#నిర్వచించు ACCESS_ALLOWED_OBJECT_ACE_TYPE (0x5)
#నిర్వచించు ACCESS_DENIED_OBJECT_ACE_TYPE (0x6)
#నిర్వచించు SYSTEM_AUDIT_OBJECT_ACE_TYPE (0x7)
#నిర్వచించు SYSTEM_ALARM_OBJECT_ACE_TYPE (0x8)
#నిర్వచించు ACCESS_MAX_MS_OBJECT_ACE_TYPE (0x8)

#నిర్వచించు ACCESS_MAX_MS_V4_ACE_TYPE (0x8)
#నిర్వచించు ACCESS_MAX_MS_ACE_TYPE (0x8)

#నిర్వచించు ACCESS_ALLOWED_CALLBACK_ACE_TYPE (0x9)
#నిర్వచించు ACCESS_DENIED_CALLBACK_ACE_TYPE (0xA)
#నిర్వచించు ACCESS_ALLOWED_CALLBACK_OBJECT_ACE_TYPE (0xB)
#నిర్వచించు ACCESS_DENIED_CALLBACK_OBJECT_ACE_TYPE (0xC)
#నిర్వచించు SYSTEM_AUDIT_CALLBACK_ACE_TYPE (0xD)
#నిర్వచించు SYSTEM_ALARM_CALLBACK_ACE_TYPE (0xE)
#నిర్వచించు SYSTEM_AUDIT_CALLBACK_OBJECT_ACE_TYPE (0xF)
#నిర్వచించు SYSTEM_ALARM_CALLBACK_OBJECT_ACE_TYPE (0x10)

#నిర్వచించు SYSTEM_MANDATORY_LABEL_ACE_TYPE (0x11)
#నిర్వచించు ACCESS_MAX_MS_V5_ACE_TYPE (0x11)

#నిర్వచించు OBJECT_INHERIT_ACE (0x1)
#నిర్వచించు CONTAINER_INHERIT_ACE (0x2)
#నిర్వచించు NO_PROPAGATE_INHERIT_ACE (0x4)
#నిర్వచించు INHERIT_ONLY_ACE (0x8)
#నిర్వచించు INHERITED_ACE (0x10)
#నిర్వచించు VALID_INHERIT_FLAGS (0x1F)

#నిర్వచించు SUCCESSFUL_ACCESS_ACE_FLAG (0x40)
#నిర్వచించు FAILED_ACCESS_ACE_FLAG (0x80)

    రకనిర్వచనం నిర్మాణం _ACCESS_ALLOWED_ACE {
      ACE_శీర్షిక_2 శీర్షిక_2;
      ACCESS_ముసుగు ముసుగు_3;
      DWORD Sid_ప్రారంభం;
    } ACCESS_ALLOWED_ACE;

    రకనిర్వచనం ACCESS_ALLOWED_ACE *PACCESS_ALLOWED_ACE;

    రకనిర్వచనం నిర్మాణం _ACCESS_DENIED_ACE {
      ACE_శీర్షిక_2 శీర్షిక_2;
      ACCESS_ముసుగు ముసుగు_3;
      DWORD Sid_ప్రారంభం;
    } ACCESS_DENIED_ACE;
    రకనిర్వచనం ACCESS_DENIED_ACE *PACCESS_DENIED_ACE;

    రకనిర్వచనం నిర్మాణం _SYSTEM_AUDIT_ACE {
      ACE_శీర్షిక_2 శీర్షిక_2;
      ACCESS_ముసుగు ముసుగు_3;
      DWORD Sid_ప్రారంభం;
    } SYSTEM_AUDIT_ACE;
    రకనిర్వచనం SYSTEM_AUDIT_ACE *PSYSTEM_AUDIT_ACE;

    రకనిర్వచనం నిర్మాణం _SYSTEM_ALARM_ACE {
      ACE_శీర్షిక_2 శీర్షిక_2;
      ACCESS_ముసుగు ముసుగు_3;
      DWORD Sid_ప్రారంభం;
    } SYSTEM_ALARM_ACE;
    రకనిర్వచనం SYSTEM_ALARM_ACE *PSYSTEM_ALARM_ACE;

    రకనిర్వచనం నిర్మాణం _ACCESS_ALLOWED_OBJECT_ACE {
      ACE_శీర్షిక_2 శీర్షిక_2;
      ACCESS_ముసుగు ముసుగు_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_ప్రారంభం;
    } ACCESS_ALLOWED_OBJECT_ACE,*PACCESS_ALLOWED_OBJECT_ACE;

    రకనిర్వచనం నిర్మాణం _ACCESS_DENIED_OBJECT_ACE {
      ACE_శీర్షిక_2 శీర్షిక_2;
      ACCESS_ముసుగు ముసుగు_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_ప్రారంభం;
    } ACCESS_DENIED_OBJECT_ACE,*PACCESS_DENIED_OBJECT_ACE;

    రకనిర్వచనం నిర్మాణం _SYSTEM_AUDIT_OBJECT_ACE {
      ACE_శీర్షిక_2 శీర్షిక_2;
      ACCESS_ముసుగు ముసుగు_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_ప్రారంభం;
    } SYSTEM_AUDIT_OBJECT_ACE,*PSYSTEM_AUDIT_OBJECT_ACE;

    రకనిర్వచనం నిర్మాణం _SYSTEM_ALARM_OBJECT_ACE {
      ACE_శీర్షిక_2 శీర్షిక_2;
      ACCESS_ముసుగు ముసుగు_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_ప్రారంభం;
    } SYSTEM_ALARM_OBJECT_ACE,*PSYSTEM_ALARM_OBJECT_ACE;

    రకనిర్వచనం నిర్మాణం _ACCESS_ALLOWED_CALLBACK_ACE {
      ACE_శీర్షిక_2 శీర్షిక_2;
      ACCESS_ముసుగు ముసుగు_3;
      DWORD Sid_ప్రారంభం;

    } ACCESS_ALLOWED_CALLBACK_ACE,*PACCESS_ALLOWED_CALLBACK_ACE;

    రకనిర్వచనం నిర్మాణం _ACCESS_DENIED_CALLBACK_ACE {
      ACE_శీర్షిక_2 శీర్షిక_2;
      ACCESS_ముసుగు ముసుగు_3;
      DWORD Sid_ప్రారంభం;

    } ACCESS_DENIED_CALLBACK_ACE,*PACCESS_DENIED_CALLBACK_ACE;

    రకనిర్వచనం నిర్మాణం _SYSTEM_AUDIT_CALLBACK_ACE {
      ACE_శీర్షిక_2 శీర్షిక_2;
      ACCESS_ముసుగు ముసుగు_3;
      DWORD Sid_ప్రారంభం;

    } SYSTEM_AUDIT_CALLBACK_ACE,*PSYSTEM_AUDIT_CALLBACK_ACE;

    రకనిర్వచనం నిర్మాణం _SYSTEM_ALARM_CALLBACK_ACE {
      ACE_శీర్షిక_2 శీర్షిక_2;
      ACCESS_ముసుగు ముసుగు_3;
      DWORD Sid_ప్రారంభం;

    } SYSTEM_ALARM_CALLBACK_ACE,*PSYSTEM_ALARM_CALLBACK_ACE;

    రకనిర్వచనం నిర్మాణం _ACCESS_ALLOWED_CALLBACK_OBJECT_ACE {
      ACE_శీర్షిక_2 శీర్షిక_2;
      ACCESS_ముసుగు ముసుగు_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_ప్రారంభం;

    } ACCESS_ALLOWED_CALLBACK_OBJECT_ACE,*PACCESS_ALLOWED_CALLBACK_OBJECT_ACE;

    రకనిర్వచనం నిర్మాణం _ACCESS_DENIED_CALLBACK_OBJECT_ACE {
      ACE_శీర్షిక_2 శీర్షిక_2;
      ACCESS_ముసుగు ముసుగు_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_ప్రారంభం;

    } ACCESS_DENIED_CALLBACK_OBJECT_ACE,*PACCESS_DENIED_CALLBACK_OBJECT_ACE;

    రకనిర్వచనం నిర్మాణం _SYSTEM_AUDIT_CALLBACK_OBJECT_ACE {
      ACE_శీర్షిక_2 శీర్షిక_2;
      ACCESS_ముసుగు ముసుగు_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_ప్రారంభం;

    } SYSTEM_AUDIT_CALLBACK_OBJECT_ACE,*PSYSTEM_AUDIT_CALLBACK_OBJECT_ACE;

    రకనిర్వచనం నిర్మాణం _SYSTEM_ALARM_CALLBACK_OBJECT_ACE {
      ACE_శీర్షిక_2 శీర్షిక_2;
      ACCESS_ముసుగు ముసుగు_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD Sid_ప్రారంభం;

    } SYSTEM_ALARM_CALLBACK_OBJECT_ACE,*PSYSTEM_ALARM_CALLBACK_OBJECT_ACE;

#నిర్వచించు ACE_OBJECT_TYPE_PRESENT 0x1
#నిర్వచించు ACE_INHERITED_OBJECT_TYPE_PRESENT 0x2

    రకనిర్వచనం గణన _ACL_INFORMATION_CLASS {
      AclRevisionInformation = 1,Acl_కొలత_Information
    } ACL_INFORMATION_CLASS;

    రకనిర్వచనం నిర్మాణం _ACL_REVISION_INFORMATION {
      DWORD AclRevision;
    } ACL_REVISION_INFORMATION;
    రకనిర్వచనం ACL_REVISION_INFORMATION *PACL_REVISION_INFORMATION;

    రకనిర్వచనం నిర్మాణం ACL_కొలత_INFORMATION {
      DWORD Ace_లెక్క;
      DWORD Acl_బైట్లు_లోపల_Use;
      DWORD Acl_బైట్లు_Free;
    } ACL_కొలత_INFORMATION_2;
    రకనిర్వచనం ACL_కొలత_INFORMATION_2 *PACL_కొలత_INFORMATION;

#నిర్వచించు SECURITY_DESCRIPTOR_REVISION (1)
#నిర్వచించు SECURITY_DESCRIPTOR_REVISION1 (1)

#నిర్వచించు SECURITY_DESCRIPTOR_MIN_నిడివి (పరిమాణం(SECURITY_DESCRIPTOR))

    రకనిర్వచనం మాట_3 SECURITY_DESCRIPTOR_CONTROL,*PSECURITY_DESCRIPTOR_CONTROL;

#నిర్వచించు SE_OWNER_DEFAULTED (0x0001)
#నిర్వచించు SE_సమూహం_DEFAULTED (0x0002)
#నిర్వచించు SE_DACL_PRESENT (0x0004)
#నిర్వచించు SE_DACL_DEFAULTED (0x0008)
#నిర్వచించు SE_SACL_PRESENT (0x0010)
#నిర్వచించు SE_SACL_DEFAULTED (0x0020)
#నిర్వచించు SE_DACL_AUTO_INHERIT_REQ (0x0100)
#నిర్వచించు SE_SACL_AUTO_INHERIT_REQ (0x0200)
#నిర్వచించు SE_DACL_AUTO_INHERITED (0x0400)
#నిర్వచించు SE_SACL_AUTO_INHERITED (0x0800)
#నిర్వచించు SE_DACL_PROTECTED (0x1000)
#నిర్వచించు SE_SACL_PROTECTED (0x2000)
#నిర్వచించు SE_RM_CONTROL_VALID (0x4000)
#నిర్వచించు SE_SELF_RELATIVE (0x8000)

    రకనిర్వచనం నిర్మాణం _SECURITY_DESCRIPTOR_RELATIVE {
      BYTE Revision;
      BYTE Sbz1;
      SECURITY_DESCRIPTOR_CONTROL Control;
      DWORD Owner;
      DWORD సమూహం_2;
      DWORD Sacl;
      DWORD Dacl;
    } SECURITY_DESCRIPTOR_RELATIVE,*PISECURITY_DESCRIPTOR_RELATIVE;

    రకనిర్వచనం నిర్మాణం _SECURITY_DESCRIPTOR {
      BYTE Revision;
      BYTE Sbz1;
      SECURITY_DESCRIPTOR_CONTROL Control;
      PSID Owner;
      PSID సమూహం_2;
      PACL Sacl;
      PACL Dacl;

    } SECURITY_DESCRIPTOR,*PISECURITY_DESCRIPTOR;

    రకనిర్వచనం నిర్మాణం _OBJECT_TYPE_LIST {
      మాట_3 Level;
      మాట_3 Sbz;
      GUID *ObjectType;
    } OBJECT_TYPE_LIST,*POBJECT_TYPE_LIST;

#నిర్వచించు ACCESS_OBJECT_GUID 0
#నిర్వచించు ACCESS_PROPERTY_సమితి_GUID 1
#నిర్వచించు ACCESS_PROPERTY_GUID 2

#నిర్వచించు ACCESS_MAX_LEVEL 4

    రకనిర్వచనం గణన _AUDIT_EVENT_TYPE {
      AuditEventObjectAccess,AuditEventDirectoryServiceAccess
    } AUDIT_EVENT_TYPE,*PAUDIT_EVENT_TYPE;

#నిర్వచించు AUDIT_ALLOW_NO_PRIVILEGE 0x1

#నిర్వచించు ACCESS_DS_ఆధారం_A "DS"
#నిర్వచించు ACCESS_DS_ఆధారం_W L"DS"
#నిర్వచించు ACCESS_DS_OBJECT_TYPE_NAME_A "Directory Service Object"
#నిర్వచించు ACCESS_DS_OBJECT_TYPE_NAME_W L"Directory Service Object"

#నిర్వచించు SE_PRIVILEGE_ENABLED_BY_DEFAULT (0x00000001L)
#నిర్వచించు SE_PRIVILEGE_ENABLED (0x00000002L)
#నిర్వచించు SE_PRIVILEGE_REMOVED (0X00000004L)
#నిర్వచించు SE_PRIVILEGE_వాడిన_FOR_ACCESS (0x80000000L)

#నిర్వచించు PRIVILEGE_సమితి_ALL_NECESSARY (1)

    రకనిర్వచనం నిర్మాణం PRIVILEGE_సమితి {
      DWORD Privilege_లెక్క;
      DWORD Control;
      LUID_AND_లక్షణాలు_2 Privilege[ANYSIZE_ARRAY];
    } PRIVILEGE_సమితి_2,*PPRIVILEGE_సమితి;

#నిర్వచించు SE_CREATE_TOKEN_NAME పాఠ్యం_3("SeCreateTokenPrivilege")
#నిర్వచించు SE_ASSIGNPRIMARYTOKEN_NAME పాఠ్యం_3("SeAssignPrimaryTokenPrivilege")
#నిర్వచించు SE_తాళం_జ్ఞాపకం_NAME పాఠ్యం_3("SeLockMemoryPrivilege")
#నిర్వచించు SE_INCREASE_QUOTA_NAME పాఠ్యం_3("SeIncreaseQuotaPrivilege")
#నిర్వచించు SE_UNSOLICITED_ఆదానం_NAME పాఠ్యం_3("SeUnsolicitedInputPrivilege")
#నిర్వచించు SE_MACHINE_ACCOUNT_NAME పాఠ్యం_3("SeMachineAccountPrivilege")
#నిర్వచించు SE_TCB_NAME పాఠ్యం_3("SeTcbPrivilege")
#నిర్వచించు SE_SECURITY_NAME పాఠ్యం_3("SeSecurityPrivilege")
#నిర్వచించు SE_TAKE_OWNERSHIP_NAME పాఠ్యం_3("SeTakeOwnershipPrivilege")
#నిర్వచించు SE_ఎక్కించు_DRIVER_NAME పాఠ్యం_3("SeLoadDriverPrivilege")
#నిర్వచించు SE_SYSTEM_PROFILE_NAME పాఠ్యం_3("SeSystemProfilePrivilege")
#నిర్వచించు SE_SYSTEMTIME_NAME పాఠ్యం_3("SeSystemtimePrivilege")
#నిర్వచించు SE_PROF_SINGLE_PROCESS_NAME పాఠ్యం_3("SeProfileSingleProcessPrivilege")
#నిర్వచించు SE_INC_పునాది_ప్రాధాన్యత_NAME పాఠ్యం_3("SeIncreaseBasePriorityPrivilege")
#నిర్వచించు SE_CREATE_PAGEFILE_NAME పాఠ్యం_3("SeCreatePagefilePrivilege")
#నిర్వచించు SE_CREATE_PERMANENT_NAME పాఠ్యం_3("SeCreatePermanentPrivilege")
#నిర్వచించు SE_BACKUP_NAME పాఠ్యం_3("SeBackupPrivilege")
#నిర్వచించు SE_RESTORE_NAME పాఠ్యం_3("SeRestorePrivilege")
#నిర్వచించు SE_SHUTDOWN_NAME పాఠ్యం_3("SeShutdownPrivilege")
#నిర్వచించు SE_DEBUG_NAME పాఠ్యం_3("SeDebugPrivilege")
#నిర్వచించు SE_AUDIT_NAME పాఠ్యం_3("SeAuditPrivilege")
#నిర్వచించు SE_SYSTEM_ENVIRONMENT_NAME పాఠ్యం_3("SeSystemEnvironmentPrivilege")
#నిర్వచించు SE_CHANGE_NOTIFY_NAME పాఠ్యం_3("SeChangeNotifyPrivilege")
#నిర్వచించు SE_REMOTE_SHUTDOWN_NAME పాఠ్యం_3("SeRemoteShutdownPrivilege")
#నిర్వచించు SE_UNDOCK_NAME పాఠ్యం_3("SeUndockPrivilege")
#నిర్వచించు SE_SYNC_AGENT_NAME పాఠ్యం_3("SeSyncAgentPrivilege")
#నిర్వచించు SE_ENABLE_DELEGATION_NAME పాఠ్యం_3("SeEnableDelegationPrivilege")
#నిర్వచించు SE_MANAGE_VOLUME_NAME పాఠ్యం_3("SeManageVolumePrivilege")
#నిర్వచించు SE_IMPERSONATE_NAME పాఠ్యం_3("SeImpersonatePrivilege")
#నిర్వచించు SE_CREATE_GLOBAL_NAME పాఠ్యం_3("SeCreateGlobalPrivilege")

    రకనిర్వచనం గణన _SECURITY_IMPERSONATION_LEVEL {
      SecurityAnonymous,SecurityIdentification,SecurityImpersonation,SecurityDelegation
    } SECURITY_IMPERSONATION_LEVEL,*PSECURITY_IMPERSONATION_LEVEL;

#నిర్వచించు SECURITY_MAX_IMPERSONATION_LEVEL SecurityDelegation
#నిర్వచించు SECURITY_MIN_IMPERSONATION_LEVEL SecurityAnonymous
#నిర్వచించు DEFAULT_IMPERSONATION_LEVEL SecurityImpersonation
#నిర్వచించు VALID_IMPERSONATION_LEVEL(L) (((L) >= SECURITY_MIN_IMPERSONATION_LEVEL) && ((L) <= SECURITY_MAX_IMPERSONATION_LEVEL))

#నిర్వచించు TOKEN_కేటాయించు_PRIMARY (0x0001)
#నిర్వచించు TOKEN_DUPLICATE (0x0002)
#నిర్వచించు TOKEN_IMPERSONATE (0x0004)
#నిర్వచించు TOKEN_QUERY (0x0008)
#నిర్వచించు TOKEN_QUERY_ఆధారం (0x0010)
#నిర్వచించు TOKEN_ADJUST_PRIVILEGES (0x0020)
#నిర్వచించు TOKEN_ADJUST_GROUPS (0x0040)
#నిర్వచించు TOKEN_ADJUST_DEFAULT (0x0080)
#నిర్వచించు TOKEN_ADJUST_SESSIONID (0x0100)

#నిర్వచించు TOKEN_ALL_ACCESS_P (STANDARD_RIGHTS_REQUIRED | TOKEN_కేటాయించు_PRIMARY | TOKEN_DUPLICATE | TOKEN_IMPERSONATE | TOKEN_QUERY | TOKEN_QUERY_ఆధారం | TOKEN_ADJUST_PRIVILEGES | TOKEN_ADJUST_GROUPS | TOKEN_ADJUST_DEFAULT)
#నిర్వచించు TOKEN_ALL_ACCESS (TOKEN_ALL_ACCESS_P | TOKEN_ADJUST_SESSIONID)
#నిర్వచించు TOKEN_READ (STANDARD_RIGHTS_READ | TOKEN_QUERY)

#నిర్వచించు TOKEN_WRITE (STANDARD_RIGHTS_WRITE | TOKEN_ADJUST_PRIVILEGES | TOKEN_ADJUST_GROUPS | TOKEN_ADJUST_DEFAULT)

#నిర్వచించు TOKEN_EXECUTE (STANDARD_RIGHTS_EXECUTE)

    రకనిర్వచనం గణన _TOKEN_TYPE {
      TokenPrimary = 1,TokenImpersonation
    } TOKEN_TYPE;
    రకనిర్వచనం TOKEN_TYPE *PTOKEN_TYPE;

    రకనిర్వచనం గణన _TOKEN_INFORMATION_CLASS {
      TokenUser = 1,TokenGroups,TokenPrivileges,TokenOwner,Token_Primary_సమూహం,TokenDefaultDacl,Token_ఆధారం,TokenType,TokenImpersonationLevel,
      TokenStatistics,TokenRestrictedSids,TokenSessionId,TokenGroupsAndPrivileges,TokenSessionReference,TokenSandBoxInert,TokenAuditPolicy,
      TokenOrigin,MaxTokenInfoClass
    } TOKEN_INFORMATION_CLASS,*PTOKEN_INFORMATION_CLASS;

    రకనిర్వచనం నిర్మాణం _TOKEN_USER {
      SID_AND_లక్షణాలు_2 User;
    } TOKEN_USER,*PTOKEN_USER;

    రకనిర్వచనం నిర్మాణం _TOKEN_GROUPS {
      DWORD సమూహం_లెక్క;
      SID_AND_లక్షణాలు_2 Groups[ANYSIZE_ARRAY];
    } TOKEN_GROUPS,*PTOKEN_GROUPS;

    రకనిర్వచనం నిర్మాణం _TOKEN_PRIVILEGES {
      DWORD Privilege_లెక్క;
      LUID_AND_లక్షణాలు_2 Privileges[ANYSIZE_ARRAY];
    } TOKEN_PRIVILEGES,*PTOKEN_PRIVILEGES;

    రకనిర్వచనం నిర్మాణం _TOKEN_OWNER {
      PSID Owner;
    } TOKEN_OWNER,*PTOKEN_OWNER;

    రకనిర్వచనం నిర్మాణం TOKEN_PRIMARY_సమూహం {
      PSID Primary_సమూహం;
    } TOKEN_PRIMARY_సమూహం_2,*PTOKEN_PRIMARY_సమూహం;

    రకనిర్వచనం నిర్మాణం _TOKEN_DEFAULT_DACL {
      PACL DefaultDacl;
    } TOKEN_DEFAULT_DACL,*PTOKEN_DEFAULT_DACL;

    రకనిర్వచనం నిర్మాణం _TOKEN_GROUPS_AND_PRIVILEGES {
      DWORD Sid_లెక్క;
      DWORD Sid_నిడివి;
      PSID_AND_లక్షణాలు Sids;
      DWORD Restricted_Sid_లెక్క;
      DWORD Restricted_Sid_నిడివి;
      PSID_AND_లక్షణాలు RestrictedSids;
      DWORD Privilege_లెక్క;
      DWORD Privilege_నిడివి;
      PLUID_AND_లక్షణాలు Privileges;
      LUID AuthenticationId;
    } TOKEN_GROUPS_AND_PRIVILEGES,*PTOKEN_GROUPS_AND_PRIVILEGES;

#నిర్వచించు TOKEN_AUDIT_SUCCESS_INCLUDE 0x1
#నిర్వచించు TOKEN_AUDIT_SUCCESS_EXCLUDE 0x2
#నిర్వచించు TOKEN_AUDIT_FAILURE_INCLUDE 0x4
#నిర్వచించు TOKEN_AUDIT_FAILURE_EXCLUDE 0x8

#నిర్వచించు VALID_AUDIT_POLICY_బిట్లు (TOKEN_AUDIT_SUCCESS_INCLUDE | TOKEN_AUDIT_SUCCESS_EXCLUDE | TOKEN_AUDIT_FAILURE_INCLUDE | TOKEN_AUDIT_FAILURE_EXCLUDE)
#నిర్వచించు VALID_TOKEN_AUDIT_POLICY_ELEMENT(P) ((((P).Policy_ముసుగు & ~VALID_AUDIT_POLICY_బిట్లు)==0) && ((P).Category <= AuditEventMaxType))

    రకనిర్వచనం నిర్మాణం _TOKEN_AUDIT_POLICY_ELEMENT {
      DWORD Category;
      DWORD Policy_ముసుగు;
    } TOKEN_AUDIT_POLICY_ELEMENT,*PTOKEN_AUDIT_POLICY_ELEMENT;

    రకనిర్వచనం నిర్మాణం _TOKEN_AUDIT_POLICY {
      DWORD Policy_లెక్క;
      TOKEN_AUDIT_POLICY_ELEMENT Policy[ANYSIZE_ARRAY];
    } TOKEN_AUDIT_POLICY,*PTOKEN_AUDIT_POLICY;

#నిర్వచించు చొప్పున_USER_AUDITING_POLICY_కొలత(p) (పరిమాణం(TOKEN_AUDIT_POLICY) + (((p)->Policy_లెక్క > ANYSIZE_ARRAY) ? (పరిమాణం(TOKEN_AUDIT_POLICY_ELEMENT) *((p)->Policy_లెక్క - ANYSIZE_ARRAY)) : 0))
#నిర్వచించు చొప్పున_USER_AUDITING_POLICY_కొలత_BY_లెక్క(C) (పరిమాణం(TOKEN_AUDIT_POLICY) + (((C) > ANYSIZE_ARRAY) ? (పరిమాణం(TOKEN_AUDIT_POLICY_ELEMENT) *((C) - ANYSIZE_ARRAY)) : 0))

#నిర్వచించు TOKEN_ఆధారం_నిడివి 8

    రకనిర్వచనం నిర్మాణం TOKEN_ఆధారం {
      CHAR ఆధారం_Name[TOKEN_ఆధారం_నిడివి];
      LUID ఆధారం_Identifier;
    } TOKEN_ఆధారం_2,*PTOKEN_ఆధారం;

    రకనిర్వచనం నిర్మాణం _TOKEN_STATISTICS {
      LUID TokenId;
      LUID AuthenticationId;
      LARGE_INTEGER Expiration_సమయం;
      TOKEN_TYPE TokenType;
      SECURITY_IMPERSONATION_LEVEL ImpersonationLevel;
      DWORD DynamicCharged;
      DWORD Dynamic_అందుబాటు;
      DWORD సమూహం_లెక్క;
      DWORD Privilege_లెక్క;
      LUID ModifiedId;
    } TOKEN_STATISTICS,*PTOKEN_STATISTICS;

    రకనిర్వచనం నిర్మాణం _TOKEN_CONTROL {
      LUID TokenId;
      LUID AuthenticationId;
      LUID ModifiedId;
      TOKEN_ఆధారం_2 Token_ఆధారం;
    } TOKEN_CONTROL,*PTOKEN_CONTROL;

    రకనిర్వచనం నిర్మాణం _TOKEN_ORIGIN {
      LUID OriginatingLogonSession;
    } TOKEN_ORIGIN,*PTOKEN_ORIGIN;

#నిర్వచించు SECURITY_DYNAMIC_TRACKING (TRUE)
#నిర్వచించు SECURITY_STATIC_TRACKING (FALSE)

    రకనిర్వచనం BOOLEAN SECURITY_CONTEXT_TRACKING_బహుళకం,*PSECURITY_CONTEXT_TRACKING_బహుళకం;

    రకనిర్వచనం నిర్మాణం SECURITY_QUALITY_యొక్క_SERVICE {
      DWORD నిడివి_2;
      SECURITY_IMPERSONATION_LEVEL ImpersonationLevel;
      SECURITY_CONTEXT_TRACKING_బహుళకం Context_Tracking_బహుళకం;
      BOOLEAN EffectiveOnly;
    } SECURITY_QUALITY_యొక్క_SERVICE_2,*PSECURITY_QUALITY_యొక్క_SERVICE;

    రకనిర్వచనం నిర్మాణం _SE_IMPERSONATION_STATE {
      PACCESS_TOKEN Token;
      BOOLEAN CopyOnOpen;
      BOOLEAN EffectiveOnly;
      SECURITY_IMPERSONATION_LEVEL Level;
    } SE_IMPERSONATION_STATE,*PSE_IMPERSONATION_STATE;

#నిర్వచించు DISABLE_MAX_PRIVILEGE 0x1
#నిర్వచించు SANDBOX_INERT 0x2

    రకనిర్వచనం DWORD SECURITY_INFORMATION,*PSECURITY_INFORMATION;

#నిర్వచించు OWNER_SECURITY_INFORMATION (0x00000001L)
#నిర్వచించు సమూహం_SECURITY_INFORMATION (0x00000002L)
#నిర్వచించు DACL_SECURITY_INFORMATION (0x00000004L)
#నిర్వచించు SACL_SECURITY_INFORMATION (0x00000008L)

#నిర్వచించు PROTECTED_DACL_SECURITY_INFORMATION (0x80000000L)
#నిర్వచించు PROTECTED_SACL_SECURITY_INFORMATION (0x40000000L)
#నిర్వచించు UNPROTECTED_DACL_SECURITY_INFORMATION (0x20000000L)
#నిర్వచించు UNPROTECTED_SACL_SECURITY_INFORMATION (0x10000000L)

#నిర్వచించు PROCESS_TERMINATE (0x0001)
#నిర్వచించు PROCESS_CREATE_THREAD (0x0002)
#నిర్వచించు PROCESS_సమితి_SESSIONID (0x0004)
#నిర్వచించు PROCESS_VM_OPERATION (0x0008)
#నిర్వచించు PROCESS_VM_READ (0x0010)
#నిర్వచించు PROCESS_VM_WRITE (0x0020)
#నిర్వచించు PROCESS_DUP_HANDLE (0x0040)
#నిర్వచించు PROCESS_CREATE_PROCESS (0x0080)
#నిర్వచించు PROCESS_సమితి_QUOTA (0x0100)
#నిర్వచించు PROCESS_సమితి_INFORMATION (0x0200)
#నిర్వచించు PROCESS_QUERY_INFORMATION (0x0400)
#నిర్వచించు PROCESS_SUSPEND_RESUME (0x0800)
#నిర్వచించు PROCESS_QUERY_LIMITED_INFORMATION (0x1000)
#నిర్వచించు PROCESS_సమితి_LIMITED_INFORMATION (0x2000)
#నిర్వచించు PROCESS_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0xFFF)

#నిర్వచితమైతే _WIN64
#నిర్వచించు గరిష్ఠ_PROCESSORS 64
#లేకపోతే
#నిర్వచించు గరిష్ఠ_PROCESSORS 32
#అయితే_ముగింపు

#నిర్వచించు THREAD_TERMINATE (0x0001)
#నిర్వచించు THREAD_SUSPEND_RESUME (0x0002)
#నిర్వచించు THREAD_GET_CONTEXT (0x0008)
#నిర్వచించు THREAD_సమితి_CONTEXT (0x0010)
#నిర్వచించు THREAD_సమితి_INFORMATION (0x0020)
#నిర్వచించు THREAD_QUERY_INFORMATION (0x0040)
#నిర్వచించు THREAD_సమితి_THREAD_TOKEN (0x0080)
#నిర్వచించు THREAD_IMPERSONATE (0x0100)
#నిర్వచించు THREAD_ప్రత్యక్ష_IMPERSONATION (0x0200)

#నిర్వచించు THREAD_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0x3FF)

#నిర్వచించు పని_OBJECT_కేటాయించు_PROCESS (0x0001)
#నిర్వచించు పని_OBJECT_సమితి_లక్షణాలు (0x0002)
#నిర్వచించు పని_OBJECT_QUERY (0x0004)
#నిర్వచించు పని_OBJECT_TERMINATE (0x0008)
#నిర్వచించు పని_OBJECT_సమితి_SECURITY_లక్షణాలు (0x0010)
#నిర్వచించు పని_OBJECT_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0x1F)

    రకనిర్వచనం నిర్మాణం పని_సమితి_ARRAY {
      HANDLE పని_Handle;
      DWORD MemberLevel;
      DWORD Flags;
    } పని_సమితి_ARRAY_2,*PJOB_సమితి_ARRAY;

#నిర్వచించు FLS_గరిష్ఠ_అందుబాటు 128
#నిర్వచించు TLS_MINIMUM_అందుబాటు 64

#నిర్వచితం_కాకపోతే _NT_TIB_DEFINED
#నిర్వచించు _NT_TIB_DEFINED
    రకనిర్వచనం నిర్మాణం _NT_TIB {
      నిర్మాణం EXCEPTION_REGISTRATION_రికార్డు_2 *ExceptionList;
      PVOID దొంతర_పునాది;
      PVOID దొంతర_హద్దు;
      PVOID SubSystemTib;
      సంఘం {
	PVOID Fiber_దత్తాంశం;
	DWORD సంస్కరణ_2;
      };
      PVOID Arbitrary_User_సూచిక;
      నిర్మాణం _NT_TIB *Self;
    } NT_TIB;
    రకనిర్వచనం NT_TIB *PNT_TIB;
#అయితే_ముగింపు

    రకనిర్వచనం నిర్మాణం _NT_TIB32 {
      DWORD ExceptionList;
      DWORD దొంతర_పునాది;
      DWORD దొంతర_హద్దు;
      DWORD SubSystemTib;
      సంఘం {
	DWORD Fiber_దత్తాంశం;
	DWORD సంస్కరణ_2;
      };
      DWORD Arbitrary_User_సూచిక;
      DWORD Self;
    } NT_TIB32,*PNT_TIB32;

    రకనిర్వచనం నిర్మాణం _NT_TIB64 {
      DWORD64 ExceptionList;
      DWORD64 దొంతర_పునాది;
      DWORD64 దొంతర_హద్దు;
      DWORD64 SubSystemTib;
      సంఘం {
	DWORD64 Fiber_దత్తాంశం;
	DWORD సంస్కరణ_2;
      };
      DWORD64 Arbitrary_User_సూచిక;
      DWORD64 Self;
    } NT_TIB64,*PNT_TIB64;

#ఒకవేళ !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_)
#నిర్వచించు WX86
#అయితే_ముగింపు

#నిర్వచించు THREAD_పునాది_ప్రాధాన్యత_LOWRT 15
#నిర్వచించు THREAD_పునాది_ప్రాధాన్యత_MAX 2
#నిర్వచించు THREAD_పునాది_ప్రాధాన్యత_MIN (-2)
#నిర్వచించు THREAD_పునాది_ప్రాధాన్యత_IDLE (-15)

    రకనిర్వచనం నిర్మాణం _QUOTA_LIMITS {
      కొలత_T Paged_Pool_హద్దు;
      కొలత_T Non_Paged_Pool_హద్దు;
      కొలత_T Minimum_Working_సమితి_కొలత;
      కొలత_T గరిష్ఠ_Working_సమితి_కొలత;
      కొలత_T Pagefile_హద్దు;
      LARGE_INTEGER సమయం_హద్దు;
    } QUOTA_LIMITS,*PQUOTA_LIMITS;

#నిర్వచించు QUOTA_LIMITS_HARDWS_MIN_ENABLE 0x00000001
#నిర్వచించు QUOTA_LIMITS_HARDWS_MIN_DISABLE 0x00000002
#నిర్వచించు QUOTA_LIMITS_HARDWS_MAX_ENABLE 0x00000004
#నిర్వచించు QUOTA_LIMITS_HARDWS_MAX_DISABLE 0x00000008

    రకనిర్వచనం నిర్మాణం _QUOTA_LIMITS_EX {
      కొలత_T Paged_Pool_హద్దు;
      కొలత_T Non_Paged_Pool_హద్దు;
      కొలత_T Minimum_Working_సమితి_కొలత;
      కొలత_T గరిష్ఠ_Working_సమితి_కొలత;
      కొలత_T Pagefile_హద్దు;
      LARGE_INTEGER సమయం_హద్దు;
      కొలత_T Reserved1;
      కొలత_T Reserved2;
      కొలత_T Reserved3;
      కొలత_T Reserved4;
      DWORD Flags;
      DWORD Reserved5;
    } QUOTA_LIMITS_EX,*PQUOTA_LIMITS_EX;

    రకనిర్వచనం నిర్మాణం _IO_COUNTERS {
      ULONGLONG Read_Operation_లెక్క;
      ULONGLONG Write_Operation_లెక్క;
      ULONGLONG Other_Operation_లెక్క;
      ULONGLONG Read_Transfer_లెక్క;
      ULONGLONG Write_Transfer_లెక్క;
      ULONGLONG Other_Transfer_లెక్క;
    } IO_COUNTERS;
    రకనిర్వచనం IO_COUNTERS *PIO_COUNTERS;

    రకనిర్వచనం నిర్మాణం _JOBOBJECT_BASIC_ACCOUNTING_INFORMATION {
      LARGE_INTEGER మొత్తం_User_సమయం;
      LARGE_INTEGER మొత్తం_Kernel_సమయం;
      LARGE_INTEGER This_Period_మొత్తం_User_సమయం;
      LARGE_INTEGER This_Period_మొత్తం_Kernel_సమయం;
      DWORD మొత్తం_పుట_Fault_లెక్క;
      DWORD మొత్తం_Processes;
      DWORD చురుకైన_Processes;
      DWORD మొత్తం_Terminated_Processes;
    } JOBOBJECT_BASIC_ACCOUNTING_INFORMATION,*PJOBOBJECT_BASIC_ACCOUNTING_INFORMATION;

    రకనిర్వచనం నిర్మాణం JOBOBJECT_BASIC_హద్దు_INFORMATION {
      LARGE_INTEGER చొప్పున_Process_User_సమయం_హద్దు;
      LARGE_INTEGER చొప్పున_పని_User_సమయం_హద్దు;
      DWORD హద్దు_Flags;
      కొలత_T Minimum_Working_సమితి_కొలత;
      కొలత_T గరిష్ఠ_Working_సమితి_కొలత;
      DWORD చురుకైన_Process_హద్దు;
      ULONG_PTR Affinity;
      DWORD ప్రాధాన్యత_Class;
      DWORD SchedulingClass;
    } JOBOBJECT_BASIC_హద్దు_INFORMATION_2,*PJOBOBJECT_BASIC_హద్దు_INFORMATION;

    రకనిర్వచనం నిర్మాణం JOBOBJECT_EXTENDED_హద్దు_INFORMATION {
      JOBOBJECT_BASIC_హద్దు_INFORMATION_2 Basic_హద్దు_Information;
      IO_COUNTERS IoInfo;
      కొలత_T Process_జ్ఞాపకం_హద్దు;
      కొలత_T పని_జ్ఞాపకం_హద్దు;
      కొలత_T Peak_Process_జ్ఞాపకం_వాడిన;
      కొలత_T Peak_పని_జ్ఞాపకం_వాడిన;
    } JOBOBJECT_EXTENDED_హద్దు_INFORMATION_2,*PJOBOBJECT_EXTENDED_హద్దు_INFORMATION;

    రకనిర్వచనం నిర్మాణం _JOBOBJECT_BASIC_PROCESS_ID_LIST {
      DWORD సంఖ్య_యొక్క_Assigned_Processes;
      DWORD సంఖ్య_యొక్క_Process_Ids_లోపల_List;
      ULONG_PTR ProcessIdList[1];
    } JOBOBJECT_BASIC_PROCESS_ID_LIST,*PJOBOBJECT_BASIC_PROCESS_ID_LIST;

    రకనిర్వచనం నిర్మాణం _JOBOBJECT_BASIC_UI_RESTRICTIONS {
      DWORD UIRestrictionsClass;
    } JOBOBJECT_BASIC_UI_RESTRICTIONS,*PJOBOBJECT_BASIC_UI_RESTRICTIONS;

    రకనిర్వచనం నిర్మాణం JOBOBJECT_SECURITY_హద్దు_INFORMATION {
      DWORD Security_హద్దు_Flags;
      HANDLE పని_Token;
      PTOKEN_GROUPS Sids_గమ్యం_Disable;
      PTOKEN_PRIVILEGES Privileges_గమ్యం_Delete;
      PTOKEN_GROUPS RestrictedSids;
    } JOBOBJECT_SECURITY_హద్దు_INFORMATION_2,*PJOBOBJECT_SECURITY_హద్దు_INFORMATION;

    రకనిర్వచనం నిర్మాణం JOBOBJECT_చివర_యొక్క_పని_సమయం_INFORMATION {
      DWORD చివర_యొక్క_పని_సమయం_Action;
    } JOBOBJECT_చివర_యొక్క_పని_సమయం_INFORMATION_2,*PJOBOBJECT_చివర_యొక్క_పని_సమయం_INFORMATION;

    రకనిర్వచనం నిర్మాణం JOBOBJECT_ASSOCIATE_COMPLETION_పోర్టు {
      PVOID Completion_కీలకం;
      HANDLE Completion_పోర్టు;
    } JOBOBJECT_ASSOCIATE_COMPLETION_పోర్టు_2,*PJOBOBJECT_ASSOCIATE_COMPLETION_పోర్టు;

    రకనిర్వచనం నిర్మాణం _JOBOBJECT_BASIC_AND_IO_ACCOUNTING_INFORMATION {
      JOBOBJECT_BASIC_ACCOUNTING_INFORMATION BasicInfo;
      IO_COUNTERS IoInfo;
    } JOBOBJECT_BASIC_AND_IO_ACCOUNTING_INFORMATION,*PJOBOBJECT_BASIC_AND_IO_ACCOUNTING_INFORMATION;

    రకనిర్వచనం నిర్మాణం _JOBOBJECT_JOBSET_INFORMATION {
      DWORD MemberLevel;
    } JOBOBJECT_JOBSET_INFORMATION,*PJOBOBJECT_JOBSET_INFORMATION;

#నిర్వచించు పని_OBJECT_TERMINATE_AT_చివర_యొక్క_పని 0
#నిర్వచించు పని_OBJECT_POST_AT_చివర_యొక్క_పని 1

#నిర్వచించు పని_OBJECT_సందేశం_చివర_యొక్క_పని_సమయం 1
#నిర్వచించు పని_OBJECT_సందేశం_చివర_యొక్క_PROCESS_సమయం 2
#నిర్వచించు పని_OBJECT_సందేశం_చురుకైన_PROCESS_హద్దు 3
#నిర్వచించు పని_OBJECT_సందేశం_చురుకైన_PROCESS_ZERO 4
#నిర్వచించు పని_OBJECT_సందేశం_NEW_PROCESS 6
#నిర్వచించు పని_OBJECT_సందేశం_EXIT_PROCESS 7
#నిర్వచించు పని_OBJECT_సందేశం_ABNORMAL_EXIT_PROCESS 8
#నిర్వచించు పని_OBJECT_సందేశం_PROCESS_జ్ఞాపకం_హద్దు 9
#నిర్వచించు పని_OBJECT_సందేశం_పని_జ్ఞాపకం_హద్దు 10

#నిర్వచించు పని_OBJECT_హద్దు_WORKINGSET 0x00000001
#నిర్వచించు పని_OBJECT_హద్దు_PROCESS_సమయం 0x00000002
#నిర్వచించు పని_OBJECT_హద్దు_పని_సమయం 0x00000004
#నిర్వచించు పని_OBJECT_హద్దు_చురుకైన_PROCESS 0x00000008
#నిర్వచించు పని_OBJECT_హద్దు_AFFINITY 0x00000010
#నిర్వచించు పని_OBJECT_హద్దు_ప్రాధాన్యత_CLASS 0x00000020
#నిర్వచించు పని_OBJECT_హద్దు_PRESERVE_పని_సమయం 0x00000040
#నిర్వచించు పని_OBJECT_హద్దు_SCHEDULING_CLASS 0x00000080

#నిర్వచించు పని_OBJECT_హద్దు_PROCESS_జ్ఞాపకం 0x00000100
#నిర్వచించు పని_OBJECT_హద్దు_పని_జ్ఞాపకం 0x00000200
#నిర్వచించు పని_OBJECT_హద్దు_DIE_ON_UNHANDLED_EXCEPTION 0x00000400
#నిర్వచించు పని_OBJECT_హద్దు_BREAKAWAY_OK 0x00000800
#నిర్వచించు పని_OBJECT_హద్దు_SILENT_BREAKAWAY_OK 0x00001000
#నిర్వచించు పని_OBJECT_హద్దు_KILL_ON_పని_CLOSE 0x00002000

#నిర్వచించు పని_OBJECT_హద్దు_RESERVED2 0x00004000
#నిర్వచించు పని_OBJECT_హద్దు_RESERVED3 0x00008000
#నిర్వచించు పని_OBJECT_హద్దు_RESERVED4 0x00010000
#నిర్వచించు పని_OBJECT_హద్దు_RESERVED5 0x00020000
#నిర్వచించు పని_OBJECT_హద్దు_RESERVED6 0x00040000

#నిర్వచించు పని_OBJECT_హద్దు_VALID_FLAGS 0x0007ffff

#నిర్వచించు పని_OBJECT_BASIC_హద్దు_VALID_FLAGS 0x000000ff
#నిర్వచించు పని_OBJECT_EXTENDED_హద్దు_VALID_FLAGS 0x00003fff
#నిర్వచించు పని_OBJECT_RESERVED_హద్దు_VALID_FLAGS 0x0007ffff

#నిర్వచించు పని_OBJECT_UILIMIT_NONE 0x00000000

#నిర్వచించు పని_OBJECT_UILIMIT_HANDLES 0x00000001
#నిర్వచించు పని_OBJECT_UILIMIT_READCLIPBOARD 0x00000002
#నిర్వచించు పని_OBJECT_UILIMIT_WRITECLIPBOARD 0x00000004
#నిర్వచించు పని_OBJECT_UILIMIT_SYSTEMPARAMETERS 0x00000008
#నిర్వచించు పని_OBJECT_UILIMIT_DISPLAYSETTINGS 0x00000010
#నిర్వచించు పని_OBJECT_UILIMIT_GLOBALATOMS 0x00000020
#నిర్వచించు పని_OBJECT_UILIMIT_DESKTOP 0x00000040
#నిర్వచించు పని_OBJECT_UILIMIT_EXITWINDOWS 0x00000080

#నిర్వచించు పని_OBJECT_UILIMIT_ALL 0x000000FF

#నిర్వచించు పని_OBJECT_UI_VALID_FLAGS 0x000000FF

#నిర్వచించు పని_OBJECT_SECURITY_NO_ADMIN 0x00000001
#నిర్వచించు పని_OBJECT_SECURITY_RESTRICTED_TOKEN 0x00000002
#నిర్వచించు పని_OBJECT_SECURITY_ONLY_TOKEN 0x00000004
#నిర్వచించు పని_OBJECT_SECURITY_FILTER_టోకెన్లు 0x00000008

#నిర్వచించు పని_OBJECT_SECURITY_VALID_FLAGS 0x0000000f

    రకనిర్వచనం గణన _JOBOBJECTINFOCLASS {
      పని_Object_Basic_Accounting_Information = 1,పని_Object_Basic_హద్దు_Information,పని_Object_Basic_Process_Id_List,పని_Object_Basic_UIRestrictions,
      పని_Object_Security_హద్దు_Information,పని_Object_చివర_యొక్క_పని_సమయం_Information,పని_Object_Associate_Completion_పోర్టు_Information,
      పని_Object_Basic_And_Io_Accounting_Information,పని_Object_Extended_హద్దు_Information,పని_Object_పని_సమితి_Information,Max_పని_Object_Info_Class
    } JOBOBJECTINFOCLASS;

#నిర్వచించు EVENT_MODIFY_STATE 0x0002
#నిర్వచించు EVENT_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x3)

#నిర్వచించు MUTANT_QUERY_STATE 0x0001

#నిర్వచించు MUTANT_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE| MUTANT_QUERY_STATE)
#నిర్వచించు SEMAPHORE_MODIFY_STATE 0x0002
#నిర్వచించు SEMAPHORE_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x3)

#నిర్వచించు TIMER_QUERY_STATE 0x0001
#నిర్వచించు TIMER_MODIFY_STATE 0x0002

#నిర్వచించు TIMER_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE| TIMER_QUERY_STATE|TIMER_MODIFY_STATE)

#నిర్వచించు సమయం_ZONE_ID_UNKNOWN 0
#నిర్వచించు సమయం_ZONE_ID_STANDARD 1
#నిర్వచించు సమయం_ZONE_ID_DAYLIGHT 2

    రకనిర్వచనం గణన _LOGICAL_PROCESSOR_RELATIONSHIP {
      సంబంధం_Processor_Core,సంబంధం_Numa_కణుపు,సంబంధం_Cache
    } LOGICAL_PROCESSOR_RELATIONSHIP;

#నిర్వచించు LTP_PC_SMT 0x1

    రకనిర్వచనం గణన _PROCESSOR_CACHE_TYPE {
      CacheUnified,CacheInstruction,Cache_దత్తాంశం,CacheTrace
    } PROCESSOR_CACHE_TYPE;

#నిర్వచించు CACHE_FULLY_ASSOCIATIVE 0xFF

    రకనిర్వచనం నిర్మాణం _CACHE_DESCRIPTOR {
      BYTE Level;
      BYTE Associativity;
      మాట_3 పంక్తి_కొలత_2;
      DWORD కొలత_3;
      PROCESSOR_CACHE_TYPE Type;
    } CACHE_DESCRIPTOR,*PCACHE_DESCRIPTOR;

    రకనిర్వచనం నిర్మాణం _SYSTEM_LOGICAL_PROCESSOR_INFORMATION {
      ULONG_PTR Processor_ముసుగు;
      LOGICAL_PROCESSOR_RELATIONSHIP Relationship;
      సంఘం {
	నిర్మాణం {
	  BYTE Flags;
	} ProcessorCore;
	నిర్మాణం {
	  DWORD కణుపు_సంఖ్య;
	} Numa_కణుపు;
	CACHE_DESCRIPTOR Cache;
	ULONGLONG Reserved[2];
      };
    } SYSTEM_LOGICAL_PROCESSOR_INFORMATION,*PSYSTEM_LOGICAL_PROCESSOR_INFORMATION;

#నిర్వచించు PROCESSOR_INTEL_386 386
#నిర్వచించు PROCESSOR_INTEL_486 486
#నిర్వచించు PROCESSOR_INTEL_PENTIUM 586
#నిర్వచించు PROCESSOR_INTEL_IA64 2200
#నిర్వచించు PROCESSOR_AMD_X8664 8664
#నిర్వచించు PROCESSOR_MIPS_R4000 4000
#నిర్వచించు PROCESSOR_ALPHA_21064 21064
#నిర్వచించు PROCESSOR_PPC_601 601
#నిర్వచించు PROCESSOR_PPC_603 603
#నిర్వచించు PROCESSOR_PPC_604 604
#నిర్వచించు PROCESSOR_PPC_620 620
#నిర్వచించు PROCESSOR_HITACHI_SH3 10003
#నిర్వచించు PROCESSOR_HITACHI_SH3E 10004
#నిర్వచించు PROCESSOR_HITACHI_SH4 10005
#నిర్వచించు PROCESSOR_MOTOROLA_821 821
#నిర్వచించు PROCESSOR_SHx_SH3 103
#నిర్వచించు PROCESSOR_SHx_SH4 104
#నిర్వచించు PROCESSOR_STRONGARM 2577
#నిర్వచించు PROCESSOR_ARM720 1824
#నిర్వచించు PROCESSOR_ARM820 2080
#నిర్వచించు PROCESSOR_ARM920 2336
#నిర్వచించు PROCESSOR_ARM_7TDMI 70001
#నిర్వచించు PROCESSOR_OPTIL 0x494f

#నిర్వచించు PROCESSOR_ARCHITECTURE_INTEL 0
#నిర్వచించు PROCESSOR_ARCHITECTURE_MIPS 1
#నిర్వచించు PROCESSOR_ARCHITECTURE_ALPHA 2
#నిర్వచించు PROCESSOR_ARCHITECTURE_PPC 3
#నిర్వచించు PROCESSOR_ARCHITECTURE_SHX 4
#నిర్వచించు PROCESSOR_ARCHITECTURE_ARM 5
#నిర్వచించు PROCESSOR_ARCHITECTURE_IA64 6
#నిర్వచించు PROCESSOR_ARCHITECTURE_ALPHA64 7
#నిర్వచించు PROCESSOR_ARCHITECTURE_MSIL 8
#నిర్వచించు PROCESSOR_ARCHITECTURE_AMD64 9
#నిర్వచించు PROCESSOR_ARCHITECTURE_IA32_ON_WIN64 10

#నిర్వచించు PROCESSOR_ARCHITECTURE_UNKNOWN 0xFFFF

#నిర్వచించు PF_FLOATING_బిందువు_PRECISION_ERRATA 0
#నిర్వచించు PF_FLOATING_బిందువు_EMULATED 1
#నిర్వచించు PF_COMPARE_EXCHANGE_DOUBLE 2
#నిర్వచించు PF_MMX_INSTRUCTIONS_అందుబాటు 3
#నిర్వచించు PF_PPC_MOVEMEM_64_బిట్టు_OK 4
#నిర్వచించు PF_ALPHA_BYTE_INSTRUCTIONS 5
#నిర్వచించు PF_XMMI_INSTRUCTIONS_అందుబాటు 6
#నిర్వచించు PF_3_DNOW_INSTRUCTIONS_అందుబాటు 7
#నిర్వచించు PF_RDTSC_INSTRUCTION_అందుబాటు 8
#నిర్వచించు PF_PAE_ENABLED 9
#నిర్వచించు PF_XMMI64_INSTRUCTIONS_అందుబాటు 10
#నిర్వచించు PF_SSE_DAZ_బహుళకం_అందుబాటు 11
#నిర్వచించు PF_NX_ENABLED 12

    రకనిర్వచనం నిర్మాణం జ్ఞాపకం_BASIC_INFORMATION_2 {
      PVOID పునాది_చిరునామా;
      PVOID కేటాయింపు_పునాది;
      DWORD కేటాయింపు_Protect;
      కొలత_T Region_కొలత;
      DWORD State;
      DWORD Protect;
      DWORD Type;
    } జ్ఞాపకం_BASIC_INFORMATION,*PMEMORY_BASIC_INFORMATION;

    రకనిర్వచనం నిర్మాణం జ్ఞాపకం_BASIC_INFORMATION32 {
      DWORD పునాది_చిరునామా;
      DWORD కేటాయింపు_పునాది;
      DWORD కేటాయింపు_Protect;
      DWORD Region_కొలత;
      DWORD State;
      DWORD Protect;
      DWORD Type;
    } జ్ఞాపకం_BASIC_INFORMATION32_2,*PMEMORY_BASIC_INFORMATION32;

    రకనిర్వచనం నిర్మాణం DECLSPEC_ALIGN(16) జ్ఞాపకం_BASIC_INFORMATION64 {
      ULONGLONG పునాది_చిరునామా;
      ULONGLONG కేటాయింపు_పునాది;
      DWORD కేటాయింపు_Protect;
      DWORD __alignment1;
      ULONGLONG Region_కొలత;
      DWORD State;
      DWORD Protect;
      DWORD Type;
      DWORD __alignment2;
    } జ్ఞాపకం_BASIC_INFORMATION64_2,*PMEMORY_BASIC_INFORMATION64;

#నిర్వచించు SECTION_QUERY 0x0001
#నిర్వచించు SECTION_MAP_WRITE 0x0002
#నిర్వచించు SECTION_MAP_READ 0x0004
#నిర్వచించు SECTION_MAP_EXECUTE 0x0008
#నిర్వచించు SECTION_EXTEND_కొలత 0x0010
#నిర్వచించు SECTION_MAP_EXECUTE_EXPLICIT 0x0020

#నిర్వచించు SECTION_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SECTION_QUERY| SECTION_MAP_WRITE | SECTION_MAP_READ | SECTION_MAP_EXECUTE | SECTION_EXTEND_కొలత)
#నిర్వచించు పుట_NOACCESS 0x01
#నిర్వచించు పుట_READONLY 0x02
#నిర్వచించు పుట_READWRITE 0x04
#నిర్వచించు పుట_WRITECOPY 0x08
#నిర్వచించు పుట_EXECUTE 0x10
#నిర్వచించు పుట_EXECUTE_READ 0x20
#నిర్వచించు పుట_EXECUTE_READWRITE 0x40
#నిర్వచించు పుట_EXECUTE_WRITECOPY 0x80
#నిర్వచించు పుట_GUARD 0x100
#నిర్వచించు పుట_NOCACHE 0x200
#నిర్వచించు పుట_WRITECOMBINE 0x400
#నిర్వచించు MEM_COMMIT 0x1000
#నిర్వచించు MEM_RESERVE 0x2000
#నిర్వచించు MEM_DECOMMIT 0x4000
#నిర్వచించు MEM_RELEASE 0x8000
#నిర్వచించు MEM_FREE 0x10000
#నిర్వచించు MEM_వ్యక్తిగత 0x20000
#నిర్వచించు MEM_MAPPED 0x40000
#నిర్వచించు MEM_RESET 0x80000
#నిర్వచించు MEM_శిఖరం_కిందికి 0x100000
#నిర్వచించు MEM_WRITE_WATCH 0x200000
#నిర్వచించు MEM_PHYSICAL 0x400000
#నిర్వచించు MEM_LARGE_పుటలు 0x20000000
#నిర్వచించు MEM_4_MB_పుటలు 0x80000000
#నిర్వచించు SEC_FILE 0x800000
#నిర్వచించు SEC_IMAGE 0x1000000
#నిర్వచించు SEC_RESERVE 0x4000000
#నిర్వచించు SEC_COMMIT 0x8000000
#నిర్వచించు SEC_NOCACHE 0x10000000
#నిర్వచించు SEC_LARGE_పుటలు 0x80000000
#నిర్వచించు MEM_IMAGE SEC_IMAGE
#నిర్వచించు WRITE_WATCH_FLAG_RESET 0x01

#నిర్వచించు FILE_READ_దత్తాంశం (0x0001)
#నిర్వచించు FILE_LIST_DIRECTORY (0x0001)

#నిర్వచించు FILE_WRITE_దత్తాంశం (0x0002)
#నిర్వచించు FILE_కూడు_FILE (0x0002)

#నిర్వచించు FILE_APPEND_దత్తాంశం (0x0004)
#నిర్వచించు FILE_కూడు_SUBDIRECTORY (0x0004)
#నిర్వచించు FILE_CREATE_PIPE_INSTANCE (0x0004)

#నిర్వచించు FILE_READ_EA (0x0008)

#నిర్వచించు FILE_WRITE_EA (0x0010)

#నిర్వచించు FILE_EXECUTE (0x0020)
#నిర్వచించు FILE_TRAVERSE (0x0020)

#నిర్వచించు FILE_DELETE_బిడ్డ (0x0040)

#నిర్వచించు FILE_READ_లక్షణాలు (0x0080)

#నిర్వచించు FILE_WRITE_లక్షణాలు (0x0100)

#నిర్వచించు FILE_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0x1FF)
#నిర్వచించు FILE_GENERIC_READ (STANDARD_RIGHTS_READ | FILE_READ_దత్తాంశం | FILE_READ_లక్షణాలు | FILE_READ_EA | SYNCHRONIZE)
#నిర్వచించు FILE_GENERIC_WRITE (STANDARD_RIGHTS_WRITE | FILE_WRITE_దత్తాంశం | FILE_WRITE_లక్షణాలు | FILE_WRITE_EA | FILE_APPEND_దత్తాంశం | SYNCHRONIZE)
#నిర్వచించు FILE_GENERIC_EXECUTE (STANDARD_RIGHTS_EXECUTE | FILE_READ_లక్షణాలు | FILE_EXECUTE | SYNCHRONIZE)

#నిర్వచించు FILE_SHARE_READ 0x00000001
#నిర్వచించు FILE_SHARE_WRITE 0x00000002
#నిర్వచించు FILE_SHARE_DELETE 0x00000004
#నిర్వచించు FILE_ATTRIBUTE_READONLY 0x00000001
#నిర్వచించు FILE_ATTRIBUTE_HIDDEN 0x00000002
#నిర్వచించు FILE_ATTRIBUTE_SYSTEM 0x00000004
#నిర్వచించు FILE_ATTRIBUTE_DIRECTORY 0x00000010
#నిర్వచించు FILE_ATTRIBUTE_ARCHIVE 0x00000020
#నిర్వచించు FILE_ATTRIBUTE_DEVICE 0x00000040
#నిర్వచించు FILE_ATTRIBUTE_సాధారణ 0x00000080
#నిర్వచించు FILE_ATTRIBUTE_TEMPORARY 0x00000100
#నిర్వచించు FILE_ATTRIBUTE_SPARSE_FILE 0x00000200
#నిర్వచించు FILE_ATTRIBUTE_REPARSE_బిందువు 0x00000400
#నిర్వచించు FILE_ATTRIBUTE_COMPRESSED 0x00000800
#నిర్వచించు FILE_ATTRIBUTE_OFFLINE 0x00001000
#నిర్వచించు FILE_ATTRIBUTE_NOT_CONTENT_సూచీకృత 0x00002000
#నిర్వచించు FILE_ATTRIBUTE_ENCRYPTED 0x00004000
#నిర్వచించు FILE_NOTIFY_CHANGE_FILE_NAME 0x00000001
#నిర్వచించు FILE_NOTIFY_CHANGE_DIR_NAME 0x00000002
#నిర్వచించు FILE_NOTIFY_CHANGE_లక్షణాలు 0x00000004
#నిర్వచించు FILE_NOTIFY_CHANGE_కొలత 0x00000008
#నిర్వచించు FILE_NOTIFY_CHANGE_చివరి_WRITE 0x00000010
#నిర్వచించు FILE_NOTIFY_CHANGE_చివరి_ACCESS 0x00000020
#నిర్వచించు FILE_NOTIFY_CHANGE_CREATION 0x00000040
#నిర్వచించు FILE_NOTIFY_CHANGE_SECURITY 0x00000100
#నిర్వచించు FILE_ACTION_ADDED 0x00000001
#నిర్వచించు FILE_ACTION_REMOVED 0x00000002
#నిర్వచించు FILE_ACTION_MODIFIED 0x00000003
#నిర్వచించు FILE_ACTION_RENAMED_OLD_NAME 0x00000004
#నిర్వచించు FILE_ACTION_RENAMED_NEW_NAME 0x00000005
#నిర్వచించు MAILSLOT_NO_సందేశం ((DWORD)-1)
#నిర్వచించు MAILSLOT_WAIT_FOREVER ((DWORD)-1)
#నిర్వచించు FILE_CASE_SENSITIVE_శోధన 0x00000001
#నిర్వచించు FILE_CASE_PRESERVED_పేర్లు 0x00000002
#నిర్వచించు FILE_UNICODE_ON_DISK 0x00000004
#నిర్వచించు FILE_PERSISTENT_ACLS 0x00000008
#నిర్వచించు FILE_FILE_COMPRESSION 0x00000010
#నిర్వచించు FILE_VOLUME_QUOTAS 0x00000020
#నిర్వచించు FILE_SUPPORTS_SPARSE_FILES 0x00000040
#నిర్వచించు FILE_SUPPORTS_REPARSE_POINTS 0x00000080
#నిర్వచించు FILE_SUPPORTS_REMOTE_STORAGE 0x00000100
#నిర్వచించు FILE_VOLUME_IS_COMPRESSED 0x00008000
#నిర్వచించు FILE_SUPPORTS_OBJECT_IDS 0x00010000
#నిర్వచించు FILE_SUPPORTS_ENCRYPTION 0x00020000
#నిర్వచించు FILE_NAMED_STREAMS 0x00040000
#నిర్వచించు FILE_READ_ONLY_VOLUME 0x00080000

    రకనిర్వచనం నిర్మాణం _FILE_NOTIFY_INFORMATION {
      DWORD తదుపరి_నమోదు_స్థానభ్రంశం;
      DWORD Action;
      DWORD File_Name_నిడివి;
      WCHAR FileName[1];
    } FILE_NOTIFY_INFORMATION,*PFILE_NOTIFY_INFORMATION;

    రకనిర్వచనం సంఘం _FILE_SEGMENT_ELEMENT {
      PVOID64 బఫరు_3;
      ULONGLONG Alignment;
    }FILE_SEGMENT_ELEMENT,*PFILE_SEGMENT_ELEMENT;

    రకనిర్వచనం నిర్మాణం REPARSE_GUID_దత్తాంశం_బఫరు {
      DWORD Reparse_ట్యాగ్;
      మాట_3 Reparse_దత్తాంశం_నిడివి;
      మాట_3 Reserved;
      GUID ReparseGuid;
      నిర్మాణం {
	BYTE దత్తాంశం_బఫరు[1];
      } Generic_Reparse_బఫరు;
    } REPARSE_GUID_దత్తాంశం_బఫరు_2,*PREPARSE_GUID_దత్తాంశం_బఫరు;

#నిర్వచించు REPARSE_GUID_దత్తాంశం_బఫరు_శీర్షిక_కొలత క్షేత్రం_స్థానభ్రంశం(REPARSE_GUID_దత్తాంశం_బఫరు_2,Generic_Reparse_బఫరు)

#నిర్వచించు గరిష్ఠ_REPARSE_దత్తాంశం_బఫరు_కొలత (16 *1024)

#నిర్వచించు IO_REPARSE_ట్యాగ్_RESERVED_ZERO (0)
#నిర్వచించు IO_REPARSE_ట్యాగ్_RESERVED_ONE (1)

#నిర్వచించు IO_REPARSE_ట్యాగ్_RESERVED_RANGE IO_REPARSE_ట్యాగ్_RESERVED_ONE

#నిర్వచించు Is_Reparse_ట్యాగ్_Microsoft(ట్యాగ్_2) (((ట్యాగ్_2) & 0x80000000))
#నిర్వచించు Is_Reparse_ట్యాగ్_Name_Surrogate(ట్యాగ్_2) (((ట్యాగ్_2) & 0x20000000))

#నిర్వచించు IO_REPARSE_ట్యాగ్_MOUNT_బిందువు (0xA0000003L)
#నిర్వచించు IO_REPARSE_ట్యాగ్_HSM (0xC0000004L)
#నిర్వచించు IO_REPARSE_ట్యాగ్_SIS (0x80000007L)
#నిర్వచించు IO_REPARSE_ట్యాగ్_DFS (0x8000000AL)
#నిర్వచించు IO_REPARSE_ట్యాగ్_FILTER_MANAGER (0x8000000BL)
#నిర్వచించు IO_COMPLETION_MODIFY_STATE 0x0002
#నిర్వచించు IO_COMPLETION_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x3)
#నిర్వచించు DUPLICATE_CLOSE_ఆధారం 0x00000001
#నిర్వచించు DUPLICATE_SAME_ACCESS 0x00000002

    రకనిర్వచనం గణన _SYSTEM_POWER_STATE {
      PowerSystemUnspecified = 0,PowerSystemWorking = 1,PowerSystemSleeping1 = 2,PowerSystemSleeping2 = 3,PowerSystemSleeping3 = 4,PowerSystemHibernate = 5,PowerSystemShutdown = 6,Power_System_గరిష్ఠ = 7
    } SYSTEM_POWER_STATE,*PSYSTEM_POWER_STATE;

#నిర్వచించు POWER_SYSTEM_గరిష్ఠ 7

    రకనిర్వచనం గణన {
      PowerActionNone = 0,PowerActionReserved,PowerActionSleep,PowerActionHibernate,PowerActionShutdown,PowerActionShutdownReset,PowerActionShutdownOff,PowerActionWarmEject
    } POWER_ACTION,*PPOWER_ACTION;

    రకనిర్వచనం గణన _DEVICE_POWER_STATE {
      PowerDeviceUnspecified = 0,PowerDeviceD0,PowerDeviceD1,PowerDeviceD2,PowerDeviceD3,Power_Device_గరిష్ఠ
    } DEVICE_POWER_STATE,*PDEVICE_POWER_STATE;

#నిర్వచించు ES_SYSTEM_REQUIRED ((DWORD)0x00000001)
#నిర్వచించు ES_DISPLAY_REQUIRED ((DWORD)0x00000002)
#నిర్వచించు ES_USER_PRESENT ((DWORD)0x00000004)
#నిర్వచించు ES_CONTINUOUS ((DWORD)0x80000000)

    రకనిర్వచనం DWORD EXECUTION_STATE;

    రకనిర్వచనం గణన {
      LT_DONT_CARE,LT_అత్యల్ప_LATENCY
    } LATENCY_సమయం;

#నిర్వచించు PDCAP_D0_SUPPORTED 0x00000001
#నిర్వచించు PDCAP_D1_SUPPORTED 0x00000002
#నిర్వచించు PDCAP_D2_SUPPORTED 0x00000004
#నిర్వచించు PDCAP_D3_SUPPORTED 0x00000008
#నిర్వచించు PDCAP_WAKE_FROM_D0_SUPPORTED 0x00000010
#నిర్వచించు PDCAP_WAKE_FROM_D1_SUPPORTED 0x00000020
#నిర్వచించు PDCAP_WAKE_FROM_D2_SUPPORTED 0x00000040
#నిర్వచించు PDCAP_WAKE_FROM_D3_SUPPORTED 0x00000080
#నిర్వచించు PDCAP_WARM_EJECT_SUPPORTED 0x00000100

    రకనిర్వచనం నిర్మాణం CM_Power_దత్తాంశం_s {
      DWORD PD_కొలత;
      DEVICE_POWER_STATE PD_MostRecentPowerState;
      DWORD PD_Capabilities;
      DWORD PD_D1Latency;
      DWORD PD_D2Latency;
      DWORD PD_D3Latency;
      DEVICE_POWER_STATE PD_PowerStateMapping[POWER_SYSTEM_గరిష్ఠ];
      SYSTEM_POWER_STATE PD_అత్యంతలోతు_System_Wake;
    } CM_POWER_దత్తాంశం,*PCM_POWER_దత్తాంశం;

    రకనిర్వచనం గణన {
      SystemPowerPolicyAc,SystemPowerPolicyDc,VerifySystemPolicyAc,VerifySystemPolicyDc,SystemPowerCapabilities,SystemBatteryState,SystemPowerStateHandler,ProcessorStateHandler,SystemPowerPolicyCurrent,AdministratorPowerPolicy,SystemReserveHiberFile,ProcessorInformation,SystemPowerInformation,ProcessorStateHandler2,చివరి_Wake_సమయం,చివరి_Sleep_సమయం,SystemExecutionState,SystemPowerStateNotifyHandler,ProcessorPowerPolicyAc,ProcessorPowerPolicyDc,VerifyProcessorPowerPolicyAc,VerifyProcessorPowerPolicyDc,ProcessorPowerPolicyCurrent,SystemPowerStateLogging,System_Power_Logging_నమోదు
    } POWER_INFORMATION_LEVEL;

    రకనిర్వచనం నిర్మాణం {
      DWORD Granularity;
      DWORD సామర్థ్యం;
    } BATTERY_REPORTING_SCALE,*PBATTERY_REPORTING_SCALE;

    రకనిర్వచనం నిర్మాణం {
      POWER_ACTION Action;
      DWORD Flags;
      DWORD Event_సంకేతం;
    } POWER_ACTION_POLICY,*PPOWER_ACTION_POLICY;

#నిర్వచించు POWER_ACTION_QUERY_ALLOWED 0x00000001
#నిర్వచించు POWER_ACTION_UI_ALLOWED 0x00000002
#నిర్వచించు POWER_ACTION_OVERRIDE_APPS 0x00000004
#నిర్వచించు POWER_ACTION_LIGHTEST_మొదటి 0x10000000
#నిర్వచించు POWER_ACTION_తాళం_CONSOLE 0x20000000
#నిర్వచించు POWER_ACTION_DISABLE_WAKES 0x40000000
#నిర్వచించు POWER_ACTION_CRITICAL 0x80000000

#నిర్వచించు POWER_LEVEL_USER_NOTIFY_పాఠ్యం 0x00000001
#నిర్వచించు POWER_LEVEL_USER_NOTIFY_SOUND 0x00000002
#నిర్వచించు POWER_LEVEL_USER_NOTIFY_EXEC 0x00000004
#నిర్వచించు POWER_USER_NOTIFY_BUTTON 0x00000008
#నిర్వచించు POWER_USER_NOTIFY_SHUTDOWN 0x00000010
#నిర్వచించు POWER_FORCE_TRIGGER_RESET 0x80000000

    రకనిర్వచనం నిర్మాణం {
      BOOLEAN Enable;
      BYTE అదనపు_2[3];
      DWORD BatteryLevel;
      POWER_ACTION_POLICY PowerPolicy;
      SYSTEM_POWER_STATE MinSystemState;
    } SYSTEM_POWER_LEVEL,*PSYSTEM_POWER_LEVEL;

#నిర్వచించు అంకె_DISCHARGE_POLICIES 4
#నిర్వచించు DISCHARGE_POLICY_CRITICAL 0
#నిర్వచించు DISCHARGE_POLICY_దిగువ 1

#నిర్వచించు PO_THROTTLE_NONE 0
#నిర్వచించు PO_THROTTLE_CONSTANT 1
#నిర్వచించు PO_THROTTLE_DEGRADE 2
#నిర్వచించు PO_THROTTLE_ADAPTIVE 3
#నిర్వచించు PO_THROTTLE_గరిష్ఠ 4

    రకనిర్వచనం నిర్మాణం _SYSTEM_POWER_POLICY {
      DWORD Revision;
      POWER_ACTION_POLICY PowerButton;
      POWER_ACTION_POLICY SleepButton;
      POWER_ACTION_POLICY LidClose;
      SYSTEM_POWER_STATE LidOpenWake;
      DWORD Reserved;
      POWER_ACTION_POLICY Idle;
      DWORD IdleTimeout;
      BYTE Idle_సున్నితత్వం;
      BYTE DynamicThrottle;
      BYTE Spare2[2];
      SYSTEM_POWER_STATE MinSleep;
      SYSTEM_POWER_STATE MaxSleep;
      SYSTEM_POWER_STATE ReducedLatencySleep;
      DWORD WinLogonFlags;
      DWORD Spare3;
      DWORD DozeS4Timeout;
      DWORD ప్రసారం_సామర్థ్యం_Resolution;
      SYSTEM_POWER_LEVEL DischargePolicy[అంకె_DISCHARGE_POLICIES];
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

    రకనిర్వచనం నిర్మాణం _PROCESSOR_POWER_POLICY_INFO {
      DWORD సమయం_Check;
      DWORD Demote_హద్దు;
      DWORD Promote_హద్దు;
      BYTE DemotePercent;
      BYTE PromotePercent;
      BYTE అదనపు_2[2];
      DWORD AllowDemotion:1;
      DWORD AllowPromotion:1;
      DWORD Reserved:30;
    } PROCESSOR_POWER_POLICY_INFO,*PPROCESSOR_POWER_POLICY_INFO;

    రకనిర్వచనం నిర్మాణం _PROCESSOR_POWER_POLICY {
      DWORD Revision;
      BYTE DynamicThrottle;
      BYTE అదనపు_2[3];
      DWORD DisableCStates:1;
      DWORD Reserved:31;
      DWORD Policy_లెక్క;
      PROCESSOR_POWER_POLICY_INFO Policy[3];
    } PROCESSOR_POWER_POLICY,*PPROCESSOR_POWER_POLICY;

    రకనిర్వచనం నిర్మాణం _ADMINISTRATOR_POWER_POLICY {
      SYSTEM_POWER_STATE MinSleep;
      SYSTEM_POWER_STATE MaxSleep;
      DWORD MinVideoTimeout;
      DWORD MaxVideoTimeout;
      DWORD MinSpindownTimeout;
      DWORD MaxSpindownTimeout;
    } ADMINISTRATOR_POWER_POLICY,*PADMINISTRATOR_POWER_POLICY;

    రకనిర్వచనం నిర్మాణం {
      BOOLEAN PowerButtonPresent;
      BOOLEAN SleepButtonPresent;
      BOOLEAN LidPresent;
      BOOLEAN SystemS1;
      BOOLEAN SystemS2;
      BOOLEAN SystemS3;
      BOOLEAN SystemS4;
      BOOLEAN SystemS5;
      BOOLEAN HiberFilePresent;
      BOOLEAN నిండిన_Wake;
      BOOLEAN VideoDimPresent;
      BOOLEAN ApmPresent;
      BOOLEAN UpsPresent;
      BOOLEAN ThermalControl;
      BOOLEAN ProcessorThrottle;
      BYTE ProcessorMinThrottle;
      BYTE ProcessorMaxThrottle;
      BYTE spare2[4];
      BOOLEAN Disk_Spin_కిందికి;
      BYTE spare3[8];
      BOOLEAN SystemBatteriesPresent;
      BOOLEAN Batteries_Are_Short_పదం;
      BATTERY_REPORTING_SCALE BatteryScale[3];
      SYSTEM_POWER_STATE Ac_On_పంక్తి_Wake;
      SYSTEM_POWER_STATE SoftLidWake;
      SYSTEM_POWER_STATE RtcWake;
      SYSTEM_POWER_STATE MinDeviceWakeState;
      SYSTEM_POWER_STATE Default_దిగువ_Latency_Wake;
    } SYSTEM_POWER_CAPABILITIES,*PSYSTEM_POWER_CAPABILITIES;

    రకనిర్వచనం నిర్మాణం {
      BOOLEAN Ac_On_పంక్తి;
      BOOLEAN BatteryPresent;
      BOOLEAN Charging;
      BOOLEAN Discharging;
      BOOLEAN Spare1[4];
      DWORD Max_సామర్థ్యం;
      DWORD మిగిలిన_సామర్థ్యం;
      DWORD రేటు;
      DWORD Estimated_సమయం;
      DWORD DefaultAlert1;
      DWORD DefaultAlert2;
    } SYSTEM_BATTERY_STATE,*PSYSTEM_BATTERY_STATE;

#అన్తర్భావ "pshpack4.h"

#నిర్వచించు IMAGE_DOS_SIGNATURE 0x5A4D
#నిర్వచించు IMAGE_OS2_SIGNATURE 0x454E
#నిర్వచించు IMAGE_OS2_SIGNATURE_LE 0x454C
#నిర్వచించు IMAGE_VXD_SIGNATURE 0x454C
#నిర్వచించు IMAGE_NT_SIGNATURE 0x00004550

#అన్తర్భావ "pshpack2.h"

    రకనిర్వచనం నిర్మాణం IMAGE_DOS_శీర్షిక {
      మాట_3 e_magic;
      మాట_3 e_cblp;
      మాట_3 e_cp;
      మాట_3 e_crlc;
      మాట_3 e_cparhdr;
      మాట_3 e_minalloc;
      మాట_3 e_maxalloc;
      మాట_3 e_ss;
      మాట_3 e_sp;
      మాట_3 e_csum;
      మాట_3 e_ip;
      మాట_3 e_cs;
      మాట_3 e_lfarlc;
      మాట_3 e_ovno;
      మాట_3 e_res[4];
      మాట_3 e_oemid;
      మాట_3 e_oeminfo;
      మాట_3 e_res2[10];
      LONG e_lfanew;
    } IMAGE_DOS_శీర్షిక_2,*PIMAGE_DOS_శీర్షిక;

    రకనిర్వచనం నిర్మాణం IMAGE_OS2_శీర్షిక {
      మాట_3 ne_magic;
      CHAR ne_ver;
      CHAR ne_rev;
      మాట_3 ne_enttab;
      మాట_3 ne_cbenttab;
      LONG ne_చక్రీయ_తనిఖీ;
      మాట_3 ne_flags;
      మాట_3 ne_autodata;
      మాట_3 ne_కుప్ప;
      మాట_3 ne_దొంతర;
      LONG ne_csip;
      LONG ne_sssp;
      మాట_3 ne_cseg;
      మాట_3 ne_cmod;
      మాట_3 ne_cbnrestab;
      మాట_3 ne_segtab;
      మాట_3 ne_rsrctab;
      మాట_3 ne_restab;
      మాట_3 ne_modtab;
      మాట_3 ne_imptab;
      LONG ne_nrestab;
      మాట_3 ne_cmovent;
      మాట_3 ne_align;
      మాట_3 ne_cres;
      BYTE ne_exetyp;
      BYTE ne_flagsothers;
      మాట_3 ne_pretthunks;
      మాట_3 ne_psegrefbytes;
      మాట_3 ne_swaparea;
      మాట_3 ne_expver;
    } IMAGE_OS2_శీర్షిక_2,*PIMAGE_OS2_శీర్షిక;

    రకనిర్వచనం నిర్మాణం IMAGE_VXD_శీర్షిక {
      మాట_3 e32_magic;
      BYTE e32_border;
      BYTE e32_worder;
      DWORD e32_level;
      మాట_3 e32_cpu;
      మాట_3 e32_os;
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
      మాట_3 e32_devid;
      మాట_3 e32_ddkver;
    } IMAGE_VXD_శీర్షిక_2,*PIMAGE_VXD_శీర్షిక;

#అన్తర్భావ "poppack.h"

    రకనిర్వచనం నిర్మాణం IMAGE_FILE_శీర్షిక {
      మాట_3 Machine;
      మాట_3 సంఖ్య_యొక్క_Sections;
      DWORD సమయం_Date_Stamp;
      DWORD సూచిక_గమ్యం_చిహ్నం_పట్టిక;
      DWORD సంఖ్య_యొక్క_Symbols;
      మాట_3 కొలత_యొక్క_Optional_శీర్షిక;
      మాట_3 Characteristics;
    } IMAGE_FILE_శీర్షిక_2,*PIMAGE_FILE_శీర్షిక;

#నిర్వచించు IMAGE_SIZEOF_FILE_శీర్షిక 20

#నిర్వచించు IMAGE_FILE_RELOCS_STRIPPED 0x0001
#నిర్వచించు IMAGE_FILE_EXECUTABLE_IMAGE 0x0002
#నిర్వచించు IMAGE_FILE_పంక్తి_NUMS_STRIPPED 0x0004
#నిర్వచించు IMAGE_FILE_LOCAL_SYMS_STRIPPED 0x0008
#నిర్వచించు IMAGE_FILE_AGGRESIVE_WS_TRIM 0x0010
#నిర్వచించు IMAGE_FILE_LARGE_చిరునామా_AWARE 0x0020
#నిర్వచించు IMAGE_FILE_బైట్లు_REVERSED_LO 0x0080
#నిర్వచించు IMAGE_FILE_32_బిట్టు_MACHINE 0x0100
#నిర్వచించు IMAGE_FILE_DEBUG_STRIPPED 0x0200
#నిర్వచించు IMAGE_FILE_REMOVABLE_నిరంతరం_FROM_మార్పిడి 0x0400
#నిర్వచించు IMAGE_FILE_NET_నిరంతరం_FROM_మార్పిడి 0x0800
#నిర్వచించు IMAGE_FILE_SYSTEM 0x1000
#నిర్వచించు IMAGE_FILE_DLL 0x2000
#నిర్వచించు IMAGE_FILE_పైకి_SYSTEM_ONLY 0x4000
#నిర్వచించు IMAGE_FILE_బైట్లు_REVERSED_HI 0x8000

#నిర్వచించు IMAGE_FILE_MACHINE_UNKNOWN 0
#నిర్వచించు IMAGE_FILE_MACHINE_I386 0x014c
#నిర్వచించు IMAGE_FILE_MACHINE_R3000 0x0162
#నిర్వచించు IMAGE_FILE_MACHINE_R4000 0x0166
#నిర్వచించు IMAGE_FILE_MACHINE_R10000 0x0168
#నిర్వచించు IMAGE_FILE_MACHINE_WCEMIPSV2 0x0169
#నిర్వచించు IMAGE_FILE_MACHINE_ALPHA 0x0184
#నిర్వచించు IMAGE_FILE_MACHINE_SH3 0x01a2
#నిర్వచించు IMAGE_FILE_MACHINE_SH3DSP 0x01a3
#నిర్వచించు IMAGE_FILE_MACHINE_SH3E 0x01a4
#నిర్వచించు IMAGE_FILE_MACHINE_SH4 0x01a6
#నిర్వచించు IMAGE_FILE_MACHINE_SH5 0x01a8
#నిర్వచించు IMAGE_FILE_MACHINE_ARM 0x01c0
#నిర్వచించు IMAGE_FILE_MACHINE_THUMB 0x01c2
#నిర్వచించు IMAGE_FILE_MACHINE_AM33 0x01d3
#నిర్వచించు IMAGE_FILE_MACHINE_POWERPC 0x01F0
#నిర్వచించు IMAGE_FILE_MACHINE_POWERPCFP 0x01f1
#నిర్వచించు IMAGE_FILE_MACHINE_IA64 0x0200
#నిర్వచించు IMAGE_FILE_MACHINE_MIPS16 0x0266
#నిర్వచించు IMAGE_FILE_MACHINE_ALPHA64 0x0284
#నిర్వచించు IMAGE_FILE_MACHINE_MIPSFPU 0x0366
#నిర్వచించు IMAGE_FILE_MACHINE_MIPSFPU16 0x0466
#నిర్వచించు IMAGE_FILE_MACHINE_AXP64 IMAGE_FILE_MACHINE_ALPHA64
#నిర్వచించు IMAGE_FILE_MACHINE_TRICORE 0x0520
#నిర్వచించు IMAGE_FILE_MACHINE_CEF 0x0CEF
#నిర్వచించు IMAGE_FILE_MACHINE_EBC 0x0EBC
#నిర్వచించు IMAGE_FILE_MACHINE_AMD64 0x8664
#నిర్వచించు IMAGE_FILE_MACHINE_ARM64 0xAA64
#నిర్వచించు IMAGE_FILE_MACHINE_M32R 0x9041
#నిర్వచించు IMAGE_FILE_MACHINE_CEE 0xC0EE

    రకనిర్వచనం నిర్మాణం IMAGE_దత్తాంశం_DIRECTORY {
      DWORD Virtual_చిరునామా;
      DWORD కొలత_3;
    } IMAGE_దత్తాంశం_DIRECTORY_2,*PIMAGE_దత్తాంశం_DIRECTORY;

#నిర్వచించు IMAGE_NUMBEROF_DIRECTORY_ENTRIES 16

    రకనిర్వచనం నిర్మాణం IMAGE_OPTIONAL_శీర్షిక {

      మాట_3 Magic;
      BYTE Major_Linker_సంస్కరణ;
      BYTE Minor_Linker_సంస్కరణ;
      DWORD కొలత_యొక్క_సంకేతం;
      DWORD కొలత_యొక్క_Initialized_దత్తాంశం;
      DWORD కొలత_యొక్క_Uninitialized_దత్తాంశం;
      DWORD చిరునామా_యొక్క_నమోదు_బిందువు;
      DWORD పునాది_యొక్క_సంకేతం;
      DWORD పునాది_యొక్క_దత్తాంశం;
      DWORD Image_పునాది;
      DWORD SectionAlignment;
      DWORD FileAlignment;
      మాట_3 Major_Operating_System_సంస్కరణ;
      మాట_3 Minor_Operating_System_సంస్కరణ;
      మాట_3 Major_Image_సంస్కరణ;
      మాట_3 Minor_Image_సంస్కరణ;
      మాట_3 Major_Subsystem_సంస్కరణ;
      మాట_3 Minor_Subsystem_సంస్కరణ;
      DWORD Win32_సంస్కరణ_విలువ;
      DWORD కొలత_యొక్క_Image;
      DWORD కొలత_యొక్క_శీర్షికలు;
      DWORD Check_కూడిక;
      మాట_3 Subsystem;
      మాట_3 DllCharacteristics;
      DWORD కొలత_యొక్క_దొంతర_Reserve;
      DWORD కొలత_యొక్క_దొంతర_Commit;
      DWORD కొలత_యొక్క_కుప్ప_Reserve;
      DWORD కొలత_యొక్క_కుప్ప_Commit;
      DWORD LoaderFlags;
      DWORD సంఖ్య_యొక్క_Rva_And_Sizes;
      IMAGE_దత్తాంశం_DIRECTORY_2 దత్తాంశం_Directory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
    } IMAGE_OPTIONAL_HEADER32,*PIMAGE_OPTIONAL_HEADER32;

    రకనిర్వచనం నిర్మాణం IMAGE_ROM_OPTIONAL_శీర్షిక {
      మాట_3 Magic;
      BYTE Major_Linker_సంస్కరణ;
      BYTE Minor_Linker_సంస్కరణ;
      DWORD కొలత_యొక్క_సంకేతం;
      DWORD కొలత_యొక్క_Initialized_దత్తాంశం;
      DWORD కొలత_యొక్క_Uninitialized_దత్తాంశం;
      DWORD చిరునామా_యొక్క_నమోదు_బిందువు;
      DWORD పునాది_యొక్క_సంకేతం;
      DWORD పునాది_యొక్క_దత్తాంశం;
      DWORD పునాది_యొక్క_Bss;
      DWORD Gpr_ముసుగు;
      DWORD Cpr_ముసుగు[4];
      DWORD Gp_విలువ;
    } IMAGE_ROM_OPTIONAL_శీర్షిక_2,*PIMAGE_ROM_OPTIONAL_శీర్షిక;

    రకనిర్వచనం నిర్మాణం _IMAGE_OPTIONAL_HEADER64 {
      మాట_3 Magic;
      BYTE Major_Linker_సంస్కరణ;
      BYTE Minor_Linker_సంస్కరణ;
      DWORD కొలత_యొక్క_సంకేతం;
      DWORD కొలత_యొక్క_Initialized_దత్తాంశం;
      DWORD కొలత_యొక్క_Uninitialized_దత్తాంశం;
      DWORD చిరునామా_యొక్క_నమోదు_బిందువు;
      DWORD పునాది_యొక్క_సంకేతం;
      ULONGLONG Image_పునాది;
      DWORD SectionAlignment;
      DWORD FileAlignment;
      మాట_3 Major_Operating_System_సంస్కరణ;
      మాట_3 Minor_Operating_System_సంస్కరణ;
      మాట_3 Major_Image_సంస్కరణ;
      మాట_3 Minor_Image_సంస్కరణ;
      మాట_3 Major_Subsystem_సంస్కరణ;
      మాట_3 Minor_Subsystem_సంస్కరణ;
      DWORD Win32_సంస్కరణ_విలువ;
      DWORD కొలత_యొక్క_Image;
      DWORD కొలత_యొక్క_శీర్షికలు;
      DWORD Check_కూడిక;
      మాట_3 Subsystem;
      మాట_3 DllCharacteristics;
      ULONGLONG కొలత_యొక్క_దొంతర_Reserve;
      ULONGLONG కొలత_యొక్క_దొంతర_Commit;
      ULONGLONG కొలత_యొక్క_కుప్ప_Reserve;
      ULONGLONG కొలత_యొక్క_కుప్ప_Commit;
      DWORD LoaderFlags;
      DWORD సంఖ్య_యొక్క_Rva_And_Sizes;
      IMAGE_దత్తాంశం_DIRECTORY_2 దత్తాంశం_Directory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
    } IMAGE_OPTIONAL_HEADER64,*PIMAGE_OPTIONAL_HEADER64;

#నిర్వచించు IMAGE_SIZEOF_ROM_OPTIONAL_శీర్షిక 56
#నిర్వచించు IMAGE_SIZEOF_STD_OPTIONAL_శీర్షిక 28
#నిర్వచించు IMAGE_SIZEOF_NT_OPTIONAL32_శీర్షిక 224
#నిర్వచించు IMAGE_SIZEOF_NT_OPTIONAL64_శీర్షిక 240

#నిర్వచించు IMAGE_NT_OPTIONAL_HDR32_MAGIC 0x10b
#నిర్వచించు IMAGE_NT_OPTIONAL_HDR64_MAGIC 0x20b
#నిర్వచించు IMAGE_ROM_OPTIONAL_HDR_MAGIC 0x107

#నిర్వచితమైతే _WIN64
    రకనిర్వచనం IMAGE_OPTIONAL_HEADER64 IMAGE_OPTIONAL_శీర్షిక_2;
    రకనిర్వచనం PIMAGE_OPTIONAL_HEADER64 PIMAGE_OPTIONAL_శీర్షిక;
#నిర్వచించు IMAGE_SIZEOF_NT_OPTIONAL_శీర్షిక IMAGE_SIZEOF_NT_OPTIONAL64_శీర్షిక
#నిర్వచించు IMAGE_NT_OPTIONAL_HDR_MAGIC IMAGE_NT_OPTIONAL_HDR64_MAGIC
#లేకపోతే
    రకనిర్వచనం IMAGE_OPTIONAL_HEADER32 IMAGE_OPTIONAL_శీర్షిక_2;
    రకనిర్వచనం PIMAGE_OPTIONAL_HEADER32 PIMAGE_OPTIONAL_శీర్షిక;
#నిర్వచించు IMAGE_SIZEOF_NT_OPTIONAL_శీర్షిక IMAGE_SIZEOF_NT_OPTIONAL32_శీర్షిక
#నిర్వచించు IMAGE_NT_OPTIONAL_HDR_MAGIC IMAGE_NT_OPTIONAL_HDR32_MAGIC
#అయితే_ముగింపు

    రకనిర్వచనం నిర్మాణం _IMAGE_NT_HEADERS64 {
      DWORD Signature;
      IMAGE_FILE_శీర్షిక_2 File_శీర్షిక;
      IMAGE_OPTIONAL_HEADER64 Optional_శీర్షిక;
    } IMAGE_NT_HEADERS64,*PIMAGE_NT_HEADERS64;

    రకనిర్వచనం నిర్మాణం IMAGE_NT_శీర్షికలు {
      DWORD Signature;
      IMAGE_FILE_శీర్షిక_2 File_శీర్షిక;
      IMAGE_OPTIONAL_HEADER32 Optional_శీర్షిక;
    } IMAGE_NT_HEADERS32,*PIMAGE_NT_HEADERS32;

    రకనిర్వచనం నిర్మాణం IMAGE_ROM_శీర్షికలు {
      IMAGE_FILE_శీర్షిక_2 File_శీర్షిక;
      IMAGE_ROM_OPTIONAL_శీర్షిక_2 Optional_శీర్షిక;
    } IMAGE_ROM_శీర్షికలు_2,*PIMAGE_ROM_శీర్షికలు;

#నిర్వచితమైతే _WIN64
    రకనిర్వచనం IMAGE_NT_HEADERS64 IMAGE_NT_శీర్షికలు_2;
    రకనిర్వచనం PIMAGE_NT_HEADERS64 PIMAGE_NT_శీర్షికలు;
#లేకపోతే
    రకనిర్వచనం IMAGE_NT_HEADERS32 IMAGE_NT_శీర్షికలు_2;
    రకనిర్వచనం PIMAGE_NT_HEADERS32 PIMAGE_NT_శీర్షికలు;
#అయితే_ముగింపు

#నిర్వచించు IMAGE_మొదటి_SECTION(ntheader) ((PIMAGE_SECTION_శీర్షిక) ((ULONG_PTR)ntheader + క్షేత్రం_స్థానభ్రంశం(IMAGE_NT_శీర్షికలు_2,Optional_శీర్షిక) + ((PIMAGE_NT_శీర్షికలు)(ntheader))->File_శీర్షిక.కొలత_యొక్క_Optional_శీర్షిక))

#నిర్వచించు IMAGE_SUBSYSTEM_UNKNOWN 0
#నిర్వచించు IMAGE_SUBSYSTEM_NATIVE 1
#నిర్వచించు IMAGE_SUBSYSTEM_WINDOWS_GUI 2
#నిర్వచించు IMAGE_SUBSYSTEM_WINDOWS_CUI 3
#నిర్వచించు IMAGE_SUBSYSTEM_OS2_CUI 5
#నిర్వచించు IMAGE_SUBSYSTEM_POSIX_CUI 7
#నిర్వచించు IMAGE_SUBSYSTEM_NATIVE_WINDOWS 8
#నిర్వచించు IMAGE_SUBSYSTEM_WINDOWS_CE_GUI 9
#నిర్వచించు IMAGE_SUBSYSTEM_EFI_APPLICATION 10
#నిర్వచించు IMAGE_SUBSYSTEM_EFI_BOOT_SERVICE_DRIVER 11
#నిర్వచించు IMAGE_SUBSYSTEM_EFI_RUNTIME_DRIVER 12
#నిర్వచించు IMAGE_SUBSYSTEM_EFI_ROM 13
#నిర్వచించు IMAGE_SUBSYSTEM_XBOX 14

#నిర్వచించు IMAGE_DLLCHARACTERISTICS_ఎగువ_ENTROPY_VA 0x0020
#నిర్వచించు IMAGE_DLLCHARACTERISTICS_DYNAMIC_పునాది 0x0040
#నిర్వచించు IMAGE_DLLCHARACTERISTICS_FORCE_INTEGRITY 0x0080
#నిర్వచించు IMAGE_DLLCHARACTERISTICS_NX_COMPAT 0x0100
#నిర్వచించు IMAGE_DLLCHARACTERISTICS_NO_ISOLATION 0x0200
#నిర్వచించు IMAGE_DLLCHARACTERISTICS_NO_SEH 0x0400
#నిర్వచించు IMAGE_DLLCHARACTERISTICS_NO_BIND 0x0800
#నిర్వచించు IMAGE_DLLCHARACTERISTICS_APPCONTAINER 0x1000
#నిర్వచించు IMAGE_DLLCHARACTERISTICS_WDM_DRIVER 0x2000
#నిర్వచించు IMAGE_DLLCHARACTERISTICS_GUARD_CF 0x4000
#నిర్వచించు IMAGE_DLLCHARACTERISTICS_TERMINAL_SERVER_AWARE 0x8000

#నిర్వచించు IMAGE_DIRECTORY_నమోదు_EXPORT 0
#నిర్వచించు IMAGE_DIRECTORY_నమోదు_IMPORT 1
#నిర్వచించు IMAGE_DIRECTORY_నమోదు_RESOURCE 2
#నిర్వచించు IMAGE_DIRECTORY_నమోదు_EXCEPTION 3
#నిర్వచించు IMAGE_DIRECTORY_నమోదు_SECURITY 4
#నిర్వచించు IMAGE_DIRECTORY_నమోదు_BASERELOC 5
#నిర్వచించు IMAGE_DIRECTORY_నమోదు_DEBUG 6

#నిర్వచించు IMAGE_DIRECTORY_నమోదు_ARCHITECTURE 7
#నిర్వచించు IMAGE_DIRECTORY_నమోదు_GLOBALPTR 8
#నిర్వచించు IMAGE_DIRECTORY_నమోదు_TLS 9
#నిర్వచించు IMAGE_DIRECTORY_నమోదు_ఎక్కించు_CONFIG 10
#నిర్వచించు IMAGE_DIRECTORY_నమోదు_BOUND_IMPORT 11
#నిర్వచించు IMAGE_DIRECTORY_నమోదు_IAT 12
#నిర్వచించు IMAGE_DIRECTORY_నమోదు_DELAY_IMPORT 13
#నిర్వచించు IMAGE_DIRECTORY_నమోదు_COM_DESCRIPTOR 14

    రకనిర్వచనం నిర్మాణం ANON_OBJECT_శీర్షిక {
      మాట_3 Sig1;
      మాట_3 Sig2;
      మాట_3 సంస్కరణ_2;
      మాట_3 Machine;
      DWORD సమయం_Date_Stamp;
      CLSID ClassID;
      DWORD కొలత_యొక్క_దత్తాంశం;
    } ANON_OBJECT_శీర్షిక;

#నిర్వచించు IMAGE_SIZEOF_SHORT_NAME 8

    రకనిర్వచనం నిర్మాణం IMAGE_SECTION_శీర్షిక {
      BYTE Name[IMAGE_SIZEOF_SHORT_NAME];
      సంఘం {
	DWORD Physical_చిరునామా;
	DWORD Virtual_కొలత;
      } Misc;
      DWORD Virtual_చిరునామా;
      DWORD కొలత_యొక్క_Raw_దత్తాంశం;
      DWORD సూచిక_గమ్యం_Raw_దత్తాంశం;
      DWORD సూచిక_గమ్యం_Relocations;
      DWORD సూచిక_గమ్యం_Linenumbers;
      మాట_3 సంఖ్య_యొక్క_Relocations;
      మాట_3 సంఖ్య_యొక్క_Linenumbers;
      DWORD Characteristics;
    } IMAGE_SECTION_శీర్షిక_2,*PIMAGE_SECTION_శీర్షిక;

#నిర్వచించు IMAGE_SIZEOF_SECTION_శీర్షిక 40

#నిర్వచించు IMAGE_SCN_TYPE_NO_PAD 0x00000008

#నిర్వచించు IMAGE_SCN_CNT_సంకేతం 0x00000020
#నిర్వచించు IMAGE_SCN_CNT_INITIALIZED_దత్తాంశం 0x00000040
#నిర్వచించు IMAGE_SCN_CNT_UNINITIALIZED_దత్తాంశం 0x00000080
#నిర్వచించు IMAGE_SCN_LNK_OTHER 0x00000100
#నిర్వచించు IMAGE_SCN_LNK_INFO 0x00000200
#నిర్వచించు IMAGE_SCN_LNK_REMOVE 0x00000800
#నిర్వచించు IMAGE_SCN_LNK_COMDAT 0x00001000
#నిర్వచించు IMAGE_SCN_NO_DEFER_SPEC_EXC 0x00004000
#నిర్వచించు IMAGE_SCN_GPREL 0x00008000
#నిర్వచించు IMAGE_SCN_MEM_FARDATA 0x00008000
#నిర్వచించు IMAGE_SCN_MEM_PURGEABLE 0x00020000
#నిర్వచించు IMAGE_SCN_MEM_16_బిట్టు 0x00020000
#నిర్వచించు IMAGE_SCN_MEM_LOCKED 0x00040000
#నిర్వచించు IMAGE_SCN_MEM_PRELOAD 0x00080000

#నిర్వచించు IMAGE_SCN_ALIGN_1_బైట్లు 0x00100000
#నిర్వచించు IMAGE_SCN_ALIGN_2_బైట్లు 0x00200000
#నిర్వచించు IMAGE_SCN_ALIGN_4_బైట్లు 0x00300000
#నిర్వచించు IMAGE_SCN_ALIGN_8_బైట్లు 0x00400000
#నిర్వచించు IMAGE_SCN_ALIGN_16_బైట్లు 0x00500000
#నిర్వచించు IMAGE_SCN_ALIGN_32_బైట్లు 0x00600000
#నిర్వచించు IMAGE_SCN_ALIGN_64_బైట్లు 0x00700000
#నిర్వచించు IMAGE_SCN_ALIGN_128_బైట్లు 0x00800000
#నిర్వచించు IMAGE_SCN_ALIGN_256_బైట్లు 0x00900000
#నిర్వచించు IMAGE_SCN_ALIGN_512_బైట్లు 0x00A00000
#నిర్వచించు IMAGE_SCN_ALIGN_1024_బైట్లు 0x00B00000
#నిర్వచించు IMAGE_SCN_ALIGN_2048_బైట్లు 0x00C00000
#నిర్వచించు IMAGE_SCN_ALIGN_4096_బైట్లు 0x00D00000
#నిర్వచించు IMAGE_SCN_ALIGN_8192_బైట్లు 0x00E00000

#నిర్వచించు IMAGE_SCN_ALIGN_ముసుగు 0x00F00000

#నిర్వచించు IMAGE_SCN_LNK_NRELOC_OVFL 0x01000000
#నిర్వచించు IMAGE_SCN_MEM_DISCARDABLE 0x02000000
#నిర్వచించు IMAGE_SCN_MEM_NOT_CACHED 0x04000000
#నిర్వచించు IMAGE_SCN_MEM_NOT_PAGED 0x08000000
#నిర్వచించు IMAGE_SCN_MEM_SHARED 0x10000000
#నిర్వచించు IMAGE_SCN_MEM_EXECUTE 0x20000000
#నిర్వచించు IMAGE_SCN_MEM_READ 0x40000000
#నిర్వచించు IMAGE_SCN_MEM_WRITE 0x80000000

#నిర్వచించు IMAGE_SCN_SCALE_సూచీ 0x00000001

#అన్తర్భావ "pshpack2.h"

    రకనిర్వచనం నిర్మాణం IMAGE_చిహ్నం {
      సంఘం {
	BYTE ShortName[8];
	నిర్మాణం {
	  DWORD Short;
	  DWORD Long;
	} Name;
	DWORD LongName[2];
      } N;
      DWORD విలువ_3;
      SHORT Section_సంఖ్య;
      మాట_3 Type;
      BYTE StorageClass;
      BYTE సంఖ్య_యొక్క_Aux_Symbols;
    } IMAGE_చిహ్నం_2;
    రకనిర్వచనం IMAGE_చిహ్నం_2 UNALIGNED *PIMAGE_చిహ్నం;

#నిర్వచించు IMAGE_SIZEOF_చిహ్నం 18

#నిర్వచించు IMAGE_SYM_UNDEFINED (SHORT)0
#నిర్వచించు IMAGE_SYM_ABSOLUTE (SHORT)-1
#నిర్వచించు IMAGE_SYM_DEBUG (SHORT)-2
#నిర్వచించు IMAGE_SYM_SECTION_MAX 0xFEFF

#నిర్వచించు IMAGE_SYM_TYPE_NULL 0x0000
#నిర్వచించు IMAGE_SYM_TYPE_VOID 0x0001
#నిర్వచించు IMAGE_SYM_TYPE_CHAR 0x0002
#నిర్వచించు IMAGE_SYM_TYPE_SHORT 0x0003
#నిర్వచించు IMAGE_SYM_TYPE_INT 0x0004
#నిర్వచించు IMAGE_SYM_TYPE_LONG 0x0005
#నిర్వచించు IMAGE_SYM_TYPE_FLOAT 0x0006
#నిర్వచించు IMAGE_SYM_TYPE_DOUBLE 0x0007
#నిర్వచించు IMAGE_SYM_TYPE_STRUCT 0x0008
#నిర్వచించు IMAGE_SYM_TYPE_UNION 0x0009
#నిర్వచించు IMAGE_SYM_TYPE_ENUM 0x000A
#నిర్వచించు IMAGE_SYM_TYPE_MOE 0x000B
#నిర్వచించు IMAGE_SYM_TYPE_BYTE 0x000C
#నిర్వచించు IMAGE_SYM_TYPE_మాట 0x000D
#నిర్వచించు IMAGE_SYM_TYPE_UINT 0x000E
#నిర్వచించు IMAGE_SYM_TYPE_DWORD 0x000F
#నిర్వచించు IMAGE_SYM_TYPE_PCODE 0x8000

#నిర్వచించు IMAGE_SYM_DTYPE_NULL 0
#నిర్వచించు IMAGE_SYM_DTYPE_సూచిక 1
#నిర్వచించు IMAGE_SYM_DTYPE_FUNCTION 2
#నిర్వచించు IMAGE_SYM_DTYPE_ARRAY 3

#నిర్వచించు IMAGE_SYM_CLASS_చివర_యొక్క_FUNCTION (BYTE)-1
#నిర్వచించు IMAGE_SYM_CLASS_NULL 0x0000
#నిర్వచించు IMAGE_SYM_CLASS_AUTOMATIC 0x0001
#నిర్వచించు IMAGE_SYM_CLASS_EXTERNAL 0x0002
#నిర్వచించు IMAGE_SYM_CLASS_STATIC 0x0003
#నిర్వచించు IMAGE_SYM_CLASS_రిజిస్టరు 0x0004
#నిర్వచించు IMAGE_SYM_CLASS_EXTERNAL_DEF 0x0005
#నిర్వచించు IMAGE_SYM_CLASS_LABEL 0x0006
#నిర్వచించు IMAGE_SYM_CLASS_UNDEFINED_LABEL 0x0007
#నిర్వచించు IMAGE_SYM_CLASS_MEMBER_యొక్క_STRUCT 0x0008
#నిర్వచించు IMAGE_SYM_CLASS_వాదం 0x0009
#నిర్వచించు IMAGE_SYM_CLASS_STRUCT_ట్యాగ్ 0x000A
#నిర్వచించు IMAGE_SYM_CLASS_MEMBER_యొక్క_UNION 0x000B
#నిర్వచించు IMAGE_SYM_CLASS_UNION_ట్యాగ్ 0x000C
#నిర్వచించు IMAGE_SYM_CLASS_TYPE_DEFINITION 0x000D
#నిర్వచించు IMAGE_SYM_CLASS_UNDEFINED_STATIC 0x000E
#నిర్వచించు IMAGE_SYM_CLASS_ENUM_ట్యాగ్ 0x000F
#నిర్వచించు IMAGE_SYM_CLASS_MEMBER_యొక్క_ENUM 0x0010
#నిర్వచించు IMAGE_SYM_CLASS_రిజిస్టరు_PARAM 0x0011
#నిర్వచించు IMAGE_SYM_CLASS_బిట్టు_క్షేత్రం 0x0012
#నిర్వచించు IMAGE_SYM_CLASS_FAR_EXTERNAL 0x0044
#నిర్వచించు IMAGE_SYM_CLASS_ఖండం 0x0064
#నిర్వచించు IMAGE_SYM_CLASS_FUNCTION 0x0065
#నిర్వచించు IMAGE_SYM_CLASS_చివర_యొక్క_STRUCT 0x0066
#నిర్వచించు IMAGE_SYM_CLASS_FILE 0x0067
#నిర్వచించు IMAGE_SYM_CLASS_SECTION 0x0068
#నిర్వచించు IMAGE_SYM_CLASS_WEAK_EXTERNAL 0x0069
#నిర్వచించు IMAGE_SYM_CLASS_CLR_TOKEN 0x006B

#నిర్వచించు N_BTMASK 0x000F
#నిర్వచించు N_TMASK 0x0030
#నిర్వచించు N_TMASK1 0x00C0
#నిర్వచించు N_TMASK2 0x00F0
#నిర్వచించు N_BTSHFT 4
#నిర్వచించు N_TSHIFT 2

#నిర్వచించు BTYPE(x) ((x) & N_BTMASK)

#నిర్వచితం_కాకపోతే ISPTR
#నిర్వచించు ISPTR(x) (((x) & N_TMASK)==(IMAGE_SYM_DTYPE_సూచిక << N_BTSHFT))
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే ISFCN
#నిర్వచించు ISFCN(x) (((x) & N_TMASK)==(IMAGE_SYM_DTYPE_FUNCTION << N_BTSHFT))
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే ISARY
#నిర్వచించు ISARY(x) (((x) & N_TMASK)==(IMAGE_SYM_DTYPE_ARRAY << N_BTSHFT))
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే ISTAG
#నిర్వచించు ISTAG(x) ((x)==IMAGE_SYM_CLASS_STRUCT_ట్యాగ్ || (x)==IMAGE_SYM_CLASS_UNION_ట్యాగ్ || (x)==IMAGE_SYM_CLASS_ENUM_ట్యాగ్)
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే INCREF
#నిర్వచించు INCREF(x) ((((x)&~N_BTMASK)<<N_TSHIFT)|(IMAGE_SYM_DTYPE_సూచిక<<N_BTSHFT)|((x)&N_BTMASK))
#అయితే_ముగింపు
#నిర్వచితం_కాకపోతే DECREF
#నిర్వచించు DECREF(x) ((((x)>>N_TSHIFT)&~N_BTMASK)|((x)&N_BTMASK))
#అయితే_ముగింపు

    రకనిర్వచనం సంఘం IMAGE_AUX_చిహ్నం {
      నిర్మాణం {
	DWORD ట్యాగ్_సూచీ;
	సంఘం {
	  నిర్మాణం {
	    మాట_3 Linenumber;
	    మాట_3 కొలత_3;
	  } LnSz;
	  DWORD మొత్తం_కొలత;
	} Misc;
	సంఘం {
	  నిర్మాణం {
	    DWORD సూచిక_గమ్యం_Linenumber;
	    DWORD సూచిక_గమ్యం_తదుపరి_Function;
	  } Function;
	  నిర్మాణం {
	    మాట_3 Dimension[4];
	  } Array;
	} FcnAry;
	మాట_3 Tv_సూచీ;
      } Sym;
      నిర్మాణం {
	BYTE Name[IMAGE_SIZEOF_చిహ్నం];
      } File;
      నిర్మాణం {
	DWORD నిడివి_2;
	మాట_3 సంఖ్య_యొక్క_Relocations;
	మాట_3 సంఖ్య_యొక్క_Linenumbers;
	DWORD Check_కూడిక;
	SHORT సంఖ్య_2;
	BYTE Selection;
      } Section;
    } IMAGE_AUX_చిహ్నం_2;
    రకనిర్వచనం IMAGE_AUX_చిహ్నం_2 UNALIGNED *PIMAGE_AUX_చిహ్నం;

#నిర్వచించు IMAGE_SIZEOF_AUX_చిహ్నం 18

    రకనిర్వచనం గణన IMAGE_AUX_చిహ్నం_TYPE {
      IMAGE_AUX_చిహ్నం_TYPE_TOKEN_DEF = 1
    } IMAGE_AUX_చిహ్నం_TYPE;

#అన్తర్భావ <pshpack2.h>

    రకనిర్వచనం నిర్మాణం IMAGE_AUX_చిహ్నం_TOKEN_DEF {
      BYTE bAuxType;
      BYTE bReserved;
      DWORD చిహ్నం_పట్టిక_సూచీ;
      BYTE rgbReserved[12];
    } IMAGE_AUX_చిహ్నం_TOKEN_DEF;

    రకనిర్వచనం IMAGE_AUX_చిహ్నం_TOKEN_DEF UNALIGNED *PIMAGE_AUX_చిహ్నం_TOKEN_DEF;

#అన్తర్భావ <poppack.h>

#నిర్వచించు IMAGE_COMDAT_SELECT_NODUPLICATES 1
#నిర్వచించు IMAGE_COMDAT_SELECT_ANY 2
#నిర్వచించు IMAGE_COMDAT_SELECT_SAME_కొలత 3
#నిర్వచించు IMAGE_COMDAT_SELECT_EXACT_సరిపోలిక 4
#నిర్వచించు IMAGE_COMDAT_SELECT_ASSOCIATIVE 5
#నిర్వచించు IMAGE_COMDAT_SELECT_అతిపెద్ద 6
#నిర్వచించు IMAGE_COMDAT_SELECT_NEWEST 7

#నిర్వచించు IMAGE_WEAK_EXTERN_శోధన_NOLIBRARY 1
#నిర్వచించు IMAGE_WEAK_EXTERN_శోధన_LIBRARY 2
#నిర్వచించు IMAGE_WEAK_EXTERN_శోధన_ALIAS 3

    రకనిర్వచనం నిర్మాణం _IMAGE_RELOCATION {
      సంఘం {
	DWORD Virtual_చిరునామా;
	DWORD Reloc_లెక్క;
      };
      DWORD చిహ్నం_పట్టిక_సూచీ;
      మాట_3 Type;
    } IMAGE_RELOCATION;
    రకనిర్వచనం IMAGE_RELOCATION UNALIGNED *PIMAGE_RELOCATION;

#నిర్వచించు IMAGE_SIZEOF_RELOCATION 10

#నిర్వచించు IMAGE_REL_I386_ABSOLUTE 0x0000
#నిర్వచించు IMAGE_REL_I386_DIR16 0x0001
#నిర్వచించు IMAGE_REL_I386_REL16 0x0002
#నిర్వచించు IMAGE_REL_I386_DIR32 0x0006
#నిర్వచించు IMAGE_REL_I386_DIR32NB 0x0007
#నిర్వచించు IMAGE_REL_I386_SEG12 0x0009
#నిర్వచించు IMAGE_REL_I386_SECTION 0x000A
#నిర్వచించు IMAGE_REL_I386_SECREL 0x000B
#నిర్వచించు IMAGE_REL_I386_TOKEN 0x000C
#నిర్వచించు IMAGE_REL_I386_SECREL7 0x000D
#నిర్వచించు IMAGE_REL_I386_REL32 0x0014

#నిర్వచించు IMAGE_REL_MIPS_ABSOLUTE 0x0000
#నిర్వచించు IMAGE_REL_MIPS_REFHALF 0x0001
#నిర్వచించు IMAGE_REL_MIPS_REFWORD 0x0002
#నిర్వచించు IMAGE_REL_MIPS_JMPADDR 0x0003
#నిర్వచించు IMAGE_REL_MIPS_REFHI 0x0004
#నిర్వచించు IMAGE_REL_MIPS_REFLO 0x0005
#నిర్వచించు IMAGE_REL_MIPS_GPREL 0x0006
#నిర్వచించు IMAGE_REL_MIPS_LITERAL 0x0007
#నిర్వచించు IMAGE_REL_MIPS_SECTION 0x000A
#నిర్వచించు IMAGE_REL_MIPS_SECREL 0x000B
#నిర్వచించు IMAGE_REL_MIPS_SECRELLO 0x000C
#నిర్వచించు IMAGE_REL_MIPS_SECRELHI 0x000D
#నిర్వచించు IMAGE_REL_MIPS_TOKEN 0x000E
#నిర్వచించు IMAGE_REL_MIPS_JMPADDR16 0x0010
#నిర్వచించు IMAGE_REL_MIPS_REFWORDNB 0x0022
#నిర్వచించు IMAGE_REL_MIPS_PAIR 0x0025

#నిర్వచించు IMAGE_REL_ALPHA_ABSOLUTE 0x0000
#నిర్వచించు IMAGE_REL_ALPHA_REFLONG 0x0001
#నిర్వచించు IMAGE_REL_ALPHA_REFQUAD 0x0002
#నిర్వచించు IMAGE_REL_ALPHA_GPREL32 0x0003
#నిర్వచించు IMAGE_REL_ALPHA_LITERAL 0x0004
#నిర్వచించు IMAGE_REL_ALPHA_LITUSE 0x0005
#నిర్వచించు IMAGE_REL_ALPHA_GPDISP 0x0006
#నిర్వచించు IMAGE_REL_ALPHA_BRADDR 0x0007
#నిర్వచించు IMAGE_REL_ALPHA_HINT 0x0008
#నిర్వచించు IMAGE_REL_ALPHA_INLINE_REFLONG 0x0009
#నిర్వచించు IMAGE_REL_ALPHA_REFHI 0x000A
#నిర్వచించు IMAGE_REL_ALPHA_REFLO 0x000B
#నిర్వచించు IMAGE_REL_ALPHA_PAIR 0x000C
#నిర్వచించు IMAGE_REL_ALPHA_సరిపోలిక 0x000D
#నిర్వచించు IMAGE_REL_ALPHA_SECTION 0x000E
#నిర్వచించు IMAGE_REL_ALPHA_SECREL 0x000F
#నిర్వచించు IMAGE_REL_ALPHA_REFLONGNB 0x0010
#నిర్వచించు IMAGE_REL_ALPHA_SECRELLO 0x0011
#నిర్వచించు IMAGE_REL_ALPHA_SECRELHI 0x0012
#నిర్వచించు IMAGE_REL_ALPHA_REFQ3 0x0013
#నిర్వచించు IMAGE_REL_ALPHA_REFQ2 0x0014
#నిర్వచించు IMAGE_REL_ALPHA_REFQ1 0x0015
#నిర్వచించు IMAGE_REL_ALPHA_GPRELLO 0x0016
#నిర్వచించు IMAGE_REL_ALPHA_GPRELHI 0x0017

#నిర్వచించు IMAGE_REL_PPC_ABSOLUTE 0x0000
#నిర్వచించు IMAGE_REL_PPC_ADDR64 0x0001
#నిర్వచించు IMAGE_REL_PPC_ADDR32 0x0002
#నిర్వచించు IMAGE_REL_PPC_ADDR24 0x0003
#నిర్వచించు IMAGE_REL_PPC_ADDR16 0x0004
#నిర్వచించు IMAGE_REL_PPC_ADDR14 0x0005
#నిర్వచించు IMAGE_REL_PPC_REL24 0x0006
#నిర్వచించు IMAGE_REL_PPC_REL14 0x0007
#నిర్వచించు IMAGE_REL_PPC_TOCREL16 0x0008
#నిర్వచించు IMAGE_REL_PPC_TOCREL14 0x0009
#నిర్వచించు IMAGE_REL_PPC_ADDR32NB 0x000A
#నిర్వచించు IMAGE_REL_PPC_SECREL 0x000B
#నిర్వచించు IMAGE_REL_PPC_SECTION 0x000C
#నిర్వచించు IMAGE_REL_PPC_IFGLUE 0x000D
#నిర్వచించు IMAGE_REL_PPC_IMGLUE 0x000E
#నిర్వచించు IMAGE_REL_PPC_SECREL16 0x000F
#నిర్వచించు IMAGE_REL_PPC_REFHI 0x0010
#నిర్వచించు IMAGE_REL_PPC_REFLO 0x0011
#నిర్వచించు IMAGE_REL_PPC_PAIR 0x0012
#నిర్వచించు IMAGE_REL_PPC_SECRELLO 0x0013
#నిర్వచించు IMAGE_REL_PPC_SECRELHI 0x0014
#నిర్వచించు IMAGE_REL_PPC_GPREL 0x0015
#నిర్వచించు IMAGE_REL_PPC_TOKEN 0x0016
#నిర్వచించు IMAGE_REL_PPC_TYPEMASK 0x00FF
#నిర్వచించు IMAGE_REL_PPC_NEG 0x0100
#నిర్వచించు IMAGE_REL_PPC_BRTAKEN 0x0200
#నిర్వచించు IMAGE_REL_PPC_BRNTAKEN 0x0400
#నిర్వచించు IMAGE_REL_PPC_TOCDEFN 0x0800

#నిర్వచించు IMAGE_REL_SH3_ABSOLUTE 0x0000
#నిర్వచించు IMAGE_REL_SH3_DIRECT16 0x0001
#నిర్వచించు IMAGE_REL_SH3_DIRECT32 0x0002
#నిర్వచించు IMAGE_REL_SH3_DIRECT8 0x0003
#నిర్వచించు IMAGE_REL_SH3_DIRECT8_మాట 0x0004
#నిర్వచించు IMAGE_REL_SH3_DIRECT8_LONG 0x0005
#నిర్వచించు IMAGE_REL_SH3_DIRECT4 0x0006
#నిర్వచించు IMAGE_REL_SH3_DIRECT4_మాట 0x0007
#నిర్వచించు IMAGE_REL_SH3_DIRECT4_LONG 0x0008
#నిర్వచించు IMAGE_REL_SH3_PCREL8_మాట 0x0009
#నిర్వచించు IMAGE_REL_SH3_PCREL8_LONG 0x000A
#నిర్వచించు IMAGE_REL_SH3_PCREL12_మాట 0x000B
#నిర్వచించు IMAGE_REL_SH3_STARTOF_SECTION 0x000C
#నిర్వచించు IMAGE_REL_SH3_SIZEOF_SECTION 0x000D
#నిర్వచించు IMAGE_REL_SH3_SECTION 0x000E
#నిర్వచించు IMAGE_REL_SH3_SECREL 0x000F
#నిర్వచించు IMAGE_REL_SH3_DIRECT32_NB 0x0010
#నిర్వచించు IMAGE_REL_SH3_GPREL4_LONG 0x0011
#నిర్వచించు IMAGE_REL_SH3_TOKEN 0x0012

#నిర్వచించు IMAGE_REL_SHM_PCRELPT 0x0013
#నిర్వచించు IMAGE_REL_SHM_REFLO 0x0014
#నిర్వచించు IMAGE_REL_SHM_REFHALF 0x0015
#నిర్వచించు IMAGE_REL_SHM_RELLO 0x0016
#నిర్వచించు IMAGE_REL_SHM_RELHALF 0x0017
#నిర్వచించు IMAGE_REL_SHM_PAIR 0x0018

#నిర్వచించు IMAGE_REL_SH_NOMODE 0x8000

#నిర్వచించు IMAGE_REL_ARM_ABSOLUTE 0x0000
#నిర్వచించు IMAGE_REL_ARM_ADDR32 0x0001
#నిర్వచించు IMAGE_REL_ARM_ADDR32NB 0x0002
#నిర్వచించు IMAGE_REL_ARM_BRANCH24 0x0003
#నిర్వచించు IMAGE_REL_ARM_BRANCH11 0x0004
#నిర్వచించు IMAGE_REL_ARM_TOKEN 0x0005
#నిర్వచించు IMAGE_REL_ARM_GPREL12 0x0006
#నిర్వచించు IMAGE_REL_ARM_GPREL7 0x0007
#నిర్వచించు IMAGE_REL_ARM_BLX24 0x0008
#నిర్వచించు IMAGE_REL_ARM_BLX11 0x0009
#నిర్వచించు IMAGE_REL_ARM_SECTION 0x000E
#నిర్వచించు IMAGE_REL_ARM_SECREL 0x000F

#నిర్వచించు IMAGE_REL_AM_ABSOLUTE 0x0000
#నిర్వచించు IMAGE_REL_AM_ADDR32 0x0001
#నిర్వచించు IMAGE_REL_AM_ADDR32NB 0x0002
#నిర్వచించు IMAGE_REL_AM_CALL32 0x0003
#నిర్వచించు IMAGE_REL_AM_FUNCINFO 0x0004
#నిర్వచించు IMAGE_REL_AM_REL32_1 0x0005
#నిర్వచించు IMAGE_REL_AM_REL32_2 0x0006
#నిర్వచించు IMAGE_REL_AM_SECREL 0x0007
#నిర్వచించు IMAGE_REL_AM_SECTION 0x0008
#నిర్వచించు IMAGE_REL_AM_TOKEN 0x0009

#నిర్వచించు IMAGE_REL_AMD64_ABSOLUTE 0x0000
#నిర్వచించు IMAGE_REL_AMD64_ADDR64 0x0001
#నిర్వచించు IMAGE_REL_AMD64_ADDR32 0x0002
#నిర్వచించు IMAGE_REL_AMD64_ADDR32NB 0x0003
#నిర్వచించు IMAGE_REL_AMD64_REL32 0x0004
#నిర్వచించు IMAGE_REL_AMD64_REL32_1 0x0005
#నిర్వచించు IMAGE_REL_AMD64_REL32_2 0x0006
#నిర్వచించు IMAGE_REL_AMD64_REL32_3 0x0007
#నిర్వచించు IMAGE_REL_AMD64_REL32_4 0x0008
#నిర్వచించు IMAGE_REL_AMD64_REL32_5 0x0009
#నిర్వచించు IMAGE_REL_AMD64_SECTION 0x000A
#నిర్వచించు IMAGE_REL_AMD64_SECREL 0x000B
#నిర్వచించు IMAGE_REL_AMD64_SECREL7 0x000C
#నిర్వచించు IMAGE_REL_AMD64_TOKEN 0x000D
#నిర్వచించు IMAGE_REL_AMD64_SREL32 0x000E
#నిర్వచించు IMAGE_REL_AMD64_PAIR 0x000F
#నిర్వచించు IMAGE_REL_AMD64_SSPAN32 0x0010

#నిర్వచించు IMAGE_REL_IA64_ABSOLUTE 0x0000
#నిర్వచించు IMAGE_REL_IA64_IMM14 0x0001
#నిర్వచించు IMAGE_REL_IA64_IMM22 0x0002
#నిర్వచించు IMAGE_REL_IA64_IMM64 0x0003
#నిర్వచించు IMAGE_REL_IA64_DIR32 0x0004
#నిర్వచించు IMAGE_REL_IA64_DIR64 0x0005
#నిర్వచించు IMAGE_REL_IA64_PCREL21B 0x0006
#నిర్వచించు IMAGE_REL_IA64_PCREL21M 0x0007
#నిర్వచించు IMAGE_REL_IA64_PCREL21F 0x0008
#నిర్వచించు IMAGE_REL_IA64_GPREL22 0x0009
#నిర్వచించు IMAGE_REL_IA64_LTOFF22 0x000A
#నిర్వచించు IMAGE_REL_IA64_SECTION 0x000B
#నిర్వచించు IMAGE_REL_IA64_SECREL22 0x000C
#నిర్వచించు IMAGE_REL_IA64_SECREL64I 0x000D
#నిర్వచించు IMAGE_REL_IA64_SECREL32 0x000E

#నిర్వచించు IMAGE_REL_IA64_DIR32NB 0x0010
#నిర్వచించు IMAGE_REL_IA64_SREL14 0x0011
#నిర్వచించు IMAGE_REL_IA64_SREL22 0x0012
#నిర్వచించు IMAGE_REL_IA64_SREL32 0x0013
#నిర్వచించు IMAGE_REL_IA64_UREL32 0x0014
#నిర్వచించు IMAGE_REL_IA64_PCREL60X 0x0015
#నిర్వచించు IMAGE_REL_IA64_PCREL60B 0x0016
#నిర్వచించు IMAGE_REL_IA64_PCREL60F 0x0017
#నిర్వచించు IMAGE_REL_IA64_PCREL60I 0x0018
#నిర్వచించు IMAGE_REL_IA64_PCREL60M 0x0019
#నిర్వచించు IMAGE_REL_IA64_IMMGPREL64 0x001A
#నిర్వచించు IMAGE_REL_IA64_TOKEN 0x001B
#నిర్వచించు IMAGE_REL_IA64_GPREL32 0x001C
#నిర్వచించు IMAGE_REL_IA64_ADDEND 0x001F

#నిర్వచించు IMAGE_REL_CEF_ABSOLUTE 0x0000
#నిర్వచించు IMAGE_REL_CEF_ADDR32 0x0001
#నిర్వచించు IMAGE_REL_CEF_ADDR64 0x0002
#నిర్వచించు IMAGE_REL_CEF_ADDR32NB 0x0003
#నిర్వచించు IMAGE_REL_CEF_SECTION 0x0004
#నిర్వచించు IMAGE_REL_CEF_SECREL 0x0005
#నిర్వచించు IMAGE_REL_CEF_TOKEN 0x0006

#నిర్వచించు IMAGE_REL_CEE_ABSOLUTE 0x0000
#నిర్వచించు IMAGE_REL_CEE_ADDR32 0x0001
#నిర్వచించు IMAGE_REL_CEE_ADDR64 0x0002
#నిర్వచించు IMAGE_REL_CEE_ADDR32NB 0x0003
#నిర్వచించు IMAGE_REL_CEE_SECTION 0x0004
#నిర్వచించు IMAGE_REL_CEE_SECREL 0x0005
#నిర్వచించు IMAGE_REL_CEE_TOKEN 0x0006

#నిర్వచించు IMAGE_REL_M32R_ABSOLUTE 0x0000
#నిర్వచించు IMAGE_REL_M32R_ADDR32 0x0001
#నిర్వచించు IMAGE_REL_M32R_ADDR32NB 0x0002
#నిర్వచించు IMAGE_REL_M32R_ADDR24 0x0003
#నిర్వచించు IMAGE_REL_M32R_GPREL16 0x0004
#నిర్వచించు IMAGE_REL_M32R_PCREL24 0x0005
#నిర్వచించు IMAGE_REL_M32R_PCREL16 0x0006
#నిర్వచించు IMAGE_REL_M32R_PCREL8 0x0007
#నిర్వచించు IMAGE_REL_M32R_REFHALF 0x0008
#నిర్వచించు IMAGE_REL_M32R_REFHI 0x0009
#నిర్వచించు IMAGE_REL_M32R_REFLO 0x000A
#నిర్వచించు IMAGE_REL_M32R_PAIR 0x000B
#నిర్వచించు IMAGE_REL_M32R_SECTION 0x000C
#నిర్వచించు IMAGE_REL_M32R_SECREL32 0x000D
#నిర్వచించు IMAGE_REL_M32R_TOKEN 0x000E

#నిర్వచించు EXT_IMM64(విలువ_3,చిరునామా_2,కొలత_3,InstPos,ValPos) విలువ_3 |= (((ULONGLONG)((*(చిరునామా_2) >> InstPos) & (((ULONGLONG)1 << కొలత_3) - 1))) << ValPos)
#నిర్వచించు INS_IMM64(విలువ_3,చిరునామా_2,కొలత_3,InstPos,ValPos) *(PDWORD)చిరునామా_2 = (*(PDWORD)చిరునామా_2 & ~(((1 << కొలత_3) - 1) << InstPos)) | ((DWORD)((((ULONGLONG)విలువ_3 >> ValPos) & (((ULONGLONG)1 << కొలత_3) - 1))) << InstPos)

#నిర్వచించు EMARCH_ENC_I17_IMM7_B_INST_మాట_X 3
#నిర్వచించు EMARCH_ENC_I17_IMM7_B_కొలత_X 7
#నిర్వచించు EMARCH_ENC_I17_IMM7_B_INST_మాట_POS_X 4
#నిర్వచించు EMARCH_ENC_I17_IMM7B_VAL_POS_X 0

#నిర్వచించు EMARCH_ENC_I17_IMM9_D_INST_మాట_X 3
#నిర్వచించు EMARCH_ENC_I17_IMM9_D_కొలత_X 9
#నిర్వచించు EMARCH_ENC_I17_IMM9_D_INST_మాట_POS_X 18
#నిర్వచించు EMARCH_ENC_I17_IMM9D_VAL_POS_X 7

#నిర్వచించు EMARCH_ENC_I17_IMM5_C_INST_మాట_X 3
#నిర్వచించు EMARCH_ENC_I17_IMM5_C_కొలత_X 5
#నిర్వచించు EMARCH_ENC_I17_IMM5_C_INST_మాట_POS_X 13
#నిర్వచించు EMARCH_ENC_I17_IMM5C_VAL_POS_X 16

#నిర్వచించు EMARCH_ENC_I17_IC_INST_మాట_X 3
#నిర్వచించు EMARCH_ENC_I17_IC_కొలత_X 1
#నిర్వచించు EMARCH_ENC_I17_IC_INST_మాట_POS_X 12
#నిర్వచించు EMARCH_ENC_I17_IC_VAL_POS_X 21

#నిర్వచించు EMARCH_ENC_I17_IMM41a_INST_మాట_X 1
#నిర్వచించు EMARCH_ENC_I17_IMM41a_కొలత_X 10
#నిర్వచించు EMARCH_ENC_I17_IMM41a_INST_మాట_POS_X 14
#నిర్వచించు EMARCH_ENC_I17_IMM41a_VAL_POS_X 22

#నిర్వచించు EMARCH_ENC_I17_IMM41b_INST_మాట_X 1
#నిర్వచించు EMARCH_ENC_I17_IMM41b_కొలత_X 8
#నిర్వచించు EMARCH_ENC_I17_IMM41b_INST_మాట_POS_X 24
#నిర్వచించు EMARCH_ENC_I17_IMM41b_VAL_POS_X 32

#నిర్వచించు EMARCH_ENC_I17_IMM41c_INST_మాట_X 2
#నిర్వచించు EMARCH_ENC_I17_IMM41c_కొలత_X 23
#నిర్వచించు EMARCH_ENC_I17_IMM41c_INST_మాట_POS_X 0
#నిర్వచించు EMARCH_ENC_I17_IMM41c_VAL_POS_X 40

#నిర్వచించు EMARCH_ENC_I17_SIGN_INST_మాట_X 3
#నిర్వచించు EMARCH_ENC_I17_SIGN_కొలత_X 1
#నిర్వచించు EMARCH_ENC_I17_SIGN_INST_మాట_POS_X 27
#నిర్వచించు EMARCH_ENC_I17_SIGN_VAL_POS_X 63

#నిర్వచించు X3_OPCODE_INST_మాట_X 3
#నిర్వచించు X3_OPCODE_కొలత_X 4
#నిర్వచించు X3_OPCODE_INST_మాట_POS_X 28
#నిర్వచించు X3_OPCODE_SIGN_VAL_POS_X 0

#నిర్వచించు X3_I_INST_మాట_X 3
#నిర్వచించు X3_I_కొలత_X 1
#నిర్వచించు X3_I_INST_మాట_POS_X 27
#నిర్వచించు X3_I_SIGN_VAL_POS_X 59

#నిర్వచించు X3_D_WH_INST_మాట_X 3
#నిర్వచించు X3_D_WH_కొలత_X 3
#నిర్వచించు X3_D_WH_INST_మాట_POS_X 24
#నిర్వచించు X3_D_WH_SIGN_VAL_POS_X 0

#నిర్వచించు X3_IMM20_INST_మాట_X 3
#నిర్వచించు X3_IMM20_కొలత_X 20
#నిర్వచించు X3_IMM20_INST_మాట_POS_X 4
#నిర్వచించు X3_IMM20_SIGN_VAL_POS_X 0

#నిర్వచించు X3_IMM39_1_INST_మాట_X 2
#నిర్వచించు X3_IMM39_1_కొలత_X 23
#నిర్వచించు X3_IMM39_1_INST_మాట_POS_X 0
#నిర్వచించు X3_IMM39_1_SIGN_VAL_POS_X 36

#నిర్వచించు X3_IMM39_2_INST_మాట_X 1
#నిర్వచించు X3_IMM39_2_కొలత_X 16
#నిర్వచించు X3_IMM39_2_INST_మాట_POS_X 16
#నిర్వచించు X3_IMM39_2_SIGN_VAL_POS_X 20

#నిర్వచించు X3_P_INST_మాట_X 3
#నిర్వచించు X3_P_కొలత_X 4
#నిర్వచించు X3_P_INST_మాట_POS_X 0
#నిర్వచించు X3_P_SIGN_VAL_POS_X 0

#నిర్వచించు X3_TMPLT_INST_మాట_X 0
#నిర్వచించు X3_TMPLT_కొలత_X 4
#నిర్వచించు X3_TMPLT_INST_మాట_POS_X 0
#నిర్వచించు X3_TMPLT_SIGN_VAL_POS_X 0

#నిర్వచించు X3_BTYPE_QP_INST_మాట_X 2
#నిర్వచించు X3_BTYPE_QP_కొలత_X 9
#నిర్వచించు X3_BTYPE_QP_INST_మాట_POS_X 23
#నిర్వచించు X3_BTYPE_QP_INST_VAL_POS_X 0

#నిర్వచించు X3_ఖాళీలు_INST_మాట_X 1
#నిర్వచించు X3_ఖాళీలు_కొలత_X 2
#నిర్వచించు X3_ఖాళీలు_INST_మాట_POS_X 14
#నిర్వచించు X3_ఖాళీలు_INST_VAL_POS_X 0

    రకనిర్వచనం నిర్మాణం _IMAGE_LINENUMBER {
      సంఘం {
	DWORD చిహ్నం_పట్టిక_సూచీ;
	DWORD Virtual_చిరునామా;
      } Type;
      మాట_3 Linenumber;
    } IMAGE_LINENUMBER;
    రకనిర్వచనం IMAGE_LINENUMBER UNALIGNED *PIMAGE_LINENUMBER;

#నిర్వచించు IMAGE_SIZEOF_LINENUMBER 6

#అన్తర్భావ "poppack.h"

    రకనిర్వచనం నిర్మాణం IMAGE_పునాది_RELOCATION {
      DWORD Virtual_చిరునామా;
      DWORD కొలత_యొక్క_ఖండం;

    } IMAGE_పునాది_RELOCATION_2;
    రకనిర్వచనం IMAGE_పునాది_RELOCATION_2 UNALIGNED *PIMAGE_పునాది_RELOCATION;

#నిర్వచించు IMAGE_SIZEOF_పునాది_RELOCATION 8

#నిర్వచించు IMAGE_REL_BASED_ABSOLUTE 0
#నిర్వచించు IMAGE_REL_BASED_ఎగువ 1
#నిర్వచించు IMAGE_REL_BASED_దిగువ 2
#నిర్వచించు IMAGE_REL_BASED_HIGHLOW 3
#నిర్వచించు IMAGE_REL_BASED_HIGHADJ 4
#నిర్వచించు IMAGE_REL_BASED_MIPS_JMPADDR 5
#నిర్వచించు IMAGE_REL_BASED_MIPS_JMPADDR16 9
#నిర్వచించు IMAGE_REL_BASED_IA64_IMM64 9
#నిర్వచించు IMAGE_REL_BASED_DIR64 10

#నిర్వచించు IMAGE_ARCHIVE_ప్రారంభం_కొలత 8
#నిర్వచించు IMAGE_ARCHIVE_ప్రారంభం "!<arch>\n"
#నిర్వచించు IMAGE_ARCHIVE_చివర "`\n"
#నిర్వచించు IMAGE_ARCHIVE_PAD "\n"
#నిర్వచించు IMAGE_ARCHIVE_LINKER_MEMBER "/               "
#నిర్వచించు IMAGE_ARCHIVE_LONGNAMES_MEMBER "//              "

    రకనిర్వచనం నిర్మాణం IMAGE_ARCHIVE_MEMBER_శీర్షిక {
      BYTE Name[16];
      BYTE Date[12];
      BYTE UserID[6];
      BYTE సమూహం_ID[6];
      BYTE బహుళకం_4[8];
      BYTE కొలత_3[10];
      BYTE చివర_శీర్షిక[2];
    } IMAGE_ARCHIVE_MEMBER_శీర్షిక_2,*PIMAGE_ARCHIVE_MEMBER_శీర్షిక;

#నిర్వచించు IMAGE_SIZEOF_ARCHIVE_MEMBER_HDR 60

    రకనిర్వచనం నిర్మాణం _IMAGE_EXPORT_DIRECTORY {
      DWORD Characteristics;
      DWORD సమయం_Date_Stamp;
      మాట_3 Major_సంస్కరణ;
      మాట_3 Minor_సంస్కరణ;
      DWORD Name;
      DWORD పునాది_2;
      DWORD సంఖ్య_యొక్క_Functions;
      DWORD సంఖ్య_యొక్క_పేర్లు;
      DWORD చిరునామా_యొక్క_Functions;
      DWORD చిరునామా_యొక్క_పేర్లు;
      DWORD చిరునామా_యొక్క_Name_Ordinals;
    } IMAGE_EXPORT_DIRECTORY,*PIMAGE_EXPORT_DIRECTORY;

    రకనిర్వచనం నిర్మాణం _IMAGE_IMPORT_BY_NAME {
      మాట_3 Hint;
      BYTE Name[1];
    } IMAGE_IMPORT_BY_NAME,*PIMAGE_IMPORT_BY_NAME;

#అన్తర్భావ "pshpack8.h"

    రకనిర్వచనం నిర్మాణం _IMAGE_THUNK_DATA64 {
      సంఘం {
	ULONGLONG ForwarderString;
	ULONGLONG Function;
	ULONGLONG Ordinal;
	ULONGLONG చిరునామా_యొక్క_దత్తాంశం;
      } u1;
    } IMAGE_THUNK_DATA64;
    రకనిర్వచనం IMAGE_THUNK_DATA64 *PIMAGE_THUNK_DATA64;

#అన్తర్భావ "poppack.h"

    రకనిర్వచనం నిర్మాణం _IMAGE_THUNK_DATA32 {
      సంఘం {
	DWORD ForwarderString;
	DWORD Function;
	DWORD Ordinal;
	DWORD చిరునామా_యొక్క_దత్తాంశం;
      } u1;
    } IMAGE_THUNK_DATA32;
    రకనిర్వచనం IMAGE_THUNK_DATA32 *PIMAGE_THUNK_DATA32;

#నిర్వచించు IMAGE_ORDINAL_FLAG64 0x8000000000000000ull
#నిర్వచించు IMAGE_ORDINAL_FLAG32 0x80000000
#నిర్వచించు IMAGE_ORDINAL64(Ordinal) (Ordinal & 0xffffull)
#నిర్వచించు IMAGE_ORDINAL32(Ordinal) (Ordinal & 0xffff)
#నిర్వచించు IMAGE_SNAP_BY_ORDINAL64(Ordinal) ((Ordinal & IMAGE_ORDINAL_FLAG64)!=0)
#నిర్వచించు IMAGE_SNAP_BY_ORDINAL32(Ordinal) ((Ordinal & IMAGE_ORDINAL_FLAG32)!=0)

    రకనిర్వచనం VOID
      (NTAPI *PIMAGE_TLS_CALLBACK)(PVOID DllHandle,DWORD Reason,PVOID Reserved);

    రకనిర్వచనం నిర్మాణం _IMAGE_TLS_DIRECTORY64 {
      ULONGLONG ప్రారంభం_చిరునామా_యొక్క_Raw_దత్తాంశం;
      ULONGLONG చివర_చిరునామా_యొక్క_Raw_దత్తాంశం;
      ULONGLONG చిరునామా_యొక్క_సూచీ;
      ULONGLONG చిరునామా_యొక్క_Call_Backs;
      DWORD కొలత_యొక్క_Zero_Fill;
      DWORD Characteristics;
    } IMAGE_TLS_DIRECTORY64;
    రకనిర్వచనం IMAGE_TLS_DIRECTORY64 *PIMAGE_TLS_DIRECTORY64;

    రకనిర్వచనం నిర్మాణం _IMAGE_TLS_DIRECTORY32 {
      DWORD ప్రారంభం_చిరునామా_యొక్క_Raw_దత్తాంశం;
      DWORD చివర_చిరునామా_యొక్క_Raw_దత్తాంశం;
      DWORD చిరునామా_యొక్క_సూచీ;
      DWORD చిరునామా_యొక్క_Call_Backs;
      DWORD కొలత_యొక్క_Zero_Fill;
      DWORD Characteristics;
    } IMAGE_TLS_DIRECTORY32;
    రకనిర్వచనం IMAGE_TLS_DIRECTORY32 *PIMAGE_TLS_DIRECTORY32;

#నిర్వచితమైతే _WIN64
#నిర్వచించు IMAGE_ORDINAL_FLAG IMAGE_ORDINAL_FLAG64
#నిర్వచించు IMAGE_ORDINAL(Ordinal) IMAGE_ORDINAL64(Ordinal)
    రకనిర్వచనం IMAGE_THUNK_DATA64 IMAGE_THUNK_దత్తాంశం;
    రకనిర్వచనం PIMAGE_THUNK_DATA64 PIMAGE_THUNK_దత్తాంశం;
#నిర్వచించు IMAGE_SNAP_BY_ORDINAL(Ordinal) IMAGE_SNAP_BY_ORDINAL64(Ordinal)
    రకనిర్వచనం IMAGE_TLS_DIRECTORY64 IMAGE_TLS_DIRECTORY;
    రకనిర్వచనం PIMAGE_TLS_DIRECTORY64 PIMAGE_TLS_DIRECTORY;
#లేకపోతే
#నిర్వచించు IMAGE_ORDINAL_FLAG IMAGE_ORDINAL_FLAG32
#నిర్వచించు IMAGE_ORDINAL(Ordinal) IMAGE_ORDINAL32(Ordinal)
    రకనిర్వచనం IMAGE_THUNK_DATA32 IMAGE_THUNK_దత్తాంశం;
    రకనిర్వచనం PIMAGE_THUNK_DATA32 PIMAGE_THUNK_దత్తాంశం;
#నిర్వచించు IMAGE_SNAP_BY_ORDINAL(Ordinal) IMAGE_SNAP_BY_ORDINAL32(Ordinal)
    రకనిర్వచనం IMAGE_TLS_DIRECTORY32 IMAGE_TLS_DIRECTORY;
    రకనిర్వచనం PIMAGE_TLS_DIRECTORY32 PIMAGE_TLS_DIRECTORY;
#అయితే_ముగింపు

    రకనిర్వచనం నిర్మాణం _IMAGE_IMPORT_DESCRIPTOR {
      సంఘం {
	DWORD Characteristics;
	DWORD Original_మొదటి_Thunk;
      };
      DWORD సమయం_Date_Stamp;

      DWORD ForwarderChain;
      DWORD Name;
      DWORD మొదటి_Thunk;
    } IMAGE_IMPORT_DESCRIPTOR;
    రకనిర్వచనం IMAGE_IMPORT_DESCRIPTOR UNALIGNED *PIMAGE_IMPORT_DESCRIPTOR;

    రకనిర్వచనం నిర్మాణం _IMAGE_BOUND_IMPORT_DESCRIPTOR {
      DWORD సమయం_Date_Stamp;
      మాట_3 స్థానభ్రంశం_Module_Name;
      మాట_3 సంఖ్య_యొక్క_Module_Forwarder_Refs;
    } IMAGE_BOUND_IMPORT_DESCRIPTOR,*PIMAGE_BOUND_IMPORT_DESCRIPTOR;

    రకనిర్వచనం నిర్మాణం _IMAGE_BOUND_FORWARDER_REF {
      DWORD సమయం_Date_Stamp;
      మాట_3 స్థానభ్రంశం_Module_Name;
      మాట_3 Reserved;
    } IMAGE_BOUND_FORWARDER_REF,*PIMAGE_BOUND_FORWARDER_REF;

    రకనిర్వచనం నిర్మాణం _IMAGE_RESOURCE_DIRECTORY {
      DWORD Characteristics;
      DWORD సమయం_Date_Stamp;
      మాట_3 Major_సంస్కరణ;
      మాట_3 Minor_సంస్కరణ;
      మాట_3 సంఖ్య_యొక్క_Named_Entries;
      మాట_3 సంఖ్య_యొక్క_Id_Entries;
    } IMAGE_RESOURCE_DIRECTORY,*PIMAGE_RESOURCE_DIRECTORY;

#నిర్వచించు IMAGE_RESOURCE_NAME_IS_STRING 0x80000000
#నిర్వచించు IMAGE_RESOURCE_దత్తాంశం_IS_DIRECTORY 0x80000000

    రకనిర్వచనం నిర్మాణం IMAGE_RESOURCE_DIRECTORY_నమోదు {
      సంఘం {
	నిర్మాణం {
	  DWORD Name_స్థానభ్రంశం:31;
	  DWORD NameIsString:1;
	};
	DWORD Name;
	మాట_3 Id;
      };
      సంఘం {
	DWORD స్థానభ్రంశం_గమ్యం_దత్తాంశం;
	నిర్మాణం {
	  DWORD స్థానభ్రంశం_గమ్యం_Directory:31;
	  DWORD దత్తాంశం_Is_Directory:1;
	};
      };
    } IMAGE_RESOURCE_DIRECTORY_నమోదు_2,*PIMAGE_RESOURCE_DIRECTORY_నమోదు;

    రకనిర్వచనం నిర్మాణం _IMAGE_RESOURCE_DIRECTORY_STRING {
      మాట_3 నిడివి_2;
      CHAR NameString[1];
    } IMAGE_RESOURCE_DIRECTORY_STRING,*PIMAGE_RESOURCE_DIRECTORY_STRING;

    రకనిర్వచనం నిర్మాణం _IMAGE_RESOURCE_DIR_STRING_U {
      మాట_3 నిడివి_2;
      WCHAR NameString[1];
    } IMAGE_RESOURCE_DIR_STRING_U,*PIMAGE_RESOURCE_DIR_STRING_U;

    రకనిర్వచనం నిర్మాణం IMAGE_RESOURCE_దత్తాంశం_నమోదు {
      DWORD స్థానభ్రంశం_గమ్యం_దత్తాంశం;
      DWORD కొలత_3;
      DWORD సంకేతం_పుట;
      DWORD Reserved;
    } IMAGE_RESOURCE_దత్తాంశం_నమోదు_2,*PIMAGE_RESOURCE_దత్తాంశం_నమోదు;

    రకనిర్వచనం నిర్మాణం {
      DWORD కొలత_3;
      DWORD సమయం_Date_Stamp;
      మాట_3 Major_సంస్కరణ;
      మాట_3 Minor_సంస్కరణ;
      DWORD GlobalFlagsClear;
      DWORD Global_Flags_సమితి;
      DWORD CriticalSectionDefaultTimeout;
      DWORD De_Commit_Free_ఖండం_పరిమితి;
      DWORD De_Commit_మొత్తం_Free_పరిమితి;
      DWORD తాళం_ఉపసర్గ_పట్టిక;
      DWORD గరిష్ఠ_కేటాయింపు_కొలత;
      DWORD Virtual_జ్ఞాపకం_పరిమితి;
      DWORD Process_కుప్ప_Flags;
      DWORD Process_Affinity_ముసుగు;
      మాట_3 CSDVersion;
      మాట_3 Reserved1;
      DWORD EditList;
      DWORD SecurityCookie;
      DWORD SEHandler_పట్టిక;
      DWORD SEHandler_లెక్క;
    } IMAGE_ఎక్కించు_CONFIG_DIRECTORY32,*PIMAGE_ఎక్కించు_CONFIG_DIRECTORY32;

    రకనిర్వచనం నిర్మాణం {
      DWORD కొలత_3;
      DWORD సమయం_Date_Stamp;
      మాట_3 Major_సంస్కరణ;
      మాట_3 Minor_సంస్కరణ;
      DWORD GlobalFlagsClear;
      DWORD Global_Flags_సమితి;
      DWORD CriticalSectionDefaultTimeout;
      ULONGLONG De_Commit_Free_ఖండం_పరిమితి;
      ULONGLONG De_Commit_మొత్తం_Free_పరిమితి;
      ULONGLONG తాళం_ఉపసర్గ_పట్టిక;
      ULONGLONG గరిష్ఠ_కేటాయింపు_కొలత;
      ULONGLONG Virtual_జ్ఞాపకం_పరిమితి;
      ULONGLONG Process_Affinity_ముసుగు;
      DWORD Process_కుప్ప_Flags;
      మాట_3 CSDVersion;
      మాట_3 Reserved1;
      ULONGLONG EditList;
      ULONGLONG SecurityCookie;
      ULONGLONG SEHandler_పట్టిక;
      ULONGLONG SEHandler_లెక్క;
    } IMAGE_ఎక్కించు_CONFIG_DIRECTORY64,*PIMAGE_ఎక్కించు_CONFIG_DIRECTORY64;

#నిర్వచితమైతే _WIN64
    రకనిర్వచనం IMAGE_ఎక్కించు_CONFIG_DIRECTORY64 IMAGE_ఎక్కించు_CONFIG_DIRECTORY;
    రకనిర్వచనం PIMAGE_ఎక్కించు_CONFIG_DIRECTORY64 PIMAGE_ఎక్కించు_CONFIG_DIRECTORY;
#లేకపోతే
    రకనిర్వచనం IMAGE_ఎక్కించు_CONFIG_DIRECTORY32 IMAGE_ఎక్కించు_CONFIG_DIRECTORY;
    రకనిర్వచనం PIMAGE_ఎక్కించు_CONFIG_DIRECTORY32 PIMAGE_ఎక్కించు_CONFIG_DIRECTORY;
#అయితే_ముగింపు

    రకనిర్వచనం నిర్మాణం IMAGE_CE_RUNTIME_FUNCTION_నమోదు {
      DWORD Func_ప్రారంభం;
      DWORD PrologLen : 8;
      DWORD FuncLen : 22;
      DWORD Thirty_Two_బిట్టు : 1;
      DWORD ExceptionFlag : 1;
    } IMAGE_CE_RUNTIME_FUNCTION_నమోదు_2,*PIMAGE_CE_RUNTIME_FUNCTION_నమోదు;

    రకనిర్వచనం నిర్మాణం IMAGE_ALPHA64_RUNTIME_FUNCTION_నమోదు {
      ULONGLONG Begin_చిరునామా;
      ULONGLONG చివర_చిరునామా;
      ULONGLONG ExceptionHandler;
      ULONGLONG Handler_దత్తాంశం;
      ULONGLONG Prolog_చివర_చిరునామా;
    } IMAGE_ALPHA64_RUNTIME_FUNCTION_నమోదు_2,*PIMAGE_ALPHA64_RUNTIME_FUNCTION_నమోదు;

    రకనిర్వచనం నిర్మాణం IMAGE_ALPHA_RUNTIME_FUNCTION_నమోదు {
      DWORD Begin_చిరునామా;
      DWORD చివర_చిరునామా;
      DWORD ExceptionHandler;
      DWORD Handler_దత్తాంశం;
      DWORD Prolog_చివర_చిరునామా;
    } IMAGE_ALPHA_RUNTIME_FUNCTION_నమోదు_2,*PIMAGE_ALPHA_RUNTIME_FUNCTION_నమోదు;

    రకనిర్వచనం నిర్మాణం IMAGE_RUNTIME_FUNCTION_నమోదు {
      DWORD Begin_చిరునామా;
      DWORD చివర_చిరునామా;
      DWORD Unwind_Info_చిరునామా;
    } IMAGE_RUNTIME_FUNCTION_నమోదు,*PIMAGE_RUNTIME_FUNCTION_నమోదు;

    రకనిర్వచనం IMAGE_RUNTIME_FUNCTION_నమోదు IMAGE_IA64_RUNTIME_FUNCTION_నమోదు;
    రకనిర్వచనం PIMAGE_RUNTIME_FUNCTION_నమోదు PIMAGE_IA64_RUNTIME_FUNCTION_నమోదు;

    రకనిర్వచనం IMAGE_RUNTIME_FUNCTION_నమోదు IMAGE_RUNTIME_FUNCTION_నమోదు_2;
    రకనిర్వచనం PIMAGE_RUNTIME_FUNCTION_నమోదు PIMAGE_RUNTIME_FUNCTION_నమోదు_2;

    రకనిర్వచనం నిర్మాణం _IMAGE_DEBUG_DIRECTORY {
      DWORD Characteristics;
      DWORD సమయం_Date_Stamp;
      మాట_3 Major_సంస్కరణ;
      మాట_3 Minor_సంస్కరణ;
      DWORD Type;
      DWORD కొలత_యొక్క_దత్తాంశం;
      DWORD చిరునామా_యొక్క_Raw_దత్తాంశం;
      DWORD సూచిక_గమ్యం_Raw_దత్తాంశం;
    } IMAGE_DEBUG_DIRECTORY,*PIMAGE_DEBUG_DIRECTORY;

#నిర్వచించు IMAGE_DEBUG_TYPE_UNKNOWN 0
#నిర్వచించు IMAGE_DEBUG_TYPE_COFF 1
#నిర్వచించు IMAGE_DEBUG_TYPE_CODEVIEW 2
#నిర్వచించు IMAGE_DEBUG_TYPE_FPO 3
#నిర్వచించు IMAGE_DEBUG_TYPE_MISC 4
#నిర్వచించు IMAGE_DEBUG_TYPE_EXCEPTION 5
#నిర్వచించు IMAGE_DEBUG_TYPE_FIXUP 6
#నిర్వచించు IMAGE_DEBUG_TYPE_OMAP_గమ్యం_SRC 7
#నిర్వచించు IMAGE_DEBUG_TYPE_OMAP_FROM_SRC 8
#నిర్వచించు IMAGE_DEBUG_TYPE_BORLAND 9
#నిర్వచించు IMAGE_DEBUG_TYPE_RESERVED10 10
#నిర్వచించు IMAGE_DEBUG_TYPE_CLSID 11

    రకనిర్వచనం నిర్మాణం IMAGE_COFF_SYMBOLS_శీర్షిక {
      DWORD సంఖ్య_యొక్క_Symbols;
      DWORD Lva_గమ్యం_మొదటి_చిహ్నం;
      DWORD సంఖ్య_యొక్క_Linenumbers;
      DWORD Lva_గమ్యం_మొదటి_Linenumber;
      DWORD Rva_గమ్యం_మొదటి_Byte_యొక్క_సంకేతం;
      DWORD Rva_గమ్యం_చివరి_Byte_యొక్క_సంకేతం;
      DWORD Rva_గమ్యం_మొదటి_Byte_యొక్క_దత్తాంశం;
      DWORD Rva_గమ్యం_చివరి_Byte_యొక్క_దత్తాంశం;
    } IMAGE_COFF_SYMBOLS_శీర్షిక_2,*PIMAGE_COFF_SYMBOLS_శీర్షిక;

#నిర్వచించు చట్రం_FPO 0
#నిర్వచించు చట్రం_TRAP 1
#నిర్వచించు చట్రం_TSS 2
#నిర్వచించు చట్రం_NONFPO 3

    రకనిర్వచనం నిర్మాణం FPO_దత్తాంశం {
      DWORD ul_Off_ప్రారంభం;
      DWORD cb_Proc_కొలత;
      DWORD cdwLocals;
      మాట_3 cdwParams;
      మాట_3 cbProlog : 8;
      మాట_3 cbRegs : 3;
      మాట_3 fHasSEH : 1;
      మాట_3 fUseBP : 1;
      మాట_3 reserved : 1;
      మాట_3 cb_చట్రం : 2;
    } FPO_దత్తాంశం_2,*PFPO_దత్తాంశం;
#నిర్వచించు SIZEOF_RFPO_దత్తాంశం 16

#నిర్వచించు IMAGE_DEBUG_MISC_EXENAME 1

    రకనిర్వచనం నిర్మాణం _IMAGE_DEBUG_MISC {
      DWORD దత్తాంశం_Type;
      DWORD నిడివి_2;
      BOOLEAN Unicode;
      BYTE Reserved[3];
      BYTE దత్తాంశం_3[1];
    } IMAGE_DEBUG_MISC,*PIMAGE_DEBUG_MISC;

    రకనిర్వచనం నిర్మాణం IMAGE_FUNCTION_నమోదు {
      DWORD Starting_చిరునామా;
      DWORD Ending_చిరునామా;
      DWORD చివర_యొక్క_Prologue;
    } IMAGE_FUNCTION_నమోదు_2,*PIMAGE_FUNCTION_నమోదు;

    రకనిర్వచనం నిర్మాణం _IMAGE_FUNCTION_ENTRY64 {
      ULONGLONG Starting_చిరునామా;
      ULONGLONG Ending_చిరునామా;
      సంఘం {
	ULONGLONG చివర_యొక్క_Prologue;
	ULONGLONG Unwind_Info_చిరునామా;
      };
    } IMAGE_FUNCTION_ENTRY64,*PIMAGE_FUNCTION_ENTRY64;

    రకనిర్వచనం నిర్మాణం IMAGE_SEPARATE_DEBUG_శీర్షిక {
      మాట_3 Signature;
      మాట_3 Flags;
      మాట_3 Machine;
      మాట_3 Characteristics;
      DWORD సమయం_Date_Stamp;
      DWORD Check_కూడిక;
      DWORD Image_పునాది;
      DWORD కొలత_యొక్క_Image;
      DWORD సంఖ్య_యొక్క_Sections;
      DWORD Exported_పేర్లు_కొలత;
      DWORD Debug_Directory_కొలత;
      DWORD SectionAlignment;
      DWORD Reserved[2];
    } IMAGE_SEPARATE_DEBUG_శీర్షిక_2,*PIMAGE_SEPARATE_DEBUG_శీర్షిక;

    రకనిర్వచనం నిర్మాణం _NON_PAGED_DEBUG_INFO {
      మాట_3 Signature;
      మాట_3 Flags;
      DWORD కొలత_3;
      మాట_3 Machine;
      మాట_3 Characteristics;
      DWORD సమయం_Date_Stamp;
      DWORD Check_కూడిక;
      DWORD కొలత_యొక్క_Image;
      ULONGLONG Image_పునాది;

    } NON_PAGED_DEBUG_INFO,*PNON_PAGED_DEBUG_INFO;

#నిర్వచించు IMAGE_SEPARATE_DEBUG_SIGNATURE 0x4944
#నిర్వచించు NON_PAGED_DEBUG_SIGNATURE 0x494E

#నిర్వచించు IMAGE_SEPARATE_DEBUG_FLAGS_ముసుగు 0x8000
#నిర్వచించు IMAGE_SEPARATE_DEBUG_MISMATCH 0x8000

    రకనిర్వచనం నిర్మాణం Image_Architecture_శీర్షిక {
      గుర్తులేని పూర్ణాంకం Amask_విలువ: 1;
      పూర్ణాంకం Adummy1 :7;
      గుర్తులేని పూర్ణాంకం Amask_జరుపు: 8;
      పూర్ణాంకం Adummy2 :16;
      DWORD మొదటి_నమోదు_RVA;
    } IMAGE_ARCHITECTURE_శీర్షిక,*PIMAGE_ARCHITECTURE_శీర్షిక;

    రకనిర్వచనం నిర్మాణం Image_Architecture_నమోదు {
      DWORD FixupInstRVA;
      DWORD NewInst;
    } IMAGE_ARCHITECTURE_నమోదు,*PIMAGE_ARCHITECTURE_నమోదు;

#అన్తర్భావ "poppack.h"

#నిర్వచించు IMPORT_OBJECT_HDR_SIG2 0xffff

    రకనిర్వచనం నిర్మాణం IMPORT_OBJECT_శీర్షిక {
      మాట_3 Sig1;
      మాట_3 Sig2;
      మాట_3 సంస్కరణ_2;
      మాట_3 Machine;
      DWORD సమయం_Date_Stamp;
      DWORD కొలత_యొక్క_దత్తాంశం;
      సంఘం {
	మాట_3 Ordinal;
	మాట_3 Hint;
      };
      మాట_3 Type : 2;
      మాట_3 NameType : 3;
      మాట_3 Reserved : 11;
    } IMPORT_OBJECT_శీర్షిక;

    రకనిర్వచనం గణన IMPORT_OBJECT_TYPE {
      IMPORT_OBJECT_సంకేతం = 0,IMPORT_OBJECT_దత్తాంశం = 1,IMPORT_OBJECT_CONST = 2
    } IMPORT_OBJECT_TYPE;

    రకనిర్వచనం గణన IMPORT_OBJECT_NAME_TYPE {
      IMPORT_OBJECT_ORDINAL = 0,IMPORT_OBJECT_NAME = 1,IMPORT_OBJECT_NAME_NO_ఉపసర్గ = 2,IMPORT_OBJECT_NAME_UNDECORATE = 3
    } IMPORT_OBJECT_NAME_TYPE;

#నిర్వచితం_కాకపోతే __IMAGE_COR20_HEADER_DEFINED__
#నిర్వచించు __IMAGE_COR20_HEADER_DEFINED__
    రకనిర్వచనం గణన Replaces_Cor_Hdr_Numeric_నిర్వచిస్తుంది {
      COMIMAGE_FLAGS_ILONLY =0x00000001,COMIMAGE_FLAGS_32BITREQUIRED =0x00000002,COMIMAGE_FLAGS_IL_LIBRARY =0x00000004,
      COMIMAGE_FLAGS_STRONGNAMESIGNED =0x00000008,COMIMAGE_FLAGS_TRACKDEBUGDATA =0x00010000,COR_సంస్కరణ_MAJOR_V2 =2,
      COR_సంస్కరణ_MAJOR =COR_సంస్కరణ_MAJOR_V2,COR_సంస్కరణ_MINOR =0,COR_DELETED_NAME_నిడివి =8,COR_VTABLEGAP_NAME_నిడివి =8,
      NATIVE_TYPE_MAX_CB =1,COR_ILMETHOD_SECT_SMALL_MAX_DATASIZE=0xFF,IMAGE_COR_MIH_METHODRVA =0x01,IMAGE_COR_MIH_EHRVA =0x02,
      IMAGE_COR_MIH_BASICBLOCK =0x08,COR_VTABLE_32_బిట్టు =0x01,COR_VTABLE_64_బిట్టు =0x02,COR_VTABLE_FROM_UNMANAGED =0x04,
      COR_VTABLE_CALL_MOST_DERIVED =0x10,IMAGE_COR_EATJ_THUNK_కొలత =32,MAX_CLASS_NAME =1024,MAX_PACKAGE_NAME =1024
    } Replaces_Cor_Hdr_Numeric_నిర్వచిస్తుంది;

    రకనిర్వచనం నిర్మాణం IMAGE_COR20_శీర్షిక {
      DWORD cb;
      మాట_3 Major_Runtime_సంస్కరణ;
      మాట_3 Minor_Runtime_సంస్కరణ;
      IMAGE_దత్తాంశం_DIRECTORY_2 Meta_దత్తాంశం;
      DWORD Flags;
      DWORD నమోదు_బిందువు_Token;
      IMAGE_దత్తాంశం_DIRECTORY_2 Resources;
      IMAGE_దత్తాంశం_DIRECTORY_2 StrongNameSignature;
      IMAGE_దత్తాంశం_DIRECTORY_2 సంకేతం_Manager_పట్టిక;
      IMAGE_దత్తాంశం_DIRECTORY_2 VTableFixups;
      IMAGE_దత్తాంశం_DIRECTORY_2 Export_చిరునామా_పట్టిక_Jumps;
      IMAGE_దత్తాంశం_DIRECTORY_2 Managed_Native_శీర్షిక;
    } IMAGE_COR20_శీర్షిక,*PIMAGE_COR20_శీర్షిక;
#అయితే_ముగింపు

#ఒకవేళ defined (__x86_64)
    NTSYSAPI PRUNTIME_FUNCTION NTAPI Rtl_Lookup_Function_నమోదు (DWORD64 ControlPc, PDWORD64 Image_పునాది, PUNWIND_HISTORY_పట్టిక History_పట్టిక);
    NTSYSAPI VOID NTAPI RtlUnwindEx (PVOID లక్ష్యం_చట్రం, PVOID లక్ష్యం_Ip, PEXCEPTION_రికార్డు Exception_రికార్డు, PVOID Return_విలువ_2, PCONTEXT Context_రికార్డు, PUNWIND_HISTORY_పట్టిక History_పట్టిక);
#అయితే_ముగింపు

#అన్తర్భావ <string.h>

#నిర్వచితం_కాకపోతే SLIST_శీర్షిక
#నిర్వచించు SLIST_శీర్షిక

#నిర్వచితమైతే _WIN64
    రకనిర్వచనం నిర్మాణం SLIST_నమోదు *PSLIST_నమోదు;
    రకనిర్వచనం నిర్మాణం DECLSPEC_ALIGN(16) SLIST_నమోదు {
      PSLIST_నమోదు తదుపరి_2;
    } SLIST_నమోదు_2;
#లేకపోతే

#నిర్వచించు SLIST_నమోదు_2 SINGLE_LIST_నమోదు_2
#నిర్వచించు SLIST_నమోదు SINGLE_LIST_నమోదు
#నిర్వచించు PSLIST_నమోదు PSINGLE_LIST_నమోదు
#అయితే_ముగింపు

#ఒకవేళ defined(_WIN64)

    రకనిర్వచనం నిర్మాణం DECLSPEC_ALIGN(16) SLIST_శీర్షిక_2 {
      ULONGLONG Alignment;
      ULONGLONG Region;
    } SLIST_శీర్షిక_3;

    రకనిర్వచనం నిర్మాణం SLIST_శీర్షిక_2 *PSLIST_శీర్షిక;
#లేకపోతే

    రకనిర్వచనం సంఘం SLIST_శీర్షిక_2 {
      ULONGLONG Alignment;
      నిర్మాణం {
	SLIST_నమోదు_2 తదుపరి_2;
	మాట_3 లోతు;
	మాట_3 Sequence;
      };
    } SLIST_శీర్షిక_3,*PSLIST_శీర్షిక;
#అయితే_ముగింపు
#అయితే_ముగింపు

    NTSYSAPI VOID NTAPI Rtl_Initialize_SList_తల(PSLIST_శీర్షిక List_తల);
    NTSYSAPI PSLIST_నమోదు NTAPI Rtl_మొదటి_నమోదు_SList(స్థిరరాశి SLIST_శీర్షిక_3 *List_తల);
    NTSYSAPI PSLIST_నమోదు NTAPI Rtl_Interlocked_తీయి_నమోదు_SList(PSLIST_శీర్షిక List_తల);
    NTSYSAPI PSLIST_నమోదు NTAPI Rtl_Interlocked_నెట్టు_నమోదు_SList(PSLIST_శీర్షిక List_తల,PSLIST_నమోదు List_నమోదు);
    NTSYSAPI PSLIST_నమోదు NTAPI RtlInterlockedFlushSList(PSLIST_శీర్షిక List_తల);
    NTSYSAPI మాట_3 NTAPI Rtl_Query_లోతు_SList(PSLIST_శీర్షిక List_తల);

#నిర్వచించు కుప్ప_NO_SERIALIZE 0x00000001
#నిర్వచించు కుప్ప_GROWABLE 0x00000002
#నిర్వచించు కుప్ప_GENERATE_EXCEPTIONS 0x00000004
#నిర్వచించు కుప్ప_ZERO_జ్ఞాపకం 0x00000008
#నిర్వచించు కుప్ప_REALLOC_లోపల_ఉంచు_ONLY 0x00000010
#నిర్వచించు కుప్ప_తోక_CHECKING_ENABLED 0x00000020
#నిర్వచించు కుప్ప_FREE_CHECKING_ENABLED 0x00000040
#నిర్వచించు కుప్ప_DISABLE_COALESCE_ON_FREE 0x00000080
#నిర్వచించు కుప్ప_CREATE_ALIGN_16 0x00010000
#నిర్వచించు కుప్ప_CREATE_ENABLE_TRACING 0x00020000
#నిర్వచించు కుప్ప_CREATE_ENABLE_EXECUTE 0x00040000
#నిర్వచించు కుప్ప_గరిష్ఠ_ట్యాగ్ 0x0FFF
#నిర్వచించు కుప్ప_PSEUDO_ట్యాగ్_FLAG 0x8000
#నిర్వచించు కుప్ప_ట్యాగ్_జరుపు 18
#నిర్వచించు కుప్ప_MAKE_ట్యాగ్_FLAGS(b,o) ((DWORD)((b) + ((o) << 18)))

    NTSYSAPI VOID NTAPI RtlCaptureContext(PCONTEXT Context_రికార్డు);

#నిర్వచించు IS_పాఠ్యం_UNICODE_ASCII16 0x0001
#నిర్వచించు IS_పాఠ్యం_UNICODE_తిరగేయి_ASCII16 0x0010

#నిర్వచించు IS_పాఠ్యం_UNICODE_STATISTICS 0x0002
#నిర్వచించు IS_పాఠ్యం_UNICODE_తిరగేయి_STATISTICS 0x0020

#నిర్వచించు IS_పాఠ్యం_UNICODE_CONTROLS 0x0004
#నిర్వచించు IS_పాఠ్యం_UNICODE_తిరగేయి_CONTROLS 0x0040

#నిర్వచించు IS_పాఠ్యం_UNICODE_SIGNATURE 0x0008
#నిర్వచించు IS_పాఠ్యం_UNICODE_తిరగేయి_SIGNATURE 0x0080

#నిర్వచించు IS_పాఠ్యం_UNICODE_ILLEGAL_CHARS 0x0100
#నిర్వచించు IS_పాఠ్యం_UNICODE_ODD_నిడివి 0x0200
#నిర్వచించు IS_పాఠ్యం_UNICODE_DBCS_LEADBYTE 0x0400
#నిర్వచించు IS_పాఠ్యం_UNICODE_NULL_బైట్లు 0x1000

#నిర్వచించు IS_పాఠ్యం_UNICODE_UNICODE_ముసుగు 0x000F
#నిర్వచించు IS_పాఠ్యం_UNICODE_తిరగేయి_ముసుగు 0x00F0
#నిర్వచించు IS_పాఠ్యం_UNICODE_NOT_UNICODE_ముసుగు 0x0F00
#నిర్వచించు IS_పాఠ్యం_UNICODE_NOT_ASCII_ముసుగు 0xF000

#నిర్వచించు COMPRESSION_FORMAT_NONE (0x0000)
#నిర్వచించు COMPRESSION_FORMAT_DEFAULT (0x0001)
#నిర్వచించు COMPRESSION_FORMAT_LZNT1 (0x0002)
#నిర్వచించు COMPRESSION_ENGINE_STANDARD (0x0000)
#నిర్వచించు COMPRESSION_ENGINE_గరిష్ఠ (0x0100)
#నిర్వచించు COMPRESSION_ENGINE_HIBER (0x0200)

#ఒకవేళ _DBG_MEMCPY_INLINE_ && !defined(_MEMCPY_INLINE_) && !defined(_CRTBLD)
#నిర్వచించు _MEMCPY_INLINE_
    __CRT_INLINE PVOID __cdecl memcpy_inline(శూన్య *dst,స్థిరరాశి శూన్య *src,కొలత_t కొలత) {
      ఒకవేళ(((అక్షరం *)dst > (అక్షరం *)src) && ((అక్షరం *)dst < ((అక్షరం *)src + కొలత))) {
	__debugbreak();
      }
      తిరిగి జ్ఞాపకం_నకలు(dst,src,కొలత);
    }
#నిర్వచించు జ్ఞాపకం_నకలు memcpy_inline
#అయితే_ముగింపు

    NTSYSAPI కొలత_T NTAPI Rtl_Compare_జ్ఞాపకం(స్థిరరాశి VOID *Source1,స్థిరరాశి VOID *Source2,కొలత_T నిడివి_2);

#నిర్వచించు Rtl_Equal_జ్ఞాపకం(Destination,ఆధారం_2,నిడివి_2) (!memcmp((Destination),(ఆధారం_2),(నిడివి_2)))
#నిర్వచించు Rtl_Move_జ్ఞాపకం(Destination,ఆధారం_2,నిడివి_2) memmove((Destination),(ఆధారం_2),(నిడివి_2))
#నిర్వచించు Rtl_Copy_జ్ఞాపకం(Destination,ఆధారం_2,నిడివి_2) జ్ఞాపకం_నకలు((Destination),(ఆధారం_2),(నిడివి_2))
#నిర్వచించు Rtl_Fill_జ్ఞాపకం(Destination,నిడివి_2,Fill) memset((Destination),(Fill),(నిడివి_2))
#నిర్వచించు Rtl_Zero_జ్ఞాపకం(Destination,నిడివి_2) memset((Destination),0,(నిడివి_2))

    __CRT_INLINE PVOID Rtl_Secure_Zero_జ్ఞాపకం(PVOID ptr,కొలత_T cnt) {
      అస్థిర అక్షరం *vptr =(అస్థిర అక్షరం *)ptr;
#నిర్వచితమైతే __x86_64
      __stosb((PBYTE)((DWORD64)vptr),0,cnt);
#లేకపోతే
      అయితే(cnt) {
	*vptr = 0;
	vptr++;
	cnt--;
      }
#అయితే_ముగింపు
      తిరిగి ptr;
    }

    రకనిర్వచనం నిర్మాణం సందేశం_RESOURCE_నమోదు {
      మాట_3 నిడివి_2;
      మాట_3 Flags;
      BYTE పాఠ్యం_4[1];
    } సందేశం_RESOURCE_నమోదు_2,*PMESSAGE_RESOURCE_నమోదు;

#నిర్వచించు సందేశం_RESOURCE_UNICODE 0x0001

    రకనిర్వచనం నిర్మాణం సందేశం_RESOURCE_ఖండం {
      DWORD దిగువ_Id;
      DWORD ఎగువ_Id;
      DWORD స్థానభ్రంశం_గమ్యం_Entries;
    } సందేశం_RESOURCE_ఖండం_2,*PMESSAGE_RESOURCE_ఖండం;

    రకనిర్వచనం నిర్మాణం సందేశం_RESOURCE_దత్తాంశం {
      DWORD సంఖ్య_యొక్క_ఖండాలు;
      సందేశం_RESOURCE_ఖండం_2 ఖండాలు_2[1];
    } సందేశం_RESOURCE_దత్తాంశం_2,*PMESSAGE_RESOURCE_దత్తాంశం;

    రకనిర్వచనం నిర్మాణం _OSVERSIONINFOA {
      DWORD dw_OSVersion_Info_కొలత;
      DWORD dw_Major_సంస్కరణ;
      DWORD dw_Minor_సంస్కరణ;
      DWORD dw_Build_సంఖ్య;
      DWORD dwPlatformId;
      CHAR szCSDVersion[128];
    } OSVERSIONINFOA,*POSVERSIONINFOA,*LPOSVERSIONINFOA;

    రకనిర్వచనం నిర్మాణం _OSVERSIONINFOW {
      DWORD dw_OSVersion_Info_కొలత;
      DWORD dw_Major_సంస్కరణ;
      DWORD dw_Minor_సంస్కరణ;
      DWORD dw_Build_సంఖ్య;
      DWORD dwPlatformId;
      WCHAR szCSDVersion[128];
    } OSVERSIONINFOW,*POSVERSIONINFOW,*LPOSVERSIONINFOW,RTL_OSVERSIONINFOW,*PRTL_OSVERSIONINFOW;

#నిర్వచితమైతే UNICODE
    రకనిర్వచనం OSVERSIONINFOW OSVERSIONINFO;
    రకనిర్వచనం POSVERSIONINFOW POSVERSIONINFO;
    రకనిర్వచనం LPOSVERSIONINFOW LPOSVERSIONINFO;
#లేకపోతే
    రకనిర్వచనం OSVERSIONINFOA OSVERSIONINFO;
    రకనిర్వచనం POSVERSIONINFOA POSVERSIONINFO;
    రకనిర్వచనం LPOSVERSIONINFOA LPOSVERSIONINFO;
#అయితే_ముగింపు

    రకనిర్వచనం నిర్మాణం _OSVERSIONINFOEXA {
      DWORD dw_OSVersion_Info_కొలత;
      DWORD dw_Major_సంస్కరణ;
      DWORD dw_Minor_సంస్కరణ;
      DWORD dw_Build_సంఖ్య;
      DWORD dwPlatformId;
      CHAR szCSDVersion[128];
      మాట_3 wServicePackMajor;
      మాట_3 wServicePackMinor;
      మాట_3 w_Suite_ముసుగు;
      BYTE w_లబ్ధం_Type;
      BYTE wReserved;
    } OSVERSIONINFOEXA,*POSVERSIONINFOEXA,*LPOSVERSIONINFOEXA;

    రకనిర్వచనం నిర్మాణం _OSVERSIONINFOEXW {
      DWORD dw_OSVersion_Info_కొలత;
      DWORD dw_Major_సంస్కరణ;
      DWORD dw_Minor_సంస్కరణ;
      DWORD dw_Build_సంఖ్య;
      DWORD dwPlatformId;
      WCHAR szCSDVersion[128];
      మాట_3 wServicePackMajor;
      మాట_3 wServicePackMinor;
      మాట_3 w_Suite_ముసుగు;
      BYTE w_లబ్ధం_Type;
      BYTE wReserved;
    } OSVERSIONINFOEXW,*POSVERSIONINFOEXW,*LPOSVERSIONINFOEXW,RTL_OSVERSIONINFOEXW,*PRTL_OSVERSIONINFOEXW;
#నిర్వచితమైతే UNICODE
    రకనిర్వచనం OSVERSIONINFOEXW OSVERSIONINFOEX;
    రకనిర్వచనం POSVERSIONINFOEXW POSVERSIONINFOEX;
    రకనిర్వచనం LPOSVERSIONINFOEXW LPOSVERSIONINFOEX;
#లేకపోతే
    రకనిర్వచనం OSVERSIONINFOEXA OSVERSIONINFOEX;
    రకనిర్వచనం POSVERSIONINFOEXA POSVERSIONINFOEX;
    రకనిర్వచనం LPOSVERSIONINFOEXA LPOSVERSIONINFOEX;
#అయితే_ముగింపు

#నిర్వచించు VER_EQUAL 1
#నిర్వచించు VER_GREATER 2
#నిర్వచించు VER_GREATER_EQUAL 3
#నిర్వచించు VER_LESS 4
#నిర్వచించు VER_LESS_EQUAL 5
#నిర్వచించు VER_AND 6
#నిర్వచించు VER_OR 7

#నిర్వచించు VER_CONDITION_ముసుగు 7
#నిర్వచించు VER_అంకె_బిట్లు_చొప్పున_CONDITION_ముసుగు 3

#నిర్వచించు VER_MINORVERSION 0x0000001
#నిర్వచించు VER_MAJORVERSION 0x0000002
#నిర్వచించు VER_BUILDNUMBER 0x0000004
#నిర్వచించు VER_PLATFORMID 0x0000008
#నిర్వచించు VER_SERVICEPACKMINOR 0x0000010
#నిర్వచించు VER_SERVICEPACKMAJOR 0x0000020
#నిర్వచించు VER_SUITENAME 0x0000040
#నిర్వచించు VER_లబ్ధం_TYPE 0x0000080

#నిర్వచించు VER_NT_WORKSTATION 0x0000001
#నిర్వచించు VER_NT_DOMAIN_CONTROLLER 0x0000002
#నిర్వచించు VER_NT_SERVER 0x0000003

#నిర్వచించు VER_PLATFORM_WIN32s 0
#నిర్వచించు VER_PLATFORM_WIN32_WINDOWS 1
#నిర్వచించు VER_PLATFORM_WIN32_NT 2

#నిర్వచించు VER_సమితి_CONDITION(_m_,_t_,_c_) ((_m_)=Ver_సమితి_Condition_ముసుగు((_m_),(_t_),(_c_)))

    NTSYSAPI ULONGLONG NTAPI Ver_సమితి_Condition_ముసుగు(ULONGLONG Condition_ముసుగు,DWORD Type_ముసుగు,BYTE Condition);

    రకనిర్వచనం నిర్మాణం _RTL_CRITICAL_SECTION_DEBUG {
      మాట_3 Type;
      మాట_3 Creator_వెనుక_Trace_సూచీ;
      నిర్మాణం _RTL_CRITICAL_SECTION *CriticalSection;
      LIST_నమోదు_2 ProcessLocksList;
      DWORD నమోదు_లెక్క;
      DWORD Contention_లెక్క;
      DWORD అదనపు_2[2];
    } RTL_CRITICAL_SECTION_DEBUG,*PRTL_CRITICAL_SECTION_DEBUG,RTL_RESOURCE_DEBUG,*PRTL_RESOURCE_DEBUG;

#నిర్వచించు RTL_CRITSECT_TYPE 0
#నిర్వచించు RTL_RESOURCE_TYPE 1

    రకనిర్వచనం నిర్మాణం _RTL_CRITICAL_SECTION {
      PRTL_CRITICAL_SECTION_DEBUG DebugInfo;
      LONG తాళం_లెక్క;
      LONG Recursion_లెక్క;
      HANDLE OwningThread;
      HANDLE తాళం_Semaphore;
      ULONG_PTR Spin_లెక్క;
    } RTL_CRITICAL_SECTION,*PRTL_CRITICAL_SECTION;

    రకనిర్వచనం VOID (NTAPI *RTL_VERIFIER_DLL_ఎక్కించు_CALLBACK) (PWSTR DllName,PVOID Dll_పునాది,కొలత_T Dll_కొలత,PVOID Reserved);
    రకనిర్వచనం VOID (NTAPI *RTL_VERIFIER_DLL_UNLOAD_CALLBACK) (PWSTR DllName,PVOID Dll_పునాది,కొలత_T Dll_కొలత,PVOID Reserved);
    రకనిర్వచనం VOID (NTAPI *RTL_VERIFIER_NTDLLHEAPFREE_CALLBACK)(PVOID కేటాయింపు_పునాది,కొలత_T కేటాయింపు_కొలత);

    రకనిర్వచనం నిర్మాణం _RTL_VERIFIER_THUNK_DESCRIPTOR {
      PCHAR ThunkName;
      PVOID Thunk_Old_చిరునామా;
      PVOID Thunk_New_చిరునామా;
    } RTL_VERIFIER_THUNK_DESCRIPTOR,*PRTL_VERIFIER_THUNK_DESCRIPTOR;

    రకనిర్వచనం నిర్మాణం _RTL_VERIFIER_DLL_DESCRIPTOR {
      PWCHAR DllName;
      DWORD DllFlags;
      PVOID Dll_చిరునామా;
      PRTL_VERIFIER_THUNK_DESCRIPTOR DllThunks;
    } RTL_VERIFIER_DLL_DESCRIPTOR,*PRTL_VERIFIER_DLL_DESCRIPTOR;

    రకనిర్వచనం నిర్మాణం _RTL_VERIFIER_PROVIDER_DESCRIPTOR {
      DWORD నిడివి_2;
      PRTL_VERIFIER_DLL_DESCRIPTOR ProviderDlls;
      RTL_VERIFIER_DLL_ఎక్కించు_CALLBACK Provider_Dll_ఎక్కించు_Callback;
      RTL_VERIFIER_DLL_UNLOAD_CALLBACK ProviderDllUnloadCallback;
      PWSTR VerifierImage;
      DWORD VerifierFlags;
      DWORD VerifierDebug;
      PVOID Rtlp_Get_దొంతర_Trace_చిరునామా;
      PVOID Rtlp_Debug_పుట_కుప్ప_Create;
      PVOID Rtlp_Debug_పుట_కుప్ప_Destroy;
      RTL_VERIFIER_NTDLLHEAPFREE_CALLBACK Provider_Ntdll_కుప్ప_Free_Callback;
    } RTL_VERIFIER_PROVIDER_DESCRIPTOR,*PRTL_VERIFIER_PROVIDER_DESCRIPTOR;

#నిర్వచించు RTL_VRF_FLG_నిండిన_పుట_కుప్ప 0x00000001
#నిర్వచించు RTL_VRF_FLG_RESERVED_DONOTUSE 0x00000002
#నిర్వచించు RTL_VRF_FLG_HANDLE_CHECKS 0x00000004
#నిర్వచించు RTL_VRF_FLG_దొంతర_CHECKS 0x00000008
#నిర్వచించు RTL_VRF_FLG_APPCOMPAT_CHECKS 0x00000010
#నిర్వచించు RTL_VRF_FLG_TLS_CHECKS 0x00000020
#నిర్వచించు RTL_VRF_FLG_DIRTY_STACKS 0x00000040
#నిర్వచించు RTL_VRF_FLG_RPC_CHECKS 0x00000080
#నిర్వచించు RTL_VRF_FLG_COM_CHECKS 0x00000100
#నిర్వచించు RTL_VRF_FLG_DANGEROUS_APIS 0x00000200
#నిర్వచించు RTL_VRF_FLG_RACE_CHECKS 0x00000400
#నిర్వచించు RTL_VRF_FLG_DEADLOCK_CHECKS 0x00000800
#నిర్వచించు RTL_VRF_FLG_మొదటి_CHANCE_EXCEPTION_CHECKS 0x00001000
#నిర్వచించు RTL_VRF_FLG_VIRTUAL_MEM_CHECKS 0x00002000
#నిర్వచించు RTL_VRF_FLG_ENABLE_LOGGING 0x00004000
#నిర్వచించు RTL_VRF_FLG_FAST_FILL_కుప్ప 0x00008000
#నిర్వచించు RTL_VRF_FLG_VIRTUAL_SPACE_TRACKING 0x00010000
#నిర్వచించు RTL_VRF_FLG_ENABLED_SYSTEM_WIDE 0x00020000
#నిర్వచించు RTL_VRF_FLG_MISCELLANEOUS_CHECKS 0x00020000
#నిర్వచించు RTL_VRF_FLG_తాళం_CHECKS 0x00040000

#నిర్వచించు APPLICATION_VERIFIER_అంతర్గత_ERROR 0x80000000
#నిర్వచించు APPLICATION_VERIFIER_అంతర్గత_WARNING 0x40000000
#నిర్వచించు APPLICATION_VERIFIER_NO_BREAK 0x20000000
#నిర్వచించు APPLICATION_VERIFIER_CONTINUABLE_BREAK 0x10000000

#నిర్వచించు APPLICATION_VERIFIER_UNKNOWN_ERROR 0x0001
#నిర్వచించు APPLICATION_VERIFIER_ACCESS_VIOLATION 0x0002
#నిర్వచించు APPLICATION_VERIFIER_UNSYNCHRONIZED_ACCESS 0x0003
#నిర్వచించు APPLICATION_VERIFIER_EXTREME_కొలత_REQUEST 0x0004
#నిర్వచించు APPLICATION_VERIFIER_BAD_కుప్ప_HANDLE 0x0005
#నిర్వచించు APPLICATION_VERIFIER_SWITCHED_కుప్ప_HANDLE 0x0006
#నిర్వచించు APPLICATION_VERIFIER_DOUBLE_FREE 0x0007
#నిర్వచించు APPLICATION_VERIFIER_CORRUPTED_కుప్ప_ఖండం 0x0008
#నిర్వచించు APPLICATION_VERIFIER_DESTROY_PROCESS_కుప్ప 0x0009
#నిర్వచించు APPLICATION_VERIFIER_UNEXPECTED_EXCEPTION 0x000A
#నిర్వచించు APPLICATION_VERIFIER_CORRUPTED_కుప్ప_ఖండం_EXCEPTION_RAISED_FOR_శీర్షిక 0x000B
#నిర్వచించు APPLICATION_VERIFIER_CORRUPTED_కుప్ప_ఖండం_EXCEPTION_RAISED_FOR_PROBING 0x000C
#నిర్వచించు APPLICATION_VERIFIER_CORRUPTED_కుప్ప_ఖండం_శీర్షిక 0x000D
#నిర్వచించు APPLICATION_VERIFIER_CORRUPTED_FREED_కుప్ప_ఖండం 0x000E
#నిర్వచించు APPLICATION_VERIFIER_CORRUPTED_కుప్ప_ఖండం_SUFFIX 0x000F
#నిర్వచించు APPLICATION_VERIFIER_CORRUPTED_కుప్ప_ఖండం_ప్రారంభం_STAMP 0x0010
#నిర్వచించు APPLICATION_VERIFIER_CORRUPTED_కుప్ప_ఖండం_చివర_STAMP 0x0011
#నిర్వచించు APPLICATION_VERIFIER_CORRUPTED_కుప్ప_ఖండం_ఉపసర్గ 0x0012
#నిర్వచించు APPLICATION_VERIFIER_మొదటి_CHANCE_ACCESS_VIOLATION 0x0013
#నిర్వచించు APPLICATION_VERIFIER_CORRUPTED_కుప్ప_LIST 0x0014

#నిర్వచించు APPLICATION_VERIFIER_TERMINATE_THREAD_CALL 0x0100
#నిర్వచించు APPLICATION_VERIFIER_దొంతర_అధికప్రవాహం 0x0101
#నిర్వచించు APPLICATION_VERIFIER_INVALID_EXIT_PROCESS_CALL 0x0102

#నిర్వచించు APPLICATION_VERIFIER_EXIT_THREAD_OWNS_తాళం 0x0200
#నిర్వచించు APPLICATION_VERIFIER_తాళం_లోపల_UNLOADED_DLL 0x0201
#నిర్వచించు APPLICATION_VERIFIER_తాళం_లోపల_FREED_కుప్ప 0x0202
#నిర్వచించు APPLICATION_VERIFIER_తాళం_DOUBLE_INITIALIZE 0x0203
#నిర్వచించు APPLICATION_VERIFIER_తాళం_లోపల_FREED_జ్ఞాపకం 0x0204
#నిర్వచించు APPLICATION_VERIFIER_తాళం_CORRUPTED 0x0205
#నిర్వచించు APPLICATION_VERIFIER_తాళం_INVALID_OWNER 0x0206
#నిర్వచించు APPLICATION_VERIFIER_తాళం_INVALID_RECURSION_లెక్క 0x0207
#నిర్వచించు APPLICATION_VERIFIER_తాళం_INVALID_తాళం_లెక్క 0x0208
#నిర్వచించు APPLICATION_VERIFIER_తాళం_OVER_RELEASED 0x0209
#నిర్వచించు APPLICATION_VERIFIER_తాళం_NOT_INITIALIZED 0x0210
#నిర్వచించు APPLICATION_VERIFIER_తాళం_ALREADY_INITIALIZED 0x0211
#నిర్వచించు APPLICATION_VERIFIER_తాళం_లోపల_FREED_VMEM 0x0212
#నిర్వచించు APPLICATION_VERIFIER_తాళం_లోపల_UNMAPPED_MEM 0x0213
#నిర్వచించు APPLICATION_VERIFIER_THREAD_NOT_తాళం_OWNER 0x0214

#నిర్వచించు APPLICATION_VERIFIER_INVALID_HANDLE 0x0300
#నిర్వచించు APPLICATION_VERIFIER_INVALID_TLS_విలువ 0x0301
#నిర్వచించు APPLICATION_VERIFIER_INCORRECT_WAIT_CALL 0x0302
#నిర్వచించు APPLICATION_VERIFIER_NULL_HANDLE 0x0303
#నిర్వచించు APPLICATION_VERIFIER_WAIT_లోపల_DLLMAIN 0x0304

#నిర్వచించు APPLICATION_VERIFIER_COM_ERROR 0x0400
#నిర్వచించు APPLICATION_VERIFIER_COM_API_లోపల_DLLMAIN 0x0401
#నిర్వచించు APPLICATION_VERIFIER_COM_UNHANDLED_EXCEPTION 0x0402
#నిర్వచించు APPLICATION_VERIFIER_COM_UNBALANCED_COINIT 0x0403
#నిర్వచించు APPLICATION_VERIFIER_COM_UNBALANCED_OLEINIT 0x0404
#నిర్వచించు APPLICATION_VERIFIER_COM_UNBALANCED_SWC 0x0405
#నిర్వచించు APPLICATION_VERIFIER_COM_NULL_DACL 0x0406
#నిర్వచించు APPLICATION_VERIFIER_COM_UNSAFE_IMPERSONATION 0x0407
#నిర్వచించు APPLICATION_VERIFIER_COM_SMUGGLED_WRAPPER 0x0408
#నిర్వచించు APPLICATION_VERIFIER_COM_SMUGGLED_PROXY 0x0409
#నిర్వచించు APPLICATION_VERIFIER_COM_CF_SUCCESS_WITH_NULL 0x040A
#నిర్వచించు APPLICATION_VERIFIER_COM_GCO_SUCCESS_WITH_NULL 0x040B
#నిర్వచించు APPLICATION_VERIFIER_COM_OBJECT_లోపల_FREED_జ్ఞాపకం 0x040C
#నిర్వచించు APPLICATION_VERIFIER_COM_OBJECT_లోపల_UNLOADED_DLL 0x040D
#నిర్వచించు APPLICATION_VERIFIER_COM_VTBL_లోపల_FREED_జ్ఞాపకం 0x040E
#నిర్వచించు APPLICATION_VERIFIER_COM_VTBL_లోపల_UNLOADED_DLL 0x040F
#నిర్వచించు APPLICATION_VERIFIER_COM_HOLDING_LOCKS_ON_CALL 0x0410

#నిర్వచించు APPLICATION_VERIFIER_RPC_ERROR 0x0500

#నిర్వచించు APPLICATION_VERIFIER_INVALID_FREEMEM 0x0600
#నిర్వచించు APPLICATION_VERIFIER_INVALID_ALLOCMEM 0x0601
#నిర్వచించు APPLICATION_VERIFIER_INVALID_MAPVIEW 0x0602
#నిర్వచించు APPLICATION_VERIFIER_PROBE_INVALID_చిరునామా 0x0603
#నిర్వచించు APPLICATION_VERIFIER_PROBE_FREE_MEM 0x0604
#నిర్వచించు APPLICATION_VERIFIER_PROBE_GUARD_పుట 0x0605
#నిర్వచించు APPLICATION_VERIFIER_PROBE_NULL 0x0606
#నిర్వచించు APPLICATION_VERIFIER_PROBE_INVALID_ప్రారంభం_OR_కొలత 0x0607
#నిర్వచించు APPLICATION_VERIFIER_కొలత_కుప్ప_UNEXPECTED_EXCEPTION 0x0618

#నిర్వచించు VERIFIER_STOP(సంకేతం_5,సందేశం_5,P1,S1,P2,S2,P3,S3,P4,S4) { RtlApplicationVerifierStop ((సంకేతం_5),(సందేశం_5),(ULONG_PTR)(P1),(S1),(ULONG_PTR)(P2),(S2),(ULONG_PTR)(P3),(S3),(ULONG_PTR)(P4),(S4)); }

    VOID NTAPI RtlApplicationVerifierStop(ULONG_PTR సంకేతం_5,PSTR సందేశం_6,ULONG_PTR Param1,PSTR Description1,ULONG_PTR Param2,PSTR Description2,ULONG_PTR Param3,PSTR Description3,ULONG_PTR Param4,PSTR Description4);

    రకనిర్వచనం LONG (NTAPI *PVECTORED_EXCEPTION_HANDLER)(నిర్మాణం EXCEPTION_సూచికలు_2 *ExceptionInfo);
#నిర్వచించు SEF_DACL_AUTO_INHERIT 0x01
#నిర్వచించు SEF_SACL_AUTO_INHERIT 0x02
#నిర్వచించు SEF_DEFAULT_DESCRIPTOR_FOR_OBJECT 0x04
#నిర్వచించు SEF_AVOID_PRIVILEGE_CHECK 0x08
#నిర్వచించు SEF_AVOID_OWNER_CHECK 0x10
#నిర్వచించు SEF_DEFAULT_OWNER_FROM_మాతృ 0x20
#నిర్వచించు SEF_DEFAULT_సమూహం_FROM_మాతృ 0x40

    రకనిర్వచనం గణన కుప్ప_INFORMATION_CLASS_2 {
      కుప్ప_Compatibility_Information
    } కుప్ప_INFORMATION_CLASS;

    NTSYSAPI DWORD NTAPI Rtl_సమితి_కుప్ప_Information(PVOID కుప్ప_Handle,కుప్ప_INFORMATION_CLASS కుప్ప_Information_Class,PVOID కుప్ప_Information,కొలత_T కుప్ప_Information_నిడివి);
    NTSYSAPI DWORD NTAPI Rtl_Query_కుప్ప_Information(PVOID కుప్ప_Handle,కుప్ప_INFORMATION_CLASS కుప్ప_Information_Class,PVOID కుప్ప_Information,కొలత_T కుప్ప_Information_నిడివి,PSIZE_T Return_నిడివి);
    DWORD NTAPI Rtl_గుణిజం_Allocate_కుప్ప(PVOID కుప్ప_Handle,DWORD Flags,కొలత_T కొలత_3,DWORD లెక్క_3,PVOID *Array);
    DWORD NTAPI Rtl_గుణిజం_Free_కుప్ప(PVOID కుప్ప_Handle,DWORD Flags,DWORD లెక్క_3,PVOID *Array);

#నిర్వచించు WT_EXECUTEDEFAULT 0x00000000
#నిర్వచించు WT_EXECUTEINIOTHREAD 0x00000001
#నిర్వచించు WT_EXECUTEINUITHREAD 0x00000002
#నిర్వచించు WT_EXECUTEINWAITTHREAD 0x00000004
#నిర్వచించు WT_EXECUTEONLYONCE 0x00000008
#నిర్వచించు WT_EXECUTEINTIMERTHREAD 0x00000020
#నిర్వచించు WT_EXECUTELONGFUNCTION 0x00000010
#నిర్వచించు WT_EXECUTEINPERSISTENTIOTHREAD 0x00000040
#నిర్వచించు WT_EXECUTEINPERSISTENTTHREAD 0x00000080
#నిర్వచించు WT_TRANSFER_IMPERSONATION 0x00000100
#నిర్వచించు WT_సమితి_MAX_THREADPOOL_దారాలు(Flags,హద్దు_2) ((Flags) |= (హద్దు_2)<<16)
    రకనిర్వచనం VOID (NTAPI *WAITORTIMERCALLBACKFUNC)(PVOID,BOOLEAN);
    రకనిర్వచనం VOID (NTAPI *WORKERCALLBACKFUNC)(PVOID);
    రకనిర్వచనం VOID (NTAPI *APC_CALLBACK_FUNCTION)(DWORD ,PVOID,PVOID);
    రకనిర్వచనం
      VOID
      (NTAPI *PFLS_CALLBACK_FUNCTION)(PVOID lp_Fls_దత్తాంశం);
#నిర్వచించు WT_EXECUTEINLONGTHREAD 0x00000010
#నిర్వచించు WT_EXECUTEDELETEWAIT 0x00000008

    రకనిర్వచనం గణన _ACTIVATION_CONTEXT_INFO_CLASS {
      ActivationContextBasicInformation = 1,ActivationContextDetailedInformation = 2,Assembly_Detailed_Information_లోపల_Activation_Context = 3,File_Information_లోపల_Assembly_యొక్క_Assembly_లోపల_Activation_Context = 4,MaxActivationContextInfoClass,Assembly_Detailed_Information_లోపల_Activation_Contxt = 3,File_Information_లోపల_Assembly_యొక్క_Assembly_లోపల_Activation_Contxt = 4
    } ACTIVATION_CONTEXT_INFO_CLASS;

#నిర్వచించు ACTIVATIONCONTEXTINFOCLASS ACTIVATION_CONTEXT_INFO_CLASS

    రకనిర్వచనం నిర్మాణం ACTIVATION_CONTEXT_QUERY_సూచీ {
      DWORD ul_Assembly_సూచీ;
      DWORD ul_File_సూచీ_లోపల_Assembly;
    } ACTIVATION_CONTEXT_QUERY_సూచీ_2,*PACTIVATION_CONTEXT_QUERY_సూచీ;

    రకనిర్వచనం స్థిరరాశి నిర్మాణం ACTIVATION_CONTEXT_QUERY_సూచీ *PCACTIVATION_CONTEXT_QUERY_సూచీ;

#నిర్వచించు ACTIVATION_CONTEXT_మార్గం_TYPE_NONE (1)
#నిర్వచించు ACTIVATION_CONTEXT_మార్గం_TYPE_WIN32_FILE (2)
#నిర్వచించు ACTIVATION_CONTEXT_మార్గం_TYPE_URL (3)
#నిర్వచించు ACTIVATION_CONTEXT_మార్గం_TYPE_ASSEMBLYREF (4)

    రకనిర్వచనం నిర్మాణం _ASSEMBLY_FILE_DETAILED_INFORMATION {
      DWORD ulFlags;
      DWORD ul_Filename_నిడివి;
      DWORD ul_మార్గం_నిడివి;

      PCWSTR lpFileName;
      PCWSTR lp_File_మార్గం;
    } ASSEMBLY_FILE_DETAILED_INFORMATION,*PASSEMBLY_FILE_DETAILED_INFORMATION;
    రకనిర్వచనం స్థిరరాశి ASSEMBLY_FILE_DETAILED_INFORMATION *PCASSEMBLY_FILE_DETAILED_INFORMATION;

#నిర్వచించు _ASSEMBLY_DLL_REDIRECTION_DETAILED_INFORMATION _ASSEMBLY_FILE_DETAILED_INFORMATION
#నిర్వచించు ASSEMBLY_DLL_REDIRECTION_DETAILED_INFORMATION ASSEMBLY_FILE_DETAILED_INFORMATION
#నిర్వచించు PASSEMBLY_DLL_REDIRECTION_DETAILED_INFORMATION PASSEMBLY_FILE_DETAILED_INFORMATION
#నిర్వచించు PCASSEMBLY_DLL_REDIRECTION_DETAILED_INFORMATION PCASSEMBLY_FILE_DETAILED_INFORMATION

    రకనిర్వచనం నిర్మాణం _ACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION {
      DWORD ulFlags;
      DWORD ul_Encoded_Assembly_తటస్థం_నిడివి;
      DWORD ul_Manifest_మార్గం_Type;
      DWORD ul_Manifest_మార్గం_నిడివి;
      LARGE_INTEGER li_Manifest_చివరి_Write_సమయం;
      DWORD ul_Policy_మార్గం_Type;
      DWORD ul_Policy_మార్గం_నిడివి;
      LARGE_INTEGER li_Policy_చివరి_Write_సమయం;
      DWORD ul_Metadata_Satellite_Roster_సూచీ;
      DWORD ul_Manifest_సంస్కరణ_Major;
      DWORD ul_Manifest_సంస్కరణ_Minor;
      DWORD ul_Policy_సంస్కరణ_Major;
      DWORD ul_Policy_సంస్కరణ_Minor;
      DWORD ul_Assembly_Directory_Name_నిడివి;
      PCWSTR lp_Assembly_Encoded_Assembly_తటస్థం;
      PCWSTR lp_Assembly_Manifest_మార్గం;
      PCWSTR lp_Assembly_Policy_మార్గం;
      PCWSTR lpAssemblyDirectoryName;
      DWORD ul_File_లెక్క;
    } ACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION,*PACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION;

    రకనిర్వచనం స్థిరరాశి నిర్మాణం _ACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION *PCACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION;

    రకనిర్వచనం నిర్మాణం _ACTIVATION_CONTEXT_DETAILED_INFORMATION {
      DWORD dwFlags;
      DWORD ul_Format_సంస్కరణ;
      DWORD ul_Assembly_లెక్క;
      DWORD ul_మూలం_Manifest_మార్గం_Type;
      DWORD ul_మూలం_Manifest_మార్గం_Chars;
      DWORD ul_మూలం_Configuration_మార్గం_Type;
      DWORD ul_మూలం_Configuration_మార్గం_Chars;
      DWORD ul_App_Dir_మార్గం_Type;
      DWORD ul_App_Dir_మార్గం_Chars;
      PCWSTR lp_మూలం_Manifest_మార్గం;
      PCWSTR lp_మూలం_Configuration_మార్గం;
      PCWSTR lp_App_Dir_మార్గం;
    } ACTIVATION_CONTEXT_DETAILED_INFORMATION,*PACTIVATION_CONTEXT_DETAILED_INFORMATION;

    రకనిర్వచనం స్థిరరాశి నిర్మాణం _ACTIVATION_CONTEXT_DETAILED_INFORMATION *PCACTIVATION_CONTEXT_DETAILED_INFORMATION;

#నిర్వచించు DLL_PROCESS_ATTACH 1
#నిర్వచించు DLL_THREAD_ATTACH 2
#నిర్వచించు DLL_THREAD_DETACH 3
#నిర్వచించు DLL_PROCESS_DETACH 0
#నిర్వచించు DLL_PROCESS_VERIFIER 4

#నిర్వచించు EVENTLOG_SEQUENTIAL_READ 0x0001
#నిర్వచించు EVENTLOG_SEEK_READ 0x0002
#నిర్వచించు EVENTLOG_FORWARDS_READ 0x0004
#నిర్వచించు EVENTLOG_BACKWARDS_READ 0x0008

#నిర్వచించు EVENTLOG_SUCCESS 0x0000
#నిర్వచించు EVENTLOG_ERROR_TYPE 0x0001
#నిర్వచించు EVENTLOG_WARNING_TYPE 0x0002
#నిర్వచించు EVENTLOG_INFORMATION_TYPE 0x0004
#నిర్వచించు EVENTLOG_AUDIT_SUCCESS 0x0008
#నిర్వచించు EVENTLOG_AUDIT_FAILURE 0x0010

#నిర్వచించు EVENTLOG_ప్రారంభం_PAIRED_EVENT 0x0001
#నిర్వచించు EVENTLOG_చివర_PAIRED_EVENT 0x0002
#నిర్వచించు EVENTLOG_చివర_ALL_PAIRED_EVENTS 0x0004
#నిర్వచించు EVENTLOG_PAIRED_EVENT_చురుకైన 0x0008
#నిర్వచించు EVENTLOG_PAIRED_EVENT_INACTIVE 0x0010

    రకనిర్వచనం నిర్మాణం _EVENTLOGRECORD {
      DWORD నిడివి_2;
      DWORD Reserved;
      DWORD రికార్డు_సంఖ్య;
      DWORD సమయం_Generated;
      DWORD సమయం_Written;
      DWORD EventID;
      మాట_3 EventType;
      మాట_3 అంకె_అక్షరశ్రేణులు;
      మాట_3 EventCategory;
      మాట_3 ReservedFlags;
      DWORD Closing_రికార్డు_సంఖ్య;
      DWORD String_స్థానభ్రంశం;
      DWORD User_Sid_నిడివి;
      DWORD User_Sid_స్థానభ్రంశం;
      DWORD దత్తాంశం_నిడివి;
      DWORD దత్తాంశం_స్థానభ్రంశం_2;
    } EVENTLOGRECORD,*PEVENTLOGRECORD;

#నిర్వచించు MAXLOGICALLOGNAMESIZE 256

    రకనిర్వచనం నిర్మాణం _EVENTSFORLOGFILE{
      DWORD ul_కొలత;
      WCHAR szLogicalLogFile[MAXLOGICALLOGNAMESIZE];
      DWORD ul_అంకె_రికార్డులు;
      EVENTLOGRECORD p_Event_Log_రికార్డులు[];
    } EVENTSFORLOGFILE,*PEVENTSFORLOGFILE;

    రకనిర్వచనం నిర్మాణం _PACKEDEVENTINFO{
      DWORD ul_కొలత;
      DWORD ul_అంకె_Events_For_Log_File;
      DWORD ulOffsets[];
    } PACKEDEVENTINFO,*PPACKEDEVENTINFO;

#నిర్వచించు కీలకం_QUERY_విలువ (0x0001)
#నిర్వచించు కీలకం_సమితి_విలువ (0x0002)
#నిర్వచించు కీలకం_CREATE_SUB_కీలకం (0x0004)
#నిర్వచించు కీలకం_ENUMERATE_SUB_కీలకాలు (0x0008)
#నిర్వచించు కీలకం_NOTIFY (0x0010)
#నిర్వచించు కీలకం_CREATE_LINK (0x0020)
#నిర్వచించు కీలకం_WOW64_32_కీలకం (0x0200)
#నిర్వచించు కీలకం_WOW64_64_కీలకం (0x0100)
#నిర్వచించు కీలకం_WOW64_RES (0x0300)

#నిర్వచించు కీలకం_READ ((STANDARD_RIGHTS_READ | కీలకం_QUERY_విలువ | కీలకం_ENUMERATE_SUB_కీలకాలు | కీలకం_NOTIFY) & (~SYNCHRONIZE))
#నిర్వచించు కీలకం_WRITE ((STANDARD_RIGHTS_WRITE | కీలకం_సమితి_విలువ | కీలకం_CREATE_SUB_కీలకం) & (~SYNCHRONIZE))
#నిర్వచించు కీలకం_EXECUTE ((కీలకం_READ) & (~SYNCHRONIZE))
#నిర్వచించు కీలకం_ALL_ACCESS ((STANDARD_RIGHTS_ALL | కీలకం_QUERY_విలువ | కీలకం_సమితి_విలువ | కీలకం_CREATE_SUB_కీలకం | కీలకం_ENUMERATE_SUB_కీలకాలు | కీలకం_NOTIFY | కీలకం_CREATE_LINK) & (~SYNCHRONIZE))
#నిర్వచించు REG_OPTION_RESERVED (0x00000000L)

#నిర్వచించు REG_OPTION_NON_VOLATILE (0x00000000L)
#నిర్వచించు REG_OPTION_VOLATILE (0x00000001L)
#నిర్వచించు REG_OPTION_CREATE_LINK (0x00000002L)
#నిర్వచించు REG_OPTION_BACKUP_RESTORE (0x00000004L)
#నిర్వచించు REG_OPTION_OPEN_LINK (0x00000008L)
#నిర్వచించు REG_LEGAL_OPTION (REG_OPTION_RESERVED | REG_OPTION_NON_VOLATILE | REG_OPTION_VOLATILE | REG_OPTION_CREATE_LINK | REG_OPTION_BACKUP_RESTORE | REG_OPTION_OPEN_LINK)
#నిర్వచించు REG_CREATED_NEW_కీలకం (0x00000001L)
#నిర్వచించు REG_OPENED_EXISTING_కీలకం (0x00000002L)
#నిర్వచించు REG_STANDARD_FORMAT 1
#నిర్వచించు REG_LATEST_FORMAT 2
#నిర్వచించు REG_NO_COMPRESSION 4
#నిర్వచించు REG_సంపూర్ణ_HIVE_VOLATILE (0x00000001L)
#నిర్వచించు REG_REFRESH_HIVE (0x00000002L)
#నిర్వచించు REG_NO_LAZY_FLUSH (0x00000004L)
#నిర్వచించు REG_FORCE_RESTORE (0x00000008L)
#నిర్వచించు REG_FORCE_UNLOAD 1

#నిర్వచించు REG_NOTIFY_CHANGE_NAME (0x00000001L)
#నిర్వచించు REG_NOTIFY_CHANGE_లక్షణాలు (0x00000002L)
#నిర్వచించు REG_NOTIFY_CHANGE_చివరి_సమితి (0x00000004L)
#నిర్వచించు REG_NOTIFY_CHANGE_SECURITY (0x00000008L)

#నిర్వచించు REG_LEGAL_CHANGE_FILTER (REG_NOTIFY_CHANGE_NAME | REG_NOTIFY_CHANGE_లక్షణాలు | REG_NOTIFY_CHANGE_చివరి_సమితి | REG_NOTIFY_CHANGE_SECURITY)

#నిర్వచించు REG_NONE (0)
#నిర్వచించు REG_SZ (1)
#నిర్వచించు REG_EXPAND_SZ (2)

#నిర్వచించు REG_ద్విమాన (3)
#నిర్వచించు REG_DWORD (4)
#నిర్వచించు REG_DWORD_LITTLE_ENDIAN (4)
#నిర్వచించు REG_DWORD_BIG_ENDIAN (5)
#నిర్వచించు REG_LINK (6)
#నిర్వచించు REG_MULTI_SZ (7)
#నిర్వచించు REG_RESOURCE_LIST (8)
#నిర్వచించు REG_నిండిన_RESOURCE_DESCRIPTOR (9)
#నిర్వచించు REG_RESOURCE_REQUIREMENTS_LIST (10)
#నిర్వచించు REG_QWORD (11)
#నిర్వచించు REG_QWORD_LITTLE_ENDIAN (11)

#నిర్వచించు SERVICE_KERNEL_DRIVER 0x00000001
#నిర్వచించు SERVICE_FILE_SYSTEM_DRIVER 0x00000002
#నిర్వచించు SERVICE_ADAPTER 0x00000004
#నిర్వచించు SERVICE_RECOGNIZER_DRIVER 0x00000008

#నిర్వచించు SERVICE_DRIVER (SERVICE_KERNEL_DRIVER | SERVICE_FILE_SYSTEM_DRIVER | SERVICE_RECOGNIZER_DRIVER)

#నిర్వచించు SERVICE_WIN32_OWN_PROCESS 0x00000010
#నిర్వచించు SERVICE_WIN32_SHARE_PROCESS 0x00000020
#నిర్వచించు SERVICE_WIN32 (SERVICE_WIN32_OWN_PROCESS | SERVICE_WIN32_SHARE_PROCESS)

#నిర్వచించు SERVICE_INTERACTIVE_PROCESS 0x00000100

#నిర్వచించు SERVICE_TYPE_ALL (SERVICE_WIN32 | SERVICE_ADAPTER | SERVICE_DRIVER | SERVICE_INTERACTIVE_PROCESS)

#నిర్వచించు SERVICE_BOOT_ప్రారంభం 0x00000000
#నిర్వచించు SERVICE_SYSTEM_ప్రారంభం 0x00000001
#నిర్వచించు SERVICE_AUTO_ప్రారంభం 0x00000002
#నిర్వచించు SERVICE_DEMAND_ప్రారంభం 0x00000003
#నిర్వచించు SERVICE_DISABLED 0x00000004

#నిర్వచించు SERVICE_ERROR_IGNORE 0x00000000
#నిర్వచించు SERVICE_ERROR_సాధారణ 0x00000001
#నిర్వచించు SERVICE_ERROR_SEVERE 0x00000002
#నిర్వచించు SERVICE_ERROR_CRITICAL 0x00000003

    రకనిర్వచనం గణన CM_SERVICE_కణుపు_TYPE {
      DriverType = SERVICE_KERNEL_DRIVER,FileSystemType = SERVICE_FILE_SYSTEM_DRIVER,Win32ServiceOwnProcess = SERVICE_WIN32_OWN_PROCESS,
      Win32ServiceShareProcess = SERVICE_WIN32_SHARE_PROCESS,AdapterType = SERVICE_ADAPTER,RecognizerType = SERVICE_RECOGNIZER_DRIVER
    } SERVICE_కణుపు_TYPE;

    రకనిర్వచనం గణన CM_SERVICE_ఎక్కించు_TYPE {
      Boot_ఎక్కించు = SERVICE_BOOT_ప్రారంభం,System_ఎక్కించు = SERVICE_SYSTEM_ప్రారంభం,Auto_ఎక్కించు = SERVICE_AUTO_ప్రారంభం,Demand_ఎక్కించు = SERVICE_DEMAND_ప్రారంభం,
      Disable_ఎక్కించు = SERVICE_DISABLED
    } SERVICE_ఎక్కించు_TYPE;

    రకనిర్వచనం గణన _CM_ERROR_CONTROL_TYPE {
      IgnoreError = SERVICE_ERROR_IGNORE,సాధారణ_Error = SERVICE_ERROR_సాధారణ,SevereError = SERVICE_ERROR_SEVERE,CriticalError = SERVICE_ERROR_CRITICAL
    } SERVICE_ERROR_TYPE;

#నిర్వచించు పట్టీ_ERASE_SHORT 0L
#నిర్వచించు పట్టీ_ERASE_LONG 1L

    రకనిర్వచనం నిర్మాణం పట్టీ_ERASE {
      DWORD Type;
      BOOLEAN తక్షణ_2;
    } పట్టీ_ERASE_2,*PTAPE_ERASE;

#నిర్వచించు పట్టీ_ఎక్కించు 0L
#నిర్వచించు పట్టీ_UNLOAD 1L
#నిర్వచించు పట్టీ_TENSION 2L
#నిర్వచించు పట్టీ_తాళం 3L
#నిర్వచించు పట్టీ_UNLOCK 4L
#నిర్వచించు పట్టీ_FORMAT 5L

    రకనిర్వచనం నిర్మాణం పట్టీ_PREPARE {
      DWORD Operation;
      BOOLEAN తక్షణ_2;
    } పట్టీ_PREPARE_2,*PTAPE_PREPARE;

#నిర్వచించు పట్టీ_SETMARKS 0L
#నిర్వచించు పట్టీ_FILEMARKS 1L
#నిర్వచించు పట్టీ_SHORT_FILEMARKS 2L
#నిర్వచించు పట్టీ_LONG_FILEMARKS 3L

    రకనిర్వచనం నిర్మాణం పట్టీ_WRITE_MARKS {
      DWORD Type;
      DWORD లెక్క_3;
      BOOLEAN తక్షణ_2;
    } పట్టీ_WRITE_MARKS_2,*PTAPE_WRITE_MARKS;

#నిర్వచించు పట్టీ_ABSOLUTE_POSITION 0L
#నిర్వచించు పట్టీ_LOGICAL_POSITION 1L
#నిర్వచించు పట్టీ_PSEUDO_LOGICAL_POSITION 2L

    రకనిర్వచనం నిర్మాణం పట్టీ_GET_POSITION {
      DWORD Type;
      DWORD విభజన_2;
      LARGE_INTEGER స్థానభ్రంశం_3;
    } పట్టీ_GET_POSITION_2,*PTAPE_GET_POSITION;

#నిర్వచించు పట్టీ_REWIND 0L
#నిర్వచించు పట్టీ_ABSOLUTE_ఖండం 1L
#నిర్వచించు పట్టీ_LOGICAL_ఖండం 2L
#నిర్వచించు పట్టీ_PSEUDO_LOGICAL_ఖండం 3L
#నిర్వచించు పట్టీ_SPACE_చివర_యొక్క_దత్తాంశం 4L
#నిర్వచించు పట్టీ_SPACE_RELATIVE_ఖండాలు 5L
#నిర్వచించు పట్టీ_SPACE_FILEMARKS 6L
#నిర్వచించు పట్టీ_SPACE_SEQUENTIAL_FMKS 7L
#నిర్వచించు పట్టీ_SPACE_SETMARKS 8L
#నిర్వచించు పట్టీ_SPACE_SEQUENTIAL_SMKS 9L

    రకనిర్వచనం నిర్మాణం పట్టీ_సమితి_POSITION {
      DWORD పద్ధతి_2;
      DWORD విభజన_2;
      LARGE_INTEGER స్థానభ్రంశం_3;
      BOOLEAN తక్షణ_2;
    } పట్టీ_సమితి_POSITION_2,*PTAPE_సమితి_POSITION;

#నిర్వచించు పట్టీ_DRIVE_FIXED 0x00000001
#నిర్వచించు పట్టీ_DRIVE_SELECT 0x00000002
#నిర్వచించు పట్టీ_DRIVE_INITIATOR 0x00000004

#నిర్వచించు పట్టీ_DRIVE_ERASE_SHORT 0x00000010
#నిర్వచించు పట్టీ_DRIVE_ERASE_LONG 0x00000020
#నిర్వచించు పట్టీ_DRIVE_ERASE_BOP_ONLY 0x00000040
#నిర్వచించు పట్టీ_DRIVE_ERASE_తక్షణ 0x00000080

#నిర్వచించు పట్టీ_DRIVE_పట్టీ_సామర్థ్యం 0x00000100
#నిర్వచించు పట్టీ_DRIVE_పట్టీ_మిగిలిన 0x00000200
#నిర్వచించు పట్టీ_DRIVE_FIXED_ఖండం 0x00000400
#నిర్వచించు పట్టీ_DRIVE_VARIABLE_ఖండం 0x00000800

#నిర్వచించు పట్టీ_DRIVE_WRITE_PROTECT 0x00001000
#నిర్వచించు పట్టీ_DRIVE_EOT_WZ_కొలత 0x00002000

#నిర్వచించు పట్టీ_DRIVE_ECC 0x00010000
#నిర్వచించు పట్టీ_DRIVE_COMPRESSION 0x00020000
#నిర్వచించు పట్టీ_DRIVE_PADDING 0x00040000
#నిర్వచించు పట్టీ_DRIVE_REPORT_SMKS 0x00080000

#నిర్వచించు పట్టీ_DRIVE_GET_ABSOLUTE_BLK 0x00100000
#నిర్వచించు పట్టీ_DRIVE_GET_LOGICAL_BLK 0x00200000
#నిర్వచించు పట్టీ_DRIVE_సమితి_EOT_WZ_కొలత 0x00400000

#నిర్వచించు పట్టీ_DRIVE_EJECT_MEDIA 0x01000000
#నిర్వచించు పట్టీ_DRIVE_CLEAN_అభ్యర్థనలు 0x02000000
#నిర్వచించు పట్టీ_DRIVE_సమితి_CMP_BOP_ONLY 0x04000000

#నిర్వచించు పట్టీ_DRIVE_RESERVED_బిట్టు 0x80000000

#నిర్వచించు పట్టీ_DRIVE_ఎక్కించు_UNLOAD 0x80000001
#నిర్వచించు పట్టీ_DRIVE_TENSION 0x80000002
#నిర్వచించు పట్టీ_DRIVE_తాళం_UNLOCK 0x80000004
#నిర్వచించు పట్టీ_DRIVE_REWIND_తక్షణ 0x80000008

#నిర్వచించు పట్టీ_DRIVE_సమితి_ఖండం_కొలత 0x80000010
#నిర్వచించు పట్టీ_DRIVE_ఎక్కించు_UNLD_IMMED 0x80000020
#నిర్వచించు పట్టీ_DRIVE_TENSION_IMMED 0x80000040
#నిర్వచించు పట్టీ_DRIVE_తాళం_UNLK_IMMED 0x80000080

#నిర్వచించు పట్టీ_DRIVE_సమితి_ECC 0x80000100
#నిర్వచించు పట్టీ_DRIVE_సమితి_COMPRESSION 0x80000200
#నిర్వచించు పట్టీ_DRIVE_సమితి_PADDING 0x80000400
#నిర్వచించు పట్టీ_DRIVE_సమితి_REPORT_SMKS 0x80000800

#నిర్వచించు పట్టీ_DRIVE_ABSOLUTE_BLK 0x80001000
#నిర్వచించు పట్టీ_DRIVE_ABS_BLK_IMMED 0x80002000
#నిర్వచించు పట్టీ_DRIVE_LOGICAL_BLK 0x80004000
#నిర్వచించు పట్టీ_DRIVE_LOG_BLK_IMMED 0x80008000

#నిర్వచించు పట్టీ_DRIVE_చివర_యొక్క_దత్తాంశం 0x80010000
#నిర్వచించు పట్టీ_DRIVE_RELATIVE_BLKS 0x80020000
#నిర్వచించు పట్టీ_DRIVE_FILEMARKS 0x80040000
#నిర్వచించు పట్టీ_DRIVE_SEQUENTIAL_FMKS 0x80080000

#నిర్వచించు పట్టీ_DRIVE_SETMARKS 0x80100000
#నిర్వచించు పట్టీ_DRIVE_SEQUENTIAL_SMKS 0x80200000
#నిర్వచించు పట్టీ_DRIVE_తిరగేయి_POSITION 0x80400000
#నిర్వచించు పట్టీ_DRIVE_SPACE_తక్షణ 0x80800000

#నిర్వచించు పట్టీ_DRIVE_WRITE_SETMARKS 0x81000000
#నిర్వచించు పట్టీ_DRIVE_WRITE_FILEMARKS 0x82000000
#నిర్వచించు పట్టీ_DRIVE_WRITE_SHORT_FMKS 0x84000000
#నిర్వచించు పట్టీ_DRIVE_WRITE_LONG_FMKS 0x88000000

#నిర్వచించు పట్టీ_DRIVE_WRITE_MARK_IMMED 0x90000000
#నిర్వచించు పట్టీ_DRIVE_FORMAT 0xA0000000
#నిర్వచించు పట్టీ_DRIVE_FORMAT_తక్షణ 0xC0000000
#నిర్వచించు పట్టీ_DRIVE_ఎగువ_FEATURES 0x80000000

    రకనిర్వచనం నిర్మాణం పట్టీ_GET_DRIVE_PARAMETERS {
      BOOLEAN ECC;
      BOOLEAN Compression;
      BOOLEAN దత్తాంశం_Padding;
      BOOLEAN ReportSetmarks;
      DWORD Default_ఖండం_కొలత;
      DWORD గరిష్ఠ_ఖండం_కొలత;
      DWORD Minimum_ఖండం_కొలత;
      DWORD గరిష్ఠ_విభజన_లెక్క;
      DWORD Features_దిగువ;
      DWORD Features_ఎగువ;
      DWORD EOTWarning_Zone_కొలత;
    } పట్టీ_GET_DRIVE_PARAMETERS_2,*PTAPE_GET_DRIVE_PARAMETERS;

    రకనిర్వచనం నిర్మాణం పట్టీ_సమితి_DRIVE_PARAMETERS {
      BOOLEAN ECC;
      BOOLEAN Compression;
      BOOLEAN దత్తాంశం_Padding;
      BOOLEAN ReportSetmarks;
      DWORD EOTWarning_Zone_కొలత;
    } పట్టీ_సమితి_DRIVE_PARAMETERS_2,*PTAPE_సమితి_DRIVE_PARAMETERS;

    రకనిర్వచనం నిర్మాణం పట్టీ_GET_MEDIA_PARAMETERS {
      LARGE_INTEGER సామర్థ్యం;
      LARGE_INTEGER మిగిలిన;
      DWORD ఖండం_కొలత;
      DWORD విభజన_లెక్క;
      BOOLEAN WriteProtected;
    } పట్టీ_GET_MEDIA_PARAMETERS_2,*PTAPE_GET_MEDIA_PARAMETERS;

    రకనిర్వచనం నిర్మాణం పట్టీ_సమితి_MEDIA_PARAMETERS {
      DWORD ఖండం_కొలత;
    } పట్టీ_సమితి_MEDIA_PARAMETERS_2,*PTAPE_సమితి_MEDIA_PARAMETERS;

#నిర్వచించు పట్టీ_FIXED_PARTITIONS 0L
#నిర్వచించు పట్టీ_SELECT_PARTITIONS 1L
#నిర్వచించు పట్టీ_INITIATOR_PARTITIONS 2L

    రకనిర్వచనం నిర్మాణం పట్టీ_CREATE_విభజన {
      DWORD పద్ధతి_2;
      DWORD లెక్క_3;
      DWORD కొలత_3;
    } పట్టీ_CREATE_విభజన_2,*PTAPE_CREATE_విభజన;

#నిర్వచించు పట్టీ_QUERY_DRIVE_PARAMETERS 0L
#నిర్వచించు పట్టీ_QUERY_MEDIA_సామర్థ్యం 1L
#నిర్వచించు పట్టీ_CHECK_FOR_DRIVE_PROBLEM 2L
#నిర్వచించు పట్టీ_QUERY_IO_ERROR_దత్తాంశం 3L
#నిర్వచించు పట్టీ_QUERY_DEVICE_ERROR_దత్తాంశం 4L

    రకనిర్వచనం నిర్మాణం పట్టీ_WMI_OPERATIONS {
      DWORD పద్ధతి_2;
      DWORD దత్తాంశం_బఫరు_కొలత;
      PVOID దత్తాంశం_బఫరు;
    } పట్టీ_WMI_OPERATIONS_2,*PTAPE_WMI_OPERATIONS;

    రకనిర్వచనం గణన పట్టీ_DRIVE_PROBLEM_TYPE {
      పట్టీ_Drive_Problem_None,పట్టీ_Drive_Read_Write_Warning,పట్టీ_Drive_Read_Write_Error,పట్టీ_Drive_Read_Warning,పట్టీ_Drive_Write_Warning,పట్టీ_Drive_Read_Error,పట్టీ_Drive_Write_Error,పట్టీ_Drive_Hardware_Error,పట్టీ_Drive_Unsupported_Media,పట్టీ_Drive_Scsi_Connection_Error,పట్టీ_Drive_Timeto_Clean,పట్టీ_Drive_Clean_Drive_Now,పట్టీ_Drive_Media_Life_Expired,పట్టీ_Drive_Snapped_పట్టీ
    } పట్టీ_DRIVE_PROBLEM_TYPE_2;

#ఒకవేళ defined(__x86_64)
    __CRT_INLINE నిర్మాణం _TEB *NtCurrentTeb(VOID) { తిరిగి (నిర్మాణం _TEB *)__readgsqword(క్షేత్రం_స్థానభ్రంశం(NT_TIB,Self)); }
    __CRT_INLINE PVOID GetCurrentFiber(VOID) { తిరిగి(PVOID)__readgsqword(క్షేత్రం_స్థానభ్రంశం(NT_TIB,Fiber_దత్తాంశం)); }
    __CRT_INLINE PVOID Get_Fiber_దత్తాంశం(VOID) {
      తిరిగి *(PVOID *)GetCurrentFiber();
    }
#అయితే_ముగింపు

#ఒకవేళ(defined(_X86_) && !defined(__x86_64))
#నిర్వచించు PcTeb 0x18
    __CRT_INLINE నిర్మాణం _TEB *NtCurrentTeb(శూన్య) {
      నిర్మాణం _TEB *ret;
      __asm__ అస్థిర ("movl	%%fs:0x18,%0"
	: "=r" (ret));
      తిరిగి ret;
    }
#అయితే_ముగింపు

#నిర్వచించు ACTIVATION_CONTEXT_SECTION_ASSEMBLY_INFORMATION (1)
#నిర్వచించు ACTIVATION_CONTEXT_SECTION_DLL_REDIRECTION (2)
#నిర్వచించు ACTIVATION_CONTEXT_SECTION_కిటికీ_CLASS_REDIRECTION (3)
#నిర్వచించు ACTIVATION_CONTEXT_SECTION_COM_SERVER_REDIRECTION (4)
#నిర్వచించు ACTIVATION_CONTEXT_SECTION_COM_INTERFACE_REDIRECTION (5)
#నిర్వచించు ACTIVATION_CONTEXT_SECTION_COM_TYPE_LIBRARY_REDIRECTION (6)
#నిర్వచించు ACTIVATION_CONTEXT_SECTION_COM_PROGID_REDIRECTION (7)
#నిర్వచించు ACTIVATION_CONTEXT_SECTION_GLOBAL_OBJECT_RENAME_పట్టిక (8)
#నిర్వచించు ACTIVATION_CONTEXT_SECTION_CLR_SURROGATES (9)
#నిర్వచించు ACTIVATION_CONTEXT_SECTION_APPLICATION_SETTINGS (10)

#నిర్వచితమైతే __cplusplus
  }
#అయితే_ముగింపు
#అయితే_ముగింపు
