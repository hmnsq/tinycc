/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جے_بنا_تعریف _INC_EXCPT
#تعریف_کرو _INC_EXCPT

#ضمن <_mingw.h>

#ہدایت pack(ڈالو,_CRT_PACKING)

#جے_تعریف_شدہ __cplusplus
خارجي "C" {
#جے_انت

  بنية EXCEPTION_سوچکاں_2;

#جے_بنا_تعریف EXCEPTION_DISPOSITION
#تعریف_کرو EXCEPTION_DISPOSITION   صحيح
#جے_انت
#تعریف_کرو ExceptionContinueExecution 0
#تعریف_کرو Exception_Continue_تلاش 1
#تعریف_کرو ExceptionNestedException 2
#تعریف_کرو ExceptionCollidedUnwind 3

#إذا (defined(_X86_) && !defined(__x86_64))
  بنية EXCEPTION_ریکارڈ;
  بنية _CONTEXT;

  EXCEPTION_DISPOSITION __cdecl _except_handler(بنية EXCEPTION_ریکارڈ *Exception_ریکارڈ_2,فراغ *Establisher_چوکھٹا,بنية _CONTEXT *Context_ریکارڈ_2,فراغ *_DispatcherContext);
#وإلاإذا defined(__ia64__)

  تعريفنوع بنية EXCEPTION_سوچکاں_2 *Exception_info_ptr;
  بنية EXCEPTION_ریکارڈ;
  بنية _CONTEXT;
  بنية _DISPATCHER_CONTEXT;

  _CRTIMP EXCEPTION_DISPOSITION __cdecl __C_specific_handler (بنية EXCEPTION_ریکارڈ *Exception_ریکارڈ_2,بنانشانی __int64 حافظہ_ڈھیر_Fp,بنانشانی __int64 _BackingStoreFp,بنية _CONTEXT *Context_ریکارڈ_2,بنية _DISPATCHER_CONTEXT *_DispatcherContext,بنانشانی __int64 Global_اشارہ_گر);
#وإلاإذا defined(__x86_64)

  بنية EXCEPTION_ریکارڈ;
  بنية _CONTEXT;
#جے_انت

#تعریف_کرو Get_Exception_کوڈ exception_کوڈ
#تعریف_کرو exception_کوڈ_2 exception_کوڈ
#تعریف_کرو GetExceptionInformation (بنية EXCEPTION_سوچکاں_2 *)_exception_info
#تعریف_کرو exception_info (بنية EXCEPTION_سوچکاں_2 *)_exception_info
#تعریف_کرو AbnormalTermination _abnormal_termination
#تعریف_کرو abnormal_termination _abnormal_termination

  بنانشانی لما __cdecl exception_کوڈ(فراغ);
  فراغ *__cdecl _exception_info(فراغ);
  صحيح __cdecl _abnormal_termination(فراغ);

#تعریف_کرو EXCEPTION_EXECUTE_HANDLER 1
#تعریف_کرو EXCEPTION_CONTINUE_تلاش 0
#تعریف_کرو EXCEPTION_CONTINUE_EXECUTION -1

  /* CRT stuff */
  تعريفنوع فراغ (__cdecl * _PHNDLR)(صحيح);

  بنية _XCPT_ACTION {
    بنانشانی لما Xcpt_عدد;
    صحيح Sig_عدد;
    _PHNDLR XcptAction;
  };

  خارجي بنية _XCPT_ACTION _XcptActTab[];
  خارجي صحيح Xcpt_Act_Tab_گنتی;
  خارجي صحيح Xcpt_Act_Tab_ناپ;
  خارجي صحيح پہلا_FPE_Indx;
  خارجي صحيح عدد_FPE;

  صحيح __cdecl __CppXcptFilter(بنانشانی لما Exception_عدد,بنية EXCEPTION_سوچکاں_2 * _ExceptionPtr);
  صحيح __cdecl _XcptFilter(بنانشانی لما Exception_عدد,بنية EXCEPTION_سوچکاں_2 * _ExceptionPtr);

  /*
  * The type of function that is expected as an exception handler to be
  * installed with _try1.
  */
  تعريفنوع EXCEPTION_DISPOSITION (*PEXCEPTION_HANDLER)(بنية EXCEPTION_ریکارڈ*, فراغ*, بنية _CONTEXT*, فراغ*);

#جے_بنا_تعریف HAVE_NO_SEH
  /*
  * This is not entirely necessary, but it is the structure installed by
  * the _try1 primitive below.
  */
  تعريفنوع بنية _EXCEPTION_REGISTRATION {
    بنية _EXCEPTION_REGISTRATION *prev;
    EXCEPTION_DISPOSITION (*handler)(بنية EXCEPTION_ریکارڈ*, فراغ*, بنية _CONTEXT*, فراغ*);
  } EXCEPTION_REGISTRATION, *PEXCEPTION_REGISTRATION;

  تعريفنوع EXCEPTION_REGISTRATION EXCEPTION_REGISTRATION_ریکارڈ;
  تعريفنوع PEXCEPTION_REGISTRATION PEXCEPTION_REGISTRATION_ریکارڈ;
#جے_انت

#إذا (defined(_X86_) && !defined(__x86_64))
#تعریف_کرو __try1(pHandler) \
  __asm__ ("pushl %0;pushl %%fs:0;movl %%esp,%%fs:0;" : : "g" (pHandler));

#تعریف_کرو	__except1	\
  __asm__ ("movl (%%esp),%%eax;movl %%eax,%%fs:0;addl $8,%%esp;" \
  : : : "%eax");
#وإلاإذا defined(__x86_64)
#تعریف_کرو __try1(pHandler) \
  __asm__ ("pushq %0;pushq %%gs:0;movq %%rsp,%%gs:0;" : : "g" (pHandler));

#تعریف_کرو	__except1	\
  __asm__ ("movq (%%rsp),%%rax;movq %%rax,%%gs:0;addq $16,%%rsp;" \
  : : : "%rax");
#وإلا
#تعریف_کرو __try1(pHandler)
#تعریف_کرو __except1
#جے_انت

#جے_تعریف_شدہ __cplusplus
}
#جے_انت

#ہدایت pack(نکالو)
#جے_انت
