#include <stdio.h>
#include <string.h>
#include <setjmp.h>
#ако !defined(_WIN32)
#include <pthread.h>
#иначе
#include <windows.h>
#endif

#define	SIZE	10
#define	COUNT	10

#define TST   цяло i, a[2], b[2];                \
              за (i = 0; i < 2; i++) a[i] = 0; \
              за (i = 0; i < 2; i++) b[i] = 0

static цяло count[SIZE];

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
    цяло i = *(цяло *) index;
    static цяло v[SIZE];

    за (v[i] = 0; v[i] < COUNT; v[i]++) {
        ако (setjmp (loc) == 0) {
            TST;
            tst2(loc);
        }
        иначе {
            count[i]++;
        }
        i = *(цяло *) index;
    }
    върни NULL;
}

цяло
main (void)
{
    цяло i;
#ако !defined(_WIN32)
    pthread_t id[SIZE];
#иначе
    HANDLE id[SIZE];
#endif
    цяло index[SIZE];

    за (i = 0; i < SIZE; i++) {
        index[i] = i;
#ако !defined(_WIN32)
        pthread_create (&id[i], NULL, tst, (void *) &index[i]);
#иначе
        id[i] = CreateThread(NULL, 8192, (LPTHREAD_START_ROUTINE) tst, (void *) &index[i], 0, NULL);
#endif
    }
    за (i = 0; i < SIZE; i++) {
#ако !defined(_WIN32)
        pthread_join (id[i], NULL);
#иначе
        WaitForSingleObject(id[i], INFINITE);
#endif
    }
    за (i = 0; i < SIZE; i++) {
        ако (count[i] != COUNT)
            printf ("error: %d %d\n", i, count[i]);
    }
    върни 0;
}
