#അന്തര്ഭാവ <stdio.h>
#അന്തര്ഭാവ <assert.h>

#എങ്കിൽ !(defined( _WIN32) || (defined(__FreeBSD__) && defined(__i386__)))
#define __fastcall __attribute((fastcall))
#endif

#ifndef __leading_underscore
#define ചിഹ്നം_2(x) _##x
#അല്ലെങ്കിൽ
#define ചിഹ്നം_2(x) x
#endif

/////////////////////////////////////////////////////////////////////////
//////////                TRAP FRAMEWORK
/////////////////////////////////////////////////////////////////////////
// if you cast 'TRAP' to a function pointer and call it,
//   it will save all 8 registers,
//   and jump into C-code (previously set using 'SET_TRAP_HANDLER(x)'),
//   in C-code you can pop DWORDs from stack and modify registers
//

ശൂന്യം *ചിഹ്നം_2(trap_handler);

ബാഹ്യ unsigned അക്ഷരം ചിഹ്നം_2(trap)[];
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

ഘടന trapframe {
    unsigned edi, esi, ebp, esp, ebx, edx, ecx, eax;
};


#define M_FLOAT(addr) (*(ദശാംശം *)(addr))
#define M_DWORD(addr) (*(unsigned *)(addr))
#define M_WORD(addr) (*(unsigned short *)(addr))
#define M_BYTE(addr) (*(unsigned അക്ഷരം *)(addr))
#define R_EAX ((tf)->eax)
#define R_ECX ((tf)->ecx)
#define R_EDX ((tf)->edx)
#define R_EBX ((tf)->ebx)
#define R_ESP ((tf)->esp)
#define R_EBP ((tf)->ebp)
#define R_ESI ((tf)->esi)
#define R_EDI ((tf)->edi)

#define ARG(x) (M_DWORD(R_ESP + (x) * 4))

#define RETN(x) ചെയ്യുക { \
    M_DWORD(R_ESP + (x)) = M_DWORD(R_ESP); \
    R_ESP += (x); \
} ആകുമ്പോൾ (0)

#define DUMP() ചെയ്യുക { \
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
    വേണ്ടി (i = 1; i <= 8; i++) { \
        printf("[ARG%4d]: %08X\n", i, ARG(i)); \
    } \
} ആകുമ്പോൾ (0)

#define SET_TRAP_HANDLER(x) ((ചിഹ്നം_2(trap_handler)) = (x))
#define TRAP ((ശൂന്യം *) &ചിഹ്നം_2(trap))



/////////////////////////////////////////////////////////////////////////
//////////                SAFECALL FRAMEWORK
/////////////////////////////////////////////////////////////////////////
// this framework will convert any calling convention to cdecl
// usage: first set call target with 'SET_SAFECALL_TARGET(x)'
//        then cast 'SAFECALL' to target function pointer type and invoke it
//        after calling, 'ESPDIFF' is the difference of old and new esp

ശൂന്യം *ചിഹ്നം_2(sc_call_target);
unsigned ചിഹ്നം_2(sc_retn_addr);
unsigned ചിഹ്നം_2(sc_old_esp);
unsigned ചിഹ്നം_2(sc_new_esp);

ബാഹ്യ unsigned അക്ഷരം ചിഹ്നം_2(safecall)[];
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

#define SET_SAFECALL_TARGET(x) ((ചിഹ്നം_2(sc_call_target)) = (x))
#define SAFECALL ((ശൂന്യം *) &ചിഹ്നം_2(safecall))
#define ESPDIFF (ചിഹ്നം_2(sc_new_esp) - ചിഹ്നം_2(sc_old_esp))


/////////////////////////////////////////////////////////////////////////
//////////                TEST FASTCALL INVOKE
/////////////////////////////////////////////////////////////////////////

ശൂന്യം check_fastcall_invoke_0(ഘടന trapframe *tf)
{
    //DUMP();
    RETN(0);
}

ശൂന്യം check_fastcall_invoke_1(ഘടന trapframe *tf)
{
    //DUMP();
    പ്രതിജ്ഞാ(R_ECX == 0x11111111);
    RETN(0);
}
ശൂന്യം check_fastcall_invoke_2(ഘടന trapframe *tf)
{
    //DUMP();
    പ്രതിജ്ഞാ(R_ECX == 0x11111111);
    പ്രതിജ്ഞാ(R_EDX == 0x22222222);
    RETN(0);
}
ശൂന്യം check_fastcall_invoke_3(ഘടന trapframe *tf)
{
    //DUMP();
    പ്രതിജ്ഞാ(R_ECX == 0x11111111);
    പ്രതിജ്ഞാ(R_EDX == 0x22222222);
    പ്രതിജ്ഞാ(ARG(1) == 0x33333333);
    RETN(1*4);
}
ശൂന്യം check_fastcall_invoke_4(ഘടന trapframe *tf)
{
    //DUMP();
    പ്രതിജ്ഞാ(R_ECX == 0x11111111);
    പ്രതിജ്ഞാ(R_EDX == 0x22222222);
    പ്രതിജ്ഞാ(ARG(1) == 0x33333333);
    പ്രതിജ്ഞാ(ARG(2) == 0x44444444);
    RETN(2*4);
}

ശൂന്യം check_fastcall_invoke_5(ഘടന trapframe *tf)
{
    //DUMP();
    പ്രതിജ്ഞാ(R_ECX == 0x11111111);
    പ്രതിജ്ഞാ(R_EDX == 0x22222222);
    പ്രതിജ്ഞാ(ARG(1) == 0x33333333);
    പ്രതിജ്ഞാ(ARG(2) == 0x44444444);
    പ്രതിജ്ഞാ(ARG(3) == 0x55555555);
    RETN(3*4);
}

