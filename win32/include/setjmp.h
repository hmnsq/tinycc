/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _INC_SETJMP
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _INC_SETJMP

#ਅਨ੍ਤਰ੍ਭਾਵ <_mingw.h>

#ਹਦਾਇਤ pack(ਧੱਕੋ,_CRT_PACKING)

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
ਬਾਹਰੀ "C" {
#ਜੇ_ਅੰਤ

#ਜੇ (defined(_X86_) && !defined(__x86_64))

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _JBLEN 16
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _JBTYPE ਪੂਰਨ

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ __JUMP_BUFFER {
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ Ebp;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ Ebx;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ Edi;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ Esi;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ Esp;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ Eip;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ Registration;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ TryLevel;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ Cookie;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ UnwindFunc;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ Unwind_ਅੰਕੜੇ[6];
  } JUMP_ਬਫਰ;
#ਜਾਂਜੇ defined(__ia64__)
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ _CRT_ALIGN(16) ਬਣਤਰ _SETJMP_FLOAT128 {
    __int64 ਨੀਵਾਂ_Part;
    __int64 ਉੱਚਾ_Part;
  } SETJMP_FLOAT128;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _JBLEN 33
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ SETJMP_FLOAT128 _JBTYPE;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ __JUMP_BUFFER {

    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ iAReserved[6];

    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ Registration;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ TryLevel;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ Cookie;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ UnwindFunc;

    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ Unwind_ਅੰਕੜੇ[6];

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

  } JUMP_ਬਫਰ;
#ਜਾਂਜੇ defined(__x86_64)
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ _CRT_ALIGN(16) ਬਣਤਰ _SETJMP_FLOAT128 {
    ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 Part[2];
  } SETJMP_FLOAT128;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _JBLEN 16
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ SETJMP_FLOAT128 _JBTYPE;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ JUMP_ਬਫਰ {
    ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 ਚੌਖਟਾ;
    ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 Rbx;
    ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 Rsp;
    ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 Rbp;
    ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 Rsi;
    ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 Rdi;
    ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 R12;
    ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 R13;
    ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 R14;
    ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 R15;
    ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 Rip;
    ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 ਵਾਧੂ_2;
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
  } JUMP_ਬਫਰ;
#ਜਾਂਜੇ defined(_ARM_)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _JBLEN 28
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _JBTYPE ਪੂਰਨ

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ __JUMP_BUFFER {
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਚੌਖਟਾ;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ R4;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ R5;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ R6;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ R7;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ R8;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ R9;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ R10;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ R11;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ Sp;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ Pc;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ Fpscr;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ ਲੰਮਾ D[8];
  } JUMP_ਬਫਰ;
#ਜਾਂਜੇ defined(_ARM64_)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _JBLEN 24
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _JBTYPE ਬਿਨਾਨਿਸ਼ਾਨੀ __int64

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ __JUMP_BUFFER {
    ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 ਚੌਖਟਾ;
    ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 Reserved;
    ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 X19;
    ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 X20;
    ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 X21;
    ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 X22;
    ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 X23;
    ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 X24;
    ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 X25;
    ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 X26;
    ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 X27;
    ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 X28;
    ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 Fp;
    ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 Lr;
    ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 Sp;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ Fpcr;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ Fpsr;
    ਦੁੱਗਣਾ D[8];
  } JUMP_ਬਫਰ;
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _JBLEN 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _JBTYPE ਪੂਰਨ
#ਜੇ_ਅੰਤ
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _JMP_BUF_DEFINED
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ _JBTYPE jmp_buf[_JBLEN];
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _JMP_BUF_DEFINED
#ਜੇ_ਅੰਤ

#ਹਦਾਇਤ pack(ਕੱਢੋ)

#ਜੇ defined __aarch64__
  ਪੂਰਨ _setjmpex(jmp_buf _Buf, ਖਾਲੀ *ਚੌਖਟਾ_2);
  #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ setjmp(BUF) _setjmpex((BUF), (ਅੱਖਰ*)__builtin_frame_address(0) + 224)
#ਜਾਂਜੇ defined __x86_64__
  ਪੂਰਨ _setjmp(jmp_buf _Buf, ਖਾਲੀ *ਚੌਖਟਾ_2);
  #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ setjmp(BUF) _setjmp((BUF), __builtin_frame_address(0))
#ਨਹੀਂਤਾਂ /* __i386__ */
  ਪੂਰਨ _setjmp(jmp_buf _Buf);
  #ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ setjmp _setjmp
#ਜੇ_ਅੰਤ

__declspec(noreturn) ਖਾਲੀ longjmp(jmp_buf _Buf,ਪੂਰਨ ਮੁੱਲ_2);

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
}
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
