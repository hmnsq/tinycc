#अन्तर्भाव <stdlib.h>
#अन्तर्भाव <stdio.h>
#अन्तर्भाव <string.h>

#define NB_ITS 1000000
//#define NB_ITS 1
#define TAB_SIZE 100

पूर्णाङ्क tab[TAB_SIZE];
पूर्णाङ्क ret_sum;
वर्ण tab3[256];

पूर्णाङ्क test1(शून्य)
{
    पूर्णाङ्क i, sum = 0;
    प्रति(i=0;i<TAB_SIZE;i++) {
        sum += tab[i];
    }
    प्रत्यागम sum;
}

/* error */
पूर्णाङ्क test2(शून्य)
{
    पूर्णाङ्क i, sum = 0;
    प्रति(i=0;i<TAB_SIZE + 1;i++) {
        sum += tab[i];
    }
    प्रत्यागम sum;
}

/* actually, profiling test */
पूर्णाङ्क test3(शून्य)
{
    पूर्णाङ्क sum;
    पूर्णाङ्क i, it;

    sum = 0;
    प्रति(it=0;it<NB_ITS;it++) {
        प्रति(i=0;i<TAB_SIZE;i++) {
            sum += tab[i];
        }
    }
    प्रत्यागम sum;
}

/* ok */
पूर्णाङ्क test4(शून्य)
{
    पूर्णाङ्क i, sum = 0;
    पूर्णाङ्क *tab4;

    tab4 = malloc(20 * परिमाण(पूर्णाङ्क));
    प्रति(i=0;i<20;i++) {
        sum += tab4[i];
    }
    मुक्त(tab4);

    प्रत्यागम sum;
}

/* error */
पूर्णाङ्क test5(शून्य)
{
    पूर्णाङ्क i, sum = 0;
    पूर्णाङ्क *tab4;

    tab4 = malloc(20 * परिमाण(पूर्णाङ्क));
    प्रति(i=0;i<21;i++) {
        sum += tab4[i];
    }
    मुक्त(tab4);

    प्रत्यागम sum;
}

/* error */
पूर्णाङ्क test6(शून्य)
{
    पूर्णाङ्क i, sum = 0;
    पूर्णाङ्क *tab4;
    
    tab4 = malloc(20 * परिमाण(पूर्णाङ्क));
    मुक्त(tab4);
    प्रति(i=0;i<21;i++) {
        sum += tab4[i];
    }

    प्रत्यागम sum;
}

/* error */
पूर्णाङ्क test7(शून्य)
{
    पूर्णाङ्क i, sum = 0;
    पूर्णाङ्क *p;

    प्रति(i=0;i<TAB_SIZE + 1;i++) {
        p = &tab[i];
        जइ (i == TAB_SIZE)
            printf("i=%d %x\n", i, p);
        sum += *p;
    }
    प्रत्यागम sum;
}

/* ok */
पूर्णाङ्क test8(शून्य)
{
    पूर्णाङ्क i, sum = 0;
    पूर्णाङ्क tab[10];

    प्रति(i=0;i<10;i++) {
        sum += tab[i];
    }
    प्रत्यागम sum;
}

/* error */
पूर्णाङ्क test9(शून्य)
{
    पूर्णाङ्क i, sum = 0;
    वर्ण tab[10];

    प्रति(i=0;i<11;i++) {
        sum += tab[i];
    }
    प्रत्यागम sum;
}

/* ok */
पूर्णाङ्क test10(शून्य)
{
    वर्ण tab[10];
    वर्ण tab1[10];

    memset(tab, 0, 10);
    memcpy(tab, tab1, 10);
    memmove(tab, tab1, 10);
    प्रत्यागम 0;
}

/* error */
पूर्णाङ्क test11(शून्य)
{
    वर्ण tab[10];

    memset(tab, 0, 11);
    प्रत्यागम 0;
}

/* error */
पूर्णाङ्क test12(शून्य)
{
    शून्य *ptr;
    ptr = malloc(10);
    मुक्त(ptr);
    मुक्त(ptr);
    प्रत्यागम 0;
}

/* error */
पूर्णाङ्क test13(शून्य)
{
    वर्ण pad1 = 0;
    वर्ण tab[10];
    वर्ण pad2 = 0;
    memset(tab, 'a', परिमाण(tab));
    प्रत्यागम strlen(tab);
}

पूर्णाङ्क test14(शून्य)
{
    वर्ण *p = alloca(TAB_SIZE);
    size_t ret;
    memset(p, 'a', TAB_SIZE);
    p[TAB_SIZE-1] = 0;
    ret = strlen(p);
    प्रत्यागम ret;
}

/* error */
पूर्णाङ्क test15(शून्य)
{
    वर्ण *p = alloca(TAB_SIZE-1);
    size_t ret;
    memset(p, 'a', TAB_SIZE);
    p[TAB_SIZE-1] = 0;
    ret = strlen(p);
    प्रत्यागम ret;
}

/* ok */
पूर्णाङ्क test16()
{
    वर्ण *demo = "This is only a test.";
    वर्ण *p, *q;

    p = alloca(16);
    strcpy(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    printf("alloca : %s : %s\n", p, strcpy(q=alloca(strlen(demo)+1),demo) );

    प्रत्यागम 0;
}

/* error */
पूर्णाङ्क test17()
{
    वर्ण *demo = "This is only a test.";
    वर्ण *p, *q;

    p = alloca(16);
    strcpy(p,"12345678901234");

    /* Test alloca embedded in a larger expression */
    printf("alloca : %s : %s\n", p, strcpy(q=alloca(strlen(demo)),demo) );

    प्रत्यागम 0;
}

पूर्णाङ्क test18(शून्य)
{
    पूर्णाङ्क i, sum = 0, n = TAB_SIZE;
    पूर्णाङ्क tab[n];
    प्रति(i=0;i<TAB_SIZE+1;i++) {
        sum += tab[i];
    }
    प्रत्यागम sum;
}

पूर्णाङ्क (*table_test[])(शून्य) = {
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

पूर्णाङ्क main(पूर्णाङ्क argc, वर्ण **argv)
{
    पूर्णाङ्क i;
    वर्ण *cp;
    पूर्णाङ्क index;
    पूर्णाङ्क (*ftest)(शून्य);
    पूर्णाङ्क index_max = परिमाण(table_test)/परिमाण(table_test[0]);

    /* check bounds checking main arg */
    प्रति (i = 0; i < argc; i++) {
        cp = argv[i];
        जाव (*cp) {
            cp++;
        }
    }

    जइ (argc < 2) {
        printf(
    	    "test TCC bound checking system\n"
	    "usage: boundtest N\n"
            "  1 <= N <= %d\n", index_max);
        exit(1);
    }

    index = 0;
    जइ (argc >= 2)
        index = atoi(argv[1]) - 1;

    जइ ((index < 0) || (index >= index_max)) {
        printf("N is outside of the valid range (%d)\n", index);
        exit(2);
    }

    /* well, we also use bounds on this ! */
    ftest = table_test[index];
    ftest();

    प्रत्यागम 0;
}

/*
 * without bound   0.77 s
 * with bounds    4.73
 */  
