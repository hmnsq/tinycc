#ضمن <stdio.h>
#ضمن <string.h>
#ضمن <setjmp.h>
#אם !defined(_WIN32)
#ضمن <pthread.h>
#אחרת
#ضمن <windows.h>
#endif

#define	SIZE	10
#define	COUNT	10

#define TST   صحيح i, a[2], b[2];                \
              עבור (i = 0; i < 2; i++) a[i] = 0; \
              עבור (i = 0; i < 2; i++) b[i] = 0

ساكن صحيح count[SIZE];

ساكن فراغ tst1 (jmp_buf loc)
{
    TST;
    longjmp(loc, 1);
}

ساكن فراغ tst2(jmp_buf loc)
{
    jmp_buf jmp;

    setjmp (jmp);
    TST;
    tst1(loc);
}

ساكن فراغ *tst (فراغ * index)
{
    jmp_buf loc;
    صحيح i = *(صحيح *) index;
    ساكن صحيح v[SIZE];

    עבור (v[i] = 0; v[i] < COUNT; v[i]++) {
        אם (setjmp (loc) == 0) {
            TST;
            tst2(loc);
        }
        אחרת {
            count[i]++;
        }
        i = *(صحيح *) index;
    }
    החזר عدم;
}

صحيح
main (فراغ)
{
    صحيح i;
#אם !defined(_WIN32)
    pthread_t id[SIZE];
#אחרת
    HANDLE id[SIZE];
#endif
    صحيح index[SIZE];

    עבור (i = 0; i < SIZE; i++) {
        index[i] = i;
#אם !defined(_WIN32)
        pthread_create (&id[i], عدم, tst, (فراغ *) &index[i]);
#אחרת
        id[i] = CreateThread(عدم, 8192, (LPTHREAD_START_ROUTINE) tst, (فراغ *) &index[i], 0, عدم);
#endif
    }
    עבור (i = 0; i < SIZE; i++) {
#אם !defined(_WIN32)
        pthread_join (id[i], عدم);
#אחרת
        WaitForSingleObject(id[i], INFINITE);
#endif
    }
    עבור (i = 0; i < SIZE; i++) {
        אם (count[i] != COUNT)
            printf ("error: %d %d\n", i, count[i]);
    }
    החזר 0;
}
