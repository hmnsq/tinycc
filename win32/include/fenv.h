/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _FENV_H_
#define _FENV_H_

#અન્તર્ભાવ <_mingw.h>

/* FPU status word exception flags */
#define FE_INVALID	0x01
#define FE_DENORMAL	0x02
#define FE_DIVBYZERO	0x04
#define FE_OVERFLOW	0x08
#define FE_UNDERFLOW	0x10
#define FE_INEXACT	0x20
#define FE_ALL_EXCEPT (FE_INVALID | FE_DENORMAL | FE_DIVBYZERO \
		       | FE_OVERFLOW | FE_UNDERFLOW | FE_INEXACT)

/* FPU control word rounding flags */
#define FE_TONEAREST	0x0000
#define FE_DOWNWARD	0x0400
#define FE_UPWARD	0x0800
#define FE_TOWARDZERO	0x0c00

/* The MXCSR exception flags are the same as the
   FE flags. */
#define __MXCSR_EXCEPT_FLAG_SHIFT 0

/* How much to shift FE status word exception flags
   to get MXCSR rounding flags,  */
#define __MXCSR_ROUND_FLAG_SHIFT 3

#ifndef RC_INVOKED
/*
  For now, support only for the basic abstraction of flags that are
  either set or clear. fexcept_t could be  structure that holds more
  info about the fp environment.
*/
પ્રકારવ્યાખ્યા unsigned short fexcept_t;

/* This 32-byte struct represents the entire floating point
   environment as stored by fnstenv or fstenv, augmented by
   the  contents of the MXCSR register, as stored by stmxcsr
   (if CPU supports it). */
પ્રકારવ્યાખ્યા સંરચના
{
  unsigned short __control_word;
  unsigned short __unused0;
  unsigned short __status_word;
  unsigned short __unused1;
  unsigned short __tag_word;
  unsigned short __unused2;  
  unsigned પૂર્ણાંક	 __ip_offset;    /* instruction pointer offset */
  unsigned short __ip_selector;  
  unsigned short __opcode;
  unsigned પૂર્ણાંક	 __data_offset;
  unsigned short __data_selector;  
  unsigned short __unused3;
  unsigned પૂર્ણાંક   __mxcsr; /* contents of the MXCSR register  */
} fenv_t;


/*The C99 standard (7.6.9) allows us to define implementation-specific macros for
  different fp environments */
  
/* The default Intel x87 floating point environment (64-bit mantissa) */
#define FE_PC64_ENV ((અચલ fenv_t *)-1)

/* The floating point environment set by MSVCRT _fpreset (53-bit mantissa) */
#define FE_PC53_ENV ((અચલ fenv_t *)-2)

/* The FE_DFL_ENV macro is required by standard.
  fesetenv will use the environment set at app startup.*/
#define FE_DFL_ENV ((અચલ fenv_t *) 0)

#ifdef __cplusplus
બાહ્ય "C" {
#endif

/*TODO: Some of these could be inlined */
/* 7.6.2 Exception */

બાહ્ય પૂર્ણાંક __cdecl feclearexcept (પૂર્ણાંક);
બાહ્ય પૂર્ણાંક __cdecl fegetexceptflag (fexcept_t * flagp, પૂર્ણાંક excepts);
બાહ્ય પૂર્ણાંક __cdecl feraiseexcept (પૂર્ણાંક excepts );
બાહ્ય પૂર્ણાંક __cdecl fesetexceptflag (અચલ fexcept_t *, પૂર્ણાંક);
બાહ્ય પૂર્ણાંક __cdecl fetestexcept (પૂર્ણાંક excepts);

/* 7.6.3 Rounding */

બાહ્ય પૂર્ણાંક __cdecl fegetround (શૂન્ય);
બાહ્ય પૂર્ણાંક __cdecl fesetround (પૂર્ણાંક mode);

/* 7.6.4 Environment */

બાહ્ય પૂર્ણાંક __cdecl fegetenv(fenv_t * envp);
બાહ્ય પૂર્ણાંક __cdecl fesetenv(અચલ fenv_t * );
બાહ્ય પૂર્ણાંક __cdecl feupdateenv(અચલ fenv_t *);
બાહ્ય પૂર્ણાંક __cdecl feholdexcept(fenv_t *);

#ifdef __cplusplus
}
#endif
#endif	/* Not RC_INVOKED */

#endif /* ndef _FENV_H */
