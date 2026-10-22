صحیح printf(ثابت نویسه *, ...);

#define أكد(x) ((x) \
    ? (printf(" 1 (%s)\n",#x),1) \
    : (printf("%s:%d: error: (%s)\n",__FILE__,__LINE__,#x),0))

#define O 100
#define SO 200

/* ------------------------------------------------------ */
#اگر TEST-O == 1
بیرونی نویسه etext[], _etext[];
بیرونی نویسه edata[], _edata[];
بیرونی نویسه end[], _end[];
صحیح check_linker_symbols(تهی)
{
    صحیح errors = 0;
    errors += !أكد(etext == _etext);
    errors += !أكد(edata == _edata);
    errors += !أكد(end == _end);
    بازگشت errors;
}

#وگرنهاگر TEST-MAIN == 1
صحیح check_linker_symbols(تهی);
صحیح اصلی(تهی)
{
    printf("linker symbols test\n");
    أكد(check_linker_symbols() == 0);
}

/* ------------------------------------------------------ */
#وگرنهاگر TEST-SO == 2
بیرونی نویسه etext[], edata[], end[];
تهی get_dso_end(نویسه **p)
{
    p[0] = etext;
    p[1] = edata;
    p[2] = end;
}

#وگرنهاگر TEST-MAIN == 2
بیرونی نویسه _etext[], _edata[], _end[];
بیرونی تهی get_dso_end(نویسه **);
ایستا صحیح fill_data = 123;
ایستا صحیح fill_bss;

صحیح اصلی(تهی)
{
    نویسه *p[3];
    printf("DSO linker symbols test\n");
    get_dso_end(p);
    أكد(p[0] == _etext) || printf("-- %p %p\n", p[0], _etext);
    أكد(p[1] == _edata) || printf("-- %p %p\n", p[1], _edata);
    أكد(p[2] == _end)   || printf("-- %p %p\n", p[2], _end);
}

/* ------------------------------------------------------ */
#وگرنهاگر TEST-MAIN == 3

صحیح etext(تهی) { بازگشت 1; }
صحیح edata(تهی) { بازگشت 2; }
صحیح end(تهی) { بازگشت 3; }
صحیح اصلی(تهی)
{
    printf("user definition test\n");
    أكد(etext() + edata() + end() == 6);
}

/* ------------------------------------------------------ */
#وگرنهاگر TEST-SO == 4
unsigned نویسه copy_reloc_data[257];

#وگرنهاگر TEST-MAIN == 4
بیرونی unsigned نویسه copy_reloc_data[257];
بیرونی نویسه end[], _end[];

صحیح اصلی(تهی)
{
    unsigned long data_end;
    printf("end copy relocation test\n");
    copy_reloc_data[256] = 42;
    data_end = (unsigned long)(copy_reloc_data + اندازه copy_reloc_data);
    أكد(end == _end);
    أكد((unsigned long)end >= data_end);
    أكد(copy_reloc_data[256] == 42);
}

/* ------------------------------------------------------ */
#وگرنهاگر TEST-O == 5
تهی __attribute__((section(".text.linker_test"), noinline, used))
linker_test_text(تهی)
{
}
__attribute__((section(".bss.linker_test"), used))
unsigned نویسه linker_test_bss[257];

__attribute__((section(".data.linker_test"), used))
unsigned نویسه linker_test_data[23] = { 1 };

#وگرنهاگر TEST-MAIN == 5
بیرونی تهی linker_test_text(تهی);
بیرونی unsigned نویسه linker_test_data[23];
بیرونی unsigned نویسه linker_test_bss[257];
بیرونی نویسه etext[], _etext[];
بیرونی نویسه edata[], _edata[];
بیرونی نویسه end[], _end[];

صحیح اصلی(تهی)
{
    نویسه* text_addr = (تهی*)linker_test_text;
    نویسه* data_end = linker_test_data + اندازه linker_test_data;
    نویسه* bss_end = linker_test_bss + اندازه linker_test_bss;

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
#وگرنهاگر TEST-SO == 6
صحیح end;
صحیح eight = 8;
صحیح nine;
صحیح dso_add() { بازگشت end + eight + nine; }

#وگرنهاگر TEST-MAIN == 6
صحیح end = 7;
صحیح eight;
صحیح nine = 9;
صحیح dso_add();
صحیح اصلی()
{
    صحیح sum;
    printf("DSO initialized data test\n");
    sum = dso_add();
    أكد(end == 7);
    أكد(eight == 8);
    أكد(nine == 9);
    أكد(sum == 24) || printf("-- %d + %d + %d = %d\n", end, eight, nine, sum);
}

/* ------------------------------------------------------ */
#endif
