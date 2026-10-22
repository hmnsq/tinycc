#অন্তর্ভাব <stdio.h>
#অন্তর্ভাব <assert.h>

#যদি !(defined( _WIN32) || (defined(__FreeBSD__) && defined(__i386__)))
#define __fastcall __attribute((fastcall))
#endif

#ifndef __leading_underscore
#define প্রতীক_2(x) _##x
#অন্যথা
#define প্রতীক_2(x) x
#endif

/////////////////////////////////////////////////////////////////////////
//////////                TRAP FRAMEWORK
/////////////////////////////////////////////////////////////////////////
// if you cast 'TRAP' to a function pointer and call it,
//   it will save all 8 registers,
//   and jump into C-code (previously set using 'SET_TRAP_HANDLER(x)'),
//   in C-code you can pop DWORDs from stack and modify registers
//

শূন্য *প্রতীক_2(trap_handler);

বাহ্যিক unsigned অক্ষর প্রতীক_2(trap)[];
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

কাঠামো trapframe {
    unsigned edi, esi, ebp, esp, ebx, edx, ecx, eax;
};


#define M_FLOAT(addr) (*(দশমিক *)(addr))
#define M_DWORD(addr) (*(unsigned *)(addr))
#define M_WORD(addr) (*(unsigned short *)(addr))
#define M_BYTE(addr) (*(unsigned অক্ষর *)(addr))
#define R_EAX ((tf)->eax)
#define R_ECX ((tf)->ecx)
#define R_EDX ((tf)->edx)
#define R_EBX ((tf)->ebx)
#define R_ESP ((tf)->esp)
#define R_EBP ((tf)->ebp)
#define R_ESI ((tf)->esi)
#define R_EDI ((tf)->edi)

#define ARG(x) (M_DWORD(R_ESP + (x) * 4))

#define RETN(x) করো { \
    M_DWORD(R_ESP + (x)) = M_DWORD(R_ESP); \
    R_ESP += (x); \
} যখন (0)

#define DUMP() করো { \
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
    জন্য (i = 1; i <= 8; i++) { \
        printf("[ARG%4d]: %08X\n", i, ARG(i)); \
    } \
} যখন (0)

#define SET_TRAP_HANDLER(x) ((প্রতীক_2(trap_handler)) = (x))
#define TRAP ((শূন্য *) &প্রতীক_2(trap))



/////////////////////////////////////////////////////////////////////////
//////////                SAFECALL FRAMEWORK
/////////////////////////////////////////////////////////////////////////
// this framework will convert any calling convention to cdecl
// usage: first set call target with 'SET_SAFECALL_TARGET(x)'
//        then cast 'SAFECALL' to target function pointer type and invoke it
//        after calling, 'ESPDIFF' is the difference of old and new esp

শূন্য *প্রতীক_2(sc_call_target);
unsigned প্রতীক_2(sc_retn_addr);
unsigned প্রতীক_2(sc_old_esp);
unsigned প্রতীক_2(sc_new_esp);

বাহ্যিক unsigned অক্ষর প্রতীক_2(safecall)[];
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

#define SET_SAFECALL_TARGET(x) ((প্রতীক_2(sc_call_target)) = (x))
#define SAFECALL ((শূন্য *) &প্রতীক_2(safecall))
#define ESPDIFF (প্রতীক_2(sc_new_esp) - প্রতীক_2(sc_old_esp))


/////////////////////////////////////////////////////////////////////////
//////////                TEST FASTCALL INVOKE
/////////////////////////////////////////////////////////////////////////

শূন্য check_fastcall_invoke_0(কাঠামো trapframe *tf)
{
    //DUMP();
    RETN(0);
}

শূন্য check_fastcall_invoke_1(কাঠামো trapframe *tf)
{
    //DUMP();
    প্রতিজ্ঞা(R_ECX == 0x11111111);
    RETN(0);
}
শূন্য check_fastcall_invoke_2(কাঠামো trapframe *tf)
{
    //DUMP();
    প্রতিজ্ঞা(R_ECX == 0x11111111);
    প্রতিজ্ঞা(R_EDX == 0x22222222);
    RETN(0);
}
শূন্য check_fastcall_invoke_3(কাঠামো trapframe *tf)
{
    //DUMP();
    প্রতিজ্ঞা(R_ECX == 0x11111111);
    প্রতিজ্ঞা(R_EDX == 0x22222222);
    প্রতিজ্ঞা(ARG(1) == 0x33333333);
    RETN(1*4);
}
শূন্য check_fastcall_invoke_4(কাঠামো trapframe *tf)
{
    //DUMP();
    প্রতিজ্ঞা(R_ECX == 0x11111111);
    প্রতিজ্ঞা(R_EDX == 0x22222222);
    প্রতিজ্ঞা(ARG(1) == 0x33333333);
    প্রতিজ্ঞা(ARG(2) == 0x44444444);
    RETN(2*4);
}

শূন্য check_fastcall_invoke_5(কাঠামো trapframe *tf)
{
    //DUMP();
    প্রতিজ্ঞা(R_ECX == 0x11111111);
    প্রতিজ্ঞা(R_EDX == 0x22222222);
    প্রতিজ্ঞা(ARG(1) == 0x33333333);
    প্রতিজ্ঞা(ARG(2) == 0x44444444);
    প্রতিজ্ঞা(ARG(3) == 0x55555555);
    RETN(3*4);
}

