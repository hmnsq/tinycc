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

ایستا فرار صحیح run = 1;
ایستا sem_t sem;
ایستا sem_t sem_child;

ایستا تهی
add (صحیح n)
{
    صحیح i;
    صحیح arr[n];

    برای (i = 0; i < n; i++) {
        arr[i]++;
    }
    memset (&arr[0], 0, n * اندازه(صحیح));
}

ایستا تهی *
بالا_load (تهی *unused)
{
    وقتی (run) {
        add(10);
        add(20);
    }
    بازگشت پوچ;
}

ایستا تهی *
do_signal (تهی *unused)
{
    وقتی (run) {
        kill (getpid(), SIGUSR1);
        وقتی (sem_wait(&sem) < 0 && errno == EINTR);
    }
    بازگشت پوچ;
}

ایستا تهی *
do_fork (تهی *unused)
{
    pid_t pid;

    وقتی (run) {
        انتخاب ((pid = fork())) {
        حالت 0:
            add(1000);
            add(2000);
            exit(0);
            بشکن;
        حالت -1:
            بازگشت پوچ;
        پیشفرض:
            وقتی (sem_wait(&sem_child) < 0 && errno == EINTR);
            wait(پوچ);
            بشکن;
        }
    }
    بازگشت پوچ;
}

ایستا تهی signal_handler(صحیح sig)
{
    add(10);
    add(20);
    sem_post (&sem);
}

ایستا تهی child_handler(صحیح sig)
{
    add(10);
    add(20);
    sem_post (&sem_child);
}

ایستا unsigned getclock_ms(تهی)
{
#ifdef _WIN32
    بازگشت Get_Tick_شمار();
#وگرنه
    ساختار timeval tv;
    gettimeofday(&tv, پوچ);
    بازگشت tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#endif
}

صحیح
اصلی (تهی)
{
    صحیح i;
    pthread_t id1, id2, id3;
    ساختار sigaction act;
    sigjmp_buf sj;
    sigset_t m;
    time_t end;

    memset (&act, 0, اندازه (act));
    act.sa_handler = signal_handler;
    act.sa_flags = 0;
    sigemptyset (&act.sa_mask);
    sigaction (SIGUSR1, &act, پوچ);
    act.sa_handler = child_handler;
    sigaction (SIGCHLD, &act, پوچ);

    printf ("start\n"); fflush(stdout);

    sem_init (&sem, 0, 0);
    sem_init (&sem_child, 0, 0);
    pthread_create(&id1, پوچ, بالا_load, پوچ);
    pthread_create(&id2, پوچ, do_signal, پوچ);
#اگر !defined(__APPLE__)
    pthread_create(&id3, پوچ, do_fork, پوچ);
#endif

    /* sleep does not work !!! */
    end = getclock_ms() + 200;
    وقتی (getclock_ms() < end) ;
    run = 0;

    pthread_join(id1, پوچ);
    pthread_join(id2, پوچ);
#اگر !defined(__APPLE__)
    pthread_join(id3, پوچ);
#endif
    sem_destroy (&sem);
    sem_destroy (&sem_child);

    printf ("end\n"); fflush(stdout);

    sigemptyset (&m);
    sigprocmask (SIG_SETMASK, &m, پوچ);
    اگر (sigsetjmp (sj, 0) == 0)
    {
        sigaddset (&m, SIGUSR1);
        sigprocmask (SIG_SETMASK, &m, پوچ);
        siglongjmp (sj, 1);
        printf ("failed");
        بازگشت 1;
    }
    sigprocmask (SIG_SETMASK, پوچ, &m);
    اگر (!sigismember (&m, SIGUSR1))
        printf ("failed");
    بازگشت 0;
}
