#include <stdio.h>
#include <string.h>
#include <setjmp.h>
#ຖ້າ !defined(_WIN32)
#include <pthread.h>
#ບໍ່ດັ່ງນັ້ນ
#include <windows.h>
#endif

#define	SIZE	10
#define	COUNT	10

#define TST   ຈຳນວນເຕັມ i, a[2], b[2];                \
              ສຳລັບ (i = 0; i < 2; i++) a[i] = 0; \
              ສຳລັບ (i = 0; i < 2; i++) b[i] = 0

static ຈຳນວນເຕັມ count[SIZE];

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
    ຈຳນວນເຕັມ i = *(ຈຳນວນເຕັມ *) index;
    static ຈຳນວນເຕັມ v[SIZE];

    ສຳລັບ (v[i] = 0; v[i] < COUNT; v[i]++) {
        ຖ້າ (setjmp (loc) == 0) {
            TST;
            tst2(loc);
        }
        ບໍ່ດັ່ງນັ້ນ {
            count[i]++;
        }
        i = *(ຈຳນວນເຕັມ *) index;
    }
    ສົ່ງຄືນ NULL;
}

ຈຳນວນເຕັມ
main (void)
{
    ຈຳນວນເຕັມ i;
#ຖ້າ !defined(_WIN32)
    pthread_t id[SIZE];
#ບໍ່ດັ່ງນັ້ນ
    HANDLE id[SIZE];
#endif
    ຈຳນວນເຕັມ index[SIZE];

    ສຳລັບ (i = 0; i < SIZE; i++) {
        index[i] = i;
#ຖ້າ !defined(_WIN32)
        pthread_create (&id[i], NULL, tst, (void *) &index[i]);
#ບໍ່ດັ່ງນັ້ນ
        id[i] = CreateThread(NULL, 8192, (LPTHREAD_START_ROUTINE) tst, (void *) &index[i], 0, NULL);
#endif
    }
    ສຳລັບ (i = 0; i < SIZE; i++) {
#ຖ້າ !defined(_WIN32)
        pthread_join (id[i], NULL);
#ບໍ່ດັ່ງນັ້ນ
        WaitForSingleObject(id[i], INFINITE);
#endif
    }
    ສຳລັບ (i = 0; i < SIZE; i++) {
        ຖ້າ (count[i] != COUNT)
            printf ("error: %d %d\n", i, count[i]);
    }
    ສົ່ງຄືນ 0;
}
