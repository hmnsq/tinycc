/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_تعریف_نشده _INC_CONIO
#تعریف_کن _INC_CONIO

#ضمن <_mingw.h>

#اگر_تعریف_شده __cplusplus
خارجي "C" {
#پایان_اگر

  _CRTIMP حرف *_cgets(حرف *میانگیر_2);
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
  صحيح __cdecl _inp(بیعلامت کوتاه);
  بیعلامت کوتاه __cdecl _inpw(بیعلامت کوتاه);
  بیعلامت دراز __cdecl _inpd(بیعلامت کوتاه);
  صحيح __cdecl _outp(بیعلامت کوتاه,صحيح);
  بیعلامت کوتاه __cdecl _outpw(بیعلامت کوتاه,بیعلامت کوتاه);
  بیعلامت دراز __cdecl _outpd(بیعلامت کوتاه,بیعلامت دراز);
#پایان_اگر

  _CRTIMP صحيح __cdecl _putch(صحيح _Ch);
  _CRTIMP صحيح __cdecl _ungetch(صحيح _Ch);
  _CRTIMP صحيح __cdecl _getch_nolock(فراغ);
  _CRTIMP صحيح __cdecl _getche_nolock(فراغ);
  _CRTIMP صحيح __cdecl _putch_nolock(صحيح _Ch);
  _CRTIMP صحيح __cdecl _ungetch_nolock(صحيح _Ch);

#اگر_تعریف_نشده _WCONIO_DEFINED
#تعریف_کن _WCONIO_DEFINED

#اگر_تعریف_نشده WEOF
#تعریف_کن WEOF (wint_t)(0xFFFF)
#پایان_اگر

  _CRTIMP wchar_t *_cgetws(wchar_t *میانگیر_2);
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
#پایان_اگر

#اگر_تعریف_نشده	NO_OLDNAMES
  حرف *__cdecl cgets(حرف *میانگیر_2);
  صحيح __cdecl cprintf(ثابت حرف *_Format,...);
  صحيح __cdecl cputs(ثابت حرف *_Str);
  صحيح __cdecl cscanf(ثابت حرف *_Format,...);
  صحيح __cdecl getch(فراغ);
  صحيح __cdecl getche(فراغ);
  صحيح __cdecl kbhit(فراغ);
  صحيح __cdecl putch(صحيح _Ch);
  صحيح __cdecl ungetch(صحيح _Ch);

#إذا (defined(_X86_) && !defined(__x86_64))
  صحيح __cdecl inp(بیعلامت کوتاه);
  بیعلامت کوتاه __cdecl inpw(بیعلامت کوتاه);
  صحيح __cdecl outp(بیعلامت کوتاه,صحيح);
  بیعلامت کوتاه __cdecl outpw(بیعلامت کوتاه,بیعلامت کوتاه);
#پایان_اگر

  /* I/O intrin functions.  */
  __CRT_INLINE بیعلامت حرف __inbyte(بیعلامت کوتاه پورت)
  {
      بیعلامت حرف مقدار;
      __asm__ __volatile__ ("inb %w1,%b0"
          : "=a" (مقدار)
          : "Nd" (پورت));
      أرجع مقدار;
  }
  __CRT_INLINE بیعلامت کوتاه __inword(بیعلامت کوتاه پورت)
  {
      بیعلامت کوتاه مقدار;
      __asm__ __volatile__ ("inw %w1,%w0"
          : "=a" (مقدار)
          : "Nd" (پورت));
      أرجع مقدار;
  }
  __CRT_INLINE بیعلامت دراز __indword(بیعلامت کوتاه پورت)
  {
      بیعلامت دراز مقدار;
      __asm__ __volatile__ ("inl %w1,%0"
          : "=a" (مقدار)
          : "Nd" (پورت));
      أرجع مقدار;
  }
  __CRT_INLINE فراغ __outbyte(بیعلامت کوتاه پورت,بیعلامت حرف داده_3)
  {
      __asm__ __volatile__ ("outb %b0,%w1"
          :
          : "a" (داده_3), "Nd" (پورت));
  }
  __CRT_INLINE فراغ __outword(بیعلامت کوتاه پورت,بیعلامت کوتاه داده_3)
  {
      __asm__ __volatile__ ("outw %w0,%w1"
          :
          : "a" (داده_3), "Nd" (پورت));
  }
  __CRT_INLINE فراغ __outdword(بیعلامت کوتاه پورت,بیعلامت دراز داده_3)
  {
      __asm__ __volatile__ ("outl %0,%w1"
          :
          : "a" (داده_3), "Nd" (پورت));
  }
  __CRT_INLINE فراغ __inbytestring(بیعلامت کوتاه پورت,بیعلامت حرف *میانگیر_3,بیعلامت دراز شمار_3)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insb " 
		: "=D" (میانگیر_3), "=c" (شمار_3)
		: "d"(پورت), "0"(میانگیر_3), "1" (شمار_3)
		);
  }
  __CRT_INLINE فراغ __inwordstring(بیعلامت کوتاه پورت,بیعلامت کوتاه *میانگیر_3,بیعلامت دراز شمار_3)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insw " 
		: "=D" (میانگیر_3), "=c" (شمار_3)
		: "d"(پورت), "0"(میانگیر_3), "1" (شمار_3)
		);
  }
  __CRT_INLINE فراغ __indwordstring(بیعلامت کوتاه پورت,بیعلامت دراز *میانگیر_3,بیعلامت دراز شمار_3)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insl " 
		: "=D" (میانگیر_3), "=c" (شمار_3)
		: "d"(پورت), "0"(میانگیر_3), "1" (شمار_3)
		);
  }

  __CRT_INLINE فراغ __outbytestring(بیعلامت کوتاه پورت,بیعلامت حرف *میانگیر_3,بیعلامت دراز شمار_3)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsb " 
          : "=S" (میانگیر_3), "=c" (شمار_3)
          : "d"(پورت), "0"(میانگیر_3), "1" (شمار_3)
          );
  }
  __CRT_INLINE فراغ __outwordstring(بیعلامت کوتاه پورت,بیعلامت کوتاه *میانگیر_3,بیعلامت دراز شمار_3)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsw " 
          : "=S" (میانگیر_3), "=c" (شمار_3)
          : "d"(پورت), "0"(میانگیر_3), "1" (شمار_3)
          );
  }
  __CRT_INLINE فراغ __outdwordstring(بیعلامت کوتاه پورت,بیعلامت دراز *میانگیر_3,بیعلامت دراز شمار_3)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsl " 
          : "=S" (میانگیر_3), "=c" (شمار_3)
          : "d"(پورت), "0"(میانگیر_3), "1" (شمار_3)
          );
  }

  __CRT_INLINE بیعلامت __int64 __readcr0(فراغ)
  {
      بیعلامت __int64 مقدار;
      __asm__ __volatile__ (
          "mov %%cr0, %[value]" 
          : [مقدار] "=q" (مقدار));
      أرجع مقدار;
  }
 
  /* Register sizes are different between 32/64 bit mode. So we have to do this for _WIN64 and _WIN32
     separately.  */
 
