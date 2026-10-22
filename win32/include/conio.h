/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#अगर_अघोषित _INC_CONIO
#घोषणा _INC_CONIO

#समावेश <_mingw.h>

#अगर_घोषित __cplusplus
बाह्य "C" {
#पूर्ण_अगर

  _CRTIMP अक्षर *_cgets(अक्षर *बफर_2);
  _CRTIMP पूर्णांक __cdecl _cprintf(स्थिर अक्षर *_Format,...);
  _CRTIMP पूर्णांक __cdecl _cputs(स्थिर अक्षर *_Str);
  _CRTIMP पूर्णांक __cdecl _cscanf(स्थिर अक्षर *_Format,...);
  _CRTIMP पूर्णांक __cdecl _cscanf_l(स्थिर अक्षर *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _getch(व्योम);
  _CRTIMP पूर्णांक __cdecl _getche(व्योम);
  _CRTIMP पूर्णांक __cdecl _vcprintf(स्थिर अक्षर *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _cprintf_p(स्थिर अक्षर *_Format,...);
  _CRTIMP पूर्णांक __cdecl _vcprintf_p(स्थिर अक्षर *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _cprintf_l(स्थिर अक्षर *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _vcprintf_l(स्थिर अक्षर *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _cprintf_p_l(स्थिर अक्षर *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _vcprintf_p_l(स्थिर अक्षर *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _kbhit(व्योम);

#अगर defined(_X86_) && !defined(__x86_64)
  पूर्णांक __cdecl _inp(अचिन्हित लघु);
  अचिन्हित लघु __cdecl _inpw(अचिन्हित लघु);
  अचिन्हित दीर्घ __cdecl _inpd(अचिन्हित लघु);
  पूर्णांक __cdecl _outp(अचिन्हित लघु,पूर्णांक);
  अचिन्हित लघु __cdecl _outpw(अचिन्हित लघु,अचिन्हित लघु);
  अचिन्हित दीर्घ __cdecl _outpd(अचिन्हित लघु,अचिन्हित दीर्घ);
#पूर्ण_अगर

  _CRTIMP पूर्णांक __cdecl _putch(पूर्णांक _Ch);
  _CRTIMP पूर्णांक __cdecl _ungetch(पूर्णांक _Ch);
  _CRTIMP पूर्णांक __cdecl _getch_nolock(व्योम);
  _CRTIMP पूर्णांक __cdecl _getche_nolock(व्योम);
  _CRTIMP पूर्णांक __cdecl _putch_nolock(पूर्णांक _Ch);
  _CRTIMP पूर्णांक __cdecl _ungetch_nolock(पूर्णांक _Ch);

#अगर_अघोषित _WCONIO_DEFINED
#घोषणा _WCONIO_DEFINED

#अगर_अघोषित WEOF
#घोषणा WEOF (wint_t)(0xFFFF)
#पूर्ण_अगर

  _CRTIMP ब_अक्षर_प्रकार *_cgetws(ब_अक्षर_प्रकार *बफर_2);
  _CRTIMP wint_t __cdecl _getwch(व्योम);
  _CRTIMP wint_t __cdecl _getwche(व्योम);
  _CRTIMP wint_t __cdecl _putwch(ब_अक्षर_प्रकार _WCh);
  _CRTIMP wint_t __cdecl _ungetwch(wint_t _WCh);
  _CRTIMP पूर्णांक __cdecl _cputws(स्थिर ब_अक्षर_प्रकार *_String);
  _CRTIMP पूर्णांक __cdecl _cwprintf(स्थिर ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णांक __cdecl _cwscanf(स्थिर ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णांक __cdecl _cwscanf_l(स्थिर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _vcwprintf(स्थिर ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _cwprintf_p(स्थिर ब_अक्षर_प्रकार *_Format,...);
  _CRTIMP पूर्णांक __cdecl _vcwprintf_p(स्थिर ब_अक्षर_प्रकार *_Format,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _cwprintf_l(स्थिर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _vcwprintf_l(स्थिर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP पूर्णांक __cdecl _cwprintf_p_l(स्थिर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,...);
  _CRTIMP पूर्णांक __cdecl _vcwprintf_p_l(स्थिर ब_अक्षर_प्रकार *_Format,_locale_t _Locale,बहु_सूची _ArgList);
  _CRTIMP wint_t __cdecl _putwch_nolock(ब_अक्षर_प्रकार _WCh);
  _CRTIMP wint_t __cdecl _getwch_nolock(व्योम);
  _CRTIMP wint_t __cdecl _getwche_nolock(व्योम);
  _CRTIMP wint_t __cdecl _ungetwch_nolock(wint_t _WCh);
#पूर्ण_अगर

#अगर_अघोषित	NO_OLDNAMES
  अक्षर *__cdecl cgets(अक्षर *बफर_2);
  पूर्णांक __cdecl cprintf(स्थिर अक्षर *_Format,...);
  पूर्णांक __cdecl cputs(स्थिर अक्षर *_Str);
  पूर्णांक __cdecl cscanf(स्थिर अक्षर *_Format,...);
  पूर्णांक __cdecl getch(व्योम);
  पूर्णांक __cdecl getche(व्योम);
  पूर्णांक __cdecl kbhit(व्योम);
  पूर्णांक __cdecl putch(पूर्णांक _Ch);
  पूर्णांक __cdecl ungetch(पूर्णांक _Ch);

#अगर (defined(_X86_) && !defined(__x86_64))
  पूर्णांक __cdecl inp(अचिन्हित लघु);
  अचिन्हित लघु __cdecl inpw(अचिन्हित लघु);
  पूर्णांक __cdecl outp(अचिन्हित लघु,पूर्णांक);
  अचिन्हित लघु __cdecl outpw(अचिन्हित लघु,अचिन्हित लघु);
#पूर्ण_अगर

  /* I/O intrin functions.  */
  __CRT_INLINE अचिन्हित अक्षर __inbyte(अचिन्हित लघु Port)
  {
      अचिन्हित अक्षर मूल्य;
      __asm__ __volatile__ ("inb %w1,%b0"
          : "=a" (मूल्य)
          : "Nd" (Port));
      वापस मूल्य;
  }
  __CRT_INLINE अचिन्हित लघु __inword(अचिन्हित लघु Port)
  {
      अचिन्हित लघु मूल्य;
      __asm__ __volatile__ ("inw %w1,%w0"
          : "=a" (मूल्य)
          : "Nd" (Port));
      वापस मूल्य;
  }
  __CRT_INLINE अचिन्हित दीर्घ __indword(अचिन्हित लघु Port)
  {
      अचिन्हित दीर्घ मूल्य;
      __asm__ __volatile__ ("inl %w1,%0"
          : "=a" (मूल्य)
          : "Nd" (Port));
      वापस मूल्य;
  }
  __CRT_INLINE व्योम __outbyte(अचिन्हित लघु Port,अचिन्हित अक्षर तथ्य_3)
  {
      __asm__ __volatile__ ("outb %b0,%w1"
          :
          : "a" (तथ्य_3), "Nd" (Port));
  }
  __CRT_INLINE व्योम __outword(अचिन्हित लघु Port,अचिन्हित लघु तथ्य_3)
  {
      __asm__ __volatile__ ("outw %w0,%w1"
          :
          : "a" (तथ्य_3), "Nd" (Port));
  }
  __CRT_INLINE व्योम __outdword(अचिन्हित लघु Port,अचिन्हित दीर्घ तथ्य_3)
  {
      __asm__ __volatile__ ("outl %0,%w1"
          :
          : "a" (तथ्य_3), "Nd" (Port));
  }
  __CRT_INLINE व्योम __inbytestring(अचिन्हित लघु Port,अचिन्हित अक्षर *बफर_3,अचिन्हित दीर्घ गिनती_3)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insb " 
		: "=D" (बफर_3), "=c" (गिनती_3)
		: "d"(Port), "0"(बफर_3), "1" (गिनती_3)
		);
  }
  __CRT_INLINE व्योम __inwordstring(अचिन्हित लघु Port,अचिन्हित लघु *बफर_3,अचिन्हित दीर्घ गिनती_3)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insw " 
		: "=D" (बफर_3), "=c" (गिनती_3)
		: "d"(Port), "0"(बफर_3), "1" (गिनती_3)
		);
  }
  __CRT_INLINE व्योम __indwordstring(अचिन्हित लघु Port,अचिन्हित दीर्घ *बफर_3,अचिन्हित दीर्घ गिनती_3)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insl " 
		: "=D" (बफर_3), "=c" (गिनती_3)
		: "d"(Port), "0"(बफर_3), "1" (गिनती_3)
		);
  }

  __CRT_INLINE व्योम __outbytestring(अचिन्हित लघु Port,अचिन्हित अक्षर *बफर_3,अचिन्हित दीर्घ गिनती_3)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsb " 
          : "=S" (बफर_3), "=c" (गिनती_3)
          : "d"(Port), "0"(बफर_3), "1" (गिनती_3)
          );
  }
  __CRT_INLINE व्योम __outwordstring(अचिन्हित लघु Port,अचिन्हित लघु *बफर_3,अचिन्हित दीर्घ गिनती_3)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsw " 
          : "=S" (बफर_3), "=c" (गिनती_3)
          : "d"(Port), "0"(बफर_3), "1" (गिनती_3)
          );
  }
  __CRT_INLINE व्योम __outdwordstring(अचिन्हित लघु Port,अचिन्हित दीर्घ *बफर_3,अचिन्हित दीर्घ गिनती_3)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsl " 
          : "=S" (बफर_3), "=c" (गिनती_3)
          : "d"(Port), "0"(बफर_3), "1" (गिनती_3)
          );
  }

  __CRT_INLINE अचिन्हित __int64 __readcr0(व्योम)
  {
      अचिन्हित __int64 मूल्य;
      __asm__ __volatile__ (
          "mov %%cr0, %[value]" 
          : [मूल्य] "=q" (मूल्य));
      वापस मूल्य;
  }
 
  /* Register sizes are different between 32/64 bit mode. So we have to do this for _WIN64 and _WIN32
     separately.  */
 
#अगर_घोषित _WIN64
  __CRT_INLINE व्योम __writecr0(अचिन्हित __int64 तथ्य_3)
  {
   __asm__ __volatile__ (
       "mov %[Data], %%cr0"
       :
       : [तथ्य_3] "q" (तथ्य_3)
       : "memory");
  }
 
  __CRT_INLINE अचिन्हित __int64 __readcr2(व्योम)
  {
      अचिन्हित __int64 मूल्य;
      __asm__ __volatile__ (
          "mov %%cr2, %[value]" 
          : [मूल्य] "=q" (मूल्य));
      वापस मूल्य;
  }

 __CRT_INLINE व्योम __writecr2(अचिन्हित __int64 तथ्य_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr2"
       :
       : [तथ्य_3] "q" (तथ्य_3)
       : "memory");
 }
 
  __CRT_INLINE अचिन्हित __int64 __readcr3(व्योम)
  {
      अचिन्हित __int64 मूल्य;
      __asm__ __volatile__ (
          "mov %%cr3, %[value]" 
          : [मूल्य] "=q" (मूल्य));
      वापस मूल्य;
  }

 __CRT_INLINE व्योम __writecr3(अचिन्हित __int64 तथ्य_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr3"
       :
       : [तथ्य_3] "q" (तथ्य_3)
       : "memory");
 }
 
  __CRT_INLINE अचिन्हित __int64 __readcr4(व्योम)
  {
      अचिन्हित __int64 मूल्य;
      __asm__ __volatile__ (
          "mov %%cr4, %[value]" 
          : [मूल्य] "=q" (मूल्य));
      वापस मूल्य;
  }

 __CRT_INLINE व्योम __writecr4(अचिन्हित __int64 तथ्य_3)
 {
     __asm__ __volatile__ (
         "mov %[Data], %%cr4"
         :
         : [तथ्य_3] "q" (तथ्य_3)
         : "memory");
 }
 
  __CRT_INLINE अचिन्हित __int64 __readcr8(व्योम)
  {
      अचिन्हित __int64 मूल्य;
      __asm__ __volatile__ (
          "mov %%cr8, %[value]" 
          : [मूल्य] "=q" (मूल्य));
      वापस मूल्य;
  }

 __CRT_INLINE व्योम __writecr8(अचिन्हित __int64 तथ्य_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr8"
       :
       : [तथ्य_3] "q" (तथ्य_3)
       : "memory");
 }
 
