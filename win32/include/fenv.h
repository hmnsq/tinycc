/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#यदि_अपरिभाषितम् _FENV_H_
#परिभाषय _FENV_H_

#अन्तर्भाव <_mingw.h>

/* FPU status word exception flags */
#परिभाषय FE_INVALID	0x01
#परिभाषय FE_DENORMAL	0x02
#परिभाषय FE_DIVBYZERO	0x04
#परिभाषय FE_अतिप्रवाहः	0x08
#परिभाषय FE_UNDERFLOW	0x10
#परिभाषय FE_INEXACT	0x20
#परिभाषय FE_ALL_EXCEPT (FE_INVALID | FE_DENORMAL | FE_DIVBYZERO \
		       | FE_अतिप्रवाहः | FE_UNDERFLOW | FE_INEXACT)

/* FPU control word rounding flags */
#परिभाषय FE_TONEAREST	0x0000
#परिभाषय FE_DOWNWARD	0x0400
#परिभाषय FE_UPWARD	0x0800
#परिभाषय FE_TOWARDZERO	0x0c00

/* The MXCSR exception flags are the same as the
   FE flags. */
#परिभाषय __MXCSR_EXCEPT_FLAG_SHIFT 0

/* How much to shift FE status word exception flags
   to get MXCSR rounding flags,  */
#परिभाषय __MXCSR_ROUND_FLAG_SHIFT 3

#यदि_अपरिभाषितम् RC_INVOKED
/*
  For now, support only for the basic abstraction of flags that are
  either set or clear. fexcept_t could be  structure that holds more
  info about the fp environment.
*/
प्रकारनिर्देश अचिह्नित ह्रस्व fexcept_t;

/* This 32-byte struct represents the entire floating point
   environment as stored by fnstenv or fstenv, augmented by
   the  contents of the MXCSR register, as stored by stmxcsr
   (if CPU supports it). */
प्रकारनिर्देश संरचना
{
  अचिह्नित ह्रस्व __control_word;
  अचिह्नित ह्रस्व __unused0;
  अचिह्नित ह्रस्व __status_word;
  अचिह्नित ह्रस्व __unused1;
  अचिह्नित ह्रस्व __tag_word;
  अचिह्नित ह्रस्व __unused2;  
  अचिह्नित पूर्णाङ्क	 __ip_offset;    /* instruction pointer offset */
  अचिह्नित ह्रस्व __ip_selector;  
  अचिह्नित ह्रस्व __opcode;
  अचिह्नित पूर्णाङ्क	 __data_offset;
  अचिह्नित ह्रस्व __data_selector;  
  अचिह्नित ह्रस्व __unused3;
  अचिह्नित पूर्णाङ्क   __mxcsr; /* contents of the MXCSR register  */
} fenv_t;


/*The C99 standard (7.6.9) allows us to define implementation-specific macros for
  different fp environments */
  
/* The default Intel x87 floating point environment (64-bit mantissa) */
#परिभाषय FE_PC64_ENV ((ध्रुव fenv_t *)-1)

/* The floating point environment set by MSVCRT _fpreset (53-bit mantissa) */
#परिभाषय FE_PC53_ENV ((ध्रुव fenv_t *)-2)

/* The FE_DFL_ENV macro is required by standard.
  fesetenv will use the environment set at app startup.*/
#परिभाषय FE_DFL_ENV ((ध्रुव fenv_t *) 0)

#यदि_परिभाषितम् __cplusplus
बाह्य "C" {
#यदि_अन्तः

/*TODO: Some of these could be inlined */
/* 7.6.2 Exception */

बाह्य पूर्णाङ्क __cdecl feclearexcept (पूर्णाङ्क);
बाह्य पूर्णाङ्क __cdecl fegetexceptflag (fexcept_t * flagp, पूर्णाङ्क excepts);
बाह्य पूर्णाङ्क __cdecl feraiseexcept (पूर्णाङ्क excepts );
बाह्य पूर्णाङ्क __cdecl fesetexceptflag (ध्रुव fexcept_t *, पूर्णाङ्क);
बाह्य पूर्णाङ्क __cdecl fetestexcept (पूर्णाङ्क excepts);

/* 7.6.3 Rounding */

बाह्य पूर्णाङ्क __cdecl fegetround (शून्य);
बाह्य पूर्णाङ्क __cdecl fesetround (पूर्णाङ्क बहुलकम्);

/* 7.6.4 Environment */

बाह्य पूर्णाङ्क __cdecl fegetenv(fenv_t * envp);
बाह्य पूर्णाङ्क __cdecl fesetenv(ध्रुव fenv_t * );
बाह्य पूर्णाङ्क __cdecl feupdateenv(ध्रुव fenv_t *);
बाह्य पूर्णाङ्क __cdecl feholdexcept(fenv_t *);

#यदि_परिभाषितम् __cplusplus
}
#यदि_अन्तः
#यदि_अन्तः	/* Not RC_INVOKED */

#यदि_अन्तः /* ndef _FENV_H */
