#അന്തര്ഭാവ <stdio.h>
#അന്തര്ഭാവ <string.h>
#അന്തര്ഭാവ <setjmp.h>
#എങ്കിൽ !defined(_WIN32)
#അന്തര്ഭാവ <pthread.h>
#അല്ലെങ്കിൽ
#അന്തര്ഭാവ <windows.h>
#endif

#define	SIZE	10
#define	എണ്ണം_4	10

#define TST   പൂർണ്ണസംഖ്യ i, a[2], b[2];                \
              വേണ്ടി (i = 0; i < 2; i++) a[i] = 0; \
              വേണ്ടി (i = 0; i < 2; i++) b[i] = 0

സ്ഥിതം പൂർണ്ണസംഖ്യ എണ്ണം_2[SIZE];

സ്ഥിതം ശൂന്യം tst1 (jmp_buf loc)
{
    TST;
    longjmp(loc, 1);
}

സ്ഥിതം ശൂന്യം tst2(jmp_buf loc)
{
    jmp_buf jmp;

    setjmp (jmp);
    TST;
    tst1(loc);
}

സ്ഥിതം ശൂന്യം *tst (ശൂന്യം * index)
{
    jmp_buf loc;
    പൂർണ്ണസംഖ്യ i = *(പൂർണ്ണസംഖ്യ *) index;
    സ്ഥിതം പൂർണ്ണസംഖ്യ v[SIZE];

    വേണ്ടി (v[i] = 0; v[i] < എണ്ണം_4; v[i]++) {
        എങ്കിൽ (setjmp (loc) == 0) {
            TST;
            tst2(loc);
        }
        അല്ലെങ്കിൽ {
            എണ്ണം_2[i]++;
        }
        i = *(പൂർണ്ണസംഖ്യ *) index;
    }
    തിരികെ ശൂന്യ;
}

പൂർണ്ണസംഖ്യ
പ്രധാന (ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ i;
#എങ്കിൽ !defined(_WIN32)
    pthread_t id[SIZE];
#അല്ലെങ്കിൽ
    HANDLE id[SIZE];
#endif
    പൂർണ്ണസംഖ്യ index[SIZE];

    വേണ്ടി (i = 0; i < SIZE; i++) {
        index[i] = i;
#എങ്കിൽ !defined(_WIN32)
        pthread_create (&id[i], ശൂന്യ, tst, (ശൂന്യം *) &index[i]);
#അല്ലെങ്കിൽ
        id[i] = CreateThread(ശൂന്യ, 8192, (LPTHREAD_START_ROUTINE) tst, (ശൂന്യം *) &index[i], 0, ശൂന്യ);
#endif
    }
    വേണ്ടി (i = 0; i < SIZE; i++) {
#എങ്കിൽ !defined(_WIN32)
        pthread_join (id[i], ശൂന്യ);
#അല്ലെങ്കിൽ
        WaitForSingleObject(id[i], INFINITE);
#endif
    }
    വേണ്ടി (i = 0; i < SIZE; i++) {
        എങ്കിൽ (എണ്ണം_2[i] != എണ്ണം_4)
            printf ("error: %d %d\n", i, എണ്ണം_2[i]);
    }
    തിരികെ 0;
}
