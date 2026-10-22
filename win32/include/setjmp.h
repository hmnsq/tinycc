/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جيڪڏهن_وصف_نه_ٿيل _INC_SETJMP
#وصف_ڪريو _INC_SETJMP

#ضمن <_mingw.h>

#هدايت pack(ڌڪو,_CRT_PACKING)

#جيڪڏهن_وصف_ٿيل __cplusplus
خارجي "C" {
#جيڪڏهن_پورو

#إذا (defined(_X86_) && !defined(__x86_64))

#وصف_ڪريو _JBLEN 16
#وصف_ڪريو _JBTYPE صحيح

  تعريفنوع بنية __JUMP_BUFFER {
    بنانشان ڊگهو Ebp;
    بنانشان ڊگهو Ebx;
    بنانشان ڊگهو Edi;
    بنانشان ڊگهو Esi;
    بنانشان ڊگهو Esp;
    بنانشان ڊگهو Eip;
    بنانشان ڊگهو Registration;
    بنانشان ڊگهو TryLevel;
    بنانشان ڊگهو Cookie;
    بنانشان ڊگهو UnwindFunc;
    بنانشان ڊگهو Unwind_معلومات[6];
  } JUMP_بفر;
#وإلاإذا defined(__ia64__)
  تعريفنوع _CRT_ALIGN(16) بنية _SETJMP_FLOAT128 {
    __int64 هيٺيون_Part;
    __int64 مٿاهون_Part;
  } SETJMP_FLOAT128;

#وصف_ڪريو _JBLEN 33
  تعريفنوع SETJMP_FLOAT128 _JBTYPE;

  تعريفنوع بنية __JUMP_BUFFER {

    بنانشان ڊگهو iAReserved[6];

    بنانشان ڊگهو Registration;
    بنانشان ڊگهو TryLevel;
    بنانشان ڊگهو Cookie;
    بنانشان ڊگهو UnwindFunc;

    بنانشان ڊگهو Unwind_معلومات[6];

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
    بنانشان __int64 Part[2];
  } SETJMP_FLOAT128;

#وصف_ڪريو _JBLEN 16
  تعريفنوع SETJMP_FLOAT128 _JBTYPE;

  تعريفنوع بنية JUMP_بفر {
    بنانشان __int64 چوکٺو;
    بنانشان __int64 Rbx;
    بنانشان __int64 Rsp;
    بنانشان __int64 Rbp;
    بنانشان __int64 Rsi;
    بنانشان __int64 Rdi;
    بنانشان __int64 R12;
    بنانشان __int64 R13;
    بنانشان __int64 R14;
    بنانشان __int64 R15;
    بنانشان __int64 Rip;
    بنانشان __int64 اضافي_2;
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

#وصف_ڪريو _JBLEN 28
#وصف_ڪريو _JBTYPE صحيح

  تعريفنوع بنية __JUMP_BUFFER {
    بنانشان ڊگهو چوکٺو;
    بنانشان ڊگهو R4;
    بنانشان ڊگهو R5;
    بنانشان ڊگهو R6;
    بنانشان ڊگهو R7;
    بنانشان ڊگهو R8;
    بنانشان ڊگهو R9;
    بنانشان ڊگهو R10;
    بنانشان ڊگهو R11;
    بنانشان ڊگهو Sp;
    بنانشان ڊگهو Pc;
    بنانشان ڊگهو Fpscr;
    بنانشان ڊگهو ڊگهو D[8];
  } JUMP_بفر;
#وإلاإذا defined(_ARM64_)

#وصف_ڪريو _JBLEN 24
#وصف_ڪريو _JBTYPE بنانشان __int64

  تعريفنوع بنية __JUMP_BUFFER {
    بنانشان __int64 چوکٺو;
    بنانشان __int64 Reserved;
    بنانشان __int64 X19;
    بنانشان __int64 X20;
    بنانشان __int64 X21;
    بنانشان __int64 X22;
    بنانشان __int64 X23;
    بنانشان __int64 X24;
    بنانشان __int64 X25;
    بنانشان __int64 X26;
    بنانشان __int64 X27;
    بنانشان __int64 X28;
    بنانشان __int64 Fp;
    بنانشان __int64 Lr;
    بنانشان __int64 Sp;
    بنانشان ڊگهو Fpcr;
    بنانشان ڊگهو Fpsr;
    مزدوج D[8];
  } JUMP_بفر;
#وإلا
#وصف_ڪريو _JBLEN 1
#وصف_ڪريو _JBTYPE صحيح
#جيڪڏهن_پورو
#جيڪڏهن_وصف_نه_ٿيل _JMP_BUF_DEFINED
  تعريفنوع _JBTYPE jmp_buf[_JBLEN];
#وصف_ڪريو _JMP_BUF_DEFINED
#جيڪڏهن_پورو

#هدايت pack(ڪڍو)

#إذا defined __aarch64__
  صحيح _setjmpex(jmp_buf _Buf, فراغ *چوکٺو_2);
  #وصف_ڪريو setjmp(BUF) _setjmpex((BUF), (حرف*)__builtin_frame_address(0) + 224)
#وإلاإذا defined __x86_64__
  صحيح _setjmp(jmp_buf _Buf, فراغ *چوکٺو_2);
  #وصف_ڪريو setjmp(BUF) _setjmp((BUF), __builtin_frame_address(0))
#وإلا /* __i386__ */
  صحيح _setjmp(jmp_buf _Buf);
  #وصف_ڪريو setjmp _setjmp
#جيڪڏهن_پورو

__declspec(noreturn) فراغ longjmp(jmp_buf _Buf,صحيح قدر_2);

#جيڪڏهن_وصف_ٿيل __cplusplus
}
#جيڪڏهن_پورو
#جيڪڏهن_پورو
