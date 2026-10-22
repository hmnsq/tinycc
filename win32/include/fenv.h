/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _FENV_H_
#define _FENV_H_

#अन्तर्भाव <_mingw.h>

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
प्रकारनिर्देश अचिन्हित लघु fexcept_t;

/* This 32-byte struct represents the entire floating point
   environment as stored by fnstenv or fstenv, augmented by
   the  contents of the MXCSR register, as stored by stmxcsr
   (if CPU supports it). */
प्रकारनिर्देश संरचना
{
  अचिन्हित लघु __control_word;
  अचिन्हित लघु __unused0;
  अचिन्हित लघु __status_word;
  अचिन्हित लघु __unused1;
  अचिन्हित लघु __tag_word;
  अचिन्हित लघु __unused2;  
  अचिन्हित पूर्णाङ्क	 __ip_offset;    /* instruction pointer offset */
  अचिन्हित लघु __ip_selector;  
  अचिन्हित लघु __opcode;
  अचिन्हित पूर्णाङ्क	 __data_offset;
  अचिन्हित लघु __data_selector;  
  अचिन्हित लघु __unused3;
  अचिन्हित पूर्णाङ्क   __mxcsr; /* contents of the MXCSR register  */
} fenv_t;


/*The C99 standard (7.6.9) allows us to define implementation-specific macros for
  different fp environments */
  
/* The default Intel x87 floating point environment (64-bit mantissa) */
#define FE_PC64_ENV ((अचर fenv_t *)-1)

/* The floating point environment set by MSVCRT _fpreset (53-bit mantissa) */
#define FE_PC53_ENV ((अचर fenv_t *)-2)

/* The FE_DFL_ENV macro is required by standard.
  fesetenv will use the environment set at app startup.*/
#define FE_DFL_ENV ((अचर fenv_t *) 0)

#ifdef __cplusplus
बाह्य "C" {
#endif

/*TODO: Some of these could be inlined */
/* 7.6.2 Exception */

बाह्य पूर्णाङ्क __cdecl feclearexcept (पूर्णाङ्क);
बाह्य पूर्णाङ्क __cdecl fegetexceptflag (fexcept_t * flagp, पूर्णाङ्क excepts);
बाह्य पूर्णाङ्क __cdecl feraiseexcept (पूर्णाङ्क excepts );
बाह्य पूर्णाङ्क __cdecl fesetexceptflag (अचर fexcept_t *, पूर्णाङ्क);
बाह्य पूर्णाङ्क __cdecl fetestexcept (पूर्णाङ्क excepts);

/* 7.6.3 Rounding */

बाह्य पूर्णाङ्क __cdecl fegetround (शून्य);
बाह्य पूर्णाङ्क __cdecl fesetround (पूर्णाङ्क mode);

/* 7.6.4 Environment */

बाह्य पूर्णाङ्क __cdecl fegetenv(fenv_t * envp);
बाह्य पूर्णाङ्क __cdecl fesetenv(अचर fenv_t * );
बाह्य पूर्णाङ्क __cdecl feupdateenv(अचर fenv_t *);
बाह्य पूर्णाङ्क __cdecl feholdexcept(fenv_t *);

#ifdef __cplusplus
}
#endif
#endif	/* Not RC_INVOKED */

#endif /* ndef _FENV_H */
