#ضمن <stdio.h>
#ضمن <string.h>
#ضمن <setjmp.h>
#𐡄𐡍 !defined(_WIN32)
#ضمن <pthread.h>
#وإلا
#ضمن <windows.h>
#endif

#define	SIZE	10
#define	COUNT	10

#define TST   صحيح i, a[2], b[2];                \
              لكل (i = 0; i < 2; i++) a[i] = 0; \
              لكل (i = 0; i < 2; i++) b[i] = 0

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

    لكل (v[i] = 0; v[i] < COUNT; v[i]++) {
        𐡄𐡍 (setjmp (loc) == 0) {
            TST;
            tst2(loc);
        }
        وإلا {
            count[i]++;
        }
        i = *(صحيح *) index;
    }
    أرجع عدم;
}

صحيح
main (فراغ)
{
    صحيح i;
#𐡄𐡍 !defined(_WIN32)
    pthread_t id[SIZE];
#وإلا
    HANDLE id[SIZE];
#endif
    صحيح index[SIZE];

    لكل (i = 0; i < SIZE; i++) {
        index[i] = i;
#𐡄𐡍 !defined(_WIN32)
        pthread_create (&id[i], عدم, tst, (فراغ *) &index[i]);
#وإلا
        id[i] = CreateThread(عدم, 8192, (LPTHREAD_START_ROUTINE) tst, (فراغ *) &index[i], 0, عدم);
#endif
    }
    لكل (i = 0; i < SIZE; i++) {
#𐡄𐡍 !defined(_WIN32)
        pthread_join (id[i], عدم);
#وإلا
        WaitForSingleObject(id[i], INFINITE);
#endif
    }
    لكل (i = 0; i < SIZE; i++) {
        𐡄𐡍 (count[i] != COUNT)
            printf ("error: %d %d\n", i, count[i]);
    }
    أرجع 0;
}
