#ضمن <stdio.h>
#ضمن <string.h>
#ضمن <setjmp.h>
#إذا !defined(_WIN32)
#ضمن <pthread.h>
#وإلا
#ضمن <windows.h>
#جيڪڏهن_پورو

#وصف_ڪريو	سائيز_2	10
#وصف_ڪريو	ڳڻپ_4	10

#وصف_ڪريو TST   صحيح i, a[2], b[2];                \
              لكل (i = 0; i < 2; i++) a[i] = 0; \
              لكل (i = 0; i < 2; i++) b[i] = 0

ساكن صحيح ڳڻپ_2[سائيز_2];

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

ساكن فراغ *tst (فراغ * اشاريو)
{
    jmp_buf loc;
    صحيح i = *(صحيح *) اشاريو;
    ساكن صحيح v[سائيز_2];

    لكل (v[i] = 0; v[i] < ڳڻپ_4; v[i]++) {
        إذا (setjmp (loc) == 0) {
            TST;
            tst2(loc);
        }
        وإلا {
            ڳڻپ_2[i]++;
        }
        i = *(صحيح *) اشاريو;
    }
    أرجع عدم;
}

صحيح
مکيه (فراغ)
{
    صحيح i;
#إذا !defined(_WIN32)
    pthread_t id[سائيز_2];
#وإلا
    HANDLE id[سائيز_2];
#جيڪڏهن_پورو
    صحيح اشاريو[سائيز_2];

    لكل (i = 0; i < سائيز_2; i++) {
        اشاريو[i] = i;
#إذا !defined(_WIN32)
        pthread_create (&id[i], عدم, tst, (فراغ *) &اشاريو[i]);
#وإلا
        id[i] = CreateThread(عدم, 8192, (LPTHREAD_شروعات_ROUTINE) tst, (فراغ *) &اشاريو[i], 0, عدم);
#جيڪڏهن_پورو
    }
    لكل (i = 0; i < سائيز_2; i++) {
#إذا !defined(_WIN32)
        pthread_join (id[i], عدم);
#وإلا
        WaitForSingleObject(id[i], INFINITE);
#جيڪڏهن_پورو
    }
    لكل (i = 0; i < سائيز_2; i++) {
        إذا (ڳڻپ_2[i] != ڳڻپ_4)
            لکو ("error: %d %d\n", i, ڳڻپ_2[i]);
    }
    أرجع 0;
}
