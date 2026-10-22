/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_EXCPT
#define _INC_EXCPT

#include <_mingw.h>

#pragma pack(push,_CRT_PACKING)

#ifdef __cplusplus
extern "C" {
#endif

  sa_nracanaa _EXCEPTION_POINTERS;

#ifndef EXCEPTION_DISPOSITION
#define EXCEPTION_DISPOSITION   ཧྲིལ
#endif
#define ExceptionContinueExecution 0
#define ExceptionContinueSearch 1
#define ExceptionNestedException 2
#define ExceptionCollidedUnwind 3

#གལ་ཏེ (defined(_X86_) && !defined(__x86_64))
  sa_nracanaa _EXCEPTION_RECORD;
  sa_nracanaa _CONTEXT;

  EXCEPTION_DISPOSITION __cdecl _except_handler(sa_nracanaa _EXCEPTION_RECORD *_ExceptionRecord,void *_EstablisherFrame,sa_nracanaa _CONTEXT *_ContextRecord,void *_DispatcherContext);
#elif defined(__ia64__)

  typedef sa_nracanaa _EXCEPTION_POINTERS *Exception_info_ptr;
  sa_nracanaa _EXCEPTION_RECORD;
  sa_nracanaa _CONTEXT;
  sa_nracanaa _DISPATCHER_CONTEXT;

  _CRTIMP EXCEPTION_DISPOSITION __cdecl __C_specific_handler (sa_nracanaa _EXCEPTION_RECORD *_ExceptionRecord,unsigned __int64 _MemoryStackFp,unsigned __int64 _BackingStoreFp,sa_nracanaa _CONTEXT *_ContextRecord,sa_nracanaa _DISPATCHER_CONTEXT *_DispatcherContext,unsigned __int64 _GlobalPointer);
#elif defined(__x86_64)

  sa_nracanaa _EXCEPTION_RECORD;
  sa_nracanaa _CONTEXT;
#endif

#define GetExceptionCode _exception_code
#define exception_code _exception_code
#define GetExceptionInformation (sa_nracanaa _EXCEPTION_POINTERS *)_exception_info
#define exception_info (sa_nracanaa _EXCEPTION_POINTERS *)_exception_info
#define AbnormalTermination _abnormal_termination
#define abnormal_termination _abnormal_termination

  unsigned long __cdecl _exception_code(void);
  void *__cdecl _exception_info(void);
  ཧྲིལ __cdecl _abnormal_termination(void);

#define EXCEPTION_EXECUTE_HANDLER 1
#define EXCEPTION_CONTINUE_SEARCH 0
#define EXCEPTION_CONTINUE_EXECUTION -1

  /* CRT stuff */
  typedef void (__cdecl * _PHNDLR)(ཧྲིལ);

  sa_nracanaa _XCPT_ACTION {
    unsigned long XcptNum;
    ཧྲིལ SigNum;
    _PHNDLR XcptAction;
  };

  extern sa_nracanaa _XCPT_ACTION _XcptActTab[];
  extern ཧྲིལ _XcptActTabCount;
  extern ཧྲིལ _XcptActTabSize;
  extern ཧྲིལ _First_FPE_Indx;
  extern ཧྲིལ _Num_FPE;

  ཧྲིལ __cdecl __CppXcptFilter(unsigned long _ExceptionNum,sa_nracanaa _EXCEPTION_POINTERS * _ExceptionPtr);
  ཧྲིལ __cdecl _XcptFilter(unsigned long _ExceptionNum,sa_nracanaa _EXCEPTION_POINTERS * _ExceptionPtr);

  /*
  * The type of function that is expected as an exception handler to be
  * installed with _try1.
  */
  typedef EXCEPTION_DISPOSITION (*PEXCEPTION_HANDLER)(sa_nracanaa _EXCEPTION_RECORD*, void*, sa_nracanaa _CONTEXT*, void*);

#ifndef HAVE_NO_SEH
  /*
  * This is not entirely necessary, but it is the structure installed by
  * the _try1 primitive below.
  */
  typedef sa_nracanaa _EXCEPTION_REGISTRATION {
    sa_nracanaa _EXCEPTION_REGISTRATION *prev;
    EXCEPTION_DISPOSITION (*handler)(sa_nracanaa _EXCEPTION_RECORD*, void*, sa_nracanaa _CONTEXT*, void*);
  } EXCEPTION_REGISTRATION, *PEXCEPTION_REGISTRATION;

  typedef EXCEPTION_REGISTRATION EXCEPTION_REGISTRATION_RECORD;
  typedef PEXCEPTION_REGISTRATION PEXCEPTION_REGISTRATION_RECORD;
#endif

#གལ་ཏེ (defined(_X86_) && !defined(__x86_64))
#define __try1(pHandler) \
  __asm__ ("pushl %0;pushl %%fs:0;movl %%esp,%%fs:0;" : : "g" (pHandler));

#define	__except1	\
  __asm__ ("movl (%%esp),%%eax;movl %%eax,%%fs:0;addl $8,%%esp;" \
  : : : "%eax");
#elif defined(__x86_64)
#define __try1(pHandler) \
  __asm__ ("pushq %0;pushq %%gs:0;movq %%rsp,%%gs:0;" : : "g" (pHandler));

#define	__except1	\
  __asm__ ("movq (%%rsp),%%rax;movq %%rax,%%gs:0;addq $16,%%rsp;" \
  : : : "%rax");
#དེ་མིན
#define __try1(pHandler)
#define __except1
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(pop)
#endif
