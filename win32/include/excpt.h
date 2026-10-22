/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_EXCPT
#define _INC_EXCPT

#અન્તર્ભાવ <_mingw.h>

#pragma pack(ધકેલો,_CRT_PACKING)

#ifdef __cplusplus
બાહ્ય "C" {
#endif

  સંરચના _EXCEPTION_POINTERS;

#ifndef EXCEPTION_DISPOSITION
#define EXCEPTION_DISPOSITION   પૂર્ણાંક
#endif
#define ExceptionContinueExecution 0
#define Exception_Continue_શોધ 1
#define ExceptionNestedException 2
#define ExceptionCollidedUnwind 3

#જો (defined(_X86_) && !defined(__x86_64))
  સંરચના _EXCEPTION_RECORD;
  સંરચના _CONTEXT;

  EXCEPTION_DISPOSITION __cdecl _except_handler(સંરચના _EXCEPTION_RECORD *_ExceptionRecord,શૂન્ય *_EstablisherFrame,સંરચના _CONTEXT *_ContextRecord,શૂન્ય *_DispatcherContext);
#અથવાજો defined(__ia64__)

  પ્રકારવ્યાખ્યા સંરચના _EXCEPTION_POINTERS *Exception_info_ptr;
  સંરચના _EXCEPTION_RECORD;
  સંરચના _CONTEXT;
  સંરચના _DISPATCHER_CONTEXT;

  _CRTIMP EXCEPTION_DISPOSITION __cdecl __C_specific_handler (સંરચના _EXCEPTION_RECORD *_ExceptionRecord,unsigned __int64 Memory_ઢગલો_Fp,unsigned __int64 _BackingStoreFp,સંરચના _CONTEXT *_ContextRecord,સંરચના _DISPATCHER_CONTEXT *_DispatcherContext,unsigned __int64 _GlobalPointer);
#અથવાજો defined(__x86_64)

  સંરચના _EXCEPTION_RECORD;
  સંરચના _CONTEXT;
#endif

#define GetExceptionCode _exception_code
#define exception_code _exception_code
#define GetExceptionInformation (સંરચના _EXCEPTION_POINTERS *)_exception_info
#define exception_info (સંરચના _EXCEPTION_POINTERS *)_exception_info
#define AbnormalTermination _abnormal_termination
#define abnormal_termination _abnormal_termination

  unsigned long __cdecl _exception_code(શૂન્ય);
  શૂન્ય *__cdecl _exception_info(શૂન્ય);
  પૂર્ણાંક __cdecl _abnormal_termination(શૂન્ય);

#define EXCEPTION_EXECUTE_HANDLER 1
#define EXCEPTION_CONTINUE_શોધ 0
#define EXCEPTION_CONTINUE_EXECUTION -1

  /* CRT stuff */
  પ્રકારવ્યાખ્યા શૂન્ય (__cdecl * _PHNDLR)(પૂર્ણાંક);

  સંરચના _XCPT_ACTION {
    unsigned long Xcpt_અંક;
    પૂર્ણાંક Sig_અંક;
    _PHNDLR XcptAction;
  };

  બાહ્ય સંરચના _XCPT_ACTION _XcptActTab[];
  બાહ્ય પૂર્ણાંક Xcpt_Act_Tab_ગણતરી;
  બાહ્ય પૂર્ણાંક _XcptActTabSize;
  બાહ્ય પૂર્ણાંક _First_FPE_Indx;
  બાહ્ય પૂર્ણાંક અંક_FPE;

  પૂર્ણાંક __cdecl __CppXcptFilter(unsigned long Exception_અંક,સંરચના _EXCEPTION_POINTERS * _ExceptionPtr);
  પૂર્ણાંક __cdecl _XcptFilter(unsigned long Exception_અંક,સંરચના _EXCEPTION_POINTERS * _ExceptionPtr);

  /*
  * The type of function that is expected as an exception handler to be
  * installed with _try1.
  */
  પ્રકારવ્યાખ્યા EXCEPTION_DISPOSITION (*PEXCEPTION_HANDLER)(સંરચના _EXCEPTION_RECORD*, શૂન્ય*, સંરચના _CONTEXT*, શૂન્ય*);

#ifndef HAVE_NO_SEH
  /*
  * This is not entirely necessary, but it is the structure installed by
  * the _try1 primitive below.
  */
  પ્રકારવ્યાખ્યા સંરચના _EXCEPTION_REGISTRATION {
    સંરચના _EXCEPTION_REGISTRATION *prev;
    EXCEPTION_DISPOSITION (*handler)(સંરચના _EXCEPTION_RECORD*, શૂન્ય*, સંરચના _CONTEXT*, શૂન્ય*);
  } EXCEPTION_REGISTRATION, *PEXCEPTION_REGISTRATION;

  પ્રકારવ્યાખ્યા EXCEPTION_REGISTRATION EXCEPTION_REGISTRATION_RECORD;
  પ્રકારવ્યાખ્યા PEXCEPTION_REGISTRATION PEXCEPTION_REGISTRATION_RECORD;
#endif

#જો (defined(_X86_) && !defined(__x86_64))
#define __try1(pHandler) \
  __asm__ ("pushl %0;pushl %%fs:0;movl %%esp,%%fs:0;" : : "g" (pHandler));

#define	__except1	\
  __asm__ ("movl (%%esp),%%eax;movl %%eax,%%fs:0;addl $8,%%esp;" \
  : : : "%eax");
#અથવાજો defined(__x86_64)
#define __try1(pHandler) \
  __asm__ ("pushq %0;pushq %%gs:0;movq %%rsp,%%gs:0;" : : "g" (pHandler));

#define	__except1	\
  __asm__ ("movq (%%rsp),%%rax;movq %%rax,%%gs:0;addq $16,%%rsp;" \
  : : : "%rax");
#નહીંતર
#define __try1(pHandler)
#define __except1
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(કાઢો)
#endif
