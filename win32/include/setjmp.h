/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#నిర్వచితం_కాకపోతే _INC_SETJMP
#నిర్వచించు _INC_SETJMP

#అన్తర్భావ <_mingw.h>

#సూచన pack(నెట్టు,_CRT_PACKING)

#నిర్వచితమైతే __cplusplus
బాహ్య "C" {
#అయితే_ముగింపు

#ఒకవేళ (defined(_X86_) && !defined(__x86_64))

#నిర్వచించు _JBLEN 16
#నిర్వచించు _JBTYPE పూర్ణాంకం

  రకనిర్వచనం నిర్మాణం __JUMP_BUFFER {
    గుర్తులేని దీర్ఘ Ebp;
    గుర్తులేని దీర్ఘ Ebx;
    గుర్తులేని దీర్ఘ Edi;
    గుర్తులేని దీర్ఘ Esi;
    గుర్తులేని దీర్ఘ Esp;
    గుర్తులేని దీర్ఘ Eip;
    గుర్తులేని దీర్ఘ Registration;
    గుర్తులేని దీర్ఘ TryLevel;
    గుర్తులేని దీర్ఘ Cookie;
    గుర్తులేని దీర్ఘ UnwindFunc;
    గుర్తులేని దీర్ఘ Unwind_దత్తాంశం[6];
  } JUMP_బఫరు;
#లేదావేళ defined(__ia64__)
  రకనిర్వచనం _CRT_ALIGN(16) నిర్మాణం _SETJMP_FLOAT128 {
    __int64 దిగువ_Part;
    __int64 ఎగువ_Part;
  } SETJMP_FLOAT128;

#నిర్వచించు _JBLEN 33
  రకనిర్వచనం SETJMP_FLOAT128 _JBTYPE;

  రకనిర్వచనం నిర్మాణం __JUMP_BUFFER {

    గుర్తులేని దీర్ఘ iAReserved[6];

    గుర్తులేని దీర్ఘ Registration;
    గుర్తులేని దీర్ఘ TryLevel;
    గుర్తులేని దీర్ఘ Cookie;
    గుర్తులేని దీర్ఘ UnwindFunc;

    గుర్తులేని దీర్ఘ Unwind_దత్తాంశం[6];

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

  } JUMP_బఫరు;
#లేదావేళ defined(__x86_64)
  రకనిర్వచనం _CRT_ALIGN(16) నిర్మాణం _SETJMP_FLOAT128 {
    గుర్తులేని __int64 Part[2];
  } SETJMP_FLOAT128;

#నిర్వచించు _JBLEN 16
  రకనిర్వచనం SETJMP_FLOAT128 _JBTYPE;

  రకనిర్వచనం నిర్మాణం JUMP_బఫరు {
    గుర్తులేని __int64 చట్రం;
    గుర్తులేని __int64 Rbx;
    గుర్తులేని __int64 Rsp;
    గుర్తులేని __int64 Rbp;
    గుర్తులేని __int64 Rsi;
    గుర్తులేని __int64 Rdi;
    గుర్తులేని __int64 R12;
    గుర్తులేని __int64 R13;
    గుర్తులేని __int64 R14;
    గుర్తులేని __int64 R15;
    గుర్తులేని __int64 Rip;
    గుర్తులేని __int64 అదనపు_2;
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
  } JUMP_బఫరు;
#లేదావేళ defined(_ARM_)

#నిర్వచించు _JBLEN 28
#నిర్వచించు _JBTYPE పూర్ణాంకం

  రకనిర్వచనం నిర్మాణం __JUMP_BUFFER {
    గుర్తులేని దీర్ఘ చట్రం;
    గుర్తులేని దీర్ఘ R4;
    గుర్తులేని దీర్ఘ R5;
    గుర్తులేని దీర్ఘ R6;
    గుర్తులేని దీర్ఘ R7;
    గుర్తులేని దీర్ఘ R8;
    గుర్తులేని దీర్ఘ R9;
    గుర్తులేని దీర్ఘ R10;
    గుర్తులేని దీర్ఘ R11;
    గుర్తులేని దీర్ఘ Sp;
    గుర్తులేని దీర్ఘ Pc;
    గుర్తులేని దీర్ఘ Fpscr;
    గుర్తులేని దీర్ఘ దీర్ఘ D[8];
  } JUMP_బఫరు;
#లేదావేళ defined(_ARM64_)

#నిర్వచించు _JBLEN 24
#నిర్వచించు _JBTYPE గుర్తులేని __int64

  రకనిర్వచనం నిర్మాణం __JUMP_BUFFER {
    గుర్తులేని __int64 చట్రం;
    గుర్తులేని __int64 Reserved;
    గుర్తులేని __int64 X19;
    గుర్తులేని __int64 X20;
    గుర్తులేని __int64 X21;
    గుర్తులేని __int64 X22;
    గుర్తులేని __int64 X23;
    గుర్తులేని __int64 X24;
    గుర్తులేని __int64 X25;
    గుర్తులేని __int64 X26;
    గుర్తులేని __int64 X27;
    గుర్తులేని __int64 X28;
    గుర్తులేని __int64 Fp;
    గుర్తులేని __int64 Lr;
    గుర్తులేని __int64 Sp;
    గుర్తులేని దీర్ఘ Fpcr;
    గుర్తులేని దీర్ఘ Fpsr;
    ద్విగుణ D[8];
  } JUMP_బఫరు;
#లేకపోతే
#నిర్వచించు _JBLEN 1
#నిర్వచించు _JBTYPE పూర్ణాంకం
#అయితే_ముగింపు
#నిర్వచితం_కాకపోతే _JMP_BUF_DEFINED
  రకనిర్వచనం _JBTYPE jmp_buf[_JBLEN];
#నిర్వచించు _JMP_BUF_DEFINED
#అయితే_ముగింపు

#సూచన pack(తీయి)

#ఒకవేళ defined __aarch64__
  పూర్ణాంకం _setjmpex(jmp_buf _Buf, శూన్య *చట్రం_2);
  #నిర్వచించు setjmp(BUF) _setjmpex((BUF), (అక్షరం*)__builtin_frame_address(0) + 224)
#లేదావేళ defined __x86_64__
  పూర్ణాంకం _setjmp(jmp_buf _Buf, శూన్య *చట్రం_2);
  #నిర్వచించు setjmp(BUF) _setjmp((BUF), __builtin_frame_address(0))
#లేకపోతే /* __i386__ */
  పూర్ణాంకం _setjmp(jmp_buf _Buf);
  #నిర్వచించు setjmp _setjmp
#అయితే_ముగింపు

__declspec(noreturn) శూన్య longjmp(jmp_buf _Buf,పూర్ణాంకం విలువ_2);

#నిర్వచితమైతే __cplusplus
}
#అయితే_ముగింపు
#అయితే_ముగింపు
