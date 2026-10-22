#অন্তর্ভাৱ <stdio.h>
#অন্তর্ভাৱ <pthread.h>
#অন্তর্ভাৱ <semaphore.h>
#অন্তর্ভাৱ <signal.h>
#অন্তর্ভাৱ <string.h>
#অন্তর্ভাৱ <sys/types.h>
#অন্তর্ভাৱ <sys/wait.h>
#অন্তর্ভাৱ <sys/time.h>
#অন্তর্ভাৱ <unistd.h>
#অন্তর্ভাৱ <stdlib.h>
#অন্তর্ভাৱ <errno.h>
#অন্তর্ভাৱ <setjmp.h>

স্থির চঞ্চল পূর্ণাঙ্ক run = 1;
স্থির sem_t sem;
স্থির sem_t sem_child;

স্থির শূন্য
add (পূর্ণাঙ্ক n)
{
    পূর্ণাঙ্ক i;
    পূর্ণাঙ্ক arr[n];

    বাবে (i = 0; i < n; i++) {
        arr[i]++;
    }
    memset (&arr[0], 0, n * পরিমাণ(পূর্ণাঙ্ক));
}

স্থির শূন্য *
উপৰেৰ_load (শূন্য *unused)
{
    যেতিয়ালৈ (run) {
        add(10);
        add(20);
    }
    ঘূৰাই রিক্ত;
}

স্থির শূন্য *
do_signal (শূন্য *unused)
{
    যেতিয়ালৈ (run) {
        kill (getpid(), SIGUSR1);
        যেতিয়ালৈ (sem_wait(&sem) < 0 && errno == EINTR);
    }
    ঘূৰাই রিক্ত;
}

স্থির শূন্য *
do_fork (শূন্য *unused)
{
    pid_t pid;

    যেতিয়ালৈ (run) {
        ৱিকল্প ((pid = fork())) {
        পক্ষ 0:
            add(1000);
            add(2000);
            exit(0);
            ভঙ্গ;
        পক্ষ -1:
            ঘূৰাই রিক্ত;
        স্ৱভাৱ:
            যেতিয়ালৈ (sem_wait(&sem_child) < 0 && errno == EINTR);
            wait(রিক্ত);
            ভঙ্গ;
        }
    }
    ঘূৰাই রিক্ত;
}

স্থির শূন্য signal_handler(পূর্ণাঙ্ক sig)
{
    add(10);
    add(20);
    sem_post (&sem);
}

স্থির শূন্য child_handler(পূর্ণাঙ্ক sig)
{
    add(10);
    add(20);
    sem_post (&sem_child);
}

স্থির unsigned getclock_ms(শূন্য)
{
#ifdef _WIN32
    ঘূৰাই Get_Tick_গুনতি();
#অন্যথা
    সংরচনা timeval tv;
    gettimeofday(&tv, রিক্ত);
    ঘূৰাই tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#endif
}

পূর্ণাঙ্ক
main (শূন্য)
{
    পূর্ণাঙ্ক i;
    pthread_t id1, id2, id3;
    সংরচনা sigaction act;
    sigjmp_buf sj;
    sigset_t m;
    time_t end;

    memset (&act, 0, পরিমাণ (act));
    act.sa_handler = signal_handler;
    act.sa_flags = 0;
    sigemptyset (&act.sa_mask);
    sigaction (SIGUSR1, &act, রিক্ত);
    act.sa_handler = child_handler;
    sigaction (SIGCHLD, &act, রিক্ত);

    printf ("start\n"); fflush(stdout);

    sem_init (&sem, 0, 0);
    sem_init (&sem_child, 0, 0);
    pthread_create(&id1, রিক্ত, উপৰেৰ_load, রিক্ত);
    pthread_create(&id2, রিক্ত, do_signal, রিক্ত);
#যদি !defined(__APPLE__)
    pthread_create(&id3, রিক্ত, do_fork, রিক্ত);
#endif

    /* sleep does not work !!! */
    end = getclock_ms() + 200;
    যেতিয়ালৈ (getclock_ms() < end) ;
    run = 0;

    pthread_join(id1, রিক্ত);
    pthread_join(id2, রিক্ত);
#যদি !defined(__APPLE__)
    pthread_join(id3, রিক্ত);
#endif
    sem_destroy (&sem);
    sem_destroy (&sem_child);

    printf ("end\n"); fflush(stdout);

    sigemptyset (&m);
    sigprocmask (SIG_SETMASK, &m, রিক্ত);
    যদি (sigsetjmp (sj, 0) == 0)
    {
        sigaddset (&m, SIGUSR1);
        sigprocmask (SIG_SETMASK, &m, রিক্ত);
        siglongjmp (sj, 1);
        printf ("failed");
        ঘূৰাই 1;
    }
    sigprocmask (SIG_SETMASK, রিক্ত, &m);
    যদি (!sigismember (&m, SIGUSR1))
        printf ("failed");
    ঘূৰাই 0;
}
