/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#यदि_अपरिभाषितम् _INC_SETJMP
#परिभाषय _INC_SETJMP

#अन्तर्भाव <_mingw.h>

#निर्देशः pack(प्रक्षिप,_CRT_PACKING)

#यदि_परिभाषितम् __cplusplus
बाह्य "C" {
#यदि_अन्तः

#यदि (defined(_X86_) && !defined(__x86_64))

#परिभाषय _JBLEN 16
#परिभाषय _JBTYPE पूर्णाङ्क

  प्रकारनिर्देश संरचना __JUMP_BUFFER {
    अचिह्नित दीर्घ Ebp;
    अचिह्नित दीर्घ Ebx;
    अचिह्नित दीर्घ Edi;
    अचिह्नित दीर्घ Esi;
    अचिह्नित दीर्घ Esp;
    अचिह्नित दीर्घ Eip;
    अचिह्नित दीर्घ Registration;
    अचिह्नित दीर्घ TryLevel;
    अचिह्नित दीर्घ Cookie;
    अचिह्नित दीर्घ UnwindFunc;
    अचिह्नित दीर्घ Unwind_दत्त[6];
  } JUMP_बफर;
#नोचेद्यदि defined(__ia64__)
  प्रकारनिर्देश _CRT_ALIGN(16) संरचना _SETJMP_FLOAT128 {
    __int64 नीचः_Part;
    __int64 उच्चः_Part;
  } SETJMP_FLOAT128;

#परिभाषय _JBLEN 33
  प्रकारनिर्देश SETJMP_FLOAT128 _JBTYPE;

  प्रकारनिर्देश संरचना __JUMP_BUFFER {

    अचिह्नित दीर्घ iAReserved[6];

    अचिह्नित दीर्घ Registration;
    अचिह्नित दीर्घ TryLevel;
    अचिह्नित दीर्घ Cookie;
    अचिह्नित दीर्घ UnwindFunc;

    अचिह्नित दीर्घ Unwind_दत्त[6];

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

  } JUMP_बफर;
#नोचेद्यदि defined(__x86_64)
  प्रकारनिर्देश _CRT_ALIGN(16) संरचना _SETJMP_FLOAT128 {
    अचिह्नित __int64 Part[2];
  } SETJMP_FLOAT128;

#परिभाषय _JBLEN 16
  प्रकारनिर्देश SETJMP_FLOAT128 _JBTYPE;

  प्रकारनिर्देश संरचना JUMP_बफर {
    अचिह्नित __int64 Frame;
    अचिह्नित __int64 Rbx;
    अचिह्नित __int64 Rsp;
    अचिह्नित __int64 Rbp;
    अचिह्नित __int64 Rsi;
    अचिह्नित __int64 Rdi;
    अचिह्नित __int64 R12;
    अचिह्नित __int64 R13;
    अचिह्नित __int64 R14;
    अचिह्नित __int64 R15;
    अचिह्नित __int64 Rip;
    अचिह्नित __int64 अतिरिक्तः_2;
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
  } JUMP_बफर;
#नोचेद्यदि defined(_ARM_)

#परिभाषय _JBLEN 28
#परिभाषय _JBTYPE पूर्णाङ्क

  प्रकारनिर्देश संरचना __JUMP_BUFFER {
    अचिह्नित दीर्घ Frame;
    अचिह्नित दीर्घ R4;
    अचिह्नित दीर्घ R5;
    अचिह्नित दीर्घ R6;
    अचिह्नित दीर्घ R7;
    अचिह्नित दीर्घ R8;
    अचिह्नित दीर्घ R9;
    अचिह्नित दीर्घ R10;
    अचिह्नित दीर्घ R11;
    अचिह्नित दीर्घ Sp;
    अचिह्नित दीर्घ Pc;
    अचिह्नित दीर्घ Fpscr;
    अचिह्नित दीर्घ दीर्घ D[8];
  } JUMP_बफर;
#नोचेद्यदि defined(_ARM64_)

#परिभाषय _JBLEN 24
#परिभाषय _JBTYPE अचिह्नित __int64

  प्रकारनिर्देश संरचना __JUMP_BUFFER {
    अचिह्नित __int64 Frame;
    अचिह्नित __int64 Reserved;
    अचिह्नित __int64 X19;
    अचिह्नित __int64 X20;
    अचिह्नित __int64 X21;
    अचिह्नित __int64 X22;
    अचिह्नित __int64 X23;
    अचिह्नित __int64 X24;
    अचिह्नित __int64 X25;
    अचिह्नित __int64 X26;
    अचिह्नित __int64 X27;
    अचिह्नित __int64 X28;
    अचिह्नित __int64 Fp;
    अचिह्नित __int64 Lr;
    अचिह्नित __int64 Sp;
    अचिह्नित दीर्घ Fpcr;
    अचिह्नित दीर्घ Fpsr;
    द्विगुण D[8];
  } JUMP_बफर;
#अन्यथा
#परिभाषय _JBLEN 1
#परिभाषय _JBTYPE पूर्णाङ्क
#यदि_अन्तः
#यदि_अपरिभाषितम् _JMP_BUF_DEFINED
  प्रकारनिर्देश _JBTYPE jmp_buf[_JBLEN];
#परिभाषय _JMP_BUF_DEFINED
#यदि_अन्तः

#निर्देशः pack(निष्कासय)

#यदि defined __aarch64__
  पूर्णाङ्क _setjmpex(jmp_buf _Buf, शून्य *frame);
  #परिभाषय setjmp(BUF) _setjmpex((BUF), (वर्ण*)__builtin_frame_address(0) + 224)
#नोचेद्यदि defined __x86_64__
  पूर्णाङ्क _setjmp(jmp_buf _Buf, शून्य *frame);
  #परिभाषय setjmp(BUF) _setjmp((BUF), __builtin_frame_address(0))
#अन्यथा /* __i386__ */
  पूर्णाङ्क _setjmp(jmp_buf _Buf);
  #परिभाषय setjmp _setjmp
#यदि_अन्तः

__declspec(noreturn) शून्य longjmp(jmp_buf _Buf,पूर्णाङ्क मानम्_2);

#यदि_परिभाषितम् __cplusplus
}
#यदि_अन्तः
#यदि_अन्तः
