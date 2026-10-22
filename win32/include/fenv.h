/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _FENV_H_
#define _FENV_H_

#അന്തര്ഭാവ <_mingw.h>

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
തരനിർവചനം unsigned short fexcept_t;

/* This 32-byte struct represents the entire floating point
   environment as stored by fnstenv or fstenv, augmented by
   the  contents of the MXCSR register, as stored by stmxcsr
   (if CPU supports it). */
തരനിർവചനം ഘടന
{
  unsigned short __control_word;
  unsigned short __unused0;
  unsigned short __status_word;
  unsigned short __unused1;
  unsigned short __tag_word;
  unsigned short __unused2;  
  unsigned പൂർണ്ണസംഖ്യ	 __ip_offset;    /* instruction pointer offset */
  unsigned short __ip_selector;  
  unsigned short __opcode;
  unsigned പൂർണ്ണസംഖ്യ	 __data_offset;
  unsigned short __data_selector;  
  unsigned short __unused3;
  unsigned പൂർണ്ണസംഖ്യ   __mxcsr; /* contents of the MXCSR register  */
} fenv_t;


/*The C99 standard (7.6.9) allows us to define implementation-specific macros for
  different fp environments */
  
/* The default Intel x87 floating point environment (64-bit mantissa) */
#define FE_PC64_ENV ((സ്ഥിരം fenv_t *)-1)

/* The floating point environment set by MSVCRT _fpreset (53-bit mantissa) */
#define FE_PC53_ENV ((സ്ഥിരം fenv_t *)-2)

/* The FE_DFL_ENV macro is required by standard.
  fesetenv will use the environment set at app startup.*/
#define FE_DFL_ENV ((സ്ഥിരം fenv_t *) 0)

#ifdef __cplusplus
ബാഹ്യ "C" {
#endif

/*TODO: Some of these could be inlined */
/* 7.6.2 Exception */

ബാഹ്യ പൂർണ്ണസംഖ്യ __cdecl feclearexcept (പൂർണ്ണസംഖ്യ);
ബാഹ്യ പൂർണ്ണസംഖ്യ __cdecl fegetexceptflag (fexcept_t * flagp, പൂർണ്ണസംഖ്യ excepts);
ബാഹ്യ പൂർണ്ണസംഖ്യ __cdecl feraiseexcept (പൂർണ്ണസംഖ്യ excepts );
ബാഹ്യ പൂർണ്ണസംഖ്യ __cdecl fesetexceptflag (സ്ഥിരം fexcept_t *, പൂർണ്ണസംഖ്യ);
ബാഹ്യ പൂർണ്ണസംഖ്യ __cdecl fetestexcept (പൂർണ്ണസംഖ്യ excepts);

/* 7.6.3 Rounding */

ബാഹ്യ പൂർണ്ണസംഖ്യ __cdecl fegetround (ശൂന്യം);
ബാഹ്യ പൂർണ്ണസംഖ്യ __cdecl fesetround (പൂർണ്ണസംഖ്യ mode);

/* 7.6.4 Environment */

ബാഹ്യ പൂർണ്ണസംഖ്യ __cdecl fegetenv(fenv_t * envp);
ബാഹ്യ പൂർണ്ണസംഖ്യ __cdecl fesetenv(സ്ഥിരം fenv_t * );
ബാഹ്യ പൂർണ്ണസംഖ്യ __cdecl feupdateenv(സ്ഥിരം fenv_t *);
ബാഹ്യ പൂർണ്ണസംഖ്യ __cdecl feholdexcept(fenv_t *);

#ifdef __cplusplus
}
#endif
#endif	/* Not RC_INVOKED */

#endif /* ndef _FENV_H */
