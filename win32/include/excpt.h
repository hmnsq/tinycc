/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_EXCPT
#define _INC_EXCPT

#ಅನ್ತರ್ಭಾವ <_mingw.h>

#pragma pack(ತಳ್ಳು,_CRT_PACKING)

#ifdef __cplusplus
ಬಾಹ್ಯ "C" {
#endif

  ಸಂರಚನಾ _EXCEPTION_POINTERS;

#ifndef EXCEPTION_DISPOSITION
#define EXCEPTION_DISPOSITION   ಪೂರ್ಣಾಙ್ಕ
#endif
#define ExceptionContinueExecution 0
#define Exception_Continue_ಹುಡುಕು 1
#define ExceptionNestedException 2
#define ExceptionCollidedUnwind 3

#ಯದಿ (defined(_X86_) && !defined(__x86_64))
  ಸಂರಚನಾ _EXCEPTION_RECORD;
  ಸಂರಚನಾ _CONTEXT;

  EXCEPTION_DISPOSITION __cdecl _except_handler(ಸಂರಚನಾ _EXCEPTION_RECORD *_ExceptionRecord,ಶೂನ್ಯ *_EstablisherFrame,ಸಂರಚನಾ _CONTEXT *_ContextRecord,ಶೂನ್ಯ *_DispatcherContext);
#ನೋಚೇದ್ಯದಿ defined(__ia64__)

  ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ _EXCEPTION_POINTERS *Exception_info_ptr;
  ಸಂರಚನಾ _EXCEPTION_RECORD;
  ಸಂರಚನಾ _CONTEXT;
  ಸಂರಚನಾ _DISPATCHER_CONTEXT;

  _CRTIMP EXCEPTION_DISPOSITION __cdecl __C_specific_handler (ಸಂರಚನಾ _EXCEPTION_RECORD *_ExceptionRecord,unsigned __int64 Memory_ರಾಶಿ_Fp,unsigned __int64 _BackingStoreFp,ಸಂರಚನಾ _CONTEXT *_ContextRecord,ಸಂರಚನಾ _DISPATCHER_CONTEXT *_DispatcherContext,unsigned __int64 _GlobalPointer);
#ನೋಚೇದ್ಯದಿ defined(__x86_64)

  ಸಂರಚನಾ _EXCEPTION_RECORD;
  ಸಂರಚನಾ _CONTEXT;
#endif

#define GetExceptionCode _exception_code
#define exception_code _exception_code
#define GetExceptionInformation (ಸಂರಚನಾ _EXCEPTION_POINTERS *)_exception_info
#define exception_info (ಸಂರಚನಾ _EXCEPTION_POINTERS *)_exception_info
#define AbnormalTermination _abnormal_termination
#define abnormal_termination _abnormal_termination

  unsigned long __cdecl _exception_code(ಶೂನ್ಯ);
  ಶೂನ್ಯ *__cdecl _exception_info(ಶೂನ್ಯ);
  ಪೂರ್ಣಾಙ್ಕ __cdecl _abnormal_termination(ಶೂನ್ಯ);

#define EXCEPTION_EXECUTE_HANDLER 1
#define EXCEPTION_CONTINUE_ಹುಡುಕು 0
#define EXCEPTION_CONTINUE_EXECUTION -1

  /* CRT stuff */
  ಪ್ರಕಾರನಿರ್ದೇಶ ಶೂನ್ಯ (__cdecl * _PHNDLR)(ಪೂರ್ಣಾಙ್ಕ);

  ಸಂರಚನಾ _XCPT_ACTION {
    unsigned long Xcpt_ಅಂಕೆ;
    ಪೂರ್ಣಾಙ್ಕ Sig_ಅಂಕೆ;
    _PHNDLR XcptAction;
  };

  ಬಾಹ್ಯ ಸಂರಚನಾ _XCPT_ACTION _XcptActTab[];
  ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ Xcpt_Act_Tab_ಎಣಿಕೆ;
  ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ _XcptActTabSize;
  ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ _First_FPE_Indx;
  ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ ಅಂಕೆ_FPE;

  ಪೂರ್ಣಾಙ್ಕ __cdecl __CppXcptFilter(unsigned long Exception_ಅಂಕೆ,ಸಂರಚನಾ _EXCEPTION_POINTERS * _ExceptionPtr);
  ಪೂರ್ಣಾಙ್ಕ __cdecl _XcptFilter(unsigned long Exception_ಅಂಕೆ,ಸಂರಚನಾ _EXCEPTION_POINTERS * _ExceptionPtr);

  /*
  * The type of function that is expected as an exception handler to be
  * installed with _try1.
  */
  ಪ್ರಕಾರನಿರ್ದೇಶ EXCEPTION_DISPOSITION (*PEXCEPTION_HANDLER)(ಸಂರಚನಾ _EXCEPTION_RECORD*, ಶೂನ್ಯ*, ಸಂರಚನಾ _CONTEXT*, ಶೂನ್ಯ*);

#ifndef HAVE_NO_SEH
  /*
  * This is not entirely necessary, but it is the structure installed by
  * the _try1 primitive below.
  */
  ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ _EXCEPTION_REGISTRATION {
    ಸಂರಚನಾ _EXCEPTION_REGISTRATION *prev;
    EXCEPTION_DISPOSITION (*handler)(ಸಂರಚನಾ _EXCEPTION_RECORD*, ಶೂನ್ಯ*, ಸಂರಚನಾ _CONTEXT*, ಶೂನ್ಯ*);
  } EXCEPTION_REGISTRATION, *PEXCEPTION_REGISTRATION;

  ಪ್ರಕಾರನಿರ್ದೇಶ EXCEPTION_REGISTRATION EXCEPTION_REGISTRATION_RECORD;
  ಪ್ರಕಾರನಿರ್ದೇಶ PEXCEPTION_REGISTRATION PEXCEPTION_REGISTRATION_RECORD;
#endif

#ಯದಿ (defined(_X86_) && !defined(__x86_64))
#define __try1(pHandler) \
  __asm__ ("pushl %0;pushl %%fs:0;movl %%esp,%%fs:0;" : : "g" (pHandler));

#define	__except1	\
  __asm__ ("movl (%%esp),%%eax;movl %%eax,%%fs:0;addl $8,%%esp;" \
  : : : "%eax");
#ನೋಚೇದ್ಯದಿ defined(__x86_64)
#define __try1(pHandler) \
  __asm__ ("pushq %0;pushq %%gs:0;movq %%rsp,%%gs:0;" : : "g" (pHandler));

#define	__except1	\
  __asm__ ("movq (%%rsp),%%rax;movq %%rax,%%gs:0;addq $16,%%rsp;" \
  : : : "%rax");
#ಅನ್ಯಥಾ
#define __try1(pHandler)
#define __except1
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(ತೆಗೆ)
#endif
