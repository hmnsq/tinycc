/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _INC_SIGNAL
#ವ್ಯಾಖ್ಯಾನಿಸು _INC_SIGNAL

#ಅನ್ತರ್ಭಾವ <_mingw.h>

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
ಬಾಹ್ಯ "C" {
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _SIG_ATOMIC_T_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _SIG_ATOMIC_T_DEFINED
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ sig_atomic_t;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು NSIG 23

#ವ್ಯಾಖ್ಯಾನಿಸು	SIGHUP	1	/* hangup */
#ವ್ಯಾಖ್ಯಾನಿಸು SIGINT 2
#ವ್ಯಾಖ್ಯಾನಿಸು	SIGQUIT	3	/* quit */
#ವ್ಯಾಖ್ಯಾನಿಸು SIGILL 4
#ವ್ಯಾಖ್ಯಾನಿಸು	SIGTRAP	5	/* trace trap (not reset when caught) */
#ವ್ಯಾಖ್ಯಾನಿಸು	SIGIOT	6	/* IOT instruction */
#ವ್ಯಾಖ್ಯಾನಿಸು	SIGABRT 6	/* used by abort, replace SIGIOT in the future */
#ವ್ಯಾಖ್ಯಾನಿಸು	SIGEMT	7	/* EMT instruction */
#ವ್ಯಾಖ್ಯಾನಿಸು SIGFPE 8
#ವ್ಯಾಖ್ಯಾನಿಸು	SIGKILL	9	/* kill (cannot be caught or ignored) */
#ವ್ಯಾಖ್ಯಾನಿಸು	SIGBUS	10	/* bus error */
#ವ್ಯಾಖ್ಯಾನಿಸು SIGSEGV 11
#ವ್ಯಾಖ್ಯಾನಿಸು	SIGSYS	12	/* bad argument to system call */
#ವ್ಯಾಖ್ಯಾನಿಸು	SIGPIPE	13	/* write on a pipe with no one to read it */
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __USE_MINGW_ALARM
#ವ್ಯಾಖ್ಯಾನಿಸು	SIGALRM	14	/* alarm clock */
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿಸು SIGTERM 15
#ವ್ಯಾಖ್ಯಾನಿಸು SIGBREAK 21
#ವ್ಯಾಖ್ಯಾನಿಸು SIGABRT2 22

#ವ್ಯಾಖ್ಯಾನಿಸು SIGABRT_COMPAT 6

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ	ಶೂನ್ಯ (*__p_sig_fn_t)(ಪೂರ್ಣಾಂಕ);

#ವ್ಯಾಖ್ಯಾನಿಸು SIG_DFL (__p_sig_fn_t)0
#ವ್ಯಾಖ್ಯಾನಿಸು SIG_IGN (__p_sig_fn_t)1
#ವ್ಯಾಖ್ಯಾನಿಸು SIG_GET (__p_sig_fn_t)2
#ವ್ಯಾಖ್ಯಾನಿಸು SIG_SGE (__p_sig_fn_t)3
#ವ್ಯಾಖ್ಯಾನಿಸು SIG_ACK (__p_sig_fn_t)4
#ವ್ಯಾಖ್ಯಾನಿಸು SIG_ERR (__p_sig_fn_t)-1

  ಬಾಹ್ಯ ಶೂನ್ಯ **__cdecl __pxcptinfoptrs(ಶೂನ್ಯ);
#ವ್ಯಾಖ್ಯಾನಿಸು _pxcptinfoptrs (*__pxcptinfoptrs())

  __p_sig_fn_t __cdecl ಸಂಕೇತ(ಪೂರ್ಣಾಂಕ Sig_ಅಂಕೆ_2,__p_sig_fn_t _Func);
  ಪೂರ್ಣಾಂಕ __cdecl ಎತ್ತು(ಪೂರ್ಣಾಂಕ Sig_ಅಂಕೆ_2);

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
}
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
