/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_CONIO
#define _INC_CONIO

#شامل <_mingw.h>

#ifdef __cplusplus
بیرونی "C" {
#endif

  _CRTIMP نویسه *_cgets(نویسه *_Buffer);
  _CRTIMP صحیح __cdecl _cprintf(ثابت نویسه *_Format,...);
  _CRTIMP صحیح __cdecl _cputs(ثابت نویسه *_Str);
  _CRTIMP صحیح __cdecl _cscanf(ثابت نویسه *_Format,...);
  _CRTIMP صحیح __cdecl _cscanf_l(ثابت نویسه *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _getch(تهی);
  _CRTIMP صحیح __cdecl _getche(تهی);
  _CRTIMP صحیح __cdecl _vcprintf(ثابت نویسه *_Format,va_list _ArgList);
  _CRTIMP صحیح __cdecl _cprintf_p(ثابت نویسه *_Format,...);
  _CRTIMP صحیح __cdecl _vcprintf_p(ثابت نویسه *_Format,va_list _ArgList);
  _CRTIMP صحیح __cdecl _cprintf_l(ثابت نویسه *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vcprintf_l(ثابت نویسه *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _cprintf_p_l(ثابت نویسه *_Format,_locale_t _Locale,...);
  _CRTIMP صحیح __cdecl _vcprintf_p_l(ثابت نویسه *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP صحیح __cdecl _kbhit(تهی);

#اگر defined(_X86_) && !defined(__x86_64)
  صحیح __cdecl _inp(unsigned short);
  unsigned short __cdecl _inpw(unsigned short);
  unsigned long __cdecl _inpd(unsigned short);
  صحیح __cdecl _outp(unsigned short,صحیح);
  unsigned short __cdecl _outpw(unsigned short,unsigned short);
  unsigned long __cdecl _outpd(unsigned short,unsigned long);
#endif

  _CRTIMP صحیح __cdecl _putch(صحیح _Ch);
  _CRTIMP صحیح __cdecl _ungetch(صحیح _Ch);
  _CRTIMP صحیح __cdecl _getch_nolock(تهی);
  _CRTIMP صحیح __cdecl _getche_nolock(تهی);
  _CRTIMP صحیح __cdecl _putch_nolock(صحیح _Ch);
  _CRTIMP صحیح __cdecl _ungetch_nolock(صحیح _Ch);

#ifndef _WCONIO_DEFINED
#define _WCONIO_DEFINED

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

  _CRTIMP wchar_t *_cgetws(wchar_t *_Buffer);
  _CRTIMP wint_t __cdecl _getwch(تهی);
  _CRTIMP wint_t __cdecl _getwche(تهی);
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
  _CRTIMP wint_t __cdecl _getwch_nolock(تهی);
  _CRTIMP wint_t __cdecl _getwche_nolock(تهی);
  _CRTIMP wint_t __cdecl _ungetwch_nolock(wint_t _WCh);
#endif

#ifndef	NO_OLDNAMES
  نویسه *__cdecl cgets(نویسه *_Buffer);
  صحیح __cdecl cprintf(ثابت نویسه *_Format,...);
  صحیح __cdecl cputs(ثابت نویسه *_Str);
  صحیح __cdecl cscanf(ثابت نویسه *_Format,...);
  صحیح __cdecl getch(تهی);
  صحیح __cdecl getche(تهی);
  صحیح __cdecl kbhit(تهی);
  صحیح __cdecl putch(صحیح _Ch);
  صحیح __cdecl ungetch(صحیح _Ch);

#اگر (defined(_X86_) && !defined(__x86_64))
  صحیح __cdecl inp(unsigned short);
  unsigned short __cdecl inpw(unsigned short);
  صحیح __cdecl outp(unsigned short,صحیح);
  unsigned short __cdecl outpw(unsigned short,unsigned short);
#endif

  /* I/O intrin functions.  */
  __CRT_INLINE unsigned نویسه __inbyte(unsigned short Port)
  {
      unsigned نویسه مقدار;
      __asm__ __volatile__ ("inb %w1,%b0"
          : "=a" (مقدار)
          : "Nd" (Port));
      بازگشت مقدار;
  }
  __CRT_INLINE unsigned short __inword(unsigned short Port)
  {
      unsigned short مقدار;
      __asm__ __volatile__ ("inw %w1,%w0"
          : "=a" (مقدار)
          : "Nd" (Port));
      بازگشت مقدار;
  }
  __CRT_INLINE unsigned long __indword(unsigned short Port)
  {
      unsigned long مقدار;
      __asm__ __volatile__ ("inl %w1,%0"
          : "=a" (مقدار)
          : "Nd" (Port));
      بازگشت مقدار;
  }
  __CRT_INLINE تهی __outbyte(unsigned short Port,unsigned نویسه Data)
  {
      __asm__ __volatile__ ("outb %b0,%w1"
          :
          : "a" (Data), "Nd" (Port));
  }
  __CRT_INLINE تهی __outword(unsigned short Port,unsigned short Data)
  {
      __asm__ __volatile__ ("outw %w0,%w1"
          :
          : "a" (Data), "Nd" (Port));
  }
  __CRT_INLINE تهی __outdword(unsigned short Port,unsigned long Data)
  {
      __asm__ __volatile__ ("outl %0,%w1"
          :
          : "a" (Data), "Nd" (Port));
  }
  __CRT_INLINE تهی __inbytestring(unsigned short Port,unsigned نویسه *Buffer,unsigned long شمار_3)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insb " 
		: "=D" (Buffer), "=c" (شمار_3)
		: "d"(Port), "0"(Buffer), "1" (شمار_3)
		);
  }
  __CRT_INLINE تهی __inwordstring(unsigned short Port,unsigned short *Buffer,unsigned long شمار_3)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insw " 
		: "=D" (Buffer), "=c" (شمار_3)
		: "d"(Port), "0"(Buffer), "1" (شمار_3)
		);
  }
  __CRT_INLINE تهی __indwordstring(unsigned short Port,unsigned long *Buffer,unsigned long شمار_3)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insl " 
		: "=D" (Buffer), "=c" (شمار_3)
		: "d"(Port), "0"(Buffer), "1" (شمار_3)
		);
  }

  __CRT_INLINE تهی __outbytestring(unsigned short Port,unsigned نویسه *Buffer,unsigned long شمار_3)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsb " 
          : "=S" (Buffer), "=c" (شمار_3)
          : "d"(Port), "0"(Buffer), "1" (شمار_3)
          );
  }
  __CRT_INLINE تهی __outwordstring(unsigned short Port,unsigned short *Buffer,unsigned long شمار_3)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsw " 
          : "=S" (Buffer), "=c" (شمار_3)
          : "d"(Port), "0"(Buffer), "1" (شمار_3)
          );
  }
  __CRT_INLINE تهی __outdwordstring(unsigned short Port,unsigned long *Buffer,unsigned long شمار_3)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsl " 
          : "=S" (Buffer), "=c" (شمار_3)
          : "d"(Port), "0"(Buffer), "1" (شمار_3)
          );
  }

  __CRT_INLINE unsigned __int64 __readcr0(تهی)
  {
      unsigned __int64 مقدار;
      __asm__ __volatile__ (
          "mov %%cr0, %[value]" 
          : [مقدار] "=q" (مقدار));
      بازگشت مقدار;
  }
 
  /* Register sizes are different between 32/64 bit mode. So we have to do this for _WIN64 and _WIN32
     separately.  */
 
