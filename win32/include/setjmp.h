/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_تعریف_نشده _INC_SETJMP
#تعریف_کن _INC_SETJMP

#ضمن <_mingw.h>

#رهنمود pack(افزودن,_CRT_PACKING)

#اگر_تعریف_شده __cplusplus
خارجي "C" {
#پایان_اگر

#إذا (defined(_X86_) && !defined(__x86_64))

#تعریف_کن _JBLEN 16
#تعریف_کن _JBTYPE صحيح

  تعريفنوع بنية __JUMP_BUFFER {
    بیعلامت دراز Ebp;
    بیعلامت دراز Ebx;
    بیعلامت دراز Edi;
    بیعلامت دراز Esi;
    بیعلامت دراز Esp;
    بیعلامت دراز Eip;
    بیعلامت دراز Registration;
    بیعلامت دراز TryLevel;
    بیعلامت دراز Cookie;
    بیعلامت دراز UnwindFunc;
    بیعلامت دراز Unwind_داده[6];
  } JUMP_میانگیر;
#وإلاإذا defined(__ia64__)
  تعريفنوع _CRT_ALIGN(16) بنية _SETJMP_FLOAT128 {
    __int64 کم_Part;
    __int64 بالا_Part;
  } SETJMP_FLOAT128;

#تعریف_کن _JBLEN 33
  تعريفنوع SETJMP_FLOAT128 _JBTYPE;

  تعريفنوع بنية __JUMP_BUFFER {

    بیعلامت دراز iAReserved[6];

    بیعلامت دراز Registration;
    بیعلامت دراز TryLevel;
    بیعلامت دراز Cookie;
    بیعلامت دراز UnwindFunc;

    بیعلامت دراز Unwind_داده[6];

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

  } JUMP_میانگیر;
#وإلاإذا defined(__x86_64)
  تعريفنوع _CRT_ALIGN(16) بنية _SETJMP_FLOAT128 {
    بیعلامت __int64 Part[2];
  } SETJMP_FLOAT128;

#تعریف_کن _JBLEN 16
  تعريفنوع SETJMP_FLOAT128 _JBTYPE;

  تعريفنوع بنية JUMP_میانگیر {
    بیعلامت __int64 قاب;
    بیعلامت __int64 Rbx;
    بیعلامت __int64 Rsp;
    بیعلامت __int64 Rbp;
    بیعلامت __int64 Rsi;
    بیعلامت __int64 Rdi;
    بیعلامت __int64 R12;
    بیعلامت __int64 R13;
    بیعلامت __int64 R14;
    بیعلامت __int64 R15;
    بیعلامت __int64 Rip;
    بیعلامت __int64 یدکی_2;
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
  } JUMP_میانگیر;
#وإلاإذا defined(_ARM_)

#تعریف_کن _JBLEN 28
#تعریف_کن _JBTYPE صحيح

  تعريفنوع بنية __JUMP_BUFFER {
    بیعلامت دراز قاب;
    بیعلامت دراز R4;
    بیعلامت دراز R5;
    بیعلامت دراز R6;
    بیعلامت دراز R7;
    بیعلامت دراز R8;
    بیعلامت دراز R9;
    بیعلامت دراز R10;
    بیعلامت دراز R11;
    بیعلامت دراز Sp;
    بیعلامت دراز Pc;
    بیعلامت دراز Fpscr;
    بیعلامت دراز دراز D[8];
  } JUMP_میانگیر;
#وإلاإذا defined(_ARM64_)

#تعریف_کن _JBLEN 24
#تعریف_کن _JBTYPE بیعلامت __int64

  تعريفنوع بنية __JUMP_BUFFER {
    بیعلامت __int64 قاب;
    بیعلامت __int64 Reserved;
    بیعلامت __int64 X19;
    بیعلامت __int64 X20;
    بیعلامت __int64 X21;
    بیعلامت __int64 X22;
    بیعلامت __int64 X23;
    بیعلامت __int64 X24;
    بیعلامت __int64 X25;
    بیعلامت __int64 X26;
    بیعلامت __int64 X27;
    بیعلامت __int64 X28;
    بیعلامت __int64 Fp;
    بیعلامت __int64 Lr;
    بیعلامت __int64 Sp;
    بیعلامت دراز Fpcr;
    بیعلامت دراز Fpsr;
    مزدوج D[8];
  } JUMP_میانگیر;
#وإلا
#تعریف_کن _JBLEN 1
#تعریف_کن _JBTYPE صحيح
#پایان_اگر
#اگر_تعریف_نشده _JMP_BUF_DEFINED
  تعريفنوع _JBTYPE jmp_buf[_JBLEN];
#تعریف_کن _JMP_BUF_DEFINED
#پایان_اگر

#رهنمود pack(برداشت)

#إذا defined __aarch64__
  صحيح _setjmpex(jmp_buf _Buf, فراغ *قاب_2);
  #تعریف_کن setjmp(BUF) _setjmpex((BUF), (حرف*)__builtin_frame_address(0) + 224)
#وإلاإذا defined __x86_64__
  صحيح _setjmp(jmp_buf _Buf, فراغ *قاب_2);
  #تعریف_کن setjmp(BUF) _setjmp((BUF), __builtin_frame_address(0))
#وإلا /* __i386__ */
  صحيح _setjmp(jmp_buf _Buf);
  #تعریف_کن setjmp _setjmp
#پایان_اگر

__declspec(noreturn) فراغ longjmp(jmp_buf _Buf,صحيح مقدار_2);

#اگر_تعریف_شده __cplusplus
}
#پایان_اگر
#پایان_اگر
