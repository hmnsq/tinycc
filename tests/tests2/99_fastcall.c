#ಅನ್ತರ್ಭಾವ <stdio.h>
#ಅನ್ತರ್ಭಾವ <assert.h>

#ಆದರೆ !(defined( _WIN32) || (defined(__FreeBSD__) && defined(__i386__)))
#ವ್ಯಾಖ್ಯಾನಿಸು __fastcall __attribute((fastcall))
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __leading_underscore
#ವ್ಯಾಖ್ಯಾನಿಸು ಚಿಹ್ನೆ_2(x) _##x
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು ಚಿಹ್ನೆ_2(x) x
#ಆದರೆ_ಅಂತ್ಯ

/////////////////////////////////////////////////////////////////////////
//////////                TRAP FRAMEWORK
/////////////////////////////////////////////////////////////////////////
// if you cast 'TRAP' to a function pointer and call it,
//   it will save all 8 registers,
//   and jump into C-code (previously set using 'SET_TRAP_HANDLER(x)'),
//   in C-code you can pop DWORDs from stack and modify registers
//

ಶೂನ್ಯ *ಚಿಹ್ನೆ_2(trap_handler);

ಬಾಹ್ಯ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ ಚಿಹ್ನೆ_2(trap)[];
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

ರಚನೆ trapframe {
    ಚಿಹ್ನೆರಹಿತ edi, esi, ebp, esp, ebx, edx, ecx, eax;
};


#ವ್ಯಾಖ್ಯಾನಿಸು M_FLOAT(addr) (*(ದಶಮಾಂಶ *)(addr))
#ವ್ಯಾಖ್ಯಾನಿಸು M_DWORD(addr) (*(ಚಿಹ್ನೆರಹಿತ *)(addr))
#ವ್ಯಾಖ್ಯಾನಿಸು M_ಶಬ್ದ(addr) (*(ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ *)(addr))
#ವ್ಯಾಖ್ಯಾನಿಸು M_BYTE(addr) (*(ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ *)(addr))
#ವ್ಯಾಖ್ಯಾನಿಸು R_EAX ((tf)->eax)
#ವ್ಯಾಖ್ಯಾನಿಸು R_ECX ((tf)->ecx)
#ವ್ಯಾಖ್ಯಾನಿಸು R_EDX ((tf)->edx)
#ವ್ಯಾಖ್ಯಾನಿಸು R_EBX ((tf)->ebx)
#ವ್ಯಾಖ್ಯಾನಿಸು R_ESP ((tf)->esp)
#ವ್ಯಾಖ್ಯಾನಿಸು R_EBP ((tf)->ebp)
#ವ್ಯಾಖ್ಯಾನಿಸು R_ESI ((tf)->esi)
#ವ್ಯಾಖ್ಯಾನಿಸು R_EDI ((tf)->edi)

#ವ್ಯಾಖ್ಯಾನಿಸು ARG(x) (M_DWORD(R_ESP + (x) * 4))

#ವ್ಯಾಖ್ಯಾನಿಸು RETN(x) ಮಾಡು { \
    M_DWORD(R_ESP + (x)) = M_DWORD(R_ESP); \
    R_ESP += (x); \
} ಆಗ (0)

#ವ್ಯಾಖ್ಯಾನಿಸು DUMP() ಮಾಡು { \
    ಚಿಹ್ನೆರಹಿತ i; \
    ಬರೆ("EAX: %08X\n", R_EAX); \
    ಬರೆ("ECX: %08X\n", R_ECX); \
    ಬರೆ("EDX: %08X\n", R_EDX); \
    ಬರೆ("EBX: %08X\n", R_EBX); \
    ಬರೆ("ESP: %08X\n", R_ESP); \
    ಬರೆ("EBP: %08X\n", R_EBP); \
    ಬರೆ("ESI: %08X\n", R_ESI); \
    ಬರೆ("EDI: %08X\n", R_EDI); \
    ಬರೆ("\n"); \
    ಬರೆ("[RETADDR]: %08X\n", M_DWORD(R_ESP)); \
    ಗಾಗಿ (i = 1; i <= 8; i++) { \
        ಬರೆ("[ARG%4d]: %08X\n", i, ARG(i)); \
    } \
} ಆಗ (0)

#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_TRAP_HANDLER(x) ((ಚಿಹ್ನೆ_2(trap_handler)) = (x))
#ವ್ಯಾಖ್ಯಾನಿಸು TRAP ((ಶೂನ್ಯ *) &ಚಿಹ್ನೆ_2(trap))



/////////////////////////////////////////////////////////////////////////
//////////                SAFECALL FRAMEWORK
/////////////////////////////////////////////////////////////////////////
// this framework will convert any calling convention to cdecl
// usage: first set call target with 'SET_SAFECALL_TARGET(x)'
//        then cast 'SAFECALL' to target function pointer type and invoke it
//        after calling, 'ESPDIFF' is the difference of old and new esp

