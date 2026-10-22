#समावेश <stdio.h>
#समावेश <assert.h>

#अगर !(defined( _WIN32) || (defined(__FreeBSD__) && defined(__i386__)))
#घोषणा __fastcall __attribute((fastcall))
#पूर्ण_अगर

#अगर_अघोषित __leading_underscore
#घोषणा प्रतीक_2(x) _##x
#अन्यथा
#घोषणा प्रतीक_2(x) x
#पूर्ण_अगर

/////////////////////////////////////////////////////////////////////////
//////////                TRAP FRAMEWORK
/////////////////////////////////////////////////////////////////////////
// if you cast 'TRAP' to a function pointer and call it,
//   it will save all 8 registers,
//   and jump into C-code (previously set using 'SET_TRAP_HANDLER(x)'),
//   in C-code you can pop DWORDs from stack and modify registers
//

व्योम *प्रतीक_2(trap_handler);

बाह्य अचिन्हित अक्षर प्रतीक_2(trap)[];
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

काष्ठा trapframe {
    अचिन्हित edi, esi, ebp, esp, ebx, edx, ecx, eax;
};


#घोषणा M_FLOAT(addr) (*(भग्न *)(addr))
#घोषणा M_DWORD(addr) (*(अचिन्हित *)(addr))
#घोषणा M_WORD(addr) (*(अचिन्हित लघु *)(addr))
#घोषणा M_BYTE(addr) (*(अचिन्हित अक्षर *)(addr))
#घोषणा R_EAX ((tf)->eax)
#घोषणा R_ECX ((tf)->ecx)
#घोषणा R_EDX ((tf)->edx)
#घोषणा R_EBX ((tf)->ebx)
#घोषणा R_ESP ((tf)->esp)
#घोषणा R_EBP ((tf)->ebp)
#घोषणा R_ESI ((tf)->esi)
#घोषणा R_EDI ((tf)->edi)

#घोषणा ARG(x) (M_DWORD(R_ESP + (x) * 4))

#घोषणा RETN(x) करो { \
    M_DWORD(R_ESP + (x)) = M_DWORD(R_ESP); \
    R_ESP += (x); \
} जबतक (0)

#घोषणा DUMP() करो { \
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
    क्रम (i = 1; i <= 8; i++) { \
        म_लिखो("[ARG%4d]: %08X\n", i, ARG(i)); \
    } \
} जबतक (0)

#घोषणा SET_TRAP_HANDLER(x) ((प्रतीक_2(trap_handler)) = (x))
#घोषणा TRAP ((व्योम *) &प्रतीक_2(trap))



/////////////////////////////////////////////////////////////////////////
//////////                SAFECALL FRAMEWORK
/////////////////////////////////////////////////////////////////////////
// this framework will convert any calling convention to cdecl
// usage: first set call target with 'SET_SAFECALL_TARGET(x)'
//        then cast 'SAFECALL' to target function pointer type and invoke it
//        after calling, 'ESPDIFF' is the difference of old and new esp

व्योम *प्रतीक_2(sc_call_target);
अचिन्हित प्रतीक_2(sc_retn_addr);
अचिन्हित प्रतीक_2(sc_old_esp);
अचिन्हित प्रतीक_2(sc_new_esp);

बाह्य अचिन्हित अक्षर प्रतीक_2(safecall)[];
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

#घोषणा SET_SAFECALL_TARGET(x) ((प्रतीक_2(sc_call_target)) = (x))
#घोषणा SAFECALL ((व्योम *) &प्रतीक_2(safecall))
#घोषणा ESPDIFF (प्रतीक_2(sc_new_esp) - प्रतीक_2(sc_old_esp))


/////////////////////////////////////////////////////////////////////////
//////////                TEST FASTCALL INVOKE
/////////////////////////////////////////////////////////////////////////

व्योम check_fastcall_invoke_0(काष्ठा trapframe *tf)
{
    //DUMP();
    RETN(0);
}

व्योम check_fastcall_invoke_1(काष्ठा trapframe *tf)
{
    //DUMP();
    निश्चित(R_ECX == 0x11111111);
    RETN(0);
}
व्योम check_fastcall_invoke_2(काष्ठा trapframe *tf)
{
    //DUMP();
    निश्चित(R_ECX == 0x11111111);
    निश्चित(R_EDX == 0x22222222);
    RETN(0);
}
व्योम check_fastcall_invoke_3(काष्ठा trapframe *tf)
{
    //DUMP();
    निश्चित(R_ECX == 0x11111111);
    निश्चित(R_EDX == 0x22222222);
    निश्चित(ARG(1) == 0x33333333);
    RETN(1*4);
}
व्योम check_fastcall_invoke_4(काष्ठा trapframe *tf)
{
    //DUMP();
    निश्चित(R_ECX == 0x11111111);
    निश्चित(R_EDX == 0x22222222);
    निश्चित(ARG(1) == 0x33333333);
    निश्चित(ARG(2) == 0x44444444);
    RETN(2*4);
}