#اگر_تعریف_شده _WIN64
  __CRT_INLINE فراغ __writecr0(بیعلامت __int64 داده_3)
  {
   __asm__ __volatile__ (
       "mov %[Data], %%cr0"
       :
       : [داده_3] "q" (داده_3)
       : "memory");
  }
 
  __CRT_INLINE بیعلامت __int64 __readcr2(فراغ)
  {
      بیعلامت __int64 مقدار;
      __asm__ __volatile__ (
          "mov %%cr2, %[value]" 
          : [مقدار] "=q" (مقدار));
      أرجع مقدار;
  }

 __CRT_INLINE فراغ __writecr2(بیعلامت __int64 داده_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr2"
       :
       : [داده_3] "q" (داده_3)
       : "memory");
 }
 
  __CRT_INLINE بیعلامت __int64 __readcr3(فراغ)
  {
      بیعلامت __int64 مقدار;
      __asm__ __volatile__ (
          "mov %%cr3, %[value]" 
          : [مقدار] "=q" (مقدار));
      أرجع مقدار;
  }

 __CRT_INLINE فراغ __writecr3(بیعلامت __int64 داده_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr3"
       :
       : [داده_3] "q" (داده_3)
       : "memory");
 }
 
  __CRT_INLINE بیعلامت __int64 __readcr4(فراغ)
  {
      بیعلامت __int64 مقدار;
      __asm__ __volatile__ (
          "mov %%cr4, %[value]" 
          : [مقدار] "=q" (مقدار));
      أرجع مقدار;
  }

 __CRT_INLINE فراغ __writecr4(بیعلامت __int64 داده_3)
 {
     __asm__ __volatile__ (
         "mov %[Data], %%cr4"
         :
         : [داده_3] "q" (داده_3)
         : "memory");
 }
 
  __CRT_INLINE بیعلامت __int64 __readcr8(فراغ)
  {
      بیعلامت __int64 مقدار;
      __asm__ __volatile__ (
          "mov %%cr8, %[value]" 
          : [مقدار] "=q" (مقدار));
      أرجع مقدار;
  }

 __CRT_INLINE فراغ __writecr8(بیعلامت __int64 داده_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr8"
       :
       : [داده_3] "q" (داده_3)
       : "memory");
 }
 
