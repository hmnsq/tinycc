/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _INC_EXCPT
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _INC_EXCPT

#ਅਨ੍ਤਰ੍ਭਾਵ <_mingw.h>

#ਹਦਾਇਤ pack(ਧੱਕੋ,_CRT_PACKING)

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
ਬਾਹਰੀ "C" {
#ਜੇ_ਅੰਤ

  ਬਣਤਰ EXCEPTION_ਸੂਚਕ_ਸਾਰੇ_2;

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ EXCEPTION_DISPOSITION
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXCEPTION_DISPOSITION   ਪੂਰਨ
#ਜੇ_ਅੰਤ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ExceptionContinueExecution 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Exception_Continue_ਖੋਜ 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ExceptionNestedException 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ExceptionCollidedUnwind 3

#ਜੇ (defined(_X86_) && !defined(__x86_64))
  ਬਣਤਰ EXCEPTION_ਰਿਕਾਰਡ;
  ਬਣਤਰ _CONTEXT;

  EXCEPTION_DISPOSITION __cdecl _except_handler(ਬਣਤਰ EXCEPTION_ਰਿਕਾਰਡ *Exception_ਰਿਕਾਰਡ_2,ਖਾਲੀ *Establisher_ਚੌਖਟਾ,ਬਣਤਰ _CONTEXT *Context_ਰਿਕਾਰਡ_2,ਖਾਲੀ *_DispatcherContext);
#ਜਾਂਜੇ defined(__ia64__)

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ EXCEPTION_ਸੂਚਕ_ਸਾਰੇ_2 *Exception_info_ptr;
  ਬਣਤਰ EXCEPTION_ਰਿਕਾਰਡ;
  ਬਣਤਰ _CONTEXT;
  ਬਣਤਰ _DISPATCHER_CONTEXT;

  _CRTIMP EXCEPTION_DISPOSITION __cdecl __C_specific_handler (ਬਣਤਰ EXCEPTION_ਰਿਕਾਰਡ *Exception_ਰਿਕਾਰਡ_2,ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 ਸਮ੍ਰਿਤੀ_ਢੇਰ_Fp,ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 _BackingStoreFp,ਬਣਤਰ _CONTEXT *Context_ਰਿਕਾਰਡ_2,ਬਣਤਰ _DISPATCHER_CONTEXT *_DispatcherContext,ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 Global_ਸੂਚਕ);
#ਜਾਂਜੇ defined(__x86_64)

  ਬਣਤਰ EXCEPTION_ਰਿਕਾਰਡ;
  ਬਣਤਰ _CONTEXT;
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_Exception_ਕੋਡ exception_ਕੋਡ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ exception_ਕੋਡ_2 exception_ਕੋਡ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetExceptionInformation (ਬਣਤਰ EXCEPTION_ਸੂਚਕ_ਸਾਰੇ_2 *)_exception_info
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ exception_info (ਬਣਤਰ EXCEPTION_ਸੂਚਕ_ਸਾਰੇ_2 *)_exception_info
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AbnormalTermination _abnormal_termination
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ abnormal_termination _abnormal_termination

  ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ __cdecl exception_ਕੋਡ(ਖਾਲੀ);
  ਖਾਲੀ *__cdecl _exception_info(ਖਾਲੀ);
  ਪੂਰਨ __cdecl _abnormal_termination(ਖਾਲੀ);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXCEPTION_EXECUTE_HANDLER 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXCEPTION_CONTINUE_ਖੋਜ 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXCEPTION_CONTINUE_EXECUTION -1

  /* CRT stuff */
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਖਾਲੀ (__cdecl * _PHNDLR)(ਪੂਰਨ);

  ਬਣਤਰ _XCPT_ACTION {
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ Xcpt_ਅੰਕ;
    ਪੂਰਨ Sig_ਅੰਕ;
    _PHNDLR XcptAction;
  };

  ਬਾਹਰੀ ਬਣਤਰ _XCPT_ACTION _XcptActTab[];
  ਬਾਹਰੀ ਪੂਰਨ Xcpt_Act_Tab_ਗਿਣਤੀ;
  ਬਾਹਰੀ ਪੂਰਨ Xcpt_Act_Tab_ਮਾਪ;
  ਬਾਹਰੀ ਪੂਰਨ ਪਹਿਲਾ_FPE_Indx;
  ਬਾਹਰੀ ਪੂਰਨ ਅੰਕ_FPE;

  ਪੂਰਨ __cdecl __CppXcptFilter(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ Exception_ਅੰਕ,ਬਣਤਰ EXCEPTION_ਸੂਚਕ_ਸਾਰੇ_2 * _ExceptionPtr);
  ਪੂਰਨ __cdecl _XcptFilter(ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ Exception_ਅੰਕ,ਬਣਤਰ EXCEPTION_ਸੂਚਕ_ਸਾਰੇ_2 * _ExceptionPtr);

  /*
  * The type of function that is expected as an exception handler to be
  * installed with _try1.
  */
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ EXCEPTION_DISPOSITION (*PEXCEPTION_HANDLER)(ਬਣਤਰ EXCEPTION_ਰਿਕਾਰਡ*, ਖਾਲੀ*, ਬਣਤਰ _CONTEXT*, ਖਾਲੀ*);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ HAVE_NO_SEH
  /*
  * This is not entirely necessary, but it is the structure installed by
  * the _try1 primitive below.
  */
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _EXCEPTION_REGISTRATION {
    ਬਣਤਰ _EXCEPTION_REGISTRATION *prev;
    EXCEPTION_DISPOSITION (*handler)(ਬਣਤਰ EXCEPTION_ਰਿਕਾਰਡ*, ਖਾਲੀ*, ਬਣਤਰ _CONTEXT*, ਖਾਲੀ*);
  } EXCEPTION_REGISTRATION, *PEXCEPTION_REGISTRATION;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ EXCEPTION_REGISTRATION EXCEPTION_REGISTRATION_ਰਿਕਾਰਡ;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PEXCEPTION_REGISTRATION PEXCEPTION_REGISTRATION_ਰਿਕਾਰਡ;
#ਜੇ_ਅੰਤ

#ਜੇ (defined(_X86_) && !defined(__x86_64))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __try1(pHandler) \
  __asm__ ("pushl %0;pushl %%fs:0;movl %%esp,%%fs:0;" : : "g" (pHandler));

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	__except1	\
  __asm__ ("movl (%%esp),%%eax;movl %%eax,%%fs:0;addl $8,%%esp;" \
  : : : "%eax");
#ਜਾਂਜੇ defined(__x86_64)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __try1(pHandler) \
  __asm__ ("pushq %0;pushq %%gs:0;movq %%rsp,%%gs:0;" : : "g" (pHandler));

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	__except1	\
  __asm__ ("movq (%%rsp),%%rax;movq %%rax,%%gs:0;addq $16,%%rsp;" \
  : : : "%rax");
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __try1(pHandler)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __except1
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
}
#ਜੇ_ਅੰਤ

#ਹਦਾਇਤ pack(ਕੱਢੋ)
#ਜੇ_ਅੰਤ
