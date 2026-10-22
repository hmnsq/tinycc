#ضمن <stdio.h>
#ضمن <assert.h>

#إذا !(defined( _WIN32) || (defined(__FreeBSD__) && defined(__i386__)))
#تعریف_کړه __fastcall __attribute((fastcall))
#د_که_پای

#که_نه_تعریف_شوی __leading_underscore
#تعریف_کړه نښه_2(x) _##x
#وإلا
#تعریف_کړه نښه_2(x) x
#د_که_پای

/////////////////////////////////////////////////////////////////////////
//////////                TRAP FRAMEWORK
/////////////////////////////////////////////////////////////////////////
// if you cast 'TRAP' to a function pointer and call it,
//   it will save all 8 registers,
//   and jump into C-code (previously set using 'SET_TRAP_HANDLER(x)'),
//   in C-code you can pop DWORDs from stack and modify registers
//

فراغ *نښه_2(trap_handler);

خارجي بینښه حرف نښه_2(trap)[];
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
    بینښه edi, esi, ebp, esp, ebx, edx, ecx, eax;
};


#تعریف_کړه M_FLOAT(addr) (*(عائم *)(addr))
#تعریف_کړه M_DWORD(addr) (*(بینښه *)(addr))
#تعریف_کړه M_کلمه(addr) (*(بینښه لنډ *)(addr))
#تعریف_کړه M_BYTE(addr) (*(بینښه حرف *)(addr))
#تعریف_کړه R_EAX ((tf)->eax)
#تعریف_کړه R_ECX ((tf)->ecx)
#تعریف_کړه R_EDX ((tf)->edx)
#تعریف_کړه R_EBX ((tf)->ebx)
#تعریف_کړه R_ESP ((tf)->esp)
#تعریف_کړه R_EBP ((tf)->ebp)
#تعریف_کړه R_ESI ((tf)->esi)
#تعریف_کړه R_EDI ((tf)->edi)

#تعریف_کړه ARG(x) (M_DWORD(R_ESP + (x) * 4))

#تعریف_کړه RETN(x) افعل { \
    M_DWORD(R_ESP + (x)) = M_DWORD(R_ESP); \
    R_ESP += (x); \
} طالما (0)

#تعریف_کړه DUMP() افعل { \
    بینښه i; \
    چاپ_کړه("EAX: %08X\n", R_EAX); \
    چاپ_کړه("ECX: %08X\n", R_ECX); \
    چاپ_کړه("EDX: %08X\n", R_EDX); \
    چاپ_کړه("EBX: %08X\n", R_EBX); \
    چاپ_کړه("ESP: %08X\n", R_ESP); \
    چاپ_کړه("EBP: %08X\n", R_EBP); \
    چاپ_کړه("ESI: %08X\n", R_ESI); \
    چاپ_کړه("EDI: %08X\n", R_EDI); \
    چاپ_کړه("\n"); \
    چاپ_کړه("[RETADDR]: %08X\n", M_DWORD(R_ESP)); \
    لكل (i = 1; i <= 8; i++) { \
        چاپ_کړه("[ARG%4d]: %08X\n", i, ARG(i)); \
    } \
} طالما (0)

#تعریف_کړه سېټ_TRAP_HANDLER(x) ((نښه_2(trap_handler)) = (x))
#تعریف_کړه TRAP ((فراغ *) &نښه_2(trap))



/////////////////////////////////////////////////////////////////////////
//////////                SAFECALL FRAMEWORK
/////////////////////////////////////////////////////////////////////////
// this framework will convert any calling convention to cdecl
// usage: first set call target with 'SET_SAFECALL_TARGET(x)'
//        then cast 'SAFECALL' to target function pointer type and invoke it
//        after calling, 'ESPDIFF' is the difference of old and new esp

فراغ *نښه_2(sc_call_موخه);
بینښه نښه_2(sc_retn_addr);
بینښه نښه_2(sc_old_esp);
بینښه نښه_2(sc_new_esp);

خارجي بینښه حرف نښه_2(safecall)[];
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

#تعریف_کړه سېټ_SAFECALL_موخه(x) ((نښه_2(sc_call_موخه)) = (x))
#تعریف_کړه SAFECALL ((فراغ *) &نښه_2(safecall))
#تعریف_کړه ESPDIFF (نښه_2(sc_new_esp) - نښه_2(sc_old_esp))


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
    سېټ_TRAP_HANDLER(check_fastcall_invoke_0);
    ((فراغ __fastcall (*)(فراغ)) TRAP)();

    سېټ_TRAP_HANDLER(check_fastcall_invoke_1);
    ((فراغ __fastcall (*)(بینښه)) TRAP)(0x11111111);

    سېټ_TRAP_HANDLER(check_fastcall_invoke_2);
    ((فراغ __fastcall (*)(بینښه, بینښه)) TRAP)(0x11111111, 0x22222222);

    سېټ_TRAP_HANDLER(check_fastcall_invoke_3);
    ((فراغ __fastcall (*)(بینښه, بینښه, بینښه)) TRAP)(0x11111111, 0x22222222, 0x33333333);

    سېټ_TRAP_HANDLER(check_fastcall_invoke_4);
    ((فراغ __fastcall (*)(بینښه, بینښه, بینښه, بینښه)) TRAP)(0x11111111, 0x22222222, 0x33333333, 0x44444444);

    سېټ_TRAP_HANDLER(check_fastcall_invoke_5);
    ((فراغ __fastcall (*)(بینښه, بینښه, بینښه, بینښه, بینښه)) TRAP)(0x11111111, 0x22222222, 0x33333333, 0x44444444, 0x55555555);
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
    سېټ_SAFECALL_موخه(check_fastcall_espdiff_0);
    x = ((typeof(&check_fastcall_espdiff_0))SAFECALL)();
    أكد(x == 0);
    أكد(ESPDIFF == 0);

    سېټ_SAFECALL_موخه(check_fastcall_espdiff_1);
    x = ((typeof(&check_fastcall_espdiff_1))SAFECALL)(1);
    أكد(x == 1);
    أكد(ESPDIFF == 0);

    سېټ_SAFECALL_موخه(check_fastcall_espdiff_2);
    x = ((typeof(&check_fastcall_espdiff_2))SAFECALL)(1, 2);
    أكد(x == 1 + 2);
    أكد(ESPDIFF == 0);

    سېټ_SAFECALL_موخه(check_fastcall_espdiff_3);
    x = ((typeof(&check_fastcall_espdiff_3))SAFECALL)(1, 2, 3);
    أكد(x == 1 + 2 + 3);
    أكد(ESPDIFF == 1*4);

    سېټ_SAFECALL_موخه(check_fastcall_espdiff_4);
    x = ((typeof(&check_fastcall_espdiff_4))SAFECALL)(1, 2, 3, 4);
    أكد(x == 1 + 2 + 3 + 4);
    أكد(ESPDIFF == 2*4);

    سېټ_SAFECALL_موخه(check_fastcall_espdiff_5);
    x = ((typeof(&check_fastcall_espdiff_5))SAFECALL)(1, 2, 3, 4, 5);
    أكد(x == 1 + 2 + 3 + 4 + 5);
    أكد(ESPDIFF == 3*4);
}

صحيح اصلي()
{
#تعریف_کړه N 10000
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
