/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#که_نه_تعریف_شوی _INC_CONIO
#تعریف_کړه _INC_CONIO

#ضمن <_mingw.h>

#که_تعریف_شوی __cplusplus
خارجي "C" {
#د_که_پای

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
  صحيح __cdecl _inp(بینښه لنډ);
  بینښه لنډ __cdecl _inpw(بینښه لنډ);
  بینښه اوږد __cdecl _inpd(بینښه لنډ);
  صحيح __cdecl _outp(بینښه لنډ,صحيح);
  بینښه لنډ __cdecl _outpw(بینښه لنډ,بینښه لنډ);
  بینښه اوږد __cdecl _outpd(بینښه لنډ,بینښه اوږد);
#د_که_پای

  _CRTIMP صحيح __cdecl _putch(صحيح _Ch);
  _CRTIMP صحيح __cdecl _ungetch(صحيح _Ch);
  _CRTIMP صحيح __cdecl _getch_nolock(فراغ);
  _CRTIMP صحيح __cdecl _getche_nolock(فراغ);
  _CRTIMP صحيح __cdecl _putch_nolock(صحيح _Ch);
  _CRTIMP صحيح __cdecl _ungetch_nolock(صحيح _Ch);

#که_نه_تعریف_شوی _WCONIO_DEFINED
#تعریف_کړه _WCONIO_DEFINED

#که_نه_تعریف_شوی WEOF
#تعریف_کړه WEOF (wint_t)(0xFFFF)
#د_که_پای

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
#د_که_پای

#که_نه_تعریف_شوی	NO_OLDNAMES
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
  صحيح __cdecl inp(بینښه لنډ);
  بینښه لنډ __cdecl inpw(بینښه لنډ);
  صحيح __cdecl outp(بینښه لنډ,صحيح);
  بینښه لنډ __cdecl outpw(بینښه لنډ,بینښه لنډ);
#د_که_پای

  /* I/O intrin functions.  */
  __CRT_INLINE بینښه حرف __inbyte(بینښه لنډ پورټ)
  {
      بینښه حرف ارزښت;
      __asm__ __volatile__ ("inb %w1,%b0"
          : "=a" (ارزښت)
          : "Nd" (پورټ));
      أرجع ارزښت;
  }
  __CRT_INLINE بینښه لنډ __inword(بینښه لنډ پورټ)
  {
      بینښه لنډ ارزښت;
      __asm__ __volatile__ ("inw %w1,%w0"
          : "=a" (ارزښت)
          : "Nd" (پورټ));
      أرجع ارزښت;
  }
  __CRT_INLINE بینښه اوږد __indword(بینښه لنډ پورټ)
  {
      بینښه اوږد ارزښت;
      __asm__ __volatile__ ("inl %w1,%0"
          : "=a" (ارزښت)
          : "Nd" (پورټ));
      أرجع ارزښت;
  }
  __CRT_INLINE فراغ __outbyte(بینښه لنډ پورټ,بینښه حرف معلومات_3)
  {
      __asm__ __volatile__ ("outb %b0,%w1"
          :
          : "a" (معلومات_3), "Nd" (پورټ));
  }
  __CRT_INLINE فراغ __outword(بینښه لنډ پورټ,بینښه لنډ معلومات_3)
  {
      __asm__ __volatile__ ("outw %w0,%w1"
          :
          : "a" (معلومات_3), "Nd" (پورټ));
  }
  __CRT_INLINE فراغ __outdword(بینښه لنډ پورټ,بینښه اوږد معلومات_3)
  {
      __asm__ __volatile__ ("outl %0,%w1"
          :
          : "a" (معلومات_3), "Nd" (پورټ));
  }
  __CRT_INLINE فراغ __inbytestring(بینښه لنډ پورټ,بینښه حرف *بفر_3,بینښه اوږد شمېر_3)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insb " 
		: "=D" (بفر_3), "=c" (شمېر_3)
		: "d"(پورټ), "0"(بفر_3), "1" (شمېر_3)
		);
  }
  __CRT_INLINE فراغ __inwordstring(بینښه لنډ پورټ,بینښه لنډ *بفر_3,بینښه اوږد شمېر_3)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insw " 
		: "=D" (بفر_3), "=c" (شمېر_3)
		: "d"(پورټ), "0"(بفر_3), "1" (شمېر_3)
		);
  }
  __CRT_INLINE فراغ __indwordstring(بینښه لنډ پورټ,بینښه اوږد *بفر_3,بینښه اوږد شمېر_3)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insl " 
		: "=D" (بفر_3), "=c" (شمېر_3)
		: "d"(پورټ), "0"(بفر_3), "1" (شمېر_3)
		);
  }

  __CRT_INLINE فراغ __outbytestring(بینښه لنډ پورټ,بینښه حرف *بفر_3,بینښه اوږد شمېر_3)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsb " 
          : "=S" (بفر_3), "=c" (شمېر_3)
          : "d"(پورټ), "0"(بفر_3), "1" (شمېر_3)
          );
  }
  __CRT_INLINE فراغ __outwordstring(بینښه لنډ پورټ,بینښه لنډ *بفر_3,بینښه اوږد شمېر_3)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsw " 
          : "=S" (بفر_3), "=c" (شمېر_3)
          : "d"(پورټ), "0"(بفر_3), "1" (شمېر_3)
          );
  }
  __CRT_INLINE فراغ __outdwordstring(بینښه لنډ پورټ,بینښه اوږد *بفر_3,بینښه اوږد شمېر_3)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsl " 
          : "=S" (بفر_3), "=c" (شمېر_3)
          : "d"(پورټ), "0"(بفر_3), "1" (شمېر_3)
          );
  }

  __CRT_INLINE بینښه __int64 __readcr0(فراغ)
  {
      بینښه __int64 ارزښت;
      __asm__ __volatile__ (
          "mov %%cr0, %[value]" 
          : [ارزښت] "=q" (ارزښت));
      أرجع ارزښت;
  }
 
  /* Register sizes are different between 32/64 bit mode. So we have to do this for _WIN64 and _WIN32
     separately.  */
 
