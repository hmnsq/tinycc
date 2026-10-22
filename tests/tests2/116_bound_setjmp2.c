#अन्तर्भाव <stdio.h>
#अन्तर्भाव <string.h>
#अन्तर्भाव <setjmp.h>
#जइ !defined(_WIN32)
#अन्तर्भाव <pthread.h>
#अण्णहा
#अन्तर्भाव <windows.h>
#endif

#define	SIZE	10
#define	गणनम्_4	10

#define TST   पूर्णाङ्क i, a[2], b[2];                \
              प्रति (i = 0; i < 2; i++) a[i] = 0; \
              प्रति (i = 0; i < 2; i++) b[i] = 0

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

    प्रति (v[i] = 0; v[i] < गणनम्_4; v[i]++) {
        जइ (setjmp (loc) == 0) {
            TST;
            tst2(loc);
        }
        अण्णहा {
            गणनम्_2[i]++;
        }
        i = *(पूर्णाङ्क *) index;
    }
    प्रत्यागम रिक्त;
}

पूर्णाङ्क
main (शून्य)
{
    पूर्णाङ्क i;
#जइ !defined(_WIN32)
    pthread_t id[SIZE];
#अण्णहा
    HANDLE id[SIZE];
#endif
    पूर्णाङ्क index[SIZE];

    प्रति (i = 0; i < SIZE; i++) {
        index[i] = i;
#जइ !defined(_WIN32)
        pthread_create (&id[i], रिक्त, tst, (शून्य *) &index[i]);
#अण्णहा
        id[i] = CreateThread(रिक्त, 8192, (LPTHREAD_START_ROUTINE) tst, (शून्य *) &index[i], 0, रिक्त);
#endif
    }
    प्रति (i = 0; i < SIZE; i++) {
#जइ !defined(_WIN32)
        pthread_join (id[i], रिक्त);
#अण्णहा
        WaitForSingleObject(id[i], INFINITE);
#endif
    }
    प्रति (i = 0; i < SIZE; i++) {
        जइ (गणनम्_2[i] != गणनम्_4)
            printf ("error: %d %d\n", i, गणनम्_2[i]);
    }
    प्रत्यागम 0;
}
