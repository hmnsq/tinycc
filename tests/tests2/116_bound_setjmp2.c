#include <stdio.h>
#include <string.h>
#include <setjmp.h>
#ถ้า !defined(_WIN32)
#include <pthread.h>
#มิฉะนั้น
#include <windows.h>
#endif

#define	SIZE	10
#define	COUNT	10

#define TST   จำนวนเต็ม i, a[2], b[2];                \
              สำหรับ (i = 0; i < 2; i++) a[i] = 0; \
              สำหรับ (i = 0; i < 2; i++) b[i] = 0

static จำนวนเต็ม count[SIZE];

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
    จำนวนเต็ม i = *(จำนวนเต็ม *) index;
    static จำนวนเต็ม v[SIZE];

    สำหรับ (v[i] = 0; v[i] < COUNT; v[i]++) {
        ถ้า (setjmp (loc) == 0) {
            TST;
            tst2(loc);
        }
        มิฉะนั้น {
            count[i]++;
        }
        i = *(จำนวนเต็ม *) index;
    }
    คืน NULL;
}

จำนวนเต็ม
หลัก (void)
{
    จำนวนเต็ม i;
#ถ้า !defined(_WIN32)
    pthread_t id[SIZE];
#มิฉะนั้น
    HANDLE id[SIZE];
#endif
    จำนวนเต็ม index[SIZE];

    สำหรับ (i = 0; i < SIZE; i++) {
        index[i] = i;
#ถ้า !defined(_WIN32)
        pthread_create (&id[i], NULL, tst, (void *) &index[i]);
#มิฉะนั้น
        id[i] = CreateThread(NULL, 8192, (LPTHREAD_START_ROUTINE) tst, (void *) &index[i], 0, NULL);
#endif
    }
    สำหรับ (i = 0; i < SIZE; i++) {
#ถ้า !defined(_WIN32)
        pthread_join (id[i], NULL);
#มิฉะนั้น
        WaitForSingleObject(id[i], INFINITE);
#endif
    }
    สำหรับ (i = 0; i < SIZE; i++) {
        ถ้า (count[i] != COUNT)
            printf ("error: %d %d\n", i, count[i]);
    }
    คืน 0;
}
