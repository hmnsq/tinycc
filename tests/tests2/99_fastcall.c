#ضمن <stdio.h>
#ضمن <assert.h>

#إذا !(defined( _WIN32) || (defined(__FreeBSD__) && defined(__i386__)))
#تعریف_کن __fastcall __attribute((fastcall))
#پایان_اگر

#اگر_تعریف_نشده __leading_underscore
#تعریف_کن نماد_2(x) _##x
#وإلا
#تعریف_کن نماد_2(x) x
#پایان_اگر

/////////////////////////////////////////////////////////////////////////
//////////                TRAP FRAMEWORK
/////////////////////////////////////////////////////////////////////////
// if you cast 'TRAP' to a function pointer and call it,
//   it will save all 8 registers,
//   and jump into C-code (previously set using 'SET_TRAP_HANDLER(x)'),
//   in C-code you can pop DWORDs from stack and modify registers
//

فراغ *نماد_2(trap_handler);

خارجي بیعلامت حرف نماد_2(trap)[];
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
    بیعلامت edi, esi, ebp, esp, ebx, edx, ecx, eax;
};


#تعریف_کن M_FLOAT(addr) (*(عائم *)(addr))
#تعریف_کن M_DWORD(addr) (*(بیعلامت *)(addr))
#تعریف_کن M_کلمه(addr) (*(بیعلامت کوتاه *)(addr))
#تعریف_کن M_BYTE(addr) (*(بیعلامت حرف *)(addr))
#تعریف_کن R_EAX ((tf)->eax)
#تعریف_کن R_ECX ((tf)->ecx)
#تعریف_کن R_EDX ((tf)->edx)
#تعریف_کن R_EBX ((tf)->ebx)
#تعریف_کن R_ESP ((tf)->esp)
#تعریف_کن R_EBP ((tf)->ebp)
#تعریف_کن R_ESI ((tf)->esi)
#تعریف_کن R_EDI ((tf)->edi)

#تعریف_کن ARG(x) (M_DWORD(R_ESP + (x) * 4))

#تعریف_کن RETN(x) افعل { \
    M_DWORD(R_ESP + (x)) = M_DWORD(R_ESP); \
    R_ESP += (x); \
} طالما (0)

#تعریف_کن DUMP() افعل { \
    بیعلامت i; \
    چاپ_کن("EAX: %08X\n", R_EAX); \
    چاپ_کن("ECX: %08X\n", R_ECX); \
    چاپ_کن("EDX: %08X\n", R_EDX); \
    چاپ_کن("EBX: %08X\n", R_EBX); \
    چاپ_کن("ESP: %08X\n", R_ESP); \
    چاپ_کن("EBP: %08X\n", R_EBP); \
    چاپ_کن("ESI: %08X\n", R_ESI); \
    چاپ_کن("EDI: %08X\n", R_EDI); \
    چاپ_کن("\n"); \
    چاپ_کن("[RETADDR]: %08X\n", M_DWORD(R_ESP)); \
    لكل (i = 1; i <= 8; i++) { \
        چاپ_کن("[ARG%4d]: %08X\n", i, ARG(i)); \
    } \
} طالما (0)

#تعریف_کن مجموعه_TRAP_HANDLER(x) ((نماد_2(trap_handler)) = (x))
#تعریف_کن TRAP ((فراغ *) &نماد_2(trap))



/////////////////////////////////////////////////////////////////////////
//////////                SAFECALL FRAMEWORK
/////////////////////////////////////////////////////////////////////////
// this framework will convert any calling convention to cdecl
// usage: first set call target with 'SET_SAFECALL_TARGET(x)'
//        then cast 'SAFECALL' to target function pointer type and invoke it
//        after calling, 'ESPDIFF' is the difference of old and new esp

فراغ *نماد_2(sc_call_هدف);
بیعلامت نماد_2(sc_retn_addr);
بیعلامت نماد_2(sc_old_esp);
بیعلامت نماد_2(sc_new_esp);

خارجي بیعلامت حرف نماد_2(safecall)[];
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

#تعریف_کن مجموعه_SAFECALL_هدف(x) ((نماد_2(sc_call_هدف)) = (x))
#تعریف_کن SAFECALL ((فراغ *) &نماد_2(safecall))
#تعریف_کن ESPDIFF (نماد_2(sc_new_esp) - نماد_2(sc_old_esp))


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
    مجموعه_TRAP_HANDLER(check_fastcall_invoke_0);
    ((فراغ __fastcall (*)(فراغ)) TRAP)();

    مجموعه_TRAP_HANDLER(check_fastcall_invoke_1);
    ((فراغ __fastcall (*)(بیعلامت)) TRAP)(0x11111111);

    مجموعه_TRAP_HANDLER(check_fastcall_invoke_2);
    ((فراغ __fastcall (*)(بیعلامت, بیعلامت)) TRAP)(0x11111111, 0x22222222);

    مجموعه_TRAP_HANDLER(check_fastcall_invoke_3);
    ((فراغ __fastcall (*)(بیعلامت, بیعلامت, بیعلامت)) TRAP)(0x11111111, 0x22222222, 0x33333333);

    مجموعه_TRAP_HANDLER(check_fastcall_invoke_4);
    ((فراغ __fastcall (*)(بیعلامت, بیعلامت, بیعلامت, بیعلامت)) TRAP)(0x11111111, 0x22222222, 0x33333333, 0x44444444);

    مجموعه_TRAP_HANDLER(check_fastcall_invoke_5);
    ((فراغ __fastcall (*)(بیعلامت, بیعلامت, بیعلامت, بیعلامت, بیعلامت)) TRAP)(0x11111111, 0x22222222, 0x33333333, 0x44444444, 0x55555555);
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
    مجموعه_SAFECALL_هدف(check_fastcall_espdiff_0);
    x = ((typeof(&check_fastcall_espdiff_0))SAFECALL)();
    أكد(x == 0);
    أكد(ESPDIFF == 0);

    مجموعه_SAFECALL_هدف(check_fastcall_espdiff_1);
    x = ((typeof(&check_fastcall_espdiff_1))SAFECALL)(1);
    أكد(x == 1);
    أكد(ESPDIFF == 0);

    مجموعه_SAFECALL_هدف(check_fastcall_espdiff_2);
    x = ((typeof(&check_fastcall_espdiff_2))SAFECALL)(1, 2);
    أكد(x == 1 + 2);
    أكد(ESPDIFF == 0);

    مجموعه_SAFECALL_هدف(check_fastcall_espdiff_3);
    x = ((typeof(&check_fastcall_espdiff_3))SAFECALL)(1, 2, 3);
    أكد(x == 1 + 2 + 3);
    أكد(ESPDIFF == 1*4);

    مجموعه_SAFECALL_هدف(check_fastcall_espdiff_4);
    x = ((typeof(&check_fastcall_espdiff_4))SAFECALL)(1, 2, 3, 4);
    أكد(x == 1 + 2 + 3 + 4);
    أكد(ESPDIFF == 2*4);

    مجموعه_SAFECALL_هدف(check_fastcall_espdiff_5);
    x = ((typeof(&check_fastcall_espdiff_5))SAFECALL)(1, 2, 3, 4, 5);
    أكد(x == 1 + 2 + 3 + 4 + 5);
    أكد(ESPDIFF == 3*4);
}

صحيح اصلی()
{
#تعریف_کن N 10000
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
