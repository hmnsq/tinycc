#include <stdio.h>
#include <string.h>
#include <setjmp.h>
#အကယ်၍ !defined(_WIN32)
#include <pthread.h>
#မဟုတ်ပါက
#include <windows.h>
#endif

#define	SIZE	10
#define	COUNT	10

#define TST   ကိန်းပြည့် i, a[2], b[2];                \
              အတွက် (i = 0; i < 2; i++) a[i] = 0; \
              အတွက် (i = 0; i < 2; i++) b[i] = 0

static ကိန်းပြည့် count[SIZE];

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
    ကိန်းပြည့် i = *(ကိန်းပြည့် *) index;
    static ကိန်းပြည့် v[SIZE];

    အတွက် (v[i] = 0; v[i] < COUNT; v[i]++) {
        အကယ်၍ (setjmp (loc) == 0) {
            TST;
            tst2(loc);
        }
        မဟုတ်ပါက {
            count[i]++;
        }
        i = *(ကိန်းပြည့် *) index;
    }
    ပြန်ပေး NULL;
}

ကိန်းပြည့်
main (void)
{
    ကိန်းပြည့် i;
#အကယ်၍ !defined(_WIN32)
    pthread_t id[SIZE];
#မဟုတ်ပါက
    HANDLE id[SIZE];
#endif
    ကိန်းပြည့် index[SIZE];

    အတွက် (i = 0; i < SIZE; i++) {
        index[i] = i;
#အကယ်၍ !defined(_WIN32)
        pthread_create (&id[i], NULL, tst, (void *) &index[i]);
#မဟုတ်ပါက
        id[i] = CreateThread(NULL, 8192, (LPTHREAD_START_ROUTINE) tst, (void *) &index[i], 0, NULL);
#endif
    }
    အတွက် (i = 0; i < SIZE; i++) {
#အကယ်၍ !defined(_WIN32)
        pthread_join (id[i], NULL);
#မဟုတ်ပါက
        WaitForSingleObject(id[i], INFINITE);
#endif
    }
    အတွက် (i = 0; i < SIZE; i++) {
        အကယ်၍ (count[i] != COUNT)
            printf ("error: %d %d\n", i, count[i]);
    }
    ပြန်ပေး 0;
}
