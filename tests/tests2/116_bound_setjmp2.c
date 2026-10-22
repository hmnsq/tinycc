#அந்தர்பாவ <stdio.h>
#அந்தர்பாவ <string.h>
#அந்தர்பாவ <setjmp.h>
#எனில் !defined(_WIN32)
#அந்தர்பாவ <pthread.h>
#இல்லையெனில்
#அந்தர்பாவ <windows.h>
#endif

#define	SIZE	10
#define	மொத்தம்_4	10

#define TST   முழு i, a[2], b[2];                \
              க்கு (i = 0; i < 2; i++) a[i] = 0; \
              க்கு (i = 0; i < 2; i++) b[i] = 0

நிலையான முழு மொத்தம்_2[SIZE];

நிலையான வெறுமை tst1 (jmp_buf loc)
{
    TST;
    longjmp(loc, 1);
}

நிலையான வெறுமை tst2(jmp_buf loc)
{
    jmp_buf jmp;

    setjmp (jmp);
    TST;
    tst1(loc);
}

நிலையான வெறுமை *tst (வெறுமை * index)
{
    jmp_buf loc;
    முழு i = *(முழு *) index;
    நிலையான முழு v[SIZE];

    க்கு (v[i] = 0; v[i] < மொத்தம்_4; v[i]++) {
        எனில் (setjmp (loc) == 0) {
            TST;
            tst2(loc);
        }
        இல்லையெனில் {
            மொத்தம்_2[i]++;
        }
        i = *(முழு *) index;
    }
    திரும்பு வெற்று;
}

முழு
முதன்மை (வெறுமை)
{
    முழு i;
#எனில் !defined(_WIN32)
    pthread_t id[SIZE];
#இல்லையெனில்
    HANDLE id[SIZE];
#endif
    முழு index[SIZE];

    க்கு (i = 0; i < SIZE; i++) {
        index[i] = i;
#எனில் !defined(_WIN32)
        pthread_create (&id[i], வெற்று, tst, (வெறுமை *) &index[i]);
#இல்லையெனில்
        id[i] = CreateThread(வெற்று, 8192, (LPTHREAD_START_ROUTINE) tst, (வெறுமை *) &index[i], 0, வெற்று);
#endif
    }
    க்கு (i = 0; i < SIZE; i++) {
#எனில் !defined(_WIN32)
        pthread_join (id[i], வெற்று);
#இல்லையெனில்
        WaitForSingleObject(id[i], INFINITE);
#endif
    }
    க்கு (i = 0; i < SIZE; i++) {
        எனில் (மொத்தம்_2[i] != மொத்தம்_4)
            printf ("error: %d %d\n", i, மொத்தம்_2[i]);
    }
    திரும்பு 0;
}
