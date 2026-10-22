ಪೂರ್ಣಾಙ್ಕ printf(ಧ್ರುವ ವರ್ಣ *, ...);

#define ಪ್ರತಿಜ್ಞಾ(x) ((x) \
    ? (printf(" 1 (%s)\n",#x),1) \
    : (printf("%s:%d: error: (%s)\n",__FILE__,__LINE__,#x),0))

#define O 100
#define SO 200

/* ------------------------------------------------------ */
#ಯದಿ TEST-O == 1
ಬಾಹ್ಯ ವರ್ಣ etext[], _etext[];
ಬಾಹ್ಯ ವರ್ಣ edata[], _edata[];
ಬಾಹ್ಯ ವರ್ಣ end[], _end[];
ಪೂರ್ಣಾಙ್ಕ check_linker_symbols(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ errors = 0;
    errors += !ಪ್ರತಿಜ್ಞಾ(etext == _etext);
    errors += !ಪ್ರತಿಜ್ಞಾ(edata == _edata);
    errors += !ಪ್ರತಿಜ್ಞಾ(end == _end);
    ಪ್ರತ್ಯಾಗಮ errors;
}

#ನೋಚೇದ್ಯದಿ TEST-MAIN == 1
ಪೂರ್ಣಾಙ್ಕ check_linker_symbols(ಶೂನ್ಯ);
ಪೂರ್ಣಾಙ್ಕ main(ಶೂನ್ಯ)
{
    printf("linker symbols test\n");
    ಪ್ರತಿಜ್ಞಾ(check_linker_symbols() == 0);
}

/* ------------------------------------------------------ */
#ನೋಚೇದ್ಯದಿ TEST-SO == 2
ಬಾಹ್ಯ ವರ್ಣ etext[], edata[], end[];
ಶೂನ್ಯ get_dso_end(ವರ್ಣ **p)
{
    p[0] = etext;
    p[1] = edata;
    p[2] = end;
}

#ನೋಚೇದ್ಯದಿ TEST-MAIN == 2
ಬಾಹ್ಯ ವರ್ಣ _etext[], _edata[], _end[];
ಬಾಹ್ಯ ಶೂನ್ಯ get_dso_end(ವರ್ಣ **);
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ fill_data = 123;
ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ fill_bss;

ಪೂರ್ಣಾಙ್ಕ main(ಶೂನ್ಯ)
{
    ವರ್ಣ *p[3];
    printf("DSO linker symbols test\n");
    get_dso_end(p);
    ಪ್ರತಿಜ್ಞಾ(p[0] == _etext) || printf("-- %p %p\n", p[0], _etext);
    ಪ್ರತಿಜ್ಞಾ(p[1] == _edata) || printf("-- %p %p\n", p[1], _edata);
    ಪ್ರತಿಜ್ಞಾ(p[2] == _end)   || printf("-- %p %p\n", p[2], _end);
}

/* ------------------------------------------------------ */
#ನೋಚೇದ್ಯದಿ TEST-MAIN == 3

ಪೂರ್ಣಾಙ್ಕ etext(ಶೂನ್ಯ) { ಪ್ರತ್ಯಾಗಮ 1; }
ಪೂರ್ಣಾಙ್ಕ edata(ಶೂನ್ಯ) { ಪ್ರತ್ಯಾಗಮ 2; }
ಪೂರ್ಣಾಙ್ಕ end(ಶೂನ್ಯ) { ಪ್ರತ್ಯಾಗಮ 3; }
ಪೂರ್ಣಾಙ್ಕ main(ಶೂನ್ಯ)
{
    printf("user definition test\n");
    ಪ್ರತಿಜ್ಞಾ(etext() + edata() + end() == 6);
}

/* ------------------------------------------------------ */
#ನೋಚೇದ್ಯದಿ TEST-SO == 4
unsigned ವರ್ಣ copy_reloc_data[257];

#ನೋಚೇದ್ಯದಿ TEST-MAIN == 4
ಬಾಹ್ಯ unsigned ವರ್ಣ copy_reloc_data[257];
ಬಾಹ್ಯ ವರ್ಣ end[], _end[];

ಪೂರ್ಣಾಙ್ಕ main(ಶೂನ್ಯ)
{
    unsigned long data_end;
    printf("end copy relocation test\n");
    copy_reloc_data[256] = 42;
    data_end = (unsigned long)(copy_reloc_data + ಪರಿಮಾಣ copy_reloc_data);
    ಪ್ರತಿಜ್ಞಾ(end == _end);
    ಪ್ರತಿಜ್ಞಾ((unsigned long)end >= data_end);
    ಪ್ರತಿಜ್ಞಾ(copy_reloc_data[256] == 42);
}

/* ------------------------------------------------------ */
#ನೋಚೇದ್ಯದಿ TEST-O == 5
ಶೂನ್ಯ __attribute__((section(".text.linker_test"), noinline, used))
linker_test_text(ಶೂನ್ಯ)
{
}
__attribute__((section(".bss.linker_test"), used))
unsigned ವರ್ಣ linker_test_bss[257];

__attribute__((section(".data.linker_test"), used))
unsigned ವರ್ಣ linker_test_data[23] = { 1 };

#ನೋಚೇದ್ಯದಿ TEST-MAIN == 5
ಬಾಹ್ಯ ಶೂನ್ಯ linker_test_text(ಶೂನ್ಯ);
ಬಾಹ್ಯ unsigned ವರ್ಣ linker_test_data[23];
ಬಾಹ್ಯ unsigned ವರ್ಣ linker_test_bss[257];
ಬಾಹ್ಯ ವರ್ಣ etext[], _etext[];
ಬಾಹ್ಯ ವರ್ಣ edata[], _edata[];
ಬಾಹ್ಯ ವರ್ಣ end[], _end[];

ಪೂರ್ಣಾಙ್ಕ main(ಶೂನ್ಯ)
{
    ವರ್ಣ* text_addr = (ಶೂನ್ಯ*)linker_test_text;
    ವರ್ಣ* data_end = linker_test_data + ಪರಿಮಾಣ linker_test_data;
    ವರ್ಣ* bss_end = linker_test_bss + ಪರಿಮಾಣ linker_test_bss;

    printf("linker boundary test\n");
    linker_test_data[22] = 42;
    linker_test_bss[256] = 42;
    ಪ್ರತಿಜ್ಞಾ(linker_test_bss > linker_test_data);
    ಪ್ರತಿಜ್ಞಾ(etext == _etext);
    ಪ್ರತಿಜ್ಞಾ(edata == _edata);
    ಪ್ರತಿಜ್ಞಾ(end == _end);
    ಪ್ರತಿಜ್ಞಾ(etext >= text_addr);
    ಪ್ರತಿಜ್ಞಾ(edata >= data_end);
    ಪ್ರತಿಜ್ಞಾ(end >= bss_end);
    ಪ್ರತಿಜ್ಞಾ(linker_test_data[22] == 42);
    ಪ್ರತಿಜ್ಞಾ(linker_test_bss[256] == 42);
}

/* ------------------------------------------------------ */
#ನೋಚೇದ್ಯದಿ TEST-SO == 6
ಪೂರ್ಣಾಙ್ಕ end;
ಪೂರ್ಣಾಙ್ಕ eight = 8;
ಪೂರ್ಣಾಙ್ಕ nine;
ಪೂರ್ಣಾಙ್ಕ dso_add() { ಪ್ರತ್ಯಾಗಮ end + eight + nine; }

#ನೋಚೇದ್ಯದಿ TEST-MAIN == 6
ಪೂರ್ಣಾಙ್ಕ end = 7;
ಪೂರ್ಣಾಙ್ಕ eight;
ಪೂರ್ಣಾಙ್ಕ nine = 9;
ಪೂರ್ಣಾಙ್ಕ dso_add();
ಪೂರ್ಣಾಙ್ಕ main()
{
    ಪೂರ್ಣಾಙ್ಕ sum;
    printf("DSO initialized data test\n");
    sum = dso_add();
    ಪ್ರತಿಜ್ಞಾ(end == 7);
    ಪ್ರತಿಜ್ಞಾ(eight == 8);
    ಪ್ರತಿಜ್ಞಾ(nine == 9);
    ಪ್ರತಿಜ್ಞಾ(sum == 24) || printf("-- %d + %d + %d = %d\n", end, eight, nine, sum);
}

/* ------------------------------------------------------ */
#endif
