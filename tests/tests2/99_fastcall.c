#અન્તર્ભાવ <stdio.h>
#અન્તર્ભાવ <assert.h>

#જો !(defined( _WIN32) || (defined(__FreeBSD__) && defined(__i386__)))
#define __fastcall __attribute((fastcall))
#endif

#ifndef __leading_underscore
#define પ્રતીક_2(x) _##x
#નહીંતર
#define પ્રતીક_2(x) x
#endif

/////////////////////////////////////////////////////////////////////////
//////////                TRAP FRAMEWORK
/////////////////////////////////////////////////////////////////////////
// if you cast 'TRAP' to a function pointer and call it,
//   it will save all 8 registers,
//   and jump into C-code (previously set using 'SET_TRAP_HANDLER(x)'),
//   in C-code you can pop DWORDs from stack and modify registers
//

શૂન્ય *પ્રતીક_2(trap_handler);

બાહ્ય unsigned અક્ષર પ્રતીક_2(trap)[];
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

સંરચના trapframe {
    unsigned edi, esi, ebp, esp, ebx, edx, ecx, eax;
};


#define M_FLOAT(addr) (*(દશાંશ *)(addr))
#define M_DWORD(addr) (*(unsigned *)(addr))
#define M_WORD(addr) (*(unsigned short *)(addr))
#define M_BYTE(addr) (*(unsigned અક્ષર *)(addr))
#define R_EAX ((tf)->eax)
#define R_ECX ((tf)->ecx)
#define R_EDX ((tf)->edx)
#define R_EBX ((tf)->ebx)
#define R_ESP ((tf)->esp)
#define R_EBP ((tf)->ebp)
#define R_ESI ((tf)->esi)
#define R_EDI ((tf)->edi)

#define ARG(x) (M_DWORD(R_ESP + (x) * 4))

#define RETN(x) કરો { \
    M_DWORD(R_ESP + (x)) = M_DWORD(R_ESP); \
    R_ESP += (x); \
} જ્યારે (0)

#define DUMP() કરો { \
    unsigned i; \
    printf("EAX: %08X\n", R_EAX); \
    printf("ECX: %08X\n", R_ECX); \
    printf("EDX: %08X\n", R_EDX); \
    printf("EBX: %08X\n", R_EBX); \
    printf("ESP: %08X\n", R_ESP); \
    printf("EBP: %08X\n", R_EBP); \
    printf("ESI: %08X\n", R_ESI); \
    printf("EDI: %08X\n", R_EDI); \
    printf("\n"); \
    printf("[RETADDR]: %08X\n", M_DWORD(R_ESP)); \
    માટે (i = 1; i <= 8; i++) { \
        printf("[ARG%4d]: %08X\n", i, ARG(i)); \
    } \
} જ્યારે (0)

#define SET_TRAP_HANDLER(x) ((પ્રતીક_2(trap_handler)) = (x))
#define TRAP ((શૂન્ય *) &પ્રતીક_2(trap))



/////////////////////////////////////////////////////////////////////////
//////////                SAFECALL FRAMEWORK
/////////////////////////////////////////////////////////////////////////
// this framework will convert any calling convention to cdecl
// usage: first set call target with 'SET_SAFECALL_TARGET(x)'
//        then cast 'SAFECALL' to target function pointer type and invoke it
//        after calling, 'ESPDIFF' is the difference of old and new esp

શૂન્ય *પ્રતીક_2(sc_call_target);
unsigned પ્રતીક_2(sc_retn_addr);
unsigned પ્રતીક_2(sc_old_esp);
unsigned પ્રતીક_2(sc_new_esp);

બાહ્ય unsigned અક્ષર પ્રતીક_2(safecall)[];
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

#define SET_SAFECALL_TARGET(x) ((પ્રતીક_2(sc_call_target)) = (x))
#define SAFECALL ((શૂન્ય *) &પ્રતીક_2(safecall))
#define ESPDIFF (પ્રતીક_2(sc_new_esp) - પ્રતીક_2(sc_old_esp))


/////////////////////////////////////////////////////////////////////////
//////////                TEST FASTCALL INVOKE
/////////////////////////////////////////////////////////////////////////

શૂન્ય check_fastcall_invoke_0(સંરચના trapframe *tf)
{
    //DUMP();
    RETN(0);
}

શૂન્ય check_fastcall_invoke_1(સંરચના trapframe *tf)
{
    //DUMP();
    પ્રતિજ્ઞા(R_ECX == 0x11111111);
    RETN(0);
}
શૂન્ય check_fastcall_invoke_2(સંરચના trapframe *tf)
{
    //DUMP();
    પ્રતિજ્ઞા(R_ECX == 0x11111111);
    પ્રતિજ્ઞા(R_EDX == 0x22222222);
    RETN(0);
}
શૂન્ય check_fastcall_invoke_3(સંરચના trapframe *tf)
{
    //DUMP();
    પ્રતિજ્ઞા(R_ECX == 0x11111111);
    પ્રતિજ્ઞા(R_EDX == 0x22222222);
    પ્રતિજ્ઞા(ARG(1) == 0x33333333);
    RETN(1*4);
}
શૂન્ય check_fastcall_invoke_4(સંરચના trapframe *tf)
{
    //DUMP();
    પ્રતિજ્ઞા(R_ECX == 0x11111111);
    પ્રતિજ્ઞા(R_EDX == 0x22222222);
    પ્રતિજ્ઞા(ARG(1) == 0x33333333);
    પ્રતિજ્ઞા(ARG(2) == 0x44444444);
    RETN(2*4);
}

