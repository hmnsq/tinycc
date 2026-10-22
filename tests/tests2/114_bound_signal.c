#अन्तर्भाव <stdio.h>
#अन्तर्भाव <pthread.h>
#अन्तर्भाव <semaphore.h>
#अन्तर्भाव <signal.h>
#अन्तर्भाव <string.h>
#अन्तर्भाव <sys/types.h>
#अन्तर्भाव <sys/wait.h>
#अन्तर्भाव <sys/time.h>
#अन्तर्भाव <unistd.h>
#अन्तर्भाव <stdlib.h>
#अन्तर्भाव <errno.h>
#अन्तर्भाव <setjmp.h>

स्थिर चञ्चल पूर्णाङ्क run = 1;
स्थिर sem_t sem;
स्थिर sem_t sem_child;

स्थिर शून्य
add (पूर्णाङ्क n)
{
    पूर्णाङ्क i;
    पूर्णाङ्क arr[n];

    अत्थाय (i = 0; i < n; i++) {
        arr[i]++;
    }
    memset (&arr[0], 0, n * परिमाण(पूर्णाङ्क));
}

स्थिर शून्य *
उच्चः_load (शून्य *unused)
{
    याव (run) {
        add(10);
        add(20);
    }
    पटिनिवत्त रिक्त;
}

स्थिर शून्य *
do_signal (शून्य *unused)
{
    याव (run) {
        kill (getpid(), SIGUSR1);
        याव (sem_wait(&sem) < 0 && errno == EINTR);
    }
    पटिनिवत्त रिक्त;
}

स्थिर शून्य *
do_fork (शून्य *unused)
{
    pid_t pid;

    याव (run) {
        विकल्प ((pid = fork())) {
        पक्ष 0:
            add(1000);
            add(2000);
            exit(0);
            भङ्ग;
        पक्ष -1:
            पटिनिवत्त रिक्त;
        स्वभाव:
            याव (sem_wait(&sem_child) < 0 && errno == EINTR);
            wait(रिक्त);
            भङ्ग;
        }
    }
    पटिनिवत्त रिक्त;
}

स्थिर शून्य signal_handler(पूर्णाङ्क sig)
{
    add(10);
    add(20);
    sem_post (&sem);
}

स्थिर शून्य child_handler(पूर्णाङ्क sig)
{
    add(10);
    add(20);
    sem_post (&sem_child);
}

स्थिर unsigned getclock_ms(शून्य)
{
#ifdef _WIN32
    पटिनिवत्त Get_Tick_गणनम्();
#अञ्ञथा
    संरचना timeval tv;
    gettimeofday(&tv, रिक्त);
    पटिनिवत्त tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#endif
}

पूर्णाङ्क
main (शून्य)
{
    पूर्णाङ्क i;
    pthread_t id1, id2, id3;
    संरचना sigaction act;
    sigjmp_buf sj;
    sigset_t m;
    time_t end;

    memset (&act, 0, परिमाण (act));
    act.sa_handler = signal_handler;
    act.sa_flags = 0;
    sigemptyset (&act.sa_mask);
    sigaction (SIGUSR1, &act, रिक्त);
    act.sa_handler = child_handler;
    sigaction (SIGCHLD, &act, रिक्त);

    printf ("start\n"); fflush(stdout);

    sem_init (&sem, 0, 0);
    sem_init (&sem_child, 0, 0);
    pthread_create(&id1, रिक्त, उच्चः_load, रिक्त);
    pthread_create(&id2, रिक्त, do_signal, रिक्त);
#सचे !defined(__APPLE__)
    pthread_create(&id3, रिक्त, do_fork, रिक्त);
#endif

    /* sleep does not work !!! */
    end = getclock_ms() + 200;
    याव (getclock_ms() < end) ;
    run = 0;

    pthread_join(id1, रिक्त);
    pthread_join(id2, रिक्त);
#सचे !defined(__APPLE__)
    pthread_join(id3, रिक्त);
#endif
    sem_destroy (&sem);
    sem_destroy (&sem_child);

    printf ("end\n"); fflush(stdout);

    sigemptyset (&m);
    sigprocmask (SIG_SETMASK, &m, रिक्त);
    सचे (sigsetjmp (sj, 0) == 0)
    {
        sigaddset (&m, SIGUSR1);
        sigprocmask (SIG_SETMASK, &m, रिक्त);
        siglongjmp (sj, 1);
        printf ("failed");
        पटिनिवत्त 1;
    }
    sigprocmask (SIG_SETMASK, रिक्त, &m);
    सचे (!sigismember (&m, SIGUSR1))
        printf ("failed");
    पटिनिवत्त 0;
}
