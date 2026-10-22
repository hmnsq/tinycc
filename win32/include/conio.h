/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جيڪڏهن_وصف_نه_ٿيل _INC_CONIO
#وصف_ڪريو _INC_CONIO

#ضمن <_mingw.h>

#جيڪڏهن_وصف_ٿيل __cplusplus
خارجي "C" {
#جيڪڏهن_پورو

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
  صحيح __cdecl _inp(بنانشان ننڍو);
  بنانشان ننڍو __cdecl _inpw(بنانشان ننڍو);
  بنانشان ڊگهو __cdecl _inpd(بنانشان ننڍو);
  صحيح __cdecl _outp(بنانشان ننڍو,صحيح);
  بنانشان ننڍو __cdecl _outpw(بنانشان ننڍو,بنانشان ننڍو);
  بنانشان ڊگهو __cdecl _outpd(بنانشان ننڍو,بنانشان ڊگهو);
#جيڪڏهن_پورو

  _CRTIMP صحيح __cdecl _putch(صحيح _Ch);
  _CRTIMP صحيح __cdecl _ungetch(صحيح _Ch);
  _CRTIMP صحيح __cdecl _getch_nolock(فراغ);
  _CRTIMP صحيح __cdecl _getche_nolock(فراغ);
  _CRTIMP صحيح __cdecl _putch_nolock(صحيح _Ch);
  _CRTIMP صحيح __cdecl _ungetch_nolock(صحيح _Ch);

#جيڪڏهن_وصف_نه_ٿيل _WCONIO_DEFINED
#وصف_ڪريو _WCONIO_DEFINED

#جيڪڏهن_وصف_نه_ٿيل WEOF
#وصف_ڪريو WEOF (wint_t)(0xFFFF)
#جيڪڏهن_پورو

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
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل	NO_OLDNAMES
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
  صحيح __cdecl inp(بنانشان ننڍو);
  بنانشان ننڍو __cdecl inpw(بنانشان ننڍو);
  صحيح __cdecl outp(بنانشان ننڍو,صحيح);
  بنانشان ننڍو __cdecl outpw(بنانشان ننڍو,بنانشان ننڍو);
#جيڪڏهن_پورو

  /* I/O intrin functions.  */
  __CRT_INLINE بنانشان حرف __inbyte(بنانشان ننڍو پورٽ)
  {
      بنانشان حرف قدر;
      __asm__ __volatile__ ("inb %w1,%b0"
          : "=a" (قدر)
          : "Nd" (پورٽ));
      أرجع قدر;
  }
  __CRT_INLINE بنانشان ننڍو __inword(بنانشان ننڍو پورٽ)
  {
      بنانشان ننڍو قدر;
      __asm__ __volatile__ ("inw %w1,%w0"
          : "=a" (قدر)
          : "Nd" (پورٽ));
      أرجع قدر;
  }
  __CRT_INLINE بنانشان ڊگهو __indword(بنانشان ننڍو پورٽ)
  {
      بنانشان ڊگهو قدر;
      __asm__ __volatile__ ("inl %w1,%0"
          : "=a" (قدر)
          : "Nd" (پورٽ));
      أرجع قدر;
  }
  __CRT_INLINE فراغ __outbyte(بنانشان ننڍو پورٽ,بنانشان حرف معلومات_3)
  {
      __asm__ __volatile__ ("outb %b0,%w1"
          :
          : "a" (معلومات_3), "Nd" (پورٽ));
  }
  __CRT_INLINE فراغ __outword(بنانشان ننڍو پورٽ,بنانشان ننڍو معلومات_3)
  {
      __asm__ __volatile__ ("outw %w0,%w1"
          :
          : "a" (معلومات_3), "Nd" (پورٽ));
  }
  __CRT_INLINE فراغ __outdword(بنانشان ننڍو پورٽ,بنانشان ڊگهو معلومات_3)
  {
      __asm__ __volatile__ ("outl %0,%w1"
          :
          : "a" (معلومات_3), "Nd" (پورٽ));
  }
  __CRT_INLINE فراغ __inbytestring(بنانشان ننڍو پورٽ,بنانشان حرف *بفر_3,بنانشان ڊگهو ڳڻپ_3)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insb " 
		: "=D" (بفر_3), "=c" (ڳڻپ_3)
		: "d"(پورٽ), "0"(بفر_3), "1" (ڳڻپ_3)
		);
  }
  __CRT_INLINE فراغ __inwordstring(بنانشان ننڍو پورٽ,بنانشان ننڍو *بفر_3,بنانشان ڊگهو ڳڻپ_3)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insw " 
		: "=D" (بفر_3), "=c" (ڳڻپ_3)
		: "d"(پورٽ), "0"(بفر_3), "1" (ڳڻپ_3)
		);
  }
  __CRT_INLINE فراغ __indwordstring(بنانشان ننڍو پورٽ,بنانشان ڊگهو *بفر_3,بنانشان ڊگهو ڳڻپ_3)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insl " 
		: "=D" (بفر_3), "=c" (ڳڻپ_3)
		: "d"(پورٽ), "0"(بفر_3), "1" (ڳڻپ_3)
		);
  }

  __CRT_INLINE فراغ __outbytestring(بنانشان ننڍو پورٽ,بنانشان حرف *بفر_3,بنانشان ڊگهو ڳڻپ_3)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsb " 
          : "=S" (بفر_3), "=c" (ڳڻپ_3)
          : "d"(پورٽ), "0"(بفر_3), "1" (ڳڻپ_3)
          );
  }
  __CRT_INLINE فراغ __outwordstring(بنانشان ننڍو پورٽ,بنانشان ننڍو *بفر_3,بنانشان ڊگهو ڳڻپ_3)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsw " 
          : "=S" (بفر_3), "=c" (ڳڻپ_3)
          : "d"(پورٽ), "0"(بفر_3), "1" (ڳڻپ_3)
          );
  }
  __CRT_INLINE فراغ __outdwordstring(بنانشان ننڍو پورٽ,بنانشان ڊگهو *بفر_3,بنانشان ڊگهو ڳڻپ_3)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsl " 
          : "=S" (بفر_3), "=c" (ڳڻپ_3)
          : "d"(پورٽ), "0"(بفر_3), "1" (ڳڻپ_3)
          );
  }

  __CRT_INLINE بنانشان __int64 __readcr0(فراغ)
  {
      بنانشان __int64 قدر;
      __asm__ __volatile__ (
          "mov %%cr0, %[value]" 
          : [قدر] "=q" (قدر));
      أرجع قدر;
  }
 
  /* Register sizes are different between 32/64 bit mode. So we have to do this for _WIN64 and _WIN32
     separately.  */
 
