/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_SETJMP
#define _INC_SETJMP

#अन्तर्भाव <_mingw.h>

#pragma pack(थप,_CRT_PACKING)

#ifdef __cplusplus
बाह्य "C" {
#endif

#यदि (defined(_X86_) && !defined(__x86_64))

#define _JBLEN 16
#define _JBTYPE पूर्णाङ्क

  प्रकारनिर्देश संरचना __JUMP_BUFFER {
    अचिन्हित दीर्घ Ebp;
    अचिन्हित दीर्घ Ebx;
    अचिन्हित दीर्घ Edi;
    अचिन्हित दीर्घ Esi;
    अचिन्हित दीर्घ Esp;
    अचिन्हित दीर्घ Eip;
    अचिन्हित दीर्घ Registration;
    अचिन्हित दीर्घ TryLevel;
    अचिन्हित दीर्घ Cookie;
    अचिन्हित दीर्घ UnwindFunc;
    अचिन्हित दीर्घ UnwindData[6];
  } _JUMP_BUFFER;
#अथवायदि defined(__ia64__)
  प्रकारनिर्देश _CRT_ALIGN(16) संरचना _SETJMP_FLOAT128 {
    __int64 तल्लो_Part;
    __int64 माथिल्लो_Part;
  } SETJMP_FLOAT128;

#define _JBLEN 33
  प्रकारनिर्देश SETJMP_FLOAT128 _JBTYPE;

  प्रकारनिर्देश संरचना __JUMP_BUFFER {

    अचिन्हित दीर्घ iAReserved[6];

    अचिन्हित दीर्घ Registration;
    अचिन्हित दीर्घ TryLevel;
    अचिन्हित दीर्घ Cookie;
    अचिन्हित दीर्घ UnwindFunc;

    अचिन्हित दीर्घ UnwindData[6];

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
#अथवायदि defined(__x86_64)
  प्रकारनिर्देश _CRT_ALIGN(16) संरचना _SETJMP_FLOAT128 {
    अचिन्हित __int64 Part[2];
  } SETJMP_FLOAT128;

#define _JBLEN 16
  प्रकारनिर्देश SETJMP_FLOAT128 _JBTYPE;

  प्रकारनिर्देश संरचना _JUMP_BUFFER {
    अचिन्हित __int64 Frame;
    अचिन्हित __int64 Rbx;
    अचिन्हित __int64 Rsp;
    अचिन्हित __int64 Rbp;
    अचिन्हित __int64 Rsi;
    अचिन्हित __int64 Rdi;
    अचिन्हित __int64 R12;
    अचिन्हित __int64 R13;
    अचिन्हित __int64 R14;
    अचिन्हित __int64 R15;
    अचिन्हित __int64 Rip;
    अचिन्हित __int64 Spare;
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
#अथवायदि defined(_ARM_)

#define _JBLEN 28
#define _JBTYPE पूर्णाङ्क

  प्रकारनिर्देश संरचना __JUMP_BUFFER {
    अचिन्हित दीर्घ Frame;
    अचिन्हित दीर्घ R4;
    अचिन्हित दीर्घ R5;
    अचिन्हित दीर्घ R6;
    अचिन्हित दीर्घ R7;
    अचिन्हित दीर्घ R8;
    अचिन्हित दीर्घ R9;
    अचिन्हित दीर्घ R10;
    अचिन्हित दीर्घ R11;
    अचिन्हित दीर्घ Sp;
    अचिन्हित दीर्घ Pc;
    अचिन्हित दीर्घ Fpscr;
    अचिन्हित दीर्घ दीर्घ D[8];
  } _JUMP_BUFFER;
#अथवायदि defined(_ARM64_)

#define _JBLEN 24
#define _JBTYPE अचिन्हित __int64

  प्रकारनिर्देश संरचना __JUMP_BUFFER {
    अचिन्हित __int64 Frame;
    अचिन्हित __int64 Reserved;
    अचिन्हित __int64 X19;
    अचिन्हित __int64 X20;
    अचिन्हित __int64 X21;
    अचिन्हित __int64 X22;
    अचिन्हित __int64 X23;
    अचिन्हित __int64 X24;
    अचिन्हित __int64 X25;
    अचिन्हित __int64 X26;
    अचिन्हित __int64 X27;
    अचिन्हित __int64 X28;
    अचिन्हित __int64 Fp;
    अचिन्हित __int64 Lr;
    अचिन्हित __int64 Sp;
    अचिन्हित दीर्घ Fpcr;
    अचिन्हित दीर्घ Fpsr;
    द्विगुण D[8];
  } _JUMP_BUFFER;
#अन्यथा
#define _JBLEN 1
#define _JBTYPE पूर्णाङ्क
#endif
#ifndef _JMP_BUF_DEFINED
  प्रकारनिर्देश _JBTYPE लाँघ_बफ[_JBLEN];
#define _JMP_BUF_DEFINED
#endif

#pragma pack(झिक)

#यदि defined __aarch64__
  पूर्णाङ्क _setjmpex(लाँघ_बफ _Buf, शून्य *frame);
  #define बनाओ_लाँघ(BUF) _setjmpex((BUF), (वर्ण*)__builtin_frame_address(0) + 224)
#अथवायदि defined __x86_64__
  पूर्णाङ्क _setjmp(लाँघ_बफ _Buf, शून्य *frame);
  #define बनाओ_लाँघ(BUF) _setjmp((BUF), __builtin_frame_address(0))
#अन्यथा /* __i386__ */
  पूर्णाङ्क _setjmp(लाँघ_बफ _Buf);
  #define बनाओ_लाँघ _setjmp
#endif

__declspec(noreturn) शून्य दीर्घ_लाँघ(लाँघ_बफ _Buf,पूर्णाङ्क मान_2);

#ifdef __cplusplus
}
#endif
#endif