ಶೂನ್ಯ *ಚಿಹ್ನೆ_2(sc_call_ಗುರಿ);
ಚಿಹ್ನೆರಹಿತ ಚಿಹ್ನೆ_2(sc_retn_addr);
ಚಿಹ್ನೆರಹಿತ ಚಿಹ್ನೆ_2(sc_old_esp);
ಚಿಹ್ನೆರಹಿತ ಚಿಹ್ನೆ_2(sc_new_esp);

ಬಾಹ್ಯ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ ಚಿಹ್ನೆ_2(safecall)[];
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

#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_SAFECALL_ಗುರಿ(x) ((ಚಿಹ್ನೆ_2(sc_call_ಗುರಿ)) = (x))
#ವ್ಯಾಖ್ಯಾನಿಸು SAFECALL ((ಶೂನ್ಯ *) &ಚಿಹ್ನೆ_2(safecall))
#ವ್ಯಾಖ್ಯಾನಿಸು ESPDIFF (ಚಿಹ್ನೆ_2(sc_new_esp) - ಚಿಹ್ನೆ_2(sc_old_esp))


/////////////////////////////////////////////////////////////////////////
//////////                TEST FASTCALL INVOKE
/////////////////////////////////////////////////////////////////////////

ಶೂನ್ಯ check_fastcall_invoke_0(ರಚನೆ trapframe *tf)
{
    //DUMP();
    RETN(0);
}

ಶೂನ್ಯ check_fastcall_invoke_1(ರಚನೆ trapframe *tf)
{
    //DUMP();
    ಪ್ರತಿಜ್ಞಾ(R_ECX == 0x11111111);
    RETN(0);
}
ಶೂನ್ಯ check_fastcall_invoke_2(ರಚನೆ trapframe *tf)
{
    //DUMP();
    ಪ್ರತಿಜ್ಞಾ(R_ECX == 0x11111111);
    ಪ್ರತಿಜ್ಞಾ(R_EDX == 0x22222222);
    RETN(0);
}
ಶೂನ್ಯ check_fastcall_invoke_3(ರಚನೆ trapframe *tf)
{
    //DUMP();
    ಪ್ರತಿಜ್ಞಾ(R_ECX == 0x11111111);
    ಪ್ರತಿಜ್ಞಾ(R_EDX == 0x22222222);
    ಪ್ರತಿಜ್ಞಾ(ARG(1) == 0x33333333);
    RETN(1*4);
}
ಶೂನ್ಯ check_fastcall_invoke_4(ರಚನೆ trapframe *tf)
{
    //DUMP();
    ಪ್ರತಿಜ್ಞಾ(R_ECX == 0x11111111);
    ಪ್ರತಿಜ್ಞಾ(R_EDX == 0x22222222);
    ಪ್ರತಿಜ್ಞಾ(ARG(1) == 0x33333333);
    ಪ್ರತಿಜ್ಞಾ(ARG(2) == 0x44444444);
    RETN(2*4);
}

ಶೂನ್ಯ check_fastcall_invoke_5(ರಚನೆ trapframe *tf)
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
    ಗಣ_TRAP_HANDLER(check_fastcall_invoke_0);
    ((ಶೂನ್ಯ __fastcall (*)(ಶೂನ್ಯ)) TRAP)();

    ಗಣ_TRAP_HANDLER(check_fastcall_invoke_1);
    ((ಶೂನ್ಯ __fastcall (*)(ಚಿಹ್ನೆರಹಿತ)) TRAP)(0x11111111);

    ಗಣ_TRAP_HANDLER(check_fastcall_invoke_2);
    ((ಶೂನ್ಯ __fastcall (*)(ಚಿಹ್ನೆರಹಿತ, ಚಿಹ್ನೆರಹಿತ)) TRAP)(0x11111111, 0x22222222);

    ಗಣ_TRAP_HANDLER(check_fastcall_invoke_3);
    ((ಶೂನ್ಯ __fastcall (*)(ಚಿಹ್ನೆರಹಿತ, ಚಿಹ್ನೆರಹಿತ, ಚಿಹ್ನೆರಹಿತ)) TRAP)(0x11111111, 0x22222222, 0x33333333);

    ಗಣ_TRAP_HANDLER(check_fastcall_invoke_4);
    ((ಶೂನ್ಯ __fastcall (*)(ಚಿಹ್ನೆರಹಿತ, ಚಿಹ್ನೆರಹಿತ, ಚಿಹ್ನೆರಹಿತ, ಚಿಹ್ನೆರಹಿತ)) TRAP)(0x11111111, 0x22222222, 0x33333333, 0x44444444);

    ಗಣ_TRAP_HANDLER(check_fastcall_invoke_5);
    ((ಶೂನ್ಯ __fastcall (*)(ಚಿಹ್ನೆರಹಿತ, ಚಿಹ್ನೆರಹಿತ, ಚಿಹ್ನೆರಹಿತ, ಚಿಹ್ನೆರಹಿತ, ಚಿಹ್ನೆರಹಿತ)) TRAP)(0x11111111, 0x22222222, 0x33333333, 0x44444444, 0x55555555);
}