#که_تعریف_شوی _WIN64
  __CRT_INLINE فراغ __writecr0(بینښه __int64 معلومات_3)
  {
   __asm__ __volatile__ (
       "mov %[Data], %%cr0"
       :
       : [معلومات_3] "q" (معلومات_3)
       : "memory");
  }
 
  __CRT_INLINE بینښه __int64 __readcr2(فراغ)
  {
      بینښه __int64 ارزښت;
      __asm__ __volatile__ (
          "mov %%cr2, %[value]" 
          : [ارزښت] "=q" (ارزښت));
      أرجع ارزښت;
  }

 __CRT_INLINE فراغ __writecr2(بینښه __int64 معلومات_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr2"
       :
       : [معلومات_3] "q" (معلومات_3)
       : "memory");
 }
 
  __CRT_INLINE بینښه __int64 __readcr3(فراغ)
  {
      بینښه __int64 ارزښت;
      __asm__ __volatile__ (
          "mov %%cr3, %[value]" 
          : [ارزښت] "=q" (ارزښت));
      أرجع ارزښت;
  }

 __CRT_INLINE فراغ __writecr3(بینښه __int64 معلومات_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr3"
       :
       : [معلومات_3] "q" (معلومات_3)
       : "memory");
 }
 
  __CRT_INLINE بینښه __int64 __readcr4(فراغ)
  {
      بینښه __int64 ارزښت;
      __asm__ __volatile__ (
          "mov %%cr4, %[value]" 
          : [ارزښت] "=q" (ارزښت));
      أرجع ارزښت;
  }

 __CRT_INLINE فراغ __writecr4(بینښه __int64 معلومات_3)
 {
     __asm__ __volatile__ (
         "mov %[Data], %%cr4"
         :
         : [معلومات_3] "q" (معلومات_3)
         : "memory");
 }
 
  __CRT_INLINE بینښه __int64 __readcr8(فراغ)
  {
      بینښه __int64 ارزښت;
      __asm__ __volatile__ (
          "mov %%cr8, %[value]" 
          : [ارزښت] "=q" (ارزښت));
      أرجع ارزښت;
  }

 __CRT_INLINE فراغ __writecr8(بینښه __int64 معلومات_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr8"
       :
       : [معلومات_3] "q" (معلومات_3)
       : "memory");
 }
 
