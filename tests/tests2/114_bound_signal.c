#ଅନ୍ତର୍ଭାଵ <stdio.h>
#ଅନ୍ତର୍ଭାଵ <pthread.h>
#ଅନ୍ତର୍ଭାଵ <semaphore.h>
#ଅନ୍ତର୍ଭାଵ <signal.h>
#ଅନ୍ତର୍ଭାଵ <string.h>
#ଅନ୍ତର୍ଭାଵ <sys/types.h>
#ଅନ୍ତର୍ଭାଵ <sys/wait.h>
#ଅନ୍ତର୍ଭାଵ <sys/time.h>
#ଅନ୍ତର୍ଭାଵ <unistd.h>
#ଅନ୍ତର୍ଭାଵ <stdlib.h>
#ଅନ୍ତର୍ଭାଵ <errno.h>
#ଅନ୍ତର୍ଭାଵ <setjmp.h>

ସ୍ଥିର ଅସ୍ଥିର ପୂର୍ଣ୍ଣସଂଖ୍ୟା run = 1;
ସ୍ଥିର sem_t sem;
ସ୍ଥିର sem_t sem_child;

ସ୍ଥିର ଶୂନ୍ୟ
add (ପୂର୍ଣ୍ଣସଂଖ୍ୟା n)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା arr[n];

    ପାଇଁ (i = 0; i < n; i++) {
        arr[i]++;
    }
    memset (&arr[0], 0, n * ଆକାର(ପୂର୍ଣ୍ଣସଂଖ୍ୟା));
}

ସ୍ଥିର ଶୂନ୍ୟ *
ଉପର_load (ଶୂନ୍ୟ *unused)
{
    ଯେତେବେଳେ (run) {
        add(10);
        add(20);
    }
    ଫେରନ୍ତୁ ଖାଲି;
}

ସ୍ଥିର ଶୂନ୍ୟ *
do_signal (ଶୂନ୍ୟ *unused)
{
    ଯେତେବେଳେ (run) {
        kill (getpid(), SIGUSR1);
        ଯେତେବେଳେ (sem_wait(&sem) < 0 && errno == EINTR);
    }
    ଫେରନ୍ତୁ ଖାଲି;
}

ସ୍ଥିର ଶୂନ୍ୟ *
do_fork (ଶୂନ୍ୟ *unused)
{
    pid_t pid;

    ଯେତେବେଳେ (run) {
        ବାଛ ((pid = fork())) {
        ସ୍ଥିତି 0:
            add(1000);
            add(2000);
            exit(0);
            ଭାଙ୍ଗ;
        ସ୍ଥିତି -1:
            ଫେରନ୍ତୁ ଖାଲି;
        ପୂର୍ବନିର୍ଦ୍ଧାରିତ:
            ଯେତେବେଳେ (sem_wait(&sem_child) < 0 && errno == EINTR);
            wait(ଖାଲି);
            ଭାଙ୍ଗ;
        }
    }
    ଫେରନ୍ତୁ ଖାଲି;
}

ସ୍ଥିର ଶୂନ୍ୟ signal_handler(ପୂର୍ଣ୍ଣସଂଖ୍ୟା sig)
{
    add(10);
    add(20);
    sem_post (&sem);
}

ସ୍ଥିର ଶୂନ୍ୟ child_handler(ପୂର୍ଣ୍ଣସଂଖ୍ୟା sig)
{
    add(10);
    add(20);
    sem_post (&sem_child);
}

ସ୍ଥିର unsigned getclock_ms(ଶୂନ୍ୟ)
{
#ifdef _WIN32
    ଫେରନ୍ତୁ Get_Tick_ଗଣନା();
#ଅନ୍ୟଥା
    ସଂରଚନା timeval tv;
    gettimeofday(&tv, ଖାଲି);
    ଫେରନ୍ତୁ tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#endif
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା
ମୁଖ୍ୟ (ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
    pthread_t id1, id2, id3;
    ସଂରଚନା sigaction act;
    sigjmp_buf sj;
    sigset_t m;
    time_t end;

    memset (&act, 0, ଆକାର (act));
    act.sa_handler = signal_handler;
    act.sa_flags = 0;
    sigemptyset (&act.sa_mask);
    sigaction (SIGUSR1, &act, ଖାଲି);
    act.sa_handler = child_handler;
    sigaction (SIGCHLD, &act, ଖାଲି);

    printf ("start\n"); fflush(stdout);

    sem_init (&sem, 0, 0);
    sem_init (&sem_child, 0, 0);
    pthread_create(&id1, ଖାଲି, ଉପର_load, ଖାଲି);
    pthread_create(&id2, ଖାଲି, do_signal, ଖାଲି);
#ଯଦି !defined(__APPLE__)
    pthread_create(&id3, ଖାଲି, do_fork, ଖାଲି);
#endif

    /* sleep does not work !!! */
    end = getclock_ms() + 200;
    ଯେତେବେଳେ (getclock_ms() < end) ;
    run = 0;

    pthread_join(id1, ଖାଲି);
    pthread_join(id2, ଖାଲି);
#ଯଦି !defined(__APPLE__)
    pthread_join(id3, ଖାଲି);
#endif
    sem_destroy (&sem);
    sem_destroy (&sem_child);

    printf ("end\n"); fflush(stdout);

    sigemptyset (&m);
    sigprocmask (SIG_SETMASK, &m, ଖାଲି);
    ଯଦି (sigsetjmp (sj, 0) == 0)
    {
        sigaddset (&m, SIGUSR1);
        sigprocmask (SIG_SETMASK, &m, ଖାଲି);
        siglongjmp (sj, 1);
        printf ("failed");
        ଫେରନ୍ତୁ 1;
    }
    sigprocmask (SIG_SETMASK, ଖାଲି, &m);
    ଯଦି (!sigismember (&m, SIGUSR1))
        printf ("failed");
    ଫେରନ୍ତୁ 0;
}
