#अन्तर्भाव <stdio.h>
#अन्तर्भाव <assert.h>

#जर !(defined( _WIN32) || (defined(__FreeBSD__) && defined(__i386__)))
#define __fastcall __attribute((fastcall))
#endif

#ifndef __leading_underscore
#define चिन्ह_2(x) _##x
#अन्यथा
#define चिन्ह_2(x) x
#endif

/////////////////////////////////////////////////////////////////////////
//////////                TRAP FRAMEWORK
/////////////////////////////////////////////////////////////////////////
// if you cast 'TRAP' to a function pointer and call it,
//   it will save all 8 registers,
//   and jump into C-code (previously set using 'SET_TRAP_HANDLER(x)'),
//   in C-code you can pop DWORDs from stack and modify registers
//

शून्य *चिन्ह_2(trap_handler);

बाह्य अचिन्हित अक्षर चिन्ह_2(trap)[];
यंत्र (
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

संरचना trapframe {
    अचिन्हित edi, esi, ebp, esp, ebx, edx, ecx, eax;
};


#define M_FLOAT(addr) (*(दशांश *)(addr))
#define M_DWORD(addr) (*(अचिन्हित *)(addr))
#define M_WORD(addr) (*(अचिन्हित लघु *)(addr))
#define M_BYTE(addr) (*(अचिन्हित अक्षर *)(addr))
#define R_EAX ((tf)->eax)
#define R_ECX ((tf)->ecx)
#define R_EDX ((tf)->edx)
#define R_EBX ((tf)->ebx)
#define R_ESP ((tf)->esp)
#define R_EBP ((tf)->ebp)
#define R_ESI ((tf)->esi)
#define R_EDI ((tf)->edi)

#define ARG(x) (M_DWORD(R_ESP + (x) * 4))

#define RETN(x) करा { \
    M_DWORD(R_ESP + (x)) = M_DWORD(R_ESP); \
    R_ESP += (x); \
} पर्यंत (0)

#define DUMP() करा { \
    अचिन्हित i; \
    म_लिखो("EAX: %08X\n", R_EAX); \
    म_लिखो("ECX: %08X\n", R_ECX); \
    म_लिखो("EDX: %08X\n", R_EDX); \
    म_लिखो("EBX: %08X\n", R_EBX); \
    म_लिखो("ESP: %08X\n", R_ESP); \
    म_लिखो("EBP: %08X\n", R_EBP); \
    म_लिखो("ESI: %08X\n", R_ESI); \
    म_लिखो("EDI: %08X\n", R_EDI); \
    म_लिखो("\n"); \
    म_लिखो("[RETADDR]: %08X\n", M_DWORD(R_ESP)); \
    साठी (i = 1; i <= 8; i++) { \
        म_लिखो("[ARG%4d]: %08X\n", i, ARG(i)); \
    } \
} पर्यंत (0)

#define SET_TRAP_HANDLER(x) ((चिन्ह_2(trap_handler)) = (x))
#define TRAP ((शून्य *) &चिन्ह_2(trap))



/////////////////////////////////////////////////////////////////////////
//////////                SAFECALL FRAMEWORK
/////////////////////////////////////////////////////////////////////////
// this framework will convert any calling convention to cdecl
// usage: first set call target with 'SET_SAFECALL_TARGET(x)'
//        then cast 'SAFECALL' to target function pointer type and invoke it
//        after calling, 'ESPDIFF' is the difference of old and new esp

शून्य *चिन्ह_2(sc_call_target);
अचिन्हित चिन्ह_2(sc_retn_addr);
अचिन्हित चिन्ह_2(sc_old_esp);
अचिन्हित चिन्ह_2(sc_new_esp);

बाह्य अचिन्हित अक्षर चिन्ह_2(safecall)[];
यंत्र (
    ".text;"
    "_safecall:;"
    "popl _sc_retn_addr;"
    "movl %esp, _sc_old_esp;"
    "call *_sc_call_target;"
    "movl %esp, _sc_new_esp;"
    "movl _sc_old_esp, %esp;"
	"jmp *_sc_retn_addr;"
);

#define SET_SAFECALL_TARGET(x) ((चिन्ह_2(sc_call_target)) = (x))
#define SAFECALL ((शून्य *) &चिन्ह_2(safecall))
#define ESPDIFF (चिन्ह_2(sc_new_esp) - चिन्ह_2(sc_old_esp))


/////////////////////////////////////////////////////////////////////////
//////////                TEST FASTCALL INVOKE
/////////////////////////////////////////////////////////////////////////

शून्य check_fastcall_invoke_0(संरचना trapframe *tf)
{
    //DUMP();
    RETN(0);
}

शून्य check_fastcall_invoke_1(संरचना trapframe *tf)
{
    //DUMP();
    प्रतिज्ञा(R_ECX == 0x11111111);
    RETN(0);
}
शून्य check_fastcall_invoke_2(संरचना trapframe *tf)
{
    //DUMP();
    प्रतिज्ञा(R_ECX == 0x11111111);
    प्रतिज्ञा(R_EDX == 0x22222222);
    RETN(0);
}
शून्य check_fastcall_invoke_3(संरचना trapframe *tf)
{
    //DUMP();
    प्रतिज्ञा(R_ECX == 0x11111111);
    प्रतिज्ञा(R_EDX == 0x22222222);
    प्रतिज्ञा(ARG(1) == 0x33333333);
    RETN(1*4);
}
शून्य check_fastcall_invoke_4(संरचना trapframe *tf)
{
    //DUMP();
    प्रतिज्ञा(R_ECX == 0x11111111);
    प्रतिज्ञा(R_EDX == 0x22222222);
    प्रतिज्ञा(ARG(1) == 0x33333333);
    प्रतिज्ञा(ARG(2) == 0x44444444);
    RETN(2*4);
}

