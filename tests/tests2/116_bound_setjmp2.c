#অন্তর্ভাব <stdio.h>
#অন্তর্ভাব <string.h>
#অন্তর্ভাব <setjmp.h>
#যদি !defined(_WIN32)
#অন্তর্ভাব <pthread.h>
#অন্যথা
#অন্তর্ভাব <windows.h>
#endif

#define	আকার_3	10
#define	গুনতি_4	10

#define TST   পূর্ণসংখ্যা i, a[2], b[2];                \
              জন্য (i = 0; i < 2; i++) a[i] = 0; \
              জন্য (i = 0; i < 2; i++) b[i] = 0

স্থির পূর্ণসংখ্যা গুনতি_2[আকার_3];

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

স্থির শূন্য *tst (শূন্য * সূচক)
{
    jmp_buf loc;
    পূর্ণসংখ্যা i = *(পূর্ণসংখ্যা *) সূচক;
    স্থির পূর্ণসংখ্যা v[আকার_3];

    জন্য (v[i] = 0; v[i] < গুনতি_4; v[i]++) {
        যদি (setjmp (loc) == 0) {
            TST;
            tst2(loc);
        }
        অন্যথা {
            গুনতি_2[i]++;
        }
        i = *(পূর্ণসংখ্যা *) সূচক;
    }
    ফেরত ফাঁকা;
}

পূর্ণসংখ্যা
প্রধান (শূন্য)
{
    পূর্ণসংখ্যা i;
#যদি !defined(_WIN32)
    pthread_t id[আকার_3];
#অন্যথা
    HANDLE id[আকার_3];
#endif
    পূর্ণসংখ্যা সূচক[আকার_3];

    জন্য (i = 0; i < আকার_3; i++) {
        সূচক[i] = i;
#যদি !defined(_WIN32)
        pthread_create (&id[i], ফাঁকা, tst, (শূন্য *) &সূচক[i]);
#অন্যথা
        id[i] = CreateThread(ফাঁকা, 8192, (LPTHREAD_START_ROUTINE) tst, (শূন্য *) &সূচক[i], 0, ফাঁকা);
#endif
    }
    জন্য (i = 0; i < আকার_3; i++) {
#যদি !defined(_WIN32)
        pthread_join (id[i], ফাঁকা);
#অন্যথা
        WaitForSingleObject(id[i], INFINITE);
#endif
    }
    জন্য (i = 0; i < আকার_3; i++) {
        যদি (গুনতি_2[i] != গুনতি_4)
            printf ("error: %d %d\n", i, গুনতি_2[i]);
    }
    ফেরত 0;
}
