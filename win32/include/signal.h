/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جيڪڏهن_وصف_نه_ٿيل _INC_SIGNAL
#وصف_ڪريو _INC_SIGNAL

#ضمن <_mingw.h>

#جيڪڏهن_وصف_ٿيل __cplusplus
خارجي "C" {
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _SIG_ATOMIC_T_DEFINED
#وصف_ڪريو _SIG_ATOMIC_T_DEFINED
  تعريفنوع صحيح sig_atomic_t;
#جيڪڏهن_پورو

#وصف_ڪريو NSIG 23

#وصف_ڪريو	SIGHUP	1	/* hangup */
#وصف_ڪريو SIGINT 2
#وصف_ڪريو	SIGQUIT	3	/* quit */
#وصف_ڪريو SIGILL 4
#وصف_ڪريو	SIGTRAP	5	/* trace trap (not reset when caught) */
#وصف_ڪريو	SIGIOT	6	/* IOT instruction */
#وصف_ڪريو	SIGABRT 6	/* used by abort, replace SIGIOT in the future */
#وصف_ڪريو	SIGEMT	7	/* EMT instruction */
#وصف_ڪريو SIGFPE 8
#وصف_ڪريو	SIGKILL	9	/* kill (cannot be caught or ignored) */
#وصف_ڪريو	SIGBUS	10	/* bus error */
#وصف_ڪريو SIGSEGV 11
#وصف_ڪريو	SIGSYS	12	/* bad argument to system call */
#وصف_ڪريو	SIGPIPE	13	/* write on a pipe with no one to read it */
#جيڪڏهن_وصف_ٿيل __USE_MINGW_ALARM
#وصف_ڪريو	SIGALRM	14	/* alarm clock */
#جيڪڏهن_پورو
#وصف_ڪريو SIGTERM 15
#وصف_ڪريو SIGBREAK 21
#وصف_ڪريو SIGABRT2 22

#وصف_ڪريو SIGABRT_COMPAT 6

  تعريفنوع	فراغ (*__p_sig_fn_t)(صحيح);

#وصف_ڪريو SIG_DFL (__p_sig_fn_t)0
#وصف_ڪريو SIG_IGN (__p_sig_fn_t)1
#وصف_ڪريو SIG_GET (__p_sig_fn_t)2
#وصف_ڪريو SIG_SGE (__p_sig_fn_t)3
#وصف_ڪريو SIG_ACK (__p_sig_fn_t)4
#وصف_ڪريو SIG_ERR (__p_sig_fn_t)-1

  خارجي فراغ **__cdecl __pxcptinfoptrs(فراغ);
#وصف_ڪريو _pxcptinfoptrs (*__pxcptinfoptrs())

  __p_sig_fn_t __cdecl إشارة(صحيح Sig_انگ_2,__p_sig_fn_t _Func);
  صحيح __cdecl ارفع(صحيح Sig_انگ_2);

#جيڪڏهن_وصف_ٿيل __cplusplus
}
#جيڪڏهن_پورو
#جيڪڏهن_پورو
