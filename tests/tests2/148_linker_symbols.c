ପୂର୍ଣ୍ଣସଂଖ୍ୟା printf(ଅଚଳ ଅକ୍ଷର *, ...);

#define ପ୍ରତିଜ୍ଞା(x) ((x) \
    ? (printf(" 1 (%s)\n",#x),1) \
    : (printf("%s:%d: error: (%s)\n",__FILE__,__LINE__,#x),0))

#define O 100
#define SO 200

/* ------------------------------------------------------ */
#ଯଦି TEST-O == 1
ବାହ୍ୟ ଅକ୍ଷର etext[], _etext[];
ବାହ୍ୟ ଅକ୍ଷର edata[], _edata[];
ବାହ୍ୟ ଅକ୍ଷର end[], _end[];
ପୂର୍ଣ୍ଣସଂଖ୍ୟା check_linker_symbols(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା errors = 0;
    errors += !ପ୍ରତିଜ୍ଞା(etext == _etext);
    errors += !ପ୍ରତିଜ୍ଞା(edata == _edata);
    errors += !ପ୍ରତିଜ୍ଞା(end == _end);
    ଫେରନ୍ତୁ errors;
}

#ନଚେତଯଦି TEST-MAIN == 1
ପୂର୍ଣ୍ଣସଂଖ୍ୟା check_linker_symbols(ଶୂନ୍ୟ);
ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ(ଶୂନ୍ୟ)
{
    printf("linker symbols test\n");
    ପ୍ରତିଜ୍ଞା(check_linker_symbols() == 0);
}

/* ------------------------------------------------------ */
#ନଚେତଯଦି TEST-SO == 2
ବାହ୍ୟ ଅକ୍ଷର etext[], edata[], end[];
ଶୂନ୍ୟ get_dso_end(ଅକ୍ଷର **p)
{
    p[0] = etext;
    p[1] = edata;
    p[2] = end;
}

#ନଚେତଯଦି TEST-MAIN == 2
ବାହ୍ୟ ଅକ୍ଷର _etext[], _edata[], _end[];
ବାହ୍ୟ ଶୂନ୍ୟ get_dso_end(ଅକ୍ଷର **);
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା fill_data = 123;
ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା fill_bss;

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ(ଶୂନ୍ୟ)
{
    ଅକ୍ଷର *p[3];
    printf("DSO linker symbols test\n");
    get_dso_end(p);
    ପ୍ରତିଜ୍ଞା(p[0] == _etext) || printf("-- %p %p\n", p[0], _etext);
    ପ୍ରତିଜ୍ଞା(p[1] == _edata) || printf("-- %p %p\n", p[1], _edata);
    ପ୍ରତିଜ୍ଞା(p[2] == _end)   || printf("-- %p %p\n", p[2], _end);
}

/* ------------------------------------------------------ */
#ନଚେତଯଦି TEST-MAIN == 3

ପୂର୍ଣ୍ଣସଂଖ୍ୟା etext(ଶୂନ୍ୟ) { ଫେରନ୍ତୁ 1; }
ପୂର୍ଣ୍ଣସଂଖ୍ୟା edata(ଶୂନ୍ୟ) { ଫେରନ୍ତୁ 2; }
ପୂର୍ଣ୍ଣସଂଖ୍ୟା end(ଶୂନ୍ୟ) { ଫେରନ୍ତୁ 3; }
ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ(ଶୂନ୍ୟ)
{
    printf("user definition test\n");
    ପ୍ରତିଜ୍ଞା(etext() + edata() + end() == 6);
}

/* ------------------------------------------------------ */
#ନଚେତଯଦି TEST-SO == 4
unsigned ଅକ୍ଷର copy_reloc_data[257];

#ନଚେତଯଦି TEST-MAIN == 4
ବାହ୍ୟ unsigned ଅକ୍ଷର copy_reloc_data[257];
ବାହ୍ୟ ଅକ୍ଷର end[], _end[];

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ(ଶୂନ୍ୟ)
{
    unsigned long data_end;
    printf("end copy relocation test\n");
    copy_reloc_data[256] = 42;
    data_end = (unsigned long)(copy_reloc_data + ଆକାର copy_reloc_data);
    ପ୍ରତିଜ୍ଞା(end == _end);
    ପ୍ରତିଜ୍ଞା((unsigned long)end >= data_end);
    ପ୍ରତିଜ୍ଞା(copy_reloc_data[256] == 42);
}

/* ------------------------------------------------------ */
#ନଚେତଯଦି TEST-O == 5
ଶୂନ୍ୟ __attribute__((section(".text.linker_test"), noinline, used))
linker_test_text(ଶୂନ୍ୟ)
{
}
__attribute__((section(".bss.linker_test"), used))
unsigned ଅକ୍ଷର linker_test_bss[257];

__attribute__((section(".data.linker_test"), used))
unsigned ଅକ୍ଷର linker_test_data[23] = { 1 };

#ନଚେତଯଦି TEST-MAIN == 5
ବାହ୍ୟ ଶୂନ୍ୟ linker_test_text(ଶୂନ୍ୟ);
ବାହ୍ୟ unsigned ଅକ୍ଷର linker_test_data[23];
ବାହ୍ୟ unsigned ଅକ୍ଷର linker_test_bss[257];
ବାହ୍ୟ ଅକ୍ଷର etext[], _etext[];
ବାହ୍ୟ ଅକ୍ଷର edata[], _edata[];
ବାହ୍ୟ ଅକ୍ଷର end[], _end[];

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ(ଶୂନ୍ୟ)
{
    ଅକ୍ଷର* text_addr = (ଶୂନ୍ୟ*)linker_test_text;
    ଅକ୍ଷର* data_end = linker_test_data + ଆକାର linker_test_data;
    ଅକ୍ଷର* bss_end = linker_test_bss + ଆକାର linker_test_bss;

    printf("linker boundary test\n");
    linker_test_data[22] = 42;
    linker_test_bss[256] = 42;
    ପ୍ରତିଜ୍ଞା(linker_test_bss > linker_test_data);
    ପ୍ରତିଜ୍ଞା(etext == _etext);
    ପ୍ରତିଜ୍ଞା(edata == _edata);
    ପ୍ରତିଜ୍ଞା(end == _end);
    ପ୍ରତିଜ୍ଞା(etext >= text_addr);
    ପ୍ରତିଜ୍ଞା(edata >= data_end);
    ପ୍ରତିଜ୍ଞା(end >= bss_end);
    ପ୍ରତିଜ୍ଞା(linker_test_data[22] == 42);
    ପ୍ରତିଜ୍ଞା(linker_test_bss[256] == 42);
}

/* ------------------------------------------------------ */
#ନଚେତଯଦି TEST-SO == 6
ପୂର୍ଣ୍ଣସଂଖ୍ୟା end;
ପୂର୍ଣ୍ଣସଂଖ୍ୟା eight = 8;
ପୂର୍ଣ୍ଣସଂଖ୍ୟା nine;
ପୂର୍ଣ୍ଣସଂଖ୍ୟା dso_add() { ଫେରନ୍ତୁ end + eight + nine; }

#ନଚେତଯଦି TEST-MAIN == 6
ପୂର୍ଣ୍ଣସଂଖ୍ୟା end = 7;
ପୂର୍ଣ୍ଣସଂଖ୍ୟା eight;
ପୂର୍ଣ୍ଣସଂଖ୍ୟା nine = 9;
ପୂର୍ଣ୍ଣସଂଖ୍ୟା dso_add();
ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ()
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା sum;
    printf("DSO initialized data test\n");
    sum = dso_add();
    ପ୍ରତିଜ୍ଞା(end == 7);
    ପ୍ରତିଜ୍ଞା(eight == 8);
    ପ୍ରତିଜ୍ଞା(nine == 9);
    ପ୍ରତିଜ୍ଞା(sum == 24) || printf("-- %d + %d + %d = %d\n", end, eight, nine, sum);
}

/* ------------------------------------------------------ */
#endif
