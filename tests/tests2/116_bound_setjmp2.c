#ଅନ୍ତର୍ଭାଵ <stdio.h>
#ଅନ୍ତର୍ଭାଵ <string.h>
#ଅନ୍ତର୍ଭାଵ <setjmp.h>
#ଯଦି !defined(_WIN32)
#ଅନ୍ତର୍ଭାଵ <pthread.h>
#ଅନ୍ୟଥା
#ଅନ୍ତର୍ଭାଵ <windows.h>
#endif

#define	SIZE	10
#define	ଗଣନା_5	10

#define TST   ପୂର୍ଣ୍ଣସଂଖ୍ୟା i, a[2], b[2];                \
              ପାଇଁ (i = 0; i < 2; i++) a[i] = 0; \
              ପାଇଁ (i = 0; i < 2; i++) b[i] = 0

ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଗଣନା_3[SIZE];

ସ୍ଥିର ଶୂନ୍ୟ tst1 (jmp_buf loc)
{
    TST;
    longjmp(loc, 1);
}

ସ୍ଥିର ଶୂନ୍ୟ tst2(jmp_buf loc)
{
    jmp_buf jmp;

    setjmp (jmp);
    TST;
    tst1(loc);
}

ସ୍ଥିର ଶୂନ୍ୟ *tst (ଶୂନ୍ୟ * index)
{
    jmp_buf loc;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i = *(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *) index;
    ସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା v[SIZE];

    ପାଇଁ (v[i] = 0; v[i] < ଗଣନା_5; v[i]++) {
        ଯଦି (setjmp (loc) == 0) {
            TST;
            tst2(loc);
        }
        ଅନ୍ୟଥା {
            ଗଣନା_3[i]++;
        }
        i = *(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *) index;
    }
    ଫେରନ୍ତୁ ଖାଲି;
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା
ମୁଖ୍ୟ (ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
#ଯଦି !defined(_WIN32)
    pthread_t id[SIZE];
#ଅନ୍ୟଥା
    HANDLE id[SIZE];
#endif
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା index[SIZE];

    ପାଇଁ (i = 0; i < SIZE; i++) {
        index[i] = i;
#ଯଦି !defined(_WIN32)
        pthread_create (&id[i], ଖାଲି, tst, (ଶୂନ୍ୟ *) &index[i]);
#ଅନ୍ୟଥା
        id[i] = CreateThread(ଖାଲି, 8192, (LPTHREAD_START_ROUTINE) tst, (ଶୂନ୍ୟ *) &index[i], 0, ଖାଲି);
#endif
    }
    ପାଇଁ (i = 0; i < SIZE; i++) {
#ଯଦି !defined(_WIN32)
        pthread_join (id[i], ଖାଲି);
#ଅନ୍ୟଥା
        WaitForSingleObject(id[i], INFINITE);
#endif
    }
    ପାଇଁ (i = 0; i < SIZE; i++) {
        ଯଦି (ଗଣନା_3[i] != ଗଣନା_5)
            printf ("error: %d %d\n", i, ଗଣନା_3[i]);
    }
    ଫେରନ୍ତୁ 0;
}
