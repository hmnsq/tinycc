/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#که_نه_تعریف_شوی _FENV_H_
#تعریف_کړه _FENV_H_

#ضمن <_mingw.h>

/* FPU status word exception flags */
#تعریف_کړه FE_INVALID	0x01
#تعریف_کړه FE_DENORMAL	0x02
#تعریف_کړه FE_DIVBYZERO	0x04
#تعریف_کړه FE_ډکېدنه	0x08
#تعریف_کړه FE_UNDERFLOW	0x10
#تعریف_کړه FE_INEXACT	0x20
#تعریف_کړه FE_ALL_EXCEPT (FE_INVALID | FE_DENORMAL | FE_DIVBYZERO \
		       | FE_ډکېدنه | FE_UNDERFLOW | FE_INEXACT)

/* FPU control word rounding flags */
#تعریف_کړه FE_TONEAREST	0x0000
#تعریف_کړه FE_DOWNWARD	0x0400
#تعریف_کړه FE_UPWARD	0x0800
#تعریف_کړه FE_TOWARDZERO	0x0c00

/* The MXCSR exception flags are the same as the
   FE flags. */
#تعریف_کړه __MXCSR_EXCEPT_FLAG_SHIFT 0

/* How much to shift FE status word exception flags
   to get MXCSR rounding flags,  */
#تعریف_کړه __MXCSR_ROUND_FLAG_SHIFT 3

#که_نه_تعریف_شوی RC_INVOKED
/*
  For now, support only for the basic abstraction of flags that are
  either set or clear. fexcept_t could be  structure that holds more
  info about the fp environment.
*/
تعريفنوع بینښه لنډ fexcept_t;

/* This 32-byte struct represents the entire floating point
   environment as stored by fnstenv or fstenv, augmented by
   the  contents of the MXCSR register, as stored by stmxcsr
   (if CPU supports it). */
تعريفنوع بنية
{
  بینښه لنډ __control_word;
  بینښه لنډ __unused0;
  بینښه لنډ __status_word;
  بینښه لنډ __unused1;
  بینښه لنډ __tag_word;
  بینښه لنډ __unused2;  
  بینښه صحيح	 __ip_offset;    /* instruction pointer offset */
  بینښه لنډ __ip_selector;  
  بینښه لنډ __opcode;
  بینښه صحيح	 __data_offset;
  بینښه لنډ __data_selector;  
  بینښه لنډ __unused3;
  بینښه صحيح   __mxcsr; /* contents of the MXCSR register  */
} fenv_t;


/*The C99 standard (7.6.9) allows us to define implementation-specific macros for
  different fp environments */
  
/* The default Intel x87 floating point environment (64-bit mantissa) */
#تعریف_کړه FE_PC64_ENV ((ثابت fenv_t *)-1)

/* The floating point environment set by MSVCRT _fpreset (53-bit mantissa) */
#تعریف_کړه FE_PC53_ENV ((ثابت fenv_t *)-2)

/* The FE_DFL_ENV macro is required by standard.
  fesetenv will use the environment set at app startup.*/
#تعریف_کړه FE_DFL_ENV ((ثابت fenv_t *) 0)

#که_تعریف_شوی __cplusplus
خارجي "C" {
#د_که_پای

/*TODO: Some of these could be inlined */
/* 7.6.2 Exception */

خارجي صحيح __cdecl feclearexcept (صحيح);
خارجي صحيح __cdecl fegetexceptflag (fexcept_t * flagp, صحيح excepts);
خارجي صحيح __cdecl feraiseexcept (صحيح excepts );
خارجي صحيح __cdecl fesetexceptflag (ثابت fexcept_t *, صحيح);
خارجي صحيح __cdecl fetestexcept (صحيح excepts);

/* 7.6.3 Rounding */

خارجي صحيح __cdecl fegetround (فراغ);
خارجي صحيح __cdecl fesetround (صحيح ډېرپېښ);

/* 7.6.4 Environment */

خارجي صحيح __cdecl fegetenv(fenv_t * envp);
خارجي صحيح __cdecl fesetenv(ثابت fenv_t * );
خارجي صحيح __cdecl feupdateenv(ثابت fenv_t *);
خارجي صحيح __cdecl feholdexcept(fenv_t *);

#که_تعریف_شوی __cplusplus
}
#د_که_پای
#د_که_پای	/* Not RC_INVOKED */

#د_که_پای /* ndef _FENV_H */
