#include <stdio.h>
#include <string.h>
#include <setjmp.h>
#якщо !defined(_WIN32)
#include <pthread.h>
#інакше
#include <windows.h>
#endif

#define	SIZE	10
#define	COUNT	10

#define TST   ціле i, a[2], b[2];                \
              для (i = 0; i < 2; i++) a[i] = 0; \
              для (i = 0; i < 2; i++) b[i] = 0

static ціле count[SIZE];

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
    ціле i = *(ціле *) index;
    static ціле v[SIZE];

    для (v[i] = 0; v[i] < COUNT; v[i]++) {
        якщо (setjmp (loc) == 0) {
            TST;
            tst2(loc);
        }
        інакше {
            count[i]++;
        }
        i = *(ціле *) index;
    }
    повернути NULL;
}

ціле
main (void)
{
    ціле i;
#якщо !defined(_WIN32)
    pthread_t id[SIZE];
#інакше
    HANDLE id[SIZE];
#endif
    ціле index[SIZE];

    для (i = 0; i < SIZE; i++) {
        index[i] = i;
#якщо !defined(_WIN32)
        pthread_create (&id[i], NULL, tst, (void *) &index[i]);
#інакше
        id[i] = CreateThread(NULL, 8192, (LPTHREAD_START_ROUTINE) tst, (void *) &index[i], 0, NULL);
#endif
    }
    для (i = 0; i < SIZE; i++) {
#якщо !defined(_WIN32)
        pthread_join (id[i], NULL);
#інакше
        WaitForSingleObject(id[i], INFINITE);
#endif
    }
    для (i = 0; i < SIZE; i++) {
        якщо (count[i] != COUNT)
            printf ("error: %d %d\n", i, count[i]);
    }
    повернути 0;
}
