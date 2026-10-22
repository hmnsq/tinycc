صحيح printf(ثابت حرف *, ...);

#define أكد(x) ((x) \
    ? (printf(" 1 (%s)\n",#x),1) \
    : (printf("%s:%d: error: (%s)\n",__FILE__,__LINE__,#x),0))

#define O 100
#define SO 200

/* ------------------------------------------------------ */
#إذا TEST-O == 1
خارجي حرف etext[], _etext[];
خارجي حرف edata[], _edata[];
خارجي حرف end[], _end[];
صحيح check_linker_symbols(فراغ)
{
    صحيح errors = 0;
    errors += !أكد(etext == _etext);
    errors += !أكد(edata == _edata);
    errors += !أكد(end == _end);
    أرجع errors;
}

#وإلاإذا TEST-MAIN == 1
صحيح check_linker_symbols(فراغ);
صحيح main(فراغ)
{
    printf("linker symbols test\n");
    أكد(check_linker_symbols() == 0);
}

/* ------------------------------------------------------ */
#وإلاإذا TEST-SO == 2
خارجي حرف etext[], edata[], end[];
فراغ get_dso_end(حرف **p)
{
    p[0] = etext;
    p[1] = edata;
    p[2] = end;
}

#وإلاإذا TEST-MAIN == 2
خارجي حرف _etext[], _edata[], _end[];
خارجي فراغ get_dso_end(حرف **);
ساكن صحيح fill_data = 123;
ساكن صحيح fill_bss;

صحيح main(فراغ)
{
    حرف *p[3];
    printf("DSO linker symbols test\n");
    get_dso_end(p);
    أكد(p[0] == _etext) || printf("-- %p %p\n", p[0], _etext);
    أكد(p[1] == _edata) || printf("-- %p %p\n", p[1], _edata);
    أكد(p[2] == _end)   || printf("-- %p %p\n", p[2], _end);
}

/* ------------------------------------------------------ */
#وإلاإذا TEST-MAIN == 3

صحيح etext(فراغ) { أرجع 1; }
صحيح edata(فراغ) { أرجع 2; }
صحيح end(فراغ) { أرجع 3; }
صحيح main(فراغ)
{
    printf("user definition test\n");
    أكد(etext() + edata() + end() == 6);
}

/* ------------------------------------------------------ */
#وإلاإذا TEST-SO == 4
unsigned حرف copy_reloc_data[257];

#وإلاإذا TEST-MAIN == 4
خارجي unsigned حرف copy_reloc_data[257];
خارجي حرف end[], _end[];

صحيح main(فراغ)
{
    unsigned long data_end;
    printf("end copy relocation test\n");
    copy_reloc_data[256] = 42;
    data_end = (unsigned long)(copy_reloc_data + حجم copy_reloc_data);
    أكد(end == _end);
    أكد((unsigned long)end >= data_end);
    أكد(copy_reloc_data[256] == 42);
}

/* ------------------------------------------------------ */
#وإلاإذا TEST-O == 5
فراغ __attribute__((section(".text.linker_test"), noinline, used))
linker_test_text(فراغ)
{
}
__attribute__((section(".bss.linker_test"), used))
unsigned حرف linker_test_bss[257];

__attribute__((section(".data.linker_test"), used))
unsigned حرف linker_test_data[23] = { 1 };

#وإلاإذا TEST-MAIN == 5
خارجي فراغ linker_test_text(فراغ);
خارجي unsigned حرف linker_test_data[23];
خارجي unsigned حرف linker_test_bss[257];
خارجي حرف etext[], _etext[];
خارجي حرف edata[], _edata[];
خارجي حرف end[], _end[];

صحيح main(فراغ)
{
    حرف* text_addr = (فراغ*)linker_test_text;
    حرف* data_end = linker_test_data + حجم linker_test_data;
    حرف* bss_end = linker_test_bss + حجم linker_test_bss;

    printf("linker boundary test\n");
    linker_test_data[22] = 42;
    linker_test_bss[256] = 42;
    أكد(linker_test_bss > linker_test_data);
    أكد(etext == _etext);
    أكد(edata == _edata);
    أكد(end == _end);
    أكد(etext >= text_addr);
    أكد(edata >= data_end);
    أكد(end >= bss_end);
    أكد(linker_test_data[22] == 42);
    أكد(linker_test_bss[256] == 42);
}

/* ------------------------------------------------------ */
#وإلاإذا TEST-SO == 6
صحيح end;
صحيح eight = 8;
صحيح nine;
صحيح dso_add() { أرجع end + eight + nine; }

#وإلاإذا TEST-MAIN == 6
صحيح end = 7;
صحيح eight;
صحيح nine = 9;
صحيح dso_add();
صحيح main()
{
    صحيح sum;
    printf("DSO initialized data test\n");
    sum = dso_add();
    أكد(end == 7);
    أكد(eight == 8);
    أكد(nine == 9);
    أكد(sum == 24) || printf("-- %d + %d + %d = %d\n", end, eight, nine, sum);
}

/* ------------------------------------------------------ */
#endif