ശൂന്യം test_fastcall_invoke()
{
    SET_TRAP_HANDLER(check_fastcall_invoke_0);
    ((ശൂന്യം __fastcall (*)(ശൂന്യം)) TRAP)();

    SET_TRAP_HANDLER(check_fastcall_invoke_1);
    ((ശൂന്യം __fastcall (*)(unsigned)) TRAP)(0x11111111);

    SET_TRAP_HANDLER(check_fastcall_invoke_2);
    ((ശൂന്യം __fastcall (*)(unsigned, unsigned)) TRAP)(0x11111111, 0x22222222);

    SET_TRAP_HANDLER(check_fastcall_invoke_3);
    ((ശൂന്യം __fastcall (*)(unsigned, unsigned, unsigned)) TRAP)(0x11111111, 0x22222222, 0x33333333);

    SET_TRAP_HANDLER(check_fastcall_invoke_4);
    ((ശൂന്യം __fastcall (*)(unsigned, unsigned, unsigned, unsigned)) TRAP)(0x11111111, 0x22222222, 0x33333333, 0x44444444);

    SET_TRAP_HANDLER(check_fastcall_invoke_5);
    ((ശൂന്യം __fastcall (*)(unsigned, unsigned, unsigned, unsigned, unsigned)) TRAP)(0x11111111, 0x22222222, 0x33333333, 0x44444444, 0x55555555);
}


/////////////////////////////////////////////////////////////////////////
//////////                TEST FUNCTION CODE GENERATION
/////////////////////////////////////////////////////////////////////////

പൂർണ്ണസംഖ്യ __fastcall check_fastcall_espdiff_0(ശൂന്യം)
{
    തിരികെ 0;
}

പൂർണ്ണസംഖ്യ __fastcall check_fastcall_espdiff_1(പൂർണ്ണസംഖ്യ a)
{
    തിരികെ a;
}

പൂർണ്ണസംഖ്യ __fastcall check_fastcall_espdiff_2(പൂർണ്ണസംഖ്യ a, പൂർണ്ണസംഖ്യ b)
{
    തിരികെ a + b;
}

പൂർണ്ണസംഖ്യ __fastcall check_fastcall_espdiff_3(പൂർണ്ണസംഖ്യ a, പൂർണ്ണസംഖ്യ b, പൂർണ്ണസംഖ്യ c)
{
    തിരികെ a + b + c;
}

പൂർണ്ണസംഖ്യ __fastcall check_fastcall_espdiff_4(പൂർണ്ണസംഖ്യ a, പൂർണ്ണസംഖ്യ b, പൂർണ്ണസംഖ്യ c, പൂർണ്ണസംഖ്യ d)
{
    തിരികെ a + b + c + d;
}

പൂർണ്ണസംഖ്യ __fastcall check_fastcall_espdiff_5(പൂർണ്ണസംഖ്യ a, പൂർണ്ണസംഖ്യ b, പൂർണ്ണസംഖ്യ c, പൂർണ്ണസംഖ്യ d, പൂർണ്ണസംഖ്യ e)
{
    തിരികെ a + b + c + d + e;
}

ശൂന്യം test_fastcall_espdiff()
{
    പൂർണ്ണസംഖ്യ x;
    SET_SAFECALL_TARGET(check_fastcall_espdiff_0);
    x = ((typeof(&check_fastcall_espdiff_0))SAFECALL)();
    പ്രതിജ്ഞാ(x == 0);
    പ്രതിജ്ഞാ(ESPDIFF == 0);

    SET_SAFECALL_TARGET(check_fastcall_espdiff_1);
    x = ((typeof(&check_fastcall_espdiff_1))SAFECALL)(1);
    പ്രതിജ്ഞാ(x == 1);
    പ്രതിജ്ഞാ(ESPDIFF == 0);

    SET_SAFECALL_TARGET(check_fastcall_espdiff_2);
    x = ((typeof(&check_fastcall_espdiff_2))SAFECALL)(1, 2);
    പ്രതിജ്ഞാ(x == 1 + 2);
    പ്രതിജ്ഞാ(ESPDIFF == 0);

    SET_SAFECALL_TARGET(check_fastcall_espdiff_3);
    x = ((typeof(&check_fastcall_espdiff_3))SAFECALL)(1, 2, 3);
    പ്രതിജ്ഞാ(x == 1 + 2 + 3);
    പ്രതിജ്ഞാ(ESPDIFF == 1*4);

    SET_SAFECALL_TARGET(check_fastcall_espdiff_4);
    x = ((typeof(&check_fastcall_espdiff_4))SAFECALL)(1, 2, 3, 4);
    പ്രതിജ്ഞാ(x == 1 + 2 + 3 + 4);
    പ്രതിജ്ഞാ(ESPDIFF == 2*4);

    SET_SAFECALL_TARGET(check_fastcall_espdiff_5);
    x = ((typeof(&check_fastcall_espdiff_5))SAFECALL)(1, 2, 3, 4, 5);
    പ്രതിജ്ഞാ(x == 1 + 2 + 3 + 4 + 5);
    പ്രതിജ്ഞാ(ESPDIFF == 3*4);
}

പൂർണ്ണസംഖ്യ പ്രധാന()
{
#define N 10000
    പൂർണ്ണസംഖ്യ i;

    വേണ്ടി (i = 1; i <= N; i++) {
        test_fastcall_espdiff();
    }

    വേണ്ടി (i = 1; i <= N; i++) {
        test_fastcall_invoke();
    }

    puts("TEST OK");
    തിരികെ 0;
}
