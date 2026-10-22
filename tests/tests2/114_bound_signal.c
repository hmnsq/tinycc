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

स्थिर अस्थिर पूर्णांक run = 1;
स्थिर sem_t sem;
स्थिर sem_t sem_child;

स्थिर शून्य
add (पूर्णांक n)
{
    पूर्णांक i;
    पूर्णांक arr[n];

    साठी (i = 0; i < n; i++) {
        arr[i]++;
    }
    स_रखो (&arr[0], 0, n * आकार(पूर्णांक));
}

स्थिर शून्य *
वरचा_load (शून्य *unused)
{
    पर्यंत (run) {
        add(10);
        add(20);
    }
    परत रिक्त;
}

स्थिर शून्य *
do_signal (शून्य *unused)
{
    पर्यंत (run) {
        समाप्त (getpid(), SIGUSR1);
        पर्यंत (sem_wait(&sem) < 0 && त्रुटि_सं == EINTR);
    }
    परत रिक्त;
}

स्थिर शून्य *
do_fork (शून्य *unused)
{
    pid_t pid;

    पर्यंत (run) {
        निवड ((pid = विभाजन())) {
        स्थिती 0:
            add(1000);
            add(2000);
            निकास(0);
            थांबा;
        स्थिती -1:
            परत रिक्त;
        पूर्वनिर्धारित:
            पर्यंत (sem_wait(&sem_child) < 0 && त्रुटि_सं == EINTR);
            रुको(रिक्त);
            थांबा;
        }
    }
    परत रिक्त;
}

स्थिर शून्य signal_handler(पूर्णांक sig)
{
    add(10);
    add(20);
    sem_post (&sem);
}

स्थिर शून्य child_handler(पूर्णांक sig)
{
    add(10);
    add(20);
    sem_post (&sem_child);
}

स्थिर अचिन्हित getclock_ms(शून्य)
{
#ifdef _WIN32
    परत Get_Tick_मोजणी();
#अन्यथा
    संरचना timeval tv;
    gettimeofday(&tv, रिक्त);
    परत tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#endif
}

पूर्णांक
main (शून्य)
{
    पूर्णांक i;
    pthread_t id1, id2, id3;
    संरचना sigaction act;
    sigjmp_buf sj;
    sigset_t m;
    समय_प्रकार end;

    स_रखो (&act, 0, आकार (act));
    act.sa_handler = signal_handler;
    act.sa_flags = 0;
    sigemptyset (&act.sa_mask);
    sigaction (SIGUSR1, &act, रिक्त);
    act.sa_handler = child_handler;
    sigaction (SIGCHLD, &act, रिक्त);

    म_लिखो ("start\n"); ख_साफ(मानक_निकास);

    sem_init (&sem, 0, 0);
    sem_init (&sem_child, 0, 0);
    pthread_create(&id1, रिक्त, वरचा_load, रिक्त);
    pthread_create(&id2, रिक्त, do_signal, रिक्त);
#जर !defined(__APPLE__)
    pthread_create(&id3, रिक्त, do_fork, रिक्त);
#endif

    /* sleep does not work !!! */
    end = getclock_ms() + 200;
    पर्यंत (getclock_ms() < end) ;
    run = 0;

    pthread_join(id1, रिक्त);
    pthread_join(id2, रिक्त);
#जर !defined(__APPLE__)
    pthread_join(id3, रिक्त);
#endif
    sem_destroy (&sem);
    sem_destroy (&sem_child);

    म_लिखो ("end\n"); ख_साफ(मानक_निकास);

    sigemptyset (&m);
    sigprocmask (SIG_SETMASK, &m, रिक्त);
    जर (sigsetjmp (sj, 0) == 0)
    {
        sigaddset (&m, SIGUSR1);
        sigprocmask (SIG_SETMASK, &m, रिक्त);
        siglongjmp (sj, 1);
        म_लिखो ("failed");
        परत 1;
    }
    sigprocmask (SIG_SETMASK, रिक्त, &m);
    जर (!sigismember (&m, SIGUSR1))
        म_लिखो ("failed");
    परत 0;
}
