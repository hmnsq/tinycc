#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <string.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <setjmp.h>
#ਜੇ !defined(_WIN32)
#ਅਨ੍ਤਰ੍ਭਾਵ <pthread.h>
#ਨਹੀਂਤਾਂ
#ਅਨ੍ਤਰ੍ਭਾਵ <windows.h>
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	ਮਾਪ_2	10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ	ਗਿਣਤੀ_5	10

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TST   ਪੂਰਨ i, a[2], b[2];                \
              ਲਈ (i = 0; i < 2; i++) a[i] = 0; \
              ਲਈ (i = 0; i < 2; i++) b[i] = 0

ਸਥਿਰ ਪੂਰਨ ਗਿਣਤੀ_3[ਮਾਪ_2];

ਸਥਿਰ ਖਾਲੀ tst1 (jmp_buf loc)
{
    TST;
    longjmp(loc, 1);
}

ਸਥਿਰ ਖਾਲੀ tst2(jmp_buf loc)
{
    jmp_buf jmp;

    setjmp (jmp);
    TST;
    tst1(loc);
}

ਸਥਿਰ ਖਾਲੀ *tst (ਖਾਲੀ * ਸੂਚਕਾਂਕ)
{
    jmp_buf loc;
    ਪੂਰਨ i = *(ਪੂਰਨ *) ਸੂਚਕਾਂਕ;
    ਸਥਿਰ ਪੂਰਨ v[ਮਾਪ_2];

    ਲਈ (v[i] = 0; v[i] < ਗਿਣਤੀ_5; v[i]++) {
        ਜੇ (setjmp (loc) == 0) {
            TST;
            tst2(loc);
        }
        ਨਹੀਂਤਾਂ {
            ਗਿਣਤੀ_3[i]++;
        }
        i = *(ਪੂਰਨ *) ਸੂਚਕਾਂਕ;
    }
    ਵਾਪਸ ਨਿਰਾ;
}

ਪੂਰਨ
ਮੁੱਖ (ਖਾਲੀ)
{
    ਪੂਰਨ i;
#ਜੇ !defined(_WIN32)
    pthread_t id[ਮਾਪ_2];
#ਨਹੀਂਤਾਂ
    HANDLE id[ਮਾਪ_2];
#ਜੇ_ਅੰਤ
    ਪੂਰਨ ਸੂਚਕਾਂਕ[ਮਾਪ_2];

    ਲਈ (i = 0; i < ਮਾਪ_2; i++) {
        ਸੂਚਕਾਂਕ[i] = i;
#ਜੇ !defined(_WIN32)
        pthread_create (&id[i], ਨਿਰਾ, tst, (ਖਾਲੀ *) &ਸੂਚਕਾਂਕ[i]);
#ਨਹੀਂਤਾਂ
        id[i] = CreateThread(ਨਿਰਾ, 8192, (LPTHREAD_ਸ਼ੁਰੂ_ROUTINE) tst, (ਖਾਲੀ *) &ਸੂਚਕਾਂਕ[i], 0, ਨਿਰਾ);
#ਜੇ_ਅੰਤ
    }
    ਲਈ (i = 0; i < ਮਾਪ_2; i++) {
#ਜੇ !defined(_WIN32)
        pthread_join (id[i], ਨਿਰਾ);
#ਨਹੀਂਤਾਂ
        WaitForSingleObject(id[i], INFINITE);
#ਜੇ_ਅੰਤ
    }
    ਲਈ (i = 0; i < ਮਾਪ_2; i++) {
        ਜੇ (ਗਿਣਤੀ_3[i] != ਗਿਣਤੀ_5)
            ਲਿਖੋ ("error: %d %d\n", i, ਗਿਣਤੀ_3[i]);
    }
    ਵਾਪਸ 0;
}
