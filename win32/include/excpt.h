/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_EXCPT
#define _INC_EXCPT

#شامل <_mingw.h>

#pragma pack(افزودن,_CRT_PACKING)

#ifdef __cplusplus
بیرونی "C" {
#endif

  ساختار _EXCEPTION_POINTERS;

#ifndef EXCEPTION_DISPOSITION
#define EXCEPTION_DISPOSITION   صحیح
#endif
#define ExceptionContinueExecution 0
#define Exception_Continue_جستجو 1
#define ExceptionNestedException 2
#define ExceptionCollidedUnwind 3

#اگر (defined(_X86_) && !defined(__x86_64))
  ساختار _EXCEPTION_RECORD;
  ساختار _CONTEXT;

  EXCEPTION_DISPOSITION __cdecl _except_handler(ساختار _EXCEPTION_RECORD *_ExceptionRecord,تهی *_EstablisherFrame,ساختار _CONTEXT *_ContextRecord,تهی *_DispatcherContext);
#وگرنهاگر defined(__ia64__)

  تعریفنوع ساختار _EXCEPTION_POINTERS *Exception_info_ptr;
  ساختار _EXCEPTION_RECORD;
  ساختار _CONTEXT;
  ساختار _DISPATCHER_CONTEXT;

  _CRTIMP EXCEPTION_DISPOSITION __cdecl __C_specific_handler (ساختار _EXCEPTION_RECORD *_ExceptionRecord,unsigned __int64 Memory_پشته_Fp,unsigned __int64 _BackingStoreFp,ساختار _CONTEXT *_ContextRecord,ساختار _DISPATCHER_CONTEXT *_DispatcherContext,unsigned __int64 _GlobalPointer);
#وگرنهاگر defined(__x86_64)

  ساختار _EXCEPTION_RECORD;
  ساختار _CONTEXT;
#endif

#define GetExceptionCode _exception_code
#define exception_code _exception_code
#define GetExceptionInformation (ساختار _EXCEPTION_POINTERS *)_exception_info
#define exception_info (ساختار _EXCEPTION_POINTERS *)_exception_info
#define AbnormalTermination _abnormal_termination
#define abnormal_termination _abnormal_termination

  unsigned long __cdecl _exception_code(تهی);
  تهی *__cdecl _exception_info(تهی);
  صحیح __cdecl _abnormal_termination(تهی);

#define EXCEPTION_EXECUTE_HANDLER 1
#define EXCEPTION_CONTINUE_جستجو 0
#define EXCEPTION_CONTINUE_EXECUTION -1

  /* CRT stuff */
  تعریفنوع تهی (__cdecl * _PHNDLR)(صحیح);

  ساختار _XCPT_ACTION {
    unsigned long Xcpt_رقم;
    صحیح Sig_رقم;
    _PHNDLR XcptAction;
  };

  بیرونی ساختار _XCPT_ACTION _XcptActTab[];
  بیرونی صحیح Xcpt_Act_Tab_شمار;
  بیرونی صحیح _XcptActTabSize;
  بیرونی صحیح _First_FPE_Indx;
  بیرونی صحیح رقم_FPE;

  صحیح __cdecl __CppXcptFilter(unsigned long Exception_رقم,ساختار _EXCEPTION_POINTERS * _ExceptionPtr);
  صحیح __cdecl _XcptFilter(unsigned long Exception_رقم,ساختار _EXCEPTION_POINTERS * _ExceptionPtr);

  /*
  * The type of function that is expected as an exception handler to be
  * installed with _try1.
  */
  تعریفنوع EXCEPTION_DISPOSITION (*PEXCEPTION_HANDLER)(ساختار _EXCEPTION_RECORD*, تهی*, ساختار _CONTEXT*, تهی*);

#ifndef HAVE_NO_SEH
  /*
  * This is not entirely necessary, but it is the structure installed by
  * the _try1 primitive below.
  */
  تعریفنوع ساختار _EXCEPTION_REGISTRATION {
    ساختار _EXCEPTION_REGISTRATION *prev;
    EXCEPTION_DISPOSITION (*handler)(ساختار _EXCEPTION_RECORD*, تهی*, ساختار _CONTEXT*, تهی*);
  } EXCEPTION_REGISTRATION, *PEXCEPTION_REGISTRATION;

  تعریفنوع EXCEPTION_REGISTRATION EXCEPTION_REGISTRATION_RECORD;
  تعریفنوع PEXCEPTION_REGISTRATION PEXCEPTION_REGISTRATION_RECORD;
#endif

#اگر (defined(_X86_) && !defined(__x86_64))
#define __try1(pHandler) \
  __asm__ ("pushl %0;pushl %%fs:0;movl %%esp,%%fs:0;" : : "g" (pHandler));

#define	__except1	\
  __asm__ ("movl (%%esp),%%eax;movl %%eax,%%fs:0;addl $8,%%esp;" \
  : : : "%eax");
#وگرنهاگر defined(__x86_64)
#define __try1(pHandler) \
  __asm__ ("pushq %0;pushq %%gs:0;movq %%rsp,%%gs:0;" : : "g" (pHandler));

#define	__except1	\
  __asm__ ("movq (%%rsp),%%rax;movq %%rax,%%gs:0;addq $16,%%rsp;" \
  : : : "%rax");
#وگرنه
#define __try1(pHandler)
#define __except1
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(برداشت)
#endif
