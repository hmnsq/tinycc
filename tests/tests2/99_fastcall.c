#ಅನ್ತರ್ಭಾವ <stdio.h>
#ಅನ್ತರ್ಭಾವ <assert.h>

#ಯದಿ !(defined( _WIN32) || (defined(__FreeBSD__) && defined(__i386__)))
#define __fastcall __attribute((fastcall))
#endif

#ifndef __leading_underscore
#define ಚಿಹ್ನೆ_2(x) _##x
#ಅನ್ಯಥಾ
#define ಚಿಹ್ನೆ_2(x) x
#endif

/////////////////////////////////////////////////////////////////////////
//////////                TRAP FRAMEWORK
/////////////////////////////////////////////////////////////////////////
// if you cast 'TRAP' to a function pointer and call it,
//   it will save all 8 registers,
//   and jump into C-code (previously set using 'SET_TRAP_HANDLER(x)'),
//   in C-code you can pop DWORDs from stack and modify registers
//

ಶೂನ್ಯ *ಚಿಹ್ನೆ_2(trap_handler);

ಬಾಹ್ಯ unsigned ವರ್ಣ ಚಿಹ್ನೆ_2(trap)[];
asm (
    ".text;"
    "_trap:;"
    "pushl %esp;"
    "pusha;"
    "addl $0x4, 0xc(%esp);"
    "pushl %esp;"
    "call *_trap_handler;"
    "addl $0x4, %esp;"
    "movl 0xc(%esp), %eax;"
    "movl %eax, 0x20(%esp);"
    "popa;"
    "popl %esp;"
	"ret;"
);

ಸಂರಚನಾ trapframe {
    unsigned edi, esi, ebp, esp, ebx, edx, ecx, eax;
};


#define M_FLOAT(addr) (*(ಭಿನ್ನ *)(addr))
#define M_DWORD(addr) (*(unsigned *)(addr))
#define M_WORD(addr) (*(unsigned short *)(addr))
#define M_BYTE(addr) (*(unsigned ವರ್ಣ *)(addr))
#define R_EAX ((tf)->eax)
#define R_ECX ((tf)->ecx)
#define R_EDX ((tf)->edx)
#define R_EBX ((tf)->ebx)
#define R_ESP ((tf)->esp)
#define R_EBP ((tf)->ebp)
#define R_ESI ((tf)->esi)
#define R_EDI ((tf)->edi)

#define ARG(x) (M_DWORD(R_ESP + (x) * 4))

#define RETN(x) ಕುರು { \
    M_DWORD(R_ESP + (x)) = M_DWORD(R_ESP); \
    R_ESP += (x); \
} ಯಾವತ್ (0)

#define DUMP() ಕುರು { \
    unsigned i; \
    printf("EAX: %08X\n", R_EAX); \
    printf("ECX: %08X\n", R_ECX); \
    printf("EDX: %08X\n", R_EDX); \
    printf("EBX: %08X\n", R_EBX); \
    printf("ESP: %08X\n", R_ESP); \
    printf("EBP: %08X\n", R_EBP); \
    printf("ESI: %08X\n", R_ESI); \
    printf("EDI: %08X\n", R_EDI); \
    printf("\n"); \
    printf("[RETADDR]: %08X\n", M_DWORD(R_ESP)); \
    ಪ್ರತಿ (i = 1; i <= 8; i++) { \
        printf("[ARG%4d]: %08X\n", i, ARG(i)); \
    } \
} ಯಾವತ್ (0)

#define SET_TRAP_HANDLER(x) ((ಚಿಹ್ನೆ_2(trap_handler)) = (x))
#define TRAP ((ಶೂನ್ಯ *) &ಚಿಹ್ನೆ_2(trap))



/////////////////////////////////////////////////////////////////////////
//////////                SAFECALL FRAMEWORK
/////////////////////////////////////////////////////////////////////////
// this framework will convert any calling convention to cdecl
// usage: first set call target with 'SET_SAFECALL_TARGET(x)'
//        then cast 'SAFECALL' to target function pointer type and invoke it
//        after calling, 'ESPDIFF' is the difference of old and new esp

ಶೂನ್ಯ *ಚಿಹ್ನೆ_2(sc_call_target);
unsigned ಚಿಹ್ನೆ_2(sc_retn_addr);
unsigned ಚಿಹ್ನೆ_2(sc_old_esp);
unsigned ಚಿಹ್ನೆ_2(sc_new_esp);

ಬಾಹ್ಯ unsigned ವರ್ಣ ಚಿಹ್ನೆ_2(safecall)[];
asm (
    ".text;"
    "_safecall:;"
    "popl _sc_retn_addr;"
    "movl %esp, _sc_old_esp;"
    "call *_sc_call_target;"
    "movl %esp, _sc_new_esp;"
    "movl _sc_old_esp, %esp;"
	"jmp *_sc_retn_addr;"
);

