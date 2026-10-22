പൂർണ്ണസംഖ്യ printf(സ്ഥിരം അക്ഷരം *, ...);

#define പ്രതിജ്ഞാ(x) ((x) \
    ? (printf(" 1 (%s)\n",#x),1) \
    : (printf("%s:%d: error: (%s)\n",__FILE__,__LINE__,#x),0))

#define O 100
#define SO 200

/* ------------------------------------------------------ */
#എങ്കിൽ TEST-O == 1
ബാഹ്യ അക്ഷരം etext[], _etext[];
ബാഹ്യ അക്ഷരം edata[], _edata[];
ബാഹ്യ അക്ഷരം end[], _end[];
പൂർണ്ണസംഖ്യ check_linker_symbols(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ errors = 0;
    errors += !പ്രതിജ്ഞാ(etext == _etext);
    errors += !പ്രതിജ്ഞാ(edata == _edata);
    errors += !പ്രതിജ്ഞാ(end == _end);
    തിരികെ errors;
}

#അല്ലെങ്കിലെങ്കിൽ TEST-MAIN == 1
പൂർണ്ണസംഖ്യ check_linker_symbols(ശൂന്യം);
പൂർണ്ണസംഖ്യ പ്രധാന(ശൂന്യം)
{
    printf("linker symbols test\n");
    പ്രതിജ്ഞാ(check_linker_symbols() == 0);
}

/* ------------------------------------------------------ */
#അല്ലെങ്കിലെങ്കിൽ TEST-SO == 2
ബാഹ്യ അക്ഷരം etext[], edata[], end[];
ശൂന്യം get_dso_end(അക്ഷരം **p)
{
    p[0] = etext;
    p[1] = edata;
    p[2] = end;
}

#അല്ലെങ്കിലെങ്കിൽ TEST-MAIN == 2
ബാഹ്യ അക്ഷരം _etext[], _edata[], _end[];
ബാഹ്യ ശൂന്യം get_dso_end(അക്ഷരം **);
സ്ഥിതം പൂർണ്ണസംഖ്യ fill_data = 123;
സ്ഥിതം പൂർണ്ണസംഖ്യ fill_bss;

പൂർണ്ണസംഖ്യ പ്രധാന(ശൂന്യം)
{
    അക്ഷരം *p[3];
    printf("DSO linker symbols test\n");
    get_dso_end(p);
    പ്രതിജ്ഞാ(p[0] == _etext) || printf("-- %p %p\n", p[0], _etext);
    പ്രതിജ്ഞാ(p[1] == _edata) || printf("-- %p %p\n", p[1], _edata);
    പ്രതിജ്ഞാ(p[2] == _end)   || printf("-- %p %p\n", p[2], _end);
}

/* ------------------------------------------------------ */
#അല്ലെങ്കിലെങ്കിൽ TEST-MAIN == 3

പൂർണ്ണസംഖ്യ etext(ശൂന്യം) { തിരികെ 1; }
പൂർണ്ണസംഖ്യ edata(ശൂന്യം) { തിരികെ 2; }
പൂർണ്ണസംഖ്യ end(ശൂന്യം) { തിരികെ 3; }
പൂർണ്ണസംഖ്യ പ്രധാന(ശൂന്യം)
{
    printf("user definition test\n");
    പ്രതിജ്ഞാ(etext() + edata() + end() == 6);
}

/* ------------------------------------------------------ */
#അല്ലെങ്കിലെങ്കിൽ TEST-SO == 4
unsigned അക്ഷരം copy_reloc_data[257];

#അല്ലെങ്കിലെങ്കിൽ TEST-MAIN == 4
ബാഹ്യ unsigned അക്ഷരം copy_reloc_data[257];
ബാഹ്യ അക്ഷരം end[], _end[];

പൂർണ്ണസംഖ്യ പ്രധാന(ശൂന്യം)
{
    unsigned long data_end;
    printf("end copy relocation test\n");
    copy_reloc_data[256] = 42;
    data_end = (unsigned long)(copy_reloc_data + വലുപ്പം copy_reloc_data);
    പ്രതിജ്ഞാ(end == _end);
    പ്രതിജ്ഞാ((unsigned long)end >= data_end);
    പ്രതിജ്ഞാ(copy_reloc_data[256] == 42);
}

/* ------------------------------------------------------ */
#അല്ലെങ്കിലെങ്കിൽ TEST-O == 5
ശൂന്യം __attribute__((section(".text.linker_test"), noinline, used))
linker_test_text(ശൂന്യം)
{
}
__attribute__((section(".bss.linker_test"), used))
unsigned അക്ഷരം linker_test_bss[257];

__attribute__((section(".data.linker_test"), used))
unsigned അക്ഷരം linker_test_data[23] = { 1 };

#അല്ലെങ്കിലെങ്കിൽ TEST-MAIN == 5
ബാഹ്യ ശൂന്യം linker_test_text(ശൂന്യം);
ബാഹ്യ unsigned അക്ഷരം linker_test_data[23];
ബാഹ്യ unsigned അക്ഷരം linker_test_bss[257];
ബാഹ്യ അക്ഷരം etext[], _etext[];
ബാഹ്യ അക്ഷരം edata[], _edata[];
ബാഹ്യ അക്ഷരം end[], _end[];

പൂർണ്ണസംഖ്യ പ്രധാന(ശൂന്യം)
{
    അക്ഷരം* text_addr = (ശൂന്യം*)linker_test_text;
    അക്ഷരം* data_end = linker_test_data + വലുപ്പം linker_test_data;
    അക്ഷരം* bss_end = linker_test_bss + വലുപ്പം linker_test_bss;

    printf("linker boundary test\n");
    linker_test_data[22] = 42;
    linker_test_bss[256] = 42;
    പ്രതിജ്ഞാ(linker_test_bss > linker_test_data);
    പ്രതിജ്ഞാ(etext == _etext);
    പ്രതിജ്ഞാ(edata == _edata);
    പ്രതിജ്ഞാ(end == _end);
    പ്രതിജ്ഞാ(etext >= text_addr);
    പ്രതിജ്ഞാ(edata >= data_end);
    പ്രതിജ്ഞാ(end >= bss_end);
    പ്രതിജ്ഞാ(linker_test_data[22] == 42);
    പ്രതിജ്ഞാ(linker_test_bss[256] == 42);
}

/* ------------------------------------------------------ */
#അല്ലെങ്കിലെങ്കിൽ TEST-SO == 6
പൂർണ്ണസംഖ്യ end;
പൂർണ്ണസംഖ്യ eight = 8;
പൂർണ്ണസംഖ്യ nine;
പൂർണ്ണസംഖ്യ dso_add() { തിരികെ end + eight + nine; }

#അല്ലെങ്കിലെങ്കിൽ TEST-MAIN == 6
പൂർണ്ണസംഖ്യ end = 7;
പൂർണ്ണസംഖ്യ eight;
പൂർണ്ണസംഖ്യ nine = 9;
പൂർണ്ണസംഖ്യ dso_add();
പൂർണ്ണസംഖ്യ പ്രധാന()
{
    പൂർണ്ണസംഖ്യ sum;
    printf("DSO initialized data test\n");
    sum = dso_add();
    പ്രതിജ്ഞാ(end == 7);
    പ്രതിജ്ഞാ(eight == 8);
    പ്രതിജ്ഞാ(nine == 9);
    പ്രതിജ്ഞാ(sum == 24) || printf("-- %d + %d + %d = %d\n", end, eight, nine, sum);
}

/* ------------------------------------------------------ */
#endif
