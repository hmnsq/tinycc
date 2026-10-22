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

ساكن متطاير صحيح لگاتار = 1;
ساكن sem_t sem;
ساكن sem_t sem_بچہ;

ساكن فراغ
جوڑو (صحيح n)
{
    صحيح i;
    صحيح arr[n];

    لكل (i = 0; i < n; i++) {
        arr[i]++;
    }
    memset (&arr[0], 0, n * حجم(صحيح));
}

ساكن فراغ *
بلند_لدو (فراغ *بن_ورتیا)
{
    طالما (لگاتار) {
        جوڑو(10);
        جوڑو(20);
    }
    أرجع عدم;
}

ساكن فراغ *
do_signal (فراغ *بن_ورتیا)
{
    طالما (لگاتار) {
        kill (getpid(), SIGUSR1);
        طالما (sem_wait(&sem) < 0 && errno == EINTR);
    }
    أرجع عدم;
}

ساكن فراغ *
do_fork (فراغ *بن_ورتیا)
{
    pid_t pid;

    طالما (لگاتار) {
        بدل ((pid = fork())) {
        حالة 0:
            جوڑو(1000);
            جوڑو(2000);
            باہر_نکلو(0);
            اكسر;
        حالة -1:
            أرجع عدم;
        افتراضي:
            طالما (sem_wait(&sem_بچہ) < 0 && errno == EINTR);
            wait(عدم);
            اكسر;
        }
    }
    أرجع عدم;
}

ساكن فراغ signal_handler(صحيح sig)
{
    جوڑو(10);
    جوڑو(20);
    sem_post (&sem);
}

ساكن فراغ بچہ_handler(صحيح sig)
{
    جوڑو(10);
    جوڑو(20);
    sem_post (&sem_بچہ);
}

ساكن بنانشانی getclock_ms(فراغ)
{
#جے_تعریف_شدہ _WIN32
    أرجع Get_Tick_گنتی();
#وإلا
    بنية timeval tv;
    gettimeofday(&tv, عدم);
    أرجع tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#جے_انت
}

صحيح
مکھ (فراغ)
{
    صحيح i;
    pthread_t id1, id2, id3;
    بنية sigaction act;
    sigjmp_buf sj;
    sigset_t m;
    time_t سرا;

    memset (&act, 0, حجم (act));
    act.sa_handler = signal_handler;
    act.sa_flags = 0;
    sigemptyset (&act.sa_mask);
    sigaction (SIGUSR1, &act, عدم);
    act.sa_handler = بچہ_handler;
    sigaction (SIGCHLD, &act, عدم);

    لکھو ("start\n"); fflush(stdout);

    sem_init (&sem, 0, 0);
    sem_init (&sem_بچہ, 0, 0);
    pthread_create(&id1, عدم, بلند_لدو, عدم);
    pthread_create(&id2, عدم, do_signal, عدم);
#إذا !defined(__APPLE__)
    pthread_create(&id3, عدم, do_fork, عدم);
#جے_انت

    /* sleep does not work !!! */
    سرا = getclock_ms() + 200;
    طالما (getclock_ms() < سرا) ;
    لگاتار = 0;

    pthread_join(id1, عدم);
    pthread_join(id2, عدم);
#إذا !defined(__APPLE__)
    pthread_join(id3, عدم);
#جے_انت
    sem_destroy (&sem);
    sem_destroy (&sem_بچہ);

    لکھو ("end\n"); fflush(stdout);

    sigemptyset (&m);
    sigprocmask (SIG_SETMASK, &m, عدم);
    إذا (sigsetjmp (sj, 0) == 0)
    {
        sigaddset (&m, SIGUSR1);
        sigprocmask (SIG_SETMASK, &m, عدم);
        siglongjmp (sj, 1);
        لکھو ("failed");
        أرجع 1;
    }
    sigprocmask (SIG_SETMASK, عدم, &m);
    إذا (!sigismember (&m, SIGUSR1))
        لکھو ("failed");
    أرجع 0;
}
