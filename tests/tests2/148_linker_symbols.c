पूर्णांक म_लिखो(स्थिर अक्षर *, ...);

#घोषणा निश्चित(x) ((x) \
    ? (म_लिखो(" 1 (%s)\n",#x),1) \
    : (म_लिखो("%s:%d: error: (%s)\n",__खाता__,__LINE__,#x),0))

#घोषणा O 100
#घोषणा SO 200

/* ------------------------------------------------------ */
#अगर TEST-O == 1
बाह्य अक्षर etext[], _etext[];
बाह्य अक्षर edata[], _edata[];
बाह्य अक्षर end[], _end[];
पूर्णांक check_linker_symbols(व्योम)
{
    पूर्णांक errors = 0;
    errors += !निश्चित(etext == _etext);
    errors += !निश्चित(edata == _edata);
    errors += !निश्चित(end == _end);
    वापस errors;
}

#या_अगर TEST-MAIN == 1
पूर्णांक check_linker_symbols(व्योम);
पूर्णांक मुख्य(व्योम)
{
    म_लिखो("linker symbols test\n");
    निश्चित(check_linker_symbols() == 0);
}

/* ------------------------------------------------------ */
#या_अगर TEST-SO == 2
बाह्य अक्षर etext[], edata[], end[];
व्योम get_dso_end(अक्षर **p)
{
    p[0] = etext;
    p[1] = edata;
    p[2] = end;
}

#या_अगर TEST-MAIN == 2
बाह्य अक्षर _etext[], _edata[], _end[];
बाह्य व्योम get_dso_end(अक्षर **);
अटल पूर्णांक fill_तथ्य = 123;
अटल पूर्णांक fill_bss;

पूर्णांक मुख्य(व्योम)
{
    अक्षर *p[3];
    म_लिखो("DSO linker symbols test\n");
    get_dso_end(p);
    निश्चित(p[0] == _etext) || म_लिखो("-- %p %p\n", p[0], _etext);
    निश्चित(p[1] == _edata) || म_लिखो("-- %p %p\n", p[1], _edata);
    निश्चित(p[2] == _end)   || म_लिखो("-- %p %p\n", p[2], _end);
}

/* ------------------------------------------------------ */
#या_अगर TEST-MAIN == 3

पूर्णांक etext(व्योम) { वापस 1; }
पूर्णांक edata(व्योम) { वापस 2; }
पूर्णांक end(व्योम) { वापस 3; }
पूर्णांक मुख्य(व्योम)
{
    म_लिखो("user definition test\n");
    निश्चित(etext() + edata() + end() == 6);
}

/* ------------------------------------------------------ */
#या_अगर TEST-SO == 4
अचिन्हित अक्षर copy_reloc_तथ्य[257];

#या_अगर TEST-MAIN == 4
बाह्य अचिन्हित अक्षर copy_reloc_तथ्य[257];
बाह्य अक्षर end[], _end[];

पूर्णांक मुख्य(व्योम)
{
    अचिन्हित दीर्घ तथ्य_end;
    म_लिखो("end copy relocation test\n");
    copy_reloc_तथ्य[256] = 42;
    तथ्य_end = (अचिन्हित दीर्घ)(copy_reloc_तथ्य + माप copy_reloc_तथ्य);
    निश्चित(end == _end);
    निश्चित((अचिन्हित दीर्घ)end >= तथ्य_end);
    निश्चित(copy_reloc_तथ्य[256] == 42);
}

/* ------------------------------------------------------ */
#या_अगर TEST-O == 5
व्योम __attribute__((section(".text.linker_test"), noinline, used))
linker_test_text(व्योम)
{
}
__attribute__((section(".bss.linker_test"), used))
अचिन्हित अक्षर linker_test_bss[257];

__attribute__((section(".data.linker_test"), used))
अचिन्हित अक्षर linker_test_तथ्य[23] = { 1 };

#या_अगर TEST-MAIN == 5
बाह्य व्योम linker_test_text(व्योम);
बाह्य अचिन्हित अक्षर linker_test_तथ्य[23];
बाह्य अचिन्हित अक्षर linker_test_bss[257];
बाह्य अक्षर etext[], _etext[];
बाह्य अक्षर edata[], _edata[];
बाह्य अक्षर end[], _end[];

पूर्णांक मुख्य(व्योम)
{
    अक्षर* text_addr = (व्योम*)linker_test_text;
    अक्षर* तथ्य_end = linker_test_तथ्य + माप linker_test_तथ्य;
    अक्षर* bss_end = linker_test_bss + माप linker_test_bss;

    म_लिखो("linker boundary test\n");
    linker_test_तथ्य[22] = 42;
    linker_test_bss[256] = 42;
    निश्चित(linker_test_bss > linker_test_तथ्य);
    निश्चित(etext == _etext);
    निश्चित(edata == _edata);
    निश्चित(end == _end);
    निश्चित(etext >= text_addr);
    निश्चित(edata >= तथ्य_end);
    निश्चित(end >= bss_end);
    निश्चित(linker_test_तथ्य[22] == 42);
    निश्चित(linker_test_bss[256] == 42);
}

/* ------------------------------------------------------ */
#या_अगर TEST-SO == 6
पूर्णांक end;
पूर्णांक eight = 8;
पूर्णांक nine;
पूर्णांक dso_add() { वापस end + eight + nine; }

#या_अगर TEST-MAIN == 6
पूर्णांक end = 7;
पूर्णांक eight;
पूर्णांक nine = 9;
पूर्णांक dso_add();
पूर्णांक मुख्य()
{
    पूर्णांक योग;
    म_लिखो("DSO initialized data test\n");
    योग = dso_add();
    निश्चित(end == 7);
    निश्चित(eight == 8);
    निश्चित(nine == 9);
    निश्चित(योग == 24) || म_लिखो("-- %d + %d + %d = %d\n", end, eight, nine, योग);
}

/* ------------------------------------------------------ */
#पूर्ण_अगर
