/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_تعریف_نشده _INC_EXCPT
#تعریف_کن _INC_EXCPT

#ضمن <_mingw.h>

#رهنمود pack(افزودن,_CRT_PACKING)

#اگر_تعریف_شده __cplusplus
خارجي "C" {
#پایان_اگر

  بنية EXCEPTION_اشارهگرها_2;

#اگر_تعریف_نشده EXCEPTION_DISPOSITION
#تعریف_کن EXCEPTION_DISPOSITION   صحيح
#پایان_اگر
#تعریف_کن ExceptionContinueExecution 0
#تعریف_کن Exception_Continue_جستجو 1
#تعریف_کن ExceptionNestedException 2
#تعریف_کن ExceptionCollidedUnwind 3

#إذا (defined(_X86_) && !defined(__x86_64))
  بنية EXCEPTION_رکورد;
  بنية _CONTEXT;

  EXCEPTION_DISPOSITION __cdecl _except_handler(بنية EXCEPTION_رکورد *Exception_رکورد_2,فراغ *Establisher_قاب,بنية _CONTEXT *Context_رکورد_2,فراغ *_DispatcherContext);
#وإلاإذا defined(__ia64__)

  تعريفنوع بنية EXCEPTION_اشارهگرها_2 *Exception_info_ptr;
  بنية EXCEPTION_رکورد;
  بنية _CONTEXT;
  بنية _DISPATCHER_CONTEXT;

  _CRTIMP EXCEPTION_DISPOSITION __cdecl __C_specific_handler (بنية EXCEPTION_رکورد *Exception_رکورد_2,بیعلامت __int64 حافظه_پشته_Fp,بیعلامت __int64 _BackingStoreFp,بنية _CONTEXT *Context_رکورد_2,بنية _DISPATCHER_CONTEXT *_DispatcherContext,بیعلامت __int64 Global_اشاره_گر);
#وإلاإذا defined(__x86_64)

  بنية EXCEPTION_رکورد;
  بنية _CONTEXT;
#پایان_اگر

#تعریف_کن Get_Exception_کد exception_کد
#تعریف_کن exception_کد_2 exception_کد
#تعریف_کن GetExceptionInformation (بنية EXCEPTION_اشارهگرها_2 *)_exception_info
#تعریف_کن exception_info (بنية EXCEPTION_اشارهگرها_2 *)_exception_info
#تعریف_کن AbnormalTermination _abnormal_termination
#تعریف_کن abnormal_termination _abnormal_termination

  بیعلامت دراز __cdecl exception_کد(فراغ);
  فراغ *__cdecl _exception_info(فراغ);
  صحيح __cdecl _abnormal_termination(فراغ);

#تعریف_کن EXCEPTION_EXECUTE_HANDLER 1
#تعریف_کن EXCEPTION_CONTINUE_جستجو 0
#تعریف_کن EXCEPTION_CONTINUE_EXECUTION -1

  /* CRT stuff */
  تعريفنوع فراغ (__cdecl * _PHNDLR)(صحيح);

  بنية _XCPT_ACTION {
    بیعلامت دراز Xcpt_رقم;
    صحيح Sig_رقم;
    _PHNDLR XcptAction;
  };

  خارجي بنية _XCPT_ACTION _XcptActTab[];
  خارجي صحيح Xcpt_Act_Tab_شمار;
  خارجي صحيح Xcpt_Act_Tab_اندازه;
  خارجي صحيح اولی_FPE_Indx;
  خارجي صحيح رقم_FPE;

  صحيح __cdecl __CppXcptFilter(بیعلامت دراز Exception_رقم,بنية EXCEPTION_اشارهگرها_2 * _ExceptionPtr);
  صحيح __cdecl _XcptFilter(بیعلامت دراز Exception_رقم,بنية EXCEPTION_اشارهگرها_2 * _ExceptionPtr);

  /*
  * The type of function that is expected as an exception handler to be
  * installed with _try1.
  */
  تعريفنوع EXCEPTION_DISPOSITION (*PEXCEPTION_HANDLER)(بنية EXCEPTION_رکورد*, فراغ*, بنية _CONTEXT*, فراغ*);

#اگر_تعریف_نشده HAVE_NO_SEH
  /*
  * This is not entirely necessary, but it is the structure installed by
  * the _try1 primitive below.
  */
  تعريفنوع بنية _EXCEPTION_REGISTRATION {
    بنية _EXCEPTION_REGISTRATION *prev;
    EXCEPTION_DISPOSITION (*handler)(بنية EXCEPTION_رکورد*, فراغ*, بنية _CONTEXT*, فراغ*);
  } EXCEPTION_REGISTRATION, *PEXCEPTION_REGISTRATION;

  تعريفنوع EXCEPTION_REGISTRATION EXCEPTION_REGISTRATION_رکورد;
  تعريفنوع PEXCEPTION_REGISTRATION PEXCEPTION_REGISTRATION_رکورد;
#پایان_اگر

#إذا (defined(_X86_) && !defined(__x86_64))
#تعریف_کن __try1(pHandler) \
  __asm__ ("pushl %0;pushl %%fs:0;movl %%esp,%%fs:0;" : : "g" (pHandler));

#تعریف_کن	__except1	\
  __asm__ ("movl (%%esp),%%eax;movl %%eax,%%fs:0;addl $8,%%esp;" \
  : : : "%eax");
#وإلاإذا defined(__x86_64)
#تعریف_کن __try1(pHandler) \
  __asm__ ("pushq %0;pushq %%gs:0;movq %%rsp,%%gs:0;" : : "g" (pHandler));

#تعریف_کن	__except1	\
  __asm__ ("movq (%%rsp),%%rax;movq %%rax,%%gs:0;addq $16,%%rsp;" \
  : : : "%rax");
#وإلا
#تعریف_کن __try1(pHandler)
#تعریف_کن __except1
#پایان_اگر

#اگر_تعریف_شده __cplusplus
}
#پایان_اگر

#رهنمود pack(برداشت)
#پایان_اگر
