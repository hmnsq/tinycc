/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_تعریف_نشده _FENV_H_
#تعریف_کن _FENV_H_

#ضمن <_mingw.h>

/* FPU status word exception flags */
#تعریف_کن FE_INVALID	0x01
#تعریف_کن FE_DENORMAL	0x02
#تعریف_کن FE_DIVBYZERO	0x04
#تعریف_کن FE_سرریز	0x08
#تعریف_کن FE_UNDERFLOW	0x10
#تعریف_کن FE_INEXACT	0x20
#تعریف_کن FE_ALL_EXCEPT (FE_INVALID | FE_DENORMAL | FE_DIVBYZERO \
		       | FE_سرریز | FE_UNDERFLOW | FE_INEXACT)

/* FPU control word rounding flags */
#تعریف_کن FE_TONEAREST	0x0000
#تعریف_کن FE_DOWNWARD	0x0400
#تعریف_کن FE_UPWARD	0x0800
#تعریف_کن FE_TOWARDZERO	0x0c00

/* The MXCSR exception flags are the same as the
   FE flags. */
#تعریف_کن __MXCSR_EXCEPT_FLAG_SHIFT 0

/* How much to shift FE status word exception flags
   to get MXCSR rounding flags,  */
#تعریف_کن __MXCSR_ROUND_FLAG_SHIFT 3

#اگر_تعریف_نشده RC_INVOKED
/*
  For now, support only for the basic abstraction of flags that are
  either set or clear. fexcept_t could be  structure that holds more
  info about the fp environment.
*/
تعريفنوع بیعلامت کوتاه fexcept_t;

/* This 32-byte struct represents the entire floating point
   environment as stored by fnstenv or fstenv, augmented by
   the  contents of the MXCSR register, as stored by stmxcsr
   (if CPU supports it). */
تعريفنوع بنية
{
  بیعلامت کوتاه __control_word;
  بیعلامت کوتاه __unused0;
  بیعلامت کوتاه __status_word;
  بیعلامت کوتاه __unused1;
  بیعلامت کوتاه __tag_word;
  بیعلامت کوتاه __unused2;  
  بیعلامت صحيح	 __ip_offset;    /* instruction pointer offset */
  بیعلامت کوتاه __ip_selector;  
  بیعلامت کوتاه __opcode;
  بیعلامت صحيح	 __data_offset;
  بیعلامت کوتاه __data_selector;  
  بیعلامت کوتاه __unused3;
  بیعلامت صحيح   __mxcsr; /* contents of the MXCSR register  */
} fenv_t;


/*The C99 standard (7.6.9) allows us to define implementation-specific macros for
  different fp environments */
  
/* The default Intel x87 floating point environment (64-bit mantissa) */
#تعریف_کن FE_PC64_ENV ((ثابت fenv_t *)-1)

/* The floating point environment set by MSVCRT _fpreset (53-bit mantissa) */
#تعریف_کن FE_PC53_ENV ((ثابت fenv_t *)-2)

/* The FE_DFL_ENV macro is required by standard.
  fesetenv will use the environment set at app startup.*/
#تعریف_کن FE_DFL_ENV ((ثابت fenv_t *) 0)

#اگر_تعریف_شده __cplusplus
خارجي "C" {
#پایان_اگر

/*TODO: Some of these could be inlined */
/* 7.6.2 Exception */

خارجي صحيح __cdecl feclearexcept (صحيح);
خارجي صحيح __cdecl fegetexceptflag (fexcept_t * flagp, صحيح excepts);
خارجي صحيح __cdecl feraiseexcept (صحيح excepts );
خارجي صحيح __cdecl fesetexceptflag (ثابت fexcept_t *, صحيح);
خارجي صحيح __cdecl fetestexcept (صحيح excepts);

/* 7.6.3 Rounding */

خارجي صحيح __cdecl fegetround (فراغ);
خارجي صحيح __cdecl fesetround (صحيح نما);

/* 7.6.4 Environment */

خارجي صحيح __cdecl fegetenv(fenv_t * envp);
خارجي صحيح __cdecl fesetenv(ثابت fenv_t * );
خارجي صحيح __cdecl feupdateenv(ثابت fenv_t *);
خارجي صحيح __cdecl feholdexcept(fenv_t *);

#اگر_تعریف_شده __cplusplus
}
#پایان_اگر
#پایان_اگر	/* Not RC_INVOKED */

#پایان_اگر /* ndef _FENV_H */