#جيڪڏهن_وصف_ٿيل _WIN64
  __CRT_INLINE فراغ __writecr0(بنانشان __int64 معلومات_3)
  {
   __asm__ __volatile__ (
       "mov %[Data], %%cr0"
       :
       : [معلومات_3] "q" (معلومات_3)
       : "memory");
  }
 
  __CRT_INLINE بنانشان __int64 __readcr2(فراغ)
  {
      بنانشان __int64 قدر;
      __asm__ __volatile__ (
          "mov %%cr2, %[value]" 
          : [قدر] "=q" (قدر));
      أرجع قدر;
  }

 __CRT_INLINE فراغ __writecr2(بنانشان __int64 معلومات_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr2"
       :
       : [معلومات_3] "q" (معلومات_3)
       : "memory");
 }
 
  __CRT_INLINE بنانشان __int64 __readcr3(فراغ)
  {
      بنانشان __int64 قدر;
      __asm__ __volatile__ (
          "mov %%cr3, %[value]" 
          : [قدر] "=q" (قدر));
      أرجع قدر;
  }

 __CRT_INLINE فراغ __writecr3(بنانشان __int64 معلومات_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr3"
       :
       : [معلومات_3] "q" (معلومات_3)
       : "memory");
 }
 
  __CRT_INLINE بنانشان __int64 __readcr4(فراغ)
  {
      بنانشان __int64 قدر;
      __asm__ __volatile__ (
          "mov %%cr4, %[value]" 
          : [قدر] "=q" (قدر));
      أرجع قدر;
  }

 __CRT_INLINE فراغ __writecr4(بنانشان __int64 معلومات_3)
 {
     __asm__ __volatile__ (
         "mov %[Data], %%cr4"
         :
         : [معلومات_3] "q" (معلومات_3)
         : "memory");
 }
 
  __CRT_INLINE بنانشان __int64 __readcr8(فراغ)
  {
      بنانشان __int64 قدر;
      __asm__ __volatile__ (
          "mov %%cr8, %[value]" 
          : [قدر] "=q" (قدر));
      أرجع قدر;
  }

 __CRT_INLINE فراغ __writecr8(بنانشان __int64 معلومات_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr8"
       :
       : [معلومات_3] "q" (معلومات_3)
       : "memory");
 }
 
