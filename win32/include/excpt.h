/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#నిర్వచితం_కాకపోతే _INC_EXCPT
#నిర్వచించు _INC_EXCPT

#అన్తర్భావ <_mingw.h>

#సూచన pack(నెట్టు,_CRT_PACKING)

#నిర్వచితమైతే __cplusplus
బాహ్య "C" {
#అయితే_ముగింపు

  నిర్మాణం EXCEPTION_సూచికలు_2;

#నిర్వచితం_కాకపోతే EXCEPTION_DISPOSITION
#నిర్వచించు EXCEPTION_DISPOSITION   పూర్ణాంకం
#అయితే_ముగింపు
#నిర్వచించు ExceptionContinueExecution 0
#నిర్వచించు Exception_Continue_శోధన 1
#నిర్వచించు ExceptionNestedException 2
#నిర్వచించు ExceptionCollidedUnwind 3

#ఒకవేళ (defined(_X86_) && !defined(__x86_64))
  నిర్మాణం EXCEPTION_రికార్డు;
  నిర్మాణం _CONTEXT;

  EXCEPTION_DISPOSITION __cdecl _except_handler(నిర్మాణం EXCEPTION_రికార్డు *Exception_రికార్డు_2,శూన్య *Establisher_చట్రం,నిర్మాణం _CONTEXT *Context_రికార్డు_2,శూన్య *_DispatcherContext);
#లేదావేళ defined(__ia64__)

  రకనిర్వచనం నిర్మాణం EXCEPTION_సూచికలు_2 *Exception_info_ptr;
  నిర్మాణం EXCEPTION_రికార్డు;
  నిర్మాణం _CONTEXT;
  నిర్మాణం _DISPATCHER_CONTEXT;

  _CRTIMP EXCEPTION_DISPOSITION __cdecl __C_specific_handler (నిర్మాణం EXCEPTION_రికార్డు *Exception_రికార్డు_2,గుర్తులేని __int64 జ్ఞాపకం_దొంతర_Fp,గుర్తులేని __int64 _BackingStoreFp,నిర్మాణం _CONTEXT *Context_రికార్డు_2,నిర్మాణం _DISPATCHER_CONTEXT *_DispatcherContext,గుర్తులేని __int64 Global_సూచిక);
#లేదావేళ defined(__x86_64)

  నిర్మాణం EXCEPTION_రికార్డు;
  నిర్మాణం _CONTEXT;
#అయితే_ముగింపు

#నిర్వచించు Get_Exception_సంకేతం exception_సంకేతం
#నిర్వచించు exception_సంకేతం_2 exception_సంకేతం
#నిర్వచించు GetExceptionInformation (నిర్మాణం EXCEPTION_సూచికలు_2 *)_exception_info
#నిర్వచించు exception_info (నిర్మాణం EXCEPTION_సూచికలు_2 *)_exception_info
#నిర్వచించు AbnormalTermination _abnormal_termination
#నిర్వచించు abnormal_termination _abnormal_termination

  గుర్తులేని దీర్ఘ __cdecl exception_సంకేతం(శూన్య);
  శూన్య *__cdecl _exception_info(శూన్య);
  పూర్ణాంకం __cdecl _abnormal_termination(శూన్య);

#నిర్వచించు EXCEPTION_EXECUTE_HANDLER 1
#నిర్వచించు EXCEPTION_CONTINUE_శోధన 0
#నిర్వచించు EXCEPTION_CONTINUE_EXECUTION -1

  /* CRT stuff */
  రకనిర్వచనం శూన్య (__cdecl * _PHNDLR)(పూర్ణాంకం);

  నిర్మాణం _XCPT_ACTION {
    గుర్తులేని దీర్ఘ Xcpt_అంకె;
    పూర్ణాంకం Sig_అంకె;
    _PHNDLR XcptAction;
  };

  బాహ్య నిర్మాణం _XCPT_ACTION _XcptActTab[];
  బాహ్య పూర్ణాంకం Xcpt_Act_Tab_లెక్క;
  బాహ్య పూర్ణాంకం Xcpt_Act_Tab_కొలత;
  బాహ్య పూర్ణాంకం మొదటి_FPE_Indx;
  బాహ్య పూర్ణాంకం అంకె_FPE;

  పూర్ణాంకం __cdecl __CppXcptFilter(గుర్తులేని దీర్ఘ Exception_అంకె,నిర్మాణం EXCEPTION_సూచికలు_2 * _ExceptionPtr);
  పూర్ణాంకం __cdecl _XcptFilter(గుర్తులేని దీర్ఘ Exception_అంకె,నిర్మాణం EXCEPTION_సూచికలు_2 * _ExceptionPtr);

  /*
  * The type of function that is expected as an exception handler to be
  * installed with _try1.
  */
  రకనిర్వచనం EXCEPTION_DISPOSITION (*PEXCEPTION_HANDLER)(నిర్మాణం EXCEPTION_రికార్డు*, శూన్య*, నిర్మాణం _CONTEXT*, శూన్య*);

#నిర్వచితం_కాకపోతే HAVE_NO_SEH
  /*
  * This is not entirely necessary, but it is the structure installed by
  * the _try1 primitive below.
  */
  రకనిర్వచనం నిర్మాణం _EXCEPTION_REGISTRATION {
    నిర్మాణం _EXCEPTION_REGISTRATION *prev;
    EXCEPTION_DISPOSITION (*handler)(నిర్మాణం EXCEPTION_రికార్డు*, శూన్య*, నిర్మాణం _CONTEXT*, శూన్య*);
  } EXCEPTION_REGISTRATION, *PEXCEPTION_REGISTRATION;

  రకనిర్వచనం EXCEPTION_REGISTRATION EXCEPTION_REGISTRATION_రికార్డు;
  రకనిర్వచనం PEXCEPTION_REGISTRATION PEXCEPTION_REGISTRATION_రికార్డు;
#అయితే_ముగింపు

#ఒకవేళ (defined(_X86_) && !defined(__x86_64))
#నిర్వచించు __try1(pHandler) \
  __asm__ ("pushl %0;pushl %%fs:0;movl %%esp,%%fs:0;" : : "g" (pHandler));

#నిర్వచించు	__except1	\
  __asm__ ("movl (%%esp),%%eax;movl %%eax,%%fs:0;addl $8,%%esp;" \
  : : : "%eax");
#లేదావేళ defined(__x86_64)
#నిర్వచించు __try1(pHandler) \
  __asm__ ("pushq %0;pushq %%gs:0;movq %%rsp,%%gs:0;" : : "g" (pHandler));

#నిర్వచించు	__except1	\
  __asm__ ("movq (%%rsp),%%rax;movq %%rax,%%gs:0;addq $16,%%rsp;" \
  : : : "%rax");
#లేకపోతే
#నిర్వచించు __try1(pHandler)
#నిర్వచించు __except1
#అయితే_ముగింపు

#నిర్వచితమైతే __cplusplus
}
#అయితే_ముగింపు

#సూచన pack(తీయి)
#అయితే_ముగింపు
