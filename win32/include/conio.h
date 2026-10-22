/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جے_بنا_تعریف _INC_CONIO
#تعریف_کرو _INC_CONIO

#ضمن <_mingw.h>

#جے_تعریف_شدہ __cplusplus
خارجي "C" {
#جے_انت

  _CRTIMP حرف *_cgets(حرف *بفر_2);
  _CRTIMP صحيح __cdecl _cprintf(ثابت حرف *_Format,...);
  _CRTIMP صحيح __cdecl _cputs(ثابت حرف *_Str);
  _CRTIMP صحيح __cdecl _cscanf(ثابت حرف *_Format,...);
  _CRTIMP صحيح __cdecl _cscanf_l(ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _getch(فراغ);
  _CRTIMP صحيح __cdecl _getche(فراغ);
  _CRTIMP صحيح __cdecl _vcprintf(ثابت حرف *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _cprintf_p(ثابت حرف *_Format,...);
  _CRTIMP صحيح __cdecl _vcprintf_p(ثابت حرف *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _cprintf_l(ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vcprintf_l(ثابت حرف *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _cprintf_p_l(ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vcprintf_p_l(ثابت حرف *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _kbhit(فراغ);

#إذا defined(_X86_) && !defined(__x86_64)
  صحيح __cdecl _inp(بنانشانی چھوٹا);
  بنانشانی چھوٹا __cdecl _inpw(بنانشانی چھوٹا);
  بنانشانی لما __cdecl _inpd(بنانشانی چھوٹا);
  صحيح __cdecl _outp(بنانشانی چھوٹا,صحيح);
  بنانشانی چھوٹا __cdecl _outpw(بنانشانی چھوٹا,بنانشانی چھوٹا);
  بنانشانی لما __cdecl _outpd(بنانشانی چھوٹا,بنانشانی لما);
#جے_انت

  _CRTIMP صحيح __cdecl _putch(صحيح _Ch);
  _CRTIMP صحيح __cdecl _ungetch(صحيح _Ch);
  _CRTIMP صحيح __cdecl _getch_nolock(فراغ);
  _CRTIMP صحيح __cdecl _getche_nolock(فراغ);
  _CRTIMP صحيح __cdecl _putch_nolock(صحيح _Ch);
  _CRTIMP صحيح __cdecl _ungetch_nolock(صحيح _Ch);

#جے_بنا_تعریف _WCONIO_DEFINED
#تعریف_کرو _WCONIO_DEFINED

#جے_بنا_تعریف WEOF
#تعریف_کرو WEOF (wint_t)(0xFFFF)
#جے_انت

  _CRTIMP wchar_t *_cgetws(wchar_t *بفر_2);
  _CRTIMP wint_t __cdecl _getwch(فراغ);
  _CRTIMP wint_t __cdecl _getwche(فراغ);
  _CRTIMP wint_t __cdecl _putwch(wchar_t _WCh);
  _CRTIMP wint_t __cdecl _ungetwch(wint_t _WCh);
  _CRTIMP صحيح __cdecl _cputws(ثابت wchar_t *_String);
  _CRTIMP صحيح __cdecl _cwprintf(ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _cwscanf(ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _cwscanf_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vcwprintf(ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _cwprintf_p(ثابت wchar_t *_Format,...);
  _CRTIMP صحيح __cdecl _vcwprintf_p(ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحيح __cdecl _cwprintf_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vcwprintf_l(ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحيح __cdecl _cwprintf_p_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحيح __cdecl _vcwprintf_p_l(ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP wint_t __cdecl _putwch_nolock(wchar_t _WCh);
  _CRTIMP wint_t __cdecl _getwch_nolock(فراغ);
  _CRTIMP wint_t __cdecl _getwche_nolock(فراغ);
  _CRTIMP wint_t __cdecl _ungetwch_nolock(wint_t _WCh);
#جے_انت

#جے_بنا_تعریف	NO_OLDNAMES
  حرف *__cdecl cgets(حرف *بفر_2);
  صحيح __cdecl cprintf(ثابت حرف *_Format,...);
  صحيح __cdecl cputs(ثابت حرف *_Str);
  صحيح __cdecl cscanf(ثابت حرف *_Format,...);
  صحيح __cdecl getch(فراغ);
  صحيح __cdecl getche(فراغ);
  صحيح __cdecl kbhit(فراغ);
  صحيح __cdecl putch(صحيح _Ch);
  صحيح __cdecl ungetch(صحيح _Ch);

#إذا (defined(_X86_) && !defined(__x86_64))
  صحيح __cdecl inp(بنانشانی چھوٹا);
  بنانشانی چھوٹا __cdecl inpw(بنانشانی چھوٹا);
  صحيح __cdecl outp(بنانشانی چھوٹا,صحيح);
  بنانشانی چھوٹا __cdecl outpw(بنانشانی چھوٹا,بنانشانی چھوٹا);
#جے_انت

  /* I/O intrin functions.  */
  __CRT_INLINE بنانشانی حرف __inbyte(بنانشانی چھوٹا پورٹ)
  {
      بنانشانی حرف قدر;
      __asm__ __volatile__ ("inb %w1,%b0"
          : "=a" (قدر)
          : "Nd" (پورٹ));
      أرجع قدر;
  }
  __CRT_INLINE بنانشانی چھوٹا __inword(بنانشانی چھوٹا پورٹ)
  {
      بنانشانی چھوٹا قدر;
      __asm__ __volatile__ ("inw %w1,%w0"
          : "=a" (قدر)
          : "Nd" (پورٹ));
      أرجع قدر;
  }
  __CRT_INLINE بنانشانی لما __indword(بنانشانی چھوٹا پورٹ)
  {
      بنانشانی لما قدر;
      __asm__ __volatile__ ("inl %w1,%0"
          : "=a" (قدر)
          : "Nd" (پورٹ));
      أرجع قدر;
  }
  __CRT_INLINE فراغ __outbyte(بنانشانی چھوٹا پورٹ,بنانشانی حرف انکڑے_3)
  {
      __asm__ __volatile__ ("outb %b0,%w1"
          :
          : "a" (انکڑے_3), "Nd" (پورٹ));
  }
  __CRT_INLINE فراغ __outword(بنانشانی چھوٹا پورٹ,بنانشانی چھوٹا انکڑے_3)
  {
      __asm__ __volatile__ ("outw %w0,%w1"
          :
          : "a" (انکڑے_3), "Nd" (پورٹ));
  }
  __CRT_INLINE فراغ __outdword(بنانشانی چھوٹا پورٹ,بنانشانی لما انکڑے_3)
  {
      __asm__ __volatile__ ("outl %0,%w1"
          :
          : "a" (انکڑے_3), "Nd" (پورٹ));
  }
  __CRT_INLINE فراغ __inbytestring(بنانشانی چھوٹا پورٹ,بنانشانی حرف *بفر_3,بنانشانی لما گنتی_3)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insb " 
		: "=D" (بفر_3), "=c" (گنتی_3)
		: "d"(پورٹ), "0"(بفر_3), "1" (گنتی_3)
		);
  }
  __CRT_INLINE فراغ __inwordstring(بنانشانی چھوٹا پورٹ,بنانشانی چھوٹا *بفر_3,بنانشانی لما گنتی_3)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insw " 
		: "=D" (بفر_3), "=c" (گنتی_3)
		: "d"(پورٹ), "0"(بفر_3), "1" (گنتی_3)
		);
  }
  __CRT_INLINE فراغ __indwordstring(بنانشانی چھوٹا پورٹ,بنانشانی لما *بفر_3,بنانشانی لما گنتی_3)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insl " 
		: "=D" (بفر_3), "=c" (گنتی_3)
		: "d"(پورٹ), "0"(بفر_3), "1" (گنتی_3)
		);
  }

  __CRT_INLINE فراغ __outbytestring(بنانشانی چھوٹا پورٹ,بنانشانی حرف *بفر_3,بنانشانی لما گنتی_3)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsb " 
          : "=S" (بفر_3), "=c" (گنتی_3)
          : "d"(پورٹ), "0"(بفر_3), "1" (گنتی_3)
          );
  }
  __CRT_INLINE فراغ __outwordstring(بنانشانی چھوٹا پورٹ,بنانشانی چھوٹا *بفر_3,بنانشانی لما گنتی_3)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsw " 
          : "=S" (بفر_3), "=c" (گنتی_3)
          : "d"(پورٹ), "0"(بفر_3), "1" (گنتی_3)
          );
  }
  __CRT_INLINE فراغ __outdwordstring(بنانشانی چھوٹا پورٹ,بنانشانی لما *بفر_3,بنانشانی لما گنتی_3)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsl " 
          : "=S" (بفر_3), "=c" (گنتی_3)
          : "d"(پورٹ), "0"(بفر_3), "1" (گنتی_3)
          );
  }

  __CRT_INLINE بنانشانی __int64 __readcr0(فراغ)
  {
      بنانشانی __int64 قدر;
      __asm__ __volatile__ (
          "mov %%cr0, %[value]" 
          : [قدر] "=q" (قدر));
      أرجع قدر;
  }
 
  /* Register sizes are different between 32/64 bit mode. So we have to do this for _WIN64 and _WIN32
     separately.  */
 
#جے_تعریف_شدہ _WIN64
  __CRT_INLINE فراغ __writecr0(بنانشانی __int64 انکڑے_3)
  {
   __asm__ __volatile__ (
       "mov %[Data], %%cr0"
       :
       : [انکڑے_3] "q" (انکڑے_3)
       : "memory");
  }
 
  __CRT_INLINE بنانشانی __int64 __readcr2(فراغ)
  {
      بنانشانی __int64 قدر;
      __asm__ __volatile__ (
          "mov %%cr2, %[value]" 
          : [قدر] "=q" (قدر));
      أرجع قدر;
  }

 __CRT_INLINE فراغ __writecr2(بنانشانی __int64 انکڑے_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr2"
       :
       : [انکڑے_3] "q" (انکڑے_3)
       : "memory");
 }
 
  __CRT_INLINE بنانشانی __int64 __readcr3(فراغ)
  {
      بنانشانی __int64 قدر;
      __asm__ __volatile__ (
          "mov %%cr3, %[value]" 
          : [قدر] "=q" (قدر));
      أرجع قدر;
  }

 __CRT_INLINE فراغ __writecr3(بنانشانی __int64 انکڑے_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr3"
       :
       : [انکڑے_3] "q" (انکڑے_3)
       : "memory");
 }
 
  __CRT_INLINE بنانشانی __int64 __readcr4(فراغ)
  {
      بنانشانی __int64 قدر;
      __asm__ __volatile__ (
          "mov %%cr4, %[value]" 
          : [قدر] "=q" (قدر));
      أرجع قدر;
  }

 __CRT_INLINE فراغ __writecr4(بنانشانی __int64 انکڑے_3)
 {
     __asm__ __volatile__ (
         "mov %[Data], %%cr4"
         :
         : [انکڑے_3] "q" (انکڑے_3)
         : "memory");
 }
 
  __CRT_INLINE بنانشانی __int64 __readcr8(فراغ)
  {
      بنانشانی __int64 قدر;
      __asm__ __volatile__ (
          "mov %%cr8, %[value]" 
          : [قدر] "=q" (قدر));
      أرجع قدر;
  }

 __CRT_INLINE فراغ __writecr8(بنانشانی __int64 انکڑے_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr8"
       :
       : [انکڑے_3] "q" (انکڑے_3)
       : "memory");
 }
 
