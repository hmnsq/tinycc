/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_غیر_تعریف_شدہ _INC_SETJMP
#تعریف_کرو _INC_SETJMP

#شامل <_mingw.h>

#ہدایت pack(ڈالو,_CRT_PACKING)

#اگر_تعریف_شدہ __cplusplus
خارجی "C" {
#اگر_ختم

#اگر (defined(_X86_) && !defined(__x86_64))

#تعریف_کرو _JBLEN 16
#تعریف_کرو _JBTYPE صحیح

  قسمتعریف ساخت __JUMP_BUFFER {
    غیرعلامتی طویل Ebp;
    غیرعلامتی طویل Ebx;
    غیرعلامتی طویل Edi;
    غیرعلامتی طویل Esi;
    غیرعلامتی طویل Esp;
    غیرعلامتی طویل Eip;
    غیرعلامتی طویل Registration;
    غیرعلامتی طویل TryLevel;
    غیرعلامتی طویل Cookie;
    غیرعلامتی طویل UnwindFunc;
    غیرعلامتی طویل Unwind_ڈیٹا[6];
  } JUMP_بفر;
#وگرنہ_اگر defined(__ia64__)
  قسمتعریف _CRT_ALIGN(16) ساخت _SETJMP_FLOAT128 {
    __int64 کم_Part;
    __int64 بلند_Part;
  } SETJMP_FLOAT128;

#تعریف_کرو _JBLEN 33
  قسمتعریف SETJMP_FLOAT128 _JBTYPE;

  قسمتعریف ساخت __JUMP_BUFFER {

    غیرعلامتی طویل iAReserved[6];

    غیرعلامتی طویل Registration;
    غیرعلامتی طویل TryLevel;
    غیرعلامتی طویل Cookie;
    غیرعلامتی طویل UnwindFunc;

    غیرعلامتی طویل Unwind_ڈیٹا[6];

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
#وگرنہ_اگر defined(__x86_64)
  قسمتعریف _CRT_ALIGN(16) ساخت _SETJMP_FLOAT128 {
    غیرعلامتی __int64 Part[2];
  } SETJMP_FLOAT128;

#تعریف_کرو _JBLEN 16
  قسمتعریف SETJMP_FLOAT128 _JBTYPE;

  قسمتعریف ساخت JUMP_بفر {
    غیرعلامتی __int64 چوکھٹا;
    غیرعلامتی __int64 Rbx;
    غیرعلامتی __int64 Rsp;
    غیرعلامتی __int64 Rbp;
    غیرعلامتی __int64 Rsi;
    غیرعلامتی __int64 Rdi;
    غیرعلامتی __int64 R12;
    غیرعلامتی __int64 R13;
    غیرعلامتی __int64 R14;
    غیرعلامتی __int64 R15;
    غیرعلامتی __int64 Rip;
    غیرعلامتی __int64 فالتو_2;
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
#وگرنہ_اگر defined(_ARM_)

#تعریف_کرو _JBLEN 28
#تعریف_کرو _JBTYPE صحیح

  قسمتعریف ساخت __JUMP_BUFFER {
    غیرعلامتی طویل چوکھٹا;
    غیرعلامتی طویل R4;
    غیرعلامتی طویل R5;
    غیرعلامتی طویل R6;
    غیرعلامتی طویل R7;
    غیرعلامتی طویل R8;
    غیرعلامتی طویل R9;
    غیرعلامتی طویل R10;
    غیرعلامتی طویل R11;
    غیرعلامتی طویل Sp;
    غیرعلامتی طویل Pc;
    غیرعلامتی طویل Fpscr;
    غیرعلامتی طویل طویل D[8];
  } JUMP_بفر;
#وگرنہ_اگر defined(_ARM64_)

#تعریف_کرو _JBLEN 24
#تعریف_کرو _JBTYPE غیرعلامتی __int64

  قسمتعریف ساخت __JUMP_BUFFER {
    غیرعلامتی __int64 چوکھٹا;
    غیرعلامتی __int64 Reserved;
    غیرعلامتی __int64 X19;
    غیرعلامتی __int64 X20;
    غیرعلامتی __int64 X21;
    غیرعلامتی __int64 X22;
    غیرعلامتی __int64 X23;
    غیرعلامتی __int64 X24;
    غیرعلامتی __int64 X25;
    غیرعلامتی __int64 X26;
    غیرعلامتی __int64 X27;
    غیرعلامتی __int64 X28;
    غیرعلامتی __int64 Fp;
    غیرعلامتی __int64 Lr;
    غیرعلامتی __int64 Sp;
    غیرعلامتی طویل Fpcr;
    غیرعلامتی طویل Fpsr;
    دوہرا D[8];
  } JUMP_بفر;
#ورنہ
#تعریف_کرو _JBLEN 1
#تعریف_کرو _JBTYPE صحیح
#اگر_ختم
#اگر_غیر_تعریف_شدہ _JMP_BUF_DEFINED
  قسمتعریف _JBTYPE jmp_buf[_JBLEN];
#تعریف_کرو _JMP_BUF_DEFINED
#اگر_ختم

#ہدایت pack(نکالو)

#اگر defined __aarch64__
  صحیح _setjmpex(jmp_buf _Buf, خالی *چوکھٹا_2);
  #تعریف_کرو setjmp(BUF) _setjmpex((BUF), (حرف*)__builtin_frame_address(0) + 224)
#وگرنہ_اگر defined __x86_64__
  صحیح _setjmp(jmp_buf _Buf, خالی *چوکھٹا_2);
  #تعریف_کرو setjmp(BUF) _setjmp((BUF), __builtin_frame_address(0))
#ورنہ /* __i386__ */
  صحیح _setjmp(jmp_buf _Buf);
  #تعریف_کرو setjmp _setjmp
#اگر_ختم

__declspec(noreturn) خالی longjmp(jmp_buf _Buf,صحیح قدر_2);

#اگر_تعریف_شدہ __cplusplus
}
#اگر_ختم
#اگر_ختم
