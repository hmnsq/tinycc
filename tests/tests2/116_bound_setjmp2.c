#include <stdio.h>
#include <string.h>
#include <setjmp.h>
#གལ་སྲིད !defined(_WIN32)
#include <pthread.h>
#དེ་མིན
#include <windows.h>
#endif

#define	SIZE	10
#define	COUNT	10

#define TST   ཧྲིལ i, a[2], b[2];                \
              དོན་ལུ (i = 0; i < 2; i++) a[i] = 0; \
              དོན་ལུ (i = 0; i < 2; i++) b[i] = 0

static ཧྲིལ count[SIZE];

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
    ཧྲིལ i = *(ཧྲིལ *) index;
    static ཧྲིལ v[SIZE];

    དོན་ལུ (v[i] = 0; v[i] < COUNT; v[i]++) {
        གལ་སྲིད (setjmp (loc) == 0) {
            TST;
            tst2(loc);
        }
        དེ་མིན {
            count[i]++;
        }
        i = *(ཧྲིལ *) index;
    }
    ལོག NULL;
}

ཧྲིལ
main (void)
{
    ཧྲིལ i;
#གལ་སྲིད !defined(_WIN32)
    pthread_t id[SIZE];
#དེ་མིན
    HANDLE id[SIZE];
#endif
    ཧྲིལ index[SIZE];

    དོན་ལུ (i = 0; i < SIZE; i++) {
        index[i] = i;
#གལ་སྲིད !defined(_WIN32)
        pthread_create (&id[i], NULL, tst, (void *) &index[i]);
#དེ་མིན
        id[i] = CreateThread(NULL, 8192, (LPTHREAD_START_ROUTINE) tst, (void *) &index[i], 0, NULL);
#endif
    }
    དོན་ལུ (i = 0; i < SIZE; i++) {
#གལ་སྲིད !defined(_WIN32)
        pthread_join (id[i], NULL);
#དེ་མིན
        WaitForSingleObject(id[i], INFINITE);
#endif
    }
    དོན་ལུ (i = 0; i < SIZE; i++) {
        གལ་སྲིད (count[i] != COUNT)
            printf ("error: %d %d\n", i, count[i]);
    }
    ལོག 0;
}
