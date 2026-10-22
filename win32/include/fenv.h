/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#अगर_अघोषित _FENV_H_
#घोषणा _FENV_H_

#समावेश <_mingw.h>

/* FPU status word exception flags */
#घोषणा FE_INVALID	0x01
#घोषणा FE_DENORMAL	0x02
#घोषणा FE_DIVBYZERO	0x04
#घोषणा FE_OVERFLOW	0x08
#घोषणा FE_UNDERFLOW	0x10
#घोषणा FE_INEXACT	0x20
#घोषणा FE_ALL_EXCEPT (FE_INVALID | FE_DENORMAL | FE_DIVBYZERO \
		       | FE_OVERFLOW | FE_UNDERFLOW | FE_INEXACT)

/* FPU control word rounding flags */
#घोषणा FE_TONEAREST	0x0000
#घोषणा FE_DOWNWARD	0x0400
#घोषणा FE_UPWARD	0x0800
#घोषणा FE_TOWARDZERO	0x0c00

/* The MXCSR exception flags are the same as the
   FE flags. */
#घोषणा __MXCSR_EXCEPT_FLAG_SHIFT 0

/* How much to shift FE status word exception flags
   to get MXCSR rounding flags,  */
#घोषणा __MXCSR_ROUND_FLAG_SHIFT 3

#अगर_अघोषित RC_INVOKED
/*
  For now, support only for the basic abstraction of flags that are
  either set or clear. fexcept_t could be  structure that holds more
  info about the fp environment.
*/
प्रकार अचिन्हित लघु fexcept_t;

/* This 32-byte struct represents the entire floating point
   environment as stored by fnstenv or fstenv, augmented by
   the  contents of the MXCSR register, as stored by stmxcsr
   (if CPU supports it). */
प्रकार काष्ठा
{
  अचिन्हित लघु __control_word;
  अचिन्हित लघु __unused0;
  अचिन्हित लघु __status_word;
  अचिन्हित लघु __unused1;
  अचिन्हित लघु __tag_word;
  अचिन्हित लघु __unused2;  
  अचिन्हित पूर्णांक	 __ip_offset;    /* instruction pointer offset */
  अचिन्हित लघु __ip_selector;  
  अचिन्हित लघु __opcode;
  अचिन्हित पूर्णांक	 __data_offset;
  अचिन्हित लघु __data_selector;  
  अचिन्हित लघु __unused3;
  अचिन्हित पूर्णांक   __mxcsr; /* contents of the MXCSR register  */
} fenv_t;


/*The C99 standard (7.6.9) allows us to define implementation-specific macros for
  different fp environments */
  
/* The default Intel x87 floating point environment (64-bit mantissa) */
#घोषणा FE_PC64_ENV ((स्थिर fenv_t *)-1)

/* The floating point environment set by MSVCRT _fpreset (53-bit mantissa) */
#घोषणा FE_PC53_ENV ((स्थिर fenv_t *)-2)

/* The FE_DFL_ENV macro is required by standard.
  fesetenv will use the environment set at app startup.*/
#घोषणा FE_DFL_ENV ((स्थिर fenv_t *) 0)

#अगर_घोषित __cplusplus
बाह्य "C" {
#पूर्ण_अगर

/*TODO: Some of these could be inlined */
/* 7.6.2 Exception */

बाह्य पूर्णांक __cdecl feclearexcept (पूर्णांक);
बाह्य पूर्णांक __cdecl fegetexceptflag (fexcept_t * flagp, पूर्णांक excepts);
बाह्य पूर्णांक __cdecl feraiseexcept (पूर्णांक excepts );
बाह्य पूर्णांक __cdecl fesetexceptflag (स्थिर fexcept_t *, पूर्णांक);
बाह्य पूर्णांक __cdecl fetestexcept (पूर्णांक excepts);

/* 7.6.3 Rounding */

बाह्य पूर्णांक __cdecl fegetround (व्योम);
बाह्य पूर्णांक __cdecl fesetround (पूर्णांक mode);

/* 7.6.4 Environment */

बाह्य पूर्णांक __cdecl fegetenv(fenv_t * envp);
बाह्य पूर्णांक __cdecl fesetenv(स्थिर fenv_t * );
बाह्य पूर्णांक __cdecl feupdateenv(स्थिर fenv_t *);
बाह्य पूर्णांक __cdecl feholdexcept(fenv_t *);

#अगर_घोषित __cplusplus
}
#पूर्ण_अगर
#पूर्ण_अगर	/* Not RC_INVOKED */

#पूर्ण_अगर /* ndef _FENV_H */
