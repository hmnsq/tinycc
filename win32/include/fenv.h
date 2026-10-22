/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _FENV_H_
#define _FENV_H_

#অন্তর্ভাৱ <_mingw.h>

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
প্রকারনির্দেশ unsigned short fexcept_t;

/* This 32-byte struct represents the entire floating point
   environment as stored by fnstenv or fstenv, augmented by
   the  contents of the MXCSR register, as stored by stmxcsr
   (if CPU supports it). */
প্রকারনির্দেশ সংরচনা
{
  unsigned short __control_word;
  unsigned short __unused0;
  unsigned short __status_word;
  unsigned short __unused1;
  unsigned short __tag_word;
  unsigned short __unused2;  
  unsigned পূর্ণাঙ্ক	 __ip_offset;    /* instruction pointer offset */
  unsigned short __ip_selector;  
  unsigned short __opcode;
  unsigned পূর্ণাঙ্ক	 __data_offset;
  unsigned short __data_selector;  
  unsigned short __unused3;
  unsigned পূর্ণাঙ্ক   __mxcsr; /* contents of the MXCSR register  */
} fenv_t;


/*The C99 standard (7.6.9) allows us to define implementation-specific macros for
  different fp environments */
  
/* The default Intel x87 floating point environment (64-bit mantissa) */
#define FE_PC64_ENV ((ধ্রুৱ fenv_t *)-1)

/* The floating point environment set by MSVCRT _fpreset (53-bit mantissa) */
#define FE_PC53_ENV ((ধ্রুৱ fenv_t *)-2)

/* The FE_DFL_ENV macro is required by standard.
  fesetenv will use the environment set at app startup.*/
#define FE_DFL_ENV ((ধ্রুৱ fenv_t *) 0)

#ifdef __cplusplus
বাহ্য "C" {
#endif

/*TODO: Some of these could be inlined */
/* 7.6.2 Exception */

বাহ্য পূর্ণাঙ্ক __cdecl feclearexcept (পূর্ণাঙ্ক);
বাহ্য পূর্ণাঙ্ক __cdecl fegetexceptflag (fexcept_t * flagp, পূর্ণাঙ্ক excepts);
বাহ্য পূর্ণাঙ্ক __cdecl feraiseexcept (পূর্ণাঙ্ক excepts );
বাহ্য পূর্ণাঙ্ক __cdecl fesetexceptflag (ধ্রুৱ fexcept_t *, পূর্ণাঙ্ক);
বাহ্য পূর্ণাঙ্ক __cdecl fetestexcept (পূর্ণাঙ্ক excepts);

/* 7.6.3 Rounding */

বাহ্য পূর্ণাঙ্ক __cdecl fegetround (শূন্য);
বাহ্য পূর্ণাঙ্ক __cdecl fesetround (পূর্ণাঙ্ক mode);

/* 7.6.4 Environment */

বাহ্য পূর্ণাঙ্ক __cdecl fegetenv(fenv_t * envp);
বাহ্য পূর্ণাঙ্ক __cdecl fesetenv(ধ্রুৱ fenv_t * );
বাহ্য পূর্ণাঙ্ক __cdecl feupdateenv(ধ্রুৱ fenv_t *);
বাহ্য পূর্ণাঙ্ক __cdecl feholdexcept(fenv_t *);

#ifdef __cplusplus
}
#endif
#endif	/* Not RC_INVOKED */

#endif /* ndef _FENV_H */
