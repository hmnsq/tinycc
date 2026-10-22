/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_غیر_تعریف_شدہ _INC_CONIO
#تعریف_کرو _INC_CONIO

#شامل <_mingw.h>

#اگر_تعریف_شدہ __cplusplus
خارجی "C" {
#اگر_ختم

  _CRTIMP حرف *_cgets(حرف *بفر_2);
  _CRTIMP صحیح __cdecl _cprintf(ثابت حرف *_Format,...);
  _CRTIMP صحیح __cdecl _cputs(ثابت حرف *_Str);
  _CRTIMP صحیح __cdecl _cscanf(ثابت حرف *_Format,...);
  _CRTIMP صحیح __cdecl _cscanf_l(ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _getch(خالی);
  _CRTIMP صحیح __cdecl _getche(خالی);
  _CRTIMP صحیح __cdecl _vcprintf(ثابت حرف *_Format,va_list _ArgList);
  _CRTIMP صحیح __cdecl _cprintf_p(ثابت حرف *_Format,...);
  _CRTIMP صحیح __cdecl _vcprintf_p(ثابت حرف *_Format,va_list _ArgList);
  _CRTIMP صحیح __cdecl _cprintf_l(ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vcprintf_l(ثابت حرف *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _cprintf_p_l(ثابت حرف *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vcprintf_p_l(ثابت حرف *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _kbhit(خالی);

#اگر defined(_X86_) && !defined(__x86_64)
  صحیح __cdecl _inp(غیرعلامتی مختصر);
  غیرعلامتی مختصر __cdecl _inpw(غیرعلامتی مختصر);
  غیرعلامتی طویل __cdecl _inpd(غیرعلامتی مختصر);
  صحیح __cdecl _outp(غیرعلامتی مختصر,صحیح);
  غیرعلامتی مختصر __cdecl _outpw(غیرعلامتی مختصر,غیرعلامتی مختصر);
  غیرعلامتی طویل __cdecl _outpd(غیرعلامتی مختصر,غیرعلامتی طویل);
#اگر_ختم

  _CRTIMP صحیح __cdecl _putch(صحیح _Ch);
  _CRTIMP صحیح __cdecl _ungetch(صحیح _Ch);
  _CRTIMP صحیح __cdecl _getch_nolock(خالی);
  _CRTIMP صحیح __cdecl _getche_nolock(خالی);
  _CRTIMP صحیح __cdecl _putch_nolock(صحیح _Ch);
  _CRTIMP صحیح __cdecl _ungetch_nolock(صحیح _Ch);

#اگر_غیر_تعریف_شدہ _WCONIO_DEFINED
#تعریف_کرو _WCONIO_DEFINED

#اگر_غیر_تعریف_شدہ WEOF
#تعریف_کرو WEOF (wint_t)(0xFFFF)
#اگر_ختم

  _CRTIMP wchar_t *_cgetws(wchar_t *بفر_2);
  _CRTIMP wint_t __cdecl _getwch(خالی);
  _CRTIMP wint_t __cdecl _getwche(خالی);
  _CRTIMP wint_t __cdecl _putwch(wchar_t _WCh);
  _CRTIMP wint_t __cdecl _ungetwch(wint_t _WCh);
  _CRTIMP صحیح __cdecl _cputws(ثابت wchar_t *_String);
  _CRTIMP صحیح __cdecl _cwprintf(ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _cwscanf(ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _cwscanf_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vcwprintf(ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحیح __cdecl _cwprintf_p(ثابت wchar_t *_Format,...);
  _CRTIMP صحیح __cdecl _vcwprintf_p(ثابت wchar_t *_Format,va_list _ArgList);
  _CRTIMP صحیح __cdecl _cwprintf_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vcwprintf_l(ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _cwprintf_p_l(ثابت wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vcwprintf_p_l(ثابت wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP wint_t __cdecl _putwch_nolock(wchar_t _WCh);
  _CRTIMP wint_t __cdecl _getwch_nolock(خالی);
  _CRTIMP wint_t __cdecl _getwche_nolock(خالی);
  _CRTIMP wint_t __cdecl _ungetwch_nolock(wint_t _WCh);
#اگر_ختم

#اگر_غیر_تعریف_شدہ	NO_OLDNAMES
  حرف *__cdecl cgets(حرف *بفر_2);
  صحیح __cdecl cprintf(ثابت حرف *_Format,...);
  صحیح __cdecl cputs(ثابت حرف *_Str);
  صحیح __cdecl cscanf(ثابت حرف *_Format,...);
  صحیح __cdecl getch(خالی);
  صحیح __cdecl getche(خالی);
  صحیح __cdecl kbhit(خالی);
  صحیح __cdecl putch(صحیح _Ch);
  صحیح __cdecl ungetch(صحیح _Ch);

#اگر (defined(_X86_) && !defined(__x86_64))
  صحیح __cdecl inp(غیرعلامتی مختصر);
  غیرعلامتی مختصر __cdecl inpw(غیرعلامتی مختصر);
  صحیح __cdecl outp(غیرعلامتی مختصر,صحیح);
  غیرعلامتی مختصر __cdecl outpw(غیرعلامتی مختصر,غیرعلامتی مختصر);
#اگر_ختم

  /* I/O intrin functions.  */
  __CRT_INLINE غیرعلامتی حرف __inbyte(غیرعلامتی مختصر پورٹ)
  {
      غیرعلامتی حرف قدر;
      __asm__ __volatile__ ("inb %w1,%b0"
          : "=a" (قدر)
          : "Nd" (پورٹ));
      واپس قدر;
  }
  __CRT_INLINE غیرعلامتی مختصر __inword(غیرعلامتی مختصر پورٹ)
  {
      غیرعلامتی مختصر قدر;
      __asm__ __volatile__ ("inw %w1,%w0"
          : "=a" (قدر)
          : "Nd" (پورٹ));
      واپس قدر;
  }
  __CRT_INLINE غیرعلامتی طویل __indword(غیرعلامتی مختصر پورٹ)
  {
      غیرعلامتی طویل قدر;
      __asm__ __volatile__ ("inl %w1,%0"
          : "=a" (قدر)
          : "Nd" (پورٹ));
      واپس قدر;
  }
  __CRT_INLINE خالی __outbyte(غیرعلامتی مختصر پورٹ,غیرعلامتی حرف ڈیٹا_3)
  {
      __asm__ __volatile__ ("outb %b0,%w1"
          :
          : "a" (ڈیٹا_3), "Nd" (پورٹ));
  }
  __CRT_INLINE خالی __outword(غیرعلامتی مختصر پورٹ,غیرعلامتی مختصر ڈیٹا_3)
  {
      __asm__ __volatile__ ("outw %w0,%w1"
          :
          : "a" (ڈیٹا_3), "Nd" (پورٹ));
  }
  __CRT_INLINE خالی __outdword(غیرعلامتی مختصر پورٹ,غیرعلامتی طویل ڈیٹا_3)
  {
      __asm__ __volatile__ ("outl %0,%w1"
          :
          : "a" (ڈیٹا_3), "Nd" (پورٹ));
  }
  __CRT_INLINE خالی __inbytestring(غیرعلامتی مختصر پورٹ,غیرعلامتی حرف *بفر_3,غیرعلامتی طویل گنتی_3)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insb " 
		: "=D" (بفر_3), "=c" (گنتی_3)
		: "d"(پورٹ), "0"(بفر_3), "1" (گنتی_3)
		);
  }
  __CRT_INLINE خالی __inwordstring(غیرعلامتی مختصر پورٹ,غیرعلامتی مختصر *بفر_3,غیرعلامتی طویل گنتی_3)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insw " 
		: "=D" (بفر_3), "=c" (گنتی_3)
		: "d"(پورٹ), "0"(بفر_3), "1" (گنتی_3)
		);
  }
  __CRT_INLINE خالی __indwordstring(غیرعلامتی مختصر پورٹ,غیرعلامتی طویل *بفر_3,غیرعلامتی طویل گنتی_3)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insl " 
		: "=D" (بفر_3), "=c" (گنتی_3)
		: "d"(پورٹ), "0"(بفر_3), "1" (گنتی_3)
		);
  }

  __CRT_INLINE خالی __outbytestring(غیرعلامتی مختصر پورٹ,غیرعلامتی حرف *بفر_3,غیرعلامتی طویل گنتی_3)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsb " 
          : "=S" (بفر_3), "=c" (گنتی_3)
          : "d"(پورٹ), "0"(بفر_3), "1" (گنتی_3)
          );
  }
  __CRT_INLINE خالی __outwordstring(غیرعلامتی مختصر پورٹ,غیرعلامتی مختصر *بفر_3,غیرعلامتی طویل گنتی_3)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsw " 
          : "=S" (بفر_3), "=c" (گنتی_3)
          : "d"(پورٹ), "0"(بفر_3), "1" (گنتی_3)
          );
  }
  __CRT_INLINE خالی __outdwordstring(غیرعلامتی مختصر پورٹ,غیرعلامتی طویل *بفر_3,غیرعلامتی طویل گنتی_3)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsl " 
          : "=S" (بفر_3), "=c" (گنتی_3)
          : "d"(پورٹ), "0"(بفر_3), "1" (گنتی_3)
          );
  }

  __CRT_INLINE غیرعلامتی __int64 __readcr0(خالی)
  {
      غیرعلامتی __int64 قدر;
      __asm__ __volatile__ (
          "mov %%cr0, %[value]" 
          : [قدر] "=q" (قدر));
      واپس قدر;
  }
 
  /* Register sizes are different between 32/64 bit mode. So we have to do this for _WIN64 and _WIN32
     separately.  */
 
