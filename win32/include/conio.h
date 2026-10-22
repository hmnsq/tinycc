/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _INC_CONIO
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _INC_CONIO

#ਅਨ੍ਤਰ੍ਭਾਵ <_mingw.h>

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
ਬਾਹਰੀ "C" {
#ਜੇ_ਅੰਤ

  _CRTIMP ਅੱਖਰ *_cgets(ਅੱਖਰ *ਬਫਰ_2);
  _CRTIMP ਪੂਰਨ __cdecl _cprintf(ਅਚਲ ਅੱਖਰ *_Format,...);
  _CRTIMP ਪੂਰਨ __cdecl _cputs(ਅਚਲ ਅੱਖਰ *_Str);
  _CRTIMP ਪੂਰਨ __cdecl _cscanf(ਅਚਲ ਅੱਖਰ *_Format,...);
  _CRTIMP ਪੂਰਨ __cdecl _cscanf_l(ਅਚਲ ਅੱਖਰ *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _getch(ਖਾਲੀ);
  _CRTIMP ਪੂਰਨ __cdecl _getche(ਖਾਲੀ);
  _CRTIMP ਪੂਰਨ __cdecl _vcprintf(ਅਚਲ ਅੱਖਰ *_Format,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _cprintf_p(ਅਚਲ ਅੱਖਰ *_Format,...);
  _CRTIMP ਪੂਰਨ __cdecl _vcprintf_p(ਅਚਲ ਅੱਖਰ *_Format,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _cprintf_l(ਅਚਲ ਅੱਖਰ *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _vcprintf_l(ਅਚਲ ਅੱਖਰ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _cprintf_p_l(ਅਚਲ ਅੱਖਰ *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _vcprintf_p_l(ਅਚਲ ਅੱਖਰ *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _kbhit(ਖਾਲੀ);

#ਜੇ defined(_X86_) && !defined(__x86_64)
  ਪੂਰਨ __cdecl _inp(ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ);
  ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ __cdecl _inpw(ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ);
  ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ __cdecl _inpd(ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ);
  ਪੂਰਨ __cdecl _outp(ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ,ਪੂਰਨ);
  ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ __cdecl _outpw(ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ,ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ);
  ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ __cdecl _outpd(ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ,ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ);
#ਜੇ_ਅੰਤ

  _CRTIMP ਪੂਰਨ __cdecl _putch(ਪੂਰਨ _Ch);
  _CRTIMP ਪੂਰਨ __cdecl _ungetch(ਪੂਰਨ _Ch);
  _CRTIMP ਪੂਰਨ __cdecl _getch_nolock(ਖਾਲੀ);
  _CRTIMP ਪੂਰਨ __cdecl _getche_nolock(ਖਾਲੀ);
  _CRTIMP ਪੂਰਨ __cdecl _putch_nolock(ਪੂਰਨ _Ch);
  _CRTIMP ਪੂਰਨ __cdecl _ungetch_nolock(ਪੂਰਨ _Ch);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WCONIO_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WCONIO_DEFINED

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ WEOF
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WEOF (wint_t)(0xFFFF)
#ਜੇ_ਅੰਤ

  _CRTIMP wchar_t *_cgetws(wchar_t *ਬਫਰ_2);
  _CRTIMP wint_t __cdecl _getwch(ਖਾਲੀ);
  _CRTIMP wint_t __cdecl _getwche(ਖਾਲੀ);
  _CRTIMP wint_t __cdecl _putwch(wchar_t _WCh);
  _CRTIMP wint_t __cdecl _ungetwch(wint_t _WCh);
  _CRTIMP ਪੂਰਨ __cdecl _cputws(ਅਚਲ wchar_t *_String);
  _CRTIMP ਪੂਰਨ __cdecl _cwprintf(ਅਚਲ wchar_t *_Format,...);
  _CRTIMP ਪੂਰਨ __cdecl _cwscanf(ਅਚਲ wchar_t *_Format,...);
  _CRTIMP ਪੂਰਨ __cdecl _cwscanf_l(ਅਚਲ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _vcwprintf(ਅਚਲ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _cwprintf_p(ਅਚਲ wchar_t *_Format,...);
  _CRTIMP ਪੂਰਨ __cdecl _vcwprintf_p(ਅਚਲ wchar_t *_Format,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _cwprintf_l(ਅਚਲ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _vcwprintf_l(ਅਚਲ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP ਪੂਰਨ __cdecl _cwprintf_p_l(ਅਚਲ wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP ਪੂਰਨ __cdecl _vcwprintf_p_l(ਅਚਲ wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP wint_t __cdecl _putwch_nolock(wchar_t _WCh);
  _CRTIMP wint_t __cdecl _getwch_nolock(ਖਾਲੀ);
  _CRTIMP wint_t __cdecl _getwche_nolock(ਖਾਲੀ);
  _CRTIMP wint_t __cdecl _ungetwch_nolock(wint_t _WCh);
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ	NO_OLDNAMES
  ਅੱਖਰ *__cdecl cgets(ਅੱਖਰ *ਬਫਰ_2);
  ਪੂਰਨ __cdecl cprintf(ਅਚਲ ਅੱਖਰ *_Format,...);
  ਪੂਰਨ __cdecl cputs(ਅਚਲ ਅੱਖਰ *_Str);
  ਪੂਰਨ __cdecl cscanf(ਅਚਲ ਅੱਖਰ *_Format,...);
  ਪੂਰਨ __cdecl getch(ਖਾਲੀ);
  ਪੂਰਨ __cdecl getche(ਖਾਲੀ);
  ਪੂਰਨ __cdecl kbhit(ਖਾਲੀ);
  ਪੂਰਨ __cdecl putch(ਪੂਰਨ _Ch);
  ਪੂਰਨ __cdecl ungetch(ਪੂਰਨ _Ch);

#ਜੇ (defined(_X86_) && !defined(__x86_64))
  ਪੂਰਨ __cdecl inp(ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ);
  ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ __cdecl inpw(ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ);
  ਪੂਰਨ __cdecl outp(ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ,ਪੂਰਨ);
  ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ __cdecl outpw(ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ,ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ);
#ਜੇ_ਅੰਤ

  /* I/O intrin functions.  */
  __CRT_INLINE ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ __inbyte(ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ ਪੋਰਟ)
  {
      ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ ਮੁੱਲ;
      __asm__ __volatile__ ("inb %w1,%b0"
          : "=a" (ਮੁੱਲ)
          : "Nd" (ਪੋਰਟ));
      ਵਾਪਸ ਮੁੱਲ;
  }
  __CRT_INLINE ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ __inword(ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ ਪੋਰਟ)
  {
      ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ ਮੁੱਲ;
      __asm__ __volatile__ ("inw %w1,%w0"
          : "=a" (ਮੁੱਲ)
          : "Nd" (ਪੋਰਟ));
      ਵਾਪਸ ਮੁੱਲ;
  }
  __CRT_INLINE ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ __indword(ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ ਪੋਰਟ)
  {
      ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਮੁੱਲ;
      __asm__ __volatile__ ("inl %w1,%0"
          : "=a" (ਮੁੱਲ)
          : "Nd" (ਪੋਰਟ));
      ਵਾਪਸ ਮੁੱਲ;
  }
  __CRT_INLINE ਖਾਲੀ __outbyte(ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ ਪੋਰਟ,ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ ਅੰਕੜੇ_3)
  {
      __asm__ __volatile__ ("outb %b0,%w1"
          :
          : "a" (ਅੰਕੜੇ_3), "Nd" (ਪੋਰਟ));
  }
  __CRT_INLINE ਖਾਲੀ __outword(ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ ਪੋਰਟ,ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ ਅੰਕੜੇ_3)
  {
      __asm__ __volatile__ ("outw %w0,%w1"
          :
          : "a" (ਅੰਕੜੇ_3), "Nd" (ਪੋਰਟ));
  }
  __CRT_INLINE ਖਾਲੀ __outdword(ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ ਪੋਰਟ,ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਅੰਕੜੇ_3)
  {
      __asm__ __volatile__ ("outl %0,%w1"
          :
          : "a" (ਅੰਕੜੇ_3), "Nd" (ਪੋਰਟ));
  }
  __CRT_INLINE ਖਾਲੀ __inbytestring(ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ ਪੋਰਟ,ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *ਬਫਰ_3,ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਗਿਣਤੀ_4)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insb " 
		: "=D" (ਬਫਰ_3), "=c" (ਗਿਣਤੀ_4)
		: "d"(ਪੋਰਟ), "0"(ਬਫਰ_3), "1" (ਗਿਣਤੀ_4)
		);
  }
  __CRT_INLINE ਖਾਲੀ __inwordstring(ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ ਪੋਰਟ,ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ *ਬਫਰ_3,ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਗਿਣਤੀ_4)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insw " 
		: "=D" (ਬਫਰ_3), "=c" (ਗਿਣਤੀ_4)
		: "d"(ਪੋਰਟ), "0"(ਬਫਰ_3), "1" (ਗਿਣਤੀ_4)
		);
  }
  __CRT_INLINE ਖਾਲੀ __indwordstring(ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ ਪੋਰਟ,ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ *ਬਫਰ_3,ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਗਿਣਤੀ_4)
  {
	__asm__ __volatile__ (
		"cld ; rep ; insl " 
		: "=D" (ਬਫਰ_3), "=c" (ਗਿਣਤੀ_4)
		: "d"(ਪੋਰਟ), "0"(ਬਫਰ_3), "1" (ਗਿਣਤੀ_4)
		);
  }

  __CRT_INLINE ਖਾਲੀ __outbytestring(ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ ਪੋਰਟ,ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *ਬਫਰ_3,ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਗਿਣਤੀ_4)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsb " 
          : "=S" (ਬਫਰ_3), "=c" (ਗਿਣਤੀ_4)
          : "d"(ਪੋਰਟ), "0"(ਬਫਰ_3), "1" (ਗਿਣਤੀ_4)
          );
  }
  __CRT_INLINE ਖਾਲੀ __outwordstring(ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ ਪੋਰਟ,ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ *ਬਫਰ_3,ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਗਿਣਤੀ_4)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsw " 
          : "=S" (ਬਫਰ_3), "=c" (ਗਿਣਤੀ_4)
          : "d"(ਪੋਰਟ), "0"(ਬਫਰ_3), "1" (ਗਿਣਤੀ_4)
          );
  }
  __CRT_INLINE ਖਾਲੀ __outdwordstring(ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ ਪੋਰਟ,ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ *ਬਫਰ_3,ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਗਿਣਤੀ_4)
  {
      __asm__ __volatile__ (
          "cld ; rep ; outsl " 
          : "=S" (ਬਫਰ_3), "=c" (ਗਿਣਤੀ_4)
          : "d"(ਪੋਰਟ), "0"(ਬਫਰ_3), "1" (ਗਿਣਤੀ_4)
          );
  }

  __CRT_INLINE ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 __readcr0(ਖਾਲੀ)
  {
      ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 ਮੁੱਲ;
      __asm__ __volatile__ (
          "mov %%cr0, %[value]" 
          : [ਮੁੱਲ] "=q" (ਮੁੱਲ));
      ਵਾਪਸ ਮੁੱਲ;
  }
 
  /* Register sizes are different between 32/64 bit mode. So we have to do this for _WIN64 and _WIN32
     separately.  */
 
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN64
  __CRT_INLINE ਖਾਲੀ __writecr0(ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 ਅੰਕੜੇ_3)
  {
   __asm__ __volatile__ (
       "mov %[Data], %%cr0"
       :
       : [ਅੰਕੜੇ_3] "q" (ਅੰਕੜੇ_3)
       : "memory");
  }
 
  __CRT_INLINE ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 __readcr2(ਖਾਲੀ)
  {
      ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 ਮੁੱਲ;
      __asm__ __volatile__ (
          "mov %%cr2, %[value]" 
          : [ਮੁੱਲ] "=q" (ਮੁੱਲ));
      ਵਾਪਸ ਮੁੱਲ;
  }

 __CRT_INLINE ਖਾਲੀ __writecr2(ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 ਅੰਕੜੇ_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr2"
       :
       : [ਅੰਕੜੇ_3] "q" (ਅੰਕੜੇ_3)
       : "memory");
 }
 
  __CRT_INLINE ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 __readcr3(ਖਾਲੀ)
  {
      ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 ਮੁੱਲ;
      __asm__ __volatile__ (
          "mov %%cr3, %[value]" 
          : [ਮੁੱਲ] "=q" (ਮੁੱਲ));
      ਵਾਪਸ ਮੁੱਲ;
  }

 __CRT_INLINE ਖਾਲੀ __writecr3(ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 ਅੰਕੜੇ_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr3"
       :
       : [ਅੰਕੜੇ_3] "q" (ਅੰਕੜੇ_3)
       : "memory");
 }
 
  __CRT_INLINE ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 __readcr4(ਖਾਲੀ)
  {
      ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 ਮੁੱਲ;
      __asm__ __volatile__ (
          "mov %%cr4, %[value]" 
          : [ਮੁੱਲ] "=q" (ਮੁੱਲ));
      ਵਾਪਸ ਮੁੱਲ;
  }

 __CRT_INLINE ਖਾਲੀ __writecr4(ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 ਅੰਕੜੇ_3)
 {
     __asm__ __volatile__ (
         "mov %[Data], %%cr4"
         :
         : [ਅੰਕੜੇ_3] "q" (ਅੰਕੜੇ_3)
         : "memory");
 }
 
  __CRT_INLINE ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 __readcr8(ਖਾਲੀ)
  {
      ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 ਮੁੱਲ;
      __asm__ __volatile__ (
          "mov %%cr8, %[value]" 
          : [ਮੁੱਲ] "=q" (ਮੁੱਲ));
      ਵਾਪਸ ਮੁੱਲ;
  }

 __CRT_INLINE ਖਾਲੀ __writecr8(ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 ਅੰਕੜੇ_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr8"
       :
       : [ਅੰਕੜੇ_3] "q" (ਅੰਕੜੇ_3)
       : "memory");
 }
 
#ਜਾਂਜੇ defined(_WIN32)

  __CRT_INLINE ਖਾਲੀ __writecr0(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੰਕੜੇ_3)
  {
    __asm__ __volatile__ (
       "mov %[Data], %%cr0"
       :
       : [ਅੰਕੜੇ_3] "q" (ਅੰਕੜੇ_3)
       : "memory");
  }
 
  __CRT_INLINE ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ __readcr2(ਖਾਲੀ)
  {
      ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਮੁੱਲ;
      __asm__ __volatile__ (
          "mov %%cr2, %[value]" 
          : [ਮੁੱਲ] "=q" (ਮੁੱਲ));
      ਵਾਪਸ ਮੁੱਲ;
  }

 __CRT_INLINE ਖਾਲੀ __writecr2(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੰਕੜੇ_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr2"
       :
       : [ਅੰਕੜੇ_3] "q" (ਅੰਕੜੇ_3)
       : "memory");
 }
 
  __CRT_INLINE ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ __readcr3(ਖਾਲੀ)
  {
      ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਮੁੱਲ;
      __asm__ __volatile__ (
          "mov %%cr3, %[value]" 
          : [ਮੁੱਲ] "=q" (ਮੁੱਲ));
      ਵਾਪਸ ਮੁੱਲ;
  }

 __CRT_INLINE ਖਾਲੀ __writecr3(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੰਕੜੇ_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr3"
       :
       : [ਅੰਕੜੇ_3] "q" (ਅੰਕੜੇ_3)
       : "memory");
 }
 
  __CRT_INLINE ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ __readcr4(ਖਾਲੀ)
  {
      ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਮੁੱਲ;
      __asm__ __volatile__ (
          "mov %%cr4, %[value]" 
          : [ਮੁੱਲ] "=q" (ਮੁੱਲ));
      ਵਾਪਸ ਮੁੱਲ;
  }

 __CRT_INLINE ਖਾਲੀ __writecr4(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੰਕੜੇ_3)
 {
     __asm__ __volatile__ (
         "mov %[Data], %%cr4"
         :
         : [ਅੰਕੜੇ_3] "q" (ਅੰਕੜੇ_3)
         : "memory");
 }
 
 __CRT_INLINE ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ __readcr8(ਖਾਲੀ)
 {
   ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਮੁੱਲ;      __asm__ __volatile__ (
          "mov %%cr8, %[value]" 
          : [ਮੁੱਲ] "=q" (ਮੁੱਲ));
     ਵਾਪਸ ਮੁੱਲ;
 }

 __CRT_INLINE ਖਾਲੀ __writecr8(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੰਕੜੇ_3)
 {
   __asm__ __volatile__ (
       "mov %[Data], %%cr8"
       :
       : [ਅੰਕੜੇ_3] "q" (ਅੰਕੜੇ_3)
       : "memory");
 }
 
#ਜੇ_ਅੰਤ

  __CRT_INLINE ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 __readmsr(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ msr)
  {
      ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 val1, val2;
       __asm__ __volatile__(
           "rdmsr"
           : "=a" (val1), "=d" (val2)
           : "c" (msr));
      ਵਾਪਸ val1 | (val2 << 32);
  }

 __CRT_INLINE ਖਾਲੀ __writemsr (ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ msr, ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 ਮੁੱਲ_3)
 {
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ val1 = ਮੁੱਲ_3, val2 = ਮੁੱਲ_3 >> 32;
   __asm__ __volatile__ (
       "wrmsr"
       :
       : "c" (msr), "a" (val1), "d" (val2));
 }
 
  __CRT_INLINE ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 __rdtsc(ਖਾਲੀ)
  {
      ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 val1, val2;
      __asm__ __volatile__ (
          "rdtsc" 
          : "=a" (val1), "=d" (val2));
      ਵਾਪਸ val1 | (val2 << 32);
  }

  __CRT_INLINE ਖਾਲੀ __cpuid(ਪੂਰਨ CPUInfo[4], ਪੂਰਨ InfoType)
  {
      __asm__ __volatile__ (
          "cpuid"
          : "=a" (CPUInfo [0]), "=b" (CPUInfo [1]), "=c" (CPUInfo [2]), "=d" (CPUInfo [3])
          : "a" (InfoType));
  }

#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
}
#ਜੇ_ਅੰਤ

#ਅਨ੍ਤਰ੍ਭਾਵ <sec_api/conio_s.h>

#ਜੇ_ਅੰਤ
