#ضمن <stdio.h>
#ضمن <pthread.h>
#ضمن <semaphore.h>
#ضمن <signal.h>
#ضمن <string.h>
#ضمن <sys/types.h>
#ضمن <sys/wait.h>
#ضمن <sys/time.h>
#ضمن <unistd.h>
#ضمن <stdlib.h>
#ضمن <errno.h>
#ضمن <setjmp.h>

ساكن متطاير صحيح پیاپی = 1;
ساكن sem_t sem;
ساكن sem_t sem_فرزند;

ساكن فراغ
جمع_کن (صحيح n)
{
    صحيح i;
    صحيح arr[n];

    لكل (i = 0; i < n; i++) {
        arr[i]++;
    }
    memset (&arr[0], 0, n * حجم(صحيح));
}

ساكن فراغ *
بالا_بارگیری (فراغ *استفادهنشده)
{
    طالما (پیاپی) {
        جمع_کن(10);
        جمع_کن(20);
    }
    أرجع عدم;
}

ساكن فراغ *
do_signal (فراغ *استفادهنشده)
{
    طالما (پیاپی) {
        kill (getpid(), SIGUSR1);
        طالما (sem_wait(&sem) < 0 && errno == EINTR);
    }
    أرجع عدم;
}

ساكن فراغ *
do_fork (فراغ *استفادهنشده)
{
    pid_t pid;

    طالما (پیاپی) {
        بدل ((pid = fork())) {
        حالة 0:
            جمع_کن(1000);
            جمع_کن(2000);
            خروج(0);
            اكسر;
        حالة -1:
            أرجع عدم;
        افتراضي:
            طالما (sem_wait(&sem_فرزند) < 0 && errno == EINTR);
            wait(عدم);
            اكسر;
        }
    }
    أرجع عدم;
}

ساكن فراغ signal_handler(صحيح sig)
{
    جمع_کن(10);
    جمع_کن(20);
    sem_post (&sem);
}

ساكن فراغ فرزند_handler(صحيح sig)
{
    جمع_کن(10);
    جمع_کن(20);
    sem_post (&sem_فرزند);
}

ساكن بیعلامت getclock_ms(فراغ)
{
#اگر_تعریف_شده _WIN32
    أرجع Get_Tick_شمار();
#وإلا
    بنية timeval tv;
    gettimeofday(&tv, عدم);
    أرجع tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#پایان_اگر
}

صحيح
اصلی (فراغ)
{
    صحيح i;
    pthread_t id1, id2, id3;
    بنية sigaction act;
    sigjmp_buf sj;
    sigset_t m;
    time_t انتها;

    memset (&act, 0, حجم (act));
    act.sa_handler = signal_handler;
    act.sa_flags = 0;
    sigemptyset (&act.sa_mask);
    sigaction (SIGUSR1, &act, عدم);
    act.sa_handler = فرزند_handler;
    sigaction (SIGCHLD, &act, عدم);

    چاپ_کن ("start\n"); fflush(stdout);

    sem_init (&sem, 0, 0);
    sem_init (&sem_فرزند, 0, 0);
    pthread_create(&id1, عدم, بالا_بارگیری, عدم);
    pthread_create(&id2, عدم, do_signal, عدم);
#إذا !defined(__APPLE__)
    pthread_create(&id3, عدم, do_fork, عدم);
#پایان_اگر

    /* sleep does not work !!! */
    انتها = getclock_ms() + 200;
    طالما (getclock_ms() < انتها) ;
    پیاپی = 0;

    pthread_join(id1, عدم);
    pthread_join(id2, عدم);
#إذا !defined(__APPLE__)
    pthread_join(id3, عدم);
#پایان_اگر
    sem_destroy (&sem);
    sem_destroy (&sem_فرزند);

    چاپ_کن ("end\n"); fflush(stdout);

    sigemptyset (&m);
    sigprocmask (SIG_SETMASK, &m, عدم);
    إذا (sigsetjmp (sj, 0) == 0)
    {
        sigaddset (&m, SIGUSR1);
        sigprocmask (SIG_SETMASK, &m, عدم);
        siglongjmp (sj, 1);
        چاپ_کن ("failed");
        أرجع 1;
    }
    sigprocmask (SIG_SETMASK, عدم, &m);
    إذا (!sigismember (&m, SIGUSR1))
        چاپ_کن ("failed");
    أرجع 0;
}
