/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_CONIO
#define _INC_CONIO

#अन्तर्भाव <_mingw.h>

#ifdef __cplusplus
बाह्य "C" {
#endif

  _CRTIMP वर्ण *_cgets(वर्ण *_Buffer);
  _CRTIMP पूर्णाङ्क __cdecl _cprintf(ध्रुव वर्ण *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _cputs(ध्रुव वर्ण *_Str);
  _CRTIMP पूर्णाङ्क __cdecl _cscanf(ध्रुव वर्ण *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _cscanf_l(ध्रुव वर्ण *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _getch(शून्य);
  _CRTIMP पूर्णाङ्क __cdecl _getche(शून्य);
  _CRTIMP पूर्णाङ्क __cdecl _vcprintf(ध्रुव वर्ण *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _cprintf_p(ध्रुव वर्ण *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _vcprintf_p(ध्रुव वर्ण *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _cprintf_l(ध्रुव वर्ण *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vcprintf_l(ध्रुव वर्ण *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _cprintf_p_l(ध्रुव वर्ण *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vcprintf_p_l(ध्रुव वर्ण *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _kbhit(शून्य);

#यदि defined(_X86_) && !defined(__x86_64)
  पूर्णाङ्क __cdecl _inp(अचिन्हित लघु);
  अचिन्हित लघु __cdecl _inpw(अचिन्हित लघु);
  अचिन्हित दीर्घ __cdecl _inpd(अचिन्हित लघु);
  पूर्णाङ्क __cdecl _outp(अचिन्हित लघु,पूर्णाङ्क);
  अचिन्हित लघु __cdecl _outpw(अचिन्हित लघु,अचिन्हित लघु);
  अचिन्हित दीर्घ __cdecl _outpd(अचिन्हित लघु,अचिन्हित दीर्घ);
#endif

  _CRTIMP पूर्णाङ्क __cdecl _putch(पूर्णाङ्क _Ch);
  _CRTIMP पूर्णाङ्क __cdecl _ungetch(पूर्णाङ्क _Ch);
  _CRTIMP पूर्णाङ्क __cdecl _getch_nolock(शून्य);
  _CRTIMP पूर्णाङ्क __cdecl _getche_nolock(शून्य);
  _CRTIMP पूर्णाङ्क __cdecl _putch_nolock(पूर्णाङ्क _Ch);
  _CRTIMP पूर्णाङ्क __cdecl _ungetch_nolock(पूर्णाङ्क _Ch);

#ifndef _WCONIO_DEFINED
#define _WCONIO_DEFINED

#ifndef WEOF
#define WEOF (wint_t)(0xFFFF)
#endif

  _CRTIMP ब_अक्षर_प्रकार *_cgetws(ब_अक्षर_प्रकार *_Buffer);
  _CRTIMP wint_t __cdecl _getwch(शून्य);
  _CRTIMP wint_t __cdecl _getwche(शून्य);
  _CRTIMP wint_t __cdecl _putwch(ब_अक्षर_प्रकार _WCh);
  _CRTIMP wint_t __cdecl _ungetwch(wint_t _WCh);
  _CRTIMP पूर्णाङ्क __cdecl _cputws(ध्रुव ब_अक्षर_प्रकार *_String);
  _CRTIMP पूर्णाङ्क __cdecl _cwprintf(ध्रुव ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _cwscanf(ध्रुव ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _cwscanf_l(ध्रुव ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vcwprintf(ध्रुव ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _cwprintf_p(ध्रुव ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णाङ्क __cdecl _vcwprintf_p(ध्रुव ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _cwprintf_l(ध्रुव ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vcwprintf_l(ध्रुव ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णाङ्क __cdecl _cwprintf_p_l(ध्रुव ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णाङ्क __cdecl _vcwprintf_p_l(ध्रुव ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP wint_t __cdecl _putwch_nolock(ब_अक्षर_प्रकार _WCh);
  _CRTIMP wint_t __cdecl _getwch_nolock(शून्य);
  _CRTIMP wint_t __cdecl _getwche_nolock(शून्य);
  _CRTIMP wint_t __cdecl _ungetwch_nolock(wint_t _WCh);
#endif

#ifndef	NO_OLDNAMES
  वर्ण *__cdecl cgets(वर्ण *_Buffer);
  पूर्णाङ्क __cdecl cprintf(ध्रुव वर्ण *_Format,...);
  पूर्णाङ्क __cdecl cputs(ध्रुव वर्ण *_Str);
  पूर्णाङ्क __cdecl cscanf(ध्रुव वर्ण *_Format,...);
  पूर्णाङ्क __cdecl getch(शून्य);
  पूर्णाङ्क __cdecl getche(शून्य);
  पूर्णाङ्क __cdecl kbhit(शून्य);
  पूर्णाङ्क __cdecl putch(पूर्णाङ्क _Ch);
  पूर्णाङ्क __cdecl ungetch(पूर्णाङ्क _Ch);

#यदि (defined(_X86_) && !defined(__x86_64))
  पूर्णाङ्क __cdecl inp(अचिन्हित लघु);
  अचिन्हित लघु __cdecl inpw(अचिन्हित लघु);
  पूर्णाङ्क __cdecl outp(अचिन्हित लघु,पूर्णाङ्क);
  अचिन्हित लघु __cdecl outpw(अचिन्हित लघु,अचिन्हित लघु);
#endif

  /* I/O intrin functions.  */
  __CRT_INLINE अचिन्हित वर्ण __inbyte(अचिन्हित लघु Port)
  {
      अचिन्हित वर्ण मूल्य;
      __asm__ __volatile__ ("inb %w1,%b0"
          : "=a" (मूल्य)
          : "Nd" (Port));
      प्रत्यागम मूल्य;
  }
  __CRT_INLINE अचिन्हित लघु __inword(अचिन्हित लघु Port)
  {
      अचिन्हित लघु मूल्य;
      __asm__ __volatile__ ("inw %w1,%w0"
          : "=a" (मूल्य)
          : "Nd" (Port));
      प्रत्यागम मूल्य;
  }
  __CRT_INLINE अचिन्हित दीर्घ __indword(अचिन्हित लघु Port)
  {
      अचिन्हित दीर्घ मूल्य;
      __asm__ __volatile__ ("inl %w1,%0"
          : "=a" (मूल्य)
          : "Nd" (Port));
      प्रत्यागम मूल्य;
  }
  __CRT_INLINE शून्य __outbyte(अचिन्हित लघु Port,अचिन्हित वर्ण Data)
  {
      __asm__ __volatile__ ("outb %b0,%w1"
          :
          : "a" (Data), "Nd" (Port));
  }
  __CRT_INLINE शून्य __outword(अचिन्हित लघु Port,अचिन्हित लघु Data)
  {
      __asm__ __volatile__ ("outw %w0,%w1"
          :
          : "a" (Data), "Nd" (Port));
  }
  __CRT_INLINE शून्य __outdword(अचिन्हित लघु Port,अचिन्हित दीर्घ Data)
  {
      __asm__ __volatile__ ("outl %0,%w1"
          :
          : "a" (Data), "Nd" (Port));
  }
  __CRT_INLINE शून्य __inbytestring(अचिन्हित लघु Port,अचिन्हित वर्ण *Buffer,अचिन्हित दीर्घ गिनती_3)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insb " 
		: "=D" (Buffer), "=c" (गिनती_3)
		: "d"(Port), "0"(Buffer), "1" (गिनती_3)
		);
  }
  __CRT_INLINE शून्य __inwordstring(अचिन्हित लघु Port,अचिन्हित लघु *Buffer,अचिन्हित दीर्घ गिनती_3)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insw " 
		: "=D" (Buffer), "=c" (गिनती_3)
		: "d"(Port), "0"(Buffer), "1" (गिनती_3)
		);
  }
  __CRT_INLINE शून्य __indwordstring(अचिन्हित लघु Port,अचिन्हित दीर्घ *Buffer,अचिन्हित दीर्घ गिनती_3)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insl " 
		: "=D" (Buffer), "=c" (गिनती_3)
		: "d"(Port), "0"(Buffer), "1" (गिनती_3)
		);
  }

  __CRT_INLINE शून्य __outbytestring(अचिन्हित लघु Port,अचिन्हित वर्ण *Buffer,अचिन्हित दीर्घ गिनती_3)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsb " 
          : "=S" (Buffer), "=c" (गिनती_3)
          : "d"(Port), "0"(Buffer), "1" (गिनती_3)
          );
  }
  __CRT_INLINE शून्य __outwordstring(अचिन्हित लघु Port,अचिन्हित लघु *Buffer,अचिन्हित दीर्घ गिनती_3)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsw " 
          : "=S" (Buffer), "=c" (गिनती_3)
          : "d"(Port), "0"(Buffer), "1" (गिनती_3)
          );
  }
  __CRT_INLINE शून्य __outdwordstring(अचिन्हित लघु Port,अचिन्हित दीर्घ *Buffer,अचिन्हित दीर्घ गिनती_3)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsl " 
          : "=S" (Buffer), "=c" (गिनती_3)
          : "d"(Port), "0"(Buffer), "1" (गिनती_3)
          );
  }

  __CRT_INLINE अचिन्हित __int64 __readcr0(शून्य)
  {
      अचिन्हित __int64 मूल्य;
      __asm__ __volatile__ (
          "mov %%cr0, %[value]" 
          : [मूल्य] "=q" (मूल्य));
      प्रत्यागम मूल्य;
  }
 
  /* Register sizes are different between 32/64 bit mode. So we have to do this for _WIN64 and _WIN32
     separately.  */
 
#ifdef _WIN64
  __CRT_INLINE शून्य __writecr0(अचिन्हित __int64 Data)
  {
   __asm__ __volatile__ (
       "mov %[Data], %%cr0"
       :
       : [Data] "q" (Data)
       : "memory");
  }
 
  __CRT_INLINE अचिन्हित __int64 __readcr2(शून्य)
  {
      अचिन्हित __int64 मूल्य;
      __asm__ __volatile__ (
          "mov %%cr2, %[value]" 
          : [मूल्य] "=q" (मूल्य));
      प्रत्यागम मूल्य;
  }

 __CRT_INLINE शून्य __writecr2(अचिन्हित __int64 Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr2"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE अचिन्हित __int64 __readcr3(शून्य)
  {
      अचिन्हित __int64 मूल्य;
      __asm__ __volatile__ (
          "mov %%cr3, %[value]" 
          : [मूल्य] "=q" (मूल्य));
      प्रत्यागम मूल्य;
  }

 __CRT_INLINE शून्य __writecr3(अचिन्हित __int64 Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr3"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE अचिन्हित __int64 __readcr4(शून्य)
  {
      अचिन्हित __int64 मूल्य;
      __asm__ __volatile__ (
          "mov %%cr4, %[value]" 
          : [मूल्य] "=q" (मूल्य));
      प्रत्यागम मूल्य;
  }

 __CRT_INLINE शून्य __writecr4(अचिन्हित __int64 Data)
 {
     __asm__ __volatile__ (
         "mov %[Data], %%cr4"
         :
         : [Data] "q" (Data)
         : "memory");
 }
 
  __CRT_INLINE अचिन्हित __int64 __readcr8(शून्य)
  {
      अचिन्हित __int64 मूल्य;
      __asm__ __volatile__ (
          "mov %%cr8, %[value]" 
          : [मूल्य] "=q" (मूल्य));
      प्रत्यागम मूल्य;
  }

 __CRT_INLINE शून्य __writecr8(अचिन्हित __int64 Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr8"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
#नोचेद्यदि defined(_WIN32)

  __CRT_INLINE शून्य __writecr0(अचिन्हित Data)
  {
    __asm__ __volatile__ (
       "mov %[Data], %%cr0"
       :
       : [Data] "q" (Data)
       : "memory");
  }
 
  __CRT_INLINE अचिन्हित दीर्घ __readcr2(शून्य)
  {
      अचिन्हित दीर्घ मूल्य;
      __asm__ __volatile__ (
          "mov %%cr2, %[value]" 
          : [मूल्य] "=q" (मूल्य));
      प्रत्यागम मूल्य;
  }

 __CRT_INLINE शून्य __writecr2(अचिन्हित Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr2"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE अचिन्हित दीर्घ __readcr3(शून्य)
  {
      अचिन्हित दीर्घ मूल्य;
      __asm__ __volatile__ (
          "mov %%cr3, %[value]" 
          : [मूल्य] "=q" (मूल्य));
      प्रत्यागम मूल्य;
  }

 __CRT_INLINE शून्य __writecr3(अचिन्हित Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr3"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE अचिन्हित दीर्घ __readcr4(शून्य)
  {
      अचिन्हित दीर्घ मूल्य;
      __asm__ __volatile__ (
          "mov %%cr4, %[value]" 
          : [मूल्य] "=q" (मूल्य));
      प्रत्यागम मूल्य;
  }

 __CRT_INLINE शून्य __writecr4(अचिन्हित Data)
 {
     __asm__ __volatile__ (
         "mov %[Data], %%cr4"
         :
         : [Data] "q" (Data)
         : "memory");
 }
 
 __CRT_INLINE अचिन्हित दीर्घ __readcr8(शून्य)
 {
   अचिन्हित दीर्घ मूल्य;      __asm__ __volatile__ (
          "mov %%cr8, %[value]" 
          : [मूल्य] "=q" (मूल्य));
     प्रत्यागम मूल्य;
 }

 __CRT_INLINE शून्य __writecr8(अचिन्हित Data)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr8"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
#endif

  __CRT_INLINE अचिन्हित __int64 __readmsr(अचिन्हित दीर्घ msr)
  {
      अचिन्हित __int64 val1, val2;
       __asm__ __volatile__(
           "rdmsr"
           : "=a" (val1), "=d" (val2)
           : "c" (msr));
      प्रत्यागम val1 | (val2 << 32);
  }

 __CRT_INLINE शून्य __writemsr (अचिन्हित दीर्घ msr, अचिन्हित __int64 मूल्य_3)
 {
    अचिन्हित दीर्घ val1 = मूल्य_3, val2 = मूल्य_3 >> 32;
   __asm__ __volatile__ (
       "wrmsr"
       :
       : "c" (msr), "a" (val1), "d" (val2));
 }
 
  __CRT_INLINE अचिन्हित __int64 __rdtsc(शून्य)
  {
      अचिन्हित __int64 val1, val2;
      __asm__ __volatile__ (
          "rdtsc" 
          : "=a" (val1), "=d" (val2));
      प्रत्यागम val1 | (val2 << 32);
  }

  __CRT_INLINE शून्य __cpuid(पूर्णाङ्क CPUInfo[4], पूर्णाङ्क InfoType)
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

#अन्तर्भाव <sec_api/conio_s.h>

#endif
