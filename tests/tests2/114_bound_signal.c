#અન્તર્ભાવ <stdio.h>
#અન્તર્ભાવ <pthread.h>
#અન્તર્ભાવ <semaphore.h>
#અન્તર્ભાવ <signal.h>
#અન્તર્ભાવ <string.h>
#અન્તર્ભાવ <sys/types.h>
#અન્તર્ભાવ <sys/wait.h>
#અન્તર્ભાવ <sys/time.h>
#અન્તર્ભાવ <unistd.h>
#અન્તર્ભાવ <stdlib.h>
#અન્તર્ભાવ <errno.h>
#અન્તર્ભાવ <setjmp.h>

સ્થિર અસ્થિર પૂર્ણાંક run = 1;
સ્થિર sem_t sem;
સ્થિર sem_t sem_child;

સ્થિર શૂન્ય
add (પૂર્ણાંક n)
{
    પૂર્ણાંક i;
    પૂર્ણાંક arr[n];

    માટે (i = 0; i < n; i++) {
        arr[i]++;
    }
    memset (&arr[0], 0, n * કદ(પૂર્ણાંક));
}

સ્થિર શૂન્ય *
ઉપલું_load (શૂન્ય *unused)
{
    જ્યારે (run) {
        add(10);
        add(20);
    }
    પાછા ખાલી;
}

સ્થિર શૂન્ય *
do_signal (શૂન્ય *unused)
{
    જ્યારે (run) {
        kill (getpid(), SIGUSR1);
        જ્યારે (sem_wait(&sem) < 0 && errno == EINTR);
    }
    પાછા ખાલી;
}

સ્થિર શૂન્ય *
do_fork (શૂન્ય *unused)
{
    pid_t pid;

    જ્યારે (run) {
        પસંદગી ((pid = fork())) {
        સ્થિતિ 0:
            add(1000);
            add(2000);
            exit(0);
            તોડો;
        સ્થિતિ -1:
            પાછા ખાલી;
        મૂળભૂત:
            જ્યારે (sem_wait(&sem_child) < 0 && errno == EINTR);
            wait(ખાલી);
            તોડો;
        }
    }
    પાછા ખાલી;
}

સ્થિર શૂન્ય signal_handler(પૂર્ણાંક sig)
{
    add(10);
    add(20);
    sem_post (&sem);
}

સ્થિર શૂન્ય child_handler(પૂર્ણાંક sig)
{
    add(10);
    add(20);
    sem_post (&sem_child);
}

સ્થિર unsigned getclock_ms(શૂન્ય)
{
#ifdef _WIN32
    પાછા Get_Tick_ગણતરી();
#નહીંતર
    સંરચના timeval tv;
    gettimeofday(&tv, ખાલી);
    પાછા tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#endif
}

પૂર્ણાંક
મુખ્ય (શૂન્ય)
{
    પૂર્ણાંક i;
    pthread_t id1, id2, id3;
    સંરચના sigaction act;
    sigjmp_buf sj;
    sigset_t m;
    time_t end;

    memset (&act, 0, કદ (act));
    act.sa_handler = signal_handler;
    act.sa_flags = 0;
    sigemptyset (&act.sa_mask);
    sigaction (SIGUSR1, &act, ખાલી);
    act.sa_handler = child_handler;
    sigaction (SIGCHLD, &act, ખાલી);

    printf ("start\n"); fflush(stdout);

    sem_init (&sem, 0, 0);
    sem_init (&sem_child, 0, 0);
    pthread_create(&id1, ખાલી, ઉપલું_load, ખાલી);
    pthread_create(&id2, ખાલી, do_signal, ખાલી);
#જો !defined(__APPLE__)
    pthread_create(&id3, ખાલી, do_fork, ખાલી);
#endif

    /* sleep does not work !!! */
    end = getclock_ms() + 200;
    જ્યારે (getclock_ms() < end) ;
    run = 0;

    pthread_join(id1, ખાલી);
    pthread_join(id2, ખાલી);
#જો !defined(__APPLE__)
    pthread_join(id3, ખાલી);
#endif
    sem_destroy (&sem);
    sem_destroy (&sem_child);

    printf ("end\n"); fflush(stdout);

    sigemptyset (&m);
    sigprocmask (SIG_SETMASK, &m, ખાલી);
    જો (sigsetjmp (sj, 0) == 0)
    {
        sigaddset (&m, SIGUSR1);
        sigprocmask (SIG_SETMASK, &m, ખાલી);
        siglongjmp (sj, 1);
        printf ("failed");
        પાછા 1;
    }
    sigprocmask (SIG_SETMASK, ખાલી, &m);
    જો (!sigismember (&m, SIGUSR1))
        printf ("failed");
    પાછા 0;
}
