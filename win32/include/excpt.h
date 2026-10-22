/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#यदि_अपरिभाषितम् _INC_EXCPT
#परिभाषय _INC_EXCPT

#अन्तर्भाव <_mingw.h>

#निर्देशः pack(प्रक्षिप,_CRT_PACKING)

#यदि_परिभाषितम् __cplusplus
बाह्य "C" {
#यदि_अन्तः

  संरचना EXCEPTION_सूचकाः_2;

#यदि_अपरिभाषितम् EXCEPTION_DISPOSITION
#परिभाषय EXCEPTION_DISPOSITION   पूर्णाङ्क
#यदि_अन्तः
#परिभाषय ExceptionContinueExecution 0
#परिभाषय Exception_Continue_अन्वेषणम् 1
#परिभाषय ExceptionNestedException 2
#परिभाषय ExceptionCollidedUnwind 3

#यदि (defined(_X86_) && !defined(__x86_64))
  संरचना EXCEPTION_लेखः;
  संरचना _CONTEXT;

  EXCEPTION_DISPOSITION __cdecl _except_handler(संरचना EXCEPTION_लेखः *Exception_लेखः_2,शून्य *_EstablisherFrame,संरचना _CONTEXT *Context_लेखः_2,शून्य *_DispatcherContext);
#नोचेद्यदि defined(__ia64__)

  प्रकारनिर्देश संरचना EXCEPTION_सूचकाः_2 *Exception_info_ptr;
  संरचना EXCEPTION_लेखः;
  संरचना _CONTEXT;
  संरचना _DISPATCHER_CONTEXT;

  _CRTIMP EXCEPTION_DISPOSITION __cdecl __C_specific_handler (संरचना EXCEPTION_लेखः *Exception_लेखः_2,अचिह्नित __int64 स्मृतिः_राशिः_Fp,अचिह्नित __int64 _BackingStoreFp,संरचना _CONTEXT *Context_लेखः_2,संरचना _DISPATCHER_CONTEXT *_DispatcherContext,अचिह्नित __int64 _GlobalPointer);
#नोचेद्यदि defined(__x86_64)

  संरचना EXCEPTION_लेखः;
  संरचना _CONTEXT;
#यदि_अन्तः

#परिभाषय Get_Exception_संहिता exception_संहिता
#परिभाषय exception_संहिता_2 exception_संहिता
#परिभाषय GetExceptionInformation (संरचना EXCEPTION_सूचकाः_2 *)_exception_info
#परिभाषय exception_info (संरचना EXCEPTION_सूचकाः_2 *)_exception_info
#परिभाषय AbnormalTermination _abnormal_termination
#परिभाषय abnormal_termination _abnormal_termination

  अचिह्नित दीर्घ __cdecl exception_संहिता(शून्य);
  शून्य *__cdecl _exception_info(शून्य);
  पूर्णाङ्क __cdecl _abnormal_termination(शून्य);

#परिभाषय EXCEPTION_EXECUTE_HANDLER 1
#परिभाषय EXCEPTION_CONTINUE_अन्वेषणम् 0
#परिभाषय EXCEPTION_CONTINUE_EXECUTION -1

  /* CRT stuff */
  प्रकारनिर्देश शून्य (__cdecl * _PHNDLR)(पूर्णाङ्क);

  संरचना _XCPT_ACTION {
    अचिह्नित दीर्घ Xcpt_अङ्कः;
    पूर्णाङ्क Sig_अङ्कः;
    _PHNDLR XcptAction;
  };

  बाह्य संरचना _XCPT_ACTION _XcptActTab[];
  बाह्य पूर्णाङ्क Xcpt_Act_Tab_गणनम्;
  बाह्य पूर्णाङ्क Xcpt_Act_Tab_आकार;
  बाह्य पूर्णाङ्क _First_FPE_Indx;
  बाह्य पूर्णाङ्क अङ्कः_FPE;

  पूर्णाङ्क __cdecl __CppXcptFilter(अचिह्नित दीर्घ Exception_अङ्कः,संरचना EXCEPTION_सूचकाः_2 * _ExceptionPtr);
  पूर्णाङ्क __cdecl _XcptFilter(अचिह्नित दीर्घ Exception_अङ्कः,संरचना EXCEPTION_सूचकाः_2 * _ExceptionPtr);

  /*
  * The type of function that is expected as an exception handler to be
  * installed with _try1.
  */
  प्रकारनिर्देश EXCEPTION_DISPOSITION (*PEXCEPTION_HANDLER)(संरचना EXCEPTION_लेखः*, शून्य*, संरचना _CONTEXT*, शून्य*);

#यदि_अपरिभाषितम् HAVE_NO_SEH
  /*
  * This is not entirely necessary, but it is the structure installed by
  * the _try1 primitive below.
  */
  प्रकारनिर्देश संरचना _EXCEPTION_REGISTRATION {
    संरचना _EXCEPTION_REGISTRATION *पूर्व;
    EXCEPTION_DISPOSITION (*handler)(संरचना EXCEPTION_लेखः*, शून्य*, संरचना _CONTEXT*, शून्य*);
  } EXCEPTION_REGISTRATION, *PEXCEPTION_REGISTRATION;

  प्रकारनिर्देश EXCEPTION_REGISTRATION EXCEPTION_REGISTRATION_लेखः;
  प्रकारनिर्देश PEXCEPTION_REGISTRATION PEXCEPTION_REGISTRATION_लेखः;
#यदि_अन्तः

#यदि (defined(_X86_) && !defined(__x86_64))
#परिभाषय __try1(pHandler) \
  __asm__ ("pushl %0;pushl %%fs:0;movl %%esp,%%fs:0;" : : "g" (pHandler));

#परिभाषय	__except1	\
  __asm__ ("movl (%%esp),%%eax;movl %%eax,%%fs:0;addl $8,%%esp;" \
  : : : "%eax");
#नोचेद्यदि defined(__x86_64)
#परिभाषय __try1(pHandler) \
  __asm__ ("pushq %0;pushq %%gs:0;movq %%rsp,%%gs:0;" : : "g" (pHandler));

#परिभाषय	__except1	\
  __asm__ ("movq (%%rsp),%%rax;movq %%rax,%%gs:0;addq $16,%%rsp;" \
  : : : "%rax");
#अन्यथा
#परिभाषय __try1(pHandler)
#परिभाषय __except1
#यदि_अन्तः

#यदि_परिभाषितम् __cplusplus
}
#यदि_अन्तः

#निर्देशः pack(निष्कासय)
#यदि_अन्तः
