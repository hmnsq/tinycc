#include <stdio.h>
#include <string.h>
#include <setjmp.h>
#nếu !defined(_WIN32)
#include <pthread.h>
#không_thì
#include <windows.h>
#endif

#define	SIZE	10
#define	COUNT	10

#define TST   số_nguyên i, a[2], b[2];                \
              cho (i = 0; i < 2; i++) a[i] = 0; \
              cho (i = 0; i < 2; i++) b[i] = 0

static số_nguyên count[SIZE];

static void tst1 (jmp_buf loc)
{
    TST;
    longjmp(loc, 1);
}

static void tst2(jmp_buf loc)
{
    jmp_buf jmp;

    setjmp (jmp);
    TST;
    tst1(loc);
}

static void *tst (void * index)
{
    jmp_buf loc;
    số_nguyên i = *(số_nguyên *) index;
    static số_nguyên v[SIZE];

    cho (v[i] = 0; v[i] < COUNT; v[i]++) {
        nếu (setjmp (loc) == 0) {
            TST;
            tst2(loc);
        }
        không_thì {
            count[i]++;
        }
        i = *(số_nguyên *) index;
    }
    trả_về NULL;
}

số_nguyên
main (void)
{
    số_nguyên i;
#nếu !defined(_WIN32)
    pthread_t id[SIZE];
#không_thì
    HANDLE id[SIZE];
#endif
    số_nguyên index[SIZE];

    cho (i = 0; i < SIZE; i++) {
        index[i] = i;
#nếu !defined(_WIN32)
        pthread_create (&id[i], NULL, tst, (void *) &index[i]);
#không_thì
        id[i] = CreateThread(NULL, 8192, (LPTHREAD_START_ROUTINE) tst, (void *) &index[i], 0, NULL);
#endif
    }
    cho (i = 0; i < SIZE; i++) {
#nếu !defined(_WIN32)
        pthread_join (id[i], NULL);
#không_thì
        WaitForSingleObject(id[i], INFINITE);
#endif
    }
    cho (i = 0; i < SIZE; i++) {
        nếu (count[i] != COUNT)
            printf ("error: %d %d\n", i, count[i]);
    }
    trả_về 0;
}
