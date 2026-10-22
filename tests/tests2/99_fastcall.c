#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <assert.h>

#ਜੇ !(defined( _WIN32) || (defined(__FreeBSD__) && defined(__i386__)))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __fastcall __attribute((fastcall))
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __leading_underscore
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਚਿੰਨ੍ਹ_2(x) _##x
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਚਿੰਨ੍ਹ_2(x) x
#ਜੇ_ਅੰਤ

/////////////////////////////////////////////////////////////////////////
//////////                TRAP FRAMEWORK
/////////////////////////////////////////////////////////////////////////
// if you cast 'TRAP' to a function pointer and call it,
//   it will save all 8 registers,
//   and jump into C-code (previously set using 'SET_TRAP_HANDLER(x)'),
//   in C-code you can pop DWORDs from stack and modify registers
//

ਖਾਲੀ *ਚਿੰਨ੍ਹ_2(trap_handler);

ਬਾਹਰੀ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ ਚਿੰਨ੍ਹ_2(trap)[];
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

ਬਣਤਰ trapframe {
    ਬਿਨਾਨਿਸ਼ਾਨੀ edi, esi, ebp, esp, ebx, edx, ecx, eax;
};


#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ M_FLOAT(addr) (*(ਦਸ਼ਮਲਵ *)(addr))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ M_DWORD(addr) (*(ਬਿਨਾਨਿਸ਼ਾਨੀ *)(addr))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ M_ਸ਼ਬਦ(addr) (*(ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ *)(addr))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ M_BYTE(addr) (*(ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ *)(addr))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_EAX ((tf)->eax)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_ECX ((tf)->ecx)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_EDX ((tf)->edx)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_EBX ((tf)->ebx)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_ESP ((tf)->esp)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_EBP ((tf)->ebp)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_ESI ((tf)->esi)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_EDI ((tf)->edi)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ARG(x) (M_DWORD(R_ESP + (x) * 4))

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RETN(x) ਕਰੋ { \
    M_DWORD(R_ESP + (x)) = M_DWORD(R_ESP); \
    R_ESP += (x); \
} ਜਦੋਂ (0)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DUMP() ਕਰੋ { \
    ਬਿਨਾਨਿਸ਼ਾਨੀ i; \
    ਲਿਖੋ("EAX: %08X\n", R_EAX); \
    ਲਿਖੋ("ECX: %08X\n", R_ECX); \
    ਲਿਖੋ("EDX: %08X\n", R_EDX); \
    ਲਿਖੋ("EBX: %08X\n", R_EBX); \
    ਲਿਖੋ("ESP: %08X\n", R_ESP); \
    ਲਿਖੋ("EBP: %08X\n", R_EBP); \
    ਲਿਖੋ("ESI: %08X\n", R_ESI); \
    ਲਿਖੋ("EDI: %08X\n", R_EDI); \
    ਲਿਖੋ("\n"); \
    ਲਿਖੋ("[RETADDR]: %08X\n", M_DWORD(R_ESP)); \
    ਲਈ (i = 1; i <= 8; i++) { \
        ਲਿਖੋ("[ARG%4d]: %08X\n", i, ARG(i)); \
    } \
} ਜਦੋਂ (0)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_TRAP_HANDLER(x) ((ਚਿੰਨ੍ਹ_2(trap_handler)) = (x))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TRAP ((ਖਾਲੀ *) &ਚਿੰਨ੍ਹ_2(trap))



/////////////////////////////////////////////////////////////////////////
//////////                SAFECALL FRAMEWORK
/////////////////////////////////////////////////////////////////////////
// this framework will convert any calling convention to cdecl
// usage: first set call target with 'SET_SAFECALL_TARGET(x)'
//        then cast 'SAFECALL' to target function pointer type and invoke it
//        after calling, 'ESPDIFF' is the difference of old and new esp

ਖਾਲੀ *ਚਿੰਨ੍ਹ_2(sc_call_ਨਿਸ਼ਾਨਾ);
ਬਿਨਾਨਿਸ਼ਾਨੀ ਚਿੰਨ੍ਹ_2(sc_retn_addr);
ਬਿਨਾਨਿਸ਼ਾਨੀ ਚਿੰਨ੍ਹ_2(sc_old_esp);
ਬਿਨਾਨਿਸ਼ਾਨੀ ਚਿੰਨ੍ਹ_2(sc_new_esp);

ਬਾਹਰੀ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ ਚਿੰਨ੍ਹ_2(safecall)[];
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

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_SAFECALL_ਨਿਸ਼ਾਨਾ(x) ((ਚਿੰਨ੍ਹ_2(sc_call_ਨਿਸ਼ਾਨਾ)) = (x))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SAFECALL ((ਖਾਲੀ *) &ਚਿੰਨ੍ਹ_2(safecall))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ESPDIFF (ਚਿੰਨ੍ਹ_2(sc_new_esp) - ਚਿੰਨ੍ਹ_2(sc_old_esp))