#وإلاإذا defined(_WIN32)

  __CRT_INLINE فراغ __writecr0(بیعلامت داده_3)
  {
    __asm__ __volatile__ (
       "mov %[Data], %%cr0"
       :
       : [داده_3] "q" (داده_3)
       : "memory");
  }
 
  __CRT_INLINE بیعلامت دراز __readcr2(فراغ)
  {
      بیعلامت دراز مقدار;
      __asm__ __volatile__ (
          "mov %%cr2, %[value]" 
          : [مقدار] "=q" (مقدار));
      أرجع مقدار;
  }

 __CRT_INLINE فراغ __writecr2(بیعلامت داده_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr2"
       :
       : [داده_3] "q" (داده_3)
       : "memory");
 }
 
  __CRT_INLINE بیعلامت دراز __readcr3(فراغ)
  {
      بیعلامت دراز مقدار;
      __asm__ __volatile__ (
          "mov %%cr3, %[value]" 
          : [مقدار] "=q" (مقدار));
      أرجع مقدار;
  }

 __CRT_INLINE فراغ __writecr3(بیعلامت داده_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr3"
       :
       : [داده_3] "q" (داده_3)
       : "memory");
 }
 
  __CRT_INLINE بیعلامت دراز __readcr4(فراغ)
  {
      بیعلامت دراز مقدار;
      __asm__ __volatile__ (
          "mov %%cr4, %[value]" 
          : [مقدار] "=q" (مقدار));
      أرجع مقدار;
  }

 __CRT_INLINE فراغ __writecr4(بیعلامت داده_3)
 {
     __asm__ __volatile__ (
         "mov %[Data], %%cr4"
         :
         : [داده_3] "q" (داده_3)
         : "memory");
 }
 
 __CRT_INLINE بیعلامت دراز __readcr8(فراغ)
 {
   بیعلامت دراز مقدار;      __asm__ __volatile__ (
          "mov %%cr8, %[value]" 
          : [مقدار] "=q" (مقدار));
     أرجع مقدار;
 }

 __CRT_INLINE فراغ __writecr8(بیعلامت داده_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr8"
       :
       : [داده_3] "q" (داده_3)
       : "memory");
 }
 
#پایان_اگر

  __CRT_INLINE بیعلامت __int64 __readmsr(بیعلامت دراز msr)
  {
      بیعلامت __int64 val1, val2;
       __asm__ __volatile__(
           "rdmsr"
           : "=a" (val1), "=d" (val2)
           : "c" (msr));
      أرجع val1 | (val2 << 32);
  }

 __CRT_INLINE فراغ __writemsr (بیعلامت دراز msr, بیعلامت __int64 مقدار_3)
 {
    بیعلامت دراز val1 = مقدار_3, val2 = مقدار_3 >> 32;
   __asm__ __volatile__ (
       "wrmsr"
       :
       : "c" (msr), "a" (val1), "d" (val2));
 }
 
  __CRT_INLINE بیعلامت __int64 __rdtsc(فراغ)
  {
      بیعلامت __int64 val1, val2;
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

#پایان_اگر

#اگر_تعریف_شده __cplusplus
}
#پایان_اگر

#ضمن <sec_api/conio_s.h>

#پایان_اگر