#اگر_تعریف_شدہ _WIN64
  __CRT_INLINE خالی __writecr0(غیرعلامتی __int64 ڈیٹا_3)
  {
   __asm__ __volatile__ (
       "mov %[Data], %%cr0"
       :
       : [ڈیٹا_3] "q" (ڈیٹا_3)
       : "memory");
  }
 
  __CRT_INLINE غیرعلامتی __int64 __readcr2(خالی)
  {
      غیرعلامتی __int64 قدر;
      __asm__ __volatile__ (
          "mov %%cr2, %[value]" 
          : [قدر] "=q" (قدر));
      واپس قدر;
  }

 __CRT_INLINE خالی __writecr2(غیرعلامتی __int64 ڈیٹا_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr2"
       :
       : [ڈیٹا_3] "q" (ڈیٹا_3)
       : "memory");
 }
 
  __CRT_INLINE غیرعلامتی __int64 __readcr3(خالی)
  {
      غیرعلامتی __int64 قدر;
      __asm__ __volatile__ (
          "mov %%cr3, %[value]" 
          : [قدر] "=q" (قدر));
      واپس قدر;
  }

 __CRT_INLINE خالی __writecr3(غیرعلامتی __int64 ڈیٹا_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr3"
       :
       : [ڈیٹا_3] "q" (ڈیٹا_3)
       : "memory");
 }
 
  __CRT_INLINE غیرعلامتی __int64 __readcr4(خالی)
  {
      غیرعلامتی __int64 قدر;
      __asm__ __volatile__ (
          "mov %%cr4, %[value]" 
          : [قدر] "=q" (قدر));
      واپس قدر;
  }

 __CRT_INLINE خالی __writecr4(غیرعلامتی __int64 ڈیٹا_3)
 {
     __asm__ __volatile__ (
         "mov %[Data], %%cr4"
         :
         : [ڈیٹا_3] "q" (ڈیٹا_3)
         : "memory");
 }
 
  __CRT_INLINE غیرعلامتی __int64 __readcr8(خالی)
  {
      غیرعلامتی __int64 قدر;
      __asm__ __volatile__ (
          "mov %%cr8, %[value]" 
          : [قدر] "=q" (قدر));
      واپس قدر;
  }

 __CRT_INLINE خالی __writecr8(غیرعلامتی __int64 ڈیٹا_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr8"
       :
       : [ڈیٹا_3] "q" (ڈیٹا_3)
       : "memory");
 }
 
