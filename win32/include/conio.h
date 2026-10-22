/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_CONIO
#define _INC_CONIO

#அந்தர்பாவ <_mingw.h>

#ifdef __cplusplus
வெளி "C" {
#endif

  _CRTIMP எழுத்து *_cgets(எழுத்து *_Buffer);
  _CRTIMP முழு __cdecl _cprintf(மாறிலி எழுத்து *_Format,...);
  _CRTIMP முழு __cdecl _cputs(மாறிலி எழுத்து *_Str);
  _CRTIMP முழு __cdecl _cscanf(மாறிலி எழுத்து *_Format,...);
  _CRTIMP முழு __cdecl _cscanf_l(மாறிலி எழுத்து *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _getch(வெறுமை);
  _CRTIMP முழு __cdecl _getche(வெறுமை);
  _CRTIMP முழு __cdecl _vcprintf(மாறிலி எழுத்து *_Format,va_list _ArgList);
  _CRTIMP முழு __cdecl _cprintf_p(மாறிலி எழுத்து *_Format,...);
  _CRTIMP முழு __cdecl _vcprintf_p(மாறிலி எழுத்து *_Format,va_list _ArgList);
  _CRTIMP முழு __cdecl _cprintf_l(மாறிலி எழுத்து *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _vcprintf_l(மாறிலி எழுத்து *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP முழு __cdecl _cprintf_p_l(மாறிலி எழுத்து *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _vcprintf_p_l(மாறிலி எழுத்து *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP முழு __cdecl _kbhit(வெறுமை);

#எனில் defined(_X86_) && !defined(__x86_64)
  முழு __cdecl _inp(unsigned short);
  unsigned short __cdecl _inpw(unsigned short);
  unsigned long __cdecl _inpd(unsigned short);
  முழு __cdecl _outp(unsigned short,முழு);
  unsigned short __cdecl _outpw(unsigned short,unsigned short);
  unsigned long __cdecl _outpd(unsigned short,unsigned long);
#endif

  _CRTIMP முழு __cdecl _putch(முழு _Ch);
  _CRTIMP முழு __cdecl _ungetch(முழு _Ch);
  _CRTIMP முழு __cdecl _getch_nolock(வெறுமை);
  _CRTIMP முழு __cdecl _getche_nolock(வெறுமை);
  _CRTIMP முழு __cdecl _putch_nolock(முழு _Ch);
  _CRTIMP முழு __cdecl _ungetch_nolock(முழு _Ch);

#ifndef _WCONIO_DEFINED
#define _WCONIO_DEFINED

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

  _CRTIMP wchar_t *_cgetws(wchar_t *_Buffer);
  _CRTIMP wint_t __cdecl _getwch(வெறுமை);
  _CRTIMP wint_t __cdecl _getwche(வெறுமை);
  _CRTIMP wint_t __cdecl _putwch(wchar_t _WCh);
  _CRTIMP wint_t __cdecl _ungetwch(wint_t _WCh);
  _CRTIMP முழு __cdecl _cputws(மாறிலி wchar_t *_String);
  _CRTIMP முழு __cdecl _cwprintf(மாறிலி wchar_t *_Format,...);
  _CRTIMP முழு __cdecl _cwscanf(மாறிலி wchar_t *_Format,...);
  _CRTIMP முழு __cdecl _cwscanf_l(மாறிலி wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _vcwprintf(மாறிலி wchar_t *_Format,va_list _ArgList);
  _CRTIMP முழு __cdecl _cwprintf_p(மாறிலி wchar_t *_Format,...);
  _CRTIMP முழு __cdecl _vcwprintf_p(மாறிலி wchar_t *_Format,va_list _ArgList);
  _CRTIMP முழு __cdecl _cwprintf_l(மாறிலி wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _vcwprintf_l(மாறிலி wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP முழு __cdecl _cwprintf_p_l(மாறிலி wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP முழு __cdecl _vcwprintf_p_l(மாறிலி wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP wint_t __cdecl _putwch_nolock(wchar_t _WCh);
  _CRTIMP wint_t __cdecl _getwch_nolock(வெறுமை);
  _CRTIMP wint_t __cdecl _getwche_nolock(வெறுமை);
  _CRTIMP wint_t __cdecl _ungetwch_nolock(wint_t _WCh);
#endif

#ifndef	NO_OLDNAMES
  எழுத்து *__cdecl cgets(எழுத்து *_Buffer);
  முழு __cdecl cprintf(மாறிலி எழுத்து *_Format,...);
  முழு __cdecl cputs(மாறிலி எழுத்து *_Str);
  முழு __cdecl cscanf(மாறிலி எழுத்து *_Format,...);
  முழு __cdecl getch(வெறுமை);
  முழு __cdecl getche(வெறுமை);
  முழு __cdecl kbhit(வெறுமை);
  முழு __cdecl putch(முழு _Ch);
  முழு __cdecl ungetch(முழு _Ch);

#எனில் (defined(_X86_) && !defined(__x86_64))
  முழு __cdecl inp(unsigned short);
  unsigned short __cdecl inpw(unsigned short);
  முழு __cdecl outp(unsigned short,முழு);
  unsigned short __cdecl outpw(unsigned short,unsigned short);
#endif

  /* I/O intrin functions.  */
  __CRT_INLINE unsigned எழுத்து __inbyte(unsigned short Port)
  {
      unsigned எழுத்து மதிப்பு;
      __asm__ __volatile__ ("inb %w1,%b0"
          : "=a" (மதிப்பு)
          : "Nd" (Port));
      திரும்பு மதிப்பு;
  }
  __CRT_INLINE unsigned short __inword(unsigned short Port)
  {
      unsigned short மதிப்பு;
      __asm__ __volatile__ ("inw %w1,%w0"
          : "=a" (மதிப்பு)
          : "Nd" (Port));
      திரும்பு மதிப்பு;
  }
  __CRT_INLINE unsigned long __indword(unsigned short Port)
  {
      unsigned long மதிப்பு;
      __asm__ __volatile__ ("inl %w1,%0"
          : "=a" (மதிப்பு)
          : "Nd" (Port));
      திரும்பு மதிப்பு;
  }
  __CRT_INLINE வெறுமை __outbyte(unsigned short Port,unsigned எழுத்து Data)
  {
      __asm__ __volatile__ ("outb %b0,%w1"
          :
          : "a" (Data), "Nd" (Port));
  }
  __CRT_INLINE வெறுமை __outword(unsigned short Port,unsigned short Data)
  {
      __asm__ __volatile__ ("outw %w0,%w1"
          :
          : "a" (Data), "Nd" (Port));
  }
  __CRT_INLINE வெறுமை __outdword(unsigned short Port,unsigned long Data)
  {
      __asm__ __volatile__ ("outl %0,%w1"
          :
          : "a" (Data), "Nd" (Port));
  }
  __CRT_INLINE வெறுமை __inbytestring(unsigned short Port,unsigned எழுத்து *Buffer,unsigned long மொத்தம்_3)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insb " 
		: "=D" (Buffer), "=c" (மொத்தம்_3)
		: "d"(Port), "0"(Buffer), "1" (மொத்தம்_3)
		);
  }
  __CRT_INLINE வெறுமை __inwordstring(unsigned short Port,unsigned short *Buffer,unsigned long மொத்தம்_3)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insw " 
		: "=D" (Buffer), "=c" (மொத்தம்_3)
		: "d"(Port), "0"(Buffer), "1" (மொத்தம்_3)
		);
  }
  __CRT_INLINE வெறுமை __indwordstring(unsigned short Port,unsigned long *Buffer,unsigned long மொத்தம்_3)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insl " 
		: "=D" (Buffer), "=c" (மொத்தம்_3)
		: "d"(Port), "0"(Buffer), "1" (மொத்தம்_3)
		);
  }

  __CRT_INLINE வெறுமை __outbytestring(unsigned short Port,unsigned எழுத்து *Buffer,unsigned long மொத்தம்_3)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsb " 
          : "=S" (Buffer), "=c" (மொத்தம்_3)
          : "d"(Port), "0"(Buffer), "1" (மொத்தம்_3)
          );
  }
  __CRT_INLINE வெறுமை __outwordstring(unsigned short Port,unsigned short *Buffer,unsigned long மொத்தம்_3)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsw " 
          : "=S" (Buffer), "=c" (மொத்தம்_3)
          : "d"(Port), "0"(Buffer), "1" (மொத்தம்_3)
          );
  }
  __CRT_INLINE வெறுமை __outdwordstring(unsigned short Port,unsigned long *Buffer,unsigned long மொத்தம்_3)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsl " 
          : "=S" (Buffer), "=c" (மொத்தம்_3)
          : "d"(Port), "0"(Buffer), "1" (மொத்தம்_3)
          );
  }

  __CRT_INLINE unsigned __int64 __readcr0(வெறுமை)
  {
      unsigned __int64 மதிப்பு;
      __asm__ __volatile__ (
          "mov %%cr0, %[value]" 
          : [மதிப்பு] "=q" (மதிப்பு));
      திரும்பு மதிப்பு;
  }
 
  /* Register sizes are different between 32/64 bit mode. So we have to do this for _WIN64 and _WIN32
     separately.  */
 
