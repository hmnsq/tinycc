/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جے_بنا_تعریف _FENV_H_
#تعریف_کرو _FENV_H_

#ضمن <_mingw.h>

/* FPU status word exception flags */
#تعریف_کرو FE_INVALID	0x01
#تعریف_کرو FE_DENORMAL	0x02
#تعریف_کرو FE_DIVBYZERO	0x04
#تعریف_کرو FE_حد_توں_ودھ	0x08
#تعریف_کرو FE_UNDERFLOW	0x10
#تعریف_کرو FE_INEXACT	0x20
#تعریف_کرو FE_ALL_EXCEPT (FE_INVALID | FE_DENORMAL | FE_DIVBYZERO \
		       | FE_حد_توں_ودھ | FE_UNDERFLOW | FE_INEXACT)

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

#جے_بنا_تعریف RC_INVOKED
/*
  For now, support only for the basic abstraction of flags that are
  either set or clear. fexcept_t could be  structure that holds more
  info about the fp environment.
*/
تعريفنوع بنانشانی چھوٹا fexcept_t;

/* This 32-byte struct represents the entire floating point
   environment as stored by fnstenv or fstenv, augmented by
   the  contents of the MXCSR register, as stored by stmxcsr
   (if CPU supports it). */
تعريفنوع بنية
{
  بنانشانی چھوٹا __control_word;
  بنانشانی چھوٹا __unused0;
  بنانشانی چھوٹا __status_word;
  بنانشانی چھوٹا __unused1;
  بنانشانی چھوٹا __tag_word;
  بنانشانی چھوٹا __unused2;  
  بنانشانی صحيح	 __ip_offset;    /* instruction pointer offset */
  بنانشانی چھوٹا __ip_selector;  
  بنانشانی چھوٹا __opcode;
  بنانشانی صحيح	 __data_offset;
  بنانشانی چھوٹا __data_selector;  
  بنانشانی چھوٹا __unused3;
  بنانشانی صحيح   __mxcsr; /* contents of the MXCSR register  */
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

#جے_تعریف_شدہ __cplusplus
خارجي "C" {
#جے_انت

/*TODO: Some of these could be inlined */
/* 7.6.2 Exception */

خارجي صحيح __cdecl feclearexcept (صحيح);
خارجي صحيح __cdecl fegetexceptflag (fexcept_t * flagp, صحيح excepts);
خارجي صحيح __cdecl feraiseexcept (صحيح excepts );
خارجي صحيح __cdecl fesetexceptflag (ثابت fexcept_t *, صحيح);
خارجي صحيح __cdecl fetestexcept (صحيح excepts);

/* 7.6.3 Rounding */

خارجي صحيح __cdecl fegetround (فراغ);
خارجي صحيح __cdecl fesetround (صحيح منوال);

/* 7.6.4 Environment */

خارجي صحيح __cdecl fegetenv(fenv_t * envp);
خارجي صحيح __cdecl fesetenv(ثابت fenv_t * );
خارجي صحيح __cdecl feupdateenv(ثابت fenv_t *);
خارجي صحيح __cdecl feholdexcept(fenv_t *);

#جے_تعریف_شدہ __cplusplus
}
#جے_انت
#جے_انت	/* Not RC_INVOKED */

#جے_انت /* ndef _FENV_H */
