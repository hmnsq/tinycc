#அந்தர்பாவ <stdio.h>
#அந்தர்பாவ <assert.h>

#எனில் !(defined( _WIN32) || (defined(__FreeBSD__) && defined(__i386__)))
#define __fastcall __attribute((fastcall))
#endif

#ifndef __leading_underscore
#define குறியீடு_2(x) _##x
#இல்லையெனில்
#define குறியீடு_2(x) x
#endif

/////////////////////////////////////////////////////////////////////////
//////////                TRAP FRAMEWORK
/////////////////////////////////////////////////////////////////////////
// if you cast 'TRAP' to a function pointer and call it,
//   it will save all 8 registers,
//   and jump into C-code (previously set using 'SET_TRAP_HANDLER(x)'),
//   in C-code you can pop DWORDs from stack and modify registers
//

வெறுமை *குறியீடு_2(trap_handler);

வெளி unsigned எழுத்து குறியீடு_2(trap)[];
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

கட்டமைப்பு trapframe {
    unsigned edi, esi, ebp, esp, ebx, edx, ecx, eax;
};


#define M_FLOAT(addr) (*(தசம *)(addr))
#define M_DWORD(addr) (*(unsigned *)(addr))
#define M_WORD(addr) (*(unsigned short *)(addr))
#define M_BYTE(addr) (*(unsigned எழுத்து *)(addr))
#define R_EAX ((tf)->eax)
#define R_ECX ((tf)->ecx)
#define R_EDX ((tf)->edx)
#define R_EBX ((tf)->ebx)
#define R_ESP ((tf)->esp)
#define R_EBP ((tf)->ebp)
#define R_ESI ((tf)->esi)
#define R_EDI ((tf)->edi)

#define ARG(x) (M_DWORD(R_ESP + (x) * 4))

#define RETN(x) செய் { \
    M_DWORD(R_ESP + (x)) = M_DWORD(R_ESP); \
    R_ESP += (x); \
} போது (0)

#define DUMP() செய் { \
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
    க்கு (i = 1; i <= 8; i++) { \
        printf("[ARG%4d]: %08X\n", i, ARG(i)); \
    } \
} போது (0)

#define SET_TRAP_HANDLER(x) ((குறியீடு_2(trap_handler)) = (x))
#define TRAP ((வெறுமை *) &குறியீடு_2(trap))



/////////////////////////////////////////////////////////////////////////
//////////                SAFECALL FRAMEWORK
/////////////////////////////////////////////////////////////////////////
// this framework will convert any calling convention to cdecl
// usage: first set call target with 'SET_SAFECALL_TARGET(x)'
//        then cast 'SAFECALL' to target function pointer type and invoke it
//        after calling, 'ESPDIFF' is the difference of old and new esp

வெறுமை *குறியீடு_2(sc_call_target);
unsigned குறியீடு_2(sc_retn_addr);
unsigned குறியீடு_2(sc_old_esp);
unsigned குறியீடு_2(sc_new_esp);

வெளி unsigned எழுத்து குறியீடு_2(safecall)[];
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

#define SET_SAFECALL_TARGET(x) ((குறியீடு_2(sc_call_target)) = (x))
#define SAFECALL ((வெறுமை *) &குறியீடு_2(safecall))
#define ESPDIFF (குறியீடு_2(sc_new_esp) - குறியீடு_2(sc_old_esp))


/////////////////////////////////////////////////////////////////////////
//////////                TEST FASTCALL INVOKE
/////////////////////////////////////////////////////////////////////////

வெறுமை check_fastcall_invoke_0(கட்டமைப்பு trapframe *tf)
{
    //DUMP();
    RETN(0);
}

வெறுமை check_fastcall_invoke_1(கட்டமைப்பு trapframe *tf)
{
    //DUMP();
    ப்ரதிஜ்ஞா(R_ECX == 0x11111111);
    RETN(0);
}
வெறுமை check_fastcall_invoke_2(கட்டமைப்பு trapframe *tf)
{
    //DUMP();
    ப்ரதிஜ்ஞா(R_ECX == 0x11111111);
    ப்ரதிஜ்ஞா(R_EDX == 0x22222222);
    RETN(0);
}
வெறுமை check_fastcall_invoke_3(கட்டமைப்பு trapframe *tf)
{
    //DUMP();
    ப்ரதிஜ்ஞா(R_ECX == 0x11111111);
    ப்ரதிஜ்ஞா(R_EDX == 0x22222222);
    ப்ரதிஜ்ஞா(ARG(1) == 0x33333333);
    RETN(1*4);
}
வெறுமை check_fastcall_invoke_4(கட்டமைப்பு trapframe *tf)
{
    //DUMP();
    ப்ரதிஜ்ஞா(R_ECX == 0x11111111);
    ப்ரதிஜ்ஞா(R_EDX == 0x22222222);
    ப்ரதிஜ்ஞா(ARG(1) == 0x33333333);
    ப்ரதிஜ்ஞா(ARG(2) == 0x44444444);
    RETN(2*4);
}

