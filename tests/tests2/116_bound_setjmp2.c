#अन्तर्भाव <stdio.h>
#अन्तर्भाव <string.h>
#अन्तर्भाव <setjmp.h>
#यदि !defined(_WIN32)
#अन्तर्भाव <pthread.h>
#अन्यथा
#अन्तर्भाव <windows.h>
#endif

#define	SIZE	10
#define	गन्ती_4	10

#define TST   पूर्णाङ्क i, a[2], b[2];                \
              लागि (i = 0; i < 2; i++) a[i] = 0; \
              लागि (i = 0; i < 2; i++) b[i] = 0

स्थिर पूर्णाङ्क गन्ती_2[SIZE];

स्थिर शून्य tst1 (लाँघ_बफ loc)
{
    TST;
    दीर्घ_लाँघ(loc, 1);
}

स्थिर शून्य tst2(लाँघ_बफ loc)
{
    लाँघ_बफ jmp;

    बनाओ_लाँघ (jmp);
    TST;
    tst1(loc);
}

स्थिर शून्य *tst (शून्य * index)
{
    लाँघ_बफ loc;
    पूर्णाङ्क i = *(पूर्णाङ्क *) index;
    स्थिर पूर्णाङ्क v[SIZE];

    लागि (v[i] = 0; v[i] < गन्ती_4; v[i]++) {
        यदि (बनाओ_लाँघ (loc) == 0) {
            TST;
            tst2(loc);
        }
        अन्यथा {
            गन्ती_2[i]++;
        }
        i = *(पूर्णाङ्क *) index;
    }
    फर्काऊ रिक्त;
}

पूर्णाङ्क
main (शून्य)
{
    पूर्णाङ्क i;
#यदि !defined(_WIN32)
    pthread_t id[SIZE];
#अन्यथा
    HANDLE id[SIZE];
#endif
    पूर्णाङ्क index[SIZE];

    लागि (i = 0; i < SIZE; i++) {
        index[i] = i;
#यदि !defined(_WIN32)
        pthread_create (&id[i], रिक्त, tst, (शून्य *) &index[i]);
#अन्यथा
        id[i] = CreateThread(रिक्त, 8192, (LPTHREAD_START_ROUTINE) tst, (शून्य *) &index[i], 0, रिक्त);
#endif
    }
    लागि (i = 0; i < SIZE; i++) {
#यदि !defined(_WIN32)
        pthread_join (id[i], रिक्त);
#अन्यथा
        WaitForSingleObject(id[i], INFINITE);
#endif
    }
    लागि (i = 0; i < SIZE; i++) {
        यदि (गन्ती_2[i] != गन्ती_4)
            म_लिखो ("error: %d %d\n", i, गन्ती_2[i]);
    }
    फर्काऊ 0;
}
