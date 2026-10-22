/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#अगर_अघोषित _INC_SIGNAL
#घोषणा _INC_SIGNAL

#समावेश <_mingw.h>

#अगर_घोषित __cplusplus
बाह्य "C" {
#पूर्ण_अगर

#अगर_अघोषित _SIG_ATOMIC_T_DEFINED
#घोषणा _SIG_ATOMIC_T_DEFINED
  प्रकार पूर्णांक संक_पूर्ण_प्रकार;
#पूर्ण_अगर

#घोषणा NSIG 23

#घोषणा	SIGHUP	1	/* hangup */
#घोषणा संक_विघ्न 2
#घोषणा	SIGQUIT	3	/* quit */
#घोषणा संक_अवैध 4
#घोषणा	SIGTRAP	5	/* trace trap (not reset when caught) */
#घोषणा	SIGIOT	6	/* IOT instruction */
#घोषणा	SIGABRT 6	/* used by abort, replace SIGIOT in the future */
#घोषणा	SIGEMT	7	/* EMT instruction */
#घोषणा संक_भ_त्रुटि 8
#घोषणा	SIGKILL	9	/* kill (cannot be caught or ignored) */
#घोषणा	SIGBUS	10	/* bus error */
#घोषणा संक_अंश 11
#घोषणा	SIGSYS	12	/* bad argument to system call */
#घोषणा	SIGPIPE	13	/* write on a pipe with no one to read it */
#अगर_घोषित __USE_MINGW_ALARM
#घोषणा	SIGALRM	14	/* alarm clock */
#पूर्ण_अगर
#घोषणा संक_इति 15
#घोषणा SIGBREAK 21
#घोषणा SIGABRT2 22

#घोषणा SIGABRT_COMPAT 6

  प्रकार	व्योम (*__p_sig_fn_t)(पूर्णांक);

#घोषणा संक_पूर्व (__p_sig_fn_t)0
#घोषणा संक_छोड़ो (__p_sig_fn_t)1
#घोषणा SIG_GET (__p_sig_fn_t)2
#घोषणा SIG_SGE (__p_sig_fn_t)3
#घोषणा SIG_ACK (__p_sig_fn_t)4
#घोषणा संक_त्रुटि (__p_sig_fn_t)-1

  बाह्य व्योम **__cdecl __pxcptinfoptrs(व्योम);
#घोषणा _pxcptinfoptrs (*__pxcptinfoptrs())

  __p_sig_fn_t __cdecl संकेत(पूर्णांक Sig_अंक_2,__p_sig_fn_t _Func);
  पूर्णांक __cdecl उठाओ(पूर्णांक Sig_अंक_2);

#अगर_घोषित __cplusplus
}
#पूर्ण_अगर
#पूर्ण_अगर
