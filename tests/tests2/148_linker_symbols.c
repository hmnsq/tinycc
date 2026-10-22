পূর্ণসংখ্যা printf(ধ্রুবক অক্ষর *, ...);

#define প্রতিজ্ঞা(x) ((x) \
    ? (printf(" 1 (%s)\n",#x),1) \
    : (printf("%s:%d: error: (%s)\n",__FILE__,__LINE__,#x),0))

#define O 100
#define SO 200

/* ------------------------------------------------------ */
#যদি TEST-O == 1
বাহ্যিক অক্ষর etext[], _etext[];
বাহ্যিক অক্ষর edata[], _edata[];
বাহ্যিক অক্ষর end[], _end[];
পূর্ণসংখ্যা check_linker_symbols(শূন্য)
{
    পূর্ণসংখ্যা errors = 0;
    errors += !প্রতিজ্ঞা(etext == _etext);
    errors += !প্রতিজ্ঞা(edata == _edata);
    errors += !প্রতিজ্ঞা(end == _end);
    ফেরত errors;
}

#নতুবা_যদি TEST-MAIN == 1
পূর্ণসংখ্যা check_linker_symbols(শূন্য);
পূর্ণসংখ্যা প্রধান(শূন্য)
{
    printf("linker symbols test\n");
    প্রতিজ্ঞা(check_linker_symbols() == 0);
}

/* ------------------------------------------------------ */
#নতুবা_যদি TEST-SO == 2
বাহ্যিক অক্ষর etext[], edata[], end[];
শূন্য get_dso_end(অক্ষর **p)
{
    p[0] = etext;
    p[1] = edata;
    p[2] = end;
}

#নতুবা_যদি TEST-MAIN == 2
বাহ্যিক অক্ষর _etext[], _edata[], _end[];
বাহ্যিক শূন্য get_dso_end(অক্ষর **);
স্থির পূর্ণসংখ্যা fill_তথ্য = 123;
স্থির পূর্ণসংখ্যা fill_bss;

পূর্ণসংখ্যা প্রধান(শূন্য)
{
    অক্ষর *p[3];
    printf("DSO linker symbols test\n");
    get_dso_end(p);
    প্রতিজ্ঞা(p[0] == _etext) || printf("-- %p %p\n", p[0], _etext);
    প্রতিজ্ঞা(p[1] == _edata) || printf("-- %p %p\n", p[1], _edata);
    প্রতিজ্ঞা(p[2] == _end)   || printf("-- %p %p\n", p[2], _end);
}

/* ------------------------------------------------------ */
#নতুবা_যদি TEST-MAIN == 3

পূর্ণসংখ্যা etext(শূন্য) { ফেরত 1; }
পূর্ণসংখ্যা edata(শূন্য) { ফেরত 2; }
পূর্ণসংখ্যা end(শূন্য) { ফেরত 3; }
পূর্ণসংখ্যা প্রধান(শূন্য)
{
    printf("user definition test\n");
    প্রতিজ্ঞা(etext() + edata() + end() == 6);
}

/* ------------------------------------------------------ */
#নতুবা_যদি TEST-SO == 4
unsigned অক্ষর copy_reloc_তথ্য[257];

#নতুবা_যদি TEST-MAIN == 4
বাহ্যিক unsigned অক্ষর copy_reloc_তথ্য[257];
বাহ্যিক অক্ষর end[], _end[];

পূর্ণসংখ্যা প্রধান(শূন্য)
{
    unsigned long তথ্য_end;
    printf("end copy relocation test\n");
    copy_reloc_তথ্য[256] = 42;
    তথ্য_end = (unsigned long)(copy_reloc_তথ্য + আকার copy_reloc_তথ্য);
    প্রতিজ্ঞা(end == _end);
    প্রতিজ্ঞা((unsigned long)end >= তথ্য_end);
    প্রতিজ্ঞা(copy_reloc_তথ্য[256] == 42);
}

/* ------------------------------------------------------ */
#নতুবা_যদি TEST-O == 5
শূন্য __attribute__((section(".text.linker_test"), noinline, used))
linker_test_text(শূন্য)
{
}
__attribute__((section(".bss.linker_test"), used))
unsigned অক্ষর linker_test_bss[257];

__attribute__((section(".data.linker_test"), used))
unsigned অক্ষর linker_test_তথ্য[23] = { 1 };

#নতুবা_যদি TEST-MAIN == 5
বাহ্যিক শূন্য linker_test_text(শূন্য);
বাহ্যিক unsigned অক্ষর linker_test_তথ্য[23];
বাহ্যিক unsigned অক্ষর linker_test_bss[257];
বাহ্যিক অক্ষর etext[], _etext[];
বাহ্যিক অক্ষর edata[], _edata[];
বাহ্যিক অক্ষর end[], _end[];

পূর্ণসংখ্যা প্রধান(শূন্য)
{
    অক্ষর* text_addr = (শূন্য*)linker_test_text;
    অক্ষর* তথ্য_end = linker_test_তথ্য + আকার linker_test_তথ্য;
    অক্ষর* bss_end = linker_test_bss + আকার linker_test_bss;

    printf("linker boundary test\n");
    linker_test_তথ্য[22] = 42;
    linker_test_bss[256] = 42;
    প্রতিজ্ঞা(linker_test_bss > linker_test_তথ্য);
    প্রতিজ্ঞা(etext == _etext);
    প্রতিজ্ঞা(edata == _edata);
    প্রতিজ্ঞা(end == _end);
    প্রতিজ্ঞা(etext >= text_addr);
    প্রতিজ্ঞা(edata >= তথ্য_end);
    প্রতিজ্ঞা(end >= bss_end);
    প্রতিজ্ঞা(linker_test_তথ্য[22] == 42);
    প্রতিজ্ঞা(linker_test_bss[256] == 42);
}

/* ------------------------------------------------------ */
#নতুবা_যদি TEST-SO == 6
পূর্ণসংখ্যা end;
পূর্ণসংখ্যা eight = 8;
পূর্ণসংখ্যা nine;
পূর্ণসংখ্যা dso_add() { ফেরত end + eight + nine; }

#নতুবা_যদি TEST-MAIN == 6
পূর্ণসংখ্যা end = 7;
পূর্ণসংখ্যা eight;
পূর্ণসংখ্যা nine = 9;
পূর্ণসংখ্যা dso_add();
পূর্ণসংখ্যা প্রধান()
{
    পূর্ণসংখ্যা যোগ;
    printf("DSO initialized data test\n");
    যোগ = dso_add();
    প্রতিজ্ঞা(end == 7);
    প্রতিজ্ঞা(eight == 8);
    প্রতিজ্ঞা(nine == 9);
    প্রতিজ্ঞা(যোগ == 24) || printf("-- %d + %d + %d = %d\n", end, eight, nine, যোগ);
}

/* ------------------------------------------------------ */
#endif