શૂન્ય check_fastcall_invoke_5(સંરચના trapframe *tf)
{
    //DUMP();
    પ્રતિજ્ઞા(R_ECX == 0x11111111);
    પ્રતિજ્ઞા(R_EDX == 0x22222222);
    પ્રતિજ્ઞા(ARG(1) == 0x33333333);
    પ્રતિજ્ઞા(ARG(2) == 0x44444444);
    પ્રતિજ્ઞા(ARG(3) == 0x55555555);
    RETN(3*4);
}

શૂન્ય test_fastcall_invoke()
{
    SET_TRAP_HANDLER(check_fastcall_invoke_0);
    ((શૂન્ય __fastcall (*)(શૂન્ય)) TRAP)();

    SET_TRAP_HANDLER(check_fastcall_invoke_1);
    ((શૂન્ય __fastcall (*)(unsigned)) TRAP)(0x11111111);

    SET_TRAP_HANDLER(check_fastcall_invoke_2);
    ((શૂન્ય __fastcall (*)(unsigned, unsigned)) TRAP)(0x11111111, 0x22222222);

    SET_TRAP_HANDLER(check_fastcall_invoke_3);
    ((શૂન્ય __fastcall (*)(unsigned, unsigned, unsigned)) TRAP)(0x11111111, 0x22222222, 0x33333333);

    SET_TRAP_HANDLER(check_fastcall_invoke_4);
    ((શૂન્ય __fastcall (*)(unsigned, unsigned, unsigned, unsigned)) TRAP)(0x11111111, 0x22222222, 0x33333333, 0x44444444);

    SET_TRAP_HANDLER(check_fastcall_invoke_5);
    ((શૂન્ય __fastcall (*)(unsigned, unsigned, unsigned, unsigned, unsigned)) TRAP)(0x11111111, 0x22222222, 0x33333333, 0x44444444, 0x55555555);
}


/////////////////////////////////////////////////////////////////////////
//////////                TEST FUNCTION CODE GENERATION
/////////////////////////////////////////////////////////////////////////

પૂર્ણાંક __fastcall check_fastcall_espdiff_0(શૂન્ય)
{
    પાછા 0;
}

પૂર્ણાંક __fastcall check_fastcall_espdiff_1(પૂર્ણાંક a)
{
    પાછા a;
}

પૂર્ણાંક __fastcall check_fastcall_espdiff_2(પૂર્ણાંક a, પૂર્ણાંક b)
{
    પાછા a + b;
}

પૂર્ણાંક __fastcall check_fastcall_espdiff_3(પૂર્ણાંક a, પૂર્ણાંક b, પૂર્ણાંક c)
{
    પાછા a + b + c;
}

પૂર્ણાંક __fastcall check_fastcall_espdiff_4(પૂર્ણાંક a, પૂર્ણાંક b, પૂર્ણાંક c, પૂર્ણાંક d)
{
    પાછા a + b + c + d;
}

પૂર્ણાંક __fastcall check_fastcall_espdiff_5(પૂર્ણાંક a, પૂર્ણાંક b, પૂર્ણાંક c, પૂર્ણાંક d, પૂર્ણાંક e)
{
    પાછા a + b + c + d + e;
}

શૂન્ય test_fastcall_espdiff()
{
    પૂર્ણાંક x;
    SET_SAFECALL_TARGET(check_fastcall_espdiff_0);
    x = ((typeof(&check_fastcall_espdiff_0))SAFECALL)();
    પ્રતિજ્ઞા(x == 0);
    પ્રતિજ્ઞા(ESPDIFF == 0);

    SET_SAFECALL_TARGET(check_fastcall_espdiff_1);
    x = ((typeof(&check_fastcall_espdiff_1))SAFECALL)(1);
    પ્રતિજ્ઞા(x == 1);
    પ્રતિજ્ઞા(ESPDIFF == 0);

    SET_SAFECALL_TARGET(check_fastcall_espdiff_2);
    x = ((typeof(&check_fastcall_espdiff_2))SAFECALL)(1, 2);
    પ્રતિજ્ઞા(x == 1 + 2);
    પ્રતિજ્ઞા(ESPDIFF == 0);

    SET_SAFECALL_TARGET(check_fastcall_espdiff_3);
    x = ((typeof(&check_fastcall_espdiff_3))SAFECALL)(1, 2, 3);
    પ્રતિજ્ઞા(x == 1 + 2 + 3);
    પ્રતિજ્ઞા(ESPDIFF == 1*4);

    SET_SAFECALL_TARGET(check_fastcall_espdiff_4);
    x = ((typeof(&check_fastcall_espdiff_4))SAFECALL)(1, 2, 3, 4);
    પ્રતિજ્ઞા(x == 1 + 2 + 3 + 4);
    પ્રતિજ્ઞા(ESPDIFF == 2*4);

    SET_SAFECALL_TARGET(check_fastcall_espdiff_5);
    x = ((typeof(&check_fastcall_espdiff_5))SAFECALL)(1, 2, 3, 4, 5);
    પ્રતિજ્ઞા(x == 1 + 2 + 3 + 4 + 5);
    પ્રતિજ્ઞા(ESPDIFF == 3*4);
}

પૂર્ણાંક મુખ્ય()
{
#define N 10000
    પૂર્ણાંક i;

    માટે (i = 1; i <= N; i++) {
        test_fastcall_espdiff();
    }

    માટે (i = 1; i <= N; i++) {
        test_fastcall_invoke();
    }

    puts("TEST OK");
    પાછા 0;
}
