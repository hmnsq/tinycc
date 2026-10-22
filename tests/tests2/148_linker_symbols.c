puur_naa_nka printf(const var_na *, ...);

#define assert(x) ((x) \
    ? (printf(" 1 (%s)\n",#x),1) \
    : (printf("%s:%d: error: (%s)\n",__FILE__,__LINE__,#x),0))

#define O 100
#define SO 200

/* ------------------------------------------------------ */
#ᨀᨘ TEST-O == 1
extern var_na etext[], _etext[];
extern var_na edata[], _edata[];
extern var_na end[], _end[];
puur_naa_nka check_linker_symbols(void)
{
    puur_naa_nka errors = 0;
    errors += !assert(etext == _etext);
    errors += !assert(edata == _edata);
    errors += !assert(end == _end);
    ᨀᨘᨒ errors;
}

#elif TEST-MAIN == 1
puur_naa_nka check_linker_symbols(void);
puur_naa_nka main(void)
{
    printf("linker symbols test\n");
    assert(check_linker_symbols() == 0);
}

/* ------------------------------------------------------ */
#elif TEST-SO == 2
extern var_na etext[], edata[], end[];
void get_dso_end(var_na **p)
{
    p[0] = etext;
    p[1] = edata;
    p[2] = end;
}

#elif TEST-MAIN == 2
extern var_na _etext[], _edata[], _end[];
extern void get_dso_end(var_na **);
static puur_naa_nka fill_data = 123;
static puur_naa_nka fill_bss;

puur_naa_nka main(void)
{
    var_na *p[3];
    printf("DSO linker symbols test\n");
    get_dso_end(p);
    assert(p[0] == _etext) || printf("-- %p %p\n", p[0], _etext);
    assert(p[1] == _edata) || printf("-- %p %p\n", p[1], _edata);
    assert(p[2] == _end)   || printf("-- %p %p\n", p[2], _end);
}

/* ------------------------------------------------------ */
#elif TEST-MAIN == 3

puur_naa_nka etext(void) { ᨀᨘᨒ 1; }
puur_naa_nka edata(void) { ᨀᨘᨒ 2; }
puur_naa_nka end(void) { ᨀᨘᨒ 3; }
puur_naa_nka main(void)
{
    printf("user definition test\n");
    assert(etext() + edata() + end() == 6);
}

/* ------------------------------------------------------ */
#elif TEST-SO == 4
unsigned var_na copy_reloc_data[257];

#elif TEST-MAIN == 4
extern unsigned var_na copy_reloc_data[257];
extern var_na end[], _end[];

puur_naa_nka main(void)
{
    unsigned long data_end;
    printf("end copy relocation test\n");
    copy_reloc_data[256] = 42;
    data_end = (unsigned long)(copy_reloc_data + parimaa_na copy_reloc_data);
    assert(end == _end);
    assert((unsigned long)end >= data_end);
    assert(copy_reloc_data[256] == 42);
}

/* ------------------------------------------------------ */
#elif TEST-O == 5
void __attribute__((section(".text.linker_test"), noinline, used))
linker_test_text(void)
{
}
__attribute__((section(".bss.linker_test"), used))
unsigned var_na linker_test_bss[257];

__attribute__((section(".data.linker_test"), used))
unsigned var_na linker_test_data[23] = { 1 };

#elif TEST-MAIN == 5
extern void linker_test_text(void);
extern unsigned var_na linker_test_data[23];
extern unsigned var_na linker_test_bss[257];
extern var_na etext[], _etext[];
extern var_na edata[], _edata[];
extern var_na end[], _end[];

puur_naa_nka main(void)
{
    var_na* text_addr = (void*)linker_test_text;
    var_na* data_end = linker_test_data + parimaa_na linker_test_data;
    var_na* bss_end = linker_test_bss + parimaa_na linker_test_bss;

    printf("linker boundary test\n");
    linker_test_data[22] = 42;
    linker_test_bss[256] = 42;
    assert(linker_test_bss > linker_test_data);
    assert(etext == _etext);
    assert(edata == _edata);
    assert(end == _end);
    assert(etext >= text_addr);
    assert(edata >= data_end);
    assert(end >= bss_end);
    assert(linker_test_data[22] == 42);
    assert(linker_test_bss[256] == 42);
}

/* ------------------------------------------------------ */
#elif TEST-SO == 6
puur_naa_nka end;
puur_naa_nka eight = 8;
puur_naa_nka nine;
puur_naa_nka dso_add() { ᨀᨘᨒ end + eight + nine; }

#elif TEST-MAIN == 6
puur_naa_nka end = 7;
puur_naa_nka eight;
puur_naa_nka nine = 9;
puur_naa_nka dso_add();
puur_naa_nka main()
{
    puur_naa_nka sum;
    printf("DSO initialized data test\n");
    sum = dso_add();
    assert(end == 7);
    assert(eight == 8);
    assert(nine == 9);
    assert(sum == 24) || printf("-- %d + %d + %d = %d\n", end, eight, nine, sum);
}

/* ------------------------------------------------------ */
#endif
