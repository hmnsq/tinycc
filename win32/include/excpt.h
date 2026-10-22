/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جيڪڏهن_وصف_نه_ٿيل _INC_EXCPT
#وصف_ڪريو _INC_EXCPT

#ضمن <_mingw.h>

#هدايت pack(ڌڪو,_CRT_PACKING)

#جيڪڏهن_وصف_ٿيل __cplusplus
خارجي "C" {
#جيڪڏهن_پورو

  بنية EXCEPTION_اشارا_2;

#جيڪڏهن_وصف_نه_ٿيل EXCEPTION_DISPOSITION
#وصف_ڪريو EXCEPTION_DISPOSITION   صحيح
#جيڪڏهن_پورو
#وصف_ڪريو ExceptionContinueExecution 0
#وصف_ڪريو Exception_Continue_ڳولا 1
#وصف_ڪريو ExceptionNestedException 2
#وصف_ڪريو ExceptionCollidedUnwind 3

#إذا (defined(_X86_) && !defined(__x86_64))
  بنية EXCEPTION_رڪارڊ;
  بنية _CONTEXT;

  EXCEPTION_DISPOSITION __cdecl _except_handler(بنية EXCEPTION_رڪارڊ *Exception_رڪارڊ_2,فراغ *Establisher_چوکٺو,بنية _CONTEXT *Context_رڪارڊ_2,فراغ *_DispatcherContext);
#وإلاإذا defined(__ia64__)

  تعريفنوع بنية EXCEPTION_اشارا_2 *Exception_info_ptr;
  بنية EXCEPTION_رڪارڊ;
  بنية _CONTEXT;
  بنية _DISPATCHER_CONTEXT;

  _CRTIMP EXCEPTION_DISPOSITION __cdecl __C_specific_handler (بنية EXCEPTION_رڪارڊ *Exception_رڪارڊ_2,بنانشان __int64 يادگيري_ڍير_Fp,بنانشان __int64 _BackingStoreFp,بنية _CONTEXT *Context_رڪارڊ_2,بنية _DISPATCHER_CONTEXT *_DispatcherContext,بنانشان __int64 Global_اشارو);
#وإلاإذا defined(__x86_64)

  بنية EXCEPTION_رڪارڊ;
  بنية _CONTEXT;
#جيڪڏهن_پورو

#وصف_ڪريو Get_Exception_ڪوڊ exception_ڪوڊ
#وصف_ڪريو exception_ڪوڊ_2 exception_ڪوڊ
#وصف_ڪريو GetExceptionInformation (بنية EXCEPTION_اشارا_2 *)_exception_info
#وصف_ڪريو exception_info (بنية EXCEPTION_اشارا_2 *)_exception_info
#وصف_ڪريو AbnormalTermination _abnormal_termination
#وصف_ڪريو abnormal_termination _abnormal_termination

  بنانشان ڊگهو __cdecl exception_ڪوڊ(فراغ);
  فراغ *__cdecl _exception_info(فراغ);
  صحيح __cdecl _abnormal_termination(فراغ);

#وصف_ڪريو EXCEPTION_EXECUTE_HANDLER 1
#وصف_ڪريو EXCEPTION_CONTINUE_ڳولا 0
#وصف_ڪريو EXCEPTION_CONTINUE_EXECUTION -1

  /* CRT stuff */
  تعريفنوع فراغ (__cdecl * _PHNDLR)(صحيح);

  بنية _XCPT_ACTION {
    بنانشان ڊگهو Xcpt_انگ;
    صحيح Sig_انگ;
    _PHNDLR XcptAction;
  };

  خارجي بنية _XCPT_ACTION _XcptActTab[];
  خارجي صحيح Xcpt_Act_Tab_ڳڻپ;
  خارجي صحيح Xcpt_Act_Tab_سائيز;
  خارجي صحيح پهريون_FPE_Indx;
  خارجي صحيح انگ_FPE;

  صحيح __cdecl __CppXcptFilter(بنانشان ڊگهو Exception_انگ,بنية EXCEPTION_اشارا_2 * _ExceptionPtr);
  صحيح __cdecl _XcptFilter(بنانشان ڊگهو Exception_انگ,بنية EXCEPTION_اشارا_2 * _ExceptionPtr);

  /*
  * The type of function that is expected as an exception handler to be
  * installed with _try1.
  */
  تعريفنوع EXCEPTION_DISPOSITION (*PEXCEPTION_HANDLER)(بنية EXCEPTION_رڪارڊ*, فراغ*, بنية _CONTEXT*, فراغ*);

#جيڪڏهن_وصف_نه_ٿيل HAVE_NO_SEH
  /*
  * This is not entirely necessary, but it is the structure installed by
  * the _try1 primitive below.
  */
  تعريفنوع بنية _EXCEPTION_REGISTRATION {
    بنية _EXCEPTION_REGISTRATION *prev;
    EXCEPTION_DISPOSITION (*handler)(بنية EXCEPTION_رڪارڊ*, فراغ*, بنية _CONTEXT*, فراغ*);
  } EXCEPTION_REGISTRATION, *PEXCEPTION_REGISTRATION;

  تعريفنوع EXCEPTION_REGISTRATION EXCEPTION_REGISTRATION_رڪارڊ;
  تعريفنوع PEXCEPTION_REGISTRATION PEXCEPTION_REGISTRATION_رڪارڊ;
#جيڪڏهن_پورو

#إذا (defined(_X86_) && !defined(__x86_64))
#وصف_ڪريو __try1(pHandler) \
  __asm__ ("pushl %0;pushl %%fs:0;movl %%esp,%%fs:0;" : : "g" (pHandler));

#وصف_ڪريو	__except1	\
  __asm__ ("movl (%%esp),%%eax;movl %%eax,%%fs:0;addl $8,%%esp;" \
  : : : "%eax");
#وإلاإذا defined(__x86_64)
#وصف_ڪريو __try1(pHandler) \
  __asm__ ("pushq %0;pushq %%gs:0;movq %%rsp,%%gs:0;" : : "g" (pHandler));

#وصف_ڪريو	__except1	\
  __asm__ ("movq (%%rsp),%%rax;movq %%rax,%%gs:0;addq $16,%%rsp;" \
  : : : "%rax");
#وإلا
#وصف_ڪريو __try1(pHandler)
#وصف_ڪريو __except1
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل __cplusplus
}
#جيڪڏهن_پورو

#هدايت pack(ڪڍو)
#جيڪڏهن_پورو
