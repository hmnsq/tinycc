#ضمن <stdio.h>
#ضمن <assert.h>

#إذا !(defined( _WIN32) || (defined(__FreeBSD__) && defined(__i386__)))
#وصف_ڪريو __fastcall __attribute((fastcall))
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل __leading_underscore
#وصف_ڪريو نشان_2(x) _##x
#وإلا
#وصف_ڪريو نشان_2(x) x
#جيڪڏهن_پورو

/////////////////////////////////////////////////////////////////////////
//////////                TRAP FRAMEWORK
/////////////////////////////////////////////////////////////////////////
// if you cast 'TRAP' to a function pointer and call it,
//   it will save all 8 registers,
//   and jump into C-code (previously set using 'SET_TRAP_HANDLER(x)'),
//   in C-code you can pop DWORDs from stack and modify registers
//

فراغ *نشان_2(trap_handler);

خارجي بنانشان حرف نشان_2(trap)[];
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

بنية trapframe {
    بنانشان edi, esi, ebp, esp, ebx, edx, ecx, eax;
};


#وصف_ڪريو M_FLOAT(addr) (*(عائم *)(addr))
#وصف_ڪريو M_DWORD(addr) (*(بنانشان *)(addr))
#وصف_ڪريو M_لفظ(addr) (*(بنانشان ننڍو *)(addr))
#وصف_ڪريو M_BYTE(addr) (*(بنانشان حرف *)(addr))
#وصف_ڪريو R_EAX ((tf)->eax)
#وصف_ڪريو R_ECX ((tf)->ecx)
#وصف_ڪريو R_EDX ((tf)->edx)
#وصف_ڪريو R_EBX ((tf)->ebx)
#وصف_ڪريو R_ESP ((tf)->esp)
#وصف_ڪريو R_EBP ((tf)->ebp)
#وصف_ڪريو R_ESI ((tf)->esi)
#وصف_ڪريو R_EDI ((tf)->edi)

#وصف_ڪريو ARG(x) (M_DWORD(R_ESP + (x) * 4))

#وصف_ڪريو RETN(x) افعل { \
    M_DWORD(R_ESP + (x)) = M_DWORD(R_ESP); \
    R_ESP += (x); \
} طالما (0)

#وصف_ڪريو DUMP() افعل { \
    بنانشان i; \
    لکو("EAX: %08X\n", R_EAX); \
    لکو("ECX: %08X\n", R_ECX); \
    لکو("EDX: %08X\n", R_EDX); \
    لکو("EBX: %08X\n", R_EBX); \
    لکو("ESP: %08X\n", R_ESP); \
    لکو("EBP: %08X\n", R_EBP); \
    لکو("ESI: %08X\n", R_ESI); \
    لکو("EDI: %08X\n", R_EDI); \
    لکو("\n"); \
    لکو("[RETADDR]: %08X\n", M_DWORD(R_ESP)); \
    لكل (i = 1; i <= 8; i++) { \
        لکو("[ARG%4d]: %08X\n", i, ARG(i)); \
    } \
} طالما (0)

#وصف_ڪريو سيٽ_TRAP_HANDLER(x) ((نشان_2(trap_handler)) = (x))
#وصف_ڪريو TRAP ((فراغ *) &نشان_2(trap))



/////////////////////////////////////////////////////////////////////////
//////////                SAFECALL FRAMEWORK
/////////////////////////////////////////////////////////////////////////
// this framework will convert any calling convention to cdecl
// usage: first set call target with 'SET_SAFECALL_TARGET(x)'
//        then cast 'SAFECALL' to target function pointer type and invoke it
//        after calling, 'ESPDIFF' is the difference of old and new esp

فراغ *نشان_2(sc_call_هدف);
بنانشان نشان_2(sc_retn_addr);
بنانشان نشان_2(sc_old_esp);
بنانشان نشان_2(sc_new_esp);

خارجي بنانشان حرف نشان_2(safecall)[];
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

#وصف_ڪريو سيٽ_SAFECALL_هدف(x) ((نشان_2(sc_call_هدف)) = (x))
#وصف_ڪريو SAFECALL ((فراغ *) &نشان_2(safecall))
#وصف_ڪريو ESPDIFF (نشان_2(sc_new_esp) - نشان_2(sc_old_esp))


/////////////////////////////////////////////////////////////////////////
//////////                TEST FASTCALL INVOKE
/////////////////////////////////////////////////////////////////////////

فراغ check_fastcall_invoke_0(بنية trapframe *tf)
{
    //DUMP();
    RETN(0);
}

فراغ check_fastcall_invoke_1(بنية trapframe *tf)
{
    //DUMP();
    أكد(R_ECX == 0x11111111);
    RETN(0);
}
فراغ check_fastcall_invoke_2(بنية trapframe *tf)
{
    //DUMP();
    أكد(R_ECX == 0x11111111);
    أكد(R_EDX == 0x22222222);
    RETN(0);
}
فراغ check_fastcall_invoke_3(بنية trapframe *tf)
{
    //DUMP();
    أكد(R_ECX == 0x11111111);
    أكد(R_EDX == 0x22222222);
    أكد(ARG(1) == 0x33333333);
    RETN(1*4);
}
فراغ check_fastcall_invoke_4(بنية trapframe *tf)
{
    //DUMP();
    أكد(R_ECX == 0x11111111);
    أكد(R_EDX == 0x22222222);
    أكد(ARG(1) == 0x33333333);
    أكد(ARG(2) == 0x44444444);
    RETN(2*4);
}