#وإلاإذا defined(_WIN32)

  __CRT_INLINE فراغ __writecr0(بینښه معلومات_3)
  {
    __asm__ __volatile__ (
       "mov %[Data], %%cr0"
       :
       : [معلومات_3] "q" (معلومات_3)
       : "memory");
  }
 
  __CRT_INLINE بینښه اوږد __readcr2(فراغ)
  {
      بینښه اوږد ارزښت;
      __asm__ __volatile__ (
          "mov %%cr2, %[value]" 
          : [ارزښت] "=q" (ارزښت));
      أرجع ارزښت;
  }

 __CRT_INLINE فراغ __writecr2(بینښه معلومات_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr2"
       :
       : [معلومات_3] "q" (معلومات_3)
       : "memory");
 }
 
  __CRT_INLINE بینښه اوږد __readcr3(فراغ)
  {
      بینښه اوږد ارزښت;
      __asm__ __volatile__ (
          "mov %%cr3, %[value]" 
          : [ارزښت] "=q" (ارزښت));
      أرجع ارزښت;
  }

 __CRT_INLINE فراغ __writecr3(بینښه معلومات_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr3"
       :
       : [معلومات_3] "q" (معلومات_3)
       : "memory");
 }
 
  __CRT_INLINE بینښه اوږد __readcr4(فراغ)
  {
      بینښه اوږد ارزښت;
      __asm__ __volatile__ (
          "mov %%cr4, %[value]" 
          : [ارزښت] "=q" (ارزښت));
      أرجع ارزښت;
  }

 __CRT_INLINE فراغ __writecr4(بینښه معلومات_3)
 {
     __asm__ __volatile__ (
         "mov %[Data], %%cr4"
         :
         : [معلومات_3] "q" (معلومات_3)
         : "memory");
 }
 
 __CRT_INLINE بینښه اوږد __readcr8(فراغ)
 {
   بینښه اوږد ارزښت;      __asm__ __volatile__ (
          "mov %%cr8, %[value]" 
          : [ارزښت] "=q" (ارزښت));
     أرجع ارزښت;
 }

 __CRT_INLINE فراغ __writecr8(بینښه معلومات_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr8"
       :
       : [معلومات_3] "q" (معلومات_3)
       : "memory");
 }
 
#د_که_پای

  __CRT_INLINE بینښه __int64 __readmsr(بینښه اوږد msr)
  {
      بینښه __int64 val1, val2;
       __asm__ __volatile__(
           "rdmsr"
           : "=a" (val1), "=d" (val2)
           : "c" (msr));
      أرجع val1 | (val2 << 32);
  }

 __CRT_INLINE فراغ __writemsr (بینښه اوږد msr, بینښه __int64 ارزښت_3)
 {
    بینښه اوږد val1 = ارزښت_3, val2 = ارزښت_3 >> 32;
   __asm__ __volatile__ (
       "wrmsr"
       :
       : "c" (msr), "a" (val1), "d" (val2));
 }
 
  __CRT_INLINE بینښه __int64 __rdtsc(فراغ)
  {
      بینښه __int64 val1, val2;
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

#د_که_پای

#که_تعریف_شوی __cplusplus
}
#د_که_پای

#ضمن <sec_api/conio_s.h>

#د_که_پای
