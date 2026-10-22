/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#నిర్వచితం_కాకపోతే _FENV_H_
#నిర్వచించు _FENV_H_

#అన్తర్భావ <_mingw.h>

/* FPU status word exception flags */
#నిర్వచించు FE_INVALID	0x01
#నిర్వచించు FE_DENORMAL	0x02
#నిర్వచించు FE_DIVBYZERO	0x04
#నిర్వచించు FE_అధికప్రవాహం	0x08
#నిర్వచించు FE_UNDERFLOW	0x10
#నిర్వచించు FE_INEXACT	0x20
#నిర్వచించు FE_ALL_EXCEPT (FE_INVALID | FE_DENORMAL | FE_DIVBYZERO \
		       | FE_అధికప్రవాహం | FE_UNDERFLOW | FE_INEXACT)

/* FPU control word rounding flags */
#నిర్వచించు FE_TONEAREST	0x0000
#నిర్వచించు FE_DOWNWARD	0x0400
#నిర్వచించు FE_UPWARD	0x0800
#నిర్వచించు FE_TOWARDZERO	0x0c00

/* The MXCSR exception flags are the same as the
   FE flags. */
#నిర్వచించు __MXCSR_EXCEPT_FLAG_SHIFT 0

/* How much to shift FE status word exception flags
   to get MXCSR rounding flags,  */
#నిర్వచించు __MXCSR_ROUND_FLAG_SHIFT 3

#నిర్వచితం_కాకపోతే RC_INVOKED
/*
  For now, support only for the basic abstraction of flags that are
  either set or clear. fexcept_t could be  structure that holds more
  info about the fp environment.
*/
రకనిర్వచనం గుర్తులేని పొట్టి fexcept_t;

/* This 32-byte struct represents the entire floating point
   environment as stored by fnstenv or fstenv, augmented by
   the  contents of the MXCSR register, as stored by stmxcsr
   (if CPU supports it). */
రకనిర్వచనం నిర్మాణం
{
  గుర్తులేని పొట్టి __control_word;
  గుర్తులేని పొట్టి __unused0;
  గుర్తులేని పొట్టి __status_word;
  గుర్తులేని పొట్టి __unused1;
  గుర్తులేని పొట్టి __tag_word;
  గుర్తులేని పొట్టి __unused2;  
  గుర్తులేని పూర్ణాంకం	 __ip_offset;    /* instruction pointer offset */
  గుర్తులేని పొట్టి __ip_selector;  
  గుర్తులేని పొట్టి __opcode;
  గుర్తులేని పూర్ణాంకం	 __data_offset;
  గుర్తులేని పొట్టి __data_selector;  
  గుర్తులేని పొట్టి __unused3;
  గుర్తులేని పూర్ణాంకం   __mxcsr; /* contents of the MXCSR register  */
} fenv_t;


/*The C99 standard (7.6.9) allows us to define implementation-specific macros for
  different fp environments */
  
/* The default Intel x87 floating point environment (64-bit mantissa) */
#నిర్వచించు FE_PC64_ENV ((స్థిరరాశి fenv_t *)-1)

/* The floating point environment set by MSVCRT _fpreset (53-bit mantissa) */
#నిర్వచించు FE_PC53_ENV ((స్థిరరాశి fenv_t *)-2)

/* The FE_DFL_ENV macro is required by standard.
  fesetenv will use the environment set at app startup.*/
#నిర్వచించు FE_DFL_ENV ((స్థిరరాశి fenv_t *) 0)

#నిర్వచితమైతే __cplusplus
బాహ్య "C" {
#అయితే_ముగింపు

/*TODO: Some of these could be inlined */
/* 7.6.2 Exception */

బాహ్య పూర్ణాంకం __cdecl feclearexcept (పూర్ణాంకం);
బాహ్య పూర్ణాంకం __cdecl fegetexceptflag (fexcept_t * flagp, పూర్ణాంకం excepts);
బాహ్య పూర్ణాంకం __cdecl feraiseexcept (పూర్ణాంకం excepts );
బాహ్య పూర్ణాంకం __cdecl fesetexceptflag (స్థిరరాశి fexcept_t *, పూర్ణాంకం);
బాహ్య పూర్ణాంకం __cdecl fetestexcept (పూర్ణాంకం excepts);

/* 7.6.3 Rounding */

బాహ్య పూర్ణాంకం __cdecl fegetround (శూన్య);
బాహ్య పూర్ణాంకం __cdecl fesetround (పూర్ణాంకం బహుళకం);

/* 7.6.4 Environment */

బాహ్య పూర్ణాంకం __cdecl fegetenv(fenv_t * envp);
బాహ్య పూర్ణాంకం __cdecl fesetenv(స్థిరరాశి fenv_t * );
బాహ్య పూర్ణాంకం __cdecl feupdateenv(స్థిరరాశి fenv_t *);
బాహ్య పూర్ణాంకం __cdecl feholdexcept(fenv_t *);

#నిర్వచితమైతే __cplusplus
}
#అయితే_ముగింపు
#అయితే_ముగింపు	/* Not RC_INVOKED */

#అయితే_ముగింపు /* ndef _FENV_H */
