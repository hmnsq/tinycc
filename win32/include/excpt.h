/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#که_نه_تعریف_شوی _INC_EXCPT
#تعریف_کړه _INC_EXCPT

#ضمن <_mingw.h>

#لارښوونه pack(ټېل,_CRT_PACKING)

#که_تعریف_شوی __cplusplus
خارجي "C" {
#د_که_پای

  بنية EXCEPTION_اشارې_2;

#که_نه_تعریف_شوی EXCEPTION_DISPOSITION
#تعریف_کړه EXCEPTION_DISPOSITION   صحيح
#د_که_پای
#تعریف_کړه ExceptionContinueExecution 0
#تعریف_کړه Exception_Continue_پلټنه 1
#تعریف_کړه ExceptionNestedException 2
#تعریف_کړه ExceptionCollidedUnwind 3

#إذا (defined(_X86_) && !defined(__x86_64))
  بنية EXCEPTION_ریکارډ;
  بنية _CONTEXT;

  EXCEPTION_DISPOSITION __cdecl _except_handler(بنية EXCEPTION_ریکارډ *Exception_ریکارډ_2,فراغ *Establisher_چوکاټ,بنية _CONTEXT *Context_ریکارډ_2,فراغ *_DispatcherContext);
#وإلاإذا defined(__ia64__)

  تعريفنوع بنية EXCEPTION_اشارې_2 *Exception_info_ptr;
  بنية EXCEPTION_ریکارډ;
  بنية _CONTEXT;
  بنية _DISPATCHER_CONTEXT;

  _CRTIMP EXCEPTION_DISPOSITION __cdecl __C_specific_handler (بنية EXCEPTION_ریکارډ *Exception_ریکارډ_2,بینښه __int64 حافظه_ډېری_Fp,بینښه __int64 _BackingStoreFp,بنية _CONTEXT *Context_ریکارډ_2,بنية _DISPATCHER_CONTEXT *_DispatcherContext,بینښه __int64 Global_اشاره_ګر);
#وإلاإذا defined(__x86_64)

  بنية EXCEPTION_ریکارډ;
  بنية _CONTEXT;
#د_که_پای

#تعریف_کړه Get_Exception_کوډ exception_کوډ
#تعریف_کړه exception_کوډ_2 exception_کوډ
#تعریف_کړه GetExceptionInformation (بنية EXCEPTION_اشارې_2 *)_exception_info
#تعریف_کړه exception_info (بنية EXCEPTION_اشارې_2 *)_exception_info
#تعریف_کړه AbnormalTermination _abnormal_termination
#تعریف_کړه abnormal_termination _abnormal_termination

  بینښه اوږد __cdecl exception_کوډ(فراغ);
  فراغ *__cdecl _exception_info(فراغ);
  صحيح __cdecl _abnormal_termination(فراغ);

#تعریف_کړه EXCEPTION_EXECUTE_HANDLER 1
#تعریف_کړه EXCEPTION_CONTINUE_پلټنه 0
#تعریف_کړه EXCEPTION_CONTINUE_EXECUTION -1

  /* CRT stuff */
  تعريفنوع فراغ (__cdecl * _PHNDLR)(صحيح);

  بنية _XCPT_ACTION {
    بینښه اوږد Xcpt_عدد;
    صحيح Sig_عدد;
    _PHNDLR XcptAction;
  };

  خارجي بنية _XCPT_ACTION _XcptActTab[];
  خارجي صحيح Xcpt_Act_Tab_شمېر;
  خارجي صحيح Xcpt_Act_Tab_اندازه;
  خارجي صحيح لومړی_FPE_Indx;
  خارجي صحيح عدد_FPE;

  صحيح __cdecl __CppXcptFilter(بینښه اوږد Exception_عدد,بنية EXCEPTION_اشارې_2 * _ExceptionPtr);
  صحيح __cdecl _XcptFilter(بینښه اوږد Exception_عدد,بنية EXCEPTION_اشارې_2 * _ExceptionPtr);

  /*
  * The type of function that is expected as an exception handler to be
  * installed with _try1.
  */
  تعريفنوع EXCEPTION_DISPOSITION (*PEXCEPTION_HANDLER)(بنية EXCEPTION_ریکارډ*, فراغ*, بنية _CONTEXT*, فراغ*);

#که_نه_تعریف_شوی HAVE_NO_SEH
  /*
  * This is not entirely necessary, but it is the structure installed by
  * the _try1 primitive below.
  */
  تعريفنوع بنية _EXCEPTION_REGISTRATION {
    بنية _EXCEPTION_REGISTRATION *prev;
    EXCEPTION_DISPOSITION (*handler)(بنية EXCEPTION_ریکارډ*, فراغ*, بنية _CONTEXT*, فراغ*);
  } EXCEPTION_REGISTRATION, *PEXCEPTION_REGISTRATION;

  تعريفنوع EXCEPTION_REGISTRATION EXCEPTION_REGISTRATION_ریکارډ;
  تعريفنوع PEXCEPTION_REGISTRATION PEXCEPTION_REGISTRATION_ریکارډ;
#د_که_پای

#إذا (defined(_X86_) && !defined(__x86_64))
#تعریف_کړه __try1(pHandler) \
  __asm__ ("pushl %0;pushl %%fs:0;movl %%esp,%%fs:0;" : : "g" (pHandler));

#تعریف_کړه	__except1	\
  __asm__ ("movl (%%esp),%%eax;movl %%eax,%%fs:0;addl $8,%%esp;" \
  : : : "%eax");
#وإلاإذا defined(__x86_64)
#تعریف_کړه __try1(pHandler) \
  __asm__ ("pushq %0;pushq %%gs:0;movq %%rsp,%%gs:0;" : : "g" (pHandler));

#تعریف_کړه	__except1	\
  __asm__ ("movq (%%rsp),%%rax;movq %%rax,%%gs:0;addq $16,%%rsp;" \
  : : : "%rax");
#وإلا
#تعریف_کړه __try1(pHandler)
#تعریف_کړه __except1
#د_که_پای

#که_تعریف_شوی __cplusplus
}
#د_که_پای

#لارښوونه pack(راوباسه)
#د_که_پای
