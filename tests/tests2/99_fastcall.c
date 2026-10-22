#అన్తర్భావ <stdio.h>
#అన్తర్భావ <assert.h>

#ఒకవేళ !(defined( _WIN32) || (defined(__FreeBSD__) && defined(__i386__)))
#నిర్వచించు __fastcall __attribute((fastcall))
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే __leading_underscore
#నిర్వచించు చిహ్నం_2(x) _##x
#లేకపోతే
#నిర్వచించు చిహ్నం_2(x) x
#అయితే_ముగింపు

/////////////////////////////////////////////////////////////////////////
//////////                TRAP FRAMEWORK
/////////////////////////////////////////////////////////////////////////
// if you cast 'TRAP' to a function pointer and call it,
//   it will save all 8 registers,
//   and jump into C-code (previously set using 'SET_TRAP_HANDLER(x)'),
//   in C-code you can pop DWORDs from stack and modify registers
//

శూన్య *చిహ్నం_2(trap_handler);

బాహ్య గుర్తులేని అక్షరం చిహ్నం_2(trap)[];
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

నిర్మాణం trapframe {
    గుర్తులేని edi, esi, ebp, esp, ebx, edx, ecx, eax;
};


#నిర్వచించు M_FLOAT(addr) (*(దశాంశం *)(addr))
#నిర్వచించు M_DWORD(addr) (*(గుర్తులేని *)(addr))
#నిర్వచించు M_మాట(addr) (*(గుర్తులేని పొట్టి *)(addr))
#నిర్వచించు M_BYTE(addr) (*(గుర్తులేని అక్షరం *)(addr))
#నిర్వచించు R_EAX ((tf)->eax)
#నిర్వచించు R_ECX ((tf)->ecx)
#నిర్వచించు R_EDX ((tf)->edx)
#నిర్వచించు R_EBX ((tf)->ebx)
#నిర్వచించు R_ESP ((tf)->esp)
#నిర్వచించు R_EBP ((tf)->ebp)
#నిర్వచించు R_ESI ((tf)->esi)
#నిర్వచించు R_EDI ((tf)->edi)

#నిర్వచించు ARG(x) (M_DWORD(R_ESP + (x) * 4))

#నిర్వచించు RETN(x) చేయి { \
    M_DWORD(R_ESP + (x)) = M_DWORD(R_ESP); \
    R_ESP += (x); \
} అయితే (0)

#నిర్వచించు DUMP() చేయి { \
    గుర్తులేని i; \
    రాయి("EAX: %08X\n", R_EAX); \
    రాయి("ECX: %08X\n", R_ECX); \
    రాయి("EDX: %08X\n", R_EDX); \
    రాయి("EBX: %08X\n", R_EBX); \
    రాయి("ESP: %08X\n", R_ESP); \
    రాయి("EBP: %08X\n", R_EBP); \
    రాయి("ESI: %08X\n", R_ESI); \
    రాయి("EDI: %08X\n", R_EDI); \
    రాయి("\n"); \
    రాయి("[RETADDR]: %08X\n", M_DWORD(R_ESP)); \
    కొరకు (i = 1; i <= 8; i++) { \
        రాయి("[ARG%4d]: %08X\n", i, ARG(i)); \
    } \
} అయితే (0)

#నిర్వచించు సమితి_TRAP_HANDLER(x) ((చిహ్నం_2(trap_handler)) = (x))
#నిర్వచించు TRAP ((శూన్య *) &చిహ్నం_2(trap))



/////////////////////////////////////////////////////////////////////////
//////////                SAFECALL FRAMEWORK
/////////////////////////////////////////////////////////////////////////
// this framework will convert any calling convention to cdecl
// usage: first set call target with 'SET_SAFECALL_TARGET(x)'
//        then cast 'SAFECALL' to target function pointer type and invoke it
//        after calling, 'ESPDIFF' is the difference of old and new esp

శూన్య *చిహ్నం_2(sc_call_లక్ష్యం);
గుర్తులేని చిహ్నం_2(sc_retn_addr);
గుర్తులేని చిహ్నం_2(sc_old_esp);
గుర్తులేని చిహ్నం_2(sc_new_esp);

