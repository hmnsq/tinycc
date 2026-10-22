#include <stdio.h>
#include <string.h>
#include <setjmp.h>
#ᱡᱩᱫᱤ !defined(_WIN32)
#include <pthread.h>
#ᱵᱟᱝ
#include <windows.h>
#endif

#define	SIZE	10
#define	COUNT	10

#define TST   puur_naa_nka i, a[2], b[2];                \
              for (i = 0; i < 2; i++) a[i] = 0; \
              for (i = 0; i < 2; i++) b[i] = 0

static puur_naa_nka count[SIZE];

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
    puur_naa_nka i = *(puur_naa_nka *) index;
    static puur_naa_nka v[SIZE];

    for (v[i] = 0; v[i] < COUNT; v[i]++) {
        ᱡᱩᱫᱤ (setjmp (loc) == 0) {
            TST;
            tst2(loc);
        }
        ᱵᱟᱝ {
            count[i]++;
        }
        i = *(puur_naa_nka *) index;
    }
    ᱨᱩᱣᱟᱹᱲ NULL;
}

puur_naa_nka
main (void)
{
    puur_naa_nka i;
#ᱡᱩᱫᱤ !defined(_WIN32)
    pthread_t id[SIZE];
#ᱵᱟᱝ
    HANDLE id[SIZE];
#endif
    puur_naa_nka index[SIZE];

    for (i = 0; i < SIZE; i++) {
        index[i] = i;
#ᱡᱩᱫᱤ !defined(_WIN32)
        pthread_create (&id[i], NULL, tst, (void *) &index[i]);
#ᱵᱟᱝ
        id[i] = CreateThread(NULL, 8192, (LPTHREAD_START_ROUTINE) tst, (void *) &index[i], 0, NULL);
#endif
    }
    for (i = 0; i < SIZE; i++) {
#ᱡᱩᱫᱤ !defined(_WIN32)
        pthread_join (id[i], NULL);
#ᱵᱟᱝ
        WaitForSingleObject(id[i], INFINITE);
#endif
    }
    for (i = 0; i < SIZE; i++) {
        ᱡᱩᱫᱤ (count[i] != COUNT)
            printf ("error: %d %d\n", i, count[i]);
    }
    ᱨᱩᱣᱟᱹᱲ 0;
}
