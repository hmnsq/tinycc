#অন্তর্ভাৱ <stdio.h>
#অন্তর্ভাৱ <string.h>
#অন্তর্ভাৱ <setjmp.h>
#যদি !defined(_WIN32)
#অন্তর্ভাৱ <pthread.h>
#অন্যথা
#অন্তর্ভাৱ <windows.h>
#endif

#define	SIZE	10
#define	গুনতি_4	10

#define TST   পূর্ণাঙ্ক i, a[2], b[2];                \
              বাবে (i = 0; i < 2; i++) a[i] = 0; \
              বাবে (i = 0; i < 2; i++) b[i] = 0

স্থির পূর্ণাঙ্ক গুনতি_2[SIZE];

স্থির শূন্য tst1 (jmp_buf loc)
{
    TST;
    longjmp(loc, 1);
}

স্থির শূন্য tst2(jmp_buf loc)
{
    jmp_buf jmp;

    setjmp (jmp);
    TST;
    tst1(loc);
}

স্থির শূন্য *tst (শূন্য * index)
{
    jmp_buf loc;
    পূর্ণাঙ্ক i = *(পূর্ণাঙ্ক *) index;
    স্থির পূর্ণাঙ্ক v[SIZE];

    বাবে (v[i] = 0; v[i] < গুনতি_4; v[i]++) {
        যদি (setjmp (loc) == 0) {
            TST;
            tst2(loc);
        }
        অন্যথা {
            গুনতি_2[i]++;
        }
        i = *(পূর্ণাঙ্ক *) index;
    }
    ঘূৰাই রিক্ত;
}

পূর্ণাঙ্ক
main (শূন্য)
{
    পূর্ণাঙ্ক i;
#যদি !defined(_WIN32)
    pthread_t id[SIZE];
#অন্যথা
    HANDLE id[SIZE];
#endif
    পূর্ণাঙ্ক index[SIZE];

    বাবে (i = 0; i < SIZE; i++) {
        index[i] = i;
#যদি !defined(_WIN32)
        pthread_create (&id[i], রিক্ত, tst, (শূন্য *) &index[i]);
#অন্যথা
        id[i] = CreateThread(রিক্ত, 8192, (LPTHREAD_START_ROUTINE) tst, (শূন্য *) &index[i], 0, রিক্ত);
#endif
    }
    বাবে (i = 0; i < SIZE; i++) {
#যদি !defined(_WIN32)
        pthread_join (id[i], রিক্ত);
#অন্যথা
        WaitForSingleObject(id[i], INFINITE);
#endif
    }
    বাবে (i = 0; i < SIZE; i++) {
        যদি (গুনতি_2[i] != গুনতি_4)
            printf ("error: %d %d\n", i, গুনতি_2[i]);
    }
    ঘূৰাই 0;
}
