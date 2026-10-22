/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#నిర్వచితం_కాకపోతే _INC_SIGNAL
#నిర్వచించు _INC_SIGNAL

#అన్తర్భావ <_mingw.h>

#నిర్వచితమైతే __cplusplus
బాహ్య "C" {
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _SIG_ATOMIC_T_DEFINED
#నిర్వచించు _SIG_ATOMIC_T_DEFINED
  రకనిర్వచనం పూర్ణాంకం sig_atomic_t;
#అయితే_ముగింపు

#నిర్వచించు NSIG 23

#నిర్వచించు	SIGHUP	1	/* hangup */
#నిర్వచించు SIGINT 2
#నిర్వచించు	SIGQUIT	3	/* quit */
#నిర్వచించు SIGILL 4
#నిర్వచించు	SIGTRAP	5	/* trace trap (not reset when caught) */
#నిర్వచించు	SIGIOT	6	/* IOT instruction */
#నిర్వచించు	SIGABRT 6	/* used by abort, replace SIGIOT in the future */
#నిర్వచించు	SIGEMT	7	/* EMT instruction */
#నిర్వచించు SIGFPE 8
#నిర్వచించు	SIGKILL	9	/* kill (cannot be caught or ignored) */
#నిర్వచించు	SIGBUS	10	/* bus error */
#నిర్వచించు SIGSEGV 11
#నిర్వచించు	SIGSYS	12	/* bad argument to system call */
#నిర్వచించు	SIGPIPE	13	/* write on a pipe with no one to read it */
#నిర్వచితమైతే __USE_MINGW_ALARM
#నిర్వచించు	SIGALRM	14	/* alarm clock */
#అయితే_ముగింపు
#నిర్వచించు SIGTERM 15
#నిర్వచించు SIGBREAK 21
#నిర్వచించు SIGABRT2 22

#నిర్వచించు SIGABRT_COMPAT 6

  రకనిర్వచనం	శూన్య (*__p_sig_fn_t)(పూర్ణాంకం);

#నిర్వచించు SIG_DFL (__p_sig_fn_t)0
#నిర్వచించు SIG_IGN (__p_sig_fn_t)1
#నిర్వచించు SIG_GET (__p_sig_fn_t)2
#నిర్వచించు SIG_SGE (__p_sig_fn_t)3
#నిర్వచించు SIG_ACK (__p_sig_fn_t)4
#నిర్వచించు SIG_ERR (__p_sig_fn_t)-1

  బాహ్య శూన్య **__cdecl __pxcptinfoptrs(శూన్య);
#నిర్వచించు _pxcptinfoptrs (*__pxcptinfoptrs())

  __p_sig_fn_t __cdecl సంకేతం(పూర్ణాంకం Sig_అంకె_2,__p_sig_fn_t _Func);
  పూర్ణాంకం __cdecl లేపు(పూర్ణాంకం Sig_అంకె_2);

#నిర్వచితమైతే __cplusplus
}
#అయితే_ముగింపు
#అయితే_ముగింపు
