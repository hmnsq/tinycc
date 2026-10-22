#ಅನ್ತರ್ಭಾವ <stdio.h>
#ಅನ್ತರ್ಭಾವ <pthread.h>
#ಅನ್ತರ್ಭಾವ <semaphore.h>
#ಅನ್ತರ್ಭಾವ <signal.h>
#ಅನ್ತರ್ಭಾವ <string.h>
#ಅನ್ತರ್ಭಾವ <sys/types.h>
#ಅನ್ತರ್ಭಾವ <sys/wait.h>
#ಅನ್ತರ್ಭಾವ <sys/time.h>
#ಅನ್ತರ್ಭಾವ <unistd.h>
#ಅನ್ತರ್ಭಾವ <stdlib.h>
#ಅನ್ತರ್ಭಾವ <errno.h>
#ಅನ್ತರ್ಭಾವ <setjmp.h>

ಸ್ಥಿರ ಚಞ್ಚಲ ಪೂರ್ಣಾಙ್ಕ run = 1;
ಸ್ಥಿರ sem_t sem;
ಸ್ಥಿರ sem_t sem_child;

ಸ್ಥಿರ ಶೂನ್ಯ
add (ಪೂರ್ಣಾಙ್ಕ n)
{
    ಪೂರ್ಣಾಙ್ಕ i;
    ಪೂರ್ಣಾಙ್ಕ arr[n];

    ಪ್ರತಿ (i = 0; i < n; i++) {
        arr[i]++;
    }
    memset (&arr[0], 0, n * ಪರಿಮಾಣ(ಪೂರ್ಣಾಙ್ಕ));
}

ಸ್ಥಿರ ಶೂನ್ಯ *
ಮೇಲಿನ_load (ಶೂನ್ಯ *unused)
{
    ಯಾವತ್ (run) {
        add(10);
        add(20);
    }
    ಪ್ರತ್ಯಾಗಮ ರಿಕ್ತ;
}

ಸ್ಥಿರ ಶೂನ್ಯ *
do_signal (ಶೂನ್ಯ *unused)
{
    ಯಾವತ್ (run) {
        kill (getpid(), SIGUSR1);
        ಯಾವತ್ (sem_wait(&sem) < 0 && errno == EINTR);
    }
    ಪ್ರತ್ಯಾಗಮ ರಿಕ್ತ;
}

ಸ್ಥಿರ ಶೂನ್ಯ *
do_fork (ಶೂನ್ಯ *unused)
{
    pid_t pid;

    ಯಾವತ್ (run) {
        ವಿಕಲ್ಪ ((pid = fork())) {
        ಪಕ್ಷ 0:
            add(1000);
            add(2000);
            exit(0);
            ಭಙ್ಗ;
        ಪಕ್ಷ -1:
            ಪ್ರತ್ಯಾಗಮ ರಿಕ್ತ;
        ಸ್ವಭಾವ:
            ಯಾವತ್ (sem_wait(&sem_child) < 0 && errno == EINTR);
            wait(ರಿಕ್ತ);
            ಭಙ್ಗ;
        }
    }
    ಪ್ರತ್ಯಾಗಮ ರಿಕ್ತ;
}

ಸ್ಥಿರ ಶೂನ್ಯ signal_handler(ಪೂರ್ಣಾಙ್ಕ sig)
{
    add(10);
    add(20);
    sem_post (&sem);
}

ಸ್ಥಿರ ಶೂನ್ಯ child_handler(ಪೂರ್ಣಾಙ್ಕ sig)
{
    add(10);
    add(20);
    sem_post (&sem_child);
}

ಸ್ಥಿರ unsigned getclock_ms(ಶೂನ್ಯ)
{
#ifdef _WIN32
    ಪ್ರತ್ಯಾಗಮ Get_Tick_ಎಣಿಕೆ();
#ಅನ್ಯಥಾ
    ಸಂರಚನಾ timeval tv;
    gettimeofday(&tv, ರಿಕ್ತ);
    ಪ್ರತ್ಯಾಗಮ tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#endif
}

ಪೂರ್ಣಾಙ್ಕ
main (ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ i;
    pthread_t id1, id2, id3;
    ಸಂರಚನಾ sigaction act;
    sigjmp_buf sj;
    sigset_t m;
    time_t end;

    memset (&act, 0, ಪರಿಮಾಣ (act));
    act.sa_handler = signal_handler;
    act.sa_flags = 0;
    sigemptyset (&act.sa_mask);
    sigaction (SIGUSR1, &act, ರಿಕ್ತ);
    act.sa_handler = child_handler;
    sigaction (SIGCHLD, &act, ರಿಕ್ತ);

    printf ("start\n"); fflush(stdout);

    sem_init (&sem, 0, 0);
    sem_init (&sem_child, 0, 0);
    pthread_create(&id1, ರಿಕ್ತ, ಮೇಲಿನ_load, ರಿಕ್ತ);
    pthread_create(&id2, ರಿಕ್ತ, do_signal, ರಿಕ್ತ);
#ಯದಿ !defined(__APPLE__)
    pthread_create(&id3, ರಿಕ್ತ, do_fork, ರಿಕ್ತ);
#endif

    /* sleep does not work !!! */
    end = getclock_ms() + 200;
    ಯಾವತ್ (getclock_ms() < end) ;
    run = 0;

    pthread_join(id1, ರಿಕ್ತ);
    pthread_join(id2, ರಿಕ್ತ);
#ಯದಿ !defined(__APPLE__)
    pthread_join(id3, ರಿಕ್ತ);
#endif
    sem_destroy (&sem);
    sem_destroy (&sem_child);

    printf ("end\n"); fflush(stdout);

    sigemptyset (&m);
    sigprocmask (SIG_SETMASK, &m, ರಿಕ್ತ);
    ಯದಿ (sigsetjmp (sj, 0) == 0)
    {
        sigaddset (&m, SIGUSR1);
        sigprocmask (SIG_SETMASK, &m, ರಿಕ್ತ);
        siglongjmp (sj, 1);
        printf ("failed");
        ಪ್ರತ್ಯಾಗಮ 1;
    }
    sigprocmask (SIG_SETMASK, ರಿಕ್ತ, &m);
    ಯದಿ (!sigismember (&m, SIGUSR1))
        printf ("failed");
    ಪ್ರತ್ಯಾಗಮ 0;
}