#وإلاإذا defined(_WIN32)

  __CRT_INLINE فراغ __writecr0(بنانشانی انکڑے_3)
  {
    __asm__ __volatile__ (
       "mov %[Data], %%cr0"
       :
       : [انکڑے_3] "q" (انکڑے_3)
       : "memory");
  }
 
  __CRT_INLINE بنانشانی لما __readcr2(فراغ)
  {
      بنانشانی لما قدر;
      __asm__ __volatile__ (
          "mov %%cr2, %[value]" 
          : [قدر] "=q" (قدر));
      أرجع قدر;
  }

 __CRT_INLINE فراغ __writecr2(بنانشانی انکڑے_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr2"
       :
       : [انکڑے_3] "q" (انکڑے_3)
       : "memory");
 }
 
  __CRT_INLINE بنانشانی لما __readcr3(فراغ)
  {
      بنانشانی لما قدر;
      __asm__ __volatile__ (
          "mov %%cr3, %[value]" 
          : [قدر] "=q" (قدر));
      أرجع قدر;
  }

 __CRT_INLINE فراغ __writecr3(بنانشانی انکڑے_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr3"
       :
       : [انکڑے_3] "q" (انکڑے_3)
       : "memory");
 }
 
  __CRT_INLINE بنانشانی لما __readcr4(فراغ)
  {
      بنانشانی لما قدر;
      __asm__ __volatile__ (
          "mov %%cr4, %[value]" 
          : [قدر] "=q" (قدر));
      أرجع قدر;
  }

 __CRT_INLINE فراغ __writecr4(بنانشانی انکڑے_3)
 {
     __asm__ __volatile__ (
         "mov %[Data], %%cr4"
         :
         : [انکڑے_3] "q" (انکڑے_3)
         : "memory");
 }
 
 __CRT_INLINE بنانشانی لما __readcr8(فراغ)
 {
   بنانشانی لما قدر;      __asm__ __volatile__ (
          "mov %%cr8, %[value]" 
          : [قدر] "=q" (قدر));
     أرجع قدر;
 }

 __CRT_INLINE فراغ __writecr8(بنانشانی انکڑے_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr8"
       :
       : [انکڑے_3] "q" (انکڑے_3)
       : "memory");
 }
 
