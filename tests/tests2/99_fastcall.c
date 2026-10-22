#شامل <stdio.h>
#شامل <assert.h>

#اگر !(defined( _WIN32) || (defined(__FreeBSD__) && defined(__i386__)))
#تعریف_کرو __fastcall __attribute((fastcall))
#اگر_ختم

#اگر_غیر_تعریف_شدہ __leading_underscore
#تعریف_کرو علامت_2(x) _##x
#ورنہ
#تعریف_کرو علامت_2(x) x
#اگر_ختم

/////////////////////////////////////////////////////////////////////////
//////////                TRAP FRAMEWORK
/////////////////////////////////////////////////////////////////////////
// if you cast 'TRAP' to a function pointer and call it,
//   it will save all 8 registers,
//   and jump into C-code (previously set using 'SET_TRAP_HANDLER(x)'),
//   in C-code you can pop DWORDs from stack and modify registers
//

خالی *علامت_2(trap_handler);

خارجی غیرعلامتی حرف علامت_2(trap)[];
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

ساخت trapframe {
    غیرعلامتی edi, esi, ebp, esp, ebx, edx, ecx, eax;
};


#تعریف_کرو M_FLOAT(addr) (*(اعشاری *)(addr))
#تعریف_کرو M_DWORD(addr) (*(غیرعلامتی *)(addr))
#تعریف_کرو M_لفظ(addr) (*(غیرعلامتی مختصر *)(addr))
#تعریف_کرو M_BYTE(addr) (*(غیرعلامتی حرف *)(addr))
#تعریف_کرو R_EAX ((tf)->eax)
#تعریف_کرو R_ECX ((tf)->ecx)
#تعریف_کرو R_EDX ((tf)->edx)
#تعریف_کرو R_EBX ((tf)->ebx)
#تعریف_کرو R_ESP ((tf)->esp)
#تعریف_کرو R_EBP ((tf)->ebp)
#تعریف_کرو R_ESI ((tf)->esi)
#تعریف_کرو R_EDI ((tf)->edi)

#تعریف_کرو ARG(x) (M_DWORD(R_ESP + (x) * 4))

#تعریف_کرو RETN(x) کرو { \
    M_DWORD(R_ESP + (x)) = M_DWORD(R_ESP); \
    R_ESP += (x); \
} جب (0)

#تعریف_کرو DUMP() کرو { \
    غیرعلامتی i; \
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
    برائے (i = 1; i <= 8; i++) { \
        لکھو("[ARG%4d]: %08X\n", i, ARG(i)); \
    } \
} جب (0)

#تعریف_کرو سیٹ_TRAP_HANDLER(x) ((علامت_2(trap_handler)) = (x))
#تعریف_کرو TRAP ((خالی *) &علامت_2(trap))



/////////////////////////////////////////////////////////////////////////
//////////                SAFECALL FRAMEWORK
/////////////////////////////////////////////////////////////////////////
// this framework will convert any calling convention to cdecl
// usage: first set call target with 'SET_SAFECALL_TARGET(x)'
//        then cast 'SAFECALL' to target function pointer type and invoke it
//        after calling, 'ESPDIFF' is the difference of old and new esp

خالی *علامت_2(sc_call_ہدف);
غیرعلامتی علامت_2(sc_retn_addr);
غیرعلامتی علامت_2(sc_old_esp);
غیرعلامتی علامت_2(sc_new_esp);

خارجی غیرعلامتی حرف علامت_2(safecall)[];
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

#تعریف_کرو سیٹ_SAFECALL_ہدف(x) ((علامت_2(sc_call_ہدف)) = (x))
#تعریف_کرو SAFECALL ((خالی *) &علامت_2(safecall))
#تعریف_کرو ESPDIFF (علامت_2(sc_new_esp) - علامت_2(sc_old_esp))


/////////////////////////////////////////////////////////////////////////
//////////                TEST FASTCALL INVOKE
/////////////////////////////////////////////////////////////////////////

خالی check_fastcall_invoke_0(ساخت trapframe *tf)
{
    //DUMP();
    RETN(0);
}

خالی check_fastcall_invoke_1(ساخت trapframe *tf)
{
    //DUMP();
    أكد(R_ECX == 0x11111111);
    RETN(0);
}
خالی check_fastcall_invoke_2(ساخت trapframe *tf)
{
    //DUMP();
    أكد(R_ECX == 0x11111111);
    أكد(R_EDX == 0x22222222);
    RETN(0);
}
خالی check_fastcall_invoke_3(ساخت trapframe *tf)
{
    //DUMP();
    أكد(R_ECX == 0x11111111);
    أكد(R_EDX == 0x22222222);
    أكد(ARG(1) == 0x33333333);
    RETN(1*4);
}
خالی check_fastcall_invoke_4(ساخت trapframe *tf)
{
    //DUMP();
    أكد(R_ECX == 0x11111111);
    أكد(R_EDX == 0x22222222);
    أكد(ARG(1) == 0x33333333);
    أكد(ARG(2) == 0x44444444);
    RETN(2*4);
}

