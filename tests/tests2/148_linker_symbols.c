पूर्णांक म_लिखो(स्थिरांक अक्षर *, ...);

#define प्रतिज्ञा(x) ((x) \
    ? (म_लिखो(" 1 (%s)\n",#x),1) \
    : (म_लिखो("%s:%d: error: (%s)\n",__FILE__,__LINE__,#x),0))

#define O 100
#define SO 200

/* ------------------------------------------------------ */
#जर TEST-O == 1
बाह्य अक्षर etext[], _etext[];
बाह्य अक्षर edata[], _edata[];
बाह्य अक्षर end[], _end[];
पूर्णांक check_linker_symbols(शून्य)
{
    पूर्णांक errors = 0;
    errors += !प्रतिज्ञा(etext == _etext);
    errors += !प्रतिज्ञा(edata == _edata);
    errors += !प्रतिज्ञा(end == _end);
    परत errors;
}

#किंवाजर TEST-MAIN == 1
पूर्णांक check_linker_symbols(शून्य);
पूर्णांक main(शून्य)
{
    म_लिखो("linker symbols test\n");
    प्रतिज्ञा(check_linker_symbols() == 0);
}

/* ------------------------------------------------------ */
#किंवाजर TEST-SO == 2
बाह्य अक्षर etext[], edata[], end[];
शून्य get_dso_end(अक्षर **p)
{
    p[0] = etext;
    p[1] = edata;
    p[2] = end;
}

#किंवाजर TEST-MAIN == 2
बाह्य अक्षर _etext[], _edata[], _end[];
बाह्य शून्य get_dso_end(अक्षर **);
स्थिर पूर्णांक fill_data = 123;
स्थिर पूर्णांक fill_bss;

पूर्णांक main(शून्य)
{
    अक्षर *p[3];
    म_लिखो("DSO linker symbols test\n");
    get_dso_end(p);
    प्रतिज्ञा(p[0] == _etext) || म_लिखो("-- %p %p\n", p[0], _etext);
    प्रतिज्ञा(p[1] == _edata) || म_लिखो("-- %p %p\n", p[1], _edata);
    प्रतिज्ञा(p[2] == _end)   || म_लिखो("-- %p %p\n", p[2], _end);
}

/* ------------------------------------------------------ */
#किंवाजर TEST-MAIN == 3

पूर्णांक etext(शून्य) { परत 1; }
पूर्णांक edata(शून्य) { परत 2; }
पूर्णांक end(शून्य) { परत 3; }
पूर्णांक main(शून्य)
{
    म_लिखो("user definition test\n");
    प्रतिज्ञा(etext() + edata() + end() == 6);
}

/* ------------------------------------------------------ */
#किंवाजर TEST-SO == 4
अचिन्हित अक्षर copy_reloc_data[257];

#किंवाजर TEST-MAIN == 4
बाह्य अचिन्हित अक्षर copy_reloc_data[257];
बाह्य अक्षर end[], _end[];

पूर्णांक main(शून्य)
{
    अचिन्हित दीर्घ data_end;
    म_लिखो("end copy relocation test\n");
    copy_reloc_data[256] = 42;
    data_end = (अचिन्हित दीर्घ)(copy_reloc_data + आकार copy_reloc_data);
    प्रतिज्ञा(end == _end);
    प्रतिज्ञा((अचिन्हित दीर्घ)end >= data_end);
    प्रतिज्ञा(copy_reloc_data[256] == 42);
}

/* ------------------------------------------------------ */
#किंवाजर TEST-O == 5
शून्य __attribute__((section(".text.linker_test"), noinline, used))
linker_test_text(शून्य)
{
}
__attribute__((section(".bss.linker_test"), used))
अचिन्हित अक्षर linker_test_bss[257];

__attribute__((section(".data.linker_test"), used))
अचिन्हित अक्षर linker_test_data[23] = { 1 };

#किंवाजर TEST-MAIN == 5
बाह्य शून्य linker_test_text(शून्य);
बाह्य अचिन्हित अक्षर linker_test_data[23];
बाह्य अचिन्हित अक्षर linker_test_bss[257];
बाह्य अक्षर etext[], _etext[];
बाह्य अक्षर edata[], _edata[];
बाह्य अक्षर end[], _end[];

पूर्णांक main(शून्य)
{
    अक्षर* text_addr = (शून्य*)linker_test_text;
    अक्षर* data_end = linker_test_data + आकार linker_test_data;
    अक्षर* bss_end = linker_test_bss + आकार linker_test_bss;

    म_लिखो("linker boundary test\n");
    linker_test_data[22] = 42;
    linker_test_bss[256] = 42;
    प्रतिज्ञा(linker_test_bss > linker_test_data);
    प्रतिज्ञा(etext == _etext);
    प्रतिज्ञा(edata == _edata);
    प्रतिज्ञा(end == _end);
    प्रतिज्ञा(etext >= text_addr);
    प्रतिज्ञा(edata >= data_end);
    प्रतिज्ञा(end >= bss_end);
    प्रतिज्ञा(linker_test_data[22] == 42);
    प्रतिज्ञा(linker_test_bss[256] == 42);
}

/* ------------------------------------------------------ */
#किंवाजर TEST-SO == 6
पूर्णांक end;
पूर्णांक eight = 8;
पूर्णांक nine;
पूर्णांक dso_add() { परत end + eight + nine; }

#किंवाजर TEST-MAIN == 6
पूर्णांक end = 7;
पूर्णांक eight;
पूर्णांक nine = 9;
पूर्णांक dso_add();
पूर्णांक main()
{
    पूर्णांक sum;
    म_लिखो("DSO initialized data test\n");
    sum = dso_add();
    प्रतिज्ञा(end == 7);
    प्रतिज्ञा(eight == 8);
    प्रतिज्ञा(nine == 9);
    प्रतिज्ञा(sum == 24) || म_लिखो("-- %d + %d + %d = %d\n", end, eight, nine, sum);
}

/* ------------------------------------------------------ */
#endif
