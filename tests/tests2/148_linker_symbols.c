முழு printf(மாறிலி எழுத்து *, ...);

#define ப்ரதிஜ்ஞா(x) ((x) \
    ? (printf(" 1 (%s)\n",#x),1) \
    : (printf("%s:%d: error: (%s)\n",__FILE__,__LINE__,#x),0))

#define O 100
#define SO 200

/* ------------------------------------------------------ */
#எனில் TEST-O == 1
வெளி எழுத்து etext[], _etext[];
வெளி எழுத்து edata[], _edata[];
வெளி எழுத்து end[], _end[];
முழு check_linker_symbols(வெறுமை)
{
    முழு errors = 0;
    errors += !ப்ரதிஜ்ஞா(etext == _etext);
    errors += !ப்ரதிஜ்ஞா(edata == _edata);
    errors += !ப்ரதிஜ்ஞா(end == _end);
    திரும்பு errors;
}

#அல்லதெனில் TEST-MAIN == 1
முழு check_linker_symbols(வெறுமை);
முழு முதன்மை(வெறுமை)
{
    printf("linker symbols test\n");
    ப்ரதிஜ்ஞா(check_linker_symbols() == 0);
}

/* ------------------------------------------------------ */
#அல்லதெனில் TEST-SO == 2
வெளி எழுத்து etext[], edata[], end[];
வெறுமை get_dso_end(எழுத்து **p)
{
    p[0] = etext;
    p[1] = edata;
    p[2] = end;
}

#அல்லதெனில் TEST-MAIN == 2
வெளி எழுத்து _etext[], _edata[], _end[];
வெளி வெறுமை get_dso_end(எழுத்து **);
நிலையான முழு fill_data = 123;
நிலையான முழு fill_bss;

முழு முதன்மை(வெறுமை)
{
    எழுத்து *p[3];
    printf("DSO linker symbols test\n");
    get_dso_end(p);
    ப்ரதிஜ்ஞா(p[0] == _etext) || printf("-- %p %p\n", p[0], _etext);
    ப்ரதிஜ்ஞா(p[1] == _edata) || printf("-- %p %p\n", p[1], _edata);
    ப்ரதிஜ்ஞா(p[2] == _end)   || printf("-- %p %p\n", p[2], _end);
}

/* ------------------------------------------------------ */
#அல்லதெனில் TEST-MAIN == 3

முழு etext(வெறுமை) { திரும்பு 1; }
முழு edata(வெறுமை) { திரும்பு 2; }
முழு end(வெறுமை) { திரும்பு 3; }
முழு முதன்மை(வெறுமை)
{
    printf("user definition test\n");
    ப்ரதிஜ்ஞா(etext() + edata() + end() == 6);
}

/* ------------------------------------------------------ */
#அல்லதெனில் TEST-SO == 4
unsigned எழுத்து copy_reloc_data[257];

#அல்லதெனில் TEST-MAIN == 4
வெளி unsigned எழுத்து copy_reloc_data[257];
வெளி எழுத்து end[], _end[];

முழு முதன்மை(வெறுமை)
{
    unsigned long data_end;
    printf("end copy relocation test\n");
    copy_reloc_data[256] = 42;
    data_end = (unsigned long)(copy_reloc_data + அளவு copy_reloc_data);
    ப்ரதிஜ்ஞா(end == _end);
    ப்ரதிஜ்ஞா((unsigned long)end >= data_end);
    ப்ரதிஜ்ஞா(copy_reloc_data[256] == 42);
}

/* ------------------------------------------------------ */
#அல்லதெனில் TEST-O == 5
வெறுமை __attribute__((section(".text.linker_test"), noinline, used))
linker_test_text(வெறுமை)
{
}
__attribute__((section(".bss.linker_test"), used))
unsigned எழுத்து linker_test_bss[257];

__attribute__((section(".data.linker_test"), used))
unsigned எழுத்து linker_test_data[23] = { 1 };

#அல்லதெனில் TEST-MAIN == 5
வெளி வெறுமை linker_test_text(வெறுமை);
வெளி unsigned எழுத்து linker_test_data[23];
வெளி unsigned எழுத்து linker_test_bss[257];
வெளி எழுத்து etext[], _etext[];
வெளி எழுத்து edata[], _edata[];
வெளி எழுத்து end[], _end[];

முழு முதன்மை(வெறுமை)
{
    எழுத்து* text_addr = (வெறுமை*)linker_test_text;
    எழுத்து* data_end = linker_test_data + அளவு linker_test_data;
    எழுத்து* bss_end = linker_test_bss + அளவு linker_test_bss;

    printf("linker boundary test\n");
    linker_test_data[22] = 42;
    linker_test_bss[256] = 42;
    ப்ரதிஜ்ஞா(linker_test_bss > linker_test_data);
    ப்ரதிஜ்ஞா(etext == _etext);
    ப்ரதிஜ்ஞா(edata == _edata);
    ப்ரதிஜ்ஞா(end == _end);
    ப்ரதிஜ்ஞா(etext >= text_addr);
    ப்ரதிஜ்ஞா(edata >= data_end);
    ப்ரதிஜ்ஞா(end >= bss_end);
    ப்ரதிஜ்ஞா(linker_test_data[22] == 42);
    ப்ரதிஜ்ஞா(linker_test_bss[256] == 42);
}

/* ------------------------------------------------------ */
#அல்லதெனில் TEST-SO == 6
முழு end;
முழு eight = 8;
முழு nine;
முழு dso_add() { திரும்பு end + eight + nine; }

#அல்லதெனில் TEST-MAIN == 6
முழு end = 7;
முழு eight;
முழு nine = 9;
முழு dso_add();
முழு முதன்மை()
{
    முழு sum;
    printf("DSO initialized data test\n");
    sum = dso_add();
    ப்ரதிஜ்ஞா(end == 7);
    ப்ரதிஜ்ஞா(eight == 8);
    ப்ரதிஜ்ஞா(nine == 9);
    ப்ரதிஜ்ஞா(sum == 24) || printf("-- %d + %d + %d = %d\n", end, eight, nine, sum);
}

/* ------------------------------------------------------ */
#endif
