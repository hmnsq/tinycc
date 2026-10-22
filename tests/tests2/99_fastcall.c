#अन्तर्भाव <stdio.h>
#अन्तर्भाव <assert.h>

#यदि !(defined( _WIN32) || (defined(__FreeBSD__) && defined(__i386__)))
#परिभाषय __fastcall __attribute((fastcall))
#यदि_अन्तः

#यदि_अपरिभाषितम् __leading_underscore
#परिभाषय चिह्नम्_2(x) _##x
#अन्यथा
#परिभाषय चिह्नम्_2(x) x
#यदि_अन्तः

/////////////////////////////////////////////////////////////////////////
//////////                TRAP FRAMEWORK
/////////////////////////////////////////////////////////////////////////
// if you cast 'TRAP' to a function pointer and call it,
//   it will save all 8 registers,
//   and jump into C-code (previously set using 'SET_TRAP_HANDLER(x)'),
//   in C-code you can pop DWORDs from stack and modify registers
//

शून्य *चिह्नम्_2(trap_handler);

बाह्य अचिह्नित वर्ण चिह्नम्_2(trap)[];
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

संरचना trapframe {
    अचिह्नित edi, esi, ebp, esp, ebx, edx, ecx, eax;
};


#परिभाषय M_FLOAT(addr) (*(भिन्न *)(addr))
#परिभाषय M_DWORD(addr) (*(अचिह्नित *)(addr))
#परिभाषय M_WORD(addr) (*(अचिह्नित ह्रस्व *)(addr))
#परिभाषय M_BYTE(addr) (*(अचिह्नित वर्ण *)(addr))
#परिभाषय R_EAX ((tf)->eax)
#परिभाषय R_ECX ((tf)->ecx)
#परिभाषय R_EDX ((tf)->edx)
#परिभाषय R_EBX ((tf)->ebx)
#परिभाषय R_ESP ((tf)->esp)
#परिभाषय R_EBP ((tf)->ebp)
#परिभाषय R_ESI ((tf)->esi)
#परिभाषय R_EDI ((tf)->edi)

#परिभाषय ARG(x) (M_DWORD(R_ESP + (x) * 4))

#परिभाषय RETN(x) कुरु { \
    M_DWORD(R_ESP + (x)) = M_DWORD(R_ESP); \
    R_ESP += (x); \
} यावत् (0)

#परिभाषय DUMP() कुरु { \
    अचिह्नित i; \
    प्रारूप_लिख("EAX: %08X\n", R_EAX); \
    प्रारूप_लिख("ECX: %08X\n", R_ECX); \
    प्रारूप_लिख("EDX: %08X\n", R_EDX); \
    प्रारूप_लिख("EBX: %08X\n", R_EBX); \
    प्रारूप_लिख("ESP: %08X\n", R_ESP); \
    प्रारूप_लिख("EBP: %08X\n", R_EBP); \
    प्रारूप_लिख("ESI: %08X\n", R_ESI); \
    प्रारूप_लिख("EDI: %08X\n", R_EDI); \
    प्रारूप_लिख("\n"); \
    प्रारूप_लिख("[RETADDR]: %08X\n", M_DWORD(R_ESP)); \
    प्रति (i = 1; i <= 8; i++) { \
        प्रारूप_लिख("[ARG%4d]: %08X\n", i, ARG(i)); \
    } \
} यावत् (0)

#परिभाषय समुच्चयः_TRAP_HANDLER(x) ((चिह्नम्_2(trap_handler)) = (x))
#परिभाषय TRAP ((शून्य *) &चिह्नम्_2(trap))



/////////////////////////////////////////////////////////////////////////
//////////                SAFECALL FRAMEWORK
/////////////////////////////////////////////////////////////////////////
// this framework will convert any calling convention to cdecl
// usage: first set call target with 'SET_SAFECALL_TARGET(x)'
//        then cast 'SAFECALL' to target function pointer type and invoke it
//        after calling, 'ESPDIFF' is the difference of old and new esp

शून्य *चिह्नम्_2(sc_call_target);
अचिह्नित चिह्नम्_2(sc_retn_addr);
अचिह्नित चिह्नम्_2(sc_old_esp);
अचिह्नित चिह्नम्_2(sc_new_esp);

बाह्य अचिह्नित वर्ण चिह्नम्_2(safecall)[];
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

