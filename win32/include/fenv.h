/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _FENV_H_
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _FENV_H_

#ਅਨ੍ਤਰ੍ਭਾਵ <_mingw.h>

/* FPU status word exception flags */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FE_INVALID	0x01
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FE_DENORMAL	0x02
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FE_DIVBYZERO	0x04
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FE_ਉਛਾਲ	0x08
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FE_UNDERFLOW	0x10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FE_INEXACT	0x20
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FE_ALL_EXCEPT (FE_INVALID | FE_DENORMAL | FE_DIVBYZERO \
		       | FE_ਉਛਾਲ | FE_UNDERFLOW | FE_INEXACT)

/* FPU control word rounding flags */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FE_TONEAREST	0x0000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FE_DOWNWARD	0x0400
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FE_UPWARD	0x0800
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FE_TOWARDZERO	0x0c00

/* The MXCSR exception flags are the same as the
   FE flags. */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __MXCSR_EXCEPT_FLAG_SHIFT 0

/* How much to shift FE status word exception flags
   to get MXCSR rounding flags,  */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __MXCSR_ROUND_FLAG_SHIFT 3

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ RC_INVOKED
/*
  For now, support only for the basic abstraction of flags that are
  either set or clear. fexcept_t could be  structure that holds more
  info about the fp environment.
*/
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ fexcept_t;

/* This 32-byte struct represents the entire floating point
   environment as stored by fnstenv or fstenv, augmented by
   the  contents of the MXCSR register, as stored by stmxcsr
   (if CPU supports it). */
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ
{
  ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ __control_word;
  ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ __unused0;
  ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ __status_word;
  ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ __unused1;
  ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ __tag_word;
  ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ __unused2;  
  ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ	 __ip_offset;    /* instruction pointer offset */
  ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ __ip_selector;  
  ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ __opcode;
  ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ	 __data_offset;
  ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ __data_selector;  
  ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ __unused3;
  ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ   __mxcsr; /* contents of the MXCSR register  */
} fenv_t;


/*The C99 standard (7.6.9) allows us to define implementation-specific macros for
  different fp environments */
  
/* The default Intel x87 floating point environment (64-bit mantissa) */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FE_PC64_ENV ((ਅਚਲ fenv_t *)-1)

/* The floating point environment set by MSVCRT _fpreset (53-bit mantissa) */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FE_PC53_ENV ((ਅਚਲ fenv_t *)-2)

/* The FE_DFL_ENV macro is required by standard.
  fesetenv will use the environment set at app startup.*/
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FE_DFL_ENV ((ਅਚਲ fenv_t *) 0)

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
ਬਾਹਰੀ "C" {
#ਜੇ_ਅੰਤ

/*TODO: Some of these could be inlined */
/* 7.6.2 Exception */

ਬਾਹਰੀ ਪੂਰਨ __cdecl feclearexcept (ਪੂਰਨ);
ਬਾਹਰੀ ਪੂਰਨ __cdecl fegetexceptflag (fexcept_t * flagp, ਪੂਰਨ excepts);
ਬਾਹਰੀ ਪੂਰਨ __cdecl feraiseexcept (ਪੂਰਨ excepts );
ਬਾਹਰੀ ਪੂਰਨ __cdecl fesetexceptflag (ਅਚਲ fexcept_t *, ਪੂਰਨ);
ਬਾਹਰੀ ਪੂਰਨ __cdecl fetestexcept (ਪੂਰਨ excepts);

/* 7.6.3 Rounding */

ਬਾਹਰੀ ਪੂਰਨ __cdecl fegetround (ਖਾਲੀ);
ਬਾਹਰੀ ਪੂਰਨ __cdecl fesetround (ਪੂਰਨ ਬਹੁਲਕ);

/* 7.6.4 Environment */

ਬਾਹਰੀ ਪੂਰਨ __cdecl fegetenv(fenv_t * envp);
ਬਾਹਰੀ ਪੂਰਨ __cdecl fesetenv(ਅਚਲ fenv_t * );
ਬਾਹਰੀ ਪੂਰਨ __cdecl feupdateenv(ਅਚਲ fenv_t *);
ਬਾਹਰੀ ਪੂਰਨ __cdecl feholdexcept(fenv_t *);

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
}
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ	/* Not RC_INVOKED */

#ਜੇ_ਅੰਤ /* ndef _FENV_H */
