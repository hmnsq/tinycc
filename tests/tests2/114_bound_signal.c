#அந்தர்பாவ <stdio.h>
#அந்தர்பாவ <pthread.h>
#அந்தர்பாவ <semaphore.h>
#அந்தர்பாவ <signal.h>
#அந்தர்பாவ <string.h>
#அந்தர்பாவ <sys/types.h>
#அந்தர்பாவ <sys/wait.h>
#அந்தர்பாவ <sys/time.h>
#அந்தர்பாவ <unistd.h>
#அந்தர்பாவ <stdlib.h>
#அந்தர்பாவ <errno.h>
#அந்தர்பாவ <setjmp.h>

நிலையான நிலையற்ற முழு run = 1;
நிலையான sem_t sem;
நிலையான sem_t sem_child;

நிலையான வெறுமை
add (முழு n)
{
    முழு i;
    முழு arr[n];

    க்கு (i = 0; i < n; i++) {
        arr[i]++;
    }
    memset (&arr[0], 0, n * அளவு(முழு));
}

நிலையான வெறுமை *
உயர்வு_load (வெறுமை *unused)
{
    போது (run) {
        add(10);
        add(20);
    }
    திரும்பு வெற்று;
}

நிலையான வெறுமை *
do_signal (வெறுமை *unused)
{
    போது (run) {
        kill (getpid(), SIGUSR1);
        போது (sem_wait(&sem) < 0 && errno == EINTR);
    }
    திரும்பு வெற்று;
}

நிலையான வெறுமை *
do_fork (வெறுமை *unused)
{
    pid_t pid;

    போது (run) {
        தேர்வு ((pid = fork())) {
        நிலை 0:
            add(1000);
            add(2000);
            exit(0);
            நிறுத்து;
        நிலை -1:
            திரும்பு வெற்று;
        இயல்பு:
            போது (sem_wait(&sem_child) < 0 && errno == EINTR);
            wait(வெற்று);
            நிறுத்து;
        }
    }
    திரும்பு வெற்று;
}

நிலையான வெறுமை signal_handler(முழு sig)
{
    add(10);
    add(20);
    sem_post (&sem);
}

நிலையான வெறுமை child_handler(முழு sig)
{
    add(10);
    add(20);
    sem_post (&sem_child);
}

நிலையான unsigned getclock_ms(வெறுமை)
{
#ifdef _WIN32
    திரும்பு Get_Tick_மொத்தம்();
#இல்லையெனில்
    கட்டமைப்பு timeval tv;
    gettimeofday(&tv, வெற்று);
    திரும்பு tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#endif
}

முழு
முதன்மை (வெறுமை)
{
    முழு i;
    pthread_t id1, id2, id3;
    கட்டமைப்பு sigaction act;
    sigjmp_buf sj;
    sigset_t m;
    time_t end;

    memset (&act, 0, அளவு (act));
    act.sa_handler = signal_handler;
    act.sa_flags = 0;
    sigemptyset (&act.sa_mask);
    sigaction (SIGUSR1, &act, வெற்று);
    act.sa_handler = child_handler;
    sigaction (SIGCHLD, &act, வெற்று);

    printf ("start\n"); fflush(stdout);

    sem_init (&sem, 0, 0);
    sem_init (&sem_child, 0, 0);
    pthread_create(&id1, வெற்று, உயர்வு_load, வெற்று);
    pthread_create(&id2, வெற்று, do_signal, வெற்று);
#எனில் !defined(__APPLE__)
    pthread_create(&id3, வெற்று, do_fork, வெற்று);
#endif

    /* sleep does not work !!! */
    end = getclock_ms() + 200;
    போது (getclock_ms() < end) ;
    run = 0;

    pthread_join(id1, வெற்று);
    pthread_join(id2, வெற்று);
#எனில் !defined(__APPLE__)
    pthread_join(id3, வெற்று);
#endif
    sem_destroy (&sem);
    sem_destroy (&sem_child);

    printf ("end\n"); fflush(stdout);

    sigemptyset (&m);
    sigprocmask (SIG_SETMASK, &m, வெற்று);
    எனில் (sigsetjmp (sj, 0) == 0)
    {
        sigaddset (&m, SIGUSR1);
        sigprocmask (SIG_SETMASK, &m, வெற்று);
        siglongjmp (sj, 1);
        printf ("failed");
        திரும்பு 1;
    }
    sigprocmask (SIG_SETMASK, வெற்று, &m);
    எனில் (!sigismember (&m, SIGUSR1))
        printf ("failed");
    திரும்பு 0;
}
