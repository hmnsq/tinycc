/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#که_نه_تعریف_شوی _INC_SIGNAL
#تعریف_کړه _INC_SIGNAL

#ضمن <_mingw.h>

#که_تعریف_شوی __cplusplus
خارجي "C" {
#د_که_پای

#که_نه_تعریف_شوی _SIG_ATOMIC_T_DEFINED
#تعریف_کړه _SIG_ATOMIC_T_DEFINED
  تعريفنوع صحيح sig_atomic_t;
#د_که_پای

#تعریف_کړه NSIG 23

#تعریف_کړه	SIGHUP	1	/* hangup */
#تعریف_کړه SIGINT 2
#تعریف_کړه	SIGQUIT	3	/* quit */
#تعریف_کړه SIGILL 4
#تعریف_کړه	SIGTRAP	5	/* trace trap (not reset when caught) */
#تعریف_کړه	SIGIOT	6	/* IOT instruction */
#تعریف_کړه	SIGABRT 6	/* used by abort, replace SIGIOT in the future */
#تعریف_کړه	SIGEMT	7	/* EMT instruction */
#تعریف_کړه SIGFPE 8
#تعریف_کړه	SIGKILL	9	/* kill (cannot be caught or ignored) */
#تعریف_کړه	SIGBUS	10	/* bus error */
#تعریف_کړه SIGSEGV 11
#تعریف_کړه	SIGSYS	12	/* bad argument to system call */
#تعریف_کړه	SIGPIPE	13	/* write on a pipe with no one to read it */
#که_تعریف_شوی __USE_MINGW_ALARM
#تعریف_کړه	SIGALRM	14	/* alarm clock */
#د_که_پای
#تعریف_کړه SIGTERM 15
#تعریف_کړه SIGBREAK 21
#تعریف_کړه SIGABRT2 22

#تعریف_کړه SIGABRT_COMPAT 6

  تعريفنوع	فراغ (*__p_sig_fn_t)(صحيح);

#تعریف_کړه SIG_DFL (__p_sig_fn_t)0
#تعریف_کړه SIG_IGN (__p_sig_fn_t)1
#تعریف_کړه SIG_GET (__p_sig_fn_t)2
#تعریف_کړه SIG_SGE (__p_sig_fn_t)3
#تعریف_کړه SIG_ACK (__p_sig_fn_t)4
#تعریف_کړه SIG_ERR (__p_sig_fn_t)-1

  خارجي فراغ **__cdecl __pxcptinfoptrs(فراغ);
#تعریف_کړه _pxcptinfoptrs (*__pxcptinfoptrs())

  __p_sig_fn_t __cdecl إشارة(صحيح Sig_عدد_2,__p_sig_fn_t _Func);
  صحيح __cdecl ارفع(صحيح Sig_عدد_2);

#که_تعریف_شوی __cplusplus
}
#د_که_پای
#د_که_پای