व्योम check_fastcall_invoke_5(काष्ठा trapframe *tf)
{
    //DUMP();
    निश्चित(R_ECX == 0x11111111);
    निश्चित(R_EDX == 0x22222222);
    निश्चित(ARG(1) == 0x33333333);
    निश्चित(ARG(2) == 0x44444444);
    निश्चित(ARG(3) == 0x55555555);
    RETN(3*4);
}

व्योम test_fastcall_invoke()
{
    SET_TRAP_HANDLER(check_fastcall_invoke_0);
    ((व्योम __fastcall (*)(व्योम)) TRAP)();

    SET_TRAP_HANDLER(check_fastcall_invoke_1);
    ((व्योम __fastcall (*)(अचिन्हित)) TRAP)(0x11111111);

    SET_TRAP_HANDLER(check_fastcall_invoke_2);
    ((व्योम __fastcall (*)(अचिन्हित, अचिन्हित)) TRAP)(0x11111111, 0x22222222);

    SET_TRAP_HANDLER(check_fastcall_invoke_3);
    ((व्योम __fastcall (*)(अचिन्हित, अचिन्हित, अचिन्हित)) TRAP)(0x11111111, 0x22222222, 0x33333333);

    SET_TRAP_HANDLER(check_fastcall_invoke_4);
    ((व्योम __fastcall (*)(अचिन्हित, अचिन्हित, अचिन्हित, अचिन्हित)) TRAP)(0x11111111, 0x22222222, 0x33333333, 0x44444444);

    SET_TRAP_HANDLER(check_fastcall_invoke_5);
    ((व्योम __fastcall (*)(अचिन्हित, अचिन्हित, अचिन्हित, अचिन्हित, अचिन्हित)) TRAP)(0x11111111, 0x22222222, 0x33333333, 0x44444444, 0x55555555);
}


/////////////////////////////////////////////////////////////////////////
//////////                TEST FUNCTION CODE GENERATION
/////////////////////////////////////////////////////////////////////////

पूर्णांक __fastcall check_fastcall_espdiff_0(व्योम)
{
    वापस 0;
}

पूर्णांक __fastcall check_fastcall_espdiff_1(पूर्णांक a)
{
    वापस a;
}

पूर्णांक __fastcall check_fastcall_espdiff_2(पूर्णांक a, पूर्णांक b)
{
    वापस a + b;
}

पूर्णांक __fastcall check_fastcall_espdiff_3(पूर्णांक a, पूर्णांक b, पूर्णांक c)
{
    वापस a + b + c;
}

पूर्णांक __fastcall check_fastcall_espdiff_4(पूर्णांक a, पूर्णांक b, पूर्णांक c, पूर्णांक d)
{
    वापस a + b + c + d;
}

पूर्णांक __fastcall check_fastcall_espdiff_5(पूर्णांक a, पूर्णांक b, पूर्णांक c, पूर्णांक d, पूर्णांक e)
{
    वापस a + b + c + d + e;
}

व्योम test_fastcall_espdiff()
{
    पूर्णांक x;
    SET_SAFECALL_TARGET(check_fastcall_espdiff_0);
    x = ((typeof(&check_fastcall_espdiff_0))SAFECALL)();
    निश्चित(x == 0);
    निश्चित(ESPDIFF == 0);

    SET_SAFECALL_TARGET(check_fastcall_espdiff_1);
    x = ((typeof(&check_fastcall_espdiff_1))SAFECALL)(1);
    निश्चित(x == 1);
    निश्चित(ESPDIFF == 0);

    SET_SAFECALL_TARGET(check_fastcall_espdiff_2);
    x = ((typeof(&check_fastcall_espdiff_2))SAFECALL)(1, 2);
    निश्चित(x == 1 + 2);
    निश्चित(ESPDIFF == 0);

    SET_SAFECALL_TARGET(check_fastcall_espdiff_3);
    x = ((typeof(&check_fastcall_espdiff_3))SAFECALL)(1, 2, 3);
    निश्चित(x == 1 + 2 + 3);
    निश्चित(ESPDIFF == 1*4);

    SET_SAFECALL_TARGET(check_fastcall_espdiff_4);
    x = ((typeof(&check_fastcall_espdiff_4))SAFECALL)(1, 2, 3, 4);
    निश्चित(x == 1 + 2 + 3 + 4);
    निश्चित(ESPDIFF == 2*4);

    SET_SAFECALL_TARGET(check_fastcall_espdiff_5);
    x = ((typeof(&check_fastcall_espdiff_5))SAFECALL)(1, 2, 3, 4, 5);
    निश्चित(x == 1 + 2 + 3 + 4 + 5);
    निश्चित(ESPDIFF == 3*4);
}

पूर्णांक मुख्य()
{
#घोषणा N 10000
    पूर्णांक i;

    क्रम (i = 1; i <= N; i++) {
        test_fastcall_espdiff();
    }

    क्रम (i = 1; i <= N; i++) {
        test_fastcall_invoke();
    }

    माला_दो("TEST OK");
    वापस 0;
}