#परिभाषय समुच्चयः_SAFECALL_TARGET(x) ((चिह्नम्_2(sc_call_target)) = (x))
#परिभाषय SAFECALL ((शून्य *) &चिह्नम्_2(safecall))
#परिभाषय ESPDIFF (चिह्नम्_2(sc_new_esp) - चिह्नम्_2(sc_old_esp))


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
    समुच्चयः_TRAP_HANDLER(check_fastcall_invoke_0);
    ((शून्य __fastcall (*)(शून्य)) TRAP)();

    समुच्चयः_TRAP_HANDLER(check_fastcall_invoke_1);
    ((शून्य __fastcall (*)(अचिह्नित)) TRAP)(0x11111111);

    समुच्चयः_TRAP_HANDLER(check_fastcall_invoke_2);
    ((शून्य __fastcall (*)(अचिह्नित, अचिह्नित)) TRAP)(0x11111111, 0x22222222);

    समुच्चयः_TRAP_HANDLER(check_fastcall_invoke_3);
    ((शून्य __fastcall (*)(अचिह्नित, अचिह्नित, अचिह्नित)) TRAP)(0x11111111, 0x22222222, 0x33333333);

    समुच्चयः_TRAP_HANDLER(check_fastcall_invoke_4);
    ((शून्य __fastcall (*)(अचिह्नित, अचिह्नित, अचिह्नित, अचिह्नित)) TRAP)(0x11111111, 0x22222222, 0x33333333, 0x44444444);

    समुच्चयः_TRAP_HANDLER(check_fastcall_invoke_5);
    ((शून्य __fastcall (*)(अचिह्नित, अचिह्नित, अचिह्नित, अचिह्नित, अचिह्नित)) TRAP)(0x11111111, 0x22222222, 0x33333333, 0x44444444, 0x55555555);
}


/////////////////////////////////////////////////////////////////////////
//////////                TEST FUNCTION CODE GENERATION
/////////////////////////////////////////////////////////////////////////

पूर्णाङ्क __fastcall check_fastcall_espdiff_0(शून्य)
{
    प्रत्यागम 0;
}

पूर्णाङ्क __fastcall check_fastcall_espdiff_1(पूर्णाङ्क a)
{
    प्रत्यागम a;
}

पूर्णाङ्क __fastcall check_fastcall_espdiff_2(पूर्णाङ्क a, पूर्णाङ्क b)
{
    प्रत्यागम a + b;
}

पूर्णाङ्क __fastcall check_fastcall_espdiff_3(पूर्णाङ्क a, पूर्णाङ्क b, पूर्णाङ्क c)
{
    प्रत्यागम a + b + c;
}

पूर्णाङ्क __fastcall check_fastcall_espdiff_4(पूर्णाङ्क a, पूर्णाङ्क b, पूर्णाङ्क c, पूर्णाङ्क d)
{
    प्रत्यागम a + b + c + d;
}

पूर्णाङ्क __fastcall check_fastcall_espdiff_5(पूर्णाङ्क a, पूर्णाङ्क b, पूर्णाङ्क c, पूर्णाङ्क d, पूर्णाङ्क e)
{
    प्रत्यागम a + b + c + d + e;
}

शून्य test_fastcall_espdiff()
{
    पूर्णाङ्क x;
    समुच्चयः_SAFECALL_TARGET(check_fastcall_espdiff_0);
    x = ((typeof(&check_fastcall_espdiff_0))SAFECALL)();
    प्रतिज्ञा(x == 0);
    प्रतिज्ञा(ESPDIFF == 0);

    समुच्चयः_SAFECALL_TARGET(check_fastcall_espdiff_1);
    x = ((typeof(&check_fastcall_espdiff_1))SAFECALL)(1);
    प्रतिज्ञा(x == 1);
    प्रतिज्ञा(ESPDIFF == 0);

    समुच्चयः_SAFECALL_TARGET(check_fastcall_espdiff_2);
    x = ((typeof(&check_fastcall_espdiff_2))SAFECALL)(1, 2);
    प्रतिज्ञा(x == 1 + 2);
    प्रतिज्ञा(ESPDIFF == 0);

    समुच्चयः_SAFECALL_TARGET(check_fastcall_espdiff_3);
    x = ((typeof(&check_fastcall_espdiff_3))SAFECALL)(1, 2, 3);
    प्रतिज्ञा(x == 1 + 2 + 3);
    प्रतिज्ञा(ESPDIFF == 1*4);

    समुच्चयः_SAFECALL_TARGET(check_fastcall_espdiff_4);
    x = ((typeof(&check_fastcall_espdiff_4))SAFECALL)(1, 2, 3, 4);
    प्रतिज्ञा(x == 1 + 2 + 3 + 4);
    प्रतिज्ञा(ESPDIFF == 2*4);

    समुच्चयः_SAFECALL_TARGET(check_fastcall_espdiff_5);
    x = ((typeof(&check_fastcall_espdiff_5))SAFECALL)(1, 2, 3, 4, 5);
    प्रतिज्ञा(x == 1 + 2 + 3 + 4 + 5);
    प्रतिज्ञा(ESPDIFF == 3*4);
}

पूर्णाङ्क मुख्यम्()
{
#परिभाषय N 10000
    पूर्णाङ्क i;

    प्रति (i = 1; i <= N; i++) {
        test_fastcall_espdiff();
    }

    प्रति (i = 1; i <= N; i++) {
        test_fastcall_invoke();
    }

    पङ्क्तिं_लिख("TEST OK");
    प्रत्यागम 0;
}
