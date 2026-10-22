#شامل <stdio.h>
#شامل <string.h>
#شامل <setjmp.h>
#اگر !defined(_WIN32)
#شامل <pthread.h>
#وگرنه
#شامل <windows.h>
#endif

#define	SIZE	10
#define	شمار_4	10

#define TST   صحیح i, a[2], b[2];                \
              برای (i = 0; i < 2; i++) a[i] = 0; \
              برای (i = 0; i < 2; i++) b[i] = 0

ایستا صحیح شمار_2[SIZE];

ایستا تهی tst1 (jmp_buf loc)
{
    TST;
    longjmp(loc, 1);
}

ایستا تهی tst2(jmp_buf loc)
{
    jmp_buf jmp;

    setjmp (jmp);
    TST;
    tst1(loc);
}

ایستا تهی *tst (تهی * index)
{
    jmp_buf loc;
    صحیح i = *(صحیح *) index;
    ایستا صحیح v[SIZE];

    برای (v[i] = 0; v[i] < شمار_4; v[i]++) {
        اگر (setjmp (loc) == 0) {
            TST;
            tst2(loc);
        }
        وگرنه {
            شمار_2[i]++;
        }
        i = *(صحیح *) index;
    }
    بازگشت پوچ;
}

صحیح
اصلی (تهی)
{
    صحیح i;
#اگر !defined(_WIN32)
    pthread_t id[SIZE];
#وگرنه
    HANDLE id[SIZE];
#endif
    صحیح index[SIZE];

    برای (i = 0; i < SIZE; i++) {
        index[i] = i;
#اگر !defined(_WIN32)
        pthread_create (&id[i], پوچ, tst, (تهی *) &index[i]);
#وگرنه
        id[i] = CreateThread(پوچ, 8192, (LPTHREAD_START_ROUTINE) tst, (تهی *) &index[i], 0, پوچ);
#endif
    }
    برای (i = 0; i < SIZE; i++) {
#اگر !defined(_WIN32)
        pthread_join (id[i], پوچ);
#وگرنه
        WaitForSingleObject(id[i], INFINITE);
#endif
    }
    برای (i = 0; i < SIZE; i++) {
        اگر (شمار_2[i] != شمار_4)
            printf ("error: %d %d\n", i, شمار_2[i]);
    }
    بازگشت 0;
}
