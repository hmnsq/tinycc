#അന്തര്ഭാവ <stdio.h>
#അന്തര്ഭാവ <pthread.h>
#അന്തര്ഭാവ <semaphore.h>
#അന്തര്ഭാവ <signal.h>
#അന്തര്ഭാവ <string.h>
#അന്തര്ഭാവ <sys/types.h>
#അന്തര്ഭാവ <sys/wait.h>
#അന്തര്ഭാവ <sys/time.h>
#അന്തര്ഭാവ <unistd.h>
#അന്തര്ഭാവ <stdlib.h>
#അന്തര്ഭാവ <errno.h>
#അന്തര്ഭാവ <setjmp.h>

സ്ഥിതം അസ്ഥിര പൂർണ്ണസംഖ്യ run = 1;
സ്ഥിതം sem_t sem;
സ്ഥിതം sem_t sem_child;

സ്ഥിതം ശൂന്യം
add (പൂർണ്ണസംഖ്യ n)
{
    പൂർണ്ണസംഖ്യ i;
    പൂർണ്ണസംഖ്യ arr[n];

    വേണ്ടി (i = 0; i < n; i++) {
        arr[i]++;
    }
    memset (&arr[0], 0, n * വലുപ്പം(പൂർണ്ണസംഖ്യ));
}

സ്ഥിതം ശൂന്യം *
മുകളിലെ_load (ശൂന്യം *unused)
{
    ആകുമ്പോൾ (run) {
        add(10);
        add(20);
    }
    തിരികെ ശൂന്യ;
}

സ്ഥിതം ശൂന്യം *
do_signal (ശൂന്യം *unused)
{
    ആകുമ്പോൾ (run) {
        kill (getpid(), SIGUSR1);
        ആകുമ്പോൾ (sem_wait(&sem) < 0 && errno == EINTR);
    }
    തിരികെ ശൂന്യ;
}

സ്ഥിതം ശൂന്യം *
do_fork (ശൂന്യം *unused)
{
    pid_t pid;

    ആകുമ്പോൾ (run) {
        തിരഞ്ഞെടുപ്പ് ((pid = fork())) {
        അവസ്ഥ 0:
            add(1000);
            add(2000);
            exit(0);
            നിർത്തുക;
        അവസ്ഥ -1:
            തിരികെ ശൂന്യ;
        സ്ഥിരസ്ഥിതി:
            ആകുമ്പോൾ (sem_wait(&sem_child) < 0 && errno == EINTR);
            wait(ശൂന്യ);
            നിർത്തുക;
        }
    }
    തിരികെ ശൂന്യ;
}

സ്ഥിതം ശൂന്യം signal_handler(പൂർണ്ണസംഖ്യ sig)
{
    add(10);
    add(20);
    sem_post (&sem);
}

സ്ഥിതം ശൂന്യം child_handler(പൂർണ്ണസംഖ്യ sig)
{
    add(10);
    add(20);
    sem_post (&sem_child);
}

സ്ഥിതം unsigned getclock_ms(ശൂന്യം)
{
#ifdef _WIN32
    തിരികെ Get_Tick_എണ്ണം();
#അല്ലെങ്കിൽ
    ഘടന timeval tv;
    gettimeofday(&tv, ശൂന്യ);
    തിരികെ tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#endif
}

പൂർണ്ണസംഖ്യ
പ്രധാന (ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ i;
    pthread_t id1, id2, id3;
    ഘടന sigaction act;
    sigjmp_buf sj;
    sigset_t m;
    time_t end;

    memset (&act, 0, വലുപ്പം (act));
    act.sa_handler = signal_handler;
    act.sa_flags = 0;
    sigemptyset (&act.sa_mask);
    sigaction (SIGUSR1, &act, ശൂന്യ);
    act.sa_handler = child_handler;
    sigaction (SIGCHLD, &act, ശൂന്യ);

    printf ("start\n"); fflush(stdout);

    sem_init (&sem, 0, 0);
    sem_init (&sem_child, 0, 0);
    pthread_create(&id1, ശൂന്യ, മുകളിലെ_load, ശൂന്യ);
    pthread_create(&id2, ശൂന്യ, do_signal, ശൂന്യ);
#എങ്കിൽ !defined(__APPLE__)
    pthread_create(&id3, ശൂന്യ, do_fork, ശൂന്യ);
#endif

    /* sleep does not work !!! */
    end = getclock_ms() + 200;
    ആകുമ്പോൾ (getclock_ms() < end) ;
    run = 0;

    pthread_join(id1, ശൂന്യ);
    pthread_join(id2, ശൂന്യ);
#എങ്കിൽ !defined(__APPLE__)
    pthread_join(id3, ശൂന്യ);
#endif
    sem_destroy (&sem);
    sem_destroy (&sem_child);

    printf ("end\n"); fflush(stdout);

    sigemptyset (&m);
    sigprocmask (SIG_SETMASK, &m, ശൂന്യ);
    എങ്കിൽ (sigsetjmp (sj, 0) == 0)
    {
        sigaddset (&m, SIGUSR1);
        sigprocmask (SIG_SETMASK, &m, ശൂന്യ);
        siglongjmp (sj, 1);
        printf ("failed");
        തിരികെ 1;
    }
    sigprocmask (SIG_SETMASK, ശൂന്യ, &m);
    എങ്കിൽ (!sigismember (&m, SIGUSR1))
        printf ("failed");
    തിരികെ 0;
}
