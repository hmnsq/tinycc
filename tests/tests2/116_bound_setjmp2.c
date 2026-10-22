#ضمن <stdio.h>
#ضمن <string.h>
#ضمن <setjmp.h>
#إذا !defined(_WIN32)
#ضمن <pthread.h>
#وإلا
#ضمن <windows.h>
#جے_انت

#تعریف_کرو	ناپ_2	10
#تعریف_کرو	گنتی_4	10

#تعریف_کرو TST   صحيح i, a[2], b[2];                \
              لكل (i = 0; i < 2; i++) a[i] = 0; \
              لكل (i = 0; i < 2; i++) b[i] = 0

ساكن صحيح گنتی_2[ناپ_2];

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

ساكن فراغ *tst (فراغ * اشاریہ)
{
    jmp_buf loc;
    صحيح i = *(صحيح *) اشاریہ;
    ساكن صحيح v[ناپ_2];

    لكل (v[i] = 0; v[i] < گنتی_4; v[i]++) {
        إذا (setjmp (loc) == 0) {
            TST;
            tst2(loc);
        }
        وإلا {
            گنتی_2[i]++;
        }
        i = *(صحيح *) اشاریہ;
    }
    أرجع عدم;
}

صحيح
مکھ (فراغ)
{
    صحيح i;
#إذا !defined(_WIN32)
    pthread_t id[ناپ_2];
#وإلا
    HANDLE id[ناپ_2];
#جے_انت
    صحيح اشاریہ[ناپ_2];

    لكل (i = 0; i < ناپ_2; i++) {
        اشاریہ[i] = i;
#إذا !defined(_WIN32)
        pthread_create (&id[i], عدم, tst, (فراغ *) &اشاریہ[i]);
#وإلا
        id[i] = CreateThread(عدم, 8192, (LPTHREAD_شروع_ROUTINE) tst, (فراغ *) &اشاریہ[i], 0, عدم);
#جے_انت
    }
    لكل (i = 0; i < ناپ_2; i++) {
#إذا !defined(_WIN32)
        pthread_join (id[i], عدم);
#وإلا
        WaitForSingleObject(id[i], INFINITE);
#جے_انت
    }
    لكل (i = 0; i < ناپ_2; i++) {
        إذا (گنتی_2[i] != گنتی_4)
            لکھو ("error: %d %d\n", i, گنتی_2[i]);
    }
    أرجع 0;
}
