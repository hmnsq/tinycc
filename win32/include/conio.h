/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_CONIO
#define _INC_CONIO

#ಅನ್ತರ್ಭಾವ <_mingw.h>

#ifdef __cplusplus
ಬಾಹ್ಯ "C" {
#endif

  _CRTIMP ವರ್ಣ *_cgets(ವರ್ಣ *_Buffer);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _cprintf(ಧ್ರುವ ವರ್ಣ *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _cputs(ಧ್ರುವ ವರ್ಣ *_Str);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _cscanf(ಧ್ರುವ ವರ್ಣ *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _cscanf_l(ಧ್ರುವ ವರ್ಣ *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _getch(ಶೂನ್ಯ);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _getche(ಶೂನ್ಯ);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vcprintf(ಧ್ರುವ ವರ್ಣ *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _cprintf_p(ಧ್ರುವ ವರ್ಣ *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vcprintf_p(ಧ್ರುವ ವರ್ಣ *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _cprintf_l(ಧ್ರುವ ವರ್ಣ *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vcprintf_l(ಧ್ರುವ ವರ್ಣ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _cprintf_p_l(ಧ್ರುವ ವರ್ಣ *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vcprintf_p_l(ಧ್ರುವ ವರ್ಣ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _kbhit(ಶೂನ್ಯ);

#ಯದಿ defined(_X86_) && !defined(__x86_64)
  ಪೂರ್ಣಾಙ್ಕ __cdecl _inp(unsigned short);
  unsigned short __cdecl _inpw(unsigned short);
  unsigned long __cdecl _inpd(unsigned short);
  ಪೂರ್ಣಾಙ್ಕ __cdecl _outp(unsigned short,ಪೂರ್ಣಾಙ್ಕ);
  unsigned short __cdecl _outpw(unsigned short,unsigned short);
  unsigned long __cdecl _outpd(unsigned short,unsigned long);
#endif

  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _putch(ಪೂರ್ಣಾಙ್ಕ _Ch);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _ungetch(ಪೂರ್ಣಾಙ್ಕ _Ch);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _getch_nolock(ಶೂನ್ಯ);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _getche_nolock(ಶೂನ್ಯ);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _putch_nolock(ಪೂರ್ಣಾಙ್ಕ _Ch);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _ungetch_nolock(ಪೂರ್ಣಾಙ್ಕ _Ch);

#ifndef _WCONIO_DEFINED
#define _WCONIO_DEFINED

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

  _CRTIMP wchar_t *_cgetws(wchar_t *_Buffer);
  _CRTIMP wint_t __cdecl _getwch(ಶೂನ್ಯ);
  _CRTIMP wint_t __cdecl _getwche(ಶೂನ್ಯ);
  _CRTIMP wint_t __cdecl _putwch(wchar_t _WCh);
  _CRTIMP wint_t __cdecl _ungetwch(wint_t _WCh);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _cputws(ಧ್ರುವ wchar_t *_String);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _cwprintf(ಧ್ರುವ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _cwscanf(ಧ್ರುವ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _cwscanf_l(ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vcwprintf(ಧ್ರುವ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _cwprintf_p(ಧ್ರುವ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vcwprintf_p(ಧ್ರುವ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _cwprintf_l(ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vcwprintf_l(ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _cwprintf_p_l(ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _vcwprintf_p_l(ಧ್ರುವ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP wint_t __cdecl _putwch_nolock(wchar_t _WCh);
  _CRTIMP wint_t __cdecl _getwch_nolock(ಶೂನ್ಯ);
  _CRTIMP wint_t __cdecl _getwche_nolock(ಶೂನ್ಯ);
  _CRTIMP wint_t __cdecl _ungetwch_nolock(wint_t _WCh);
#endif

#ifndef	NO_OLDNAMES
  ವರ್ಣ *__cdecl cgets(ವರ್ಣ *_Buffer);
  ಪೂರ್ಣಾಙ್ಕ __cdecl cprintf(ಧ್ರುವ ವರ್ಣ *_Format,...);
  ಪೂರ್ಣಾಙ್ಕ __cdecl cputs(ಧ್ರುವ ವರ್ಣ *_Str);
  ಪೂರ್ಣಾಙ್ಕ __cdecl cscanf(ಧ್ರುವ ವರ್ಣ *_Format,...);
  ಪೂರ್ಣಾಙ್ಕ __cdecl getch(ಶೂನ್ಯ);
  ಪೂರ್ಣಾಙ್ಕ __cdecl getche(ಶೂನ್ಯ);
  ಪೂರ್ಣಾಙ್ಕ __cdecl kbhit(ಶೂನ್ಯ);
  ಪೂರ್ಣಾಙ್ಕ __cdecl putch(ಪೂರ್ಣಾಙ್ಕ _Ch);
  ಪೂರ್ಣಾಙ್ಕ __cdecl ungetch(ಪೂರ್ಣಾಙ್ಕ _Ch);

#ಯದಿ (defined(_X86_) && !defined(__x86_64))
  ಪೂರ್ಣಾಙ್ಕ __cdecl inp(unsigned short);
  unsigned short __cdecl inpw(unsigned short);
  ಪೂರ್ಣಾಙ್ಕ __cdecl outp(unsigned short,ಪೂರ್ಣಾಙ್ಕ);
  unsigned short __cdecl outpw(unsigned short,unsigned short);
#endif

  /* I/O intrin functions.  */
  __CRT_INLINE unsigned ವರ್ಣ __inbyte(unsigned short Port)
  {
      unsigned ವರ್ಣ ಮೌಲ್ಯ;
      __asm__ __volatile__ ("inb %w1,%b0"
          : "=a" (ಮೌಲ್ಯ)
          : "Nd" (Port));
      ಪ್ರತ್ಯಾಗಮ ಮೌಲ್ಯ;
  }
  __CRT_INLINE unsigned short __inword(unsigned short Port)
  {
      unsigned short ಮೌಲ್ಯ;
      __asm__ __volatile__ ("inw %w1,%w0"
          : "=a" (ಮೌಲ್ಯ)
          : "Nd" (Port));
      ಪ್ರತ್ಯಾಗಮ ಮೌಲ್ಯ;
  }
  __CRT_INLINE unsigned long __indword(unsigned short Port)
  {
      unsigned long ಮೌಲ್ಯ;
      __asm__ __volatile__ ("inl %w1,%0"
          : "=a" (ಮೌಲ್ಯ)
          : "Nd" (Port));
      ಪ್ರತ್ಯಾಗಮ ಮೌಲ್ಯ;
  }
  __CRT_INLINE ಶೂನ್ಯ __outbyte(unsigned short Port,unsigned ವರ್ಣ Data)
  {
      __asm__ __volatile__ ("outb %b0,%w1"
          :
          : "a" (Data), "Nd" (Port));
  }
  __CRT_INLINE ಶೂನ್ಯ __outword(unsigned short Port,unsigned short Data)
  {
      __asm__ __volatile__ ("outw %w0,%w1"
          :
          : "a" (Data), "Nd" (Port));
  }
  __CRT_INLINE ಶೂನ್ಯ __outdword(unsigned short Port,unsigned long Data)
  {
      __asm__ __volatile__ ("outl %0,%w1"
          :
          : "a" (Data), "Nd" (Port));
  }
  __CRT_INLINE ಶೂನ್ಯ __inbytestring(unsigned short Port,unsigned ವರ್ಣ *Buffer,unsigned long ಎಣಿಕೆ_3)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insb " 
		: "=D" (Buffer), "=c" (ಎಣಿಕೆ_3)
		: "d"(Port), "0"(Buffer), "1" (ಎಣಿಕೆ_3)
		);
  }
  __CRT_INLINE ಶೂನ್ಯ __inwordstring(unsigned short Port,unsigned short *Buffer,unsigned long ಎಣಿಕೆ_3)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insw " 
		: "=D" (Buffer), "=c" (ಎಣಿಕೆ_3)
		: "d"(Port), "0"(Buffer), "1" (ಎಣಿಕೆ_3)
		);
  }
  __CRT_INLINE ಶೂನ್ಯ __indwordstring(unsigned short Port,unsigned long *Buffer,unsigned long ಎಣಿಕೆ_3)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insl " 
		: "=D" (Buffer), "=c" (ಎಣಿಕೆ_3)
		: "d"(Port), "0"(Buffer), "1" (ಎಣಿಕೆ_3)
		);
  }

  __CRT_INLINE ಶೂನ್ಯ __outbytestring(unsigned short Port,unsigned ವರ್ಣ *Buffer,unsigned long ಎಣಿಕೆ_3)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsb " 
          : "=S" (Buffer), "=c" (ಎಣಿಕೆ_3)
          : "d"(Port), "0"(Buffer), "1" (ಎಣಿಕೆ_3)
          );
  }
  __CRT_INLINE ಶೂನ್ಯ __outwordstring(unsigned short Port,unsigned short *Buffer,unsigned long ಎಣಿಕೆ_3)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsw " 
          : "=S" (Buffer), "=c" (ಎಣಿಕೆ_3)
          : "d"(Port), "0"(Buffer), "1" (ಎಣಿಕೆ_3)
          );
  }
  __CRT_INLINE ಶೂನ್ಯ __outdwordstring(unsigned short Port,unsigned long *Buffer,unsigned long ಎಣಿಕೆ_3)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsl " 
          : "=S" (Buffer), "=c" (ಎಣಿಕೆ_3)
          : "d"(Port), "0"(Buffer), "1" (ಎಣಿಕೆ_3)
          );
  }

  __CRT_INLINE unsigned __int64 __readcr0(ಶೂನ್ಯ)
  {
      unsigned __int64 ಮೌಲ್ಯ;
      __asm__ __volatile__ (
          "mov %%cr0, %[value]" 
          : [ಮೌಲ್ಯ] "=q" (ಮೌಲ್ಯ));
      ಪ್ರತ್ಯಾಗಮ ಮೌಲ್ಯ;
  }
 
  /* Register sizes are different between 32/64 bit mode. So we have to do this for _WIN64 and _WIN32
     separately.  */
 
#ifdef _WIN64
  __CRT_INLINE ಶೂನ್ಯ __writecr0(unsigned __int64 Data)
  {
   __asm__ __volatile__ (
       "mov %[Data], %%cr0"
       :
       : [Data] "q" (Data)
       : "memory");
  }
 
  __CRT_INLINE unsigned __int64 __readcr2(ಶೂನ್ಯ)
  {
      unsigned __int64 ಮೌಲ್ಯ;
      __asm__ __volatile__ (
          "mov %%cr2, %[value]" 
          : [ಮೌಲ್ಯ] "=q" (ಮೌಲ್ಯ));
      ಪ್ರತ್ಯಾಗಮ ಮೌಲ್ಯ;
  }

 __CRT_INLINE ಶೂನ್ಯ __writecr2(unsigned __int64 Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr2"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE unsigned __int64 __readcr3(ಶೂನ್ಯ)
  {
      unsigned __int64 ಮೌಲ್ಯ;
      __asm__ __volatile__ (
          "mov %%cr3, %[value]" 
          : [ಮೌಲ್ಯ] "=q" (ಮೌಲ್ಯ));
      ಪ್ರತ್ಯಾಗಮ ಮೌಲ್ಯ;
  }

 __CRT_INLINE ಶೂನ್ಯ __writecr3(unsigned __int64 Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr3"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE unsigned __int64 __readcr4(ಶೂನ್ಯ)
  {
      unsigned __int64 ಮೌಲ್ಯ;
      __asm__ __volatile__ (
          "mov %%cr4, %[value]" 
          : [ಮೌಲ್ಯ] "=q" (ಮೌಲ್ಯ));
      ಪ್ರತ್ಯಾಗಮ ಮೌಲ್ಯ;
  }

 __CRT_INLINE ಶೂನ್ಯ __writecr4(unsigned __int64 Data)
 {
     __asm__ __volatile__ (
         "mov %[Data], %%cr4"
         :
         : [Data] "q" (Data)
         : "memory");
 }
 
  __CRT_INLINE unsigned __int64 __readcr8(ಶೂನ್ಯ)
  {
      unsigned __int64 ಮೌಲ್ಯ;
      __asm__ __volatile__ (
          "mov %%cr8, %[value]" 
          : [ಮೌಲ್ಯ] "=q" (ಮೌಲ್ಯ));
      ಪ್ರತ್ಯಾಗಮ ಮೌಲ್ಯ;
  }

 __CRT_INLINE ಶೂನ್ಯ __writecr8(unsigned __int64 Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr8"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
#ನೋಚೇದ್ಯದಿ defined(_WIN32)

  __CRT_INLINE ಶೂನ್ಯ __writecr0(unsigned Data)
  {
    __asm__ __volatile__ (
       "mov %[Data], %%cr0"
       :
       : [Data] "q" (Data)
       : "memory");
  }
 
  __CRT_INLINE unsigned long __readcr2(ಶೂನ್ಯ)
  {
      unsigned long ಮೌಲ್ಯ;
      __asm__ __volatile__ (
          "mov %%cr2, %[value]" 
          : [ಮೌಲ್ಯ] "=q" (ಮೌಲ್ಯ));
      ಪ್ರತ್ಯಾಗಮ ಮೌಲ್ಯ;
  }

 __CRT_INLINE ಶೂನ್ಯ __writecr2(unsigned Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr2"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE unsigned long __readcr3(ಶೂನ್ಯ)
  {
      unsigned long ಮೌಲ್ಯ;
      __asm__ __volatile__ (
          "mov %%cr3, %[value]" 
          : [ಮೌಲ್ಯ] "=q" (ಮೌಲ್ಯ));
      ಪ್ರತ್ಯಾಗಮ ಮೌಲ್ಯ;
  }

 __CRT_INLINE ಶೂನ್ಯ __writecr3(unsigned Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr3"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE unsigned long __readcr4(ಶೂನ್ಯ)
  {
      unsigned long ಮೌಲ್ಯ;
      __asm__ __volatile__ (
          "mov %%cr4, %[value]" 
          : [ಮೌಲ್ಯ] "=q" (ಮೌಲ್ಯ));
      ಪ್ರತ್ಯಾಗಮ ಮೌಲ್ಯ;
  }

 __CRT_INLINE ಶೂನ್ಯ __writecr4(unsigned Data)
 {
     __asm__ __volatile__ (
         "mov %[Data], %%cr4"
         :
         : [Data] "q" (Data)
         : "memory");
 }
 
 __CRT_INLINE unsigned long __readcr8(ಶೂನ್ಯ)
 {
   unsigned long ಮೌಲ್ಯ;      __asm__ __volatile__ (
          "mov %%cr8, %[value]" 
          : [ಮೌಲ್ಯ] "=q" (ಮೌಲ್ಯ));
     ಪ್ರತ್ಯಾಗಮ ಮೌಲ್ಯ;
 }

 __CRT_INLINE ಶೂನ್ಯ __writecr8(unsigned Data)
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
      ಪ್ರತ್ಯಾಗಮ val1 | (val2 << 32);
  }

 __CRT_INLINE ಶೂನ್ಯ __writemsr (unsigned long msr, unsigned __int64 ಮೌಲ್ಯ_3)
 {
    unsigned long val1 = ಮೌಲ್ಯ_3, val2 = ಮೌಲ್ಯ_3 >> 32;
   __asm__ __volatile__ (
       "wrmsr"
       :
       : "c" (msr), "a" (val1), "d" (val2));
 }
 
  __CRT_INLINE unsigned __int64 __rdtsc(ಶೂನ್ಯ)
  {
      unsigned __int64 val1, val2;
      __asm__ __volatile__ (
          "rdtsc" 
          : "=a" (val1), "=d" (val2));
      ಪ್ರತ್ಯಾಗಮ val1 | (val2 << 32);
  }

  __CRT_INLINE ಶೂನ್ಯ __cpuid(ಪೂರ್ಣಾಙ್ಕ CPUInfo[4], ಪೂರ್ಣಾಙ್ಕ InfoType)
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

#ಅನ್ತರ್ಭಾವ <sec_api/conio_s.h>

#endif