#ifdef _WIN64
  __CRT_INLINE تهی __writecr0(unsigned __int64 Data)
  {
   __asm__ __volatile__ (
       "mov %[Data], %%cr0"
       :
       : [Data] "q" (Data)
       : "memory");
  }
 
  __CRT_INLINE unsigned __int64 __readcr2(تهی)
  {
      unsigned __int64 مقدار;
      __asm__ __volatile__ (
          "mov %%cr2, %[value]" 
          : [مقدار] "=q" (مقدار));
      بازگشت مقدار;
  }

 __CRT_INLINE تهی __writecr2(unsigned __int64 Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr2"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE unsigned __int64 __readcr3(تهی)
  {
      unsigned __int64 مقدار;
      __asm__ __volatile__ (
          "mov %%cr3, %[value]" 
          : [مقدار] "=q" (مقدار));
      بازگشت مقدار;
  }

 __CRT_INLINE تهی __writecr3(unsigned __int64 Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr3"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE unsigned __int64 __readcr4(تهی)
  {
      unsigned __int64 مقدار;
      __asm__ __volatile__ (
          "mov %%cr4, %[value]" 
          : [مقدار] "=q" (مقدار));
      بازگشت مقدار;
  }

 __CRT_INLINE تهی __writecr4(unsigned __int64 Data)
 {
     __asm__ __volatile__ (
         "mov %[Data], %%cr4"
         :
         : [Data] "q" (Data)
         : "memory");
 }
 
  __CRT_INLINE unsigned __int64 __readcr8(تهی)
  {
      unsigned __int64 مقدار;
      __asm__ __volatile__ (
          "mov %%cr8, %[value]" 
          : [مقدار] "=q" (مقدار));
      بازگشت مقدار;
  }

 __CRT_INLINE تهی __writecr8(unsigned __int64 Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr8"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
#وگرنهاگر defined(_WIN32)

  __CRT_INLINE تهی __writecr0(unsigned Data)
  {
    __asm__ __volatile__ (
       "mov %[Data], %%cr0"
       :
       : [Data] "q" (Data)
       : "memory");
  }
 
  __CRT_INLINE unsigned long __readcr2(تهی)
  {
      unsigned long مقدار;
      __asm__ __volatile__ (
          "mov %%cr2, %[value]" 
          : [مقدار] "=q" (مقدار));
      بازگشت مقدار;
  }

 __CRT_INLINE تهی __writecr2(unsigned Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr2"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE unsigned long __readcr3(تهی)
  {
      unsigned long مقدار;
      __asm__ __volatile__ (
          "mov %%cr3, %[value]" 
          : [مقدار] "=q" (مقدار));
      بازگشت مقدار;
  }

 __CRT_INLINE تهی __writecr3(unsigned Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr3"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE unsigned long __readcr4(تهی)
  {
      unsigned long مقدار;
      __asm__ __volatile__ (
          "mov %%cr4, %[value]" 
          : [مقدار] "=q" (مقدار));
      بازگشت مقدار;
  }

 __CRT_INLINE تهی __writecr4(unsigned Data)
 {
     __asm__ __volatile__ (
         "mov %[Data], %%cr4"
         :
         : [Data] "q" (Data)
         : "memory");
 }
 
 __CRT_INLINE unsigned long __readcr8(تهی)
 {
   unsigned long مقدار;      __asm__ __volatile__ (
          "mov %%cr8, %[value]" 
          : [مقدار] "=q" (مقدار));
     بازگشت مقدار;
 }

 __CRT_INLINE تهی __writecr8(unsigned Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr8"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
#endif

  __CRT_INLINE unsigned __int64 __readmsr(unsigned long msr)
  {
      unsigned __int64 val1, val2;
       __asm__ __volatile__(
           "rdmsr"
           : "=a" (val1), "=d" (val2)
           : "c" (msr));
      بازگشت val1 | (val2 << 32);
  }

 __CRT_INLINE تهی __writemsr (unsigned long msr, unsigned __int64 مقدار_3)
 {
    unsigned long val1 = مقدار_3, val2 = مقدار_3 >> 32;
   __asm__ __volatile__ (
       "wrmsr"
       :
       : "c" (msr), "a" (val1), "d" (val2));
 }
 
  __CRT_INLINE unsigned __int64 __rdtsc(تهی)
  {
      unsigned __int64 val1, val2;
      __asm__ __volatile__ (
          "rdtsc" 
          : "=a" (val1), "=d" (val2));
      بازگشت val1 | (val2 << 32);
  }

  __CRT_INLINE تهی __cpuid(صحیح CPUInfo[4], صحیح InfoType)
  {
      __asm__ __volatile__ (
          "cpuid"
          : "=a" (CPUInfo [0]), "=b" (CPUInfo [1]), "=c" (CPUInfo [2]), "=d" (CPUInfo [3])
          : "a" (InfoType));
  }

#endif

#ifdef __cplusplus
}
#endif

#شامل <sec_api/conio_s.h>

#endif