#وإلاإذا defined(_WIN32)

  __CRT_INLINE فراغ __writecr0(بنانشان معلومات_3)
  {
    __asm__ __volatile__ (
       "mov %[Data], %%cr0"
       :
       : [معلومات_3] "q" (معلومات_3)
       : "memory");
  }
 
  __CRT_INLINE بنانشان ڊگهو __readcr2(فراغ)
  {
      بنانشان ڊگهو قدر;
      __asm__ __volatile__ (
          "mov %%cr2, %[value]" 
          : [قدر] "=q" (قدر));
      أرجع قدر;
  }

 __CRT_INLINE فراغ __writecr2(بنانشان معلومات_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr2"
       :
       : [معلومات_3] "q" (معلومات_3)
       : "memory");
 }
 
  __CRT_INLINE بنانشان ڊگهو __readcr3(فراغ)
  {
      بنانشان ڊگهو قدر;
      __asm__ __volatile__ (
          "mov %%cr3, %[value]" 
          : [قدر] "=q" (قدر));
      أرجع قدر;
  }

 __CRT_INLINE فراغ __writecr3(بنانشان معلومات_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr3"
       :
       : [معلومات_3] "q" (معلومات_3)
       : "memory");
 }
 
  __CRT_INLINE بنانشان ڊگهو __readcr4(فراغ)
  {
      بنانشان ڊگهو قدر;
      __asm__ __volatile__ (
          "mov %%cr4, %[value]" 
          : [قدر] "=q" (قدر));
      أرجع قدر;
  }

 __CRT_INLINE فراغ __writecr4(بنانشان معلومات_3)
 {
     __asm__ __volatile__ (
         "mov %[Data], %%cr4"
         :
         : [معلومات_3] "q" (معلومات_3)
         : "memory");
 }
 
 __CRT_INLINE بنانشان ڊگهو __readcr8(فراغ)
 {
   بنانشان ڊگهو قدر;      __asm__ __volatile__ (
          "mov %%cr8, %[value]" 
          : [قدر] "=q" (قدر));
     أرجع قدر;
 }

 __CRT_INLINE فراغ __writecr8(بنانشان معلومات_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr8"
       :
       : [معلومات_3] "q" (معلومات_3)
       : "memory");
 }
 
#جيڪڏهن_پورو

  __CRT_INLINE بنانشان __int64 __readmsr(بنانشان ڊگهو msr)
  {
      بنانشان __int64 val1, val2;
       __asm__ __volatile__(
           "rdmsr"
           : "=a" (val1), "=d" (val2)
           : "c" (msr));
      أرجع val1 | (val2 << 32);
  }

 __CRT_INLINE فراغ __writemsr (بنانشان ڊگهو msr, بنانشان __int64 قدر_3)
 {
    بنانشان ڊگهو val1 = قدر_3, val2 = قدر_3 >> 32;
   __asm__ __volatile__ (
       "wrmsr"
       :
       : "c" (msr), "a" (val1), "d" (val2));
 }
 
  __CRT_INLINE بنانشان __int64 __rdtsc(فراغ)
  {
      بنانشان __int64 val1, val2;
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

#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل __cplusplus
}
#جيڪڏهن_پورو

#ضمن <sec_api/conio_s.h>

#جيڪڏهن_پورو
