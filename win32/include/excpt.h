/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_EXCPT
#define _INC_EXCPT

#ضمن <_mingw.h>

#pragma pack(push,_CRT_PACKING)

#ifdef __cplusplus
خارجي "C" {
#endif

  بنية _EXCEPTION_POINTERS;

#ifndef EXCEPTION_DISPOSITION
#define EXCEPTION_DISPOSITION   صحيح
#endif
#define ExceptionContinueExecution 0
#define ExceptionContinueSearch 1
#define ExceptionNestedException 2
#define ExceptionCollidedUnwind 3

#𐡄𐡍 (defined(_X86_) && !defined(__x86_64))
  بنية _EXCEPTION_RECORD;
  بنية _CONTEXT;

  EXCEPTION_DISPOSITION __cdecl _except_handler(بنية _EXCEPTION_RECORD *_ExceptionRecord,فراغ *_EstablisherFrame,بنية _CONTEXT *_ContextRecord,فراغ *_DispatcherContext);
#وإلاإذا defined(__ia64__)

  تعريفنوع بنية _EXCEPTION_POINTERS *Exception_info_ptr;
  بنية _EXCEPTION_RECORD;
  بنية _CONTEXT;
  بنية _DISPATCHER_CONTEXT;

  _CRTIMP EXCEPTION_DISPOSITION __cdecl __C_specific_handler (بنية _EXCEPTION_RECORD *_ExceptionRecord,unsigned __int64 _MemoryStackFp,unsigned __int64 _BackingStoreFp,بنية _CONTEXT *_ContextRecord,بنية _DISPATCHER_CONTEXT *_DispatcherContext,unsigned __int64 _GlobalPointer);
#وإلاإذا defined(__x86_64)

  بنية _EXCEPTION_RECORD;
  بنية _CONTEXT;
#endif

#define GetExceptionCode _exception_code
#define exception_code _exception_code
#define GetExceptionInformation (بنية _EXCEPTION_POINTERS *)_exception_info
#define exception_info (بنية _EXCEPTION_POINTERS *)_exception_info
#define AbnormalTermination _abnormal_termination
#define abnormal_termination _abnormal_termination

  unsigned long __cdecl _exception_code(فراغ);
  فراغ *__cdecl _exception_info(فراغ);
  صحيح __cdecl _abnormal_termination(فراغ);

#define EXCEPTION_EXECUTE_HANDLER 1
#define EXCEPTION_CONTINUE_SEARCH 0
#define EXCEPTION_CONTINUE_EXECUTION -1

  /* CRT stuff */
  تعريفنوع فراغ (__cdecl * _PHNDLR)(صحيح);

  بنية _XCPT_ACTION {
    unsigned long XcptNum;
    صحيح SigNum;
    _PHNDLR XcptAction;
  };

  خارجي بنية _XCPT_ACTION _XcptActTab[];
  خارجي صحيح _XcptActTabCount;
  خارجي صحيح _XcptActTabSize;
  خارجي صحيح _First_FPE_Indx;
  خارجي صحيح _Num_FPE;

  صحيح __cdecl __CppXcptFilter(unsigned long _ExceptionNum,بنية _EXCEPTION_POINTERS * _ExceptionPtr);
  صحيح __cdecl _XcptFilter(unsigned long _ExceptionNum,بنية _EXCEPTION_POINTERS * _ExceptionPtr);

  /*
  * The type of function that is expected as an exception handler to be
  * installed with _try1.
  */
  تعريفنوع EXCEPTION_DISPOSITION (*PEXCEPTION_HANDLER)(بنية _EXCEPTION_RECORD*, فراغ*, بنية _CONTEXT*, فراغ*);

#ifndef HAVE_NO_SEH
  /*
  * This is not entirely necessary, but it is the structure installed by
  * the _try1 primitive below.
  */
  تعريفنوع بنية _EXCEPTION_REGISTRATION {
    بنية _EXCEPTION_REGISTRATION *prev;
    EXCEPTION_DISPOSITION (*handler)(بنية _EXCEPTION_RECORD*, فراغ*, بنية _CONTEXT*, فراغ*);
  } EXCEPTION_REGISTRATION, *PEXCEPTION_REGISTRATION;

  تعريفنوع EXCEPTION_REGISTRATION EXCEPTION_REGISTRATION_RECORD;
  تعريفنوع PEXCEPTION_REGISTRATION PEXCEPTION_REGISTRATION_RECORD;
#endif

#𐡄𐡍 (defined(_X86_) && !defined(__x86_64))
#define __try1(pHandler) \
  __asm__ ("pushl %0;pushl %%fs:0;movl %%esp,%%fs:0;" : : "g" (pHandler));

#define	__except1	\
  __asm__ ("movl (%%esp),%%eax;movl %%eax,%%fs:0;addl $8,%%esp;" \
  : : : "%eax");
#وإلاإذا defined(__x86_64)
#define __try1(pHandler) \
  __asm__ ("pushq %0;pushq %%gs:0;movq %%rsp,%%gs:0;" : : "g" (pHandler));

#define	__except1	\
  __asm__ ("movq (%%rsp),%%rax;movq %%rax,%%gs:0;addq $16,%%rsp;" \
  : : : "%rax");
#وإلا
#define __try1(pHandler)
#define __except1
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(pop)
#endif
