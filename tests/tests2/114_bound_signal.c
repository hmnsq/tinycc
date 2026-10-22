#అన్తర్భావ <stdio.h>
#అన్తర్భావ <pthread.h>
#అన్తర్భావ <semaphore.h>
#అన్తర్భావ <signal.h>
#అన్తర్భావ <string.h>
#అన్తర్భావ <sys/types.h>
#అన్తర్భావ <sys/wait.h>
#అన్తర్భావ <sys/time.h>
#అన్తర్భావ <unistd.h>
#అన్తర్భావ <stdlib.h>
#అన్తర్భావ <errno.h>
#అన్తర్భావ <setjmp.h>

స్థిర అస్థిర పూర్ణాంకం నిరంతరం = 1;
స్థిర sem_t sem;
స్థిర sem_t sem_బిడ్డ;

స్థిర శూన్య
కూడు (పూర్ణాంకం n)
{
    పూర్ణాంకం i;
    పూర్ణాంకం arr[n];

    కొరకు (i = 0; i < n; i++) {
        arr[i]++;
    }
    memset (&arr[0], 0, n * పరిమాణం(పూర్ణాంకం));
}

స్థిర శూన్య *
ఎగువ_ఎక్కించు (శూన్య *వాడని)
{
    అయితే (నిరంతరం) {
        కూడు(10);
        కూడు(20);
    }
    తిరిగి ఖాళీ;
}

స్థిర శూన్య *
do_signal (శూన్య *వాడని)
{
    అయితే (నిరంతరం) {
        kill (getpid(), SIGUSR1);
        అయితే (sem_wait(&sem) < 0 && errno == EINTR);
    }
    తిరిగి ఖాళీ;
}

స్థిర శూన్య *
do_fork (శూన్య *వాడని)
{
    pid_t pid;

    అయితే (నిరంతరం) {
        ఎంపిక ((pid = fork())) {
        స్థితి 0:
            కూడు(1000);
            కూడు(2000);
            నిష్క్రమించు(0);
            ఆపు;
        స్థితి -1:
            తిరిగి ఖాళీ;
        అప్రమేయ:
            అయితే (sem_wait(&sem_బిడ్డ) < 0 && errno == EINTR);
            wait(ఖాళీ);
            ఆపు;
        }
    }
    తిరిగి ఖాళీ;
}

స్థిర శూన్య signal_handler(పూర్ణాంకం sig)
{
    కూడు(10);
    కూడు(20);
    sem_post (&sem);
}

స్థిర శూన్య బిడ్డ_handler(పూర్ణాంకం sig)
{
    కూడు(10);
    కూడు(20);
    sem_post (&sem_బిడ్డ);
}

స్థిర గుర్తులేని getclock_ms(శూన్య)
{
#నిర్వచితమైతే _WIN32
    తిరిగి Get_Tick_లెక్క();
#లేకపోతే
    నిర్మాణం timeval tv;
    gettimeofday(&tv, ఖాళీ);
    తిరిగి tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#అయితే_ముగింపు
}

పూర్ణాంకం
ప్రధాన (శూన్య)
{
    పూర్ణాంకం i;
    pthread_t id1, id2, id3;
    నిర్మాణం sigaction act;
    sigjmp_buf sj;
    sigset_t m;
    time_t చివర;

    memset (&act, 0, పరిమాణం (act));
    act.sa_handler = signal_handler;
    act.sa_flags = 0;
    sigemptyset (&act.sa_mask);
    sigaction (SIGUSR1, &act, ఖాళీ);
    act.sa_handler = బిడ్డ_handler;
    sigaction (SIGCHLD, &act, ఖాళీ);

    రాయి ("start\n"); fflush(stdout);

    sem_init (&sem, 0, 0);
    sem_init (&sem_బిడ్డ, 0, 0);
    pthread_create(&id1, ఖాళీ, ఎగువ_ఎక్కించు, ఖాళీ);
    pthread_create(&id2, ఖాళీ, do_signal, ఖాళీ);
#ఒకవేళ !defined(__APPLE__)
    pthread_create(&id3, ఖాళీ, do_fork, ఖాళీ);
#అయితే_ముగింపు

    /* sleep does not work !!! */
    చివర = getclock_ms() + 200;
    అయితే (getclock_ms() < చివర) ;
    నిరంతరం = 0;

    pthread_join(id1, ఖాళీ);
    pthread_join(id2, ఖాళీ);
#ఒకవేళ !defined(__APPLE__)
    pthread_join(id3, ఖాళీ);
#అయితే_ముగింపు
    sem_destroy (&sem);
    sem_destroy (&sem_బిడ్డ);

    రాయి ("end\n"); fflush(stdout);

    sigemptyset (&m);
    sigprocmask (SIG_SETMASK, &m, ఖాళీ);
    ఒకవేళ (sigsetjmp (sj, 0) == 0)
    {
        sigaddset (&m, SIGUSR1);
        sigprocmask (SIG_SETMASK, &m, ఖాళీ);
        siglongjmp (sj, 1);
        రాయి ("failed");
        తిరిగి 1;
    }
    sigprocmask (SIG_SETMASK, ఖాళీ, &m);
    ఒకవేళ (!sigismember (&m, SIGUSR1))
        రాయి ("failed");
    తిరిగి 0;
}