शून्य check_fastcall_invoke_5(संरचना trapframe *tf)
{
    //DUMP();
    प्रतिज्ञा(R_ECX == 0x11111111);
    प्रतिज्ञा(R_EDX == 0x22222222);
    प्रतिज्ञा(ARG(1) == 0x33333333);
    प्रतिज्ञा(ARG(2) == 0x44444444);
    प्रतिज्ञा(ARG(3) == 0x55555555);
    RETN(3*4);
}

शून्य test_fastcall_invoke()
{
    SET_TRAP_HANDLER(check_fastcall_invoke_0);
    ((शून्य __fastcall (*)(शून्य)) TRAP)();

    SET_TRAP_HANDLER(check_fastcall_invoke_1);
    ((शून्य __fastcall (*)(अचिन्हित)) TRAP)(0x11111111);

    SET_TRAP_HANDLER(check_fastcall_invoke_2);
    ((शून्य __fastcall (*)(अचिन्हित, अचिन्हित)) TRAP)(0x11111111, 0x22222222);

    SET_TRAP_HANDLER(check_fastcall_invoke_3);
    ((शून्य __fastcall (*)(अचिन्हित, अचिन्हित, अचिन्हित)) TRAP)(0x11111111, 0x22222222, 0x33333333);

    SET_TRAP_HANDLER(check_fastcall_invoke_4);
    ((शून्य __fastcall (*)(अचिन्हित, अचिन्हित, अचिन्हित, अचिन्हित)) TRAP)(0x11111111, 0x22222222, 0x33333333, 0x44444444);

    SET_TRAP_HANDLER(check_fastcall_invoke_5);
    ((शून्य __fastcall (*)(अचिन्हित, अचिन्हित, अचिन्हित, अचिन्हित, अचिन्हित)) TRAP)(0x11111111, 0x22222222, 0x33333333, 0x44444444, 0x55555555);
}


/////////////////////////////////////////////////////////////////////////
//////////                TEST FUNCTION CODE GENERATION
/////////////////////////////////////////////////////////////////////////

पूर्णांक __fastcall check_fastcall_espdiff_0(शून्य)
{
    परत 0;
}

पूर्णांक __fastcall check_fastcall_espdiff_1(पूर्णांक a)
{
    परत a;
}

पूर्णांक __fastcall check_fastcall_espdiff_2(पूर्णांक a, पूर्णांक b)
{
    परत a + b;
}

पूर्णांक __fastcall check_fastcall_espdiff_3(पूर्णांक a, पूर्णांक b, पूर्णांक c)
{
    परत a + b + c;
}

पूर्णांक __fastcall check_fastcall_espdiff_4(पूर्णांक a, पूर्णांक b, पूर्णांक c, पूर्णांक d)
{
    परत a + b + c + d;
}

पूर्णांक __fastcall check_fastcall_espdiff_5(पूर्णांक a, पूर्णांक b, पूर्णांक c, पूर्णांक d, पूर्णांक e)
{
    परत a + b + c + d + e;
}

शून्य test_fastcall_espdiff()
{
    पूर्णांक x;
    SET_SAFECALL_TARGET(check_fastcall_espdiff_0);
    x = ((typeof(&check_fastcall_espdiff_0))SAFECALL)();
    प्रतिज्ञा(x == 0);
    प्रतिज्ञा(ESPDIFF == 0);

    SET_SAFECALL_TARGET(check_fastcall_espdiff_1);
    x = ((typeof(&check_fastcall_espdiff_1))SAFECALL)(1);
    प्रतिज्ञा(x == 1);
    प्रतिज्ञा(ESPDIFF == 0);

    SET_SAFECALL_TARGET(check_fastcall_espdiff_2);
    x = ((typeof(&check_fastcall_espdiff_2))SAFECALL)(1, 2);
    प्रतिज्ञा(x == 1 + 2);
    प्रतिज्ञा(ESPDIFF == 0);

    SET_SAFECALL_TARGET(check_fastcall_espdiff_3);
    x = ((typeof(&check_fastcall_espdiff_3))SAFECALL)(1, 2, 3);
    प्रतिज्ञा(x == 1 + 2 + 3);
    प्रतिज्ञा(ESPDIFF == 1*4);

    SET_SAFECALL_TARGET(check_fastcall_espdiff_4);
    x = ((typeof(&check_fastcall_espdiff_4))SAFECALL)(1, 2, 3, 4);
    प्रतिज्ञा(x == 1 + 2 + 3 + 4);
    प्रतिज्ञा(ESPDIFF == 2*4);

    SET_SAFECALL_TARGET(check_fastcall_espdiff_5);
    x = ((typeof(&check_fastcall_espdiff_5))SAFECALL)(1, 2, 3, 4, 5);
    प्रतिज्ञा(x == 1 + 2 + 3 + 4 + 5);
    प्रतिज्ञा(ESPDIFF == 3*4);
}

पूर्णांक main()
{
#define N 10000
    पूर्णांक i;

    साठी (i = 1; i <= N; i++) {
        test_fastcall_espdiff();
    }

    साठी (i = 1; i <= N; i++) {
        test_fastcall_invoke();
    }

    माला_दो("TEST OK");
    परत 0;
}
