/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_EXCPT
#define _INC_EXCPT

#அந்தர்பாவ <_mingw.h>

#pragma pack(தள்ளு,_CRT_PACKING)

#ifdef __cplusplus
வெளி "C" {
#endif

  கட்டமைப்பு _EXCEPTION_POINTERS;

#ifndef EXCEPTION_DISPOSITION
#define EXCEPTION_DISPOSITION   முழு
#endif
#define ExceptionContinueExecution 0
#define Exception_Continue_தேடல் 1
#define ExceptionNestedException 2
#define ExceptionCollidedUnwind 3

#எனில் (defined(_X86_) && !defined(__x86_64))
  கட்டமைப்பு _EXCEPTION_RECORD;
  கட்டமைப்பு _CONTEXT;

  EXCEPTION_DISPOSITION __cdecl _except_handler(கட்டமைப்பு _EXCEPTION_RECORD *_ExceptionRecord,வெறுமை *_EstablisherFrame,கட்டமைப்பு _CONTEXT *_ContextRecord,வெறுமை *_DispatcherContext);
#அல்லதெனில் defined(__ia64__)

  வகைவரை கட்டமைப்பு _EXCEPTION_POINTERS *Exception_info_ptr;
  கட்டமைப்பு _EXCEPTION_RECORD;
  கட்டமைப்பு _CONTEXT;
  கட்டமைப்பு _DISPATCHER_CONTEXT;

  _CRTIMP EXCEPTION_DISPOSITION __cdecl __C_specific_handler (கட்டமைப்பு _EXCEPTION_RECORD *_ExceptionRecord,unsigned __int64 Memory_அடுக்கு_Fp,unsigned __int64 _BackingStoreFp,கட்டமைப்பு _CONTEXT *_ContextRecord,கட்டமைப்பு _DISPATCHER_CONTEXT *_DispatcherContext,unsigned __int64 _GlobalPointer);
#அல்லதெனில் defined(__x86_64)

  கட்டமைப்பு _EXCEPTION_RECORD;
  கட்டமைப்பு _CONTEXT;
#endif

#define GetExceptionCode _exception_code
#define exception_code _exception_code
#define GetExceptionInformation (கட்டமைப்பு _EXCEPTION_POINTERS *)_exception_info
#define exception_info (கட்டமைப்பு _EXCEPTION_POINTERS *)_exception_info
#define AbnormalTermination _abnormal_termination
#define abnormal_termination _abnormal_termination

  unsigned long __cdecl _exception_code(வெறுமை);
  வெறுமை *__cdecl _exception_info(வெறுமை);
  முழு __cdecl _abnormal_termination(வெறுமை);

#define EXCEPTION_EXECUTE_HANDLER 1
#define EXCEPTION_CONTINUE_தேடல் 0
#define EXCEPTION_CONTINUE_EXECUTION -1

  /* CRT stuff */
  வகைவரை வெறுமை (__cdecl * _PHNDLR)(முழு);

  கட்டமைப்பு _XCPT_ACTION {
    unsigned long Xcpt_இலக்கம்;
    முழு Sig_இலக்கம்;
    _PHNDLR XcptAction;
  };

  வெளி கட்டமைப்பு _XCPT_ACTION _XcptActTab[];
  வெளி முழு Xcpt_Act_Tab_மொத்தம்;
  வெளி முழு _XcptActTabSize;
  வெளி முழு _First_FPE_Indx;
  வெளி முழு இலக்கம்_FPE;

  முழு __cdecl __CppXcptFilter(unsigned long Exception_இலக்கம்,கட்டமைப்பு _EXCEPTION_POINTERS * _ExceptionPtr);
  முழு __cdecl _XcptFilter(unsigned long Exception_இலக்கம்,கட்டமைப்பு _EXCEPTION_POINTERS * _ExceptionPtr);

  /*
  * The type of function that is expected as an exception handler to be
  * installed with _try1.
  */
  வகைவரை EXCEPTION_DISPOSITION (*PEXCEPTION_HANDLER)(கட்டமைப்பு _EXCEPTION_RECORD*, வெறுமை*, கட்டமைப்பு _CONTEXT*, வெறுமை*);

#ifndef HAVE_NO_SEH
  /*
  * This is not entirely necessary, but it is the structure installed by
  * the _try1 primitive below.
  */
  வகைவரை கட்டமைப்பு _EXCEPTION_REGISTRATION {
    கட்டமைப்பு _EXCEPTION_REGISTRATION *prev;
    EXCEPTION_DISPOSITION (*handler)(கட்டமைப்பு _EXCEPTION_RECORD*, வெறுமை*, கட்டமைப்பு _CONTEXT*, வெறுமை*);
  } EXCEPTION_REGISTRATION, *PEXCEPTION_REGISTRATION;

  வகைவரை EXCEPTION_REGISTRATION EXCEPTION_REGISTRATION_RECORD;
  வகைவரை PEXCEPTION_REGISTRATION PEXCEPTION_REGISTRATION_RECORD;
#endif

#எனில் (defined(_X86_) && !defined(__x86_64))
#define __try1(pHandler) \
  __asm__ ("pushl %0;pushl %%fs:0;movl %%esp,%%fs:0;" : : "g" (pHandler));

#define	__except1	\
  __asm__ ("movl (%%esp),%%eax;movl %%eax,%%fs:0;addl $8,%%esp;" \
  : : : "%eax");
#அல்லதெனில் defined(__x86_64)
#define __try1(pHandler) \
  __asm__ ("pushq %0;pushq %%gs:0;movq %%rsp,%%gs:0;" : : "g" (pHandler));

#define	__except1	\
  __asm__ ("movq (%%rsp),%%rax;movq %%rax,%%gs:0;addq $16,%%rsp;" \
  : : : "%rax");
#இல்லையெனில்
#define __try1(pHandler)
#define __except1
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(எடு)
#endif
