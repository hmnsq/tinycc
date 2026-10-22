/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _FENV_H_
#ವ್ಯಾಖ್ಯಾನಿಸು _FENV_H_

#ಅನ್ತರ್ಭಾವ <_mingw.h>

/* FPU status word exception flags */
#ವ್ಯಾಖ್ಯಾನಿಸು FE_INVALID	0x01
#ವ್ಯಾಖ್ಯಾನಿಸು FE_DENORMAL	0x02
#ವ್ಯಾಖ್ಯಾನಿಸು FE_DIVBYZERO	0x04
#ವ್ಯಾಖ್ಯಾನಿಸು FE_ಅತಿಪ್ರವಾಹ	0x08
#ವ್ಯಾಖ್ಯಾನಿಸು FE_UNDERFLOW	0x10
#ವ್ಯಾಖ್ಯಾನಿಸು FE_INEXACT	0x20
#ವ್ಯಾಖ್ಯಾನಿಸು FE_ALL_EXCEPT (FE_INVALID | FE_DENORMAL | FE_DIVBYZERO \
		       | FE_ಅತಿಪ್ರವಾಹ | FE_UNDERFLOW | FE_INEXACT)

/* FPU control word rounding flags */
#ವ್ಯಾಖ್ಯಾನಿಸು FE_TONEAREST	0x0000
#ವ್ಯಾಖ್ಯಾನಿಸು FE_DOWNWARD	0x0400
#ವ್ಯಾಖ್ಯಾನಿಸು FE_UPWARD	0x0800
#ವ್ಯಾಖ್ಯಾನಿಸು FE_TOWARDZERO	0x0c00

/* The MXCSR exception flags are the same as the
   FE flags. */
#ವ್ಯಾಖ್ಯಾನಿಸು __MXCSR_EXCEPT_FLAG_SHIFT 0

/* How much to shift FE status word exception flags
   to get MXCSR rounding flags,  */
#ವ್ಯಾಖ್ಯಾನಿಸು __MXCSR_ROUND_FLAG_SHIFT 3

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ RC_INVOKED
/*
  For now, support only for the basic abstraction of flags that are
  either set or clear. fexcept_t could be  structure that holds more
  info about the fp environment.
*/
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ fexcept_t;

/* This 32-byte struct represents the entire floating point
   environment as stored by fnstenv or fstenv, augmented by
   the  contents of the MXCSR register, as stored by stmxcsr
   (if CPU supports it). */
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ
{
  ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ __control_word;
  ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ __unused0;
  ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ __status_word;
  ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ __unused1;
  ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ __tag_word;
  ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ __unused2;  
  ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ	 __ip_offset;    /* instruction pointer offset */
  ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ __ip_selector;  
  ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ __opcode;
  ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ	 __data_offset;
  ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ __data_selector;  
  ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ __unused3;
  ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ   __mxcsr; /* contents of the MXCSR register  */
} fenv_t;


/*The C99 standard (7.6.9) allows us to define implementation-specific macros for
  different fp environments */
  
/* The default Intel x87 floating point environment (64-bit mantissa) */
#ವ್ಯಾಖ್ಯಾನಿಸು FE_PC64_ENV ((ಸ್ಥಿರಾಂಕ fenv_t *)-1)

/* The floating point environment set by MSVCRT _fpreset (53-bit mantissa) */
#ವ್ಯಾಖ್ಯಾನಿಸು FE_PC53_ENV ((ಸ್ಥಿರಾಂಕ fenv_t *)-2)

/* The FE_DFL_ENV macro is required by standard.
  fesetenv will use the environment set at app startup.*/
#ವ್ಯಾಖ್ಯಾನಿಸು FE_DFL_ENV ((ಸ್ಥಿರಾಂಕ fenv_t *) 0)

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
ಬಾಹ್ಯ "C" {
#ಆದರೆ_ಅಂತ್ಯ

/*TODO: Some of these could be inlined */
/* 7.6.2 Exception */

ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ __cdecl feclearexcept (ಪೂರ್ಣಾಂಕ);
ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ __cdecl fegetexceptflag (fexcept_t * flagp, ಪೂರ್ಣಾಂಕ excepts);
ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ __cdecl feraiseexcept (ಪೂರ್ಣಾಂಕ excepts );
ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ __cdecl fesetexceptflag (ಸ್ಥಿರಾಂಕ fexcept_t *, ಪೂರ್ಣಾಂಕ);
ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ __cdecl fetestexcept (ಪೂರ್ಣಾಂಕ excepts);

/* 7.6.3 Rounding */

ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ __cdecl fegetround (ಶೂನ್ಯ);
ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ __cdecl fesetround (ಪೂರ್ಣಾಂಕ ಬಹುಲಕ);

/* 7.6.4 Environment */

ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ __cdecl fegetenv(fenv_t * envp);
ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ __cdecl fesetenv(ಸ್ಥಿರಾಂಕ fenv_t * );
ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ __cdecl feupdateenv(ಸ್ಥಿರಾಂಕ fenv_t *);
ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ __cdecl feholdexcept(fenv_t *);

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
}
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ	/* Not RC_INVOKED */

#ಆದರೆ_ಅಂತ್ಯ /* ndef _FENV_H */