బాహ్య గుర్తులేని అక్షరం చిహ్నం_2(safecall)[];
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

#నిర్వచించు సమితి_SAFECALL_లక్ష్యం(x) ((చిహ్నం_2(sc_call_లక్ష్యం)) = (x))
#నిర్వచించు SAFECALL ((శూన్య *) &చిహ్నం_2(safecall))
#నిర్వచించు ESPDIFF (చిహ్నం_2(sc_new_esp) - చిహ్నం_2(sc_old_esp))


/////////////////////////////////////////////////////////////////////////
//////////                TEST FASTCALL INVOKE
/////////////////////////////////////////////////////////////////////////

శూన్య check_fastcall_invoke_0(నిర్మాణం trapframe *tf)
{
    //DUMP();
    RETN(0);
}

శూన్య check_fastcall_invoke_1(నిర్మాణం trapframe *tf)
{
    //DUMP();
    ప్రతిజ్ఞా(R_ECX == 0x11111111);
    RETN(0);
}
శూన్య check_fastcall_invoke_2(నిర్మాణం trapframe *tf)
{
    //DUMP();
    ప్రతిజ్ఞా(R_ECX == 0x11111111);
    ప్రతిజ్ఞా(R_EDX == 0x22222222);
    RETN(0);
}
శూన్య check_fastcall_invoke_3(నిర్మాణం trapframe *tf)
{
    //DUMP();
    ప్రతిజ్ఞా(R_ECX == 0x11111111);
    ప్రతిజ్ఞా(R_EDX == 0x22222222);
    ప్రతిజ్ఞా(ARG(1) == 0x33333333);
    RETN(1*4);
}
శూన్య check_fastcall_invoke_4(నిర్మాణం trapframe *tf)
{
    //DUMP();
    ప్రతిజ్ఞా(R_ECX == 0x11111111);
    ప్రతిజ్ఞా(R_EDX == 0x22222222);
    ప్రతిజ్ఞా(ARG(1) == 0x33333333);
    ప్రతిజ్ఞా(ARG(2) == 0x44444444);
    RETN(2*4);
}

శూన్య check_fastcall_invoke_5(నిర్మాణం trapframe *tf)
{
    //DUMP();
    ప్రతిజ్ఞా(R_ECX == 0x11111111);
    ప్రతిజ్ఞా(R_EDX == 0x22222222);
    ప్రతిజ్ఞా(ARG(1) == 0x33333333);
    ప్రతిజ్ఞా(ARG(2) == 0x44444444);
    ప్రతిజ్ఞా(ARG(3) == 0x55555555);
    RETN(3*4);
}

శూన్య test_fastcall_invoke()
{
    సమితి_TRAP_HANDLER(check_fastcall_invoke_0);
    ((శూన్య __fastcall (*)(శూన్య)) TRAP)();

    సమితి_TRAP_HANDLER(check_fastcall_invoke_1);
    ((శూన్య __fastcall (*)(గుర్తులేని)) TRAP)(0x11111111);

    సమితి_TRAP_HANDLER(check_fastcall_invoke_2);
    ((శూన్య __fastcall (*)(గుర్తులేని, గుర్తులేని)) TRAP)(0x11111111, 0x22222222);

    సమితి_TRAP_HANDLER(check_fastcall_invoke_3);
    ((శూన్య __fastcall (*)(గుర్తులేని, గుర్తులేని, గుర్తులేని)) TRAP)(0x11111111, 0x22222222, 0x33333333);

    సమితి_TRAP_HANDLER(check_fastcall_invoke_4);
    ((శూన్య __fastcall (*)(గుర్తులేని, గుర్తులేని, గుర్తులేని, గుర్తులేని)) TRAP)(0x11111111, 0x22222222, 0x33333333, 0x44444444);

    సమితి_TRAP_HANDLER(check_fastcall_invoke_5);
    ((శూన్య __fastcall (*)(గుర్తులేని, గుర్తులేని, గుర్తులేని, గుర్తులేని, గుర్తులేని)) TRAP)(0x11111111, 0x22222222, 0x33333333, 0x44444444, 0x55555555);
}