/////////////////////////////////////////////////////////////////////////
//////////                TEST FASTCALL INVOKE
/////////////////////////////////////////////////////////////////////////

ਖਾਲੀ check_fastcall_invoke_0(ਬਣਤਰ trapframe *tf)
{
    //DUMP();
    RETN(0);
}

ਖਾਲੀ check_fastcall_invoke_1(ਬਣਤਰ trapframe *tf)
{
    //DUMP();
    ਪ੍ਰਤਿਜ੍ਞਾ(R_ECX == 0x11111111);
    RETN(0);
}
ਖਾਲੀ check_fastcall_invoke_2(ਬਣਤਰ trapframe *tf)
{
    //DUMP();
    ਪ੍ਰਤਿਜ੍ਞਾ(R_ECX == 0x11111111);
    ਪ੍ਰਤਿਜ੍ਞਾ(R_EDX == 0x22222222);
    RETN(0);
}
ਖਾਲੀ check_fastcall_invoke_3(ਬਣਤਰ trapframe *tf)
{
    //DUMP();
    ਪ੍ਰਤਿਜ੍ਞਾ(R_ECX == 0x11111111);
    ਪ੍ਰਤਿਜ੍ਞਾ(R_EDX == 0x22222222);
    ਪ੍ਰਤਿਜ੍ਞਾ(ARG(1) == 0x33333333);
    RETN(1*4);
}
ਖਾਲੀ check_fastcall_invoke_4(ਬਣਤਰ trapframe *tf)
{
    //DUMP();
    ਪ੍ਰਤਿਜ੍ਞਾ(R_ECX == 0x11111111);
    ਪ੍ਰਤਿਜ੍ਞਾ(R_EDX == 0x22222222);
    ਪ੍ਰਤਿਜ੍ਞਾ(ARG(1) == 0x33333333);
    ਪ੍ਰਤਿਜ੍ਞਾ(ARG(2) == 0x44444444);
    RETN(2*4);
}

ਖਾਲੀ check_fastcall_invoke_5(ਬਣਤਰ trapframe *tf)
{
    //DUMP();
    ਪ੍ਰਤਿਜ੍ਞਾ(R_ECX == 0x11111111);
    ਪ੍ਰਤਿਜ੍ਞਾ(R_EDX == 0x22222222);
    ਪ੍ਰਤਿਜ੍ਞਾ(ARG(1) == 0x33333333);
    ਪ੍ਰਤਿਜ੍ਞਾ(ARG(2) == 0x44444444);
    ਪ੍ਰਤਿਜ੍ਞਾ(ARG(3) == 0x55555555);
    RETN(3*4);
}

ਖਾਲੀ test_fastcall_invoke()
{
    ਸੈੱਟ_TRAP_HANDLER(check_fastcall_invoke_0);
    ((ਖਾਲੀ __fastcall (*)(ਖਾਲੀ)) TRAP)();

    ਸੈੱਟ_TRAP_HANDLER(check_fastcall_invoke_1);
    ((ਖਾਲੀ __fastcall (*)(ਬਿਨਾਨਿਸ਼ਾਨੀ)) TRAP)(0x11111111);

    ਸੈੱਟ_TRAP_HANDLER(check_fastcall_invoke_2);
    ((ਖਾਲੀ __fastcall (*)(ਬਿਨਾਨਿਸ਼ਾਨੀ, ਬਿਨਾਨਿਸ਼ਾਨੀ)) TRAP)(0x11111111, 0x22222222);

    ਸੈੱਟ_TRAP_HANDLER(check_fastcall_invoke_3);
    ((ਖਾਲੀ __fastcall (*)(ਬਿਨਾਨਿਸ਼ਾਨੀ, ਬਿਨਾਨਿਸ਼ਾਨੀ, ਬਿਨਾਨਿਸ਼ਾਨੀ)) TRAP)(0x11111111, 0x22222222, 0x33333333);

    ਸੈੱਟ_TRAP_HANDLER(check_fastcall_invoke_4);
    ((ਖਾਲੀ __fastcall (*)(ਬਿਨਾਨਿਸ਼ਾਨੀ, ਬਿਨਾਨਿਸ਼ਾਨੀ, ਬਿਨਾਨਿਸ਼ਾਨੀ, ਬਿਨਾਨਿਸ਼ਾਨੀ)) TRAP)(0x11111111, 0x22222222, 0x33333333, 0x44444444);

    ਸੈੱਟ_TRAP_HANDLER(check_fastcall_invoke_5);
    ((ਖਾਲੀ __fastcall (*)(ਬਿਨਾਨਿਸ਼ਾਨੀ, ਬਿਨਾਨਿਸ਼ਾਨੀ, ਬਿਨਾਨਿਸ਼ਾਨੀ, ਬਿਨਾਨਿਸ਼ਾਨੀ, ਬਿਨਾਨਿਸ਼ਾਨੀ)) TRAP)(0x11111111, 0x22222222, 0x33333333, 0x44444444, 0x55555555);
}


