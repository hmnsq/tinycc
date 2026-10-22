/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _INC_EXCPT
#ವ್ಯಾಖ್ಯಾನಿಸು _INC_EXCPT

#ಅನ್ತರ್ಭಾವ <_mingw.h>

#ಸೂಚನೆ pack(ತಳ್ಳು,_CRT_PACKING)

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
ಬಾಹ್ಯ "C" {
#ಆದರೆ_ಅಂತ್ಯ

  ರಚನೆ EXCEPTION_ಸೂಚಕಗಳು_2;

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ EXCEPTION_DISPOSITION
#ವ್ಯಾಖ್ಯಾನಿಸು EXCEPTION_DISPOSITION   ಪೂರ್ಣಾಂಕ
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿಸು ExceptionContinueExecution 0
#ವ್ಯಾಖ್ಯಾನಿಸು Exception_Continue_ಹುಡುಕು 1
#ವ್ಯಾಖ್ಯಾನಿಸು ExceptionNestedException 2
#ವ್ಯಾಖ್ಯಾನಿಸು ExceptionCollidedUnwind 3

#ಆದರೆ (defined(_X86_) && !defined(__x86_64))
  ರಚನೆ EXCEPTION_ದಾಖಲೆ;
  ರಚನೆ _CONTEXT;

  EXCEPTION_DISPOSITION __cdecl _except_handler(ರಚನೆ EXCEPTION_ದಾಖಲೆ *Exception_ದಾಖಲೆ_2,ಶೂನ್ಯ *Establisher_ಚೌಕಟ್ಟು,ರಚನೆ _CONTEXT *Context_ದಾಖಲೆ_2,ಶೂನ್ಯ *_DispatcherContext);
#ಅಥವಾಆದರೆ defined(__ia64__)

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ EXCEPTION_ಸೂಚಕಗಳು_2 *Exception_info_ptr;
  ರಚನೆ EXCEPTION_ದಾಖಲೆ;
  ರಚನೆ _CONTEXT;
  ರಚನೆ _DISPATCHER_CONTEXT;

  _CRTIMP EXCEPTION_DISPOSITION __cdecl __C_specific_handler (ರಚನೆ EXCEPTION_ದಾಖಲೆ *Exception_ದಾಖಲೆ_2,ಚಿಹ್ನೆರಹಿತ __int64 ಸ್ಮರಣೆ_ರಾಶಿ_Fp,ಚಿಹ್ನೆರಹಿತ __int64 _BackingStoreFp,ರಚನೆ _CONTEXT *Context_ದಾಖಲೆ_2,ರಚನೆ _DISPATCHER_CONTEXT *_DispatcherContext,ಚಿಹ್ನೆರಹಿತ __int64 Global_ಸೂಚಕ);
#ಅಥವಾಆದರೆ defined(__x86_64)

  ರಚನೆ EXCEPTION_ದಾಖಲೆ;
  ರಚನೆ _CONTEXT;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು Get_Exception_ಸಂಕೇತ exception_ಸಂಕೇತ
#ವ್ಯಾಖ್ಯಾನಿಸು exception_ಸಂಕೇತ_2 exception_ಸಂಕೇತ
#ವ್ಯಾಖ್ಯಾನಿಸು GetExceptionInformation (ರಚನೆ EXCEPTION_ಸೂಚಕಗಳು_2 *)_exception_info
#ವ್ಯಾಖ್ಯಾನಿಸು exception_info (ರಚನೆ EXCEPTION_ಸೂಚಕಗಳು_2 *)_exception_info
#ವ್ಯಾಖ್ಯಾನಿಸು AbnormalTermination _abnormal_termination
#ವ್ಯಾಖ್ಯಾನಿಸು abnormal_termination _abnormal_termination

  ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ __cdecl exception_ಸಂಕೇತ(ಶೂನ್ಯ);
  ಶೂನ್ಯ *__cdecl _exception_info(ಶೂನ್ಯ);
  ಪೂರ್ಣಾಂಕ __cdecl _abnormal_termination(ಶೂನ್ಯ);

#ವ್ಯಾಖ್ಯಾನಿಸು EXCEPTION_EXECUTE_HANDLER 1
#ವ್ಯಾಖ್ಯಾನಿಸು EXCEPTION_CONTINUE_ಹುಡುಕು 0
#ವ್ಯಾಖ್ಯಾನಿಸು EXCEPTION_CONTINUE_EXECUTION -1

  /* CRT stuff */
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಶೂನ್ಯ (__cdecl * _PHNDLR)(ಪೂರ್ಣಾಂಕ);

  ರಚನೆ _XCPT_ACTION {
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ Xcpt_ಅಂಕೆ;
    ಪೂರ್ಣಾಂಕ Sig_ಅಂಕೆ;
    _PHNDLR XcptAction;
  };

  ಬಾಹ್ಯ ರಚನೆ _XCPT_ACTION _XcptActTab[];
  ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ Xcpt_Act_Tab_ಎಣಿಕೆ;
  ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ Xcpt_Act_Tab_ಗಾತ್ರ;
  ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ ಮೊದಲ_FPE_Indx;
  ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ ಅಂಕೆ_FPE;

  ಪೂರ್ಣಾಂಕ __cdecl __CppXcptFilter(ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ Exception_ಅಂಕೆ,ರಚನೆ EXCEPTION_ಸೂಚಕಗಳು_2 * _ExceptionPtr);
  ಪೂರ್ಣಾಂಕ __cdecl _XcptFilter(ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ Exception_ಅಂಕೆ,ರಚನೆ EXCEPTION_ಸೂಚಕಗಳು_2 * _ExceptionPtr);

  /*
  * The type of function that is expected as an exception handler to be
  * installed with _try1.
  */
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ EXCEPTION_DISPOSITION (*PEXCEPTION_HANDLER)(ರಚನೆ EXCEPTION_ದಾಖಲೆ*, ಶೂನ್ಯ*, ರಚನೆ _CONTEXT*, ಶೂನ್ಯ*);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ HAVE_NO_SEH
  /*
  * This is not entirely necessary, but it is the structure installed by
  * the _try1 primitive below.
  */
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _EXCEPTION_REGISTRATION {
    ರಚನೆ _EXCEPTION_REGISTRATION *prev;
    EXCEPTION_DISPOSITION (*handler)(ರಚನೆ EXCEPTION_ದಾಖಲೆ*, ಶೂನ್ಯ*, ರಚನೆ _CONTEXT*, ಶೂನ್ಯ*);
  } EXCEPTION_REGISTRATION, *PEXCEPTION_REGISTRATION;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ EXCEPTION_REGISTRATION EXCEPTION_REGISTRATION_ದಾಖಲೆ;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PEXCEPTION_REGISTRATION PEXCEPTION_REGISTRATION_ದಾಖಲೆ;
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ (defined(_X86_) && !defined(__x86_64))
#ವ್ಯಾಖ್ಯಾನಿಸು __try1(pHandler) \
  __asm__ ("pushl %0;pushl %%fs:0;movl %%esp,%%fs:0;" : : "g" (pHandler));

#ವ್ಯಾಖ್ಯಾನಿಸು	__except1	\
  __asm__ ("movl (%%esp),%%eax;movl %%eax,%%fs:0;addl $8,%%esp;" \
  : : : "%eax");
#ಅಥವಾಆದರೆ defined(__x86_64)
#ವ್ಯಾಖ್ಯಾನಿಸು __try1(pHandler) \
  __asm__ ("pushq %0;pushq %%gs:0;movq %%rsp,%%gs:0;" : : "g" (pHandler));

#ವ್ಯಾಖ್ಯಾನಿಸು	__except1	\
  __asm__ ("movq (%%rsp),%%rax;movq %%rax,%%gs:0;addq $16,%%rsp;" \
  : : : "%rax");
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು __try1(pHandler)
#ವ್ಯಾಖ್ಯಾನಿಸು __except1
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
}
#ಆದರೆ_ಅಂತ್ಯ

#ಸೂಚನೆ pack(ತೆಗೆ)
#ಆದರೆ_ಅಂತ್ಯ
