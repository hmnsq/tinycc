/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_EXCPT
#define _INC_EXCPT

#अन्तर्भाव <_mingw.h>

#pragma pack(ढकला,_CRT_PACKING)

#ifdef __cplusplus
बाह्य "C" {
#endif

  संरचना _EXCEPTION_POINTERS;

#ifndef EXCEPTION_DISPOSITION
#define EXCEPTION_DISPOSITION   पूर्णांक
#endif
#define ExceptionContinueExecution 0
#define Exception_Continue_शोध 1
#define ExceptionNestedException 2
#define ExceptionCollidedUnwind 3

#जर (defined(_X86_) && !defined(__x86_64))
  संरचना _EXCEPTION_RECORD;
  संरचना _CONTEXT;

  EXCEPTION_DISPOSITION __cdecl _except_handler(संरचना _EXCEPTION_RECORD *_ExceptionRecord,शून्य *_EstablisherFrame,संरचना _CONTEXT *_ContextRecord,शून्य *_DispatcherContext);
#किंवाजर defined(__ia64__)

  प्रकारव्याख्या संरचना _EXCEPTION_POINTERS *Exception_info_ptr;
  संरचना _EXCEPTION_RECORD;
  संरचना _CONTEXT;
  संरचना _DISPATCHER_CONTEXT;

  _CRTIMP EXCEPTION_DISPOSITION __cdecl __C_specific_handler (संरचना _EXCEPTION_RECORD *_ExceptionRecord,अचिन्हित __int64 Memory_चळत_Fp,अचिन्हित __int64 _BackingStoreFp,संरचना _CONTEXT *_ContextRecord,संरचना _DISPATCHER_CONTEXT *_DispatcherContext,अचिन्हित __int64 _GlobalPointer);
#किंवाजर defined(__x86_64)

  संरचना _EXCEPTION_RECORD;
  संरचना _CONTEXT;
#endif

#define GetExceptionCode _exception_code
#define exception_code _exception_code
#define GetExceptionInformation (संरचना _EXCEPTION_POINTERS *)_exception_info
#define exception_info (संरचना _EXCEPTION_POINTERS *)_exception_info
#define AbnormalTermination _abnormal_termination
#define abnormal_termination _abnormal_termination

  अचिन्हित दीर्घ __cdecl _exception_code(शून्य);
  शून्य *__cdecl _exception_info(शून्य);
  पूर्णांक __cdecl _abnormal_termination(शून्य);

#define EXCEPTION_EXECUTE_HANDLER 1
#define EXCEPTION_CONTINUE_शोध 0
#define EXCEPTION_CONTINUE_EXECUTION -1

  /* CRT stuff */
  प्रकारव्याख्या शून्य (__cdecl * _PHNDLR)(पूर्णांक);

  संरचना _XCPT_ACTION {
    अचिन्हित दीर्घ Xcpt_अंक;
    पूर्णांक Sig_अंक;
    _PHNDLR XcptAction;
  };

  बाह्य संरचना _XCPT_ACTION _XcptActTab[];
  बाह्य पूर्णांक Xcpt_Act_Tab_मोजणी;
  बाह्य पूर्णांक _XcptActTabSize;
  बाह्य पूर्णांक _First_FPE_Indx;
  बाह्य पूर्णांक अंक_FPE;

  पूर्णांक __cdecl __CppXcptFilter(अचिन्हित दीर्घ Exception_अंक,संरचना _EXCEPTION_POINTERS * _ExceptionPtr);
  पूर्णांक __cdecl _XcptFilter(अचिन्हित दीर्घ Exception_अंक,संरचना _EXCEPTION_POINTERS * _ExceptionPtr);

  /*
  * The type of function that is expected as an exception handler to be
  * installed with _try1.
  */
  प्रकारव्याख्या EXCEPTION_DISPOSITION (*PEXCEPTION_HANDLER)(संरचना _EXCEPTION_RECORD*, शून्य*, संरचना _CONTEXT*, शून्य*);

#ifndef HAVE_NO_SEH
  /*
  * This is not entirely necessary, but it is the structure installed by
  * the _try1 primitive below.
  */
  प्रकारव्याख्या संरचना _EXCEPTION_REGISTRATION {
    संरचना _EXCEPTION_REGISTRATION *prev;
    EXCEPTION_DISPOSITION (*handler)(संरचना _EXCEPTION_RECORD*, शून्य*, संरचना _CONTEXT*, शून्य*);
  } EXCEPTION_REGISTRATION, *PEXCEPTION_REGISTRATION;

  प्रकारव्याख्या EXCEPTION_REGISTRATION EXCEPTION_REGISTRATION_RECORD;
  प्रकारव्याख्या PEXCEPTION_REGISTRATION PEXCEPTION_REGISTRATION_RECORD;
#endif

#जर (defined(_X86_) && !defined(__x86_64))
#define __try1(pHandler) \
  __asm__ ("pushl %0;pushl %%fs:0;movl %%esp,%%fs:0;" : : "g" (pHandler));

#define	__except1	\
  __asm__ ("movl (%%esp),%%eax;movl %%eax,%%fs:0;addl $8,%%esp;" \
  : : : "%eax");
#किंवाजर defined(__x86_64)
#define __try1(pHandler) \
  __asm__ ("pushq %0;pushq %%gs:0;movq %%rsp,%%gs:0;" : : "g" (pHandler));

#define	__except1	\
  __asm__ ("movq (%%rsp),%%rax;movq %%rax,%%gs:0;addq $16,%%rsp;" \
  : : : "%rax");
#अन्यथा
#define __try1(pHandler)
#define __except1
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(काढा)
#endif