#define SET_SAFECALL_TARGET(x) ((ಚಿಹ್ನೆ_2(sc_call_target)) = (x))
#define SAFECALL ((ಶೂನ್ಯ *) &ಚಿಹ್ನೆ_2(safecall))
#define ESPDIFF (ಚಿಹ್ನೆ_2(sc_new_esp) - ಚಿಹ್ನೆ_2(sc_old_esp))


/////////////////////////////////////////////////////////////////////////
//////////                TEST FASTCALL INVOKE
/////////////////////////////////////////////////////////////////////////

ಶೂನ್ಯ check_fastcall_invoke_0(ಸಂರಚನಾ trapframe *tf)
{
    //DUMP();
    RETN(0);
}

ಶೂನ್ಯ check_fastcall_invoke_1(ಸಂರಚನಾ trapframe *tf)
{
    //DUMP();
    ಪ್ರತಿಜ್ಞಾ(R_ECX == 0x11111111);
    RETN(0);
}
ಶೂನ್ಯ check_fastcall_invoke_2(ಸಂರಚನಾ trapframe *tf)
{
    //DUMP();
    ಪ್ರತಿಜ್ಞಾ(R_ECX == 0x11111111);
    ಪ್ರತಿಜ್ಞಾ(R_EDX == 0x22222222);
    RETN(0);
}
ಶೂನ್ಯ check_fastcall_invoke_3(ಸಂರಚನಾ trapframe *tf)
{
    //DUMP();
    ಪ್ರತಿಜ್ಞಾ(R_ECX == 0x11111111);
    ಪ್ರತಿಜ್ಞಾ(R_EDX == 0x22222222);
    ಪ್ರತಿಜ್ಞಾ(ARG(1) == 0x33333333);
    RETN(1*4);
}
ಶೂನ್ಯ check_fastcall_invoke_4(ಸಂರಚನಾ trapframe *tf)
{
    //DUMP();
    ಪ್ರತಿಜ್ಞಾ(R_ECX == 0x11111111);
    ಪ್ರತಿಜ್ಞಾ(R_EDX == 0x22222222);
    ಪ್ರತಿಜ್ಞಾ(ARG(1) == 0x33333333);
    ಪ್ರತಿಜ್ಞಾ(ARG(2) == 0x44444444);
    RETN(2*4);
}

ಶೂನ್ಯ check_fastcall_invoke_5(ಸಂರಚನಾ trapframe *tf)
{
    //DUMP();
    ಪ್ರತಿಜ್ಞಾ(R_ECX == 0x11111111);
    ಪ್ರತಿಜ್ಞಾ(R_EDX == 0x22222222);
    ಪ್ರತಿಜ್ಞಾ(ARG(1) == 0x33333333);
    ಪ್ರತಿಜ್ಞಾ(ARG(2) == 0x44444444);
    ಪ್ರತಿಜ್ಞಾ(ARG(3) == 0x55555555);
    RETN(3*4);
}

ಶೂನ್ಯ test_fastcall_invoke()
{
    SET_TRAP_HANDLER(check_fastcall_invoke_0);
    ((ಶೂನ್ಯ __fastcall (*)(ಶೂನ್ಯ)) TRAP)();

    SET_TRAP_HANDLER(check_fastcall_invoke_1);
    ((ಶೂನ್ಯ __fastcall (*)(unsigned)) TRAP)(0x11111111);

    SET_TRAP_HANDLER(check_fastcall_invoke_2);
    ((ಶೂನ್ಯ __fastcall (*)(unsigned, unsigned)) TRAP)(0x11111111, 0x22222222);

    SET_TRAP_HANDLER(check_fastcall_invoke_3);
    ((ಶೂನ್ಯ __fastcall (*)(unsigned, unsigned, unsigned)) TRAP)(0x11111111, 0x22222222, 0x33333333);

    SET_TRAP_HANDLER(check_fastcall_invoke_4);
    ((ಶೂನ್ಯ __fastcall (*)(unsigned, unsigned, unsigned, unsigned)) TRAP)(0x11111111, 0x22222222, 0x33333333, 0x44444444);

    SET_TRAP_HANDLER(check_fastcall_invoke_5);
    ((ಶೂನ್ಯ __fastcall (*)(unsigned, unsigned, unsigned, unsigned, unsigned)) TRAP)(0x11111111, 0x22222222, 0x33333333, 0x44444444, 0x55555555);
}


/////////////////////////////////////////////////////////////////////////
//////////                TEST FUNCTION CODE GENERATION
/////////////////////////////////////////////////////////////////////////

