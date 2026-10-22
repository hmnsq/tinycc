#include <stdio.h>
#include <string.h>
#include <setjmp.h>
#ប្រសិនបើ !defined(_WIN32)
#include <pthread.h>
#បើមិនដូច្នេះ
#include <windows.h>
#endif

#define	SIZE	10
#define	COUNT	10

#define TST   ចំនួនគត់ i, a[2], b[2];                \
              សម្រាប់ (i = 0; i < 2; i++) a[i] = 0; \
              សម្រាប់ (i = 0; i < 2; i++) b[i] = 0

static ចំនួនគត់ count[SIZE];

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
    ចំនួនគត់ i = *(ចំនួនគត់ *) index;
    static ចំនួនគត់ v[SIZE];

    សម្រាប់ (v[i] = 0; v[i] < COUNT; v[i]++) {
        ប្រសិនបើ (setjmp (loc) == 0) {
            TST;
            tst2(loc);
        }
        បើមិនដូច្នេះ {
            count[i]++;
        }
        i = *(ចំនួនគត់ *) index;
    }
    ត្រឡប់ NULL;
}

ចំនួនគត់
main (void)
{
    ចំនួនគត់ i;
#ប្រសិនបើ !defined(_WIN32)
    pthread_t id[SIZE];
#បើមិនដូច្នេះ
    HANDLE id[SIZE];
#endif
    ចំនួនគត់ index[SIZE];

    សម្រាប់ (i = 0; i < SIZE; i++) {
        index[i] = i;
#ប្រសិនបើ !defined(_WIN32)
        pthread_create (&id[i], NULL, tst, (void *) &index[i]);
#បើមិនដូច្នេះ
        id[i] = CreateThread(NULL, 8192, (LPTHREAD_START_ROUTINE) tst, (void *) &index[i], 0, NULL);
#endif
    }
    សម្រាប់ (i = 0; i < SIZE; i++) {
#ប្រសិនបើ !defined(_WIN32)
        pthread_join (id[i], NULL);
#បើមិនដូច្នេះ
        WaitForSingleObject(id[i], INFINITE);
#endif
    }
    សម្រាប់ (i = 0; i < SIZE; i++) {
        ប្រសិនបើ (count[i] != COUNT)
            printf ("error: %d %d\n", i, count[i]);
    }
    ត្រឡប់ 0;
}
