પૂર્ણાંક printf(અચલ અક્ષર *, ...);

#define પ્રતિજ્ઞા(x) ((x) \
    ? (printf(" 1 (%s)\n",#x),1) \
    : (printf("%s:%d: error: (%s)\n",__FILE__,__LINE__,#x),0))

#define O 100
#define SO 200

/* ------------------------------------------------------ */
#જો TEST-O == 1
બાહ્ય અક્ષર etext[], _etext[];
બાહ્ય અક્ષર edata[], _edata[];
બાહ્ય અક્ષર end[], _end[];
પૂર્ણાંક check_linker_symbols(શૂન્ય)
{
    પૂર્ણાંક errors = 0;
    errors += !પ્રતિજ્ઞા(etext == _etext);
    errors += !પ્રતિજ્ઞા(edata == _edata);
    errors += !પ્રતિજ્ઞા(end == _end);
    પાછા errors;
}

#અથવાજો TEST-MAIN == 1
પૂર્ણાંક check_linker_symbols(શૂન્ય);
પૂર્ણાંક મુખ્ય(શૂન્ય)
{
    printf("linker symbols test\n");
    પ્રતિજ્ઞા(check_linker_symbols() == 0);
}

/* ------------------------------------------------------ */
#અથવાજો TEST-SO == 2
બાહ્ય અક્ષર etext[], edata[], end[];
શૂન્ય get_dso_end(અક્ષર **p)
{
    p[0] = etext;
    p[1] = edata;
    p[2] = end;
}

#અથવાજો TEST-MAIN == 2
બાહ્ય અક્ષર _etext[], _edata[], _end[];
બાહ્ય શૂન્ય get_dso_end(અક્ષર **);
સ્થિર પૂર્ણાંક fill_data = 123;
સ્થિર પૂર્ણાંક fill_bss;

પૂર્ણાંક મુખ્ય(શૂન્ય)
{
    અક્ષર *p[3];
    printf("DSO linker symbols test\n");
    get_dso_end(p);
    પ્રતિજ્ઞા(p[0] == _etext) || printf("-- %p %p\n", p[0], _etext);
    પ્રતિજ્ઞા(p[1] == _edata) || printf("-- %p %p\n", p[1], _edata);
    પ્રતિજ્ઞા(p[2] == _end)   || printf("-- %p %p\n", p[2], _end);
}

/* ------------------------------------------------------ */
#અથવાજો TEST-MAIN == 3

પૂર્ણાંક etext(શૂન્ય) { પાછા 1; }
પૂર્ણાંક edata(શૂન્ય) { પાછા 2; }
પૂર્ણાંક end(શૂન્ય) { પાછા 3; }
પૂર્ણાંક મુખ્ય(શૂન્ય)
{
    printf("user definition test\n");
    પ્રતિજ્ઞા(etext() + edata() + end() == 6);
}

/* ------------------------------------------------------ */
#અથવાજો TEST-SO == 4
unsigned અક્ષર copy_reloc_data[257];

#અથવાજો TEST-MAIN == 4
બાહ્ય unsigned અક્ષર copy_reloc_data[257];
બાહ્ય અક્ષર end[], _end[];

પૂર્ણાંક મુખ્ય(શૂન્ય)
{
    unsigned long data_end;
    printf("end copy relocation test\n");
    copy_reloc_data[256] = 42;
    data_end = (unsigned long)(copy_reloc_data + કદ copy_reloc_data);
    પ્રતિજ્ઞા(end == _end);
    પ્રતિજ્ઞા((unsigned long)end >= data_end);
    પ્રતિજ્ઞા(copy_reloc_data[256] == 42);
}

/* ------------------------------------------------------ */
#અથવાજો TEST-O == 5
શૂન્ય __attribute__((section(".text.linker_test"), noinline, used))
linker_test_text(શૂન્ય)
{
}
__attribute__((section(".bss.linker_test"), used))
unsigned અક્ષર linker_test_bss[257];

__attribute__((section(".data.linker_test"), used))
unsigned અક્ષર linker_test_data[23] = { 1 };

#અથવાજો TEST-MAIN == 5
બાહ્ય શૂન્ય linker_test_text(શૂન્ય);
બાહ્ય unsigned અક્ષર linker_test_data[23];
બાહ્ય unsigned અક્ષર linker_test_bss[257];
બાહ્ય અક્ષર etext[], _etext[];
બાહ્ય અક્ષર edata[], _edata[];
બાહ્ય અક્ષર end[], _end[];

પૂર્ણાંક મુખ્ય(શૂન્ય)
{
    અક્ષર* text_addr = (શૂન્ય*)linker_test_text;
    અક્ષર* data_end = linker_test_data + કદ linker_test_data;
    અક્ષર* bss_end = linker_test_bss + કદ linker_test_bss;

    printf("linker boundary test\n");
    linker_test_data[22] = 42;
    linker_test_bss[256] = 42;
    પ્રતિજ્ઞા(linker_test_bss > linker_test_data);
    પ્રતિજ્ઞા(etext == _etext);
    પ્રતિજ્ઞા(edata == _edata);
    પ્રતિજ્ઞા(end == _end);
    પ્રતિજ્ઞા(etext >= text_addr);
    પ્રતિજ્ઞા(edata >= data_end);
    પ્રતિજ્ઞા(end >= bss_end);
    પ્રતિજ્ઞા(linker_test_data[22] == 42);
    પ્રતિજ્ઞા(linker_test_bss[256] == 42);
}

/* ------------------------------------------------------ */
#અથવાજો TEST-SO == 6
પૂર્ણાંક end;
પૂર્ણાંક eight = 8;
પૂર્ણાંક nine;
પૂર્ણાંક dso_add() { પાછા end + eight + nine; }

#અથવાજો TEST-MAIN == 6
પૂર્ણાંક end = 7;
પૂર્ણાંક eight;
પૂર્ણાંક nine = 9;
પૂર્ણાંક dso_add();
પૂર્ણાંક મુખ્ય()
{
    પૂર્ણાંક sum;
    printf("DSO initialized data test\n");
    sum = dso_add();
    પ્રતિજ્ઞા(end == 7);
    પ્રતિજ્ઞા(eight == 8);
    પ્રતિજ્ઞા(nine == 9);
    પ્રતિજ્ઞા(sum == 24) || printf("-- %d + %d + %d = %d\n", end, eight, nine, sum);
}

/* ------------------------------------------------------ */
#endif
