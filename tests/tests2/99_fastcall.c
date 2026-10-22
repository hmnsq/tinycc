#ଅନ୍ତର୍ଭାଵ <stdio.h>
#ଅନ୍ତର୍ଭାଵ <assert.h>

#ଯଦି !(defined( _WIN32) || (defined(__FreeBSD__) && defined(__i386__)))
#define __fastcall __attribute((fastcall))
#endif

#ifndef __leading_underscore
#define ପ୍ରତୀକ_2(x) _##x
#ଅନ୍ୟଥା
#define ପ୍ରତୀକ_2(x) x
#endif

/////////////////////////////////////////////////////////////////////////
//////////                TRAP FRAMEWORK
/////////////////////////////////////////////////////////////////////////
// if you cast 'TRAP' to a function pointer and call it,
//   it will save all 8 registers,
//   and jump into C-code (previously set using 'SET_TRAP_HANDLER(x)'),
//   in C-code you can pop DWORDs from stack and modify registers
//

ଶୂନ୍ୟ *ପ୍ରତୀକ_2(trap_handler);

ବାହ୍ୟ unsigned ଅକ୍ଷର ପ୍ରତୀକ_2(trap)[];
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

ସଂରଚନା trapframe {
    unsigned edi, esi, ebp, esp, ebx, edx, ecx, eax;
};


#define M_FLOAT(addr) (*(ଦଶମିକ *)(addr))
#define M_DWORD(addr) (*(unsigned *)(addr))
#define M_WORD(addr) (*(unsigned short *)(addr))
#define M_BYTE(addr) (*(unsigned ଅକ୍ଷର *)(addr))
#define R_EAX ((tf)->eax)
#define R_ECX ((tf)->ecx)
#define R_EDX ((tf)->edx)
#define R_EBX ((tf)->ebx)
#define R_ESP ((tf)->esp)
#define R_EBP ((tf)->ebp)
#define R_ESI ((tf)->esi)
#define R_EDI ((tf)->edi)

#define ARG(x) (M_DWORD(R_ESP + (x) * 4))

#define RETN(x) କର { \
    M_DWORD(R_ESP + (x)) = M_DWORD(R_ESP); \
    R_ESP += (x); \
} ଯେତେବେଳେ (0)

#define DUMP() କର { \
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
    ପାଇଁ (i = 1; i <= 8; i++) { \
        printf("[ARG%4d]: %08X\n", i, ARG(i)); \
    } \
} ଯେତେବେଳେ (0)

#define SET_TRAP_HANDLER(x) ((ପ୍ରତୀକ_2(trap_handler)) = (x))
#define TRAP ((ଶୂନ୍ୟ *) &ପ୍ରତୀକ_2(trap))



/////////////////////////////////////////////////////////////////////////
//////////                SAFECALL FRAMEWORK
/////////////////////////////////////////////////////////////////////////
// this framework will convert any calling convention to cdecl
// usage: first set call target with 'SET_SAFECALL_TARGET(x)'
//        then cast 'SAFECALL' to target function pointer type and invoke it
//        after calling, 'ESPDIFF' is the difference of old and new esp

ଶୂନ୍ୟ *ପ୍ରତୀକ_2(sc_call_target);
unsigned ପ୍ରତୀକ_2(sc_retn_addr);
unsigned ପ୍ରତୀକ_2(sc_old_esp);
unsigned ପ୍ରତୀକ_2(sc_new_esp);

ବାହ୍ୟ unsigned ଅକ୍ଷର ପ୍ରତୀକ_2(safecall)[];
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

#define SET_SAFECALL_TARGET(x) ((ପ୍ରତୀକ_2(sc_call_target)) = (x))
#define SAFECALL ((ଶୂନ୍ୟ *) &ପ୍ରତୀକ_2(safecall))
#define ESPDIFF (ପ୍ରତୀକ_2(sc_new_esp) - ପ୍ରତୀକ_2(sc_old_esp))


/////////////////////////////////////////////////////////////////////////
//////////                TEST FASTCALL INVOKE
/////////////////////////////////////////////////////////////////////////

