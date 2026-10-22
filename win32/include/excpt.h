/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_EXCPT
#define _INC_EXCPT

#അന്തര്ഭാവ <_mingw.h>

#pragma pack(തള്ളുക,_CRT_PACKING)

#ifdef __cplusplus
ബാഹ്യ "C" {
#endif

  ഘടന _EXCEPTION_POINTERS;

#ifndef EXCEPTION_DISPOSITION
#define EXCEPTION_DISPOSITION   പൂർണ്ണസംഖ്യ
#endif
#define ExceptionContinueExecution 0
#define Exception_Continue_തിരയൽ 1
#define ExceptionNestedException 2
#define ExceptionCollidedUnwind 3

#എങ്കിൽ (defined(_X86_) && !defined(__x86_64))
  ഘടന _EXCEPTION_RECORD;
  ഘടന _CONTEXT;

  EXCEPTION_DISPOSITION __cdecl _except_handler(ഘടന _EXCEPTION_RECORD *_ExceptionRecord,ശൂന്യം *_EstablisherFrame,ഘടന _CONTEXT *_ContextRecord,ശൂന്യം *_DispatcherContext);
#അല്ലെങ്കിലെങ്കിൽ defined(__ia64__)

  തരനിർവചനം ഘടന _EXCEPTION_POINTERS *Exception_info_ptr;
  ഘടന _EXCEPTION_RECORD;
  ഘടന _CONTEXT;
  ഘടന _DISPATCHER_CONTEXT;

  _CRTIMP EXCEPTION_DISPOSITION __cdecl __C_specific_handler (ഘടന _EXCEPTION_RECORD *_ExceptionRecord,unsigned __int64 Memory_അട്ടി_Fp,unsigned __int64 _BackingStoreFp,ഘടന _CONTEXT *_ContextRecord,ഘടന _DISPATCHER_CONTEXT *_DispatcherContext,unsigned __int64 _GlobalPointer);
#അല്ലെങ്കിലെങ്കിൽ defined(__x86_64)

  ഘടന _EXCEPTION_RECORD;
  ഘടന _CONTEXT;
#endif

#define GetExceptionCode _exception_code
#define exception_code _exception_code
#define GetExceptionInformation (ഘടന _EXCEPTION_POINTERS *)_exception_info
#define exception_info (ഘടന _EXCEPTION_POINTERS *)_exception_info
#define AbnormalTermination _abnormal_termination
#define abnormal_termination _abnormal_termination

  unsigned long __cdecl _exception_code(ശൂന്യം);
  ശൂന്യം *__cdecl _exception_info(ശൂന്യം);
  പൂർണ്ണസംഖ്യ __cdecl _abnormal_termination(ശൂന്യം);

#define EXCEPTION_EXECUTE_HANDLER 1
#define EXCEPTION_CONTINUE_തിരയൽ 0
#define EXCEPTION_CONTINUE_EXECUTION -1

  /* CRT stuff */
  തരനിർവചനം ശൂന്യം (__cdecl * _PHNDLR)(പൂർണ്ണസംഖ്യ);

  ഘടന _XCPT_ACTION {
    unsigned long Xcpt_അക്കം;
    പൂർണ്ണസംഖ്യ Sig_അക്കം;
    _PHNDLR XcptAction;
  };

  ബാഹ്യ ഘടന _XCPT_ACTION _XcptActTab[];
  ബാഹ്യ പൂർണ്ണസംഖ്യ Xcpt_Act_Tab_എണ്ണം;
  ബാഹ്യ പൂർണ്ണസംഖ്യ _XcptActTabSize;
  ബാഹ്യ പൂർണ്ണസംഖ്യ _First_FPE_Indx;
  ബാഹ്യ പൂർണ്ണസംഖ്യ അക്കം_FPE;

  പൂർണ്ണസംഖ്യ __cdecl __CppXcptFilter(unsigned long Exception_അക്കം,ഘടന _EXCEPTION_POINTERS * _ExceptionPtr);
  പൂർണ്ണസംഖ്യ __cdecl _XcptFilter(unsigned long Exception_അക്കം,ഘടന _EXCEPTION_POINTERS * _ExceptionPtr);

  /*
  * The type of function that is expected as an exception handler to be
  * installed with _try1.
  */
  തരനിർവചനം EXCEPTION_DISPOSITION (*PEXCEPTION_HANDLER)(ഘടന _EXCEPTION_RECORD*, ശൂന്യം*, ഘടന _CONTEXT*, ശൂന്യം*);

#ifndef HAVE_NO_SEH
  /*
  * This is not entirely necessary, but it is the structure installed by
  * the _try1 primitive below.
  */
  തരനിർവചനം ഘടന _EXCEPTION_REGISTRATION {
    ഘടന _EXCEPTION_REGISTRATION *prev;
    EXCEPTION_DISPOSITION (*handler)(ഘടന _EXCEPTION_RECORD*, ശൂന്യം*, ഘടന _CONTEXT*, ശൂന്യം*);
  } EXCEPTION_REGISTRATION, *PEXCEPTION_REGISTRATION;

  തരനിർവചനം EXCEPTION_REGISTRATION EXCEPTION_REGISTRATION_RECORD;
  തരനിർവചനം PEXCEPTION_REGISTRATION PEXCEPTION_REGISTRATION_RECORD;
#endif

#എങ്കിൽ (defined(_X86_) && !defined(__x86_64))
#define __try1(pHandler) \
  __asm__ ("pushl %0;pushl %%fs:0;movl %%esp,%%fs:0;" : : "g" (pHandler));

#define	__except1	\
  __asm__ ("movl (%%esp),%%eax;movl %%eax,%%fs:0;addl $8,%%esp;" \
  : : : "%eax");
#അല്ലെങ്കിലെങ്കിൽ defined(__x86_64)
#define __try1(pHandler) \
  __asm__ ("pushq %0;pushq %%gs:0;movq %%rsp,%%gs:0;" : : "g" (pHandler));

#define	__except1	\
  __asm__ ("movq (%%rsp),%%rax;movq %%rax,%%gs:0;addq $16,%%rsp;" \
  : : : "%rax");
#അല്ലെങ്കിൽ
#define __try1(pHandler)
#define __except1
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(എടുക്കുക)
#endif
