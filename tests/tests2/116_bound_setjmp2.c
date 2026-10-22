#अन्तर्भाव <stdio.h>
#अन्तर्भाव <string.h>
#अन्तर्भाव <setjmp.h>
#सचे !defined(_WIN32)
#अन्तर्भाव <pthread.h>
#अञ्ञथा
#अन्तर्भाव <windows.h>
#endif

#define	SIZE	10
#define	गणनम्_4	10

#define TST   पूर्णाङ्क i, a[2], b[2];                \
              अत्थाय (i = 0; i < 2; i++) a[i] = 0; \
              अत्थाय (i = 0; i < 2; i++) b[i] = 0

स्थिर पूर्णाङ्क गणनम्_2[SIZE];

स्थिर शून्य tst1 (jmp_buf loc)
{
    TST;
    longjmp(loc, 1);
}

स्थिर शून्य tst2(jmp_buf loc)
{
    jmp_buf jmp;

    setjmp (jmp);
    TST;
    tst1(loc);
}

स्थिर शून्य *tst (शून्य * index)
{
    jmp_buf loc;
    पूर्णाङ्क i = *(पूर्णाङ्क *) index;
    स्थिर पूर्णाङ्क v[SIZE];

    अत्थाय (v[i] = 0; v[i] < गणनम्_4; v[i]++) {
        सचे (setjmp (loc) == 0) {
            TST;
            tst2(loc);
        }
        अञ्ञथा {
            गणनम्_2[i]++;
        }
        i = *(पूर्णाङ्क *) index;
    }
    पटिनिवत्त रिक्त;
}

पूर्णाङ्क
main (शून्य)
{
    पूर्णाङ्क i;
#सचे !defined(_WIN32)
    pthread_t id[SIZE];
#अञ्ञथा
    HANDLE id[SIZE];
#endif
    पूर्णाङ्क index[SIZE];

    अत्थाय (i = 0; i < SIZE; i++) {
        index[i] = i;
#सचे !defined(_WIN32)
        pthread_create (&id[i], रिक्त, tst, (शून्य *) &index[i]);
#अञ्ञथा
        id[i] = CreateThread(रिक्त, 8192, (LPTHREAD_START_ROUTINE) tst, (शून्य *) &index[i], 0, रिक्त);
#endif
    }
    अत्थाय (i = 0; i < SIZE; i++) {
#सचे !defined(_WIN32)
        pthread_join (id[i], रिक्त);
#अञ्ञथा
        WaitForSingleObject(id[i], INFINITE);
#endif
    }
    अत्थाय (i = 0; i < SIZE; i++) {
        सचे (गणनम्_2[i] != गणनम्_4)
            printf ("error: %d %d\n", i, गणनम्_2[i]);
    }
    पटिनिवत्त 0;
}