#या_अगर defined(_WIN32)

  __CRT_INLINE व्योम __writecr0(अचिन्हित तथ्य_3)
  {
    __asm__ __volatile__ (
       "mov %[Data], %%cr0"
       :
       : [तथ्य_3] "q" (तथ्य_3)
       : "memory");
  }
 
  __CRT_INLINE अचिन्हित दीर्घ __readcr2(व्योम)
  {
      अचिन्हित दीर्घ मूल्य;
      __asm__ __volatile__ (
          "mov %%cr2, %[value]" 
          : [मूल्य] "=q" (मूल्य));
      वापस मूल्य;
  }

 __CRT_INLINE व्योम __writecr2(अचिन्हित तथ्य_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr2"
       :
       : [तथ्य_3] "q" (तथ्य_3)
       : "memory");
 }
 
  __CRT_INLINE अचिन्हित दीर्घ __readcr3(व्योम)
  {
      अचिन्हित दीर्घ मूल्य;
      __asm__ __volatile__ (
          "mov %%cr3, %[value]" 
          : [मूल्य] "=q" (मूल्य));
      वापस मूल्य;
  }

 __CRT_INLINE व्योम __writecr3(अचिन्हित तथ्य_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr3"
       :
       : [तथ्य_3] "q" (तथ्य_3)
       : "memory");
 }
 
  __CRT_INLINE अचिन्हित दीर्घ __readcr4(व्योम)
  {
      अचिन्हित दीर्घ मूल्य;
      __asm__ __volatile__ (
          "mov %%cr4, %[value]" 
          : [मूल्य] "=q" (मूल्य));
      वापस मूल्य;
  }

 __CRT_INLINE व्योम __writecr4(अचिन्हित तथ्य_3)
 {
     __asm__ __volatile__ (
         "mov %[Data], %%cr4"
         :
         : [तथ्य_3] "q" (तथ्य_3)
         : "memory");
 }
 
 __CRT_INLINE अचिन्हित दीर्घ __readcr8(व्योम)
 {
   अचिन्हित दीर्घ मूल्य;      __asm__ __volatile__ (
          "mov %%cr8, %[value]" 
          : [मूल्य] "=q" (मूल्य));
     वापस मूल्य;
 }

 __CRT_INLINE व्योम __writecr8(अचिन्हित तथ्य_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr8"
       :
       : [तथ्य_3] "q" (तथ्य_3)
       : "memory");
 }
 
