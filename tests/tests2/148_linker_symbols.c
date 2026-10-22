पूर्णाङ्क म_लिखो(अचर वर्ण *, ...);

#define प्रतिज्ञा(x) ((x) \
    ? (म_लिखो(" 1 (%s)\n",#x),1) \
    : (म_लिखो("%s:%d: error: (%s)\n",__FILE__,__LINE__,#x),0))

#define O 100
#define SO 200

/* ------------------------------------------------------ */
#यदि TEST-O == 1
बाह्य वर्ण etext[], _etext[];
बाह्य वर्ण edata[], _edata[];
बाह्य वर्ण end[], _end[];
पूर्णाङ्क check_linker_symbols(शून्य)
{
    पूर्णाङ्क errors = 0;
    errors += !प्रतिज्ञा(etext == _etext);
    errors += !प्रतिज्ञा(edata == _edata);
    errors += !प्रतिज्ञा(end == _end);
    फर्काऊ errors;
}

#अथवायदि TEST-MAIN == 1
पूर्णाङ्क check_linker_symbols(शून्य);
पूर्णाङ्क main(शून्य)
{
    म_लिखो("linker symbols test\n");
    प्रतिज्ञा(check_linker_symbols() == 0);
}

/* ------------------------------------------------------ */
#अथवायदि TEST-SO == 2
बाह्य वर्ण etext[], edata[], end[];
शून्य get_dso_end(वर्ण **p)
{
    p[0] = etext;
    p[1] = edata;
    p[2] = end;
}

#अथवायदि TEST-MAIN == 2
बाह्य वर्ण _etext[], _edata[], _end[];
बाह्य शून्य get_dso_end(वर्ण **);
स्थिर पूर्णाङ्क fill_data = 123;
स्थिर पूर्णाङ्क fill_bss;

पूर्णाङ्क main(शून्य)
{
    वर्ण *p[3];
    म_लिखो("DSO linker symbols test\n");
    get_dso_end(p);
    प्रतिज्ञा(p[0] == _etext) || म_लिखो("-- %p %p\n", p[0], _etext);
    प्रतिज्ञा(p[1] == _edata) || म_लिखो("-- %p %p\n", p[1], _edata);
    प्रतिज्ञा(p[2] == _end)   || म_लिखो("-- %p %p\n", p[2], _end);
}

/* ------------------------------------------------------ */
#अथवायदि TEST-MAIN == 3

पूर्णाङ्क etext(शून्य) { फर्काऊ 1; }
पूर्णाङ्क edata(शून्य) { फर्काऊ 2; }
पूर्णाङ्क end(शून्य) { फर्काऊ 3; }
पूर्णाङ्क main(शून्य)
{
    म_लिखो("user definition test\n");
    प्रतिज्ञा(etext() + edata() + end() == 6);
}

/* ------------------------------------------------------ */
#अथवायदि TEST-SO == 4
अचिन्हित वर्ण copy_reloc_data[257];

#अथवायदि TEST-MAIN == 4
बाह्य अचिन्हित वर्ण copy_reloc_data[257];
बाह्य वर्ण end[], _end[];

पूर्णाङ्क main(शून्य)
{
    अचिन्हित दीर्घ data_end;
    म_लिखो("end copy relocation test\n");
    copy_reloc_data[256] = 42;
    data_end = (अचिन्हित दीर्घ)(copy_reloc_data + परिमाण copy_reloc_data);
    प्रतिज्ञा(end == _end);
    प्रतिज्ञा((अचिन्हित दीर्घ)end >= data_end);
    प्रतिज्ञा(copy_reloc_data[256] == 42);
}

/* ------------------------------------------------------ */
#अथवायदि TEST-O == 5
शून्य __attribute__((section(".text.linker_test"), noinline, used))
linker_test_text(शून्य)
{
}
__attribute__((section(".bss.linker_test"), used))
अचिन्हित वर्ण linker_test_bss[257];

__attribute__((section(".data.linker_test"), used))
अचिन्हित वर्ण linker_test_data[23] = { 1 };

#अथवायदि TEST-MAIN == 5
बाह्य शून्य linker_test_text(शून्य);
बाह्य अचिन्हित वर्ण linker_test_data[23];
बाह्य अचिन्हित वर्ण linker_test_bss[257];
बाह्य वर्ण etext[], _etext[];
बाह्य वर्ण edata[], _edata[];
बाह्य वर्ण end[], _end[];

पूर्णाङ्क main(शून्य)
{
    वर्ण* text_addr = (शून्य*)linker_test_text;
    वर्ण* data_end = linker_test_data + परिमाण linker_test_data;
    वर्ण* bss_end = linker_test_bss + परिमाण linker_test_bss;

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
#अथवायदि TEST-SO == 6
पूर्णाङ्क end;
पूर्णाङ्क eight = 8;
पूर्णाङ्क nine;
पूर्णाङ्क dso_add() { फर्काऊ end + eight + nine; }

#अथवायदि TEST-MAIN == 6
पूर्णाङ्क end = 7;
पूर्णाङ्क eight;
पूर्णाङ्क nine = 9;
पूर्णाङ्क dso_add();
पूर्णाङ्क main()
{
    पूर्णाङ्क sum;
    म_लिखो("DSO initialized data test\n");
    sum = dso_add();
    प्रतिज्ञा(end == 7);
    प्रतिज्ञा(eight == 8);
    प्रतिज्ञा(nine == 9);
    प्रतिज्ञा(sum == 24) || म_लिखो("-- %d + %d + %d = %d\n", end, eight, nine, sum);
}

/* ------------------------------------------------------ */
#endif
