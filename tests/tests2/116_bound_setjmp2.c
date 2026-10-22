#include <stdio.h>
#include <string.h>
#include <setjmp.h>
#もし !defined(_WIN32)
#include <pthread.h>
#否则
#include <windows.h>
#endif

#define	SIZE	10
#define	COUNT	10

#define TST   整数 i, a[2], b[2];                \
              ために (i = 0; i < 2; i++) a[i] = 0; \
              ために (i = 0; i < 2; i++) b[i] = 0

static 整数 count[SIZE];

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
    整数 i = *(整数 *) index;
    static 整数 v[SIZE];

    ために (v[i] = 0; v[i] < COUNT; v[i]++) {
        もし (setjmp (loc) == 0) {
            TST;
            tst2(loc);
        }
        否则 {
            count[i]++;
        }
        i = *(整数 *) index;
    }
    戻る NULL;
}

整数
メインページ (void)
{
    整数 i;
#もし !defined(_WIN32)
    pthread_t id[SIZE];
#否则
    HANDLE id[SIZE];
#endif
    整数 index[SIZE];

    ために (i = 0; i < SIZE; i++) {
        index[i] = i;
#もし !defined(_WIN32)
        pthread_create (&id[i], NULL, tst, (void *) &index[i]);
#否则
        id[i] = CreateThread(NULL, 8192, (LPTHREAD_START_ROUTINE) tst, (void *) &index[i], 0, NULL);
#endif
    }
    ために (i = 0; i < SIZE; i++) {
#もし !defined(_WIN32)
        pthread_join (id[i], NULL);
#否则
        WaitForSingleObject(id[i], INFINITE);
#endif
    }
    ために (i = 0; i < SIZE; i++) {
        もし (count[i] != COUNT)
            printf ("error: %d %d\n", i, count[i]);
    }
    戻る 0;
}