/////////////////////////////////////////////////////////////////////////
//////////                TEST FUNCTION CODE GENERATION
/////////////////////////////////////////////////////////////////////////

ಪೂರ್ಣಾಂಕ __fastcall check_fastcall_espdiff_0(ಶೂನ್ಯ)
{
    ಹಿಂತಿರುಗಿ 0;
}

ಪೂರ್ಣಾಂಕ __fastcall check_fastcall_espdiff_1(ಪೂರ್ಣಾಂಕ a)
{
    ಹಿಂತಿರುಗಿ a;
}

ಪೂರ್ಣಾಂಕ __fastcall check_fastcall_espdiff_2(ಪೂರ್ಣಾಂಕ a, ಪೂರ್ಣಾಂಕ b)
{
    ಹಿಂತಿರುಗಿ a + b;
}

ಪೂರ್ಣಾಂಕ __fastcall check_fastcall_espdiff_3(ಪೂರ್ಣಾಂಕ a, ಪೂರ್ಣಾಂಕ b, ಪೂರ್ಣಾಂಕ c)
{
    ಹಿಂತಿರುಗಿ a + b + c;
}

ಪೂರ್ಣಾಂಕ __fastcall check_fastcall_espdiff_4(ಪೂರ್ಣಾಂಕ a, ಪೂರ್ಣಾಂಕ b, ಪೂರ್ಣಾಂಕ c, ಪೂರ್ಣಾಂಕ d)
{
    ಹಿಂತಿರುಗಿ a + b + c + d;
}

ಪೂರ್ಣಾಂಕ __fastcall check_fastcall_espdiff_5(ಪೂರ್ಣಾಂಕ a, ಪೂರ್ಣಾಂಕ b, ಪೂರ್ಣಾಂಕ c, ಪೂರ್ಣಾಂಕ d, ಪೂರ್ಣಾಂಕ e)
{
    ಹಿಂತಿರುಗಿ a + b + c + d + e;
}

ಶೂನ್ಯ test_fastcall_espdiff()
{
    ಪೂರ್ಣಾಂಕ x;
    ಗಣ_SAFECALL_ಗುರಿ(check_fastcall_espdiff_0);
    x = ((typeof(&check_fastcall_espdiff_0))SAFECALL)();
    ಪ್ರತಿಜ್ಞಾ(x == 0);
    ಪ್ರತಿಜ್ಞಾ(ESPDIFF == 0);

    ಗಣ_SAFECALL_ಗುರಿ(check_fastcall_espdiff_1);
    x = ((typeof(&check_fastcall_espdiff_1))SAFECALL)(1);
    ಪ್ರತಿಜ್ಞಾ(x == 1);
    ಪ್ರತಿಜ್ಞಾ(ESPDIFF == 0);

    ಗಣ_SAFECALL_ಗುರಿ(check_fastcall_espdiff_2);
    x = ((typeof(&check_fastcall_espdiff_2))SAFECALL)(1, 2);
    ಪ್ರತಿಜ್ಞಾ(x == 1 + 2);
    ಪ್ರತಿಜ್ಞಾ(ESPDIFF == 0);

    ಗಣ_SAFECALL_ಗುರಿ(check_fastcall_espdiff_3);
    x = ((typeof(&check_fastcall_espdiff_3))SAFECALL)(1, 2, 3);
    ಪ್ರತಿಜ್ಞಾ(x == 1 + 2 + 3);
    ಪ್ರತಿಜ್ಞಾ(ESPDIFF == 1*4);

    ಗಣ_SAFECALL_ಗುರಿ(check_fastcall_espdiff_4);
    x = ((typeof(&check_fastcall_espdiff_4))SAFECALL)(1, 2, 3, 4);
    ಪ್ರತಿಜ್ಞಾ(x == 1 + 2 + 3 + 4);
    ಪ್ರತಿಜ್ಞಾ(ESPDIFF == 2*4);

    ಗಣ_SAFECALL_ಗುರಿ(check_fastcall_espdiff_5);
    x = ((typeof(&check_fastcall_espdiff_5))SAFECALL)(1, 2, 3, 4, 5);
    ಪ್ರತಿಜ್ಞಾ(x == 1 + 2 + 3 + 4 + 5);
    ಪ್ರತಿಜ್ಞಾ(ESPDIFF == 3*4);
}

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
{
#ವ್ಯಾಖ್ಯಾನಿಸು N 10000
    ಪೂರ್ಣಾಂಕ i;

    ಗಾಗಿ (i = 1; i <= N; i++) {
        test_fastcall_espdiff();
    }

    ಗಾಗಿ (i = 1; i <= N; i++) {
        test_fastcall_invoke();
    }

    puts("TEST OK");
    ಹಿಂತಿರುಗಿ 0;
}