/////////////////////////////////////////////////////////////////////////
//////////                TEST FUNCTION CODE GENERATION
/////////////////////////////////////////////////////////////////////////

ਪੂਰਨ __fastcall check_fastcall_espdiff_0(ਖਾਲੀ)
{
    ਵਾਪਸ 0;
}

ਪੂਰਨ __fastcall check_fastcall_espdiff_1(ਪੂਰਨ a)
{
    ਵਾਪਸ a;
}

ਪੂਰਨ __fastcall check_fastcall_espdiff_2(ਪੂਰਨ a, ਪੂਰਨ b)
{
    ਵਾਪਸ a + b;
}

ਪੂਰਨ __fastcall check_fastcall_espdiff_3(ਪੂਰਨ a, ਪੂਰਨ b, ਪੂਰਨ c)
{
    ਵਾਪਸ a + b + c;
}

ਪੂਰਨ __fastcall check_fastcall_espdiff_4(ਪੂਰਨ a, ਪੂਰਨ b, ਪੂਰਨ c, ਪੂਰਨ d)
{
    ਵਾਪਸ a + b + c + d;
}

ਪੂਰਨ __fastcall check_fastcall_espdiff_5(ਪੂਰਨ a, ਪੂਰਨ b, ਪੂਰਨ c, ਪੂਰਨ d, ਪੂਰਨ e)
{
    ਵਾਪਸ a + b + c + d + e;
}

ਖਾਲੀ test_fastcall_espdiff()
{
    ਪੂਰਨ x;
    ਸੈੱਟ_SAFECALL_ਨਿਸ਼ਾਨਾ(check_fastcall_espdiff_0);
    x = ((typeof(&check_fastcall_espdiff_0))SAFECALL)();
    ਪ੍ਰਤਿਜ੍ਞਾ(x == 0);
    ਪ੍ਰਤਿਜ੍ਞਾ(ESPDIFF == 0);

    ਸੈੱਟ_SAFECALL_ਨਿਸ਼ਾਨਾ(check_fastcall_espdiff_1);
    x = ((typeof(&check_fastcall_espdiff_1))SAFECALL)(1);
    ਪ੍ਰਤਿਜ੍ਞਾ(x == 1);
    ਪ੍ਰਤਿਜ੍ਞਾ(ESPDIFF == 0);

    ਸੈੱਟ_SAFECALL_ਨਿਸ਼ਾਨਾ(check_fastcall_espdiff_2);
    x = ((typeof(&check_fastcall_espdiff_2))SAFECALL)(1, 2);
    ਪ੍ਰਤਿਜ੍ਞਾ(x == 1 + 2);
    ਪ੍ਰਤਿਜ੍ਞਾ(ESPDIFF == 0);

    ਸੈੱਟ_SAFECALL_ਨਿਸ਼ਾਨਾ(check_fastcall_espdiff_3);
    x = ((typeof(&check_fastcall_espdiff_3))SAFECALL)(1, 2, 3);
    ਪ੍ਰਤਿਜ੍ਞਾ(x == 1 + 2 + 3);
    ਪ੍ਰਤਿਜ੍ਞਾ(ESPDIFF == 1*4);

    ਸੈੱਟ_SAFECALL_ਨਿਸ਼ਾਨਾ(check_fastcall_espdiff_4);
    x = ((typeof(&check_fastcall_espdiff_4))SAFECALL)(1, 2, 3, 4);
    ਪ੍ਰਤਿਜ੍ਞਾ(x == 1 + 2 + 3 + 4);
    ਪ੍ਰਤਿਜ੍ਞਾ(ESPDIFF == 2*4);

    ਸੈੱਟ_SAFECALL_ਨਿਸ਼ਾਨਾ(check_fastcall_espdiff_5);
    x = ((typeof(&check_fastcall_espdiff_5))SAFECALL)(1, 2, 3, 4, 5);
    ਪ੍ਰਤਿਜ੍ਞਾ(x == 1 + 2 + 3 + 4 + 5);
    ਪ੍ਰਤਿਜ੍ਞਾ(ESPDIFF == 3*4);
}

ਪੂਰਨ ਮੁੱਖ()
{
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ N 10000
    ਪੂਰਨ i;

    ਲਈ (i = 1; i <= N; i++) {
        test_fastcall_espdiff();
    }

    ਲਈ (i = 1; i <= N; i++) {
        test_fastcall_invoke();
    }

    puts("TEST OK");
    ਵਾਪਸ 0;
}
