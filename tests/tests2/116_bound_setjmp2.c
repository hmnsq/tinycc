#अन्तर्भाव <stdio.h>
#अन्तर्भाव <string.h>
#अन्तर्भाव <setjmp.h>
#जर !defined(_WIN32)
#अन्तर्भाव <pthread.h>
#अन्यथा
#अन्तर्भाव <windows.h>
#endif

#define	SIZE	10
#define	मोजणी_4	10

#define TST   पूर्णांक i, a[2], b[2];                \
              साठी (i = 0; i < 2; i++) a[i] = 0; \
              साठी (i = 0; i < 2; i++) b[i] = 0

स्थिर पूर्णांक मोजणी_2[SIZE];

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
    पूर्णांक i = *(पूर्णांक *) index;
    स्थिर पूर्णांक v[SIZE];

    साठी (v[i] = 0; v[i] < मोजणी_4; v[i]++) {
        जर (बनाओ_लाँघ (loc) == 0) {
            TST;
            tst2(loc);
        }
        अन्यथा {
            मोजणी_2[i]++;
        }
        i = *(पूर्णांक *) index;
    }
    परत रिक्त;
}

पूर्णांक
main (शून्य)
{
    पूर्णांक i;
#जर !defined(_WIN32)
    pthread_t id[SIZE];
#अन्यथा
    HANDLE id[SIZE];
#endif
    पूर्णांक index[SIZE];

    साठी (i = 0; i < SIZE; i++) {
        index[i] = i;
#जर !defined(_WIN32)
        pthread_create (&id[i], रिक्त, tst, (शून्य *) &index[i]);
#अन्यथा
        id[i] = CreateThread(रिक्त, 8192, (LPTHREAD_START_ROUTINE) tst, (शून्य *) &index[i], 0, रिक्त);
#endif
    }
    साठी (i = 0; i < SIZE; i++) {
#जर !defined(_WIN32)
        pthread_join (id[i], रिक्त);
#अन्यथा
        WaitForSingleObject(id[i], INFINITE);
#endif
    }
    साठी (i = 0; i < SIZE; i++) {
        जर (मोजणी_2[i] != मोजणी_4)
            म_लिखो ("error: %d %d\n", i, मोजणी_2[i]);
    }
    परत 0;
}
