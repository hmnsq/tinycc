/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_SIGNAL
#define _INC_SIGNAL

#अन्तर्भाव <_mingw.h>

#ifdef __cplusplus
बाह्य "C" {
#endif

#ifndef _SIG_ATOMIC_T_DEFINED
#define _SIG_ATOMIC_T_DEFINED
  प्रकारनिर्देश पूर्णाङ्क संक_पूर्ण_प्रकार;
#endif

#define NSIG 23

#define	SIGHUP	1	/* hangup */
#define संक_विघ्न 2
#define	SIGQUIT	3	/* quit */
#define संक_अवैध 4
#define	SIGTRAP	5	/* trace trap (not reset when caught) */
#define	SIGIOT	6	/* IOT instruction */
#define	SIGABRT 6	/* used by abort, replace SIGIOT in the future */
#define	SIGEMT	7	/* EMT instruction */
#define संक_भ_त्रुटि 8
#define	SIGKILL	9	/* kill (cannot be caught or ignored) */
#define	SIGBUS	10	/* bus error */
#define संक_अंश 11
#define	SIGSYS	12	/* bad argument to system call */
#define	SIGPIPE	13	/* write on a pipe with no one to read it */
#ifdef __USE_MINGW_ALARM
#define	SIGALRM	14	/* alarm clock */
#endif
#define संक_इति 15
#define SIGBREAK 21
#define SIGABRT2 22

#define SIGABRT_COMPAT 6

  प्रकारनिर्देश	शून्य (*__p_sig_fn_t)(पूर्णाङ्क);

#define संक_पूर्व (__p_sig_fn_t)0
#define संक_छोड़ो (__p_sig_fn_t)1
#define SIG_GET (__p_sig_fn_t)2
#define SIG_SGE (__p_sig_fn_t)3
#define SIG_ACK (__p_sig_fn_t)4
#define संक_त्रुटि (__p_sig_fn_t)-1

  बाह्य शून्य **__cdecl __pxcptinfoptrs(शून्य);
#define _pxcptinfoptrs (*__pxcptinfoptrs())

  __p_sig_fn_t __cdecl सङ्केत(पूर्णाङ्क Sig_अंक_2,__p_sig_fn_t _Func);
  पूर्णाङ्क __cdecl उत्थापय(पूर्णाङ्क Sig_अंक_2);

#ifdef __cplusplus
}
#endif
#endif