வெறுமை check_fastcall_invoke_5(கட்டமைப்பு trapframe *tf)
{
    //DUMP();
    ப்ரதிஜ்ஞா(R_ECX == 0x11111111);
    ப்ரதிஜ்ஞா(R_EDX == 0x22222222);
    ப்ரதிஜ்ஞா(ARG(1) == 0x33333333);
    ப்ரதிஜ்ஞா(ARG(2) == 0x44444444);
    ப்ரதிஜ்ஞா(ARG(3) == 0x55555555);
    RETN(3*4);
}

வெறுமை test_fastcall_invoke()
{
    SET_TRAP_HANDLER(check_fastcall_invoke_0);
    ((வெறுமை __fastcall (*)(வெறுமை)) TRAP)();

    SET_TRAP_HANDLER(check_fastcall_invoke_1);
    ((வெறுமை __fastcall (*)(unsigned)) TRAP)(0x11111111);

    SET_TRAP_HANDLER(check_fastcall_invoke_2);
    ((வெறுமை __fastcall (*)(unsigned, unsigned)) TRAP)(0x11111111, 0x22222222);

    SET_TRAP_HANDLER(check_fastcall_invoke_3);
    ((வெறுமை __fastcall (*)(unsigned, unsigned, unsigned)) TRAP)(0x11111111, 0x22222222, 0x33333333);

    SET_TRAP_HANDLER(check_fastcall_invoke_4);
    ((வெறுமை __fastcall (*)(unsigned, unsigned, unsigned, unsigned)) TRAP)(0x11111111, 0x22222222, 0x33333333, 0x44444444);

    SET_TRAP_HANDLER(check_fastcall_invoke_5);
    ((வெறுமை __fastcall (*)(unsigned, unsigned, unsigned, unsigned, unsigned)) TRAP)(0x11111111, 0x22222222, 0x33333333, 0x44444444, 0x55555555);
}


/////////////////////////////////////////////////////////////////////////
//////////                TEST FUNCTION CODE GENERATION
/////////////////////////////////////////////////////////////////////////

முழு __fastcall check_fastcall_espdiff_0(வெறுமை)
{
    திரும்பு 0;
}

முழு __fastcall check_fastcall_espdiff_1(முழு a)
{
    திரும்பு a;
}

முழு __fastcall check_fastcall_espdiff_2(முழு a, முழு b)
{
    திரும்பு a + b;
}

முழு __fastcall check_fastcall_espdiff_3(முழு a, முழு b, முழு c)
{
    திரும்பு a + b + c;
}

முழு __fastcall check_fastcall_espdiff_4(முழு a, முழு b, முழு c, முழு d)
{
    திரும்பு a + b + c + d;
}

முழு __fastcall check_fastcall_espdiff_5(முழு a, முழு b, முழு c, முழு d, முழு e)
{
    திரும்பு a + b + c + d + e;
}

வெறுமை test_fastcall_espdiff()
{
    முழு x;
    SET_SAFECALL_TARGET(check_fastcall_espdiff_0);
    x = ((typeof(&check_fastcall_espdiff_0))SAFECALL)();
    ப்ரதிஜ்ஞா(x == 0);
    ப்ரதிஜ்ஞா(ESPDIFF == 0);

    SET_SAFECALL_TARGET(check_fastcall_espdiff_1);
    x = ((typeof(&check_fastcall_espdiff_1))SAFECALL)(1);
    ப்ரதிஜ்ஞா(x == 1);
    ப்ரதிஜ்ஞா(ESPDIFF == 0);

    SET_SAFECALL_TARGET(check_fastcall_espdiff_2);
    x = ((typeof(&check_fastcall_espdiff_2))SAFECALL)(1, 2);
    ப்ரதிஜ்ஞா(x == 1 + 2);
    ப்ரதிஜ்ஞா(ESPDIFF == 0);

    SET_SAFECALL_TARGET(check_fastcall_espdiff_3);
    x = ((typeof(&check_fastcall_espdiff_3))SAFECALL)(1, 2, 3);
    ப்ரதிஜ்ஞா(x == 1 + 2 + 3);
    ப்ரதிஜ்ஞா(ESPDIFF == 1*4);

    SET_SAFECALL_TARGET(check_fastcall_espdiff_4);
    x = ((typeof(&check_fastcall_espdiff_4))SAFECALL)(1, 2, 3, 4);
    ப்ரதிஜ்ஞா(x == 1 + 2 + 3 + 4);
    ப்ரதிஜ்ஞா(ESPDIFF == 2*4);

    SET_SAFECALL_TARGET(check_fastcall_espdiff_5);
    x = ((typeof(&check_fastcall_espdiff_5))SAFECALL)(1, 2, 3, 4, 5);
    ப்ரதிஜ்ஞா(x == 1 + 2 + 3 + 4 + 5);
    ப்ரதிஜ்ஞா(ESPDIFF == 3*4);
}

முழு முதன்மை()
{
#define N 10000
    முழு i;

    க்கு (i = 1; i <= N; i++) {
        test_fastcall_espdiff();
    }

    க்கு (i = 1; i <= N; i++) {
        test_fastcall_invoke();
    }

    puts("TEST OK");
    திரும்பு 0;
}
