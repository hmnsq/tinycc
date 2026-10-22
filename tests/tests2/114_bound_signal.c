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

ساكن متطاير صحيح run = 1;
ساكن sem_t sem;
ساكن sem_t sem_child;

ساكن فراغ
add (صحيح n)
{
    صحيح i;
    صحيح arr[n];

    עבור (i = 0; i < n; i++) {
        arr[i]++;
    }
    memset (&arr[0], 0, n * حجم(صحيح));
}

ساكن فراغ *
high_load (فراغ *unused)
{
    כלעוד (run) {
        add(10);
        add(20);
    }
    החזר عدم;
}

ساكن فراغ *
do_signal (فراغ *unused)
{
    כלעוד (run) {
        kill (getpid(), SIGUSR1);
        כלעוד (sem_wait(&sem) < 0 && errno == EINTR);
    }
    החזר عدم;
}

ساكن فراغ *
do_fork (فراغ *unused)
{
    pid_t pid;

    כלעוד (run) {
        بدل ((pid = fork())) {
        حالة 0:
            add(1000);
            add(2000);
            exit(0);
            اكسر;
        حالة -1:
            החזר عدم;
        افتراضي:
            כלעוד (sem_wait(&sem_child) < 0 && errno == EINTR);
            wait(عدم);
            اكسر;
        }
    }
    החזר عدم;
}

ساكن فراغ signal_handler(صحيح sig)
{
    add(10);
    add(20);
    sem_post (&sem);
}

ساكن فراغ child_handler(صحيح sig)
{
    add(10);
    add(20);
    sem_post (&sem_child);
}

ساكن unsigned getclock_ms(فراغ)
{
#ifdef _WIN32
    החזר GetTickCount();
#אחרת
    بنية timeval tv;
    gettimeofday(&tv, عدم);
    החזר tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#endif
}

صحيح
main (فراغ)
{
    صحيح i;
    pthread_t id1, id2, id3;
    بنية sigaction act;
    sigjmp_buf sj;
    sigset_t m;
    time_t end;

    memset (&act, 0, حجم (act));
    act.sa_handler = signal_handler;
    act.sa_flags = 0;
    sigemptyset (&act.sa_mask);
    sigaction (SIGUSR1, &act, عدم);
    act.sa_handler = child_handler;
    sigaction (SIGCHLD, &act, عدم);

    printf ("start\n"); fflush(stdout);

    sem_init (&sem, 0, 0);
    sem_init (&sem_child, 0, 0);
    pthread_create(&id1, عدم, high_load, عدم);
    pthread_create(&id2, عدم, do_signal, عدم);
#אם !defined(__APPLE__)
    pthread_create(&id3, عدم, do_fork, عدم);
#endif

    /* sleep does not work !!! */
    end = getclock_ms() + 200;
    כלעוד (getclock_ms() < end) ;
    run = 0;

    pthread_join(id1, عدم);
    pthread_join(id2, عدم);
#אם !defined(__APPLE__)
    pthread_join(id3, عدم);
#endif
    sem_destroy (&sem);
    sem_destroy (&sem_child);

    printf ("end\n"); fflush(stdout);

    sigemptyset (&m);
    sigprocmask (SIG_SETMASK, &m, عدم);
    אם (sigsetjmp (sj, 0) == 0)
    {
        sigaddset (&m, SIGUSR1);
        sigprocmask (SIG_SETMASK, &m, عدم);
        siglongjmp (sj, 1);
        printf ("failed");
        החזר 1;
    }
    sigprocmask (SIG_SETMASK, عدم, &m);
    אם (!sigismember (&m, SIGUSR1))
        printf ("failed");
    החזר 0;
}