#وگرنہ_اگر defined(_WIN32)

  __CRT_INLINE خالی __writecr0(غیرعلامتی ڈیٹا_3)
  {
    __asm__ __volatile__ (
       "mov %[Data], %%cr0"
       :
       : [ڈیٹا_3] "q" (ڈیٹا_3)
       : "memory");
  }
 
  __CRT_INLINE غیرعلامتی طویل __readcr2(خالی)
  {
      غیرعلامتی طویل قدر;
      __asm__ __volatile__ (
          "mov %%cr2, %[value]" 
          : [قدر] "=q" (قدر));
      واپس قدر;
  }

 __CRT_INLINE خالی __writecr2(غیرعلامتی ڈیٹا_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr2"
       :
       : [ڈیٹا_3] "q" (ڈیٹا_3)
       : "memory");
 }
 
  __CRT_INLINE غیرعلامتی طویل __readcr3(خالی)
  {
      غیرعلامتی طویل قدر;
      __asm__ __volatile__ (
          "mov %%cr3, %[value]" 
          : [قدر] "=q" (قدر));
      واپس قدر;
  }

 __CRT_INLINE خالی __writecr3(غیرعلامتی ڈیٹا_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr3"
       :
       : [ڈیٹا_3] "q" (ڈیٹا_3)
       : "memory");
 }
 
  __CRT_INLINE غیرعلامتی طویل __readcr4(خالی)
  {
      غیرعلامتی طویل قدر;
      __asm__ __volatile__ (
          "mov %%cr4, %[value]" 
          : [قدر] "=q" (قدر));
      واپس قدر;
  }

 __CRT_INLINE خالی __writecr4(غیرعلامتی ڈیٹا_3)
 {
     __asm__ __volatile__ (
         "mov %[Data], %%cr4"
         :
         : [ڈیٹا_3] "q" (ڈیٹا_3)
         : "memory");
 }
 
 __CRT_INLINE غیرعلامتی طویل __readcr8(خالی)
 {
   غیرعلامتی طویل قدر;      __asm__ __volatile__ (
          "mov %%cr8, %[value]" 
          : [قدر] "=q" (قدر));
     واپس قدر;
 }

 __CRT_INLINE خالی __writecr8(غیرعلامتی ڈیٹا_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr8"
       :
       : [ڈیٹا_3] "q" (ڈیٹا_3)
       : "memory");
 }
 