ଶୂନ୍ୟ check_fastcall_invoke_0(ସଂରଚନା trapframe *tf)
{
    //DUMP();
    RETN(0);
}

ଶୂନ୍ୟ check_fastcall_invoke_1(ସଂରଚନା trapframe *tf)
{
    //DUMP();
    ପ୍ରତିଜ୍ଞା(R_ECX == 0x11111111);
    RETN(0);
}
ଶୂନ୍ୟ check_fastcall_invoke_2(ସଂରଚନା trapframe *tf)
{
    //DUMP();
    ପ୍ରତିଜ୍ଞା(R_ECX == 0x11111111);
    ପ୍ରତିଜ୍ଞା(R_EDX == 0x22222222);
    RETN(0);
}
ଶୂନ୍ୟ check_fastcall_invoke_3(ସଂରଚନା trapframe *tf)
{
    //DUMP();
    ପ୍ରତିଜ୍ଞା(R_ECX == 0x11111111);
    ପ୍ରତିଜ୍ଞା(R_EDX == 0x22222222);
    ପ୍ରତିଜ୍ଞା(ARG(1) == 0x33333333);
    RETN(1*4);
}
ଶୂନ୍ୟ check_fastcall_invoke_4(ସଂରଚନା trapframe *tf)
{
    //DUMP();
    ପ୍ରତିଜ୍ଞା(R_ECX == 0x11111111);
    ପ୍ରତିଜ୍ଞା(R_EDX == 0x22222222);
    ପ୍ରତିଜ୍ଞା(ARG(1) == 0x33333333);
    ପ୍ରତିଜ୍ଞା(ARG(2) == 0x44444444);
    RETN(2*4);
}

ଶୂନ୍ୟ check_fastcall_invoke_5(ସଂରଚନା trapframe *tf)
{
    //DUMP();
    ପ୍ରତିଜ୍ଞା(R_ECX == 0x11111111);
    ପ୍ରତିଜ୍ଞା(R_EDX == 0x22222222);
    ପ୍ରତିଜ୍ଞା(ARG(1) == 0x33333333);
    ପ୍ରତିଜ୍ଞା(ARG(2) == 0x44444444);
    ପ୍ରତିଜ୍ଞା(ARG(3) == 0x55555555);
    RETN(3*4);
}

ଶୂନ୍ୟ test_fastcall_invoke()
{
    SET_TRAP_HANDLER(check_fastcall_invoke_0);
    ((ଶୂନ୍ୟ __fastcall (*)(ଶୂନ୍ୟ)) TRAP)();

    SET_TRAP_HANDLER(check_fastcall_invoke_1);
    ((ଶୂନ୍ୟ __fastcall (*)(unsigned)) TRAP)(0x11111111);

    SET_TRAP_HANDLER(check_fastcall_invoke_2);
    ((ଶୂନ୍ୟ __fastcall (*)(unsigned, unsigned)) TRAP)(0x11111111, 0x22222222);

    SET_TRAP_HANDLER(check_fastcall_invoke_3);
    ((ଶୂନ୍ୟ __fastcall (*)(unsigned, unsigned, unsigned)) TRAP)(0x11111111, 0x22222222, 0x33333333);

    SET_TRAP_HANDLER(check_fastcall_invoke_4);
    ((ଶୂନ୍ୟ __fastcall (*)(unsigned, unsigned, unsigned, unsigned)) TRAP)(0x11111111, 0x22222222, 0x33333333, 0x44444444);

    SET_TRAP_HANDLER(check_fastcall_invoke_5);
    ((ଶୂନ୍ୟ __fastcall (*)(unsigned, unsigned, unsigned, unsigned, unsigned)) TRAP)(0x11111111, 0x22222222, 0x33333333, 0x44444444, 0x55555555);
}


/////////////////////////////////////////////////////////////////////////
//////////                TEST FUNCTION CODE GENERATION
/////////////////////////////////////////////////////////////////////////

