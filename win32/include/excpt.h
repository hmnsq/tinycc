/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_EXCPT
#define _INC_EXCPT

#अन्तर्भाव <_mingw.h>

#pragma pack(प्रक्षिप,_CRT_PACKING)

#ifdef __cplusplus
बाह्य "C" {
#endif

  संरचना _EXCEPTION_POINTERS;

#ifndef EXCEPTION_DISPOSITION
#define EXCEPTION_DISPOSITION   पूर्णाङ्क
#endif
#define ExceptionContinueExecution 0
#define Exception_Continue_अन्वेषणम् 1
#define ExceptionNestedException 2
#define ExceptionCollidedUnwind 3

#सचे (defined(_X86_) && !defined(__x86_64))
  संरचना _EXCEPTION_RECORD;
  संरचना _CONTEXT;

  EXCEPTION_DISPOSITION __cdecl _except_handler(संरचना _EXCEPTION_RECORD *_ExceptionRecord,शून्य *_EstablisherFrame,संरचना _CONTEXT *_ContextRecord,शून्य *_DispatcherContext);
#नोचेद्यदि defined(__ia64__)

  प्रकारनिर्देश संरचना _EXCEPTION_POINTERS *Exception_info_ptr;
  संरचना _EXCEPTION_RECORD;
  संरचना _CONTEXT;
  संरचना _DISPATCHER_CONTEXT;

  _CRTIMP EXCEPTION_DISPOSITION __cdecl __C_specific_handler (संरचना _EXCEPTION_RECORD *_ExceptionRecord,unsigned __int64 Memory_राशिः_Fp,unsigned __int64 _BackingStoreFp,संरचना _CONTEXT *_ContextRecord,संरचना _DISPATCHER_CONTEXT *_DispatcherContext,unsigned __int64 _GlobalPointer);
#नोचेद्यदि defined(__x86_64)

  संरचना _EXCEPTION_RECORD;
  संरचना _CONTEXT;
#endif

#define GetExceptionCode _exception_code
#define exception_code _exception_code
#define GetExceptionInformation (संरचना _EXCEPTION_POINTERS *)_exception_info
#define exception_info (संरचना _EXCEPTION_POINTERS *)_exception_info
#define AbnormalTermination _abnormal_termination
#define abnormal_termination _abnormal_termination

  unsigned long __cdecl _exception_code(शून्य);
  शून्य *__cdecl _exception_info(शून्य);
  पूर्णाङ्क __cdecl _abnormal_termination(शून्य);

#define EXCEPTION_EXECUTE_HANDLER 1
#define EXCEPTION_CONTINUE_अन्वेषणम् 0
#define EXCEPTION_CONTINUE_EXECUTION -1

  /* CRT stuff */
  प्रकारनिर्देश शून्य (__cdecl * _PHNDLR)(पूर्णाङ्क);

  संरचना _XCPT_ACTION {
    unsigned long Xcpt_अङ्कः;
    पूर्णाङ्क Sig_अङ्कः;
    _PHNDLR XcptAction;
  };

  बाह्य संरचना _XCPT_ACTION _XcptActTab[];
  बाह्य पूर्णाङ्क Xcpt_Act_Tab_गणनम्;
  बाह्य पूर्णाङ्क _XcptActTabSize;
  बाह्य पूर्णाङ्क _First_FPE_Indx;
  बाह्य पूर्णाङ्क अङ्कः_FPE;

  पूर्णाङ्क __cdecl __CppXcptFilter(unsigned long Exception_अङ्कः,संरचना _EXCEPTION_POINTERS * _ExceptionPtr);
  पूर्णाङ्क __cdecl _XcptFilter(unsigned long Exception_अङ्कः,संरचना _EXCEPTION_POINTERS * _ExceptionPtr);

  /*
  * The type of function that is expected as an exception handler to be
  * installed with _try1.
  */
  प्रकारनिर्देश EXCEPTION_DISPOSITION (*PEXCEPTION_HANDLER)(संरचना _EXCEPTION_RECORD*, शून्य*, संरचना _CONTEXT*, शून्य*);

#ifndef HAVE_NO_SEH
  /*
  * This is not entirely necessary, but it is the structure installed by
  * the _try1 primitive below.
  */
  प्रकारनिर्देश संरचना _EXCEPTION_REGISTRATION {
    संरचना _EXCEPTION_REGISTRATION *prev;
    EXCEPTION_DISPOSITION (*handler)(संरचना _EXCEPTION_RECORD*, शून्य*, संरचना _CONTEXT*, शून्य*);
  } EXCEPTION_REGISTRATION, *PEXCEPTION_REGISTRATION;

  प्रकारनिर्देश EXCEPTION_REGISTRATION EXCEPTION_REGISTRATION_RECORD;
  प्रकारनिर्देश PEXCEPTION_REGISTRATION PEXCEPTION_REGISTRATION_RECORD;
#endif

#सचे (defined(_X86_) && !defined(__x86_64))
#define __try1(pHandler) \
  __asm__ ("pushl %0;pushl %%fs:0;movl %%esp,%%fs:0;" : : "g" (pHandler));

#define	__except1	\
  __asm__ ("movl (%%esp),%%eax;movl %%eax,%%fs:0;addl $8,%%esp;" \
  : : : "%eax");
#नोचेद्यदि defined(__x86_64)
#define __try1(pHandler) \
  __asm__ ("pushq %0;pushq %%gs:0;movq %%rsp,%%gs:0;" : : "g" (pHandler));

#define	__except1	\
  __asm__ ("movq (%%rsp),%%rax;movq %%rax,%%gs:0;addq $16,%%rsp;" \
  : : : "%rax");
#अञ्ञथा
#define __try1(pHandler)
#define __except1
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(निष्कासय)
#endif
