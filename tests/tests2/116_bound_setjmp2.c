#ضمن <stdio.h>
#ضمن <string.h>
#ضمن <setjmp.h>
#إذا !defined(_WIN32)
#ضمن <pthread.h>
#وإلا
#ضمن <windows.h>
#endif

#define	SIZE	10
#define	سانى_4	10

#define TST   صحيح i, a[2], b[2];                \
              لكل (i = 0; i < 2; i++) a[i] = 0; \
              لكل (i = 0; i < 2; i++) b[i] = 0

ساكن صحيح سانى_2[SIZE];

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

    لكل (v[i] = 0; v[i] < سانى_4; v[i]++) {
        إذا (setjmp (loc) == 0) {
            TST;
            tst2(loc);
        }
        وإلا {
            سانى_2[i]++;
        }
        i = *(صحيح *) index;
    }
    أرجع عدم;
}

صحيح
main (فراغ)
{
    صحيح i;
#إذا !defined(_WIN32)
    pthread_t id[SIZE];
#وإلا
    HANDLE id[SIZE];
#endif
    صحيح index[SIZE];

    لكل (i = 0; i < SIZE; i++) {
        index[i] = i;
#إذا !defined(_WIN32)
        pthread_create (&id[i], عدم, tst, (فراغ *) &index[i]);
#وإلا
        id[i] = CreateThread(عدم, 8192, (LPTHREAD_START_ROUTINE) tst, (فراغ *) &index[i], 0, عدم);
#endif
    }
    لكل (i = 0; i < SIZE; i++) {
#إذا !defined(_WIN32)
        pthread_join (id[i], عدم);
#وإلا
        WaitForSingleObject(id[i], INFINITE);
#endif
    }
    لكل (i = 0; i < SIZE; i++) {
        إذا (سانى_2[i] != سانى_4)
            printf ("error: %d %d\n", i, سانى_2[i]);
    }
    أرجع 0;
}
