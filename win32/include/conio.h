/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _INC_CONIO
#ವ್ಯಾಖ್ಯಾನಿಸು _INC_CONIO

#ಅನ್ತರ್ಭಾವ <_mingw.h>

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
ಬಾಹ್ಯ "C" {
#ಆದರೆ_ಅಂತ್ಯ

  _CRTIMP ಅಕ್ಷರ *_cgets(ಅಕ್ಷರ *ಬಫರ್_2);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _cprintf(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _cputs(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Str);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _cscanf(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _cscanf_l(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _getch(ಶೂನ್ಯ);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _getche(ಶೂನ್ಯ);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vcprintf(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _cprintf_p(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vcprintf_p(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _cprintf_l(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vcprintf_l(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _cprintf_p_l(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vcprintf_p_l(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _kbhit(ಶೂನ್ಯ);

#ಆದರೆ defined(_X86_) && !defined(__x86_64)
  ಪೂರ್ಣಾಂಕ __cdecl _inp(ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ);
  ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ __cdecl _inpw(ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ);
  ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ __cdecl _inpd(ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ);
  ಪೂರ್ಣಾಂಕ __cdecl _outp(ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ,ಪೂರ್ಣಾಂಕ);
  ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ __cdecl _outpw(ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ,ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ);
  ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ __cdecl _outpd(ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ,ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ);
#ಆದರೆ_ಅಂತ್ಯ

  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _putch(ಪೂರ್ಣಾಂಕ _Ch);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _ungetch(ಪೂರ್ಣಾಂಕ _Ch);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _getch_nolock(ಶೂನ್ಯ);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _getche_nolock(ಶೂನ್ಯ);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _putch_nolock(ಪೂರ್ಣಾಂಕ _Ch);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _ungetch_nolock(ಪೂರ್ಣಾಂಕ _Ch);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WCONIO_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _WCONIO_DEFINED

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ WEOF
#ವ್ಯಾಖ್ಯಾನಿಸು WEOF (wint_t)(0xFFFF)
#ಆದರೆ_ಅಂತ್ಯ

  _CRTIMP wchar_t *_cgetws(wchar_t *ಬಫರ್_2);
  _CRTIMP wint_t __cdecl _getwch(ಶೂನ್ಯ);
  _CRTIMP wint_t __cdecl _getwche(ಶೂನ್ಯ);
  _CRTIMP wint_t __cdecl _putwch(wchar_t _WCh);
  _CRTIMP wint_t __cdecl _ungetwch(wint_t _WCh);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _cputws(ಸ್ಥಿರಾಂಕ wchar_t *_String);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _cwprintf(ಸ್ಥಿರಾಂಕ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _cwscanf(ಸ್ಥಿರಾಂಕ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _cwscanf_l(ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vcwprintf(ಸ್ಥಿರಾಂಕ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _cwprintf_p(ಸ್ಥಿರಾಂಕ wchar_t *_Format,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vcwprintf_p(ಸ್ಥಿರಾಂಕ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _cwprintf_l(ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vcwprintf_l(ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _cwprintf_p_l(ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _vcwprintf_p_l(ಸ್ಥಿರಾಂಕ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP wint_t __cdecl _putwch_nolock(wchar_t _WCh);
  _CRTIMP wint_t __cdecl _getwch_nolock(ಶೂನ್ಯ);
  _CRTIMP wint_t __cdecl _getwche_nolock(ಶೂನ್ಯ);
  _CRTIMP wint_t __cdecl _ungetwch_nolock(wint_t _WCh);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ	NO_OLDNAMES
  ಅಕ್ಷರ *__cdecl cgets(ಅಕ್ಷರ *ಬಫರ್_2);
  ಪೂರ್ಣಾಂಕ __cdecl cprintf(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,...);
  ಪೂರ್ಣಾಂಕ __cdecl cputs(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Str);
  ಪೂರ್ಣಾಂಕ __cdecl cscanf(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Format,...);
  ಪೂರ್ಣಾಂಕ __cdecl getch(ಶೂನ್ಯ);
  ಪೂರ್ಣಾಂಕ __cdecl getche(ಶೂನ್ಯ);
  ಪೂರ್ಣಾಂಕ __cdecl kbhit(ಶೂನ್ಯ);
  ಪೂರ್ಣಾಂಕ __cdecl putch(ಪೂರ್ಣಾಂಕ _Ch);
  ಪೂರ್ಣಾಂಕ __cdecl ungetch(ಪೂರ್ಣಾಂಕ _Ch);

#ಆದರೆ (defined(_X86_) && !defined(__x86_64))
  ಪೂರ್ಣಾಂಕ __cdecl inp(ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ);
  ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ __cdecl inpw(ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ);
  ಪೂರ್ಣಾಂಕ __cdecl outp(ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ,ಪೂರ್ಣಾಂಕ);
  ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ __cdecl outpw(ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ,ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ);
#ಆದರೆ_ಅಂತ್ಯ

  /* I/O intrin functions.  */
  __CRT_INLINE ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ __inbyte(ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ ಪೋರ್ಟ್)
  {
      ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ ಮೌಲ್ಯ;
      __asm__ __volatile__ ("inb %w1,%b0"
          : "=a" (ಮೌಲ್ಯ)
          : "Nd" (ಪೋರ್ಟ್));
      ಹಿಂತಿರುಗಿ ಮೌಲ್ಯ;
  }
  __CRT_INLINE ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ __inword(ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ ಪೋರ್ಟ್)
  {
      ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ ಮೌಲ್ಯ;
      __asm__ __volatile__ ("inw %w1,%w0"
          : "=a" (ಮೌಲ್ಯ)
          : "Nd" (ಪೋರ್ಟ್));
      ಹಿಂತಿರುಗಿ ಮೌಲ್ಯ;
  }
  __CRT_INLINE ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ __indword(ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ ಪೋರ್ಟ್)
  {
      ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಮೌಲ್ಯ;
      __asm__ __volatile__ ("inl %w1,%0"
          : "=a" (ಮೌಲ್ಯ)
          : "Nd" (ಪೋರ್ಟ್));
      ಹಿಂತಿರುಗಿ ಮೌಲ್ಯ;
  }
  __CRT_INLINE ಶೂನ್ಯ __outbyte(ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ ಪೋರ್ಟ್,ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ ದತ್ತಾಂಶ_3)
  {
      __asm__ __volatile__ ("outb %b0,%w1"
          :
          : "a" (ದತ್ತಾಂಶ_3), "Nd" (ಪೋರ್ಟ್));
  }
  __CRT_INLINE ಶೂನ್ಯ __outword(ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ ಪೋರ್ಟ್,ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ ದತ್ತಾಂಶ_3)
  {
      __asm__ __volatile__ ("outw %w0,%w1"
          :
          : "a" (ದತ್ತಾಂಶ_3), "Nd" (ಪೋರ್ಟ್));
  }
  __CRT_INLINE ಶೂನ್ಯ __outdword(ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ ಪೋರ್ಟ್,ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದತ್ತಾಂಶ_3)
  {
      __asm__ __volatile__ ("outl %0,%w1"
          :
          : "a" (ದತ್ತಾಂಶ_3), "Nd" (ಪೋರ್ಟ್));
  }
  __CRT_INLINE ಶೂನ್ಯ __inbytestring(ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ ಪೋರ್ಟ್,ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *ಬಫರ್_3,ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಎಣಿಕೆ_4)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insb " 
		: "=D" (ಬಫರ್_3), "=c" (ಎಣಿಕೆ_4)
		: "d"(ಪೋರ್ಟ್), "0"(ಬಫರ್_3), "1" (ಎಣಿಕೆ_4)
		);
  }
  __CRT_INLINE ಶೂನ್ಯ __inwordstring(ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ ಪೋರ್ಟ್,ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ *ಬಫರ್_3,ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಎಣಿಕೆ_4)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insw " 
		: "=D" (ಬಫರ್_3), "=c" (ಎಣಿಕೆ_4)
		: "d"(ಪೋರ್ಟ್), "0"(ಬಫರ್_3), "1" (ಎಣಿಕೆ_4)
		);
  }
  __CRT_INLINE ಶೂನ್ಯ __indwordstring(ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ ಪೋರ್ಟ್,ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ *ಬಫರ್_3,ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಎಣಿಕೆ_4)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insl " 
		: "=D" (ಬಫರ್_3), "=c" (ಎಣಿಕೆ_4)
		: "d"(ಪೋರ್ಟ್), "0"(ಬಫರ್_3), "1" (ಎಣಿಕೆ_4)
		);
  }

  __CRT_INLINE ಶೂನ್ಯ __outbytestring(ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ ಪೋರ್ಟ್,ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *ಬಫರ್_3,ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಎಣಿಕೆ_4)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsb " 
          : "=S" (ಬಫರ್_3), "=c" (ಎಣಿಕೆ_4)
          : "d"(ಪೋರ್ಟ್), "0"(ಬಫರ್_3), "1" (ಎಣಿಕೆ_4)
          );
  }
  __CRT_INLINE ಶೂನ್ಯ __outwordstring(ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ ಪೋರ್ಟ್,ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ *ಬಫರ್_3,ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಎಣಿಕೆ_4)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsw " 
          : "=S" (ಬಫರ್_3), "=c" (ಎಣಿಕೆ_4)
          : "d"(ಪೋರ್ಟ್), "0"(ಬಫರ್_3), "1" (ಎಣಿಕೆ_4)
          );
  }
  __CRT_INLINE ಶೂನ್ಯ __outdwordstring(ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ ಪೋರ್ಟ್,ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ *ಬಫರ್_3,ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಎಣಿಕೆ_4)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsl " 
          : "=S" (ಬಫರ್_3), "=c" (ಎಣಿಕೆ_4)
          : "d"(ಪೋರ್ಟ್), "0"(ಬಫರ್_3), "1" (ಎಣಿಕೆ_4)
          );
  }

  __CRT_INLINE ಚಿಹ್ನೆರಹಿತ __int64 __readcr0(ಶೂನ್ಯ)
  {
      ಚಿಹ್ನೆರಹಿತ __int64 ಮೌಲ್ಯ;
      __asm__ __volatile__ (
          "mov %%cr0, %[value]" 
          : [ಮೌಲ್ಯ] "=q" (ಮೌಲ್ಯ));
      ಹಿಂತಿರುಗಿ ಮೌಲ್ಯ;
  }
 
  /* Register sizes are different between 32/64 bit mode. So we have to do this for _WIN64 and _WIN32
     separately.  */
 
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN64
  __CRT_INLINE ಶೂನ್ಯ __writecr0(ಚಿಹ್ನೆರಹಿತ __int64 ದತ್ತಾಂಶ_3)
  {
   __asm__ __volatile__ (
       "mov %[Data], %%cr0"
       :
       : [ದತ್ತಾಂಶ_3] "q" (ದತ್ತಾಂಶ_3)
       : "memory");
  }
 
  __CRT_INLINE ಚಿಹ್ನೆರಹಿತ __int64 __readcr2(ಶೂನ್ಯ)
  {
      ಚಿಹ್ನೆರಹಿತ __int64 ಮೌಲ್ಯ;
      __asm__ __volatile__ (
          "mov %%cr2, %[value]" 
          : [ಮೌಲ್ಯ] "=q" (ಮೌಲ್ಯ));
      ಹಿಂತಿರುಗಿ ಮೌಲ್ಯ;
  }

 __CRT_INLINE ಶೂನ್ಯ __writecr2(ಚಿಹ್ನೆರಹಿತ __int64 ದತ್ತಾಂಶ_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr2"
       :
       : [ದತ್ತಾಂಶ_3] "q" (ದತ್ತಾಂಶ_3)
       : "memory");
 }
 
  __CRT_INLINE ಚಿಹ್ನೆರಹಿತ __int64 __readcr3(ಶೂನ್ಯ)
  {
      ಚಿಹ್ನೆರಹಿತ __int64 ಮೌಲ್ಯ;
      __asm__ __volatile__ (
          "mov %%cr3, %[value]" 
          : [ಮೌಲ್ಯ] "=q" (ಮೌಲ್ಯ));
      ಹಿಂತಿರುಗಿ ಮೌಲ್ಯ;
  }

 __CRT_INLINE ಶೂನ್ಯ __writecr3(ಚಿಹ್ನೆರಹಿತ __int64 ದತ್ತಾಂಶ_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr3"
       :
       : [ದತ್ತಾಂಶ_3] "q" (ದತ್ತಾಂಶ_3)
       : "memory");
 }
 
  __CRT_INLINE ಚಿಹ್ನೆರಹಿತ __int64 __readcr4(ಶೂನ್ಯ)
  {
      ಚಿಹ್ನೆರಹಿತ __int64 ಮೌಲ್ಯ;
      __asm__ __volatile__ (
          "mov %%cr4, %[value]" 
          : [ಮೌಲ್ಯ] "=q" (ಮೌಲ್ಯ));
      ಹಿಂತಿರುಗಿ ಮೌಲ್ಯ;
  }

 __CRT_INLINE ಶೂನ್ಯ __writecr4(ಚಿಹ್ನೆರಹಿತ __int64 ದತ್ತಾಂಶ_3)
 {
     __asm__ __volatile__ (
         "mov %[Data], %%cr4"
         :
         : [ದತ್ತಾಂಶ_3] "q" (ದತ್ತಾಂಶ_3)
         : "memory");
 }
 
  __CRT_INLINE ಚಿಹ್ನೆರಹಿತ __int64 __readcr8(ಶೂನ್ಯ)
  {
      ಚಿಹ್ನೆರಹಿತ __int64 ಮೌಲ್ಯ;
      __asm__ __volatile__ (
          "mov %%cr8, %[value]" 
          : [ಮೌಲ್ಯ] "=q" (ಮೌಲ್ಯ));
      ಹಿಂತಿರುಗಿ ಮೌಲ್ಯ;
  }

 __CRT_INLINE ಶೂನ್ಯ __writecr8(ಚಿಹ್ನೆರಹಿತ __int64 ದತ್ತಾಂಶ_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr8"
       :
       : [ದತ್ತಾಂಶ_3] "q" (ದತ್ತಾಂಶ_3)
       : "memory");
 }
 
#ಅಥವಾಆದರೆ defined(_WIN32)

  __CRT_INLINE ಶೂನ್ಯ __writecr0(ಚಿಹ್ನೆರಹಿತ ದತ್ತಾಂಶ_3)
  {
    __asm__ __volatile__ (
       "mov %[Data], %%cr0"
       :
       : [ದತ್ತಾಂಶ_3] "q" (ದತ್ತಾಂಶ_3)
       : "memory");
  }
 
  __CRT_INLINE ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ __readcr2(ಶೂನ್ಯ)
  {
      ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಮೌಲ್ಯ;
      __asm__ __volatile__ (
          "mov %%cr2, %[value]" 
          : [ಮೌಲ್ಯ] "=q" (ಮೌಲ್ಯ));
      ಹಿಂತಿರುಗಿ ಮೌಲ್ಯ;
  }

 __CRT_INLINE ಶೂನ್ಯ __writecr2(ಚಿಹ್ನೆರಹಿತ ದತ್ತಾಂಶ_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr2"
       :
       : [ದತ್ತಾಂಶ_3] "q" (ದತ್ತಾಂಶ_3)
       : "memory");
 }
 
  __CRT_INLINE ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ __readcr3(ಶೂನ್ಯ)
  {
      ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಮೌಲ್ಯ;
      __asm__ __volatile__ (
          "mov %%cr3, %[value]" 
          : [ಮೌಲ್ಯ] "=q" (ಮೌಲ್ಯ));
      ಹಿಂತಿರುಗಿ ಮೌಲ್ಯ;
  }

 __CRT_INLINE ಶೂನ್ಯ __writecr3(ಚಿಹ್ನೆರಹಿತ ದತ್ತಾಂಶ_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr3"
       :
       : [ದತ್ತಾಂಶ_3] "q" (ದತ್ತಾಂಶ_3)
       : "memory");
 }
 
  __CRT_INLINE ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ __readcr4(ಶೂನ್ಯ)
  {
      ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಮೌಲ್ಯ;
      __asm__ __volatile__ (
          "mov %%cr4, %[value]" 
          : [ಮೌಲ್ಯ] "=q" (ಮೌಲ್ಯ));
      ಹಿಂತಿರುಗಿ ಮೌಲ್ಯ;
  }

 __CRT_INLINE ಶೂನ್ಯ __writecr4(ಚಿಹ್ನೆರಹಿತ ದತ್ತಾಂಶ_3)
 {
     __asm__ __volatile__ (
         "mov %[Data], %%cr4"
         :
         : [ದತ್ತಾಂಶ_3] "q" (ದತ್ತಾಂಶ_3)
         : "memory");
 }
 
 __CRT_INLINE ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ __readcr8(ಶೂನ್ಯ)
 {
   ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಮೌಲ್ಯ;      __asm__ __volatile__ (
          "mov %%cr8, %[value]" 
          : [ಮೌಲ್ಯ] "=q" (ಮೌಲ್ಯ));
     ಹಿಂತಿರುಗಿ ಮೌಲ್ಯ;
 }

 __CRT_INLINE ಶೂನ್ಯ __writecr8(ಚಿಹ್ನೆರಹಿತ ದತ್ತಾಂಶ_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr8"
       :
       : [ದತ್ತಾಂಶ_3] "q" (ದತ್ತಾಂಶ_3)
       : "memory");
 }
 
#ಆದರೆ_ಅಂತ್ಯ

  __CRT_INLINE ಚಿಹ್ನೆರಹಿತ __int64 __readmsr(ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ msr)
  {
      ಚಿಹ್ನೆರಹಿತ __int64 val1, val2;
       __asm__ __volatile__(
           "rdmsr"
           : "=a" (val1), "=d" (val2)
           : "c" (msr));
      ಹಿಂತಿರುಗಿ val1 | (val2 << 32);
  }

 __CRT_INLINE ಶೂನ್ಯ __writemsr (ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ msr, ಚಿಹ್ನೆರಹಿತ __int64 ಮೌಲ್ಯ_3)
 {
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ val1 = ಮೌಲ್ಯ_3, val2 = ಮೌಲ್ಯ_3 >> 32;
   __asm__ __volatile__ (
       "wrmsr"
       :
       : "c" (msr), "a" (val1), "d" (val2));
 }
 
  __CRT_INLINE ಚಿಹ್ನೆರಹಿತ __int64 __rdtsc(ಶೂನ್ಯ)
  {
      ಚಿಹ್ನೆರಹಿತ __int64 val1, val2;
      __asm__ __volatile__ (
          "rdtsc" 
          : "=a" (val1), "=d" (val2));
      ಹಿಂತಿರುಗಿ val1 | (val2 << 32);
  }

  __CRT_INLINE ಶೂನ್ಯ __cpuid(ಪೂರ್ಣಾಂಕ CPUInfo[4], ಪೂರ್ಣಾಂಕ InfoType)
  {
      __asm__ __volatile__ (
          "cpuid"
          : "=a" (CPUInfo [0]), "=b" (CPUInfo [1]), "=c" (CPUInfo [2]), "=d" (CPUInfo [3])
          : "a" (InfoType));
  }

#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
}
#ಆದರೆ_ಅಂತ್ಯ

#ಅನ್ತರ್ಭಾವ <sec_api/conio_s.h>

#ಆದರೆ_ಅಂತ್ಯ
