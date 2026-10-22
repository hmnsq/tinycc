#अन्तर्भाव <stdlib.h>
#अन्तर्भाव <stdio.h>
#अन्तर्भाव <string.h>

#define NB_ITS 1000000
//#define NB_ITS 1
#define TAB_SIZE 100

पूर्णांक tab[TAB_SIZE];
पूर्णांक ret_sum;
अक्षर tab3[256];

पूर्णांक test1(शून्य)
{
    पूर्णांक i, sum = 0;
    साठी(i=0;i<TAB_SIZE;i++) {
        sum += tab[i];
    }
    परत sum;
}

/* error */
पूर्णांक test2(शून्य)
{
    पूर्णांक i, sum = 0;
    साठी(i=0;i<TAB_SIZE + 1;i++) {
        sum += tab[i];
    }
    परत sum;
}

/* actually, profiling test */
पूर्णांक test3(शून्य)
{
    पूर्णांक sum;
    पूर्णांक i, it;

    sum = 0;
    साठी(it=0;it<NB_ITS;it++) {
        साठी(i=0;i<TAB_SIZE;i++) {
            sum += tab[i];
        }
    }
    परत sum;
}

/* ok */
पूर्णांक test4(शून्य)
{
    पूर्णांक i, sum = 0;
    पूर्णांक *tab4;

    tab4 = दो_स्मृति(20 * आकार(पूर्णांक));
    साठी(i=0;i<20;i++) {
        sum += tab4[i];
    }
    मुक्त(tab4);

    परत sum;
}

/* error */
पूर्णांक test5(शून्य)
{
    पूर्णांक i, sum = 0;
    पूर्णांक *tab4;

    tab4 = दो_स्मृति(20 * आकार(पूर्णांक));
    साठी(i=0;i<21;i++) {
        sum += tab4[i];
    }
    मुक्त(tab4);

    परत sum;
}

/* error */
पूर्णांक test6(शून्य)
{
    पूर्णांक i, sum = 0;
    पूर्णांक *tab4;
    
    tab4 = दो_स्मृति(20 * आकार(पूर्णांक));
    मुक्त(tab4);
    साठी(i=0;i<21;i++) {
        sum += tab4[i];
    }

    परत sum;
}

/* error */
पूर्णांक test7(शून्य)
{
    पूर्णांक i, sum = 0;
    पूर्णांक *p;

    साठी(i=0;i<TAB_SIZE + 1;i++) {
        p = &tab[i];
        जर (i == TAB_SIZE)
            म_लिखो("i=%d %x\n", i, p);
        sum += *p;
    }
    परत sum;
}

/* ok */
पूर्णांक test8(शून्य)
{
    पूर्णांक i, sum = 0;
    पूर्णांक tab[10];

    साठी(i=0;i<10;i++) {
        sum += tab[i];
    }
    परत sum;
}

/* error */
पूर्णांक test9(शून्य)
{
    पूर्णांक i, sum = 0;
    अक्षर tab[10];

    साठी(i=0;i<11;i++) {
        sum += tab[i];
    }
    परत sum;
}

/* ok */
पूर्णांक test10(शून्य)
{
    अक्षर tab[10];
    अक्षर tab1[10];

    स_रखो(tab, 0, 10);
    स_नकल(tab, tab1, 10);
    स_हटाओ(tab, tab1, 10);
    परत 0;
}

/* error */
पूर्णांक test11(शून्य)
{
    अक्षर tab[10];

    स_रखो(tab, 0, 11);
    परत 0;
}

/* error */
पूर्णांक test12(शून्य)
{
    शून्य *ptr;
    ptr = दो_स्मृति(10);
    मुक्त(ptr);
    मुक्त(ptr);
    परत 0;
}

/* error */
पूर्णांक test13(शून्य)
{
    अक्षर pad1 = 0;
    अक्षर tab[10];
    अक्षर pad2 = 0;
    स_रखो(tab, 'a', आकार(tab));
    परत म_माप(tab);
}

पूर्णांक test14(शून्य)
{
    अक्षर *p = alloca(TAB_SIZE);
    माप_प्रकार ret;
    स_रखो(p, 'a', TAB_SIZE);
    p[TAB_SIZE-1] = 0;
    ret = म_माप(p);
    परत ret;
}

/* error */
पूर्णांक test15(शून्य)
{
    अक्षर *p = alloca(TAB_SIZE-1);
    माप_प्रकार ret;
    स_रखो(p, 'a', TAB_SIZE);
    p[TAB_SIZE-1] = 0;
    ret = म_माप(p);
    परत ret;
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

    परत 0;
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

    परत 0;
}

पूर्णांक test18(शून्य)
{
    पूर्णांक i, sum = 0, n = TAB_SIZE;
    पूर्णांक tab[n];
    साठी(i=0;i<TAB_SIZE+1;i++) {
        sum += tab[i];
    }
    परत sum;
}

पूर्णांक (*table_test[])(शून्य) = {
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

पूर्णांक main(पूर्णांक argc, अक्षर **argv)
{
    पूर्णांक i;
    अक्षर *cp;
    पूर्णांक index;
    पूर्णांक (*ftest)(शून्य);
    पूर्णांक index_max = आकार(table_test)/आकार(table_test[0]);

    /* check bounds checking main arg */
    साठी (i = 0; i < argc; i++) {
        cp = argv[i];
        पर्यंत (*cp) {
            cp++;
        }
    }

    जर (argc < 2) {
        म_लिखो(
    	    "test TCC bound checking system\n"
	    "usage: boundtest N\n"
            "  1 <= N <= %d\n", index_max);
        निकास(1);
    }

    index = 0;
    जर (argc >= 2)
        index = म_से_प(argv[1]) - 1;

    जर ((index < 0) || (index >= index_max)) {
        म_लिखो("N is outside of the valid range (%d)\n", index);
        निकास(2);
    }

    /* well, we also use bounds on this ! */
    ftest = table_test[index];
    ftest();

    परत 0;
}

/*
 * without bound   0.77 s
 * with bounds    4.73
 */  
