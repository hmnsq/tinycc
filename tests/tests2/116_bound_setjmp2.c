#ضمن <stdio.h>
#ضمن <string.h>
#ضمن <setjmp.h>
#إذا !defined(_WIN32)
#ضمن <pthread.h>
#وإلا
#ضمن <windows.h>
#پایان_اگر

#تعریف_کن	اندازه_2	10
#تعریف_کن	شمار_4	10

#تعریف_کن TST   صحيح i, a[2], b[2];                \
              لكل (i = 0; i < 2; i++) a[i] = 0; \
              لكل (i = 0; i < 2; i++) b[i] = 0

ساكن صحيح شمار_2[اندازه_2];

ساكن فراغ tst1 (jmp_buf loc)
{
    TST;
    longjmp(loc, 1);
}

ساكن فراغ tst2(jmp_buf loc)
{
    jmp_buf jmp;

    setjmp (jmp);
    TST;
    tst1(loc);
}

ساكن فراغ *tst (فراغ * شاخص)
{
    jmp_buf loc;
    صحيح i = *(صحيح *) شاخص;
    ساكن صحيح v[اندازه_2];

    لكل (v[i] = 0; v[i] < شمار_4; v[i]++) {
        إذا (setjmp (loc) == 0) {
            TST;
            tst2(loc);
        }
        وإلا {
            شمار_2[i]++;
        }
        i = *(صحيح *) شاخص;
    }
    أرجع عدم;
}

صحيح
اصلی (فراغ)
{
    صحيح i;
#إذا !defined(_WIN32)
    pthread_t id[اندازه_2];
#وإلا
    HANDLE id[اندازه_2];
#پایان_اگر
    صحيح شاخص[اندازه_2];

    لكل (i = 0; i < اندازه_2; i++) {
        شاخص[i] = i;
#إذا !defined(_WIN32)
        pthread_create (&id[i], عدم, tst, (فراغ *) &شاخص[i]);
#وإلا
        id[i] = CreateThread(عدم, 8192, (LPTHREAD_شروع_ROUTINE) tst, (فراغ *) &شاخص[i], 0, عدم);
#پایان_اگر
    }
    لكل (i = 0; i < اندازه_2; i++) {
#إذا !defined(_WIN32)
        pthread_join (id[i], عدم);
#وإلا
        WaitForSingleObject(id[i], INFINITE);
#پایان_اگر
    }
    لكل (i = 0; i < اندازه_2; i++) {
        إذا (شمار_2[i] != شمار_4)
            چاپ_کن ("error: %d %d\n", i, شمار_2[i]);
    }
    أرجع 0;
}
