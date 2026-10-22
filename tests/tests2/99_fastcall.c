#ضمن <stdio.h>
#ضمن <assert.h>

#إذا !(defined( _WIN32) || (defined(__FreeBSD__) && defined(__i386__)))
#تعریف_کرو __fastcall __attribute((fastcall))
#جے_انت

#جے_بنا_تعریف __leading_underscore
#تعریف_کرو علامت_2(x) _##x
#وإلا
#تعریف_کرو علامت_2(x) x
#جے_انت

/////////////////////////////////////////////////////////////////////////
//////////                TRAP FRAMEWORK
/////////////////////////////////////////////////////////////////////////
// if you cast 'TRAP' to a function pointer and call it,
//   it will save all 8 registers,
//   and jump into C-code (previously set using 'SET_TRAP_HANDLER(x)'),
//   in C-code you can pop DWORDs from stack and modify registers
//

فراغ *علامت_2(trap_handler);

خارجي بنانشانی حرف علامت_2(trap)[];
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
    بنانشانی edi, esi, ebp, esp, ebx, edx, ecx, eax;
};


#تعریف_کرو M_FLOAT(addr) (*(عائم *)(addr))
#تعریف_کرو M_DWORD(addr) (*(بنانشانی *)(addr))
#تعریف_کرو M_لفظ(addr) (*(بنانشانی چھوٹا *)(addr))
#تعریف_کرو M_BYTE(addr) (*(بنانشانی حرف *)(addr))
#تعریف_کرو R_EAX ((tf)->eax)
#تعریف_کرو R_ECX ((tf)->ecx)
#تعریف_کرو R_EDX ((tf)->edx)
#تعریف_کرو R_EBX ((tf)->ebx)
#تعریف_کرو R_ESP ((tf)->esp)
#تعریف_کرو R_EBP ((tf)->ebp)
#تعریف_کرو R_ESI ((tf)->esi)
#تعریف_کرو R_EDI ((tf)->edi)

#تعریف_کرو ARG(x) (M_DWORD(R_ESP + (x) * 4))

#تعریف_کرو RETN(x) افعل { \
    M_DWORD(R_ESP + (x)) = M_DWORD(R_ESP); \
    R_ESP += (x); \
} طالما (0)

#تعریف_کرو DUMP() افعل { \
    بنانشانی i; \
    لکھو("EAX: %08X\n", R_EAX); \
    لکھو("ECX: %08X\n", R_ECX); \
    لکھو("EDX: %08X\n", R_EDX); \
    لکھو("EBX: %08X\n", R_EBX); \
    لکھو("ESP: %08X\n", R_ESP); \
    لکھو("EBP: %08X\n", R_EBP); \
    لکھو("ESI: %08X\n", R_ESI); \
    لکھو("EDI: %08X\n", R_EDI); \
    لکھو("\n"); \
    لکھو("[RETADDR]: %08X\n", M_DWORD(R_ESP)); \
    لكل (i = 1; i <= 8; i++) { \
        لکھو("[ARG%4d]: %08X\n", i, ARG(i)); \
    } \
} طالما (0)

#تعریف_کرو سیٹ_TRAP_HANDLER(x) ((علامت_2(trap_handler)) = (x))
#تعریف_کرو TRAP ((فراغ *) &علامت_2(trap))



/////////////////////////////////////////////////////////////////////////
//////////                SAFECALL FRAMEWORK
/////////////////////////////////////////////////////////////////////////
// this framework will convert any calling convention to cdecl
// usage: first set call target with 'SET_SAFECALL_TARGET(x)'
//        then cast 'SAFECALL' to target function pointer type and invoke it
//        after calling, 'ESPDIFF' is the difference of old and new esp

فراغ *علامت_2(sc_call_نشانہ);
بنانشانی علامت_2(sc_retn_addr);
بنانشانی علامت_2(sc_old_esp);
بنانشانی علامت_2(sc_new_esp);

خارجي بنانشانی حرف علامت_2(safecall)[];
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

#تعریف_کرو سیٹ_SAFECALL_نشانہ(x) ((علامت_2(sc_call_نشانہ)) = (x))
#تعریف_کرو SAFECALL ((فراغ *) &علامت_2(safecall))
#تعریف_کرو ESPDIFF (علامت_2(sc_new_esp) - علامت_2(sc_old_esp))


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
    سیٹ_TRAP_HANDLER(check_fastcall_invoke_0);
    ((فراغ __fastcall (*)(فراغ)) TRAP)();

    سیٹ_TRAP_HANDLER(check_fastcall_invoke_1);
    ((فراغ __fastcall (*)(بنانشانی)) TRAP)(0x11111111);

    سیٹ_TRAP_HANDLER(check_fastcall_invoke_2);
    ((فراغ __fastcall (*)(بنانشانی, بنانشانی)) TRAP)(0x11111111, 0x22222222);

    سیٹ_TRAP_HANDLER(check_fastcall_invoke_3);
    ((فراغ __fastcall (*)(بنانشانی, بنانشانی, بنانشانی)) TRAP)(0x11111111, 0x22222222, 0x33333333);

    سیٹ_TRAP_HANDLER(check_fastcall_invoke_4);
    ((فراغ __fastcall (*)(بنانشانی, بنانشانی, بنانشانی, بنانشانی)) TRAP)(0x11111111, 0x22222222, 0x33333333, 0x44444444);

    سیٹ_TRAP_HANDLER(check_fastcall_invoke_5);
    ((فراغ __fastcall (*)(بنانشانی, بنانشانی, بنانشانی, بنانشانی, بنانشانی)) TRAP)(0x11111111, 0x22222222, 0x33333333, 0x44444444, 0x55555555);
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
    سیٹ_SAFECALL_نشانہ(check_fastcall_espdiff_0);
    x = ((typeof(&check_fastcall_espdiff_0))SAFECALL)();
    أكد(x == 0);
    أكد(ESPDIFF == 0);

    سیٹ_SAFECALL_نشانہ(check_fastcall_espdiff_1);
    x = ((typeof(&check_fastcall_espdiff_1))SAFECALL)(1);
    أكد(x == 1);
    أكد(ESPDIFF == 0);

    سیٹ_SAFECALL_نشانہ(check_fastcall_espdiff_2);
    x = ((typeof(&check_fastcall_espdiff_2))SAFECALL)(1, 2);
    أكد(x == 1 + 2);
    أكد(ESPDIFF == 0);

    سیٹ_SAFECALL_نشانہ(check_fastcall_espdiff_3);
    x = ((typeof(&check_fastcall_espdiff_3))SAFECALL)(1, 2, 3);
    أكد(x == 1 + 2 + 3);
    أكد(ESPDIFF == 1*4);

    سیٹ_SAFECALL_نشانہ(check_fastcall_espdiff_4);
    x = ((typeof(&check_fastcall_espdiff_4))SAFECALL)(1, 2, 3, 4);
    أكد(x == 1 + 2 + 3 + 4);
    أكد(ESPDIFF == 2*4);

    سیٹ_SAFECALL_نشانہ(check_fastcall_espdiff_5);
    x = ((typeof(&check_fastcall_espdiff_5))SAFECALL)(1, 2, 3, 4, 5);
    أكد(x == 1 + 2 + 3 + 4 + 5);
    أكد(ESPDIFF == 3*4);
}

صحيح مکھ()
{
#تعریف_کرو N 10000
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
