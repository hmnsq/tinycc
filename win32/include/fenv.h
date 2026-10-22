/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_غیر_تعریف_شدہ _FENV_H_
#تعریف_کرو _FENV_H_

#شامل <_mingw.h>

/* FPU status word exception flags */
#تعریف_کرو FE_INVALID	0x01
#تعریف_کرو FE_DENORMAL	0x02
#تعریف_کرو FE_DIVBYZERO	0x04
#تعریف_کرو FE_حد_سے_تجاوز	0x08
#تعریف_کرو FE_UNDERFLOW	0x10
#تعریف_کرو FE_INEXACT	0x20
#تعریف_کرو FE_ALL_EXCEPT (FE_INVALID | FE_DENORMAL | FE_DIVBYZERO \
		       | FE_حد_سے_تجاوز | FE_UNDERFLOW | FE_INEXACT)

/* FPU control word rounding flags */
#تعریف_کرو FE_TONEAREST	0x0000
#تعریف_کرو FE_DOWNWARD	0x0400
#تعریف_کرو FE_UPWARD	0x0800
#تعریف_کرو FE_TOWARDZERO	0x0c00

/* The MXCSR exception flags are the same as the
   FE flags. */
#تعریف_کرو __MXCSR_EXCEPT_FLAG_SHIFT 0

/* How much to shift FE status word exception flags
   to get MXCSR rounding flags,  */
#تعریف_کرو __MXCSR_ROUND_FLAG_SHIFT 3

#اگر_غیر_تعریف_شدہ RC_INVOKED
/*
  For now, support only for the basic abstraction of flags that are
  either set or clear. fexcept_t could be  structure that holds more
  info about the fp environment.
*/
قسمتعریف غیرعلامتی مختصر fexcept_t;

/* This 32-byte struct represents the entire floating point
   environment as stored by fnstenv or fstenv, augmented by
   the  contents of the MXCSR register, as stored by stmxcsr
   (if CPU supports it). */
قسمتعریف ساخت
{
  غیرعلامتی مختصر __control_word;
  غیرعلامتی مختصر __unused0;
  غیرعلامتی مختصر __status_word;
  غیرعلامتی مختصر __unused1;
  غیرعلامتی مختصر __tag_word;
  غیرعلامتی مختصر __unused2;  
  غیرعلامتی صحیح	 __ip_offset;    /* instruction pointer offset */
  غیرعلامتی مختصر __ip_selector;  
  غیرعلامتی مختصر __opcode;
  غیرعلامتی صحیح	 __data_offset;
  غیرعلامتی مختصر __data_selector;  
  غیرعلامتی مختصر __unused3;
  غیرعلامتی صحیح   __mxcsr; /* contents of the MXCSR register  */
} fenv_t;


/*The C99 standard (7.6.9) allows us to define implementation-specific macros for
  different fp environments */
  
/* The default Intel x87 floating point environment (64-bit mantissa) */
#تعریف_کرو FE_PC64_ENV ((ثابت fenv_t *)-1)

/* The floating point environment set by MSVCRT _fpreset (53-bit mantissa) */
#تعریف_کرو FE_PC53_ENV ((ثابت fenv_t *)-2)

/* The FE_DFL_ENV macro is required by standard.
  fesetenv will use the environment set at app startup.*/
#تعریف_کرو FE_DFL_ENV ((ثابت fenv_t *) 0)

#اگر_تعریف_شدہ __cplusplus
خارجی "C" {
#اگر_ختم

/*TODO: Some of these could be inlined */
/* 7.6.2 Exception */

خارجی صحیح __cdecl feclearexcept (صحیح);
خارجی صحیح __cdecl fegetexceptflag (fexcept_t * flagp, صحیح excepts);
خارجی صحیح __cdecl feraiseexcept (صحیح excepts );
خارجی صحیح __cdecl fesetexceptflag (ثابت fexcept_t *, صحیح);
خارجی صحیح __cdecl fetestexcept (صحیح excepts);

/* 7.6.3 Rounding */

خارجی صحیح __cdecl fegetround (خالی);
خارجی صحیح __cdecl fesetround (صحیح منوال);

/* 7.6.4 Environment */

خارجی صحیح __cdecl fegetenv(fenv_t * envp);
خارجی صحیح __cdecl fesetenv(ثابت fenv_t * );
خارجی صحیح __cdecl feupdateenv(ثابت fenv_t *);
خارجی صحیح __cdecl feholdexcept(fenv_t *);

#اگر_تعریف_شدہ __cplusplus
}
#اگر_ختم
#اگر_ختم	/* Not RC_INVOKED */

#اگر_ختم /* ndef _FENV_H */
