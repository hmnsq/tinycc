/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _INC_SETJMP
#ವ್ಯಾಖ್ಯಾನಿಸು _INC_SETJMP

#ಅನ್ತರ್ಭಾವ <_mingw.h>

#ಸೂಚನೆ pack(ತಳ್ಳು,_CRT_PACKING)

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
ಬಾಹ್ಯ "C" {
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ (defined(_X86_) && !defined(__x86_64))

#ವ್ಯಾಖ್ಯಾನಿಸು _JBLEN 16
#ವ್ಯಾಖ್ಯಾನಿಸು _JBTYPE ಪೂರ್ಣಾಂಕ

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ __JUMP_BUFFER {
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ Ebp;
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ Ebx;
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ Edi;
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ Esi;
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ Esp;
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ Eip;
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ Registration;
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ TryLevel;
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ Cookie;
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ UnwindFunc;
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ Unwind_ದತ್ತಾಂಶ[6];
  } JUMP_ಬಫರ್;
#ಅಥವಾಆದರೆ defined(__ia64__)
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ _CRT_ALIGN(16) ರಚನೆ _SETJMP_FLOAT128 {
    __int64 ಕೆಳಗಿನ_Part;
    __int64 ಮೇಲಿನ_Part;
  } SETJMP_FLOAT128;

#ವ್ಯಾಖ್ಯಾನಿಸು _JBLEN 33
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ SETJMP_FLOAT128 _JBTYPE;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ __JUMP_BUFFER {

    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ iAReserved[6];

    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ Registration;
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ TryLevel;
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ Cookie;
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ UnwindFunc;

    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ Unwind_ದತ್ತಾಂಶ[6];

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

  } JUMP_ಬಫರ್;
#ಅಥವಾಆದರೆ defined(__x86_64)
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ _CRT_ALIGN(16) ರಚನೆ _SETJMP_FLOAT128 {
    ಚಿಹ್ನೆರಹಿತ __int64 Part[2];
  } SETJMP_FLOAT128;

#ವ್ಯಾಖ್ಯಾನಿಸು _JBLEN 16
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ SETJMP_FLOAT128 _JBTYPE;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ JUMP_ಬಫರ್ {
    ಚಿಹ್ನೆರಹಿತ __int64 ಚೌಕಟ್ಟು;
    ಚಿಹ್ನೆರಹಿತ __int64 Rbx;
    ಚಿಹ್ನೆರಹಿತ __int64 Rsp;
    ಚಿಹ್ನೆರಹಿತ __int64 Rbp;
    ಚಿಹ್ನೆರಹಿತ __int64 Rsi;
    ಚಿಹ್ನೆರಹಿತ __int64 Rdi;
    ಚಿಹ್ನೆರಹಿತ __int64 R12;
    ಚಿಹ್ನೆರಹಿತ __int64 R13;
    ಚಿಹ್ನೆರಹಿತ __int64 R14;
    ಚಿಹ್ನೆರಹಿತ __int64 R15;
    ಚಿಹ್ನೆರಹಿತ __int64 Rip;
    ಚಿಹ್ನೆರಹಿತ __int64 ಹೆಚ್ಚುವರಿ_2;
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
  } JUMP_ಬಫರ್;
#ಅಥವಾಆದರೆ defined(_ARM_)

#ವ್ಯಾಖ್ಯಾನಿಸು _JBLEN 28
#ವ್ಯಾಖ್ಯಾನಿಸು _JBTYPE ಪೂರ್ಣಾಂಕ

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ __JUMP_BUFFER {
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ಚೌಕಟ್ಟು;
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ R4;
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ R5;
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ R6;
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ R7;
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ R8;
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ R9;
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ R10;
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ R11;
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ Sp;
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ Pc;
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ Fpscr;
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ ದೀರ್ಘ D[8];
  } JUMP_ಬಫರ್;
#ಅಥವಾಆದರೆ defined(_ARM64_)

#ವ್ಯಾಖ್ಯಾನಿಸು _JBLEN 24
#ವ್ಯಾಖ್ಯಾನಿಸು _JBTYPE ಚಿಹ್ನೆರಹಿತ __int64

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ __JUMP_BUFFER {
    ಚಿಹ್ನೆರಹಿತ __int64 ಚೌಕಟ್ಟು;
    ಚಿಹ್ನೆರಹಿತ __int64 Reserved;
    ಚಿಹ್ನೆರಹಿತ __int64 X19;
    ಚಿಹ್ನೆರಹಿತ __int64 X20;
    ಚಿಹ್ನೆರಹಿತ __int64 X21;
    ಚಿಹ್ನೆರಹಿತ __int64 X22;
    ಚಿಹ್ನೆರಹಿತ __int64 X23;
    ಚಿಹ್ನೆರಹಿತ __int64 X24;
    ಚಿಹ್ನೆರಹಿತ __int64 X25;
    ಚಿಹ್ನೆರಹಿತ __int64 X26;
    ಚಿಹ್ನೆರಹಿತ __int64 X27;
    ಚಿಹ್ನೆರಹಿತ __int64 X28;
    ಚಿಹ್ನೆರಹಿತ __int64 Fp;
    ಚಿಹ್ನೆರಹಿತ __int64 Lr;
    ಚಿಹ್ನೆರಹಿತ __int64 Sp;
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ Fpcr;
    ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ Fpsr;
    ದ್ವಿಗುಣ D[8];
  } JUMP_ಬಫರ್;
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು _JBLEN 1
#ವ್ಯಾಖ್ಯಾನಿಸು _JBTYPE ಪೂರ್ಣಾಂಕ
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _JMP_BUF_DEFINED
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ _JBTYPE jmp_buf[_JBLEN];
#ವ್ಯಾಖ್ಯಾನಿಸು _JMP_BUF_DEFINED
#ಆದರೆ_ಅಂತ್ಯ

#ಸೂಚನೆ pack(ತೆಗೆ)

#ಆದರೆ defined __aarch64__
  ಪೂರ್ಣಾಂಕ _setjmpex(jmp_buf _Buf, ಶೂನ್ಯ *ಚೌಕಟ್ಟು_2);
  #ವ್ಯಾಖ್ಯಾನಿಸು setjmp(BUF) _setjmpex((BUF), (ಅಕ್ಷರ*)__builtin_frame_address(0) + 224)
#ಅಥವಾಆದರೆ defined __x86_64__
  ಪೂರ್ಣಾಂಕ _setjmp(jmp_buf _Buf, ಶೂನ್ಯ *ಚೌಕಟ್ಟು_2);
  #ವ್ಯಾಖ್ಯಾನಿಸು setjmp(BUF) _setjmp((BUF), __builtin_frame_address(0))
#ಇಲ್ಲದಿದ್ದರೆ /* __i386__ */
  ಪೂರ್ಣಾಂಕ _setjmp(jmp_buf _Buf);
  #ವ್ಯಾಖ್ಯಾನಿಸು setjmp _setjmp
#ಆದರೆ_ಅಂತ್ಯ

__declspec(noreturn) ಶೂನ್ಯ longjmp(jmp_buf _Buf,ಪೂರ್ಣಾಂಕ ಮೌಲ್ಯ_2);

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
}
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
