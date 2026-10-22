/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_EXCPT
#define _INC_EXCPT

#অন্তর্ভাব <_mingw.h>

#pragma pack(ঠেলো,_CRT_PACKING)

#ifdef __cplusplus
বাহ্য "C" {
#endif

  সংরচনা _EXCEPTION_POINTERS;

#ifndef EXCEPTION_DISPOSITION
#define EXCEPTION_DISPOSITION   পূর্ণাঙ্ক
#endif
#define ExceptionContinueExecution 0
#define Exception_Continue_অনুসন্ধান 1
#define ExceptionNestedException 2
#define ExceptionCollidedUnwind 3

#যদি (defined(_X86_) && !defined(__x86_64))
  সংরচনা _EXCEPTION_RECORD;
  সংরচনা _CONTEXT;

  EXCEPTION_DISPOSITION __cdecl _except_handler(সংরচনা _EXCEPTION_RECORD *_ExceptionRecord,শূন্য *_EstablisherFrame,সংরচনা _CONTEXT *_ContextRecord,শূন্য *_DispatcherContext);
#নোচেদ্যদি defined(__ia64__)

  প্রকারনির্দেশ সংরচনা _EXCEPTION_POINTERS *Exception_info_ptr;
  সংরচনা _EXCEPTION_RECORD;
  সংরচনা _CONTEXT;
  সংরচনা _DISPATCHER_CONTEXT;

  _CRTIMP EXCEPTION_DISPOSITION __cdecl __C_specific_handler (সংরচনা _EXCEPTION_RECORD *_ExceptionRecord,unsigned __int64 Memory_স্তূপ_Fp,unsigned __int64 _BackingStoreFp,সংরচনা _CONTEXT *_ContextRecord,সংরচনা _DISPATCHER_CONTEXT *_DispatcherContext,unsigned __int64 _GlobalPointer);
#নোচেদ্যদি defined(__x86_64)

  সংরচনা _EXCEPTION_RECORD;
  সংরচনা _CONTEXT;
#endif

#define GetExceptionCode _exception_code
#define exception_code _exception_code
#define GetExceptionInformation (সংরচনা _EXCEPTION_POINTERS *)_exception_info
#define exception_info (সংরচনা _EXCEPTION_POINTERS *)_exception_info
#define AbnormalTermination _abnormal_termination
#define abnormal_termination _abnormal_termination

  unsigned long __cdecl _exception_code(শূন্য);
  শূন্য *__cdecl _exception_info(শূন্য);
  পূর্ণাঙ্ক __cdecl _abnormal_termination(শূন্য);

#define EXCEPTION_EXECUTE_HANDLER 1
#define EXCEPTION_CONTINUE_অনুসন্ধান 0
#define EXCEPTION_CONTINUE_EXECUTION -1

  /* CRT stuff */
  প্রকারনির্দেশ শূন্য (__cdecl * _PHNDLR)(পূর্ণাঙ্ক);

  সংরচনা _XCPT_ACTION {
    unsigned long Xcpt_অঙ্ক;
    পূর্ণাঙ্ক Sig_অঙ্ক;
    _PHNDLR XcptAction;
  };

  বাহ্য সংরচনা _XCPT_ACTION _XcptActTab[];
  বাহ্য পূর্ণাঙ্ক Xcpt_Act_Tab_গুনতি;
  বাহ্য পূর্ণাঙ্ক _XcptActTabSize;
  বাহ্য পূর্ণাঙ্ক _First_FPE_Indx;
  বাহ্য পূর্ণাঙ্ক অঙ্ক_FPE;

  পূর্ণাঙ্ক __cdecl __CppXcptFilter(unsigned long Exception_অঙ্ক,সংরচনা _EXCEPTION_POINTERS * _ExceptionPtr);
  পূর্ণাঙ্ক __cdecl _XcptFilter(unsigned long Exception_অঙ্ক,সংরচনা _EXCEPTION_POINTERS * _ExceptionPtr);

  /*
  * The type of function that is expected as an exception handler to be
  * installed with _try1.
  */
  প্রকারনির্দেশ EXCEPTION_DISPOSITION (*PEXCEPTION_HANDLER)(সংরচনা _EXCEPTION_RECORD*, শূন্য*, সংরচনা _CONTEXT*, শূন্য*);

#ifndef HAVE_NO_SEH
  /*
  * This is not entirely necessary, but it is the structure installed by
  * the _try1 primitive below.
  */
  প্রকারনির্দেশ সংরচনা _EXCEPTION_REGISTRATION {
    সংরচনা _EXCEPTION_REGISTRATION *prev;
    EXCEPTION_DISPOSITION (*handler)(সংরচনা _EXCEPTION_RECORD*, শূন্য*, সংরচনা _CONTEXT*, শূন্য*);
  } EXCEPTION_REGISTRATION, *PEXCEPTION_REGISTRATION;

  প্রকারনির্দেশ EXCEPTION_REGISTRATION EXCEPTION_REGISTRATION_RECORD;
  প্রকারনির্দেশ PEXCEPTION_REGISTRATION PEXCEPTION_REGISTRATION_RECORD;
#endif

#যদি (defined(_X86_) && !defined(__x86_64))
#define __try1(pHandler) \
  __asm__ ("pushl %0;pushl %%fs:0;movl %%esp,%%fs:0;" : : "g" (pHandler));

#define	__except1	\
  __asm__ ("movl (%%esp),%%eax;movl %%eax,%%fs:0;addl $8,%%esp;" \
  : : : "%eax");
#নোচেদ্যদি defined(__x86_64)
#define __try1(pHandler) \
  __asm__ ("pushq %0;pushq %%gs:0;movq %%rsp,%%gs:0;" : : "g" (pHandler));

#define	__except1	\
  __asm__ ("movq (%%rsp),%%rax;movq %%rax,%%gs:0;addq $16,%%rsp;" \
  : : : "%rax");
#অন্যথা
#define __try1(pHandler)
#define __except1
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(বের_করো)
#endif
