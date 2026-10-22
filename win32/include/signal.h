/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _INC_SIGNAL
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _INC_SIGNAL

#ਅਨ੍ਤਰ੍ਭਾਵ <_mingw.h>

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
ਬਾਹਰੀ "C" {
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _SIG_ATOMIC_T_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _SIG_ATOMIC_T_DEFINED
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ sig_atomic_t;
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NSIG 23

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	SIGHUP	1	/* hangup */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIGINT 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	SIGQUIT	3	/* quit */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIGILL 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	SIGTRAP	5	/* trace trap (not reset when caught) */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	SIGIOT	6	/* IOT instruction */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	SIGABRT 6	/* used by abort, replace SIGIOT in the future */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	SIGEMT	7	/* EMT instruction */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIGFPE 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	SIGKILL	9	/* kill (cannot be caught or ignored) */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	SIGBUS	10	/* bus error */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIGSEGV 11
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	SIGSYS	12	/* bad argument to system call */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	SIGPIPE	13	/* write on a pipe with no one to read it */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __USE_MINGW_ALARM
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	SIGALRM	14	/* alarm clock */
#ਜੇ_ਅੰਤ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIGTERM 15
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIGBREAK 21
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIGABRT2 22

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIGABRT_COMPAT 6

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ	ਖਾਲੀ (*__p_sig_fn_t)(ਪੂਰਨ);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIG_DFL (__p_sig_fn_t)0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIG_IGN (__p_sig_fn_t)1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIG_GET (__p_sig_fn_t)2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIG_SGE (__p_sig_fn_t)3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIG_ACK (__p_sig_fn_t)4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIG_ERR (__p_sig_fn_t)-1

  ਬਾਹਰੀ ਖਾਲੀ **__cdecl __pxcptinfoptrs(ਖਾਲੀ);
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _pxcptinfoptrs (*__pxcptinfoptrs())

  __p_sig_fn_t __cdecl ਸੰਕੇਤ(ਪੂਰਨ Sig_ਅੰਕ_2,__p_sig_fn_t _Func);
  ਪੂਰਨ __cdecl ਉਠਾਓ(ਪੂਰਨ Sig_ਅੰਕ_2);

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
}
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
