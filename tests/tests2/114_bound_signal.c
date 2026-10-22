#অন্তর্ভাব <stdio.h>
#অন্তর্ভাব <pthread.h>
#অন্তর্ভাব <semaphore.h>
#অন্তর্ভাব <signal.h>
#অন্তর্ভাব <string.h>
#অন্তর্ভাব <sys/types.h>
#অন্তর্ভাব <sys/wait.h>
#অন্তর্ভাব <sys/time.h>
#অন্তর্ভাব <unistd.h>
#অন্তর্ভাব <stdlib.h>
#অন্তর্ভাব <errno.h>
#অন্তর্ভাব <setjmp.h>

স্থির অস্থির পূর্ণসংখ্যা run = 1;
স্থির sem_t sem;
স্থির sem_t sem_child;

স্থির শূন্য
add (পূর্ণসংখ্যা n)
{
    পূর্ণসংখ্যা i;
    পূর্ণসংখ্যা arr[n];

    জন্য (i = 0; i < n; i++) {
        arr[i]++;
    }
    memset (&arr[0], 0, n * আকার(পূর্ণসংখ্যা));
}

স্থির শূন্য *
উপরের_load (শূন্য *unused)
{
    যখন (run) {
        add(10);
        add(20);
    }
    ফেরত ফাঁকা;
}

স্থির শূন্য *
do_signal (শূন্য *unused)
{
    যখন (run) {
        kill (getpid(), SIGUSR1);
        যখন (sem_wait(&sem) < 0 && errno == EINTR);
    }
    ফেরত ফাঁকা;
}

স্থির শূন্য *
do_fork (শূন্য *unused)
{
    pid_t pid;

    যখন (run) {
        নির্বাচন ((pid = fork())) {
        ক্ষেত্র 0:
            add(1000);
            add(2000);
            exit(0);
            বিরতি;
        ক্ষেত্র -1:
            ফেরত ফাঁকা;
        পূর্বনির্ধারিত:
            যখন (sem_wait(&sem_child) < 0 && errno == EINTR);
            wait(ফাঁকা);
            বিরতি;
        }
    }
    ফেরত ফাঁকা;
}

স্থির শূন্য signal_handler(পূর্ণসংখ্যা sig)
{
    add(10);
    add(20);
    sem_post (&sem);
}

স্থির শূন্য child_handler(পূর্ণসংখ্যা sig)
{
    add(10);
    add(20);
    sem_post (&sem_child);
}

স্থির unsigned getclock_ms(শূন্য)
{
#ifdef _WIN32
    ফেরত Get_Tick_গুনতি();
#অন্যথা
    কাঠামো timeval tv;
    gettimeofday(&tv, ফাঁকা);
    ফেরত tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#endif
}

পূর্ণসংখ্যা
প্রধান (শূন্য)
{
    পূর্ণসংখ্যা i;
    pthread_t id1, id2, id3;
    কাঠামো sigaction act;
    sigjmp_buf sj;
    sigset_t m;
    time_t end;

    memset (&act, 0, আকার (act));
    act.sa_handler = signal_handler;
    act.sa_flags = 0;
    sigemptyset (&act.sa_mask);
    sigaction (SIGUSR1, &act, ফাঁকা);
    act.sa_handler = child_handler;
    sigaction (SIGCHLD, &act, ফাঁকা);

    printf ("start\n"); fflush(stdout);

    sem_init (&sem, 0, 0);
    sem_init (&sem_child, 0, 0);
    pthread_create(&id1, ফাঁকা, উপরের_load, ফাঁকা);
    pthread_create(&id2, ফাঁকা, do_signal, ফাঁকা);
#যদি !defined(__APPLE__)
    pthread_create(&id3, ফাঁকা, do_fork, ফাঁকা);
#endif

    /* sleep does not work !!! */
    end = getclock_ms() + 200;
    যখন (getclock_ms() < end) ;
    run = 0;

    pthread_join(id1, ফাঁকা);
    pthread_join(id2, ফাঁকা);
#যদি !defined(__APPLE__)
    pthread_join(id3, ফাঁকা);
#endif
    sem_destroy (&sem);
    sem_destroy (&sem_child);

    printf ("end\n"); fflush(stdout);

    sigemptyset (&m);
    sigprocmask (SIG_SETMASK, &m, ফাঁকা);
    যদি (sigsetjmp (sj, 0) == 0)
    {
        sigaddset (&m, SIGUSR1);
        sigprocmask (SIG_SETMASK, &m, ফাঁকা);
        siglongjmp (sj, 1);
        printf ("failed");
        ফেরত 1;
    }
    sigprocmask (SIG_SETMASK, ফাঁকা, &m);
    যদি (!sigismember (&m, SIGUSR1))
        printf ("failed");
    ফেরত 0;
}
