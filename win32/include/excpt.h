/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#अगर_अघोषित _INC_EXCPT
#घोषणा _INC_EXCPT

#समावेश <_mingw.h>

#आशय pack(धकेलो,_CRT_PACKING)

#अगर_घोषित __cplusplus
बाह्य "C" {
#पूर्ण_अगर

  काष्ठा _EXCEPTION_POINTERS;

#अगर_अघोषित EXCEPTION_DISPOSITION
#घोषणा EXCEPTION_DISPOSITION   पूर्णांक
#पूर्ण_अगर
#घोषणा ExceptionContinueExecution 0
#घोषणा Exception_Continue_खोज 1
#घोषणा ExceptionNestedException 2
#घोषणा ExceptionCollidedUnwind 3

#अगर (defined(_X86_) && !defined(__x86_64))
  काष्ठा _EXCEPTION_RECORD;
  काष्ठा _CONTEXT;

  EXCEPTION_DISPOSITION __cdecl _except_handler(काष्ठा _EXCEPTION_RECORD *_ExceptionRecord,व्योम *_EstablisherFrame,काष्ठा _CONTEXT *_ContextRecord,व्योम *_DispatcherContext);
#या_अगर defined(__ia64__)

  प्रकार काष्ठा _EXCEPTION_POINTERS *Exception_info_ptr;
  काष्ठा _EXCEPTION_RECORD;
  काष्ठा _CONTEXT;
  काष्ठा _DISPATCHER_CONTEXT;

  _CRTIMP EXCEPTION_DISPOSITION __cdecl __C_specific_handler (काष्ठा _EXCEPTION_RECORD *_ExceptionRecord,अचिन्हित __int64 Memory_ढेर_Fp,अचिन्हित __int64 _BackingStoreFp,काष्ठा _CONTEXT *_ContextRecord,काष्ठा _DISPATCHER_CONTEXT *_DispatcherContext,अचिन्हित __int64 _GlobalPointer);
#या_अगर defined(__x86_64)

  काष्ठा _EXCEPTION_RECORD;
  काष्ठा _CONTEXT;
#पूर्ण_अगर

#घोषणा GetExceptionCode _exception_code
#घोषणा exception_code _exception_code
#घोषणा GetExceptionInformation (काष्ठा _EXCEPTION_POINTERS *)_exception_info
#घोषणा exception_info (काष्ठा _EXCEPTION_POINTERS *)_exception_info
#घोषणा AbnormalTermination _abnormal_termination
#घोषणा abnormal_termination _abnormal_termination

  अचिन्हित दीर्घ __cdecl _exception_code(व्योम);
  व्योम *__cdecl _exception_info(व्योम);
  पूर्णांक __cdecl _abnormal_termination(व्योम);

#घोषणा EXCEPTION_EXECUTE_HANDLER 1
#घोषणा EXCEPTION_CONTINUE_खोज 0
#घोषणा EXCEPTION_CONTINUE_EXECUTION -1

  /* CRT stuff */
  प्रकार व्योम (__cdecl * _PHNDLR)(पूर्णांक);

  काष्ठा _XCPT_ACTION {
    अचिन्हित दीर्घ Xcpt_अंक;
    पूर्णांक Sig_अंक;
    _PHNDLR XcptAction;
  };

  बाह्य काष्ठा _XCPT_ACTION _XcptActTab[];
  बाह्य पूर्णांक Xcpt_Act_Tab_गिनती;
  बाह्य पूर्णांक Xcpt_Act_Tab_आकार;
  बाह्य पूर्णांक _First_FPE_Indx;
  बाह्य पूर्णांक अंक_FPE;

  पूर्णांक __cdecl __CppXcptFilter(अचिन्हित दीर्घ Exception_अंक,काष्ठा _EXCEPTION_POINTERS * _ExceptionPtr);
  पूर्णांक __cdecl _XcptFilter(अचिन्हित दीर्घ Exception_अंक,काष्ठा _EXCEPTION_POINTERS * _ExceptionPtr);

  /*
  * The type of function that is expected as an exception handler to be
  * installed with _try1.
  */
  प्रकार EXCEPTION_DISPOSITION (*PEXCEPTION_HANDLER)(काष्ठा _EXCEPTION_RECORD*, व्योम*, काष्ठा _CONTEXT*, व्योम*);

#अगर_अघोषित HAVE_NO_SEH
  /*
  * This is not entirely necessary, but it is the structure installed by
  * the _try1 primitive below.
  */
  प्रकार काष्ठा _EXCEPTION_REGISTRATION {
    काष्ठा _EXCEPTION_REGISTRATION *पूर्व;
    EXCEPTION_DISPOSITION (*handler)(काष्ठा _EXCEPTION_RECORD*, व्योम*, काष्ठा _CONTEXT*, व्योम*);
  } EXCEPTION_REGISTRATION, *PEXCEPTION_REGISTRATION;

  प्रकार EXCEPTION_REGISTRATION EXCEPTION_REGISTRATION_RECORD;
  प्रकार PEXCEPTION_REGISTRATION PEXCEPTION_REGISTRATION_RECORD;
#पूर्ण_अगर

#अगर (defined(_X86_) && !defined(__x86_64))
#घोषणा __try1(pHandler) \
  __asm__ ("pushl %0;pushl %%fs:0;movl %%esp,%%fs:0;" : : "g" (pHandler));

#घोषणा	__except1	\
  __asm__ ("movl (%%esp),%%eax;movl %%eax,%%fs:0;addl $8,%%esp;" \
  : : : "%eax");
#या_अगर defined(__x86_64)
#घोषणा __try1(pHandler) \
  __asm__ ("pushq %0;pushq %%gs:0;movq %%rsp,%%gs:0;" : : "g" (pHandler));

#घोषणा	__except1	\
  __asm__ ("movq (%%rsp),%%rax;movq %%rax,%%gs:0;addq $16,%%rsp;" \
  : : : "%rax");
#अन्यथा
#घोषणा __try1(pHandler)
#घोषणा __except1
#पूर्ण_अगर

#अगर_घोषित __cplusplus
}
#पूर्ण_अगर

#आशय pack(निकालो)
#पूर्ण_अगर