#اگر_ختم

  __CRT_INLINE غیرعلامتی __int64 __readmsr(غیرعلامتی طویل msr)
  {
      غیرعلامتی __int64 val1, val2;
       __asm__ __volatile__(
           "rdmsr"
           : "=a" (val1), "=d" (val2)
           : "c" (msr));
      واپس val1 | (val2 << 32);
  }

 __CRT_INLINE خالی __writemsr (غیرعلامتی طویل msr, غیرعلامتی __int64 قدر_3)
 {
    غیرعلامتی طویل val1 = قدر_3, val2 = قدر_3 >> 32;
   __asm__ __volatile__ (
       "wrmsr"
       :
       : "c" (msr), "a" (val1), "d" (val2));
 }
 
  __CRT_INLINE غیرعلامتی __int64 __rdtsc(خالی)
  {
      غیرعلامتی __int64 val1, val2;
      __asm__ __volatile__ (
          "rdtsc" 
          : "=a" (val1), "=d" (val2));
      واپس val1 | (val2 << 32);
  }

  __CRT_INLINE خالی __cpuid(صحیح CPUInfo[4], صحیح InfoType)
  {
      __asm__ __volatile__ (
          "cpuid"
          : "=a" (CPUInfo [0]), "=b" (CPUInfo [1]), "=c" (CPUInfo [2]), "=d" (CPUInfo [3])
          : "a" (InfoType));
  }

#اگر_ختم

#اگر_تعریف_شدہ __cplusplus
}
#اگر_ختم

#شامل <sec_api/conio_s.h>

#اگر_ختم
