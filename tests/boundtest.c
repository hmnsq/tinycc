#समावेश <stdlib.h>
#समावेश <stdio.h>
#समावेश <string.h>

#घोषणा NB_ITS 1000000
//#define NB_ITS 1
#घोषणा TAB_आकार 100

पूर्णांक tab[TAB_आकार];
पूर्णांक ret_योग;
अक्षर tab3[256];

पूर्णांक test1(व्योम)
{
    पूर्णांक i, योग = 0;
    क्रम(i=0;i<TAB_आकार;i++) {
        योग += tab[i];
    }
    वापस योग;
}

/* error */
पूर्णांक test2(व्योम)
{
    पूर्णांक i, योग = 0;
    क्रम(i=0;i<TAB_आकार + 1;i++) {
        योग += tab[i];
    }
    वापस योग;
}

/* actually, profiling test */
पूर्णांक test3(व्योम)
{
    पूर्णांक योग;
    पूर्णांक i, it;

    योग = 0;
    क्रम(it=0;it<NB_ITS;it++) {
        क्रम(i=0;i<TAB_आकार;i++) {
            योग += tab[i];
        }
    }
    वापस योग;
}

/* ok */
पूर्णांक test4(व्योम)
{
    पूर्णांक i, योग = 0;
    पूर्णांक *tab4;

    tab4 = दो_स्मृति(20 * माप(पूर्णांक));
    क्रम(i=0;i<20;i++) {
        योग += tab4[i];
    }
    मुक्त(tab4);

    वापस योग;
}

/* error */
पूर्णांक test5(व्योम)
{
    पूर्णांक i, योग = 0;
    पूर्णांक *tab4;

    tab4 = दो_स्मृति(20 * माप(पूर्णांक));
    क्रम(i=0;i<21;i++) {
        योग += tab4[i];
    }
    मुक्त(tab4);

    वापस योग;
}

/* error */
पूर्णांक test6(व्योम)
{
    पूर्णांक i, योग = 0;
    पूर्णांक *tab4;
    
    tab4 = दो_स्मृति(20 * माप(पूर्णांक));
    मुक्त(tab4);
    क्रम(i=0;i<21;i++) {
        योग += tab4[i];
    }

    वापस योग;
}

/* error */
पूर्णांक test7(व्योम)
{
    पूर्णांक i, योग = 0;
    पूर्णांक *p;

    क्रम(i=0;i<TAB_आकार + 1;i++) {
        p = &tab[i];
        अगर (i == TAB_आकार)
            म_लिखो("i=%d %x\n", i, p);
        योग += *p;
    }
    वापस योग;
}

/* ok */
पूर्णांक test8(व्योम)
{
    पूर्णांक i, योग = 0;
    पूर्णांक tab[10];

    क्रम(i=0;i<10;i++) {
        योग += tab[i];
    }
    वापस योग;
}

/* error */
पूर्णांक test9(व्योम)
{
    पूर्णांक i, योग = 0;
    अक्षर tab[10];

    क्रम(i=0;i<11;i++) {
        योग += tab[i];
    }
    वापस योग;
}

/* ok */
पूर्णांक test10(व्योम)
{
    अक्षर tab[10];
    अक्षर tab1[10];

    स_रखो(tab, 0, 10);
    स_नकल(tab, tab1, 10);
    स_हटाओ(tab, tab1, 10);
    वापस 0;
}

/* error */
पूर्णांक test11(व्योम)
{
    अक्षर tab[10];

    स_रखो(tab, 0, 11);
    वापस 0;
}

/* error */
पूर्णांक test12(व्योम)
{
    व्योम *ptr;
    ptr = दो_स्मृति(10);
    मुक्त(ptr);
    मुक्त(ptr);
    वापस 0;
}

/* error */
पूर्णांक test13(व्योम)
{
    अक्षर pad1 = 0;
    अक्षर tab[10];
    अक्षर pad2 = 0;
    स_रखो(tab, 'a', माप(tab));
    वापस म_माप(tab);
}

पूर्णांक test14(व्योम)
{
    अक्षर *p = alloca(TAB_आकार);
    माप_प्रकार ret;
    स_रखो(p, 'a', TAB_आकार);
    p[TAB_आकार-1] = 0;
    ret = म_माप(p);
    वापस ret;
}

/* error */
पूर्णांक test15(व्योम)
{
    अक्षर *p = alloca(TAB_आकार-1);
    माप_प्रकार ret;
    स_रखो(p, 'a', TAB_आकार);
    p[TAB_आकार-1] = 0;
    ret = म_माप(p);
    वापस ret;
}

/* ok */
पूर्णांक test16()
{
    अक्षर *demo = "This is only a test.";
    अक्षर *p, *q;

    p = alloca(16);
    म_नकल(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    म_लिखो("alloca : %s : %s\n", p, म_नकल(q=alloca(म_माप(demo)+1),demo) );

    वापस 0;
}

/* error */
पूर्णांक test17()
{
    अक्षर *demo = "This is only a test.";
    अक्षर *p, *q;

    p = alloca(16);
    म_नकल(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    म_लिखो("alloca : %s : %s\n", p, म_नकल(q=alloca(म_माप(demo)),demo) );

    वापस 0;
}

पूर्णांक test18(व्योम)
{
    पूर्णांक i, योग = 0, n = TAB_आकार;
    पूर्णांक tab[n];
    क्रम(i=0;i<TAB_आकार+1;i++) {
        योग += tab[i];
    }
    वापस योग;
}

पूर्णांक (*table_test[])(व्योम) = {
    test1,
    test2,
    test3,
    test4,
    test5,
    test6,
    test7,
    test8,
    test9,
    test10,
    test11,
    test12,
    test13,
    test14,
    test15,
    test16,
    test17,
    test18
};

पूर्णांक मुख्य(पूर्णांक argc, अक्षर **argv)
{
    पूर्णांक i;
    अक्षर *cp;
    पूर्णांक सूचकांक;
    पूर्णांक (*ftest)(व्योम);
    पूर्णांक सूचकांक_max = माप(table_test)/माप(table_test[0]);

    /* check bounds checking main arg */
    क्रम (i = 0; i < argc; i++) {
        cp = argv[i];
        जबतक (*cp) {
            cp++;
        }
    }

    अगर (argc < 2) {
        म_लिखो(
    	    "test TCC bound checking system\n"
	    "usage: boundtest N\n"
            "  1 <= N <= %d\n", सूचकांक_max);
        निकास(1);
    }

    सूचकांक = 0;
    अगर (argc >= 2)
        सूचकांक = म_से_प(argv[1]) - 1;

    अगर ((सूचकांक < 0) || (सूचकांक >= सूचकांक_max)) {
        म_लिखो("N is outside of the valid range (%d)\n", सूचकांक);
        निकास(2);
    }

    /* well, we also use bounds on this ! */
    ftest = table_test[सूचकांक];
    ftest();

    वापस 0;
}

/*
 * without bound   0.77 s
 * with bounds    4.73
 */  
