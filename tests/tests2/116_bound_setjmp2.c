#include <stdio.h>
#include <string.h>
#include <setjmp.h>
#නම් !defined(_WIN32)
#include <pthread.h>
#නැතහොත්
#include <windows.h>
#endif

#define	SIZE	10
#define	COUNT	10

#define TST   පූර්ණ_සංඛ්‍යා i, a[2], b[2];                \
              සඳහා (i = 0; i < 2; i++) a[i] = 0; \
              සඳහා (i = 0; i < 2; i++) b[i] = 0

static පූර්ණ_සංඛ්‍යා count[SIZE];

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
    පූර්ණ_සංඛ්‍යා i = *(පූර්ණ_සංඛ්‍යා *) index;
    static පූර්ණ_සංඛ්‍යා v[SIZE];

    සඳහා (v[i] = 0; v[i] < COUNT; v[i]++) {
        නම් (setjmp (loc) == 0) {
            TST;
            tst2(loc);
        }
        නැතහොත් {
            count[i]++;
        }
        i = *(පූර්ණ_සංඛ්‍යා *) index;
    }
    ආපසු NULL;
}

පූර්ණ_සංඛ්‍යා
main (void)
{
    පූර්ණ_සංඛ්‍යා i;
#නම් !defined(_WIN32)
    pthread_t id[SIZE];
#නැතහොත්
    HANDLE id[SIZE];
#endif
    පූර්ණ_සංඛ්‍යා index[SIZE];

    සඳහා (i = 0; i < SIZE; i++) {
        index[i] = i;
#නම් !defined(_WIN32)
        pthread_create (&id[i], NULL, tst, (void *) &index[i]);
#නැතහොත්
        id[i] = CreateThread(NULL, 8192, (LPTHREAD_START_ROUTINE) tst, (void *) &index[i], 0, NULL);
#endif
    }
    සඳහා (i = 0; i < SIZE; i++) {
#නම් !defined(_WIN32)
        pthread_join (id[i], NULL);
#නැතහොත්
        WaitForSingleObject(id[i], INFINITE);
#endif
    }
    සඳහා (i = 0; i < SIZE; i++) {
        නම් (count[i] != COUNT)
            printf ("error: %d %d\n", i, count[i]);
    }
    ආපසු 0;
}
