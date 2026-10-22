#include <stdio.h>
#include <string.h>
#include <setjmp.h>
#если !defined(_WIN32)
#include <pthread.h>
#иначе
#include <windows.h>
#endif

#define	SIZE	10
#define	COUNT	10

#define TST   целое i, a[2], b[2];                \
              для (i = 0; i < 2; i++) a[i] = 0; \
              для (i = 0; i < 2; i++) b[i] = 0

static целое count[SIZE];

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
    целое i = *(целое *) index;
    static целое v[SIZE];

    для (v[i] = 0; v[i] < COUNT; v[i]++) {
        если (setjmp (loc) == 0) {
            TST;
            tst2(loc);
        }
        иначе {
            count[i]++;
        }
        i = *(целое *) index;
    }
    вернуть NULL;
}

целое
основной (void)
{
    целое i;
#если !defined(_WIN32)
    pthread_t id[SIZE];
#иначе
    HANDLE id[SIZE];
#endif
    целое index[SIZE];

    для (i = 0; i < SIZE; i++) {
        index[i] = i;
#если !defined(_WIN32)
        pthread_create (&id[i], NULL, tst, (void *) &index[i]);
#иначе
        id[i] = CreateThread(NULL, 8192, (LPTHREAD_START_ROUTINE) tst, (void *) &index[i], 0, NULL);
#endif
    }
    для (i = 0; i < SIZE; i++) {
#если !defined(_WIN32)
        pthread_join (id[i], NULL);
#иначе
        WaitForSingleObject(id[i], INFINITE);
#endif
    }
    для (i = 0; i < SIZE; i++) {
        если (count[i] != COUNT)
            printf ("error: %d %d\n", i, count[i]);
    }
    вернуть 0;
}
