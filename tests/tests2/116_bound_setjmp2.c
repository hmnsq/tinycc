#અન્તર્ભાવ <stdio.h>
#અન્તર્ભાવ <string.h>
#અન્તર્ભાવ <setjmp.h>
#જો !defined(_WIN32)
#અન્તર્ભાવ <pthread.h>
#નહીંતર
#અન્તર્ભાવ <windows.h>
#endif

#define	SIZE	10
#define	ગણતરી_4	10

#define TST   પૂર્ણાંક i, a[2], b[2];                \
              માટે (i = 0; i < 2; i++) a[i] = 0; \
              માટે (i = 0; i < 2; i++) b[i] = 0

સ્થિર પૂર્ણાંક ગણતરી_2[SIZE];

સ્થિર શૂન્ય tst1 (jmp_buf loc)
{
    TST;
    longjmp(loc, 1);
}

સ્થિર શૂન્ય tst2(jmp_buf loc)
{
    jmp_buf jmp;

    setjmp (jmp);
    TST;
    tst1(loc);
}

સ્થિર શૂન્ય *tst (શૂન્ય * index)
{
    jmp_buf loc;
    પૂર્ણાંક i = *(પૂર્ણાંક *) index;
    સ્થિર પૂર્ણાંક v[SIZE];

    માટે (v[i] = 0; v[i] < ગણતરી_4; v[i]++) {
        જો (setjmp (loc) == 0) {
            TST;
            tst2(loc);
        }
        નહીંતર {
            ગણતરી_2[i]++;
        }
        i = *(પૂર્ણાંક *) index;
    }
    પાછા ખાલી;
}

પૂર્ણાંક
મુખ્ય (શૂન્ય)
{
    પૂર્ણાંક i;
#જો !defined(_WIN32)
    pthread_t id[SIZE];
#નહીંતર
    HANDLE id[SIZE];
#endif
    પૂર્ણાંક index[SIZE];

    માટે (i = 0; i < SIZE; i++) {
        index[i] = i;
#જો !defined(_WIN32)
        pthread_create (&id[i], ખાલી, tst, (શૂન્ય *) &index[i]);
#નહીંતર
        id[i] = CreateThread(ખાલી, 8192, (LPTHREAD_START_ROUTINE) tst, (શૂન્ય *) &index[i], 0, ખાલી);
#endif
    }
    માટે (i = 0; i < SIZE; i++) {
#જો !defined(_WIN32)
        pthread_join (id[i], ખાલી);
#નહીંતર
        WaitForSingleObject(id[i], INFINITE);
#endif
    }
    માટે (i = 0; i < SIZE; i++) {
        જો (ગણતરી_2[i] != ગણતરી_4)
            printf ("error: %d %d\n", i, ગણતરી_2[i]);
    }
    પાછા 0;
}