#جے_انت

  __CRT_INLINE بنانشانی __int64 __readmsr(بنانشانی لما msr)
  {
      بنانشانی __int64 val1, val2;
       __asm__ __volatile__(
           "rdmsr"
           : "=a" (val1), "=d" (val2)
           : "c" (msr));
      أرجع val1 | (val2 << 32);
  }

 __CRT_INLINE فراغ __writemsr (بنانشانی لما msr, بنانشانی __int64 قدر_3)
 {
    بنانشانی لما val1 = قدر_3, val2 = قدر_3 >> 32;
   __asm__ __volatile__ (
       "wrmsr"
       :
       : "c" (msr), "a" (val1), "d" (val2));
 }
 
  __CRT_INLINE بنانشانی __int64 __rdtsc(فراغ)
  {
      بنانشانی __int64 val1, val2;
      __asm__ __volatile__ (
          "rdtsc" 
          : "=a" (val1), "=d" (val2));
      أرجع val1 | (val2 << 32);
  }

  __CRT_INLINE فراغ __cpuid(صحيح CPUInfo[4], صحيح InfoType)
  {
      __asm__ __volatile__ (
          "cpuid"
          : "=a" (CPUInfo [0]), "=b" (CPUInfo [1]), "=c" (CPUInfo [2]), "=d" (CPUInfo [3])
          : "a" (InfoType));
  }

#جے_انت

#جے_تعریف_شدہ __cplusplus
}
#جے_انت

#ضمن <sec_api/conio_s.h>

#جے_انت
