/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جے_بنا_تعریف _INC_SETJMP
#تعریف_کرو _INC_SETJMP

#ضمن <_mingw.h>

#ہدایت pack(ڈالو,_CRT_PACKING)

#جے_تعریف_شدہ __cplusplus
خارجي "C" {
#جے_انت

#إذا (defined(_X86_) && !defined(__x86_64))

#تعریف_کرو _JBLEN 16
#تعریف_کرو _JBTYPE صحيح

  تعريفنوع بنية __JUMP_BUFFER {
    بنانشانی لما Ebp;
    بنانشانی لما Ebx;
    بنانشانی لما Edi;
    بنانشانی لما Esi;
    بنانشانی لما Esp;
    بنانشانی لما Eip;
    بنانشانی لما Registration;
    بنانشانی لما TryLevel;
    بنانشانی لما Cookie;
    بنانشانی لما UnwindFunc;
    بنانشانی لما Unwind_انکڑے[6];
  } JUMP_بفر;
#وإلاإذا defined(__ia64__)
  تعريفنوع _CRT_ALIGN(16) بنية _SETJMP_FLOAT128 {
    __int64 کم_Part;
    __int64 بلند_Part;
  } SETJMP_FLOAT128;

#تعریف_کرو _JBLEN 33
  تعريفنوع SETJMP_FLOAT128 _JBTYPE;

  تعريفنوع بنية __JUMP_BUFFER {

    بنانشانی لما iAReserved[6];

    بنانشانی لما Registration;
    بنانشانی لما TryLevel;
    بنانشانی لما Cookie;
    بنانشانی لما UnwindFunc;

    بنانشانی لما Unwind_انکڑے[6];

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
    بنانشانی __int64 Part[2];
  } SETJMP_FLOAT128;

#تعریف_کرو _JBLEN 16
  تعريفنوع SETJMP_FLOAT128 _JBTYPE;

  تعريفنوع بنية JUMP_بفر {
    بنانشانی __int64 چوکھٹا;
    بنانشانی __int64 Rbx;
    بنانشانی __int64 Rsp;
    بنانشانی __int64 Rbp;
    بنانشانی __int64 Rsi;
    بنانشانی __int64 Rdi;
    بنانشانی __int64 R12;
    بنانشانی __int64 R13;
    بنانشانی __int64 R14;
    بنانشانی __int64 R15;
    بنانشانی __int64 Rip;
    بنانشانی __int64 وادھو_2;
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

#تعریف_کرو _JBLEN 28
#تعریف_کرو _JBTYPE صحيح

  تعريفنوع بنية __JUMP_BUFFER {
    بنانشانی لما چوکھٹا;
    بنانشانی لما R4;
    بنانشانی لما R5;
    بنانشانی لما R6;
    بنانشانی لما R7;
    بنانشانی لما R8;
    بنانشانی لما R9;
    بنانشانی لما R10;
    بنانشانی لما R11;
    بنانشانی لما Sp;
    بنانشانی لما Pc;
    بنانشانی لما Fpscr;
    بنانشانی لما لما D[8];
  } JUMP_بفر;
#وإلاإذا defined(_ARM64_)

#تعریف_کرو _JBLEN 24
#تعریف_کرو _JBTYPE بنانشانی __int64

  تعريفنوع بنية __JUMP_BUFFER {
    بنانشانی __int64 چوکھٹا;
    بنانشانی __int64 Reserved;
    بنانشانی __int64 X19;
    بنانشانی __int64 X20;
    بنانشانی __int64 X21;
    بنانشانی __int64 X22;
    بنانشانی __int64 X23;
    بنانشانی __int64 X24;
    بنانشانی __int64 X25;
    بنانشانی __int64 X26;
    بنانشانی __int64 X27;
    بنانشانی __int64 X28;
    بنانشانی __int64 Fp;
    بنانشانی __int64 Lr;
    بنانشانی __int64 Sp;
    بنانشانی لما Fpcr;
    بنانشانی لما Fpsr;
    مزدوج D[8];
  } JUMP_بفر;
#وإلا
#تعریف_کرو _JBLEN 1
#تعریف_کرو _JBTYPE صحيح
#جے_انت
#جے_بنا_تعریف _JMP_BUF_DEFINED
  تعريفنوع _JBTYPE jmp_buf[_JBLEN];
#تعریف_کرو _JMP_BUF_DEFINED
#جے_انت

#ہدایت pack(نکالو)

#إذا defined __aarch64__
  صحيح _setjmpex(jmp_buf _Buf, فراغ *چوکھٹا_2);
  #تعریف_کرو setjmp(BUF) _setjmpex((BUF), (حرف*)__builtin_frame_address(0) + 224)
#وإلاإذا defined __x86_64__
  صحيح _setjmp(jmp_buf _Buf, فراغ *چوکھٹا_2);
  #تعریف_کرو setjmp(BUF) _setjmp((BUF), __builtin_frame_address(0))
#وإلا /* __i386__ */
  صحيح _setjmp(jmp_buf _Buf);
  #تعریف_کرو setjmp _setjmp
#جے_انت

__declspec(noreturn) فراغ longjmp(jmp_buf _Buf,صحيح قدر_2);

#جے_تعریف_شدہ __cplusplus
}
#جے_انت
#جے_انت
