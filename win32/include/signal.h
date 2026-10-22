/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#यदि_अपरिभाषितम् _INC_SIGNAL
#परिभाषय _INC_SIGNAL

#अन्तर्भाव <_mingw.h>

#यदि_परिभाषितम् __cplusplus
बाह्य "C" {
#यदि_अन्तः

#यदि_अपरिभाषितम् _SIG_ATOMIC_T_DEFINED
#परिभाषय _SIG_ATOMIC_T_DEFINED
  प्रकारनिर्देश पूर्णाङ्क sig_atomic_t;
#यदि_अन्तः

#परिभाषय NSIG 23

#परिभाषय	SIGHUP	1	/* hangup */
#परिभाषय SIGINT 2
#परिभाषय	SIGQUIT	3	/* quit */
#परिभाषय SIGILL 4
#परिभाषय	SIGTRAP	5	/* trace trap (not reset when caught) */
#परिभाषय	SIGIOT	6	/* IOT instruction */
#परिभाषय	SIGABRT 6	/* used by abort, replace SIGIOT in the future */
#परिभाषय	SIGEMT	7	/* EMT instruction */
#परिभाषय SIGFPE 8
#परिभाषय	SIGKILL	9	/* kill (cannot be caught or ignored) */
#परिभाषय	SIGBUS	10	/* bus error */
#परिभाषय SIGSEGV 11
#परिभाषय	SIGSYS	12	/* bad argument to system call */
#परिभाषय	SIGPIPE	13	/* write on a pipe with no one to read it */
#यदि_परिभाषितम् __USE_MINGW_ALARM
#परिभाषय	SIGALRM	14	/* alarm clock */
#यदि_अन्तः
#परिभाषय SIGTERM 15
#परिभाषय SIGBREAK 21
#परिभाषय SIGABRT2 22

#परिभाषय SIGABRT_COMPAT 6

  प्रकारनिर्देश	शून्य (*__p_sig_fn_t)(पूर्णाङ्क);

#परिभाषय SIG_DFL (__p_sig_fn_t)0
#परिभाषय SIG_IGN (__p_sig_fn_t)1
#परिभाषय SIG_GET (__p_sig_fn_t)2
#परिभाषय SIG_SGE (__p_sig_fn_t)3
#परिभाषय SIG_ACK (__p_sig_fn_t)4
#परिभाषय SIG_ERR (__p_sig_fn_t)-1

  बाह्य शून्य **__cdecl __pxcptinfoptrs(शून्य);
#परिभाषय _pxcptinfoptrs (*__pxcptinfoptrs())

  __p_sig_fn_t __cdecl सङ्केत(पूर्णाङ्क Sig_अङ्कः_2,__p_sig_fn_t _Func);
  पूर्णाङ्क __cdecl उत्थापय(पूर्णाङ्क Sig_अङ्कः_2);

#यदि_परिभाषितम् __cplusplus
}
#यदि_अन्तः
#यदि_अन्तः
