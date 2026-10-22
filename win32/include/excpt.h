/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_EXCPT
#define _INC_EXCPT

#ଅନ୍ତର୍ଭାଵ <_mingw.h>

#pragma pack(ଠେଲ,_CRT_PACKING)

#ifdef __cplusplus
ବାହ୍ୟ "C" {
#endif

  ସଂରଚନା _EXCEPTION_POINTERS;

#ifndef EXCEPTION_DISPOSITION
#define EXCEPTION_DISPOSITION   ପୂର୍ଣ୍ଣସଂଖ୍ୟା
#endif
#define ExceptionContinueExecution 0
#define Exception_Continue_ସନ୍ଧାନ 1
#define ExceptionNestedException 2
#define ExceptionCollidedUnwind 3

#ଯଦି (defined(_X86_) && !defined(__x86_64))
  ସଂରଚନା _EXCEPTION_RECORD;
  ସଂରଚନା _CONTEXT;

  EXCEPTION_DISPOSITION __cdecl _except_handler(ସଂରଚନା _EXCEPTION_RECORD *_ExceptionRecord,ଶୂନ୍ୟ *_EstablisherFrame,ସଂରଚନା _CONTEXT *_ContextRecord,ଶୂନ୍ୟ *_DispatcherContext);
#ନଚେତଯଦି defined(__ia64__)

  ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା _EXCEPTION_POINTERS *Exception_info_ptr;
  ସଂରଚନା _EXCEPTION_RECORD;
  ସଂରଚନା _CONTEXT;
  ସଂରଚନା _DISPATCHER_CONTEXT;

  _CRTIMP EXCEPTION_DISPOSITION __cdecl __C_specific_handler (ସଂରଚନା _EXCEPTION_RECORD *_ExceptionRecord,unsigned __int64 Memory_ଗଦା_Fp,unsigned __int64 _BackingStoreFp,ସଂରଚନା _CONTEXT *_ContextRecord,ସଂରଚନା _DISPATCHER_CONTEXT *_DispatcherContext,unsigned __int64 _GlobalPointer);
#ନଚେତଯଦି defined(__x86_64)

  ସଂରଚନା _EXCEPTION_RECORD;
  ସଂରଚନା _CONTEXT;
#endif

#define GetExceptionCode _exception_code
#define exception_code _exception_code
#define GetExceptionInformation (ସଂରଚନା _EXCEPTION_POINTERS *)_exception_info
#define exception_info (ସଂରଚନା _EXCEPTION_POINTERS *)_exception_info
#define AbnormalTermination _abnormal_termination
#define abnormal_termination _abnormal_termination

  unsigned long __cdecl _exception_code(ଶୂନ୍ୟ);
  ଶୂନ୍ୟ *__cdecl _exception_info(ଶୂନ୍ୟ);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _abnormal_termination(ଶୂନ୍ୟ);

#define EXCEPTION_EXECUTE_HANDLER 1
#define EXCEPTION_CONTINUE_ସନ୍ଧାନ 0
#define EXCEPTION_CONTINUE_EXECUTION -1

  /* CRT stuff */
  ପ୍ରକାରବ୍ୟାଖ୍ୟା ଶୂନ୍ୟ (__cdecl * _PHNDLR)(ପୂର୍ଣ୍ଣସଂଖ୍ୟା);

  ସଂରଚନା _XCPT_ACTION {
    unsigned long Xcpt_ଅଙ୍କ;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା Sig_ଅଙ୍କ;
    _PHNDLR XcptAction;
  };

  ବାହ୍ୟ ସଂରଚନା _XCPT_ACTION _XcptActTab[];
  ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା Xcpt_Act_Tab_ଗଣନା;
  ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା _XcptActTabSize;
  ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା _First_FPE_Indx;
  ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଅଙ୍କ_FPE;

  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl __CppXcptFilter(unsigned long Exception_ଅଙ୍କ,ସଂରଚନା _EXCEPTION_POINTERS * _ExceptionPtr);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _XcptFilter(unsigned long Exception_ଅଙ୍କ,ସଂରଚନା _EXCEPTION_POINTERS * _ExceptionPtr);

  /*
  * The type of function that is expected as an exception handler to be
  * installed with _try1.
  */
  ପ୍ରକାରବ୍ୟାଖ୍ୟା EXCEPTION_DISPOSITION (*PEXCEPTION_HANDLER)(ସଂରଚନା _EXCEPTION_RECORD*, ଶୂନ୍ୟ*, ସଂରଚନା _CONTEXT*, ଶୂନ୍ୟ*);

#ifndef HAVE_NO_SEH
  /*
  * This is not entirely necessary, but it is the structure installed by
  * the _try1 primitive below.
  */
  ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା _EXCEPTION_REGISTRATION {
    ସଂରଚନା _EXCEPTION_REGISTRATION *prev;
    EXCEPTION_DISPOSITION (*handler)(ସଂରଚନା _EXCEPTION_RECORD*, ଶୂନ୍ୟ*, ସଂରଚନା _CONTEXT*, ଶୂନ୍ୟ*);
  } EXCEPTION_REGISTRATION, *PEXCEPTION_REGISTRATION;

  ପ୍ରକାରବ୍ୟାଖ୍ୟା EXCEPTION_REGISTRATION EXCEPTION_REGISTRATION_RECORD;
  ପ୍ରକାରବ୍ୟାଖ୍ୟା PEXCEPTION_REGISTRATION PEXCEPTION_REGISTRATION_RECORD;
#endif

#ଯଦି (defined(_X86_) && !defined(__x86_64))
#define __try1(pHandler) \
  __asm__ ("pushl %0;pushl %%fs:0;movl %%esp,%%fs:0;" : : "g" (pHandler));

#define	__except1	\
  __asm__ ("movl (%%esp),%%eax;movl %%eax,%%fs:0;addl $8,%%esp;" \
  : : : "%eax");
#ନଚେତଯଦି defined(__x86_64)
#define __try1(pHandler) \
  __asm__ ("pushq %0;pushq %%gs:0;movq %%rsp,%%gs:0;" : : "g" (pHandler));

#define	__except1	\
  __asm__ ("movq (%%rsp),%%rax;movq %%rax,%%gs:0;addq $16,%%rsp;" \
  : : : "%rax");
#ଅନ୍ୟଥା
#define __try1(pHandler)
#define __except1
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(କାଢ଼)
#endif