خالی check_fastcall_invoke_5(ساخت trapframe *tf)
{
    //DUMP();
    أكد(R_ECX == 0x11111111);
    أكد(R_EDX == 0x22222222);
    أكد(ARG(1) == 0x33333333);
    أكد(ARG(2) == 0x44444444);
    أكد(ARG(3) == 0x55555555);
    RETN(3*4);
}

خالی test_fastcall_invoke()
{
    سیٹ_TRAP_HANDLER(check_fastcall_invoke_0);
    ((خالی __fastcall (*)(خالی)) TRAP)();

    سیٹ_TRAP_HANDLER(check_fastcall_invoke_1);
    ((خالی __fastcall (*)(غیرعلامتی)) TRAP)(0x11111111);

    سیٹ_TRAP_HANDLER(check_fastcall_invoke_2);
    ((خالی __fastcall (*)(غیرعلامتی, غیرعلامتی)) TRAP)(0x11111111, 0x22222222);

    سیٹ_TRAP_HANDLER(check_fastcall_invoke_3);
    ((خالی __fastcall (*)(غیرعلامتی, غیرعلامتی, غیرعلامتی)) TRAP)(0x11111111, 0x22222222, 0x33333333);

    سیٹ_TRAP_HANDLER(check_fastcall_invoke_4);
    ((خالی __fastcall (*)(غیرعلامتی, غیرعلامتی, غیرعلامتی, غیرعلامتی)) TRAP)(0x11111111, 0x22222222, 0x33333333, 0x44444444);

    سیٹ_TRAP_HANDLER(check_fastcall_invoke_5);
    ((خالی __fastcall (*)(غیرعلامتی, غیرعلامتی, غیرعلامتی, غیرعلامتی, غیرعلامتی)) TRAP)(0x11111111, 0x22222222, 0x33333333, 0x44444444, 0x55555555);
}


/////////////////////////////////////////////////////////////////////////
//////////                TEST FUNCTION CODE GENERATION
/////////////////////////////////////////////////////////////////////////

صحیح __fastcall check_fastcall_espdiff_0(خالی)
{
    واپس 0;
}

صحیح __fastcall check_fastcall_espdiff_1(صحیح a)
{
    واپس a;
}

صحیح __fastcall check_fastcall_espdiff_2(صحیح a, صحیح b)
{
    واپس a + b;
}

صحیح __fastcall check_fastcall_espdiff_3(صحیح a, صحیح b, صحیح c)
{
    واپس a + b + c;
}

صحیح __fastcall check_fastcall_espdiff_4(صحیح a, صحیح b, صحیح c, صحیح d)
{
    واپس a + b + c + d;
}

صحیح __fastcall check_fastcall_espdiff_5(صحیح a, صحیح b, صحیح c, صحیح d, صحیح e)
{
    واپس a + b + c + d + e;
}

خالی test_fastcall_espdiff()
{
    صحیح x;
    سیٹ_SAFECALL_ہدف(check_fastcall_espdiff_0);
    x = ((typeof(&check_fastcall_espdiff_0))SAFECALL)();
    أكد(x == 0);
    أكد(ESPDIFF == 0);

    سیٹ_SAFECALL_ہدف(check_fastcall_espdiff_1);
    x = ((typeof(&check_fastcall_espdiff_1))SAFECALL)(1);
    أكد(x == 1);
    أكد(ESPDIFF == 0);

    سیٹ_SAFECALL_ہدف(check_fastcall_espdiff_2);
    x = ((typeof(&check_fastcall_espdiff_2))SAFECALL)(1, 2);
    أكد(x == 1 + 2);
    أكد(ESPDIFF == 0);

    سیٹ_SAFECALL_ہدف(check_fastcall_espdiff_3);
    x = ((typeof(&check_fastcall_espdiff_3))SAFECALL)(1, 2, 3);
    أكد(x == 1 + 2 + 3);
    أكد(ESPDIFF == 1*4);

    سیٹ_SAFECALL_ہدف(check_fastcall_espdiff_4);
    x = ((typeof(&check_fastcall_espdiff_4))SAFECALL)(1, 2, 3, 4);
    أكد(x == 1 + 2 + 3 + 4);
    أكد(ESPDIFF == 2*4);

    سیٹ_SAFECALL_ہدف(check_fastcall_espdiff_5);
    x = ((typeof(&check_fastcall_espdiff_5))SAFECALL)(1, 2, 3, 4, 5);
    أكد(x == 1 + 2 + 3 + 4 + 5);
    أكد(ESPDIFF == 3*4);
}

صحیح مین()
{
#تعریف_کرو N 10000
    صحیح i;

    برائے (i = 1; i <= N; i++) {
        test_fastcall_espdiff();
    }

    برائے (i = 1; i <= N; i++) {
        test_fastcall_invoke();
    }

    puts("TEST OK");
    واپس 0;
}
