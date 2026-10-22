/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#که_نه_تعریف_شوی _INC_SETJMP
#تعریف_کړه _INC_SETJMP

#ضمن <_mingw.h>

#لارښوونه pack(ټېل,_CRT_PACKING)

#که_تعریف_شوی __cplusplus
خارجي "C" {
#د_که_پای

#إذا (defined(_X86_) && !defined(__x86_64))

#تعریف_کړه _JBLEN 16
#تعریف_کړه _JBTYPE صحيح

  تعريفنوع بنية __JUMP_BUFFER {
    بینښه اوږد Ebp;
    بینښه اوږد Ebx;
    بینښه اوږد Edi;
    بینښه اوږد Esi;
    بینښه اوږد Esp;
    بینښه اوږد Eip;
    بینښه اوږد Registration;
    بینښه اوږد TryLevel;
    بینښه اوږد Cookie;
    بینښه اوږد UnwindFunc;
    بینښه اوږد Unwind_معلومات[6];
  } JUMP_بفر;
#وإلاإذا defined(__ia64__)
  تعريفنوع _CRT_ALIGN(16) بنية _SETJMP_FLOAT128 {
    __int64 ټیټ_Part;
    __int64 لوړ_Part;
  } SETJMP_FLOAT128;

#تعریف_کړه _JBLEN 33
  تعريفنوع SETJMP_FLOAT128 _JBTYPE;

  تعريفنوع بنية __JUMP_BUFFER {

    بینښه اوږد iAReserved[6];

    بینښه اوږد Registration;
    بینښه اوږد TryLevel;
    بینښه اوږد Cookie;
    بینښه اوږد UnwindFunc;

    بینښه اوږد Unwind_معلومات[6];

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

  } JUMP_بفر;
#وإلاإذا defined(__x86_64)
  تعريفنوع _CRT_ALIGN(16) بنية _SETJMP_FLOAT128 {
    بینښه __int64 Part[2];
  } SETJMP_FLOAT128;

#تعریف_کړه _JBLEN 16
  تعريفنوع SETJMP_FLOAT128 _JBTYPE;

  تعريفنوع بنية JUMP_بفر {
    بینښه __int64 چوکاټ;
    بینښه __int64 Rbx;
    بینښه __int64 Rsp;
    بینښه __int64 Rbp;
    بینښه __int64 Rsi;
    بینښه __int64 Rdi;
    بینښه __int64 R12;
    بینښه __int64 R13;
    بینښه __int64 R14;
    بینښه __int64 R15;
    بینښه __int64 Rip;
    بینښه __int64 اضافي_2;
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
  } JUMP_بفر;
#وإلاإذا defined(_ARM_)

#تعریف_کړه _JBLEN 28
#تعریف_کړه _JBTYPE صحيح

  تعريفنوع بنية __JUMP_BUFFER {
    بینښه اوږد چوکاټ;
    بینښه اوږد R4;
    بینښه اوږد R5;
    بینښه اوږد R6;
    بینښه اوږد R7;
    بینښه اوږد R8;
    بینښه اوږد R9;
    بینښه اوږد R10;
    بینښه اوږد R11;
    بینښه اوږد Sp;
    بینښه اوږد Pc;
    بینښه اوږد Fpscr;
    بینښه اوږد اوږد D[8];
  } JUMP_بفر;
#وإلاإذا defined(_ARM64_)

#تعریف_کړه _JBLEN 24
#تعریف_کړه _JBTYPE بینښه __int64

  تعريفنوع بنية __JUMP_BUFFER {
    بینښه __int64 چوکاټ;
    بینښه __int64 Reserved;
    بینښه __int64 X19;
    بینښه __int64 X20;
    بینښه __int64 X21;
    بینښه __int64 X22;
    بینښه __int64 X23;
    بینښه __int64 X24;
    بینښه __int64 X25;
    بینښه __int64 X26;
    بینښه __int64 X27;
    بینښه __int64 X28;
    بینښه __int64 Fp;
    بینښه __int64 Lr;
    بینښه __int64 Sp;
    بینښه اوږد Fpcr;
    بینښه اوږد Fpsr;
    مزدوج D[8];
  } JUMP_بفر;
#وإلا
#تعریف_کړه _JBLEN 1
#تعریف_کړه _JBTYPE صحيح
#د_که_پای
#که_نه_تعریف_شوی _JMP_BUF_DEFINED
  تعريفنوع _JBTYPE jmp_buf[_JBLEN];
#تعریف_کړه _JMP_BUF_DEFINED
#د_که_پای

#لارښوونه pack(راوباسه)

#إذا defined __aarch64__
  صحيح _setjmpex(jmp_buf _Buf, فراغ *چوکاټ_2);
  #تعریف_کړه setjmp(BUF) _setjmpex((BUF), (حرف*)__builtin_frame_address(0) + 224)
#وإلاإذا defined __x86_64__
  صحيح _setjmp(jmp_buf _Buf, فراغ *چوکاټ_2);
  #تعریف_کړه setjmp(BUF) _setjmp((BUF), __builtin_frame_address(0))
#وإلا /* __i386__ */
  صحيح _setjmp(jmp_buf _Buf);
  #تعریف_کړه setjmp _setjmp
#د_که_پای

__declspec(noreturn) فراغ longjmp(jmp_buf _Buf,صحيح ارزښت_2);

#که_تعریف_شوی __cplusplus
}
#د_که_پای
#د_که_پای
