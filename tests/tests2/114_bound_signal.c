#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <pthread.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <semaphore.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <signal.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <string.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <sys/types.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <sys/wait.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <sys/time.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <unistd.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <stdlib.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <errno.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <setjmp.h>

ਸਥਿਰ ਅਸਥਿਰ ਪੂਰਨ ਲੜੀਵਾਰ = 1;
ਸਥਿਰ sem_t sem;
ਸਥਿਰ sem_t sem_ਬੱਚਾ;

ਸਥਿਰ ਖਾਲੀ
ਜੋੜੋ (ਪੂਰਨ n)
{
    ਪੂਰਨ i;
    ਪੂਰਨ arr[n];

    ਲਈ (i = 0; i < n; i++) {
        arr[i]++;
    }
    memset (&arr[0], 0, n * ਆਕਾਰ(ਪੂਰਨ));
}

ਸਥਿਰ ਖਾਲੀ *
ਉੱਚਾ_ਲੱਦੋ (ਖਾਲੀ *ਅਣਵਰਤਿਆ)
{
    ਜਦੋਂ (ਲੜੀਵਾਰ) {
        ਜੋੜੋ(10);
        ਜੋੜੋ(20);
    }
    ਵਾਪਸ ਨਿਰਾ;
}

ਸਥਿਰ ਖਾਲੀ *
do_signal (ਖਾਲੀ *ਅਣਵਰਤਿਆ)
{
    ਜਦੋਂ (ਲੜੀਵਾਰ) {
        kill (getpid(), SIGUSR1);
        ਜਦੋਂ (sem_wait(&sem) < 0 && errno == EINTR);
    }
    ਵਾਪਸ ਨਿਰਾ;
}

ਸਥਿਰ ਖਾਲੀ *
do_fork (ਖਾਲੀ *ਅਣਵਰਤਿਆ)
{
    pid_t pid;

    ਜਦੋਂ (ਲੜੀਵਾਰ) {
        ਚੋਣ ((pid = fork())) {
        ਹਾਲਤ 0:
            ਜੋੜੋ(1000);
            ਜੋੜੋ(2000);
            ਬਾਹਰ_ਨਿਕਲੋ(0);
            ਰੋਕੋ;
        ਹਾਲਤ -1:
            ਵਾਪਸ ਨਿਰਾ;
        ਮੂਲ:
            ਜਦੋਂ (sem_wait(&sem_ਬੱਚਾ) < 0 && errno == EINTR);
            wait(ਨਿਰਾ);
            ਰੋਕੋ;
        }
    }
    ਵਾਪਸ ਨਿਰਾ;
}

ਸਥਿਰ ਖਾਲੀ signal_handler(ਪੂਰਨ sig)
{
    ਜੋੜੋ(10);
    ਜੋੜੋ(20);
    sem_post (&sem);
}

ਸਥਿਰ ਖਾਲੀ ਬੱਚਾ_handler(ਪੂਰਨ sig)
{
    ਜੋੜੋ(10);
    ਜੋੜੋ(20);
    sem_post (&sem_ਬੱਚਾ);
}

ਸਥਿਰ ਬਿਨਾਨਿਸ਼ਾਨੀ getclock_ms(ਖਾਲੀ)
{
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN32
    ਵਾਪਸ Get_Tick_ਗਿਣਤੀ();
#ਨਹੀਂਤਾਂ
    ਬਣਤਰ timeval tv;
    gettimeofday(&tv, ਨਿਰਾ);
    ਵਾਪਸ tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#ਜੇ_ਅੰਤ
}

ਪੂਰਨ
ਮੁੱਖ (ਖਾਲੀ)
{
    ਪੂਰਨ i;
    pthread_t id1, id2, id3;
    ਬਣਤਰ sigaction act;
    sigjmp_buf sj;
    sigset_t m;
    time_t ਸਿਰਾ;

    memset (&act, 0, ਆਕਾਰ (act));
    act.sa_handler = signal_handler;
    act.sa_flags = 0;
    sigemptyset (&act.sa_mask);
    sigaction (SIGUSR1, &act, ਨਿਰਾ);
    act.sa_handler = ਬੱਚਾ_handler;
    sigaction (SIGCHLD, &act, ਨਿਰਾ);

    ਲਿਖੋ ("start\n"); fflush(stdout);

    sem_init (&sem, 0, 0);
    sem_init (&sem_ਬੱਚਾ, 0, 0);
    pthread_create(&id1, ਨਿਰਾ, ਉੱਚਾ_ਲੱਦੋ, ਨਿਰਾ);
    pthread_create(&id2, ਨਿਰਾ, do_signal, ਨਿਰਾ);
#ਜੇ !defined(__APPLE__)
    pthread_create(&id3, ਨਿਰਾ, do_fork, ਨਿਰਾ);
#ਜੇ_ਅੰਤ

    /* sleep does not work !!! */
    ਸਿਰਾ = getclock_ms() + 200;
    ਜਦੋਂ (getclock_ms() < ਸਿਰਾ) ;
    ਲੜੀਵਾਰ = 0;

    pthread_join(id1, ਨਿਰਾ);
    pthread_join(id2, ਨਿਰਾ);
#ਜੇ !defined(__APPLE__)
    pthread_join(id3, ਨਿਰਾ);
#ਜੇ_ਅੰਤ
    sem_destroy (&sem);
    sem_destroy (&sem_ਬੱਚਾ);

    ਲਿਖੋ ("end\n"); fflush(stdout);

    sigemptyset (&m);
    sigprocmask (SIG_SETMASK, &m, ਨਿਰਾ);
    ਜੇ (sigsetjmp (sj, 0) == 0)
    {
        sigaddset (&m, SIGUSR1);
        sigprocmask (SIG_SETMASK, &m, ਨਿਰਾ);
        siglongjmp (sj, 1);
        ਲਿਖੋ ("failed");
        ਵਾਪਸ 1;
    }
    sigprocmask (SIG_SETMASK, ਨਿਰਾ, &m);
    ਜੇ (!sigismember (&m, SIGUSR1))
        ਲਿਖੋ ("failed");
    ਵਾਪਸ 0;
}