ಪೂರ್ಣಾಙ್ಕ __fastcall check_fastcall_espdiff_0(ಶೂನ್ಯ)
{
    ಪ್ರತ್ಯಾಗಮ 0;
}

ಪೂರ್ಣಾಙ್ಕ __fastcall check_fastcall_espdiff_1(ಪೂರ್ಣಾಙ್ಕ a)
{
    ಪ್ರತ್ಯಾಗಮ a;
}

ಪೂರ್ಣಾಙ್ಕ __fastcall check_fastcall_espdiff_2(ಪೂರ್ಣಾಙ್ಕ a, ಪೂರ್ಣಾಙ್ಕ b)
{
    ಪ್ರತ್ಯಾಗಮ a + b;
}

ಪೂರ್ಣಾಙ್ಕ __fastcall check_fastcall_espdiff_3(ಪೂರ್ಣಾಙ್ಕ a, ಪೂರ್ಣಾಙ್ಕ b, ಪೂರ್ಣಾಙ್ಕ c)
{
    ಪ್ರತ್ಯಾಗಮ a + b + c;
}

ಪೂರ್ಣಾಙ್ಕ __fastcall check_fastcall_espdiff_4(ಪೂರ್ಣಾಙ್ಕ a, ಪೂರ್ಣಾಙ್ಕ b, ಪೂರ್ಣಾಙ್ಕ c, ಪೂರ್ಣಾಙ್ಕ d)
{
    ಪ್ರತ್ಯಾಗಮ a + b + c + d;
}

ಪೂರ್ಣಾಙ್ಕ __fastcall check_fastcall_espdiff_5(ಪೂರ್ಣಾಙ್ಕ a, ಪೂರ್ಣಾಙ್ಕ b, ಪೂರ್ಣಾಙ್ಕ c, ಪೂರ್ಣಾಙ್ಕ d, ಪೂರ್ಣಾಙ್ಕ e)
{
    ಪ್ರತ್ಯಾಗಮ a + b + c + d + e;
}

ಶೂನ್ಯ test_fastcall_espdiff()
{
    ಪೂರ್ಣಾಙ್ಕ x;
    SET_SAFECALL_TARGET(check_fastcall_espdiff_0);
    x = ((typeof(&check_fastcall_espdiff_0))SAFECALL)();
    ಪ್ರತಿಜ್ಞಾ(x == 0);
    ಪ್ರತಿಜ್ಞಾ(ESPDIFF == 0);

    SET_SAFECALL_TARGET(check_fastcall_espdiff_1);
    x = ((typeof(&check_fastcall_espdiff_1))SAFECALL)(1);
    ಪ್ರತಿಜ್ಞಾ(x == 1);
    ಪ್ರತಿಜ್ಞಾ(ESPDIFF == 0);

    SET_SAFECALL_TARGET(check_fastcall_espdiff_2);
    x = ((typeof(&check_fastcall_espdiff_2))SAFECALL)(1, 2);
    ಪ್ರತಿಜ್ಞಾ(x == 1 + 2);
    ಪ್ರತಿಜ್ಞಾ(ESPDIFF == 0);

    SET_SAFECALL_TARGET(check_fastcall_espdiff_3);
    x = ((typeof(&check_fastcall_espdiff_3))SAFECALL)(1, 2, 3);
    ಪ್ರತಿಜ್ಞಾ(x == 1 + 2 + 3);
    ಪ್ರತಿಜ್ಞಾ(ESPDIFF == 1*4);

    SET_SAFECALL_TARGET(check_fastcall_espdiff_4);
    x = ((typeof(&check_fastcall_espdiff_4))SAFECALL)(1, 2, 3, 4);
    ಪ್ರತಿಜ್ಞಾ(x == 1 + 2 + 3 + 4);
    ಪ್ರತಿಜ್ಞಾ(ESPDIFF == 2*4);

    SET_SAFECALL_TARGET(check_fastcall_espdiff_5);
    x = ((typeof(&check_fastcall_espdiff_5))SAFECALL)(1, 2, 3, 4, 5);
    ಪ್ರತಿಜ್ಞಾ(x == 1 + 2 + 3 + 4 + 5);
    ಪ್ರತಿಜ್ಞಾ(ESPDIFF == 3*4);
}

ಪೂರ್ಣಾಙ್ಕ main()
{
#define N 10000
    ಪೂರ್ಣಾಙ್ಕ i;

    ಪ್ರತಿ (i = 1; i <= N; i++) {
        test_fastcall_espdiff();
    }

    ಪ್ರತಿ (i = 1; i <= N; i++) {
        test_fastcall_invoke();
    }

    puts("TEST OK");
    ಪ್ರತ್ಯಾಗಮ 0;
}
