/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_تعریف_نشده _INC_SIGNAL
#تعریف_کن _INC_SIGNAL

#ضمن <_mingw.h>

#اگر_تعریف_شده __cplusplus
خارجي "C" {
#پایان_اگر

#اگر_تعریف_نشده _SIG_ATOMIC_T_DEFINED
#تعریف_کن _SIG_ATOMIC_T_DEFINED
  تعريفنوع صحيح sig_atomic_t;
#پایان_اگر

#تعریف_کن NSIG 23

#تعریف_کن	SIGHUP	1	/* hangup */
#تعریف_کن SIGINT 2
#تعریف_کن	SIGQUIT	3	/* quit */
#تعریف_کن SIGILL 4
#تعریف_کن	SIGTRAP	5	/* trace trap (not reset when caught) */
#تعریف_کن	SIGIOT	6	/* IOT instruction */
#تعریف_کن	SIGABRT 6	/* used by abort, replace SIGIOT in the future */
#تعریف_کن	SIGEMT	7	/* EMT instruction */
#تعریف_کن SIGFPE 8
#تعریف_کن	SIGKILL	9	/* kill (cannot be caught or ignored) */
#تعریف_کن	SIGBUS	10	/* bus error */
#تعریف_کن SIGSEGV 11
#تعریف_کن	SIGSYS	12	/* bad argument to system call */
#تعریف_کن	SIGPIPE	13	/* write on a pipe with no one to read it */
#اگر_تعریف_شده __USE_MINGW_ALARM
#تعریف_کن	SIGALRM	14	/* alarm clock */
#پایان_اگر
#تعریف_کن SIGTERM 15
#تعریف_کن SIGBREAK 21
#تعریف_کن SIGABRT2 22

#تعریف_کن SIGABRT_COMPAT 6

  تعريفنوع	فراغ (*__p_sig_fn_t)(صحيح);

#تعریف_کن SIG_DFL (__p_sig_fn_t)0
#تعریف_کن SIG_IGN (__p_sig_fn_t)1
#تعریف_کن SIG_GET (__p_sig_fn_t)2
#تعریف_کن SIG_SGE (__p_sig_fn_t)3
#تعریف_کن SIG_ACK (__p_sig_fn_t)4
#تعریف_کن SIG_ERR (__p_sig_fn_t)-1

  خارجي فراغ **__cdecl __pxcptinfoptrs(فراغ);
#تعریف_کن _pxcptinfoptrs (*__pxcptinfoptrs())

  __p_sig_fn_t __cdecl إشارة(صحيح Sig_رقم_2,__p_sig_fn_t _Func);
  صحيح __cdecl ارفع(صحيح Sig_رقم_2);

#اگر_تعریف_شده __cplusplus
}
#پایان_اگر
#پایان_اگر