/////////////////////////////////////////////////////////////////////////
//////////                TEST FUNCTION CODE GENERATION
/////////////////////////////////////////////////////////////////////////

పూర్ణాంకం __fastcall check_fastcall_espdiff_0(శూన్య)
{
    తిరిగి 0;
}

పూర్ణాంకం __fastcall check_fastcall_espdiff_1(పూర్ణాంకం a)
{
    తిరిగి a;
}

పూర్ణాంకం __fastcall check_fastcall_espdiff_2(పూర్ణాంకం a, పూర్ణాంకం b)
{
    తిరిగి a + b;
}

పూర్ణాంకం __fastcall check_fastcall_espdiff_3(పూర్ణాంకం a, పూర్ణాంకం b, పూర్ణాంకం c)
{
    తిరిగి a + b + c;
}

పూర్ణాంకం __fastcall check_fastcall_espdiff_4(పూర్ణాంకం a, పూర్ణాంకం b, పూర్ణాంకం c, పూర్ణాంకం d)
{
    తిరిగి a + b + c + d;
}

పూర్ణాంకం __fastcall check_fastcall_espdiff_5(పూర్ణాంకం a, పూర్ణాంకం b, పూర్ణాంకం c, పూర్ణాంకం d, పూర్ణాంకం e)
{
    తిరిగి a + b + c + d + e;
}

శూన్య test_fastcall_espdiff()
{
    పూర్ణాంకం x;
    సమితి_SAFECALL_లక్ష్యం(check_fastcall_espdiff_0);
    x = ((typeof(&check_fastcall_espdiff_0))SAFECALL)();
    ప్రతిజ్ఞా(x == 0);
    ప్రతిజ్ఞా(ESPDIFF == 0);

    సమితి_SAFECALL_లక్ష్యం(check_fastcall_espdiff_1);
    x = ((typeof(&check_fastcall_espdiff_1))SAFECALL)(1);
    ప్రతిజ్ఞా(x == 1);
    ప్రతిజ్ఞా(ESPDIFF == 0);

    సమితి_SAFECALL_లక్ష్యం(check_fastcall_espdiff_2);
    x = ((typeof(&check_fastcall_espdiff_2))SAFECALL)(1, 2);
    ప్రతిజ్ఞా(x == 1 + 2);
    ప్రతిజ్ఞా(ESPDIFF == 0);

    సమితి_SAFECALL_లక్ష్యం(check_fastcall_espdiff_3);
    x = ((typeof(&check_fastcall_espdiff_3))SAFECALL)(1, 2, 3);
    ప్రతిజ్ఞా(x == 1 + 2 + 3);
    ప్రతిజ్ఞా(ESPDIFF == 1*4);

    సమితి_SAFECALL_లక్ష్యం(check_fastcall_espdiff_4);
    x = ((typeof(&check_fastcall_espdiff_4))SAFECALL)(1, 2, 3, 4);
    ప్రతిజ్ఞా(x == 1 + 2 + 3 + 4);
    ప్రతిజ్ఞా(ESPDIFF == 2*4);

    సమితి_SAFECALL_లక్ష్యం(check_fastcall_espdiff_5);
    x = ((typeof(&check_fastcall_espdiff_5))SAFECALL)(1, 2, 3, 4, 5);
    ప్రతిజ్ఞా(x == 1 + 2 + 3 + 4 + 5);
    ప్రతిజ్ఞా(ESPDIFF == 3*4);
}

పూర్ణాంకం ప్రధాన()
{
#నిర్వచించు N 10000
    పూర్ణాంకం i;

    కొరకు (i = 1; i <= N; i++) {
        test_fastcall_espdiff();
    }

    కొరకు (i = 1; i <= N; i++) {
        test_fastcall_invoke();
    }

    puts("TEST OK");
    తిరిగి 0;
}
