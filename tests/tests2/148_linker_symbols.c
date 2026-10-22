পূর্ণাঙ্ক printf(ধ্রুৱ ৱর্ণ *, ...);

#define প্রতিজ্ঞা(x) ((x) \
    ? (printf(" 1 (%s)\n",#x),1) \
    : (printf("%s:%d: error: (%s)\n",__FILE__,__LINE__,#x),0))

#define O 100
#define SO 200

/* ------------------------------------------------------ */
#যদি TEST-O == 1
বাহ্য ৱর্ণ etext[], _etext[];
বাহ্য ৱর্ণ edata[], _edata[];
বাহ্য ৱর্ণ end[], _end[];
পূর্ণাঙ্ক check_linker_symbols(শূন্য)
{
    পূর্ণাঙ্ক errors = 0;
    errors += !প্রতিজ্ঞা(etext == _etext);
    errors += !প্রতিজ্ঞা(edata == _edata);
    errors += !প্রতিজ্ঞা(end == _end);
    ঘূৰাই errors;
}

#নোচেদ্যদি TEST-MAIN == 1
পূর্ণাঙ্ক check_linker_symbols(শূন্য);
পূর্ণাঙ্ক main(শূন্য)
{
    printf("linker symbols test\n");
    প্রতিজ্ঞা(check_linker_symbols() == 0);
}

/* ------------------------------------------------------ */
#নোচেদ্যদি TEST-SO == 2
বাহ্য ৱর্ণ etext[], edata[], end[];
শূন্য get_dso_end(ৱর্ণ **p)
{
    p[0] = etext;
    p[1] = edata;
    p[2] = end;
}

#নোচেদ্যদি TEST-MAIN == 2
বাহ্য ৱর্ণ _etext[], _edata[], _end[];
বাহ্য শূন্য get_dso_end(ৱর্ণ **);
স্থির পূর্ণাঙ্ক fill_data = 123;
স্থির পূর্ণাঙ্ক fill_bss;

পূর্ণাঙ্ক main(শূন্য)
{
    ৱর্ণ *p[3];
    printf("DSO linker symbols test\n");
    get_dso_end(p);
    প্রতিজ্ঞা(p[0] == _etext) || printf("-- %p %p\n", p[0], _etext);
    প্রতিজ্ঞা(p[1] == _edata) || printf("-- %p %p\n", p[1], _edata);
    প্রতিজ্ঞা(p[2] == _end)   || printf("-- %p %p\n", p[2], _end);
}

/* ------------------------------------------------------ */
#নোচেদ্যদি TEST-MAIN == 3

পূর্ণাঙ্ক etext(শূন্য) { ঘূৰাই 1; }
পূর্ণাঙ্ক edata(শূন্য) { ঘূৰাই 2; }
পূর্ণাঙ্ক end(শূন্য) { ঘূৰাই 3; }
পূর্ণাঙ্ক main(শূন্য)
{
    printf("user definition test\n");
    প্রতিজ্ঞা(etext() + edata() + end() == 6);
}

/* ------------------------------------------------------ */
#নোচেদ্যদি TEST-SO == 4
unsigned ৱর্ণ copy_reloc_data[257];

#নোচেদ্যদি TEST-MAIN == 4
বাহ্য unsigned ৱর্ণ copy_reloc_data[257];
বাহ্য ৱর্ণ end[], _end[];

পূর্ণাঙ্ক main(শূন্য)
{
    unsigned long data_end;
    printf("end copy relocation test\n");
    copy_reloc_data[256] = 42;
    data_end = (unsigned long)(copy_reloc_data + পরিমাণ copy_reloc_data);
    প্রতিজ্ঞা(end == _end);
    প্রতিজ্ঞা((unsigned long)end >= data_end);
    প্রতিজ্ঞা(copy_reloc_data[256] == 42);
}

/* ------------------------------------------------------ */
#নোচেদ্যদি TEST-O == 5
শূন্য __attribute__((section(".text.linker_test"), noinline, used))
linker_test_text(শূন্য)
{
}
__attribute__((section(".bss.linker_test"), used))
unsigned ৱর্ণ linker_test_bss[257];

__attribute__((section(".data.linker_test"), used))
unsigned ৱর্ণ linker_test_data[23] = { 1 };

#নোচেদ্যদি TEST-MAIN == 5
বাহ্য শূন্য linker_test_text(শূন্য);
বাহ্য unsigned ৱর্ণ linker_test_data[23];
বাহ্য unsigned ৱর্ণ linker_test_bss[257];
বাহ্য ৱর্ণ etext[], _etext[];
বাহ্য ৱর্ণ edata[], _edata[];
বাহ্য ৱর্ণ end[], _end[];

পূর্ণাঙ্ক main(শূন্য)
{
    ৱর্ণ* text_addr = (শূন্য*)linker_test_text;
    ৱর্ণ* data_end = linker_test_data + পরিমাণ linker_test_data;
    ৱর্ণ* bss_end = linker_test_bss + পরিমাণ linker_test_bss;

    printf("linker boundary test\n");
    linker_test_data[22] = 42;
    linker_test_bss[256] = 42;
    প্রতিজ্ঞা(linker_test_bss > linker_test_data);
    প্রতিজ্ঞা(etext == _etext);
    প্রতিজ্ঞা(edata == _edata);
    প্রতিজ্ঞা(end == _end);
    প্রতিজ্ঞা(etext >= text_addr);
    প্রতিজ্ঞা(edata >= data_end);
    প্রতিজ্ঞা(end >= bss_end);
    প্রতিজ্ঞা(linker_test_data[22] == 42);
    প্রতিজ্ঞা(linker_test_bss[256] == 42);
}

/* ------------------------------------------------------ */
#নোচেদ্যদি TEST-SO == 6
পূর্ণাঙ্ক end;
পূর্ণাঙ্ক eight = 8;
পূর্ণাঙ্ক nine;
পূর্ণাঙ্ক dso_add() { ঘূৰাই end + eight + nine; }

#নোচেদ্যদি TEST-MAIN == 6
পূর্ণাঙ্ক end = 7;
পূর্ণাঙ্ক eight;
পূর্ণাঙ্ক nine = 9;
পূর্ণাঙ্ক dso_add();
পূর্ণাঙ্ক main()
{
    পূর্ণাঙ্ক sum;
    printf("DSO initialized data test\n");
    sum = dso_add();
    প্রতিজ্ঞা(end == 7);
    প্রতিজ্ঞা(eight == 8);
    প্রতিজ্ঞা(nine == 9);
    প্রতিজ্ঞা(sum == 24) || printf("-- %d + %d + %d = %d\n", end, eight, nine, sum);
}

/* ------------------------------------------------------ */
#endif
