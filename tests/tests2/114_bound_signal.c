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

ساكن متطاير صحيح پرلپسې = 1;
ساكن sem_t sem;
ساكن sem_t sem_ماشوم;

ساكن فراغ
جمع_کړه (صحيح n)
{
    صحيح i;
    صحيح arr[n];

    لكل (i = 0; i < n; i++) {
        arr[i]++;
    }
    memset (&arr[0], 0, n * حجم(صحيح));
}

ساكن فراغ *
لوړ_بارول (فراغ *ناکارول_شوی)
{
    طالما (پرلپسې) {
        جمع_کړه(10);
        جمع_کړه(20);
    }
    أرجع عدم;
}

ساكن فراغ *
do_signal (فراغ *ناکارول_شوی)
{
    طالما (پرلپسې) {
        kill (getpid(), SIGUSR1);
        طالما (sem_wait(&sem) < 0 && errno == EINTR);
    }
    أرجع عدم;
}

ساكن فراغ *
do_fork (فراغ *ناکارول_شوی)
{
    pid_t pid;

    طالما (پرلپسې) {
        بدل ((pid = fork())) {
        حالة 0:
            جمع_کړه(1000);
            جمع_کړه(2000);
            وتل(0);
            اكسر;
        حالة -1:
            أرجع عدم;
        افتراضي:
            طالما (sem_wait(&sem_ماشوم) < 0 && errno == EINTR);
            wait(عدم);
            اكسر;
        }
    }
    أرجع عدم;
}

ساكن فراغ signal_handler(صحيح sig)
{
    جمع_کړه(10);
    جمع_کړه(20);
    sem_post (&sem);
}

ساكن فراغ ماشوم_handler(صحيح sig)
{
    جمع_کړه(10);
    جمع_کړه(20);
    sem_post (&sem_ماشوم);
}

ساكن بینښه getclock_ms(فراغ)
{
#که_تعریف_شوی _WIN32
    أرجع Get_Tick_شمېر();
#وإلا
    بنية timeval tv;
    gettimeofday(&tv, عدم);
    أرجع tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#د_که_پای
}

صحيح
اصلي (فراغ)
{
    صحيح i;
    pthread_t id1, id2, id3;
    بنية sigaction act;
    sigjmp_buf sj;
    sigset_t m;
    time_t پای_ټکی;

    memset (&act, 0, حجم (act));
    act.sa_handler = signal_handler;
    act.sa_flags = 0;
    sigemptyset (&act.sa_mask);
    sigaction (SIGUSR1, &act, عدم);
    act.sa_handler = ماشوم_handler;
    sigaction (SIGCHLD, &act, عدم);

    چاپ_کړه ("start\n"); fflush(stdout);

    sem_init (&sem, 0, 0);
    sem_init (&sem_ماشوم, 0, 0);
    pthread_create(&id1, عدم, لوړ_بارول, عدم);
    pthread_create(&id2, عدم, do_signal, عدم);
#إذا !defined(__APPLE__)
    pthread_create(&id3, عدم, do_fork, عدم);
#د_که_پای

    /* sleep does not work !!! */
    پای_ټکی = getclock_ms() + 200;
    طالما (getclock_ms() < پای_ټکی) ;
    پرلپسې = 0;

    pthread_join(id1, عدم);
    pthread_join(id2, عدم);
#إذا !defined(__APPLE__)
    pthread_join(id3, عدم);
#د_که_پای
    sem_destroy (&sem);
    sem_destroy (&sem_ماشوم);

    چاپ_کړه ("end\n"); fflush(stdout);

    sigemptyset (&m);
    sigprocmask (SIG_SETMASK, &m, عدم);
    إذا (sigsetjmp (sj, 0) == 0)
    {
        sigaddset (&m, SIGUSR1);
        sigprocmask (SIG_SETMASK, &m, عدم);
        siglongjmp (sj, 1);
        چاپ_کړه ("failed");
        أرجع 1;
    }
    sigprocmask (SIG_SETMASK, عدم, &m);
    إذا (!sigismember (&m, SIGUSR1))
        چاپ_کړه ("failed");
    أرجع 0;
}
