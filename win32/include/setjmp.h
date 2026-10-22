/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_SETJMP
#define _INC_SETJMP

#ଅନ୍ତର୍ଭାଵ <_mingw.h>

#pragma pack(ଠେଲ,_CRT_PACKING)

#ifdef __cplusplus
ବାହ୍ୟ "C" {
#endif

#ଯଦି (defined(_X86_) && !defined(__x86_64))

#define _JBLEN 16
#define _JBTYPE ପୂର୍ଣ୍ଣସଂଖ୍ୟା

  ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା __JUMP_BUFFER {
    unsigned long Ebp;
    unsigned long Ebx;
    unsigned long Edi;
    unsigned long Esi;
    unsigned long Esp;
    unsigned long Eip;
    unsigned long Registration;
    unsigned long TryLevel;
    unsigned long Cookie;
    unsigned long UnwindFunc;
    unsigned long UnwindData[6];
  } _JUMP_BUFFER;
#ନଚେତଯଦି defined(__ia64__)
  ପ୍ରକାରବ୍ୟାଖ୍ୟା _CRT_ALIGN(16) ସଂରଚନା _SETJMP_FLOAT128 {
    __int64 ତଳ_Part;
    __int64 ଉପର_Part;
  } SETJMP_FLOAT128;

#define _JBLEN 33
  ପ୍ରକାରବ୍ୟାଖ୍ୟା SETJMP_FLOAT128 _JBTYPE;

  ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା __JUMP_BUFFER {

    unsigned long iAReserved[6];

    unsigned long Registration;
    unsigned long TryLevel;
    unsigned long Cookie;
    unsigned long UnwindFunc;

    unsigned long UnwindData[6];

    SETJMP_FLOAT128 FltS0;
    SETJMP_FLOAT128 FltS1;
    SETJMP_FLOAT128 FltS2;
    SETJMP_FLOAT128 FltS3;
    SETJMP_FLOAT128 FltS4;
    SETJMP_FLOAT128 FltS5;
    SETJMP_FLOAT128 FltS6;
    SETJMP_FLOAT128 FltS7;
    SETJMP_FLOAT128 FltS8;
    SETJMP_FLOAT128 FltS9;
    SETJMP_FLOAT128 FltS10;
    SETJMP_FLOAT128 FltS11;
    SETJMP_FLOAT128 FltS12;
    SETJMP_FLOAT128 FltS13;
    SETJMP_FLOAT128 FltS14;
    SETJMP_FLOAT128 FltS15;
    SETJMP_FLOAT128 FltS16;
    SETJMP_FLOAT128 FltS17;
    SETJMP_FLOAT128 FltS18;
    SETJMP_FLOAT128 FltS19;
    __int64 FPSR;
    __int64 StIIP;
    __int64 BrS0;
    __int64 BrS1;
    __int64 BrS2;
    __int64 BrS3;
    __int64 BrS4;
    __int64 IntS0;
    __int64 IntS1;
    __int64 IntS2;
    __int64 IntS3;
    __int64 RsBSP;
    __int64 RsPFS;
    __int64 ApUNAT;
    __int64 ApLC;
    __int64 IntSp;
    __int64 IntNats;
    __int64 Preds;

  } _JUMP_BUFFER;
#ନଚେତଯଦି defined(__x86_64)
  ପ୍ରକାରବ୍ୟାଖ୍ୟା _CRT_ALIGN(16) ସଂରଚନା _SETJMP_FLOAT128 {
    unsigned __int64 Part[2];
  } SETJMP_FLOAT128;

#define _JBLEN 16
  ପ୍ରକାରବ୍ୟାଖ୍ୟା SETJMP_FLOAT128 _JBTYPE;

  ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା _JUMP_BUFFER {
    unsigned __int64 Frame;
    unsigned __int64 Rbx;
    unsigned __int64 Rsp;
    unsigned __int64 Rbp;
    unsigned __int64 Rsi;
    unsigned __int64 Rdi;
    unsigned __int64 R12;
    unsigned __int64 R13;
    unsigned __int64 R14;
    unsigned __int64 R15;
    unsigned __int64 Rip;
    unsigned __int64 Spare;
    SETJMP_FLOAT128 Xmm6;
    SETJMP_FLOAT128 Xmm7;
    SETJMP_FLOAT128 Xmm8;
    SETJMP_FLOAT128 Xmm9;
    SETJMP_FLOAT128 Xmm10;
    SETJMP_FLOAT128 Xmm11;
    SETJMP_FLOAT128 Xmm12;
    SETJMP_FLOAT128 Xmm13;
    SETJMP_FLOAT128 Xmm14;
    SETJMP_FLOAT128 Xmm15;
  } _JUMP_BUFFER;
#ନଚେତଯଦି defined(_ARM_)

#define _JBLEN 28
#define _JBTYPE ପୂର୍ଣ୍ଣସଂଖ୍ୟା

  ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା __JUMP_BUFFER {
    unsigned long Frame;
    unsigned long R4;
    unsigned long R5;
    unsigned long R6;
    unsigned long R7;
    unsigned long R8;
    unsigned long R9;
    unsigned long R10;
    unsigned long R11;
    unsigned long Sp;
    unsigned long Pc;
    unsigned long Fpscr;
    unsigned long long D[8];
  } _JUMP_BUFFER;
#ନଚେତଯଦି defined(_ARM64_)

#define _JBLEN 24
#define _JBTYPE unsigned __int64

  ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା __JUMP_BUFFER {
    unsigned __int64 Frame;
    unsigned __int64 Reserved;
    unsigned __int64 X19;
    unsigned __int64 X20;
    unsigned __int64 X21;
    unsigned __int64 X22;
    unsigned __int64 X23;
    unsigned __int64 X24;
    unsigned __int64 X25;
    unsigned __int64 X26;
    unsigned __int64 X27;
    unsigned __int64 X28;
    unsigned __int64 Fp;
    unsigned __int64 Lr;
    unsigned __int64 Sp;
    unsigned long Fpcr;
    unsigned long Fpsr;
    ଦ୍ୱିଗୁଣ D[8];
  } _JUMP_BUFFER;
#ଅନ୍ୟଥା
#define _JBLEN 1
#define _JBTYPE ପୂର୍ଣ୍ଣସଂଖ୍ୟା
#endif
#ifndef _JMP_BUF_DEFINED
  ପ୍ରକାରବ୍ୟାଖ୍ୟା _JBTYPE jmp_buf[_JBLEN];
#define _JMP_BUF_DEFINED
#endif

#pragma pack(କାଢ଼)

#ଯଦି defined __aarch64__
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା _setjmpex(jmp_buf _Buf, ଶୂନ୍ୟ *frame);
  #define setjmp(BUF) _setjmpex((BUF), (ଅକ୍ଷର*)__builtin_frame_address(0) + 224)
#ନଚେତଯଦି defined __x86_64__
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା _setjmp(jmp_buf _Buf, ଶୂନ୍ୟ *frame);
  #define setjmp(BUF) _setjmp((BUF), __builtin_frame_address(0))
#ଅନ୍ୟଥା /* __i386__ */
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା _setjmp(jmp_buf _Buf);
  #define setjmp _setjmp
#endif

__declspec(noreturn) ଶୂନ୍ୟ longjmp(jmp_buf _Buf,ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୂଲ୍ୟ_2);

#ifdef __cplusplus
}
#endif
#endif
