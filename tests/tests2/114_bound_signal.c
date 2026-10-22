#شامل <stdio.h>
#شامل <pthread.h>
#شامل <semaphore.h>
#شامل <signal.h>
#شامل <string.h>
#شامل <sys/types.h>
#شامل <sys/wait.h>
#شامل <sys/time.h>
#شامل <unistd.h>
#شامل <stdlib.h>
#شامل <errno.h>
#شامل <setjmp.h>

ساکن متلون صحیح تسلسل = 1;
ساکن sem_t sem;
ساکن sem_t sem_بچہ;

ساکن خالی
جوڑو (صحیح n)
{
    صحیح i;
    صحیح arr[n];

    برائے (i = 0; i < n; i++) {
        arr[i]++;
    }
    memset (&arr[0], 0, n * حجم(صحیح));
}

ساکن خالی *
بلند_بھرو (خالی *غیر_مستعمل)
{
    جب (تسلسل) {
        جوڑو(10);
        جوڑو(20);
    }
    واپس تہی;
}

ساکن خالی *
do_signal (خالی *غیر_مستعمل)
{
    جب (تسلسل) {
        kill (getpid(), SIGUSR1);
        جب (sem_wait(&sem) < 0 && errno == EINTR);
    }
    واپس تہی;
}

ساکن خالی *
do_fork (خالی *غیر_مستعمل)
{
    pid_t pid;

    جب (تسلسل) {
        انتخاب ((pid = fork())) {
        حالت 0:
            جوڑو(1000);
            جوڑو(2000);
            باہر_نکلو(0);
            توڑو;
        حالت -1:
            واپس تہی;
        طےشدہ:
            جب (sem_wait(&sem_بچہ) < 0 && errno == EINTR);
            wait(تہی);
            توڑو;
        }
    }
    واپس تہی;
}

ساکن خالی signal_handler(صحیح sig)
{
    جوڑو(10);
    جوڑو(20);
    sem_post (&sem);
}

ساکن خالی بچہ_handler(صحیح sig)
{
    جوڑو(10);
    جوڑو(20);
    sem_post (&sem_بچہ);
}

ساکن غیرعلامتی getclock_ms(خالی)
{
#اگر_تعریف_شدہ _WIN32
    واپس Get_Tick_گنتی();
#ورنہ
    ساخت timeval tv;
    gettimeofday(&tv, تہی);
    واپس tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#اگر_ختم
}

صحیح
مین (خالی)
{
    صحیح i;
    pthread_t id1, id2, id3;
    ساخت sigaction act;
    sigjmp_buf sj;
    sigset_t m;
    time_t انتہا;

    memset (&act, 0, حجم (act));
    act.sa_handler = signal_handler;
    act.sa_flags = 0;
    sigemptyset (&act.sa_mask);
    sigaction (SIGUSR1, &act, تہی);
    act.sa_handler = بچہ_handler;
    sigaction (SIGCHLD, &act, تہی);

    لکھو ("start\n"); fflush(stdout);

    sem_init (&sem, 0, 0);
    sem_init (&sem_بچہ, 0, 0);
    pthread_create(&id1, تہی, بلند_بھرو, تہی);
    pthread_create(&id2, تہی, do_signal, تہی);
#اگر !defined(__APPLE__)
    pthread_create(&id3, تہی, do_fork, تہی);
#اگر_ختم

    /* sleep does not work !!! */
    انتہا = getclock_ms() + 200;
    جب (getclock_ms() < انتہا) ;
    تسلسل = 0;

    pthread_join(id1, تہی);
    pthread_join(id2, تہی);
#اگر !defined(__APPLE__)
    pthread_join(id3, تہی);
#اگر_ختم
    sem_destroy (&sem);
    sem_destroy (&sem_بچہ);

    لکھو ("end\n"); fflush(stdout);

    sigemptyset (&m);
    sigprocmask (SIG_SETMASK, &m, تہی);
    اگر (sigsetjmp (sj, 0) == 0)
    {
        sigaddset (&m, SIGUSR1);
        sigprocmask (SIG_SETMASK, &m, تہی);
        siglongjmp (sj, 1);
        لکھو ("failed");
        واپس 1;
    }
    sigprocmask (SIG_SETMASK, تہی, &m);
    اگر (!sigismember (&m, SIGUSR1))
        لکھو ("failed");
    واپس 0;
}