فراغ check_fastcall_invoke_5(بنية trapframe *tf)
{
    //DUMP();
    أكد(R_ECX == 0x11111111);
    أكد(R_EDX == 0x22222222);
    أكد(ARG(1) == 0x33333333);
    أكد(ARG(2) == 0x44444444);
    أكد(ARG(3) == 0x55555555);
    RETN(3*4);
}

فراغ test_fastcall_invoke()
{
    سيٽ_TRAP_HANDLER(check_fastcall_invoke_0);
    ((فراغ __fastcall (*)(فراغ)) TRAP)();

    سيٽ_TRAP_HANDLER(check_fastcall_invoke_1);
    ((فراغ __fastcall (*)(بنانشان)) TRAP)(0x11111111);

    سيٽ_TRAP_HANDLER(check_fastcall_invoke_2);
    ((فراغ __fastcall (*)(بنانشان, بنانشان)) TRAP)(0x11111111, 0x22222222);

    سيٽ_TRAP_HANDLER(check_fastcall_invoke_3);
    ((فراغ __fastcall (*)(بنانشان, بنانشان, بنانشان)) TRAP)(0x11111111, 0x22222222, 0x33333333);

    سيٽ_TRAP_HANDLER(check_fastcall_invoke_4);
    ((فراغ __fastcall (*)(بنانشان, بنانشان, بنانشان, بنانشان)) TRAP)(0x11111111, 0x22222222, 0x33333333, 0x44444444);

    سيٽ_TRAP_HANDLER(check_fastcall_invoke_5);
    ((فراغ __fastcall (*)(بنانشان, بنانشان, بنانشان, بنانشان, بنانشان)) TRAP)(0x11111111, 0x22222222, 0x33333333, 0x44444444, 0x55555555);
}


/////////////////////////////////////////////////////////////////////////
//////////                TEST FUNCTION CODE GENERATION
/////////////////////////////////////////////////////////////////////////

صحيح __fastcall check_fastcall_espdiff_0(فراغ)
{
    أرجع 0;
}

صحيح __fastcall check_fastcall_espdiff_1(صحيح a)
{
    أرجع a;
}

صحيح __fastcall check_fastcall_espdiff_2(صحيح a, صحيح b)
{
    أرجع a + b;
}

صحيح __fastcall check_fastcall_espdiff_3(صحيح a, صحيح b, صحيح c)
{
    أرجع a + b + c;
}

صحيح __fastcall check_fastcall_espdiff_4(صحيح a, صحيح b, صحيح c, صحيح d)
{
    أرجع a + b + c + d;
}

صحيح __fastcall check_fastcall_espdiff_5(صحيح a, صحيح b, صحيح c, صحيح d, صحيح e)
{
    أرجع a + b + c + d + e;
}

فراغ test_fastcall_espdiff()
{
    صحيح x;
    سيٽ_SAFECALL_هدف(check_fastcall_espdiff_0);
    x = ((typeof(&check_fastcall_espdiff_0))SAFECALL)();
    أكد(x == 0);
    أكد(ESPDIFF == 0);

    سيٽ_SAFECALL_هدف(check_fastcall_espdiff_1);
    x = ((typeof(&check_fastcall_espdiff_1))SAFECALL)(1);
    أكد(x == 1);
    أكد(ESPDIFF == 0);

    سيٽ_SAFECALL_هدف(check_fastcall_espdiff_2);
    x = ((typeof(&check_fastcall_espdiff_2))SAFECALL)(1, 2);
    أكد(x == 1 + 2);
    أكد(ESPDIFF == 0);

    سيٽ_SAFECALL_هدف(check_fastcall_espdiff_3);
    x = ((typeof(&check_fastcall_espdiff_3))SAFECALL)(1, 2, 3);
    أكد(x == 1 + 2 + 3);
    أكد(ESPDIFF == 1*4);

    سيٽ_SAFECALL_هدف(check_fastcall_espdiff_4);
    x = ((typeof(&check_fastcall_espdiff_4))SAFECALL)(1, 2, 3, 4);
    أكد(x == 1 + 2 + 3 + 4);
    أكد(ESPDIFF == 2*4);

    سيٽ_SAFECALL_هدف(check_fastcall_espdiff_5);
    x = ((typeof(&check_fastcall_espdiff_5))SAFECALL)(1, 2, 3, 4, 5);
    أكد(x == 1 + 2 + 3 + 4 + 5);
    أكد(ESPDIFF == 3*4);
}

صحيح مکيه()
{
#وصف_ڪريو N 10000
    صحيح i;

    لكل (i = 1; i <= N; i++) {
        test_fastcall_espdiff();
    }

    لكل (i = 1; i <= N; i++) {
        test_fastcall_invoke();
    }

    puts("TEST OK");
    أرجع 0;
}
