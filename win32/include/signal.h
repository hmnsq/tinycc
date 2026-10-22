/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_غیر_تعریف_شدہ _INC_SIGNAL
#تعریف_کرو _INC_SIGNAL

#شامل <_mingw.h>

#اگر_تعریف_شدہ __cplusplus
خارجی "C" {
#اگر_ختم

#اگر_غیر_تعریف_شدہ _SIG_ATOMIC_T_DEFINED
#تعریف_کرو _SIG_ATOMIC_T_DEFINED
  قسمتعریف صحیح sig_atomic_t;
#اگر_ختم

#تعریف_کرو NSIG 23

#تعریف_کرو	SIGHUP	1	/* hangup */
#تعریف_کرو SIGINT 2
#تعریف_کرو	SIGQUIT	3	/* quit */
#تعریف_کرو SIGILL 4
#تعریف_کرو	SIGTRAP	5	/* trace trap (not reset when caught) */
#تعریف_کرو	SIGIOT	6	/* IOT instruction */
#تعریف_کرو	SIGABRT 6	/* used by abort, replace SIGIOT in the future */
#تعریف_کرو	SIGEMT	7	/* EMT instruction */
#تعریف_کرو SIGFPE 8
#تعریف_کرو	SIGKILL	9	/* kill (cannot be caught or ignored) */
#تعریف_کرو	SIGBUS	10	/* bus error */
#تعریف_کرو SIGSEGV 11
#تعریف_کرو	SIGSYS	12	/* bad argument to system call */
#تعریف_کرو	SIGPIPE	13	/* write on a pipe with no one to read it */
#اگر_تعریف_شدہ __USE_MINGW_ALARM
#تعریف_کرو	SIGALRM	14	/* alarm clock */
#اگر_ختم
#تعریف_کرو SIGTERM 15
#تعریف_کرو SIGBREAK 21
#تعریف_کرو SIGABRT2 22

#تعریف_کرو SIGABRT_COMPAT 6

  قسمتعریف	خالی (*__p_sig_fn_t)(صحیح);

#تعریف_کرو SIG_DFL (__p_sig_fn_t)0
#تعریف_کرو SIG_IGN (__p_sig_fn_t)1
#تعریف_کرو SIG_GET (__p_sig_fn_t)2
#تعریف_کرو SIG_SGE (__p_sig_fn_t)3
#تعریف_کرو SIG_ACK (__p_sig_fn_t)4
#تعریف_کرو SIG_ERR (__p_sig_fn_t)-1

  خارجی خالی **__cdecl __pxcptinfoptrs(خالی);
#تعریف_کرو _pxcptinfoptrs (*__pxcptinfoptrs())

  __p_sig_fn_t __cdecl اشارہ(صحیح Sig_عدد_2,__p_sig_fn_t _Func);
  صحیح __cdecl اٹھاؤ(صحیح Sig_عدد_2);

#اگر_تعریف_شدہ __cplusplus
}
#اگر_ختم
#اگر_ختم