ପୂର୍ଣ୍ଣସଂଖ୍ୟା __fastcall check_fastcall_espdiff_0(ଶୂନ୍ୟ)
{
    ଫେରନ୍ତୁ 0;
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା __fastcall check_fastcall_espdiff_1(ପୂର୍ଣ୍ଣସଂଖ୍ୟା a)
{
    ଫେରନ୍ତୁ a;
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା __fastcall check_fastcall_espdiff_2(ପୂର୍ଣ୍ଣସଂଖ୍ୟା a, ପୂର୍ଣ୍ଣସଂଖ୍ୟା b)
{
    ଫେରନ୍ତୁ a + b;
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା __fastcall check_fastcall_espdiff_3(ପୂର୍ଣ୍ଣସଂଖ୍ୟା a, ପୂର୍ଣ୍ଣସଂଖ୍ୟା b, ପୂର୍ଣ୍ଣସଂଖ୍ୟା c)
{
    ଫେରନ୍ତୁ a + b + c;
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା __fastcall check_fastcall_espdiff_4(ପୂର୍ଣ୍ଣସଂଖ୍ୟା a, ପୂର୍ଣ୍ଣସଂଖ୍ୟା b, ପୂର୍ଣ୍ଣସଂଖ୍ୟା c, ପୂର୍ଣ୍ଣସଂଖ୍ୟା d)
{
    ଫେରନ୍ତୁ a + b + c + d;
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା __fastcall check_fastcall_espdiff_5(ପୂର୍ଣ୍ଣସଂଖ୍ୟା a, ପୂର୍ଣ୍ଣସଂଖ୍ୟା b, ପୂର୍ଣ୍ଣସଂଖ୍ୟା c, ପୂର୍ଣ୍ଣସଂଖ୍ୟା d, ପୂର୍ଣ୍ଣସଂଖ୍ୟା e)
{
    ଫେରନ୍ତୁ a + b + c + d + e;
}

ଶୂନ୍ୟ test_fastcall_espdiff()
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା x;
    SET_SAFECALL_TARGET(check_fastcall_espdiff_0);
    x = ((typeof(&check_fastcall_espdiff_0))SAFECALL)();
    ପ୍ରତିଜ୍ଞା(x == 0);
    ପ୍ରତିଜ୍ଞା(ESPDIFF == 0);

    SET_SAFECALL_TARGET(check_fastcall_espdiff_1);
    x = ((typeof(&check_fastcall_espdiff_1))SAFECALL)(1);
    ପ୍ରତିଜ୍ଞା(x == 1);
    ପ୍ରତିଜ୍ଞା(ESPDIFF == 0);

    SET_SAFECALL_TARGET(check_fastcall_espdiff_2);
    x = ((typeof(&check_fastcall_espdiff_2))SAFECALL)(1, 2);
    ପ୍ରତିଜ୍ଞା(x == 1 + 2);
    ପ୍ରତିଜ୍ଞା(ESPDIFF == 0);

    SET_SAFECALL_TARGET(check_fastcall_espdiff_3);
    x = ((typeof(&check_fastcall_espdiff_3))SAFECALL)(1, 2, 3);
    ପ୍ରତିଜ୍ଞା(x == 1 + 2 + 3);
    ପ୍ରତିଜ୍ଞା(ESPDIFF == 1*4);

    SET_SAFECALL_TARGET(check_fastcall_espdiff_4);
    x = ((typeof(&check_fastcall_espdiff_4))SAFECALL)(1, 2, 3, 4);
    ପ୍ରତିଜ୍ଞା(x == 1 + 2 + 3 + 4);
    ପ୍ରତିଜ୍ଞା(ESPDIFF == 2*4);

    SET_SAFECALL_TARGET(check_fastcall_espdiff_5);
    x = ((typeof(&check_fastcall_espdiff_5))SAFECALL)(1, 2, 3, 4, 5);
    ପ୍ରତିଜ୍ଞା(x == 1 + 2 + 3 + 4 + 5);
    ପ୍ରତିଜ୍ଞା(ESPDIFF == 3*4);
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
{
#define N 10000
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;

    ପାଇଁ (i = 1; i <= N; i++) {
        test_fastcall_espdiff();
    }

    ପାଇଁ (i = 1; i <= N; i++) {
        test_fastcall_invoke();
    }

    puts("TEST OK");
    ଫେରନ୍ତୁ 0;
}
