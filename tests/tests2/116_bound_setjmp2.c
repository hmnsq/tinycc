#شامل <stdio.h>
#شامل <string.h>
#شامل <setjmp.h>
#اگر !defined(_WIN32)
#شامل <pthread.h>
#ورنہ
#شامل <windows.h>
#اگر_ختم

#تعریف_کرو	سائز_2	10
#تعریف_کرو	گنتی_4	10

#تعریف_کرو TST   صحیح i, a[2], b[2];                \
              برائے (i = 0; i < 2; i++) a[i] = 0; \
              برائے (i = 0; i < 2; i++) b[i] = 0

ساکن صحیح گنتی_2[سائز_2];

ساکن خالی tst1 (jmp_buf loc)
{
    TST;
    longjmp(loc, 1);
}

ساکن خالی tst2(jmp_buf loc)
{
    jmp_buf jmp;

    setjmp (jmp);
    TST;
    tst1(loc);
}

ساکن خالی *tst (خالی * اشاریہ)
{
    jmp_buf loc;
    صحیح i = *(صحیح *) اشاریہ;
    ساکن صحیح v[سائز_2];

    برائے (v[i] = 0; v[i] < گنتی_4; v[i]++) {
        اگر (setjmp (loc) == 0) {
            TST;
            tst2(loc);
        }
        ورنہ {
            گنتی_2[i]++;
        }
        i = *(صحیح *) اشاریہ;
    }
    واپس تہی;
}

صحیح
مین (خالی)
{
    صحیح i;
#اگر !defined(_WIN32)
    pthread_t id[سائز_2];
#ورنہ
    HANDLE id[سائز_2];
#اگر_ختم
    صحیح اشاریہ[سائز_2];

    برائے (i = 0; i < سائز_2; i++) {
        اشاریہ[i] = i;
#اگر !defined(_WIN32)
        pthread_create (&id[i], تہی, tst, (خالی *) &اشاریہ[i]);
#ورنہ
        id[i] = CreateThread(تہی, 8192, (LPTHREAD_آغاز_ROUTINE) tst, (خالی *) &اشاریہ[i], 0, تہی);
#اگر_ختم
    }
    برائے (i = 0; i < سائز_2; i++) {
#اگر !defined(_WIN32)
        pthread_join (id[i], تہی);
#ورنہ
        WaitForSingleObject(id[i], INFINITE);
#اگر_ختم
    }
    برائے (i = 0; i < سائز_2; i++) {
        اگر (گنتی_2[i] != گنتی_4)
            لکھو ("error: %d %d\n", i, گنتی_2[i]);
    }
    واپس 0;
}
