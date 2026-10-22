#include <stdio.h>
#include <string.h>
#include <setjmp.h>
#만약 !defined(_WIN32)
#include <pthread.h>
#아니면
#include <windows.h>
#endif

#define	SIZE	10
#define	COUNT	10

#define TST   정수 i, a[2], b[2];                \
              위해 (i = 0; i < 2; i++) a[i] = 0; \
              위해 (i = 0; i < 2; i++) b[i] = 0

static 정수 count[SIZE];

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
    정수 i = *(정수 *) index;
    static 정수 v[SIZE];

    위해 (v[i] = 0; v[i] < COUNT; v[i]++) {
        만약 (setjmp (loc) == 0) {
            TST;
            tst2(loc);
        }
        아니면 {
            count[i]++;
        }
        i = *(정수 *) index;
    }
    반환 NULL;
}

정수
main (void)
{
    정수 i;
#만약 !defined(_WIN32)
    pthread_t id[SIZE];
#아니면
    HANDLE id[SIZE];
#endif
    정수 index[SIZE];

    위해 (i = 0; i < SIZE; i++) {
        index[i] = i;
#만약 !defined(_WIN32)
        pthread_create (&id[i], NULL, tst, (void *) &index[i]);
#아니면
        id[i] = CreateThread(NULL, 8192, (LPTHREAD_START_ROUTINE) tst, (void *) &index[i], 0, NULL);
#endif
    }
    위해 (i = 0; i < SIZE; i++) {
#만약 !defined(_WIN32)
        pthread_join (id[i], NULL);
#아니면
        WaitForSingleObject(id[i], INFINITE);
#endif
    }
    위해 (i = 0; i < SIZE; i++) {
        만약 (count[i] != COUNT)
            printf ("error: %d %d\n", i, count[i]);
    }
    반환 0;
}
