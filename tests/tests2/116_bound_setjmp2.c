#ಅನ್ತರ್ಭಾವ <stdio.h>
#ಅನ್ತರ್ಭಾವ <string.h>
#ಅನ್ತರ್ಭಾವ <setjmp.h>
#ಯದಿ !defined(_WIN32)
#ಅನ್ತರ್ಭಾವ <pthread.h>
#ಅನ್ಯಥಾ
#ಅನ್ತರ್ಭಾವ <windows.h>
#endif

#define	SIZE	10
#define	ಎಣಿಕೆ_4	10

#define TST   ಪೂರ್ಣಾಙ್ಕ i, a[2], b[2];                \
              ಪ್ರತಿ (i = 0; i < 2; i++) a[i] = 0; \
              ಪ್ರತಿ (i = 0; i < 2; i++) b[i] = 0

ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ ಎಣಿಕೆ_2[SIZE];

ಸ್ಥಿರ ಶೂನ್ಯ tst1 (jmp_buf loc)
{
    TST;
    longjmp(loc, 1);
}

ಸ್ಥಿರ ಶೂನ್ಯ tst2(jmp_buf loc)
{
    jmp_buf jmp;

    setjmp (jmp);
    TST;
    tst1(loc);
}

ಸ್ಥಿರ ಶೂನ್ಯ *tst (ಶೂನ್ಯ * index)
{
    jmp_buf loc;
    ಪೂರ್ಣಾಙ್ಕ i = *(ಪೂರ್ಣಾಙ್ಕ *) index;
    ಸ್ಥಿರ ಪೂರ್ಣಾಙ್ಕ v[SIZE];

    ಪ್ರತಿ (v[i] = 0; v[i] < ಎಣಿಕೆ_4; v[i]++) {
        ಯದಿ (setjmp (loc) == 0) {
            TST;
            tst2(loc);
        }
        ಅನ್ಯಥಾ {
            ಎಣಿಕೆ_2[i]++;
        }
        i = *(ಪೂರ್ಣಾಙ್ಕ *) index;
    }
    ಪ್ರತ್ಯಾಗಮ ರಿಕ್ತ;
}

ಪೂರ್ಣಾಙ್ಕ
main (ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ i;
#ಯದಿ !defined(_WIN32)
    pthread_t id[SIZE];
#ಅನ್ಯಥಾ
    HANDLE id[SIZE];
#endif
    ಪೂರ್ಣಾಙ್ಕ index[SIZE];

    ಪ್ರತಿ (i = 0; i < SIZE; i++) {
        index[i] = i;
#ಯದಿ !defined(_WIN32)
        pthread_create (&id[i], ರಿಕ್ತ, tst, (ಶೂನ್ಯ *) &index[i]);
#ಅನ್ಯಥಾ
        id[i] = CreateThread(ರಿಕ್ತ, 8192, (LPTHREAD_START_ROUTINE) tst, (ಶೂನ್ಯ *) &index[i], 0, ರಿಕ್ತ);
#endif
    }
    ಪ್ರತಿ (i = 0; i < SIZE; i++) {
#ಯದಿ !defined(_WIN32)
        pthread_join (id[i], ರಿಕ್ತ);
#ಅನ್ಯಥಾ
        WaitForSingleObject(id[i], INFINITE);
#endif
    }
    ಪ್ರತಿ (i = 0; i < SIZE; i++) {
        ಯದಿ (ಎಣಿಕೆ_2[i] != ಎಣಿಕೆ_4)
            printf ("error: %d %d\n", i, ಎಣಿಕೆ_2[i]);
    }
    ಪ್ರತ್ಯಾಗಮ 0;
}