#ifdef _WIN64
  __CRT_INLINE வெறுமை __writecr0(unsigned __int64 Data)
  {
   __asm__ __volatile__ (
       "mov %[Data], %%cr0"
       :
       : [Data] "q" (Data)
       : "memory");
  }
 
  __CRT_INLINE unsigned __int64 __readcr2(வெறுமை)
  {
      unsigned __int64 மதிப்பு;
      __asm__ __volatile__ (
          "mov %%cr2, %[value]" 
          : [மதிப்பு] "=q" (மதிப்பு));
      திரும்பு மதிப்பு;
  }

 __CRT_INLINE வெறுமை __writecr2(unsigned __int64 Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr2"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE unsigned __int64 __readcr3(வெறுமை)
  {
      unsigned __int64 மதிப்பு;
      __asm__ __volatile__ (
          "mov %%cr3, %[value]" 
          : [மதிப்பு] "=q" (மதிப்பு));
      திரும்பு மதிப்பு;
  }

 __CRT_INLINE வெறுமை __writecr3(unsigned __int64 Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr3"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE unsigned __int64 __readcr4(வெறுமை)
  {
      unsigned __int64 மதிப்பு;
      __asm__ __volatile__ (
          "mov %%cr4, %[value]" 
          : [மதிப்பு] "=q" (மதிப்பு));
      திரும்பு மதிப்பு;
  }

 __CRT_INLINE வெறுமை __writecr4(unsigned __int64 Data)
 {
     __asm__ __volatile__ (
         "mov %[Data], %%cr4"
         :
         : [Data] "q" (Data)
         : "memory");
 }
 
  __CRT_INLINE unsigned __int64 __readcr8(வெறுமை)
  {
      unsigned __int64 மதிப்பு;
      __asm__ __volatile__ (
          "mov %%cr8, %[value]" 
          : [மதிப்பு] "=q" (மதிப்பு));
      திரும்பு மதிப்பு;
  }

 __CRT_INLINE வெறுமை __writecr8(unsigned __int64 Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr8"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
#அல்லதெனில் defined(_WIN32)

  __CRT_INLINE வெறுமை __writecr0(unsigned Data)
  {
    __asm__ __volatile__ (
       "mov %[Data], %%cr0"
       :
       : [Data] "q" (Data)
       : "memory");
  }
 
  __CRT_INLINE unsigned long __readcr2(வெறுமை)
  {
      unsigned long மதிப்பு;
      __asm__ __volatile__ (
          "mov %%cr2, %[value]" 
          : [மதிப்பு] "=q" (மதிப்பு));
      திரும்பு மதிப்பு;
  }

 __CRT_INLINE வெறுமை __writecr2(unsigned Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr2"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE unsigned long __readcr3(வெறுமை)
  {
      unsigned long மதிப்பு;
      __asm__ __volatile__ (
          "mov %%cr3, %[value]" 
          : [மதிப்பு] "=q" (மதிப்பு));
      திரும்பு மதிப்பு;
  }

 __CRT_INLINE வெறுமை __writecr3(unsigned Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr3"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE unsigned long __readcr4(வெறுமை)
  {
      unsigned long மதிப்பு;
      __asm__ __volatile__ (
          "mov %%cr4, %[value]" 
          : [மதிப்பு] "=q" (மதிப்பு));
      திரும்பு மதிப்பு;
  }

 __CRT_INLINE வெறுமை __writecr4(unsigned Data)
 {
     __asm__ __volatile__ (
         "mov %[Data], %%cr4"
         :
         : [Data] "q" (Data)
         : "memory");
 }
 
 __CRT_INLINE unsigned long __readcr8(வெறுமை)
 {
   unsigned long மதிப்பு;      __asm__ __volatile__ (
          "mov %%cr8, %[value]" 
          : [மதிப்பு] "=q" (மதிப்பு));
     திரும்பு மதிப்பு;
 }

 __CRT_INLINE வெறுமை __writecr8(unsigned Data)
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
      திரும்பு val1 | (val2 << 32);
  }

 __CRT_INLINE வெறுமை __writemsr (unsigned long msr, unsigned __int64 மதிப்பு_3)
 {
    unsigned long val1 = மதிப்பு_3, val2 = மதிப்பு_3 >> 32;
   __asm__ __volatile__ (
       "wrmsr"
       :
       : "c" (msr), "a" (val1), "d" (val2));
 }
 
  __CRT_INLINE unsigned __int64 __rdtsc(வெறுமை)
  {
      unsigned __int64 val1, val2;
      __asm__ __volatile__ (
          "rdtsc" 
          : "=a" (val1), "=d" (val2));
      திரும்பு val1 | (val2 << 32);
  }

  __CRT_INLINE வெறுமை __cpuid(முழு CPUInfo[4], முழு InfoType)
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

#அந்தர்பாவ <sec_api/conio_s.h>

#endif