#पूर्ण_अगर

  __CRT_INLINE अचिन्हित __int64 __readmsr(अचिन्हित दीर्घ msr)
  {
      अचिन्हित __int64 val1, val2;
       __asm__ __volatile__(
           "rdmsr"
           : "=a" (val1), "=d" (val2)
           : "c" (msr));
      वापस val1 | (val2 << 32);
  }

 __CRT_INLINE व्योम __writemsr (अचिन्हित दीर्घ msr, अचिन्हित __int64 मूल्य_3)
 {
    अचिन्हित दीर्घ val1 = मूल्य_3, val2 = मूल्य_3 >> 32;
   __asm__ __volatile__ (
       "wrmsr"
       :
       : "c" (msr), "a" (val1), "d" (val2));
 }
 
  __CRT_INLINE अचिन्हित __int64 __rdtsc(व्योम)
  {
      अचिन्हित __int64 val1, val2;
      __asm__ __volatile__ (
          "rdtsc" 
          : "=a" (val1), "=d" (val2));
      वापस val1 | (val2 << 32);
  }

  __CRT_INLINE व्योम __cpuid(पूर्णांक CPUInfo[4], पूर्णांक InfoType)
  {
      __asm__ __volatile__ (
          "cpuid"
          : "=a" (CPUInfo [0]), "=b" (CPUInfo [1]), "=c" (CPUInfo [2]), "=d" (CPUInfo [3])
          : "a" (InfoType));
  }

#पूर्ण_अगर

#अगर_घोषित __cplusplus
}
#पूर्ण_अगर

#समावेश <sec_api/conio_s.h>

#पूर्ण_अगर
