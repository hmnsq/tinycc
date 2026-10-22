/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جيڪڏهن_وصف_نه_ٿيل _FENV_H_
#وصف_ڪريو _FENV_H_

#ضمن <_mingw.h>

/* FPU status word exception flags */
#وصف_ڪريو FE_INVALID	0x01
#وصف_ڪريو FE_DENORMAL	0x02
#وصف_ڪريو FE_DIVBYZERO	0x04
#وصف_ڪريو FE_حد_کان_مٿي	0x08
#وصف_ڪريو FE_UNDERFLOW	0x10
#وصف_ڪريو FE_INEXACT	0x20
#وصف_ڪريو FE_ALL_EXCEPT (FE_INVALID | FE_DENORMAL | FE_DIVBYZERO \
		       | FE_حد_کان_مٿي | FE_UNDERFLOW | FE_INEXACT)

/* FPU control word rounding flags */
#وصف_ڪريو FE_TONEAREST	0x0000
#وصف_ڪريو FE_DOWNWARD	0x0400
#وصف_ڪريو FE_UPWARD	0x0800
#وصف_ڪريو FE_TOWARDZERO	0x0c00

/* The MXCSR exception flags are the same as the
   FE flags. */
#وصف_ڪريو __MXCSR_EXCEPT_FLAG_SHIFT 0

/* How much to shift FE status word exception flags
   to get MXCSR rounding flags,  */
#وصف_ڪريو __MXCSR_ROUND_FLAG_SHIFT 3

#جيڪڏهن_وصف_نه_ٿيل RC_INVOKED
/*
  For now, support only for the basic abstraction of flags that are
  either set or clear. fexcept_t could be  structure that holds more
  info about the fp environment.
*/
تعريفنوع بنانشان ننڍو fexcept_t;

/* This 32-byte struct represents the entire floating point
   environment as stored by fnstenv or fstenv, augmented by
   the  contents of the MXCSR register, as stored by stmxcsr
   (if CPU supports it). */
تعريفنوع بنية
{
  بنانشان ننڍو __control_word;
  بنانشان ننڍو __unused0;
  بنانشان ننڍو __status_word;
  بنانشان ننڍو __unused1;
  بنانشان ننڍو __tag_word;
  بنانشان ننڍو __unused2;  
  بنانشان صحيح	 __ip_offset;    /* instruction pointer offset */
  بنانشان ننڍو __ip_selector;  
  بنانشان ننڍو __opcode;
  بنانشان صحيح	 __data_offset;
  بنانشان ننڍو __data_selector;  
  بنانشان ننڍو __unused3;
  بنانشان صحيح   __mxcsr; /* contents of the MXCSR register  */
} fenv_t;


/*The C99 standard (7.6.9) allows us to define implementation-specific macros for
  different fp environments */
  
/* The default Intel x87 floating point environment (64-bit mantissa) */
#وصف_ڪريو FE_PC64_ENV ((ثابت fenv_t *)-1)

/* The floating point environment set by MSVCRT _fpreset (53-bit mantissa) */
#وصف_ڪريو FE_PC53_ENV ((ثابت fenv_t *)-2)

/* The FE_DFL_ENV macro is required by standard.
  fesetenv will use the environment set at app startup.*/
#وصف_ڪريو FE_DFL_ENV ((ثابت fenv_t *) 0)

#جيڪڏهن_وصف_ٿيل __cplusplus
خارجي "C" {
#جيڪڏهن_پورو

/*TODO: Some of these could be inlined */
/* 7.6.2 Exception */

خارجي صحيح __cdecl feclearexcept (صحيح);
خارجي صحيح __cdecl fegetexceptflag (fexcept_t * flagp, صحيح excepts);
خارجي صحيح __cdecl feraiseexcept (صحيح excepts );
خارجي صحيح __cdecl fesetexceptflag (ثابت fexcept_t *, صحيح);
خارجي صحيح __cdecl fetestexcept (صحيح excepts);

/* 7.6.3 Rounding */

خارجي صحيح __cdecl fegetround (فراغ);
خارجي صحيح __cdecl fesetround (صحيح گهڻائي);

/* 7.6.4 Environment */

خارجي صحيح __cdecl fegetenv(fenv_t * envp);
خارجي صحيح __cdecl fesetenv(ثابت fenv_t * );
خارجي صحيح __cdecl feupdateenv(ثابت fenv_t *);
خارجي صحيح __cdecl feholdexcept(fenv_t *);

#جيڪڏهن_وصف_ٿيل __cplusplus
}
#جيڪڏهن_پورو
#جيڪڏهن_پورو	/* Not RC_INVOKED */

#جيڪڏهن_پورو /* ndef _FENV_H */
