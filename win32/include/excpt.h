/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_غیر_تعریف_شدہ _INC_EXCPT
#تعریف_کرو _INC_EXCPT

#شامل <_mingw.h>

#ہدایت pack(ڈالو,_CRT_PACKING)

#اگر_تعریف_شدہ __cplusplus
خارجی "C" {
#اگر_ختم

  ساخت EXCEPTION_اشارے_2;

#اگر_غیر_تعریف_شدہ EXCEPTION_DISPOSITION
#تعریف_کرو EXCEPTION_DISPOSITION   صحیح
#اگر_ختم
#تعریف_کرو ExceptionContinueExecution 0
#تعریف_کرو Exception_Continue_تلاش 1
#تعریف_کرو ExceptionNestedException 2
#تعریف_کرو ExceptionCollidedUnwind 3

#اگر (defined(_X86_) && !defined(__x86_64))
  ساخت EXCEPTION_ریکارڈ;
  ساخت _CONTEXT;

  EXCEPTION_DISPOSITION __cdecl _except_handler(ساخت EXCEPTION_ریکارڈ *Exception_ریکارڈ_2,خالی *Establisher_چوکھٹا,ساخت _CONTEXT *Context_ریکارڈ_2,خالی *_DispatcherContext);
#وگرنہ_اگر defined(__ia64__)

  قسمتعریف ساخت EXCEPTION_اشارے_2 *Exception_info_ptr;
  ساخت EXCEPTION_ریکارڈ;
  ساخت _CONTEXT;
  ساخت _DISPATCHER_CONTEXT;

  _CRTIMP EXCEPTION_DISPOSITION __cdecl __C_specific_handler (ساخت EXCEPTION_ریکارڈ *Exception_ریکارڈ_2,غیرعلامتی __int64 حافظہ_ڈھیر_Fp,غیرعلامتی __int64 _BackingStoreFp,ساخت _CONTEXT *Context_ریکارڈ_2,ساخت _DISPATCHER_CONTEXT *_DispatcherContext,غیرعلامتی __int64 Global_اشارہ_گر);
#وگرنہ_اگر defined(__x86_64)

  ساخت EXCEPTION_ریکارڈ;
  ساخت _CONTEXT;
#اگر_ختم

#تعریف_کرو Get_Exception_رمز exception_رمز
#تعریف_کرو exception_رمز_2 exception_رمز
#تعریف_کرو GetExceptionInformation (ساخت EXCEPTION_اشارے_2 *)_exception_info
#تعریف_کرو exception_info (ساخت EXCEPTION_اشارے_2 *)_exception_info
#تعریف_کرو AbnormalTermination _abnormal_termination
#تعریف_کرو abnormal_termination _abnormal_termination

  غیرعلامتی طویل __cdecl exception_رمز(خالی);
  خالی *__cdecl _exception_info(خالی);
  صحیح __cdecl _abnormal_termination(خالی);

#تعریف_کرو EXCEPTION_EXECUTE_HANDLER 1
#تعریف_کرو EXCEPTION_CONTINUE_تلاش 0
#تعریف_کرو EXCEPTION_CONTINUE_EXECUTION -1

  /* CRT stuff */
  قسمتعریف خالی (__cdecl * _PHNDLR)(صحیح);

  ساخت _XCPT_ACTION {
    غیرعلامتی طویل Xcpt_عدد;
    صحیح Sig_عدد;
    _PHNDLR XcptAction;
  };

  خارجی ساخت _XCPT_ACTION _XcptActTab[];
  خارجی صحیح Xcpt_Act_Tab_گنتی;
  خارجی صحیح Xcpt_Act_Tab_سائز;
  خارجی صحیح پہلا_FPE_Indx;
  خارجی صحیح عدد_FPE;

  صحیح __cdecl __CppXcptFilter(غیرعلامتی طویل Exception_عدد,ساخت EXCEPTION_اشارے_2 * _ExceptionPtr);
  صحیح __cdecl _XcptFilter(غیرعلامتی طویل Exception_عدد,ساخت EXCEPTION_اشارے_2 * _ExceptionPtr);

  /*
  * The type of function that is expected as an exception handler to be
  * installed with _try1.
  */
  قسمتعریف EXCEPTION_DISPOSITION (*PEXCEPTION_HANDLER)(ساخت EXCEPTION_ریکارڈ*, خالی*, ساخت _CONTEXT*, خالی*);

#اگر_غیر_تعریف_شدہ HAVE_NO_SEH
  /*
  * This is not entirely necessary, but it is the structure installed by
  * the _try1 primitive below.
  */
  قسمتعریف ساخت _EXCEPTION_REGISTRATION {
    ساخت _EXCEPTION_REGISTRATION *پچھلا;
    EXCEPTION_DISPOSITION (*handler)(ساخت EXCEPTION_ریکارڈ*, خالی*, ساخت _CONTEXT*, خالی*);
  } EXCEPTION_REGISTRATION, *PEXCEPTION_REGISTRATION;

  قسمتعریف EXCEPTION_REGISTRATION EXCEPTION_REGISTRATION_ریکارڈ;
  قسمتعریف PEXCEPTION_REGISTRATION PEXCEPTION_REGISTRATION_ریکارڈ;
#اگر_ختم

#اگر (defined(_X86_) && !defined(__x86_64))
#تعریف_کرو __try1(pHandler) \
  __asm__ ("pushl %0;pushl %%fs:0;movl %%esp,%%fs:0;" : : "g" (pHandler));

#تعریف_کرو	__except1	\
  __asm__ ("movl (%%esp),%%eax;movl %%eax,%%fs:0;addl $8,%%esp;" \
  : : : "%eax");
#وگرنہ_اگر defined(__x86_64)
#تعریف_کرو __try1(pHandler) \
  __asm__ ("pushq %0;pushq %%gs:0;movq %%rsp,%%gs:0;" : : "g" (pHandler));

#تعریف_کرو	__except1	\
  __asm__ ("movq (%%rsp),%%rax;movq %%rax,%%gs:0;addq $16,%%rsp;" \
  : : : "%rax");
#ورنہ
#تعریف_کرو __try1(pHandler)
#تعریف_کرو __except1
#اگر_ختم

#اگر_تعریف_شدہ __cplusplus
}
#اگر_ختم

#ہدایت pack(نکالو)
#اگر_ختم