শূন্য test_fastcall_invoke()
{
    SET_TRAP_HANDLER(check_fastcall_invoke_0);
    ((শূন্য __fastcall (*)(শূন্য)) TRAP)();

    SET_TRAP_HANDLER(check_fastcall_invoke_1);
    ((শূন্য __fastcall (*)(unsigned)) TRAP)(0x11111111);

    SET_TRAP_HANDLER(check_fastcall_invoke_2);
    ((শূন্য __fastcall (*)(unsigned, unsigned)) TRAP)(0x11111111, 0x22222222);

    SET_TRAP_HANDLER(check_fastcall_invoke_3);
    ((শূন্য __fastcall (*)(unsigned, unsigned, unsigned)) TRAP)(0x11111111, 0x22222222, 0x33333333);

    SET_TRAP_HANDLER(check_fastcall_invoke_4);
    ((শূন্য __fastcall (*)(unsigned, unsigned, unsigned, unsigned)) TRAP)(0x11111111, 0x22222222, 0x33333333, 0x44444444);

    SET_TRAP_HANDLER(check_fastcall_invoke_5);
    ((শূন্য __fastcall (*)(unsigned, unsigned, unsigned, unsigned, unsigned)) TRAP)(0x11111111, 0x22222222, 0x33333333, 0x44444444, 0x55555555);
}


/////////////////////////////////////////////////////////////////////////
//////////                TEST FUNCTION CODE GENERATION
/////////////////////////////////////////////////////////////////////////

পূর্ণসংখ্যা __fastcall check_fastcall_espdiff_0(শূন্য)
{
    ফেরত 0;
}

পূর্ণসংখ্যা __fastcall check_fastcall_espdiff_1(পূর্ণসংখ্যা a)
{
    ফেরত a;
}

পূর্ণসংখ্যা __fastcall check_fastcall_espdiff_2(পূর্ণসংখ্যা a, পূর্ণসংখ্যা b)
{
    ফেরত a + b;
}

পূর্ণসংখ্যা __fastcall check_fastcall_espdiff_3(পূর্ণসংখ্যা a, পূর্ণসংখ্যা b, পূর্ণসংখ্যা c)
{
    ফেরত a + b + c;
}

পূর্ণসংখ্যা __fastcall check_fastcall_espdiff_4(পূর্ণসংখ্যা a, পূর্ণসংখ্যা b, পূর্ণসংখ্যা c, পূর্ণসংখ্যা d)
{
    ফেরত a + b + c + d;
}

পূর্ণসংখ্যা __fastcall check_fastcall_espdiff_5(পূর্ণসংখ্যা a, পূর্ণসংখ্যা b, পূর্ণসংখ্যা c, পূর্ণসংখ্যা d, পূর্ণসংখ্যা e)
{
    ফেরত a + b + c + d + e;
}

শূন্য test_fastcall_espdiff()
{
    পূর্ণসংখ্যা x;
    SET_SAFECALL_TARGET(check_fastcall_espdiff_0);
    x = ((typeof(&check_fastcall_espdiff_0))SAFECALL)();
    প্রতিজ্ঞা(x == 0);
    প্রতিজ্ঞা(ESPDIFF == 0);

    SET_SAFECALL_TARGET(check_fastcall_espdiff_1);
    x = ((typeof(&check_fastcall_espdiff_1))SAFECALL)(1);
    প্রতিজ্ঞা(x == 1);
    প্রতিজ্ঞা(ESPDIFF == 0);

    SET_SAFECALL_TARGET(check_fastcall_espdiff_2);
    x = ((typeof(&check_fastcall_espdiff_2))SAFECALL)(1, 2);
    প্রতিজ্ঞা(x == 1 + 2);
    প্রতিজ্ঞা(ESPDIFF == 0);

    SET_SAFECALL_TARGET(check_fastcall_espdiff_3);
    x = ((typeof(&check_fastcall_espdiff_3))SAFECALL)(1, 2, 3);
    প্রতিজ্ঞা(x == 1 + 2 + 3);
    প্রতিজ্ঞা(ESPDIFF == 1*4);

    SET_SAFECALL_TARGET(check_fastcall_espdiff_4);
    x = ((typeof(&check_fastcall_espdiff_4))SAFECALL)(1, 2, 3, 4);
    প্রতিজ্ঞা(x == 1 + 2 + 3 + 4);
    প্রতিজ্ঞা(ESPDIFF == 2*4);

    SET_SAFECALL_TARGET(check_fastcall_espdiff_5);
    x = ((typeof(&check_fastcall_espdiff_5))SAFECALL)(1, 2, 3, 4, 5);
    প্রতিজ্ঞা(x == 1 + 2 + 3 + 4 + 5);
    প্রতিজ্ঞা(ESPDIFF == 3*4);
}

পূর্ণসংখ্যা প্রধান()
{
#define N 10000
    পূর্ণসংখ্যা i;

    জন্য (i = 1; i <= N; i++) {
        test_fastcall_espdiff();
    }

    জন্য (i = 1; i <= N; i++) {
        test_fastcall_invoke();
    }

    puts("TEST OK");
    ফেরত 0;
}
